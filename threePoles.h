// threePoles.h : Include file for standard system include files,
// or project specific include files.

#pragma once
#include "assert.h"
#include <iostream>
#include <vector>

class Pole {
public:
	int* discs;
	size_t SIZE;
	size_t MAX_SIZE;

	Pole(size_t max_size) {
		MAX_SIZE = max_size;
		SIZE = 0;
		discs = new int[MAX_SIZE];
	}

	~Pole() {
		delete[] discs;
	}

	void fill() {
		for (int i = 0; i < MAX_SIZE; ++i) {
			discs[i] = MAX_SIZE - i;
		}
		SIZE = MAX_SIZE;
	}

	void insert(int k) {
		if (SIZE > 0) {
			assert(k < discs[SIZE - 1]); // disc being inserted is smaller than last disc
		}
		discs[SIZE++] = k;
	}

	int pop() {
		assert(SIZE > 0);
		return discs[SIZE-- - 1]; // return last disc, and decrement size
	}


	void print() {
		std::cout << "POLE: ";
		for (int i = 0; i < SIZE; ++i) {
			std::cout << discs[i] << ", ";
		}
		std::cout << "\n";
	}

};