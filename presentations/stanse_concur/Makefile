TEX=latex
GRAPHS=$(patsubst %.dot,%.pdf,$(wildcard *.dot))

all: pdf
pdf: present.pdf
ps: present.ps

present.dvi: present.tex FORCE

present.tex: $(GRAPHS)

%.pdf: %.tex FORCE
	pdflatex --shell-escape $<

%.ps: %.tex FORCE
	pslatex --shell-escape $<
	dvips $(subst .tex$,.dvi,$<) -o$@
	rm $(subst .tex$,.dvi,$<)

%.pdf: %.dot
	dot -Tpdf -o $@ $^

clean:
	rm -f present.{pdf,dvi,toc,aux,log,bbl,blg,ps,out}

FORCE:

.PHONY: FORCE
