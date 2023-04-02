//Programming Club Code Jam Submission
//by Paul Shriner

#include <iostream>
#include <cstdlib>
#include <string>
#include "list.h"

using namespace std;

int getgooddata (std::string);
/*
    Description: Implement the sample error-checking loop as a function.
    Preconditions: The prompt to the user as a string.
    Postconditions: A integer value to be used for other purposes.
*/

int main () {
    //Declare+initialize variables
    bool quit = false, found = false, success = false;
    int prio = 0, choice = 0;
    string data = " ";
    
    //Create list objects
    List list1;

    //Welcome message
    cout << "Welcome to the Planner Program! \n";

    while (quit == false) {
        //Present user with menu options
        cout << "\nChoose from one of the following options: \n";
        cout << "1. Insert into your planner \n";
        cout << "2. Display your entire planner \n";
        cout << "3. Display the task you need to do now (lowest priority in planner) \n";
        cout << "4. Delete a task from the planner. \n";
        cout << "5. Quit \n\n";

        //Get user choice
        do {
            choice = getgooddata("Enter your selection here: ");
        } while (choice < 1 || choice > 5);

        //Insert
        if (choice == 1) {
            //Get task description, priority
            cout << "Please enter a description for your task: ";
            fflush(stdin);
            getline(cin, data);
            prio = getgooddata("Please enter a priority for your task: ");

            //Insert task
            success = list1.insert(data, prio);

            //Print success message
            if (success == false) {
                cout << "\nYou already have a task with that priority! \n"; 
            } else {
                cout << "\nTask inserted successfully. \n";
            }
        //Display entire list
        } else if (choice == 2) {
            cout << " \n" << list1 << " \n";
        //Display list with lowest priority
        } else if (choice == 3) {
            list1.search();
        //Delete a task
        } else if (choice == 4) {
            //Get the prio from the user
            prio = getgooddata("Please enter a priority for the task to remove: ");

            //Remove the task
            success = list1.remove(prio);

            //Print success message
            if (success == true) {
                cout << "\nYay you did something! \n";
            } else {
                cout << "\nA task with that priority does not exist! \n";
            }
        //Quit
        } else if (choice == 5) {
            //Goodbye message
            cout << "\nSee you later! \n";
            quit = true;            
        }
    }

    return 0;
}

//Implements sample error-checking loop as function
int getgooddata (string prompt) {
    int value = 0;

    cout << prompt;
    while(!(cin >> value) || cin.peek() != '\n' || value < 0) {
        cout << prompt;
        cin.clear();
        cin.ignore(30000, '\n');            
    }

    return value;
}