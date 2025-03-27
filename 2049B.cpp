#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
int a[510];
 
void testcase() {
    int n;
    cin >> n;
 
    string a;
    cin >> a;
 
    int pcount = 0, scount = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == 's') scount++;
        if(a[i] == 'p') pcount++;
    }
 
    if(scount > 1 && pcount > 1) {
        cout << "NO" << endl;
        return;
    }
 
    if(pcount == 0 || scount == 0) {
        cout << "YES" << endl;
        return;
    }
 
    if(pcount == 1 && a[n-1] == 'p') {
        cout << "YES" << endl;
        return;
    }
    if(scount == 1 && a[0] == 's') {
        cout << "YES" << endl;
        return;
    }
 
    if(pcount == 1 && a[n-1] != 'p') {
        cout << "NO" << endl;
        return;
    }
    if(scount == 1 && a[0] != 's') {
        cout << "NO" << endl;
        return;
    }
 
    cout << "YES" << endl;
 
}
 
int main() {
    int t;
    cin >> t;
 
    while(t--) testcase();
    
    return 0;
}