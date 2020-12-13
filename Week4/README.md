#学习笔记
本周主要学习了深度优先搜索、广度优先搜索、贪心算法以及二分查找算法  
## 一、递归、回溯和深度优先搜索  
1.递归的是借用栈实现一些操作，是有“来回”过程;  
2.回溯法的核心为试探和复原。整个过程利用递归去执行，在递归函数执行前取修改尝试，满足条件后下沉到下一层，试探完成后将数值复原。在整个试探和复原的过程中找到最终需要的一个或所有解。  
3.回溯算法其实是一种特殊的深度优先遍历算法。之所以叫回溯，主要是因为回溯利用一个不断变化的变量，通过尝试各种可能的过程来搜索需要的结果，强调了回退操作对于搜索的合理性。而深度优先遍历强调的是遍历的思想。  
想要深刻理解和掌握这些算法和思想，需要从做题的过程中感受，因此，多做题能否更加深刻和快速的掌握这些算法思想。
深度优先搜索、广度优先搜索、回溯练习题：
第46题.全排列：https://leetcode-cn.com/problems/permutations/
第102题.二叉树的层序遍历：https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
第433题.最小基因变化：https://leetcode-cn.com/problems/minimum-genetic-mutation/
第22题.括号生成：https://leetcode-cn.com/problems/generate-parentheses/
第515题.在每个树行中找最大值：https://leetcode-cn.com/problems/find-largest-value-in-each-tree-row/
## 二、贪心算法
贪心算法是一种在每一步选择中都采用在当前状态下最好或最优的选择，从而希望导致结果是全局最好或者最优的算法。一旦一个问题可以通过贪心法来解决，那么贪心法一般是解决这个问题的最好办法。由于贪心法高效性以及其所求得的答案比较接近最优结果，贪心法也可以用作辅助算法或者直接解决一些要求结果不特别精确的问题。  
贪心算法与动态规划的不同在于它对每个子问题的解决方案都做出选择，不能回退。动态规划则会保存之前的运算结果，并根据以前的结果对当前进行选择，有回退功能。  
贪心算法、回溯、动态规划之间的区别：  
贪心：当下做局部最优判断;可解决一些最优化问题，如：求图中最小生成树、求哈夫曼编码的等。  
回溯：能够回退;  
动态规划：最优判断+回退。  
练习贪心法的题目：  
第322题.零钱兑换:https://leetcode-cn.com/problems/coin-change/
第455题.分发饼干：https://leetcode-cn.com/problems/assign-cookies/

## 三、二分法
二分查找的前提：  
1.目标函数单调性（单调递增或者递减）;
2.存在上下界;
3.能够通过索引访问。
练习二分习题：  
第69题.x 的平方根：https://leetcode-cn.com/problems/sqrtx/
第153题.寻找旋转排序数组中的最小值：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/
第33题.搜索旋转排序数组：：https://leetcode-cn.com/problems/search-in-rotated-sorted-array/

通过做题，对这些的理解更加深刻。






