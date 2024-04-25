// Week6_2_12234069_DodamKim

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
	int depth(int v) {
		int idx = find(v, nodeList);
		if (idx == -1) {
			return -100;
		}

		node* self = nodeList[idx];
		int depth{ 0 };
		while (self != root) {
			self = self->parent;
			depth++;
		}
		return depth;
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
	if (find(data, nodeList) != -1) {  // 이미 노드가 존재
		cout << -1 << '\n';
		return;
	}

	int idx = find(parData, nodeList);
	if (idx == -1) {  // 부모가 존재하지 않음
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

	for (int i{ 0 }; i < (int)child.size(); i++) {
		cout << child[i]->data << " ";
	}
	cout << '\n';
}



int main() {
	Tree tree(1);

	int n, m;
	cin >> n >> m;

	for (int i{ 0 }; i < n; i++) {
		int x, y;
		cin >> x >> y;
		tree.insertNode(x, y);
	}

	for (int i{ 0 }; i < m; i++) {
		int v, w;
		cin >> v >> w;

		int vDepth = tree.depth(v);
		int wDepth = tree.depth(w);
		if (vDepth < 0 || wDepth < 0) {
			cout << "error" << '\n';
			continue;
		}
		cout << vDepth << " " << wDepth << " " << vDepth + wDepth << '\n';
	}
} 