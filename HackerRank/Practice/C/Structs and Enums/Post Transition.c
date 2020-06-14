#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_all_packages(town t) {
    printf("%s:\n", t.name);
    for (int i = 0; i < t.offices_count; ++i) {
        printf("\t%d:\n", i);
        post_office* o = &t.offices[i];
        for (int j = 0; j < o->packages_count; ++j) {
            printf("\t\t%s\n", o->packages[j].id);
        }
    }
}

void send_all_acceptable_packages(town* s, int si, town* t, int ti) {
    post_office* sp = &s->offices[si];
    post_office* tp = &t->offices[ti];
    int S = 0;
    int T = tp->packages_count;
    package* pkgS = malloc(S * sizeof (package));
    package* pkgT = tp->packages;
    for (int i = 0; i < sp->packages_count; ++i) {
        int w = sp->packages[i].weight;
        if ((tp->min_weight <= w) && (w <= tp->max_weight)) {
            ++T;
            pkgT = realloc(pkgT, T * sizeof (package));
            pkgT[T-1] = sp->packages[i];
        } else {
            ++S;
            pkgS = realloc(pkgS, S * sizeof (package));
            pkgS[S-1] = sp->packages[i];
        }
    }
    sp->packages = pkgS;
    tp->packages = pkgT;
    sp->packages_count = S;
    tp->packages_count = T;
}

town town_with_most_packages(town* towns, int towns_count) {
    int ans = -1;
    int ret = 0;
    for (int i = 0; i < towns_count; ++i) {
        town* t = &towns[i];
        int cnt = 0;
        for (int j = 0; j < t->offices_count; ++j) {
            cnt += t->offices[j].packages_count;
        }
        if (cnt > ans) {
            ans = cnt;
            ret = i;
        }
    }
    return towns[ret];
}

town* find_town(town* towns, int towns_count, char* name) {
    for (int i = 0; i < towns_count; ++i) {
        town* t = &towns[i];
        if (strcmp(t->name, name) == 0) {
            return t;
        }
    }
    return NULL;
}
