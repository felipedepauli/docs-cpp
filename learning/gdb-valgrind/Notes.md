```
continue
``` 

### First steps
You can initialize the GDB using start. It will look up for the main function inside your programa.
```
start (or s)
``` 
If it found it, then the program begins to run line by line. To get the next line, you use the command next.
```
next (or n)
```
"This command is very useful, but you have to understand that it only advances one line in the same function. If you have a function, it will show your calling, but it will not enter inside the function. We will see it after."

If you want the program go on quicly, you can execute the run command. It will run up to the next breakpoint. Then, let-s do it without a breakpoint and then using a breakpoint.
```
run
```
Now, with a breakpoint. 
```
break 5
run
```
Let's go to next breakpoint.
```
break 5
break 16
run
next 
```
Notice after you set at least one breakpoint, the next commando takes you to next breakpoint, not to the next line.

You can use break using names instead line numbers.

```
break main
break myFunction
```
If you use next, you will continue going line by line. If you want go to the next breakpoint, you can use continue.
```
continue
``` 
And to end the execution, you can use the kill command.
```
kill
``` 
You can look the process ID (PID) of the process that you are running inside the GDB. You have to use the following command:
```
info inferiors

``` 


### Passing Args
If you want to pass argments to the binary, you have to execute the gdb using --args and the arguments.
```
g++ -ggdb args.cpp -o args.o
gdb --args ./args.o 20

```
In this example, when you run the program inside GDB, you are going to have a loop from 0 to 20 instead to 10000.