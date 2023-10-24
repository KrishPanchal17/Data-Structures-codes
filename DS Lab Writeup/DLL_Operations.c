#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void createList(struct Node** head) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->prev = NULL;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void insertAtFront(struct Node** head) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->prev = NULL;
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void insertAtEnd(struct Node** head) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->prev = NULL;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void insertAtAnyPosition(struct Node** head) {
    int position, i;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    printf("Enter position: ");
    scanf("%d", &position);
    newNode->prev = NULL;
    newNode->next = NULL;
    if (position == 0) {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
    } else {
        struct Node* temp = *head;
        for (i = 0; i < position - 1; i++) {
            if (temp == NULL) {
                printf("Position out of range. Please enter a valid position.\n");
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp;
        newNode->prev = temp->prev;
        if (temp->prev != NULL) {
            temp->prev->next = newNode;
        }
        temp->prev = newNode;
        if (temp == *head) {
            *head = newNode;
        }
    }
}

void deleteAtFront(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    *head = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = NULL;
    }
    free(temp);
}

void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    }
    free(temp);
}

void deleteAtAnyPosition(struct Node** head) {
    int position, i;
    struct Node* temp = *head;
    printf("Enter position: ");
    scanf("%d", &position);
    if (position == 0) {
        *head = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = NULL;
        }
        free(temp);
    } else {
        for (i = 0; i < position; i++) {
            if (temp == NULL) {
                printf("Position out of range. Please enter a valid position.\n");
                return;
            }
            temp = temp->next;
        }
        if (temp == NULL) {
            return;
        }
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        }
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        free(temp);
    }
}

void reverseList(struct Node** head) {
    struct Node* temp = NULL;
    struct Node* current = *head;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL) {
        *head = temp->prev;
    }
}

void concatenateLists(struct Node** head1, struct Node** head2) {
    if (*head1 == NULL) {
        *head1 = *head2;
    } else if (*head2 != NULL) {
        struct Node* temp = *head1;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = *head2;
        (*head2)->prev = temp;
    }
    free(*head2);
    *head2 = NULL;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
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
                    free(temp);
                }
                return 0;
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
                break;
        }
    }
}
