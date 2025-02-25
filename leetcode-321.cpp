#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool cmp(vector<int>& a, int pa, vector<int>& b, int pb)
    {
        int i = 0;
        while (true)
        {
            if (pb + i >= b.size())
                return false;
            if (pa + i >= a.size())
                return true;
            if (a[pa + i] > b[pb + i])
                return false;
            if (a[pa + i] < b[pb + i])
                return true;
            i++;
        }
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k)
    {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int> > maxN(n + 1), maxM(m + 1);
        for (int i = 0; i <= n; i++)
        {
            vector<int> st;
            for (int j = 0; j < n; j++)
            {
                while (st.size() > 0 && st.back() < nums1[j] && n - j > i - (int)st.size())
                    st.pop_back();
                st.push_back(nums1[j]);
            }
            for (int j = 0; j < i; j++)
                maxN[i].push_back(st[j]);
        }
        for (int i = 0; i <= m; i++)
        {
            vector<int> st;
            for (int j = 0; j < m; j++)
            {
                while (st.size() > 0 && st.back() < nums2[j] && m - j > i - (int)st.size())
                    st.pop_back();
                st.push_back(nums2[j]);
            }
            for (int j = 0; j < i; j++)
                maxM[i].push_back(st[j]);
        }
        vector<vector<int> > ans(k + 1);
        for (int i = max(k - m, 0); i <= min(k, n); i++)
        {
            int ii = k - i, cn = 0;
            for (int j = 0; j < i; j++)
            {
                while (cn < ii && cmp(maxN[i], j, maxM[ii], cn))
                {
                    ans[i].push_back(maxM[ii][cn]);
                    cn++;
                }
                ans[i].push_back(maxN[i][j]);
            }
            while (cn < ii)
            {
                ans[i].push_back(maxM[ii][cn]);
                cn++;
            }
        }
        vector<int> an;
        for (int i = 0; i <= k; i++)
        {
            if (ans[i].empty())
                continue;
            if (cmp(an, 0, ans[i], 0))
                an = ans[i];
        }
        return an;
    }
};
int main()
{
    Solution a;
    vector<int> v1 = {2, 5, 6, 4, 4, 0}, v2 = {7, 3, 8, 0, 6, 5, 7, 6, 2};
    int k = 15;
    vector<int> v = a.maxNumber(v1, v2, k);
    for (auto h : v)
        cout << h << " ";
    return 0;
}
