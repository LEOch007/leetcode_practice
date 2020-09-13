//
// Created by linjliang on 2020/9/13.
//

// Sure

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

const int INF = 8000;

void dfs(vector<vector<int>>& G, int row, vector<int>& dis){
    for (int j = 0; j < G[row].size(); ++j) {
        int w = G[row][j];
        if (w!=-10) {
            dis[j] = min(dis[j], dis[row]+w);
            dfs(G,j,dis);
        }
    }
}

int main(){
    int N,K,M; cin>>N>>K>>M;
    vector<vector<int>> G(N,vector<int>(N));
    for (int i = 0; i < G.size(); ++i) {
        for (int j = 0; j < G[0].size(); ++j) { G[i][j]=INF; }
    }

    for (int i = 0; i < M; ++i) {
        int v,u,w; cin>>v>>u>>w;
        G[v-1][u-1] = w;
    }

    vector<int> dis(N);     // distance
    vector<bool> vis(N);    // visit status
    fill(dis.begin(), dis.end(), INF);
    fill(vis.begin(), vis.end(), false);
    dis[K-1] = 0;

    // relax
    for (int i = 0; i < N; ++i) {
        int u = -1;
        int min_v = INF;
        for (int j = 0; j < N; ++j) {
            if (!vis[j] && dis[j]<min_v){
                min_v = dis[j];
                u = j;
            }
        }
        if (u==-1) break;

        vis[u] = true;
        for (int v = 0; v < N; ++v) {
            if (!vis[v] && dis[v] > dis[u]+G[u][v]) {
                dis[v] = dis[u]+G[u][v];
                // cout<<"*"<<dis[v]<<endl;
            }
        }
    }

    bool reach = true;
    for (int i = 0; i < vis.size(); ++i) {
        if (!vis[i]){
            reach = false;
            break;
        }
    }
    if (!reach) cout<<-1<<endl;
    else{
        // for(auto num:dis) cout<<num<<" ";
        int max_v = -10;
        for (int i = 0; i < dis.size(); ++i) {
            if (dis[i] > max_v) max_v = dis[i];
        }
        cout<<max_v<<endl;
    }
}