class Solution(object):
    def dividePlayers(self, skill):
        """
        :type skill: List[int]
        :rtype: int
        """
        skill.sort()
        left, right = 0, len(skill) - 1
        team_skill = skill[left] + skill[right]
        total_chemistry = 0
        while left < right:
            if team_skill != skill[left] + skill[right]:
                return -1
            total_chemistry += skill[left] * skill[right]
            left += 1
            right -= 1
        return total_chemistry
