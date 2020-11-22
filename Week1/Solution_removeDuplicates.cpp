/**
*删除排序数组中的重复项
*解题思路：
*使用双指针法：i和j，i为快指针，j为慢指针
*1、一层循环完成，首先将比较数组前后的大小，如果相等，则将第一个数值赋值给j的坐标元素，然后i移动到新的数值；如果不相等，则直接移动i指针；
*2、重复上述操作；
*/
//98写法
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        int j = 1;
        for(int i=1;i<nums.size();++i) 
            if(nums[i] != nums[j-1])  nums[j++] = nums[i];
        return j;
    }
};
//C++11特性写法
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        auto i = 0;
        for(auto m : nums)
            if(m > nums[i]) nums[++i] = m;
        return ++i;
    }
};
