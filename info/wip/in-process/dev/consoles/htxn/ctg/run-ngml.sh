ar=`git rev-parse --show-toplevel`
mywd=`pwd`
cd $ar/cpp/qmake-console/projects/htxn/rz-ngml-console
./run-with-args.sh $mywd $mywd/ctg.ngml
cd -



