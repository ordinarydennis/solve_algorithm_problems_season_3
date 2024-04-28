#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        for (char c : s) 
            freq[c]++;

        auto cmp = [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second < b.second || (a.second == b.second && a.first > b.first);
            };

        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq(cmp);
        
        for (auto& p : freq) {
            if (p.second > (s.length() + 1) / 2) 
                return "";
            pq.push(p);
        }

        string result = "";
        while (pq.size() > 1)
        {
            auto top1 = pq.top(); 
            pq.pop();
            auto top2 = pq.top(); 
            pq.pop();

            result += top1.first;
            result += top2.first;

            if (--top1.second > 0) 
                pq.push(top1);
            if (--top2.second > 0) 
                pq.push(top2);
       
        }

        if (!pq.empty()) {
            auto last = pq.top();
            if (last.second > 1) 
                return "";
            result += last.first;
        }

        return result;
    }
};
