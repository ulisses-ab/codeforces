#include <bits/stdc++.h>
 
using namespace std;
 
int h[60];
 
int main() {
    int t;
    cin >> t;
 
    while(t--) {
        int n;
        cin >> n;
 
        for(int i = 0; i < n; i++) cin >> h[i];
 
        int seqLen = 1;
        int maxSeq = 0;
        for(int i = 1; i < n; i++) {
            if(h[i] == h[i - 1]) {
                seqLen++;
            }
            else {
                maxSeq = max(maxSeq, seqLen);
                seqLen = 1;
            }
        }
        maxSeq = max(maxSeq, seqLen);
 
        cout << n - maxSeq << endl;
    }
 
    return 0;
}