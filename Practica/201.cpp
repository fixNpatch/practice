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

unsigned long long hashcode(int i, int m, int A, string &str)
{
	unsigned long long res = 0;
	unsigned long long B = 1;
	for (int j = i + m - 1; j >= i; j--)
	{
		res += B * str[j];
		B *= A;
	}
	return res;
}

unsigned long long power(int A, int m)
{
	unsigned long long B = 1;
	for (int i = 0; i < m; i++)
		B *= A;
	return B;
}

int main()
{
    ios_base::sync_with_stdio(false);
    string p, str;
	cin >> p;
	cin >> str;
	unsigned long long A = 31;
	int size_p = p.length();
	int size_str = str.length();
	if (size_p > size_str)
		return 0;
	vector <int> ans;
	unsigned long long hash_p = hashcode(0, size_p, A, p);
	unsigned long long hash = hashcode(0, size_p, A, str);
	if (hash == hash_p)
		ans.push_back(0);
	unsigned long long power_A = power(A, size_p - 1);
	for (int i = 1; i < size_str - size_p + 1; i++)
	{
		hash = (hash - power_A * str[i - 1]) * A + str[i + size_p - 1];
		if (hash == hash_p)
			ans.push_back(i);
	}
	if (ans.size() != 0)
	{
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] + 1 << " ";
		cout << endl;
	}
    return 0;
}
