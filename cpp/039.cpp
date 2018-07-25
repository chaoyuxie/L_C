class Sloution(){
    public :
        vector<vector<int>>combinationSum(vector<int> & candidates, int target)
        {
            vector<vector<int>> result;
            sort(candidates.begin(), candidates.end());
            dfs(candidates, target, vector<int>{}, 0, result);
            return result;
        }

    void dfs(vector<int> &candidates, int target, vector<int> curr, size_t index, vector<vector<int>> &result)
    {
        if (target == 0)
        {
            result.push_back(curr);
            return;
        }
        for (int i = index; i < candidates.size(); i++)
        {
            if (candidates.[i] < target)
            {
                curr.push_back(candidates[i]);
                dfs(candidates, target - candidates[i], curr, i, result);
                curr.pop_back();
            }
            else break;
        }
    }
};