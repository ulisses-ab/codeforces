#include <bits/stdc++.h>
using namespace std;
 
void mergesort(vector<int>& v, int l, int r) {
    if(l == r) return;
    
    int m = (l + r) / 2;
    
    mergesort(v, l, m);
    mergesort(v, m + 1, r);
    
    vector<int> v1, v2;
    v1.clear(); v2.clear();
    for(int i = l; i <= m; i++) v1.push_back(v[i]);
    for(int i = m + 1; i <= r; i++) v2.push_back(v[i]);
    
    int p1 = 0, p2 = 0, p = l;
    while(p1 < v1.size() && p2 < v2.size()) {
 
 
        if(signed(v2[p2]) - signed(v1.size() - p1) > v1[p1]) {
            v[p] = v2[p2] - (v1.size() - p1);
            p++;
            p2++;
        }
        else {
            v[p] = v1[p1];
            p++; 
            p1++;
        }
 
    }
    
    while(p1 < v1.size()) {
        v[p] = v1[p1];
        p++;
        p1++;
    }
    
    while(p2 < v2.size()) {
        v[p] = v2[p2];
        p++;
        p2++;
    }
}
 
void solve() {
    string s;
    cin >> s;
    
    vector<int> v;
    v.resize(s.size());
 
    for(int i = 0; i < s.size(); i++) v[i] = s[i] - '0';
    
    mergesort(v, 0, s.size() - 1);
    
    for(int i = 0; i < s.size(); i++) {
        cout << v[i];
    }
    
    cout << endl;
}
 
int main() {
    int t;
    cin >> t;
    
    while(t--) solve();
 
    return 0;
}