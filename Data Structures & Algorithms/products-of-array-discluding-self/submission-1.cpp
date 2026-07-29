class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            ans.push_back(left(i,nums)*right(i,nums));
        }
        return ans;
    }

    int left(int index,vector<int>& arr)
    {
        int ans=1;
        for(int i=0;i<index;i++)
        {
            ans*=arr[i];
        }
        return ans;
    }
    int right(int index,vector<int>& arr)
    {
        int ans=1;
        for(int i=arr.size()-1;i>index;i--)
        {
            ans*=arr[i];
        }
        return ans;
    }
};
