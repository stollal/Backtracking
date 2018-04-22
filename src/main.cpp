#include <iostream>

class Backtracking{
/**
 * This creates a suduko grid/board of size 9X9
 */
	void createBoard(int board[9][9]){
		for(int i = 0; i<9; i++){
			for(int j = 0; j< 9; j++){
				std::cout<< board[i][j]<<" ";
				std::cout<<endl;
			}
		}
	}
/**
 *This looks to see if there are empty spots
 */
	bool spotUnassignedCheck(int board[9][9], int & row, int & col){
		for(int i = 0; i<9; i++){
			for(int j = 0; j<9; j++){
				if(board[i][j] == 0){
					row = i;
					col = j;
					return false;
				}
			}
		}
		return true;
	}
/**
 *This checks the rows
 */
	bool checkRow(int board[9][9], int row,int col, int num){
		for(int col = 0; col < 9; col++){
			if(board[row][col] == num){
				return true;
			}
			else{
				return false;
			}
		}
	}
/**
 *This checks the columns
 */
	bool checkCol(int board[9][9], int row, int col, int num){
		for(int row = 0; row < 9; row++){
			if(board[row][col]==num){
				return true;
			}
			else{
				return false;
			}
		}
	}
/**
 *this checks to see if in the sub boxes in the board if their are any
 * empty
 */
	bool boxUnassignedCheck(int board[9][9], int rowX, int colY, int num){
		for(int row = 0; row < 3; row++){
			for(int col = 0; col < 3; col++){
				if(board[row+rowX][col+colY] == num){
					return true;
				}
				else{
					return false;
				}
	}
/**
 * This checks to make sure each small box is valid and makes sure
 * that the num is not already place in the 3x3 box, row, or column
 */
	bool boxIsValid(int board[9][9], int rowX, int colY, int num){
		return !checkRow(board, row, col, num)&&
			!checkCol(board, row, col, num)&&
			!boxUnassignedCheck(board,row-rowX%3,col-colY%3, num);
	}
/**
 *This checks to see if we solved the puzzle correctly
 * if not then it backtracks to fix them
 */
	bool solvePuzzle(int board[9][9], int row, int col){
		for(row = 0; row<9; row++){
			for(col = 0; col<9; col++){
				if(!spotUnassignedCheck(board,row,col)){
					return true;
				}
				else{
					return false;
				}
			}
		}
		for(int num = 1; num <= 9; num++){
			if(boxIsValid){
				board[row][col]=num;
				if(solvePuzzle(board)){
					return true;
				}
				else{
				grid[row][col] = 0;
				return false;
				}
			}
		return false;
		}
	}	
/**
 *This runs a test suduko puzzle to make sure it works
 */
	int main(int argc, char** argv){

		int board[9][9] = {{ 0, 3, 0, 0, 0, 0, 0, 2, 0 },

			{ 0, 9, 0, 0, 0, 0, 0, 8, 5 },

			{ 5, 0, 0, 0, 8, 0, 4, 0, 0 },
	
			{ 4, 0, 7, 2, 0, 6, 8, 9, 0 },

			{ 0, 1, 0, 8, 0, 9, 0, 4, 0 },

			{ 0, 8, 9, 5, 0, 1, 3, 0, 2 },

			{ 0, 0, 3, 0, 1, 0, 0, 0, 9 },

			{ 9, 4, 0, 0, 0, 0, 0, 1, 0 },

			{ 0, 7, 0, 0, 0, 0, 0, 3, 0 }

		};

/**
 *This shows if it is completed and if there is a correct solution
 */

		bool complete = solve(board,0,0);

		if(complete){

			std::cout<<"Found a solution:\n\n";

		} else {

			std:cout<<"No solution found.";

		}

	}
	







