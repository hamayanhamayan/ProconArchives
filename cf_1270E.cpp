//https://codeforces.com/contest/1270/problem/E
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
void outv(vector<int> ans) {
	int n = ans.size();
	rep(i, 0, n) {
		if (i) printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
}
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N, X[1010], Y[1010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) cin >> X[i] >> Y[i];

	vector<int> a, b;
	do {
		a.clear();
		b.clear();

		rep(i, 0, N) {
			if ((X[i] + Y[i]) % 2 == 0) a.push_back(i);
			else b.push_back(i);
		}

		if (a.size() == 0) rep(i, 0, N) X[i]++;

		rep(i, 0, N) {
			int x = (X[i] + Y[i]) / 2;
			int y = (X[i] - Y[i]) / 2;
			X[i] = x;
			Y[i] = y;
		}
	} while (a.size() * b.size() == 0);

	int n = a.size();
	printf("%d\n", n);
	fore(i, a) i++;
	outv(a);
}


/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
順位表を見ると、みんな爆速で通しているので、なにか特殊なルールで分けるのだろうというのは分かる。
ヤバい状況を考えるというのが抜けていた。
今回のヤバ状況は、全部のグリッドに点がある場合である。
この場合は(x + y) % 2で、塗り分ければ問題ない。
これは使えそう。

だが、サンプル2でそれをやると、全部同じ色になってしまうので、それでは困る。
拡大縮小、回転、平行移動をしてもマンハッタン距離の大小関係は変わらないので、それを上手く使う。
以下、chokudaiさんの解法を参考に書いた調整手段。
x+yのパリティが全部1の場合はx座標を+1して、全部0にしておこう。
この状態で45度回転を行って、2分の1に縮小する。
パリティが0なので、2分の1に縮小しても切り捨てにならない。
これを2グループに分かれるまで繰り返す。
///////////////////////// writeup2 end */
