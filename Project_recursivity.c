#include <stdio.h>
#include <stdlib.h>


int** alloc_array(int row,int column);
void fill_array(int ** array,int row,int col);
void printing(int **array,int row,int column);
int somme_array(int **array,int n,int m,int row);
int recherche_element(int rows, int cols, int **array, int element, int Row, int Col);
void transpose(int ** array,int Rows,int Cols,int current_row,int current_col);


int main(){
    
    int** array;
    
    int element,row,column,c;
    
    printf("donnez la taille de tableu : ");
    scanf("%d%d",&row,&column);

    array = alloc_array(row,column);
    printing(array,row,column);


    fill_array(array,row,column);

    
    printf("Choose an operation \n");
    printf("for calculating the Sum of matrix click 1\nCheck existence of an element click 2\n");
    printf("transpose the array chick 3 \n ");
    scanf("%d",&c);
    switch(c){
        case 1:
            printf("The sum is equal %d",somme_array(array,row,column,column));

            break;
        case 2:
            printf("please enter the element you want to ckeck : ");
            scanf("%d",&element);
            if(recherche_element(row,column,array,element,0,0)){
                printf("the element exists ");
             }
            else{
                printf("the element doesn't exist ");
            }
            break;
        case 3:
            transpose(array,row,column,0,0);
             printing(array,row,column);
            break;
    
    }

   

        return 0;
}

int ** alloc_array(int row,int column){
   int** array =(int**)malloc(row * sizeof(int*));

    for(int i = 0; i<row ; i++){
        array[i]= (int *)malloc(column * sizeof(int ));
    }

    return array;
}

void fill_array(int ** array,int row,int col){

     
     for (int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("Element [%d,%d] = ",i,j);
            scanf("%d",&array[i][j]); 
            printf("\n");
        }
     }

}

void printing(int **array,int row,int column){
    for(int i =0 ; i<row;i++){
                printf("[ ");
                for(int j=0;j<column;j++){
                    printf("%d ",array[i][j]);
                    if(j!=column-1){
                        printf(",");
                    }
            
                }
                 printf("]\n");
            }

}

//La somme des elements de tableau
int somme_array(int **array,int n,int m,int row){

    if(n==1 && m==1){
        return array[0][0];
    }
    else {
        if( m > 1 ){
        return array[n-1][m-1] + somme_array(array,n,m-1,row);
        }
        else{
            m=row;
            n--;
            return array[n-1][m-1]+ somme_array(array,n,m,row);
        }
    }

}

//La recherche d'un element
int recherche_element(int rows, int cols, int **array, int element, int Row, int Col) {
    
    if (Row >= rows || Col >= cols) {
        return 0; 
    }

    
    if (array[Row][Col] == element) {
        printf("Value %d found at position (%d, %d).\n", element, Row, Col);
        return 1; 
    }

    
    if (Col < cols - 1) {
        return recherche_element(rows, cols, array, element, Row, Col + 1);
    }
    
    else {
        return recherche_element(rows, cols, array, element, Row + 1, 0);
    }
}   

//Transposer une matrice 
void transpose(int ** array,int Rows,int Cols,int current_row,int current_col){
    int Element;
    
    if( Rows <= 1 || Cols <= 1){
        printf("Pas de matrice transpose ");
        
    }
    if( current_col >= current_row && current_col != Cols){
        
        Element = array[current_row][current_col];
        array[current_row][current_col] = array[current_col][current_row];
        array[current_col][current_row] = Element;
        transpose(array,Rows,Cols,current_row,current_col+1);
        
    }
    else{
        if(current_row < Rows){
            current_col = 0;
            transpose(array,Rows,Cols,current_row+1,current_col);
        }
    }
}

