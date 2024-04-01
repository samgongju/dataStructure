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

listQueue::listQueue() {  // 생성자
	frontNode = rearNode = NULL;
	n = 0;
}

bool listQueue::empty() {  // empty 확인
	return n == 0;
}

int listQueue::size() {  // size 확인
	return n;
}

void listQueue::enqueue(int data) {  // data rear에 더하기
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

int listQueue::dequeue() {  // front 제거
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
	int t;  // 테스트 케이스
	cin >> t;

	for (int i{ 0 }; i < t; i++) {
		int sz;  // 각 케이스의 사이즈 저장
		cin >> sz;

		int playerPoint1{ 0 };  // 한 라운드 마다 점수 저장
		int playerPoint2{ 0 };

		listQueue p1;  // 각 플레이어의 객체 생성
		listQueue p2;
		int a;  // 입력 보조 변수
		for (int i{ 0 }; i < sz; i++) {  // 플레이어1의 카드 덱 저장
			cin >> a;
			p1.enqueue(a);
		}
		for (int i{ 0 }; i < sz; i++) {  // 플레이어2의 카드 덱 저장
			cin >> a;
			p2.enqueue(a);
		}

		int rest{ 0 };  // 체력 차이 저장하는 변수
		bool p1win{ true }, p2win{ true };  // 전 라운드에서 이겼는지 졌는지 비겼는지 저장하는 bool
		for (int i{ 1 }; i <= sz; i++) {  // 대결
			int point1{ p1.dequeue() };  // 플레이어1의 카드 덱의 첫 카드 가져오기
			int point2{ p2.dequeue() };  // 플레이어2의 카드 덱의 첫 카드 가져오기


			if (p1win == false) {  // 만약 플레이어1이 전 라운드에서 졌으면 체력 차이를 더하기
				point1 += rest;
			}
			else if (p2win == false) {  // ..
				point2 += rest;
			}

			// output 1
			cout << "Round" << i << " " << point1;

			if (point1 > point2) {  // 플레이어1이 승리
				rest = point1 - point2;
				playerPoint1++;
				p1win = true;
				p2win = false;
				cout << ">";
			}
			else if (point1 < point2) {  // 플레이어2가 승리
				rest = point2 - point1;
				playerPoint2++;
				p2win = true;
				p1win = false;
				cout << "<";
			}
			else if (point1 == point2) {  // 비김
				rest = 0;
				p2win = false;
				p1win = false;
				cout << "=";
			}

			// output 2
			cout << point2 << " " << playerPoint1 << ":" << playerPoint2 << '\n';
		}

		// 대결이 끝난 후 최종 결과 output
		if (playerPoint1 > playerPoint2) {  // 플레이어1 승리
			cout << "Winner P1\n";
		}
		else if (playerPoint2 > playerPoint1) {  // 플레이어2 승리
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