---
title: "quanteda Development Plans"
author: "Ken Benoit and Paul Nulty"
date: "2015-05-05"
output: rmarkdown::html_vignette
vignette: >
  %\VignetteIndexEntry{Development Plans}
  %\VignetteEngine{knitr::rmarkdown}
  \usepackage[utf8]{inputenc}
---

## Suggestions for using quanteda during development

`quanteda` is in development and will remain so until we declare a 1.0 version, at which time we will only add new functions, not change the names of 
existing ones.  In the meantime, we suggest:

-   use named formals in the function calls, rather than relying on the current ordering of formals,
    for instance, use `tokenize(mytexts, what = "sentence")` instead of `tokenize(mytexts, "sentence")` -- since the order is not stable; and also using named formals rather than relying on current defaults, e.g. `tokenize(mytexts, remnovePunct = FALSE)` since the default values are not stable.
-   hope that we get to 1.0 quickly;
-   help that process by sending us feedback stating what you think of the syntax, formal names, etc. from a user's perspective.

## To Do List

*   `bigrams` and `ngrams` need to be added as options to `tokenize()`
*   make `bigrams`, `ngrams` punctuation sensitive in the same way that `collocations` is currently
*   integrate `collocations` code for bigrams and trigrams and reduce the internal memory usage
*   make sure `corpus.VCorpus()` is fully working
*   **encoding**: some major work to be done here, such as
    *   removing all of the `enc` options to functions such as `corpus()`
    *   detecting, inspecting, correcting non-UTF-8 encodings at the `textfile()` and/or `corpus()` stage(s)
    *   (consider) removing `encoding()`
*   dfm documentation needs to group arguments into sections and describe how these correspond to the logical workflow
*   need to figure out how to exclude specific signatures (especially S4 signatures) from the man (.Rd) pages.  For instance `?"dfm-class" has far more details on methods signatures than any user will find useful.
*   encode `ie2010Corpus` (and see if CRAN lets us get away with it)
*   rewrite `kwic` to use new tokenizer, and to allow searches for multi-word regular expressions
*   consider removing `language()`
*   add a converter for objects from the **koRpus** package
*   rewrite to make use of **stringi** (and the new `tokenize()` based on that package):
    *   `phrasetotoken()` 
    *   `ntoken()`
    *   `ntype()`
    *   (ADD) `nsentence()`
    *   `segment()`
*   Devise a scheme for `settings()` and figure out how to add additional objects to a corpus, namely one or more:
    *   dictionary objects
    *   collocation objects
    *   stopword lists
*   optimize `similarity()`
*   consider adopting ISO language names for functions such as `wordstem()`, `stopwords()`, and `syllables()`
*   add methods for `tokenizedTexts` objects:
    *   `dfm.tokenizedTexts`
    *   `removeFeatures.tokenizedTexts`
    *   `syllables.tokenizedTexts`
*   `textmodel`: Devise and document a consistent, logical, and easy-to-use and remember scheme for textmodels.
*   Move more functions to S4
*   Documentation for `convert()` needs substantial work
*   Vignettes:
    *   Vastly revise the Workflow vignette
    *   Add a Performance analysis and comparison vignette
    


*   c


## Bugs to fix

*   Remove documents made empty by dfm - anything that results in rowSums(mydfm)==0

## On the To Do List

1.  Define full set of operators for dfmSparse and dfmDense.  Right now, only `+` is defined.

3.  Common import syntax for dictionary imports.

4.  Debug, make robust, and add funtionality to `textfile()`.

8.  `settings`

9.  `resample`

10. `index`

1. `textmodel`

2. Integrate C++ versions of tokenize and clean.

3. Wordfish C++.



