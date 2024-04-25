#include<iostream>
using namespace std;

struct node {
	char data;
	node* next;
};

class listStack {
private:
	node* topNode;
	int listSize;
	int depth{ 0 };

public:
	listStack();
	bool empty();
	int size();
	char top();
	void push(char data);
	void pop();
	void method(string s) {
		bool sign{ false };
		for (int i{ 0 }; i < s.length(); i++) {
			if (s[i] == '*') {
				push(s[i]);
				if (depth < size()) { depth = size(); }
				sign = true;
			}
			else if (s[i] == '-' || s[i] == '+') {
				if (size() == 1) {
					cout << topNode->data;
					pop();
				}
				push(s[i]);
				if (depth < size()) { depth = size(); }
			}
			else {
				cout << s[i];
				if (sign == true) {
					if (i + 1 >= s.length() || s[i + 1] != '*') {
						while (!empty()) {
							cout << topNode->data;
							pop();
						}
					}
					else {
						cout << topNode->data;
						pop();
					}
					sign = false;
				}
			}
			if (i == s.length() - 1) {
				while (!empty()) {
					cout << topNode->data;
					pop();
				}
			}
		}
	}

	void returnDepth() {
		cout << " " << depth << '\n';
		return;
	}
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

char listStack::top() {
	if (empty()) { return -1; }
	return topNode->data;
}

void listStack::push(char data) {
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
	topNode = topNode->next;
	delete curNode;
	listSize--;
}


int main() {
	int n;
	cin >> n;

	string str;
	for (int i{ 0 }; i < n; i++) {
		listStack stack;
		cin >> str;
		stack.method(str);
		stack.returnDepth();
	}
}


/*
7
1-2*3+4
1*2-3
2*3+5*6-7+3
7+8*9-2*3
6*4*4*2+3-5
3+7+6
2*5*4+3+1*7+2
*/

/*
24
9-9*8+5
4+6*2*9*7
5*5
8*8+7*9-9
1-6-3+9
6+6*8*4+1*1
1*3*1*2
3+4*9+6*9
1*8*7+9*6
5*1
6+3-3*9*9*1
6*3*1*2
7*1-9*2+5
1-8*3-2
7+5*3*6+5
4+2-7*3*9
3*7
5*5
9+8*6*1-7
7+5*5
1*3*9
9*1*9*4*3*2
6+7-8
6+1
*/