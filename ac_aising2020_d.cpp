//https://atcoder.jp/contests/aising2020/tasks/aising2020_d
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
#ifdef _MSC_VER
inline unsigned int __builtin_popcount(unsigned int x) { return __popcnt(x); }
#endif // _MSC_VER
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N;
string X;
int cnt[201010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> X;

	rep(i, 1, 201010) {
		int pp = __builtin_popcount(i);
		cnt[i] = cnt[i % pp] + 1;
	}

	reverse(all(X));

	int cn = 0;
	rep(i, 0, N) if (X[i] == '1') cn++;

	int tot1 = 0, p1 = 1;
	int tot2 = 0, p2 = 1;
	rep(i, 0, N) {
		if (X[i] == '1') {
			tot1 = (tot1 + p1) % (cn + 1);
			if (2 <= cn) tot2 = (tot2 + p2) % (cn - 1);
		}

		p1 = (p1 * 2) % (cn + 1);
		if (2 <= cn) p2 = (p2 * 2) % (cn - 1);
	}

	vector<int> ans;
	p1 = 1;
	p2 = 1;
	rep(i, 0, N) {
		if (X[i] == '1') {
			if (cn == 1) {
				ans.push_back(0);
			}
			else {
				int x = (tot2 - p2 + cn - 1) % (cn - 1);
				ans.push_back(cnt[x] + 1);
			}
		}
		else {
			int x = (tot1 + p1 + cn + 1) % (cn + 1);
			ans.push_back(cnt[x] + 1);
		}

		p1 = (p1 * 2) % (cn + 1);
		if (2 <= cn) p2 = (p2 * 2) % (cn - 1);
	}

	reverse(all(ans));
	rep(i, 0, N) printf("%d\n", ans[i]);
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
実装が大変な問題。
順番に考えていこう。

## 操作の特性

今回の操作を見てみると、popcountの結果の最大値はNなので、
1回操作を行うだけでN以下の数にすることができる。
かつ、nが[1,2*10^5]の場合に0にするためにかかる時間はDPができるので、
先に前計算してしまおう。
以下の配列でDPすると分かる。
cnt[n] := nに対して操作を行ったときに0になる回数
つまり、最初の1回の操作でどの数になるかが高速に計算できれば、
あとは、それ以降の計算は前計算しておいた結果を使えばいい。

## 操作1回分の高速化

各桁についてswap後の数に対してpopcountで割った余りを計算する。
重要な性質として、swap後の数のpopcountは+1されるか-1されるかのどちらかである。
よって、swap前にpopcountをとっておき、その+1と-1でmodを取ったものを事前計算しておく。
cn := Nのpopcount
tot1 := 数N mod (cn + 1)
tot2 := 数N mod (cn - 1)
これでtot1とtot2を先に計算しておくことで、各桁のswap後の数は差分だけ計算すれば良くなる。
1を0にする場合は、tot2からその桁のmod (cn-1)を引けばいいし、
0を1にする場合は、tot1からその桁のmod (cn+1)を足せばいい。
これで1回操作後の数が分かったので事前計算したもの+1が答えになる。

## 注意点

桁は下から見ていくのが分かりやすいので、Xはリバースして実装した。
答えを出すときはリバースされてるので、更にリバースして元に戻して答えよう。
///////////////////////// writeup2 end */
