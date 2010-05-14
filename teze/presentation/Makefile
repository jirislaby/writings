TEX=latex

all: pdf
pdf: obhajoba.pdf
ps: obhajoba.ps

obhajoba.dvi: obhajoba.tex FORCE

obhajoba.tex:

%.pdf: %.tex FORCE
	pdflatex $<

%.ps: %.tex FORCE
	pslatex $<
	dvips $(subst .tex$,.dvi,$<) -o$@
	rm $(subst .tex$,.dvi,$<)

clean:
	rm -f obhajoba.{pdf,dvi,toc,aux,log,bbl,blg,ps,out}

FORCE:

.PHONY: FORCE
