% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/tokens_sample.R
\name{tokens_sample}
\alias{tokens_sample}
\title{Randomly sample documents from a tokens object}
\usage{
tokens_sample(
  x,
  size = NULL,
  replace = FALSE,
  prob = NULL,
  by = NULL,
  env = NULL,
  verbose = quanteda_options("verbose")
)
}
\arguments{
\item{x}{a \link{tokens} object whose documents will be sampled}

\item{size}{a positive number, the number of documents to select; when used
with \code{by}, the number to select from each group or a vector equal in
length to the number of groups defining the samples to be chosen in each
category of \code{by}.  By defining a size larger than the number of documents,
it is possible to oversample when \code{replace = TRUE}.}

\item{replace}{if \code{TRUE}, sample  with replacement}

\item{prob}{a vector of probability weights for obtaining the elements of the
vector being sampled.  May not be applied when \code{by} is used.}

\item{by}{optional grouping variable for sampling.  This will be evaluated in
the docvars data.frame, so that docvars may be referred to by name without
quoting.  This also changes previous behaviours for \code{by}.
See \code{news(Version >= "2.9", package = "quanteda")} for details.}

\item{env}{an environment or a list object in which \code{x} is searched.
Passed to \link{substitute} for non-standard evaluation.}

\item{verbose}{if \code{TRUE} print the number of tokens and documents before and
after the function is applied. The number of tokens does not include paddings.}
}
\value{
a \link{tokens} object (re)sampled on the documents, containing the document
variables for the documents sampled.
}
\description{
Take a random sample of documents of the specified size from a corpus, with
or without replacement, optionally by grouping variables or with probability
weights.
}
\examples{
set.seed(123)
toks <- tokens(data_corpus_inaugural[1:6])
toks
tokens_sample(toks)
tokens_sample(toks, replace = TRUE) |> docnames()
tokens_sample(toks, size = 3, replace = TRUE) |> docnames()

# sampling using by
docvars(toks)
tokens_sample(toks, size = 2, replace = TRUE, by = Party) |> docnames()

}
\seealso{
\link{sample}
}
\keyword{tokens}
