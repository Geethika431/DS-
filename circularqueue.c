#include <stdio.h>
#define Max 5

int queue[Max];
int front = -1, rear = -1;


void insert() {
    int item;


    if ((front == 0 && rear == Max - 1) || (rear + 1) % Max == front) {
        printf("\nQueue Overflow! Cannot insert.\n");
        return;
    }

    printf("Enter the element to insert: ");
    scanf("%d", &item);

    if (front == -1)
        front = 0;

    rear = (rear + 1) % Max;
    queue[rear] = item;

    printf("%d inserted successfully.\n", item);
}


void delete() {
    int item;


    if (front == -1) {
        printf("\nQueue Underflow! Cannot delete.\n");
        return;
    }

    item = queue[front];


    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % Max;
    }

    printf("Deleted element: %d\n", item);
}


void display() {
    int i;

    if (front == -1) {
        printf("\nQueue is Empty.\n");
        return;
    }

    printf("\nCircular Queue elements: ");
    i = front;
    while (i != rear) {
        printf("%d ", queue[i]);
        i = (i + 1) % Max;
    }
    printf("%d\n", queue[i]);
}

int main() {
    int choice;

    while (1) {
        printf("\nCircular Queue Operations\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
