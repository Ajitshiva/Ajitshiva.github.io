#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> computePrefix(const string& pattern) {
    int m = pattern.size();
    vector<int> pi(m);
    for (int i = 1, j = 0; i < m; ++i) {
        while (j > 0 && pattern[i] != pattern[j])
            j = pi[j - 1];
        if (pattern[i] == pattern[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

void KMP(const string& text, const string& pattern) {
    int n = text.size(), m = pattern.size();
    vector<int> pi = computePrefix(pattern);

    for (int i = 0, j = 0; i < n; ++i) {
        while (j > 0 && text[i] != pattern[j])
            j = pi[j - 1];
        if (text[i] == pattern[j])
            j++;
        if (j == m) {
            cout << "Pattern found at index " << i - j + 1 << endl;
            j = pi[j - 1];
        }
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    KMP(text, pattern);
    return 0;
}
