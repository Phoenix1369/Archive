#include <cstdio>
#include <cstring>
#include <deque>
#include <map>
#define x first
#define y second
const int MAXA = 26;
const int MAXN = 1e4+5;
std::deque<int> pre;
int cnt[MAXA]{ }, inq[MAXA]{ }, need[MAXA]{ }, skip[MAXA]{ };
char s[MAXN];
int L;

void add_back(int i) { ++inq[s[i]-'a']; pre.push_back(i); }
void pop_back(int d) { --inq[d]; pre.pop_back(); }
void pop_head(int d) { --inq[d]; pre.pop_front(); }

int main()
{
    scanf("%s", s);
    L = strlen(s);
    for(int i = 0; i < L; ++i)
        ++cnt[s[i]-'a'];
    for(int i = 0; i < MAXA; ++i) if(cnt[i])
        need[i] = (cnt[i] /= 2);
    for(int i = L-1; i >= 0; --i)
    {    // Monotonic Queue
        int di = s[i]-'a';
        if(need[di] && (inq[di] < need[di]))
        {    // Greedy: Push least, skip large
            while(!pre.empty() && (s[i] < s[pre.back()]))
                pop_back(s[pre.back()]-'a');
            add_back(i);
        }
        if(++skip[di] <= cnt[di]) continue;
        // Cannot skip
        while(!pre.empty())
        {
            int j = pre.front();
            int dj = s[j]-'a';
            pop_head(dj);
            putchar(s[j]);
            --need[dj];
            --skip[dj];
            // Take s[i] once
            if(dj == di) break;
        }
    }
    return 0;
}
