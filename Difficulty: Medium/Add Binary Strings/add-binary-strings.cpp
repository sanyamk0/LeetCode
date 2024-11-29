//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        string result = "";
        int i = s1.size() - 1, j = s2.size() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            int bit1 = (i >= 0) ? s1[i--] - '0' : 0;
            int bit2 = (j >= 0) ? s2[j--] - '0' : 0;
            int sum = bit1 + bit2 + carry;
            result += (sum % 2) + '0';  
            carry = sum / 2;           
        }
        reverse(result.begin(), result.end()); 
        int count=0;
        while(result[count]=='0')
            count++;
        result.erase(0,count++);
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends