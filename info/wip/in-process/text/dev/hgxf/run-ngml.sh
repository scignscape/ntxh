ar=`git rev-parse --show-toplevel`
mywd=`pwd`
cd $ar/code/cpp/qmake-console/projects/htxn/rz-ngml-console
./run-with-args.sh "$mywd" "$mywd/hgxf.ngml" ";$mywd/man"
cd -



