<?php
//在排序数组中查找元素的第一个和最后一个位置
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function searchRange($nums, $target) {
        if (count($nums) == 0){
            return array(-1,-1);
        }
        $s = new  Solution();
        $mid = $s->searchMidRange($nums,$target,0,count($nums)-1);

        if ($nums[$mid] != $target){
            return array(-1,-1);
        }
        $begin = $mid;
        $end  = $mid;
        while ($begin >=0 &&$nums[$begin] >= $target){
            $begin--;
        }
        while ($end < count($nums) && $nums[$end] <= $target){
            $end++;
        }
            return [$begin+1,$end-1];
    }

    function searchMidRange($nums, $target,$start,$end) {

        $mid = $start+floor(($end-$start)/2);
        $s = new  Solution();
        if ($nums[$mid] > $target && $end-$start > 1){
            return $s->searchMidRange($nums,$target, $start, $mid);
        }else if($nums[$mid] < $target && $end-$start > 1){
            return $s->searchMidRange($nums,$target,$mid+1, $end);
        }else{
            if ($nums[$end] == $target){
                return $end;
            }elseif ($nums[$start] == $target){
                return $start;
            }else{
                return $mid;
            }
        }
    }
}

$arr = array(0,1);
$s = new  Solution();
$s->searchRange($arr,1);
