#include <iostream>
#include <cmath>
#define MAX_NUM 9
using namespace std;

int how_many_eight(int num){
		int array[10];
		for(int i = 0; i < 10; i++){
				array[i] = 0;
		}
		int n = 0;
		while(num / (int)pow(10, n) != 0){
				int num1 = num / (int)pow(10, n);
				int num2 = num1 % 10;
				array[num2] += 1;
				n++;
		}
		return array[8];
}

int main(){
		int L, R;
		int min = MAX_NUM;
		cin >> L >> R;
		for(int i = L; i <= R; i++){
				int comp = how_many_eight(i);
				if(min > comp){
						min = comp;
				}
		}

		cout << min << endl;
		return 0;
}
