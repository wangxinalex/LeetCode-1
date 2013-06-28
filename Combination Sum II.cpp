class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int>& num, int target)
    {
        sort(num.begin(), num.end());
        
        vector<vector<int>> result;
        vector<vector<int>> combination({{}});
        for (int n : num)
        {
            size_t count = combination.size();
            for (size_t i = 0; i < count; ++i)
            {
                int sum = accumulate(combination[i].begin(), combination[i].end(), 0);
                if (sum + n < target)
                {
                    combination.push_back(combination[i]);
                    combination.back().push_back(n);
                }
                else if (sum + n == target)
                {
                    result.push_back(combination[i]);
                    result.back().push_back(n);
                }
            }
        }
        
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        
        return result;
    }
};
