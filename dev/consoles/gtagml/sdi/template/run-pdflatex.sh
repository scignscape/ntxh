pdfl=`cat %R%/../preferred/preferred-latex`
echo $pdfl
TEXINPUTS=%I%:%U%/figures:%U%/extra:: $pdfl -synctex=1 -interaction=nonstopmode --shell-escape -output-dir=out  %F%

 
