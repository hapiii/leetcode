<?php
///盛最多水的容器
///暴力解法
function maxAreaa($height) {
    $max = 0;
    for ($i = 0;$i < count($height)-1;$i++){
        for ($j = $i+1;$j < count($height);$j++){
            $max = max($max,min($height[$i],$height[$j])*($j-$i));
        }
    }
    print_r($max);
    return $max;
}
///最优路线
function maxArea($height){
    $maxarea = 0;$l = 0;$r = count($height)-1;
    while ($l<$r){
        $maxarea = max($maxarea,min($height[$l],$height[$r])*($r-$l));
        echo min($height[$l],[$height[$r]]).$r-$l.$maxarea.'======';
        if ($height[$l] < $height[$r]){
            $l++;
        }else{
            $r--;
        }
    }
    return $maxarea;

}

maxArea(array(1,8,6,2,5,4,8,3,7));