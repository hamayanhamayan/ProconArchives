//https://yukicoder.me/problems/no/885
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

int N, A[101010], Q;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;
    priority_queue<int> que;
    ll tot = 0;
    rep(i, 0, N)
    {
        cin >> A[i];
        que.push(A[i]);
        tot += A[i];
    }
    cin >> Q;
    rep(q, 0, Q) {
        int x; cin >> x;
        while(x <= que.top()) {
            int qu = que.top();
            que.pop();
            tot -= qu;
            qu %= x;
            tot += qu;
            que.push(qu);
        }
        printf("%lld\n", tot);
    }
}



/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
剰余にまつわる重要な性質がある。
1度剰余が行われると、値が変わらないか、半分未満の数に変わる。
よって、各要素について値が変わる回数はlogA[i]回となる。
つまり、毎回のクエリで値が変わるものだけ変えていけば、ならしNlogAとなり間に合う。
どの数で値が変わるかは数が大きいものから順番に見ていけばいい。
大きいものから見ていったときに値が変わらないなら、それ以降も値は変わらない。
剰余を取るときに、総和からその数を引き、剰余をとったあとの数を足せば差分計算が可能。
///////////////////////// writeup2 end */
