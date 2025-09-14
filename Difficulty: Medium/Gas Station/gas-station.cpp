class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        //  code here
        int idx = 0, tot = 0, need = 0;
        int n = gas.size();
        for(int i = 0; i < n; i++) {
            int diff = gas[i] - cost[i];
            tot += diff;
            need += diff;
            if(need < 0) {
                idx = i + 1;
                need = 0;
            }
        }
        return (tot >= 0) ? idx : -1;
    }
};