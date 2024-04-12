// Week6_트리코드(클래스 구조)

/*
	1. 항상 루트가 존재한다.
	2. 같은 값을 지니는 노드는 단 1개 존재.
	
	* find: passbyreference
*/

#include<iostream>
#include<vector>
using namespace std;

struct node {
	int data;
	node* parent;
	vector<node*> childList;

	node(int data, node* parent){
		this->data = data;
		this->parent = parent;
	}
};

class Tree {
private:
	node* root;
	vector<node*> nodeList;
	int find(int data, vector<node*>& List);

public:
	Tree(int data);
	void insertNode(int parData, int data);
	void deleteNode(int data);
	void printParent(int data);
	void printChild(int data);
};

Tree::Tree(int data) {
	root = new node(data, NULL);
	nodeList.push_back(root);
}

int Tree::find(int data, vector<node*>& List) {
	for (int i{ 0 }; i < List.size(); i++) {
		if (List[i]->data == data) {
			return i;
		}
	}
	return -1;
}

void Tree::insertNode(int parData, int data) {
	if (find(data, nodeList) != -1) {
		return;
	}

	int idx = find(parData, nodeList);
	if (idx == -1) {
		return;
	}

	node* parNode = nodeList[idx];
	node* newNode = new node(data, parNode);
	parNode->childList.push_back(newNode);
	nodeList.push_back(newNode);
}

void Tree::deleteNode(int data) {
	int idx = find(data, nodeList);
	if (idx == -1) {
		return;
	}

	node* delNode = nodeList[idx];
	if (delNode == root) {
		return;
	}

	node* parNode = delNode->parent;
	for (int i{ 0 }; i < delNode->childList.size(); i++) {
		parNode->childList.push_back(delNode->childList[i]);
		delNode->childList[i]->parent = parNode;
	}

	vector<node*>& child = parNode->childList;
	child.erase(child.begin() + find(data, child));
	nodeList.erase(nodeList.begin() + idx);
	delete delNode;
}

void Tree::printParent(int data) {
	int idx = find(data, nodeList);
	if (idx <= 0) {
		return;
	}

	node* curNode = nodeList[idx];
	cout << curNode->parent->data << '\n';
}
void Tree::printChild(int data) {
	int idx = find(data, nodeList);
	if (idx == -1) {
		return;
	}

	vector<node*>& child = nodeList[idx]->childList;
	if (child.empty()) {
		return;
	}

	for (int i{ 0 }; i < child.size(); i++) {
		cout << child[i]->data << " ";
	}
	cout << '\n';
}


int main() {
	Tree tree(1);

	int size;
	cin >> size;

	while (size-- != 0) {
		string s;
		cin >> s;

		if (s == "insert") {
			int parData, data;
			cin >> parData >> data;
			tree.insertNode(parData, data);
		}
		else if (s == "delete") {
			int data;
			cin >> data;
			tree.deleteNode(data);
		}
		else if (s == "printParent") {
			int data;
			cin >> data;
			tree.printParent(data);
		}
		else if (s == "printChild") {
			int data;
			cin >> data;
			tree.printChild(data);
		}
	}
}
