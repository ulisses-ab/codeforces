#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
int a[200010], b[200010];
 
void testcase() {
    int n;
    cin >> n;
 
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
 
    bool found = false;
    int minMargin = 1500000000, needed = 0;
 
    for(int i = 0; i < n; i++) {
        if(a[i] - b[i] < 0) {
            if(!found) {
                needed = b[i] - a[i];
                found = true;
            }
            else {
                cout << "NO" << endl;
                return;
            }
        }
        else {
            minMargin = min(minMargin, a[i] - b[i]);
        }
    }
 
    if(needed <= minMargin) cout << "YES" << endl;
    else cout << "NO" << endl;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); std::cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) testcase();
}
