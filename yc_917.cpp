//https://yukicoder.me/problems/no/917
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
int gcd(int a, int b) { return a ? gcd(b % a, a) : b; }
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N, A[50];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> A[i];

	ll ans = 0;
	rep(i, 0, N) {
		map<int,ll> dp;
		dp[A[i]] = 1;
		rep(j, i + 1, N) {
			map<int, ll> pd;
			fore(p, dp) {
				// 採用する
				pd[gcd(p.first, A[j])] += p.second;
				// 採用しない
				pd[p.first] += p.second;
			}
			swap(dp, pd);
		}
		ans += dp[1];
	}
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [動的計画法](https://www.hamayanhamayan.com/entry/2017/02/27/021246)
///////////////////////// writeup2 start
制約が少し特殊っぽい。
よくある方針として、全通りからgcdが1とならないものを引く方針で考える？
包除原理な感じもする。

いや、1つ使う要素を固定して、DPすればdpの添字はそれの約数に収まるな。
それで解けそう。
A1, A2, ...と順番にA[i]を使うときに最大公約数が1となる部分列の個数を求める。
このとき、A[i]を使うと決めたら、j<iを満たすA[j]は使う組み合わせは求まっているので、A[j]はすべて使わないことにする。
あとは、
dp[g] := gcdがgである部分列の総数
をmapで表現しながら、求めていく。
///////////////////////// writeup2 end */
