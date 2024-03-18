#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define BUFF_SIZE 50
using namespace std;

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
		for(int i = 0; i < testcase; i++){
				string comp = bucket[i];
				int key = i;
				for(int j = i + 1; j < testcase; j++){
						if(bucket[j].length() < comp.length()){
								comp = bucket[j];
								key = j;
						}
						else if(bucket[j].length() == comp.length()){
								if(bucket[j] == comp){
										bucket.erase(bucket.begin() + j);
										testcase--;
								}
								else if(bucket[j] < comp){
										comp = bucket[j];
										key = j;
								}
						}
				}
				swap(bucket[i], bucket[key]);
		}

		//print results
		for(int i = 0; i < testcase; i++){
				cout << bucket[i] << endl;
		}

		return 0;
}
