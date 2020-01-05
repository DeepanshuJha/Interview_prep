/*
    Link - https://leetcode.com/problems/largest-divisible-subset/

    Problem - Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

             Si % Sj = 0 or Sj % Si = 0.

             If there are multiple solutions, return any subset is fine.

    Sol - Here we will use LIS approach, if we sort the array then if answer subset is
          considered then 
                    array -> [x1, x2, x3, x4, .....xn];

                    then xj % xi == 0 if(xj > xi)

                    so dp[i] -> length of subset

                        dp[i] = max(dp[i], dp[j] + 1) if(a[i] % a[j] == 0)

        Now we have to backtrack in order to print the elements of set.

    Complexity - O(n^2)

    Another approach is also there using sieve


*/
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return vector<int> {};
        sort(nums.begin(), nums.end());
        
        
        vector<int> dp(n, 1);
        vector<int> parent(n, -1); //backtrack parent
        int st = 0, mx = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0){
                    if(dp[i] < dp[j] + 1){
                        dp[i] = dp[j] + 1;
                        parent[i] = j;    // assigning parent
                    }
                    if(dp[i] > mx){
                        mx = dp[i]; 
                        st = i; // the last index which is having biggest set size
                    }
                }
            }
        }
        vector<int> ans;
        while(st != -1){
            ans.push_back(nums[st]);
            st = parent[st];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};