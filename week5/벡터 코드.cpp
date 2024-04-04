// Week5
// 벡터 코드

#include<iostream>
using namespace std;

class arrayVector {
private:
	int capacity;
	int n;
	int* arr;
	void reserve(int size);

public:
	arrayVector();
	bool empty();
	int size();
	int at(int idx);
	void set(int idx, int data);
	void erase(int idx);
	void insert(int idx, int data);
};

arrayVector::arrayVector() {
	capacity = 1;
	arr = new int[1];
	n = 0;
}
bool arrayVector::empty() {
	return n == 0;
}

int arrayVector::size() {
	return n;
}
int arrayVector::at(int idx) {
	if (idx< 0 || idx >= n) {
		return -1;
	}
	return arr[idx];
}

void arrayVector::set(int idx, int data) {
	if (idx < 0 || idx >= n) {
		return;
	}
	arr[idx] = data;
}

void arrayVector::erase(int idx) {
	if (idx < 0 || idx >= n) {
		return;
	}

	for (int i{ idx + 1 }; i < n; i++) {
		arr[i - 1] = arr[i];
	}
	n--;
}

void arrayVector::insert(int idx, int data) {
	if (idx < 0 || idx >= n) {
		return;
	}
	if (n == capacity) {
		reserve(2 * capacity);
	}
	for (int i{ n - 1 }; i >= idx; i--) {
		arr[i + 1] = arr[i];
	}
	arr[idx] = data;
	n++;
}

void arrayVector::reserve(int size) {
	if (size <= capacity) {
		return;
	}
	int* arrTemp = new int[size];
	for (int i = 0; i < n; i++) {
		arrTemp[i] = arr[i];
	}

	if (arr != NULL) {
		delete[] arr;
	}

	arr = arrTemp;
	capacity = size;
}

int main() {
	return 0;
}
