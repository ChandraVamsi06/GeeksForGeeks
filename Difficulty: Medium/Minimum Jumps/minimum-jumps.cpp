class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        int n = arr.size();
        if(n == 1) return 0;
        if(arr[0] == 0) return -1;
        int jumps = 0, far = 0, curr = 0;
        for(int i = 0; i < n - 1; i++) {
            far = max(far, i + arr[i]);
            if(i == curr) {
                jumps++;
                curr = far;
                if(curr >= n - 1) return jumps;
            }
        }
        return -1;
    }
};
