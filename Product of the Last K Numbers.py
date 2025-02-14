class ProductOfNumbers:
    def __init__(self):
        self.pref_prod = [1] # stores product of all previous nums

    def add(self, num: int):
        if num == 0:
            self.pref_prod = [1] # reset, all previous prods are 0
        else:
            self.pref_prod.append(self.pref_prod[-1] * num) # add new product

    def getProduct(self, k: int) -> int:
        if k >= len(self.pref_prod): 
            return 0 # pref_prod doesn't include 0, [k:] would be 0 if wasn't removed

        return self.pref_prod[-1] // self.pref_prod[-k - 1] # total product / prod before k = prod of k
