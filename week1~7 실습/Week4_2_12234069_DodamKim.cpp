// linked list queue

#include<iostream>
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
	void enqueue(int data);
	int dequeue();
};

listQueue::listQueue() {  // ������
	frontNode = rearNode = NULL;
	n = 0;
}

bool listQueue::empty() {  // empty Ȯ��
	return n == 0;
}

int listQueue::size() {  // size Ȯ��
	return n;
}

void listQueue::enqueue(int data) {  // data rear�� ���ϱ�
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
}

int listQueue::dequeue() {  // front ����
	if (empty()) {
		return -1;
	}
	node* curNOde = frontNode;
	int a{ frontNode->data };
	if (size() == 1) {
		frontNode = rearNode = NULL;
	}
	else {
		frontNode = frontNode->next;
	}
	delete curNOde;
	n--;
	return a;
}



int main() {
	int t;  // �׽�Ʈ ���̽�
	cin >> t;

	for (int i{ 0 }; i < t; i++) {
		int sz;  // �� ���̽��� ������ ����
		cin >> sz;

		int playerPoint1{ 0 };  // �� ���� ���� ���� ����
		int playerPoint2{ 0 };

		listQueue p1;  // �� �÷��̾��� ��ü ����
		listQueue p2;
		int a;  // �Է� ���� ����
		for (int i{ 0 }; i < sz; i++) {  // �÷��̾�1�� ī�� �� ����
			cin >> a;
			p1.enqueue(a);
		}
		for (int i{ 0 }; i < sz; i++) {  // �÷��̾�2�� ī�� �� ����
			cin >> a;
			p2.enqueue(a);
		}

		int rest{ 0 };  // ü�� ���� �����ϴ� ����
		bool p1win{ true }, p2win{ true };  // �� ���忡�� �̰���� ������ ������ �����ϴ� bool
		for (int i{ 1 }; i <= sz; i++) {  // ���
			int point1{ p1.dequeue() };  // �÷��̾�1�� ī�� ���� ù ī�� ��������
			int point2{ p2.dequeue() };  // �÷��̾�2�� ī�� ���� ù ī�� ��������


			if (p1win == false) {  // ���� �÷��̾�1�� �� ���忡�� ������ ü�� ���̸� ���ϱ�
				point1 += rest;
			}
			else if (p2win == false) {  // ..
				point2 += rest;
			}

			// output 1
			cout << "Round" << i << " " << point1;

			if (point1 > point2) {  // �÷��̾�1�� �¸�
				rest = point1 - point2;
				playerPoint1++;
				p1win = true;
				p2win = false;
				cout << ">";
			}
			else if (point1 < point2) {  // �÷��̾�2�� �¸�
				rest = point2 - point1;
				playerPoint2++;
				p2win = true;
				p1win = false;
				cout << "<";
			}
			else if (point1 == point2) {  // ���
				rest = 0;
				p2win = false;
				p1win = false;
				cout << "=";
			}

			// output 2
			cout << point2 << " " << playerPoint1 << ":" << playerPoint2 << '\n';
		}

		// ����� ���� �� ���� ��� output
		if (playerPoint1 > playerPoint2) {  // �÷��̾�1 �¸�
			cout << "Winner P1\n";
		}
		else if (playerPoint2 > playerPoint1) {  // �÷��̾�2 �¸�
			cout << "Winner P2\n";
		}
		else if (playerPoint1 == playerPoint2) {
			if (p2win == false && p1win == false) {
				cout << "Draw" << '\n';
			}
			else {
				if (p2win) {
					cout << "Winner P2\n";
				}
				else if (p1win) {
					cout << "Winner P1\n";
				}
			}
		}
	}
}