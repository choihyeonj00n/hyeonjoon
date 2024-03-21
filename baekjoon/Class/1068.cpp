#include <iostream>
using namespace std;

class Node
{
private :		

		int SelfNode;
		int ParentNode;
		int *SonNode;

public :

		Node(int _SelfNode, int _ParentNode, int* _SonNode);
		int FindParent( 
};

int main()
{
		//setting initial condition
		int NumberOfNode;
		cin >> NumberOfNode;
		int graph[NumberOfNode];
		for(int i = 0; i < NumberOfNode; i++){
				cin >> graph[i];
		}
		int RemoveNode;
		cin >> RemoveNode;

		return 0;
}

