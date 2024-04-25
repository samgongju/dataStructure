#include <iostream>
#include <string>
using namespace std;

struct node {
	string data;
	node* prev;
	node* next;

	node() {
		data = "";
		prev = next = nullptr;
	}
};

class nodeList {
public:
	nodeList();
	bool empty();
	int size();
	node* begin();
	node* end();
	void insert(node* pos, string data);
	void insertFront(string data);
	void insertBack(string data);
	void erase(node* pos);
	void eraseFront();
	void eraseBack();
	node* up(node* pos, int X);
	node* down(node* pos, int X);
	node* cut(node* pos);
	node* append(node* pos, string name);
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

void nodeList::insert(node* pos, string data) {
	node* newNode = new node();
	newNode->data = data;
	newNode->prev = pos->prev;
	newNode->next = pos;
	pos->prev->next = newNode;
	pos->prev = newNode;
	n++;
}

void nodeList::insertFront(string data) {
	insert(begin(), data);
}

void nodeList::insertBack(string data) {
	insert(end(), data);
}

void nodeList::erase(node* pos) {
	if (empty() || pos == NULL)
		return;
	else {
		pos->prev->next = pos->next;
		pos->next->prev = pos->prev;
		delete pos;
		n--;
	}
}

void nodeList::eraseFront() {
	erase(begin());
}
void nodeList::eraseBack() {
	erase(end()->prev);
}

node* nodeList::up(node* pos, int X) {
	for (int i{ 0 }; i < X; ++i) {
		pos = pos->prev;
		if (pos == header) {
			pos = begin();
			break;
		}
	}
	return pos;
}
node* nodeList::down(node* pos, int X) {
	for (int i{ 0 }; i < X; ++i) {
		pos = pos->next;
		if (pos == trailer) {
			pos = end()->prev;
			break;
		}
	}
	return pos;
}
node* nodeList::cut(node* pos) {
	node* tmp = pos;
	pos = pos->next;
	erase(tmp);
	return pos;
}

node* nodeList::append(node* pos, string name) {
	insert(pos->next, name);
	return pos->next;
}

int main() {
	int T;
	cin >> T;
	for (int i{ 0 }; i < T; ++i) {
		nodeList list;
		int N, M, K;
		cin >> N >> M >> K;
		for (int j{ 0 }; j < N; ++j) {
			string str;
			cin >> str;
			list.insertBack(str);
		}
		node* p = list.begin();
		for (int select{ 0 }; select < K; ++select) {
			p = p->next;
		}
		for (int t{ 0 }; t < M; ++t) {
			string command;
			cin >> command;
			if (command == "up") {
				int X;	cin >> X;
				if (list.empty()) {
					continue;
				}
				else {
					p = list.up(p, X);
					continue;
				}
			}
			if (command == "down") {
				int X;	cin >> X;
				if (list.empty()) {
					continue;
				}
				else {
					p = list.down(p, X);
					continue;
				}
			}
			if (command == "cut") {
				if (list.empty()) {
					continue;
				}
				else if (p == list.begin()) {
					p = p->next;
					list.eraseFront();
					continue;
				}
				else {
					p = list.cut(p);
					continue;
				}
			}
			if (command == "append") {
				string name;	cin >> name;
				if (list.empty()) {
					list.insertFront(name);
					p = list.begin();
				}
				else {
					p = list.append(p, name);
				}
			}
		}
		if (list.empty()) {
			cout << "And Then There Were None" << '\n';
		}
		else {
			node* cur = list.begin();
			while (cur != list.end()) {
				cout << cur->data << " ";
				cur = cur->next;
			}
			cout << '\n';
		}
	}
}

/*
1
4 10 1
inha
biryong
induck
annyong
up 3
cut
down 2
append
areum
up 2
append wolcheon
up 1
cut
cut
down 3
*/