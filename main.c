#include <stdio.h>
#include <malloc.h>

struct Film{
    char title[40];
    char year[10];
    char country[15];
    char genre[30];
    float rating;
};

struct Node{
    struct Film *film;
    struct Node *back;
    struct Node *next;
};

struct List{
    struct Node *head;
    struct Node *tail;
};

void createList(struct List *list){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->back = NULL;
    temp->next = NULL;
    temp->film = NULL;

    list->head = temp;
    list->tail = temp;
}

void push(struct List *list, struct Film *film){

}



void

int main() {
    FILE *input;
    printf("Hello, World!\n");
    return 0;
}
