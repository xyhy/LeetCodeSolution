class Solution {
public:
    int mid;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        BS(0, arr.size()-1, x, arr);
        int l = mid, r = mid+1;
        while(k--){
            if(r>=arr.size()){
                ans.push_back(arr[l--]);
            }
            else if(l<0){
                ans.push_back(arr[r++]);
            }
            else if(std::abs(x-arr[l])<=std::abs(arr[r]-x)){
                ans.push_back(arr[l--]);
            }
            else if(std::abs(x-arr[l])>std::abs(arr[r]-x)){
                ans.push_back(arr[r++]);
            }
        }
        
        std::sort(ans.begin(), ans.end());
        return ans;
    }

    void BS(int left, int right, int x, vector<int>& arr){
        mid = (left+right)/2;
        std::cout<<mid<<" "<<left<<" "<<right<<"\n";
        if(left>=right-1)  return;
        if(arr[mid] < x){
            left = mid;
            BS(left, right, x, arr);
        }
        else if(arr[mid] > x){
            right = mid;
            BS(left, right, x, arr);
        }
        return;
    }
};