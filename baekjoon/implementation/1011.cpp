#include <iostream>
using namespace std;

int main()
{
		int T;
		cin >> T;
		int **location = new int*[T];
		for(int i = 0; i < T; i++){
				location[i] = new int[2];
				cin >> location[i][0] >> location[i][1];
		}
		
		for(int i = 0; i< T; i++){
				delete[] location[i];
		}
		delete[] location;
		return 0;
}
