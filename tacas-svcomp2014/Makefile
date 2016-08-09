TEX=latex
PROJ=sse2014

all: $(PROJ).dvi
pdf: $(PROJ).pdf
ps: $(PROJ).ps
bib: $(PROJ).bbl

$(PROJ).dvi: $(PROJ).tex FORCE

$(PROJ).tex: $(PROJ).bbl

%.bbl: %.bib
	latex $(patsubst %.bib,%.tex,$<)
	bibtex $(patsubst %.bib,%,$<)
	latex $(patsubst %.bib,%.tex,$<)
	latex $(patsubst %.bib,%.tex,$<)
	@rm -f $(PROJ).{pdf,dvi,ps}

%.pdf: %.tex FORCE
	pdflatex $<

%.ps: %.tex FORCE
	pslatex $<
	dvips $(subst .tex$,.dvi,$<) -o$@
	rm $(subst .tex$,.dvi,$<)

clean:
	rm -f $(PROJ).{pdf,dvi,toc,aux,log,bbl,blg,ps,out}

FORCE:

.PHONY: FORCE
