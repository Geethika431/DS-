#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};


struct Node* createList(struct Node *head, int n) {
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
    return head;
}


void displayList(struct Node *head) {
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


struct Node* sortList(struct Node *head) {
    struct Node *current, *index;
    int temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }

    for (current = head; current->next != NULL; current = current->next) {
        for (index = current->next; index != NULL; index = index->next) {
            if (current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
        }
    }

    printf("List sorted successfully.\n");
    return head;
}


struct Node* reverseList(struct Node *head) {
    struct Node *prev = NULL, *current = head, *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    printf("List reversed successfully.\n");
    return prev;
}


struct Node* mergeLists(struct Node *head1, struct Node *head2) {
    struct Node *merged = NULL, *temp = NULL;

    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    if (head1->data <= head2->data) {
        merged = head1;
        head1 = head1->next;
    } else {
        merged = head2;
        head2 = head2->next;
    }

    temp = merged;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            temp->next = head1;
            head1 = head1->next;
        } else {
            temp->next = head2;
            head2 = head2->next;
        }
        temp = temp->next;
    }

    if (head1 != NULL)
        temp->next = head1;
    else
        temp->next = head2;

    printf("Two lists merged successfully.\n");
    return merged;
}

int main() {
    struct Node *head1 = NULL, *head2 = NULL;
    int n, choice;

    printf("Enter number of nodes for first list: ");
    scanf("%d", &n);
    head1 = createList(head1, n);

    printf("\nInitial ");
    displayList(head1);

    do {
        printf("\nMenu:\n");
        printf("1. Sort the list\n");
        printf("2. Reverse the list\n");
        printf("3. Merge with another list\n");
        printf("4. Display list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head1 = sortList(head1);
                break;
            case 2:
                head1 = reverseList(head1);
                break;
            case 3:
                printf("\nEnter number of nodes for second list: ");
                scanf("%d", &n);
                head2 = createList(head2, n);
                head1 = sortList(head1);
                head2 = sortList(head2);
                head1 = mergeLists(head1, head2);
                printf("\nMerged ");
                displayList(head1);
                break;
            case 4:
                displayList(head1);
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
