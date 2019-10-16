/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 *
 * https://leetcode.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (43.05%)
 * Likes:    1161
 * Dislikes: 48
 * Total Accepted:    185.2K
 * Total Submissions: 429.8K
 * Testcase Example:  '"aab"'
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome.
 * 
 * Return all possible palindrome partitioning of s.
 * 
 * Example:
 * 
 * 
 * Input: "aab"
 * Output:
 * [
 * ⁠ ["aa","b"],
 * ⁠ ["a","a","b"]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>out;
        helper(s,0,out,res);
        return res;
    }
    void helper(string s, int start, vector<string>& out, vector<vector<string>>& res)
    {
        if(start == s.size()){res.push_back(out); return;}
        for(int i = start; i < s.size();i++)
        {
            if(!ispalindorme(s,start, i))continue;
            out.push_back(s.substr(start,i-start+1));
            helper(s,i+1,out,res);
            out.pop_back();
        }
    }
    bool ispalindorme(string s,int start, int end)
    {
        while (start < end) {
            if (s[start] != s[end]) return false;
            ++start; --end;
        }
        return true;
    }
};
// @lc code=end

