class Solution {
public:
vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) 
    {
        vector<int> cur;
        backtrack(nums,target,cur,0);
        return ans;    
    }

    void backtrack(vector<int>& nums, int target,vector<int>& cur, int ind)
    {
        if(target==0)
        {
            ans.push_back(cur);
            return;
        }
        if(ind>=nums.size() || target<0) return;

        cur.push_back(nums[ind]);
        backtrack(nums,target-nums[ind],cur,ind);
        cur.pop_back();
        backtrack(nums,target,cur,ind+1);
    }
};
