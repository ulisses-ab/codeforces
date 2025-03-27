#include <bits/stdc++.h>
 
using namespace std;
using lli = unsigned long long int;
 
int n;
int a[100010];
int ones[40];
 
int main() {
    cin >> n;
 
    for(auto &x : ones) x = 0;
    for(int i = 0; i < n; i++) {
        int ai;
        cin >> ai;
        for(int j = 0; j < 31; j++) {
            ones[j] += ai & 1;
            ai >>= 1;
        }
    }
 
    for(int i = 0; i < n; i++) {
        int xi = 0;
 
        for(int j = 30; j >= 0; j--) {
            xi <<= 1;
            if(ones[j] > 0) {
                ones[j]--;
                xi++;
            }
        }
 
        cout << xi << " ";
    }
    
 
 
    return 0;
}