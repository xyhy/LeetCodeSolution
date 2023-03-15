class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        std::map<int,int> mapvec;
        std::vector<int> ans;
        for(auto it = nums2.cbegin(); it != nums2.cend(); it++){
            int val = *it;
            for(auto it2 = it+1; it2 != nums2.cend(); it2++){
                if(val < *it2){
                    mapvec.insert(std::pair<int, int>(val, *it2));
                    break;
                }
            }
            if(mapvec.find(val) == mapvec.end())   mapvec.insert(std::pair<int, int>(val, -1));
        }
        for(auto it = nums1.cbegin(); it != nums1.cend(); it++){
            ans.push_back(mapvec.find(*it)->second);
        }
        return ans;
    }
};