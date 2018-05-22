
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROW 23
#define COL 23
void initializegrid(FILE *st); //function prototype
int isStale();
int isEmpty();
void printOutput(char *st);
int detCount(int i, int j);
void nextGen(int gen, char *st);

//what if we had set these inside main method

char oldarr[ROW][COL];
char newarr[ROW][COL];

void initializegrid(FILE *st) {   
  
    int i, j;
    for (i=0; i < ROW; i++) {
        if (i%2==0) {
        
            for (j=0; j < COL; j++) {  
                if (j % 2 == 0) {
                   oldarr[i][j] = '\0';       
                   printf("%c ", oldarr[i][j]);
                }
            }
        }
        else if (i%2!=0) {
           for (j=0; j < COL; j++) {
               oldarr[i][j] = ' ';
               printf("%c ", oldarr[i][j]);
           }


      }
      printf("\n");   

    }
    printf("Initialized Grid to all Zeros\n\n\n");
   
    // Print out grid from file
    for (i=2; i < 21; i++) {
         if (i%2==0) {
             for (j=2; j < 21; j++) {
                 if (j % 2 == 0) {
                     fscanf(st,"%c ",&oldarr[i][j]);
	             }
             }
         }
         


    }
    for (i=0; i < ROW; i++) {
        if(i%2==0) {
            for (j=0; j < COL; j++) {
                if (j % 2 == 0) {
                    printf("%c ", oldarr[i][j]);
                
                }
            }
        }
       else if (i%2!=0) {
           for (j=0; j < COL; j++) {
               oldarr[i][j] = ' ';
               printf("%c ", oldarr[i][j]);
           }


       }
        printf("\n");
    }
    printf("Generation 0\n\n\n");

}

void nextGen(int gen, char *st) {
 
    int staleResult, emptyResult;
    int temp = 0;   
    int counter = 1;   
    while (counter <= gen) {
        //Store old array copy in newarr
        for (int i=0; i < ROW; i++) {
            for (int j=0; j < COL; j++) {
                newarr[i][j] = oldarr[i][j];
               
            }
        }

       //Updating the cells based on conditions 
       for(int i=2; i<21; i++) {
          for(int j=2; j<21; j++) {    
             if (oldarr[i][j] == '1') {
                temp = detCount(i,j);
                if (temp < 2) { 
                   newarr[i][j] = '0';
                } else if (temp > 3) {
                   newarr[i][j] = '0';
                } else {  
                   newarr[i][j] = '1';
                }
             }
             else if (oldarr[i][j] == '0') {
                temp = detCount(i,j);
                if (temp == 3) { 
                   newarr[i][j] = '1';
                } else {
                   newarr[i][j] = '0';
                }
             }
            
           }
       }    
       emptyResult = isEmpty();
       if (emptyResult == 1) {
          printf("The world is devoid of life.\n");
           
       }
       
       staleResult = isStale();
       if (staleResult == 1) {
          printf("This is a stale world.\n");
          
       }
       //Update the old array with updated information
       for (int i=0; i<ROW; i++) {
           for (int j=0; j<COL; j++) {
               oldarr[i][j] = newarr[i][j];
           }
       }
       for (int i=0; i<ROW; i++) {
           for(int j=0; j<COL; j++) {
               if(j % 2 == 0)
                   printf("%c ", newarr[i][j]);
           }
           printf("\n");
       } 
       printf("Generation %d\n\n\n", counter);
       
       counter++;
          
   }
   printOutput(st);

}


  
int detCount(int i, int j) {
   int count = 0;

   if (oldarr[i-2][j-2] == '1') 
        count++;
   if (oldarr[i-2][j] == '1') 
        count++;
   if (oldarr[i-2][j+2] == '1')
        count++;
   if (oldarr[i][j-2] == '1') 
        count++;
   if (oldarr[i][j+2] == '1')                      
        count++;
   if (oldarr[i+2][j-2] == '1') 
        count++;
   if (oldarr[i+2][j] == '1') 
        count++;
   if (oldarr[i+2][j+2] == '1') 
        count++;
   return count;     
}


int isStale() {
   
   for(int i=2; i<21; i++) {
      for(int j=2; j<21; j++) {
         if (oldarr[i][j] != newarr[i][j]) {
            return 0;
         }
      }
   }
   return 1;
}


int isEmpty() {
   int notAlive=0;   
   for(int i=2; i<21; i++) {
      for(int j=2; j<21; j++) {
         if (newarr[i][j] == '0') {
             notAlive++;
         }
      }
   }
   if (notAlive == 100) {
      return 1;
   } else {
      return 0;
   } 
}
 


void printOutput(char *st) {
    FILE *wt;
    char *ptr; 

    ptr = strcat(st,".out"); //Concatenate .out to the filename

    wt = fopen(ptr, "w");
    for (int i = 2; i < 21; i++) { 
    
        for (int j = 2; j < 21; j++) {
             if (j % 2 == 0) {
                 fprintf(wt,"%c ", oldarr[i][j]);
             }
        }
        fprintf(wt,"\n");
    }    

    fclose(wt);
}

         
 
int main(int argc, char *argv[]) {

    FILE *file;
    file = fopen(argv[2],"r");
    initializegrid(file); // argv[2] is filename
    int gen = atoi(argv[1]);
    nextGen(gen, argv[2]);  //argv[1] is the number of generations    
      
    fclose(file);  
    return 0;
    
}

