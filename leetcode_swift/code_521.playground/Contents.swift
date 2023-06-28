class Solution {
    func findLUSlength(_ a: String, _ b: String) -> Int {
        if a == b {
            return -1
        }else{
            return a.count>=b.count ? a.count:b.count;
        }
       
    }
}

Solution().findLUSlength("123", "12")


