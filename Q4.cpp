#include <stdio.h>

int stack[5];   
int top = -1;   

void push();
void pop();
void peek();
void display();

int main() {
    printf("Welcome\n");
    int choice;
    do {
        printf("\n1. PUSH\n2. POP\n3. PEEK\n4. DISPLAY\n5. EXIT\n");
        printf("Enter Choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: printf("Thank You!\nGood Bye\n"); break;
            default: printf("Invalid Choice! Try again.\n");
        }
    } while (choice != 5);
}

void push() {
    int element;
    if (top == 4) {  
        printf("Stack Overflow! No more space.\n");
    } else {
        printf("Enter the Element you want to insert in Stack: ");
        scanf("%d", &element);
        top++;
        stack[top] = element;
        printf("Element %d added successfully!\n", element);
    }
}

void pop() {
    if (top == -1) {   // underflow
        printf("Stack Underflow! Stack is empty.\n");
    } else {
        printf("Removed Element: %d\n", stack[top]);
        top--;
    }
}

void peek() {
    if (top == -1) {
        printf("Stack is empty, nothing to peek.\n");
    } else {
        printf("Top Element is: %d\n", stack[top]);
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Current Stack Elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

