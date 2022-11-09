#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#define ROW_SZ 100
#define COL_SZ 100


int main(){
    int row_index,col_index; 
    float matrix_1[ROW_SZ][COL_SZ];
    float matrix_2[ROW_SZ][COL_SZ];
    float matrix_3[ROW_SZ][COL_SZ];
    float matrix_4[ROW_SZ][COL_SZ];
    float matrix_5[ROW_SZ][COL_SZ];
    float matrix_6[ROW_SZ][COL_SZ];
    float matrix_7[ROW_SZ][COL_SZ];
    for(int i = 0; i < ROW_SZ; i++){
        for(int j = 0; j<COL_SZ; j++){
            matrix_1[i][j] = i*j;
        }
    }
    for(int i = 0; i < ROW_SZ; i++){
        for(int j = 0; j<COL_SZ; j++){
            matrix_2[i][j] = i*j;
        }
    }
    for(int i = 0; i < ROW_SZ; i++){
        for(int j = 0; j<COL_SZ; j++){
            matrix_3[i][j] = i*j;
        }
    }
    for(int i = 0; i < ROW_SZ; i++){
        for(int j = 0; j<COL_SZ; j++){
            matrix_4[i][j] = i*j;
        }
    }
    for(int i = 0; i < ROW_SZ; i++){
        for(int j = 0; j<COL_SZ; j++){
            matrix_5[i][j] = i*j;
        }
    }
    for(int i = 0; i < ROW_SZ; i++){
        for(int j = 0; j<COL_SZ; j++){
            matrix_6[i][j] = i*j;
        }
    }
    for(int i = 0; i < ROW_SZ; i++){
        for(int j = 0; j<COL_SZ; j++){
            matrix_7[i][j] = i*j;
        }
    }
    int row, col;
    while(1){
        for(int col=0;col<COL_SZ;col++){
            for(int row=0;row<ROW_SZ;row++){
                for(int matrix = 0; matrix < 7; matrix++){

                    //switch(matrix){
                        //case 0:
                        matrix_1[row%ROW_SZ][col%COL_SZ] = row*col;
                        //break;
                        //case 1:
                        matrix_2[(row+col)%ROW_SZ][(col+row)%COL_SZ] = row*col;
                        //break;
                        //case 2:
                        matrix_3[(row+10)%ROW_SZ][(col+10)%COL_SZ] = row*col;
                        //break;
                        //case 3:
                        matrix_4[(col+10)%ROW_SZ][(col+1)%COL_SZ] = row*col;
                       // break;
                        //case 4:
                        matrix_5[(row*10)%ROW_SZ][(col+5)%COL_SZ] = row*col;
                        //break;
                        //case 5:
                        matrix_6[row%ROW_SZ][(col+row)%COL_SZ] = row*col;
                        
                        //break;
                        //case 6:
                        matrix_7[(row+1)%ROW_SZ][(col-row)%COL_SZ] = row*col;
                        //break;
                    //}
                    
                       matrix_1[row%ROW_SZ][col%COL_SZ] = matrix_2[(col+row)%COL_SZ][(row+col)%ROW_SZ];
                       
                        matrix_2[(row+1)%ROW_SZ][(col+row)%COL_SZ] = matrix_5[(col+5)%COL_SZ][(row*10)%ROW_SZ];
                        
                        matrix_3[(row+2)%ROW_SZ][(col+10)%COL_SZ] = matrix_7[(col-row)%COL_SZ][(row+1)%ROW_SZ];
                        
                        matrix_4[(row+3)%ROW_SZ][(col+1)%COL_SZ] = matrix_1[col%ROW_SZ][row%COL_SZ];
                     
                        matrix_5[(row*10)%ROW_SZ][(col+5)%COL_SZ] = matrix_3[(col+10)%COL_SZ][(row+10)%ROW_SZ];
                        
                        matrix_6[row%ROW_SZ][(col+row)%COL_SZ] = matrix_1[(col+5)%COL_SZ][row%ROW_SZ];
                        
                        matrix_7[(row+1)%ROW_SZ][(col-row)%COL_SZ] = matrix_6[col%ROW_SZ][(col+row)%COL_SZ];
                        
                    
                }
                //matrix[row][col] = row*col;
            }
        }    
    }
    
}