#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ld long double
#define ll long long
#define Friendy  ios_base::sync_with_stdio(false); cin.tie(0);
#define sz size

int block;
struct Query {
    int L, R, idx;
};

bool compare(Query x, Query y) {
    if (x.L / block != y.L / block)
        return x.L / block < y.L / block;
    return x.R < y.R;
}
int MinDiff(vector<int>& sortedWindow) {
    if (sortedWindow.sz() < 2) return 0;
    int minDiff = INT_MAX;
    for (int i = 1; i < sortedWindow.sz(); i++) {
        minDiff = min(minDiff, sortedWindow[i] - sortedWindow[i - 1]);
    }
    return minDiff;
}
void MO(int a[], int n, Query q[], int m) {
    block = (int)sqrt(n);
    sort(q, q + m, compare);

    int currL = 0, currR = -1;
    vector<int> sortedWindow;
    vector<int> results(m);

    auto add = [&](int value) {
        auto pos = lower_bound(sortedWindow.begin(), sortedWindow.end(), value);
        sortedWindow.insert(pos, value);

    };

    auto remove = [&](int value) {
        auto pos = lower_bound(sortedWindow.begin(), sortedWindow.end(), value);
        sortedWindow.erase(pos);

    };
    for (int i = 0; i < m; i++) {
        int L = q[i].L, R = q[i].R;
        while (currR < R) {
            currR++;
            add(a[currR]);
        }
        while (currR > R) {
            remove(a[currR]);
            currR--;
        }
        while (currL < L) {
            remove(a[currL]);
            currL++;
        }
        while (currL > L) {
            currL--;
            add(a[currL]);
        }



        results[q[i].idx] = MinDiff(sortedWindow);
    }

    for (int i = 0; i < m; i++) {
        cout << results[i] << endl;
    }
}

int main() {
    Friendy

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int q;
    cin >> q;
    Query Q[q];
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        Q[i] = {l, r, i};
    }

    MO(a, n, Q, q);

    return 0;
}
