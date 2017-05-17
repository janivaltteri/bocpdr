cpd <- function(steps,data,parsv){
    if(steps != length(data)) stop('steps has to equal length(data)')
    if(length(parsv) != 5) stop('parsv: c(gamma,kappa,alfa,beta,lambda)')
    require(Rcpp)
    .Call('bocpd',c(steps),data,parsv,PACKAGE='bocpdr')
}

## add a wrapper for building the trellis object (triangular matrix)
## from the output