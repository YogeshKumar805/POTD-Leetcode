class Solution:
    def countOfAtoms(self, s: str) -> str:
        s = re.sub(r'([A-Z][a-z]*)(\d)', r'(\1)\2', s)  # O2 -> (O)2
        s = re.sub(r'(\))(\D|$)', r'\g<1>1\2', s)  # (Mg)O -> (Mg)1O
        tk = re.findall(r'[A-Z][a-z]*|\d+|[()]', s)  # (MgCO3)21 -> ( Mg C O 3 ) 21
        cf = []
        m = 1
        cnt = Counter()
        for t in tk[::-1]:
            if t == ')': continue
            if t == '(':
                m //= cf.pop()
                continue
            if t.isnumeric(): 
                cf.append(int(t))
                m *= cf[-1]
                continue
            cnt[t] += m
        return ''.join(str(x) for p in sorted(cnt.items()) for x in p if x != 1)
