//https://atcoder.jp/contests/abc164/tasks/abc164_d
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














string S;
ll cnt[2020];
//---------------------------------------------------------------------------------------------------
void _main() {
	cin >> S;
	int N = S.length();

	ll ans = 0;
	cnt[0] = 1;
	int tot = 0;
	int p = 1;
	rrep(i, N - 1, 0) {
		tot = (tot + (S[i] - '0') * p) % 2019;
		
		ans += cnt[tot];

		p = (p * 10) % 2019;
		cnt[tot]++;
	}
	cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
似たような問題を最近解いた覚えがあったので、解法自体はすぐに思いついた。
こういう区間数え上げは、片方を全列挙して、もう片方を高速に数え上げるのが定石。
iを全探索したときに、条件を満たすjが何通りあるかを計算しよう。

num[i] := i文字目からN-1文字目までの数
という風に考えてみよう。
すると、iを固定したときに条件を満たすjというのは、
(num[i] - num[j + 1]) / 10^(i - j + 1)が2019の倍数である個数を数えることになる。
ここで2019は3*673であることを考えると、10で割るということは2と5で割るということになり、
3*673の因数の個数には影響を与えない。
つまり、10で割る計算は2019の倍数であるかの判定には関係ないことになる。
よって、条件は、num[i] - num[j + 1]が2019の倍数であるかを見ればよい。

さて、これでだいぶやりやすくなった。
再掲すると、iを固定したときに条件を満たすjは「num[i] - num[j + 1]が2019の倍数」あればよい。
なので、条件を満たすjは2019の倍数ということを、mod 2019で考えるようにすると、
num[i] - num[j + 1] = 0 (mod 2019)
num[i] = num[j + 1] (mod 2019)
ということになる。
なので、num[i]を2019で割った余りと、i以降のnum[j]で2019で割った余りが等しいjの個数が
今回の条件を満たす。

よって、
cnt[m] := num[j]=m (mod 2019)であるjの個数
を集計しながら、答えを計算していくと答え。
cnt配列の集計をしながら行うので、iは末尾から全探索していく。
後は、上の解説とソースコードを見ながら、実装については読み解いていってほしい。
///////////////////////// writeup2 end */
