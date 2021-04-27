
##  use this script to quickly build enough qmake-console projects to run 
##  a GTagML workflow sufficient to recreate the papers and data set

if hash git 2>/dev/null; then
  ar=`git rev-parse --show-toplevel`
else
  ar=../../../..
fi

echo "Setting ar as: " $(realpath $ar)

qmc="$ar/code/cpp/qmake-console/projects"
cd $qmc


echo "Building NTXH projects"
cd ntxh
cd ntxh
chmod a+x ./qm.sh
./qm.sh
chmod a+x ./mk.sh
./mk.sh
cd ..
cd ntxh-parser
chmod a+x ./qm.sh
./qm.sh
chmod a+x ./mk.sh
./mk.sh
cd ..
cd ntxh-builder
chmod a+x ./qm.sh
./qm.sh
chmod a+x ./mk.sh
./mk.sh
cd ..
cd ..

echo ""
echo "Building QUAZIP projects"
cd quazip
cd quazip
chmod a+x ./qm.sh
./qm.sh
chmod a+x ./mk.sh
./mk.sh
cd ..
cd ..


echo ""
echo "Building GTagML projects"
cd gtagml
cd gtagml
chmod a+x ./qm.sh
./qm.sh
chmod a+x ./mk.sh
./mk.sh
cd ..
cd ngml-sdi
chmod a+x ./qm.sh
./qm.sh
chmod a+x ./mk.sh
./mk.sh
cd ..
cd ..

echo ""

echo "Building DGH projects"
cd dgh-sdi
cd dgh-sdi
chmod a+x ./qm.sh
./qm.sh
chmod a+x ./mk.sh
./mk.sh
cd ..
cd ..

echo ""
echo "Resuming GTagML projects"
cd gtagml
cd ngml-sdi-console
chmod a+x ./qm.sh
./qm.sh
chmod a+x ./mk.sh
./mk.sh
cd ..
cd gtagml-console
chmod a+x ./qm.sh
./qm.sh
chmod a+x ./mk.sh
./mk.sh
cd ..
cd gt-module-ir
chmod a+x ./qm.sh
./qm.sh
chmod a+x ./mk.sh
./mk.sh
cd ..
cd gt-module-ir-console
chmod a+x ./qm.sh
./qm.sh
chmod a+x ./mk.sh
./mk.sh
cd ..
cd ..

cd dataset
cd ds-extra
chmod a+x ./qm.sh
./qm.sh
chmod a+x ./mk.sh
./mk.sh
cd ..
cd ..

echo ""
echo "Building XPDF projects"
cd xpdf
cd xpdf
chmod a+x ./qm.sh
./qm.sh
chmod a+x ./mk.sh
./mk.sh
cd ..
cd xpdf-console
chmod a+x ./qm.sh
./qm.sh
chmod a+x ./mk.sh
./mk.sh
cd ..
cd ..


echo ""
echo "Building Dataset projects"
cd QScign
cd qring
chmod a+x ./qm.sh
./qm.sh
chmod a+x ./mk.sh
./mk.sh
cd ..
cd ..
cd dgdb
cd qh-package
chmod a+x ./qm.sh
./qm.sh
chmod a+x ./mk.sh
./mk.sh
cd ..
cd ..
cd dataset
cd dsmain
chmod a+x ./qm.sh
./qm.sh
chmod a+x ./mk.sh
./mk.sh
cd ..
cd dsmain-setup
chmod a+x ./qm.sh
./qm.sh
chmod a+x ./mk.sh
./mk.sh
cd ..
cd ..


