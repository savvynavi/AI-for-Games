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

	//const int size = 3;
	//const char* map[size][size] = {
	//	{"1", "1", "1" },
	//	{ "1", "0", "0" },
	//	{ "1", "1", "1" }
	//};


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

	//float gscoretst = test.getNodes()[2]->getEdges()[0]->getCost();
	//cout << gscoretst << endl;
	test.calculatePath(test.getNodes()[27], test.getNodes()[8]);

	system("pause");
	return 0;

}