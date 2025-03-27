#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
int main() {
    int n, r;
    cin >> n >> r;
 
    set<int> returned;
    for(int i = 0; i < r; i++) {
        int ri;
        cin >> ri;
        returned.insert(ri);
    }
 
    if(returned.size() == n) {
        cout << "*" << endl;
        exit(0);
    }
 
    for(int i = 1; i <= n; i++) {
        if(returned.count(i) == 0) cout << i << " ";
    }
}