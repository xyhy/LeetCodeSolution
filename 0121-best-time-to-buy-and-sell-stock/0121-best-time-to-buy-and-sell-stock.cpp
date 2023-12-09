class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int stored[100005];
        int maxi=0;
        stored[prices.size()-1]=0;
        for (int i=prices.size()-2; i>=0; i--){
            stored[i]= (stored[i+1]+prices[i+1]-prices[i]>prices[i+1]-prices[i])?stored[i+1]+prices[i+1]-prices[i]:prices[i+1]-prices[i];
            maxi=(maxi>stored[i])?maxi:stored[i];
        }
        return maxi;
    }
};