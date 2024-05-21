/*
File: 6-linked_list.c
Date: 11-04-2024  08:34
Author: Leon A.
File Description: ---

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct linked_list{
    long long num;
    char name[50];

    struct linked_list *next;
}KNOT;

void UI_list(KNOT *start);
void add_knot(KNOT **start, long long x, char *name);
void delete_knot(KNOT **start, long long x);
void print_knots(KNOT *start);
void free_all(KNOT *start);
KNOT *search_knot(KNOT *start, long long x);
KNOT *getLast_Knot(KNOT *start);
KNOT *getFirst_KNOT(KNOT *start);
int count_knots(KNOT *start);


int main(int argc, char* argv[]){
    KNOT *start = NULL;

    UI_list(start); //works
    
    // Testing
    add_knot(&start, 1, "Arron Kyller");
    add_knot(&start, 2, "Arroz Keller");
    add_knot(&start, 3, "Mark Rober");
    add_knot(&start, 4, "Raubert Banks");
    add_knot(&start, 5, "Arron Kxller");
    add_knot(&start, 6, "Xander Yor");

    delete_knot(&start, 3);
    printf("\nList has %d Knots", count_knots(start));
    print_knots(start);

    KNOT *found = search_knot(start, 4);
    if(found != NULL){
        printf("\n\nFound %s with Phonenumber %lld", found->name, found->num);
    }else{ printf("\n\nNot Found in search"); }

    KNOT *temp2 = getFirst_KNOT(start);
    if(temp2 != NULL){
        printf("\nThe first Knot has following infos: %lld %s\n", temp2->num, temp2->name);
    }
    temp2 = getLast_Knot(start);
    if(temp2 != NULL){
        printf("\nThe last Knot has following infos: %lld %s\n", temp2->num, temp2->name);
    }

    // free all
    free_all(start);
    printf("\n\nEnd of Code with all freed\n");
    
    return 0;
}


void UI_list(KNOT *start){
    KNOT *temp2 = NULL;
    KNOT *temp3 = NULL;

    int choice = 5;

    while(choice > 0 && choice < 8){
        printf("\n [1] Add Knot"); 
        printf("\n [2] Delete Knot");
        printf("\n [3] Print Knots");
        printf("\n [4] Search Knot");
        printf("\n [5] Count Knots");
        printf("\n [6] Get Last Knot");
        printf("\n [7] Get First Knot");
        printf("\n [Else] Exit");

        printf("\n Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\n Enter the Phonenumber: ");
                long long num;
                scanf("%lld", &num);
                printf("\n Enter the Name: ");
                char name[50];
                
                fflush(stdin);
                fgets(name, 50, stdin);
                fflush(stdin);

                add_knot(&start, num, name);
                break;
            case 2:
                printf("\n Enter the Phonenumber: ");
                long long num2;
                scanf("%lld", &num2);
                
                delete_knot(&start, num2);
                break;
            case 3:
                print_knots(start);
                break;
            case 4:
                printf("\n Enter the Phonenumber: ");
                long long num3;
                scanf("%lld", &num3);

                KNOT *found = search_knot(start, num3);
                if(found != NULL){
                    printf("\n\nFound %s with Phonenumber %lld", found->name, found->num);
                }else{ printf("\n\nNot Found in search"); }
                break;
            case 5:
                printf("\nList has %d Knots", count_knots(start));
                break;
            case 6:
                temp2 = getLast_Knot(start);
                if(temp2 != NULL){
                    printf("\nThe last Knot has following infos: %lld %s\n", temp2->num, temp2->name);
                }else{ printf("\n No Element \n"); }
                break;
            case 7:
                temp3 = getFirst_KNOT(start);
                if(temp3 != NULL){
                    printf("\nThe first Knot has following infos: %lld %s\n", temp3->num, temp3->name);
                }else{ printf("\n No Element \n"); }
                break;
            default:
                free_all(start);
                printf("\n\nEnd of Code with all freed\n");
                
                choice = -1; //to break out of loop

                break;
        }
    }
}


void free_all(KNOT *start){
    KNOT *temp = start;
    while (temp != NULL) {
        KNOT *next = temp->next;
        free(temp);
        temp = next;
    }
}


void print_knots(KNOT *start){
    KNOT *temp = start;
    while(temp != NULL){
        printf("\n%lld : %s", temp->num, temp->name );
        temp = temp->next; //go thru till NULL
    }
}

//needs to auto sort itself into the right slot
void add_knot(KNOT **start, long long x, char *name){ //pointer on pointer so the pointer can be changed
    KNOT *p1 = (KNOT *)malloc(sizeof(KNOT));
    if(p1 == NULL){ printf("\n ERRROR OCCURED ALLOCATING MEMORY"); return; }
    p1->next = NULL;

    p1->num = x;
    strcpy(p1->name, name);

    KNOT *temp = *start;
    if(*start == NULL){
        *start = p1;
    }else{ //if start == null

        KNOT *prev = NULL;
        KNOT *curr = *start;
        while(curr != NULL && strcmp(p1->name, curr->name) > 0){ // strcmp returns 0 if equal, 1 if p1 > curr, -1 if p1 < curr
            prev = curr;
            curr = curr->next;
        }
        if(prev == NULL){ //if to add as first
            p1->next = *start;
            *start = p1;
        }else{ //add inbetween and at last
            prev->next = p1;
            p1->next = curr;
        }
    }
}


void delete_knot(KNOT **start, long long x){
    if(*start == NULL){ printf("\nList is empty"); return; } 

    if((*start)->num == x){ //edge case
        KNOT *temp = *start;
        *start = (*start)->next;
        free(temp);
        return;
    }

    KNOT *temp = *start;
    while(temp->next != NULL){
        if(temp->next->num == x){
            KNOT *temp2 = temp->next; //to free the one before
            temp->next = temp->next->next; //to skip deleted one
            free(temp2);
            return;
        }
        temp = temp->next; // find next with null
    }
    printf("\nKnot not found to delete"); //if error occures
}


KNOT *search_knot(KNOT *start, long long x){
    KNOT *temp = start;
    while(temp != NULL){
        if(temp->num == x){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}


int count_knots(KNOT *start){
    int count = 0;
    KNOT *temp = start;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }   
    return count;
}


KNOT *getLast_Knot(KNOT *start){
    KNOT *temp = start;

    if(start == NULL){
        return NULL;
    }

    while(temp->next != NULL){
        temp = temp->next;
    }   
    return temp;
}


KNOT *getFirst_KNOT(KNOT *start){ 
    return start; 
}
