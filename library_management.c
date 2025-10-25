#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int id;
    char title[100];
    char author[100];
    struct Book *next;
};

struct Book *head = NULL;

// Function to add a new book
void addBook() {
    struct Book *newBook = (struct Book *)malloc(sizeof(struct Book));
    printf("\nEnter Book ID: ");
    scanf("%d", &newBook->id);
    getchar(); // Clear input buffer
    printf("Enter Book Title: ");
    fgets(newBook->title, sizeof(newBook->title), stdin);
    newBook->title[strcspn(newBook->title, "\n")] = 0;
    printf("Enter Author Name: ");
    fgets(newBook->author, sizeof(newBook->author), stdin);
    newBook->author[strcspn(newBook->author, "\n")] = 0;

    newBook->next = NULL;

    if (head == NULL) {
        head = newBook;
    } else {
        struct Book *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newBook;
    }
    printf("\n✅ Book added successfully!\n");
}

// Function to display all books
void displayBooks() {
    if (head == NULL) {
        printf("\nNo books available in the library.\n");
        return;
    }
    struct Book *temp = head;
    printf("\n📚 List of Books:\n");
    printf("----------------------------------------\n");
    while (temp != NULL) {
        printf("ID: %d\nTitle: %s\nAuthor: %s\n", temp->id, temp->title, temp->author);
        printf("----------------------------------------\n");
        temp = temp->next;
    }
}

// Function to search a book by ID
void searchBook() {
    if (head == NULL) {
        printf("\nNo books to search.\n");
        return;
    }
    int id;
    printf("\nEnter Book ID to search: ");
    scanf("%d", &id);

    struct Book *temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            printf("\n✅ Book Found!\n");
            printf("ID: %d\nTitle: %s\nAuthor: %s\n", temp->id, temp->title, temp->author);
            return;
        }
        temp = temp->next;
    }
    printf("\n❌ Book not found.\n");
}

// Function to delete a book by ID
void deleteBook() {
    if (head == NULL) {
        printf("\nNo books to delete.\n");
        return;
    }
    int id;
    printf("\nEnter Book ID to delete: ");
    scanf("%d", &id);

    struct Book *temp = head;
    struct Book *prev = NULL;

    if (temp != NULL && temp->id == id) {
        head = temp->next;
        free(temp);
        printf("\n✅ Book deleted successfully.\n");
        return;
    }

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("\n❌ Book not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("\n✅ Book deleted successfully.\n");
}

// Function to count total books
void countBooks() {
    int count = 0;
    struct Book *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("\nTotal number of books: %d\n", count);
}

// Main function with menu
int main() {
    int choice;
    while (1) {
        printf("\n========= Library Book Management System =========\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("5. Count Books\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: deleteBook(); break;
            case 5: countBooks(); break;
            case 6: 
                printf("\nThank you for using the system!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}
