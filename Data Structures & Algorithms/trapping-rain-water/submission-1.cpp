class Solution {
public:
    int trap(vector<int>& ht) 
    {
        int l=0;
        int r=ht.size()-1;
        int maxl=ht[l];
        int maxr=ht[r];
        int ans=0;
        while(l<=r)
        {
            if(maxl<maxr){
                maxl=max(maxl,ht[l]);
                ans+=(maxl-ht[l]);
                l++;
            }
            else{
                maxr=max(maxr,ht[r]);
                ans+=(maxr-ht[r]);
                r--;
            }
        }
        return ans;
    }
};
