/**
* 合并两个有序数组
*
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       int i=m-1,j=n-1,r=m+n;
       while(i>=0&&j>=0)
            nums1[--r] = nums1[i] > nums2[j] ? nums1[i--]: nums2[j--];   
       while(j>=0)
            nums1[--r] = nums2[j--];
    }
};
