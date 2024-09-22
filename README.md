# Third C program for 351

1. Adjust Assignment 2 as follows:

- Add memoization to (each) iterative and recursive.

- Do not change the underlying fib() routines, rename them to "fib_i_core" or some such. The original names ("fib_i," "fib_r"?) should become the place where the memoization is performed and where the fib_i_core() is called.

- You *may* need to duplicate the memoization code: once for iteration and once for recursion.

- Funsies (10 extra points): Can you create ONE memoization routine that will work for whichever type of fibbing is done?

   - *Hint* ```typedef unsigned long long *FibFunc(int fibIndex);``` creates a type with which you can create a *pointer* to a function: ```FibFunc chosenFunc``` that can be set based on params and called as ```(*chosenFunc)(fibNumberFromCommandLine)```.

- Test the appropriate variety of input numbers and note the times for both iterative and recursive. Record those in the sheet (add to the existing sheet) and upload the link again.

- How did this impact performance of each? Add some insights (your thoughts) to sheet.

- **Reminder** Only the wrapper routine knows anything about the memoization cache. It cannot/should not be accessed by the actual fib routines.

# Time to implement

The mod for this should take ~60 minutes, running it should take 15-20. This is harder, I grant you.

# Due date

Check in and submit by Monday 9/23 0600.

