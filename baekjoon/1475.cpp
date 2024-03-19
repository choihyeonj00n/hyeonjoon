#include <iostream>
#include <cmath>
using namespace std;

int main(){

		//setting initial condition
		int room_num;
		cin >> room_num;
		int result[10];
		int n = 0;	
		for(int i = 0; i < 10; i++){
				result[i] = 0;
		}

		//find solution
		while(room_num / (int)pow(10, n) != 0){
				int num1 = room_num / (int)pow(10, n);
				int num2 = num1 % 10;
				result[num2] += 1;
				n++;
		}

		int max = 0;
		for(int i = 0 ; i < 10; i++){
				if(i != 6 && i != 9){
						if(max < result[i]){
								max = result[i];
						}
				}
		}

		int max_comp = result[6] + result[9];
		if(max_comp % 2 != 0){max_comp += 1;}
		max_comp /= 2;
		if(max > max_comp){
				cout << max << endl;
		}
		else{
				cout << max_comp << endl;
		}

		return 0;
}
