#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
int n, k;
int a[300010];
string s;
 
bool isPossible(int t) {
    bool onSeg = false;
    int segCount = 0;
    
    for(int i = 0; i < n; i++) {
        if(a[i] <= t) continue;
        
        if(s[i] == 'B') {
            if(!onSeg) {
                onSeg = true;
                segCount++;
            }
        }
        else {
            if(onSeg) {
                onSeg = false;
            }
        }
    }
    
    return segCount <= k;
}
 
void testcase() {
    cin >> n >> k >> s;
    
    int maxPenalty = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        maxPenalty = max(maxPenalty, a[i]);
    }
    
    int l = 0, h = maxPenalty;
    
    while(l <= h) {
        int m = (l + h) / 2;
        
        if(isPossible(m)) {
            h = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    
   cout << l << endl;
}
 
int main()
{
    int t;
    cin >> t;
    while(t--) testcase();
 
    return 0;
}