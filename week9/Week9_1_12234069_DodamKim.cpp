#include<iostream>
#include<vector>
using namespace std;

struct compare {
	bool operator()(const int& ihs, const int& rhs) {
		return ihs > rhs;
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
		for (int i = 0; i < size(); i++) {
			if (C(arr[i], arr[minIdx])) {
				minIdx = i;
			}
		}
		return arr[minIdx];
	}

	void pop() {
		if (empty()) { return; }

		int minIdx = 0;
		for (int i = 0; i < size(); i++) {
			if (C(arr[i], arr[minIdx])) {
				minIdx = i;
			}
		}

		arr.erase(arr.begin() + minIdx);
	}

	void print() {
		for (int i{ 0 }; i < size(); i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
	}
};

int main() {
	int t;
	cin >> t;

	for (int k{ 0 };k < t; k++) {
		int sz;
		cin >> sz;

		int* arr = new int[sz];
		for (int i{ 0 }; i < sz; i++) {
			cin >> arr[i];
		}

		int n;
		cin >> n;

		unsortedSeqPQ uns;
		if (n >= sz) {
			for (int i{ 0 }; i < sz; i++) {
				uns.push(arr[i]);
			}
			cout << "S : ";
			for (int i{ 0 }; i < n - sz; i++) {
				cout << uns.top() << " ";
				uns.pop();
			}
			cout << "\nPQ : ";
			uns.print();
		}
		else if (n < sz) {
			for (int i{ 0 }; i < n; i++) {
				uns.push(arr[i]);
			}
			cout << "S : ";
			for (int i{ n }; i < sz; i++) {
				cout << arr[i] << " ";
			}
			cout << "\nPQ : ";
			uns.print();
		}
	}
}

/*
2
7
7 4 8 2 5 3 9
10
10
1 4 2 8 9 7 23 3 66 5
6
*/