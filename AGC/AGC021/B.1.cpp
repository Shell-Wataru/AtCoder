#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <math.h>
using namespace std;

double EPS = 1e-10;
double add(double a, double b)
{
    if (abs(a + b) < EPS * (abs(a) + abs(b)))
        return 0;
    return a + b;
}

struct P
{
    double x, y;
    P() {}
    P(double x, double y) : x(x), y(y) {}
    P operator+(P p)
    {
        return P(add(x, p.x), add(y, p.y));
    }
    P operator-(P p)
    {
        return P(add(x, -p.x), add(y, -p.y));
    }
    P operator*(double d)
    {
        return P(x * d, y * d);
    }
    double dot(P p)
    {
        return add(x * p.x, y * p.y);
    }
    double det(P p)
    {
        return add(x * p.y, -y * p.x);
    }
};

bool on_seg(P p1, P p2, P q)
{
    return (p1 - q).det(p2 - q) == 0 && (p1 - q).dot(p2 - q) <= 0;
}

P intersection(P p1, P p2, P q1, P q2)
{
    return p1 + (p2 - p1) * ((q2 - q1).det(q1 - p1) / (q2 - q1).det(q2 - p1));
}

int main()
{
    // 整数の入力
    long long N, x, y, i;
    vector<pair<long long, double>> data;
    cin >> N;
    double *prob = new double[N];
    for (i = 0; i < N; i++)
    {
        cin >> x >> y;
        if (x == 0)
        {
            data.push_back(make_pair(i, y / abs(y) * M_PI / 2));
        }
        else
        {
            data.push_back(make_pair(i, atan(y * 1.0 / x)));
        }
    }
    sort(data.begin(), data.end(), [](pair<long long, long long> a, pair<long long, long long> b) { return a.second > b.second; });
    for (i = 0; i < N; i++)
    {
        prob[data[i].first] = (abs(data[(i + 1) % N].second - data[i].second) / 2 + abs(data[(N + i - 1) % N].second - data[i].second) / 2) / M_PI;
    }

    for (i = 0; i < N; i++)
    {
        cout << prob[i] << endl;
    }
    return 0;
}