TEX=latex
NAME=studentska_zprava_10_slaby.utf8

all: $(NAME).dvi
pdf: $(NAME).pdf
ps: $(NAME).ps

$(NAME).dvi: $(NAME).tex FORCE

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
