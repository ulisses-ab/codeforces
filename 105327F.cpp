#include <bits/stdc++.h>
 
using namespace std;
using lli = unsigned long long int;
 
int n;
int a[50], b[50];
 
int main() {
    a[0] = 1;
    b[0] = 1;
 
    cin >> n;
 
    for(int i = 1; i <= n; i++) {
        a[i] = b[i - 1];
        b[i] = b[i - 1] + a[i - 1];
 
        for(int j = 2; j * j <= a[i] && j * j <= b[i]; j++) {
            while(a[i] % j == 0 && b[i] % j == 0) {
                a[i] /= j;
                b[i] /= j;
            } 
        }
        
        if(b[i] % a[i] == 0) {
            b[i] /= a[i];
            a[i] = 1;
        }
        
        if(a[i] % b[i] == 0) {
            a[i] /= b[i];
            b[i] = 1;
        }
    }
 
 
    cout << a[n] << endl;
 
    return 0;
}