class Solution:
    def maximumTotalDamage(self, power: List[int]) -> int:        
        counter = Counter(power)
        power_cnt = []
        for p in sorted(counter.keys()):
            power_cnt.append((p, counter[p]))        
        cache = {}
        def getMaxDamage(index):
            if index in cache:
                return cache[index]
            if index >= len(power_cnt):
                return 0          
            notDamage = getMaxDamage(index + 1)
            curPower, curCnt = power_cnt[index] 
            nxtIndex = bisect.bisect_left(power_cnt, (curPower+3, -1))
            damage = curPower * curCnt + getMaxDamage(nxtIndex)
            cache[index] = max(notDamage, damage)
            return cache[index]        
        return getMaxDamage(0)
