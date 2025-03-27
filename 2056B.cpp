#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
int connectionsWithBigger[1010], connectionsWithSmaller[1010], output[1010];
 
void testcase() {
    int n;
    cin >> n;
 
    for(int i = 1; i <= n; i++) {
        connectionsWithBigger[i] = 0;
        connectionsWithSmaller[i] = 0;
        for(int j = 1; j <= n; j++) {
            char c;
            cin >> c;
 
            if(c == '0') continue;
 
            if(j > i) connectionsWithBigger[i]++;
            else connectionsWithSmaller[i]++;
        }
    }
 
    for(int i = 1; i <= n; i++) {
        int pos = n - i - connectionsWithBigger[i] + connectionsWithSmaller[i];
        output[pos] = i;
    }
 
    for(int i = 0; i < n; i++) cout << output[i] << " ";
    cout << endl;
   
   
}
 
int main() {
    int t;
    cin >> t;
    
    while(t--) testcase();
    return 0;
}