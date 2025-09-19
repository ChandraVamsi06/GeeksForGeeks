class Solution {
  public:
    int minParentheses(string& s) {
        // code here
        int open = 0, close = 0;
        for(char i: s) {
            if(i == '(') open++;
            else {
                if(open > 0) open--;
                else close++;
            }
        }
        return open + close;
    }
};