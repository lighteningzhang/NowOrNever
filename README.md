# NowOrNever

Whether to take a leap of faith, or become an old man, filled with regret, waiting to die alone

----

## 补理论或证明

- [ ] Data Structure: heap sort
- [ ] Data Structure: binary indexed tree
- [ ] Data Structure: segment tree
- [ ] Algorithm: dynamic programming
- [ ] Algorithm: shortest path
- [ ] Algorithm: two pointer
- [ ] proof: shortest path(dij, bellman, floyd)

---

## 补题

- [ ] acw 345 (bellman ford 和 状态dp做法)
- [ ] acw 1145 (不用二分直接用单调性的做法)
- [ ] acw 341 dfs的做法
- [ ] acw 1171 **tarjan做法** 
- [ ] lc 787 **最短路和dp做法**
- [x] 双周赛自定义排序(pq, map)
- [x] 补双周赛第四题
- [ ] lc 138 插next指针的做法
- [ ] lc 327 线段树做法
- [ ] lc 327 平衡树做法
- [ ] lc 973 快排及链表快排

---

# Machine learning

### 感知机

- 损失函数
- 对偶形式

# Algorithm

## 数据结构

### 数组

1. 两数组和：leetcode 1073 [负二进制数相加](https://leetcode-cn.com/problems/adding-two-negabinary-numbers/)
2. 排序：[比大小](https://leetcode-cn.com/problems/how-many-numbers-are-smaller-than-the-current-number/), lc 31 排列, lc 153 旋转数组, lc 154 旋转数组
3. 奇偶数组：lc 922
4. trick: lc 169 抵消法, lc 189 翻转实现旋转

### 链表

1. 链表访问：lc 138 克隆链表(含随机指针)，lc 234 回文链表
2. 环形链表：lc 142 找到位置
3. 链表排序：lc 147 插入排序, lc 148 归并排序

## 字符串

1. implement：leetcode 1625  [执行操作后字典序最小的字符串](https://leetcode-cn.com/problems/lexicographically-smallest-string-after-applying-operations/), 字符串比较：lc 179
2. 加减乘除操作：leetcode 306 [累加数](https://leetcode-cn.com/problems/additive-number/)
3. 回文串：lc 131, lc 132
   4. 子字符串：lc 140单词拆分，lc 214 kmp匹配前缀后缀

### 树

1. 层次遍历：leetcode 623 [在二叉树中增加一行](https://leetcode-cn.com/problems/add-one-row-to-tree/)
2. 前中后序遍历：[lc 144](https://leetcode-cn.com/problems/binary-tree-preorder-traversal/) 前序, [lc 145](https://leetcode-cn.com/problems/binary-tree-postorder-traversal/) 后序 
3. 树上倍增：[lc 1483](https://leetcode-cn.com/problems/kth-ancestor-of-a-tree-node/)找第k个祖先, acw 1174 找公共祖先, acw 1171 距离

### 图

1. 最短路：**floyd** ([acw 344](https://www.acwing.com/activity/content/problem/content/1509/1/) 观光之旅, [acw 1125](https://www.acwing.com/activity/content/problem/content/1507/1/) 牛的旅行, [acw 345](https://www.acwing.com/activity/content/problem/content/1510/1/) 牛站(bellman ford和fast pow的思想), **dijkstra** ([lc 1631](https://leetcode-cn.com/problems/path-with-minimum-effort/) 差值最短路)
2. 最小生成树：**kruskal**([acw1146](https://www.acwing.com/problem/content/1148/) 新的开始(虚拟源点), [acw1145](https://www.acwing.com/problem/content/1147/) 北极通讯网络(~~二分~~), [acw 346 ](https://www.acwing.com/problem/content/348/)扩充最小生成树, [acw 1148](https://www.acwing.com/activity/content/problem/content/1529/1/) 次小生成树, [lc 1631](https://leetcode-cn.com/problems/path-with-minimum-effort/) 建边合并
3. 负环：acw 904 (bellman ford, spfa),  [acw 361](https://www.acwing.com/activity/content/problem/content/1531/1/) 01分数规划, [acw 1165](https://www.acwing.com/activity/content/problem/content/1532/1/) 字符串01分数规划
4. 差分约束：[acw 1169](https://www.acwing.com/activity/content/problem/content/1533/1/) 超级源点, [acw 362](https://www.acwing.com/activity/content/problem/content/1534/1/) 区间转差分约束,
5. 有向图的连通性：tarjan acw 1174, tarjan acw 367 构建强连通分量

### 并查集

1. 并查集 + implementation: lc 1632

### 树状数组

1. acw241 同时利用树状数组和数组进行查值，lc 327 离散化+树状数组

### 栈

1. 单调栈：lc 84, lc 85

### 堆

1. 堆排替换思想: lc 381

## 算法思想

### 贪心

1. 区间问题：leetcode 1024 [视频拼接](https://leetcode-cn.com/problems/video-stitching/), lc 57, lc [1642](https://leetcode-cn.com/problems/furthest-building-you-can-reach/)
2. 数组内贪心：lc 122 买卖股票


### 动态规划

1. 最长上升子序列：leetcode 845 [数组中的最长山脉](https://leetcode-cn.com/problems/longest-mountain-in-array/)(~~其实不是~~), 最长等差数列 [lc 1027](https://leetcode-cn.com/problems/longest-arithmetic-subsequence/)
2. 统计图形个数：lc 1504 长方形个数, lc 1277 正方形个数
3. 纯状态转移：lc 978，1458 两数组最大点积，lc 1639(38双周赛最后一题)
4. 位置转移: lc 174, lc 198 打家劫舍, lc 213打家劫舍 2, 
5. 单调队列优化：acw 1088旅行问题
6. 数位dp：cf 675 div2(C. bargin), acw 338
7. 字符串dp

### 二分

1. [lc 410](https://leetcode-cn.com/problems/split-array-largest-sum/) 分割连续数组, [lc 875](https://leetcode-cn.com/problems/koko-eating-bananas/), [lc 1011](https://leetcode-cn.com/problems/capacity-to-ship-packages-within-d-days/), [lc 1551](https://leetcode-cn.com/problems/magnetic-force-between-two-balls/) 差值二分
2. 二分应用：lc 222 二分检查树

### BFS

1. [lc994](https://leetcode-cn.com/problems/rotting-oranges/) 层次遍历, [lc 1631](https://leetcode-cn.com/problems/path-with-minimum-effort/) bfs +二分



### 排序

1. 桶排序：lc 164（根据和最小值的相对关系放到对应的桶里去）

### 优先队列

1. lc 514 循环字符串+优先队列+记忆化, lc 174 优先队列+记忆化
2. 逆向求目标：lc 1354多次求和构造目标数组

### 双指针

1. lc 167 左右指针       

### 数学

1. 计算几何：直线: lc 149, 矩形面积，直线交：lc 223，
2. 分解因数：lc 172 分解5的个数, 
3. 高精度计算：lc 166 高精度除法(小数，循环节)
4. 数位：lc 233 统计1的个数

### 位操作

1. 翻转：lc 190颠倒二进制位