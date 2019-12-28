//https://atcoder.jp/contests/abc148/tasks/abc148_e
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














ll N;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;

	if (N % 2 == 1) {
		cout << 0 << endl;
		return;
	}
	
	ll ans = N / 10;
	N /= 10;

	ll p5 = 5;
	while (p5 <= N) {
		ans += N / p5;
		p5 = p5 * 5;
	}
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
大学受験を済ませている人は、この問題を見たらピンと来るかもしれない。
ある数の末尾に続く0の個数はある数を素因数分解したときのmin(2の個数, 5の個数)となる。
これをベースとして考えていく。

するとNが奇数の場合は、かける全ての数に2を約数として含まないので、答えは0になる。
Nが偶数の場合は、
2*4*6*8*10*12*14*16*...
となっていく。
2はむちゃくちゃあるので、実質5の個数が答えの個数である。
15のように下1桁が5になることは無いので、10の倍数に5が含まれる可能性がある。
よって、いっぱいあるが、実際は10の倍数だけ考えれば良いことが分かる。
10*20*30*40*50*...
これは元々10の倍数なので、この個数分とりあえず10はある。
その個数を数えて、全部10で割ってやると、
1*2*3*4*5*...
となる。
ここまでくれば、センター試験で見たような問題と同じ問題になる。
5の倍数の個数+5^2の倍数の個数+5^3の倍数の個数+...を数えていけばいい。
あとは、それと元々10の倍数が何個あったかの和が答え。
オーバーフローするかもと思うが、あまりよく考えずに出すと通る。
///////////////////////// writeup2 end */