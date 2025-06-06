test_that("bootstrap_dfm works with character and corpus objects", {
    
    txt <- c(textone = "This is a sentence.  Another sentence.  Yet another.",
             texttwo = "Premiere phrase.  Deuxieme phrase.",
             textthree = "Sentence three is really short.")
    corp <- corpus(txt,
                   docvars = data.frame(country = c("UK", "USA", "UK"), 
                                        year = c(1990, 2000, 2005)))
    toks <- tokens(corpus_reshape(corp, to = "sentences"))
    dfmt <- dfm(toks)
    
    set.seed(10)
    bs <- bootstrap_dfm(dfmt, n = 10)
    expect_equal(bs[[1]], 
                 dfm_group(dfmt))
    
    # are feature names of resamples identical?
    expect_identical(
        featnames(bs[[1]]),
        featnames(bs[[2]])
    )

    # are document names of resamples identical?
    expect_identical(
        docnames(bs[[1]]),
        docnames(bs[[2]])
    )
    
    expect_error(bootstrap_dfm(dfmt, n = -1), 
                 "The value of n must be between 0 and Inf")
})

test_that("bootstrap_dfm works as planned with dfm", {
    
    txt <- c(textone = "This is a sentence.  Another sentence.  Yet another.",
             texttwo = "Premiere phrase.  Deuxieme phrase.")
    corp <- corpus(txt, 
                   docvars = data.frame(country = c("UK", "USA"), year = c(1990, 2000)))
    dfmt <- dfm(tokens(corpus_reshape(corp, to = "sentences")))
    
    set.seed(10)
    bs <- bootstrap_dfm(dfmt, n = 3, verbose = FALSE)
    expect_equivalent(bs[[1]], 
                      dfm_group(dfmt))
    
    # are feature names of resamples identical?
    expect_identical(
        featnames(bs[[1]]),
        featnames(bs[[2]])
    )
    # are document names of resamples identical?
    expect_identical(
        docnames(bs[[1]]),
        docnames(bs[[2]])
    )
})

test_that("verbose messages work", {
    
    txt <- c(textone = "This is a sentence.  Another sentence.  Yet another.",
             texttwo = "Premiere phrase.  Deuxieme phrase.",
             textthree = "Sentence three is really short.")
    corp <- corpus(txt)
    
    # sentences
    toks <- tokens(corpus_reshape(corp, to = "sentences"))
    dfmt <- dfm(toks)
    expect_message(
        bootstrap_dfm(dfmt, n = 1, verbose = TRUE),
        "resampling and forming dfms: 0"
    )
    
    # documents
    toks2 <- tokens(corp)
    dfmt2 <- dfm(toks2)
    expect_warning(
        bootstrap_dfm(dfmt2, n = 1, verbose = TRUE),
        "x must contain sentences for bootstrapping"
    )
    
    # segments
    toks3 <- tokens(corpus_segment(corp, pattern = "."))
    dfmt3 <- dfm(toks3)
    expect_message(
        bootstrap_dfm(dfmt3, n = 1, verbose = TRUE),
        "resampling and forming dfms: 0"
    )
    
})
