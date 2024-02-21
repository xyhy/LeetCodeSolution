class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool> ans;
        bool mat[101][101];
        for(int i = 0; i < numCourses; i++){
            for(int j = 0;j<numCourses; j++){
                mat[i][j] = false;
            }
        }
        for(int i = 0; i < prerequisites.size(); i++){
            int pre = prerequisites[i][0];
            int course = prerequisites[i][1];
            mat[pre][course] = true;
        }

        for(int k = 0; k<numCourses; k++){
            for(int i = 0; i < numCourses; i++){
                for(int j = 0; j<numCourses; j++){
                    if(i!=j && mat[i][k] && mat[k][j])  mat[i][j]=true;
                }
            }
        }

        for(int i = 0;i < queries.size(); i++){
            ans.push_back(mat[queries[i][0]][queries[i][1]]);
        }
        return ans;
    }
};