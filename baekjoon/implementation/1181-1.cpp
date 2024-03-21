#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
		//initial condition setting
		int testcase;
		cin >> testcase;
		vector<string> bucket;
		vector<int> count;
		for(int i = 0; i < testcase; i++){
				string str;
				cin >> str;
				bucket.push_back(str);
				count.push_back(str.length());
		}
		
/*
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
*/
		//sorting
		for(int i = 0; i < testcase; i++){
				int comp = count[i];
				int key = i;
				for(int j = i + 1; j < testcase; j++){
						if(comp > count[j]){
								comp = count[j];
								key = j;
						}
						else if(comp == count[j] && bucket[key] == bucket[j]){
								bucket.erase(bucket.begin() + j);
								count.erase(count.begin() + j);
								testcase--;
								j--;
						}
						else if(comp == count[j] && bucket[key] > bucket[j]){
								comp = count[j];
								key = j;
						}
				}
				swap(count[i], count[key]);
				swap(bucket[i], bucket[key]);
		}

		//print results
		for(int i = 0; i < testcase; i++){
				cout << endl << bucket[i] << endl;
		}

		return 0;
}
