import UIKit

func rotate(_ matrix: inout [[Int]]) {
  
}
/* 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合
 * n = 4, k = 2
 */

var endArr = [[Int]]()

func combinee(_ index: Int, _ k: Int,basicArr:inout [Int] , tempArr:inout [Int]) {
    if tempArr.count == k {
        endArr.append(tempArr)
    }else{
         tempArr.append(basicArr[index])
         basicArr.remove(at: index)
        print("tempArr",tempArr)
        print("basicArr",basicArr)
        combinee(index, k, basicArr: &basicArr, tempArr: &tempArr)
    }
}
    
func combine(_ n: Int, _ k: Int) -> [[Int]] {
    
    if n<=0 || k<=0 || n < k {
        return []
    }
    
    var basicArr = [Int]()
    for i in 0...n+1 {
        basicArr.append(i)
    }
   
    var tempArr = [Int]()
    
    for i in 0...k+1 {
        basicArr.remove(at: 0)
        var res =  basicArr
        print("res",res)
        combinee(0, k, basicArr: &res,tempArr: &tempArr)
        
        tempArr = []
        res = []
    }
    return endArr;
    
}

 print(combine(4, 2))
