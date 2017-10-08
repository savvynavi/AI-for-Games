#include "Application2D.h"
#include <stdlib.h>
#include<iostream>

#include"Graph.h"
using namespace std;

int main() {
	
	// allocation
	//auto app = new Application2D();

	// initialise and loop
	//app->run("AIE", 1280, 720, false);

	// deallocation
	//delete app;
	//Graph test;

	const int size = 3;

	const char* map[size][size] = {
		{"1", "1", "1" },
		{ "1", "0", "0" },
		{ "1", "1", "1" }
	};

	//Node* testNode();

	/*for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			Node* testNode = new Node("a");
			test.addNode(testNode);
		}
	}*/
	Graph test;
	test.setNodes();
	vector<Node*> testNodes = test.getNodes();

	for (int i = 0; i < testNodes.size(); i++) {
		cout << "Node: " << testNodes[i]->getData() << ", Edges: ";
		for (int j = 0; j < testNodes[i]->getEdges().size(); j++) {
			cout << testNodes[i]->getEdges()[j]->getTarget()->getData()<< " ";
		}
		cout << endl;
	}


	//for (int i = 0; i < size; i++) {
	//	for (int j = 0; j < size; j++) {
	//		Node* testNode = new Node("a");
	//		nodes->push_back();
	//	}
	//}








	//test.printData();

	//for (int i = 0; i < size; i++) {
	//	for (int j = 0; j < size; j++) {
	//		if(map[i][j] == "1" && (map[i+1][j] == "1")){
	//			//nodes[i]->addEdge(&nodes[i+1][j]);
	//			test.getNodes()[i]->addEdge(test.getNodes()[i + 1]);
	//		}
	//	}
	//}

	/*for (int i = 0; i < nodes.size(); i++) {
		std::cout << "Node: " << test.getNodes()[i] << std::endl;
	}*/

	system("pause");
	return 0;

}