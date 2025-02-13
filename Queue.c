#include <stdio.h>
#define SIZE 5  // ขนาดของคิว

int queue[SIZE];
int front = -1, rear = -1;

// เพิ่มข้อมูลเข้า Queue
void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("Queue เต็ม!\n");
    } else {
        if (front == -1) front = 0;  // กำหนด front เมื่อเพิ่มข้อมูลครั้งแรก
        rear++;
        queue[rear] = value;
        printf("เพิ่ม %d เข้า Queue\n", value);
    }
}

// นำข้อมูลออกจาก Queue
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue ว่าง!\n");
    } else {
        printf("ดึง %d ออกจาก Queue\n", queue[front]);
        front++;
    }
}

// แสดงผล Queue
void display() {
    if (front == -1 || front > rear) {
        printf("Queue ว่าง!\n");
    } else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    dequeue();
    display();

    enqueue(40);
    enqueue(50);
    enqueue(60);  // ทดสอบเมื่อคิวเต็ม
    display();

    return 0;
}
