//https://atcoder.jp/contests/joi2020yo2/tasks/joi2020_yo2_c
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














int N;
bool dp[1010101];
//---------------------------------------------------------------------------------------------------
int f(int x) {
	int res = x;
	while (0 < x) {
		res += x % 10;
		x /= 10;
	}
	return res;
}
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	
	dp[N] = true;
	rrep(i, N - 1, 1) if (dp[f(i)]) dp[i] = true;

	int ans = 0;
	rep(i, 0, N + 1) if (dp[i]) ans++;
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [yes/no系動的計画法](https://www.hamayanhamayan.com/entry/2017/02/27/021246)
///////////////////////// writeup2 start
これは手法を知らないと、何も思いつかないかもしれない。
yes/no系の動的計画法で解ける。
dp[i] := 数iから操作を0回以上行って整数をNにできる
ここから少し応用的なのだが、遷移を逆から行う必要がある。
つまり、dp[N]=trueから初めてiを小さくしていきながら更新する。
dp[i]から操作を行いjが作れる場合、dp[j]=trueならばdp[i]=trueになる。
全部更新が終わったら、trueになってる個数を数えれば答え。

実装面であるが、操作を関数fと考えて実装している。
あと、大きい数に対して関数fを通すと10^6をちょっと超えてしまうので、使わないが配列を多めにとっておくと、
分岐を省くことができる。
///////////////////////// writeup2 end */
