#include <iostream> // cin, cout, ios_base

#include "Collatz.h"

// ----
// main
// ----
int main () {
    using namespace std;
    ios_base::sync_with_stdio(false); // turn off synchronization with C I/O
    collatz_solve(cin, cout);
    return 0;}
	
