class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() == 0)
            return 0;
        int low = prices[0], result = 0;
        for (const auto &price : prices)
        {
            low = min(low, price);
            result = max(result, price - low);
        }
        return result;
    }
};