class Solution {
public:
    const int MOD = 1e9 + 7;

    long long power(long long base, long long exponent) {
        long long res = 1;
        while (exponent > 0) {
            if (exponent % 2 == 1)
                res = ((res * base) % MOD);
            base = (base * base) % MOD;
            exponent /= 2;
        }
        return res;
    }

    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> primeScores(n);
        for (int index = 0; index < n; index++) {
            int num = nums[index];
            for (int factor = 2; factor <= sqrt(num); factor++) {
                if (num % factor == 0) {
                    primeScores[index]++;
                    while (num % factor == 0)
                        num /= factor;
                }
            }
            if (num >= 2)
                primeScores[index]++;
        }
        vector<int> nextDominant(n, n);
        vector<int> prevDominant(n, -1);
        stack<int> decreasingPrimeScoreStack;
        for (int index = 0; index < n; index++) {
            while (!decreasingPrimeScoreStack.empty() &&
                   primeScores[decreasingPrimeScoreStack.top()] <
                       primeScores[index]) {
                int topIndex = decreasingPrimeScoreStack.top();
                decreasingPrimeScoreStack.pop();
                nextDominant[topIndex] = index;
            }
            if (!decreasingPrimeScoreStack.empty())
                prevDominant[index] = decreasingPrimeScoreStack.top();
            decreasingPrimeScoreStack.push(index);
        }
        vector<long long> numOfSubarrays(n);
        for (int index = 0; index < n; index++)
            numOfSubarrays[index] = (long long)(nextDominant[index] - index) *
                                    (index - prevDominant[index]);
        priority_queue<pair<int, int>> processingQueue;
        for (int index = 0; index < n; index++)
            processingQueue.push({nums[index], index});
        long long score = 1;
        while (k > 0) {
            auto [num, index] = processingQueue.top();
            processingQueue.pop();
            long long operations = min((long long)k, numOfSubarrays[index]);
            score = (score * power(num, operations)) % MOD;
            k -= operations;
        }
        return score;
    }
};