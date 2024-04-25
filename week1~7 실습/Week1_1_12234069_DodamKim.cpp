// problem 1

// practice 1

#include<iostream>
using namespace std;

class Array {
private:
	int* arr;
	int arrSize;

public:
	Array(int sz) {
		arrSize = sz;
		arr = new int[arrSize];

		for (int i{ 0 }; i < arrSize; i++) {
			arr[i] = 0;
		}
	}

	void at(int idx) {  // print arr[idx]
		cout << arr[idx] << '\n';
	}

	void add(int idx, int value) {  // add the vlaue at idx and shift back every number which is after index idx
		for (int i{ arrSize - 2 }; i >= idx; i--) {
			arr[i + 1] = arr[i];
		}
		arr[idx] = value;
	}

	void remove(int idx) {  // remove index idx's value and shift front every number which is after index idx
		for (int i{ idx }; i < arrSize - 1; i++) {
			arr[i] = arr[i + 1];
		}
		arr[arrSize - 1] = 0;
	}

	void set(int idx, int value) {  // arr[idx] = value: change the value of index idx
		arr[idx] = value;
	}

	void sum() {  // print sum of 
		int sum{ 0 };
		for (int i{ 0 }; i < arrSize; i++) {
			sum += arr[i];
		}
		cout << sum << '\n';
	}

	void print() {  // print array
		for (int i{ 0 }; i < arrSize; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
	}
};

int main() {
	int n, size;
	cin >> n >> size;
	string s;
	int a, b;
	Array arr(size);
	for (int i{ 0 }; i < n; i++) {
		cin >> s;
		if (s == "at") {
			cin >> a;
			arr.at(a);
		}
		else if (s == "add") {
			cin >> a >> b;
			arr.add(a, b);
		}
		else if (s == "set") {
			cin >> a >> b;
			arr.set(a, b);
		}
		else if (s == "sum") {
			arr.sum();
		}
		else if (s == "print") {
			arr.print();
		}
		else if (s == "remove") {
			cin >> a;
			arr.remove(a);
		}
	}
}