if hash git 2>/dev/null; then
  ar=`git rev-parse --show-toplevel`
else
  ar=../../..
fi
qm=`cat $ar/../preferred/preferred-qmake`
qm=${qm/\~/$HOME/}
qtv=`$qm -query QT_VERSION`
qtv=${qtv/./-}
qtv=${qtv/./-}
echo $qtv
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./targets/targets-${qtv}-qmake-console ./targets/targets-${qtv}-qmake-console/$1 $@

