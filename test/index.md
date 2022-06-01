---
layout: page
title: 'EEE243'
subtitle: 'Applied Computer Programming - Fall 2019'
---

## Periods (English)

|Day|Lecture|Lab|Room|
|---|---|---|---|
|Monday |0800-0850|0900-1050|3103 / 5200|
|Wednesday|1100-1150||3102|
|Thursday|1540-1630||3103|

## Course communications

All important course information will be published on this web site.

**Pro tip**: when printing pages from the course site, you'll get best results using Google Chrome.

I have an open-door policy; my office is in room S4106. You can drop by any time, but it's probably best to arrange a meeting in advance.


## Structure

My expectations of you (ethics, work delivery, etc.) were laid out in the first presentation on day one. If you're in need of a reminder, [open it up and take a look](../EEE243/#schedule).


## Lab reports

You do not have to submit formal lab reports. We have high expectations when it comes to code clarity, format and commenting. See the coding style document for details of what is required.
- [C coding style](/Resources/coding-style/) with examples: [bad](/Resources/coding-style/example-bad), [less-bad](/Resources/coding-style/example-less-bad), and [good](/Resources/coding-style/example-good)

## Resources
#### CLion

- [CLion Documentation](https://www.jetbrains.com/help/clion/meet-clion.html)
- Creating a CLion project<br>- [for the 3pi](project-3pi)<br>- [for the desktop (non-robot)](project-plain)
- [CLion debugging](clion-debugging)


#### 3pi programming

- [Programming the 3pi](load-3pi)
- [Determine the port number for the 3pi](config-win)
- [Pololu AVR Library Command Reference](http://www.pololu.com/docs/0J18)
- [Pololu 3pi Demo Program](https://raw.githubusercontent.com/pololu/libpololu-avr/master/examples_templates/3pi-demo-program/test.c)


#### C

- [Just enough C for 243](enough-c.pdf)
- [C Reference Card](http://www.math.brown.edu/~jhs/ReferenceCards/CRefCard.v2.2.pdf)
- [Strings in C](Labs/Lab4/strings/)
- [The GNU C Library Manual](http://www.gnu.org/software/libc/manual/html_node/index.html)
- [ASCII character table](ascii)

#### Old Exams

- [Old tests from 2004 to 2019](Exams/)

## Schedule
Hyperlinks beginning with `##-` are downloadable presentations of in-class lectures. <br>Hyperlinks following a `-` will bring you to a new page showing a small program in C. <br>All other hyperlinks are their own distinct webpages. 

| Date   | Lectures/Assignments                                  | Laboratories                                                     |
|---------|-------------------------------------------|----------------------------------------------------------|
|September 2<br><b>Labour Day</b>|---|---|
|September 4|[00-Intro](./Lectures/00-Introduction.pptx)<br>[01-Basic Concepts](./Lectures/01-Basic-Concepts.pptx)||
|September 5|[02-Algorithms](./Lectures/02-Algorithms.pptx)||
|September 9|[03-Basic I/O](./Lectures/03-I_O-base.pptx)<br>-[Temperature Converter](./Lectures/03-Solutions/temp_converter.c)<br>-[Leap Year Solver](./Lectures/03-Solutions/leap_year.c)|[Lab 1 - Greet the 3pi robot](./Labs/Lab1)|
|September 11|[04-Arrays](./Lectures/04-Arrays.pptx)||
|September 12|[05-Strings](./Lectures/05-Strings.pptx)<br>-[Nominal Roll](./Lectures/05-Solutions/nominal_roll.c)||
|September 16|[06-Computer Basics](./Lectures/06-Computer-Basic.pptx)|[Lab 2 - Take your 3pi for a walk](./Labs/Lab2)|
|September 18|[07-Pointers](./Lectures/07-Pointers.pptx)||
|September 19|Array & Pointer Exercises<br>-[Arrays! 2D - Print a 3x3 Matrix](./Lectures/07-Solutions/Arrays_2D-Print-3x3.c)||
|September 23|"Optional" Tutorial<br>-[Pointers! Print the Alphabet](./Lectures/07-Solutions/Pointers_Alphabet.c)<br>-[Pointers! Reverse an Array](./Lectures/07-Solutions/Pointers_Reverse-Order.c)<br>-[Pointers! Reverse a String](./Lectures/07-Solutions/Pointers_Reverse-String.c)|[Lab 3 - Spidey senses](./Labs/Lab3)|
|September 25|[08-Control-theory](./Lectures/08-Control-theory.pptx)||
|September 26|[Pointer Exercise](./Exercises/Pointer_Exercise/)||
|September 30|Optional Tutorial<br>-[Pointers! Count Letters](./Lectures/07-Solutions/Pointers_Count-Letters.c)<br>-[Pointers! Count Letters (The Hard Way)](./Lectures/07-Solutions/Pointers_Count-Letters-The-Hard-Way.c)|Lab 3 <i>continued</i>|
|October 2|[09-Memory-Model](./Lectures/09-Memory-Model.pptx)<br>-[Address Explorer](./Lectures/09-Solutions/address_explorer.c)||
|October 3|09-Memory-Model <i>continued</i><br>-[Dynamic Array](./Lectures/09-Solutions/dynamic_array.c)<br>-[Local Constants](./Lectures/09-Solutions/local_constant.c)||
|October 7|Optional Tutorial|Lab 3 <i>continued</i>|
|October 9|In-class Exercises<br>Midterm Prep||
|October 10|Midterm Prep||
|October 14<br><b>Thanksgiving</b>|---|---|
|October 16<br><b>Fall Break</b>|---|---|
|October 17|[2D Array Exercise: Petri Dish](./Exercises/Petri)||
|October 21|Midterm|Midterm|
|October 23|Discussion of midterm examination – theory|
|October 24|Discussion of midterm examination – practical|
|October 28|<i>Lab work</i>|[Lab 4 - Stringing You Along](./Labs/Lab4)|
|October 30|[10-Modules-and-Function-Pointers](./Lectures/10-Modules-Fct-pointers.pptx)<br>-[Function Pointers](./Lectures/10-Solutions/function_pointer.c)||
|October 31|[11-Struct-Enum-Typedef](./Lectures/11-Struct-Enum-Typedef.pptx)||
|November 4|11-Struct-Enum-Typedef <i>continued</i><br>-[Struct Comparison](./Lectures/11-Solutions/student_struct.c)|Lab 4 <i>continued</i>|
|November 6|[12-Linked-Lists](./Lectures/12-Linked-Lists.pptx)||
|November 7|12-Linked-Lists<i> continued</i><br>-[Linked List! Insert Node at Start](./Lectures/12-Solutions/linked_list.c)||
|November 11<br><b>Remembrance Day</b>|---|---|
|November 13|[13-Data-Structures](./Lectures/13-Data-Structures.pptx)||
|November 14|[15-Testing](./Lectures/15-Testing.pptx)<br>-[testing_ex.c](./Lectures/15-Solutions/testing_ex.c)||
|November 18|[14-Debugging](./Lectures/14-Debugging.pptx)|[Lab 5 - When Large Bar Codes Attack!](./Labs/Lab5)|
|November 20|[16-Inputs-Outputs](./Lectures/16-Inputs-Outputs.pptx)<br>-[Lorem.txt](./Lectures/16-Solutions/lorem.txt)||
|November 21|<i>Lab work</i>||
|November 25|<i>Lab work</i>|Lab 5 <i>continued</i> <b>and/or</b><br>[Robot Wars](./Labs/Lab6)|
|November 27|<i>Lab work</i>||
|November 28|<i>Lab work</i>|S5200 unavailable|
|December 2|Course wrap-up|Lab 5 and/or Robot Wars|
|December 4|Robot Wars Competition!|S5200 1800 hrs|
|December 11|Exam Date|S5200 0900 hrs|
