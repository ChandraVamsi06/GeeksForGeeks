class Solution {
  public:
    int toInt(const string &s) {
        int num = 0, sign = 1, i = 0;
        if (s[0] == '-') {
            sign = -1;
            i = 1;
        }
        for (; i < (int)s.size(); i++) {
            num = num * 10 + (s[i] - '0');
        }
        return sign * num;
    }
    int floorDiv(int a, int b) {
        int q = a / b;
        int r = a % b;
        if (r != 0 && ((a < 0) ^ (b < 0))) q -= 1;
        return q;
    }
    int power(int a, int b) {
        int res = 1;
        for (int i = 0; i < b; i++) res *= a;
        return res;
    }
    int evaluatePostfix(vector<string>& arr) {
        stack<int> st;
        for (string &s : arr) {
            if (s == "+" || s == "-" || s == "*" || s == "/" || s == "^") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                if (s == "+") st.push(a + b);
                else if (s == "-") st.push(a - b);
                else if (s == "*") st.push(a * b);
                else if (s == "/") st.push(floorDiv(a, b));
                else st.push(power(a, b));
            } else {
                st.push(toInt(s));
            }
        }
        return st.top();
    }
};
