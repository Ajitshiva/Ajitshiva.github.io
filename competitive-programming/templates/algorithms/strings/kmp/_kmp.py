def compute_prefix(pattern):
    m = len(pattern)
    pi = [0] * m
    j = 0
    for i in range(1, m):
        while j > 0 and pattern[i] != pattern[j]:
            j = pi[j - 1]
        if pattern[i] == pattern[j]:
            j += 1
        pi[i] = j
    return pi

def KMP(text, pattern):
    n, m = len(text), len(pattern)
    pi = compute_prefix(pattern)

    j = 0
    for i in range(n):
        while j > 0 and text[i] != pattern[j]:
            j = pi[j - 1]
        if text[i] == pattern[j]:
            j += 1
        if j == m:
            print("Pattern found at index", i - j + 1)
            j = pi[j - 1]

text = "ABABDABACDABABCABAB"
pattern = "ABABCABAB"
KMP(text, pattern)
