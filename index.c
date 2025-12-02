#include<stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return front == -1;
}

int isFull() {
    return (rear + 1) % MAX == front;
}

void enqueue(int x) {
    if(isFull()) {
        printf("Queue full!\n");
        return;
    }
    if(front == -1) front = 0;
    rear = (rear + 1) % MAX;
    queue[rear] = x;
    printf("%d added\n", x);
}

void dequeue() {
    if(isEmpty()) {
        printf("Queue empty!\n");
        return;
    }
    printf("%d removed\n", queue[front]);
    if(front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void display() {
    if(isEmpty()) {
        printf("Queue empty!\n");
        return;
    }
    printf("Elements: ");
    int i = front;
    if(front <= rear) {
        while(i <= rear) printf("%d ", queue[i++]);
    } else {
        while(i < MAX) printf("%d ", queue[i++]);
        i = 0;
        while(i <= rear) printf("%d ", queue[i++]);
    }
    printf("\n");
}

void clearBuffer() {
    while(getchar() != '\n');
}

int main() {
    int choice, val;

    printf("\nQUEUE QUESTION USING ARRAY");
    while(1) {
        printf("\n1.Add  2.Remove  3.Display  4.Exit: ");
        if(scanf("%d", &choice) != 1) {
            clearBuffer();
            printf("Invalid input!\n");
            continue;
        }
        clearBuffer();
        
        if(choice == 1) {
            printf("Enter value: ");
            if(scanf("%d", &val) != 1) {
                clearBuffer();
                printf("Invalid input!\n");
                continue;
            }
            clearBuffer();
            enqueue(val);
        }
        else if(choice == 2) dequeue();
        else if(choice == 3) display();
        else if(choice == 4) break;
        else printf("Invalid!\n");
    }
    
    return 0;
}