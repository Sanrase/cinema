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

void addFilmList(struct List *list) {
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

void loopList(struct List *list){
    list->head->back = list->tail;
    list->tail->next = list->head;
}

int len(const char *string){
    int len = 0;
    for(int i = 0; string[i] != '\0'; i++, len++);

    return len;
}

void print(struct Film film){
    char up[67];
    char mid[67];
    char down[67];
    up[0] = (char)218;
    up[65] = (char)191;
    up[66] = '\0';
    mid[0] = (char)179;
    mid[65] = (char)179;
    mid[66] = '\0';
    down[0] = (char)192;
    down[65] = (char)217;
    down[66] ='\0';

    for(int i = 1; i < 65; i++){
        up[i] = (char)196;
        down[i] = (char)196;
        mid[i] = (char)32;
    }

    char title[67];
    int middle, length = len(film.title);
    middle = (67 - length) / 2;
    title[0] = (char)179;
    title[65] = (char)179;
    title[66] = '\0';

    for(int i = 1; i < middle; i++){
        title[i] = (char)32;
    }
    for(int i = 0; i < length; i++){
        title[middle + i] = film.title[i];
    }
    for(int i = middle + length; i < 65; i++){
        title[i] = (char)32;
    }

    char year[67];
    length = len(film.year);
    middle = (67 - length) / 2;
    year[0] = (char)179;
    year[65] = (char)179;
    year[66] = '\0';

    for(int i = 1; i < middle; i++){
        year[i] = (char)32;
    }
    for(int i = 0; i < length; i++){
        year[middle + i] = film.year[i];
    }
    for(int i = middle + length; i < 65; i++){
        year[i] = (char)32;
    }

    char country[67];
    length = len(film.country);
    middle = (67 - length) / 2;
    country[0] = (char)179;
    country[65] = (char)179;
    country[66] = '\0';

    for(int i = 1; i < middle; i++){
        country[i] = (char)32;
    }
    for(int i = 0; i < length; i++){
        country[middle + i] = film.country[i];
    }
    for(int i = middle + length; i < 65; i++){
        country[i] = (char)32;
    }

    char genre[67];
    length = len(film.genre);
    middle = (67 - length) / 2;
    genre[0] = (char)179;
    genre[65] = (char)179;
    genre[66] = '\0';

    for(int i = 1; i < middle; i++){
        genre[i] = (char)32;
    }
    for(int i = 0; i < length; i++){
        genre[middle + i] = film.genre[i];
    }
    for(int i = middle + length; i < 65; i++){
        genre[i] = (char)32;
    }

    char rating[67];
    length = len(film.rating);
    middle = (67 - length) / 2;
    rating[0] = (char)179;
    rating[65] = (char)179;
    rating[66] = '\0';

    for(int i = 1; i < middle; i++){
        rating[i] = (char)32;
    }
    for(int i = 0; i < length; i++){
        rating[middle + i] = film.rating[i];
    }
    for(int i = middle + length; i < 65; i++){
        rating[i] = (char)32;
    }

    printf("\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s", up, mid, title, year, country, genre, rating, mid, down);
}

int main() {
    FILE *input;

    struct List list;
    init(&list);
    addFilmList(&list);
    loopList(&list);
    while(1){
        struct Film *film;
        struct List *cur;


    }


    return 0;
}
