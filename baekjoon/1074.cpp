#include <iostream>
#include <cmath>
using namespace std;

int factor(int num){
		int factor = 0;
		while(num != 1){
				num /= 2;
				factor++;
		}
		return factor;

}

int find_pos(int total, int r, int c){
		int half = total / 2;
		if(total == 2){
				if(r == 1 && c == 1){
						return 1;
				}
				else if(r == 1 && c == 2){
						return 2;
				}
				else if(r == 2 && c == 1){
						return 3;
				}
				else if(r == 2 && c == 2){
						return 4;
				}
		}
		else if(half >= r && half >= c){
				return find_pos(half, r, c);
		}
		else if(half >= r && half < c){
				return (int)pow(4, factor(half)) + find_pos(half, r, c - half);
		}
		else if(half < r && half >= c){
				return (int)pow(4, factor(half)) * 2 + find_pos(half, r - half, c);
		}
		else if(half < r && half < c){
				return (int)pow(4, factor(half)) * 3 + find_pos(half, r - half, c - half);
		}
		return 0;
}


int main(){
		int N, r, c;
		cin >> N >> r >> c;
		int total = (int)pow(2, N);
		int result = 0;
		r += 1;
		c += 1;
		result = find_pos(total, r, c);
		cout << result - 1 << endl;
		return 0;
}
//4 * pow(2, half / 2)
