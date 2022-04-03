#include <stdio.h>
#include <stdlib.h>
#include <string.h>
     struct node{
        char data[100];
        struct node *next;
        struct node *prev;
     };
void add_front(struct node **head, char *data){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    strcpy(temp->data, data);
    temp->next = *head;
    temp->prev = NULL;
    if(*head != NULL)
        (*head)->prev = temp;
    *head = temp;
}
void add_end(struct node **head, char *data){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    strcpy(temp->data, data);
    temp->next = NULL;
    temp->prev = NULL;
    if(*head == NULL){
        *head = temp;
        return;
    }
    struct node *curr = *head;
    while(curr->next != NULL)
        curr = curr->next;
    curr->next = temp;
    temp->prev = curr;
}
void delete_front(struct node **head){
    if(*head == NULL)
        return;
    struct node *temp = *head;
    *head = (*head)->next;
    if(*head != NULL)
        (*head)->prev = NULL;
    free(temp);
}
void delete_end(struct node **head){
    if(*head == NULL)
        return;
    struct node *curr = *head;
    while(curr->next != NULL)
        curr = curr->next;
    if(curr->prev != NULL)
        curr->prev->next = NULL;
    free(curr);
}
void print_list(struct node *head){
    FILE *fp;
    char filename[100];
    printf("Enter the file name: ");
    scanf("%s", filename);
    fp = fopen(filename, "wb");
    if(fp == NULL){
        printf("Error opening file!\n");
        return;
    }
    struct node *curr = head;
    while(curr != NULL){
        fwrite(curr->data, sizeof(char), strlen(curr->data), fp);
        curr = curr->next;
    }
    fclose(fp);
}
void read_file(struct node **head){
    FILE *fp;
    char filename[100];
    printf("Enter the file name: ");
    scanf("%s", filename);
    fp = fopen(filename, "rb");
    if(fp == NULL){
        printf("Error opening file!\n");
        return;
    }
    char data[100];
    while(fread(data, sizeof(char), 100, fp) != 0){
        add_end(head, data);
    }
    fclose(fp);
}
     int main() {
    struct node *head = NULL;
    add_front(&head, "Hello");
    add_front(&head, "World");
    add_end(&head, "!");
    delete_front(&head);
    delete_end(&head);
    struct node *curr = head;
    while(curr != NULL){
        printf("%s\n", curr->data);
        curr = curr->next;
    }
    print_list(head);
    read_file(&head);
    curr = head;
    while(curr != NULL){
        printf("%s\n", curr->data);
        curr = curr->next;
    }
    return 0;
     }
