#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
int n, m;
vector<int> input, output;
 
vector<int> foldWithBiggerStart(vector<int>& input, int newSize) {
    vector<int> fold;    
 
    for(int i = 0; i < newSize; i++) fold.push_back(input[i]);
    for(int i = newSize, j = newSize - 1; i < input.size(); i++, j--) fold[j] += input[i];
 
    return fold;
}
 
vector<int> foldWithBiggerEnd(vector<int>& input, int newSize) {
    vector<int> fold;
    
    for(int i = input.size() - 1; i > input.size() - 1 - newSize; i--) fold.push_back(input[i]);
    for(int i = input.size() - 1 - newSize, j = newSize - 1; i >= 0; i--, j--) fold[j] += input[i];
 
    return fold;
}
 
bool equals(vector<int>& v1, vector<int>& v2) {
    for(int i = 0; i < v1.size(); i++) {
        if(v1[i] != v2[i]) return false;
    }
 
    return true;
}
 
bool check(vector<int> v) {
    if(v.size() == m) {
        return equals(v, output);
    }
 
    for(int newSize = v.size() - 1; newSize >= max(m, (int(v.size()) + 1) / 2); newSize--) {
        if(check(foldWithBiggerStart(v, newSize))) return true;
        if(check(foldWithBiggerEnd(v, newSize))) return true; 
    }
 
    return false;
}
 
int main() {
    cin >> n;
    input.resize(n);
    for(int i = 0; i < n; i++) cin >> input[i];
 
    cin >> m;
    output.resize(m);
    for(int i = 0; i < m; i++) cin >> output[i];
 
    if(check(input)) {
        cout << "S" << endl;
        exit(0);
    }
 
    reverse(input.begin(), input.end());
 
    if(check(input)) {
        cout << "S" << endl;
        exit(0);
    }
 
    cout << "N" << endl;
    return 0;
}