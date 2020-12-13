/*
* 33. 搜索旋转排序数组
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int L=0,R=nums.size()-1;
        while(L<R) {
            int mid = L + (R-L)/2;
            if( nums[0] <= nums[mid] && ( target > nums[mid] || target < nums[0]))
                L = ++mid;
            else if( target > nums[mid] && target < nums[0])
                L = ++mid;
            else
                R = mid;
        }
        return L==R && nums[L]==target ? L : -1;
    }
};
