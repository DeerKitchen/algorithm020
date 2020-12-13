/*
*  153. 寻找旋转排序数组中的最小值
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int L=0,R=nums.size()-1,mid=0;
        while(L<R) {
            mid = L+(R-L)/2;
            if(nums[mid] < nums[R]) R = mid;
            else if(nums[mid] >= nums[L]) L=++mid;
        }
        return nums[L];
    }
};
