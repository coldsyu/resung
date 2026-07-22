


char * mergeAlternately(char * word1, char * word2){
    char *ans = (char*) calloc(256, sizeof(char)); // static char *ans[256];
    size_t n = strlen(word1), m = strlen(word2), i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        ans[k] = word1[i++];
        ans[k + 1] = word2[j++];
        k += 2;
    }
    strcpy(ans + k, i >= n ? word2 + j : word1 + i);
    return ans;
}