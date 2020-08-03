//
// Created by linjliang on 2020/8/3.
//

/*
 * 你是产品经理，目前正在带领一个团队开发新的产品。
 * 不幸的是，你的产品的最新版本没有通过质量检测。
 * 由于每个版本都是基于之前的版本开发的，所以错误的版本之后的所有版本都是错的。

假设你有 n 个版本 [1, 2, ..., n]，你想找出导致之后所有版本出错的第一个错误的版本。

你可以通过调用 bool isBadVersion(version) 接口来判断版本号 version 是否在单元测试中出错。
实现一个函数来查找第一个错误的版本。你应该尽量减少对调用 API 的次数。

示例:

给定 n = 5，并且 version = 4 是第一个错误的版本。

调用 isBadVersion(3) -> false
调用 isBadVersion(5) -> true
调用 isBadVersion(4) -> true

所以，4 是第一个错误的版本。 

 */


// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

bool isBadVersion(int version);
class Solution {
public:
    int firstBadVersion(int n) {
        if (n==0) return -1;

        int i = 1;
        int j = n;
        while (i+1<j){
            int mid = ((long)i+(long)j)/2;  // to avoid overflow
            if (!isBadVersion(mid))
                i = mid;
            else if (isBadVersion(mid-1))
                j = mid;
            else
                return mid;
        }
        if (isBadVersion(1)) return 1;
        if (isBadVersion(n)) return n;
        return -1;
    }
};

/*
 * Note:
 *
 * 当输入输出都是int，算法却出现数值类型溢出问题时，
 * 要检查中间计算量是否出现下溢或上溢
 */