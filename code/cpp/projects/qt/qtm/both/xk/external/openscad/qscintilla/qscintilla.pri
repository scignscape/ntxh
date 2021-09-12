

#           Copyright Nathaniel Christen 2021.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

QT += widgets

QT += network printsupport


exists($$ROOT_DIR/../preferred/sysr.pri): include($$ROOT_DIR/../preferred/sysr.pri)
exists($$ROOT_DIR/../preferred/gui.pri): include($$ROOT_DIR/../preferred/gui.pri)


#SOURCES += \
#  $$SRC_ROOT_DIR/add-minimize-frame.cpp \

DEFINES += SCINTILLA_QT SCI_LEXER INCLUDE_DEPRECATED_FEATURES


INCLUDEPATH += $$SRC_DIR/src \
  $$SRC_DIR/scintilla/include \
  $$SRC_DIR/scintilla/src \
  $$SRC_DIR/scintilla/lexlib \



HEADERS = \
    $$SRC_DIR/src/Qsci/qsciglobal.h \
    $$SRC_DIR/src/Qsci/qsciscintilla.h \
    $$SRC_DIR/src/Qsci/qsciscintillabase.h \
    $$SRC_DIR/src/Qsci/qsciabstractapis.h \
    $$SRC_DIR/src/Qsci/qsciapis.h \
    $$SRC_DIR/src/Qsci/qscicommand.h \
    $$SRC_DIR/src/Qsci/qscicommandset.h \
    $$SRC_DIR/src/Qsci/qscidocument.h \
    $$SRC_DIR/src/Qsci/qscilexer.h \
    $$SRC_DIR/src/Qsci/qscilexeravs.h \
    $$SRC_DIR/src/Qsci/qscilexerbash.h \
    $$SRC_DIR/src/Qsci/qscilexerbatch.h \
    $$SRC_DIR/src/Qsci/qscilexercmake.h \
    $$SRC_DIR/src/Qsci/qscilexercoffeescript.h \
    $$SRC_DIR/src/Qsci/qscilexercpp.h \
    $$SRC_DIR/src/Qsci/qscilexercsharp.h \
    $$SRC_DIR/src/Qsci/qscilexercss.h \
    $$SRC_DIR/src/Qsci/qscilexercustom.h \
    $$SRC_DIR/src/Qsci/qscilexerd.h \
    $$SRC_DIR/src/Qsci/qscilexerdiff.h \
    $$SRC_DIR/src/Qsci/qscilexeredifact.h \
    $$SRC_DIR/src/Qsci/qscilexerfortran.h \
    $$SRC_DIR/src/Qsci/qscilexerfortran77.h \
    $$SRC_DIR/src/Qsci/qscilexerhtml.h \
    $$SRC_DIR/src/Qsci/qscilexeridl.h \
    $$SRC_DIR/src/Qsci/qscilexerjava.h \
    $$SRC_DIR/src/Qsci/qscilexerjavascript.h \
    $$SRC_DIR/src/Qsci/qscilexerjson.h \
    $$SRC_DIR/src/Qsci/qscilexerlua.h \
    $$SRC_DIR/src/Qsci/qscilexermakefile.h \
    $$SRC_DIR/src/Qsci/qscilexermarkdown.h \
    $$SRC_DIR/src/Qsci/qscilexermatlab.h \
    $$SRC_DIR/src/Qsci/qscilexeroctave.h \
    $$SRC_DIR/src/Qsci/qscilexerpascal.h \
    $$SRC_DIR/src/Qsci/qscilexerperl.h \
    $$SRC_DIR/src/Qsci/qscilexerpostscript.h \
    $$SRC_DIR/src/Qsci/qscilexerpo.h \
    $$SRC_DIR/src/Qsci/qscilexerpov.h \
    $$SRC_DIR/src/Qsci/qscilexerproperties.h \
    $$SRC_DIR/src/Qsci/qscilexerpython.h \
    $$SRC_DIR/src/Qsci/qscilexerruby.h \
    $$SRC_DIR/src/Qsci/qscilexerspice.h \
    $$SRC_DIR/src/Qsci/qscilexersql.h \
    $$SRC_DIR/src/Qsci/qscilexertcl.h \
    $$SRC_DIR/src/Qsci/qscilexertex.h \
    $$SRC_DIR/src/Qsci/qscilexerverilog.h \
    $$SRC_DIR/src/Qsci/qscilexervhdl.h \
    $$SRC_DIR/src/Qsci/qscilexerxml.h \
    $$SRC_DIR/src/Qsci/qscilexeryaml.h \
    $$SRC_DIR/src/Qsci/qscimacro.h \
    $$SRC_DIR/src/Qsci/qscistyle.h \
    $$SRC_DIR/src/Qsci/qscistyledtext.h \
    $$SRC_DIR/src/ListBoxQt.h \
    $$SRC_DIR/src/SciAccessibility.h \
    $$SRC_DIR/src/SciClasses.h \
    $$SRC_DIR/src/ScintillaQt.h \
    $$SRC_DIR/scintilla/include/ILexer.h \
    $$SRC_DIR/scintilla/include/ILoader.h \
    $$SRC_DIR/scintilla/include/Platform.h \
    $$SRC_DIR/scintilla/include/Sci_Position.h \
    $$SRC_DIR/scintilla/include/SciLexer.h \
    $$SRC_DIR/scintilla/include/Scintilla.h \
    $$SRC_DIR/scintilla/include/ScintillaWidget.h \
    $$SRC_DIR/scintilla/lexlib/Accessor.h \
    $$SRC_DIR/scintilla/lexlib/CharacterCategory.h \
    $$SRC_DIR/scintilla/lexlib/CharacterSet.h \
    $$SRC_DIR/scintilla/lexlib/DefaultLexer.h \
    $$SRC_DIR/scintilla/lexlib/LexAccessor.h \
    $$SRC_DIR/scintilla/lexlib/LexerBase.h \
    $$SRC_DIR/scintilla/lexlib/LexerModule.h \
    $$SRC_DIR/scintilla/lexlib/LexerNoExceptions.h \
    $$SRC_DIR/scintilla/lexlib/LexerSimple.h \
    $$SRC_DIR/scintilla/lexlib/OptionSet.h \
    $$SRC_DIR/scintilla/lexlib/PropSetSimple.h \
    $$SRC_DIR/scintilla/lexlib/SparseState.h \
    $$SRC_DIR/scintilla/lexlib/StringCopy.h \
    $$SRC_DIR/scintilla/lexlib/StyleContext.h \
    $$SRC_DIR/scintilla/lexlib/SubStyles.h \
    $$SRC_DIR/scintilla/lexlib/WordList.h \
    $$SRC_DIR/scintilla/src/AutoComplete.h \
    $$SRC_DIR/scintilla/src/CallTip.h \
    $$SRC_DIR/scintilla/src/CaseConvert.h \
    $$SRC_DIR/scintilla/src/CaseFolder.h \
    $$SRC_DIR/scintilla/src/Catalogue.h \
    $$SRC_DIR/scintilla/src/CellBuffer.h \
    $$SRC_DIR/scintilla/src/CharClassify.h \
    $$SRC_DIR/scintilla/src/ContractionState.h \
    $$SRC_DIR/scintilla/src/DBCS.h \
    $$SRC_DIR/scintilla/src/Decoration.h \
    $$SRC_DIR/scintilla/src/Document.h \
    $$SRC_DIR/scintilla/src/EditModel.h \
    $$SRC_DIR/scintilla/src/Editor.h \
    $$SRC_DIR/scintilla/src/EditView.h \
    $$SRC_DIR/scintilla/src/ElapsedPeriod.h \
    $$SRC_DIR/scintilla/src/ExternalLexer.h \
    $$SRC_DIR/scintilla/src/FontQuality.h \
    $$SRC_DIR/scintilla/src/Indicator.h \
    $$SRC_DIR/scintilla/src/IntegerRectangle.h \
    $$SRC_DIR/scintilla/src/KeyMap.h \
    $$SRC_DIR/scintilla/src/LineMarker.h \
    $$SRC_DIR/scintilla/src/MarginView.h \
    $$SRC_DIR/scintilla/src/Partitioning.h \
    $$SRC_DIR/scintilla/src/PerLine.h \
    $$SRC_DIR/scintilla/src/Position.h \
    $$SRC_DIR/scintilla/src/PositionCache.h \
    $$SRC_DIR/scintilla/src/RESearch.h \
    $$SRC_DIR/scintilla/src/RunStyles.h \
    $$SRC_DIR/scintilla/src/ScintillaBase.h \
    $$SRC_DIR/scintilla/src/Selection.h \
    $$SRC_DIR/scintilla/src/SparseVector.h \
    $$SRC_DIR/scintilla/src/SplitVector.h \
    $$SRC_DIR/scintilla/src/Style.h \
    $$SRC_DIR/scintilla/src/UniConversion.h \
    $$SRC_DIR/scintilla/src/UniqueString.h \
    $$SRC_DIR/scintilla/src/ViewStyle.h \
    $$SRC_DIR/scintilla/src/XPM.h

!ios:HEADERS += $$SRC_DIR/src/Qsci/qsciprinter.h

SOURCES = \
    $$SRC_DIR/src/qsciscintilla.cpp \
    $$SRC_DIR/src/qsciscintillabase.cpp \
    $$SRC_DIR/src/qsciabstractapis.cpp \
    $$SRC_DIR/src/qsciapis.cpp \
    $$SRC_DIR/src/qscicommand.cpp \
    $$SRC_DIR/src/qscicommandset.cpp \
    $$SRC_DIR/src/qscidocument.cpp \
    $$SRC_DIR/src/qscilexer.cpp \
    $$SRC_DIR/src/qscilexeravs.cpp \
    $$SRC_DIR/src/qscilexerbash.cpp \
    $$SRC_DIR/src/qscilexerbatch.cpp \
    $$SRC_DIR/src/qscilexercmake.cpp \
    $$SRC_DIR/src/qscilexercoffeescript.cpp \
    $$SRC_DIR/src/qscilexercpp.cpp \
    $$SRC_DIR/src/qscilexercsharp.cpp \
    $$SRC_DIR/src/qscilexercss.cpp \
    $$SRC_DIR/src/qscilexercustom.cpp \
    $$SRC_DIR/src/qscilexerd.cpp \
    $$SRC_DIR/src/qscilexerdiff.cpp \
    $$SRC_DIR/src/qscilexeredifact.cpp \
    $$SRC_DIR/src/qscilexerfortran.cpp \
    $$SRC_DIR/src/qscilexerfortran77.cpp \
    $$SRC_DIR/src/qscilexerhtml.cpp \
    $$SRC_DIR/src/qscilexeridl.cpp \
    $$SRC_DIR/src/qscilexerjava.cpp \
    $$SRC_DIR/src/qscilexerjavascript.cpp \
    $$SRC_DIR/src/qscilexerjson.cpp \
    $$SRC_DIR/src/qscilexerlua.cpp \
    $$SRC_DIR/src/qscilexermakefile.cpp \
    $$SRC_DIR/src/qscilexermarkdown.cpp \
    $$SRC_DIR/src/qscilexermatlab.cpp \
    $$SRC_DIR/src/qscilexeroctave.cpp \
    $$SRC_DIR/src/qscilexerpascal.cpp \
    $$SRC_DIR/src/qscilexerperl.cpp \
    $$SRC_DIR/src/qscilexerpostscript.cpp \
    $$SRC_DIR/src/qscilexerpo.cpp \
    $$SRC_DIR/src/qscilexerpov.cpp \
    $$SRC_DIR/src/qscilexerproperties.cpp \
    $$SRC_DIR/src/qscilexerpython.cpp \
    $$SRC_DIR/src/qscilexerruby.cpp \
    $$SRC_DIR/src/qscilexerspice.cpp \
    $$SRC_DIR/src/qscilexersql.cpp \
    $$SRC_DIR/src/qscilexertcl.cpp \
    $$SRC_DIR/src/qscilexertex.cpp \
    $$SRC_DIR/src/qscilexerverilog.cpp \
    $$SRC_DIR/src/qscilexervhdl.cpp \
    $$SRC_DIR/src/qscilexerxml.cpp \
    $$SRC_DIR/src/qscilexeryaml.cpp \
    $$SRC_DIR/src/qscimacro.cpp \
    $$SRC_DIR/src/qscistyle.cpp \
    $$SRC_DIR/src/qscistyledtext.cpp \
    $$SRC_DIR/src/InputMethod.cpp \
    $$SRC_DIR/src/ListBoxQt.cpp \
    $$SRC_DIR/src/MacPasteboardMime.cpp \
    $$SRC_DIR/src/PlatQt.cpp \
    $$SRC_DIR/src/SciAccessibility.cpp \
    $$SRC_DIR/src/SciClasses.cpp \
    $$SRC_DIR/src/ScintillaQt.cpp \
    $$SRC_DIR/scintilla/lexers/LexA68k.cpp \
    $$SRC_DIR/scintilla/lexers/LexAPDL.cpp \
    $$SRC_DIR/scintilla/lexers/LexASY.cpp \
    $$SRC_DIR/scintilla/lexers/LexAU3.cpp \
    $$SRC_DIR/scintilla/lexers/LexAVE.cpp \
    $$SRC_DIR/scintilla/lexers/LexAVS.cpp \
    $$SRC_DIR/scintilla/lexers/LexAbaqus.cpp \
    $$SRC_DIR/scintilla/lexers/LexAda.cpp \
    $$SRC_DIR/scintilla/lexers/LexAsm.cpp \
    $$SRC_DIR/scintilla/lexers/LexAsn1.cpp \
    $$SRC_DIR/scintilla/lexers/LexBaan.cpp \
    $$SRC_DIR/scintilla/lexers/LexBash.cpp \
    $$SRC_DIR/scintilla/lexers/LexBasic.cpp \
    $$SRC_DIR/scintilla/lexers/LexBatch.cpp \
    $$SRC_DIR/scintilla/lexers/LexBibTeX.cpp \
    $$SRC_DIR/scintilla/lexers/LexBullant.cpp \
    $$SRC_DIR/scintilla/lexers/LexCLW.cpp \
    $$SRC_DIR/scintilla/lexers/LexCOBOL.cpp \
    $$SRC_DIR/scintilla/lexers/LexCPP.cpp \
    $$SRC_DIR/scintilla/lexers/LexCSS.cpp \
    $$SRC_DIR/scintilla/lexers/LexCaml.cpp \
    $$SRC_DIR/scintilla/lexers/LexCmake.cpp \
    $$SRC_DIR/scintilla/lexers/LexCoffeeScript.cpp \
    $$SRC_DIR/scintilla/lexers/LexConf.cpp \
    $$SRC_DIR/scintilla/lexers/LexCrontab.cpp \
    $$SRC_DIR/scintilla/lexers/LexCsound.cpp \
    $$SRC_DIR/scintilla/lexers/LexD.cpp \
    $$SRC_DIR/scintilla/lexers/LexDMAP.cpp \
    $$SRC_DIR/scintilla/lexers/LexDMIS.cpp \
    $$SRC_DIR/scintilla/lexers/LexDiff.cpp \
    $$SRC_DIR/scintilla/lexers/LexECL.cpp \
    $$SRC_DIR/scintilla/lexers/LexEDIFACT.cpp \
    $$SRC_DIR/scintilla/lexers/LexEScript.cpp \
    $$SRC_DIR/scintilla/lexers/LexEiffel.cpp \
    $$SRC_DIR/scintilla/lexers/LexErlang.cpp \
    $$SRC_DIR/scintilla/lexers/LexErrorList.cpp \
    $$SRC_DIR/scintilla/lexers/LexFlagship.cpp \
    $$SRC_DIR/scintilla/lexers/LexForth.cpp \
    $$SRC_DIR/scintilla/lexers/LexFortran.cpp \
    $$SRC_DIR/scintilla/lexers/LexGAP.cpp \
    $$SRC_DIR/scintilla/lexers/LexGui4Cli.cpp \
    $$SRC_DIR/scintilla/lexers/LexHTML.cpp \
    $$SRC_DIR/scintilla/lexers/LexHaskell.cpp \
    $$SRC_DIR/scintilla/lexers/LexHex.cpp \
    $$SRC_DIR/scintilla/lexers/LexIndent.cpp \
    $$SRC_DIR/scintilla/lexers/LexInno.cpp \
    $$SRC_DIR/scintilla/lexers/LexJSON.cpp \
    $$SRC_DIR/scintilla/lexers/LexKVIrc.cpp \
    $$SRC_DIR/scintilla/lexers/LexKix.cpp \
    $$SRC_DIR/scintilla/lexers/LexLaTeX.cpp \
    $$SRC_DIR/scintilla/lexers/LexLisp.cpp \
    $$SRC_DIR/scintilla/lexers/LexLout.cpp \
    $$SRC_DIR/scintilla/lexers/LexLua.cpp \
    $$SRC_DIR/scintilla/lexers/LexMMIXAL.cpp \
    $$SRC_DIR/scintilla/lexers/LexMPT.cpp \
    $$SRC_DIR/scintilla/lexers/LexMSSQL.cpp \
    $$SRC_DIR/scintilla/lexers/LexMagik.cpp \
    $$SRC_DIR/scintilla/lexers/LexMake.cpp \
    $$SRC_DIR/scintilla/lexers/LexMarkdown.cpp \
    $$SRC_DIR/scintilla/lexers/LexMatlab.cpp \
    $$SRC_DIR/scintilla/lexers/LexMaxima.cpp \
    $$SRC_DIR/scintilla/lexers/LexMetapost.cpp \
    $$SRC_DIR/scintilla/lexers/LexModula.cpp \
    $$SRC_DIR/scintilla/lexers/LexMySQL.cpp \
    $$SRC_DIR/scintilla/lexers/LexNimrod.cpp \
    $$SRC_DIR/scintilla/lexers/LexNsis.cpp \
    $$SRC_DIR/scintilla/lexers/LexNull.cpp \
    $$SRC_DIR/scintilla/lexers/LexOScript.cpp \
    $$SRC_DIR/scintilla/lexers/LexOpal.cpp \
    $$SRC_DIR/scintilla/lexers/LexPB.cpp \
    $$SRC_DIR/scintilla/lexers/LexPLM.cpp \
    $$SRC_DIR/scintilla/lexers/LexPO.cpp \
    $$SRC_DIR/scintilla/lexers/LexPOV.cpp \
    $$SRC_DIR/scintilla/lexers/LexPS.cpp \
    $$SRC_DIR/scintilla/lexers/LexPascal.cpp \
    $$SRC_DIR/scintilla/lexers/LexPerl.cpp \
    $$SRC_DIR/scintilla/lexers/LexPowerPro.cpp \
    $$SRC_DIR/scintilla/lexers/LexPowerShell.cpp \
    $$SRC_DIR/scintilla/lexers/LexProgress.cpp \
    $$SRC_DIR/scintilla/lexers/LexProps.cpp \
    $$SRC_DIR/scintilla/lexers/LexPython.cpp \
    $$SRC_DIR/scintilla/lexers/LexR.cpp \
    $$SRC_DIR/scintilla/lexers/LexRebol.cpp \
    $$SRC_DIR/scintilla/lexers/LexRegistry.cpp \
    $$SRC_DIR/scintilla/lexers/LexRuby.cpp \
    $$SRC_DIR/scintilla/lexers/LexRust.cpp \
    $$SRC_DIR/scintilla/lexers/LexSAS.cpp \
    $$SRC_DIR/scintilla/lexers/LexSML.cpp \
    $$SRC_DIR/scintilla/lexers/LexSQL.cpp \
    $$SRC_DIR/scintilla/lexers/LexSTTXT.cpp \
    $$SRC_DIR/scintilla/lexers/LexScriptol.cpp \
    $$SRC_DIR/scintilla/lexers/LexSmalltalk.cpp \
    $$SRC_DIR/scintilla/lexers/LexSorcus.cpp \
    $$SRC_DIR/scintilla/lexers/LexSpecman.cpp \
    $$SRC_DIR/scintilla/lexers/LexSpice.cpp \
    $$SRC_DIR/scintilla/lexers/LexStata.cpp \
    $$SRC_DIR/scintilla/lexers/LexTACL.cpp \
    $$SRC_DIR/scintilla/lexers/LexTADS3.cpp \
    $$SRC_DIR/scintilla/lexers/LexTAL.cpp \
    $$SRC_DIR/scintilla/lexers/LexTCL.cpp \
    $$SRC_DIR/scintilla/lexers/LexTCMD.cpp \
    $$SRC_DIR/scintilla/lexers/LexTeX.cpp \
    $$SRC_DIR/scintilla/lexers/LexTxt2tags.cpp \
    $$SRC_DIR/scintilla/lexers/LexVB.cpp \
    $$SRC_DIR/scintilla/lexers/LexVHDL.cpp \
    $$SRC_DIR/scintilla/lexers/LexVerilog.cpp \
    $$SRC_DIR/scintilla/lexers/LexVisualProlog.cpp \
    $$SRC_DIR/scintilla/lexers/LexYAML.cpp \
    $$SRC_DIR/scintilla/lexlib/Accessor.cpp \
    $$SRC_DIR/scintilla/lexlib/CharacterCategory.cpp \
    $$SRC_DIR/scintilla/lexlib/CharacterSet.cpp \
    $$SRC_DIR/scintilla/lexlib/DefaultLexer.cpp \
    $$SRC_DIR/scintilla/lexlib/LexerBase.cpp \
    $$SRC_DIR/scintilla/lexlib/LexerModule.cpp \
    $$SRC_DIR/scintilla/lexlib/LexerNoExceptions.cpp \
    $$SRC_DIR/scintilla/lexlib/LexerSimple.cpp \
    $$SRC_DIR/scintilla/lexlib/PropSetSimple.cpp \
    $$SRC_DIR/scintilla/lexlib/StyleContext.cpp \
    $$SRC_DIR/scintilla/lexlib/WordList.cpp \
    $$SRC_DIR/scintilla/src/AutoComplete.cpp \
    $$SRC_DIR/scintilla/src/CallTip.cpp \
    $$SRC_DIR/scintilla/src/CaseConvert.cpp \
    $$SRC_DIR/scintilla/src/CaseFolder.cpp \
    $$SRC_DIR/scintilla/src/Catalogue.cpp \
    $$SRC_DIR/scintilla/src/CellBuffer.cpp \
    $$SRC_DIR/scintilla/src/CharClassify.cpp \
    $$SRC_DIR/scintilla/src/ContractionState.cpp \
    $$SRC_DIR/scintilla/src/DBCS.cpp \
    $$SRC_DIR/scintilla/src/Decoration.cpp \
    $$SRC_DIR/scintilla/src/Document.cpp \
    $$SRC_DIR/scintilla/src/EditModel.cpp \
    $$SRC_DIR/scintilla/src/Editor.cpp \
    $$SRC_DIR/scintilla/src/EditView.cpp \
    $$SRC_DIR/scintilla/src/ExternalLexer.cpp \
    $$SRC_DIR/scintilla/src/Indicator.cpp \
    $$SRC_DIR/scintilla/src/KeyMap.cpp \
    $$SRC_DIR/scintilla/src/LineMarker.cpp \
    $$SRC_DIR/scintilla/src/MarginView.cpp \
    $$SRC_DIR/scintilla/src/PerLine.cpp \
    $$SRC_DIR/scintilla/src/PositionCache.cpp \
    $$SRC_DIR/scintilla/src/RESearch.cpp \
    $$SRC_DIR/scintilla/src/RunStyles.cpp \
    $$SRC_DIR/scintilla/src/ScintillaBase.cpp \
    $$SRC_DIR/scintilla/src/Selection.cpp \
    $$SRC_DIR/scintilla/src/Style.cpp \
    $$SRC_DIR/scintilla/src/UniConversion.cpp \
    $$SRC_DIR/scintilla/src/ViewStyle.cpp \
    $$SRC_DIR/scintilla/src/XPM.cpp

!ios:SOURCES += $$SRC_DIR/src/qsciprinter.cpp

TRANSLATIONS = \
    $$SRC_DIR/src/qscintilla_cs.ts \
    $$SRC_DIR/src/qscintilla_de.ts \
    $$SRC_DIR/src/qscintilla_es.ts \
    $$SRC_DIR/src/qscintilla_fr.ts \
    $$SRC_DIR/src/qscintilla_pt_br.ts


message(choice: $$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
mkpath($$CPP_ROOT_DIR/targets/$$CHOICE_CODE/$$PROJECT_SET--$$PROJECT_GROUP--$$PROJECT_NAME)
