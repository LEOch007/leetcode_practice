//
// Created by linjliang on 2020/8/16.
//

/*
 * dijkstra算法：求最短路
 */


// Sure

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N,P;
    cin>>N>>P;

    const int non_reach = 99999999;

    vector<vector<int>> e(N,vector<int>(N));    // 邻接矩阵
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i==j) e[i][j] = 0;
            else e[i][j] = non_reach;
        }
    }
    for (int k = 0; k <P ; ++k) {
        int A,B,T;
        cin>>A>>B>>T;
        e[A][B] = T;
        e[B][A] = T;
    }
    int des;
    cin>>des;

    vector<int> dis(N);     // 距离
    vector<bool> vis(N);     // 访问
    for (int i = 0; i < N; ++i) {
        dis[i] = e[0][i];
        vis[i] = false;
    }
    vis[0] = true;

    // shortest way
    for (int i = 0; i < N-1; ++i) {
        int min_v = non_reach;
        int u = -1;
        // 寻找权值最小u
        for (int j = 0; j < N; ++j) {
            if (!vis[j] && dis[j]<min_v){
                min_v = dis[j];
                u = j;
            }
        }
        vis[u] = true;

        for (int v = 0; v < N; ++v) {
            if (e[u][v]<non_reach){
                if (dis[v] > dis[u]+e[u][v]) dis[v] = dis[u]+e[u][v];
            }
        }
    }

    cout<<dis[des]<<endl;
}