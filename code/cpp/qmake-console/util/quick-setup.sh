
##  a very quick one-step setup if everything works via defaults ... 

echo "Running unzip-preferred.sh"
./unzip-preferred.sh

echo ""
echo "Running composite-make.sh"
./composite-make.sh

echo ""
echo "Running unzip-papers-sources.sh"
./unzip-papers-sources.sh

echo ""
echo "Running copy-documents-copy.sh"
./copy-documents-copy.sh

echo ""
echo "Running run-papers.sh"
./run-papers.sh

