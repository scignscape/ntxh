if hash git 2>/dev/null; then
  ar=`git rev-parse --show-toplevel`
else
  ar=../../../..
fi

echo "Setting ar as: " $(realpath $ar)

first_dir=$(pwd)

cd ..

for paperName in "ctg" "icg" "itm"
do
  echo "Processing paper: $paperName" 
  echo "Running GTagML"
  ./run-with-args.sh gt-module-ir-console $paperName
  echo "Running PDFLaTeX (twice, to finalize references)"
  cd "$ar/../dev/documents/$paperName/src/setup"
  chmod a+x ./run-pdflatex.sh
  ./run-pdflatex.sh
  ./run-pdflatex.sh
  cd - 
  echo "Running NGML"
  ./run-with-args.sh ngml-sdi-console $paperName
  cd "$ar/../dev/documents/$paperName/src/setup"
  echo "Running PDFLaTeX (again, to embed sdi files)"
  ./run-pdflatex.sh
  cd - 
  echo "Done."
done

echo "Running the data set preparation."
./run.sh ds-extra

cd $first_dir

echo "Zipping the sources."

cd "$ar/../dev"
zip -r "$ar/dev/documents/gen/src-copy.zip" "src-copy" 
cd -

./run-papers-xpdf-console.sh

