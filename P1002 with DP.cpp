#include <bits/stdc++.h>
using namespace std;

int n, m, hx, hy;
int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
bool blocked[30][30];
unsigned long long f[30][30];

int main(){
    cin >> n >> m >> hx >> hy;
    blocked[hx][hy] = true;
    for(int i=0; i<8; i++){
        int tx=hx+dx[i];
        int ty=hy+dy[i];
        if(tx >= 0 && tx <= n && ty >= 0 && ty <= m) blocked[tx][ty] = true;
    }
    f[0][0] = 1;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(blocked[i][j]) f[i][j] = 0;
            else{
                if(i > 0) f[i][j] += f[i-1][j];
                if(j > 0) f[i][j] += f[i][j-1];
            }
        }
    }
    cout << f[n][m];

    return 0;
}