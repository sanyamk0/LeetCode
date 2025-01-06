class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        istringstream iss1(s1);
        deque<string> deque1((istream_iterator<string>(iss1)),
                             istream_iterator<string>());
        istringstream iss2(s2);
        deque<string> deque2((istream_iterator<string>(iss2)),
                             istream_iterator<string>());
        while (!deque1.empty() && !deque2.empty() &&
               deque1.front() == deque2.front()) {
            deque1.pop_front();
            deque2.pop_front();
        }
        while (!deque1.empty() && !deque2.empty() &&
               deque1.back() == deque2.back()) {
            deque1.pop_back();
            deque2.pop_back();
        }
        return deque1.empty() || deque2.empty();
    }
};