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
  ./run-with-args.sh dsmain-setup $paperName -s
done

cd -


