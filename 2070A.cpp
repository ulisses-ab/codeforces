#include <bits/stdc++.h>
 
using namespace std;
 
void testcase() {                 
    int n;
    cin >> n;
    
    cout << (((n + 1) / 15) * 3) + min(((n + 1) % 15), 3) << endl;
}
 
int main()
{
    int t;
    cin >> t;
    while(t--) testcase();
 
    return 0;
}
