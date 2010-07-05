TEX=latex

all: bc.dvi
pdf: bc.pdf
ps: bc.ps
bib: bc.bbl

bc.dvi: bc.tex driv.tex app.tex

%.bbl: %.bib
	bibtex $(subst .bib$,,$<)
	@rm -f bc.{pdf,dvi,ps}

%.pdf: %.tex driv.tex app.tex
	pdflatex $<

%.ps: %.tex driv.tex app.tex
	pslatex $<
	dvips $(subst .tex$,.dvi,$<) -o$@
	rm $(subst .tex$,.dvi,$<)

clean:
	rm -f bc.{pdf,dvi,toc,aux,log,bbl,blg,ps,out} app.aux driv.aux
