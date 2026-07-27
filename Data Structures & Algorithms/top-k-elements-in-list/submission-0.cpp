class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
          unordered_map<int,int> map;
          for(int i=0;i<nums.size();i++)
          {
            map[nums[i]]++;
          }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> heap;
        for(auto entry: map){
            heap.push({entry.second,entry.first});
            if(heap.size()>k) heap.pop();
        }

        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(heap.top().second);
            heap.pop();
        }
        return ans;
    }
};
