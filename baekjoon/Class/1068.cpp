#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int DFS(int node, vector<int> &visited, vector<pair<int, vector<int>>> &graph, int count){
		int size = graph[node].second.size();
		visited[node] = -1;
		for (int i = 0; i < size; i++){
				int child = graph[node].second[i];
				if(child == -1){
						count += 1;
						break;
				} //case when reached to the leaf node.
				else if(visited[child] == 0){
						count = DFS(child, visited, graph, count);
				}
						
		}
		return count;
}

int main()
{
		//setting initial condition
		int NumberOfNode;
		cin >> NumberOfNode;
		int Node[NumberOfNode];
		for(int i = 0; i < NumberOfNode; i++){
				cin >> Node[i];
		}
		int RemoveNode;
		cin >> RemoveNode;
		vector<int> visited(NumberOfNode, 0); //To check its node visited 0 : nonvisited -1 : visited 
		vector<pair<int, vector<int>>> graph; //graph : vector<parent_node, child>
		for(int i = 0; i < NumberOfNode; i++){
				vector<int> node; //vector such that include each node's child
				for(int j = 0; j < NumberOfNode; j++){
						if(i == Node[j]){
								node.push_back(j);
						}
				}
				if(node.empty()){
						node.push_back(-1);
				}
				graph.push_back(make_pair(Node[i], node));
		}

		//find root node
		int root;
		for(int i = 0; i < NumberOfNode; i++){
				if(graph[i].first == -1){
						root = i;
						break;
				}
		}

		//DFS
		int count = 0;
		int rootDFS = DFS(root, visited, graph, count);
		//cout << "root node leaf node : " << DFS(root, visited, graph, count) << endl;

		for(int i = 0; i < NumberOfNode; i++){
				visited[i] = 0;
		}
		count = 0;
		int removeDFS = DFS(RemoveNode, visited, graph, count);
		//cout << "removenode leaf node : " << DFS(RemoveNode, visited, graph, count) << endl;

		cout << rootDFS - removeDFS << endl;
		return 0;
}

