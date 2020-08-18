//
// Created by linjliang on 2020/8/18.
//

#include <iostream>
#include <vector>
using namespace std;

class Graph_Path{
public:
    vector<int> Dijkstra(vector<vector<int>> G, int start){
        if (start < 0) return {-1};
        if (G.size() == 0 || G[0].size() == 0) return {-1};
        if (G.size() != G[0].size()) return {-1};

        const int INF = 9999999;
        int N = G.size();

        // initial
        vector<int> dis(N);     // distance
        vector<bool> vis(N);    // visit status
        fill(dis.begin(), dis.end(), INF);
        fill(vis.begin(), vis.end(), false);
        dis[0] = 0;

        // relax
        for (int i = 0; i < N; ++i) {
            // find the closest point
            int u = -1;
            int min_v = INF;
            for (int j = 0; j < N; ++j) {
                if (!vis[j] && dis[j]<min_v){
                    min_v = dis[j];
                    u = j;
                }
            }
            if (u==-1) break;

            // do relaxation based on this point
            vis[u] = true;
            for (int v = 0; v < N; ++v) {
                if (!vis[v] && dis[v] > dis[u]+G[u][v]) {
                    dis[v] = dis[u]+G[u][v];
                }
            }
        }

        return dis;
    }
};