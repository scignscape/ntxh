ar=../../../../..
pdfl=`cat $ar/../preferred/preferred-latex`
echo $pdfl
$pdfl -synctex=1 -interaction=nonstopmode --shell-escape section2.gt.tex

 
