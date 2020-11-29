/**
*  两数之和
利用哈希表
 *    将遍历后的元素值作为key：
 *    每次循环时，先判断哈希表中是否包含target - nums[i]的值，
 *    若包含，则返回对应的value和当前坐标。
 *    若不包含，则将该元素值作为key，地址作为value，加入到哈希map中。
 *    该方法时间复杂度为O(N)；
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        unordered_map<int,int> value_map(len);
        for(int i=0;i<len;++i) {
            int temp = target - nums[i];
            if(!value_map.count(temp)) value_map[nums[i]] = i;
            else return { value_map[temp],i };
        }
        return {};
    }
};
