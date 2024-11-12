#include <iostream>
#include <string>
using namespace std;

// Person class
class Person {
private:
    int per_id;
    string per_name;
    int per_age;

public:
    // Constructor
    Person(int id = 0, string name = "", int age = 0) : per_id(id), per_name(name), per_age(age) {}

    // Function to input data
    void input() {
        cout << "Enter ID: ";
        cin >> per_id;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, per_name);
        cout << "Enter Age: ";
        cin >> per_age;
    }

    // Function to output data
    void output() const {
        cout << "ID: " << per_id << ", Name: " << per_name << ", Age: " << per_age << endl;
    }
};

// Node class for linked list
class Node {
public:
    Person data;
    Node* next;

    Node(const Person& p) : data(p), next(nullptr) {}
};

// LinearLinkedList class
class LinearLinkedList {
private:
    Node* head;

public:
    // Constructor
    LinearLinkedList() : head(nullptr) {}

    // Function to insert a node at the head
    void insertAtHead(const Person& person) {
        Node* newNode = new Node(person);
        newNode->next = head;
        head = newNode;
    }

    // Function to display all nodes
    void display() const {
        Node* temp = head;
        while (temp != nullptr) {
            temp->data.output();
            temp = temp->next;
        }
    }

    // Destructor to free memory
    ~LinearLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    LinearLinkedList list;
    int n;
    
    cout << "Enter number of persons to insert: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "\nEntering details for person " << (i + 1) << ":" << endl;
        Person person;
        person.input();
        list.insertAtHead(person);
    }

    cout << "\nDisplaying all persons in the list:" << endl;
    list.display();

    return 0;
}
