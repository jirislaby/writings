\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{DG-report}[2009/12/17 author: hopet, version: 0.9] 

\LoadClass[a4paper,11pt]{article}

\RequirePackage[T1]{fontenc}
\RequirePackage[utf8]{inputenc}
\usepackage{lmodern}
\RequirePackage[czech]{babel}
\RequirePackage{pslatex}
%% \RequirePackage{fancyheadings}      %% Old LaTeX
\RequirePackage{fancyhdr}           %% New LaTeX

\RequirePackage{url}
\RequirePackage{paralist}


\RequirePackage{color}

\textwidth          170mm
\textheight         245mm
\oddsidemargin      -5.5mm
\evensidemargin     -5.5mm
\topmargin          -13mm

\renewcommand{\refname}{\vspace{-20mm}}

\rhead[\fancyplain{}{\bfseries DC-}\thepage/\pageref{KONEC}]
      {\fancyplain{}{\bfseries DC-}\thepage/\pageref{KONEC}}
\cfoot{}

\pagestyle{fancy}

%% \input{uv}

\AtBeginDocument{%
\renewcommand{\refname}{\vspace*{-12mm}}
}

\newcommand{\student}[5]{\subsection*{Student: #1}
\def\empty{}%
\def\nazevdisertace{#5}%
Školitel: #2\\
Škola: #3\\
Ročník: #4\\
\ifx\nazevdisertace\empty%
\else
Předpokládaný název disertace: #5
\fi
}

\newcommand{\absolvent}[5]{\subsection*{Student: #1}
\def\empty{}%
\def\nazevdisertace{#5}%
Školitel: #2\\
Škola: #3\\
Ročník: #4\\
\ifx\nazevdisertace\empty%
\else
Název disertace: #5
\fi
}

\newcommand{\dizertace}[4]{
\noindent Student: {\bf #1}\\
Školitel: #2\\
Fakulta: #3\\
Název disertační práce: #4\\
}

\newcommand{\kratkeinfo}{\subsubsection*{Krátká informace o~studentovi:}}
\newcommand{\publikace}{\subsubsection*{Seznam publikačních a realizačních výstupů:}}
\newcommand{\ucast}{\subsubsection*{Účast na seminářích:}}
\newcommand{\zahcestyzprojektu}{\subsubsection*{Zprávy ze zahraničních cest studentů hrazených z~projektu:}}
\newcommand{\zahcestymimoprojekt}{\subsubsection*{Zahraniční cesty studentů hrazené mimo projekt:}}
\newcommand{\duvodukonceni}{\subsubsection*{Důvod ukončení působení v projektu:}}

