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
		if (curNode->childList.size() == 0) {
			// depth 출력
			if (curNode == root) {// 현재 노드가 root일때
				return;
			}

			int n = 0;
			while (curNode != root) {
				n++;
				curNode = curNode->parent;
			}
			cout << n << " ";
			return;
		}
		else {
			// 자식 노드 중 가장 작은 노드의 번호를 출력
			int min{ 100000 };
			for (int i{ 0 }; i < (int)curNode->childList.size(); i++) {
				if (min > curNode->childList[i]->data) { min = curNode->childList[i]->data; }
			}
			cout << min << " ";
			return;
		}
	}

	node* getRoot() {
		return root;
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
		t.postorder(t.getRoot());
		cout << '\n';
	}
}