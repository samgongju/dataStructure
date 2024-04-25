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
	vector<int> cL;

public:
	Tree(int data);
	void insertNode(int parData, int data);
	void postorder(node* curNode);
	void process(node* curNode) {
		int mm{ curNode->data };

		while (curNode != root) {
			curNode = curNode->parent;
			if (curNode->data > mm) { mm = curNode->data; }
		}
		cout << mm << " ";
	}

	node* getRoot() {
		return root;
	}

	void preorder(node* curNode) {
		process(curNode);
		for (int i{ 0 }; i < (int)(curNode->childList.size()); i++) {
			preorder(curNode->childList[i]);
		}
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

void Tree::postorder(node* curNode) {
	for (int i{ 0 }; i < (int)(curNode->childList.size()); i++) {
		postorder(curNode->childList[i]);
	}
	process(curNode);
}



int main() {
	int testcase;
	cin >> testcase;
	for (int i{ 0 }; i < testcase; i++) {
		int n;
		cin >> n;

		Tree t(1);
		for (int i{ 0 }; i < n - 1; i++) {
			int x, y;
			cin >> x >> y;
			t.insertNode(x, y);
		}

		// output
		t.preorder(t.getRoot());
		cout << '\n';
	}
}

/*
2
10
1 6
6 5
1 4
4 9
1 2
9 3
9 8
6 7
9 10
7
1 7
1 5
5 4
1 3
3 2
3 6
*/