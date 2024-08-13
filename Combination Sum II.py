class Solution(object):
    def combinationSum2(self, candidates, target):
        sum2combination=[]
        sizeCandidates=len(candidates)
        candidates.sort()
        def solve(idx,candidateList,sum): 
            if sum==target:
                sum2combination.append(candidateList)
                return 
            for candidate in range(idx,sizeCandidates):
                candidatesTraverse=candidates[candidate]
                sumCandidates=sum+candidatesTraverse
                if candidate>idx and candidatesTraverse==candidates[candidate-1]:
                    continue
                if sumCandidates>target:
                    break
                solve(candidate+1,candidateList+[candidatesTraverse],sumCandidates)
        solve(0,[],0)
        return sum2combination
