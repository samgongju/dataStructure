// week5
// 리스트 코드(클래스 구조)

#include<iostream>
using namespace std;

struct node {
	int data;
	node* prev;
	node* next;
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
}
void nodeList::insertBack(int data) {
	insert(end(), data);
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
	nodeList list;
	node* p = list.begin();
	
	int data{ 0 };  // 기존 ppt에는 없는 것임.
	list.insert(p, data);

	list.erase(p);
	p = list.begin();

	if (p != list.end()) {
		p = p->next;
	}

	if (p != list.begin()) {
		p = p->prev;
	}
}