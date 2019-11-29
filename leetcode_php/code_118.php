<?php
/*
 *
 * 输入: 5
输出:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/
function generate($numRows) {
$endArr = array();

for ($i = 0; $i<$numRows;$i++){

    for ($j = 0; $j<=$i;$j++){

        if ($j == 0 || $j == $i){
            $tempArr[] = 1;
        }else{
            $lastArr = $endArr[$i-1];
            $tempArr[] = $lastArr[$j-1]+$lastArr[$j];
        }
    }
    $endArr[] = $tempArr;
    unset($tempArr);
    }

return $endArr;
}

print_r(generate(1));