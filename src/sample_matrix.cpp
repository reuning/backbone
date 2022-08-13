// [[Rcpp::depends(RcppArmadillo)]]

#include <RcppArmadilloExtensions/sample.h>

using namespace Rcpp;

// [[Rcpp::export]]
IntegerVector sample_matrix(NumericMatrix x) {
  int n = x.nrow();
  int max_choice = x.ncol() -1 ;
  IntegerVector choice_set = seq(1,max_choice);

  choice_set.push_back(0);
  IntegerVector result(n);
  for ( int i = 0; i < n; ++i ) {
    Rcpp::NumericVector probs(x(i, _));
    result[i] = RcppArmadillo::sample(choice_set, 1, true, probs)[0];
  }
  return result;
}



// You can include R code blocks in C++ files processed with sourceCpp
// (useful for testing and development). The R code will be automatically
// run after the compilation.
//

/*** R

mat <- matrix(runif(n = 18, 0, 1), 6, 3)
sample_matrix(mat)
*/
