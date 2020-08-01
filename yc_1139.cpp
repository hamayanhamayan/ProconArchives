//https://yukicoder.me/problems/no/1139
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














int N, D, x[101010], v[101010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> D;
	rep(i, 0, N) cin >> x[i];
	rep(i, 0, N) cin >> v[i];

	ll tot = 0;
	rep(i, 0, N) tot += v[i];
	ll ans = (D + tot - 1) / tot;
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
パッと見て、星1.5の問題には見えないので、うまい性質を見抜く問題だろうなとあたりをつける。

## うまい性質

全てのスライムが走った距離を求めるが、衝突がない場合は、速さ×時間の総和を取ればいい。
衝突があるときは、どうだろうかと考えてみると、実は衝突しても、答えは変わらない。
速さv1と速さv2のスライムが衝突後にT秒間走ったとすると、移動距離は(v1+v2)T=v1T+v2Tとなり、
衝突して合体せず、並走したと考えても特に問題はない。

## つまり…？

なので、「f(T)は速さ×Tの総和」となる。  
計算を簡単にすると、「f(T)は速さの総和×T」となる。
速さの総和×T≧D
となる最小の整数Tなので、
D/速さの総和の切り上げが答え。
///////////////////////// writeup2 end */