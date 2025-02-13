class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        for (int i = 0; i < abs(n); i++)
            ans *= x;
        if (n < 0)
            ans = 1 / ans;
        return ans;
    }
};