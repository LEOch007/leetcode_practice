//
// Created by linjliang on 2020/8/18.
//

/*
 * 有 N 个网络节点，标记为 1 到 N。

给定一个列表 times，表示信号经过有向边的传递时间。 
times[i] = (u, v, w)，其中 u 是源节点，v 是目标节点， w 是一个信号从源节点传递到目标节点的时间。

现在，我们从某个节点 K 发出一个信号。需要多久才能使所有节点都收到信号？如果不能使所有节点收到信号，返回 -1。

 

示例：



输入：times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
输出：2
 

注意:
N 的范围在 [1, 100] 之间。
K 的范围在 [1, N] 之间。
times 的长度在 [1, 6000] 之间。
所有的边 times[i] = (u, v, w) 都有 1 <= u, v <= N 且 0 <= w <= 100。

 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        const int INF = 9999999;

        // build the graph
        vector<vector<int>> G(N, vector<int>(N));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                G[i][j] = INF;
            }
        }
        for (int i = 0; i < times.size(); ++i) {
            int u = times[i][0]-1;
            int v = times[i][1]-1;
            int w = times[i][2];
            G[u][v] = w;
        }

        // dijkstra algorithm
        // initial
        vector<int> dis(N);
        vector<int> vis(N);
        fill(dis.begin(), dis.end(), INF);
        fill(vis.begin(), vis.end(), false);
        dis[K-1] = 0;       // starting point

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
                if (!vis[v] && dis[v] > dis[u]+G[u][v])
                    dis[v] = dis[u]+G[u][v];
            }
        }

        // determine
        int max_v = dis[0];
        for (int k = 1; k < N; ++k) {
            if (dis[k] > max_v) max_v = dis[k];
        }

        if (max_v == INF) return -1;
        else return max_v;
    }
};

int main(){
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};

    Solution s;
    int ans = s.networkDelayTime(times,4,2);
    cout<<ans<<endl;
}

/*
 * Note:
 *
 * 单源最短路 用Dijkstra算法：（关键点）
 * - 每次找到最近的点 （距离单源最小的点）
 * - 根据这个点对其周围连着的点进行松弛（即更新单源到周围点的距离）
 */