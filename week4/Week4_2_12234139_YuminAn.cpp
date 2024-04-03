#include <iostream>
using namespace std;

struct node {
	int data;
	node* next;
};

class listQueue {
private:
	node* frontNode;
	node* rearNode;
	int n;

public:
	listQueue();
	bool empty();
	int size();
	int front();
	void enqueue(int data);
	int dequeue();
};

listQueue::listQueue() {
	frontNode = rearNode = NULL;
	n = 0;
}

bool listQueue::empty() {
	return (n == 0);
}

int listQueue::size() {
	return n;
}

int listQueue::front() {
	if (empty()) {
		return -1;
	}
	return frontNode->data;
}

void listQueue::enqueue(int data) {
	node* newNode = new node;
	newNode->data = data;
	newNode->next = NULL;
	if (empty()) {
		frontNode = rearNode = newNode;
	}
	else {
		rearNode->next = newNode; // 마지막 노드와 새 노드 연결
		rearNode = newNode; // 꼬리노드가 새노드 가리키게
	}
	n++;
}

int listQueue::dequeue() {
	if (empty()) {
		return 0;
	}
	node* curNode = frontNode;
	if (size() == 1) {
		frontNode = rearNode = NULL;
	}
	else {
		frontNode = frontNode->next;
	}
	int m = curNode->data;
	delete curNode;
	n--;
	return m;
}

int main() {
	int T, N, x, m=0, w=0, p1, p2, s1 = 0, s2 = 0;
	cin >> T;
	while (T-- != 0) {
		cin >> N;
		listQueue q1;
		listQueue q2;
		for (int i = 0; i < N; i++) {
			cin >> x;
			q1.enqueue(x);
		}
		for (int i = 0; i < N; i++) {
			cin >> x;
			q2.enqueue(x);
		}
		for(int i=1;i<=N;++i) {
			cout << "Round" << i << " ";
			p1 = q1.dequeue();
			p2 = q2.dequeue();
			if (w == 1) {
				p2 += m;
				cout << p1;
				if (p1 > p2) {
					cout << ">";
					w = 1;
					++s1;
					m = p1 - p2;
				}
				else if (p1 == p2) {
					cout << "=";
					m = 0;
				}
				else {
					cout << "<";
					w = 2;
					++s2;
					m = p2 - p1;
				}
				cout << p2;
			}
			else {
				p1 += m;
				cout << p1;
				if (p1 > p2) {
					cout << ">";
					w = 1;
					++s1;
					m = p1 - p2;
				}
				else if (p1 == p2) {
					cout << "=";
					m = 0;
				}
				else {
					cout << "<";
					w = 2;
					++s2;
					m = p2 - p1;
				}
				cout << p2 ;
			}
			cout << " " << s1 << ":" << s2 << endl;
		}
		if (s1 > s2) cout << "Winner P1" << endl;
		else if (s1 < s2) cout << "Winner P2" << endl;
		else {
			if (p1 > p2) {
				cout << "Winner P1" << endl;
			}
			else if (p1 < p2) {
				cout << "Winner P2" << endl;
			}
			else {
				cout << "Draw" << endl;
			}
		}
		s1 = s2 = m = w = 0;
	}
}