# Extracted from test-tokens.R:1307

# setup ------------------------------------------------------------------------
library(testthat)
test_env <- simulate_test_env(package = "quanteda", path = "..")
attach(test_env, warn.conflicts = FALSE)

# prequel ----------------------------------------------------------------------
quanteda_options("tokens_tokenizer_word" = "word3")

# test -------------------------------------------------------------------------
skip_if_installed("torch")
