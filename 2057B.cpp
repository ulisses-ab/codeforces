#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
void testcase() {
    ll n, k;
    cin >> n >> k;
    
    map<ll, ll> ma;
    for(ll i = 0; i < n; i++) {
        ll ai;
        cin >> ai;
        ma[ai] ++;
    }
    
    vector<pair<ll, ll>> v;
    
    for(auto x : ma) {
        v.push_back(make_pair(x.second, x.first));
    }
    
    sort(v.begin(), v.end());
    ll total = v.size();
    
    for(ll i = 0; i < v.size(); i++) {
        if(k >= v[i].first) {
            total--;
            k-=v[i].first;
        }
        else {
            break;
        }
    }
    
    cout << max(total, 1ll) << endl;
    
} 
 
int main()
{
    ll t;
    cin >> t;
    while(t--) testcase();
 
    return 0;
}