//https://atcoder.jp/contests/abc143/tasks/abc143_d
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
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N, L[2010], cnt[2010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> L[i];

	rep(i, 0, N) cnt[L[i]]++;
	rep(i, 1, 2010) cnt[i] += cnt[i - 1];

	ll ans = 0;
	rep(a, 0, N) rep(b, 0, N) if (a != b) {
		int mi = max(L[a] - L[b], L[b] - L[a]);
		int ma = L[a] + L[b];

		int cn = 0;
		if (0 <= ma - 1) cn = cnt[ma - 1];
		cn -= cnt[mi];

		if (mi < L[a] and L[a] < ma) cn--;
		if (mi < L[b] and L[b] < ma) cn--;

		ans += cn;
	}
	ans /= 6;
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [累積和](https://www.hamayanhamayan.com/entry/2017/07/04/020117)
///////////////////////// writeup2 start
まずは全探索を考える。
a,b,cを全探索して、条件を満たすか考える。
これは組み合わせが10^9くらいなのでダメ。
でも、a,b全探索なら10^6くらいなので、まだ余地がありそう。

a,bが固定してあると、cは以下の条件を満たす必要がある。

a - b < c
b - a < c
c < a + b

上2つはまとめられる

max(a-b, b-a) < c < a+b

これを満たすcを数えればいい。
Lは[1,10^3]なので、
cnt[len] := 長さがlenである棒の個数
を作り、累積和を使うことで、条件を満たすcの組み合わせは高速に求めることができる。
注意として、a,bで選択した棒がcに入る場合があるので、その場合は抜かす。
最後に使われている棒は同じで順番だけ違うものも重複して数えているので、3!で割ると答え。
///////////////////////// writeup2 end */
