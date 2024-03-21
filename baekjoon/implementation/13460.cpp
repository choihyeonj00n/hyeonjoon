#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
		int N, M, count;
		cin >> N >> M;

		//setting initial condition
		vector<vector<char>> board(N, vector<char>(M));
		for(int i = 0; i < N; i++){
				for(int j = 0; j < M ; j++){
						cin >> board[i][j];
				}
		}

		//solve the problem


		return 0;
}
										
