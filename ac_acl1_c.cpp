//https://atcoder.jp/contests/acl1/tasks/acl1_c
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














int H, W;
string S[50];
vector<pair<int,int>> circles;
int dist[101][50][50];
ll BASE = inf;
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> H >> W;
	rep(y, 0, H) cin >> S[y];

	int id = 0;
	rep(y, 0, H) rep(x, 0, W) if (S[y][x] == 'o') {
		circles.push_back({ x, y });
		rep(xx, 0, W) rep(yy, 0, H) dist[id][yy][xx] = inf;
		queue<tuple<int,int, int>> que;

		dist[id][y][x] = 0;
		que.push(make_tuple(x, y, 0));
		while (!que.empty()) {
			int x, y, cst;
			tie(x, y, cst) = que.front(); que.pop();

			if (x + 1 < W && S[y][x + 1] != '#' && dist[id][y][x + 1] == inf) {
				dist[id][y][x + 1] = cst + 1;
				que.push(make_tuple(x + 1, y, cst + 1));
			}

			if (y + 1 < H && S[y + 1][x] != '#' && dist[id][y + 1][x] == inf) {
				dist[id][y + 1][x] = cst + 1;
				que.push(make_tuple(x, y + 1, cst + 1));
			}
		}

		id++;
	}

	mcf_graph<int, ll> g(H * W + id + 2);
	int st = H * W + id;
	int gl = st + 1;

	rep(i, 0, id) {
		g.add_edge(st, H * W + i, 1, 0);
		rep(y, 0, H) rep(x, 0, W) if (dist[i][y][x] < inf) g.add_edge(H * W + i, y * W + x, 1, BASE - dist[i][y][x]);
	}
	rep(y, 0, H) rep(x, 0, W) if (S[y][x] != '#') g.add_edge(y * W + x, gl, 1, 0);
	
	ll ans = -(g.flow(st, gl).second - BASE * id);
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
ACLコンテストということで、最小費用流が何とか出てきた。
ACLじゃなきゃ思いついていないかも。
最小費用流が分からない場合は、先にどこかで学習しよう。

## 何から手を付ける？

正直発想がなければ手を付けようがない問題に見える。
N,Mが異常に小さいというのと、とても単純な例でもだいぶきついので、
DPとか貪欲とかそんな次元じゃない感じがする。

## 最終的にはどこに移動するか

ある駒が最終的にどこに移動するかが分かっているとする。
ある駒がどこに移動するかが分かっていれば、それに必要な操作回数は定まる。
これは駒の最初の場所からBFSで距離を前計算しておく。

これをすべての駒について考えると、全ての駒の移動先が分かっていれば、操作回数の総和も分かる。
なので、過程はともあれ、どこに移動するかというのを考えてみることにする。
すると、これはマッチング問題に似ていることに気がつく。
これは最小費用流で解けそうだ。

## 最小費用流

以下のルートで最小費用流を流そう。
始点 -> 駒 -> 移動先の座標 -> 終点
2部マッチングのような雰囲気でフローを作る。

始点 -> 駒：コスト0, 流量1
駒 -> 移動先の座標 : コスト操作回数、流量1
移動先の座標 -> 終点：コスト0, 流量1

こういう感じに辺をはって駒の個数分流量を流して、コストの最大値をとれば答えになる。
最小費用流では最小化されてしまうので、コストをマイナスにして、
ACLにある最小費用流のライブラリでは負のコストは許されてないので、一律で10^9あたりを足して正にして流す。
///////////////////////// writeup2 end */
