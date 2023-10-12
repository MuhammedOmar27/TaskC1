#include <stdio.h>
#include <string.h>
#include<string.h>

struct Welcome {
    char* username[50];
    char* password[50];
};
int userCount = 0;
void registerUser(struct Welcome users[], int* Count) {
    printf("Enter username: ");
    scanf_s("%s", &users[*Count].username);
    printf("Enter password: ");
    scanf_s("%s", &users[*Count].password);
    (userCount)++;
    printf("Registration successful!\n");
}

int loginUser(struct Welcome users[], int Count, char username[], char password[]) {
    for (int i = 0; i < Count; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    struct Welcome users[100];
    

    int choice;
    char username[50];
    char password[50];

    do {
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            registerUser(users, &userCount);
            break;
        case 2:
            printf("Enter username: ");
            scanf_s("%c", &username);
            printf("Enter password: ");
            scanf_s("%c", &password);
            if (loginUser(users, userCount, username, password)) {
                printf("Login successful!\n");
            }
            else {
                printf("Login failed. Invalid username or password.\n");
            }
            break;
        case 3:
            printf("Exiting program. Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}