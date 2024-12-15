//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int n=a.size(),m=b.size();
        int i=0,j=0,index=0;
        vector<int>merge(n+m);
        while(i<n&&j<m){
            if(a[i]<b[j]){
                merge[index]=a[i];
                i++;
                index++;
            }else{
                merge[index]=b[j];
                j++;
                index++;
            }
        }
        while(i<n){
            merge[index]=a[i];
            i++;
            index++;
        }
        while(j<m){
            merge[index]=b[j];
            j++;
            index++;
        }
        return merge[k-1];
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends