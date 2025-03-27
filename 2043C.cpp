#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
#define c 1000000007ll
 
ll n, m, k, q, l, r, x, y, z, ma, mb;
ll a[200010];
 
void testcase() {
    ll n;
    cin >> n;
 
    ll di = -1;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] != 1 && a[i] != -1) di = i;
    }
 
    if(di == -1) {
        ll maxSum1 = 0;
        ll minSum1 = 0;
        ll currentSumMax = 0;
        ll currentSumMin = 0;
        for(int i = 0; i < n; i++) {
            currentSumMax += a[i];
            currentSumMin += a[i];
            if(currentSumMax < 0) currentSumMax = 0;
            if(currentSumMin > 0) currentSumMin = 0;
 
            maxSum1 = max(maxSum1, currentSumMax);
            minSum1 = min(minSum1, currentSumMin);
        }
 
        cout << maxSum1 - minSum1 + 1 << endl;
        for(int i = minSum1; i <= maxSum1; i++) cout << i << " ";
        cout << endl;
        return;
    }
 
    ll maxSum1 = 0;
    ll minSum1 = 0;
    ll currentSumMax = 0;
    ll currentSumMin = 0;
    for(int i = 0; i < di; i++) {
        currentSumMax += a[i];
        currentSumMin += a[i];
        if(currentSumMax < 0) currentSumMax = 0;
        if(currentSumMin > 0) currentSumMin = 0;
 
        maxSum1 = max(maxSum1, currentSumMax);
        minSum1 = min(minSum1, currentSumMin);
    }
 
    ll maxSum2 = 0;
    ll minSum2 = 0;
    currentSumMax = 0;
    currentSumMin = 0;
    for(int i = di + 1; i < n; i++) {
        currentSumMax += a[i];
        currentSumMin += a[i];
        if(currentSumMax < 0) currentSumMax = 0;
        if(currentSumMin > 0) currentSumMin = 0;
 
        maxSum2 = max(maxSum2, currentSumMax);
        minSum2 = min(minSum2, currentSumMin);
    }
 
    ll maxSumTouching1 = 0;
    ll minSumTouching1 = 0;
    ll currentSum = 0;
    for(int i = di - 1; i >= 0; i--) {
        currentSum += a[i];
        maxSumTouching1 = max(maxSumTouching1, currentSum);
        minSumTouching1 = min(minSumTouching1, currentSum);
    }
 
    ll maxSumTouching2 = 0;
    ll minSumTouching2 = 0;
    currentSum = 0;
    for(int i = di + 1; i < n; i++) {
        currentSum += a[i];
        maxSumTouching2 = max(maxSumTouching2, currentSum);
        minSumTouching2 = min(minSumTouching2, currentSum);
    }
 
    set<ll> present;
 
    for(int i = minSum1; i <= maxSum1; i++) present.insert(i);
    for(int i = minSum2; i <= maxSum2; i++) present.insert(i);
    for(int i = minSumTouching1 + minSumTouching2; i <= maxSumTouching1 + maxSumTouching2; i++) present.insert(i + a[di]);
 
    cout << present.size() << endl;
    for(auto x : present) {
        cout << x << " ";
    }
    cout << endl;
}
 
int main() {
    int t;
    cin >> t;
 
    while(t--) testcase();
 
    return 0;
}