#include <iostream>
using namespace std;

int main()
{
		//setting initial condition
		int row, col;
		cin >> row >> col;
		int input[row][col];
		int output[row][col];
		for(int i = 0; i < row; i++){
				for(int j = 0; j < col; j++){
						int num;
						cin >> num;
						if(num != 0 && num != 1){
								cout << "0 과 1만 행렬에 넣을 수 있습니다." << endl;
						}
						input[i]][j] = num;
				}
		}
		for(int i = 0; i < row; i++){
				for(int j = 0; j < col; j++){
						int num;
						cin >> num;
						if(num != 0 && num != 1){
								cout << "0 과 1만 행렬에 넣을 수 있습니다." << endl;
						}
						output[i]][j] = num;
				}
		}
		return 0;
}