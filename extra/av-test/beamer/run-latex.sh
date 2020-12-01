if hash git 2>/dev/null; then
  ar=`git rev-parse --show-toplevel`
else
  ar=../../..
fi
latex=`cat $ar/../preferred/preferred-latex`
$latex -interaction=nonstopmode --shell-escape $1

