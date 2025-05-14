#include <iostream>
#include <string>
#include <vector>
using namespace std;
string lcs(string& a, string& b)
{
    int n = a.size(), m = b.size();
    vector<vector<int> > dp(n + 1);
    for (int i = 0; i <= n; i++)
    {
        dp[i].resize(m + 1);
        for (int j = 0; j <= m; j++)
        {
            if (!i || !j)
                dp[i][j] = 0;
            else if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    string ans = "";
    while (n && m)
    {
        if (a[n - 1] == b[m - 1])
        {
            ans.push_back(a[n - 1]);
            n--;
            m--;
        }
        else if (dp[n - 1][m] > dp[n][m - 1])
            n--;
        else
            m--;
    }
    return ans;
}
void diff(string& a, string& b)
{
    string LCS = lcs(a, b);
    int i = 0, j = 0;
    for (int k = LCS.size() - 1; k >= 0; k--)
    {
        while (i < a.size() && a[i] != LCS[k])
        {
            cout << '-' << a[i] << ' ';
            i++;
        }
        while (j < b.size() && b[j] != LCS[k])
        {
            cout << '+' << b[j] << ' ';
            j++;
        }
        cout << LCS[k] << ' ';
        i++;
        j++;
    }
    while (i < a.size())
    {
        cout << '-' << a[i] << ' ';
        i++;
    }
    while (j < b.size())
    {
        cout << '+' << b[j] << ' ';
        j++;
    }
}
int main()
{
    string a, b;
    cin >> a >> b;
    diff(a, b);
}
