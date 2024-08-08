class Solution(object):
    
    def spiralMatrixIII(self, R, C, r0, c0):
        ret = [(r0, c0)] 
        is_valid = lambda row, col: row >= 0 and row < R and col >= 0 and col < C 
        
        steps = 1 
        r, c = r0, c0 
        while len(ret) < R * C: 
            # Go east 1
            for step in xrange(steps):
                r, c = r, c + 1 
                if is_valid(r, c): ret.append((r, c))
                    
            # Go down 1 
            for step in xrange(steps):
                r, c = r + 1, c 
                if is_valid(r, c): ret.append((r, c))
                    
            steps += 1
                    
            # Go west 2 
            for step in xrange(steps):
                r, c = r, c - 1
                if is_valid(r, c): ret.append((r, c))           
            
            # Go north 2 
            for step in xrange(steps):
                r, c = r - 1, c 
                if is_valid(r, c): ret.append((r, c))           
                    
            steps += 1
            
        return ret 
