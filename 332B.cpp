#include <bits/stdc++.h>
 
using namespace std;
using lli = long long int;
 
int n, k;
lli a[200010];
pair<int, lli> bestInterval[200010];
 
lli sum(int l, int r) {
    if(l == 0) return a[r];
    return a[r] - a[l - 1];
}
 
int main() {
    cin >> n >> k;
 
    cin >> a[0];
    for(int i = 1; i < n; i++) {
        cin >> a[i];
        a[i] += a[i-1];
    }
 
    bestInterval[n - k] = {n - k, sum(n - k, n - 1)};
    for(int i = n - k - 1; i >= 0; i--) {
        if(sum(i, i + k - 1) >= bestInterval[i + 1].second) {
            bestInterval[i] = {i, sum(i, i + k - 1)};
        }
        else {
            bestInterval[i] = bestInterval[i + 1];
        }
    }
 
    lli bestTotal = 0, bestA, bestB;
    for(int i = 0; i <= n - (2 * k); i++) {
        if(sum(i, i + k - 1) + bestInterval[i + k].second > bestTotal) {
            bestTotal = sum(i, i + k - 1) + bestInterval[i + k].second;
            bestA = i;
            bestB = bestInterval[i + k].first;
        } 
    }
 
    cout << bestA + 1 << " " << bestB + 1 << endl;
}