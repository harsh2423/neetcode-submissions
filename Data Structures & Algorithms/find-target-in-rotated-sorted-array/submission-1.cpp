class Solution {
public:
    int search(vector<int>& ar, int target) 
    {
        int ans=0;
        int lo=0,hi=ar.size()-1;

        while(lo<=hi)
        {
            int mid=(lo+hi)/2;
            if(target==ar[mid]) return mid;
            if(ar[lo]<=ar[mid])
            {
                if(ar[lo]<=target && target<=ar[mid])hi=mid-1;
                else lo=mid+1;
            }
            else
            {
                if(ar[mid]<=target && target<=ar[hi])lo=mid+1;
                else hi=mid-1;
            }
        }
        return -1;
    }
};
