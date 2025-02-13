#include <stdio.h>
#define SIZE 5  // Size of the queue

int queue[SIZE];
int front = -1, rear = -1;

// Add an element to the Queue
void enqueue(int value) {
    if (rear == SIZE - 1) {  // Check if the queue is full
        printf("Queue is Full!\n");
    } else {
        if (front == -1) front = 0;  // Set front when the first element is added
        rear++;
        queue[rear] = value;  // Add value to the queue
        printf("Added %d to the Queue\n", value);
    }
}

// Remove an element from the Queue
void dequeue() {
    if (front == -1 || front > rear) {  // Check if the queue is empty
        printf("Queue is Empty! Cannot dequeue.\n");
    } else {
        printf("Removed %d from the Queue\n", queue[front]);
        front++;  // Move the front index forward
        if (front > rear) {  // Reset front and rear when the queue becomes empty
            front = rear = -1;
        }
    }
}

// Display all elements in the Queue
void display() {
    if (front == -1 || front > rear) {  // Check if the queue is empty
        printf("Queue is Empty!\n");
    } else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++) {  // Loop through the queue
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    enqueue(10);  // Add elements
    enqueue(20);
    enqueue(30);
    display();    // Display queue contents

    dequeue();    // Remove an element
    display();

    enqueue(40);
    enqueue(50);
    enqueue(60);  // Test when the queue is full
    display();

    dequeue();    // Remove all elements
    dequeue();
    dequeue();
    dequeue();
    dequeue();    // Test dequeue when the queue is empty
    display();

    return 0;
}

