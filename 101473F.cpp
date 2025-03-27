#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
int main() {
    int n;
    cin >> n;
    vector<int> points;
    set<int> pointSet;
 
    int current = 0;
    for(int i = 0; i < n; i++) {
        points.push_back(current);
        pointSet.insert(current);
 
        int xi;
        cin >> xi;
        current += xi;
    }
 
    if(current % 3 != 0) {
        cout << "0" << endl;
        exit(0);
    }
 
    int triangles = 0;
    for(int i = 0; i < n; i++) {
        if(pointSet.count(points[i] + (current / 3)) != 0 && pointSet.count(points[i] + 2 * (current / 3)) != 0) triangles++;
    }
 
    cout << triangles << endl;
}