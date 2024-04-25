// Week6_1_12234069_DodamKim

#include<iostream>
#include<vector>
using namespace std;

struct node {
	int data;
	node* parent;
	vector<node*> childList;

	node(int data, node* parent) {
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
	void min_maxChild(int data) {
		int idx = find(data, nodeList);
		if (idx == -1) {
			cout << -1 << '\n';
			return;
		}

		node* dataNode = nodeList[idx];
		vector<node*>& child = dataNode->childList;
		if (child.empty()) {  // 자식이 없을 때 = ExternalNode
			cout << -1 << '\n';
			return;
		}

		if (child.size() == 1) {  // 자식 갯수 = 1
			cout << child[0]->data << '\n';
			return;
		}

		int min{ 10'000 }, max{ 0 };
		for (int i{ 0 }; i < (int)child.size(); i++) {
			if (child[i]->data < min) {
				min = child[i]->data;
			}
			if (child[i]->data > max) {
				max = child[i]->data;
			}
		}

		cout << max - min << '\n';
	}
};

Tree::Tree(int data) {
	root = new node(data, NULL);
	nodeList.push_back(root);
}

int Tree::find(int data, vector<node*>& List) {
	for (int i{ 0 }; i < (int)List.size(); i++) {
		if (List[i]->data == data) {
			return i;
		}
	}
	return -1;
}

void Tree::insertNode(int parData, int data) {
	if (find(data, nodeList) != -1) {
		cout << -1 << '\n';
		return;
	}

	int idx = find(parData, nodeList);
	if (idx == -1) {
		cout << -1 << '\n';
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
		cout << -1 << '\n';
		return;
	}

	node* delNode = nodeList[idx];
	if (delNode == root) {
		return;
	}

	node* parNode = delNode->parent;
	for (int i{ 0 }; i < (int)(delNode->childList.size()); i++) {
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
		cout << -1 << '\n';
		return;
	}

	node* curNode = nodeList[idx];
	cout << curNode->parent->data << '\n';
}

void Tree::printChild(int data) {
	int idx = find(data, nodeList);
	if (idx == -1) {
		cout << -1 << '\n';
		return;
	}

	vector<node*>& child = nodeList[idx]->childList;
	if (child.empty()) {
		cout << -1 << '\n';
		return;
	}

	for (int i{ 0 }; i < (int)child.size(); i++) {
		cout << child[i]->data << " ";
	}
	cout << '\n';
}



int main() {
	Tree tree(1);

	int n;
	cin >> n;

	while (n-- != 0) {
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
		else if (s == "parent") {
			int data;
			cin >> data;
			tree.printParent(data);
		}
		else if (s == "child") {
			int data;
			cin >> data;
			tree.printChild(data);
		}
		else if (s == "min_maxChild") {
			int data;
			cin >> data;
			tree.min_maxChild(data);
		}
	}
}