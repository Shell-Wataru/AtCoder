#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>
#include <boost/multiprecision/cpp_int.hpp>
#include <set>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;
ll BASE_NUM = 1000000007;

int solve_linear_equation(double a11, double a12, double a21, double a22, double b1, double b2, double &x1, double &x2)
{
    double det = a11 * a22 - a12 * a21;
    if (det == 0)
    {
        // cout << a11 << a12 << a21 << a22 << endl;
        return 0;
    }
    else
    {
        x1 = 1.0 * (a22 * b1 - a12 * b2) / det;
        x2 = 1.0 * (-a21 * b1 + a11 * b2) / det;
        return 1;
    }
}

double distance(pair<double, double> &p1, pair<double, double> &p2)
{
    double diff_x = p1.first - p2.first;
    double diff_y = p1.second - p2.second;
    return sqrt(diff_x * diff_x + diff_y * diff_y);
};
int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<pair<double, double>> points;
    for (int i = 0; i < N; i++)
    {
        double x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }
    double min_r = 10000;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            double center_x = (points[i].first + points[j].first) / 2;
            double center_y = (points[i].second + points[j].second) / 2;
            pair<double, double> center{center_x, center_y};
            double r = distance(center, points[i]);
            bool is_all_contains = true;
            for (auto p : points)
            {
                if (distance(center, p) > r)
                {
                    is_all_contains = false;
                    break;
                }
            }

            if (is_all_contains)
            {
                min_r = min(min_r, r);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                double c_ij = points[i].first * points[i].first - points[j].first * points[j].first + points[i].second * points[i].second - points[j].second * points[j].second;
                double c_ik = points[i].first * points[i].first - points[k].first * points[k].first + points[i].second * points[i].second - points[k].second * points[k].second;
                c_ij = c_ij / 2;
                c_ik = c_ik / 2;
                double center_x, center_y;
                int solved = solve_linear_equation(points[i].first - points[j].first, points[i].second - points[j].second,
                                                   points[i].first - points[k].first, points[i].second - points[k].second,
                                                   c_ij, c_ik, center_x, center_y);
                if (!solved)
                {
                    center_x = (max(max(points[i].first, points[j].first), points[k].first) + min(min(points[i].first, points[j].first), points[k].first)) / 2;
                    center_y = (max(max(points[i].second, points[j].second), points[k].second) + min(min(points[i].second, points[j].second), points[k].second)) / 2;
                }
                pair<double, double> center{center_x, center_y};
                double r = distance(center, points[i]);
                bool is_all_contains = true;
                for (auto p : points)
                {
                    if (distance(center, p) > r)
                    {
                        is_all_contains = false;
                        break;
                    }
                }

                if (is_all_contains)
                {
                    min_r = min(min_r, r);
                }
            }
        }
    }
    cout << fixed << setprecision(14) << min_r << endl;
    return 0;
}