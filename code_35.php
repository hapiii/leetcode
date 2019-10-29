<?php
/**
 * @param Integer[] $nums
 * @param Integer $target
 * @return Integer
 */


function searchInsertCount($target,$start,$end,$nums){

    $midd = $start +ceil( ($end - $start) / 2);
    if ($nums[$midd]<$target){
        return searchInsertCount($target,$midd,$end,$nums);
    }else if($nums[$midd] == $target){
        return $midd;
    }else{
        return searchInsertCount($target,$start,$midd,$nums);
    }
}

//function searchInsert($nums, $target) {
//
//
//    return searchInsertCount($target,0,count($nums)-1,$nums);
//
//}

//二分查找法
function searchInsert($nums,$target){

    $height=count($nums)-1;
    $low=0;
    while($low<=$height){
        $mid=floor(($low+$height)/2);//获取中间数
        if($nums[$mid]==$target){
            return $mid;//返回
        }else if ($nums[count($nums)-1]<$target){
            return count($nums);
        }else if ($nums[0]>$target){
            return 0;
        }else if ($nums[$mid]<$target&&$nums[$mid+1]>$target){
            return $mid+1;
        }else if ($nums[$mid]>$target&&$nums[$mid-1]<$target){
            return $mid;
        }elseif($nums[$mid]<$target){
            $low=$mid+1;
        }elseif($nums[$mid]>$target){
            $height=$mid-1;
        }else{
            return 0;
        }
    }

}

$arr = array(1,3,5,6);
echo  searchInsert($arr,4);