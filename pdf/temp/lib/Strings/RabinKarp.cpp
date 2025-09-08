@D41 @//source:https://cp-algorithms.com/string/rabin-karp.html
@    @
@295 @vector<int> rabin_karp(string const& s, string const& t) {
@E96 @    const int p = 31;
@3B1 @    const int m = 1e9 + 9;
@2B7 @    int S = s.size(), T = t.size();
@    @
@A00 @    vector<long long> p_pow(max(S, T));
@B60 @    p_pow[0] = 1;
@EFD @    for (int i = 1; i < (int)p_pow.size(); i++)
@1CA @        p_pow[i] = (p_pow[i-1] * p) % m;
@    @
@976 @    vector<long long> h(T + 1, 0);
@6E9 @    for (int i = 0; i < T; i++)
@D4F @        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m;
@554 @    long long h_s = 0;
@109 @    for (int i = 0; i < S; i++)
@161 @        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m;
@    @
@A15 @    vector<int> occurrences;
@FCE @    for (int i = 0; i + S - 1 < T; i++) {
@F0F @        long long cur_h = (h[i+S] + m - h[i]) % m;
@D52 @        if (cur_h == h_s * p_pow[i] % m)
@879 @            occurrences.push_back(i);
@F05 @    }
@831 @    return occurrences;
@5E2 @}
