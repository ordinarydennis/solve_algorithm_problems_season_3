class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {

        std::unordered_map<int, int> m;

        for (int n : nums)
        {
            m[n]++;
        }

        auto l = [](vector<int>& a, vector<int>& b) {

            return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);

        };

        std::priority_queue<vector<int>, vector<vector<int>>, decltype(l)> pq;

        for (const auto& [n, count] : m)
        {
            pq.push({ count, n });
        }

        while (k && 1 < pq.size())
        {
            auto v1 = pq.top();

            pq.pop();

            auto v2 = pq.top();

            pq.pop();

            int d = v1[1] - v2[1];

            if (d <= k)
            {
                k -= d;
                pq.push({ v1[0] + v2[0], v1[1] });
            }
            else
            {
                break;
            }
        }

        auto r = pq.top();

        return r[0];
    }
};
