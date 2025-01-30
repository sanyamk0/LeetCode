class Solution {
public:
    typedef pair<int,int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // int n=nums.size();
        vector<int>ans;
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        //1->3
        //2->2
        //3->1
        priority_queue<P,vector<P>,greater<P>>pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};