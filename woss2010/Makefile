TEX=latex
NAME=woss2010

all: $(NAME).dvi
pdf: $(NAME).pdf
ps: $(NAME).ps
bib: $(NAME).bbl

$(NAME).dvi: $(NAME).tex FORCE

$(NAME).tex: $(NAME).bbl

%.bbl: %.bib
	latex $(patsubst %.bib,%.tex,$<)
	bibtex $(subst .bib$,,$<)
	latex $(patsubst %.bib,%.tex,$<)
	latex $(patsubst %.bib,%.tex,$<)
	@rm -f $(NAME).{pdf,dvi,ps}

%.pdf: %.tex FORCE
	pdflatex $<

%.ps: %.tex FORCE
	pslatex $<
	dvips $(subst .tex$,.dvi,$<) -o$@
	rm $(subst .tex$,.dvi,$<)

clean:
	rm -f $(NAME).{pdf,dvi,toc,aux,log,bbl,blg,ps,out}

FORCE:

.PHONY: FORCE
