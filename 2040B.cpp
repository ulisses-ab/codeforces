#include <bits/stdc++.h>
 
using namespace std;
 
int a[110];
 
void testcase() {
    int n;
    cin >> n;
 
    if(n == 1) {
        cout << 1 << endl;
        return;
    }
    if(n <= 4) {
        cout << 2 << endl;
        return;
    }
 
    int totalOnes = 4;
    int operations = 2;
 
    while(totalOnes < n) {
        totalOnes++;
        totalOnes *= 2;
        operations++;
    }
 
    cout << operations << endl;
}
 
 
int main() {
    int t;
    cin >> t;
 
    while(t--) testcase();
    
    return 0;
}