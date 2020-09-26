
This file will hold C++ background and instructions.

The current purpose of this repository is to demonstrate 
several technologies related to preparing academic/scientific 
publications and data sets and sharing research data.

The long-term goal of this project is to develop a set 
of technologies organized around a graph construction, 
traversal, and query virtual machine, code-named **THQL** 
("Transparent Hypergraph Query Language").  THQL is inspired 
by Gremlin and the Gremlin Virtual Machine, and incoporates 
much of the Gremlin instruction set.  The THQL instruction also 
encompasses hypergraph-construction logic (**NTXH**) and 
instructions related to local variables, program stacks, and 
calling C++ functions (**PGVM**).  These technologies will be 
outlined here.

## NTXH

The "N" in NTXH stands for "non-constructive"; the "TX" stands for 
"type-expression language", and the "H" for "Hypergraph Serialization". 
"Non-constructive" refers to "non-constructive type systems".  In the 
NTXH context, *types* are understood to be grounded in (hyper-)graph 
representations of computer code.  Certain edges in such graph 
are termed *Digamma connections* if they represent the relation between 
a value which is input to or output from a procedure (hypernodes 
represent procedures and also so-called "carriers" for the values they 
operate on).  A digamma connection is *legitimized* by 
type-compatibility between the procedure node and the value node. 
As such, in this system, the semantics of types is centered 
on how types legitimate digamma connections.  An NTXH type system 
is *non-constructive* in that there are not (necessarily) other 
semantic or logico-mathematical principles which would offer a 
different type-semantics (e.g. inductive constructions which generate 
all type instances or a complete finite enumeration of 
types' extensions).  While some NTXH types may be 
"constructive", in the general case it is assumed that 
(1) one cannot specify, for any type *t*, the set of 
values which are instances of *t* and representable in 
the current computing environment; and (2) for type 
*t* there is not necessarily a computationally 
reasonable (in terms of time complexity) algorithm which, 
given a *t*-value *v*, can describe a series of 
steps which constructs *v* via "non-simplistic" constructors, 
or can produce a constructor-pattern which yields *v*.  (A 
"simplistic" constructor is, for instance, simply dereferencing 
a pointer and casting it to a *t* reference). 

For a more thorough treatment of type systems along these 
lines, please see "Hypergraph-Based Type Theory for Software Development in a
Cyber-Physical Context", chapter 3 of Amy Neustein, ed., 
*Advances in Ubiquitous Computing: Cyber-Physical Systems, Smart Cities and Ecological Monitoring* (Elsevier, 2020); this book (and also the 
chapter as a separate PDF file) are included in this repository.

## Preparing Data Sets and Publications

One use-case for NTXH is encoding research data published 
as part of an open-access scientific data set. 
This repository includes tools which may be used for constructing 
data sets and also integrating them with publications 
(books or articles) discussing the research project from 
which a data set originates. 

For text publications (books and articles), NTXH is paired with 
**GTagML**, a version of the "Text as Graph Markup Language" 
(**TAGML**).  TAGML, originally developed by the 
KNAW Humanities Cluster, the Netherlands, is a kind 
of stand-off annotation encoding texts as hypergraphs. 
GTagML extends TAGML with a custom character-encoding 
system which, for some glyphs, uses different code-points 
to represent alternative semantic/textual roles for characters 
(which may be visually indistinguishable).  For instance, 
a period might be the end of a sentence, part of an abbreviation, 
part of a number, or part of an ellipses.  Distinguishing these 
cases is a prerequisite for text mining.  The idea of GTagML 
is to encode documents with a format that can generate 
compelling human-readable output (e.g. LaTeX and then PDF) and 
also machine-readable text representations with a structure 
breakdown of paragraphs, sentences, Named Entities, etc.

Another goal of GTagML is to serve as a hypergraph serialization 
language.  GTagML is "grounded" TAGML, where "grounded" refers 
to certain extra constructions introduced into TAGML to 
indicate where or how a given GTagML document (or subdocument) 
serializes formally structured graphs (or property/hypergraphs), 
or serializes typed values (e.g. C++ objects) via hypergraph 
representations.  Such "grounding" entails distinguishing 
inter-node relations (where "nodes" in this context refer 
to nodes in a TAGML graph) which model or reciprocate 
inter-node relations in a (hyper)graph being serialized, 
from inter-node relations (again in the TAGML context) which 
derive from textual details (e.g., italics) rather than from 
datatype structures. 

## A GTagML/NTXH Workflow

An example of using GTagML and NTXH in combination is the 
following: a processor parses a GTagML document, yielding 
LaTeX sources *and* an NTXH file which encodes information 
about the document's sentences, paragraphs, annotations, 
and other material which may be relevant to technologies 
for human readers of the document (e.g., PDF viewers), such as 
figure illustrations or data sets discussed/visualized in 
the text.  The LaTeX sources are then run through pdflatex, 
which in addition to generating a PDF files also generates 
further NTXH files which notate viewport coordinates and 
other PDF-related data concerning paragraphs, sentences, 
annotations, figures, etc.  The two sets of NTXH files 
(one generated from LaTeX and one from GTagML) are then 
"reconciled", yielding a combined resource called a 
"Semantic Document Infoset" (**SDI**) which models 
textual entities, such as sentences and paragraphs, 
both in terms of their positions in the document's 
textual character stream (via HTXN character encoding) and 
in terms of PDF page and viewport coordinates (e.g., 
where a sentence begins and ends from the point of view 
of mouse-coordinates within a page-view window). 

An example of this workflow is included within this repository, 
comprising both Qt project files (intended to be opened 
in Qt creator, building the projects -- **.so** libraries or 
executables -- and then run from Qt creator), C++ projects 
intended to be built and run from a command line, and LaTeX files. 

Because this is "work in process," the current version will not 
provide step-by-step instructions to execute this workflow. 
Please contact the developers if you would like to 
compile and run these examples.

## NTXH as a Virtual Machine 

In its current incarnation NTXH looks more like a markup 
language than a Virtual Machine or an Intermediate Representation, 
but internally NTXH can be modeled (and to some extent is 
implemtened) as an incremental graph construction through a 
series of minimal steps.  NTXH is at least distantly related 
to the Gremlin virtual machine, although it is focused on 
graph construction/initialization as much as on graph 
querying/traversal (the traversal capabilities presented 
in this repository, admittedly, are much more bare-bones 
than Gremlin).  

Ultimately, the goal for NTXH is to unite the existing 
NTXH functionality -- treated as a "step library" in the 
Gremlim VM sense -- with an actual C++ implementation 
of Gremlin VM (perhaps based on Alex Barghi's "BitGraph"). 
Moreover, NTXH has been developed alongside a runtime/in-memory 
"Property Hypergraph Ontology" library (**PhaonGraph**); a minimal 
PhaonGraph implementation is included here in order to 
hold parsed NTXH data.  PhaonGraph has its own "PhaonGraph Virtual 
Machine" (**PGVM**) which is discussed in some modest detail 
in the aforementioned "Hypergraph-Based Type Theory" chapter. 
PGVM is oriented toward modeling computer code as hypergraphs, 
and includes support for calling in to C++ functions 
registered as an "application kernel".  

In principle, PGVM could serve as an extension to the C++ version of 
Gremlin VM providing a representation, within the VM 
"instruction set" (or "step library"), of actions or predicates 
that may involve calling general C++ procedures.  That is, 
steps such as `withSideEffect`, or any steps involving 
predicates, may call procedures implemented in the "host" 
language; since Gremlin VM is obviously not an LLVM-style 
machine for managing a program stack and calling functions 
through an ABI, the "steps" appropriate for preparing such 
function-calls are outside the scope of Gremlin proper.  In the 
JVM context, built-in language reflection mitigates the 
externality of such calls; but, in C++, how to properly 
model steps which delegate functionality to native procedures 
appears to be an open question.  If graph-traveral is written 
directly (as a DSL) in C++ code then of course procedures 
can be called directly, albeit there may be some 
type-marshaling complications.  But in the best-case 
scenario one would like to allow access to a C++ version 
of Gremlin VM that could be used by a special graph 
query language, or by C++ scripting languages such as 
AngelScript, Clasp, or Embeddable Common Lisp 
(playing a role analogous to Gremlin-Groovy, Gremlin-Scala, 
or Gremlin-Clojure).  In this scenario, we don't have 
native C++ reflection comparable to the JVM, so PGVM 
instructions could serve as a bridge between predicates 
or side-effects needed in a graph query/traversal context 
and native C++ procedures.  

In sum, NTXH, PGVM, and a C++ implementation of Gremlin VM 
are conceptualized as three distinct instruction-sets, each 
with their own emphases, which 
can be combined into a more powerful and general purpose 
VM for construction/initializing and querying/traversing 
"Property Hypergraphs" and other multi-faceted graph 
categories.  This combined "step library" would then 
be augmented by certain instruction modeling 
scientific workflows, or research protocols -- consider the 
example of BioCoder, a C++ library used to create 
representations/descriptions of laboratory protocols 
in the manner of MIBBI (Minimum Information for 
Biological and Biomedical Investigations).  More 
generally, the unified step library -- which 
as mentioned previously is envisioned as the 
foundation for "THQL" -- would include extra 
features oriented to using Property Hypergraphs 
as representational media for various scientific 
and data-sharing requirements.



