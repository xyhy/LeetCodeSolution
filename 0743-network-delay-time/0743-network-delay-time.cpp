class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int w_map[101][101];
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (i == j) w_map[i][j] = 0;
                else w_map[i][j] = 10000000;
            }
        }
        for (auto it : times){
            int u = it[0], v = it[1], w = it[2];
            w_map[u-1][v-1] = w;
        }
        
        
        for (int g = 0; g < n; g++){
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    w_map[i][j] = (w_map[i][j] <= w_map[i][g]+w_map[g][j]) ? w_map[i][j] : (w_map[i][g]+w_map[g][j]);
                    if (w_map[i][j] >= 10000000)    w_map[i][j] = 10000000;
                }
            }
        }
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j< n; j++){
                cout<< w_map[i][j]<< " ";
            }
            cout<<"\n";
        }
        
        int max_path = 0;
        for(int i = 0; i < n; i++){
            if (w_map[k-1][i] >= 10000000){
                max_path = -1;
                break;
            }
            else{
                max_path = (max_path >= w_map[k-1][i])?max_path:w_map[k-1][i];
            }
        }
        return max_path;
    }
};