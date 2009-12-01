TEX=latex

all: teze.dvi
pdf: teze.pdf
ps: teze.ps
bib: teze.bbl

teze.dvi: teze.tex

teze.tex: teze.bbl

%.bbl: %.bib
	latex $(patsubst %.bib,%.tex,$<)
	bibtex $(subst .bib$,,$<)
	latex $(patsubst %.bib,%.tex,$<)
	latex $(patsubst %.bib,%.tex,$<)
	@rm -f teze.{pdf,dvi,ps}

%.pdf: %.tex
	pdflatex $<

%.ps: %.tex
	pslatex $<
	dvips $(subst .tex$,.dvi,$<) -o$@
	rm $(subst .tex$,.dvi,$<)

clean:
	rm -f teze.{pdf,dvi,toc,aux,log,bbl,blg,ps,out}
