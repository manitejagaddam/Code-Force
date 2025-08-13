// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// struct P { ll x, y; };

// ll twiceArea(P a, P b, P c) {
//     return abs(a.x * (b.y - c.y) +
//                b.x * (c.y - a.y) +
//                c.x * (a.y - b.y));
// }

// int main() {
//     int n; ll S;
//     cin >> n >> S;
//     vector<P> pts(n);
//     for (auto &p : pts) cin >> p.x >> p.y;

//     ll target = 2 * S;
//     for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j < n; j++) {
//             for (int k = j + 1; k < n; k++) {
//                 if (twiceArea(pts[i], pts[j], pts[k]) == target) {
//                     cout << "YES\n";
//                     cout << pts[i].x << " " << pts[i].y << "\n";
//                     cout << pts[j].x << " " << pts[j].y << "\n";
//                     cout << pts[k].x << " " << pts[k].y << "\n";
//                     return 0;
//                 }
//             }
//         }
//     }
//     cout << "NO\n";
// }




#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct P { ll x, y; };

ll cross(const P &a, const P &b) {
    return a.x * b.y - a.y * b.x;
}

ll area2(const P &a, const P &b, const P &c) {
    return llabs(cross({b.x - a.x, b.y - a.y},
                       {c.x - a.x, c.y - a.y}));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; ll S;
    cin >> n >> S;
    vector<P> pts(n);
    for (auto &p : pts) cin >> p.x >> p.y;

    ll target = 2 * S;
    for (int i = 0; i < n; i++) {
        vector<P> others;
        for (int j = 0; j < n; j++) if (i != j) others.push_back(pts[j]);

        sort(others.begin(), others.end(), [&](const P &p1, const P &p2) {
            return atan2(p1.y - pts[i].y, p1.x - pts[i].x) <
                   atan2(p2.y - pts[i].y, p2.x - pts[i].x);
        });

        int m = others.size();
        for (int j = 0; j < m; j++) {
            int l = j + 1, r = m - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                ll a2 = area2(pts[i], others[j], others[mid]);
                if (a2 == target) {
                    cout << "YES\n";
                    cout << pts[i].x << " " << pts[i].y << "\n";
                    cout << others[j].x << " " << others[j].y << "\n";
                    cout << others[mid].x << " " << others[mid].y << "\n";
                    return 0;
                }
                if (a2 < target) l = mid + 1;
                else r = mid - 1;
            }
        }
    }
    cout << "NO\n";
}
