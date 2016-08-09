TEX=latex

all: pdf
pdf: analysis.pdf
ps: analysis.ps

analysis.dvi: analysis.tex FORCE

analysis.tex:

%.pdf: %.tex FORCE
	pdflatex $<

%.ps: %.tex FORCE
	pslatex $<
	dvips $(subst .tex$,.dvi,$<) -o$@
	rm $(subst .tex$,.dvi,$<)

clean:
	rm -f analysis.{pdf,dvi,toc,aux,log,bbl,blg,ps,out}

FORCE:

.PHONY: FORCE
