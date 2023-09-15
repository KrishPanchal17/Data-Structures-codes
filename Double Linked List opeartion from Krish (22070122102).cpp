#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};
//create
struct Node* create(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}
//insert
Node* insert(Node* head, int data) {
    Node* newNode = create(data);
    if (head) {
        newNode->next = head;
        head->prev = newNode;
    }
    return newNode;
}
//delete
Node* delete_(Node* head, int data) {
    Node* current = head;
    while (current) {
        if (current->data == data) {
            if (current->prev) current->prev->next = current->next;
            if (current->next) current->next->prev = current->prev;
            if (current == head) head = current->next;
            free(current);
            printf("Element %d deleted from the list.\n", data);
            return head;
        }
        current = current->next;
    }
    printf("Element %d not found in the list.\n", data);
    return head;
}
//reverse
Node* reverse(Node* head) {
    Node* current = head;
    while (current) {
        Node* temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        head = current;
        current = current->prev;
    }
    return head;
}
//concatenate or merge
Node* merge(Node* list1, Node* list2) {
    if (!list1) return list2;
    if (!list2) return list1;

    Node* current = list1;
    while (current->next) current = current->next;
    current->next = list2;
    list2->prev = current;
    return list1;
}
//display
void display(Node* head) {
    Node* current = head;
    while (current) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;
    int ch, data;
    do {
        printf("\n1. Insert to List 1\n");
		printf("2. Insert to List 2\n");
		printf("3. Delete from List 1\n");
		printf("4. Delete from List 2\n");
		printf("5. Reverse List 1\n");
		printf("6. Reverse List 2\n");
		printf("7. Concatenate Lists\n");
		printf("8. Display List 1\n");
		printf("9. Display List 2\n");
		printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
            case 2:
                printf("Enter data to insert into List %d: ", (ch== 1) ? 1 : 2);
                scanf("%d", &data);
                if (ch== 1) list1 = insert(list1, data);
                else list2 = insert(list2, data);
                break;
            case 3:
            case 4:
                printf("Enter data to delete from List %d: ", (ch== 3) ? 1 : 2);
                scanf("%d", &data);
                if (ch== 3) list1 = delete_(list1, data);
                else list2 = delete_(list2, data);
                break;
            case 5:
            case 6:
                if (ch== 5) list1 = reverse(list1);
                else list2 = reverse(list2);
                printf("List %d reversed.\n", (ch== 5) ? 1 : 2);
                break;
            case 7:
                list1 =merge(list1, list2);
                printf("Lists concatenated/merged.\n");
                break;
            case 8:
            case 9:
                printf("List %d: ", (ch== 8) ? 1 : 2);
                display((ch== 8) ? list1 : list2);
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
        }
    } while (ch!= 0);
    while (list1) {
        Node* temp = list1;
        list1 = list1->next;
        free(temp);
    }
    while (list2) {
        Node* temp = list2;
        list2 = list2->next;
}
    return 0;
}

