<?php
///反转字符串中的单词 III
function reverseWords($s) {
    $arr = [];
    $str = "";
    for($i=strlen($s)-1;$i>=0;$i--){
        //echo $s[$i].'=====>';//当然也可以这么写$str{$i}

        if ($s[$i] == ' '){
            $arr[] = $str;
            echo $str;
            $str = "";
        }
    }
    return implode(' ',$arr);
}
//echo '<br>';
echo  reverseWords("Let's take LeetCode contest");

?>