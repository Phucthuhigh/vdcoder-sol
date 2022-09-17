// RCSSNAIL1

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using pii = pair<long long, long long>;
long dx[4] = {0, -1, 0, 1};
long dy[4] = {-1, 0, 1, 0};
long long res = 1, m, n;
vector< vector<bool> > mark;
bool validcell(long long x, long long y) 
{
   return (x > -1 && y > -1 && x < m && y < n);
}
void bfs(long long x, long long y)
{
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
}
int main()
{
   long long x, y, tmp;
   cin >> m >> n >> x >> y;
   --x; --y;
   mark.resize(m);
   for(long i = 0; i < m; ++i)
   {
      mark[i].resize(n);
      for(long j = 0; j < n; ++j) 
      {
         cin >> tmp;
         mark[i][j] = tmp;
      }
   }
   bfs(x, y);
   cout << res;
   return 0;
}
    