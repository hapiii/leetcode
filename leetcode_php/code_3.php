<?php
//输入: "abcabcbb"
//输出: 3

/**
 * @param String $s
 * @return Integer
 */


function lengthOfLongestSubstring($s)
{

    if (strlen($s) == 0) {
        return 0;
    }
    $arr = str_split($s);
    $headArr = array();
    $longest = 0;

    for ($i = 0; $i < count($arr); $i++) {

        if (in_array($arr[$i], $headArr)) {///数组中包含
            $endArr[] = $headArr;

            $startKey = 0;
            //找到一样字符串在headArr的下表
            foreach ($headArr as $key => $value) {
                if ($value == $arr[$i]) {
                    $startKey = $key;
                }
            }
            
            foreach ($headArr as $key => $value) {
                if ($key <= $startKey) {
                    unset($headArr[$key]);
                }
            }
            ///遇到重复保存到最后的数组中
            array_values($headArr);

            $headArr[] = $arr[$i];

        } else {///不包含，追加
            $headArr[] = $arr[$i];
        }

        if ($i == count($arr) - 1) {
            $endArr[] = $headArr;
        }

    }

    //🏪数组，找出最长的
    $len = 0;
    for ($j = 0; $j < count($endArr); $j++) {

        $endTArr = $endArr[$j];
        if (count($endTArr) > $len) {
            $len = count($endTArr);

        }
    }
    return $len;

}

function lengthOfLongestSubstringg($s){
    if (strlen($s) == 0){
        return 0;
    }
     $n = strlen($s);
     $set = array();
     $ans = 0;$i =0;$j=0;
     while ($i<$n && $j<$n){
         print_r($set);
         if (!in_array(substr($s,$j,1),$set)){
             echo '不包含';
             $set[] = substr($s,$j++,1);
             $ans = max($ans,$j-$i);
         }else {
             echo '包含'.substr($s,$i,1);
             foreach ($set as $key=>$value)
             {
                 if ($value === substr($s,$i,1)){
                     unset($set[$key]);
                }
            }
             $i++;
             array_values($set);
         }
    }
    return $ans;
}
echo lengthOfLongestSubstringg("defwwd");
///3 abc
//strstr

