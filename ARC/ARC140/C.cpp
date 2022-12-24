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

using namespace std;
using ll = long long;

int main()
{
  ll N, X;
  cin >> N >> X;
  if (N % 2 == 0)
  {
    if (X == N / 2)
    {
      cout << X;
      for (int i = 1; i <= N - 1; i++)
      {
        if (i % 2 == 1)
        {
          X += i;
        }
        else
        {
          X -= i;
        }
        cout << " " << X;
      }
      cout << endl;
    }
    else if (X == N / 2 + 1)
    {
      cout << X;
      for (int i = 1; i <= N - 1; i++)
      {
        if (i % 2 == 1)
        {
          X -= i;
        }
        else
        {
          X += i;
        }
        cout << " " << X;
      }
      cout << endl;
    }
    else if (X > N / 2 + 1)
    {
      cout << X;
      ll current = N/ 2;
      ll iter = 0;
      cout << " " << current;
      for (int i = 1; i <= N - 1; i++)
      {
        if (iter % 2 == 0)
        {
          current -= i;
        }
        else
        {
          current += i;
        }
        if (current == X)
        {
          current++;
          i++;
        }
        iter++;
        if (1 <= current && current <= N)
        {
          cout << " " << current;
        }
      }
      cout << endl;
    }
    else
    {
      cout << X;
      ll current = N/ 2 + 1;
      ll iter = 0;
      cout << " " << current;
      for (int i = 1; i <= N - 1; i++)
      {
        if (iter % 2 == 0)
        {
          current += i;
        }
        else
        {
          current -= i;
        }
        if (current == X)
        {
          current--;
          i++;
        }
        iter++;
        if (1 <= current && current <= N)
        {
          cout << " " << current;
        }
      }
      cout << endl;
    }
  }
  else
  {
    if (X == (N + 1) / 2)
    {
      cout << X;
      for (int i = 1; i <= N - 1; i++)
      {
        if (i % 2 == 1)
        {
          X += i;
        }
        else
        {
          X -= i;
        }
        cout << " " << X;
      }
      cout << endl;
    }
    else if (X > (N + 1) / 2)
    {
      cout << X;
      ll current = (N + 1) / 2;
      ll iter = 0;
      cout << " " << current;
      for (int i = 1; i <= N - 1; i++)
      {
        if (iter % 2 == 0)
        {
          current -= i;
        }
        else
        {
          current += i;
        }
        if (current == X)
        {
          current++;
          i++;
        }
        iter++;
        if (1 <= current && current <= N)
        {
          cout << " " << current;
        }
      }
      cout << endl;
    }
    else
    {
      cout << X;
      ll current = (N + 1) / 2;
      ll iter = 0;
      cout << " " << current;
      for (int i = 1; i <= N - 1; i++)
      {
        if (iter % 2 == 0)
        {
          current += i;
        }
        else
        {
          current -= i;
        }
        if (current == X)
        {
          current--;
          i++;
        }
        iter++;
        if (1 <= current && current <= N)
        {
          cout << " " << current;
        }
      }
      cout << endl;
    }
  }
  return 0;
}
