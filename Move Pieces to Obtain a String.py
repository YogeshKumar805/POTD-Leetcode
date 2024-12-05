class Solution:
    def canChange(self, start: str, target: str) -> bool:
        # Remove '_' characters and check if the relative order of 'L' and 'R' is the same
        if start.replace('_', '') != target.replace('_', ''):
            return False

        # Check the relative positions of 'L' and 'R'
        start_L_positions = []
        start_R_positions = []
        target_L_positions = []
        target_R_positions = []

        for i in range(len(start)):
            if start[i] == 'L':
                start_L_positions.append(i)
            elif start[i] == 'R':
                start_R_positions.append(i)
            if target[i] == 'L':
                target_L_positions.append(i)
            elif target[i] == 'R':
                target_R_positions.append(i)

        # Check L positions (should only move to the left)
        for s_pos, t_pos in zip(start_L_positions, target_L_positions):
            if s_pos < t_pos:
                return False

        # Check R positions (should only move to the right)
        for s_pos, t_pos in zip(start_R_positions, target_R_positions):
            if s_pos > t_pos:
                return False

        return True
