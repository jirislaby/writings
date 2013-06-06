TEX=latex

all: posudek.dvi
pdf: posudek.pdf

posudek.dvi: posudek.tex

%.pdf: %.tex
	pdflatex $<

%.ps: %.tex
	pslatex $<
	dvips $(subst .tex$,.dvi,$<) -o$@
	rm $(subst .tex$,.dvi,$<)

clean:
	rm -f posudek.{pdf,dvi,toc,aux,log,bbl,blg,ps,out}
