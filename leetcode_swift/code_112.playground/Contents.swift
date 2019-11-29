
 public class TreeNode {
    public var val: Int
    public var left: TreeNode?
    public var right: TreeNode?
    public init(_ val: Int) {
        self.val = val
        self.left = nil
        self.right = nil
    }
 }
 
 class Solution {
    
    var i = 0
    var node =  createNodeList(i)
    func hasPathSum(_ root: TreeNode?, _ sum: Int) -> Bool {
       
     return true
    }
    
 }


    func createNodeList(_ i:inout Int) -> TreeNode {
        i = i + 1
        var node = TreeNode.init(8)
        if i < 7 {
            node.left = createNodeList(&i)
            node.right = createNodeList(&i)
        }
       
        return node
    }




