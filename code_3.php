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
            array_values($headArr);

            $headArr[] = $arr[$i];

        } else {///不包含，追加
            $headArr[] = $arr[$i];
        }

        if ($i == count($arr) - 1) {
            $endArr[] = $headArr;
        }

    }

    $len = 0;
    for ($j = 0; $j < count($endArr); $j++) {

        $endTArr = $endArr[$j];
        if (count($endTArr) > $len) {
            $len = count($endTArr);

        }
    }
    return $len;

}

echo lengthOfLongestSubstring("ohvehjdml");
///3 abc
//strstr

