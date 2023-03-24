#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Task {
private:
    int id;
    string name;
    string description;
    bool isComplete;

public:
    Task(int id, string name, string description, bool isComplete = false) {
        this->id = id;
        this->name = name;
        this->description = description;
        this->isComplete = isComplete;
    }

    int getId() {
        return id;
    }

    string getName() {
        return name;
    }

    string getDescription() {
        return description;
    }

    bool getIsComplete() {
        return isComplete;
    }

    void setIsComplete(bool isComplete) {
        this->isComplete = isComplete;
    }

    void update(string name, string description) {
        this->name = name;
        this->description = description;
    }
};

class TaskManager {
private:
    int nextId;
    vector<Task*> tasks;

public:
    TaskManager() {
        nextId = 1;
    }

    Task* createTask(string name, string description) {
        Task* task = new Task(nextId, name, description);
        nextId++;
        tasks.push_back(task);
        return task;
    }

    void deleteTask(Task* task) {
        for (auto it = tasks.begin(); it != tasks.end(); ++it) {
            if (*it == task) {
                tasks.erase(it);
                break;
            }
        }
        delete task;
    }

    vector<Task*> getTasks() {
        return tasks;
    }

    void printTasks() {
        for (Task* task : tasks) {
            cout << "ID: " << task->getId() << endl;
            cout << "Name: " << task->getName() << endl;
            cout << "Description: " << task->getDescription() << endl;
            cout << "Complete: " << (task->getIsComplete() ? "Yes" : "No") << endl;
            cout << endl;
        }
    }

    Task* findTask(int id) {
        for (Task* task : tasks) {
            if (task->getId() == id) {
                return task;
            }
        }
        return nullptr;
    }
};

int main() {
    TaskManager taskManager;

    while (true) {
        cout << "Welcome to Task Manager:" << endl;
        cout << "1. Create task" << endl;
        cout << "2. Update task" << endl;
        cout << "3. Delete task" << endl;
        cout << "4. View all tasks" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cout << "Enter your choice: \n";
        cin >> choice;

        if(choice == 1){
                
                string name, description;
                cout << "Enter task name: ";
                cin >> name;
                cout << "Enter task description: ";
                cin >> description;
                Task* task = taskManager.createTask(name, description);
                cout << "Task created with ID " << task->getId() << endl;
            }
        else if (choice == 2){
                int id;
                string name, description;
                cout << "Enter task ID to update: ";
                cin >> id;
                Task* task = taskManager.findTask(id);
                if (task == nullptr) {
                    cout << "Task not found" << endl;
                } else {
                    cout << "Enter new task name: ";
                    cin >> name;
                    cout << "Enter new task description: ";
                    cin >> description;
                    task->update(name, description);
                    cout << "Task updated" << endl;
                }
            }
        else if (choice == 3){
                int id;
                cout << "Enter task ID to delete: ";
                cin >> id;
                Task* task = taskManager.findTask(id);
                if (task == nullptr) {
                    cout << "Task not found" << endl;
                } else {
                    taskManager.deleteTask(task);
                    cout << "Task deleted" << endl;
                }
            }
        else if (choice == 4){
                taskManager.printTasks();
            }
        else if (choice == 5){
                return 0;
            }
        else{
                cout << "Invalid choice" << endl;
            }
        }
    }

