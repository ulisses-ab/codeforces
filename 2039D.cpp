#include <bits/stdc++.h>
 
using namespace std;
using lli = unsigned long long int;
 
vector<int> divisors(int x) {
    vector<int> ans;
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) {
            ans.push_back(i);
            if(x / i != i) ans.push_back(x / i);
        } 
    }
    return ans;
}
 
int main() {
    int t;
    cin >> t;
 
    while(t--) {
        int n, m;
        cin >> n >> m;
 
        vector<int> s;
        vector<int> ans;
        s.resize(m);
        ans.resize(n);
        for(int i = 0; i < m; i++) cin >> s[i]; 
 
        ans[0] = s[s.size() - 1];
        bool ok = true;
        for(int i = 2; i <= n; i++) {
            unordered_set<int> prohibited;
            for(auto x : divisors(i)) {
                prohibited.insert(ans[x - 1]);
            }
 
            bool found = false;
            for(int j = s.size() - 2; j >= 0; j--) {
                if(prohibited.count(s[j]) != 0) continue;
 
                ans[i - 1] = s[j];
                found = true;
                break;
            }
            if(!found) {
                ok = false;
                break;
            }
        }
 
        if(ok) {
            for(auto x : ans) {
                cout << x << " ";
            }
            cout << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
    return 0;
}