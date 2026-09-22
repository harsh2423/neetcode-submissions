class Solution {
public:
    int findMin(vector<int> &arr) 
    {
        int l=0;
        int r=arr.size()-1;
        int ans=arr[l];
        while(l<=r)
        {
            if(arr[l]<=arr[r])
            {
                ans=min(ans,arr[l]);
                break;
            }
            int m=l+(r-l)/2;
            ans=min(ans,arr[m]);

            if(arr[l]<=arr[m]){
                l=m+1;
            }
            else r=m-1;
        }    
        return ans;
    }
};
