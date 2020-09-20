//https://atcoder.jp/contests/acl1/tasks/acl1_a
#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std; using namespace atcoder;
void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
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
vector<tuple<int, int, int>> points;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N;
	rep(i, 0, N) {
		int x, y; cin >> x >> y;
		points.push_back(make_tuple( x, y, i ));
	}
	sort(all(points));

	set<pair<int, int>> rest;
	dsu uf(N);
	rep(i, 0, N) {
		int x, y, id;
		tie(x, y, id) = points[i];
		while (0 < rest.size()) {
			auto ite = rest.lower_bound({ y, -1 });
			if (ite != rest.begin()) {
				ite--;
				uf.merge(ite->second, id);
				y = ite->first;
				rest.erase(ite);
			}
			else {
				break;
			}
		}
		rest.insert({ y, id });
	}

	rep(i, 0, N) printf("%d\n", uf.size(i));
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
まず、x,y座標がともに小さい街への移動と、x,y座標がともに大きい街への移動は
片方ができればもう片方もできるような移動になっている。
かつ、a->bで移動ができ、b->cで移動ができれば、a->cへの移動もできる。
つまり移動できる範囲は、グラフで考えると連結である範囲となる。
答えは連結な街の数となっている、これはUnionFindで達成できそうだ。

## UnionFindで移動可能な頂点を連結する

いかに連結を行っていくかであるが、全組合せ10^10通りになるので間に合わない。
ここで、2つの移動を考えると大変なので、x,y座標がともに小さい街への移動のみを考えることにする。
ある街P(px, py)に連結な街Q(qx, qy)は、qx<pxかつqy<pyであればいい。
効率的に行うには何かを固定するしかない。

## x座標昇順でマージしていく

x座標昇順でソートした街を順番に評価していこう。
こうすることである街Pと連結する街は、これまでに処理した街に限られ、
かつ、これまでに処理した街の中でy座標がPよりも小さい街を取ってくればよくなる。
よってマージ処理を行っていくが、setを使って、y座標を保存しておこう。

だが、このままだと、マージ処理を行っていっても、結局全探索のような感じになる。
なので、マージ処理を行った街は1つにまとめることにしよう。
マージ処理ごとに街をまとめると、1マージで1つ街が消えるので、ならし最大N-1回で済む。

## マージ後にどれを残すか

マージ後に頂点がある中で最も後のマージに使える点はどれだろうか。
マージするときに、それよりもy座標が小さい座標であればマージができる。
つまり、既にあるマージ後の街のグループの中で最もy座標が小さいものがマージの可能性がある。
なので、マージ後には最もy座標が小さいものを残しておけば問題ない。

実装はちょっと大変だが、setにはy座標だけでなく、街の添え字も乗っけておく。
///////////////////////// writeup2 end */
