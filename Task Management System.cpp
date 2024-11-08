#include <iostream>
using namespace std;

struct taskNodes {
    string taskHead;
    string taskDesc;
    int taskNumber;
    bool completed;
    taskNodes* next;
    taskNodes* prev;
};

struct SectionNodes {
    string Name;
    taskNodes* task;  // Each section has its own task list
    SectionNodes* next;
    SectionNodes* prev;
};

// Function to create and add a new task to the specific section's task list
void newTask(taskNodes*& headOfTask) {
    taskNodes* newt = new taskNodes;

    string TH;
    string TD;
    int TN;

    cout << "Enter heading of the task = ";
    cin.ignore();
    getline(cin, TH);
    cout << "Enter description of the task = ";
    getline(cin, TD);
    cout << "Enter the task number (must be unique) = ";
    cin >> TN;

    newt->taskHead = TH;
    newt->taskDesc = TD;
    newt->taskNumber = TN;
    newt->completed = false;
    newt->next = NULL;
    newt->prev = NULL;

    if (headOfTask == NULL) {
        headOfTask = newt;  
    } else {
        headOfTask->prev = newt;
        newt->next = headOfTask;
        headOfTask = newt;  
    }
}

// Task menu for each section's specific task list
void taskmenu(taskNodes*& headOfTask) {
    char ch;
    cout << "Enter 'a' to enter a new task\n";
    cout << "Enter 'b' to delete a task (not implemented)\n";
    cout << "Enter 'c' to mark a task completed (not implemented)\n";
    cin >> ch;

    switch (ch) {
        case 'a':
            newTask(headOfTask);
            break;
        case 'b':
            // deleteTask(headOfTask); (to be implemented)
            break;
        case 'c':
            // completedTask(headOfTask); (to be implemented)
            break;
    }
}

// Function to display all sections and their respective tasks
void display(SectionNodes* head) {
    SectionNodes* temp = head;

    while (temp != NULL) {
        cout << "Section: " << temp->Name << endl;

        taskNodes* taskTemp = temp->task;  // Traverse this section's task list
        while (taskTemp != NULL) {
            cout << "  Task: " << taskTemp->taskHead << ", Desc: " << taskTemp->taskDesc << ", Number: " << taskTemp->taskNumber << endl;
            taskTemp = taskTemp->next;
        }
        temp = temp->next;
        cout << endl;
    }
}

// Function to create a new section and allow adding tasks to that section
void newSection(SectionNodes*& head, string name) {
    SectionNodes* newSec = new SectionNodes;
    newSec->Name = name;
    newSec->task = NULL;  // Initially, no tasks in this section
    newSec->next = NULL;
    newSec->prev = NULL;

    if (head == NULL) {
        head = newSec;  // First section
    } else {
        newSec->next = head;
        head->prev = newSec;
        head = newSec;  // New section added at the beginning
    }
    taskmenu(newSec->task);  // Create tasks specifically for this section
}

// Function to delete a section by name
void delSection(SectionNodes*& head, string name) {
    if (head == NULL) {
        cout << "No section to delete!" << endl;
        return;
    }

    SectionNodes* temp1 = head;
    SectionNodes* temp2 = NULL;

    if (head->Name == name) {
        head = head->next;
        if (head) head->prev = NULL;
        cout << "Section deleted" << endl;
        display(head);
        delete temp1;
        return;
    }

    while (temp1 != NULL && temp1->Name != name) {
        temp2 = temp1;
        temp1 = temp1->next;
    }

    if (temp1 == NULL) {
        cout << "Section not found!" << endl;
        return;
    }

    temp2->next = temp1->next;
    if (temp1->next != NULL) {
        temp1->next->prev = temp2;
    }
    cout << "Section deleted" << endl;
    display(head);
    delete temp1;
}

int main() {
    SectionNodes* head = NULL;
    char choice = 'y';
    string t;

    do {
        cout << "Enter 'N' to stop!\n";
        cout << "Enter '1' to add a new section\n";
        cout << "Enter '2' to delete a section\n";
        cout << "Enter '3' to display all sections and tasks\n";
        cin >> choice;

        switch (choice) {
            case '1':
                cout << "Name of new section = ";
                cin.ignore();
                getline(cin, t);
                newSection(head, t);
                break;
            case '2':
                cout << "Name of section to delete = ";
                cin.ignore();
                getline(cin, t);
                delSection(head, t);
                break;
            case '3':
                display(head);
                break;
        }
    } while (choice != 'N');

    return 0;
}
