//MENU DRIVEN PROGRAM TO ACCOMPLISH THE FOLLOWING FUNCITONALITIES IN CIRCULAR LINKED LIST
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Function to create a new node
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a circular linked list
void createCircularLinkedList(int data) {
    struct Node *newNode = createNode(data);
    head = newNode;
    head->next = head;
}

// Function to insert a node at the beginning
void insertAtBeginning(int data) {
    struct Node *newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        head->next = head;
        return;
    }
    newNode->next = head;
    struct Node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    head = newNode;
}

// Function to insert a node at the end
void insertAtEnd(int data) {
    struct Node *newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        head->next = head;
        return;
    }
    struct Node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
}

// Function to delete a node from the beginning
void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }
    struct Node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = head->next;
    free(head);
    head = head->next;
}

// Function to delete a node from the end
void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }
    struct Node *temp = head;
    while (temp->next->next != head) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = head;
}

// Function to delete a node after a given node
void deleteAfter(int target) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    while (temp->next != head && temp->next->data != target) {
        temp = temp->next;
    }
    if (temp->next->next == head) {
        free(temp->next);
        temp->next = head;
        return;
    }
    struct Node *toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
}

// Function to delete the entire circular linked list
void deleteList() {
    if (head == NULL) {
        return;
    }
    struct Node *temp = head;
    while (temp->next != head) {
        struct Node *toDelete = temp->next;
        temp->next = temp->next->next;
        free(toDelete);
    }
    free(temp);
    head = NULL;
}

// Function to display the elements of the circular linked list
void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    int choice, data, target;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Create a circular linked list\n");
        printf("2. Display the elements of a circular linked list\n");
        printf("3. Insert a node at the beginning\n");
        printf("4. Insert a node at the end\n");
        printf("5. Delete a node from the beginning\n");
        printf("6. Delete a node from the end\n");
        printf("7. Delete a node after a given node\n");
        printf("8. Delete the entire circular linked list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                createCircularLinkedList(data);
                break;
            case 2:
                displayList();
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 4:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 5:
                deleteAtBeginning();
                break;
            case 6:
                deleteAtEnd();
                break;
            case 7:
                printf("Enter target: ");
                scanf("%d", &target);
                deleteAfter(target);
                break;
            case 8:
                deleteList();
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
