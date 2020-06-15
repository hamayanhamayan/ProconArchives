//https://atcoder.jp/contests/abc170/tasks/abc170_d
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













const int MA = 1000001;
int N, A[201010];
int cnt[1010101];
bool ok[1010101];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> A[i];

	rep(i, 0, N) cnt[A[i]]++;
	rep(x, 1, MA) ok[x] = true;
	rep(x, 1, MA) if(0 < cnt[x]) {
		if (1 < cnt[x]) ok[x] = false;
		for (int x2 = x * 2; x2 < MA; x2 += x) ok[x2] = false;
	}

	int ans = 0;
	rep(i, 0, N) if (ok[A[i]]) ans++;
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [調和級数的計算量](https://www.hamayanhamayan.com/entry/2016/10/21/112009)
///////////////////////// writeup2 start
この問題は調和級数的計算量を知らないと難しいかもしれない。
つまるところ、
「rep(i,1,N) for(j=i;j<=N;j+=i) というループ構造はO(NlogN)で行える」
というのを知っていれば解ける。
エラトステネスの篩の計算量解析と同じである。

愚直に問題に取り組もうとすると、iの組合せでN通り、それからjの組合せでN-1通りであり、
O(N^2)で間に合わない。
iの組合せはそのままで、jを高速化することをまずは考えてみる。
ダメなjは端的に言うと、A[i]の約数であるA[j]があるとダメである。
これを高速に判定したいので、約数を調べてそれがあるかを確かめて…
としたいが計算量が厳しい（実際はうまくやれば通るっぽい）。
なので、この段階でブレイクスルーが必要となる。

約数ではなく倍数を使う事にする。
「iを固定してダメなjを探す」のではなく「jを固定して、これによってダメにするiを探す」ようにする。
これで約数から倍数に考えがシフトした。
たぶん分かりにくいだろうから、ここから解法を直接的に説明する。

最終的に以下の配列を作成する。
ok[x] := A[i]=xである要素が性質を満たすか
これが分かれば、ok[A[i]]=trueであるiの個数が答えになる。

jを固定したときにダメなiというのは、A[j]の倍数であるA[i]となる。
つまり、A[j]が存在すれば、A[j]*2,A[j]*3,...は全てダメなA[i]となる。
よって、数を[1,10^6]の範囲でA[j]をチェックして、存在すれば、その倍数は全部ダメなA[i]とする。
このように倍数に対して全探索するような処理は計算量的にはO(NlogN)であり、間に合う。

あとは作成したokを使って判定していく。
注意点として、A[j]が存在するときに複数存在する場合はA[j]もダメなA[i]となるのが注意。
なので、各数毎に個数を数えて利用していくのがいいだろう。
///////////////////////// writeup2 end */
