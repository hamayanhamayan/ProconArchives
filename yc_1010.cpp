//https://yukicoder.me/problems/no/1010
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














ll x, y, h;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> x >> y >> h;

	x *= 1000; y *= 1000;
	if (x > y) swap(x, y);

	int ans = 0;
	while (h < x) y *= 2, h *= 4, ans++;
	while (h < y) x *= 2, h *= 4, ans++;
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
完全に雰囲気で解いてしまったので、あまり参考にならないかもしれない。

この問題は貪欲法で解ける。
貪欲は「縦と横で長さが小さい方から折れるまで折って、その後、大きい方で折れるだけ折る」という感じ。

実装テクとして、x≦yとなるように処理しておくと、後々場合分けしなくて済む。
こういう前提を導入することで実装を簡単にするというのは、よく使うテク。

あと、今回の問題は誤差死の可能性があるので、注意。
横で折るときに、 `x /= 2, h *= 2`の計算をすると思うが、xの切り捨てで死ぬときがある。
（というか、一回WA出した）
重要なのは、`h<x`と`h<y`が正しく評価できるかという所であるため、相対的な大きさが正しく保たれればいい。
よって、操作を行った後、全部の長さを2倍にしても、相対的な大きさは変わらない。
なので、`x /= 2, h *= 2, y *= 1`という操作に対して、その後に全部2倍すると、
`x /= 1, h *= 4, y *= 2`という感じになるので、このように長さを変形するよう修正する。
///////////////////////// writeup2 end */
