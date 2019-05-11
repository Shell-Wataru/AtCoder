#include <iostream>
#include <queue>

using namespace std;
struct dish
{
    long long A;
    long long B;
};

int main()
{
    // 整数の入力
    long long N, K, i, a_i, b_i, sumA, sumB;
    sumA = 0LL;
    sumB = 0LL;
    auto c = [](dish p1, dish p2) {
        return (p1.A + p1.B) < (p2.A + p2.B);
    };

    priority_queue<dish, vector<dish>, decltype(c)> q1(c);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> a_i >> b_i;
        q1.push({a_i, b_i});
    }

    for (int i = 0; i < N; i++)
    {
        if (i % 2 == 0)
        {
            dish d = q1.top();
            sumA += d.A;
            q1.pop();
        }
        else
        {
            dish d = q1.top();
            sumB += d.B;
            q1.pop();
        }
    }
    cout << sumA - sumB << endl;

    return 0;
}