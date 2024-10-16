class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> maxHeap;
        if (a > 0)
            maxHeap.push({a, 'a'});
        if (b > 0)
            maxHeap.push({b, 'b'});
        if (c > 0)
            maxHeap.push({c, 'c'});
        string result = "";
        while (!maxHeap.empty()) {
            auto first = maxHeap.top();
            maxHeap.pop();
            if (result.size() >= 2 && result.back() == first.second &&
                result[result.size() - 2] == first.second) {
                if (maxHeap.empty())
                    break;
                auto second = maxHeap.top();
                maxHeap.pop();
                result += second.second;
                if (--second.first > 0)
                    maxHeap.push(second);
                maxHeap.push(first);
            } else {
                result += first.second;
                if (--first.first > 0)
                    maxHeap.push(first);
            }
        }
        return result;
    }
};