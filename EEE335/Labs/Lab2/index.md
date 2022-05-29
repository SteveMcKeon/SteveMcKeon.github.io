---
title: 'Lab 2 : Your Own Shell'
---

### Objective
The purpose of this one-week lab is to familiarize you with user space programming and using system calls.    

### Introduction
In the previous lab, you got a chance to navigate in the OS from the <i>shell</i>. In this lab, you are provided the awesome opportunity to implement your own simple version of the <i>shell</i>.

In Modern Operating Systems, 4th edition, Tanenbaum describes the basic functions of a <i>shell</i> in section 1.5.6 and provides the skeleton of such a <i>shell</i> in Figure 1.19.

```c
#define TRUE 1
while(TRUE) {                    // repeat forever
  type_prompt();                 // display prompt on screen
  read_command(cmd, params);     // read input from terminal
  if (fork() != 0) {
    // Parent code
    waitpid(-1, &status, 0);     // wait for child to exit
  } else {
    // Child code
    execve(cmd, params, 0);      // Execute command
  }
}
```

To summarize Tanenbaum, the simplest <i>shell</i>:
1. Waits for the user to input a command;
2. Analyzes the input to separate the command from the parameters;
3. If necessary, launches a new process with the appropriate program;
4. Waits for the child process to terminate; and
5. Starts over at step 1.

### Getting the Environment Ready
For this lab, we provide you an image of Linux (`L:\Electrical and Computer Engineering\435\EEE435_desktop.7z`) with graphical interface and the Eclipse C/C++ Development Tooling (CDT) integrated development environment (IDE). To use this image, follow similar steps to those followed during Lab 1.  The username is `user` and the password is `password`. We also provide you with a <i>shell</i> skeleton that you can find [here](./Files/lab2_start_code.zip). You will build your <i>shell</i> from this base code. Once downloaded, unzip the archive to your virtual machine's desktop. You should get a file called `lab2`. To import the project, start Eclipse and select `File -> Import -> General -> Existing Projects into Workspace`, then navigate to the `lab2` folder and make sure to select the `Copy projects into workspace` option before clicking `Finish`.

You must program in the linux virtual machine, the code provided will not work on Windows. 

### Requirements
#### User Inputs
When the <i>shell</i> starts, a welcome message is displayed on the screen and the command prompt `EEE335$` is displayed on the screen. The command prompt is the signal sent to the user to tell them that they can start entering commands.

You will need to implement the function that accepts the characters typed by the user and puts them into a data structure that will be used in subsequent steps. The user indicates that she or he has finished entering the command and arguments by pressing the enter key.

#### Input Analysis (parsing)
The user can enter anything at the command prompt. However, if he or she wants the <i>shell</i> to do something, commands and arguments must entered in the following format: 
```bash
<program name> <argument 1> <argument 2> ... <argument N>
```
For example, to copy `incoming.txt` file to `outgoing.txt` file, the user would write `cp incoming.txt outgoing.txt`. In this case, the name of the program is `cp` and arguments 1 and 2 are `incoming.txt` and `outgoing.txt`, respectively.

The <i>shell</i> must accept an arbitrary number of arguments, but we can assume for the purposes of the course that this number will never be greater than 64. It is also assumed that the length of commands and arguments will never be greater than 1024 characters.

#### Commands 
There are two types of commands in the <i>shell</i>, those that call programs that are integrated as part of the <i>shell</i>, and those that are a program located elsewhere in the file system.

For example, the `cd` command is part of the <i>shell</i>, but `sudo` is a program located in `/usr/bin/`. The `type` command in <i>Bash</i> or `which` in other <i>shells</i> tells you if the command in question is part of it. For example, `type sudo` indicates `sudo` is `/usr/bin/sudo` while `type cd` indicates `cd` is a <i>builtin</i> command.

For your version of the <i>shell</i>, you will have to support all programs located in `/usr/bin` and implement the following <i>builtin</i> commands (you must write your own versions):
*    exit
*    cd
*    ls
*    pwd

For programs located in `/usr/bin/`, you will need to create a child process using the `fork` function. Remember that `fork` only creates a copy of the parent process. You will need to use a mechanism to change the program executed by the child.

If the input command does not exist, the <i>shell</i> must return an error message.

### Questions
1. Why are there internal functions and others located elsewhere in the operating system?
2. In your program, do you call system calls directly? Explain your answer.
3. What are the possible benefits of writing your own version of the shell?
4. Why do we have a directory `/usr/bin`?
5. If you have a program called `my_program_x` located in `/usr/my_bin/my_program_x`, how would your shell access it?
6. What is the purpose of the `fork()` function?
7. What is the purpose of the `execve()` function?
8. Why should I use fork to call functions that are not internal (built-in)?
9. What is the difference between the `fork` and `execve` system calls?

### Lab Report
Your lab report must include a cover page, a brief introduction, discussion and conclusion.

Your discussion should explain how your shell works, what you learned, any discoveries you made, what was challenging and how you overcame any difficulties.  It should not be a list of followed steps or empty phrases about the importance of this lab. Be concise! A good discussion paragraph is better than 10 pages of fill.  The report should also include answers to the questions above. Be sure to include both the questions and your responses to each.

### Submission
You must submit your lab report as a pdf and your separate source code file via Moodle.  Use similar naming conventions as in Lab 1.

