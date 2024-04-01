#include <iostream>
#include <string>
using namespace std;

struct node {
	int data;
	node* next;
};

class listQueue {
public:
	listQueue();
	bool empty();
	int size();
	int front();
	void enqueue(int data);
	void dequeue(int gap);
private:
	node* frontNode;
	node* rearNode;
	int n;
};

listQueue::listQueue() {
	frontNode = NULL;
	rearNode = NULL;
	n = 0;
}

bool listQueue::empty() {
	return n == 0;
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
		rearNode->next = newNode;
		rearNode = newNode;
	}
	n++;
}// 새로운 노드는 맨 마지막(tail)에 들어옴


void listQueue::dequeue(int gap) {
	if (empty()) {
		return;
	}
	node* curNode = frontNode;
	if (size() == 1) {
		frontNode = rearNode = NULL;
	}
	else {
		frontNode = frontNode->next;
		frontNode->data += gap;
	}
	delete curNode;
	n--;
} // frontNode(head, 제일 먼저 들어온것) 부터 삭제

int main() {
	int T;
	cin >> T;

	for (int i{ 0 }; i < T; ++i) {
		listQueue P1;
		listQueue P2;
		int score_P1{ 0 };
		int score_P2{ 0 };
		bool is_win_P1{ false };
		bool is_win_P2{ false };
		bool is_draw{ false };

		int N;
		cin >> N;
		for (int j{ 0 }; j < N; ++j) {
			int data;
			cin >> data;
			P1.enqueue(data);
		}
		for (int k{ 0 }; k < N; ++k) {
			int data;
			cin >> data;
			P2.enqueue(data);
		}
		for (int r{ 0 }; r < N; ++r) {
			if (P1.front() > P2.front()) {
				++score_P1;

				cout << "Round" << r + 1 << ' '
					<< P1.front() << ">" << P2.front() << ' ';
				cout << score_P1 << ":" << score_P2 << '\n';

				int gap = P1.front() - P2.front();
				P1.dequeue(0);
				P2.dequeue(gap);
				if (r == N - 1 && score_P1==score_P2) {
					is_win_P1 = true;
				}
			}
			else if (P1.front() < P2.front()) {
				++score_P2;
				cout << "Round" << r + 1 << ' '
					<< P1.front() << "<" << P2.front() << ' ';
				cout << score_P1 << ":" << score_P2 << '\n';

				int gap = P2.front() - P1.front();
				P1.dequeue(gap);
				P2.dequeue(0);
				if (r == N - 1 && score_P1 == score_P2) {
					is_win_P2 = true;
				}
			}
			else if(P1.front()==P2.front()) {
				cout << "Round" << r + 1 << ' '
					<< P1.front() << "=" << P2.front() << ' ';
				cout << score_P1 << ":" << score_P2 << '\n';

				P1.dequeue(0);
				P2.dequeue(0);
				if (r == N - 1) {
					is_draw = true;
				}
			}
		}
		if (score_P1 == score_P2) {
			if (is_win_P1) {
				cout << "Winner P1" << '\n';
			}
			else if (is_win_P2) {
				cout << "Winner P2" << '\n';
			}
			else if (is_draw) {
				cout << "Draw" << '\n';
			}
		}
		else if (score_P1 > score_P2) {
			cout << "Winner P1" << '\n';
		}
		else if(score_P1 < score_P2) {
			cout << "Winner P2" << '\n';
		}
	}
}