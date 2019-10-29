<?php

/**
 * @param Integer[] $nums
 * @param Integer $val
 * @return Integer
 */
function removeElement(&$nums, $val) {

    foreach ($nums as $key => $num){
        if ($num == $val){
            unset($nums[$key]);
        }
    }
    return count($nums);
}

$arr = array(2,5,8,9,4,6,5,11,8,8,8);
$var = 8;

echo removeElement($arr,$var);