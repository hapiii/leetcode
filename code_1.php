<?php
$arr = array(2,5,9,4,6,5,11,8);
$count = 6;

function getCountID( $arr, $count)
{

    for ($i = 0; $i < count($arr); $i++) {

        for ($j = $i+1; $j < count($arr); $j++) {
            if ($arr[$i] + $arr[$j] == $count) {
                echo $i.$j;
               return [$i,$j];
            }

        }
    }
}

$indexArr = getCountID($arr, $count);
