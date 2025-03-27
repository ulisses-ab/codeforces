#include <bits/stdc++.h>
 
using ll = long long;
using namespace std;
 
int n;
vector<pair<int, int>> a, dp;
 
bool cmp(pair<int, int> x, pair<int, int> y) {
    return x.second - x.first < y.second - y.first; 
}
 
void testcase() {
    cin >> n;
    
    a.resize(n);
    dp.resize(n, make_pair(-1, -1));
    
    for(int i = 0; i < n; i++) cin >> a[i].first;
    for(int i = 0; i < n; i++) cin >> a[i].second;
    
    int mx = -2000000000;
    for(int i = 0; i < n; i++) {
        if(min(a[i].first,a[i].second) > mx) {
            mx = min(a[i].first,a[i].second);
        }
    }
    
    int total = mx;
    for(int i = 0; i < n; i++) {
        total += max(a[i].first, a[i].second);
    }
    
    cout << total << endl;
}
 
int main() {
    int t;
    cin >> t;
    
    while(t--) testcase();
    return 0;
}