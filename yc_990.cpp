//https://yukicoder.me/problems/no/990
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
vector<int> enumdiv(int n) { 
    vector<int> S;
    for (int i = 1; 1LL*i*i <= n; i++) if (n%i == 0) { S.push_back(i); if (i*i != n) S.push_back(n / i); }
    sort(S.begin(), S.end());
    return S;
}
int gcd(int a, int b) { return a ? gcd(b % a, a) : b; }
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan0
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int N, M, K; char op;
ll B[101010], A[101010];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> N >> M >> K >> op;
	rep(i, 0, M) cin >> B[i];
	rep(i, 0, N) cin >> A[i];

	ll ans = 0;
	if (op == '+') {
		map<int, int> cnt;
		rep(i, 0, M) cnt[B[i] % K]++;
		rep(i, 0, N) {
			int b_mo = K - (A[i] % K);
			b_mo %= K;
			ans += cnt[b_mo];
		}
	}
	else {
		auto ed = enumdiv(K);

		unordered_map<int, int> cnt, cnt2;
		rep(i, 0, M) fore(d, ed) if(B[i] % d == 0) cnt[d]++;
		rep(i, 0, N) ans += cnt[K / gcd(A[i], K)];
	}
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [最大公約数、約数列挙](https://www.hamayanhamayan.com/entry/2017/10/14/125941)
///////////////////////// writeup2 start
opが和と積で場合分けして考える。

opが和の場合。
A[i]について全探索しよう。
`mo = A[i] % K`とすると、B[j]%K=(K-mo)%Kを満たすB[j]の個数が求まればいい。
mapを使って、B[j]%K毎に個数を数えておこう。

opが積の場合。
こちらが難しい。
こちらも同様に、A[i]について全探索する。
こちらもmo的なことを考えるが、ある数xがKの因数をどれだけ持つかというのは、
最小公倍数を計算すると分かる。
gcd(A[i], K)を計算すると、A[i]でまかなえているKの因数が分かるので、
K/gcd(A[i], K)とすると、これが残り必要な因数となる。
よって、K/gcd(A[i], K)を因数と持つB[j]の個数が分かれば、その総和が答え。

問題が少し小さくなった。
xを因数と持つB[j]の個数を高速に求めたい。
実際、xはKの約数にしかならないので、Kの約数列挙をしておく。
約数列挙したものを使って、cnt配列を作成する。
cnt[x] := xを因数として持つB[j]の個数
これを事前計算しておけば、高速に答えることができる。
…が、びみょーに間に合わなかったので、mapをunordered_mapに変えて通した。
添え字の組み合わせも少ないので、衝突しないだろう。

本番では、解説とは若干違う方針で通した。こっちは、なかなか早い。
[本番コード](https://yukicoder.me/submissions/430337)
///////////////////////// writeup2 end */
