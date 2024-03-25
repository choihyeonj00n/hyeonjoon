#include <iostream>
#include <vector>
#include <utility>
using namespace std;

void DFS(int node, vector<int> visited, vector<pair<int, vector<int>>> graph){
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
		for(int i = 0; i < NumberOFNode; i++){
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

		//first remove RemoveNode
		visited[RemoveNode] = -1;
		int size = graph[RemoveNode].second.size();
		


		return 0;
}

