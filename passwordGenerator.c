#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* generatePassword(int length) {
    char* password = malloc((length + 1) * sizeof(char)); 
    char charSet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%%^&*";
    int charSetSize = sizeof(charSet) - 1;
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        password[i] = charSet[rand() % charSetSize];
    }
    password[length] = '\0';
    return password;
}

void welcomeMessage(void) {
    printf("\n------------------------------------\n");
    printf("WELCOME TO RANDOM PASSWORD GENERATOR\n");
    printf("------------------------------------\n\n");
}

int getLength(void) {
    int length;
    do {
        printf("CHOOSE PASSWORD LENGTH: ");
        scanf("%d", &length);
        if (length < 8 || length > 16) {
            printf("PLEASE SELECT A LENGTH BETWEEN (8-16)\n\n");
        }
    } 
    while (length < 8 || length > 16);
    return length;
}

void printPassword(void) {
    char* password = generatePassword(getLength());
    printf("\n-----------------------------------------\n");
    printf("YOUR GENERATED PASSWORD: %s", password);
    printf("\n-----------------------------------------\n\n");
    free(password);
}

int main(void) {
    welcomeMessage();
    printPassword();
    return 0;
}
