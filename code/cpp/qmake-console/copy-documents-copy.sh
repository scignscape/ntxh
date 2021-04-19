if hash git 2>/dev/null; then
  ar=`git rev-parse --show-toplevel`
else
  ar=../../..
fi

cp -R "$ar/../dev/documents-copy" "$ar/../dev/documents"
 


