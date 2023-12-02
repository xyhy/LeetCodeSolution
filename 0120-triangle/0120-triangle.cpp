class Solution {
public:
    int storage[201][201];
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i=0; i<201; i++){
            for (int j=0; j<201; j++){
               storage[i][j]=5000000;
            }
        }
        return sol(triangle, 0, 0);
    }
    int sol(vector<vector<int>>& tri, int i, int j){
        if (storage[i][j]==5000000){
            if(i==tri.size()-1){
            storage[i][j]=tri[i][j];
            return tri[i][j];
            }
            int left = sol(tri, i+1, j);
            int right= sol(tri, i+1, j+1);
            int mini=(left<right)?left:right;
            storage[i][j] = tri[i][j]+mini;
        }
        return storage[i][j];
    }
};