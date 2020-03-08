//https://atcoder.jp/contests/abc158/tasks/abc158_e
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














int N, P; string S;
int cnt[201010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> P >> S;
	ll ans = 0;

	if (P == 2 || P == 5) {
		rep(i, 0, N) if ((S[i] - '0') % P == 0) ans += i + 1;
	}
	else {
		int cu = 0; int dg = 1;

		rrep(i, N - 1, 0) {
			cu = (cu + dg * (S[i] - '0')) % P;
			dg = (dg * 10) % P;

			ans += cnt[cu];
			if (cu == 0) ans++;

			cnt[cu]++;
		}
	}

	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
結構難しい問題に見える。
問題の弱点はPが素数というところである。
なぜ、ここが弱点なんだろうか。

連続する部分列の数え上げでの常套テクとして、
「左端を全探索して、条件を満たす右端の組み合わせを効率よく数える」
があり、これを今回も使う。

左端を固定してi桁目としておこう。
num[i] = i桁目以降の部分文字列で作られた数
とすると、条件を満たす右端は、(num[i] - num[j]) / 10^(i-j)がPの倍数であるものである。
ここで注目すべきなのが、10乗で割っているが、これはPが2,5の場合のみ影響する。
それ以外であれば無視して構わない。よって、一旦、P=2,5以外で考えていく。
すると条件は、num[i] - num[j]がPの倍数であるものである。
これはnum[j] % Pを添え字とした配列で個数計算しておけば、素早く数え上げができる。
cnt[m] := num[j] % P=mである組み合わせ
この配列を構築しながら、条件を満たすものを数え上げていくと答え。
右端は逆順から見ていこう。

残りはP=2,5であるが、どちらも下一桁がPの倍数であれば、全体もその倍数になるので、
こちらは右端を全探索する感じで数え上げよう。
///////////////////////// writeup2 end */
