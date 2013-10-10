TEX=latex

all: cve.dvi cv.dvi
pdf: cve.pdf cv.pdf
ps: cve.ps

%.pdf: %.tex
	pdflatex $<

%.ps: %.tex
	pslatex $<
	dvips $(subst .tex$,.dvi,$<) -o$@
	rm $(subst .tex$,.dvi,$<)

clean:
	rm -f cv{,e}.{pdf,dvi,toc,aux,log,bbl,blg,ps,out}
