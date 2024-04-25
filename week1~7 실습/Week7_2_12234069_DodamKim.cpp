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
	int find(int data, vector<node*>& list);

public:
	Tree(int data);
	void insertNode(int parData, int data);
	void preorder(node* curNode);
	void postorder(node* curNode);
	node* getRoot() {
		return root;
	}

	int sum(int n) {
		int idx = find(n, nodeList);
		node* nod = nodeList[idx];
		if (nod == root) {
			return 0;
		}
		else {
			int n = 0;
			while (nod != root) {
				nod = nod->parent;
				n += nod->data;
			}
			return n;
		}
	}

	bool isEx(int n) {
		int idx = find(n, nodeList);
		node* nod = nodeList[idx];

		if (nod->childList.size() == 0) {
			return true;
		}
		return false;
	}
};

Tree::Tree(int data) {
	root = new node(data, NULL);
	nodeList.push_back(root);
}

int Tree::find(int data, vector<node*>& list) {
	for (int i{ 0 }; i < (int)(list.size()); i++) {
		if (list[i]->data == data) {
			return i;
		}
	}
	return -1;
}

void Tree::insertNode(int parData, int data) {
	if (find(data, nodeList) != -1) {  //  넣을 노드가 이미 존재
		return;
	}
	int idx = find(parData, nodeList);
	if (idx == -1) {  // 부모 노드가 존재하지 않음
		return;
	}
	node* parNode = nodeList[idx];
	node* newNode = new node(data, parNode);
	parNode->childList.push_back(newNode);
	nodeList.push_back(newNode);
	return;
}

void Tree::preorder(node* curNode) {
	cout << curNode->data << " ";
	for (int i{ 0 }; i < (int)(curNode->childList.size()); i++) {
		preorder(curNode->childList[i]);
	}
}

void Tree::postorder(node* curNode) {
	for (int i{ 0 }; i < (int)(curNode->childList.size()); i++) {
		postorder(curNode->childList[i]);
	}
	cout << curNode->data << " ";
}





int main() {
	Tree t(1);
	int n, m;
	cin >> n >> m;

	int x, y;
	for (int i{ 0 }; i < n - 1; i++) {
		cin >> x >> y;
		t.insertNode(x, y);
	}

	int a;
	for (int i{ 0 }; i < m; i++) {
		cin >> a;
		cout << (t.isEx(a) ? "D" : "F") << " " << t.sum(a) << '\n';
	}
}