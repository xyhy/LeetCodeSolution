class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = 0, sum = 0;
        for (int i = 0; i < piles.size(); i++){
            if(piles[i] > maxi) maxi = piles[i];
            // sum+=piles[i];
        }
        int l = 1, r = maxi;
        int k = (l+r)/2;
        while(l<r){
            // if(k*h < sum){
            //     l = k+1;
            //     k = (l+r)/2;
            //     continue;
            // }
            int time = 0;
            for (int i = 0; i < piles.size(); i++){
                time += ceil((double)piles[i]/(double)k);
            }
            if (time > h)   l = k+1;
            else  r = k;
            k = (l+r)/2;
        }
        return k;
    }
};