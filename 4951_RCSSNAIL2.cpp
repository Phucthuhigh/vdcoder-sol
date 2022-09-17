// RCSSNAIL2

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using pii = pair<long long, long long>;
long dx[4] = {0, -1, 0, 1};
long dy[4] = {-1, 0, 1, 0};
long long m, n;
vector< vector<bool> > mark;
bool validcell(long long x, long long y) 
{
   return (x > -1 && y > -1 && x < m && y < n);
}
long long bfs(long long x, long long y)
{
   long long res = 1;
   queue<pii> q;
   q.push(pii(x, y));
   mark[x][y] = true;
   while (!q.empty())
   {
      x = q.front().first, y = q.front().second;
      q.pop();
      for (long i = 0; i < 4; ++i)
      {
         long r = x + dx[i], c = y + dy[i];
         if (validcell(r, c) && !mark[r][c])
         {
            ++res;
            q.push(pii(r, c));
            mark[r][c] = true;
         }
      }
   }
   return res;
}
int main()
{
   cin >> m >> n;
   mark.resize(m);
   for(long i = 0; i < m; ++i)
   {
      mark[i].resize(n);
      for(long j = 0, tmp; j < n; ++j) 
      {
         cin >> tmp;
         mark[i][j] = tmp;
      }
   }
   long long max = 0;
   for (long i = 0; i < m; ++i)
   {
      for (long j = 0; j < n; ++j)
      {
         if (!mark[i][j])
         {
            long long tmp = bfs(i, j);
            if (max < tmp) max = tmp;
         }
      }
   }
   cout << max;
   return 0;
}
    