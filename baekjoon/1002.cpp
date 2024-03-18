#include <iostream>
#include <cmath>
using namespace std;

float distance(float x1, float y1, float x2, float y2){
		return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main(){
		int testcase;
		float x1, y1, r1, x2, y2, r2;
		cin >> testcase;
		int *results = new int[testcase];
		for(int i = 0; i < testcase; i++){
				cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
				float dist = distance(x1, y1, x2, y2);
				if(dist == 0 && r1 == r2){
						results[i] = -1;
				}
				else if(dist == r1 + r2){
						results[i] = 1;
				}
				else if(dist > r1 + r2){
						results[i] = 0;
				}
				else if(dist < r1 + r2){
						if(dist + r1 > r2 && dist + r2 > r1){
								results[i] = 2;
						}
				}
				else if(dist + r1 == r2 || dist + r2 == r1){
						results[i] = 1;
				}
			
		}

		
		//print results
		for(int i = 0; i < testcase; i++){
				cout << results[i] << endl;
		}
		delete[] results;

		return 0;
}
