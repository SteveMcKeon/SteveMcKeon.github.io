---
title: 'Lab 1 : Linux Command Line'
---

### Objective

The goal of this one-week lab is to familiarize yourself with the Linux command line environment and to practice some basic C programming.  

### Lab Instructions

Read the following sections, they will provide you the bulk of the information you need to complete the [tasks](./#tasks) and answer the [questions](./#questions) that you will need to submit.     

### Introduction
Many of you may be wondering what the usefulness of the command line is. For most users of modern computers, the Graphical User Interface (GUI) is the only way to interact with the computer. The command line, however, offers many benefits such as the ability to perform complex tasks more quickly and ‘pipelining’ various tasks into a single group of actions that can be performed without any further user input.  Consider a simple example such as writing to a file the list of all files ending in `.txt` or all those containing the term EEE335. A slightly more complex example would be to take the output of one program and pass it to another and then write the result to a file. All of these tasks would take a relatively long time to do manually with the GUI, but are done quickly at the command line.

In general, the command line refers to a program called a shell. This program is responsible for taking user input and relaying it to the operating system. In most Linux distributions, the version of the shell used is BASH, an acronym for <b>B</b>ourne <b>A</b>gain <b>SH</b>ell. In Windows, you can access an officially named Windows Command shell by searching for the `cmd.exe` program on the Start menu or similarly, a Powershell <i>shell</i>.  It is also possible to install Windows Linux <i>shell</i> emulators such as `Cygwin` or `MinGW`

In this lab you will have the chance to use basic commands to accomplish tasks such as file system browsing and file and directory manipulation.

### Starting the Virtual Machine

Since the lab computers use the Windows 10 operating system, we will use a virtual machine on these computers to be able to use Linux. There are several types of virtualization software. The one we will use for the course is called VirtualBox and is a free software developed by Oracle. Since the software is free, you can also install it on your personal computer.

The nomenclature for virtual machines is to call the operating system on which the virtualization software works (e.g. VirtualBox) the host system (Host OS) and the one running in the software, the guest system (Guest OS). In the case of the lab computers, Windows 10 is the host OS and Linux is the guest OS.

For each lab in this course, you will be provided with a Linux image adapted to the purpose of the laboratory.  The image for today’s lab can be found here:  `L:\Electrical and Computer Engineering\435\EEE435_server.7z`. To use this image, first copy it to your Documents folder:  `C:\Users\<your name>\Documents`.  Next, unzip this compressed file by right-clicking on it, selecting 7-Zip, then extract it to your current folder.  Once this is done, move to your EEE435_server folder, right click on the `EEE435_server.vbox` file and select `Open with…`.  The option presented to you will be <b>VirtualBox Manager</b>, select this application by double clicking on it.  Note that if you are trying to use VirtualBox and the image provided on your personal computer, you may need to enable the virtualization option in the BIOS.

A shared folder has already been set up for you, it will be required in order to get the necessary information for you to complete your lab report.  On your host OS, the shared folder is `C:\Users\Public\Public Documents` directory, on your guest OS it is `/home/user/share`.

If your guest OS did not launch automatically, you can start it now, you can launch the guest operating system by selecting it from the OS list (it's called EEE435_server) and pressing the `Start` button at the top of the VirtualBox window.

Linux will execute the boot sequence and finally arrive at a screen asking for your username and password. These are respectively `user` and `password`.

### First Steps in Linux

You are now in a very light version of Linux. As you may have noticed, no GUI is installed. This is intentional to enable you to practice your command line skills and better understand that the GUI is not a central part of the operating system, but rather another application.  In following labs you will have access to a GUI and will access the shell from software called terminal emulator.

The Linux distribution we will use for the course is called Ubuntu.  After entering your username and password, you should see something like `user@ubuntu: ~ $`. This is the command prompt. The first part `user` is your username and `ubuntu` is the name of the machine. `~` Refers to your `home` directory, your present working directory. The `$` indicates that you are not in administrator mode. If you were logged in with a root account, the `$` symbol would be replaced by `#`.

The command prompt is where you can enter the commands you want to execute. You can enter anything at the prompt, but of course the shell only recognizes some commands. If you enter an invalid command, the shell will return a message telling you that the command could not be found (`command not found`).

### A Quick Look at the File System

In Linux, the directory tree starts in the `root` directory instead of Windows where the tree starts with the disk name (eg `C:\`). We refer to the `root` directory with the slash, `/`.

Note that the forward slash is used in Linux rather than the back slash (`\`) used in the Windows command line environment. A location in the tree is always in the form `/home/user/`. Your present working directory (`pwd`) is the location where you are in the tree.

You can display your present working directory on the screen using the `pwd` command. The path displayed is probably `/home/user/`. You can view a list of all files and directories in the working directory by using the `ls` command. This command should display something similar to `Documents Music Pictures`. You can also view the contents of any directory by adding the path of the directory after the `ls` command. For example, if you want to display the contents of the root directory, just write `ls /`.

When you display your present working directory with the `pwd` command, the path displayed is called an absolute path. That is, it starts with the root directory and descends the tree to the directory in question. It is possible to refer to a directory according in relative terms to the working directory. For example, the absolute path to the Documents directory in your present working directory is `/home/user/Documents` and the relative path is `Documents` if your working directory is `/home/user/`.

You can change your working directory at any time by using the `cd` command and either the absolute or relative path. For example, if you want to change the working directory to `/home/user/Documents`, you can either use the command `cd /home/user/Documents` or `cd Documents`. Note that the second option only works from the directory containing the target directory. If you were in `/home/user/Music`, you would not be able to access this directory with `cd Documents`. It would be necessary to use the absolute path (unless of course, the  `./Music` directory also contained a sub-directory named `Documents`).

In each directory in Linux, there are two special entries `.` and `..` also called the dot and dot dot. These entries refer respectively to the current directory and the parent directory. From `/home/user/Documents`, you can go back to the directory `/home/user /` using `cd ..`. You can combine the `..` with the slashes. For example, it is possible to go to the root directory from `/home/user/` by using `cd ../..`.

You can return to your home directory with the `cd` or `cd ~` command and return to the previous directory by typing `cd -`.

### Options

Most commands in Linux offer several options. The usual format is `command –options arguments`. For example, it is possible to display more details (long format) on the current directory with `ls -l`.

It is possible to have more than one option assigned to a command. In such a case, the options follow each other after the dash. Thus, `ls` offers the option of sorting in order of the moment of the last modification. If we wanted to display the long format and order by modification time, we could use the `ls -lt` command.

In general, options with only one letter are preceded by a hyphen while their long format (if present) is preceded by two dashes. For the `ls` command, there is an option to reverse the order which is usually in alphabetical order. This option can be called either with `-r` or `--reverse`. If we take the previous example we could display in descending order of the last modification time using the reverse option `ls -ltr` or `ls -lt –reverse`.

If you want to see all the options available for an order, you have some options. The first is to use the `man` command followed by the command that interests you. `man` will display the manual page for the command manual and explain its purpose, options, arguments and syntax. The second option is to refer to an online version of the manual like this [one](http://man7.org/linux/man-pages/dir_section_1.html).

### Long Format – Some More Detail

When you ran the `ls -l` command, a list of files and directories was displayed with a series of characters, words, and numbers that you may not be familiar with.

Let's take a specific example. In your home directory, there should be a file called `test.txt`. The information displayed for this long format file should look like this:

```bash 
-rw-rw-r-- 1 user user 656 Aug 23 15:27 test.txt
```

The first set of characters indicates the access rights. The first character is either a dash or a d and indicates whether it is a directory (`d`) or not (`-`). The following 9 characters are grouped into three parts: the file owner, the owner group, and all other users. Each part indicates the read (r for read), write (`w` for write) and execute (`x` for execute) rights. A dash in place of the letter indicates that the owner, group or others do not have this right. `-rw-r-r--` therefore indicates that `test.txt` is not a directory, that the owner has the right to read and write, but not execute. The owner group and other users have only the right to read.

The following character is a `1` that indicates the number of material links to the file. `user` and `user` respectively, indicates the owner of the file and the owner group. In the case of the owning group, a user who is a member of a group will have the rights associated with that group. For example, if the user `Igor` is a member of the `user` group, he will only be able to read the file. It would be the same for all other members of the `user` group. Note that here the user name is the same as the group name, but this is just a coincidence (or almost).

The next set of digits, here `656` is the file size in bytes. The date and time displayed (`Aug 23 15:27`) are those of the last modification. Note that if the file had been modified in a previous year, the year would be displayed rather than the time (`Aug 23 2018`) as is the case for the `~/image.jpg` file. Finally, the last part of the entry is the name of the file or directory, here `test.txt`.

### File Type

As we will discuss later in the course, Linux has no concept of extensions. If a file has the extension `.txt`, the extension is only there by convention and to help the users to quickly recognize what type of file it is. On the other hand, Linux offers a command to give more details on a file in particular. The command `file file_name` will display a brief description of the content on the screen. So, if you are doing `file test.txt`, you should see `test.txt: ASCII text`.

If we do the same thing with `image.jpg`, we see 
``` bash
image.jpg: JPEG image data, JFIF standard 1.01, resolution (DPI), density 72x72, segment length 16, baseline, precision 8, 1200x675, frames 3
```

### Display Contents of a File

Many Linux files are human readable. The `less` command is used to display the contents of a file on the screen and to navigate within it. Thus, `less test.txt` will display the contents of the file. Note that you can only read the content since `less` is not a text editor.

To exit `less`, press the `q` key.

### Command History and Auto-Completion

We have entered several commands so far and it is possible that we would like to repeat one or more of them. The version of the shell installed on your virtual machine provides the `history` of the commands that were executed. You can see the complete list with the history command, but if you want to navigate the history, the up and down arrows are the most convenient way.

Another shell feature that will make your life easier is auto-completion. If you start writing `cd Doc` and press the tab key, the shell will fill in the name for you (if it exists in the working directory). `cd Doc` would become `cd Documents/` and you only have to press the enter key to execute the command. This feature is especially useful when the name of a file or directory is long.

The auto-completion function also works with the commands. You can start writing a command like `less` and press the Tab key to have the shell complete the command. 

Both for file names and commands, if there are more than one possibility, you must press tab twice for all the possible matches to be displayed. If too many possibilities exist, the shell will ask if you want to display them all.

### Hidden Files

Files whose names start with a period (e.g.  `.bash_history`) are hidden files that will not be displayed with the basic `ls` command. One of the options in `ls` is to display all these files.

### Linux File System Organization

The Linux root directory, the `/` directory, contains many subdirectories with important roles. The `/boot` directory, for example, contains the Linux kernel, `/home` contains users' home directories. This [Wikipedia](https://en.wikipedia.org/wiki/Filesystem_Hierarchy_Standard) page provides a more detailed description of the role of different directories.

### Modifying Your Environment

So far, the commands we have seen are rather simple and their usefulness may seem rather trivial. In this section we will see how to manipulate our environment by copying, renaming, moving, creating and deleting files and directories.

As some of you noticed, some tasks shown here are sometimes easier done using a GUI. However, we will see later that the command line shell offers features that make it extremely convenient to do bulk operations on the file system.

### Copying

In linux it is possible to copy a file or directory using the `cp` command. This offers the possibility to copy inside the same directory or in a different directory. `cp test.txt test.txt.bkp` creates a test copy in the same directory while `cp test.txt Documents/test.txt.bkp` creates a copy in the `Documents` directory.

As you may have noticed, the copy command allows you to give the name you want to copy.

When you want to copy a directory and its contents, you must use the recursion option (`-r`). To create a copy of `Documents/` called `Documents.bkp/`, you could use `cp -r Documents/ Documents.bkp`. 

It is also possible to copy more than one file at a time using `cp file1 file2 destination/` or `cp source/* destination/`. The asterisk in the last example is called a wildcard and indicates to copy all the files in the source directory. Metacharacters can be combined to create complex expressions. For example, `cp *.html destination/` will copy all html files in the working directory to the `destination` directory.

### Move and Rename

The `mv` command lets you move or rename a file or directory. The command works in much the same way as `cp` except that the file or directory is removed from the original directory. `mv Documents.bkp Documents2.bkp` renames `Documents.bkp`. After executing the command, `Documents.bkp` no longer appears in the list, `Documents2.bkp` appears in its place.  The move command can also be used to move files between different directories. Just like for `cp`, it is possible to manipulate several files at once.

### Create a Directory

It is possible to create directories with the command `mkdir`. This allows you to create one or more directories at a time.

`mkdir test-folder` creates a single directory in the working directory.  Similar to other commands, you can also make directories in other file paths, not just your present working directory.

### Links

In Linux, there are two types of links, symbolic links and hard links. Symbolic links create a pointer to a file or directory without creating a copy. This is especially useful when a program uses a file whose versions change. The program can refer to a file called `file` which is a symbolic link pointing to the file `file-v1` for example. If it is updated to version 2, you do not need to change the program. All we need to do is update the link file to point to `file-v2`.

It is possible to know if a file is a link in the description given by `ls -l` and the color of the entry. In the Linux distribution we use, the links appear in cyan and their long entries look like 
``` bash
lrwxrwxrwx 1 user user 11 Aug 23 15:27 file-link -> ../file.txt 
```
 
where the `l` at the beginning of the entry indicates that it is a link. In addition, `file-link -> ../file.txt` indicates that file-link points to a file called `file.txt` located in the parent directory.

Symbolic links are created using the `ln` command with the `-s` option.

For hard links, it is possible to have two entries pointing to the same place on the disk. We will talk about it later in class, but it should be noted that these are not used as much as the symbolic links.

### Delete Files and Directories

The `rm` command is used to delete files or directories. The `-r` option, for recursive, must be used for directories. When symbolic links exist and the file to which they point is deleted, it is said that the links are broken. However, it is possible to delete a link without affecting the file to which it points.

### Redirection

In Linux, everything is a file. Thus, the output and errors of most commands are written to files: standard output (`stdout`) and standard error (`stderr`). These files are not written to disk, but rather to the screen.

Input/Output (I/O) redirection allows you to redefine the destination of a standard output. The > operator is used to redirect the output of a command. For example, `ls /usr/bin > output.txt`, sends the output of `ls` to the `output.txt` file.  It is possible to create an empty file using the same operator without the preceding command. So, `> empty-file.txt` creates an empty file.

### Concatenation

The `cat` command is useful for displaying the contents of files (e.g. `cat file.txt`) on the screen, but also for combining different files (e.g. `cat file1 file2 file3> files-combined`).

### Pipelines

We have already talked about standard outputs, but since everything is a file, there is also a standard input (stdin). This is usually linked to the keyboard. Pipelines, however, allow us to change this link so that the standard output of one command is tied to the standard input of another.

For example, it is possible to take the output of `ls` and redirect it to `less` to display the result. The operator `|` defines the pipeline(s). `ls /usr/bin | less` will show the contents of `/usr/bin` using the `less` program. It is possible to create long pipelines to perform complex operations.

### Text Editing

Until now, we have only manipulated existing files. It is possible, even without a graphical interface, to create and modify text.

There are different word processing systems running in the shell, but for this lab we will use an editor named <i>Vim</i>. Unlike the word processing software that you have probably encountered so far, <i>Vim</i> is modal. This means that the behavior of the keyboard inputs depend on the mode. In </i>insert</i> mode, the keys on the keyboard insert the corresponding characters into the file, while in the command mode, the keys are used to execute functions of the software (eg. save, exit, etc.).

We will not provide you with a complete tutorial for <i>Vim</i>. You can always refer to those available online (for example this [one](https://www.linux.com/learn/vim-101-beginners-guide-vim)). The purpose of this section is to introduce you to Vim enough so that you can create a text file, save it and exit.

To start <i>Vim</i>, just write <i>Vim</i> and the name of the file you want to edit. If the file does not exist, one will be created but you will need to name it.  When you start <i>Vim</i>, you are in command mode. If you try to write a sentence, <i>Vim</i> will probably complain that he does not understand the command unless you press a valid command key. You can switch to insert mode by typing `i`, the `--INSERT--` message should appear at the bottom of the screen. It is now possible to write your text.

Many Windows users are used to saving their work with the shortcut `Ctrl + s`. This combination does not work in <i>Vim</i>. When you want to save, you must return to command mode. This is possible by using the escape (`esc`). To save, all you need to do is write `:w`.

If you have finished writing in your file, you can quit using the command `:q`. If you want to leave quickly without saving, you can use the `:q!` or `ZQ` command. To exit and save at the same time, the `:wq` command can be used.  To save an exit a file only if modifications have been made, one could use the `:x` or `ZZ` commands.  Note that to issue these commands, you must first exit from the `Insert` mode by pressing the escape (`esc`) key.

There are many other commands that make <i>Vim</i> extremely powerful. You can take a look at them later. For those who doubt the usefulness of word processing software in the command line, despite its archaic look, <i>Vim</i> is still very much used by system administrators and analysts.

### Downloading

Now that we have seen many commands and even edited text in the <i>shell</i>, it should not be a surprise that you can also download files. The `wget` command is what you will use to accomplish that task. There are options to pass the username and password when a page is protected.

### Shutting Down the Virtual Machine

In Linux, the command `shutdown -h` now is the one that turns off the computer (or the virtual machine). Normally, this command can only be used by a member of the administrator group, but we have made an exception and you can also execute the command. Just use `sudo` before typing the command so that it runs as root.

### Tasks

We have now seen enough commands for you to perform tasks in our operating system without GUI.   Complete the tasks outlined below.

1. Create a directory called `eee335` in you home directory.
2. Create a sub-directory called `book`.
3. Download the file called book.tar using the following command:
```bash
wget –user EEE335 –password winmac http://mckeon.segfaults.net/EEE335/Labs/Lab1/Files/book.tar
```
4. Using the tar command and the appropriate options, untar the file. The content of the archive is a series of chapters. They should be in `/home/user/eee335/book` instead of `/home/user/eee335/book/book`.
5. Create a backup copy of the directory containing the chapters. Do not include the junk folder in the backup.
6. Create a cover page for the book. It does not need to be elaborate, but should at least include the:
* book title (Introduction to the BASH command line), 
* your name; and
* a version number (v. 1). 

    Call the file `cover_v1.txt`.
7. Combine the cover page and all the chapters in a file called `book_v1.txt`.
8. Modify the cover page so that it includes the name of the publisher (<i>Linux Press</i>). Make sure you keep a copy of the original cover.
9. Since the book will be re-generated every time a chapter or the cover page is modified, it would be useful to automate that part. Write a C program to combine the cover page and the chapters in one file. The following table outlines the requirements of your C program.

    <H4>Table 1:  C Program Requirements</H4>

    |Req_#|Description of Requirement|
    |1|Two arguments must be passed to your main program.|
    |2|The first argument is the path to the directory that contains the chapters and the cover page.|
    |3|The second argument is the file name of your book to be generated.|
    |4|The program creates this newly generated file in the same directory as the first argument passed to your program.|
    |5|Your program will include a loop that will add the chapters to your book.|
    |6|Your program must successfully operate, regardless from which directory it is executed.|

    Assume that the cover page is named <i>cover.txt</i> and that the chapters are named <i>1.chapter, 2.chapter,</i> etc. To compile your program, you will have to use `gcc` (Note: Do not cheat using the system() function that allows you to execute commands in the Linux shell, but instead use the functions of the standard C library to open, read, copy and modify files);

10. Test your program in your book directory. 
11. When you untarred the archive, a directory called `junk` was created. Delete it.
12. Using only one command, create a list of all the files and directories in `eee335` and all its subdirectories, and insert the result in a file called `list_eee335_lab1_Your_last_name.listing`, obviously replace `Your_last_name` by your own last name.
13. Using only one command, create a file called `history_eee335_lab1_Your_last_name.hist` that contains a history of all the commands that were executed. Note that all the commands you used to do those tasks should be there. If they are not, it will be assumed you did not actually do the work.

### Questions

1. Why does the BASH shell mean Bourne Again SHell?
2. Explain what a Linux distribution is.
3. Explain what a Linux Kernel is.
4. What does the `~` refer to in the file system?
5. What command would you use to print the content of the home directory located in root?
6. What is an ASCII file?
7. What `ls` option will display hidden files?
8. Why do we use hidden files?
9. In what directory is the root user's home directory?
10. What is the role of the root user?
11. In what directory are usually located a distribution's programs?
12. What command would you use to copy the content from a source directory to a destination one that already exists?
13. How would you create a folder called test in `/home/user/Documents` with only one command if your working directory is `/`?
14. Assuming that your working directory is `/home/user/Documents/backup`, and you do the command `ln -s file.txt file-link` for the `file.txt` located in `/home/user/Documents`. What would happen if you were to do the command `less file-link`, and what command would you use to fix it?
15. Using `ls` (without the `-l` option), how do you know the difference between a file and a directory?
16. What file that corresponds to the standard input is linked with the keyboard?
17. What is the purpose of the standard error?
18. In your home directory, there is a file called `eee435-exam-solutions.secret`, why can't you open it?

### Submissions
For this lab, you do not have to submit a formal report, though you will need to submit the following:
1. PDF document that includes your answers to the questions (include both the questions and answers)
2. A copy of `list_eee335_lab1_Your_last_name.listing`
3. A copy of `history_eee335_lab1_Your_last_name.hist`
4. The latest version of the book that was created with your C program
5. A copy of your C program (.c file)

The above files need to be submitted via a single compressed file (e.g. .zip or .7zip) with a meaningful name (e.g. `lab1_Your_last_name.zip`) and submitted via the course Moodle site.  Recall that you set up the share folder in your home directory allows you to share files between the host and guest OS.
