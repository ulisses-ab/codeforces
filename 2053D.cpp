#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
const ll c = 998244353;
 
ll n, k;
 
ll a[200010];
ll b[200010]; 
ll tree[800040];
vector<ll> va, vb; 
 
ll build(ll p, ll l, ll r) {
    if(l == r) return tree[p] = min(va[l], vb[l]);
    
    ll m = (l + r) / 2;
    
    ll p1 = build((2 * p) + 1, l, m);
    ll p2 = build((2 * p) + 2, m + 1, r);
 
    return tree[p] = (p1 * p2) % c;
}
 
ll update(ll p, ll l, ll r, ll o, ll x) {
    if(x < l || r < x) return tree[p];
    if(l == r) {
        if(o == 1) 
            va[l]++;
        else 
            vb[l]++;
        return tree[p] = min(va[l], vb[l]);
    }
    
    ll m = (l + r) / 2;
    
    ll p1 = update((2 * p) + 1, l, m, o, x);
    ll p2 = update((2 * p) + 2, m + 1, r, o, x);
    
    return tree[p] = (p1 * p2) % c;
}
 
void testcase() {
    int n, q;
    cin >> n >> q;
 
    va.clear(); vb.clear();
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        va.push_back(a[i]);
    } 
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        vb.push_back(b[i]);
    }
 
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
 
    cout << build(0, 0, n - 1) << " ";
    while(q--) {
        int o, x;
        cin >> o >> x;
        x--;
 
        int val, pos;
 
        if(o == 1) {
            val = a[x];
            a[x]++;
            pos = distance(va.begin(), upper_bound(va.begin(), va.end(), val)) - 1;
        }
        else {
            val = b[x];
            b[x]++;
            pos = distance(vb.begin(), upper_bound(vb.begin(), vb.end(), val)) - 1;
        }
 
        cout << update(0, 0, n - 1, o, pos) << " ";
    }
    cout << endl;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); std::cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) testcase();
}
