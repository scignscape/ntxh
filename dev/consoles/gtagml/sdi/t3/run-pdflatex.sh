ar=../../../../..
pdfl=`cat $ar/../preferred/preferred-latex`
echo $pdfl
$pdfl -synctex=1 -interaction=nonstopmode --shell-escape t3.tex

 
