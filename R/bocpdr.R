cpd <- function(steps,data,parsv){
    if(steps != length(data)) stop 'steps has to equal length(data)'
    if(length(pars) != 5) stop 'pars: c(gamma,kappa,alfa,beta,lambda)'
    require(Rcpp)
    .Call('bocpd',c(steps),data,parsv,PACKAGE='bocpdr')
}
