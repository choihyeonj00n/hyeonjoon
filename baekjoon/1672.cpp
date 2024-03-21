#include <iostream>
#include <vector>
using namespace std;

char nuc_seq(char str1, char str2){
		if(str1 == str2){
				return str1;
		}
		else if(str1 == 'G' && str2 == 'A'){
				return 'C';
		}
		else if(str1 == 'A' && str2 == 'G'){
				return 'C';
		}
		else if(str1 == 'A' && str2 == 'C'){
				return 'A';
		}
		else if(str1 == 'C' && str2 == 'A'){
				return 'A';
		}
		else if(str1 == 'A' && str2 == 'T'){
				return 'G';
		}
		else if(str1 == 'T' && str2 == 'A'){
				return 'G';
		}
		else if(str1 == 'G' && str2 == 'C'){
				return 'T';
		}
		else if(str1 == 'C' && str2 == 'G'){
				return 'T';
		}
		else if(str1 == 'G' && str2 == 'T'){
				return 'A';
		}
		else if(str1 == 'T' && str2 == 'G'){
				return 'A';
		}
		else if(str1 == 'C' && str2 == 'T'){
				return 'G';
		}
		else if(str1 == 'T' && str2 == 'C'){
				return 'G';
		}
		return str1;
}

int main(){

		//setting initial condition
		int len;
		cin >> len;
		vector<char> DNA(len);
		for(int i = 0; i < len; i++){
				cin >> DNA[i];
		}

		//find solution
		while(DNA.size() != 1){
				char str1 = DNA.back();
				DNA.pop_back();
				char str2 = DNA.back();
				DNA.pop_back();
				char str = nuc_seq(str1, str2);
				DNA.push_back(str);
		}

		cout << DNA[0] << endl;
		return 0;
}
