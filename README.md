# Push_swap 🚀

## Summary 📋

Push_swap is a project focused on sorting data stored in a stack using a limited set of instructions, aiming to use the minimum number of operations possible.
To succeed, you need to experiment with various algorithms and select the most suitable one to optimize the sorting process.

---

## Introduction 📚

Push_swap is a simple yet effective algorithmic challenge: you must sort integers.
You have two stacks and a predefined set of instructions to manipulate them.
Your goal is to write a program in C named push_swap that calculates and outputs the shortest possible sequence of instructions to sort the input numbers in ascending order.

---

## Objectives 🎯

Writing a sorting algorithm is an important step in a developer’s journey, often the first exposure to algorithm complexity.
Understanding sorting algorithms and their efficiency is fundamental, especially since these topics are common in technical interviews.
This project emphasizes rigor, C programming, and algorithm basics, with a strong focus on complexity.

Sorting values is easy; sorting them efficiently is more challenging, especially since the optimal solution can vary depending on the input.

---

## Rules 📏

* You have two stacks: a and b
* Initially, stack a contains a set of integers (positive or negative), and stack b is empty
* The goal is to sort the numbers in stack a in ascending order using only the following operations:

| Instruction |                                 Description                                 |
| :---------: | :-------------------------------------------------------------------------: |
| sa          | Swap the first two elements of stack a. No effect if less than two elements |
| sb          | Swap the first two elements of stack b. No effect if less than two elements |
| ss          | Perform sa and sb simultaneously                                            |
| pa          | Push the top element of stack b onto stack a. No effect if b is empty       |
| pb          | Push the top element of stack a onto stack b. No effect if a is empty       |
| ra          | Rotate stack a upwards (first element becomes last)                         |
| rb          | Rotate stack b upwards (first element becomes last)                         |
| rr          | Perform ra and rb simultaneously                                            |
| rra         | Reverse rotate stack a (last element becomes first)                         |
| rrb         | Reverse rotate stack b (last element becomes first)                         |
| rrr         | Perform rra and rrb simultaneously                                          |

---

## Program Requirements 🖥️

* Your program must be named push_swap.
* It accepts a list of integers as arguments representing the stack a (the first argument is the top of the stack)
* The program prints the shortest possible list of instructions (one per line) to sort the stack a in ascending order
* If no arguments are provided, the program outputs nothing
* On invalid input (non-integers, duplicates, overflow), it prints Error followed by a newline on standard error
* Allowed functions include read, write, malloc, free, exit, and any libft functions you provide
* Global variables are forbidden
* Your Makefile should compile your program without relinking unnecessarily
* Your program’s output will be tested for correctness and minimal instruction count

### Prformance Tests ⚡

Sort 100 random numbers in fewer than 700 operations
Sort 500 random numbers in fewer than 5500 operations

---

## Checker Program 🌟

* Create a program named checker to verify that a list of instructions properly sorts the input stack
* Checker takes a list of integers as arguments (stack a)
* It reads a list of instructions from standard input, one per line
* It executes those instructions on the stacks
* If after executing all instructions, stack a is sorted and stack b is empty, it prints OK
* Otherwise, it prints KO
* On invalid input or instruction errors, it prints Error to standard error
* The program must handle errors gracefully
