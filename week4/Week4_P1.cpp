#include <iostream>
#include <string>
using namespace std;

class arrayQueue {
public:
	arrayQueue(int capacity);
	bool empty();
	void isEmpty();
	int size();
	void size2();
	void front();
	void enqueue(int data);
	void dequeue();
	void full();
	void rearNsum(int num);
private:
	int* arr;
	int capacity;
	int frontIndex;
	int rearIndex;
	int n;
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
void arrayQueue::isEmpty() {
	if (n == 0) {
		cout << "True" << '\n';
	}
	else {
		cout << "False" << '\n';
	}
}
int arrayQueue::size() {
	return n;
}
void arrayQueue::size2() {
	cout << n << '\n';
}

void arrayQueue::front() {
	if (empty()) {
		cout << "Empty" << '\n';
	}
	else {
		cout << arr[frontIndex] << '\n';
	}
}

void arrayQueue::enqueue(int data) {
	if (size() == capacity) {
		cout << "Full" << '\n';
	}
	else {
		arr[rearIndex] = data;
		rearIndex = (rearIndex + 1) % capacity;
		// if) rearIndex == n-1 -> 0으로 보냄
		// full 일경우, n==capacity, front,rear == 0
		// (rearIndex + capacity - 1) % capacity

		n++;
	}
}

void arrayQueue::dequeue() {
	if (empty()) {
		cout << "Empty" << '\n';
	}
	else {
		cout << arr[frontIndex] << '\n';
		frontIndex = (frontIndex + 1) % capacity;
		n--;
	}
}

void arrayQueue::full() {
	if (size() == capacity) {
		cout << "True" << '\n';
	}
	else {
		cout << "False" << '\n';
	}
}

void arrayQueue::rearNsum(int num) {
	int sum{ 0 };
	if (empty()) {
		cout << "Empty" << '\n';
	}
	else if (num > size()) {
		cout << "error" << '\n';
	}
	else {
		int index = rearIndex;
		for (int i{ 0 }; i < num; ++i) {
			index = (index - 1 + capacity) % capacity;
			// index 값을 하나씩 줄여나가고 싶을때는 이렇게!
			sum += arr[index];
		}
		cout << sum << '\n';
	}

}
int main() {
	int N, T;
	cin >> N >> T;

	arrayQueue q(N);
	string command;
	for (int i{ 0 }; i < T; ++i) {
		cin >> command;
		if (command == "size") {
			q.size2();
			continue;
		}
		if (command == "isEmpty") {
			q.isEmpty();
			continue;
		}
		if (command == "full") {
			q.full();
			continue;
		}
		if (command == "front") {
			q.front();
			continue;
		}
		if (command == "rearNsum") {
			int num;	cin >> num;
			q.rearNsum(num);
			continue;
		}
		if (command == "enqueue") {
			int value; cin >> value;
			q.enqueue(value);
			continue;
		}
		if (command == "dequeue") {
			q.dequeue();
			continue;
		}

	}

}