class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if (haystack == NULL || needle == NULL) {
            return NULL;
        }
        if (*needle == '\0') {
            return haystack;
        }
        return kmp(haystack, needle);
    }

    char *kmp(char *haystack, char *needle) {
        int len_h = strlen(haystack);
        int len_n = strlen(needle);
        // kmp table
        int * T = (int *)malloc(sizeof(int) * len_n);
        kmp_table(needle, T, len_n);

        int ph, pn;
        ph = pn = 0;
        while ((ph + pn) < len_h) {
            if (needle[pn] == haystack[ph + pn]) {
                if (pn == (len_n - 1)) {
                    return haystack + ph;
                }
                pn++;
            } else {
                ph = ph + pn - T[pn];
                if (T[pn] > -1) {
                    pn = T[pn];
                } else {
                    pn = 0;
                }
            }
        }
        // kmp search
        // clear
        free(T);
        return NULL;
    }

    void kmp_table (const char* words, int T[], int len) {
        int pos = 2;
        int cnd = 0;
        T[0] = -1;
        T[1] = 0;
        while (pos < len) {
            if (words[pos - 1] == words[cnd]) {
                cnd++;
                T[pos] = cnd;
                pos++;
            } else if (cnd > 0) {
                cnd = T[cnd];
            } else {
                T[pos] = 0;
                pos++;
            }   
        }
    }
};