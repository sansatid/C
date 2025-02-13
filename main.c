#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
  int *que, front, rear, size, Max;
} CircularQueue;

// Initialize the circular queue
CircularQueue* createQueue(int max)
{
  CircularQueue* queue = (CircularQueue*)malloc(sizeof(CircularQueue));
  queue->Max = max;
  queue->que = (int*)malloc(max * sizeof(int));
  queue->front = -1;
  queue->rear = -1;
  queue->size = 0;
  return queue;
}

// Check if queue is full
bool isFull(CircularQueue* queue) { return queue->size == queue->Max; }

// Check if queue is empty
bool isEmpty(CircularQueue* queue) { return queue->size == 0; }

// Add element to the queue
void enqueue(CircularQueue* queue, int element)
{
  if (isFull(queue))
  {
    printf("Queue is full. Cannot enqueue element: %d\n", element);
    return;
  }
  if (isEmpty(queue)) queue->front = 0;
  queue->rear = (queue->rear + 1) % queue->Max;
  queue->que[queue->rear] = element;
  queue->size++;
  printf("Enqueued element: %d\n", element);
}

// Remove element from the queue
int dequeue(CircularQueue* queue)
{
  if (isEmpty(queue))
  {
    printf("Queue is empty. Cannot dequeue element.\n");
    return -1;
  }
  int element = queue->que[queue->front];
  if (queue->front == queue->rear)
  {
    // Last element being removed
    queue->front = -1;
    queue->rear = -1;
  }
  else queue->front = (queue->front + 1) % queue->Max;
  queue->size--;
  printf("Dequeued element: %d\n", element);
  return element;
}

// Get front element without removing it
int peek(CircularQueue* queue)
{
  if (isEmpty(queue))
  {
    printf("Queue is empty.\n");
    return -1;
  }
  return queue->que[queue->front];
}

// Display all elements in the queue
void display(CircularQueue* queue)
{
  if (isEmpty(queue))
  {
    printf("Queue is empty.\n");
    return;
  }
  printf("Queue elements: ");
  int count = 0;
  int index = queue->front;
  while (count < queue->size)
  {
    printf("%d ", queue->que[index]);
    index = (index + 1) % queue->Max;
    count++;
  }
  printf("\n");
}

// Get current size of queue
int getSize(CircularQueue* queue) { return queue->size; }

// Free the memory allocated for queue
void freeQueue(CircularQueue* queue)
{
  free(queue->que);
  free(queue);
}

// Homework part: Clear the queue
void clearQueue(CircularQueue* queue)
{
  queue->front = -1;
  queue->rear = -1;
  queue->size = 0;
  printf("Queue cleared.\n");
}

// Homework part: Get the last element
int getLast(CircularQueue* queue)
{
  if (isEmpty(queue))
  {
    printf("Queue is empty.\n");
    return -1;
  }
  return queue->que[queue->rear];
}

int main()
{
  CircularQueue* queue = createQueue(5);
  int choice, element;

  while (1)
  {
    printf("Menu:\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display all elements\n");
    printf("4. Display first element\n");
    printf("5. Display last element\n");
    printf("6. Display size of queue\n");
    printf("7. Clear queue\n");
    printf("8. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
      printf("Enter element to enqueue: ");
      scanf("%d", &element);
      enqueue(queue, element);
    }
    else if (choice == 2) dequeue(queue);
    else if (choice == 3) display(queue);
    else if (choice == 4) printf("First element: %d\n", peek(queue));
    else if (choice == 5) printf("Last element: %d\n", getLast(queue));
    else if (choice == 6) printf("Queue size: %d\n", getSize(queue));
    else if (choice == 7) clearQueue(queue);
    else if (choice == 8)
    {
      printf("Exiting program...\n");
      break;
    }
    else printf("Invalid choice! Please try again.\n");
    printf("\n");
  }
  freeQueue(queue);
  return 0;
}
