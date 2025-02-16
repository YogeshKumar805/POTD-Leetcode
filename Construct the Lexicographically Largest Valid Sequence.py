class Solution:
    def constructDistancedSequence(self, n: int) -> List[int]:
        len_seq = 2 * n - 1 # 1 occurs once, 2-n appear twice
        seq = [0] * len_seq # init with empty vals
        used = set() # tracks nums used in seq

        def backtrack(i):
            if i == len_seq: return True # filled all of sequence
            if seq[i]: return backtrack(i + 1) # already filled index, check next

            for num in range(n, 0, -1): # try using num at index, n to 1 for lexicographically largest seq
                if num in used: continue # already used num in sequence

                nxt = i + num if num > 1 else i # second occurance of num, nxt = i if num = 1 so 1 occurance

                if nxt >= len_seq or seq[nxt] != 0: continue # invalid second index
                
                seq[i] = seq[nxt] = num # set two occurances of num
                used.add(num)

                if backtrack(i + 1): # try to fill rest of sequence
                    return True

                seq[i] = seq[nxt] = 0 # couldn't fill rest, reset seq
                used.remove(num)

            return False # no num option lead to valid sequence

        backtrack(0) # start backtrack at 0 index
        return seq 
