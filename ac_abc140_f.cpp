//https://atcoder.jp/contests/abc140/tasks/abc140_f
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

int N, S[2 << 18];
int M;
//---------------------------------------------------------------------------------------------------
#define yes "Yes"
#define no "No"
string solve() {
    map<int, int> cnt;
    rep(i, 0, M) cnt[S[i]]++;
    vector<pair<int,int>> v;
    fore(p, cnt) v.push_back(p);
    sort(all(v), greater<pair<int, int>>());

    priority_queue<int> connection;
    connection.push(M);
    fore(p, v)
    {
        int cnt = p.second;
        if(connection.size() < cnt)
            return no;

        vector<int> buf;
        rep(i, 0, cnt) {
            buf.push_back(connection.top());
            connection.pop();
        }

        fore(c, buf) {
            c /= 2;
            while (0 < c)
            {
                connection.push(c);
                c /= 2;
            }
        }
    }

    return yes;
}
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;
    M = 1;
    rep(i, 0, N) M *= 2;
    rep(i, 0, M) cin >> S[i];

    cout << solve() << endl;
}

/* ///////////////////////// writeup1 start
///////////////////////// writeup2 start
まず、2^18は5*10^5くらいあるので、小さい数ではない。
割り当て問題としてマッチング問題があるが、そんな雰囲気は全然しない。
全然思いつかない。
スライムの生成ではなく、スライムの合成と考えた方が楽じゃないか。
2つのスライムのmaxのスライムが出来上がる。
貪欲か？と思って貪欲を考えるもイマイチ。

解説を見た。
解説では、完全二分木の葉にスライムの体力を貪欲に割り当てていた。
スライムの体力が大きい淳に割り当てるが、ある葉を割り当てると、その端から頂点まででの合成は
全てそのスライムの体力になるため、考えなくても良くなる。
つまり、そのパスによって葉が分割される。
スライムの体力はかぶることがあるが、同じ連結成分では置けないので、
違う連結成分に配置し、それによって、連結成分をまた分割する。
葉が多い連結成分を優先的に使っていこう。

連結成分での葉の個数がcであれば、その後できる連結成分の個数はc/2, c/4, c/8…となる。
priority_queueに入るのは葉の頂点と同じだけくらいの個数となるため、
計算量については問題ない。
///////////////////////// writeup2 end */
