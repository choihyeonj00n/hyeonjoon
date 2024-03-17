#include <iostream>
using namespace std;

int main(){
		int x;
		int result = 0;
		cin >> x;
		while(x != 0){
				int arb = 0;
				while(x / (1 << arb) != 1){
						arb++;
				}
				x -= 1 << arb;
				result += 1;
		}
		cout << result << endl;
		return 0;
}
