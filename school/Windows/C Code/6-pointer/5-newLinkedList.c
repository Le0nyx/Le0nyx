#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct PERSON{
    char name[30];
    char surname[30];
    int age;

    struct PERSON *next;
};

struct PERSON *head;
struct PERSON *temp;
struct PERSON *temp2;
 
 
int to_choose() {
    int decision = 0;

    system("cls");
    printf("\n -----------------------\n[1] Add at last  \n[2] Add at chosen point  \n[3] Print all  \n[4] Print at chosen point \n[5] Delete at chosen point  \n[6] Swap lists \n[7] End Programm \n \n : ");
    scanf("%d", &decision);

    while(decision<0||decision>7){ //to big of input or wrong. Doesnt include char
        system("cls");

        printf("\n-----------------------\n Wrong Input.  \n-----------------------");
        printf("\n[1] Add at last  \n[2] Add at chosen point  \n[3] Print all  \n[4] Print at chosen point \n[5] Delete at chosen point  \n[6] Swap lists\n[7] End Programm \n \n : ");
        scanf("%d", &decision);
    }


    return decision;
}


void enter_to_continue(){

    char programm[20];
    printf("\n Press Enter to continue... ");
    fflush(stdin);
    fgets(programm, 20, stdin);
    system("cls");
}


void print_all(struct PERSON *temp, int list_amount){ // ig prints all
    int counter1 = 0;

    if(list_amount!=0){
        system("cls");

        while(temp!=NULL){
            counter1++;
            printf("\n %d. \n\n Name: %s \n Surname: %s \n Age: %d \n-------------------",counter1, temp->name, temp->surname, temp->age);
            temp = temp->next;
        }
        enter_to_continue();
    } else{
        system("cls");
        printf("\n No Lists available \n-----------------");
        enter_to_continue();
    }
}

void print_at_point(struct PERSON *temp, int list_amount){
    int decision_ig = 0;
    system("cls");

    do{
        if(list_amount==0){
            printf("\n No Lists available \n-----------------");
            enter_to_continue();
            break;
        }

        system("cls"); //refresh it

        if(decision_ig>list_amount||decision_ig<0){
            printf("\n Wrong Input. Please try again. \n");
        }

        
        printf("\n ----------------- \n Lists available: %d \n Which one to print: ", list_amount);
        scanf("%d", &decision_ig);

    } while(decision_ig>list_amount||decision_ig<0);

    if(list_amount!=0){
        for(int i = 1;i<decision_ig;i++){
            temp = temp->next;
        }
        system("cls");
        printf("\n %d.\n\n Name: %s \n Surname: %s \n Age: %d \n -----------------",decision_ig, temp->name, temp->surname, temp->age);


        enter_to_continue();
    }
}


void addList(struct PERSON *ptr){ //reads in the listitems to the given pointer
    char name2[30];
    char surname2[30];
    int age2;
    printf("\n Enter the name: ");
    fflush(stdin);
    fgets(name2, 30, stdin);
    strcpy(ptr->name, name2); //copies over to the list   
    printf("\n Enter the surname: ");
    fflush(stdin);
    fgets(surname2, 30, stdin);
    strcpy(ptr->surname, surname2);
    printf("\n Enter the age: ");
    scanf("%d", &age2);
     ptr->age= age2;
}


void swapping(struct PERSON *head, struct PERSON *first_address, struct PERSON *second_address){
//got head, previouse to first adress and previouse of second address

    if(first_address==head){ //look if they are first


    }else{


        if(first_address != second_address){ //notice if its the same or not
            temp = first_address->next;
            first_address->next = second_address->next;
            second_address->next = temp;
            //the next of first shall be changed with next of second

        } else{ //if the adresses are the same
            system("cls");
            printf("\n Trying to swap the same address \n Try again with diffrent positions");
            enter_to_continue();
        }
    }
}



int main(){
    int is_Done = 0; //is to end the programm
    int decision1 = 0;
    int list_amount = 0;


    system("cls");
    printf("\n This programm represents linked lists\n---------------------------------- \n");
    enter_to_continue();

    while(is_Done!=1){ //Programm itself
        decision1 = to_choose();

        if (decision1 == 1) { //at at last
            system("cls");

            struct PERSON *ptr = malloc(sizeof(struct PERSON)); //the type of the pointer is the struct
            addList(ptr);


            //add it to the list

            if(list_amount==0){ //if its the newest element or first
                ptr->next = NULL; //switch out the pointers to where
                head = ptr;

            } else{ //if any other one gets added
                temp = head;

                while(temp->next!=NULL){ //finds last address
                    temp = temp->next;
                }

                temp->next = ptr; //switcherone
                ptr->next = NULL;
            }

            list_amount++;
        }



        if(decision1 == 2){ // add at chosen point
            int add_at_point_decision = 1;
            int locked = 0;

            do{ //if not the right thing chosen
                system("cls");

                if(add_at_point_decision<1||add_at_point_decision>list_amount+1){
                    printf("\n ------------------- \n Wrong Input. Try within bounds \n");
                }
                printf(" List amount: %d\n-------------------\n", list_amount);
                
                printf("\n Where to add: ");
                scanf("%d", &add_at_point_decision);
                //chosen point still missing
            }while(add_at_point_decision<1||add_at_point_decision>list_amount+1);


            system("cls");

            struct PERSON *ptr = malloc(sizeof(struct PERSON)); //the type of the pointer is the struct
            addList(ptr);


            //cases
            if(list_amount == 0 && add_at_point_decision == 1){ // no lists
                head = ptr;
                ptr->next = NULL;
                
                locked = 1;
            }


            if(add_at_point_decision == list_amount+1 && list_amount >= 1 && locked != 1){ //add at last
                temp = head;

                while(temp->next!=NULL){ //finds last address
                    temp = temp->next;
                }

                temp->next = ptr;
                ptr->next = NULL;
                
                locked = 1;
            }

            if(add_at_point_decision == 1 && list_amount != 0 && locked != 1){ //add at start
                temp = head;
                head = ptr;
                ptr->next = temp;
                
                locked = 1;
            }

            if(list_amount != 0 && add_at_point_decision!=list_amount+1 && add_at_point_decision!=1 && locked != 1){//add inbetween
                temp = head;

                for(int i = 1;i<add_at_point_decision-1;i++){ //searches the pointer before the one to add ig
                    temp = temp->next;
                }
                //next one after temp is to be added
                ptr->next = temp->next;
                temp->next = ptr;

                locked = 1;
            }
            list_amount++;
            
            //probably collides via the list_amount++;

        }
        

        if(decision1 == 3) { //print all
            temp = head;
            print_all(temp, list_amount);
        }

        if(decision1 == 4){ //print at chosen point
            print_at_point(head, list_amount);
        }


        if(decision1 == 5){ //delete at chosen point
            int decision_ig = 0;
            temp = head;

            do{
                if(list_amount==0){
                    system("cls");
                    printf("\n No Lists available \n-----------------");
                    enter_to_continue();
                    break;
                }

                system("cls"); //refresh it

                if(decision_ig>list_amount||decision_ig<0){
                    printf("\n Wrong Input. Please try again. \n");
                }

                
                printf("\n ----------------- \n Lists available: %d \n Which one to delete: ", list_amount);
                scanf("%d", &decision_ig);

            } while(decision_ig>list_amount||decision_ig<0);


            if(list_amount==decision_ig){ //last one but also first one
                if(list_amount==1){ //there is only one
                    free(temp);
                    list_amount--;
                }

                if(list_amount>1){ //delete last one
                    for(int i = 1;i<(decision_ig-1);i++){ //makes it so temp is one before the one to remove
                        temp = temp->next;
                    }

                    temp2 = temp->next;
                    temp->next = NULL;
                    free(temp2);
                    list_amount--;
                }

            } else{ //if there are 3 or more
                if(decision_ig==1){ //more than just one
                    head = temp->next;
                    free(temp);
                    list_amount--;
                } else{ //3 or more

                    for(int i = 1;i<(decision_ig-1);i++){ //makes it so temp is one before the one to remove
                        temp = temp->next;
                    }
                    temp2 = temp->next;
                    temp->next = temp->next->next;

                    free(temp2);
                    list_amount--;
                }


            }


        }
        if(decision1 == 6){ //swapping function
            system("cls");

            if(list_amount>1){
                int first_swap = 1;
                int second_swap = 1;

                //determine the addresses
                temp = head;
                temp2 = head;

                do{
                    printf("\n What Number to swap: ");
                    scanf("%d", &first_swap);
                }while(first_swap < 1 || first_swap > list_amount);

                do{
                    printf("\n Swap with: ");
                    scanf("%d", &second_swap);
                }while(second_swap < 1 || second_swap > list_amount);

                //it appears i need to previouse adresses to swap out the temp->next
                for(int i = 0;i<first_swap-1;i++){
                    temp = temp->next;
                }
                
                for(int j = 0;j<second_swap-1;j++){
                    temp2 = temp2->next;
                }
                
                swapping(head, temp, temp2); //gives each the previouse one /can see if one is the first by checking with head

            }else{
                system("cls");
                printf("\n Not enough lists to swap\n -------------------------");
                enter_to_continue();
            }
        }


        if(decision1 == 7){ //ends programm
            is_Done = 1;
        }
    }
    

    //free all before closing
    if(list_amount>0){ //frees everything else
        while(temp!=NULL){
            temp2 = temp;
            temp = temp->next;
            free(temp2);
        }
    }

    return 0;
}