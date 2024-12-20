//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        vector<int> result;
        if (mat.empty()) return result;
        int top = 0, bottom = mat.size() - 1;
        int left = 0, right = mat[0].size() - 1;
        while (top <= bottom && left <= right) {
            for (int col = left; col <= right; ++col)
                result.push_back(mat[top][col]);
            top++;
            for (int row = top; row <= bottom; ++row)
                result.push_back(mat[row][right]);
            right--;
            if (top <= bottom) {
                for (int col = right; col >= left; --col)
                    result.push_back(mat[bottom][col]);
                bottom--;
            }
            if (left <= right) {
                for (int row = bottom; row >= top; --row)
                    result.push_back(mat[row][left]);
                left++;
            }
        }
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends