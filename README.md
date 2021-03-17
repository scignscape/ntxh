# ntxh

This branch contains data and code accompanying the article "Age-related hearing loss, speech understanding and cognitive technologies" by Joseph Lehmann, et. al., published as of March 2021 in the _International Journal of Speech Technology_ (IJST). Thank you for your interest in the article, dataset, and code library. 

This repository also contains a collection of audio samples used for speech quality measurement is republished from the IJST article _Subjective Speech Quality Measurement With and Without Parallel Task: Laboratory test results comparison_ by Hakob Avetisyan and Jan Holub, and data reviewed in _Advances in Ubiquitous Computing: Cyber-Physical Systems, Smart Cities and Ecological Monitoring_, Chapter 3. The audio samples are included to demonstrate techniques for evaluating speech quality that might be used in the context of assessing technologies which modify speech input in light of cognitive-linguistic principles, as proposed in Joseph Lehmann's article. The _Advances in Ubiquitous Computing_ data is a republished avian data set demonstrating certain data-management techniques through requirements associated with audio/acoustical processing.

The primary pupose of this data set is to provide a collection of language samples (mostly sentences) which illustrate various points, claims, and theories in the context of Cognitive Linguistics. The focus is on Cognitive Grammar in particular, including consideration of how discursive constructions signal speaker-relative epistemic orientation and situational understanding, and how these patterns can be manifest in prosody (speech patterns) and communicative interactions in general. The samples (mostly sentences) drawn from a variety of sources, including some invented to illustrate or examine claims in the context of cognitive grammar. Other samples are selected from writings of linguists such as Ronald Langacker, Geoffrey Nunberg, and Julia Hirsh, and from a recent Conference on Natural Language Learning corpus. In addition to the written sentences, Collectively the sentences/samples are annotated with different kinds of parses, prosodic descriptions, or other analytic structures with the goal of exploring cognitive processing and how the cognitive dimensions of understanding can be related to other aspects of languages, such as speech and prosody, as well as prelinguistic situational awareness. The data set includes code and special software for viewing the samples, together with prototypes for novel document-generation formats, database management tools, and other programming concerns which could potentially be integrated into a cognitive-linguistics software platform.

The sample annotations use several formats including 

1) S-Expressions to indicate parse structures
2) CONLLU dependency graphs
3) Prosodic Annotations using ToBI (Tones and Break Indices) or other markup to suggest intonation boundaries, stress patterns, and so forth.
4) Proposed variations on dependency graphs using De Bruijn indices, or in another context word-pairing sequences to decompose dependency parsers into particular head/dependency relations

Most of the samples are also printed inline in one of three accompanying documents discussing various linguistic and philosophical issues relevant to Cognitive Grammar. Dataset users may, if desired, read or skim over those documents to see the samples in the context of arguments discussing/analyzing them, as well as browsing the samples as a collection via the software applications whose code is provided with the data set. If built with PDF support, users can switch between the dataset application and the PDF documents by right-clicking on any of the samples; one context menu option provides a feature for launching a PDF viewer and reading the sample in the document context. 

This data set and code library will be published with the hope of helping to seed or inspire a broader software project in cognitive linguistics and particularly cognitive grammar, which could include features such as supporting different parse and analytic representations of language artifacts (e.g. sentences) annotated from a cognitive-grammar perspective, generating and visualizing parse-graphs and diagrams illustrating cognitive-grammar principles, integrating cognitive grammar with prosody and other linguistic concerns as well as cognitive science more generally, and so forth. The goal of collecting samples from existing linguistics literature -- such as those in the current data set from the _Blackwell Handbook of Pragmatics_ -- could also easily be expanded to other sources, creating a larger corpus of samples which have been used in the literature to illustrate cognitive-linguistic claims.

While some of the materials included in this repository can be viewed with ordinary PDF applications or generic text readers, conveniently accessing the central cognitive-linguistic data set requires compiling the accompanying code. This code produces a self-contained "dataset application" which allows users to scroll through the samples, and will connect samples to a custom PDF viewer and PDF documents where the samples are discussed/analyzed. To build the application and the PDF viewer, it is necessary to install Qt, a C++ GUI libary, which is freely available. The easiest way to use the data set is to run the dataset application from within the Qt Creator API.

The code base currently uses Qt5, but a newer Qt major version, Qt6, was released at the end of 2020 with some significant changes. The current repository should therefore be considered "work in progress" with one outstanding task being to port all the C++ code to work with Qt6.

This repository demonstrates a fairly extensive range of techniques and features related to dataset management and matching datasets with custom-built applications. There are demo-related components concerning text encoding, database engineering, data serialization, dataset organization, and GUI implementation, including testing and documentation. At this stage, many of these components are more conducive to in-person demonstration than out-of-the-box usability, and the documentation for most of the repository code is incomplete. For these reasons, users are invited to ask questions about the different components that may be found here by browsing through the code base. Hopefully future versions of this repository will include more detailed assistance for users seeking to try out the text-encoding, dataset curation, PDF generation, and related tools for their own C++ projects. 

##building
There are several "build strategies" that can be used to create the dataset application and other libraries.  The quickest option is to use the "`build-quick.pro`" project file in the "`.code/cpp/projects/qt/qtm/unibuild/dsmain`" folder.  For most users the best option may be "`build-most.pro`" in the same folder (both versions can be built independently).  The "`quick`" version lacks PDF and TCP features (which is explained via a message box when trying to use these features).

A more complex option is "`build-all.pro`", which is only needed for users wishing to generate test scripts or use other advanced features related to "Runtime Reflection".  For developing new code or debugging the executables it may be necessary or easier to use the "`isobuild`" strategy, where each Qt project is built separately, rather than the "`unibuild`" options where projeects are built automatically in order.  Via "`isobuild`" developers can choose which projects to include more precisely.  For the equivalent of "`build-all.pro`" follow the build order listed in "`build-order.txt`".  Note that these comments are only applicable to a small set of users extending or exploring the code in detail.

---
**Downloading**

If you use "`git clone`", it is recommended to provide your own name to the folder where the data set is unpacked.  For example, create a folder called "`NTXH-CognitiveGrammar`" or something smaller ("`ntxh`", say) and _inside_ that folder execute "`git clone https://github.com/scignscape/ntxh.git ar`" -- notice the trailing "`ar`" (for "archive") where this repository will be unpacked.  Then the parent "`ntxh`" folder can be used for other files related to the project (or follow-up research) but isolated from the actual repo.

Be aware that using long folder names, rather than succinct names like "`ntxh/ar`", may occasionally cause problems (see "`TROUBLESHOOTING`").

---
**Qt**

The Qt libraries and Qt Creator IDE (Integrated Development Environment) are the only known dependencies for most of the project (the exception being specialized use-cases needing Embeddable Commmon Lisp).  Qt is easy to install from https://www.qt.io/ and is free for noncommercial use. 

Linux users are advised to download and link against a version of Qt different from the Qt libraries bundled with your Desktop Environment.  This is first because Qt versions for Linux desktops are often out-of-date relative to the versions needed by applications, and second because developers should minimize the risk of unintentionally altering the components needed for their Desktop Environment to run.  In effect, the "`qmake`" you use for this repository (and other Qt applications not built-in to your desktop) should live somewhere other than a "`/usr`" subfolder. 

For Windows users, installing Qt is a good way to ensure that you have a C++ development environment, with components like MinGW and g++.  It is recommended to use these tools -- which are based on cross-platform environments -- as opposed to using Microsoft-specific products like the VC++ compiler.

The code in this data set is designed to build and run within Qt Creator.  You do not need a separate build tool like cmake.  Upon loading your preferred project file (e.g., "`build-quick.pro`" or "`build-most.pro`"), you can automatically compile and run the code -- and start exploring the data set -- with Qt Creator's "`Run`" option.  You can use "`build-quick.pro`" to test that your compiler is working properly and quickly browse the data set and then load "`build-most.pro`".  (Note that if you choose "`build-all.pro`" the compile time is noticeably longer -- that's usually not a sign of any problem but see "`TROUBLESHOOTING`".) 

---
**XPDF**

This data set includes a slightly modified version of the open-source XPDF reader (see https://www.xpdfreader.com/).  Users are encouraged to also install the official XPDF Reader.  The version distributed in this repository has been modified to work primarily with this data set.

Users may want to edit the "`./code/cpp/src/xk/external/xpdf/xpdf/aconf/aconf.h`" file.  If you have (or choose to install) an official XPDF Reader you may want to copy "`aconf.h`" from that code base ("`aconf.h`" will be generated during cmake; this data set provides a default "`aconf.h`" file to eliminate the need for cmake as a build tool for the data set over all).

---
**TROUBLESHOOTING**

1.  Except with "`build-quick.pro`", the build process will generate multiple executable files, some for testing or related documentation.  Most of the times users will want the executable called "`dsmain-console`" (the project named "`__run_dsmain-console`") which should run automatically.  However, any executable may be chosen by right-clicking on the project as listed on Qt Creator's Project Panel (usually on the left of the IDE) or by selecting that desired "Run Configuration" from the "Run Settings" section of the "Projects" tab (at the far-left of the IDE).  If the application does not seem to run properly, it may be because the wrong executable selection is chosen for the default Run Configuration, so the "`__run_dsmain-console`" option should be chosen from the drop-down list in "Run Settings".

2.  The dsC project organization uses Qt naming conventions to automatically configure an environment so typical users can easily build and launch the main ("`dsmain-console`") application and other executables.  This process will fail if a working Qt environment (called a Qt "`kit`") is not available _before_ the "`build-quick.pro`" or other project files are opened in the IDE.  It is recommended to double-check that you have a valid kit ("`Options`" -- "`Build & Run`" -- "`Kits`") and start a new, blank session (via the menubar "`File`" -- "`Sessions`" submenu) before starting to use this data set.

3.  Because of a quirk, Qt Creator will on some systems misidentify project files with unusually long paths, causing an endless loop during the build (because "`qmake`" will run repeatedly).  This is most likely a problem for users choosing the more complex "`build-all`" or "`isobuild`" strategies.  If you use these options, keep an eye on the "Compiler Output" window on Qt Creator and make sure "`qmake`" is not running multiple times on one file (this attention ceases to be necessary once the Compiler Output suggests that all of the "`qmake`" files are processed and the compiler has started to generate object files).  If you do encounter a loop, you may either rename the problemmatic "`.pro`" files -- this repo chooses to give projects relatively long, descriptive names -- or choose shorter names like "`ntxh/ar`" for the repo folder and its parent.  Alternatively, employ the "`isobuild`" approach where you can manually decide when to run "`qmake`".

4.  For XPDF, you may encounter linking problems associated with **freetype** fonts and **png**.  Qt provides its own freetypelib and pnglib which can be used as an alternative to system libs when those are not present. If however you have them on your system then simply uncomment the line "`LIBS += -lfreetype  -lpng`" in the XPDF-console project file to resolve linker errors for those libs.

---
**R/Z**

The R/Z project can be used for more advanced Runtime Reflection for datasets.  As it is still experimental, R/Z is not documented thoroughly.  Please inquire for more information.

R/Z provides a demo of certain concepts involved in engineering Virtual Machines and database quesry engines, discussed particularly in the _Advances in Ubiquitous Computing_ chapter (by Nathaniel Christen). R/Z is far from a working scripting language, but here it is used as part of a testing framework demonstrated via the main dataset application.

The simplest use-case for R/Z is to build Intermediate Representation files to pass to the main ("`dsmain-console`") application.  In this case the application does not need to embed an R/Z scripting environment in the application itself, just a simpler capability to process Intermediate Representation in the format generated by R/Z (though this representation is not specific to R/Z and could potentially be part of a query-evaluation pipeline, with a front end query language).  A more advanced use-case is to process scripts within a main applications directly, which is outside the scope of this data set.

To check the R/Z environment overall, test the R/Z compiler with "`rz-graph-dynamo-runtime-console`" or one of the other "rz-dynamo" executables.  The "`t1.rz`" file can have sample code like: 

```
,fnd ::: PHR_Fn_Doc*;
fnd \== default; 

,penv ::: PHR_Env*;
penv \= (envv "PHR_Env*");

fnd -> init penv;

,test-fn ::: .(u4)  $-> extern;

fnd -> read  "test-fn";

```

Multiple samples can be executed in sequence with the project/executable called "`rz-multi-console`".

So for example, after confirming that "`t1.rz`" runs properly, try "`rz-multi-console`" which (as coded) will run all scripts listed in the "`./dev/scripts/rz/demo/multi`" file; "`m1.txt`" lists scripts to run in sequence (e.g. as an informal test suite). 

Testing multiple scripts can also be achieved by including them all in one script with "`<#...>`" notation, e.g. script "`t24.rz`" in "`./dev/scripts/rz/demo/multi`" has the two lines "`<#t23>`" and "`<#t25>`".

---
**COMMENTS**

R/Z and other advanced features will continue to evolve.  This repository will be updated accordingly.  Please check back!

