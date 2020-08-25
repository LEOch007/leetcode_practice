//
// Created by linjliang on 2020/8/25.
//

/*
 * 给定n棵树和每棵树的高度，我们可以对某颗树施加魔法，使其这一轮不长高，其他树正常生长，这一轮后施加魔法的树依然
 * 可以继续生长，问：至少需要施加多少次魔法，才能使这n棵树都一样高
 *
 * 例子：
 * 3
 * 1 2 3
 * 输出：3
 * （原因如下：）
 * 第一次对第3棵树施加魔法：2 3 3
 * 第二次对第2棵树施加魔法：3 3 4
 * 第三次对第三棵树施加魔法：4 4 4
 * 共需要3次魔法
 */

// Sure

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> nums(n);
    int min_v = INT_MAX;
    for (int i = 0; i < n; ++i) {
        cin>>nums[i];
        if (nums[i] < min_v) min_v = nums[i];
    }

    long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += nums[i] - min_v;
    }

    cout<<sum<<endl;
}

/*
 * Note:
 *
 * 假设至少需要施加k次魔法，最终树相等的高度为min+k （min为这些树中最低的高度）
 * 举例分析：1 2 3 4 6
 * 1+k
 * 2+k - sth.
 * 3+k - sth.
 * 4+k - sth.
 * 6+k - sth.
 * sth.的总和即为要施加魔法的次数，即为k，故而k本质上为其他树高相对于最矮树高的差值之和
 */