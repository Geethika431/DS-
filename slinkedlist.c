#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;


struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void createList(int n) {
    struct Node *newNode, *temp;
    int data;

    if (n <= 0) {
        printf("List size must be greater than 0.\n");
        return;
    }

    head = createNode(0);
    printf("Enter data for node 1: ");
    scanf("%d", &data);
    head->data = data;
    head->next = NULL;

    temp = head;

    for (int i = 2; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newNode = createNode(data);
        temp->next = newNode;
        temp = temp->next;
    }

    printf("\nLinked list created successfully.\n");
}

void displayList() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void insertAtBeginning(int data) {
    struct Node *newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    printf("Node inserted at beginning.\n");
}


void insertAtEnd(int data) {
    struct Node *newNode = createNode(data);
    struct Node *temp = head;

    if (head == NULL) {
        head = newNode;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    printf("Node inserted at end.\n");
}


void insertAtPosition(int data, int pos) {
    struct Node *newNode = createNode(data);
    struct Node *temp = head;
    int i;

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        printf("Node inserted at position 1.\n");
        return;
    }

    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    printf("Node inserted at position %d.\n", pos);
}


int main() {
    int choice, data, n, pos;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Create List\n");
        printf("2. Display List\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Insert at Any Position\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                createList(n);
                break;

            case 2:
                displayList();
                break;

            case 3:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;

            case 4:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;

            case 5:
                printf("Enter position to insert: ");
                scanf("%d", &pos);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtPosition(data, pos);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}


