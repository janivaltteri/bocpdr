# Bayesian Online ChangePoint Detection

This is an R package which does changepoint detection in a univariate
time-series using an algorithm presented in:

Perälä, T., Kuparinen, A. 2015. Detecting regime shifts in fish stock dynamics.
Canadian Journal of Fisheries and Aquatic Sciences. DOI: 10.1139/cjfas-2014-040

which is based on:

Adams, R. P., MacKay, D. J. C, 2007. Bayesian online changepoint detection.
arxiv.org/abs/0710.3742

# Installation

1) Download
2) Unzip
3) R CMD build bocpdr/
4) start R
5) install.packages('bocpdr_X.X.X.tar.gz',repos=NULL)

# Usage

```
library(bocpdr)
```
