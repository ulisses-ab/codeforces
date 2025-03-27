#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
int a[200010];
 
vector<ll> diff(vector<ll> v) {
    vector<ll> output(v.size() - 1);
 
    for(int i = 0; i < v.size() - 1; i++) {
        output[i] = v[i + 1] - v[i];
    }
 
    return output;
}
 
ll sum(vector<ll> v) {
    ll sum = 0;
 
    for(auto x : v) {
        sum += x;
    }
 
    return sum;
}
 
ll solve2(vector<ll> v) {
    if(v.size() == 1) return v[0];
 
    return max(abs(sum(v)), abs(solve2(diff(v))));
}
 
 
ll solve(vector<ll> v) {
    if(v.size() == 1) return v[0];
 
    return max(sum(v), abs(solve2(diff(v))));
}
 
 
 
void testcase() {
    int n;
    cin >> n;
 
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    cout << solve(a) << endl;
}
 
int main() {
    int t;
    cin >> t;
    
    while(t--) testcase();
    return 0;
}