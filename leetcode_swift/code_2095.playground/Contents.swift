
//Definition for singly-linked list.
public class ListNode {
    public var val: Int
    public var next: ListNode?
    public init() { self.val = 0; self.next = nil; }
    public init(_ val: Int) { self.val = val; self.next = nil; }
    public init(_ val: Int, _ next: ListNode?) { self.val = val; self.next = next; }
}

class Solution {
    func deleteMiddle(_ head: ListNode?) -> ListNode? {
            if head == nil || head?.next == nil {
                return nil
            }
            var fN: ListNode? = head?.next?.next
            var lN: ListNode? = head
            while (fN?.next != nil) {
                fN = fN?.next?.next
                lN = lN?.next
            }
            lN?.next = lN?.next?.next
            return head
        }
}

class Solutionn {
    func deleteMiddle(_ head: ListNode?) -> ListNode? {
        guard head != nil else {
            return nil
        }
        var result: ListNode? = head
        var s: ListNode? = head
        var f: ListNode? = head

        while f?.next != nil && f?.next?.next != nil {
            s = s?.next
            f = f?.next?.next
        }
        
        s?.next = s?.next?.next

        return result?.next

    }
}


