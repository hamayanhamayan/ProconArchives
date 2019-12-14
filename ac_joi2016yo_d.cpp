//https://atcoder.jp/contests/joi2016yo/tasks/joi2016yo_d
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
vector<pair<char, int>> runLengthEncoding(string s) {
	int n = s.length();

	vector<pair<char, int>> res;
	char pre = s[0];
	int cnt = 1;
	rep(i, 1, n) {
		if (pre != s[i]) {
			res.push_back({ pre, cnt });
			pre = s[i];
			cnt = 1;
		}
		else cnt++;
	}

	res.push_back({ pre, cnt });
	return res;
}
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N; ll T; int Q;
ll A[101010]; int D[101010];
ll ans[101010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> T >> Q;
	rep(i, 0, N) cin >> A[i] >> D[i];

	string S = "";
	rep(i, 0, N) S += ((D[i] == 1) ? ">" : "<");
	auto rl = runLengthEncoding(S);
	int N_rl = rl.size();

	int cur = 0;
	int i_rl = 0;
	if (rl[0].first == '<') {
		rep(i, 0, rl[0].second) ans[i] = A[i] - T;
		cur += rl[0].second;
		i_rl++;
	}
	while (i_rl + 1 < N_rl) {
		ll cent = (A[cur + rl[i_rl].second - 1] + A[cur + rl[i_rl].second]) / 2;
		
		rep(d, 0, rl[i_rl].second) {
			ll limit = cent - A[cur + d];
			if (limit <= T) ans[cur + d] = cent;
			else ans[cur + d] = A[cur + d] + T;
		}
		cur += rl[i_rl].second;
		i_rl++;

		rep(d, 0, rl[i_rl].second) {
			ll limit = A[cur + d] - cent;
			if (limit <= T) ans[cur + d] = cent;
			else ans[cur + d] = A[cur + d] - T;
		}
		cur += rl[i_rl].second;
		i_rl++;
	}
	if (i_rl < N_rl) {
		rep(d, 0, rl[i_rl].second) ans[cur + d] = A[cur + d] + T;
		cur += rl[i_rl].second;
		i_rl++;
	}

	rep(i, 0, Q) {
		int x; cin >> x; x--;
		printf("%lld\n", ans[x]);
	}
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
それぞれの制約が大きく、制約から考えていくのは難しそう。
問題の弱点について考えていこう。
立ち止まる条件を考えると→←となってれば出会うので、時間が立つと立ち止まる。
あと、最左にある←は立ち止まることはない。
例えば、→→←←とかになってれば、この4つはある1点に集まる。
つまり、→←のグループに分割していってそれぞれに集まる時間が分かってくる。

これでとりあえず、ある1つの→←について考えていけば良くなった。
まず→←が出会う場所はここの中点になる。
→→→←←←となっていても、真ん中の→←の中点に全て集まる。
集まる場所がわかれば、そこにかかる時間もわかるので、その時間をそれぞれの場所について事前計算しておく。
その時間より前であれば、普通に動かして、後であれば、集まる場所に移動させる。
これを繰り返すことで、全ての場所について時間が立った後の場所がわかる。
最左の←と最右の→については集まる時間に制約がないので注意。

自分は実装のために、←を<、→の>として、文章にし、ランレングス圧縮をした上で操作している。
過実装ではあるが、用意してあるアルゴリズムが使えるのと、考えやすくなる。
あと、ちょっと見やすい。
///////////////////////// writeup2 end */
