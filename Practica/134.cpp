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

using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   int l, n;
   cin >> l >> n;
   vector <int> vec(l, 0);
   int p = sqrt(l) + 1;
   vector <int> b(p);
   int left, right, color;
   for (int i = 0; i < n; i++)
   {
       cin >> left >> right >> color;
       right--;
       for (int j = left; j <= right;)
       {
           if (j % p == 0 && j + p - 1 <= right)
           {
               b[j/p] = color;
               j += p;
           }
           else
           {
               if (b[j/p] >= 0)
               {
                   for (int k = j/p*p; k < min(j/p*p+p, l); k++)
                       vec[k] = b[j/p];
                   b[j/p] = -1;
               }
               vec[j++] = color;
           }
       }
   }
   for (int i = 0; i < l; i++)
   {
       if (b[i/p] != -1)
           vec[i] = b[i/p];
       cout << vec[i] << " ";
   }
   cout << endl;
   return 0;
}
