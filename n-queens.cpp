#include <iostream>
#include <vector>
using namespace std;
int N;
struct queen
{
    int r;
    int c;
    queen(int i, int j)
    {
        this->r = i;
        this->c = j;
    }
    bool operator < (const queen& other)
    {
        if (this->r < other.r)
            return true;
        if (this->r > other.r)
            return false;
        if (this->c < other.c)
            return true;
        return false;
    }
    bool attack(const queen& other)
    {
        if (this->r == other.r)
            return true;
        if (this->c == other.c)
            return true;
        if (this->r + this->c == other.r + other.c)
            return true;
        if (this->r - this->c == other.r - other.c)
            return true;
        return false;
    }
};
void solve(vector<queen>& state)
{
    if (state.size() == N)
    {
        bool valid = true;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (state[j].attack(state[i]))
                    valid = false;
            }
        }
        if (valid)
        {
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    bool full = false;
                    for (auto q : state)
                    {
                        if (q.r == i && q.c == j)
                            full = true;
                    }
                    if (full)
                        cout << '#';
                    else
                        cout << '.';
                }
                cout << '\n';
            }
            cout << '\n' << '\n';
        }
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                queen Q(i, j);
                if (state.empty() || state.back() < Q)
                {
                    vector<queen> new_state = state;
                    new_state.push_back(Q);
                    solve(new_state);
                }
            }
        }
    }
}
int main()
{
    cin >> N;
    vector<queen> v;
    solve(v);
}
