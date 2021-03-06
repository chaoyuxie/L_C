/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 *
 * https://leetcode.com/problems/interleaving-string/description/
 *
 * algorithms
 * Hard (29.15%)
 * Likes:    948
 * Dislikes: 53
 * Total Accepted:    124.8K
 * Total Submissions: 427.8K
 * Testcase Example:  '"aabcc"\n"dbbca"\n"aadbbcbcac"'
 *
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and
 * s2.
 * 
 * Example 1:
 * 
 * 
 * Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
 * Output: false
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size())return false;
        int n = s1.size(), m = s2.size();
        vector<vector<bool>>dp(n+1, vector<bool>(m+1));
        dp[0][0] = true;
        for(int i = 1; i <= n; ++i)
        {
            dp[i][0] = dp[i-1][0]&&(s1[i-1] == s3[i-1]);
        }
        for (int i = 1; i <= m; ++i) {
            dp[0][i] = dp[0][i - 1] && (s2[i - 1] == s3[i - 1]);
        }
        for(int i = 1; i <= n; i++)
        {
           for(int j = 1; j <= m; j++)
           {
               dp[i][j] = (dp[i-1][j] &&s1[i-1] == s3[i-1+j])||(dp[i][j-1] &&s2[j-1] == s3[j-1+i]);
           }
        }
        return dp[n][m];
    }
};
// @lc code=end

