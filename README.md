# LeedCode

## 数据结构：字符串
*   [regex源码](regex/Solution.hpp)
* 14 [最长公共前缀](t14_最长公共前缀/Solution.hpp) 22/9/24
* 6  [Z字形变换](t6_Z字形变换/Solution.hpp) 22/9/23
* 面试题01.09 [字符串轮转](面试题01.09.字符串轮转/Solution.hpp) 简单/22/9/29 循环就连两遍 || (i+j) mod n
* 1694 [重新格式化电话号码](t1694_重新格式化电话号码) 简单/22/10/1
* 1016 [子串能表示从1到N数字的二进制串](t1016_子串能表示从1到N数字的二进制串/Solution.hpp) 中等/22/10/1  两次迭代 set记录
*   43 [字符串相乘](t43_字符串相乘/Solution.hpp) 大数乘法/22/10/7
*    9 [回文数](t9_回文数/Solution.hpp)  简单/22/10/7

## 数据结构：数组    子串与子数组
*  828 [统计子串中的唯一字符](t828/Solution.hpp)        22/9/6
*  907 [子数组的最小值之和](t907/Solution.hpp)  最小栈 左边界（都大于等于） 右边界（都大于）  维护最小值栈 ? 22/9/6
* 1856 [子数组最小乘积的最大值](t1856/Solution.hpp) 22/9/6
* 2104 [子数组范围和](t2104/Solution.hpp) 22/9/6
*  496 [下一个更大元素I](t496/)  ？
*  503 [下一个更大元素II](t503/) ？
*    7 [整数反转](t7_整数反转)  22/9/23
* 面试题17.19 [消失的两个数字](面试题17.19.消失的两个数字/Solution.hpp)  22/9/26 先算消失的和twoSum，然后分成两半: [1, twoSum/2] , (twoSum/2 , n+2]；在左半边再来一次 
* 面试题01.08 [零矩阵](面试题01.08.零矩阵/Solution.hpp) 中等/22/9/30 第一遍标记 第二遍修改  标记放在首行首列优化存储 
*  927 [三等分](t927_三等分/Solution.hpp) 困难/22/10/6  先三等分数字1，再判相对。
* 1790 [仅执行一次字符串交换能否使两个字符串相等](t1790_仅执行一次字符串交换能否使两个字符串相等/Solution.hpp) 简单/22/10/11 计数统计

## 数据结构：链表
* offer24 [反转链表](offer024/Solution.h)  2021/6/1
* 138 [复制带随机指针的链表](t138/Solution.hpp)    算法1：循环+哈希表 算法2：递归+哈希表 22/8/30
*  21 [合并两个有序链表](t21/Solution.h)        算法1：递归   算法2：迭代     22/8/31
*  23 [合并K个升序链表](t23/Solution.h)       算法1：分治  22/8/31
*  61 [旋转链表](t61_旋转链表/Solution.hpp)     中等/22/10/1 快慢指针：快k步指针
*  24 [两两交换链表中的结点](/t24/Solution.hpp)    22/9/9
* 707 [设计链表](t707_设计链表)  22/9/23
* 143 [重排链表](t143_重排链表/Solution.hpp) 中等/22/9/29  分前后两半：快慢指针  反转：递归 合并：

## 数据结构：树
* 1026[节点与其祖先之间的最大差值](t1026_节点与其祖先之间的最大差值/Solution.hpp)  中等/22/10/2 后序遍历

## 数据结构：栈
*  946 [验证栈序列](t946/Solution.hpp)   22/8/31
* 1475 [商品折扣后的最终价格](t1475/Solution.h)  单调栈、从后往前、迭代 22/9/1
* t856 [括号的分数](t856_括号的分数/Solution.hpp) 中等22/10/9 栈，括号：右括号结算。

## 数据结构：滑动窗口
* offer59 [滑动窗口的最大值](offer59/Solution.hpp) 困难  算法1 优先队列 priority_queue ：存储二元组(num, index)  pair<int, int> ; 算法2 单调队列： deque<int> ：存储坐标index

---
## 算法：排序
* 1619 [删除某些元素后的数组均值](t1619/Solution.hpp) 简单 22/9/14
* 1608 [特殊数组的特征值](t1608/Solution.hpp) 简单 22/9/12
* 1636 [按照频率将数组升序排序](t1636/Solution.hpp) 简单 22/9/19

## 算法：二分法   找区间还是找某个值
*  162 [寻找峰值](t162_寻找峰值/Solution.hpp) 二分法，缩小也能找到最值 中等/22/10/8
* 1901 [寻找峰值II](t1901_寻找峰值II/Solution.hpp) 二分法，找到行或列的最大值，然后二分法。 中等/22/10/8
*  275 [H指数II](t275_H指数II/Solution.hpp) 二分法

## 算法：模拟 
* 1582 [二进制矩阵中的特殊位置](t1582/Solution.hpp)   矩阵 迭代2遍  22/9/4
*  946 [验证栈序列](t946/Solution.hpp)   22/8/31
* LCP55 [采集果实](LCP55_采集果实/Solution.hpp) 简单/22/10/11

## 算法: 枚举
*  672 [灯泡开关II](t672/Solution.hpp)  迭代 全排列遍历 分析开关个数和按钮次数 降低搜索次数


## 算法： 递归   数据结构 ：二叉树 搜索二叉树 递归
* 669 [修剪二叉搜索树](t669/Solution.hpp)  中等  22/9/10
* 654 [最大二叉树](t654/Solution.hpp)        22/8/30
* 998 [最大二叉树II](t998/Solution.hpp)  同 654.最大二叉树    22/8/30
* 687 [最长同值路径](t687/Solution.hpp)    中等 22/9/2
* 106 [从中序与后序遍历序列构造二叉树](t106_从中序与后序遍历序列构造二叉树/Solution.hpp) 中等/22/10/10 递归/迭代+stack

## 算法：DFS、回溯、深度优先搜索
*  282 [给表达式添加运算符](t282/Solution.h)     困难 DFS回溯 22/9/1
*  473 [火柴拼正方形](t473/Solution.hpp)        中等 22/9/10
* 1020 [飞地的数量](t1020/Solution.hpp)         中等 22/9/10 BFS
*  572 [另一个树的子树](t572/Solution.hpp)     《简单》dfs / kmp  22/9/12 
*  827 [最大人工岛](t827/Solution.hpp)          困难 dfs 岛屿标记 
* offer33 [二叉搜索树的后序遍历序列](offer33_二叉搜索树的后序遍历序列/Solution.hpp)  中等/22/9/30 优化：单调栈（递增）
*   40 [组合总和II](t40_组合总和II/Solution.hpp) 中等/22/9/28 剪枝：有序、重复且不为第一个 (i > start && candidates[i] == candidates[i - 1])
*   46 [t46_全排列I](t46_全排列I/Solution.hpp)
*   47 [t47_全排列II](t47_全排列II/Solution.hpp) 中等/22/10/7 剪枝：有序、重复且不为第一个(i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])
*  130 [被围绕的区域](t130_被围绕的区域/Solution.hpp) 中等/22/10/7 同1020题 BFS DFS 从边缘进入

## 算法：层次遍历、BFS
*  116 [充填每个节点的下一个右侧节点](t116/Solution.h) 层次遍历、BFS     22/9/1
*  117 [充填每个节点的下一个右侧节点II](t116/Solution.h) 层次遍历、BFS      22/9/1
* 1466 [重新规划路线](t1466/Solution.hpp)  22/9/9
*  854 [相似度为K的字符串](t854相似度为K的字符串/Solution.hpp)  困难 剪枝 22/9/21

## 算法：动态规划（迭代） & 记忆化搜索（递归）
*   62 [不同路径](t62/Solution.h)   算法2：组合 22/8/31
*   63 [不同路径II](t63/Solution.h)     22/8/31
*   91 [解码方法](t91/Solution.h)   中等  22/9/1
*  241 [为运算表达式设计优先级](t241/Solution.hpp)  中等 分治（？）、记忆化搜索、动态规划  22/9/1
*  646 [最长数对链](t646/Solution.hpp)       中等      22/9/2
*  435 [无重叠区间](t435/Solution.hpp)       【1】动态规划   中等   未做     
* 1987 [不同的好子序列数目](t1987/Solution.hpp) 22/9/9  未做
*   97 [交错字符串](t97/Solution.hpp)  中等 22/9/19  《滚动数组》 优化
*  788 [旋转数字](t788_旋转数字/Solution.hpp)  中等 22/9/25 忆化搜索（递归）
*  918 [环形子数组的最大和](t918_环形子数组的最大和/Solution.hpp)  中等/22/9/30   Kanade 算法 ||  技巧：前缀和和单调递增队列（保留最小值） 环形数组：把数组连两遍，保证(i-n i]
* 面试题08.11 [硬币](面试题08.11.硬币/Solution.hpp) 中等/22/9/30  先遍历硬币种类，防止顺序不同的分枝
* 面试题17.09 [第k个数](面试题17.09.第k个数/Solution.hpp) 中等/22/9/28 定义三个指针 p3,p5,p7表示下一个数是当前指针指向的数乘以对应的质因数
* 1800 [最大升序子数组和](t1800_最大升序子数组和/Solution.hpp) 简单/22/10/7 
* 2364 [统计坏数对的数目]() 组合 1+2+3+...+n 中等/22/10/8 动态规划 (dp[n] = dp[n-1]+1 或者 1)
* 2110 [股票平滑下跌阶段的数目](t2110_股票平滑下跌阶段的数目/Solution.hpp) 中等/22/10/9 组合 1+2+3+...+n (dp[n] = dp[n-1]+1 或者 1)
* t801 [使序列递增的最小交换次数](t801_使序列递增的最小交换次数/Solution.hpp) 困难/22/10/10  原来的情况：（1）必须换 (2) 不能换 （3）可换可不换       


## 算法：贪心
* 646 [最长数对链](t646/Solution.hpp)      【2】贪心算法   中等   22/9/2
* 670 [最大交换](t670/Solution.hpp)  中等   22/9/13
* 857 [雇佣 K 名工人的最低成本](t857/Solution.hpp) 困难 22/9/11  优先队列
*  45 [跳跃游戏II](t45_跳跃游戏II/Solution.hpp) 中等/22/10/7
* 870 [优势洗牌](t870_优势洗牌/Solution.hpp) 中等/22/10/8 田忌赛马 从小到大比较，没有优势把它就对应最大的。

## 算法：分治
* 395 [至少有K个重复字符的最长子串](t395至少有K个重复字符的最长子串/Solution.hpp)  实现：递归  使用split分割函数

---
## 多线程
* 1116 [打印零与奇偶数](t1116_打印零与奇偶数/Solution.hpp) mutex、condition_variable 中等/22/10/1

---

## 技巧：双指针：左右指针、快慢指针
*  11 [盛最多水的容器](t11/Solution.h)
*  15 [三数之和](t15/Solution.h)
*  16 [最接近的三数之和](t16/Solution.hpp) 22/9/9
* offer21 [调整数组顺序使奇数位于偶数前面](offer21_调整数组顺序使奇数位于偶数前面/Solution.hpp) 简单/22/9/30  左右指针 前后指针

## 技巧：滑动窗口：特殊的左右指针
* 209 [长度最小的子数组](t209/Solution.hpp)  中等 滑动窗口 方法二：前缀和+ 二分法  22/9/19

## 技巧：前缀和

## 技巧：哈希表
* 1624 [两个相同字符之间的最长子字符串](t1624/Solution.hpp) 哈希表： 当前字符->第一次出现的索引
*  811 [子域名访问计数](t811_子域名访问计数/Solution.hpp) 哈希表 中等/22/10/5
* 2364 [统计坏数对的数目](t2364_统计坏数对的数目/Solution.hpp) 中等/22/10/8
*  532 [数组中的k-diff数对](t532_数组中的k-diff数对/Solution.hpp) 中等/22/10/9 哈希表 / 排序+双指针 

---
## 
* 1598 [文件夹操作日志搜集器](t1598/Solution.hpp)  22/9/9




