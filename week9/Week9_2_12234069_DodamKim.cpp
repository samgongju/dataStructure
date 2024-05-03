#include<iostream>
#include<vector>
using namespace std;

// compare
struct compare {
	bool operator()(const string& ihs, const string& rhs) {
		if (ihs.length() == rhs.length()) {
			for (int i{ 0 }; i < (int)ihs.length(); i++) {
				if ((ihs[i] - '0') < (rhs[i] - '0')) {
					return ihs < rhs;
				}
			}
		}
		return ihs.length() > rhs.length();
	}
};

// sorted
class sortedSeqPQ {
private:
	compare C;
	vector<string> arr;

public:
	int size() {
		return arr.size();
	}

	bool empty() {
		return size() == 0;
	}

	void push(string e) {  // 작은 숫자가 뒤에 가 있음.
		int idx;
		for (idx = 0; idx < size(); idx++) {
			if (C(arr[idx], e)) { break; }
		}
		arr.insert(arr.begin() + idx, e);
	}

	string top() {
		if (empty()) { return ""; }
		return arr.back();
	}

	void pop() {
		if (empty()) { return; }
		arr.pop_back();
	}
};

// main
int main() {
	int t;
	cin >> t;

	for (int k{ 1 }; k <= t; k++) {
		int n;
		cin >> n;

		sortedSeqPQ s;
		string a;
		for (int j{ 0 }; j < n; j++) {
			cin >> a;
			s.push(a);
		}

		cout << "Case #" << k << ".\n";
		for (int i{ 0 }; i < n; i++) {
			cout << s.top() << " ";
			s.pop();
		}
		cout << '\n';
	}
}

/*
2
7
614 8 3525 4132 27 482 16656
10
824 120 565 74 17 175 170 163 1293 3696
*/