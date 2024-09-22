#include <stdio.h>
#include <stdint.h>
#include <stdlib.h> // atoi()
#include <limits.h>

#define MAX_SIZE 100

/* Function pointer type definition */
typedef unsigned long long (*FibFunc)(int);
FibFunc chosenFunc;

/* Memoization cache */
unsigned long long memo[MAX_SIZE] = {0};

unsigned long long fibonacci_r_wrapper(int num);
unsigned long long fibonacci_i_wrapper(int num);
unsigned long long fibonacci_memo(int num);

int overflow_check(unsigned long long first_num, unsigned long long second_num);

unsigned long long fibonacci_r_wrapper(int num)
{
   if (num <= 1)
   {
      return num;
   }
   if (overflow_check(fibonacci_memo(num - 1), fibonacci_memo(num - 2)))
   {
      printf("Overflow detected at Fibonacci number %d\n", num);
      exit(1);
   }

   return fibonacci_memo(num - 1) + fibonacci_memo(num - 2);
}

unsigned long long fibonacci_i_wrapper(int num)
{
   if (num <= 1)
   {
      return num;
   }

   unsigned long long first_fibonacci_num = 0, second_fibonacci_num = 1, next_fibonacci_num;

   for (int ix = 2; ix <= num; ix++)
   {
      if (overflow_check(first_fibonacci_num, second_fibonacci_num))
      {
         printf("Overflow detected at Fibonacci number %d\n", ix);
         exit(1);
      }
      next_fibonacci_num = first_fibonacci_num + second_fibonacci_num;
      first_fibonacci_num = second_fibonacci_num;
      second_fibonacci_num = next_fibonacci_num;
   }

   return second_fibonacci_num;
}

unsigned long long fibonacci_memo(int num)
{
   if (memo[num] != 0)
   {
      return memo[num];
   }

   memo[num] = chosenFunc(num);
   return memo[num];
}

/* Since overflow happens when exceeding max num, Check if adding second num would cause overflow*/
int overflow_check(unsigned long long first_num, unsigned long long second_num)
{
   if (ULLONG_MAX - first_num < second_num)
   {
      return 1;
   }
   
   return 0;
}

int main(int argc, char *argv[])
{
   int command_line_integer = atoi(argv[1]);
   char command_line_letter = argv[2][0];

   /* Subtract 1 as the first number in fibonacci sequence is 0 */
   int num_to_fibonacci = command_line_integer - 1;
   unsigned long long fibonacci_result;

   if (command_line_letter == 'r')
   {
      chosenFunc = fibonacci_r_wrapper;
   }
   if (command_line_letter == 'i')
   {
      chosenFunc = fibonacci_i_wrapper;
   }

   fibonacci_result = fibonacci_memo(num_to_fibonacci);

   printf("%llu\n", fibonacci_result);
   return 0;
}
