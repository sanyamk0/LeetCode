class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long, vector<long>, greater<long>> pq;
        unordered_set<long> seen;
        pq.push(1);
        seen.insert(1);
        long uglyNumber = 1;
        for (int i = 0; i < n; ++i) {
            uglyNumber = pq.top();
            pq.pop();
            if (seen.find(uglyNumber * 2) == seen.end()) {
                pq.push(uglyNumber * 2);
                seen.insert(uglyNumber * 2);
            }
            if (seen.find(uglyNumber * 3) == seen.end()) {
                pq.push(uglyNumber * 3);
                seen.insert(uglyNumber * 3);
            }
            if (seen.find(uglyNumber * 5) == seen.end()) {
                pq.push(uglyNumber * 5);
                seen.insert(uglyNumber * 5);
            }
        }
        return uglyNumber;
    }
};