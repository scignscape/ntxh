if hash git 2>/dev/null; then
  ar=`git rev-parse --show-toplevel`
else
  ar=../../../..
fi

echo "Setting ar as: " $(realpath $ar)

cp "$ar/preferred/preferred-zip.zip" "$ar/temp"

cd "$ar/temp"
unzip "preferred-zip.zip"

cp -R "./preferred-zip/preferred" "$ar/.."



