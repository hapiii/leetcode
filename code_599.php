<?php

function findRestaurant($list1, $list2) {
    $endArr = array();
    foreach ($list2 as $key=>$value){
        if (in_array($value,$list1)){
            $endArr[array_keys($list1,$value,true)[0] + $key] = $value;
        }
    }
    ksort($endArr);
    echo array_shift($endArr);
    return array_shift($endArr);
}

$list1 = array("Shogun","Tapioca Express","Burger King","KFC");
$list2 = array("Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun");
findRestaurant($list1,$list2);

