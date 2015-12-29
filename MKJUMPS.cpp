# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
# define MAX INT_MAX
# define pii pair<int, int>
# define rep(i, a, b) for(i = a; i < b; i++)
# define pb(x) push_back(x)
# define mem(arr, x) memset(arr, x, sizeof arr)
# define MOD 1000000007
inline void fastRead_int(int *a) {
    register char c=0;
    while (c<33) c=getchar_unlocked();
    *a=0;
    while (c>33) {
        *a=*a*10+c-'0';
        c=getchar_unlocked();
    }
}
struct node {
	int l, r;
}row[12];
int tr[] = {2, -2, 2, -2, -1, 1, 1, -1};
int tc[] = {1, -1, -1, 1, 2, -2, 2, -2};
int mx = -1, n, mark[13][13];
bool valid(int x, int y) {
	return x >= 0 && x < n && y >= row[x].l && y <= row[x].r;
}
void dfs(int x, int y, int c) {
	mx = max(c, mx);
	int nx, ny, i;
	rep(i, 0, 8) {
		nx = x+tr[i];
		ny = y+tc[i];
		if(valid(nx, ny) && !mark[nx][ny]) {
			mark[nx][ny] = 1;
			dfs(nx, ny, c+1);
			mark[nx][ny] = 0;
		}
	}
}
int main () {
	ios::sync_with_stdio(0);
	int count = 0;
	while(true) {
		mx = -1;
		mem(mark, 0);
		int i, l, r, total = 0, ans; cin >> n;
		if(!n) break;
		rep(i, 0, n) {
			cin >> l >> r;
			row[i].l = l;
			row[i].r = l+r-1;
			total += r;
		}
		mark[0][row[0].l] = 1;
		dfs(0, row[0].l, 1);
		ans = total-mx;
		if(ans == 1)
			cout << "Case "<< ++count << ", "<< ans << " square can not be reached."<< endl;
		else
			cout << "Case "<< ++count << ", "<< ans << " squares can not be reached."<< endl;
	}
}
