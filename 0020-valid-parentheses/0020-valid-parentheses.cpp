class Solution {
public:
    bool isValid(string s) {
        if(s.length() % 2)    return false;
        std::stack<char> arr;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                arr.push(s[i]);
            } else {
                if(arr.empty()) return false;
                char top = arr.top();
                if (top == '(' && s[i] == ')'){
                    arr.pop();
                    continue;
                }
                else if (top == '[' && s[i] == ']'){
                    arr.pop();
                    continue;
                }
                else if (top == '{' && s[i] == '}'){
                    arr.pop();
                    continue;
                }
                else    return false;
                
            }
        }
        return arr.empty();
    }
};