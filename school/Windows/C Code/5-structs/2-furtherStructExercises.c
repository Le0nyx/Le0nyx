#include<stdio.h>
#include<stdlib.h>


struct buch {
    char title[30];
    char release_date[30];
    char author[30];
    char pages[30];
    char isbn[30];
    char verlag[40];
    char price[30];
};

struct zeitung{
    char title[20];
    char verlag[30];
    char pages[30];
    char price[30];
};

struct dvd{
    char title[30];
    char release_date[30];
    char playtime[30];
    char price[30];
};


int main(){
    system("cls");

    int isDone = 0;  //variables 
    int chosen = 0;
    int title_chosen = 0;
    int object_chosen = 0;

    int buch_counter = 0; //counters for struct arrays
    int dvd_counter = 0;
    int zeitung_counter = 0;
    
    struct buch buch_count[100]; //struct declarations
    struct dvd dvd_count[100];
    struct zeitung zeitung_count[100];
    


    while(isDone != 1){ //UI
        printf("\n[1] Objekt eintragen   [2] Object ausgeben  [3] Beenden \n : ");
        scanf("%d", &chosen);

        while(chosen<1||chosen>3){ //wrong input
            printf("\n Please try again.");
            printf("\n[1] Objekt eintragen   [2] Object ausgeben  [3] Beenden \n : ");
            scanf("%d", &chosen);
        }

    if(chosen==3){ //Ending the programm
        isDone=1;
    }
    system("cls");

    if(chosen==1){ //Objekt eintragen
        printf("\n [1] Buch   [2] Zeitung   [3] DVD   [4] Go Back \n : ");
        scanf("%d", &object_chosen);
        while(object_chosen<1||object_chosen>4){
            printf("\n Please enter a valid number: ");
            scanf("%d", &object_chosen);
        }
        if(object_chosen==4){
            system("cls");
        }


        //eintragen
        if(object_chosen==1){ //buch
            printf("\n Titel: ");
            fflush(stdin); //to empty buffer
            fgets(buch_count[buch_counter].title, 40, stdin);
            printf("\n Veroeffentlichungsdatum: ");
            fflush(stdin);
            fgets(buch_count[buch_counter].release_date, 40, stdin);
            printf("\n Autor: ");
            fflush(stdin);
            fgets(buch_count[buch_counter].author, 40, stdin);
            printf("\n Seiten: ");
            fflush(stdin);
            fgets(buch_count[buch_counter].pages, 40, stdin);
            printf("\n ISBN: ");
            fflush(stdin);
            fgets(buch_count[buch_counter].isbn, 40, stdin);
            printf("\n Verlag: ");
            fflush(stdin);
            fgets(buch_count[buch_counter].verlag, 40, stdin);
            printf("\n Preis: ");
            fflush(stdin);
            fgets(buch_count[buch_counter].price, 40, stdin);

            buch_counter++;

            system("cls"); //refresh the menu
        }


        if(object_chosen==2){ //zeitung
            printf("\n Titel: ");
            fflush(stdin);
            fgets(zeitung_count[zeitung_counter].title, 40, stdin);
            printf("\n Verlag: ");
            fflush(stdin);
            fgets(zeitung_count[zeitung_counter].verlag, 40, stdin);
            printf("\n Seiten: ");
            fflush(stdin);
            fgets(zeitung_count[zeitung_counter].pages, 40, stdin);
            printf("\n Preis: ");
            fflush(stdin);
            fgets(zeitung_count[zeitung_counter].price, 40, stdin);

            zeitung_counter++;
            system("cls"); //menu refresh
        }

        if(object_chosen==3){ //dvd
        
            printf("\n Titel: ");
            fflush(stdin);
            fgets(dvd_count[dvd_counter].title, 40, stdin);
            printf("\n Veroeffentlichungsdatum: ");
            fflush(stdin);
            fgets(dvd_count[dvd_counter].release_date, 40, stdin);
            printf("\n Laufzeit: ");
            fflush(stdin);
            fgets(dvd_count[dvd_counter].playtime, 40, stdin);
            printf("\n Preis: ");
            fflush(stdin);
            fgets(dvd_count[dvd_counter].price, 40, stdin);

            dvd_counter++;
            system("cls"); //menu refresh

        }
        
    }

    if(chosen==2){ //Objekt printn
        printf("\n [1] Buch   [2] Zeitung   [3] DVD   [4] Go Back \n : ");
        scanf("%d", &object_chosen);
        while(object_chosen<1||object_chosen>4){
            printf("\n Please enter a valid number: ");
            scanf("%d", &object_chosen);
        }
        if(object_chosen==4){
            system("cls");
        }
        system("cls");
        //now print all of them either
        if(object_chosen==1){ //print all books
            for(int i = 0;i<buch_counter;i++){
                printf("\n [%d] %s", i, buch_count[i].title);
                
            }
                scanf("%d", &title_chosen);
                system("cls");
                printf("\n ---------- \n Enter a Number of the Title to know more about: ");
                printf("\n ---------------- \n Titel: %s\n Veroeffentlichungsdatum: %s\n Autor: %s\n Seiten: %s\n ISBN: %s\n Verlag: %s\n Preis: %s\n", buch_count[title_chosen].title, buch_count[title_chosen].release_date, buch_count[title_chosen].author, buch_count[title_chosen].pages, buch_count[title_chosen].isbn, buch_count[title_chosen].verlag, buch_count[title_chosen].price );
                char programm_done[30];
                printf("\n ---------------- \n Press Enter \n ");
                fflush(stdin);
                fgets(programm_done, 30, stdin);

                system("cls");

                title_chosen=0; //reseting for next time 
        }

        if(object_chosen==2){ //print all Zeitungen
            for(int i = 0;i<zeitung_counter;i++){
                printf("\n [%d] %s", i, zeitung_count[i].title);
                
            }
                printf("\n ---------- \n Enter a Number of the Title to know more about: ");
                scanf("%d", &title_chosen);
                system("cls");
                printf("\n ---------------- \n Titel: %s\n Verlag: %s\n Seiten: %s\n Preis: %s", zeitung_count[title_chosen].title, zeitung_count[title_chosen].verlag, zeitung_count[title_chosen].pages, zeitung_count[title_chosen].price );
                char programm_done[30];
                printf("\n ---------------- \n Press Enter \n ");
                fflush(stdin);
                fgets(programm_done, 30, stdin);
                
                system("cls");

                title_chosen=0; //reseting for next time
              
        }

        if(object_chosen==3){ //print all dvds
            for(int i = 0;i<dvd_counter;i++){
                printf("\n [%d] %s", i, dvd_count[i].title);
                
            }
                printf("\n ---------- \n Enter a Number of the Title to know more about: ");
                scanf("%d", &title_chosen);
                system("cls");
                printf("\n ---------------- \n Titel: %s\n Veröffentlichungsdatum: %s\n Laufzeit: %s\n Preis: %s", dvd_count[title_chosen].title, dvd_count[title_chosen].release_date, dvd_count[title_chosen].playtime, dvd_count[title_chosen].price );
                char programm_done[30];
                printf("\n ---------------- \n Press Enter \n ");
                fflush(stdin);
                fgets(programm_done, 30, stdin);
                
                system("cls");

                title_chosen=0;
        }

    }

    object_chosen=0; //for reseting the loop later on
    }

    return 0;
}