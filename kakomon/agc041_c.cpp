#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <climits>
using namespace std;
using ll = long long;

void write3_1(vector<string> &G, ll x,ll y)
{
    G[x + 0][y + 0] = 'x';
    G[x + 0][y + 1] = 'x';
    G[x + 1][y + 2] = 'y';
    G[x + 2][y + 2] = 'y';
}

void write3_2(vector<string> &G, ll x,ll y)
{
        G[x + 0][y + 0] = 'x';
        G[x + 0][y + 1] = 'x';
        G[x + 0][y + 2] = 'y';
        G[x + 1][y + 2] = 'y';
        G[x + 2][y + 2] = 'z';
        G[x + 2][y + 1] = 'z';
        G[x + 2][y + 0] = 'w';
        G[x + 1][y + 0] = 'w';
}
void write4_3(vector<string> &G, ll x,ll y)
{
        G[x + 0][y + 0] = 'a';
        G[x + 0][y + 1] = 'a';
        G[x + 1][y + 0] = 'b';
        G[x + 1][y + 1] = 'b';
        G[x + 2][y + 0] = 'c';
        G[x + 3][y + 0] = 'c';
        G[x + 2][y + 1] = 'd';
        G[x + 3][y + 1] = 'd';
        G[x + 0][y + 2] = 'e';
        G[x + 1][y + 2] = 'e';
        G[x + 0][y + 3] = 'f';
        G[x + 1][y + 3] = 'f';
        G[x + 2][y + 2] = 'g';
        G[x + 2][y + 3] = 'g';
        G[x + 3][y + 2] = 'h';
        G[x + 3][y + 3] = 'h';
}

void write5_3(vector<string> &G, ll x,ll y)
{
        G[x + 0][y + 0] = 'a';
        G[x + 0][y + 1] = 'a';
        G[x + 1][y + 0] = 'b';
        G[x + 1][y + 1] = 'b';
        G[x + 2][y + 0] = 'c';
        G[x + 2][y + 1] = 'c';

        G[x + 3][y + 2] = 'd';
        G[x + 4][y + 2] = 'd';
        G[x + 3][y + 3] = 'e';
        G[x + 4][y + 3] = 'e';
        G[x + 3][y + 4] = 'f';
        G[x + 4][y + 4] = 'f';
        write3_2(G,x,y+2);
}

void write7_3(vector<string> &G, ll x,ll y)
{
        G[x + 0][y + 0] = 'a';
        G[x + 0][y + 1] = 'a';
        G[x + 1][y + 0] = 'b';
        G[x + 1][y + 1] = 'b';
        G[x + 2][y + 0] = 'c';
        G[x + 2][y + 1] = 'c';

        G[x + 0][y + 2] = 'd';
        G[x + 0][y + 3] = 'd';
        G[x + 1][y + 2] = 'e';
        G[x + 1][y + 3] = 'e';
        G[x + 2][y + 2] = 'f';
        G[x + 2][y + 3] = 'f';

        G[x + 3][y + 4] = 'a';
        G[x + 4][y + 4] = 'a';
        G[x + 3][y + 5] = 'b';
        G[x + 4][y + 5] = 'b';
        G[x + 3][y + 6] = 'c';
        G[x + 4][y + 6] = 'c';

        G[x + 5][y + 4] = 'd';
        G[x + 6][y + 4] = 'd';
        G[x + 5][y + 5] = 'e';
        G[x + 6][y + 5] = 'e';
        G[x + 5][y + 6] = 'f';
        G[x + 6][y + 6] = 'f';
        write3_1(G,x,y+4);
}

int solve()
{
    ll N;
    cin >> N;
    if (N == 2)
    {
        cout << -1 << endl;
        return 0;
    }
    vector<string> Answer(N, string(N, '.'));
    ll current = 0;
    while (current < N)
    {
        if (N % 3 == 0)
        {
            write3_1(Answer, current,current);
            current += 3;
        }
        else if (N - current == 10)
        {
            write5_3(Answer, current,current);
            current += 5;
        }else if (N - current == 8)
        {
            write4_3(Answer, current,current);
            current += 4;
        }else if (N - current == 7)
        {
            write7_3(Answer, current,current);
            current += 7;
        }else if (N - current == 5){
            write5_3(Answer, current,current);
            current += 5;
        }else if (N - current == 4){
            write4_3(Answer, current,current);
            current += 4;
        }else{
            write4_3(Answer, current,current);
            current += 4;
        }
    }
    for (auto a : Answer)
    {
        cout << a << endl;
    }
    return 0;
}
int main()
{
    // // 整数の入力
    //   ll t;
    //   cin >> t;
    //   for (size_t i = 0; i < t; i++)
    //   {
    solve();
    //   }
    //   cout << flush;
    return 0;
}
