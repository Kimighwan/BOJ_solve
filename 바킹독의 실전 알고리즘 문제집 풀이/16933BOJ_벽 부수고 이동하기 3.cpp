#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int k, n, m;
string map[1002];
int dist[12][1002][1002][2]; // �� : 0 // �� : 1
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		cin >> map[i];

	dist[0][0][0][0] = 1;
	queue<tuple<int, int, int, int>> q;
	q.push({ 0, 0, 0, 0 });

	while (!q.empty())
	{
		int curx, cury, curk, curt;
		tie(curk, curx, cury, curt) = q.front();
		q.pop();
		if (curx == n - 1 && cury == m - 1)
		{
			cout << dist[curk][curx][cury][curt];
			return 0;
		}
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = curx + dx[dir];
			int ny = cury + dx[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

			if (map[nx][ny] == '0')
			{
				int nt = 1 - curt;
				int nk = curk;
				if (dist[nk][nx][ny][nt] > 0) continue;
				dist[nk][nx][ny][nt] = dist[curk][curx][cury][curt] + 1;
				q.push({ nk, nx, ny, nt });
			}
			else // ���� ���
			{
				if (curk == k) continue; // �� �̻� �� ��

				if (curt == 0) // ���̶� �� ���� �̵�
				{
					int nt = 1 - curt;
					int nk = curk + 1;
					if (dist[nk][nx][ny][nt] > 0) continue;
					dist[nk][nx][ny][nt] = dist[curk][curx][cury][curt] + 1;
					q.push({ nk, nx, ny, nt });
				}
				else // ���̶� ���� ��ٷ��� ��
				{
					int nt = 1 - curt;
					if (dist[curk][curx][cury][nt] > 0) continue;
					dist[curk][curx][cury][nt] = dist[curk][curx][cury][curt] + 1;
					q.push({ curk, curx, cury, nt });
				}
			}

		}
	}
	cout << -1;
}