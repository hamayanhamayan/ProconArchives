//https://atcoder.jp/contests/abc139/tasks/abc139_f
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
const double EPS = 1e-8, INF = 1e12, PI = 2 * acos(0.0);
typedef complex<double> P;
namespace std {
    bool operator < (const P& a, const P& b) { return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b); } 
    bool operator == (const P& a, const P& b) { return abs(real(a) - real(b)) < EPS && abs(imag(a) - imag(b)) < EPS; }
    P operator / (const P& a, const double& b) { return P(real(a) / b, imag(a) / b); }
    P operator * (const P& a, const double& b) { return P(real(a) * b, imag(a) * b); }
}
double argument(const P &a, const P &b) { // argument for A->B[-PI,PI]
    double ax = real(a), ay = imag(a), bx = real(b), by = imag(b);
    return atan2(by - ay, bx - ax);
}
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     @hamayanhamayan
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿
　 　　　＼/＿＿＿＿/　（u　⊃
---------------------------------------------------------------------------------------------------*/

int N;
//---------------------------------------------------------------------------------------------------
void _main()
{
    cin >> N;
    vector<P> v;
    rep(i, 0, N)
    {
        int x, y;
        cin >> x >> y;
        if(x != 0 or y != 0) {
            v.push_back(P(x, y));
        }
    }

    sort(all(v), [&](P a, P b) { return argument(P(0, 0), a) < argument(P(0, 0), b); });

    double ans = 0;
    int n = v.size();
    rep(i, 0, n) {
        double x = 0, y = 0;
        rep(j, 0, n) {
            auto p = v[(i + j) % n];
            x += real(p);
            y += imag(p);

            chmax(ans, sqrt(x * x + y * y));
        }
    }
    printf("%.10f\n", ans);
}

/* ///////////////////////// writeup1 start
# 前提知識
- [幾何問題](https://www.hamayanhamayan.com/entry/2018/02/27/105814)
///////////////////////// writeup2 start
頂点全てを偏角ソートすると、最適な組み合わせは、連続する区間の頂点を選んで選択することである。
言われてみればそんな気もするが、これを無からひっぱり出してくるのは難しい。
とりあえず、こういうパターンもあると覚えておくことにする。
ここまでの考察で600点ある。

あとは、偏角ソートして、区間を足していけばいい。
愚直にやっても(N^3)となるが、順次足し合わせていくとO(N^2)となり、
思いつけばこっちのほうが簡単なので、これでやるとAC

ついでに2点間偏角ソートという応用もある。
気になる人は[幾何問題](https://www.hamayanhamayan.com/entry/2018/02/27/105814)に問題がある。
///////////////////////// writeup2 end */
