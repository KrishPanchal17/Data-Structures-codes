#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void createList(struct Node** head) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head; // Make it circular
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head; // Make it circular
    }
}

void insertAtFront(struct Node** head) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->next = *head;
    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newNode;
    *head = newNode;
}

void insertAtEnd(struct Node** head) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->next = *head;
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head; 
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAtAnyPosition(struct Node** head) {
    int position, i;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    printf("Enter position: ");
    scanf("%d", &position);

    if (position == 0) {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        for (i = 0; i < position - 1; i++) {
            temp = temp->next;
            if (temp == *head) {
                printf("Position out of range. Please enter a valid position.\n");
                return;
            }
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteAtFront(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = (*head)->next;
        struct Node* removedNode = *head;
        *head = (*head)->next;
        free(removedNode);
    }
}

void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
    } else {
        struct Node* temp = *head;
        struct Node* prev = NULL;
        while (temp->next != *head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = *head;
        free(temp);
    }
}

void deleteAtAnyPosition(struct Node** head) {
    int position, i;
    struct Node* temp = *head;
    struct Node* prev = NULL;
    printf("Enter position: ");
    scanf("%d", &position);

    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (position == 0) {
        while (temp->next != *head) {
            temp = temp->next;
        }
        prev = temp;
        temp = *head;
        *head = (*head)->next;
        prev->next = *head;
        free(temp);
    } else {
        for (i = 0; i < position; i++) {
            prev = temp;
            temp = temp->next;
            if (temp == *head) {
                printf("Position out of range. Please enter a valid position.\n");
                return;
            }
        }
        prev->next = temp->next;
        free(temp);
    }
}

void reverseList(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;
    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != *head);
    (*head)->next = prev;
    *head = prev;
}

void concatenateLists(struct Node** head1, struct Node** head2) {
    if (*head1 == NULL) {
        *head1 = *head2;
    } else if (*head2 != NULL) {
        struct Node* temp = *head1;
        while (temp->next != *head1) {
            temp = temp->next;
        }
        temp->next = *head2;
        temp = *head2;
        while (temp->next != *head2) {
            temp = temp->next;
        }
        temp->next = *head1;
        *head2 = NULL;
    }
}

void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        struct Node* temp = head;
        do {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("... (back to head)\n");
    }
}

int main() {
    struct Node* head = NULL;
    struct Node* head2 = NULL;
    while (1) {
        int choice;
        printf("\n\n ***** MENU *****\n");
        printf("1. Create List\n");
        printf("2. Insert Node at Front\n");
        printf("3. Insert Node at End\n");
        printf("4. Insert Node at Any Position\n");
        printf("5. Delete Node at Front\n");
        printf("6. Delete Node at End\n");
        printf("7. Delete Node at Any Position\n");
        printf("8. Reverse List\n");
        printf("9. Concatenate Lists\n");
        printf("10. Display List\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createList(&head);
                break;
            case 2:
                insertAtFront(&head);
                break;
            case 3:
                insertAtEnd(&head);
                break;
            case 4:
                insertAtAnyPosition(&head);
                break;
            case 5:
                deleteAtFront(&head);
                break;
            case 6:
                deleteAtEnd(&head);
                break;
            case 7:
                deleteAtAnyPosition(&head);
                break;
            case 8:
                reverseList(&head);
                break;
            case 9:
                createList(&head2);
                concatenateLists(&head, &head2);
                break;
            case 10:
                printList(head);
                break;
            case 11:
                // Free allocated memory and exit
                while (head != NULL) {
                    struct Node* temp = head;
                    head = head->next;
                    if (head == temp) {
                        head = NULL;
                    }
                    free(temp);
                }
                return 0;
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
                break;
        }
    }
}
