//
// Created by linjliang on 2020/8/4.
//

/*
 * 排序算法：
 *
 * 常考点：需要能够手写 快速排序、归并排序、堆排序
 *
 * ---------------------------------------
 *
 * 十大常见排序有：
 * （参考link：https://www.cnblogs.com/onepixel/p/7674659.html）
 *
 * 1、比较类排序：
 *    交换排序： 冒泡排序、快速排序
 *    插入排序： 简单插入排序、希尔排序
 *    选择排序： 简单选择排序、堆排序
 *    归并排序： 二路归并排序、多路归并排序
 *
 * 2、非比较类排序：
 *    计数排序、桶排序、基数排序
 *
 * 各大排序算法比较：
 *
| 排序方法  | 平均时间  | 最坏时间   | 最好时间  |  空间复杂度  | 稳定性 |
| -------- | ------- | -------- | -------- | ---------- | ------ |
| 插入排序 | O(n^2)   | O(n^2)   | O(n)     | O(1)       | Y      |
| 希尔排序 | O(n^1.3) | O(n^2)   | O(n)     | O(1)       | N      |
| 选择排序 | O(n^2)   | O(n^2)   | O(n^2)   | O(1)       | N      |
| 堆排序   | O(nlogn) | O(nlogn) | O(nlogn) | O(1)       | N      |
| 冒泡排序 | O(n^2)   | O(n^2)   | O(n)     | O(1)       | Y      |
| 快速排序 | O(nlogn) | O(n^2)   | O(nlogn) | O(1)       | N      |
| 归并排序 | O(nlogn) | O(nlogn) | O(nlogn) | O(n)       | Y      |
|         |          |          |          |            |        |
| 计数排序 | O(n+k)   | O(n+k)   | O(n+k)   | O(n+k)     | Y      |
| 桶排序   | O(n+k)   | O(n^2)   | O(n)     | O(n+k)     | Y      |
| 基数排序 | O(n*k)   | O(n*k)   | O(n*k)   | O(n+k)     | Y      |


计数排序：
输入的数值转化为键/索引存储在额外开辟的数组空间中，
其要求输入的数组是有明确范围的整数（且往往范围较小）

桶排序：
利用函数映射将数据分布到不同的桶里，再对每个桶进行排序后拼接（排序可用其他排序方法）
核心在于函数映射，高效的函数映射将提高排序性能

基数排序：
先按低位计数排序，再依次对更高位计数排序，最后得到排序数组
故而最终排序结果：高优先级大的在前，高优先级相同的低优先级大的在前

 */

