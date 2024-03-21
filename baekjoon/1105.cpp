#include <iostream>
#include <cmath>
#define MAX_NUM 9
using namespace std;

int how_many_eight(int L, int R, int LR_long, int long_diff, int diff_long){
		int size = long_diff;
		int count = 0;
		int array[2][size];
		for(int i = 0; i < size; i++){
				array[0][i] = 0;
				array[1][i] = 0;
		}

		cout << "------------is it right?--------------" << endl;
		for(int j = LR_long; j > diff_long; j--){
				int a = j - diff_long - 1;
				int num1 = L / (int)pow(10, j-1);
				int num2 = num1 % 10;
				cout << num2 << endl;
				int num3 = R / (int)pow(10, j-1);
				int num4 = num3 % 10;
				cout << num4 << endl;
				array[0][a] = num2;
				array[1][a] = num4;
		}

		for(int i = 0; i < size; i++){
				if(array[0][i] != array[1][i]){
						break;
				}
				else if(array[0][i] == array[1][i] && array[0][i] == 8){
						count += 1;
				}
		}

		for(int i = 0; i < size; i++){
				cout << "L's" << i << " th number : " << array[0][i] << endl;
				cout << "R's" << i << " th number : " << array[1][i] << endl;
		}

		return count;
}

int how_long(int num){
		int n = 0;
		while(num / (int)pow(10, n) != 0){
				n++;
		}
		return n;
}

int main(){
		int L, R;
		int min = MAX_NUM;
		cin >> L >> R;
		int diff = R - L;
		int L_long = how_long(L);
		int R_long = how_long(R);
		int diff_long = how_long(diff);
		cout << "L_long : " << L_long << " R_long : " << R_long << " diff_long : " << diff_long << endl;
		if(L_long != R_long){
				cout << 0 << endl;
		}
		else{
				if(L_long == diff_long){
						cout << 0 << endl;
				}
				else{
						int long_diff = L_long - diff_long;
						cout << "long_diff : " << long_diff << endl;
						cout << how_many_eight(L, R, L_long, long_diff, diff_long) << endl;
				}
		}

		return 0;
}
