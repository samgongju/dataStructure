#include <iostream>
using namespace std;

class arrayQueue {
public:
	arrayQueue(int capacity);
	bool empty();
	int size();
	int front();
	void enqueue(int data);
	void dequeue();
	void rearNsum(int num) {
		if (empty()) {
			cout << "Empty" << "\n";
			return;
		}
		else if (num > n) {
			cout << "error" << "\n";
			return;
		}
		else {
			int s{0};
			for (int i{ 1 }; i <= num; ++i) {
				s = s + arr[(rearIndex - i + capacity) % capacity];
			}
			cout << s << "\n";
			return;
		}

	}
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
	frontIndex = rearIndex = 0; // capacity보다 크지만 않으면 아무 값 가능
	n = 0;
}

bool arrayQueue::empty() {
	return (n == 0);
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
		cout << "Full" << "\n";
		return;
	}
	arr[rearIndex] = data;
	rearIndex = (rearIndex + 1) % capacity; //-1 하고 싶으면 +capacity 해줘야함
	n++;
	return;
}

void arrayQueue::dequeue() {
	if (empty()) {
		cout << "Empty" << "\n";
		return;
	}
	cout << arr[frontIndex] << "\n";
	frontIndex = (frontIndex + 1) % capacity;
	n--;
	return;
}

int main() {
	int size; int T;
	cin >> size >> T;
	arrayQueue q(size);
	string command;

	while (T-- != 0) {
		cin >> command;
		if (command == "front") {
			if (q.empty()) {
				cout << "Empty" << "\n";
			}
			cout << q.front() << "\n";
			continue;
		}
		if (command == "enqueue") {
			int data; cin >> data;
			q.enqueue(data);
			continue;
		}
		if (command == "dequeue") {
			q.dequeue();
			continue;
		}
		if (command == "size") {
			cout << q.size() << "\n";
			continue;
		}
		if (command == "isEmpty") {
			cout << (q.empty() == 1 ? "True" : "False") << "\n";
			continue;
		}
		if (command == "full") {
			cout << (q.size() >= size ? "True" : "False") << "\n";
			continue;
		}
		if (command == "rearNsum") {
			int num; cin >> num;
			q.rearNsum(num);
			continue;
		}
	}
}