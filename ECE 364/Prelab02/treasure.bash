#! /bin/bash

#---------------------------------------
# $Author: ee364f06 $
# $Date: 2018-01-22 15:19:57 -0500 (Mon, 22 Jan 2018) $
#---------------------------------------

# Do not modify above this line.
map=$1
if [[ $# != 1 ]]
then
    echo "Usage: ./treasure.bash <filename>"
    exit 1
fi

tens=0
unit=0

num_1=$( head -n 1 $map | cut -d' ' -f1 | cut -c 1 )
num_2=$( head -n 1 $map | cut -d' ' -f1 | cut -c 2 )
#echo "num_1: $num_1 num_2: $num_2"

while [[ !(($tens == $num_1) && ($unit == $num_2)) ]]
do
    echo "($tens,$unit)"
    (( tens=$tens + 1 ))
    (( unit=$unit + 1 ))
  #  echo " $tens $unit"
    tens_2=$( head -n $tens $map | tail -n 1 | cut -d " " -f $unit | cut -c 1 )
    unit_2=$( head -n $tens $map | tail -n 1 | cut -d " " -f $unit | cut -c 2 )
 #   echo " $tens $unit"
 #   echo "tens_2: $tens_2 unit_2: $unit_2"
    (( tens_2=$tens_2 + 1 ))
    (( unit_2=$unit_2 + 1 ))
 #    echo "tens_2: $tens_2 unit_2: $unit_2"
     num_1=$( head -n $tens_2 $map | tail -n 1 | cut -d " " -f $unit_2 | cut -c 1 )
     num_2=$( head -n $tens_2 $map | tail -n 1 | cut -d " " -f $unit_2 | cut -c 2 )
# echo "num_1 : $num_1 num_2: $num_2"
    (( tens=$tens_2 - 1 ))
    (( unit=$unit_2 - 1 )) 
done
   echo "($tens,$unit)"
   echo "Treasure found at: ($tens,$unit)"


exit 0
#0,0
#0,2
#1,0
#2,2