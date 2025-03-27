#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
int a[200010];
 
int n, x, y;
 
void testcase() {
    cin >> n >> x >> y;
    x--; y--;
 
 
 
    if(n % 2 == 0) {
        for(int i = 0; i < n; i++) {
            a[i] = i % 2;
        }
        if(a[x] == a[y]) a[x] = 2;
        for(int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        return;
    }
    else {
        a[0] = 2;
        for(int i = 1; i < n; i++) {
            a[i] = (i-1) % 2;
        }
        int pointer = n;
        pointer -= x;
        for(int i = 0; i < n; i++, pointer++) {
            cout << a[pointer % n] << " ";
        } 
        cout << endl;
        return;
    }
}
 
int main() {
    int t;
    cin >> t;
 
    while(t--) testcase();
    
    return 0;
}