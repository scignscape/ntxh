myld=`cat ../../../../../../preferred/cytolib-lds`
echo $myld
cd ./cytolib-console; LD_LIBRARY_PATH=$myld:$LD_LIBRARY_PATH ./run-with-args.sh -f ../../../extra/facs/fcs/demo/Live_cells1.fcs -xskew 100  -yskew 10 -xcolumn 7 -ycolumn 6; cd -;

cd facs-gui; ./run.sh; cd -;
