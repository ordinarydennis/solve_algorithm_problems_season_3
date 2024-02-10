class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0, maxSum = INT_MIN, curMax = 0, minSum = INT_MAX, curMin = 0;
        for (int x : nums) {
            curMax = max(x, curMax + x);  //update the current max subarray sum
            maxSum = max(maxSum, curMax); //update the overall max subarray sum
            curMin = min(x, curMin + x);  //update the current min subarray sum
            minSum = min(minSum, curMin); //update the overall min subarray sum
            totalSum += x;
        }
        return maxSum > 0 ? max(maxSum, totalSum - minSum) : maxSum;
    }
};



//https://leetcode.com/problems/maximum-sum-circular-subarray/solutions/3066098/kadane-algo-easy-video-explaination-o-n-o-1/