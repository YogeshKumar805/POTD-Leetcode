class Solution:
    def maxBottlesDrunk(self, num_bottles: int, num_exchange: int) -> int:
        drank = 0
        empty_bottles = 0
        
        while num_bottles > 0:
            while num_bottles > 0 and empty_bottles < num_exchange:
                drank += 1
                empty_bottles += 1
                num_bottles -= 1
                
            if empty_bottles == num_exchange:
                num_exchange += 1
                empty_bottles = 0
                num_bottles += 1
                    
        return drank
