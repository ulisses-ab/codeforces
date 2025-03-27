#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
char a[200010];
int zeros[200010];
int ones[200010];
int t;
 
int main() {
    cin >> t;
 
    while(t--) {
        int n, k;
        cin >> n >> k;
 
        zeros[n] = 0;
        ones[n] = 0;
        for(int i = 0; i < n; i++) {
            zeros[i] = 0;
            ones[i] = 0;
            cin >> a[i];
        }
 
        for(int i = n - 1; i >= 0; i--) {
            if(a[i] == '0') zeros[i]++;
            else ones[i]++;
            zeros[i] += zeros[i+1];
            ones[i] += ones[i+1];
        }
 
        priority_queue<int> pq;
        pq = priority_queue<int>();
 
        for(int i = 1; i < n; i++) {
            pq.push(ones[i] - zeros[i]);
        }
 
        int m = 1;
        ll total = 0;
        while(!pq.empty()) {
            total+=pq.top();
            pq.pop();
            m++;
            if(total >= k) {
                cout << m << endl;
                goto wend;
            }
        }
 
        cout << -1 << endl;
 
        wend:
        m++;
    }
}