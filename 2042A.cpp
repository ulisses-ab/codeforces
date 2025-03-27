#include <bits/stdc++.h>
 
using namespace std;
using lli = unsigned long long int;
 
int a[10000];
int t;
 
int main() {
    cin >> t;
    a[0] = 0;
 
    while(t--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> vin;
        a[n + 1] = k + 1;
        
        for(int i = 1; i <= n; i++) {
            int ai;
            cin >> ai;
            vin.push_back(ai);
        }
        
        sort(vin.begin(), vin.end());
        
        for(int i = n - 1, j = 1; i >= 0; i--, j++) {
            a[j] = vin[i];
            a[j] += a[j - 1];
        }
 
        for(int i = 1; i <= n + 1; i++) {
            if(a[i] > k) {
                cout << k - a[i - 1] << endl;
                break;
            }
        }
    }
}