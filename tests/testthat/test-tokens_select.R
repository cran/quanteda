test_that("test that tokens_select is working", {
    txt <- c(doc1 = "This IS UPPER And Lower case",
             doc2 = "THIS is ALL CAPS aNd sand")
    toks <- tokens(txt)

    feats_fixed <- c("and", "is")

    expect_equivalent(
        as.list(tokens_select(toks, feats_fixed, selection = "remove", valuetype = "fixed", case_insensitive = TRUE)),
        list(c("This", "UPPER", "Lower", "case"), c("THIS", "ALL", "CAPS", "sand"))
    )

    expect_equivalent(
        as.list(tokens_select(toks, feats_fixed, selection = "keep", valuetype = "fixed", case_insensitive = TRUE)),
        list(c("IS", "And"), c("is", "aNd"))
    )

    expect_equivalent(
        as.list(tokens_select(toks, feats_fixed, selection = "remove", valuetype = "fixed", case_insensitive = FALSE)),
        list(c("This", "IS", "UPPER", "And", "Lower", "case"), c("THIS", "ALL", "CAPS", "aNd", "sand"))
    )

    expect_equivalent(
        as.list(tokens_select(toks, feats_fixed, selection = "keep", valuetype = "fixed", case_insensitive = FALSE)),
        list(character(), c("is"))
    )

    feats_regex <- c("is$", "and")

    expect_equivalent(
        as.list(tokens_select(toks, feats_regex, selection = "remove", valuetype = "regex", case_insensitive = FALSE)),
        list(c("IS", "UPPER", "And", "Lower", "case"), c("THIS", "ALL", "CAPS", "aNd"))
    )

    expect_equivalent(
        as.list(tokens_select(toks, feats_regex, selection = "keep", valuetype = "regex", case_insensitive = FALSE)),
        list(c("This"), c("is", "sand"))
    )

    feats_glob <- c("*is*", "?and")

    expect_equivalent(
        as.list(tokens_select(toks, feats_glob, selection = "remove", valuetype = "glob", case_insensitive = TRUE)),
        list(c("UPPER", "And", "Lower", "case"), c("ALL", "CAPS", "aNd"))
    )

    expect_equivalent(
        as.list(tokens_select(toks, feats_glob, selection = "keep", valuetype = "glob", case_insensitive = TRUE)),
        list(c("This", "IS"), c("THIS", "is", "sand"))
    )

    feats_multi <- list(c("this", "is"))

    expect_equivalent(
        as.list(tokens_select(toks, feats_multi, selection = "remove", valuetype = "fixed", case_insensitive = TRUE)),
        list(c("UPPER", "And", "Lower", "case"), c("ALL", "CAPS", "aNd", "sand"))
    )

    expect_equivalent(
        as.list(tokens_select(toks, feats_multi, selection = "keep", valuetype = "fixed", case_insensitive = TRUE)),
        list(c("This", "IS"), c("THIS", "is"))
    )

})


test_that("tokens_select with padding = TRUE is working", {
    toks <- tokens(c(txt1 = "This is a sentence.", txt2 = "This is a second sentence."),
                   remove_punct = TRUE)
    toks_list <- as.list(tokens_select(toks, c("is", "a", "this"), selection = "keep", padding = TRUE))
    expect_equal(toks_list$txt1[4], "")
    expect_equal(toks_list$txt2[4:5], c("", ""))

    toks_list <- as.list(tokens_select(toks, c("is", "a", "this"), selection = "remove", padding = TRUE))
    expect_equal(toks_list$txt1[1:3], c("", "", ""))
    expect_equal(toks_list$txt2[1:3], c("", "", ""))
})

test_that("tokens_select reduces the types appropriately", {
    ## see issue/PR #416
    toks <- tokens(c(doc1 = "This is a SAMPLE text", doc2 = "this sample text is better"))
    feats <- c("this", "sample", "is")
    expect_setequal(types(tokens_select(toks, feats, selection = "keep")),
                    c("This", "is", "SAMPLE", "this", "sample"))
    expect_setequal(types(tokens_select(toks, feats, selection = "keep", case_insensitive = FALSE)),
                    c("is", "this", "sample"))
})
test_that("tokens_remove works on \"\" with tokens containing padding", {
    toks <- tokens(c(doc1 = "a b c d e f g"))
    toks <- tokens_remove(toks, c("b", "e"), padding = TRUE)
    expect_equal(as.character(tokens_remove(toks, c("a", "g"))),
                 c("", "c", "d", "", "f"))
    expect_equal(as.character(tokens_remove(toks, "")),
                 c("a", "c", "d", "f", "g"))
})
test_that("tokens_select works on \"\" with tokens containing padding", {
    toks <- tokens(c(doc1 = "a b c d e f g"))
    toks <- tokens_remove(toks, c("b", "e"), padding = TRUE)
    expect_equal(as.character(tokens_select(toks, c("a", "b", ""))),
                 c("a", "", ""))
})


test_that("fcm works on tokens containing padding", {
    toks <- tokens(c(doc1 = "a b c d e f g",
                     doc2 = "f a c c f g b"))
    toks <- tokens_remove(toks, c("b", "e"), padding = TRUE)
    expect_equal(featnames(fcm(toks)), c("", "a", "c", "d", "f", "g"))
})
test_that("tokens_remove works regardless when features are overlapped, issue #711", {
    toks <- tokens("one two three four")
    expect_equal(as.list(tokens_remove(toks, pattern = c("one", "two", "three"))),
                 list(text1 = "four"))
    expect_equal(as.list(tokens_remove(toks, pattern = c("one", "two three"))),
                 list(text1 = c("two", "three", "four")))
    expect_equal(as.list(tokens_remove(toks, pattern = c("one two", "two three"))),
                 as.list(toks))
    expect_equal(as.list(tokens_remove(toks, pattern = c("one two", "two three four"))),
                 as.list(toks))
    # for phrases
    expect_equal(as.list(tokens_remove(toks, pattern = phrase(c("one two", "two three")))),
                 list(text1 = "four"))
    expect_equal(as.list(tokens_remove(toks, pattern = phrase(c("one two", "two three four")))),
                 list(text1 = character()))
})


txt <- c(d1 = "a b c d e g h",  d2 = "a b e g h i j")
toks_uni <- tokens(txt)
dfm_uni <- dfm(toks_uni)
toks_bi <- tokens(txt) |> tokens_ngrams(n = 2, concatenator = " ")
dfm_bi <- dfm(toks_bi)
char_uni <- c("a", "b", "g", "j")
char_bi <- c("a b", "g j")
list_uni <- list("a", "b", "g", "j")
list_bi <- list("a b", "g j")
dict_uni <- dictionary(list(one = c("a", "b"), two = c("g", "j")))
dict_bi <- dictionary(list(one = "a b", two = "g j"))
# coll_bi <- textstat_collocations(toks_uni, size = 2, min_count = 2)
# coll_tri <- textstat_collocations(toks_uni, size = 3, min_count = 2)[1, ]

test_that("tokens_select works as expected for unigrams selected on char, list of unigrams", {
    expect_equal(
        as.list(tokens_select(toks_uni, char_uni)),
        list(d1 = c("a", "b", "g"), d2 = c("a", "b", "g", "j"))
    )
    expect_equal(
        tokens_select(toks_uni, list_uni),
        tokens_select(toks_uni, char_uni)
    )
    expect_equal(
        as.list(tokens_select(toks_uni, c("a b", "c", "g j"))),
        list(d1 = "c", d2 = character())
    )
})

test_that("tokens_select works as expected for unigrams selected on char, list of bigrams", {
    expect_equal(
        as.list(tokens_select(toks_uni, char_bi)),
        list(d1 = character(), d2 = character())
    )
    expect_equal(
        as.list(tokens_select(toks_uni, list_bi)),
        list(d1 = character(), d2 = character())
    )
    expect_equal(
        tokens_select(toks_uni, list_bi),
        tokens_select(toks_uni, char_bi)
    )
    expect_equal(
        as.list(tokens_select(toks_uni, phrase(char_bi))),
        list(d1 = c("a", "b"), d2 = c("a", "b"))
    )
})

test_that("tokens_select works as expected for bigrams selected on char, list of unigrams", {
    expect_equal(
        as.list(tokens_select(toks_bi, char_uni)),
        list(d1 = character(), d2 = character())
    )
    expect_equal(
        tokens_select(toks_bi, list_uni),
        tokens_select(toks_bi, char_uni)
    )
    expect_silent(
        tokens_select(toks_uni, list(c("a b", "c"), "g j"))
    )
    expect_equal(
        as.list(tokens_select(toks_uni, list(c("a b", "c"), "g j"))),
        list(d1 = character(), d2 = character())
    )
    expect_equal(
        as.list(tokens_select(toks_uni, list(c("a b", "c"), "g j"), padding = TRUE)),
        list(d1 = rep("", 7), d2 = rep("", 7))
    )
})


test_that("tokens_select works as expected for bigrams selected on char, list of bigrams", {
    expect_equal(
        as.list(tokens_select(toks_bi, char_bi)),
        list(d1 = "a b", d2 = "a b")
    )
    expect_equal(
        as.list(tokens_select(toks_bi, list_bi)),
        list(d1 = "a b", d2 = "a b")
    )
    expect_equal(
        tokens_select(toks_bi, list_bi),
        tokens_select(toks_bi, char_bi)
    )
    expect_equal(
        as.list(tokens_select(toks_bi, list(c("a b", "b e"), "g j"))),
        list(d1 = character(0), d2 = c("a b", "b e"))
    )
})

# test_that("tokens_select works correctly with collocations objects", {
#     expect_equal(
#         as.list(tokens_select(toks_uni, coll_bi$collocation)),
#         list(d1 = character(), d2 = character())
#     )
#     expect_equal(
#         as.list(tokens_remove(toks_uni, phrase(coll_bi$collocation))),
#         list(d1 = c("c", "d"), d2 = c("i", "j"))
#     )
#     expect_equal(
#         as.list(tokens_remove(toks_uni, coll_bi)),
#         as.list(tokens_remove(toks_uni, phrase(coll_bi$collocation)))
#     )
#     expect_equal(
#         as.list(tokens_select(toks_uni, coll_tri$collocation)),
#         list(d1 = character(), d2 = character())
#     )
#     expect_equal(
#         as.list(tokens_select(toks_bi, coll_bi$collocation)),
#         list(d1 = c("a b", "e g", "g h"), d2 = c("a b", "e g", "g h"))
#     )
#     expect_equal(
#         as.list(tokens_select(toks_bi, phrase(coll_bi$collocation))),
#         list(d1 = character(), d2 = character())
#     )
#     expect_equal(
#         as.list(tokens_select(toks_bi, phrase(coll_bi$collocation))),
#         as.list(tokens_select(toks_bi, coll_bi))
#     )
#     expect_equal(
#         as.list(tokens_select(toks_bi, coll_tri)),
#         list(d1 = character(), d2 = character())
#     )
#     expect_silent(
#         tokens_select(toks_bi, coll_tri)
#     )
# })


test_that("tokens_select fails as expected with dfm objects", {
    expect_error(tokens_select(toks_uni, dfm_uni))
    expect_error(tokens_select(toks_uni, dfm_bi))
    expect_error(tokens_select(toks_bi, dfm_uni))
    expect_error(tokens_select(toks_bi, dfm_bi))
})


test_that("tokens_select on unigrams works as expected when padding = TRUE", {
    expect_equal(
        as.list(tokens_select(toks_uni, "c d e", padding = TRUE)),
        list(d1 = rep("", 7), d2 = rep("", 7))
    )
    expect_equal(
        as.list(tokens_select(toks_uni, list("c d e"), padding = TRUE)),
        list(d1 = rep("", 7), d2 = rep("", 7))
    )
    expect_equal(
        as.list(tokens_select(toks_uni, list(c("c", "d", "e")), padding = TRUE)),
        list(d1 = c("", "", "c", "d", "e", "", ""), d2 = rep("", 7))
    )

    # expect_equal(
    #     as.list(tokens_select(toks_uni, coll_bi$collocation, padding = TRUE)),
    #     list(d1 = rep("", 7), d2 = rep("", 7))
    # )
    #
    # expect_equal(
    #     as.list(tokens_select(toks_uni, phrase(coll_bi$collocation), padding = TRUE)),
    #     list(d1 = c("a", "b", "", "", "e", "g", "h"),
    #          d2 = c("a", "b", "e", "g", "h", "", ""))
    # )
    #
    # expect_equal(
    #     as.list(tokens_select(toks_uni, phrase(coll_bi$collocation), padding = TRUE)),
    #     as.list(tokens_select(toks_uni, coll_bi, padding = TRUE))
    # )
    #
    expect_equal(
        as.list(tokens_select(toks_uni, list_bi, padding = TRUE)),
        list(d1 = rep("", 7), d2 = rep("", 7))
    )
})

test_that("tokens_select on bigrams works as expected when padding = TRUE", {
    expect_equal(
        as.list(tokens_select(toks_bi, "c d e", padding = TRUE)),
        list(d1 = rep("", 6), d2 = rep("", 6))
    )
    expect_equal(
        as.list(tokens_select(toks_bi, list("c d e"), padding = TRUE)),
        list(d1 = rep("", 6), d2 = rep("", 6))
    )
    expect_equal(
        as.list(tokens_select(toks_bi, list(c("c", "d", "e")), padding = TRUE)),
        list(d1 = rep("", 6), d2 = rep("", 6))
    )
    expect_equal(
        as.list(tokens_select(toks_uni, phrase("c d e"), padding = TRUE)),
        list(d1 = c("", "", "c", "d", "e", "", ""), d2 = rep("", 7))
    )
    expect_silent(
        as.list(tokens_select(toks_bi, list(c("c", "d", "e")), padding = TRUE))
    )

    # expect_equal(
    #     as.list(tokens_select(toks_bi, coll_bi$collocation, padding = TRUE)),
    #     list(d1 = c("a b", "", "", "", "e g", "g h"),
    #          d2 = c("a b", "", "e g", "g h", "", ""))
    # )
    #
    # expect_equal(
    #     as.list(tokens_select(toks_bi, phrase(coll_bi$collocation), padding = TRUE)),
    #     list(d1 = rep("", 6), d2 = rep("", 6))
    # )
    #
    # expect_equal(
    #     as.list(tokens_select(toks_bi, phrase(coll_bi$collocation), padding = TRUE)),
    #     as.list(tokens_select(toks_bi, coll_bi, padding = TRUE))
    # )
    #
    # expect_silent(
    #     as.list(tokens_select(toks_bi, coll_bi, padding = TRUE))
    # )
})

test_that("tokens_select output works as planned", {
    txt <- c(wash1 <- "Fellow citizens, I am again called upon by the voice of my country to
                   execute the functions of its Chief Magistrate.",
             wash2 <- "When the occasion proper for it shall arrive, I shall endeavor to express
             the high sense I entertain of this distinguished honor.")
    toks <- tokens(txt)
    dfm <- dfm(toks)

    expect_message(
        tokens_remove(toks, stopwords("english"), verbose = TRUE),
        "tokens_remove() changed", fixed = TRUE
    )
    expect_message(
        tokens_select(toks, stopwords("english"), verbose = TRUE),
        "tokens_keep() changed", fixed = TRUE
    )
    expect_message(
        tokens_select(toks, stopwords("english"), padding = TRUE, verbose = TRUE),
        "tokens_keep() changed", fixed = TRUE
    )
})


test_that("tokens_select works when window sizes are given ", {
    toks <- tokens("a b c d e f g h i")
    expect_equal(as.list(tokens_select(toks, "c", window = 1)),
                 list(text1 = c("b", "c", "d")))
    expect_equal(as.list(tokens_select(toks, "c", window = 2)),
                 list(text1 = c("a", "b", "c", "d", "e")))
    expect_equal(as.list(tokens_select(toks, "c", window = 10)),
                 list(text1 = c("a", "b", "c", "d", "e", "f", "g", "h", "i")))
    expect_equal(as.list(tokens_select(toks, "c", window = c(1, 2))),
                 list(text1 = c("b", "c", "d", "e")))
    expect_equal(as.list(tokens_select(toks, "c", window = c(0, 1))),
                 list(text1 = c("c", "d")))
    expect_equal(as.list(tokens_select(toks, "c", window = c(1, 0))),
                 list(text1 = c("b", "c")))
    expect_equal(as.list(tokens_select(toks, "c", padding = TRUE, window = c(1, 2))),
                 list(text1 = c("", "b", "c", "d", "e", "", "", "", "")))

    expect_equal(as.list(tokens_remove(toks, "c", window = 1)),
                 list(text1 = c("a", "e", "f", "g", "h", "i")))
    expect_equal(as.list(tokens_remove(toks, "c", window = 2)),
                 list(text1 = c("f", "g", "h", "i")))
    expect_equal(as.list(tokens_remove(toks, "c", window = 10)),
                 list(text1 = character()))
    expect_equal(as.list(tokens_remove(toks, "c", window = c(1, 2))),
                 list(text1 = c("a", "f", "g", "h", "i")))
    expect_equal(as.list(tokens_remove(toks, "c", window = c(0, 1))),
                 list(text1 = c("a", "b", "e", "f", "g", "h", "i")))
    expect_equal(as.list(tokens_remove(toks, "c", window = c(1, 0))),
                 list(text1 = c("a", "d", "e", "f", "g", "h", "i")))
    expect_equal(as.list(tokens_remove(toks, "c", padding = TRUE, window = c(1, 2))),
                 list(text1 = c("a", "", "", "", "", "f", "g", "h", "i")))

    expect_error(tokens_remove(toks, "c", window = -1),
                 "The value of window must be between 0 and Inf")
    expect_error(
        tokens_remove(toks, "c", window = c(1, 1, 3)),
        "The length of window must be between 1 and 2"
    )
})

test_that("tokens_select error when dfm is given, #1006", {
    toks <- tokens("a b c")
    expect_error(tokens_select(toks, dfm(tokens("b c d"))))
})

test_that("shortcut functions works", {
    toks <- tokens(data_corpus_inaugural[1:5])
    expect_equal(tokens_select(toks, stopwords("english"), selection = "keep"),
                 tokens_keep(toks, stopwords("english")))
    expect_equal(tokens_select(toks, stopwords("english"), selection = "remove"),
                 tokens_remove(toks, stopwords("english")))
})

test_that("tokens_select works with min_nchar and max_nchar", {

    txt <- c(doc1 = "a B c D e",
             doc2 = "a BBB c D e",
             doc3 = "Aaaa BBB cc")
    toks <- tokens(txt)

    expect_equal(as.list(tokens_keep(toks, min_nchar = 3)),
                 list(doc1 = character(0),
                      doc2 = c("BBB"),
                      doc3 = c("Aaaa", "BBB"))
    )
    expect_equal(as.list(tokens_keep(toks, phrase("a b"), min_nchar = 1)),
                 list(doc1 = c("a", "B"),
                      doc2 = character(0),
                      doc3 = character(0))
    )
    expect_equal(as.list(tokens_keep(toks, phrase("a b"), min_nchar = 3)),
                 list(doc1 = character(0),
                      doc2 = character(0),
                      doc3 = character(0))
    )
    expect_equal(as.list(tokens_remove(toks, min_nchar = 3)),
                 list(doc1 = character(0),
                      doc2 = c("BBB"),
                      doc3 = c("Aaaa", "BBB"))
    )
    expect_equal(as.list(tokens_remove(toks, phrase("a b"), min_nchar = 1)),
                 list(doc1 = c("c", "D", "e"),
                      doc2 = c("a", "BBB", "c", "D", "e"),
                      doc3 = c("Aaaa", "BBB", "cc"))
    )
    expect_equal(as.list(tokens_remove(toks, phrase("a b"), min_nchar = 3)),
                 list(doc1 = character(0),
                      doc2 = c("BBB"),
                      doc3 = c("Aaaa", "BBB"))
    )
    expect_equal(as.list(tokens_keep(toks, max_nchar = 3)),
                 list(doc1 = c("a", "B", "c", "D", "e"),
                      doc2 = c("a", "BBB", "c", "D", "e"),
                      doc3 = c("BBB", "cc"))
    )
    expect_equal(as.list(tokens_keep(toks, phrase("a b"), max_nchar = 3)),
                 list(doc1 = c("a", "B"),
                      doc2 = character(0),
                      doc3 = character(0))
    )
    expect_equal(as.list(tokens_remove(toks, max_nchar = 3)),
                 list(doc1 = c("a", "B", "c", "D", "e"),
                      doc2 = c("a", "BBB", "c", "D", "e"),
                      doc3 = c("BBB", "cc"))
    )
    expect_equal(as.list(tokens_remove(toks, phrase("a b"), max_nchar = 3)),
                 list(doc1 = c("c", "D", "e"),
                      doc2 = c("a", "BBB", "c", "D", "e"),
                      doc3 = c("BBB", "cc"))
    )

})

test_that("tokens_select works with min_nchar and max_nchar in the same way as dfm_select", {

    txt <- c(doc1 = "a B c D e",
             doc2 = "a BBB c D e",
             doc3 = "Aaaa BBB cc")
    toks <- tokens(txt)
    mt <- dfm(toks, tolower = FALSE)

    expect_true(setequal(featnames(dfm_keep(mt, c("a"), min_nchar = 3)),
                         types(tokens_keep(toks, c("a"), min_nchar = 3))))

    expect_true(setequal(featnames(dfm_keep(mt, c("a"), min_nchar = 1)),
                         types(tokens_keep(toks, c("a"), min_nchar = 1))))

    expect_true(setequal(featnames(dfm_keep(mt, c("a"), max_nchar = 3)),
                         types(tokens_keep(toks, c("a"), max_nchar = 3))))

    expect_true(setequal(featnames(dfm_keep(mt, c("aaaa"), max_nchar = 3)),
                         types(tokens_keep(toks, c("aaaa"), max_nchar = 3))))

    expect_true(setequal(featnames(dfm_keep(mt, c("a"), min_nchar = 2, max_nchar = 3)),
                         types(tokens_keep(toks, c("a"), min_nchar = 2, max_nchar = 3))))

    expect_true(setequal(featnames(dfm_keep(mt, min_nchar = 2, max_nchar = 3)),
                         types(tokens_keep(toks, min_nchar = 2, max_nchar = 3))))

    expect_true(setequal(featnames(dfm_remove(mt, c("a"), min_nchar = 3)),
                         types(tokens_remove(toks, c("a"), min_nchar = 3))))

    expect_true(setequal(featnames(dfm_remove(mt, c("a"), min_nchar = 1)),
                         types(tokens_remove(toks, c("a"), min_nchar = 1))))

    expect_true(setequal(featnames(dfm_remove(mt, c("a"), max_nchar = 3)),
                         types(tokens_remove(toks, c("a"), max_nchar = 3))))

    expect_true(setequal(featnames(dfm_remove(mt, c("aaaa"), max_nchar = 3)),
                         types(tokens_remove(toks, c("aaaa"), max_nchar = 3))))

    expect_true(setequal(featnames(dfm_remove(mt, c("a"), min_nchar = 2, max_nchar = 3)),
                         types(tokens_remove(toks, c("a"), min_nchar = 2, max_nchar = 3))))

    expect_true(setequal(featnames(dfm_remove(mt, min_nchar = 2, max_nchar = 3)),
                         types(tokens_remove(toks, min_nchar = 2, max_nchar = 3))))

})

test_that("tokens_removekeep fail if selection argument is used", {
    toks <- tokens("a b c d e")
    expect_error(
        tokens_remove(toks, c("b", "c"), selection = "remove"),
        "tokens_remove cannot include selection argument"
    )
    expect_error(
        tokens_keep(toks, c("b", "c"), selection = "keep"),
        "tokens_keep cannot include selection argument"
    )
})

test_that("really long words are not removed in tokens() (#1713)", {
    toks <- tokens("one two DonaudampfschiffahrtselektrizittenhauptbetriebswerkbauunterbeamtengesellschaftXXX")
    expect_equivalent(ntoken(toks), 3)
})

test_that("position arguments are working", {
    txt <- c(doc1 = "a b c d e",
             doc2 = "a b c",
             doc3 = "a")
    toks <- tokens(txt)

    expect_identical(
        as.list(tokens_select(toks, "*", startpos = 1, endpos = 3)),
        list(doc1 = c("a", "b", "c"),
             doc2 = c("a", "b", "c"),
             doc3 = c("a"))
    )
    expect_identical(
        as.list(tokens_select(toks, "*", startpos = rep(1, 3), endpos = rep(3, 3))),
        list(doc1 = c("a", "b", "c"),
             doc2 = c("a", "b", "c"),
             doc3 = c("a"))
    )
    expect_identical(
        as.list(tokens_select(toks, "*", startpos = c(1, 2), endpos = c(3))),
        list(doc1 = c("a", "b", "c"),
             doc2 = c("b", "c"),
             doc3 = c("a"))
    )
    expect_identical(
        as.list(tokens_select(toks, "*", startpos = c(2), endpos = c(3, 2, 1))),
        list(doc1 = c("b", "c"),
             doc2 = c("b"),
             doc3 = character())
    )
    expect_identical(
        as.list(tokens_select(toks, "*", startpos = c(1, 2, 2), endpos = c(3, 2, 1))),
        list(doc1 = c("a", "b", "c"),
             doc2 = c("b"),
             doc3 = character())
    )
    
    expect_identical(
        as.list(tokens_remove(toks, "*", startpos = 1, endpos = 3)),
        list(doc1 = c("d", "e"),
             doc2 = character(),
             doc3 = character())
    )
    expect_identical(
        as.list(tokens_remove(toks, "*", startpos = rep(1, 3), endpos = rep(3, 3))),
        list(doc1 = c("d", "e"),
             doc2 = character(),
             doc3 = character())
    )
    expect_identical(
        as.list(tokens_remove(toks, "*", startpos = c(1, 2), endpos = c(3))),
        list(doc1 = c("d", "e"),
             doc2 = c("a"),
             doc3 = character())
    )
    expect_identical(
        as.list(tokens_remove(toks, "*", startpos = c(2), endpos = c(3, 2, 1))),
        list(doc1 = c("a", "d", "e"),
             doc2 = c("a", "c"),
             doc3 = c("a"))
    )
    expect_identical(
        as.list(tokens_remove(toks, "*", startpos = c(1, 2, 2), endpos = c(3, 2, 1))),
        list(doc1 = c("d", "e"),
             doc2 = c("a", "c"),
             doc3 = c("a"))
    )

    expect_identical(
        as.list(tokens_select(toks, "*", startpos = 1, endpos = 3)),
        as.list(tokens_select(toks, "*", startpos = 0, endpos = 3))
    )
    expect_identical(
        as.list(tokens_remove(toks, "*", startpos = 1, endpos = 3)),
        as.list(tokens_remove(toks, "*", startpos = 0, endpos = 3))
    )

    expect_identical(
        as.list(tokens_select(toks, "*", startpos = 3)),
        list(doc1 = c("c", "d", "e"),
             doc2 = c("c"),
             doc3 = character())
    )
    expect_identical(
        as.list(tokens_remove(toks, "*", startpos = 3)),
        list(doc1 = c("a", "b"),
             doc2 = c("a", "b"),
             doc3 = c("a"))
    )

    expect_identical(
        as.list(tokens_select(toks, "c", startpos = 1, endpos = -2)),
        list(doc1 = "c",
             doc2 = character(),
             doc3 = character())
    )
    expect_identical(
        as.list(tokens_remove(toks, "c", startpos = 1, endpos = -2)),
        list(doc1 = c("a", "b", "d", "e"),
             doc2 = c("a", "b", "c"),
             doc3 = c("a"))
    )

    expect_identical(
        as.list(tokens_select(toks, "*", startpos = 1, endpos = -2)),
        list(doc1 = c("a", "b", "c", "d"),
             doc2 = c("a", "b"),
             doc3 = character())
    )
    expect_identical(
        as.list(tokens_remove(toks, "*", startpos = 1, endpos = -2)),
        list(doc1 = "e",
             doc2 = "c",
             doc3 = "a")
    )

    expect_identical(
        as.list(tokens_select(toks, "*", startpos = -2, endpos = -1)),
        list(doc1 = c("d", "e"),
             doc2 = c("b", "c"),
             doc3 = c("a"))
    )
    expect_identical(
        as.list(tokens_remove(toks, "*", startpos = -2, endpos = -1)),
        list(doc1 = c("a", "b", "c"),
             doc2 = c("a"),
             doc3 = character())
    )

    expect_identical(
        as.list(tokens_select(toks, "*", padding = TRUE, startpos = 1, endpos = 3)),
        list(doc1 = c("a", "b", "c", "", ""),
             doc2 = c("a", "b", "c"),
             doc3 = c("a"))
    )
    expect_identical(
        as.list(tokens_remove(toks, "*", padding = TRUE, startpos = 1, endpos = 3)),
        list(doc1 = c("", "", "", "d", "e"),
             doc2 = c("", "", ""),
             doc3 = c(""))
    )

    expect_identical(
        as.list(tokens_select(toks, "*", startpos = -100, endpos = 100)),
        list(doc1 = c("a", "b", "c", "d", "e"),
             doc2 = c("a", "b", "c"),
             doc3 = c("a"))
    )
    expect_identical(
        as.list(tokens_remove(toks, "*", startpos = -100, endpos = 100)),
        list(doc1 = character(),
             doc2 = character(),
             doc3 = character())
    )
    
    expect_error(
        tokens_select(toks, "*", startpos = rep(1, 4), endpos = -1),
        "The length of startpos must be between 1 and 3"
    )
    expect_error(
        tokens_select(toks, "*", startpos = 1, endpos = rep(-1, 4)),
        "The length of endpos must be between 1 and 3"
    )
    expect_error(
        tokens_remove(toks, "*", startpos = numeric()),
        "The length of startpos must be between 1 and 3"
    )
    expect_error(
        tokens_remove(toks, "*", endpos = numeric()),
        "The length of endpos must be between 1 and 3"
    )
    
})


test_that("apply_if argument is working", {
    
    dat <- data.frame(text = c("R and C are languages",
                              "Windows (R), Quanteda (C)",
                              "Sizes are X=10, Y=20, Z=30"),
                      topic = c("language", "software", "hardware"),
                      month = c(NA, 4, 12))
    corp <- corpus(dat)
    toks <- tokens(corp)
    
    toks1 <- tokens_select(toks, min_nchar = 2, apply_if = toks$topic != "language")
    expect_identical(
        as.list(toks1),
        list(text1 = c("R", "and", "C", "are", "languages"),
             text2 = c("Windows", "Quanteda"),
             text3 = c("Sizes", "are", "10", "20", "30"))
    )
    
    docname <- docnames(toks)
    toks2 <- toks %>% 
        tokens_select(c("R", "C"), apply_if = docname == "text1") %>% 
        tokens_select(c("windows", "quanteda"), apply_if = docname == "text2") %>% 
        tokens_select("\\d", valuetype = "regex", apply_if = docname == "text3")
    expect_identical(
        as.list(toks2),
        list(text1 = c("R", "C"),
             text2 = c("Windows", "Quanteda"),
             text3 = c("10", "20", "30"))
    )
    
    toks3 <- toks |>
        tokens_keep(c("R", "C"), apply_if = toks$topic == "language") %>% 
        tokens_remove(min_nchar = 6, apply_if = toks$topic != "language")
    expect_identical(
        as.list(toks3),
        list(text1 = c("R", "C"),
             text2 = c("Windows", "Quanteda"),
             text3 = character())
    )
    
    toks4 <- toks |>
        tokens_remove(min_nchar = 2, apply_if = toks$month) |>
        tokens_remove(stopwords())
    expect_identical(
        as.list(toks4),
        list(text1 = c("R", "C", "languages"),
             text2 = c("Windows", "Quanteda"),
             text3 = c("Sizes", "10", "20", "30"))
    )
})

