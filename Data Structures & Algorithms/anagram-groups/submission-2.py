class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagram = defaultdict(list)
        result = []
        for word in strs:
            sorted_word = tuple(sorted(word))  
            anagram[sorted_word].append(word)
        for key in anagram:
            result.append(anagram[key])
        return result