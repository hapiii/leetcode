//旋转数组

    
    func rotate(_ nums: inout [Int], _ k: Int) {
        if k == 0 {
            return
        }
        for i  in 1...k {
            nums.insert(nums[nums.count-1], at: 0)
            nums.remove(at: nums.count - 1)
        }
    }
    
    var arr = [1]
    rotate(&arr,0)
    



