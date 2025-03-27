#include <bits/stdc++.h>
 
using namespace std;
 
int n, m, v;
int a[200010], piecesAhead[200010], piecesBehind[200010];
 
int piecesRestantes(int s, int e) {
    if(s == 0 && e == n - 1) return 0;
    if(s == 0) return piecesAhead[e + 1];
    if(e == n - 1) return piecesBehind[s - 1];
    return piecesAhead[e + 1] + piecesBehind[s - 1];
}
 
int main() {
    int t;
    cin >> t;
 
    while(t--) {
        cin >> n >> m >> v;
 
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
 
        long long total = 0;
        int currentPieces = 0;
        for(int i = 0; i < n; i++) {
            total += a[i];
            if(total >= v) {
                currentPieces++;
                total = 0;
            }
            piecesBehind[i] = currentPieces;
        }
 
        if(piecesBehind[n - 1] < m) {
            cout << -1 << endl;
            continue;
        }
 
        total = 0;
        currentPieces = 0;
        for(int i = n - 1; i >= 0; i--) {
            total += a[i];
            if(total >= v) {
                currentPieces++;
                total = 0;
            }
            piecesAhead[i] = currentPieces;
        }
 
        /*for(int i = 0; i < n; i++) cout << piecesBehind[i] << " ";
        cout << endl;
        for(int i = 0; i < n; i++) cout << piecesAhead[i] << " ";
        cout << endl;*/
 
        int s = 0, e = 0;
        long long totalTasty = a[0];
        long long maxTotalTasty = -1;
        while(1) {
            if(piecesRestantes(s, e) >= m) {
                maxTotalTasty = max(maxTotalTasty, totalTasty);
                if(e + 1 == n) break;
                totalTasty += a[e + 1];
                e++;
            }
            else {
                totalTasty-=a[s];
                s++;
                if(s > e) {
                    if(e + 1 == n) break;
                    totalTasty += a[e + 1];
                    e++;
                }
            }
        }
 
        cout << max(maxTotalTasty, (long long)(0)) << endl;
 
    }
}