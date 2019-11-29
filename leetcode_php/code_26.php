<?php

function removeDuplicates(&$nums) {
    array_unique($nums,1);
    print_r($nums);
    return$nums;
}
$arr = array(1,2,2);
removeDuplicates($arr);
