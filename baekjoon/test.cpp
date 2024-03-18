#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
		vector<int> v = {1,2,3,4,5};
		swap(v[1], v[4]);
		for(int i = 0; i < 5; i++){
				cout << v[i] << " ";
		}
		cout << endl;
		string str1 = "aello";
		string str2 = "no";
		cout << str1 << " : " << str1.length() << endl;
		cout << str2 << " : " << str2.length() << endl;
		if (str1 == str2){
				cout << "same" << endl;
		}
		else if(str1 < str2){
				cout << "right" << endl;
		}


		return 0;
}
