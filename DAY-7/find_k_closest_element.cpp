link --https://leetcode.com/problems/find-k-closest-elements/description/

// leetcode program number-658
find_k_closest_element_

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> pq;

        for(auto y:arr){
            pq.push({abs(y-x),y});
            if(pq.size()>k){
                pq.pop();

            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);

            pq.pop();

        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};