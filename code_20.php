<?php
//有效的括号
function isValid($s) {

    if (strlen($s) == 0){
        return true;
    }
    $strArr = str_split($s);
    if (count($strArr)%2 != 0){
        return false;
    }
    $stack = array();
    foreach ($strArr as $key =>$value){
        if ($value == "("){
            array_push($stack ,")");
        }elseif ($value =="[" ){
            array_push($stack ,"]");
        }elseif ($value =="{" ){
            array_push($stack ,"}");
        }elseif (count($stack)==0 || $value!= array_pop($stack)){
            return false;
        }
    }
    return count($stack)==0?true:false;

}
isValid("({})");
print_r(isValid(""));
