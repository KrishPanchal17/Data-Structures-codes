#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void createList(struct Node** head) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* last = *head;
        while (last->next != NULL) last = last->next;
        last->next = newNode;
    }
}

void insertAtFront(struct Node** head) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node** head) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* last = *head;
        while (last->next != NULL) last = last->next;
        last->next = newNode;
    }
}
void insertAtAnyPosition(struct Node** head) {
    int position, i;
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    printf("Enter position: ");
    scanf("%d", &position);
    newNode->next = NULL;
    if (*head == NULL) {
        printf("List is empty. Please insert at least one element to the list.\n");
    } else if (position == 0) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        for (i = 0; i < position - 1; i++) {
            if (temp->next == NULL) {
                printf("Position out of range. Please enter a valid position.\n");
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}
void deleteAtFront(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
    } else {
        struct Node* temp = *head;
        *head = temp->next;
        free(temp);
    }
}
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Please insert at least one element to the list.\n");
    } else {
        struct Node* temp = *head;
        struct Node* last = NULL;
        while (temp->next != NULL) {
            last = temp;
            temp = temp->next;
        }
        if (last == NULL) {
            *head = NULL;
        } else {
            last->next = NULL;
        }
        free(temp);
    }
}
void deleteAtAnyPosition(struct Node** head) {
    int position, i;
    if (*head == NULL) {
        printf("List is empty. Please insert at least one element to the list.\n");
    } else {
        struct Node* temp = *head;
        printf("Enter position: ");
        scanf("%d", &position);
        if (position == 0) {
            *head = temp->next;
            free(temp);
        } else {
            struct Node* prev = temp;
            for (i = 0; i < position - 1; i++) {
                if (temp->next == NULL) {
                    printf("Position out of range. Please enter valid position.\n");
                    return;
                }
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            free(temp);
        }
    }
}
void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

void concatenateLists(struct Node** head1, struct Node** head2) {
    if (*head1 == NULL) {
        *head1 = *head2;
    } else {
        struct Node* temp = *head1;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = *head2;
    }
}
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
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
