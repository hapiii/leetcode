class Solution {
    func mergeAlternately(_ word1: String, _ word2: String) -> String {
        let count = word1.count >= word2.count ? word2.count : word1.count
        var result: String = ""
        for i in 0..<count {
            let range = word1.index(word1.startIndex, offsetBy: i)..<word1.index(word1.startIndex, offsetBy: i+1)
            let aS = word1[range]
            let bS = word2[range]
            result.append(contentsOf: aS)
            result.append(contentsOf: bS)
        }
        if word1.count > count {
            let range = word1.index(word1.startIndex, offsetBy: count)..<word1.endIndex
            result.append(contentsOf: word1[range])
        } else if word2.count > count {
            let range = word2.index(word2.startIndex, offsetBy: count)..<word2.endIndex
            result.append(contentsOf: word2[range])
        }
        
        return result
    }
}

Solution().mergeAlternately("123", "abcdef")

Solution().mergeAlternately("123456", "ab")
