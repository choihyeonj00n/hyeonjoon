#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
		
		//setting initial condition
		int ele_num;
		cin >> ele_num;
		vector<int> result(ele_num);
		for(int i = 0; i < ele_num; i++){
				cin >> result[i];
		}

		//find solution
		sort(result.begin(), result.end(), [](int a, int b){return a < b ;});

		for(int i = 0; i < ele_num; i++){
				cout << result[i] << '\n';
		}

		return 0;
}
