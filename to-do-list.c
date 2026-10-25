#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct task {
    char name[100];
    int done;
    struct task *next;
};

struct task *start = NULL; /* global variable */

/*------------------------------------------------------------------------ */

/* function prototypes */
int read_int();
void read_line(char *buffer, int size); /* i created two separate functions to handle input data to stay away from buffer trouble. */

struct task *createnode();
void traverse();

void insert_first();
void insert_last();
void insert_any();

void delete_first();
void delete_last();
void delete_any();

void mark_done();
void free_list();


/* __________________________________________________________________ */


int main() {
    int choice;

    while (1) {
        printf("\n--- TO-DO LIST ---\n");
        printf("1. Insert first\n");
        printf("2. Insert last\n");
        printf("3. Insert at specific position\n");
        printf("4. Delete first\n");
        printf("5. Delete last\n");
        printf("6. Delete by task number\n");
        printf("7. Mark task done by number\n");
        printf("8. Show all tasks\n");
        printf("0. Exit\n");
        printf("Choice: ");
        
        choice = read_int();  /* as i've created a separate thing for input, so i'll just let it handle it, too! */

        switch (choice) {
            case 1:
                insert_first();
                break;
            case 2:
                insert_last();
                break;
            case 3:
                insert_any();
                break;
            case 4:
                delete_first();
                break;
            case 5:
                delete_last();
                break;
            case 6:
                delete_any();
                break;
            case 7:
                mark_done();
                break;
            case 8:
                traverse();
                break;
            case 0:
                free_list();
                printf("Goodbye!\n");
                return 0; // Exits the program
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }

    return 0;
}


/*___________________________________________________________________ */

int read_int(){
    int x;
    scanf("%d", &x);
    getchar();
    return x;
}

void read_line(char *buffer, int size){
    // nothing 
}


struct task *createnode(){
    // nothing
}

void traverse(){
    printf("call travers\n");
}

void insert_first(){
    printf("insrt_first\n");
}

void insert_last(){
    printf("insert_last\n");
}


void insert_any(){
    printf("any\n");
}


void delete_first(){
    printf("delete_first\n");
}


void delete_last(){
    printf("delete_last\n");
}

void delete_any(){
    printf("delete_any\n");
}

void mark_done(){
    printf("mark_done\n");
}


void free_list(){
    printf("free_list\n");
}