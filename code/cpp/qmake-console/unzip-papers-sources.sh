if hash git 2>/dev/null; then
  ar=`git rev-parse --show-toplevel`
else
  ar=../../..
fi

mkdir -p "$ar/../dev/documents-copy" 
cp "$ar/dev/documents/gen/src-copy.zip" "$ar/../dev/documents-copy"

cd "$ar/../dev/documents-copy"
unzip "src-copy.zip"

for paperName in "ctg" "icg" "itm"
do
  echo "Processing paper: $paperName" 
  mkdir -p "$ar/../dev/documents-copy/$paperName"
  cp -r "$ar/../dev/documents-copy/src-copy/$paperName/src" "$ar/../dev/documents-copy/$paperName" 
#  echo "Running GTagML"
#  ./run-with-args.sh gt-module-ir-console $paperName
#  echo "Running PDFLaTeX"
#  cd "$ar/../dev/documents/$paperName/src/setup"; ./run-pdflatex.sh; cd - 
#  echo "Running NGML"
#  ./run-with-args.sh ngml-sdi-console $paperName
#  echo "Done."
done


