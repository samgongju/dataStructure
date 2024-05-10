#include<iostream>
#include<vector>
using namespace std;

struct compare {
	bool operator()(const int& ihs, const int& rhs) {
		return ihs < rhs;  // min:<, max:>
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
		if (idx == 1) { return; }

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
			if (!C(arr[left], arr[right])) {
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
		return arr.size() - 1;
	}

	bool empty() {
		return size() == 0;
	}

	void push(int e) {
		arr.push_back(e);
		upHeap(size());
	}

	int top() {
		if (empty()) { return -1; }
		return arr[1];
	}

	void pop() {
		if (empty()) { return; }

		swap(1, size());
		arr.pop_back();
		downHeap(1);
	}

	void print() {
		for (int i{ 1 }; i <= size(); i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
	}
};

int main() {
	int t;
	cin >> t;

	for (int k{ 0 }; k < t; k++) {
		int n;
		cin >> n;

		heap h;
		int a;
		for (int i{ 0 }; i < n; i++) {
			cin >> a;
			h.push(a);
		}
		h.print();
	}
}
