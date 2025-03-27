#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
int main() {
    int a, b, c;
    cin >> a >> b >> c;
 
    if(a != b && a != c) {
        cout << "A" << endl;
        exit(0);
    }
 
    if(b != a && b != c) {
        cout << "B" << endl;
        exit(0);
    }
 
    if(c != a && c != b) {
        cout << "C" << endl;
        exit(0);
    }
 
    cout << "*" << endl;
    return 0;
}