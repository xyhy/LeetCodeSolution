class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int maxnum = 0;
        int arr[2501] = {0};
        for (int i = nums.size()-1; i>=0; i--){
            if (arr[i] == 0)   arr[i]++;
            for (int j = nums.size()-1; j>i; j--){
                if(nums[i] < nums[j] && arr[j]+1 > arr[i]){
                    arr[i] = arr[j]+1;
                }
            }
        }
        for (int i = 0; i < nums.size(); i++){
            if (arr[i] > maxnum)   maxnum = arr[i];
        }
        return maxnum;
    }
};