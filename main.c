#include <stdio.h>
#include <malloc.h>

struct Film{
    char title[40];
    char year[10];
    char country[15];
    char genre[30];
    char rating[5];
};

struct Node {
    int flag;
    struct Film film;
    struct Node *next;
    struct Node *back;
};

struct List {
    struct Node *head;
    struct Node *tail;
};

void init(struct List *list){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->next = NULL;
    temp->back = NULL;
    temp->flag = 1;

    list->head = temp;
    list->tail = temp;
}

void push(struct List *list, struct Film *film){
    if(list->tail->flag == 1 && list->head->flag == 1){
        list->head->film = *film;
        list->head->flag = 0;
    }else{
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->film = *film;
        temp->flag = 0;
        list->tail->next = temp;
        temp->back = list->tail;
        temp->next = NULL;
        list->tail = temp;
    }
}

struct Film addFilmList(struct List *list) {
    FILE *films = fopen("films.txt", "r");
    char c = 'c';
    int flag = 0;

    while (c != '\377') {
        c = fgetc(films);
        if(flag == 1){
            c = fgetc(films);
        }
        struct Film *film = (struct Film *) malloc(sizeof(struct Film));
        int j  = 0;
        while (c != '#' && c != '\377') {
            flag = 1;
            for (int i = 0; c != '\n'; i++) {
                film->title[i] = c;
                c = fgetc(films);
                j = i;
            }
            film->title[j + 1] = '\0';
            c = fgetc(films);
            for (int i = 0; c != '\n'; i++){
                film->year[i] = c;
                c = fgetc(films);
                j = i;
            }
            film->year[j + 1] = '\0';
            c = fgetc(films);
            for(int i = 0; c != '\n'; i++){
                film->country[i] = c;
                c = fgetc(films);
                j = i;
            }
            film->country[j + 1] = '\0';
            c = fgetc(films);
            for(int i = 0; c != '\n'; i++){
                film->genre[i] = c;
                c = fgetc(films);
                j = i;
            }
            film->genre[j + 1] = '\0';
            c = fgetc(films);
            for(int i = 0; c != '\n'; i++){
                film->rating[i] = c;
                c = fgetc(films);
                j = i;
            }
            c = fgetc(films);
            film->rating[j + 1] = '\0';
            push(list, film);
        }
    }
}

void print(struct List list){
    while
    printf("%s\n%s\n%s\n%s\n%s", list.head->film.title, list.head->film.year, list.head->film.country, list.head->film.genre, list.head->film.rating);
}

int main() {
    FILE *input;

    struct List list;
    init(&list);
    addFilmList(&list);
    print(list);

    return 0;
}
