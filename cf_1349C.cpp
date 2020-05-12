//https://codeforces.com/contest/1349/problem/C
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
//---------------------------------------------------------------------------------------------------
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/















int H, W, T;
string S[1010];
int st[1010][1010];
bool vis[1010][1010];
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { -1, 0, 1, 0 };
//---------------------------------------------------------------------------------------------------
char f(char c) {
	if (c == '0') return '1';
	return '0';
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> H >> W >> T;
	rep(y, 0, H) cin >> S[y];

	rep(y, 0, H) rep(x, 0, W) st[y][x] = -1;

	queue<pair<int, int>> que;
	rep(y, 0, H) rep(x, 0, W) {
		bool flip = false;
		rep(d, 0, 4) {
			int xx = x + dx[d];
			int yy = y + dy[d];
			if (0 <= xx && xx < W && 0 <= yy && yy < H) {
				if (S[y][x] == S[yy][xx]) flip = true;
			}
		}
		if (flip) {
			st[y][x] = 1;
			vis[y][x] = true;
			que.push({ x, y });
		}
	}

	while (!que.empty()) {
		auto q = que.front(); que.pop();

		int x, y; tie(x, y) = q;
		rep(d, 0, 4) {
			int xx = x + dx[d];
			int yy = y + dy[d];
			if (0 <= xx && xx < W && 0 <= yy && yy < H) {
				if (!vis[yy][xx]) {
					st[yy][xx] = st[y][x] + 1;
					vis[yy][xx] = true;
					que.push({ xx, yy });
				}
			}
		}
	}
	
	rep(_, 0, T) {
		int y, x; ll p;
		cin >> y >> x >> p;
		y--; x--;

		if(st[y][x] < 0) printf("%c\n", S[y][x]);
		else if (p < st[y][x]) printf("%c\n", S[y][x]);
		else {
			ll d = p - st[y][x];
			if(d % 2 == 1) printf("%c\n", S[y][x]);
			else printf("%c\n", f(S[y][x]));
		}
	}

	return;

	rep(y, 0, H) {
		rep(x, 0, W) {
			if(x) printf(" ");
			printf("%d", st[y][x]);
		}
		printf("\n");
	}
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
///////////////////////// writeup2 end */
