
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        if(n % 2 == 0) {
            for(int i = 1; i <= n / 2; i++) {
                cout << i << " " << i << " ";
            }
            cout << endl;
        }
        else if(n >= 27) {
            cout << "1 2 2 3 3 4 4 5 5 1 6 7 7 8 8 9 9 10 10 11 11 12 12 13 13 1 6 ";
            int c = 14;
            for(int i = 0; i < (n - 27) / 2; i++) {
                cout << c << " " << c << " ";
                c++;
            }
            cout << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
}