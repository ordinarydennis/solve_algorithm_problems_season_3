class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {

        int xMin = m;
        int yMin = n;

		for (int i = 0; i < ops.size(); i++)
        {
            xMin = std::min(xMin, ops[i][0]);
            yMin = std::min(yMin, ops[i][1]);
        }

        return xMin * yMin;
    }
};