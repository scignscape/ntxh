if hash git 2>/dev/null; then
  ar=`git rev-parse --show-toplevel`
else
  ar=../../../../..
fi
myld=`cat $ar/../preferred/cytolib-lds`
echo $myld
cd ./cytolib-console; LD_LIBRARY_PATH=$myld:$LD_LIBRARY_PATH ./run-with-args.sh -f $ar/dev/consoles/facs/fcs/demo/Live_cells1.fcs -xskew 100  -yskew 10 -xcolumn 7 -ycolumn 6; cd -;

cd facs-gui; ./run.sh; cd -;
