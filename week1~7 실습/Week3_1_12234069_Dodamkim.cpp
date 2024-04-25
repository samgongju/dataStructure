#include<iostream>
using namespace std;

struct node {
	int data;
	node* next;
};

class listStack {
private:
	node* topNode;
	int listSize;

public:
	listStack();
	bool empty();
	int size();
	int top();
	void push(int data);
	void pop();
};

listStack::listStack() {
	topNode = NULL;
	listSize = 0;
}

bool listStack::empty() {
	return listSize == 0;
}

int listStack::size() {
	return listSize;
}

int listStack::top() {
	if (empty()) { return -1; }
	return topNode->data;
}

void listStack::push(int data) {
	node* newNode = new node();
	newNode->data = data;
	newNode->next = topNode;
	topNode = newNode;
	listSize++;
}

void listStack::pop() {
	if (empty()) {
		return;
	}
	node* curNode = topNode;
	cout << curNode->data << " ";
	topNode = topNode->next;
	delete curNode;
	listSize--;
}


int main() {
	int n;
	cin >> n;

	string str;
	listStack stack;
	for (int i{ 0 }; i < n; i++) {
		cin >> str;

		if (str == "size") {
			cout << stack.size() << '\n';
		}

		else if (str == "empty") {
			cout << stack.empty() << '\n';
		}

		else if (str == "top") {
			cout << stack.top() << '\n';
		}

		else if (str == "push") {
			int data;
			cin >> data;
			stack.push(data);
		}
		else if (str == "pop") {
			int data;
			cin >> data;

			if (stack.empty()) {
				cout << -1 << '\n';
			}

			else if (stack.size() < data) {
				int sz{ stack.size() };
				for (int i{ 0 }; i < sz; i++) {
					stack.pop();
				}
				cout << '\n';
			}

			else if (stack.size() >= data) {
				for (int i{ 0 }; i < data; i++) {
					stack.pop();
				}
				cout << '\n';
			}
		}
	}
}