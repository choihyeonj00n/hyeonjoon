#include <iostream>
using namespace std;

//too large number - solve it

long long int combinational(long long int init_num, long long int end_num){
		long long int result = 1;

		if(init_num - end_num < end_num){
				end_num = init_num - end_num;
		}

		//bucket to find factorization
		int bucket[init_num + 1];
		for(int i = 1; i < init_num + 1; i++){
				bucket[i] = 0;
		}

		int diff = init_num - end_num;

		//Calculate nume
		for(int i = init_num; i > diff; i--){
				int arb = i;
				int factor = 2;
				while(arb != 1){
						while(arb % factor == 0){
								bucket[factor] += 1;
								arb /= factor;
						}
						factor++;
				}
				
		}

		//Calculate deno
		for(int i = 2; i <= end_num; i++){
				int arb = i;
				int factor = 2;
				while(arb != 1){
						while(arb % factor == 0){
								bucket[factor] -= 1;
								arb /= factor;
						}
						factor++;
				}
		}

		//Caculate result
		for(int i = 1; i < init_num + 1; i++){
				while(bucket[i] != 0){
						result *= i;
						bucket[i]--;
				}
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
