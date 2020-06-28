//https://atcoder.jp/contests/abc172/tasks/abc172_d
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
int val[10101010], f[10101010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 1, N + 1) val[i] = i, f[i] = 1;
	rep(p, 2, N + 1) for (int x = p; x <= N; x += p) {
		int c = 0;
		while (val[x] % p == 0) val[x] /= p, c++;
		f[x] *= c + 1;
	}

	ll ans = 0;
	rep(i, 1, N + 1) ans += 1LL * i * f[i];
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [エラトステネスの篩](https://www.hamayanhamayan.com/entry/2016/10/21/112009)
///////////////////////// writeup2 start
[1,K]の約数の個数を効率的に数え上げる必要がある。
以下のことを知っているとエラトステネスの篩が思いつくだろう。
- 約数の個数は、素因数分解ができていれば、各素因数の個数+1の総積と等しくなる
- 区間の素因数分解はエラトステネスの篩っぽいアルゴリズムが使える

## エラトステネスの篩

もし知らない場合はどこかで勉強してこよう。
2,3,4,5,6,...と数を見ていくときに割れるだけ割るような処理を追加して、
割れるだけ割るような処理をするときに割った個数をカウントしておくと、
その個数がその素因数の個数となるので、個数+1を組合せに掛け合わせていく。
f[x] := xの約数の個数
こういう風に配列を用意しておくと、問題に寄っていいかもしれない。
これで最後に作った配列fを使って問題に書いてある通りに計算すれば答え。
計算量はO(NlogN)でN=10^7なので、だいぶギリギリ。
C++じゃないと通らないんじゃないかなと思うから、たぶん想定解じゃない。
///////////////////////// writeup2 end */
