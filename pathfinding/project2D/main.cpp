#include "Application2D.h"
#include <stdlib.h>
#include<iostream>

#include"Graph.h"
using namespace std;

int main() {
	
	// allocation
	auto app = new Application2D();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	//Graph test;
	//test.setNodes();
	//vector<Node*> testNodes = test.getNodes();

	//for (int i = 0; i < testNodes.size(); i++) {
	//	cout << "Node: " << testNodes[i]->getData() << ", Edges: ";
	//	for (int j = 0; j < testNodes[i]->getEdges().size(); j++) {
	//		cout << testNodes[i]->getEdges()[j]->getTarget()->getData()<< " ";
	//	}
	//	cout << endl;
	//}

	//test.calculatePath(test.getNodes()[2], test.getNodes()[6]);

	//system("pause");
	return 0;

}