//
// Created by linjliang on 2020/9/17.
//

// Sure

#include <iostream>
#include <vector>
using namespace std;

// 并查集
int find_parent(vector<int>& parent, int x){
    if (x == parent[x]) return x;
    return find_parent(parent, parent[x]);
}

void union_set(vector<int>& parent, vector<int>& rank, int a, int b){
    int pa = find_parent(parent, a);
    int pb = find_parent(parent, b);

    if (pa == pb) return;
    if (rank[pa] < rank[pb]) { parent[pa] = pb; }
    else if (rank[pa] > rank[pb]) { parent[pb] = pa; }
    else {
        parent[pa] = pb;
        rank[pb]++;
    }
}

int main(){
    int n,m,q; cin>>n>>m>>q;

    // init
    vector<int> parent(n+1);
    vector<int> rank(n+1);
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        rank[i] = 1;
    }

    for (int j = 0; j < m; ++j) {
        int a,b; cin>>a>>b;
        union_set(parent, rank, a,b);
    }

    for (int k = 0; k < q; ++k) {
        int a,b; cin>>a>>b;
        int pa = find_parent(parent, a);
        int pb = find_parent(parent, b);
        if (pa==pb) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}