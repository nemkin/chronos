rm -rf bin
mkdir bin
cd bin

cmake ../src
make

cd ../docs
pdflatex -output-directory ../bin -jobname nemkin_viktoria_szakdolgozat diploma.tex
pdflatex -output-directory ../bin -jobname nemkin_viktoria_szakdolgozat diploma.tex
pdflatex -output-directory ../bin -jobname nemkin_viktoria_szakdolgozat diploma.tex
pdflatex -output-directory ../bin -jobname nemkin_viktoria_szakdolgozat diploma.tex

