/*
* 122. 买卖股票的最佳时机 II
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for(int i=0;i<prices.size()-1;++i) {
            int temp = prices[i+1] - prices[i];
            if(temp>0) res += temp;
        }
        return res;
    }
};
