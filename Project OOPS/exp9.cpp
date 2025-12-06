#include<iostream>
using namespace std;

class StackException : public exception {
    public:
    const char* what() const throw() {
        return "Stack Error\n";
    }
};

class QueueException : public exception {
    public:
    const char* what() const throw() {
        return "Queue Error\n";
    }
};

template<typename T>
class Stack {
    T arr[3];
    int top;
    public:
    Stack() : top(-1) {}
    
    void push(T x) {
        if(top >= 2) throw StackException();
        arr[++top] = x;
    }
    
    T pop() {
        if(top < 0) throw StackException();
        return arr[top--];
    }
};

template<typename T>
class Queue {
    T arr[3];
    int front, rear;
    public:
    Queue() : front(-1), rear(-1) {}
    
    void enqueue(T x) {
        if(rear >= 2) throw QueueException();
        if(front == -1) front = 0;
        arr[++rear] = x;
    }
    
    T dequeue() {
        if(front < 0 || front > rear) throw QueueException();
        return arr[front++];
    }
};

int main() {
    cout << "=== Stack ===\n";
    Stack<int> s;
    try {
        s.push(10);
        s.push(20);
        s.push(30);
        cout << "Popped: " << s.pop() << "\n";
        cout << "Popped: " << s.pop() << "\n";
        cout << "Popped: " << s.pop() << "\n";
        s.pop();
    }
    catch(exception &e) {
        cout << "Caught: " << e.what();
    }
    
    cout << "\n=== Queue ===\n";
    Queue<int> q;
    try {
        q.enqueue(5);
        q.enqueue(15);
        q.enqueue(25);
        cout << "Dequeued: " << q.dequeue() << "\n";
        cout << "Dequeued: " << q.dequeue() << "\n";
        cout << "Dequeued: " << q.dequeue() << "\n";
        q.dequeue();
    }
    catch(exception &e) {
        cout << "Caught: " << e.what();
    }
    
    return 0;
}