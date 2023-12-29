#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

void print_list(int list[], int list_length){
    printf("\n List: \n ");

    for(int i = 0;i<list_length;i++){
        printf("%d, ", list[i]);
    }
}

void merge(int list[], int l, int m, int r){
    int sizeL = m - l +1;
    int sizeR = r - m; //one to big for some reason?
    int L[sizeL], R[sizeR];

    for(int i = 0;i<sizeL;i++){ //fill the left list
        L[i] = list[i+l];
    }
    //print_list(L, sizeL);
    for(int j = 0;j<sizeR;j++){ //fill the right list
        R[j] = list[j + m +1];
    }
    //print_list(R, sizeR);
    int i = 0, j = 0, k = l;

    while(i < sizeL && j < sizeR){
        if(L[i] <= R[j]){
            list[k] = L[i];
            i++;
        } else {
            list[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < sizeL){
        list[k] = L[i];
        i++;
        k++;
    }

    while(j < sizeR){
        list[k] = R[j];
        j++;
        k++;

    }

}

void mergeSort(int list[], int l, int r){
    
    if(l<r){
        int m = l + (r-l)/2;
        mergeSort(list, l, m); //rechte liste rekursiv
        mergeSort(list, m+1,r); //linke liste rekursiv

        merge(list, l, m, r);

    }

}


int main() {
    system("cls");

    int list[] = {1, 3, 5, 4, 1, 20, 9}; //7 numbers in total
    int list_length = sizeof(list)/sizeof(list[0]);

    print_list(list, list_length);
    mergeSort(list, 0, list_length-1); //size itself would be to big so it needs the size of the last element
    print_list(list, list_length);

    return 0;
}
