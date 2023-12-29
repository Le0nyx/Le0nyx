#include<stdio.h>
#include<stdlib.h>

/*
This Code draws a square with the size of rows and cols with Pointer
*/

int main(){

    int rows = 4;
    int cols = 3;
    
    
    char **ptr_array = (char *)malloc(rows * sizeof(char *));   //should type (char *) before malloc usually
    
    for (int i = 0; i < rows; i++) {
      *(ptr_array+i) = malloc(cols * sizeof(char));
      
      char *ptr2 = *(ptr_array+i);
      
      for(int j = 0;j<cols;j++){
        *(ptr2+j) = '*';
      }  
      
    }
    
    for(int i = 0;i< rows;i++){

        char *ptr2 = *(ptr_array+i);

        for(int j = 0;j<cols;j++){

            printf("%c ", *(ptr2+j));

        }
        printf("\n");

    }
    
    for(int i = 0;i<rows;i++){

      free(*(ptr_array+i));

    }
    
    free(ptr_array);
    
    return 0;
}