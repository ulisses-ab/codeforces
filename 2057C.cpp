#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
void testcase() {
    unsigned int l, r;
    cin >> l >> r;
    unsigned int a = 0, b = 0, c = 0;
    
    int i;
    for(i = 31; i >= 0; i--) {
        if(((l >> i) & 1) == ((r >> i) & 1)) {
            a += l & (1 << i);
            b += l & (1 << i);
            c += l & (1 << i);
            continue;
        }
 
        a += 1 << i;
        break;
    }
    i--;
    
    for(; i >= 0; i--) {
        b += 1 << i;
    }
    
    if(a != r) {
        c = r;
    }
    else {
        c = l;
    }
    
    cout << a << " " << b << " " << c << endl;
}
 
int main()
{
    ll t;
    cin >> t;
    while(t--) testcase();
 
    return 0;
}