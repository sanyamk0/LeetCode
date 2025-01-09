//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public: 
    int nthRoot(int n, int m) {
        int ans=-1;
        for(int i=1;i<=m;i++){
            if(pow(i,n)==m){
                ans=i;
            }else if(pow(i,n)>m){
                break;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        Solution ob;
        int ans = ob.nthRoot(n, m);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends