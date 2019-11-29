<?php

function ambiguousCoordinates($S) {

    $newStr = substr($S, 1, strlen($S)-1);
    $S = substr($newStr, 0, -1);

    for ($i = 1;$i<strlen($S);$i++){
        dealWithStrArr(substr($S,0,$i),substr($S,$i,strlen($S)-$i));
    }
}
function dealWithStrArr($first,$second){
    echo  $first."===".$second."++++";
    if (strlen($first) == 1){
    }
    for ($i = 1;$i<strlen($first);$i++){
        echo  substr($first,0,$i)."DDD".substr($first,$i,strlen($first)-$i);
    }
}

ambiguousCoordinates('(120034)');
