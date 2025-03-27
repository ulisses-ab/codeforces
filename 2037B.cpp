#include <bits/stdc++.h>
 
using namespace std;
using lli = unsigned long long int;
 
unordered_set<int> possible;
 
void solve() {
    int k;
    cin >> k;
 
    possible.clear();
 
    for(int i = 0; i < k; i++) {
        int ki;
        cin >> ki;
 
        possible.insert(ki); 
    }
 
    int s = k - 2;
 
    for(int i = 1; i * i <= s; i++) {
        if(s % i == 0 && possible.count(i) != 0 && possible.count(s / i) != 0) {
            cout << i << " " << s/i << endl;
            break;
        } 
    }
}
 
int main() {
    int t;
    cin >> t;
 
    while(t--) {
        solve();
    }
    return 0;
}