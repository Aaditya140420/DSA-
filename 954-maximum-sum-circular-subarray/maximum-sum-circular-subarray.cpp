class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
       int total = nums[0];
       int best = nums[0];
       int max_ans = nums[0];
       int worst = nums[0];
       int min_ans = nums[0];

       for(int i = 1 ; i < nums.size() ; i++){
        total += nums[i];

        best = max(nums[i], best + nums[i]);
            max_ans = max(max_ans, best);

        worst = min(nums[i], worst + nums[i]);
            min_ans = min(min_ans, worst);
       } 

       if (max_ans < 0)
            return max_ans;

        
        int circular = total - min_ans;

        return max(max_ans, circular);
       }
      
    
};