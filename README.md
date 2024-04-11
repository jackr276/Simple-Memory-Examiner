# Simple Memory Examiner
Author: [Jack Robbins](https://www.github.com/jackr276)

## Introduction
This program contains a simple memory examiner/dumper that prints the addresses and contents of `argv` onto the console. For presentation purposes, all memory addresses are 8-byte aligned, meaning that the address ends in an `8` or `0`. This creates a consistent look for the printed contents, but does
have the side effect of printing out some of the surrounding memory contents that are not related to the program. This is a very simple program, written 100% in C, with no provided runner script since running this program is so easy.

## Running this program & interpreting its output
To run this program, download the [examine.c](https://github.com/jackr276/Simple-Memory-Examiner/blob/main/src/examine.c) source code and navigate to the directory where it is.

Compile the program by running:
```console
example@bash:~$ gcc examine.c -o examine
```
Following this, run the program by entering `./examine`, followed by the arguments that you would like to examine.

Here is an example run and output: 
```console
example@bash:~$ ./examine Examine these argument strings

argv    | 00 00 7f fc a0 e7 4d d8 | 0x7ffca0e74ca0

argv[0] | 00 00 7f fc a0 e7 69 8f | 0x7ffca0e74dd8

argv[1] | 00 00 7f fc a0 e7 69 99 | 0x7ffca0e74de0

argv[2] | 00 00 7f fc a0 e7 69 a1 | 0x7ffca0e74de8

argv[3] | 00 00 7f fc a0 e7 69 a7 | 0x7ffca0e74df0

argv[4] | 00 00 7f fc a0 e7 69 b0 | 0x7ffca0e74df8

|2e(.) 00(\0) 00(\0) 00(\0) 00(\0) 00(\0) 00(\0) 00(\0)  | 0x7ffca0e76988

|65(e) 6e(n) 69(i) 6d(m) 61(a) 78(x) 65(e) 2f(/)  | 0x7ffca0e76990

|65(e) 6e(n) 69(i) 6d(m) 61(a) 78(x) 45(E) 00(\0)  | 0x7ffca0e76998

|61(a) 00(\0) 65(e) 73(s) 65(e) 68(h) 74(t) 00(\0)  | 0x7ffca0e769a0

|00(\0) 74(t) 6e(n) 65(e) 6d(m) 75(u) 67(g) 72(r)  | 0x7ffca0e769a8

|00(\0) 73(s) 67(g) 6e(n) 69(i) 72(r) 74(t) 73(s)  | 0x7ffca0e769b0

example@bash:~$
```
To explain this output, lets walk through from top to bottom examining what each printed line is. The first printed line is `argv`, followed by the contents in stored in argv, followed by the address of argv in memory. From this line, we can see that 
argv is storing `00 00 7f fc a0 e7 4d d8` at address `0x7ffca0e74ca0` in memory. Since argv is of type `char**`, it stores the address of a pointer, that being the `argv[0]` pointer. Moving down to the line labeled `argv[0]`, we can see that its address
of `0x7ffca0e74dd8` is what `argv` was storing. The address of each argument pointer, `argv[#]`, are printed out by the program in order. Since there are 4 command line arguments passed to the program, and since the name of the program(`./examine`) is itself
considered to be an argument pointer, we have five `argv` items printed out.

Below all of the `argv[#]` printing is the command line arguments themselves printed out in memory. Since the program makes all memory addresses 8-byte aligned by default, some extra `\0`s are printed out before the first argument. If you look closely at the letters
enclosed in `()` in the third and final block, you will see that they spell out `./examine Examine these argument strings` in sequential order. Since each row must be 8-bytes long, some extra bytes are printed out at the very end.
