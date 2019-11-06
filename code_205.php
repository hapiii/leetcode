<?php

///新建字典做映射
function isIsomorphic($s, $t) {
    if (strlen($s) != strlen($t)){
        return false;
    }
    $sArr = str_split($s);
    $tArr = str_split($t);
    $sHash = array();
    $tHash = array();
    for ($i = 0; $i<count($sArr);$i++){
        if (array_key_exists($sArr[$i], $sHash) && array_key_exists($tArr[$i], $tHash)){
            if ($sHash[$sArr[$i]] != $tHash[$tArr[$i]]){
                return false;
            }
        }else if (!array_key_exists($sArr[$i], $sHash) && array_key_exists($tArr[$i], $tHash)){
           return false;
        }else if (array_key_exists($sArr[$i], $sHash) && !array_key_exists($tArr[$i], $tHash)){
            return false;
        }
        $sHash[$sArr[$i]] = $i;
        $tHash[$tArr[$i]] = $i;
    }
    return true;
}

///方法二:便利字符串查看第一个的下表
function isIsomorphicc($s, $t) {
    if (strlen($s) != strlen($t)){
        return false;
    }
    $sArr = str_split($s);
    $tArr = str_split($t);
    for ($i = 0; $i<count($sArr);$i++){
        if (array_search($sArr[$i],$sArr) != array_search($tArr[$i], $tArr)){
            print_r($sArr[$i]);
            print_r($tArr[$i]);
            return false;
        }
    }
    return true;
}

$isOK =  isIsomorphicc('egge', 'adde');
echo $isOK;
