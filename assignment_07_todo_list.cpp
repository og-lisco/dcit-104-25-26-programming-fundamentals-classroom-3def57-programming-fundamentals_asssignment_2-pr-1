// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 7
// =============================================================================
//
// TASK: Console-Based To-Do List Application
//
// Build a simple to-do list program that runs entirely in the console and
// allows the user to manage their tasks interactively using a menu.
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Task
//      - Prompt the user to type a task description.
//      - Add it to the list and confirm it was added.
//
//   2. View All Tasks
//      - Display all tasks currently in the list, numbered from 1.
//      - If the list is empty, print a friendly message saying so.
//
//   3. Delete a Task
//      - Show the list of tasks with their numbers.
//      - Ask the user which task number they want to remove.
//      - Remove the task and confirm the deletion.
//      - If the task number is invalid, print an error message.
//
//   4. Quit
//      - End the program with a farewell message.
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        TO-DO LIST MENU
//   ============================
//   1. Add task
//   2. View tasks
//   3. Delete task
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Enter task: Buy groceries
//   Task added: "Buy groceries"
//
//   Enter your choice (1-4): 2
//   Your Tasks:
//   1. Buy groceries
//   2. Study for exams
//
//   Enter your choice (1-4): 3
//   Enter task number to delete: 1
//   Task "Buy groceries" has been removed.
//
//   Enter your choice (1-4): 4
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Store tasks in a vector<string> (a dynamic list of text).
// - Use a loop to keep the menu running until the user chooses to quit.
// - Each feature MUST be implemented in its own function (see scaffold below).
// - Handle invalid menu choices gracefully (print an error, do not crash).
//

//
// =============================================================================
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void addTask(vector<string>& tasks) {
    string t;
    cout << "Enter task: ";
    cin.ignore();
    getline(cin, t);
    tasks.push_back(t);
    cout << "Task added: \"" << t << "\"\n";
}

void viewTasks(const vector<string>& tasks) {
    if (tasks.empty()) { cout << "Your tasks list is currently empty.\n"; return; }
    cout << "Your Tasks:\n";
    for (size_t i = 0; i < tasks.size(); i++) 
        cout << i + 1 << ". " << tasks[i] << "\n";
}

void deleteTask(vector<string>& tasks) {
    int idx;
    cout << "Enter task number to delete: ";
    cin >> idx;
    if (idx >= 1 && idx <= (int)tasks.size()) {
        cout << "Task \"" << tasks[idx - 1] << "\" has been removed.\n";
        tasks.erase(tasks.begin() + idx - 1);
    } else {
        cout << "Error: Invalid task number.\n";
    }
}

int main() {
    vector<string> tasks;
    int choice = 0;
    while (choice != 4) {
        cout << "=================================\n         TO-DO LIST MENU\n=================================\n";
        cout << "1. Add task\n2. View tasks\n3. Delete task\n4. Quit\nEnter your choice (1-4): ";
        cin >> choice;
        cout << "\n";
        
        if (choice == 1) addTask(tasks);
        else if (choice == 2) viewTasks(tasks);
        else if (choice == 3) deleteTask(tasks);
        else if (choice == 4) cout << "Goodbye!\n";
        else cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        cout << "\n";
    }
    return 0;
}
// =============================================================================
;

