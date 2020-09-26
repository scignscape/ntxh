#ar=`git rev-parse --show-toplevel`
ar=../../..
# if $@ empty ...?
`cat $ar/../preferred/preferred-qmake` $@

