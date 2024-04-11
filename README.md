# Simple Memory Examiner
Author: [Jack Robbins](https://www.github.com/jackr276)

## Introduction
This program contains a simple memory examiner/dumper that prints the addresses and contents of `argv` onto the console. For presentation purposes, all memory addresses are 8-byte aligned, meaning that the address ends in an `8` or `0`. This creates a consistent look for the printed contents, but does
have the side effect of printing out some of the surrounding memory contents that are not related to the program. This is a very simple program, written 100% in C, with no provided runner script since running this program is so easy.

## Running this program / Expected output
To run this program, download the [examine.c](https://github.com/jackr276/Simple-Memory-Examiner/blob/main/src/examine.c) source code and navigate to the directory where it is.

Compile the program by running:
```console
example@bash:~$ gcc examine.c -o examine
```

