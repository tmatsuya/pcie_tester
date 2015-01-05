#!/bin/bash
# KC705 bit image flash script
# usage: kc705_flash top
CMD_FILE=/tmp/$USER_$$
#PROJECT=$1
PROJECT=top

cd runs/$PROJECT.runs/impl_1

promgen -w -p mcs -c FF -data_width 16 -s 131072 -u 0 $PROJECT

echo setMode -bscan >$CMD_FILE
echo setCable -p auto >>$CMD_FILE
echo identify >>$CMD_FILE
echo attachflash -position 1 -bpi "28F00AP30" >>$CMD_FILE
echo assignfiletoattachedflash -position 1 -file $PROJECT.mcs >>$CMD_FILE
echo Program -p 1 -dataWidth 16 -rs1 NONE -rs0 NONE -bpionly -e -v -loadfpga >>$CMD_FILE
echo quit >>$CMD_FILE

#cat $CMD_FILE
impact -batch $CMD_FILE
rm -f $CMD_FILE
