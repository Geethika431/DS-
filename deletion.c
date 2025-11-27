#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;


void createList(int n) {
    struct Node *newNode, *temp;
    int data, i;

    for (i = 1; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
        else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
}


void displayList() {
    struct Node* temp = head;
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


void deleteFront() {
    struct Node* temp;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    temp = head;
    head = head->next;
    free(temp);
    printf("Node deleted from front.\n");
}


void deleteEnd() {
    struct Node *temp, *prev;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    temp = head;
    if (head->next == NULL) {
        head = NULL;
        free(temp);
    } else {
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
    }
    printf("Node deleted from end.\n");
}


void deleteAtPosition(int pos) {
    struct Node *temp, *prev;
    int i;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    temp = head;

    if (pos == 1) {
        head = head->next;
        free(temp);
        printf("Node deleted from position %d.\n", pos);
        return;
    }

    for (i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Node deleted from position %d.\n", pos);
}


int main() {
    int n, choice, pos;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    createList(n);

    printf("\nInitial ");
    displayList();

    do {
        printf("\n\nMenu:\n");
        printf("1. Delete from Front\n");
        printf("2. Delete from End\n");
        printf("3. Delete from Given Position\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            deleteFront();
            break;
        case 2:
            deleteEnd();
            break;
        case 3:
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            deleteAtPosition(pos);
            break;
        case 4:
            displayList();
            break;
        case 5:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}
