class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) 
    {
        vector<pair<int, int>> indexed_arr;
        for (int i = 0; i < arr.size(); i++) indexed_arr.push_back({arr[i], i});
        sort(indexed_arr.begin(), indexed_arr.end());
        vector<int> ans;
        int start=0;
        int end=arr.size()-1;
        while(start<end)
        {
            if(indexed_arr[start].first + indexed_arr[end].first == target){
                ans.push_back(indexed_arr[start].second);
                ans.push_back(indexed_arr[end].second);
                break;
            }
            else if (indexed_arr[start].first + indexed_arr[end].first > target){
                end--;
            }
            else start++;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};