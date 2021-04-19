if hash git 2>/dev/null; then
  ar=`git rev-parse --show-toplevel`
else
  ar=../../../..
fi

echo "Setting ar as: " $(realpath $ar)

for paperName in "ctg" "icg" "itm"
do
  ../run-with-rest-args.sh xpdf-console "$ar/data/dataset/$paperName/main.pdf"
done

