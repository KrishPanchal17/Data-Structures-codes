#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};//create
struct Node* create(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory not allocated \n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
Node* createLinkedList() {
    return NULL;
}
//insert
Node* insert(Node* head, int data) {
    Node* newNode = create(data);
    newNode->next = head;
    return newNode;
}
//delete
Node* delete_(Node* head, int data) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    Node* current = head;
    Node* prev = NULL;
    while (current != NULL) {
        if (current->data == data) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Element %d deleted from the list.\n", data);
            return head;
        }
        prev = current;
        current = current->next;
    }
    printf("Element %d not found in the list.\n", data);
    return head;
}
//reverse
Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
//concatenate or merge
Node* merge(Node* list1, Node* list2) {
    if (list1 == NULL) return list2;
    Node* current = list1;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = list2;
    return list1;
}
//display
void display(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
int main() {
    Node* list = createLinkedList();
    int ch,data;
    Node* list2 = createLinkedList();
    do{
        printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Reverse\n");
		printf("4.Concatenate\n");
		printf("5.Display\n");
		printf("0.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("Enter number you want to insert: ");
                scanf("%d", &data);
                list = insert(list, data);
                break;
            case 2:
                printf("Enter number you want to delete: ");
                scanf("%d", &data);
                list = delete_(list, data);
                break;
            case 3:
                list = reverse(list);
                printf("List reversed\n");
                break;
            case 4:
                printf("Enter number you want for the second list (0 to stop): ");
                while (1) {
                    scanf("%d", &data);
                    if (data ==0) break;
                    list2 = insert(list2, data);
                }
                list =merge(list, list2);
                break;
            case 5:
                printf("Linked List: ");
                display(list);
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
        }
    } while (ch!= 0);
    while (list!=NULL) {
        Node* temp=list;
        list=list->next;
       
    }
    return 0;
}

