
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
int l, c, total;
int grid[310][310];
 
void swapLines(int l1, int l2) {
    for(int i = 0; i < c; i++) {
        swap(grid[l1][i], grid[l2][i]);
    }
}
 
void swapColumns(int c1, int c2) {
    for(int i = 0; i < l; i++) {
        swap(grid[i][c1], grid[i][c2]);
    }
}
 
void sortLines() {
    for(int i = 0; i < l; i++) {
        int smallest = grid[i][0];
        int smallestIndex = i;
        for(int j = i + 1; j < l; j++) {
            if(grid[j][0] < smallest) {
                smallest = grid[j][0];
                smallestIndex = j;
            }
        }
 
        if(smallestIndex != i) total++;
        swapLines(i, smallestIndex);
    }
}
 
void sortColumns() {
    for(int i = 0; i < c; i++) {
        int smallest = grid[0][i];
        int smallestIndex = i;
        for(int j = i + 1; j < c; j++) {
            if(grid[0][j] < smallest) {
                smallest = grid[0][j];
                smallestIndex = j;
            }
        }
 
        if(smallestIndex != i) total++;
        swapColumns(i, smallestIndex);
    }
}
 
int main() {
    cin >> l >> c;
    total = 0;
 
    for(int i = 0; i < l; i++) {
        for(int j = 0; j < c; j++) {
            cin >> grid[i][j];
        }
    }
 
    sortLines();
    sortColumns();
 
    int p = 1;
    for(int i = 0; i < l; i++) {
        for(int j = 0; j < c; j++) {
            if(grid[i][j] != p) {
                cout << "*" << endl;
                exit(0);
            }
            p++;
        }
    }
 
    cout << total << endl;
}