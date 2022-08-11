# Description of branch: 

This branch is developed as a parallelized version of the backbone package. Currently only `osdsm()` uses parallelization. To run it parallelized you need to set a [future plan](https://future.futureverse.org/reference/plan.html). The following code shows how to do this:

```
future::plan("multisession")
library(progressr)
handlers(global=TRUE)

bb <- osdsm(B, alpha = 0.05,  #An oSDSM backbone...
             class = "igraph", trials = 100, parallel=TRUE)
```

In addition it can make use of [fastglm](https://jaredhuling.org/fastglm/) if installed. If it is installed it defaults to using fastglm, to turn that off set `usefastglm=FALSE`.

# backbone <img src='man/figures/logo.png' align="right" height="139" />

<!-- badges: start -->

[![](https://www.r-pkg.org/badges/version/backbone?color=orange)](https://cran.r-project.org/package=backbone)
[![](http://cranlogs.r-pkg.org/badges/grand-total/backbone?color=blue)](https://cran.r-project.org/package=backbone)
[![](http://cranlogs.r-pkg.org/badges/last-month/backbone?color=green)](https://cran.r-project.org/package=backbone)
[![DOI:10.1371/journal.pone.0269137](http://img.shields.io/badge/DOI-10.1371/journal.pone.0269137-B31B1B.svg)](https://doi.org/10.1371/journal.pone.0269137)
<!-- badges: end -->

## Welcome
The backbone package implements methods to extract the *backbone* of a network, which is a sparse and unweighted subgraph that contains only the most ‘important’ or ‘significant’ edges. A backbone can be useful when the original network is too dense, when edge weights are not needed, or when edge weights are difficult to interpret. Methods are available for:

* Weighted bipartite projections
* Non-projection weighted networks
* Unweighted networks

In addition, the package implements some other utility functions to:

* Randomize matrices while preserving the row and column sums
* Estimate the Bipartite Configuration Model (BiCM)

For more details on these functions and methods, please see:

* Neal, Z.P. (2022). backbone: An R package to extract network backbones. *PLoS ONE, 17*, e0269137. <https://doi.org/10.1371/journal.pone.0269137>
* Neal, Z.P., Domagalski, R., and Sagan, B. (2021). Comparing Alternatives to the Fixed Degree Sequence Model for Extracting the Backbone of Bipartite Projections. *Scientific Reports, 11*, 23929. <https://doi.org/10.1038/s41598-021-03238-3>
* [www.rbackbone.net](https://www.zacharyneal.com/backbone)

## Installation
The /release branch contains the current CRAN release of the backbone package. You can install it from [CRAN](https://CRAN.R-project.org) with:
``` r
install.packages("backbone")
```

The /devel branch contains the working beta version of the next release of the backbone package. All the functions are documented and have undergone various levels of preliminary debugging, so they should mostly work, but there are no guarantees. Feel free to use the devel version (with caution), and let us know if you run into any problems. You can install it You can install from GitHub with:
``` r
library(devtools)
install_github("zpneal/backbone", ref = "devel", build_vignettes = TRUE)
```
