//Baekjoon p.1012 find result by using BFS
#include <iostream>
#include <string.h>
using namespace std;

//function find_result
void find_result(int** field, int rows, int columns, int current_row, int current_column){
		/*
		# when using reculsive method - DFS#
		field[current_row][current_column] = 0;
		if(current_row - 1 > 0 && field[current_row - 1][current_column] == 1){
				find_result(field, rows, columns, current_row - 1, current_column);
		} 
		else if(current_row + 1 < rows && field[current_row + 1][current_column] == 1){
				find_result(field, rows, columns, current_row + 1, current_column);
		}
		else if(current_column - 1 > 0 && field[current_row][current_column - 1] == 1){
				find_result(field, rows, columns, current_row, current_column - 1); 
		}
		else if(current_column + 1 < columns && field[current_row][current_column + 1] == 1){
				find_result(field, rows, columns, current_row, current_column + 1);
		}
		*/
}

int main(){
		int testcase;
		cin >> testcase;
		int results[testcase];

		for(int i = 0; i < testcase; i++){
				int rows, columns, lattice;
				int result = 0;
				cin >> rows >> columns >> lattice;
				int **field = new int*[rows];
				for(int r = 0; r < rows; r++){
						field[r] = new int[columns];
				}
				
				//field reset
				for(int r = 0; r < rows; r++){
						for(int c = 0; c < columns; c++){
								field[r][c] = 0;
						}
				}

				//insert lattice in field
				for(int j = 0; j < lattice; j++){
						int input_row, input_column;
						cin >> input_row >> input_column;
						field[input_row][input_column] = 1;
				}
				
				//calculate result of each testcase
				for(int k = 0; k < rows; k++){
						for(int l = 0; l < columns; l++){
								if(field[k][l] == 1){
										find_result(field, rows, columns, k, l);
										result++;
								}
						}
				}

				//delete field
				for(int del = 0; del < rows; del++){
					delete[] field[del];
				}
				delete[] field;
				
				results[i] = result;
		}

		//print result
		for(int i = 0; i < testcase; i++){
				cout << results[i] << endl;
		}

		return 0;
}
