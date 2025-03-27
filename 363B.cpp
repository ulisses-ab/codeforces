#include <bits/stdc++.h>
 
using namespace std;
using lli = long long int;
 
int f[200010];
 
int main() {
    int n, k;
    cin >> n >> k;
 
    for(int i = 0; i < n; i++) {
        cin >> f[i];
    }
 
    int sum = 0;
    int s = 0, e = 0;
    while(e < k) {
        sum += f[e];
        e++;
    }
 
    int minSum = sum;
    int minS = 0;
 
    for(; e < n; e++, s++) {
        sum -= f[s];
        sum += f[e];
        //cout << sum << " ";
 
        if(sum < minSum) {
            minSum = sum;
            minS = s + 1;
        }
    }
 
    cout << minS + 1 << endl;
}