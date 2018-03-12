#! /bin/bash

#---------------------------------------
# $Author: ee364f06 $
# $Date: 2018-01-14 17:18:08 -0500 (Sun, 14 Jan 2018) $
#---------------------------------------

# Do not modify above this line.

Num_of_Param=$#
Filename=$1

if [[ $Num_of_Param != 2 ]]
then
    echo "Usage: ./collect_stats.bash <file> <sport>"
    exit 1
elif [[ ! -e $Filename ]]
then
    echo "Error: $Filename does not exist"
    exit 2
else
    #inital all the varaibles
    total_athletes=0
    total_medals=0
    most_medals=0
    most_athletes=0
    #implement while loop
hile read line
    do
        cur_athletes=$(echo $line | cut -d, -f2)
        cur_medals=$(echo $line | cut -d, -f3)
      #  echo "current athletes: $cur_athletes"
       # echo "most_athletes: $most_athletes"
        if [[ $2 == $cur_athletes ]]
        then
            ((total_athletes++))
            ((total_medals=cur_medals+total_medals))
            if (( $most_medals < $cur_medals ))
            then
             #   echo " "
             #   echo "reached here"
                most_athletes=$(echo $line | cut -d, -f1)
                most_medals=$cur_medals
             #   echo "most_athletes: $most_athletes"
             #   echo "cur_athletes: $cur_athletes"
            fi
        fi
    done < $1
    #printout results
    echo "Total athletes: $total_athletes"
    echo "Total medals won: $total_medals"
    echo "$most_athletes won the most medals: $most_medals"
fi
exit 0
