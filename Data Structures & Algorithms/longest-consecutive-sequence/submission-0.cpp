class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int ans=0;   
        unordered_set<int> numset(nums.begin(),nums.end());

        for(int num:nums)
        {
            if(numset.find(num-1)==numset.end()){
                int len=0;
                while(numset.find(num+len)!=numset.end()){
                    len++;
                }
                ans=max(ans,len);
            }
        }
        return ans;
    }
};
