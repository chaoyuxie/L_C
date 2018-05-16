class Solution
{
  public:
    vector<int> getRow(int k)
    {
        vector<int> ans(k + 1, 1);
        for (int i = 1; i <= k / 2; ++i)
        {
            ans[k - i] = ans[i] = long(ans[i - 1]) * (k - i + 1) / i;
        }
        return ans;
    }
};