//
// Created by linjliang on 2020/9/12.
//

/*
 * 假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对(h, k)表示，
 * 其中h是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。 编写一个算法来重建这个队列。

注意：
总人数少于1100人。

示例

输入:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

输出:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/queue-reconstruction-by-height
 */

#include <vector>
using namespace std;

class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b){
        bool ans;
        if (a[0]==b[0]){
            ans = a[1]<b[1];    // 按排名 低的在前
        }
        else {
            ans = a[0]>b[0];    // 按身高 高的在前
        }
        return ans;
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);

        vector<vector<int>> result;
        for (int i = 0; i < people.size(); ++i) {
            auto iter = people.begin()+people[i][1];
            result.insert(iter,people[i]);
        }

        return result;
    }
};

/*
 * Note:
 *
 * 蛮难想的一道题 运用到贪心的思想：
 * 假设身高都一致，那么按排名从小到大即可；
 * 如果身高不一致，那么身高低的需要插入到身高高的前面，因为这样不影响高度更高的身高的相互关系
 *
 * 排序的原则很关键，
 * 同样高的：排名从小到大；
 * 不一样高：高度从高到低；
 *
 * 目的是为了在插入的时候：始终先插入高的，再插入矮的，故而不影响高的之间的相互关系，插入位置则为其排名
 */