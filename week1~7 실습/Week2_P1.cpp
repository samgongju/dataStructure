#include<iostream>
using namespace std;

struct node {
	int data;
	node* next;
};

class singlyLinkedList {
private:
	node* head;
	node* tail;
	int sz;

public:
	singlyLinkedList();
	bool empty();
	void append(int i);
	void deletion(int i);
	void print();
	void sum();
	void afterMax(int a) {
		if (empty() || a < 0 || a >= sz) {
			cout << "error" << '\n';
			return;
		}
		node* cur = head;
		for (int j{ 1 }; j <= a; j++) {
			cur = cur->next;
		}
		int max = { cur->data };
		for (int i{ a + 1 }; i < sz; i++) {
			cur = cur->next;
			if (cur->data > max) { max = cur->data; }
		}
		cout << max << '\n';
	}
};

singlyLinkedList::singlyLinkedList() {
	head = NULL;
	tail = NULL;
	sz = 0;
}

bool singlyLinkedList::empty() {
	return sz == 0;
}

void singlyLinkedList::append(int i) {
	node* n = new node;
	n->data = i;
	n->next = NULL;

	if (empty()) {
		head = tail = n;
	}
	else {
		tail->next = n;
		tail = n;
	}
	sz++;
	print();
}

void singlyLinkedList::deletion(int i) {
	if (empty() || i < 0 || i >= sz) {  // -------------------
		cout << -1 << '\n';
		return;
	}
	node* cur = head;
	if (i == 0) {
		if (sz == 1) {
			cout << head->data << '\n';
			head = tail = NULL;
		}
		else {
			cout << head->data << '\n';
			head = head->next;
		}
	}
	else {
		node* pre = head;
		for (int j{ 0 }; j < i; j++) {
			pre = cur;
			cur = cur->next;
		}
		cout << cur->data << '\n';
		pre->next = cur->next;
		if (cur == tail) {
			tail = pre;
		}
	}
	delete cur;
	sz--;
}

void singlyLinkedList::print() {
	if (empty()) {
		cout << "empty";
	}
	node* cur = head;
	while (cur != NULL) {
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << '\n';
}

void singlyLinkedList::sum() {
	if (sz == 0) {
		cout << 0 << '\n';
		return;
	}
	else {
		node* cur = head;
		int sum{ 0 };
		while (cur != NULL) {
			sum += cur->data;
			cur = cur->next;
		}
		cout << sum << '\n';
	}
}

int main() {
	int n;
	cin >> n;

	singlyLinkedList sll;
	string s;
	for (int i{ 0 }; i < n; i++) {
		cin >> s;
		if (s == "Print") {
			sll.print();
		}
		else if (s == "Append") {
			int a;
			cin >> a;
			sll.append(a);
		}
		else if (s == "Delete") {
			int a;
			cin >> a;
			sll.deletion(a);
		}
		else if (s == "AfterMax") {
			int a;
			cin >> a;
			sll.afterMax(a);
		}
		else if (s == "Sum") {
			sll.sum();
		}
	}
}

/*
19
Print
Sum
Append 3
Append 6
Append 8
Delete 5
Sum
Append 7
Delete 2
Print
Append 2
AfterMax 2
Delete 6
AfterMax 3
Append 4
Print
AfterMax 5
Delete 3
Print
*/