#include <iostream>
#include "Array.h"
#include "Vector.h"

using namespace std;

int main() {
    Array a(5);
    for (int i = 0; i < a.get_size(); ++i) {
        a[i] = i;
    }
    Array b(a);
    for (int i = 0; i < b.get_size(); ++i) {
         cout << b[i] << ' ';
    }
    Array c(a);
    a = b + c;
    cout << a << endl;
    Vector d(3);
    cin >> d;
    d.pushback(6);
    cout << d << endl;
    d.pop_back();
    cout << d << endl;

    try {
        d.insert(2, 10);
        cout << d;
    }
    catch (const exception& e) {
       cerr<< e.what();
    }


    return 0;
}
