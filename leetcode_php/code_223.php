<?php

function computeArea($A, $B, $C, $D, $E, $F, $G, $H)
{
    $w1 = abs($C - $A);
    $h1 = abs($D - $B);

    $w2 = abs($G - $E);
    $h2 = abs($H - $F);

    $totalX = max($C,$G) - min($A,$E);
    $totalH = max($D,$H) - min($B,$F);

    if ($totalX<$w1+$w2 && $totalH <$h1+$h2){

        $widthArr = [$A, $E, $C, $G];
        $heightArr = [$D, $B, $F, $H];

        sort($widthArr);
        sort($heightArr);

        $sw = $widthArr[2] - $widthArr[1];
        $sh = $heightArr[2] - $heightArr[1];

        echo '交叉';
        return $w1 * $h1 + $w2 * $h2 - $sw * $sh;
    }else{
        echo '未交叉';
        return $w1 * $h1 + $w2 * $h2;
    }
}


echo computeArea(-5, 4, 0, 5, -3, -3, 3, 3);

//$wB = abs($G - $A);
//$hB = abs($H - $B);
//
//$wS = abs($G - $E);
//$hS = abs($D - $F);
//
//$w = abs($G - $A) > abs($G - $E)?abs($G - $E):abs($G - $A);
//$h = abs($H - $B) > abs($D - $F)?abs($D - $F):abs($H - $B);
//
//echo '巨型1宽-->'.$w1.'巨型1高-->'.$h1.'巨型2宽--->'.$w2.'巨型2高-->'.$h2.'交叉面积宽--->'.$sw.'交叉面积高--->'.$sh;