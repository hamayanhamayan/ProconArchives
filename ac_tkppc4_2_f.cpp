//https://atcoder.jp/contests/tkppc4-2/tasks/tkppc4_2_f
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









int N; ll K; ll A[151010]; ll v[4][151010];
//---------------------------------------------------------------------------------------------------
#define yes "Yes"
#define no "No"
string solve() {
    rep(i, 0, N - (K - 1) * 2) {
        if (0 < i) {
            v[1][i] = v[0][i] + v[1][i - 1];
            v[2][i] = v[1][i] + v[2][i - 1];
            v[3][i] = v[2][i] + v[3][i - 1];
        }

        ll rest = A[i] - v[3][i];
        if(rest < 0) return no;

        v[0][i] += rest;
        v[1][i] += rest;
        v[2][i] += rest;
        v[3][i] += rest;
        v[0][i + 1] += rest;
        v[0][i + 1 + 1 + K - 2] -= rest * 4 * K;
        v[0][i + 1 + 1 + K - 2 + 1] += rest * 4 * K;
        v[0][i + 1 + 1 + K - 2 + 1 + 1 + K - 2] -= rest;
        v[0][i + 1 + 1 + K - 2 + 1 + 1 + K - 2 + 1] -= rest;
    }

    rep(i, N - (K - 1) * 2, N) {
        if (0 < i) {
            v[1][i] = v[0][i] + v[1][i - 1];
            v[2][i] = v[1][i] + v[2][i - 1];
            v[3][i] = v[2][i] + v[3][i - 1];
        }

        if(A[i] != v[3][i]) return no;
    }

    return yes;
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> K;
    rep(i, 0, N) cin >> A[i];
    cout << solve() << endl;
}





/* ///////////////////////// writeup1 start
# 前提知識
- [2次imos法](https://www.hamayanhamayan.com/entry/2017/07/04/020117)
///////////////////////// writeup2 start
考え始めが難しい問題である。
制約にはこれと言った弱点が見つからない。
問題を見ると、「ちょうどゼロになる」というのが使えそう。
これだけでは解けないが、もう2つ大事な部分がある。
「操作の順番は関係ない」
「K以上N-K+1以下の番号の相手をヒットすることができる」
よって、1番目の敵を攻撃するにはK番目の相手を攻撃するしかない。
これにより、K番目の相手の攻撃回数は一意に定まる。
攻撃後は、1番目は0になる。
その後、2番目の相手を攻撃するにはK+1番目の相手を攻撃するしかない。
これを繰り返していく。

ここからも難しい。
問題が、区間に1 4 9 4 1というのを足すか引くかという操作をする必要がある。
区間に1 4 9 4 1を足す操作であるが、1 4を足して、9 4 1を足すという操作とすると、
二次関数を足している操作になる。
imos法で二次関数を足すテクがあり、これを今回の問題で応用して使っていこう。
例えば、1^2～k^2を区間に足す場合は、始点から
1 1 0 0 ... 0 -4*k 4*k 0 0 ... 0 -1 -1
とすればいい。0の個数はk-2個である。
k=1のときは適用できないので場合分けだが、この場合は必ず実現できるので、Yesが答え。
これをやって、3回累積和すれば答え。
x1^2～xk^2を区間に足す場合は、全てx倍してやればいい。
///////////////////////// writeup2 end */
