class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) 
    {
        vector<vector<int>> ans;
        sort(a.begin(),a.end());

        for(int i=0;i<a.size();i++)
        {
            if(a[i]>0) break;
            if(i>0 && a[i]==a[i-1]) continue;

            int l=i+1;
            int r=a.size()-1;
            while(l<r){
                int sum=a[i]+a[l]+a[r];
                if(sum==0){
                    ans.push_back({a[i],a[l],a[r]});
                    l++;
                    r--;
                    while(l<r && a[l]==a[l-1]) l++;
                }
                else if(sum>0) r--;
                else l++;
            }
        }
        return ans;
    }
};
