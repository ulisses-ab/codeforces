#include <bits/stdc++.h>
 
using namespace std;
 
int n;
int matrix[60][60];
 
 
int main()
{
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    
    if(matrix[0][0] < matrix[0][1]) {
        if(matrix[0][0] < matrix[1][0]) {
            cout << 0 << endl;
        }
        else {
            cout << 3 << endl;
        }
    }
    else {
        if(matrix[0][0] < matrix[1][0]) {
            cout << 1 << endl;
        }
        else {
            cout << 2 << endl;
        }
    }
    
 
    return 0;
}