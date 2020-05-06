//https://atcoder.jp/contests/past202004-open/tasks/past202004_m
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














int D, L, N, F[101010]; ll T[101010];
vector<int> days[101010];
vector<int> humans[101010];
ll ans[101010];
//---------------------------------------------------------------------------------------------------
pair<ll, int> dp[31][101010];
void solve(int dish) {
	int n = days[dish].size();

	if (n == 0) return;

	rep(i, 0, n) {
		int j = (i + 1) % n;
		int d = days[dish][j] - days[dish][i];
		if (d <= 0) d += D;

		int cnt = 1 + (d - 1) / L;
		dp[0][i] = { cnt, j };
	}
	rep(p, 1, 31) rep(i, 0, n) {
		auto pa = dp[p - 1][i];
		auto pa2 = dp[p - 1][pa.second];
		dp[p][i] = { pa.first + pa2.first, pa2.second };
	}

	fore(h, humans[dish]) {
		int x = F[h] % D;
		auto ite = lower_bound(all(days[dish]), x);

		if (ite != days[dish].end() && *ite == x) ans[h]++;
		T[h]--;

		ite = upper_bound(all(days[dish]), x);

		int d = 0, cu = 0;
		if (ite == days[dish].end()) d = D - x + days[dish][0];
		else d = *ite - x, cu = ite - days[dish].begin();

		T[h] -= (d - 1) / L;
		if (T[h] <= 0) continue;
		T[h]--;
		ans[h]++;

		rrep(p, 30, 0) {
			auto pa = dp[p][cu];
			if (pa.first <= T[h]) {
				ans[h] += 1 << p;
				T[h] -= pa.first;
				cu = pa.second;
			}
		}
	}
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> D >> L >> N;
	rep(i, 0, D) {
		int C; cin >> C;
		days[C].push_back(i);
	}
	rep(i, 0, N) {
		int K; cin >> K >> F[i] >> T[i];
		F[i]--;
		humans[K].push_back(i);
	}

	rep(dish, 1, 101010) solve(dish);
	rep(i, 0, N) printf("%d\n", ans[i]);
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
問題をパッとみて、実装を頑張るような印象を受ける。
実際、実装を頑張るような問題は一定数あり、問題は「実装が簡単になるような方針を選ぶ」ことである。
実装が重い方針を選ぶと途中で挫折したり、こんなの絶対解けないよ…となる場合がある。

ダブリングで解いていこう（唐突）。
最初、二分探索でやろうとしてて大爆死した。
ダブリングね。なるほど。
ダブリングのもう少し簡単な問題で経験を積んでから、この問題に帰ってくるといいかもしれない。

今回料理がD種類あるが、料理毎に独立に答えを導けるので、料理毎に問題を解いていくことにしよう。
days[d] := 料理dについて提供される日付の配列
humans[d] := 料理dを好む人の配列
これをあらかじめ用意しておき、これ使って料理毎に問題を解く。

高速に処理していくための性質として、以下の性質がある。
- D日毎に料理dが出てくる日付が決まっている
- 今回答えるのは好みの料理を食べる回数なので、料理dが出てくる日付に注目して考えればいい
この辺をうまく使うためにダブリングを作ろう
dp[p][i] := i番目に出てくる料理dを最後に食べてから、2^p回料理dを食べたときの(食堂の利用回数, 最後に何番目の料理dを食べたか)
これをダブリングで構築していく。
あとは、2^pのpを大きい順から食堂の利用回数がT[j]回を超えないように続けていけば、何回料理dを食べたかが分かる。

注意点としては最初に食べる日付が既に好みの料理だった場合とか、色々境界がやばそう。
根性デバッグしていくしかない。
///////////////////////// writeup2 end */
