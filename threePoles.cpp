/*
* Given three poles, where the first pole has N discs stacked on top of each other in order of size, with the smallest on top
* Transfer all the discs to the third pole, under the following rules: 
* 1) Only one disc can be moved at a time
* 2) A disc may only be placed on top of a larger disc
* 
* This program provides an iterative solution to this problem.
*/

#include "threePoles.h"

using namespace std;

// move discs (2,1) from p_start to p_end
void build_21(Pole& p_start, Pole& p_temp, Pole& p_end) {
	int disc1 = p_start.pop();
	assert(disc1 == 1);
	p_temp.insert(disc1);
	
	int disc2 = p_start.pop();
	assert(disc2 == 2);
	p_end.insert(disc2);

	disc1 = p_temp.pop();
	p_end.insert(disc1);
}

// move a tower (k->1) from p_start to p_end
void build(Pole& p_start, Pole& p_temp, Pole& p_end, int k) {
	if (k == 2) {
		build_21(p_start, p_temp, p_end);
		return;
	}
	
	build(p_start, p_end, p_temp, k - 1); // build a (k-1 -> 1) tower in the intermediate pole

	int disc_k = p_start.pop();
	assert(disc_k == k);
	p_end.insert(disc_k);

	build(p_temp, p_start, p_end, k - 1); // build a (k-1 -> 1) tower in the end pile
}


int main()
{
	size_t STACK_SIZE = 10;

	Pole p1(STACK_SIZE);
	Pole p2(STACK_SIZE);
	Pole p3(STACK_SIZE);
	p1.fill();

	p1.print();
	p2.print();
	p3.print();
	
	build(p1, p2, p3, STACK_SIZE);

	p1.print();
	p2.print();
	p3.print();

	return 0;
}
