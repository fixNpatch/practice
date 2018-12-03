#include <cassert>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iomanip>
#include <cstdlib>
#include <climits>

using namespace std;

bool t(long double x, int n, vector <pair<int, int>> &vec)
{
    long double max_way = numeric_limits<long double>::lowest();
    long double pos;
    for (int i = 0; i < n; i++)
    {
        if (vec[i].second >= 0.0)
        {
            if (vec[i].first + x*vec[i].second > max_way)
            {
                max_way = vec[i].first + x*vec[i].second;
                //pos = vec[i].first;
            }
        }
        else
        {
            //if (max_way != numeric_limits<long double>::lowest() && vec[i].first >= pos)
            {
                if (vec[i].first + x*vec[i].second <= max_way)
                    return false;
            }
        }
    }
    return true;
}

long double binary_search(int n, vector <pair<int, int>> &vec)
{
    long double l = 0;
    long double r = 1000000000;
    for (int i = 0; i < 100; i++)
    {
        long double mid = l + (r - l)/2;
        if (t(mid, n, vec))
            l = mid;
        else
            r = mid;
    }
    return l + (r - l)/2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector <pair<int, int>> vec(n);
    vector <pair<int, int>> plus;
    vector <pair<int, int>> minus;
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i].first >> vec[i].second;
        if (vec[i].second < 0.0)
            minus.push_back(vec[i]);
        else
            plus.push_back(vec[i]);
    }
    if (minus.size() == 0 || plus.size() == 0 || (minus[minus.size() - 1].first < plus[0].first))
    {
        cout << -1 << endl;
        return 0;
    }
    cout << fixed << setprecision(12) << binary_search(n, vec) << endl;
    return 0;
}
