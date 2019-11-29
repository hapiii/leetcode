<?php

/*
 * 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
*/
/**
 * @param Integer[] $nums
 * @return Integer
 */
function singleNumber($nums) {

    $endArr = array();
    foreach ($nums as $key=>$num){

        print_r($nums);
        if ($nums[0] == $num && $key!= 0){
            unset($nums[$key]);
            unset($nums[0]);
            print_r($endArr);
            $endArr = array_values($nums);
            singleNumber($endArr);
        }

    }
    print_r($endArr);
    return $endArr[0];
}

singleNumber(array(1,3,5,5,1,3,2));