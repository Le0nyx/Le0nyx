#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*
Aufgabe 1:
Male einen Buchstaben
Schreibe ein Programm, das deinen Anfangsbuchstaben mittels # ausgibt.
Benutze dabei den Befehl printf mit den Optionen \n und \t. 

Aufgabe 2:
Distanz
Berechne die Distanz zweier vom Benutzer eingegebener Punkte. Erweitere
das Programm für drei Punkte!   

Aufgabe 3:
Quadratische Gleichungen
Schreibe ein Programm, das die Nullstellen einer quadratischen Gleichung
berechnet. Die Koeffizienten a, b und c sollen vom Benutzer eingegeben
werden. Das Programm soll auch die Anzahl (eine, zwei oder keine) der
Nullstellen ermitteln und die Werte der Nullstellen ausgeben. Formel:

Aufgabe 4:
Größte Zahl  
Der Benutzer soll zwei Zahlen eingeben können. Das Programm gibt die
größere der beiden Zahlen aus. Erweitere diese Übung für 3 Zahlen.
(new add in order)

Aufgabe 5:
Schreibe für die folgenden Intervalle die If-Anweisung, die bestimmt, ob ein
Wert i in einem der Intervalle liegt oder nicht: siehe Anhang)
(already done in other file)
*/

float distance(float x1, float y1, float x2, float y2){ //lenght calculation of hypotenuse from point A to B
    float xres = x2-x1;
    float yres = y2-y1;
    xres= xres*xres;
    yres= yres*yres;
    return sqrt(xres+yres);
}

void enter_to_continue(){
    char programm[20];
    printf("\n \n \n----------------------\n Press Enter to continue... ");
    fflush(stdin);
    fgets(programm, 20, stdin);
    system("cls");
}

int main()
{
    int isDone = 0;
    while(isDone != 1){
        int chosen = 1; 
        do{ //user input for choosing
            system("cls");
            if(chosen<1 || chosen>5){
                printf("\n Wrong Input. Try again. \n\n");
            }
            printf("\n What exercise to see (1-4). \n\n1. Print first letter of name \n2. Calculating lenghts from a rectangle \n3. Entering numbers to see which is bigger \n4. Nullstellen mit Mitternachtsformel\n5. Close programm\n\n\n :");
            scanf("%d", &chosen);
        }while(chosen<1 || chosen>5);

        //A1
        if(chosen==1){
            printf("\n\n\t # # # \n\t # # # \n\t # # # \n\t # # # \n\t # # # \n\t # # # \n\t # # # \n\t # # # # # # # #\n\t # # # # # # # #");
            enter_to_continue();
        }

        //A2
        if(chosen==2){
            float x1, y1, x2, y2, x3, y3, x4, y4;
            printf("\n \n Enter the corners of an rectangle. Note to use integer values. \n First Corner X: "); //inputs

            scanf("%f", &x1);
            printf("\n First Corner Y: ");
            scanf("%f", &y1);

            printf("\n Second Corner X: ");
            scanf("%f", &x2);
            printf("\n Second Corner Y: ");
            scanf("%f", &y2);

            printf("\n Third Corner X: ");
            scanf("%f", &x3);
            printf("\n Third Corner Y: ");
            scanf("%f", &y3);

            printf("\n Fourth Corner X: ");
            scanf("%f", &x4);
            printf("\n Fourth Corner Y: ");
            scanf("%f", &y4);

            //output of calculations
            printf("\n From Point 1 to 2 the distance is: %.2f", distance(x1,y1,x2,y2));
            printf("\n From Point 2 to 3 the distance is: %.2f", distance(x2,y2,x3,y3));
            printf("\n From Point 3 to 4 the distance is: %.2f", distance(x3,y3,x4,y4));
            printf("\n From Point 4 to 1 the distance is: %.2f \n \n", distance(x4,y4,x1,y1));
            enter_to_continue();
        }

        //A3
        if(chosen==3){
            int a, b, c;
            printf("\n \n Enter 3 numbers at it calculates which is the biggest. Please use Integer values. \n a: "); //inputs
            scanf("%d", &a);
            printf("\n b: ");
            scanf("%d", &b);
            printf("\n c: ");
            scanf("%d", &c);

            int current = 0; 
            if(b>=c){  //finding out if b or c is bigger
                current = b;
            }else{
                current = c;
            }

            if(a>=current){ //then seeing if the bigger one is bigger than a or not
                printf("\n Biggest number: %d", a);
                printf("\n Middle: %d", current);
                if(current!=c){
                    printf("\n Smallest: %d", c);
                }else{
                    printf("\n Smallest: %d", b);
                }
                
            }else{
                if(a>current){ //goes from a being the biggest (easiest)
                    printf("\n Biggest number: %d", a);
                    printf("\n Middle: %d", current);
                    if(current!=c){
                        printf("\n Smallest: %d", c);
                    }else{
                        printf("\n Smallest: %d", b);
                    }

                } else{
                    printf("\n Biggest number: %d", current);
                    if(current==c){ //goes from c being biggest
                        if(a>=b){
                            printf("\n Middle: %d", a);
                            printf("\n Smallest: %d", b);
                        }else if(b>a){
                            printf("\n Middle: %d", b);
                            printf("\n Smallest: %d", a);
                        }
                    }else{ //goes from b being biggest
                        if(current==b){ //goes from c being biggest
                            if(a>=c){
                                printf("\n Middle: %d", a);
                                printf("\n Smallest: %d", c);
                            }else if(c>a){
                                printf("\n Middle: %d", c);
                                printf("\n Smallest: %d", a);
                            }
                        }
                    }
   
                }            
            }
            enter_to_continue();
        }

        if(chosen==4){ //Mitternachtsformel
            float a, b, c; //input
            printf("\n Enter a,b and c for the formula. Float numbers are also accepted\n \n a: ");
            scanf("%f", &a);
            printf("\n b: ");
            scanf("%f", &b);
            printf("\n c: ");
            scanf("%f", &c);

            //calculations
            float res1 =((-b)+sqrt((b*b)-(4*a*c)) )/(2*a); 
            float res2 =((-b)-sqrt((b*b)-(4*a*c)) )/(2*a); 
            printf("\n ---------------------\nx1 = %.2f and x2 = %.2f", res1, res2);
            enter_to_continue();
        }

        if(chosen==5){ //ends code
            isDone = 1;
        }
    }

    return 0;
}