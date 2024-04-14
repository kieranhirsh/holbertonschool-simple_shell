# C - Simple Shell Project

## Overview
In this project, we are developing a simple shell program in the C programming language. The shell, also known as a command-line interpreter, serves as a user interface for interacting with the operating system.
###
Our shell will feature a prompt for user input, command parsing, and execution. We aim to incorporate essential shell functionalities such as running external commands, handling built-in commands, managing processes, and supporting features like piping and redirection. 
###
Additionally, our shell will be designed to accept both interactive and non-interactive sessions, providing flexibility for different usage scenarios. This collaborative effort allows us to explore the intricacies of shell programming, deepening our understanding of process management and system calls.

## Prerequisites


## Installation

Compile using the following line of code:
```sh
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Usage

```sh
//code
```

## Features


## Flowchart
The main program starts by identifying the call type, then directs it to the appropriate handling route (interactive function or user command execution). It continues processing commands or user input until the user chooses to exit.
- Non-Interactive Call:
  - The process starts with a block labeled "Start".
  - From there, it goes to a decision block that asks "Call non-interactive function?". If yes, it proceeds to the next block. If no, it goes to another decision block that asks "Is there any command?".
  - If the call is non-interactive, the program waits for a command.
  - Then, it goes to another decision block that asks "File available?". If the file is available, it reads the file and executes the command. If not, it goes back to the block labeled "Wait for command".
  - Once a command is executed, if the user wants to exit type "exit", the program exits. If no, it loops back to waiting for command.
- Interactive Call:
  - Similar to the non-interactive call, the process starts with a block labeled "Start".
  - From there, it goes to a decision block that asks "Interactive?". If yes, it proceeds to the interactive call function. If no, it goes to the non-interactive call function as described above.
  - If the call is interactive, the program calls the interactive function.
  - Then it goes to a block labeled "Get Line" which presumably gets a line of input from the user.
  - It then splits the line into separate words or phrases (presumably to parse a command).
  - After that, it executes the interactive command.
  - Finally, if the user wants to exit type "exit", the program exits. If no, it loops back to the block waiting for command.
###
![Flow chart.png](https://github.com/kieranhirsh/holbertonschool-simple_shell/blob/main/Flowchart%20(1).png)

## Authors
[Abdurahman Mahammedsied](https://github.com/amirasabdu)
###
[Kieran Hirsh](https://github.com/kieranhirsh)
