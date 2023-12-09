class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int total = 0;
        int tmp = 0;
        for(int i=prices.size()-2; i>=0; i--){
            if(prices[i+1]-prices[i]>0){
                tmp+=(prices[i+1]-prices[i]);
            }
            else{
                total+=tmp;
                tmp=0;
            }
        }
        total+=tmp;
        tmp=0;
        return total;
    }
};