#include<iostream>
using namespace std;

template<typename T>
class Node {
    public:
    T data;
    Node *next;
    Node(T d) : data(d), next(NULL) {}
};

template<typename T>
class LinkedList {
    Node<T> *head;
    public:
    LinkedList() : head(NULL) {}
    
    void insert(T data) {
        Node<T> *newNode = new Node<T>(data);
        if(head == NULL) {
            head = newNode;
            return;
        }
        Node<T> *temp = head;
        while(temp->next) temp = temp->next;
        temp->next = newNode;
    }
    
    void remove(T data) {
        if(!head) return;
        if(head->data == data) {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node<T> *temp = head;
        while(temp->next && temp->next->data != data)
            temp = temp->next;
        if(temp->next) {
            Node<T> *del = temp->next;
            temp->next = temp->next->next;
            delete del;
        }
    }
    
    
    void display() {
        Node<T> *temp = head;
        while(temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
    
    ~LinkedList() {
        while(head) {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList<int> list1;
    list1.insert(10);
    list1.insert(20);
    list1.insert(30);
    cout << "Integer List: ";
    list1.display();
    list1.remove(20);
    cout << "After removal: ";
    list1.display();
    
    LinkedList<string> list2;
    list2.insert("Apple");
    list2.insert("Banana");
    list2.insert("Cherry");
    cout << "\nString List: ";
    list2.display();
    list2.remove("Banana");
    cout << "After removal: ";
    list2.display();
    
    return 0;
}