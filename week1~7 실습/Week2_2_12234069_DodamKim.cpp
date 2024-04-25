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
	void findAndDelete(int de);
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

void singlyLinkedList::findAndDelete(int de) {
	node* cur = head;
	int i{ 0 };
	while (cur != NULL) {
		if (cur->data == de) {
			deletion(i);
			break;
		}
		cur = cur->next;
		i++;
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
		
		int de, sk;
		cin >> de;
		sllM.findAndDelete(de);

		cin >> sk;
		sllM.findIdx(sk);
	}
}