#include<stdio.h>
#include<stdint.h>
#define ROW_SZ 1000
#define COL_SZ 1000


int main(){
    int row_index,col_index; 
    float matrix[ROW_SZ][COL_SZ];
    int row, col;
    while(1){
        for(int col=0;col<COL_SZ;col++){
            for(int row=0;row<ROW_SZ;row++){
                if(row*col < 100){
                    break;
                }
                if(row*col > 100 && row*col<1000){
                    continue;
                }
                if(row*col > 1000 && (row+col*col) < 10000){
                    break;
                }
                if(row*col < 100 && (row << 1)*col > 10000){
                    continue;
                }
                matrix[row][col] = row*col;
            }
        }    
    }
    
}