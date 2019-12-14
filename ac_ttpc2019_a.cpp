//https://atcoder.jp/contests/ttpc2019/tasks/ttpc2019_a
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
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/














int A, B, T;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> A >> B >> T;

    int cycle = B - A;

    int ans = T - B;

    if (0 < ans % cycle) {
        ans += (cycle - (ans % cycle));
    }

    ans += B;

    cout << ans << endl;
}





/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
計算を頑張る。
周期cycle=B-Aである。
B, B+cycle, B+cycle*2, ...のようになるが、Tのままだと扱いにくい。
そこで、T-Bとしておくと、cycleで割ったときの余りが0になればいいので、ちょっと扱いやすい。
T-Bをcycleで割ったときの余りが0でないときは、0になるように差分を足す。
最後にそれに+Bをすると元に戻るので、それが答え。
///////////////////////// writeup2 end */
