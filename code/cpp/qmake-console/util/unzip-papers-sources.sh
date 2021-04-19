if hash git 2>/dev/null; then
  ar=`git rev-parse --show-toplevel`
else
  ar=../../../..
fi

echo "Setting ar as: " $(realpath $ar)

mkdir -p "$ar/../dev/documents-copy" 
cp "$ar/dev/documents/gen/src-copy.zip" "$ar/../dev/documents-copy"

cd "$ar/../dev/documents-copy"
unzip "src-copy.zip"

for paperName in "ctg" "icg" "itm"
do
  echo "Processing paper: $paperName" 
  mkdir -p "$ar/../dev/documents-copy/$paperName"
  cp -r "$ar/../dev/documents-copy/src-copy/$paperName"/* "$ar/../dev/documents-copy/$paperName" 
done

