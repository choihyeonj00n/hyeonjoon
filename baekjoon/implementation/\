#include <iostream>
using namespace std;

int find_sol(int init_num, int target_num)
{
}

int main()
{
		//set initial condition
		int T;
		cin >> T;
		int **two_num = new int*[T];
		for(int i = 0; i < T; i++){
				two_num[i] = new int[2];
				cin >> two_num[i][0] >> two_num[i][1];
		}

		for(int i = 0; i < T; i++){
				int yn_value;
				yn_value = find_sol(two_num[i][0], two_num[i][1]);
				if(yn_value == 0){
						cout << "no" << endl;
				}
				else{
						cout << "yes" << endl;
				}
		}

		//delete two_num
		for(int i = 0; i < T; i++){
				delete[] two_num[i];
		}
		delete[] two_num;
		return 0;
}
