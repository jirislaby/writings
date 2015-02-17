TEX=latex
ifeq ("$(NH)", "")
	HANDOUT = ",handout"
endif

all: pdf
pdf: present.pdf
ps: present.ps

present.dvi: present.tex FORCE

present.tex: class.tex

class.tex: FORCE
	@echo "\documentclass[xcolor=dvipsnames$(HANDOUT)]{beamer}" > class.tex

%.pdf: %.tex FORCE
	pdflatex $<

%.ps: %.tex FORCE
	pslatex $<
	dvips $(subst .tex$,.dvi,$<) -o$@
	rm $(subst .tex$,.dvi,$<)

clean:
	rm -f present.{pdf,dvi,toc,aux,log,bbl,blg,ps,out}

FORCE:

.PHONY: FORCE all pdf ps clean
