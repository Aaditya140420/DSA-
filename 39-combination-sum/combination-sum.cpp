class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        
        sort(candidates.begin(), candidates.end());
        function<void(int, int)> backtrack = [&](int start, int target) {
            if (target == 0) {
                ans.push_back(temp);
                return;
            }
            for (int i = start; i < candidates.size(); i++) {
                if (candidates[i] > target)
                    break;
                temp.push_back(candidates[i]);
                backtrack(i, target - candidates[i]);
                temp.pop_back();
            }
        };
        backtrack(0, target);
        return ans;
    }
};