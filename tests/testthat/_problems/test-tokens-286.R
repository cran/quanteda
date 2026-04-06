# Extracted from test-tokens.R:286

# setup ------------------------------------------------------------------------
library(testthat)
test_env <- simulate_test_env(package = "quanteda", path = "..")
attach(test_env, warn.conflicts = FALSE)

# prequel ----------------------------------------------------------------------
quanteda_options("tokens_tokenizer_word" = "word3")

# test -------------------------------------------------------------------------
expect_equal(unlist(tokens(c(doc1 = "aaa bbb cccc", doc2 = "aaa bbb dddd"))),
                 c(doc11 = "aaa", doc12 = "bbb", doc13 = "cccc",
                   doc21 = "aaa", doc22 = "bbb", doc23 = "dddd"))
expect_equal(unlist(tokens(c(doc1 = "aaa bbb cccc", doc2 = "aaa bbb dddd")), use.names = FALSE),
                 c("aaa", "bbb", "cccc", "aaa", "bbb", "dddd"))
