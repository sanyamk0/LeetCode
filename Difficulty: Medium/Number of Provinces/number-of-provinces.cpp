//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, vis, adj);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        int n = adj.size(), provinces = 0;
        vector<vector<int>> adjLs(V);
        vector<int> vis(V, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(adj[i][j] == 1 && i != j){
                    adjLs[i].push_back(j);
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, vis, adjLs);
                provinces++;
            }
        }
        return provinces;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends