/**
*  移动零
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        auto i=0,j=0;
        while(i<size) {
            if(nums[i]) {
                if(i > j) swap(nums[j],nums[i]);
                ++j;
            }
            ++i;
        }
    }
};
