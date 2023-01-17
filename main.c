#include <stdio.h>
#include <malloc.h>
#include <string.h>

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

void addFilmList(struct List *list,FILE *films) {
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

void unLoop(struct List *list){
    list->head->back = NULL;
    list->tail->next = NULL;
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

int register_user (char *username, char *password){
    FILE *file = fopen("credentials.txt", "a");
    if(file == NULL){
        printf("Error opening file!\n");
        return 1;
    }

    fprintf(file, "%s:%s\n", username, password);
    fclose(file);

    printf("Registration complete!\n");
    return 0;
}

int login_user (char *username, char *password){
    FILE *file = fopen("credentials.txt", "r");
    if(file == NULL){
        printf("Error opening file!\n");
        return 1;
    }

    char c = 'c';
    while(c != '\377'){
        c = fgetc(file);
        int flag = 0;
        while(c != ':'){
            for(int i = 0; i < strlen(username); i++){
                if(c != username[i]){
                    flag = 1;
                    break;
                }
                c = fgetc(file);
            }
            if(flag){
                while(c != '\n'){
                    c = fgetc(file);
                }
                break;
            }else{
                c = fgetc(file);
                while(c != '\n'){
                    for(int i = 0; i < strlen(password); i++){
                        if(c != password[i]){
                            flag = 1;
                            break;
                        }

                        c = fgetc(file);
                    }
                    if(flag){
                        printf("\t\t\t\tValidation failed\n");

                        return 1;
                    }else{
                        printf("\t\t\t\tValidation succeeded\n");

                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

void add_film_favorites(struct Film film, char *username){
    char filename[50];
    sprintf(filename, "favorites_%s.txt", username);
    FILE *file = fopen(filename, "a");

    fprintf(file, "%s\n%s\n%s\n%s\n%s\n#\n", film.title, film.year, film.country, film.genre, film.rating);
    fflush(file);
}

void del_move(struct Node *film, struct List *list, char *filename){
    FILE *file = fopen(filename, "w");
    unLoop(list);
    if(film->back == NULL){
        list->head = film->next;
    }else if(film->next == NULL){
        list->tail = film->back;
    }else{
        film->back = film->next;
    }
    free(film);

    struct Node *cur = list->head;
    while(cur != NULL){
        fprintf(file, "%s\n%s\n%s\n%s\n%s\n#\n", cur->film.title, cur->film.year, cur->film.country, cur->film.genre, cur->film.rating);
        cur = cur->next;
    }
    loopList(list);
    fflush(file);
}

int main() {
    FILE *moves = fopen("films.txt", "r");
    FILE *favorites_user;

    struct List list;
    struct List favorites_list;
    init(&favorites_list);
    init(&list);
    addFilmList(&list, moves);
    loopList(&list);

    struct Node *cur_favorites;
    struct Node *cur = list.head;

    int flag = 0;
    int check_login = 1, favorites = 0;

    char username[256];
    char password[256];
    char filename[50];

    int is_admin = 0;

    while(1) {
        char answer;

        if (strcmp(username, "admin") == 0 && strcmp(password, "admin") == 0) {
            is_admin = 1;
        }

        if (!check_login && favorites) {
            printf("\t\t\t     You are logged in: %s\n", username);
            printf("\t\t\t\tFavorites list\n");
            printf("\tDelete Movie \"X\"\n");
        }else if (!check_login, is_admin) {
            printf("\t\t\t     You are logged in: %s\n", username);
        }else if (!check_login) {
            printf("\t\t\t   You are logged in: %s\n", username);
            printf("\tList favorites \"F\" Add to favorites\"S\"\n");
        }

        if (!favorites) {
            print(cur->film);
        } else {
            print(cur_favorites->film);
        }

        if (favorites) {
            printf("\n\tLeft \"A\"; Right \"D\"; All moves: \"B\"; Exit \"E\"\n");
        }else if(!check_login && is_admin){
            printf("\n\tLeft \"A\"; Right \"D\"; Log out \"O\"; Delete Movie \"Z\"; Exit \"E\"\n");
        }else if (!favorites && !check_login) {
            printf("\n\tLeft \"A\"; Right \"D\"; Log out \"O\"; Exit \"E\"\n");
        }else{
            printf("\n\tLeft \"A\"; Right \"D\"; Exit \"E\"\n");
        }

        if(check_login){
            printf("\tRegister \"R\"; Login \"L\"\n");
        }
        scanf("%c", &answer);
        fflush(stdin);

        if(answer == 'e' || answer == 'E'){
            break;
        }else{
            while(1) {
                if (answer == 'a' || answer == 'A') {
                    if (favorites) {
                        cur_favorites = cur_favorites->back;
                        fflush(stdin);
                        break;
                    } else {
                        cur = cur->back;
                        fflush(stdin);
                        break;
                    }
                } else if (answer == 'd' || answer == 'D') {
                    if (favorites) {
                        cur_favorites = cur_favorites->next;
                        fflush(stdin);
                        break;
                    } else {
                        cur = cur->next;
                        fflush(stdin);
                        break;
                    }
                } else if ((answer == 'r' || answer == 'R') && (check_login)) {
                    printf("Enter a username: ");
                    scanf("%s", username);

                    printf("Enter a password: ");
                    scanf("%s", password);

                    register_user(username, password);
                    fflush(stdin);
                    break;
                } else if ((answer == 'l' || answer == 'L') && (check_login)) {
                    printf("Enter a username: ");
                    scanf("%s", username);

                    printf("Enter a password: ");
                    scanf("%s", password);

                    check_login = login_user(username, password);
                    fflush(stdin);
                    break;
                } else if ((answer == 'f' || answer == 'F') && (!check_login) && (!favorites)) {
                    favorites = 1;
                    sprintf(filename, "favorites_%s.txt", username);
                    favorites_user = fopen(filename, "r");
                    addFilmList(&favorites_list, favorites_user);
                    loopList(&favorites_list);
                    cur_favorites = favorites_list.head;
                    fflush(stdin);
                    break;
                } else if ((answer == 'x' || answer == 'X') && (!check_login) && favorites) {
                    del_move(cur_favorites, &favorites_list, filename);
                    cur_favorites = favorites_list.head;
                    fflush(stdin);
                    break;
                } else if ((answer == 's' || answer == 'S') && (!check_login) && (!favorites)) {
                    add_film_favorites(cur->film, username);
                    printf("\n\tMovie added to favorites!\n");
                    fflush(stdin);
                    break;
                } else if ((answer == 'b' || answer == 'B') && (favorites)) {
                    favorites = 0;
                    fflush(stdin);
                    break;
                } else if ((answer == 'o' || answer == 'O') && (!check_login)) {
                    check_login = 1;
                    fflush(stdin);
                    break;
                }else if((answer == 'z' || answer == 'Z') && (!check_login) && is_admin){
                    del_move(cur, &list, "films.txt");
                    cur = list.head;
                    fflush(stdin);
                    break;
                } else{
                    printf("Wrong answer\n");
                    fflush(stdin);
                    break;
                }
            }
        }
    }

    return 0;
}
