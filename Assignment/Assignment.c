#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 5

typedef struct{
    int bookID;
    char title[40];
    char author[40];
    double price;
    int quantity;
} Book;

Book Bookshop[MAX];
int size = 0;

void listBooks(Book *b, int size);
int addBook(Book *b, int size);
int removeBook(Book *b, int nSize);
void findBook(Book *b, int size);
int updateBook(Book *b);

int main(){
    int choice;

    printf("NTU BOOKSHOP MANAGEMENT PROGRAM:\n");
    printf("1: listBooks()\n");
    printf("2: addBook()\n");
    printf("3: removeBook()\n");
    printf("4: findBook()\n");
    printf("5: updateBook()\n");
    printf("6: quit\n");

    do{
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch(choice){
        case 1:
            listBooks(Bookshop, size);
            break;
        case 2:
            size = addBook(Bookshop, size);
            break;
        case 3:
            size = removeBook(Bookshop, size);
            break;
        case 4:
            findBook(Bookshop, size);
            break;
        case 5:
            updateBook(Bookshop);
            break;
        }
    } while (choice != 6);
    return 0;
}

void listBooks(Book *b, int size){
    int i;
    printf("listBooks():\n");

    if(size == 0)
        printf("The bookshop is empty\n");
    else{
        for (i = 0; i < size; i++){
            printf("BookID: %d\n", (b+i)->bookID);
            printf("Book title: %s\n", (b+i)->title);
            printf("Author name: %s\n", (b+i)->author);
            printf("Book price: %.2f\n", (b+i)->price);
            printf("Quantity: %d\n", (b+i)->quantity);
        }
    }
}

int addBook(Book *b, int size){
    int i, j, newID, bookCheck = 0;
    char *p;
    printf("addBook():\n");

    printf("Enter bookID:\n");
    scanf("%d", &(b+size)->bookID);

    printf("Enter book title:\n");
    getchar();
    fgets((b+size)->title, 80, stdin);
    if(p=strchr((b+size)->title, '\n')) *p = '\0';

    printf("Enter author name:\n");
    fgets((b+size)->author, 80, stdin);
    if(p=strchr((b+size)->author, '\n')) *p = '\0';

    printf("Enter price:\n");
    scanf("%lf", &(b+size)->price);

    printf("Enter quantity: \n");
    scanf("%d", &(b+size)->quantity);

    if (size == MAX){
        printf("The bookshop is full! Unable to addBook()\n");
        return size;
    }

    /* check if there is an existing book with the same bookID */
    newID = (b+size)->bookID;
    for(i = 0; i < size; i++){
        if(newID == (b+i)->bookID){
            bookCheck = 1;
            break;
        }
    }
    switch(bookCheck){
        case 0:
            size++;
            printf("The book has been added successfully\n");
            break;
        case 1:
            printf("The bookID has already existed! Unable to addBook()\n");
            break;
    }

    /* for arranging in ascending numerical bookID */
    for (i = 0; i < size; i++){
        for(j = 0; j < size; j++){
            if(((b+i)->bookID) < ((b+j)->bookID)){
                Book temp = *(b + j);
                *(b + j) = *(b + i);
                *(b + i) = temp;
            }
        }
    }
    return size;
}

int removeBook(Book *b, int nSize){
    int i, j;
    char *p, targetTitle[40], targetName[40];
    printf("removeBook():\n");

    printf("Enter the target book title:\n");
    getchar();
    fgets(targetTitle, 40, stdin);
    if(p=strchr(targetTitle, '\n')) *p = '\0';
    for(j = 0; targetTitle[j]; j++){ // conversion to lowercase
        targetTitle[j] = tolower(targetTitle[j]);}

    printf("Enter the target author name:\n");
    fgets(targetName, 40, stdin);
    if(p=strchr(targetName, '\n')) *p = '\0';
    for(j = 0; targetName[j]; j++){ // conversion to lowercase
        targetName[j] = tolower(targetName[j]);}

    if(size == 0){
        printf("The bookshop is empty\n");
        return nSize;
    }

    for(i = 0; i < nSize; i++){
        char tempTitle[40], tempName[40];

        for(j = 0; (b+i)->title[j]; j++){
            tempTitle[j] = tolower((b+i)->title[j]);}
        tempTitle[j] = '\0';

        for(j = 0; (b+i)->author[j]; j++){
            tempName[j] = tolower((b+i)->author[j]);}
        tempName[j] = '\0';

        if (strcmp(targetTitle, tempTitle) == 0 && strcmp(targetName, tempName)==0){
            printf("The target book is removed\n");

            /* print the target book */
            printf("BookID: %d\n", (b+i)->bookID);
            printf("Book title: %s\n", (b+i)->title);
            printf("Author name: %s\n", (b+i)->author);
            printf("Book price: %.2f\n", (b+i)->price);
            printf("Quantity: %d\n", (b+i)->quantity);

            /* remove the book from the array Bookshop */
            for(j = i; j < size; j++){
                strcpy((b+j)->title, (b+j+1)->title);
                strcpy((b+j)->author, (b+j+1)->author);
                (b+j)->bookID = (b+j+1)->bookID;
                (b+j)->price = (b+j+1)->price;
                (b+j)->quantity = (b+j+1)->quantity;
            }
            return (nSize-1);
        }
    }
    printf("The target book is not in the bookshop\n");
    return nSize;
}

void findBook(Book *b, int size){
    int i, j;
    char *p, targetTitle[40], targetName[40];
    printf("findBook():\n");

    printf("Enter the target book title:\n");
    getchar();
    fgets(targetTitle, 40, stdin);
    if(p=strchr(targetTitle, '\n')) *p = '\0';
    for(j = 0; targetTitle[j]; j++){ // conversion to lowercase
        targetTitle[j] = tolower(targetTitle[j]);}

    printf("Enter the target author name:\n");
    fgets(targetName, 40, stdin);
    if(p=strchr(targetName, '\n')) *p = '\0';
    for(j = 0; targetName[j]; j++){ // conversion to lowercase
        targetName[j] = tolower(targetName[j]);}

    for(i = 0; i < size; i++){
        char tempTitle[40], tempName[40];

        for(j = 0; (b+i)->title[j]; j++){
            tempTitle[j] = tolower((b+i)->title[j]);}
        tempTitle[j] = '\0';

        for(j = 0; (b+i)->author[j]; j++){
            tempName[j] = tolower((b+i)->author[j]);}
        tempName[j] = '\0';

        if (strcmp(targetTitle, tempTitle) == 0 && strcmp(targetName, tempName)==0){
            printf("The target book is found\n");

            /* print the target book */
            printf("BookID: %d\n", (b+i)->bookID);
            printf("Book title: %s\n", (b+i)->title);
            printf("Author name: %s\n", (b+i)->author);
            printf("Book price: %.2f\n", (b+i)->price);
            printf("Quantity: %d\n", (b+i)->quantity);
            return;
        }
    }
    printf("The target book is not found\n");
}

int updateBook(Book *b){
    int i, j;
    char *p, targetTitle[40], targetName[40];
    printf("updateBook():\n");

    printf("Enter the target book title:\n");
    getchar();
    fgets(targetTitle, 40, stdin);
    if(p=strchr(targetTitle, '\n')) *p = '\0';
    for(j = 0; targetTitle[j]; j++){ // conversion to lowercase
        targetTitle[j] = tolower(targetTitle[j]);}

    printf("Enter the target author name:\n");
    fgets(targetName, 40, stdin);
    if(p=strchr(targetName, '\n')) *p = '\0';
    for(j = 0; targetName[j]; j++){ // conversion to lowercase
        targetName[j] = tolower(targetName[j]);}

    for(i = 0; i < size; i++){
        char tempTitle[40], tempName[40];

        for(j = 0; (b+i)->title[j]; j++){
            tempTitle[j] = tolower((b+i)->title[j]);}
        tempTitle[j] = '\0';

        for(j = 0; (b+i)->author[j]; j++){
            tempName[j] = tolower((b+i)->author[j]);}
        tempName[j] = '\0';

        if (strcmp(targetTitle, tempTitle) == 0 && strcmp(targetName, tempName)==0){
            printf("Enter updated book price:\n");
            scanf("%lf", &(b+i)->price);

            printf("Enter updated quantity: \n");
            scanf("%d", &(b+i)->quantity);

            printf("The target book is updated\n");
            printf("BookID: %d\n", (b+i)->bookID);
            printf("Book title: %s\n", (b+i)->title);
            printf("Author name: %s\n", (b+i)->author);
            printf("Book price: %.2f\n", (b+i)->price);
            printf("Quantity: %d\n", (b+i)->quantity);
            return size;
        }
    }
    printf("The target book is not in the bookshop\n");
    return size;
}

