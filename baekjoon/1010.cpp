#include <iostream>
using namespace std;

//too large number - solve it

int factorial(int init_num, int end_num){
		int result = 1;

		while(init_num != end_num){
				result = result * init_num;
				init_num --;
		}
		return result;
}

int main(){
		int testcase;
		cin >> testcase;
		int results[testcase];
		for(int i = 0; i < testcase; i++){
				int west, east;
				cin >> west >> east;
				int result;
				if(west > east){
						cout << "다리를 지을 수 있는 경우가 없습니다." << endl;
				}
				else{
						int diff = east - west;
						result = factorial(east, west) / factorial(diff, 0);
						results[i] = result;
				}
		}
		for(int i = 0; i < testcase; i++){
				cout << results[i] << endl;
		}
		return 0;
}
