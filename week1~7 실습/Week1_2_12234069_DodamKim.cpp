// problem 2

// practice 1

#include<iostream>
using namespace std;

class Array {
private:
	int* arr;  // to make dynamic allocation
	int arrSize;

public:
	Array(int sz) {  // constructor: arr[i] = i
		this -> arrSize = sz;
		this -> arr = new int[arrSize];

		for (int i{ 0 }; i < arrSize; i++) {
			arr[i] = i;
		}
	}

	void print() {  // output arr
		for (int i{ 0 }; i < arrSize; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
	}

	void shift(int a, int b) {  // shift between a, b
		int tmp = arr[a];
		for (int i{ a }; i < b; i++) {
			arr[i] = arr[i + 1];
		}
		arr[b] = tmp;
	}

	void swap(int a, int b) { // swap a, b
		int tmp{ arr[a] };
		arr[a] = arr[b];
		arr[b] = tmp;
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
		if (s == "print") {
			arr.print();
		}
		else if (s == "shift") {
			cin >> a >> b;
			arr.shift(a, b);
		}
		else if (s == "swap") {
			cin >> a >> b;
			arr.swap(a, b);
		}
		else {
			return 0;
		}
	}
}