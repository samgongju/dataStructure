#include<iostream>
#include<vector>
using namespace std;

struct compare {
	bool operator()(const int& ihs, const int& rhs) {
		return ihs < rhs;
	}
};


// unsorted
class unsortedSeqPQ {
private:
	compare C;
	vector<int> arr;

public:
	int size() {
		return arr.size();
	}

	bool empty() {
		return size() == 0;
	}

	void push(int e) {
		arr.push_back(e);
	}

	int top() {
		if (empty()) { return -1; }

		int minIdx = 0;
		for (int i = 0; i < arr.size(); i++) {
			if (C(arr[i], arr[minIdx])) {
				minIdx = i;
			}
		}
	}

	void pop() {
		if (empty()) { return; }

		int minIdx = 0;
		for (int i = 0; i < arr.size(); i++) {
			if (C(arr[i], arr[minIdx])) {
				minIdx = i;
			}
		}

		arr.erase(arr.begin() + minIdx);
	}
};

class sortedSeqPQ {
private:
	compare C;
	vector<int> arr;

public:
	int size() {
		return arr.size();
	}

	bool empty() {
		return size() == 0;
	}

	void push(int e) {  // 작은 숫자가 뒤에 가 있음.
		int idx;
		for (idx = 0; idx < arr.size(); idx++) {
			if (C(arr[idx], e)) { break; }
		}
		arr.insert(arr.begin() + idx, e);
	}

	int top() {
		if (empty()) { return -1; }
		return arr.back();
	}

	void pop() {
		if (empty()) { return; }
		arr.pop_back();
	}
};

int main() {
	return 0;
}