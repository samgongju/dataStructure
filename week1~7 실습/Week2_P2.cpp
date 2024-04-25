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
	void findAndInsert(int b, int a);
	void findIdx(int sk);
	void merge(singlyLinkedList a, singlyLinkedList b);
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
}

void singlyLinkedList::deletion(int i) {
	if (empty() || i < 0 || i >= sz) {
		return;
	}
	node* cur = head;
	if (i == 0) {
		if (sz == 1) {
			head = tail = NULL;
		}
		else {
			head = head->next;
		}
	}
	else {
		node* pre = head;
		for (int j{ 0 }; j < i; j++) {
			pre = cur;
			cur = cur->next;
		}
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

void singlyLinkedList::findAndInsert(int b, int a) {
	node* cur = head;
	if (cur->data == b) {
		node* nn = new node;
		nn->data = a;
		nn->next = cur;
		head = nn;
	}
	else {
		while (cur != NULL) {
			if (cur->next->data == b) {
				node* nn = new node;
				nn->data = a;
				nn->next = cur->next;
				cur->next = nn;
				break;
			}
			cur = cur->next;
		}
	}

	print();
}

void singlyLinkedList::findIdx(int sk) {
	node* cur = head;
	int i{ 0 };
	while (cur != NULL) {
		if (cur->data == sk) {
			cout << i << '\n';
			break;
		}
		cur = cur->next;
		i++;
	}
}

void singlyLinkedList::merge(singlyLinkedList a, singlyLinkedList b) {
	node* cur1 = a.head;
	while (cur1 != NULL) {
		append(cur1->data);
		cur1 = cur1->next;
	}

	cur1 = b.head;
	while (cur1 != NULL) {
		append(cur1->data);
		cur1 = cur1->next;
	}
}


int main() {
	int m;
	cin >> m;

	for (int i{ 0 }; i < m; i++) {
		singlyLinkedList sll1;
		singlyLinkedList sll2;
		int n1, n2;
		cin >> n1;
		int a;
		for (int i{ 0 }; i < n1; i++) {
			cin >> a;
			sll1.append(a);
		}

		cin >> n2;
		for (int i{ 0 }; i < n2; i++) {
			cin >> a;
			sll2.append(a);
		}

		singlyLinkedList sllM;
		sllM.merge(sll1, sll2);
		sllM.print();

		int b;
		cin >> b >> a;
		sllM.findAndInsert(b, a);
	}
}

/*
4
3
13 15 11
4
6 21 14 12
21 8
2
8 14
4
4 5 17 15
5 8
5
6 12 14 25 3
3
17 13 7
12 9
4
6 13 15 11
3
14 2 8
8 3
*/