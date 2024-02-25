class Solution {
public:
    int vis[51][51] = {0};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int target = image[sr][sc];
        if(color == target) return image;
        else{
            dfs(image, sr, sc, color, target);
        }
        return image;
    }

    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int target){
        if(image[sr][sc] == target){
            image[sr][sc] = color;
            if(sr-1>=0 && !vis[sr-1][sc])
                dfs(image, sr-1, sc, color, target);
            if(sc-1>=0 && !vis[sr][sc-1])
                dfs(image, sr, sc-1, color, target);
            if(sr+1< image.size() && !vis[sr+1][sc])
                dfs(image, sr+1, sc, color, target);
            if(sc+1<image[0].size() && !vis[sr][sc+1])
                dfs(image, sr, sc+1, color, target);
        }
        else{
            return;
        }
    }
};