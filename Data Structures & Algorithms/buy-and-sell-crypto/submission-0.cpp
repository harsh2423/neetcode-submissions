class Solution {
public:
    int maxProfit(vector<int>& arr) 
    {
        int ans=0;
        int maxans=0;
        int l=0,r=1;
        while(r<arr.size())
        {
            if(arr[l]<arr[r]){
                ans=arr[r]-arr[l];
                maxans=max(maxans,ans);

            }
            else l=r;

            r++;
        }
        return maxans;
    }
};
