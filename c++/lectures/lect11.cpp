********************************************************************************************

					LECTURE 11

********************************************************************************************

#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main() {
    int a[10];
    int* ptr2 = a;
    for (size_t i = 0; i != 10; ++i)
        a[i] = (i + 1) * (i + 1); // ptr2[i] = value; *(ptr2 + i) = value; i[ptr2] = value;
    int* first = a;
    cout << *first << "\n";

    for (int* ptr = a; ptr != a + 10; ++ptr)
        cout << *ptr << " ";
    cout << "\n";

    list<int> l;
    for (size_t i = 0; i != 10; ++i)
        l.push_back((i + 1) * (i + 1));
    for (auto it = l.begin(); it != l.end(); ++it)
        cout << *it << " ";
    cout << "\n";                                   // итераторы основаны на указателях
}

********************************************************************************************

#include <algorithm>
#include <iostream>
#include <list>
//#include <string>
#include <string.h>
#include <vector>

using namespace std;

char * my_str_cpy (char * dst, const char * src) {
    while(*dst++ = *src++);
    return dst;
}

int main() {
    //string s1 = "hello";
    //string s2;
    //s2 = s1;

    char s1[100] = "hello";
    char s2[100] = "";

    //s2 = s1; // won't work
    my_str_cpy(s2, s1);
    char s3[100] = "";
    copy(s1, s1 + strlen(s1) + 1, s3);
    cout << s2 << "\n";
    cout << s3 << "\n";
}

********************************************************************************************
