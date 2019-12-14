//https://codeforces.com/contest/1276/problem/C
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
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














int N, A[401010], ma[401010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> A[i];

	map<int, int> cnt;
	rep(i, 0, N) cnt[A[i]]++;

	map<int, int> cnt2;
	int kind = 0;
	fore(p, cnt) {
		cnt2[p.second]++;
		kind++;
	}

	ma[0] = 0;
	rep(i, 1, N + 1) {
		ma[i] = ma[i - 1] + kind;
		kind -= cnt2[i];
	}

	int H = -1, W = -1, tot = -1;
	rep(h, 1, N + 1) {
		int w = ma[h] / h;
		if (h <= w) {
			if (chmax(tot, w * h)) {
				H = h;
				W = w;
			}
		}
	}

	printf("%d\n%d %d\n", tot, H, W);

	vector<pair<int, int>> ps;
	fore(p, cnt) ps.push_back({ p.second, p.first });
	sort(all(ps), greater<pair<int, int>>());

	queue<int> que;
	fore(p, ps) rep(i, 0, min(p.first, H)) que.push(p.second);

	vector<vector<int>> ans(H, vector<int>(W, -1));
	rep(sx, 0, W) {
		int x = sx;
		rep(y, 0, H) {
			ans[y][x] = que.front();
			que.pop();
			x = (x + 1) % W;
		}
	}

	rep(y, 0, H) {
		rep(x, 0, W) {
			if (x) printf(" ");
			printf("%d", ans[y][x]);
		}
		printf("\n");
	}

}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
説明と実装を簡単にするために、答えの長さをH≦Wとしておこう。
まず、自明なこととして、同じ種類の数はH個しか使えないことが分かる。
こっからは、仮定だが、全ての種類についてH個以下になっていれば配置可能であるとする。
この辺は神頼み。

ma[h] := 同じ種類の数をh個しか使えないときに使える数の総数
これを頑張って作ろう。
自分はhを1から増やしていって、残っている数の種類を保持しておくことで、どれだけ増えるかを考えながら数えることにした

あとは、hを全探索する。
ma[h]個は使えるので最大のwはma[h]/hとなる。
これが前提として、h≦wを満たすものを取ってくる。

H,Wが決まったので、最後は構築だが、これは斜めに配置していく。
各種類の数についてH個以下で取ってきて、個数が多いものから順番に斜めに配置すると答え。
///////////////////////// writeup2 end */
