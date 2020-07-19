

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


struct event {
    int ind, type;
    event() {}
    event(int ind, int type) : ind(ind), type(type) {}
};
struct point {  int x, y;   };
const int ENTRY = 0, EXIT = 1;
const int RECT_MAX = 1000+9;

point rects[RECT_MAX][2];
bool inActiveSet[RECT_MAX];
event events_v[2 * RECT_MAX], events_h[2 * RECT_MAX];

bool cmpX(event a, event b) {
    return rects[a.ind][a.type].x < rects[b.ind][b.type].x;
}
bool cmpY(event a, event b) {
    return rects[a.ind][a.type].y < rects[b.ind][b.type].y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // redirect input stream to samples files
//    freopen("../../week_13/samples_13/boxunion/1.in", "r", stdin);
//    freopen("../../week_13/samples_13//2.in", "r", stdin);
//    freopen("../../week_13/samples_13/boxunion/test.in", "r", stdin);
    int test_cases;
    cin >> test_cases;
    for (int t = 1; t <= test_cases; ++t) {
        cout << "Case #" << t << ": ";
        long long area = 0;
        int n = 0, eventsCnt = 0;  // # rectangles, edges
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> rects[i][0].x >> rects[i][0].y >> rects[i][1].x >> rects[i][1].y;
            events_v[eventsCnt] = event(i, ENTRY), events_v[eventsCnt + 1] = event(i, EXIT);
            events_h[eventsCnt] = event(i, ENTRY), events_h[eventsCnt + 1] = event(i, EXIT);
            eventsCnt += 2;
        }
        sort(events_v, events_v + eventsCnt, cmpX);
        sort(events_h, events_h + eventsCnt, cmpY);

        inActiveSet[events_v[0].ind] = 1;
        for (int v = 1; v < eventsCnt; ++v) {  // Vertical sweep
            event c = events_v[v], p = events_v[v - 1];
            int cnt = 0, first_rect, delta_x, delta_y;

            if ((delta_x = rects[c.ind][c.type].x - rects[p.ind][p.type].x) == 0) {
                inActiveSet[c.ind] = (c.type == ENTRY);
                continue;
            }
            for (int h = 0; h < eventsCnt; ++h)
                if (inActiveSet[events_h[h].ind]) {  // Horizontal sweep
                    if (events_h[h].type == ENTRY) {
                        if (cnt++ == 0)
                            first_rect = h;
                    } else if (--cnt == 0) {
                        delta_y = rects[events_h[h].ind][EXIT].y - rects[events_h[first_rect].ind][ENTRY].y;
                        area += delta_x * delta_y;
                    }
                }
            inActiveSet[c.ind] = (c.type == ENTRY);
        }

        cout << area << "\n";
    }
}