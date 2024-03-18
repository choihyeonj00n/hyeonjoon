#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(string &str1, string &str2){
		if(str1.length() == str1.length()){
				return str1 < str2;
		}
		return str1.length() < str2.length();
}

int main(){

		//initial condition setting
		int testcase;
		cin >> testcase;
		vector<string> bucket;
		for(int i = 0; i < testcase; i++){
				string str;
				cin >> str;
				bucket.push_back(str);
		}

		//중복된 문자열 먼저 지우기
		for(int i = 0; i < testcase; i++){
				string str = bucket[i];
				for(int j = i + 1; j < testcase; j++){
						if(str == bucket[j]){
								bucket.erase(bucket.begin() + j);
								testcase--;
								j--;
						}
				}
		}

		//sorting
		sort(bucket.begin(), bucket.end(), compare);

		for(int i = 0; i < testcase; i++){
				cout << bucket[i] << endl;
		}
		return 0;
}
