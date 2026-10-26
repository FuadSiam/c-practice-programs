/*
project tile: personal tasks management

 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct task {
    int task_num;
    char task_name;
    int done;
    struct task *previous, *next;
};

struct task *start = NULL; /* global variable */

/*------------------------------------------------------------------------ */

/* function prototypes */

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
        
        scanf("%d", &choice);  /* as i've created a separate thing for input, so i'll just let it handle it, too! */

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

void traverse(){
    if(start == NULL) printf("No tasks registered\n");
    else{
        struct task *i = start;
        while(i != NULL){
            printf("[%d] Task: \n", i -> task_num, i -> task_name);
        }
    }
}


struct task *createnode(){
    int a;
    char b;
    printf("Enter task number: ");
    scanf("%d", &a);
    printf("Enter task  name: ");
    scanf(" %c", &b);

    struct task *newnode;
    newnode = (struct task*)malloc(sizeof(struct task));
    newnode -> task_num = a;
    newnode -> task_name = b;
    newnode -> previous = NULL;
    newnode -> next = NULL;

    return newnode;
    
}



void insert_first(){
    struct task *newnode = createnode();
    if(start == NULL) start = newnode;
    else{
        start -> previous = newnode;
        newnode -> next = start;
        start = newnode;
    }
}

void insert_last(){
    struct task *newnode = createnode();
    if(start == NULL) start = newnode;
    else{
        struct task *i = start;
        while(i -> next != NULL){
            i = i -> next;
        }

        newnode -> previous = i;    
        i -> next = newnode;
    }
}


void insert_any(){
    struct task *newnode = createnode();
    int position;
    printf("Enter the task number you insert after: ");
    scanf("%d", &position);

    if(start == NULL) start = newnode;
    else{
        struct task *i = start;
        while(i != NULL){
            if(i -> task_num == position){
                newnode -> previous = i;
                newnode -> next = i -> next;
                if(i -> next != NULL) i -> next -> previous = newnode;
                i -> next = newnode;
            }
            i = i -> next;
        }
    }
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