LATEX=pdflatex
LATEX_FLAGS+= -halt-on-error -file-line-error

all: thesis.pdf

thesis.pdf: parts/* thesis.tex
	mkdir -p build
	$(LATEX) $(LATEX_FLAGS) -output-directory build thesis.tex
	$(LATEX) $(LATEX_FLAGS) -output-directory build thesis.tex
	mv build/thesis.pdf thesis.pdf
