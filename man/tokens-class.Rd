% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/tokens-methods.R
\name{tokens-class}
\alias{tokens-class}
\alias{unlist.tokens}
\alias{[.tokens}
\alias{+.tokens}
\alias{c.tokens_xptr}
\alias{c.tokens}
\title{Base method extensions for tokens objects}
\usage{
\method{unlist}{tokens}(x, recursive = FALSE, use.names = TRUE)

\method{[}{tokens}(x, i, drop_docid = TRUE)

\method{+}{tokens}(t1, t2)

\method{c}{tokens_xptr}(...)

\method{c}{tokens}(...)
}
\arguments{
\item{x}{a tokens object}

\item{recursive}{a required argument for \link{unlist} but inapplicable to
\link{tokens} objects.}

\item{i}{document names or indices for documents to extract.}

\item{drop_docid}{if \code{TRUE}, \code{docid} for documents are removed as the result
of extraction.}

\item{t1}{tokens one to be added}

\item{t2}{tokens two to be added}
}
\value{
\code{unlist} returns a simple vector of characters from a
\link{tokens} object.

\code{c(...)} and \code{+} return a tokens object whose documents
have been added as a single sequence of documents.
}
\description{
Extensions of base R functions for tokens objects.
}
\examples{
toks <- tokens(c(d1 = "one two three", d2 = "four five six", d3 = "seven eight"))
str(toks)
toks[c(1,3)]
# combining tokens
toks1 <- tokens(c(doc1 = "a b c d e", doc2 = "f g h"))
toks2 <- tokens(c(doc3 = "1 2 3"))
toks1 + toks2
c(toks1, toks2)

}
\keyword{internal}
\keyword{tokens}
