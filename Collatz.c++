// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2013
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <vector>

#include "Collatz.h"

// ------------
// collatz_read
// ------------

bool collatz_read (std::istream& r, int& i, int& j) {
    r >> i;
    if (!r)
        return false;
    r >> j;
    assert(i > 0);
    assert(j > 0);
    return true;}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {

    assert(i > 0);
    assert(j > 0);
    // <your code>
	//int temp = 1;
	int max = 1;
	int k = 0;
	if (i > j){
		k = i;
		i = j;
		j = k;
	}
	std::vector<int> length_list (j,0);
	for (int a = 0; a < j; a++){
		length_list.at(a) = 0;
	}

	int count = 1;
/*	for (i; i < j+1; i++){
		int c = 1;
		int n = i;
		while (n > 1){
			if (n % 2 == 0)
				n = (n/2);
			else
				n = 3*n + 1;
			c++;
		}
		if (c > max)
			max = c;
	}
*/
	for (int k = i ; k < j+1; k++){
		int origin = k;
		int i = k;
		while (i > 1){
			//std::cout << origin << " " << i << std::endl;
			if (i < j){
				if (length_list.at(i-1) > 0) {
					count += length_list.at(i-1);
					length_list.at(origin-1) = count-1;
					break;
				}
			}
			if ((i % 2) == 0){
				i = (i / 2);
			}
			else{
				i = (3*i) + 1;
			}
			count += 1;
			
		}
		if (i == 1)
			length_list.at(origin-1) = count;
		count = 1;
		//std::cout << (i-1) << " " << length_list.at(i-1) << std::endl;

	}
	for (int l = 1; l <length_list.size() ; l++){
		if (length_list.at(l) > max)
			max = length_list.at(l);
	}
	
	// <your code>
    int v = max;
    assert(v > 0);
    return v;}
	
// --------------------
// collatz_cycle_length
// --------------------

int collatz_cycle_length(int n){
	assert(n > 0);
	int c = 1;
	while (n > 1){
		if (n % 2 == 0)
			n = (n/2);
		else
			n = 3*n + 1;
		c++;
	}
	assert (c > 0);
	return c;
}

// -------------
// collatz_print
// -------------

void collatz_print (std::ostream& w, int i, int j, int v) {
    assert(i > 0);
    assert(j > 0);
    assert(v > 0);
    w << i << " " << j << " " << v << std::endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (std::istream& r, std::ostream& w) {
    int i;
    int j;
    while (collatz_read(r, i, j)) {
        const int v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}