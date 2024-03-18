#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(string &str1, string &str2){
		if(str1.length() == str2.length()){
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

		//sorting
		sort(bucket.begin(), bucket.end(), compare);

		for(int i = 0; i < testcase - 1; i++){
				if(bucket[i] == bucket[i + 1]){
						bucket.erase(bucket.begin() + i + 1);
						i--;
						testcase--;
				}
		}

		for(int i = 0; i < testcase; i++){
				cout << bucket[i] << endl;
		}

		return 0;
}
