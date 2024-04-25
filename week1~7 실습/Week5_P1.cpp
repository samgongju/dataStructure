// Week5_P1

#include<iostream>
using namespace std;

struct node {
	int data;
	node* prev;
	node* next;

	node() {
		data = 0;
		prev = next = nullptr;
	}

	node(int data, node* prev, node* next) {
		this->data = data;
		this->prev = prev;
		this->next = next;
		prev->next = this;
		next->prev = this;
	}

	~node() {
		this->next->prev = this->prev;
		this->prev->next = this->next;
	}
};

class nodeList {
private:
	node* header;
	node* trailer;
	int n;

public:
	nodeList();
	bool empty();
	int size();
	node* begin();
	node* end();
	void insert(node* pos, int data);
	void insertFront(int data);
	void insertBack(int data);
	void erase(node* pos);
	void eraseFront();
	void eraseBack();
	void findX(int a) {
		node* p = begin();
		int sz = size();

		for (int i{ 0 }; i < sz; i++) {
			if (p->data == a) {
				cout << i << '\n';
				return;
			}
			if (sz != n - 1) {
				p = p->next;
			}
		}
		cout << "not_found\n";
		return;
	}

	void print1() {
		node* p = end()->prev;
		int sz = size();

		for (int i{ 0 }; i < sz; i++) {
			cout << p->data << " ";
			p = p->prev;
		}
		cout << '\n';
	}

	void print0() {
		node* p = begin();
		int sz = size();
		for (int i{ 0 }; i < sz; i++) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << '\n';
	}
};

nodeList::nodeList() {
	header = new node();
	trailer = new node();
	header->next = trailer;
	trailer->prev = header;
	header->prev = trailer->next = NULL;
	n = 0;
}

bool nodeList::empty() {
	return n == 0;
}

int nodeList::size() {
	return n;
}

node* nodeList::begin() {
	return header->next;
}

node* nodeList::end() {
	return trailer;
}

void nodeList::insert(node* pos, int data) {
	node* newNode = new node();
	newNode->data = data;
	newNode->prev = pos->prev;
	newNode->next = pos;
	pos->prev->next = newNode;
	pos->prev = newNode;
	n++;
}

void nodeList::insertFront(int data) {
	insert(begin(), data);
	return;
}

void nodeList::insertBack(int data) {
	insert(end(), data);
	return;
}

void nodeList::erase(node* pos) {
	if (empty() || pos == NULL) {
		return;
	}
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	delete pos;
	n--;
}

void nodeList::eraseFront() {
	erase(begin());
}

void nodeList::eraseBack() {
	erase(end()->prev);
}



int main() {
	int n;
	cin >> n;

	string s;
	nodeList list;
	node* p = list.begin();
	for (int i{ 0 }; i < n; i++) {
		cin >> s;

		if (s == "insert") {
			int a, b;
			cin >> a >> b;

			if (a < 0 || a > list.size()) {
				cout << "out_of_range\n";
				continue;
			}

			if (a == 0) {
				list.insertFront(b);
			}
			else if (a == list.size()) {
				list.insertBack(b);
			}
			else {
				p = list.begin();
				for (int i{ 0 }; i < a; i++) {
					p = p->next;
				}
				list.insert(p, b);
			}
		}

		else if (s == "erase") {
			int a;
			cin >> a;

			if (a >= list.size() || a < 0) {
				cout << "out_of_range\n";
				continue;
			}

			p = list.begin();
			for (int i{ 0 }; i < a; i++) {
				p = p->next;
			}
			list.erase(p);
		}
		else if (s == "empty") {
			cout << boolalpha << list.empty() << '\n';
		}
		else if (s == "find") {
			int a;
			cin >> a;

			if (list.size() == 0) {
				cout << "not_found\n";
				continue;
			}

			list.findX(a);
		}
		else if (s == "print") {
			int a;
			cin >> a;

			if (list.size() == 0) {
				cout << "empty\n";
				continue;
			}

			if (a == 0) {
				list.print0();
			}
			else if (a == 1) {
				list.print1();
			}
		}
	}
}

/*
16
empty
insert 0 5
insert 1 3
print 1
insert 1 2
erase 3
erase 1
find 1
find 5
insert 1 14
print 0
empty
insert 0 2
insert 3 2
find 2
print 1
*/