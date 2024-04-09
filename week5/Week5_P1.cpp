#include <iostream>
#include <string>
using namespace std;
// 예외: 비어있을때, pos == NULL일때
struct node {
	int data;
	node* prev;
	node* next;
};

class nodeList {
public:
	nodeList();
	void empty();
	int size();
	node* begin();
	node* end();
	void insert(int i, int x);
	void insert(node* pos, int data);
	void insertFront(int data);
	void insertBack(int data);
	void erase(node* pos);
	void erase(int i);
	void eraseFront();
	void eraseBack();
	void find(int x);
	void print(int m);
private:
	node* header;
	node* trailer;
	int n;
};

nodeList::nodeList() {
	header = new node();
	trailer = new node();
	header->next = trailer;
	trailer->prev = header;
	header->prev = trailer->next = NULL;
	n = 0;
}

void nodeList::empty() {
	if (n == 0) {
		cout << "true" << '\n';
	}
	else {
		cout << "false" << '\n';
	}
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

void nodeList::insert(int i, int x) {
	if (i < 0 || n < i) {
		cout << "out_of_range" << '\n';
	}
	else {
		node* p = new node();
		p = begin();
		// header->next
		for (int k{ 0 }; k < i; ++k) {
			// index를 i번 더해서
			// i = 1 이면 첫번째 인덱스
			p = p->next;

		}
		insert(p, x);
	}
}
// 0 = begin()

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
}

void nodeList::insertBack(int data) {
	insert(end(), data);
}

void nodeList::erase(int i) {
	if (i < 0 || n <= i) {
		cout << "out_of_range" << '\n';
	}
	else {
		node* p = new node();
		p = begin();
		// header->next
		for (int k{ 0 }; k < i; ++k) {
			// index를 i번 더해서
			// i = 1 이면 첫번째 인덱스
			p = p->next;

		}
		erase(p);

	}
}

void nodeList::erase(node* pos) {
	if (n == 0 || pos == NULL) {
		return;
	}
	// 리스트가 비어있거나, 
	// pos에 접근이 불가능한 경우
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
// find 1이 들어오면 다운
void nodeList::find(int x) {
	node* p = new node();
	int index = 0;
	p = end()->prev;

	while (p != header) {
		if (p->data == x) {
			break;
		}
		p = p->prev;
		++index;
	}
	if (p == header) {
		cout << "not_found" << '\n';
	}
	else {
		cout << index << '\n';
	}
}

void nodeList::print(int m) {
	if (n == 0) {
		cout << "empty" << '\n';
	}
	else {
		node* p = new node();
		if (m == 0) {
			p = begin();
			while (p != end()) {
				cout << p->data << " ";
				p = p->next;
			}
			cout << '\n';
		}
		else if (m == 1) {
			p = end()->prev;
			while (p != header) {
				cout << p->data << " ";
				p = p->prev;
			}
			cout << '\n';
		}
	}
}

int main() {
	int N;
	cin >> N;

	nodeList list;
	for (int i{ 0 }; i < N; ++i) {
		string str;
		cin >> str;

		if (str == "insert") {
			int i, x;
			cin >> i >> x;
			list.insert(i, x);
			continue;
		}
		if (str == "erase") {
			int i;
			cin >> i;
			list.erase(i);
			continue;
		}
		if (str == "empty") {
			list.empty();
			continue;
		}
		if (str == "find") {
			int x;	cin >> x;
			list.find(x);
			continue;
		}
		if (str == "print") {
			int m;
			cin >> m;
			list.print(m);
			continue;
		}
	}
}