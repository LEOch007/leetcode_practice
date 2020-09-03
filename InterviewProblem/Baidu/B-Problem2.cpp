//
// Created by linjliang on 2020/9/3.
//

// Sure

#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct ppl{
    int val;
    int id;
};

struct job{
    int val;
    int id;
};

bool ppl_cmp(ppl a, ppl b){
    return a.val < b.val;
}

bool job_cmp(job a, job b){
    return a.val < b.val;
}

int main(){
    int T; cin>>T;
    while (T--){
        int n,m; cin>>n>>m;
        vector<ppl> ppls(n);
        vector<job> jobs(m);
        for (int i = 0; i < n; ++i) {
            int val; cin>>val;
            ppls[i].val = val;
            ppls[i].id = i+1;
        }
        for (int i = 0; i < m; ++i) {
            int val; cin>>val;
            jobs[i].val = val;
            jobs[i].id = i+1;
        }

        sort(ppls.begin(), ppls.end(), ppl_cmp);
        sort(jobs.begin(), jobs.end(), job_cmp);

//        for(auto num:ppls) cout<<num.val<<"("<<num.id<<") ";
//        cout<<endl;
//        for(auto num:jobs) cout<<num.val<<"("<<num.id<<") ";
//        cout<<endl;

        unordered_map<int, int> mp;
        int j = 0;
        for (int i = 0; i < n; ++i) {
            while (j<m && jobs[j].val<ppls[i].val) { j++; }

            if (j>=m) break;
            mp.insert(make_pair(ppls[i].id, jobs[j].id));
            j++;
        }

        for (int ppl_id = 1; ppl_id <= n; ++ppl_id) {
            if (mp.find(ppl_id) == mp.end()) cout<<-1<<" ";
            else cout<<mp[ppl_id]<<" ";
        }
        cout<<endl;

//        for(auto iter = mp.begin(); iter!=mp.end(); iter++){
//            cout<<iter->first<<": "<<iter->second<<endl;
//        }
    }
}