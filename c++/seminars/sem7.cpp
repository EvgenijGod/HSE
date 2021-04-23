********************************************************************

		СЕМИНАР 7 (28.02.2019)

*********************************************************************

rvalue, lvalue

#include <iostream>
#include <vector>

using namespace std;

int foo(int a) {
    return a;
}

int bar() {
    int x = 10;
    return x;
}

int main() {
    int a = 1;
    int*p=&a;

    int*func_p = &foo(a); // foo - lvalue
    int j = bar();        // bar - rvalue
    //int* bad_p = &bar();  // bar - rvalue, bad code
}

***********************************************************************

bit-operations

#include <iostream>
#include <bitset>

using namespace std;

unsigned int check_bit (unsigned int x, unsigned int pos) {
    return (x >> pos) & 1;
}

unsigned int set_bit (unsigned int x, unsigned int pos) {
    return x | (1 << pos);
}

unsigned int unset_bit (unsigned int x, unsigned int pos) {
    return x & (~(1 << pos));
}

int main() {
    unsigned int b = (10 << 1); // moves bits one position left (multiplying by 2)
    bitset<32> bs(b);      // saves bits of b
    cout << bs << "\n";

    unsigned int a = 1;
    bitset<32> abs(~a); // ~ inverts bits
    cout << abs << "\n";

    cout << check_bit(a, 0) << " " << check_bit(a, 1) << "\n";
}
