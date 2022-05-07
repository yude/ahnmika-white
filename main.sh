#!/bin/bash
count=0
trap 'echo $((count)) 人のアンミカ;exit 0' 2

while true
do
  echo 白って$(($RANDOM % 901 + 100))色あんねん
  let count++
done
