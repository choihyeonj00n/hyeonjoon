#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

bool compare(pair<int, vector<int>> &a, pair<int, vector<int>> &b)
{
		return a.first < b.first;
}

int find_min(vector<pair<int, vector<int>>> &min, int num, int color[][3])
{		
		while(min[0].second.size() != num){
				int size = min[0].second.size();
				int back = min[0].second.back();
				int num_first = min[0].first;
				vector<int> push = min[0].second;
				min.erase(min.begin());
				for(int i = 0; i < 3; i++){
						if(i != back){
								push.push_back(i);
								min.push_back(make_pair(num_first + color[size][i], push));
								push.pop_back();
						}
				}
				sort(min.begin(), min.end(), compare);
		}
		return min[0].first;
}

int main()
{
		int num;
		cin >> num;
		int color[num][3];
		for(int i = 0; i < num; i++){
				cin >> color[i][0] >> color[i][1] >> color[i][2];
		}
		vector<pair<int, vector<int>>> min;
		min.push_back(make_pair(color[0][0], vector<int>{0}));
		min.push_back(make_pair(color[0][1], vector<int>{1}));
		min.push_back(make_pair(color[0][2], vector<int>{2}));
		sort(min.begin(), min.end(), compare);
		int min_value = find_min(min, num, color);
		cout << min_value << endl;

		return 0;
}
