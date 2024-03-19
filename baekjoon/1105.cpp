#include <iostream>
#include <cmath>
#define MAX_NUM 9
using namespace std;

int how_many_eight(int L, int R, int LR_long, int long_diff){
		int array[2][long_diff];
		for(int i = 0; i < long_diff; i++){
				array[i] = 0;
		}

		for(int i = 0; i < 2; i++){
				for(int j = LR_long; j >= long_diff; j++){
						int a = j - long_diff;
						array[i][a];
				}
		}

		return 0;
}

int what_num(int num, int diff){

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
		if(L_long != R_long){
				cout << 0 << endl;
		}
		else{
				if(L_long == diff_long){
						cout << 0 << endl;
				}
				else{
						int long_diff = L_long - diff_long;
						
				}
		}

		return 0;
}
