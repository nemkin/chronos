rm -rf build/docs 2>/dev/null
mkdir -p build/docs 2>/dev/null
mkdir bin 2>/dev/null

cd docs

pdflatex -output-directory ../build/docs -jobname thesis diploma.tex
pdflatex -output-directory ../build/docs -jobname thesis diploma.tex
pdflatex -output-directory ../build/docs -jobname thesis diploma.tex
pdflatex -output-directory ../build/docs -jobname thesis diploma.tex

mv ../build/docs/thesis.pdf ../bin

