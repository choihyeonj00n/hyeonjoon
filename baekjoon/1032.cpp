#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){

		//setting initial condition
		int example;
		cin >> example;
		vector<string> ex(example);
		char result[example];
		for(int i = 0; i < example; i++){
				cin >> ex[i];
		}

		//find solution
		int size = ex[0].length();
		for(int i = 0; i < size; i++){
				char comp = ex[0][i];
				int ident = 0;
				for(int j = 0; j < example; j++){
						if(comp != ex[j][i]){
								ident = 1;
						}
				}
				if(ident == 1){
						result[i] = '?';
				}
				else{
						result[i] = comp;
				}
		}

		for(int i = 0; i < size; i++){
				cout << result[i];
		}
		cout << endl;

		return 0;
}
