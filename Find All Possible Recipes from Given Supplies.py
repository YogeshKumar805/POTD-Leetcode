class Solution:
    def findAllRecipes(self, recipes: List[str], ingredients: List[List[str]], supplies: List[str]) -> List[str]:
        
        supplies = set(supplies)
        recipes = dict(zip(recipes, ingredients))
        made = []
        
        # basically check if we can keep making new stuff
        # add to new list of supplies and delete recipe (to not recheck)
        while True:
            # track whether we made progress this iteration
            new_recipe_made = False
            for rcp, igs in [*recipes.items()]:
                if not all(i in supplies for i in igs):
                    # can't be made (with current supplies)
                    continue
                made.append(rcp)
                supplies.add(rcp)
                del recipes[rcp]
                new_recipe_made = True

            if not new_recipe_made: 
                # we obvs. won't make anything new
                break
        return made
