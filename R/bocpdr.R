## a function that calls the cpp routine for bocpd
cpd <- function(steps,data,parsv){
    if(steps != length(data)) stop('steps has to equal length(data)')
    if(length(parsv) != 5) stop('parsv: c(gamma,kappa,alfa,beta,lambda)')
    require(Rcpp)
    .Call('bocpd',c(steps),data,parsv,PACKAGE='bocpdr')
}

## a wrapper for building the trellis object (triangular matrix)
## from the output
matrixform <- function(n,o){
    mat <- matrix(0.0,nr=n,nc=n)
    starts <- numeric(n); starts[1] <- 1
    ends <- numeric(n)
    for(i in 1:(n-1)){
        ends[i] <- n - i + starts[i]
        starts[i+1] <- ends[i] + 1
    }
    ends[n] <- (n+1)*n/2
    for(i in 1:n){
        mat[i,] <- c(numeric(i-1),o[starts[i]:ends[i]])
    }
    return(mat)
}

