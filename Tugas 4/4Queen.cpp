#define N 4
#include <stdbool.h> 
#include <string.h>
#include <iostream>
using namespace std; 
	
bool isSafe(int board[N][N], int row, int col){ 
    int i, j;
    
    for (i = 0; i < col; i++){
        if (board[row][i]==1){
            return false;
		}
	}
	
    for (i = col+1; i < N; i++){
        if (board[row][i]==1){
            return false;
		}
	}
	
    for (i = 0; i < row; i++){
        if (board[i][col]==1){
            return false;
		}
	}
	
    for (i = row+1; i < N; i++){
        if (board[i][col]==1){
            return false;
		}
	}
	
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--){
        if (board[i][j]==1){
            return false;
        }
	}
  
    for (i = row, j = col; j >= 0 && i < N; i++, j--) 
        if (board[i][j]==1){
            return false;
		} 
		
    for (i = row, j = col; j < N && i >= 0; i--, j++) 
        if (board[i][j]==1){
            return false; 
		} 
		
    for (i = row, j = col; j < 0 && i < N; i++, j++) 
        if (board[i][j]==1){
            return false; 
		} 

    return true; 
} 
bool solveNQUtil(int board[N][N], int col){
    if (col >= N){
        return true;
	}
    for (int i = 0; i < N; i++){
        if (isSafe(board, i, col)==1) {
            board[i][col] = 1;
            if (solveNQUtil(board, col+1)==1) return true; 
            board[i][col] = 0;
        }
    }
    return false; 
} 

int main(){ 
    int board[N][N]; 
    memset(board, 0, sizeof(board));
    if (solveNQUtil(board, 0) == false){
        cout << "Solusi tidak ada";
        return 0; 
    } 
    for (int i = 0; i < N; i++){ 
        for (int j = 0; j < N; j++){
			cout << " " << board[i][j] << " ";
		}
        cout << endl;
    } 
    return 0; 
}
