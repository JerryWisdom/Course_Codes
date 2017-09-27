#pragma once
#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
template <typename Type> class Vector {
private:
	int size, length;
	Type* data;
public:
	Vector(int input_size) {
		size = input_size;
		data = new Type[size];
		length = 0;
	}
	~Vector() {
		delete[] data;
	}
	bool insert(int loc, Type val) {
		if (loc<0 || loc>length) { return false; }
		if (length >= size) expand();
		for (int i = length; i>loc; i--) {
			data[i] = data[i - 1];
		}
		data[loc] = val;
		length++;
		return true;
	}
	void expand() {
		Type* old_data = data;
		size *= 2;
		data = new Type[size];
		for (int i = 0; i<length; i++) {
			data[i] = old_data[i];
		}
		delete[] old_data;
	}
	bool search(const Type &val) {
		for (int i = 0; i<length; i++) {
			if (data[i] == val) { return true; }
		}
		return false;
	}
	bool remove(int index) {
		if (index<0 || index >= length) { return false; }
		for (int i = index + 1; i<length; i++) {
			data[i - 1] = data[i];
		}
		length--;
		return true;
	}
	void print() {
		for (int i = 0; i<length; i++) {
			if (i) cout << " ";
			cout << data[i];
		}
		cout << endl;
	}
};