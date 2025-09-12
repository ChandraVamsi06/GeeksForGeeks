// User function Template for C++

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int diff = arr[n - 1] - arr[0];
        int smallH = arr[0] + k;
        int largeH = arr[n - 1] - k;
        for(int i = 0; i < n - 1; i++) {
            int minH = min(smallH, arr[i + 1] - k);
            int maxH = max(largeH, arr[i] + k);
            diff = min(diff, maxH - minH);
        }
        return diff;
    }
};