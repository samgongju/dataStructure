
// array queue

#include<iostream>
using namespace std;

class arrayQueue {
private:
	int* arr;
	int capacity;
	int frontIndex;
	int rearIndex;
	int n;

public:
	arrayQueue(int capacity);
	bool empty();
	int size();
	int front();
	void enqueue(int data);
	void dequeue();
	bool full(){
		return n == capacity;
	}
	void rearNsum(int num) {
		if (empty()) {
			cout << "Empty\n";
		}
		else if (num > n){
			cout << "error\n";
		}
		else {
			int sum{ 0 };
			int ri{ (rearIndex == 0 ? capacity - 1 : rearIndex - 1) };
			for (int i{ 0 }; i < num; i++) {
				sum += arr[ri % capacity];
				ri--;
				if (ri < 0) {
					ri = capacity - 1;
				}
			}
			cout << sum << '\n';
		}
	}
};

arrayQueue::arrayQueue(int capacity) {
	this->capacity = capacity;
	arr = new int[capacity];
	frontIndex = rearIndex = 0;
	n = 0;
}

bool arrayQueue::empty() {
	return n == 0;
}

int arrayQueue::size() {
	return n;
}

int arrayQueue::front() {
	if (empty()) {
		return -1;
	}
	return arr[frontIndex];
}

void arrayQueue::enqueue(int data) {
	if (size() == capacity) {
		cout << "Full\n";
		return;
	}
	arr[rearIndex] = data;
	rearIndex = (rearIndex + 1) % capacity;
	n++;
}

void arrayQueue::dequeue() {
	if (empty()) {
		cout << "Empty\n";
		return;
	}
	cout << arr[frontIndex] << '\n';
	frontIndex = (frontIndex + 1) % capacity;
	n--;
}



int main() {
	int n, t;
	cin >> n >> t;

	string str;
	arrayQueue q(n);
	for (int i{ 0 }; i < t; i++) {
		cin >> str;

		if (str == "front") {
			if (q.front() != -1) {
				cout << q.front() << '\n';
			}
			else {
				cout << "Empty\n";
			}
		}
		else if (str == "size") {
			cout << q.size() << '\n';
		}
		else if (str == "full") {
			if (q.full()) {
				cout << "True\n";
			}
			else {
				cout << "False\n";
			}
		}
		else if (str == "isEmpty") {
			if (q.empty()) {
				cout << "True\n";
			}
			else {
				cout << "False\n";
			}
		}
		else if (str == "rearNsum") {
			int a;
			cin >> a;
			q.rearNsum(a);
		}
		else if (str == "enqueue") {
			int a;
			cin >> a;
			q.enqueue(a);
		}
		else if (str == "dequeue") {
			q.dequeue();
		}
	}
}

/*
6 18
isEmpty
size
dequeue
rearNsum 1
enqueue 7
enqueue 11
enqueue 4
size
enqueue 2
enqueue 17
dequeue
size
enqueue 31
full
isEmpty
rearNsum 2
rearNsum 6
front
*/
