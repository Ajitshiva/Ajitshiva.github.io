import java.util.*;

public class KMP {
    public static int[] computePrefix(String pattern) {
        int m = pattern.length();
        int[] pi = new int[m];
        for (int i = 1, j = 0; i < m; ++i) {
            while (j > 0 && pattern.charAt(i) != pattern.charAt(j))
                j = pi[j - 1];
            if (pattern.charAt(i) == pattern.charAt(j))
                j++;
            pi[i] = j;
        }
        return pi;
    }

    public static void KMP(String text, String pattern) {
        int n = text.length(), m = pattern.length();
        int[] pi = computePrefix(pattern);

        int j = 0;
        for (int i = 0; i < n; ++i) {
            while (j > 0 && text.charAt(i) != pattern.charAt(j))
                j = pi[j - 1];
            if (text.charAt(i) == pattern.charAt(j))
                j++;
            if (j == m) {
                System.out.println("Pattern found at index " + (i - j + 1));
                j = pi[j - 1];
            }
        }
    }

    public static void main(String[] args) {
        String text = "ABABDABACDABABCABAB";
        String pattern = "ABABCABAB";
        KMP(text, pattern);
    }
}
