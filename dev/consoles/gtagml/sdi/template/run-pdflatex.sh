pdfl=`cat %R%/../preferred/preferred-latex`
echo $pdfl
$pdfl -synctex=1 -interaction=nonstopmode --shell-escape -output-dir=out  %F%

 
