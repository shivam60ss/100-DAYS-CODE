//this is leetcode problem no 947 ,
//most stones removed with same row and column. this problem solved using dfs 
//link -https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/?envType=daily-question&envId=2024-08-29

class Solution {
public:
void dfs(vector<vector<int>>& stones,int index,vector<bool>& visited){
    visited[index]= true;

    for(int i=0;i<stones.size();i++){
        int r = stones[index][0];
        int c = stones[index][1];

        if((visited[i]==false) && (stones[i][0]==r || stones[i][1]==c)){
            dfs( stones,i,visited);
        }
    }
}
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> visited(n,false);

        int group = 0;
        for(int i = 0;i<n;i++){
            if( visited[i]==true) //skipp
            continue;

            dfs(stones,i ,visited);
            group++;

        }
        return (n - group);  
        
    }
};