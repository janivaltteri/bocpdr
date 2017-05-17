\name{cpd}
\alias{bocpd}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{
Bayesian Online ChangePoint Detection
}
\description{
%%  ~~ A concise (1-5 lines) description of what the function does. ~~
}
\usage{
coming up
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{data}{
%%     ~~Describe \code{data} here~~
}
  \item{ker}{
%%     ~~Describe \code{ker} here~~
}
}
\details{
%%  ~~ If necessary, more details than the description above ~~
}
\value{
%%  ~Describe the value returned
%%  If it is a LIST, use
%%  \item{comp1 }{Description of 'comp1'}
%%  \item{comp2 }{Description of 'comp2'}
%% ...
}
\references{
  Perälä, T., Kuparinen, A. 2015. Detecting regime shifts in fish stock dynamics.
  Canadian Journal of Fisheries and Aquatic Sciences. 10.1139/cjfas-2014-040

  Adams, R. P., MacKay, D. J. C, 2007. Bayesian online changepoint detection.
  arxiv.org/abs/0710.3742
}
\author{
Jani Anttila
}
\note{
%%  ~~further notes~~
}

%% ~Make other sections like Warning with \section{Warning }{....} ~

\seealso{
%% ~~objects to See Also as \code{\link{help}}, ~~~
}
\examples{
  cpd(5,c(1.0,2.0,1.0,5.0,6.0),c(1.0,1.0,1.0,1.0,10.0))
}

% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{ ~kwd1 }
\keyword{ ~kwd2 }% __ONLY ONE__ keyword per line
