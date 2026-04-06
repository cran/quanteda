# Extracted from test-tokens_xptr.R:383

# setup ------------------------------------------------------------------------
library(testthat)
test_env <- simulate_test_env(package = "quanteda", path = "..")
attach(test_env, warn.conflicts = FALSE)

# prequel ----------------------------------------------------------------------
skip_on_cran()
toks <- tokens(data_corpus_inaugural)
xtoks <- as.tokens_xptr(toks)

# test -------------------------------------------------------------------------
expect_identical(
        lengths(toks),
        lengths(xtoks)
    )
