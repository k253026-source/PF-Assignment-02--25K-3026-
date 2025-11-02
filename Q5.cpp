#include <stdio.h>

void encode();
void decode();

int main() {
    int choice;
    printf("Welcome to TCS Message Tool\n");

    do {
        printf("\n1. Encode Message\n2. Decode Message\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        if (choice == 1)
            encode();
        else if (choice == 2)
            decode();
        else if (choice == 3)
            printf("Thank You! Goodbye.\n");
        else
            printf("Invalid choice!\n");

    } while (choice != 3);

    return 0;
}

void encode() {
    char msg[100], rev[100];
    int len = 0;

    printf("Enter message to encode: ");
    char ch;
    while ((ch = getchar()) != '\n') {  
        msg[len] = ch;
        len++;
    }
    msg[len] = '\0';

  
    for (int i = 0; i < len; i++) {
        rev[i] = msg[len - i - 1];
    }
    rev[len] = '\0';

    
    for (int i = 0; i < len; i++) {
        rev[i] = rev[i] ^ (1 << 1);  
        rev[i] = rev[i] ^ (1 << 4); 
    }

    printf("Encoded Message: ");
    for (int i = 0; i < len; i++) {
        putchar(rev[i]);
    }
    printf("\n");
}

void decode() {
    char msg[100], rev[100];
    int len = 0;

    printf("Enter message to decode: ");
    char ch;
    while ((ch = getchar()) != '\n') {  
        msg[len] = ch;
        len++;
    }
    msg[len] = '\0';

   
    for (int i = 0; i < len; i++) {
        msg[i] = msg[i] ^ (1 << 1);
        msg[i] = msg[i] ^ (1 << 4);
    }

   
    for (int i = 0; i < len; i++) {
        rev[i] = msg[len - i - 1];
    }
    rev[len] = '\0';

    printf("Decoded Message: ");
    for (int i = 0; i < len; i++) {
        putchar(rev[i]);
    }
    printf("\n");
}

