#include <stdio.h>
#include <string.h>
#define EMPTY -1

int hash(int k, int m) {
    return k % m;
}

int main() {
    int m, q;
    scanf("%d", &m);
    scanf("%d", &q);

    int table[m];
    for (int i = 0; i < m; i++)
        table[i] = EMPTY;

    while (q--) {
        char op[10];
        int key;
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            int i = 0;
            while (i < m) {
                int idx = (hash(key, m) + i * i) % m;
                if (table[idx] == EMPTY) {
                    table[idx] = key;
                    break;
                }
                i++;
            }
        } else if (strcmp(op, "SEARCH") == 0) {
            int i = 0, found = 0;
            while (i < m) {
                int idx = (hash(key, m) + i * i) % m;
                if (table[idx] == EMPTY)
                    break;
                if (table[idx] == key) {
                    found = 1;
                    break;
                }
                i++;
            }
            if (found) printf("FOUND\n");
            else printf("NOT FOUND\n");
        }
    }

    return 0;
}