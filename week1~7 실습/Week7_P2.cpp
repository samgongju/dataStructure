#include<iostream>
#include<vector>
using namespace std;

struct node {
	int data;
	int space;
	node* parent;
	vector<node*> childList;
	node(int data, node* parent, int space) {
		this->data = data;
		this->parent = parent;
	}
};

class Tree {
private:
	node* root;
	vector<node*> nodeList;
	int find(int data, vector<node*>& list);
	int summ{ 0 };

public:
	Tree(int data);
	void insertNode(int parData, int data);
	void preorder(node* curNode);
	node* getRoot() {
		return root;
	}


	void sum(int n) {
		summ = 0;
		int idx = find(n, nodeList);
		preorder(nodeList[idx]);
		cout << summ << '\n';
	}

	bool isEx(int n) {
		int idx = find(n, nodeList);
		node* nod = nodeList[idx];

		if (nod->childList.size() == 0) {
			return true;
		}
		return false;
	}

	void allocateSpace(int idx, int sp) {
		int a = find(idx, nodeList);
		nodeList[a]->space = sp;
		return;
	}
};

Tree::Tree(int data) {
	root = new node(data, NULL, 0);
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
	node* newNode = new node(data, parNode, 0);
	parNode->childList.push_back(newNode);
	nodeList.push_back(newNode);
	return;
}

void Tree::preorder(node* curNode) {
	summ += curNode->space;
	for (int i{ 0 }; i < (int)(curNode->childList.size()); i++) {
		preorder(curNode->childList[i]);
	}
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

	for (int i{ 0 }; i < n; i++) {
		cin >> x >> y;
		t.allocateSpace(x, y);
	}

	int a;
	for (int i{ 0 }; i < m; i++) {
		cin >> a;
		t.sum(a);
	}
}

/*
11 5
1 2
1 5
2 8
2 12
12 11
8 4
1 10
10 7
12 6
8 16
1 222
2 30
11 333
12 55
8 33
4 10
16 3
7 20
6 205
10 15
5 70
11
6
10
4
2
*/