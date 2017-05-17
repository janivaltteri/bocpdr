#include <Rcpp.h>
#include <iostream>
#include <vector>
#include "trim.h"

double prob(const double x, const double g,
	    const double k, const double a,
	    const double b)
{
  double inside, t1, t2, t3, t4;
  double pi = 3.14159265358979323846;
  inside = (x-g)/(b*(k+1)/(a*k));
  t1 = log( pow( 1.0+inside*inside/(2.0*a), -(2.0*a + 1.0)/2.0) );
  t2 = lgamma( (2.0*a + 1.0)/2.0 );
  t3 = lgamma( a );
  t4 = log( sqrt(pi*2.0*a) * (b*(k + 1.0)/(a*k)) ); // check this part!
  return(exp(t1+t2-t3-t4));
}

RcppExport SEXP bocpd(SEXP base, SEXP data, SEXP pars)
{
  int s;
  double gamma, alfa, beta, kappa, lambda;
  double gp, kp, ap, bp, summa;
  std::vector<double> d;
  Rcpp::NumericVector basev(base);
  Rcpp::NumericVector datav(data);
  Rcpp::NumericVector parsv(pars);
  s = basev[0];
  d.resize(s);
  for(int i = 0; i < s; ++i){
    d[i] = datav[i];
  }
  gamma = parsv[0];
  kappa = parsv[1];
  alfa = parsv[2];
  beta = parsv[3];
  lambda = parsv[4];
  trim gmat(s);
  trim kmat(s);
  trim amat(s);
  trim bmat(s);
  trim rlp(s);
  rlp.rcwrite(0,0,1.0);
  gmat.rcwrite(0,0,(kappa*gamma + d[0])/(kappa + 1.0));
  kmat.rcwrite(0,0,kappa + 1.0);
  amat.rcwrite(0,0,alfa + 0.5);
  bmat.rcwrite(0,0,beta + (kappa*(d[0] - gamma)*(d[0] - gamma)) /
	       (2.0 * (kappa + 1.0)));
  for(int i = 1; i < s; ++i){
    for(int j = i; j > -1; j--){
      if(j > 0){
	gp = gmat.rcread(j-1,i-1);
	kp = kmat.rcread(j-1,i-1);
	ap = amat.rcread(j-1,i-1);
	bp = bmat.rcread(j-1,i-1);
	rlp.rcwrite(j,i,rlp.rcread(j-1,i-1)*prob(d[i],gp,kp,ap,bp)*(1.0-(1.0/lambda)));
	gmat.rcwrite(j,i,((kmat.rcread(j-1,i-1)*gmat.rcread(j-1,i-1) + d[i])/
			  (kmat.rcread(j-1,i-1) + 1.0)));
	kmat.rcwrite(j,i,kmat.rcread(j-1,i-1) + 1.0);
	amat.rcwrite(j,i,amat.rcread(j-1,i-1) + 0.5);
	bmat.rcwrite(j,i,bmat.rcread(j-1,i-1) +
		     (kmat.rcread(j-1,i-1)*(d[i] - gmat.rcread(j-1,i-1))*
		      (d[i] - gmat.rcread(j-1,i-1)))/(2.0*(kmat.rcread(j-1,i-1) + 1.0)));
      }else{
	rlp.rcwrite(j,i,1.0/lambda);
	gmat.rcwrite(j,i,(kappa*gamma + d[i])/(kappa + 1.0));
	kmat.rcwrite(j,i,kappa + 1.0);
	amat.rcwrite(j,i,alfa + 0.5);
	bmat.rcwrite(j,i,beta + (kappa*(d[i] - gamma)*(d[i] - gamma)) /
		     (2.0 * (kappa + 1.0)));
      }
    }
    summa = 0.0;
    for(int j = i; j > -1; j--){
      summa += rlp.rcread(j,i);
    }
    for(int j = i; j > -1; j--){
      rlp.rcwrite(j,i,rlp.rcread(j,i)/summa);
    }
  }
  Rcpp::NumericVector ulos(s*(s+1)/2);
  for(int i = 0; i < s*(s+1)/2; ++i){
    ulos[i] = rlp.linearread(i);
  }
  return(ulos);
}
