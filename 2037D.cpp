#include <bits/stdc++.h>
 
using namespace std;
using lli = unsigned long long int;
 
void solve() {
    int n, m, l;
    cin >> n >> m >> l;
 
    vector<pair<int, int>> hurdles(n);
    for(int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
 
        hurdles[i] = make_pair(l - 1, r - l + 1);
    }
 
    vector<pair<int, int>> pups(m);
    for(int i = 0; i < m; i++) {
        int xi, vi;
        cin >> xi >> vi;
        xi--;
 
        pups[i] = make_pair(xi, vi);
    }
 
    int current_hurdle = 0;
    int current_power = 1;
    int counter = 0;
    int pi = 0;
    priority_queue<int> powerups;
    while(current_hurdle < n) {
        while(pups[pi].first < hurdles[current_hurdle].first) {
            if(pi >= m) break;
            powerups.push(pups[pi].second);
            pi++;
        }
 
        while(current_power <= hurdles[current_hurdle].second) {
            if(powerups.empty()) {
                cout << -1 << endl;
                return;
            }
 
            current_power += powerups.top();
            powerups.pop();
            counter++;
        }
 
        current_hurdle++;
    }
 
    cout << counter << endl;
}
 
int main() {
    int t;
    cin >> t;
 
    while(t--) {
        solve();
    }
    return 0;
}
