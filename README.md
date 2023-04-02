# PlannerProgram
Submission for the 4-1-23 PennWest-Cal Programming Club Code Jam

## Description
The program is meant to serve as a planner for keeping track of tasks. The user can type in tasks with a priority. A more important task should be designated with a lower priority (for example, a task with a priority of 1 is more important than one with 2). User's can view all their tasks, see the most important task, and delete tasks. This answers the Management prompt.

## Technical Aspects
The program is written in C++. The tasks are handled by a singly linked list. Each node has a description of type string, a priority of type int, and a next pointer. Functions related to the linked list are in list.cpp and list.h. The menu system is in main.cpp. The program runs in a console window.

## How to compile
I used MSYS2 G++ 12.2.0 to compile this program. Here is the command I used:

g++ main.cpp list.cpp -o main.exe

## How to operate the program
To insert a task:
  1. Choose 1 at the menu prompt.
  2. Enter a description.
  3. Enter a priority.
  4. The task is now in the planner.

To view the entire planner:
  1. Choose 2 at the menu prompt.
  2. All tasks will be displayed.

To view the task with the most importance (lowest priority):
  1. Choose 3 at the menu prompt.
  2. The task with the lowest priority is displayed.

To delete a task:
  1. Choose 4 at the menu prompt.
  2. Enter the priority of the task to delete.
  3. The task will be deleted.

To quit:
  1. Choose 5 at the menu prompt.
  2. The program will end.

## Potential Features
Here are some ways the program could be improved (certainly not all of them):
  * Load and store data from a file, so data is preserved across sessions.
  * Categories for tasks, such as school classes.
  * Due dates for tasks.
  * Notification system to remind the user to do tasks (such as a week before, a day before, etc)
  * Better interface.
