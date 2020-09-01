//
// Created by linjliang on 2020/8/31.
//

/*
 * 给你一个数组 arr ，请你将每个元素用它右边最大的元素替换，如果是最后一个元素，用 -1 替换。

完成所有替换操作后，请你返回这个数组。


示例：

输入：arr = [17,18,5,4,6,1]
输出：[18,6,6,6,1,-1]
 

提示：

1 <= arr.length <= 10^4
1 <= arr[i] <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/replace-elements-with-greatest-element-on-right-side
 */

#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        if (arr.size() == 1) return {-1};

        int max_right = arr[arr.size()-1];
        arr[arr.size()-1] = -1;
        for (int i = arr.size()-2; i >= 0; --i) {
            int tmp = arr[i];
            arr[i] = max_right;

            max_right = max(max_right, tmp);
        }
        return arr;
    }
};

/*
 * Note:
 *
 * 从左往右扫，需要维护一个单调栈来记录右边最大值，时间复杂度O(n)，空间复杂度O(n)
 * 从右往左扫，则只需要维护一个数来记录右边最大值即可，时间复杂度O(n)，空间复杂度O(1)
 *
 * 从中可见，当从左往右思路复杂时，不妨换个角度，从右往左，或许就别有洞天豁然开朗
 */
