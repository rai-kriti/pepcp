class Solution {
public:
int dfs(int node , vector<vector<int>> &adj , vector<int> &visited ,int &edgessum){
        visited[node] = 1;
        edgessum +=  adj[node].size();

        int currnodes =1;

        for( int nei :  adj[node]){
            if(!visited[nei]){
                currnodes += dfs(nei , adj , visited, edgessum);
            }
        }

        return currnodes;
}
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto &ed : edges){
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }
        int ans =0 ;
        vector<int> visited(n , 0);
        for(int i=0 ; i<n ; i++){
            if(visited[i]) continue;

            int edgessum =0;
            int nodes =  dfs(i , adj , visited , edgessum);

           edgessum  =  edgessum/2;

            if(edgessum == nodes*(nodes-1)/2 ) 
                ans++  ;
        }
        
    return ans;
    }

};