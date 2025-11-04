#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_SIZE 100
#define MAX_AUTHOR_SIZE 50

typedef struct book {
    char title[MAX_TITLE_SIZE];
    char author[MAX_AUTHOR_SIZE];
    int year;
    struct book* next;
    struct book* prev;
} Book;

Book* createBook(const char* title, const char* author, int year) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->year = year;
    newBook->next = NULL;
    newBook->prev = NULL;
    return newBook;
}

void addBook(Book** head, const char* title, const char* author, int year) {
    Book* newBook = createBook(title, author, year);

    if (*head == NULL) {
        *head = newBook;
    } else {
        Book* current = *head;
        Book* prev = NULL;

        while (current != NULL && strcmp(author, current->author) > 0) {
            prev = current;
            current = current->next;
        }

        if (prev == NULL) {
            newBook->next = *head;
            (*head)->prev = newBook;
            *head = newBook;
        } else {
            prev->next = newBook;
            newBook->prev = prev;
            newBook->next = current;
            if (current != NULL) {
                current->prev = newBook;
            }
        }
    }
}

void removeBook(Book** head, int position) {
    if (*head == NULL) {
        return;
    }

    Book* current = *head;
    Book* prev = NULL;
    int count = 1;

    while (current != NULL && count != position) {
        prev = current;
        current = current->next;
        count++;
    }

    if (current == NULL) {
        return;
    }

    if (prev == NULL) {
        *head = (*head)->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
    } else {
        prev->next = current->next;
        if (current->next != NULL) {
            current->next->prev = prev;
        }
    }

    free(current);
}

void printBooks(Book* head) {
    Book* current = head;
    int count = 1;

    while (current != NULL) {
        printf("%d - %s, %s (%d)\n", count, current->title, current->author, current->year);
        current = current->next;
        count++;
    }
}

void reversePrintBooks(Book* head) {
    Book* current = head;
    int count = 0;

    while (current->next != head) {
        current = current->next;
    }

    while (current != NULL) {
        printf("%d - %s, %s (%d)\n", count, current->title, current->author, current->year);
        current = current->prev;
        count++;
    }
}

void afterBook(Book* head, const char* title, int n) {
    Book* current = head;
    int count = 0;

    while (current != NULL && strcmp(title, current->title) != 0) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Livro não encontrado.\n");
        return;
    }

    printf("Livros anteriores:\n");
    Book* temp = current;
    for (int i = 0; i < n; i++) {
        printf("%d - %s, %s (%d)\n", count, temp->title, temp->author, temp->year);
        if (temp->prev == NULL) {
            temp = head;
        } else {
            temp = temp->prev;
        }
        count++;
    }

    count = 1;
    printf("Livro selecionado:\n");
    printf("%d - %s, %s (%d)\n", count, current->title, current->author, current->year);

    count = 0;
    temp = current->next;
    printf("Livros seguintes:\n");
    while (count < n) {
        printf("%d - %s, %s (%d)\n", count, temp->title, temp->author, temp->year);
        temp = temp->next;
        count++;
    }
}

void freeBooks(Book* head) {
    Book* current = head;
    Book* temp = NULL;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    Book* books = NULL;
    int choice, year, position, n;
