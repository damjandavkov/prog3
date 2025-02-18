class Solution
{
public:
    int maxArea(vector<int>& height)
    {
        int n = height.size(), low = n, high = -1, ans = 0;
        vector<pair<int, int> > sorted(n);
        for (int i = 0; i < n; i++)
            sorted[i] = {height[i], i};
        sort(sorted.begin(), sorted.end());
        for (int i = n - 1; i >= 0; i--)
        {
            low = min(low, sorted[i].second);
            high = max(high, sorted[i].second);
            ans = max(ans, max(sorted[i].second - low, high - sorted[i].second) * sorted[i].first);
        }
        return ans;
    }
};
