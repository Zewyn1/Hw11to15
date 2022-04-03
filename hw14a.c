#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct book{
    char name[150];
    char author[100];
    int pages;
    double price;
    struct book *next;
};
void print_books(struct book *books, int n){
    for(int i = 0; i < n; i++){
        printf("%s\n", books[i].name);
        printf("%s\n", books[i].author);
        printf("%d\n", books[i].pages);
        printf("%.2lf\n", books[i].price);
    }
}
struct book_list{
    struct book *books;
    int count;
};
void sort_books(struct book *books, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 1; j++){
            if(strcmp(books[j].name, books[j + 1].name) > 0){
                struct book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}

     int main() {
         struct book_list book_list;
         book_list.count = 0;
         book_list.books = NULL;
         int n;
         scanf("%d", &n);
         for (int i = 0; i < n; i++) {
             struct book *new_book = (struct book *) malloc(sizeof(struct book));
             scanf("%s", new_book->name);
             scanf("%s", new_book->author);
             scanf("%d", &new_book->pages);
             scanf("%lf", &new_book->price);
             if (book_list.books == NULL) {
                 book_list.books = new_book;
             } else {
                 struct book *temp = book_list.books;
                 while (temp->next != NULL) {
                     temp = temp->next;
                 }
                 temp->next = new_book;
             }
             book_list.count++;
         }
         sort_books(book_list.books, book_list.count);
         print_books(book_list.books, book_list.count);
         return 0;
     }
