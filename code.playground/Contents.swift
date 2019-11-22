import UIKit

func isIsomorphic(_ s: String, _ t: String) -> Bool {
    var arr = ["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"];
    
    var numA = [Int]();
    for  i in s {
        arr.index(of: i);
      print(i)
    }
    return true;
}

isIsomorphic("egge", "addb");
