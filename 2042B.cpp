#include <bits/stdc++.h>
 
using namespace std;
using lli = unsigned long long int;
 
int a[10000];
int t;
 
int main() {
    cin >> t;
 
    while(t--) {
        int n;
        cin >> n;
 
        int total = 0;
 
        for(int i = 1; i <= n; i++) {
            a[i] = 0;
        }
 
        for(int i = 0; i < n; i++) {
            int ci;
            cin >> ci;
            a[ci]++;
        }
 
        int ones = 0;
        int others = 0;
 
        for(int i = 1; i <= n; i++) {
            if(a[i] == 1) ones++;
            else if(a[i] > 0) others++; 
        }
 
        total += 2 * ((ones + 1) / 2);
        total += others;
 
        cout << total << endl;
    }
}