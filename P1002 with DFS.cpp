#include <bits/stdc++.h>
using namespace std;

/*!
    This code will get TLE in oj.
    See P1002 with DP.cpp to instead.
*/

int n, m, hx, hy;
long long cnt;
bool vis[30][30];
int fx[]={1, 0}, fy[]={0, 1};
int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
void dfs(int x, int y){
    if(x == n && y == m){
        cnt++;
        return ;
    }
    for(int i=0; i<2; i++){
        int tx=x+fx[i];
        int ty=y+fy[i];
        if(tx >= 0 && tx <= n && ty >= 0 && ty <= m && vis[tx][ty] == 0){
            vis[tx][ty] = true;
            dfs(tx, ty);
            vis[tx][ty] = false;
        }
    }
}

int main(){
    cin >> n >> m >> hx >> hy;
    vis[hx][hy] = true;
    for(int i=0; i<8; i++){
        int tx=hx+dx[i];
        int ty=hy+dy[i];
        if(tx >= 0 && tx <= n && ty >= 0 && ty <= m) vis[tx][ty] = true;
    }
    vis[0][0] = true;
    dfs(0, 0);
    cout << cnt;

    return 0;
}