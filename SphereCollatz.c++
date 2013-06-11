#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
	
	
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
	int temp = 1;
	int max = 1;
	for (i; i < j+1; i++){
		temp = collatz_cycle_length(i);
		if (temp > max)
			max = temp;
	}
	// <your code>
    int v = max;
    assert(v > 0);
    return v;}
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
		

// ----
// main
// ----
int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
    collatz_solve(cin, cout);
    return 0;}