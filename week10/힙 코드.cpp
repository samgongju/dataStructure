// Week10_P3
#include<iostream>
#include<vector>
using namespace std;

struct compare {
	bool operator()(const int& lhs, const int& rhs) {
		return lhs > rhs;
	}
};

class heap {
private:
	compare C;
	vector<int> arr;

	void swap(int idx1, int idx2) {
		arr[0] = arr[idx1];
		arr[idx1] = arr[idx2];
		arr[idx2] = arr[0];
	}

	void upHeap(int idx) {
		if (idx == 1) {
			return;
		}

		int parent = idx / 2;
		if (!C(arr[parent], arr[idx])) {
			swap(parent, idx);
			upHeap(parent);
		}
	}

	void downHeap(int idx) {
		int left = 2 * idx;
		int right = 2 * idx + 1;
		int child;

		if (left > size()) {
			return;
		}
		else if (left == size()) {
			child = left;
		}
		else {
			if (C(arr[left], arr[right])) {
				child = left;
			}
			else {
				child = right;
			}

			if (!C(arr[idx], arr[child])) {
				swap(child, idx);
				downHeap(child);
			}
		}
	}

public:
	heap() {
		arr.push_back(0);
	}

	int size() {
		return (int)arr.size() - 1;
	}

	bool empty() {
		return size() == 0;
	}

	void push(int e) {
		arr.push_back(e);
		upHeap(size());
	}

	int top() {
		if (empty()) {
			return -1;
		}

		return arr[1];
	}

	void pop() {
		if (empty()) {
			return;
		}

		swap(1, size());
		arr.pop_back();
		downHeap(1);
	}

	void second_top() {
		if (size() < 2) {
			cout << "Error" << '\n';
			return;
		}

		int left = 2;
		int right = 3;
		if (size() == 2 || C(arr[left], arr[right])) {
			cout << arr[left] << '\n';
		}
		else {
			cout << arr[right] << '\n';
		}
	}
};

int main() {
	int n;
	cin >> n;

	string s;
	heap h;
	for (int i{ 0 }; i < n; i++) {
		cin >> s;

		if (s == "size") {
			cout << h.size() << '\n';
		}
		else if (s == "empty") {
			if (h.empty()) {
				cout << 1 << '\n';
				continue;
			}
			cout << 0 << '\n';
		}
		else if (s == "push") {
			int x;
			cin >> x;
			h.push(x);
		}
		else if (s == "pop") {
			if (h.empty()) {
				cout << -1 << '\n';
				continue;
			}
			cout << h.top() << '\n';
			h.pop();
		}
		else if (s == "top") {
			cout << h.top() << '\n';
		}
		else if (s == "second_top") {
			h.second_top();
		}
	}
}
