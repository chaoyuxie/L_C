class Solution()
{
    public:
    vector<vector<int>> combinationSum2(vector<int> &num int target)
    {
        vector<vector<int>> result;
        sort(num.begin(),num.end());
        dfs(num, target, vector<int>{}, index, result);
        return result;
    }
    void dfs(vector<vector<int>>&num, int target, vector<int> curr, size_t index, vector<vector<int>> result)
    {
        if(!target)
        {
            result.push_back(curr);
            return;
        }
        for(auto i = index; i < num.size(); i++)
        {
            if(i > index && num[i]==num[i-1])continue;
            else if(num[i]<target)
            {
                curr.push_back(num[i]);
                dfs(num, target-num[i], curr, i+1, result);
                curr.pop_back();
            }
            else break;

        }
    }
};