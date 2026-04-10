#include <stdio.h>
#include <string.h>

#define MAX 100

// Find LCS length using DP
int lcsLength(char *s1, char *s2) {
    int m = strlen(s1);
    int n = strlen(s2);
    int dp[MAX][MAX];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
        }
    }
    return dp[m][n];
}

// Find LCS string using DP
void lcsString(char *s1, char *s2, char *lcs) {
    int m = strlen(s1);
    int n = strlen(s2);
    int dp[MAX][MAX];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
        }
    }

    int index = dp[m][n];
    lcs[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcs[--index] = s1[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
}

int main() {
    char s1[MAX], s2[MAX], lcs[MAX];

    printf("Enter first string: ");
    scanf("%s", s1);
    printf("Enter second string: ");
    scanf("%s", s2);

    int len = lcsLength(s1, s2);
    lcsString(s1, s2, lcs);

    printf("LCS Length: %d\n", len);
    printf("LCS: %s\n", lcs);

    return 0;
}