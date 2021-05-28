if hash git 2>/dev/null; then
  ar=`git rev-parse --show-toplevel`
else
  ar=../../..
fi

# if $@ empty ...?

qm=${qm/\~\//$HOME/}
`cat $ar/../preferred/preferred-qmake` $@

