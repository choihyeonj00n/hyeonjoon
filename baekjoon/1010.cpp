#include <iostream>
using namespace std;

//too large number - solve it

long long int combinational(long long int init_num, long long int end_num){
		long long int result = 1;

		while(init_num != end_num){
				result = result * init_num;
				cout << "check : " << init_num << "|" << result << endl;
				init_num --;
		}
		return result;
}

int main(){
		int testcase;
		cin >> testcase;
		long long int results[testcase];
		for(int i = 0; i < testcase; i++){
				int west, east;
				cin >> west >> east;
				long long int result;
				if(west > east){
						cout << "다리를 지을 수 있는 경우가 없습니다." << endl;
				}
				else{
						result = combinational(east, west);
						results[i] = result;
				}
		}
		for(int i = 0; i < testcase; i++){
				cout << results[i] << endl;
		}
		return 0;
}
