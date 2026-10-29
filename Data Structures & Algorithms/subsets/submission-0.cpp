class Solution {
public:
vector<vector<int>> ans;
vector<int> cur;
    vector<vector<int>> subsets(vector<int>& nums) 
    {
    backtrack(0, nums);
    return ans;
    }

    void backtrack(int ind, vector<int>& nums) {
    if (ind == nums.size()) {
        ans.push_back(cur);
        return;
    }

    // Include
    cur.push_back(nums[ind]);
    backtrack(ind + 1, nums);

    cur.pop_back();
    int next=ind+1;
    while(next<nums.size() && nums[ind]==nums[next]) next++;

    // Exclude
    backtrack(next, nums);
}  
};
