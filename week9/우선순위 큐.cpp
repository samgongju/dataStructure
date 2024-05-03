#include<iostream>
#include<vector>
using namespace std;



struct compare {
	bool operator()(const int& ihs, const int& rhs) {
		return ihs < rhs;
	}
};

//struct compare {
//	bool operator()(const int& ihs, const int& rhs) {
//		if (ihs.age == rhs.age) {
//			return ihs.height < rhs.height;
//		}
//		return ihs.age > rhs.age;
//	}
//};


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
		return arr[minIdx];
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

	void print() {
		for (int i{ 0 }; i < size(); i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
	}
};



// sorted
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

	void print() {
		for (int i{ 0 }; i < size(); i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
	}
};



// 한 번 써 본거임.
int main() {
	int sz;
	cin >> sz;

	int* arr = new int[sz];
	for (int i{ 0 }; i < sz; i++) {
		cin >> arr[i];
	}
	
	unsortedSeqPQ uns;
	sortedSeqPQ sor;
	for (int i{ 0 }; i < sz; i++) {
		uns.push(arr[i]);
		sor.push(arr[i]);
	}
	cout << "\nunsortedSeqPQ:\nbefore: ";
	uns.print();
	cout << "after: ";
	for (int i{ 0 }; i < sz; i++) {
		arr[i] = uns.top();
		uns.pop();
	}
	for (int i{ 0 }; i < sz; i++) {
		cout << arr[i] << " ";
	}
	cout << '\n';

	cout << "\nsortedSeqPQ:\nbefore: ";
	sor.print();
	cout << "after: ";
	for (int i{ 0 }; i < sz; i++) {
		arr[i] = sor.top();
		sor.pop();
	}
	for (int i{ 0 }; i < sz; i++) {
		cout << arr[i] << " ";
	}
	cout << '\n';
}
