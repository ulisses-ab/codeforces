#include <iostream>
 
using ll = long long;
using namespace std;
 
int n;
int a[5010][2];
int dp[5010][2];
 
bool cmp(int* x, int* y) {
    return x[1] - x[0] < y[1] - y[0]; 
}
 
void testcase() {
    cin >> n;
    int k = 1;
    int curr = 1;
    
    int total = 0;
    int h = 0;
    for(int i = 0; i < n; i++) {
        int ai;
        cin >> ai;
        total += ai;
        
        while(total > curr) {
            k++;
            curr += 8 * k - 8;
        }
        if(total == curr) h++;
    }
    
    cout << h << endl;
    
    
}
 
int main() {
    int t;
    cin >> t;
    
    while(t--) testcase();
    return 0;
}