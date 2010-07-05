TEX=latex

all: prez.dvi
pdf: prez.pdf
ps: prez.ps

bc.dvi: bc.tex driv.tex app.tex

%.pdf: %.tex
	pdflatex $<

%.ps: %.tex
	pslatex $<
	dvips $(subst .tex$,.dvi,$<) -o$@
	rm $(subst .tex$,.dvi,$<)

clean:
	rm -f prez.{pdf,dvi,toc,aux,log,bbl,blg,ps,out}
