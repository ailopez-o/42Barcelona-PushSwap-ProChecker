# 42-push_swap PRO CHECKER

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/ailopez-o/42Barcelona-push_swap?color=lightblue" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/ailopez-o/42Barcelona-push_swap-prochecker?color=critical" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/ailopez-o/42Barcelona-push_swap-prochecker?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/ailopez-o/42Barcelona-push_swap-prochecker?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/ailopez-o/42Barcelona-push_swap-prochecker?color=green" />
</p>

## Visual Checker to Debug the development of Push_Swap Proyect

<p align="center">
	<img src="https://github.com/ailopez-o/42Barcelona-push_swap/blob/main/img/push_swap_2.png" />
</p>

The main goal is to provide a useful and visual tool to see inside yout algorithm of sorting and try to get your bugs.

Is works like the oficial checher but with GUI and step by step functionality

Pull files ↙️
```bash
git clone --recursive https://github.com/ailopez-o/42Barcelona-PushSwap-ProChecker.git
```
Compile both push_swap & checker ↙️

```bash
$ make
```
### Execution example
```

$>ARG="4 67 3 87 23"; ./push_swap $ARG | ./pro_checker $ARG
OK
```


### PushSwap Game rules

* The game is composed of 2 stacks named a and b. <br>
* To start with: <br>
◦ a contains a random number of either positive or negative numbers without
any duplicates. <br>
◦ b is empty <br>
* The goal is to sort in ascending order numbers into stack a. <br>
* To do this you have the following operations at your disposal: <br>

| Command       | Description                                                                           |
| ------------- | --------------------------------------------------------------------------------------| 
| <b>sa</b>     | swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements). |
| <b>sb</b>     | swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements). |
| <b>ss</b>     | sa and sb at the same time. |
| <b>pa</b>     | push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty. |
| <b>pb</b>     | push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty. |
| <b>ra</b>     | rotate a - shift up all elements of stack a by 1. The first element becomes the last one. |
| <b>rb</b>     | rotate b - shift up all elements of stack b by 1. The first element becomes the last one. |
| <b>rr</b>     | ra and rb at the same time. |
| <b>rra</b>    | reverse rotate a - shift down all elements of stack a by 1. The flast element becomes the first one. |
| <b>rrb</b>    | reverse rotate b - shift down all elements of stack b by 1. The flast element becomes the first one. |
| <b>rrr</b>    | rra and rrb at the same time. |

### Sorting example

```
-------------------------------------------------------------------------------------------------------
Init a and b:
2
1
3
6
8
5
_ _
a b
-------------------------------------------------------------------------------------------------------
Exec sa:
1
2
3
6
8
5
_ _
a b
-------------------------------------------------------------------------------------------------------
Exec pb pb pb:
6 3
5 2
8 1
_ _
a b
-------------------------------------------------------------------------------------------------------
Exec ra rb (equiv. to rr):
5 2
8 1
6 3
_ _
a b
-------------------------------------------------------------------------------------------------------
Exec rra rrb (equiv. to rrr):
6 3
5 2
8 1
_ _
a b
-------------------------------------------------------------------------------------------------------
Exec sa:
5 3
6 2
8 1
_ _
a b
-------------------------------------------------------------------------------------------------------
Exec pa pa pa:
1
2
3
5
6
8
_ _
a b 
-------------------------------------------------------------------------------------------------------
```
This example sort integers from a in 12 instructions.

### The checker
* You have to write a program named checker, which will get as an argument the
stack a formatted as a list of integers. The first argument should be at the top of
the stack (be careful about the order). If no argument is given checker stops and
displays nothing.
* Checker will then wait and read instructions on the standard input, each instruction
will be followed by ’\n’. Once all the instructions have been read, checker will
execute them on the stack received as an argument.
* If after executing those instructions, stack a is actually sorted and b is empty, then
checker must display "OK" followed by a ’\n’ on the standard output. In every
other case, checker must display "KO" followed by a ’\n’ on the standard output.
* In case of error, you must display Error followed by a ’\n’ on the standard error.
Errors include for example: some arguments are not integers, some arguments are
bigger than an integer, there are duplicates, an instruction don’t exist and/or is
incorrectly formatted.

#### Checker example
```
$>./checker 3 2 1 0
rra
pb
sa
rra
pa
OK
$>./checker 3 2 1 0
sa
rra
pb
KO
$>./checker 3 2 one 0
Error
```

### The “push_swap” program
* You have to write a program named push_swap which will receive as an argument
the stack a formatted as a list of integers. The first argument should be at the top
of the stack (be careful about the order).
* The program must display the smallest list of instructions possible to sort the stack
a, the smallest number being at the top.
* Instructions must be separaed by a ’\n’ and nothing else.
* The goal is to sort the stack with the minimum possible number of operations.
During defence we’ll compare the number of instructions your program found with
a maximum number of operation tolerated. If your program either displays a list
too big or if the list isn’t sorted properly, you’ll get no points.
* In case of error, you must display Error followed by a ’\n’ on the standard error.
Errors include for example: some arguments aren’t integers, some arguments are
bigger than an integer, and/or there are duplicates.

#### Pushswap Example
```
$>./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
$>./push_swap 0 one 2 3
Error
$>
```

### Execution example
```
$>ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
6
$>ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
OK
$>
```

#### README copyright: https://github.com/sshiling


## Useful Links

- [42 Push-Swap notion](https://www.notion.so/Push_swap-21758af851874d70a09c854ae200a0ae)
- [Least amount of moves](https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&ved=2ahUKEwiLrP6CpdvvAhXmH7kGHZ21CQ0QFjACegQIBBAD&url=https%3A%2F%2Fmedium.com%2F%40jamierobertdawson%2Fpush-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a&usg=AOvVaw2KbZDpsvEv2ry63D-uw2Zx)
- [Example and Pyviz](https://github.com/anyaschukin/Push_Swap)
- VIDEO https://www.youtube.com/watch?v=7KW59UO55TQ
- Sort Algorithm: 

	- https://lamfo-unb.github.io/2019/04/21/Sorting-algorithms/
	- https://zainab-dnaya.medium.com/fastest-push-swap-algorithm-2f510028602b
	- Radix: https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e

- Push_Swap testers: 

	- https://github.com/lmalki-h/push_swap_tester
	- https://github.com/laisarena/push_swap_tester
	- https://github.com/LeoFu9487/push_swap_tester

- Visualizer: 

	- https://github.com/o-reo/push_swap_visualizer
