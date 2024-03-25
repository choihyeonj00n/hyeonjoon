#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main(){
		vector<pair<int, vector<int>>> a;
		int i = 1;
		vector<int> b = {1,2,3};
		a.push_back(make_pair(i, b));
		cout << a[0].second[1] << endl;
		return 0;
}
