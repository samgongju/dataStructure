//Week3_2_12234069_DodamKim

#include<iostream>
#include<string>
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
	char top();
	void push(int data);
	void pop();
	int method(string s){
		for (int i{ 0 }; i < s.size(); i++) {
			if (s[i] == '*' || s[i] == '+' || s[i] == '-') {
				int b = topNode->data;
				pop();
				int a = topNode->data;
				pop();

				if (s[i] == '+') {
					push(a + b);
				}
				else if (s[i] == '-') {
					push(a - b);
				}
				else if (s[i] == '*') {
					push(a * b);
				}
			}
			else {
				push(s[i] - '0');
			}
			if (i == s.size() - 1) {
				return topNode->data;
			}
		}
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
	topNode = topNode->next;
	delete curNode;
	listSize--;
}

int main() {
	int t;
	cin >> t;

	for (int i{ 0 }; i < t; i++) {
		string str{ "" };
		int k{ 0 };
		cin >> str >> k;
		listStack stack;
		cout << abs(stack.method(str)) % k << '\n';
	}
}


/*
9
35+ 3
34* 5
23+ 2
34*5+ 6
452-+ 4
36+67*- 9
378+-2* 5
357+2*+2+ 7
3548--+ 2
*/