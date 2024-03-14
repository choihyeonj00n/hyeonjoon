#include <iostream>
#include <string.h>
using namespace std;

int main(){
		int rows, columns;
		cin >> rows >> columns;
		int field[rows][columns];
		memset(field, 0 , sizeof(field));
		for(int i = 0; i < rows; i++){
				for(int j = 0; j < columns; j++){
						cout << field[i][j] << endl;
				}
		}
		return 0;
}
