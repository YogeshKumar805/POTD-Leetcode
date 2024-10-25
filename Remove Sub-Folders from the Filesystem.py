class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        # Sort the folders lexicographically
        folder.sort()
        
        # Initialize the result list with no subfolders
        result = []
        
        # Iterate through the sorted folder list
        for f in folder:
            # If result is empty or the current folder is not a subfolder of the last one in result
            if not result or not f.startswith(result[-1] + '/'):
                result.append(f)
        
        return result
