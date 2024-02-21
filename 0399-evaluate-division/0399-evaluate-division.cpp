class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
        double mat[40][40];
        int key = 0;
        std::map<string, int> nodes;
        for(int i=0; i<40;i++){
            for(int j=0;j<40;j++){
                if(i==j){
                    mat[i][j] = 1.00000;
                }
                else{
                    mat[i][j] = -1.00000;
                }
            }
        }

        for(int i=0; i<equations.size(); i++){
            if(nodes.count(equations[i][0]) == 0){
                nodes.insert(std::pair<string,int>(equations[i][0], key++));
            }
            if(nodes.count(equations[i][1]) == 0){
                nodes.insert(std::pair<string, int>(equations[i][1], key++));
            }
            int ka = nodes[equations[i][0]], kb = nodes[equations[i][1]];
            mat[ka][kb] = values[i];
            mat[kb][ka] = 1/values[i];
        }

        for(int k = 0; k < nodes.size(); k++){
            for(int i = 0; i < nodes.size(); i++){
                for(int j= 0; j < nodes.size(); j++){
                    if(mat[i][j] == -1 && mat[i][k]!=-1 && mat[k][j]!=-1){
                        mat[i][j] = mat[i][k]*mat[k][j];
                        mat[j][i] = 1/mat[i][j];
                    }
                }
            }
        }

        // for(int i= 0; i < nodes.size(); i++){
        //     for(int j=0; j<nodes.size(); j++){
        //         cout<<mat[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }

        for(int i = 0; i<queries.size(); i++){
            string qa = queries[i][0];
            string qb = queries[i][1];
            if(nodes.count(qa)==0 || nodes.count(qb)==0){
                ans.push_back(-1.00000);
            }
            else{
                ans.push_back(mat[nodes[qa]][nodes[qb]]);
            }
        }
        return ans;
    }
};