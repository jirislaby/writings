TEX=latex

all: dp.dvi
pdf: dp.pdf
ps: dp.ps
bib: dp.bbl

dp.tex: dp.bbl

%.bbl: %.bib
	bibtex $(subst .bib$,,$<)
	@rm -f dp.{pdf,dvi,ps}

%.pdf: %.tex
	pdflatex $<

%.ps: %.tex
	pslatex $<
	dvips $(subst .tex$,.dvi,$<) -o$@
	rm $(subst .tex$,.dvi,$<)

clean:
	rm -f dp.{pdf,dvi,toc,aux,log,bbl,blg,ps,out}
