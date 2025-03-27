#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
ll n, k;
 
pair<ll, ll> lucky(ll n) {
    if(n < k) return {0, 0};
 
    if(n % 2 == 0) {
        pair<ll, ll> subLucky = lucky(n / 2);
        return {subLucky.first + (subLucky.first + (subLucky.second * (n / 2))), subLucky.second * 2};
    }
    else {
        pair<ll, ll> subLucky = lucky(n / 2);
        ll toAdd = (n + 1) / 2;
        return {subLucky.first + (subLucky.first + (subLucky.second * toAdd)) + toAdd, subLucky.second * 2 + 1};
    }
}
 
void testcase() {
    cin >> n >> k;
 
    cout << lucky(n).first << endl;
}
 
int main() {
    int t;
    cin >> t;
    while(t--) testcase();
}