#include <stdio.h>

int sobrevivente(int n, int k) {
    int vivo = 0;
    for(int i = 2; i <= n; i++) {
        vivo = (vivo + k) % i;
    }
    return vivo + 1;
}

int main() {
    int NC, n, k;
    scanf("%d", &NC);

    for (int i = 1; i <= NC; i++) {
        scanf("%d %d", &n, &k);
        printf("Case %d: %d\n", i, sobrevivente(n, k));
    }

    return 0;
}
