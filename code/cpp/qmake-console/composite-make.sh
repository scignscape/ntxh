
##  use this script to quickly build enough qmake-console projects to run 
##  a GTagML workflow sufficient to recreate the papers and data set

if hash git 2>/dev/null; then
  ar=`git rev-parse --show-toplevel`
else
  ar=../../..
fi

qmc="$ar/code/cpp/qmake-console/projects"
cd $qmc

echo "Building NTXH projects"
cd ntxh
cd ntxh
./qm.sh
./mk.sh
cd ..
cd ntxh-parser
./qm.sh
./mk.sh
cd ..
cd ntxh-builder
./qm.sh
./mk.sh
cd ..

echo "Building GTagML projects"
cd ..
cd gtagml
./qm.sh
./mk.sh
cd ..
cd gtagml-console
./qm.sh
./mk.sh
cd ..
cd gt-module-ir
./qm.sh
./mk.sh
cd ..
cd gt-module-ir-console
./qm.sh
./mk.sh
cd ..
cd ngml-sdi
./qm.sh
./mk.sh
cd ..
cd ngml-sdi-console
./qm.sh
./mk.sh
cd ..
cd extra
./qm.sh
./mk.sh
cd ..
cd ..

echo "Building QUAZIP projects"
cd quazip
cd quazip
./qm.sh
./mk.sh
cd ..
cd ..

echo "Building XPDF projects"
cd xpdf
cd xpdf
./qm.sh
./mk.sh
cd ..
cd xpdf-console
./qm.sh
./mk.sh
cd ..

cd ..


