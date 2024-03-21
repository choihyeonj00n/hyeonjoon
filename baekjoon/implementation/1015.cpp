#include <iostream>
using namespace std;
#define MAX_NUM 1001

void sort(int *A, int *P, int size){
		for(int j = 0; j < size; j++){
				int record;
				int num = MAX_NUM;
				for(int i = 0; i < size; i++){
						if(num > A[i]){
								num = A[i];
								record = i;
						}
				}
				P[record] = j;
				A[record] = MAX_NUM;
		}
}

int main(){
		int size;
		cin >> size;
		int A[size];
		int P[size];
		for(int i = 0; i < size; i++){
				cin >> A[i];
		}
		sort(A, P, size);
		for(int i = 0; i < size; i++){
				cout << P[i] << " ";
		}
		cout << endl;
		return 0;
}
