pdfl=`cat %R%/../preferred/preferred-latex`
pdfl=${pdfl/\~/$HOME/}
echo $pdfl
TEXINPUTS=%I%:%U%/figures:%U%/extra:: $pdfl -jobname=%J% -synctex=1 -interaction=nonstopmode --shell-escape -output-dir=../../out  %F%

 
