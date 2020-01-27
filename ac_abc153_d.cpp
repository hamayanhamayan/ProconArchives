//https://atcoder.jp/contests/abc153/tasks/abc153_d
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














ll H;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> H;

	ll cnt = 1, ans = 0;
	while (0 < H) {
		ans += cnt;
		H /= 2;
		cnt *= 2;
	}

	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
操作について考えてみる。

モンスターの体力が1なら、体力は0になる。
これは分岐もしないので、そうなる。

モンスターの体力がXなら、X/2とX/2になる。
ここで大切なのが、分裂後のモンスターの体力は等しいという所。
かつ、独立に操作は進むので、どのように操作を行っても同じ結果しか得られない。
よって、最小値とあるが、実際はモンスターに勝つまでに行う回数の総和が得られればいい。

高速にこれを答えるために、全てのモンスターを同時に扱っていくことを考える。
操作を並列に行うと、
最初はXが1つ。
全てに操作を行うと、次はX/2が2つ。
全てに操作を行うと、次はX/4が4つとなる。
つまり、1シーズン終えるごとに、数は半分、個数は倍になることが分かる。
そして、各シーズンごとに個数分の回数が必要となるので、Xをどんどん2で割って行って、同時に個数も2倍していきながら足すことで、
1+2+4+8+...のように答えを求めることができる。
///////////////////////// writeup2 end */
