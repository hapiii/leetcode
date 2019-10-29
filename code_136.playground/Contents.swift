import UIKit

func singleNumber(_ nums: [Int]) -> Int {
    var a = 0
    for num in nums {
        print(a,num)
        a = a ^ num
        print(a)
    }
    
    return a
}

singleNumber([1,2,2])
