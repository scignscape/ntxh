
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

PROJECT_NAME = ntxh

include(../build-group.pri)

QT -= gui
QT -= core

include($$ROOT_DIR/../preferred/sysr.pri)


INCLUDEPATH += $$SRC_DIR  $$SRC_DIR/include  $$SRC_DIR/operatorsP0


#  DEFINES += MAIN

HEADERS += \
      $$SRC_DIR/include/CImg1-16.h \
      $$SRC_DIR/include/bundled.h \
      $$SRC_DIR/include/collection.h \
      $$SRC_DIR/include/collection.ht \
      $$SRC_DIR/include/dimension.h \
      $$SRC_DIR/include/errc.h \
      $$SRC_DIR/include/errc.ht \
      $$SRC_DIR/include/graph.h \
      $$SRC_DIR/include/image.h \
      $$SRC_DIR/include/image.ht \
      $$SRC_DIR/include/main.h \
      $$SRC_DIR/include/neighbours.h \
      $$SRC_DIR/include/pandore \
      $$SRC_DIR/include/pandore.h \
      $$SRC_DIR/include/panfile.h \
      $$SRC_DIR/include/plimits.h \
      $$SRC_DIR/include/plist.h \
      $$SRC_DIR/include/pobject.h \
      $$SRC_DIR/include/pobject.ht \
      $$SRC_DIR/include/point.h \
      $$SRC_DIR/include/promotions.h \
      $$SRC_DIR/include/ptypes.h \
      $$SRC_DIR/include/pversion.h \
      $$SRC_DIR/include/pviewer.h \
      $$SRC_DIR/include/pvisu.h \
      $$SRC_DIR/include/region.h \
      $$SRC_DIR/include/regionlut.h



#DISTFILES += \
#      $$SRC_DIR/operatorsP0/color/prgb2hsi.cct \
#      $$SRC_DIR/operatorsP0/color/prgb2hsl.cct \
#      $$SRC_DIR/operatorsP0/conversion/jpeg/README \
#      $$SRC_DIR/operatorsP0/conversion/png/LICENSE \
#      $$SRC_DIR/operatorsP0/conversion/ppan2analyze.cct \
#      $$SRC_DIR/operatorsP0/edgedetection/pgradient.cct \
#      $$SRC_DIR/operatorsP0/filtering/pdenoisePDE.cct \
#      $$SRC_DIR/operatorsP0/filtering/pmeanfiltering.cct \
#      $$SRC_DIR/operatorsP0/frequency/pfft.cct \
#      $$SRC_DIR/operatorsP0/frequency/pifft.cct \
#      $$SRC_DIR/operatorsP0/imagefeatureextraction/pentropyvalue.cct \
#      $$SRC_DIR/operatorsP0/information/pfile.cct \
#      $$SRC_DIR/operatorsP0/interpolation/plinearinterpolation.cct \
#      $$SRC_DIR/operatorsP0/logic/por.cct \
#      $$SRC_DIR/operatorsP0/morphology/pdilation.cct \
#      $$SRC_DIR/operatorsP0/morphology/perosion.cct \
#      $$SRC_DIR/operatorsP0/morphology/pwatershed.cct \
#      $$SRC_DIR/operatorsP0/motion/pplotquiver.cct \
#      $$SRC_DIR/operatorsP0/motion/pregistrationPDE.cct \
#      $$SRC_DIR/operatorsP0/region/pmeanselection.cct \
#      $$SRC_DIR/operatorsP0/segmentation/plabeling.cct \
#      $$SRC_DIR/operatorsP0/surfacefitting/plegendrepolynomialfitting.cct \
#      $$SRC_DIR/operatorsP0/surfacefitting/plinearregression.cct \
#      $$SRC_DIR/operatorsP0/visualization/pcontentsdisplay.cct \
#      $$SRC_DIR/operatorsP0/visualization/pplot1d.cct

#HEADERS += \
#      $$SRC_DIR/objects/bundled.cct \
#      $$SRC_DIR/objects/collection.cct \
#      $$SRC_DIR/objects/errc.cct \
#      $$SRC_DIR/objects/pobject.cct \
#      $$SRC_DIR/operatorsP0/arithmetic/pabs.cct \
#      $$SRC_DIR/operatorsP0/arithmetic/padd.cct \
#      $$SRC_DIR/operatorsP0/arithmetic/paddcst.cct \
#      $$SRC_DIR/operatorsP0/arithmetic/paddval.cct \
#      $$SRC_DIR/operatorsP0/arithmetic/pblend.cct \
#      $$SRC_DIR/operatorsP0/arithmetic/pclipvalues.cct \
#      $$SRC_DIR/operatorsP0/arithmetic/pconvolution.cct \
#      $$SRC_DIR/operatorsP0/arithmetic/pdif.cct \
#      $$SRC_DIR/operatorsP0/arithmetic/pdiv.cct \
#      $$SRC_DIR/operatorsP0/arithmetic/pdivcst.cct \
#      $$SRC_DIR/operatorsP0/arithmetic/pdivval.cct \
#      $$SRC_DIR/operatorsP0/arithmetic/pexp.cct \
#      $$SRC_DIR/operatorsP0/arithmetic/plipadd.cct \
#      $$SRC_DIR/operatorsP0/arithmetic/plipmultcst.cct \
#      $$SRC_DIR/operatorsP0/arithmetic/plipsub.cct \
#      $$SRC_DIR/operatorsP0/arithmetic/plog.cct \
#      $$SRC_DIR/operatorsP0/arithmetic/pmax.cct \
#      $$SRC_DIR/operatorsP0/arithmetic/pmean.cct \
#      $$SRC_DIR/operatorsP0/arithmetic/pmin.cct \
#      $$SRC_DIR/operatorsP0/arithmetic/pmult.cct \
#      $$SRC_DIR/operatorsP0/arithmetic/pmultcst.cct \
#      $$SRC_DIR/operatorsP0/arithmetic/pmultval.cct \
#      $$SRC_DIR/operatorsP0/arithmetic/pnormalization.cct \
#      $$SRC_DIR/operatorsP0/arithmetic/ppow.cct \
#      $$SRC_DIR/operatorsP0/arithmetic/pround.cct \
#      $$SRC_DIR/operatorsP0/arithmetic/psetcst.cct \
#      $$SRC_DIR/operatorsP0/arithmetic/psqrt.cct \
#      $$SRC_DIR/operatorsP0/arithmetic/psub.cct \
#      $$SRC_DIR/operatorsP0/arithmetic/psubval.cct \
#      $$SRC_DIR/operatorsP0/array/parray2array.cct \
#      $$SRC_DIR/operatorsP0/array/parrayargmax.cct \
#      $$SRC_DIR/operatorsP0/array/parrayeuclideannorm.cct \
#      $$SRC_DIR/operatorsP0/array/parraygetvalue.cct \
#      $$SRC_DIR/operatorsP0/array/parraymean.cct \
#      $$SRC_DIR/operatorsP0/array/parraymedian.cct \
#      $$SRC_DIR/operatorsP0/array/parraymode.cct \
#      $$SRC_DIR/operatorsP0/array/parraynorm.cct \
#      $$SRC_DIR/operatorsP0/array/parraysize.cct \
#      $$SRC_DIR/operatorsP0/array/parraysmax.cct \
#      $$SRC_DIR/operatorsP0/array/parraysmean.cct \
#      $$SRC_DIR/operatorsP0/array/parraysmin.cct \
#      $$SRC_DIR/operatorsP0/array/parraysnorm.cct \
#      $$SRC_DIR/operatorsP0/array/pcorrelationcoefficient.cct \
#      $$SRC_DIR/operatorsP0/array/pcreatearray.cct \
#      $$SRC_DIR/operatorsP0/casting/parray2im.cct \
#      $$SRC_DIR/operatorsP0/casting/pim2array.cct \
#      $$SRC_DIR/operatorsP0/casting/pim2d23d.cct \
#      $$SRC_DIR/operatorsP0/casting/pim2rg.cct \
#      $$SRC_DIR/operatorsP0/casting/pim2sf.cct \
#      $$SRC_DIR/operatorsP0/casting/pim2sl.cct \
#      $$SRC_DIR/operatorsP0/casting/pim2uc.cct \
#      $$SRC_DIR/operatorsP0/casting/pim3d22d.cct \
#      $$SRC_DIR/operatorsP0/casting/pimc2img.cct \
#      $$SRC_DIR/operatorsP0/casting/pimc2imx.cct \
#      $$SRC_DIR/operatorsP0/casting/pimg2imx.cct \
#      $$SRC_DIR/operatorsP0/casting/pimgs2imc.cct \
#      $$SRC_DIR/operatorsP0/casting/pimgs2imx.cct \
#      $$SRC_DIR/operatorsP0/casting/pimx2imc.cct \
#      $$SRC_DIR/operatorsP0/casting/pimx2img.cct \
#      $$SRC_DIR/operatorsP0/casting/prg2im.cct \
#      $$SRC_DIR/operatorsP0/casting/prg2imc.cct \
#      $$SRC_DIR/operatorsP0/classification/pkmeans.cct \
#      $$SRC_DIR/operatorsP0/classification/pknn.cct \
#      $$SRC_DIR/operatorsP0/collection/pcolgetimages.cct \
#      $$SRC_DIR/operatorsP0/collection/pcolgetobject.cct \
#      $$SRC_DIR/operatorsP0/collection/pcolgetvalue.cct \
#      $$SRC_DIR/operatorsP0/collection/pcolsetobject.cct \
#      $$SRC_DIR/operatorsP0/collection/pcolsetvalue.cct \
#      $$SRC_DIR/operatorsP0/collection/pobject2col.cct \
#      $$SRC_DIR/operatorsP0/color/pcmyk2rgb.cct \
#      $$SRC_DIR/operatorsP0/color/pgray2falsecolor.cct \
#      $$SRC_DIR/operatorsP0/color/phsi2rgb.cct \
#      $$SRC_DIR/operatorsP0/color/phsl2rgb.cct \
#      $$SRC_DIR/operatorsP0/color/phsv2rgb.cct \
#      $$SRC_DIR/operatorsP0/color/prgb2cmyk.cct \
#      $$SRC_DIR/operatorsP0/color/prgb2gray.cct \
#      $$SRC_DIR/operatorsP0/color/prgb2hsv.cct \
#      $$SRC_DIR/operatorsP0/color/pxyz2luv.cct \
#      $$SRC_DIR/operatorsP0/contour/pbarbremoval.cct \
#      $$SRC_DIR/operatorsP0/contour/pblindedgeclosing.cct \
#      $$SRC_DIR/operatorsP0/contour/pclosedcontourselection.cct \
#      $$SRC_DIR/operatorsP0/contour/pcontourselection.cct \
#      $$SRC_DIR/operatorsP0/contour/pdistance1.cct \
#      $$SRC_DIR/operatorsP0/contour/pedgeclosing.cct \
#      $$SRC_DIR/operatorsP0/contour/popencontourselection.cct \
#      $$SRC_DIR/operatorsP0/contour/ppostthinning.cct \
#      $$SRC_DIR/operatorsP0/conversion/fitsio.h \
#      $$SRC_DIR/operatorsP0/conversion/jpeg/cderror.h \
#      $$SRC_DIR/operatorsP0/conversion/jpeg/cdjpeg.h \
#      $$SRC_DIR/operatorsP0/conversion/jpeg/jconfig.h \
#      $$SRC_DIR/operatorsP0/conversion/jpeg/jdct.h \
#      $$SRC_DIR/operatorsP0/conversion/jpeg/jerror.h \
#      $$SRC_DIR/operatorsP0/conversion/jpeg/jinclude.h \
#      $$SRC_DIR/operatorsP0/conversion/jpeg/jmemsys.h \
#      $$SRC_DIR/operatorsP0/conversion/jpeg/jmorecfg.h \
#      $$SRC_DIR/operatorsP0/conversion/jpeg/jpegint.h \
#      $$SRC_DIR/operatorsP0/conversion/jpeg/jpeglib.h \
#      $$SRC_DIR/operatorsP0/conversion/jpeg/jversion.h \
#      $$SRC_DIR/operatorsP0/conversion/png/crc32.h \
#      $$SRC_DIR/operatorsP0/conversion/png/deflate.h \
#      $$SRC_DIR/operatorsP0/conversion/png/gzguts.h \
#      $$SRC_DIR/operatorsP0/conversion/png/inffast.h \
#      $$SRC_DIR/operatorsP0/conversion/png/inffixed.h \
#      $$SRC_DIR/operatorsP0/conversion/png/inflate.h \
#      $$SRC_DIR/operatorsP0/conversion/png/inftrees.h \
#      $$SRC_DIR/operatorsP0/conversion/png/png.h \
#      $$SRC_DIR/operatorsP0/conversion/png/pngconf.h \
#      $$SRC_DIR/operatorsP0/conversion/png/pngdebug.h \
#      $$SRC_DIR/operatorsP0/conversion/png/pnginfo.h \
#      $$SRC_DIR/operatorsP0/conversion/png/pnglibconf.h \
#      $$SRC_DIR/operatorsP0/conversion/png/pngpriv.h \
#      $$SRC_DIR/operatorsP0/conversion/png/pngstruct.h \
#      $$SRC_DIR/operatorsP0/conversion/png/trees.h \
#      $$SRC_DIR/operatorsP0/conversion/png/zconf.h \
#      $$SRC_DIR/operatorsP0/conversion/png/zlib.h \
#      $$SRC_DIR/operatorsP0/conversion/png/zutil.h \
#      $$SRC_DIR/operatorsP0/conversion/ppan2raw.cct \
#      $$SRC_DIR/operatorsP0/conversion/ppan2txt.cct \
#      $$SRC_DIR/operatorsP0/edgedetection/pderiche.cct \
#      $$SRC_DIR/operatorsP0/edgedetection/plaplacian.cct \
#      $$SRC_DIR/operatorsP0/edgedetection/pnonmaximasuppression.cct \
#      $$SRC_DIR/operatorsP0/edgedetection/pprewitt.cct \
#      $$SRC_DIR/operatorsP0/edgedetection/proberts.cct \
#      $$SRC_DIR/operatorsP0/edgedetection/pshen.cct \
#      $$SRC_DIR/operatorsP0/edgedetection/psobel.cct \
#      $$SRC_DIR/operatorsP0/edgedetection/pzerocross.cct \
#      $$SRC_DIR/operatorsP0/evaluation/evaluation/boundaryprecisionmeasurement.h \
#      $$SRC_DIR/operatorsP0/evaluation/evaluation/computediscrepancyresults.h \
#      $$SRC_DIR/operatorsP0/evaluation/evaluation/computeindicators.h \
#      $$SRC_DIR/operatorsP0/evaluation/evaluation/computenormalizedaveragediscrepancyresult.h \
#      $$SRC_DIR/operatorsP0/evaluation/evaluation/detectionaccuracymeasurement.h \
#      $$SRC_DIR/operatorsP0/evaluation/evaluation/dirent.h \
#      $$SRC_DIR/operatorsP0/evaluation/evaluation/displayperformancevalues.h \
#      $$SRC_DIR/operatorsP0/evaluation/evaluation/evaluation.h \
#      $$SRC_DIR/operatorsP0/evaluation/evaluation/evaluationfunction.h \
#      $$SRC_DIR/operatorsP0/evaluation/evaluation/fileutils.h \
#      $$SRC_DIR/operatorsP0/evaluation/evaluation/fragmentationconsistencymeasurement.h \
#      $$SRC_DIR/operatorsP0/evaluation/evaluation/log.h \
#      $$SRC_DIR/operatorsP0/evaluation/evaluation/matching.h \
#      $$SRC_DIR/operatorsP0/evaluation/evaluation/multiindicatorranking.h \
#      $$SRC_DIR/operatorsP0/evaluation/evaluation/myinputoutput.h \
#      $$SRC_DIR/operatorsP0/evaluation/evaluation/pnmfile.h \
#      $$SRC_DIR/operatorsP0/evaluation/evaluation/rankingfunction.h \
#      $$SRC_DIR/operatorsP0/evaluation/evaluation/shapefidelitymeasurement.h \
#      $$SRC_DIR/operatorsP0/evaluation/evaluation/topologypreservationmeasurement.h \
#      $$SRC_DIR/operatorsP0/evaluation/pborsotti.cct \
#      $$SRC_DIR/operatorsP0/evaluation/pinterregioncontrast.cct \
#      $$SRC_DIR/operatorsP0/evaluation/pintraregionuniformity.cct \
#      $$SRC_DIR/operatorsP0/evaluation/pmse.cct \
#      $$SRC_DIR/operatorsP0/evaluation/ppsnr.cct \
#      $$SRC_DIR/operatorsP0/evaluation/psnr.cct \
#      $$SRC_DIR/operatorsP0/evaluation/pzeboudj.cct \
#      $$SRC_DIR/operatorsP0/filtering/padaptivemeanfiltering.cct \
#      $$SRC_DIR/operatorsP0/filtering/pderichesmoothing.cct \
#      $$SRC_DIR/operatorsP0/filtering/perform_reg.h \
#      $$SRC_DIR/operatorsP0/filtering/pexponentialfiltering.cct \
#      $$SRC_DIR/operatorsP0/filtering/pgaussianfiltering.cct \
#      $$SRC_DIR/operatorsP0/filtering/pmalikperonafiltering.cct \
#      $$SRC_DIR/operatorsP0/filtering/pmcmfiltering.cct \
#      $$SRC_DIR/operatorsP0/filtering/pmedianfiltering.cct \
#      $$SRC_DIR/operatorsP0/filtering/pnagaofiltering.cct \
#      $$SRC_DIR/operatorsP0/filtering/poutrangefiltering.cct \
#      $$SRC_DIR/operatorsP0/filtering/psharp.cct \
#      $$SRC_DIR/operatorsP0/filtering/pshensmoothing.cct \
#      $$SRC_DIR/operatorsP0/filtering/psigmafiltering.cct \
#      $$SRC_DIR/operatorsP0/filtering/psnnfiltering.cct \
#      $$SRC_DIR/operatorsP0/filtering/pvariancefiltering.cct \
#      $$SRC_DIR/operatorsP0/frequency/pfftconvolution.cct \
#      $$SRC_DIR/operatorsP0/frequency/pfftcorrelation.cct \
#      $$SRC_DIR/operatorsP0/frequency/pfftdeconvolution.cct \
#      $$SRC_DIR/operatorsP0/frequency/pmodulus.cct \
#      $$SRC_DIR/operatorsP0/frequency/pphase.cct \
#      $$SRC_DIR/operatorsP0/imagefeatureextraction/pcontrast1value.cct \
#      $$SRC_DIR/operatorsP0/imagefeatureextraction/pcontrastvalue.cct \
#      $$SRC_DIR/operatorsP0/imagefeatureextraction/penergyvalue.cct \
#      $$SRC_DIR/operatorsP0/imagefeatureextraction/phistogram.cct \
#      $$SRC_DIR/operatorsP0/imagefeatureextraction/plocalextrema.cct \
#      $$SRC_DIR/operatorsP0/imagefeatureextraction/plocalmaxima.cct \
#      $$SRC_DIR/operatorsP0/imagefeatureextraction/plocalminima.cct \
#      $$SRC_DIR/operatorsP0/imagefeatureextraction/pmaximumvalue.cct \
#      $$SRC_DIR/operatorsP0/imagefeatureextraction/pmeanvalue.cct \
#      $$SRC_DIR/operatorsP0/imagefeatureextraction/pmedianvalue.cct \
#      $$SRC_DIR/operatorsP0/imagefeatureextraction/pminimumvalue.cct \
#      $$SRC_DIR/operatorsP0/imagefeatureextraction/pmodevalue.cct \
#      $$SRC_DIR/operatorsP0/imagefeatureextraction/pregionalmaxima.cct \
#      $$SRC_DIR/operatorsP0/imagefeatureextraction/pregionalminima.cct \
#      $$SRC_DIR/operatorsP0/imagefeatureextraction/psumvalue.cct \
#      $$SRC_DIR/operatorsP0/imagefeatureextraction/pvalueclassnumber.cct \
#      $$SRC_DIR/operatorsP0/imagefeatureextraction/pvaluenumber.cct \
#      $$SRC_DIR/operatorsP0/imagefeatureextraction/pvaluerank.cct \
#      $$SRC_DIR/operatorsP0/imagefeatureextraction/pvariancevalue.cct \
#      $$SRC_DIR/operatorsP0/information/pstatus.cct \
#      $$SRC_DIR/operatorsP0/logic/pand.cct \
#      $$SRC_DIR/operatorsP0/logic/pinverse.cct \
#      $$SRC_DIR/operatorsP0/logic/pmask.cct \
#      $$SRC_DIR/operatorsP0/logic/pnot.cct \
#      $$SRC_DIR/operatorsP0/logic/pxor.cct \
#      $$SRC_DIR/operatorsP0/luttransform/pextremumsharpening.cct \
#      $$SRC_DIR/operatorsP0/luttransform/phistogramequalization.cct \
#      $$SRC_DIR/operatorsP0/luttransform/phistogramspecification.cct \
#      $$SRC_DIR/operatorsP0/luttransform/plineartransform.cct \
#      $$SRC_DIR/operatorsP0/luttransform/plogtransform.cct \
#      $$SRC_DIR/operatorsP0/luttransform/ppowerlawtransform.cct \
#      $$SRC_DIR/operatorsP0/miscellaneous/psubsampling.cct \
#      $$SRC_DIR/operatorsP0/morphology/pareaclosing.cct \
#      $$SRC_DIR/operatorsP0/morphology/pareaopening.cct \
#      $$SRC_DIR/operatorsP0/morphology/pdilationreconstruction.cct \
#      $$SRC_DIR/operatorsP0/morphology/perform_reg.h \
#      $$SRC_DIR/operatorsP0/morphology/perosionreconstruction.cct \
#      $$SRC_DIR/operatorsP0/morphology/pgeodesicdilation.cct \
#      $$SRC_DIR/operatorsP0/morphology/pgeodesicerosion.cct \
#      $$SRC_DIR/operatorsP0/morphology/phitormiss.cct \
#      $$SRC_DIR/operatorsP0/morphology/plineardilation.cct \
#      $$SRC_DIR/operatorsP0/morphology/plinearerosion.cct \
#      $$SRC_DIR/operatorsP0/morphology/psedilation.cct \
#      $$SRC_DIR/operatorsP0/morphology/pseerosion.cct \
#      $$SRC_DIR/operatorsP0/morphology/structelt.h \
#      $$SRC_DIR/operatorsP0/pointsofinterest/pharris.cct \
#      $$SRC_DIR/operatorsP0/region/pboundary.cct \
#      $$SRC_DIR/operatorsP0/region/pboundaryregularization.cct \
#      $$SRC_DIR/operatorsP0/region/penergyselection.cct \
#      $$SRC_DIR/operatorsP0/region/pinnerselection.cct \
#      $$SRC_DIR/operatorsP0/region/pmaximumselection.cct \
#      $$SRC_DIR/operatorsP0/region/pminimumselection.cct \
#      $$SRC_DIR/operatorsP0/region/prelabelingfromarray.cct \
#      $$SRC_DIR/operatorsP0/region/pvarianceselection.cct \
#      $$SRC_DIR/operatorsP0/regionfeaturesextraction/pregiondepth.cct \
#      $$SRC_DIR/operatorsP0/regionfeaturesextraction/pregionheight.cct \
#      $$SRC_DIR/operatorsP0/regionfeaturesextraction/pregionwidth.cct \
#      $$SRC_DIR/operatorsP0/segmentation/graphbasedsegmentation/convolve.h \
#      $$SRC_DIR/operatorsP0/segmentation/graphbasedsegmentation/disjoint-set.h \
#      $$SRC_DIR/operatorsP0/segmentation/graphbasedsegmentation/filter.h \
#      $$SRC_DIR/operatorsP0/segmentation/graphbasedsegmentation/image.h \
#      $$SRC_DIR/operatorsP0/segmentation/graphbasedsegmentation/imconv.h \
#      $$SRC_DIR/operatorsP0/segmentation/graphbasedsegmentation/imutil.h \
#      $$SRC_DIR/operatorsP0/segmentation/graphbasedsegmentation/misc.h \
#      $$SRC_DIR/operatorsP0/segmentation/graphbasedsegmentation/pnmfile.h \
#      $$SRC_DIR/operatorsP0/segmentation/graphbasedsegmentation/segment-graph.h \
#      $$SRC_DIR/operatorsP0/segmentation/graphbasedsegmentation/segment-image.h \
#      $$SRC_DIR/operatorsP0/segmentation/pboundarylabeling.cct \
#      $$SRC_DIR/operatorsP0/segmentation/pboundarymerging.cct \
#      $$SRC_DIR/operatorsP0/segmentation/pcontrast1quadtree.cct \
#      $$SRC_DIR/operatorsP0/segmentation/pcontrastaggregation.cct \
#      $$SRC_DIR/operatorsP0/segmentation/pcontrastmerging.cct \
#      $$SRC_DIR/operatorsP0/segmentation/pcontrastquadtree.cct \
#      $$SRC_DIR/operatorsP0/segmentation/pedgebasedragpruning.cct \
#      $$SRC_DIR/operatorsP0/segmentation/pentropymerging.cct \
#      $$SRC_DIR/operatorsP0/segmentation/pentropyquadtree.cct \
#      $$SRC_DIR/operatorsP0/segmentation/pgaussaggregation.cct \
#      $$SRC_DIR/operatorsP0/segmentation/phistomerging.cct \
#      $$SRC_DIR/operatorsP0/segmentation/plabelmerging.cct \
#      $$SRC_DIR/operatorsP0/segmentation/pmeanaggregation.cct \
#      $$SRC_DIR/operatorsP0/segmentation/pmeanmerging.cct \
#      $$SRC_DIR/operatorsP0/segmentation/pmumfordshahmerging.cct \
#      $$SRC_DIR/operatorsP0/segmentation/puniformitymerging.cct \
#      $$SRC_DIR/operatorsP0/segmentation/puniformityquadtree.cct \
#      $$SRC_DIR/operatorsP0/segmentation/pvarianceaggregation.cct \
#      $$SRC_DIR/operatorsP0/segmentation/pvariancemerging.cct \
#      $$SRC_DIR/operatorsP0/segmentation/pvariancequadtree.cct \
#      $$SRC_DIR/operatorsP0/surfacefitting/ppolynomialfitting.cct \
#      $$SRC_DIR/operatorsP0/thresholding/pbinarization.cct \
#      $$SRC_DIR/operatorsP0/thresholding/pcorrelationbinarization.cct \
#      $$SRC_DIR/operatorsP0/thresholding/pentropybinarization.cct \
#      $$SRC_DIR/operatorsP0/thresholding/pmassbinarization.cct \
#      $$SRC_DIR/operatorsP0/thresholding/prankthresholding.cct \
#      $$SRC_DIR/operatorsP0/thresholding/pthresholding.cct \
#      $$SRC_DIR/operatorsP0/thresholding/pvariancebinarization.cct \
#      $$SRC_DIR/operatorsP0/transformation/convolution.h \
#      $$SRC_DIR/operatorsP0/transformation/paddborder.cct \
#      $$SRC_DIR/operatorsP0/transformation/pbellrescale.cct \
#      $$SRC_DIR/operatorsP0/transformation/pbicubicrescale.cct \
#      $$SRC_DIR/operatorsP0/transformation/pextrude1d22d.cct \
#      $$SRC_DIR/operatorsP0/transformation/pflip.cct \
#      $$SRC_DIR/operatorsP0/transformation/phermiterescale.cct \
#      $$SRC_DIR/operatorsP0/transformation/planczosrescale.cct \
#      $$SRC_DIR/operatorsP0/transformation/plinearrescale.cct \
#      $$SRC_DIR/operatorsP0/transformation/pmaxprojection.cct \
#      $$SRC_DIR/operatorsP0/transformation/pmeanprojection.cct \
#      $$SRC_DIR/operatorsP0/transformation/pmitchellrescale.cct \
#      $$SRC_DIR/operatorsP0/transformation/prescale.cct \
#      $$SRC_DIR/operatorsP0/transformation/presize.cct \
#      $$SRC_DIR/operatorsP0/transformation/protation.cct \
#      $$SRC_DIR/operatorsP0/transformation/pscrolling.cct \
#      $$SRC_DIR/operatorsP0/transformation/ptranslation.cct \
#      $$SRC_DIR/operatorsP0/transformation/ptransposition.cct \
#      $$SRC_DIR/operatorsP0/utility/paddnoise.cct \
#      $$SRC_DIR/operatorsP0/utility/paddslice.cct \
#      $$SRC_DIR/operatorsP0/utility/pcliparea.cct \
#      $$SRC_DIR/operatorsP0/utility/pcopyborder.cct \
#      $$SRC_DIR/operatorsP0/utility/pdepth2graylevel.cct \
#      $$SRC_DIR/operatorsP0/utility/pextractregion.cct \
#      $$SRC_DIR/operatorsP0/utility/pextractsubimage.cct \
#      $$SRC_DIR/operatorsP0/utility/pgetband.cct \
#      $$SRC_DIR/operatorsP0/utility/pgetslice.cct \
#      $$SRC_DIR/operatorsP0/utility/pgraylevel2depth.cct \
#      $$SRC_DIR/operatorsP0/utility/pinsertregion.cct \
#      $$SRC_DIR/operatorsP0/utility/pinsertsubimage.cct \
#      $$SRC_DIR/operatorsP0/utility/pmergeimages.cct \
#      $$SRC_DIR/operatorsP0/utility/ppixelvalue.cct \
#      $$SRC_DIR/operatorsP0/utility/premoveslice.cct \
#      $$SRC_DIR/operatorsP0/utility/psetband.cct \
#      $$SRC_DIR/operatorsP0/utility/psetborder.cct \
#      $$SRC_DIR/operatorsP0/utility/psetpixel.cct \
#      $$SRC_DIR/operatorsP0/utility/psetslice.cct \
#      $$SRC_DIR/operatorsP0/utility/psplitimage.cct \
#      $$SRC_DIR/operatorsP0/visualization/pcolorize.cct \
#      $$SRC_DIR/operatorsP0/visualization/psuperimposition.cct

SOURCES += \
      $$SRC_DIR/objects/bundled.cpp \
      $$SRC_DIR/objects/collection.cpp \
      $$SRC_DIR/objects/errc.cpp \
      $$SRC_DIR/objects/graph.cpp \
      $$SRC_DIR/objects/main.cpp \
      $$SRC_DIR/objects/pobject.cpp \
      $$SRC_DIR/objects/region.cpp \


#      $$SRC_DIR/operatorsP0/arithmetic/pabs.cpp \
#      $$SRC_DIR/operatorsP0/arithmetic/padd.cpp \
#      $$SRC_DIR/operatorsP0/arithmetic/paddcst.cpp \
#      $$SRC_DIR/operatorsP0/arithmetic/paddval.cpp \
#      $$SRC_DIR/operatorsP0/arithmetic/pblend.cpp \
#      $$SRC_DIR/operatorsP0/arithmetic/pclipvalues.cpp \
#      $$SRC_DIR/operatorsP0/arithmetic/pconvolution.cpp \
#      $$SRC_DIR/operatorsP0/arithmetic/pdif.cpp \
#      $$SRC_DIR/operatorsP0/arithmetic/pdiv.cpp \
#      $$SRC_DIR/operatorsP0/arithmetic/pdivcst.cpp \
#      $$SRC_DIR/operatorsP0/arithmetic/pdivval.cpp \
#      $$SRC_DIR/operatorsP0/arithmetic/pexp.cpp \
#      $$SRC_DIR/operatorsP0/arithmetic/pintegralimage.cpp \
#      $$SRC_DIR/operatorsP0/arithmetic/plipadd.cpp \
#      $$SRC_DIR/operatorsP0/arithmetic/plipmultcst.cpp \
#      $$SRC_DIR/operatorsP0/arithmetic/plipsub.cpp \
#      $$SRC_DIR/operatorsP0/arithmetic/plog.cpp \
#      $$SRC_DIR/operatorsP0/arithmetic/pmax.cpp \
#      $$SRC_DIR/operatorsP0/arithmetic/pmean.cpp \
#      $$SRC_DIR/operatorsP0/arithmetic/pmin.cpp \
#      $$SRC_DIR/operatorsP0/arithmetic/pmult.cpp \
#      $$SRC_DIR/operatorsP0/arithmetic/pmultcst.cpp \
#      $$SRC_DIR/operatorsP0/arithmetic/pmultval.cpp \
#      $$SRC_DIR/operatorsP0/arithmetic/pnormalization.cpp \
#      $$SRC_DIR/operatorsP0/arithmetic/ppow.cpp \
#      $$SRC_DIR/operatorsP0/arithmetic/pround.cpp \
#      $$SRC_DIR/operatorsP0/arithmetic/psetcst.cpp \
#      $$SRC_DIR/operatorsP0/arithmetic/psqrt.cpp \
#      $$SRC_DIR/operatorsP0/arithmetic/psquareintegralimage.cpp \
#      $$SRC_DIR/operatorsP0/arithmetic/psub.cpp \
#      $$SRC_DIR/operatorsP0/arithmetic/psubval.cpp \
#      $$SRC_DIR/operatorsP0/array/parray2array.cpp \
#      $$SRC_DIR/operatorsP0/array/parrayargmax.cpp \
#      $$SRC_DIR/operatorsP0/array/parraycovarmat.cpp \
#      $$SRC_DIR/operatorsP0/array/parrayeuclideannorm.cpp \
#      $$SRC_DIR/operatorsP0/array/parraygetvalue.cpp \
#      $$SRC_DIR/operatorsP0/array/parraymean.cpp \
#      $$SRC_DIR/operatorsP0/array/parraymedian.cpp \
#      $$SRC_DIR/operatorsP0/array/parraymode.cpp \
#      $$SRC_DIR/operatorsP0/array/parraynorm.cpp \
#      $$SRC_DIR/operatorsP0/array/parraysize.cpp \
#      $$SRC_DIR/operatorsP0/array/parraysmax.cpp \
#      $$SRC_DIR/operatorsP0/array/parraysmean.cpp \
#      $$SRC_DIR/operatorsP0/array/parraysmin.cpp \
#      $$SRC_DIR/operatorsP0/array/parraysnorm.cpp \
#      $$SRC_DIR/operatorsP0/array/pcorrelationcoefficient.cpp \
#      $$SRC_DIR/operatorsP0/array/pcreatearray.cpp \
#      $$SRC_DIR/operatorsP0/casting/parray2im.cpp \
#      $$SRC_DIR/operatorsP0/casting/pgr2im.cpp \
#      $$SRC_DIR/operatorsP0/casting/pgr2rg.cpp \
#      $$SRC_DIR/operatorsP0/casting/pim2array.cpp \
#      $$SRC_DIR/operatorsP0/casting/pim2d23d.cpp \
#      $$SRC_DIR/operatorsP0/casting/pim2rg.cpp \
#      $$SRC_DIR/operatorsP0/casting/pim2sf.cpp \
#      $$SRC_DIR/operatorsP0/casting/pim2sl.cpp \
#      $$SRC_DIR/operatorsP0/casting/pim2uc.cpp \
#      $$SRC_DIR/operatorsP0/casting/pim3d22d.cpp \
#      $$SRC_DIR/operatorsP0/casting/pimc2img.cpp \
#      $$SRC_DIR/operatorsP0/casting/pimc2imx.cpp \
#      $$SRC_DIR/operatorsP0/casting/pimg2imc.cpp \
#      $$SRC_DIR/operatorsP0/casting/pimg2imx.cpp \
#      $$SRC_DIR/operatorsP0/casting/pimgs2imc.cpp \
#      $$SRC_DIR/operatorsP0/casting/pimgs2imx.cpp \
#      $$SRC_DIR/operatorsP0/casting/pimx2imc.cpp \
#      $$SRC_DIR/operatorsP0/casting/pimx2img.cpp \
#      $$SRC_DIR/operatorsP0/casting/prg2gr.cpp \
#      $$SRC_DIR/operatorsP0/casting/prg2im.cpp \
#      $$SRC_DIR/operatorsP0/casting/prg2imc.cpp \
#      $$SRC_DIR/operatorsP0/classification/pgaussclassification.cpp \
#      $$SRC_DIR/operatorsP0/classification/pkmeans.cpp \
#      $$SRC_DIR/operatorsP0/classification/pknn.cpp \
#      $$SRC_DIR/operatorsP0/collection/pcol2csv.cpp \
#      $$SRC_DIR/operatorsP0/collection/pcol2txt.cpp \
#      $$SRC_DIR/operatorsP0/collection/pcolcatenateitem.cpp \
#      $$SRC_DIR/operatorsP0/collection/pcolgetimages.cpp \
#      $$SRC_DIR/operatorsP0/collection/pcolgetobject.cpp \
#      $$SRC_DIR/operatorsP0/collection/pcolgetvalue.cpp \
#      $$SRC_DIR/operatorsP0/collection/pcolremoveitem.cpp \
#      $$SRC_DIR/operatorsP0/collection/pcolrenameitem.cpp \
#      $$SRC_DIR/operatorsP0/collection/pcolsetobject.cpp \
#      $$SRC_DIR/operatorsP0/collection/pcolsetvalue.cpp \
#      $$SRC_DIR/operatorsP0/collection/pnewcollection.cpp \
#      $$SRC_DIR/operatorsP0/collection/pobject2col.cpp \
#      $$SRC_DIR/operatorsP0/collection/ptxt2col.cpp \
#      $$SRC_DIR/operatorsP0/color/pcmyk2rgb.cpp \
#      $$SRC_DIR/operatorsP0/color/pgray2bw.cpp \
#      $$SRC_DIR/operatorsP0/color/pgray2falsecolor.cpp \
#      $$SRC_DIR/operatorsP0/color/phsi2rgb.cpp \
#      $$SRC_DIR/operatorsP0/color/phsl2rgb.cpp \
#      $$SRC_DIR/operatorsP0/color/phsv2rgb.cpp \
#      $$SRC_DIR/operatorsP0/color/plab2lch.cpp \
#      $$SRC_DIR/operatorsP0/color/pluv2lch.cpp \
#      $$SRC_DIR/operatorsP0/color/prgb2ast.cpp \
#      $$SRC_DIR/operatorsP0/color/prgb2cmyk.cpp \
#      $$SRC_DIR/operatorsP0/color/prgb2gray.cpp \
#      $$SRC_DIR/operatorsP0/color/prgb2hsi.cpp \
#      $$SRC_DIR/operatorsP0/color/prgb2hsl.cpp \
#      $$SRC_DIR/operatorsP0/color/prgb2hsv.cpp \
#      $$SRC_DIR/operatorsP0/color/prgb2i1i2i3.cpp \
#      $$SRC_DIR/operatorsP0/color/prgb2pca.cpp \
#      $$SRC_DIR/operatorsP0/color/prgb2rngnbn.cpp \
#      $$SRC_DIR/operatorsP0/color/prgb2wry.cpp \
#      $$SRC_DIR/operatorsP0/color/prgb2xyz.cpp \
#      $$SRC_DIR/operatorsP0/color/prgb2ycbcr.cpp \
#      $$SRC_DIR/operatorsP0/color/prgb2ych1ch2.cpp \
#      $$SRC_DIR/operatorsP0/color/prgb2yiq.cpp \
#      $$SRC_DIR/operatorsP0/color/prgb2yuv.cpp \
#      $$SRC_DIR/operatorsP0/color/pxyz2lab.cpp \
#      $$SRC_DIR/operatorsP0/color/pxyz2luv.cpp \
#      $$SRC_DIR/operatorsP0/color/pxyz2rgb.cpp \
#      $$SRC_DIR/operatorsP0/color/pyuv2rgb.cpp \
#      $$SRC_DIR/operatorsP0/contour/pbarbremoval.cpp \
#      $$SRC_DIR/operatorsP0/contour/pblindedgeclosing.cpp \
#      $$SRC_DIR/operatorsP0/contour/pclosedcontourselection.cpp \
#      $$SRC_DIR/operatorsP0/contour/pcontourextensionconic.cpp \
#      $$SRC_DIR/operatorsP0/contour/pcontourextensionrect.cpp \
#      $$SRC_DIR/operatorsP0/contour/pcontourselection.cpp \
#      $$SRC_DIR/operatorsP0/contour/pdistance.cpp \
#      $$SRC_DIR/operatorsP0/contour/pdistance1.cpp \
#      $$SRC_DIR/operatorsP0/contour/pedgeclosing.cpp \
#      $$SRC_DIR/operatorsP0/contour/pedgedirection.cpp \
#      $$SRC_DIR/operatorsP0/contour/pellipsoidalapproximation.cpp \
#      $$SRC_DIR/operatorsP0/contour/phoughlines.cpp \
#      \# $$SRC_DIR/operatorsP0/contour/popencontourselection.cpp \
#      $$SRC_DIR/operatorsP0/contour/ppolygonalapproximation.cpp \
#      $$SRC_DIR/operatorsP0/contour/ppostthinning.cpp \
#      $$SRC_DIR/operatorsP0/conversion/ppan2analyze.cpp \
#      $$SRC_DIR/operatorsP0/conversion/ppan2bmp.cpp \
#      $$SRC_DIR/operatorsP0/conversion/ppan2d23d.cpp \
#      $$SRC_DIR/operatorsP0/conversion/ppan2fits.cpp \
#      $$SRC_DIR/operatorsP0/conversion/ppan2gif.cpp \
#      $$SRC_DIR/operatorsP0/conversion/ppan2jpeg.cpp \
#      $$SRC_DIR/operatorsP0/conversion/ppan2pan.cpp \
#      $$SRC_DIR/operatorsP0/conversion/ppan2png.cpp \
#      $$SRC_DIR/operatorsP0/conversion/ppan2ppm.cpp \
#      $$SRC_DIR/operatorsP0/conversion/ppan2ps.cpp \
#      $$SRC_DIR/operatorsP0/conversion/ppan2raw.cpp \
#      $$SRC_DIR/operatorsP0/conversion/ppan2tiff.cpp \
#      $$SRC_DIR/operatorsP0/conversion/ppan2txt.cpp \
#      $$SRC_DIR/operatorsP0/conversion/ppan2vff.cpp \
#      $$SRC_DIR/operatorsP0/conversion/ppan3d22d.cpp \
#      $$SRC_DIR/operatorsP0/conversion/pparrec2pan.cpp \
#      $$SRC_DIR/operatorsP0/conversion/ppng2pan.cpp \
#      $$SRC_DIR/operatorsP0/conversion/pppm2pan.cpp \
#      $$SRC_DIR/operatorsP0/conversion/pras2pan.cpp \
#      $$SRC_DIR/operatorsP0/conversion/praw2pan.cpp \
#      $$SRC_DIR/operatorsP0/conversion/ptiff2pan.cpp \
#      $$SRC_DIR/operatorsP0/conversion/ptxt2pan.cpp \
#      $$SRC_DIR/operatorsP0/conversion/pvff2pan.cpp \
#      $$SRC_DIR/operatorsP0/conversion/pyuv2pan.cpp \
#      $$SRC_DIR/operatorsP0/edgedetection/pderiche.cpp \
#      $$SRC_DIR/operatorsP0/edgedetection/pdivneumann.cpp \
#      $$SRC_DIR/operatorsP0/edgedetection/pgradient.cpp \
#      $$SRC_DIR/operatorsP0/edgedetection/pgradientthreshold.cpp \
#      $$SRC_DIR/operatorsP0/edgedetection/pgradneumann.cpp \
#      $$SRC_DIR/operatorsP0/edgedetection/plaplacian.cpp \
#      $$SRC_DIR/operatorsP0/edgedetection/pnonmaximasuppression.cpp \
#      $$SRC_DIR/operatorsP0/edgedetection/pprewitt.cpp \
#      $$SRC_DIR/operatorsP0/edgedetection/proberts.cpp \
#      $$SRC_DIR/operatorsP0/edgedetection/pshen.cpp \
#      $$SRC_DIR/operatorsP0/edgedetection/psobel.cpp \
#      $$SRC_DIR/operatorsP0/edgedetection/pzerocross.cpp \
#      $$SRC_DIR/operatorsP0/evaluation/passessboundaryprecision.cpp \
#      $$SRC_DIR/operatorsP0/evaluation/passessdetectionaccuracy.cpp \
#      $$SRC_DIR/operatorsP0/evaluation/passessfragmentationconsistency.cpp \
#      $$SRC_DIR/operatorsP0/evaluation/passesssegmentationalgorithm.cpp \
#      $$SRC_DIR/operatorsP0/evaluation/passessshapefidelity.cpp \
#      $$SRC_DIR/operatorsP0/evaluation/passesstopologypreservation.cpp \
#      $$SRC_DIR/operatorsP0/evaluation/pborsotti.cpp \
#      $$SRC_DIR/operatorsP0/evaluation/pdisplayperformancevalues.cpp \
#      $$SRC_DIR/operatorsP0/evaluation/pinterregioncontrast.cpp \
#      $$SRC_DIR/operatorsP0/evaluation/pintraregionuniformity.cpp \
#      $$SRC_DIR/operatorsP0/evaluation/pmse.cpp \
#      $$SRC_DIR/operatorsP0/evaluation/ppsnr.cpp \
#      $$SRC_DIR/operatorsP0/evaluation/pranksegmentationalgorithms.cpp \
#      $$SRC_DIR/operatorsP0/evaluation/pranksegmentationalgorithmsfromfolders.cpp \
#      $$SRC_DIR/operatorsP0/evaluation/psnr.cpp \
#      $$SRC_DIR/operatorsP0/evaluation/pvinet.cpp \
#      $$SRC_DIR/operatorsP0/evaluation/pzeboudj.cpp \
#      $$SRC_DIR/operatorsP0/filtering/padaptivemeanfiltering.cpp \
#      $$SRC_DIR/operatorsP0/filtering/pdenoisePDE.cpp \
#      $$SRC_DIR/operatorsP0/filtering/pderichesmoothing.cpp \
#      $$SRC_DIR/operatorsP0/filtering/pexponentialfiltering.cpp \
#      $$SRC_DIR/operatorsP0/filtering/pgaussianfiltering.cpp \
#      $$SRC_DIR/operatorsP0/filtering/pmalikperonafiltering.cpp \
#      $$SRC_DIR/operatorsP0/filtering/pmcmfiltering.cpp \
#      $$SRC_DIR/operatorsP0/filtering/pmeanfiltering.cpp \
#      $$SRC_DIR/operatorsP0/filtering/pmedianfiltering.cpp \
#      $$SRC_DIR/operatorsP0/filtering/pnagaofiltering.cpp \
#      $$SRC_DIR/operatorsP0/filtering/pnonlocalmeanfiltering.cpp \
#      $$SRC_DIR/operatorsP0/filtering/pnonlocalmedianfiltering.cpp \
#      $$SRC_DIR/operatorsP0/filtering/poutrangefiltering.cpp \
#      $$SRC_DIR/operatorsP0/filtering/ppeergroupfiltering.cpp \
#      $$SRC_DIR/operatorsP0/filtering/psharp.cpp \
#      $$SRC_DIR/operatorsP0/filtering/pshensmoothing.cpp \
#      $$SRC_DIR/operatorsP0/filtering/psigmafiltering.cpp \
#      $$SRC_DIR/operatorsP0/filtering/psnnfiltering.cpp \
#      $$SRC_DIR/operatorsP0/filtering/pvariancefiltering.cpp \
#      $$SRC_DIR/operatorsP0/frequency/pbutterworthfilter.cpp \
#      $$SRC_DIR/operatorsP0/frequency/pdwt.cpp \
#      $$SRC_DIR/operatorsP0/frequency/pfft.cpp \
#      $$SRC_DIR/operatorsP0/frequency/pfftconvolution.cpp \
#      $$SRC_DIR/operatorsP0/frequency/pfftcorrelation.cpp \
#      $$SRC_DIR/operatorsP0/frequency/pfftdeconvolution.cpp \
#      $$SRC_DIR/operatorsP0/frequency/pfftshift.cpp \
#      $$SRC_DIR/operatorsP0/frequency/pgaussianfilter.cpp \
#      $$SRC_DIR/operatorsP0/frequency/pgetsubband.cpp \
#      $$SRC_DIR/operatorsP0/frequency/pidwt.cpp \
#      $$SRC_DIR/operatorsP0/frequency/pifft.cpp \
#      $$SRC_DIR/operatorsP0/frequency/pmodulus.cpp \
#      $$SRC_DIR/operatorsP0/frequency/pphase.cpp \
#      $$SRC_DIR/operatorsP0/frequency/pqmf.cpp \
#      $$SRC_DIR/operatorsP0/frequency/psetsubband.cpp \
#      $$SRC_DIR/operatorsP0/graph/pbetagraph.cpp \
#      $$SRC_DIR/operatorsP0/graph/pdelaunay.cpp \
#      $$SRC_DIR/operatorsP0/graph/pedgecutting.cpp \
#      $$SRC_DIR/operatorsP0/graph/pedgevisu.cpp \
#      $$SRC_DIR/operatorsP0/graph/pgraphneighbours.cpp \
#      $$SRC_DIR/operatorsP0/graph/pgraphpruning.cpp \
#      $$SRC_DIR/operatorsP0/graph/pgraphvisu.cpp \
#      $$SRC_DIR/operatorsP0/graph/pleafcutting.cpp \
#      $$SRC_DIR/operatorsP0/graph/pmst.cpp \
#      $$SRC_DIR/operatorsP0/graph/pnodedisc.cpp \
#      $$SRC_DIR/operatorsP0/graph/pnodevisu.cpp \
#      $$SRC_DIR/operatorsP0/graph/psig.cpp \
#      $$SRC_DIR/operatorsP0/imagefeatureextraction/pcontrast1value.cpp \
#      $$SRC_DIR/operatorsP0/imagefeatureextraction/pcontrastvalue.cpp \
#      $$SRC_DIR/operatorsP0/imagefeatureextraction/penergyvalue.cpp \
#      $$SRC_DIR/operatorsP0/imagefeatureextraction/pentropyvalue.cpp \
#      $$SRC_DIR/operatorsP0/imagefeatureextraction/phistogram.cpp \
#      $$SRC_DIR/operatorsP0/imagefeatureextraction/plocalextrema.cpp \
#      $$SRC_DIR/operatorsP0/imagefeatureextraction/plocalmaxima.cpp \
#      $$SRC_DIR/operatorsP0/imagefeatureextraction/plocalminima.cpp \
#      $$SRC_DIR/operatorsP0/imagefeatureextraction/pmaximumvalue.cpp \
#      $$SRC_DIR/operatorsP0/imagefeatureextraction/pmeanvalue.cpp \
#      $$SRC_DIR/operatorsP0/imagefeatureextraction/pmedianvalue.cpp \
#      $$SRC_DIR/operatorsP0/imagefeatureextraction/pminimumvalue.cpp \
#      $$SRC_DIR/operatorsP0/imagefeatureextraction/pmodevalue.cpp \
#      $$SRC_DIR/operatorsP0/imagefeatureextraction/pregionalmaxima.cpp \
#      $$SRC_DIR/operatorsP0/imagefeatureextraction/pregionalminima.cpp \
#      $$SRC_DIR/operatorsP0/imagefeatureextraction/psumvalue.cpp \
#      $$SRC_DIR/operatorsP0/imagefeatureextraction/pvalueclassnumber.cpp \
#      $$SRC_DIR/operatorsP0/imagefeatureextraction/pvaluenumber.cpp \
#      $$SRC_DIR/operatorsP0/imagefeatureextraction/pvaluerank.cpp \
#      $$SRC_DIR/operatorsP0/imagefeatureextraction/pvariancevalue.cpp \
#      $$SRC_DIR/operatorsP0/information/pfile.cpp \
#      $$SRC_DIR/operatorsP0/information/pman.cpp \
#      $$SRC_DIR/operatorsP0/information/pmanfr.cpp \
#      $$SRC_DIR/operatorsP0/information/pproperty.cpp \
#      $$SRC_DIR/operatorsP0/information/psetstatus.cpp \
#      $$SRC_DIR/operatorsP0/information/pstatus.cpp \
#      $$SRC_DIR/operatorsP0/information/pversion.cpp \
#      $$SRC_DIR/operatorsP0/interpolation/plinearinterpolation.cpp \
#      $$SRC_DIR/operatorsP0/logic/pand.cpp \
#      $$SRC_DIR/operatorsP0/logic/pinverse.cpp \
#      $$SRC_DIR/operatorsP0/logic/pmask.cpp \
#      $$SRC_DIR/operatorsP0/logic/pnot.cpp \
#      $$SRC_DIR/operatorsP0/logic/por.cpp \
#      $$SRC_DIR/operatorsP0/logic/pxor.cpp \
#      $$SRC_DIR/operatorsP0/luttransform/pextremumsharpening.cpp \
#      $$SRC_DIR/operatorsP0/luttransform/phistogramequalization.cpp \
#      $$SRC_DIR/operatorsP0/luttransform/phistogramspecification.cpp \
#      $$SRC_DIR/operatorsP0/luttransform/plineartransform.cpp \
#      $$SRC_DIR/operatorsP0/luttransform/plogtransform.cpp \
#      $$SRC_DIR/operatorsP0/luttransform/ppowerlawtransform.cpp \
#      $$SRC_DIR/operatorsP0/miscellaneous/prds.cpp \
#      $$SRC_DIR/operatorsP0/miscellaneous/pstereogram.cpp \
#      $$SRC_DIR/operatorsP0/miscellaneous/psubsampling.cpp \
#      $$SRC_DIR/operatorsP0/morphology/pareaclosing.cpp \
#      $$SRC_DIR/operatorsP0/morphology/pareaopening.cpp \
#      $$SRC_DIR/operatorsP0/morphology/pdilatation.cpp \
#      $$SRC_DIR/operatorsP0/morphology/pdilatationreconstruction.cpp \
#      $$SRC_DIR/operatorsP0/morphology/pdilation.cpp \
#      $$SRC_DIR/operatorsP0/morphology/pdilationreconstruction.cpp \
#      $$SRC_DIR/operatorsP0/morphology/perosion.cpp \
#      $$SRC_DIR/operatorsP0/morphology/perosionreconstruction.cpp \
#      $$SRC_DIR/operatorsP0/morphology/pgeodesicdilatation.cpp \
#      $$SRC_DIR/operatorsP0/morphology/pgeodesicdilation.cpp \
#      $$SRC_DIR/operatorsP0/morphology/pgeodesicerosion.cpp \
#      $$SRC_DIR/operatorsP0/morphology/phitormiss.cpp \
#      $$SRC_DIR/operatorsP0/morphology/phomotopicskeletonization.cpp \
#      $$SRC_DIR/operatorsP0/morphology/plineardilatation.cpp \
#      $$SRC_DIR/operatorsP0/morphology/plineardilation.cpp \
#      $$SRC_DIR/operatorsP0/morphology/plinearerosion.cpp \
#      $$SRC_DIR/operatorsP0/morphology/pnonlocaldilation.cpp \
#      $$SRC_DIR/operatorsP0/morphology/pnonlocalerosion.cpp \
#      $$SRC_DIR/operatorsP0/morphology/psedesign.cpp \
#      $$SRC_DIR/operatorsP0/morphology/psedilatation.cpp \
#      $$SRC_DIR/operatorsP0/morphology/psedilation.cpp \
#      $$SRC_DIR/operatorsP0/morphology/pseerosion.cpp \
#      $$SRC_DIR/operatorsP0/morphology/pskeletonization.cpp \
#      $$SRC_DIR/operatorsP0/morphology/pwatershed.cpp \
#      $$SRC_DIR/operatorsP0/motion/pblockmatching.cpp \
#      $$SRC_DIR/operatorsP0/motion/pplotquiver.cpp \
#      $$SRC_DIR/operatorsP0/motion/pregistrationPDE.cpp \
#      $$SRC_DIR/operatorsP0/pointsofinterest/pharris.cpp \
#      $$SRC_DIR/operatorsP0/pointsofinterest/psusan.cpp \
#      $$SRC_DIR/operatorsP0/reconstruction/pgetquadrangle.cpp \
#      $$SRC_DIR/operatorsP0/reconstruction/pquadrangle2rectangle.cpp \
#      $$SRC_DIR/operatorsP0/reconstruction/pskewanglecorrection.cpp \
#      $$SRC_DIR/operatorsP0/region/pareaselection.cpp \
#      $$SRC_DIR/operatorsP0/region/pboundary.cpp \
#      $$SRC_DIR/operatorsP0/region/pboundaryregularization.cpp \
#      $$SRC_DIR/operatorsP0/region/pboundingbox.cpp \
#      $$SRC_DIR/operatorsP0/region/pcenterofmass.cpp \
#      $$SRC_DIR/operatorsP0/region/pcompactnessselection.cpp \
#      $$SRC_DIR/operatorsP0/region/pconvexhull.cpp \
#      $$SRC_DIR/operatorsP0/region/pconvexityselection.cpp \
#      $$SRC_DIR/operatorsP0/region/pdensityselection.cpp \
#      $$SRC_DIR/operatorsP0/region/peccentricityselection.cpp \
#      $$SRC_DIR/operatorsP0/region/pelongationselection.cpp \
#      $$SRC_DIR/operatorsP0/region/penergyselection.cpp \
#      $$SRC_DIR/operatorsP0/region/peulernumberselection.cpp \
#      $$SRC_DIR/operatorsP0/region/pfillhole.cpp \
#      $$SRC_DIR/operatorsP0/region/pholeselection.cpp \
#      $$SRC_DIR/operatorsP0/region/pinnerselection.cpp \
#      $$SRC_DIR/operatorsP0/region/plabelselection.cpp \
#      $$SRC_DIR/operatorsP0/region/plabelsselection.cpp \
#      $$SRC_DIR/operatorsP0/region/plocationselection.cpp \
#      $$SRC_DIR/operatorsP0/region/pmaximumselection.cpp \
#      $$SRC_DIR/operatorsP0/region/pmeanselection.cpp \
#      $$SRC_DIR/operatorsP0/region/pminimumselection.cpp \
#      $$SRC_DIR/operatorsP0/region/porientationselection.cpp \
#      $$SRC_DIR/operatorsP0/region/poutborderselection.cpp \
#      $$SRC_DIR/operatorsP0/region/pperimeterselection.cpp \
#      $$SRC_DIR/operatorsP0/region/prectangularityselection.cpp \
#      $$SRC_DIR/operatorsP0/region/prelabelingfromarray.cpp \
#      $$SRC_DIR/operatorsP0/region/prelabelingwithgraph.cpp \
#      $$SRC_DIR/operatorsP0/region/psizeselection.cpp \
#      $$SRC_DIR/operatorsP0/region/psphericityselection.cpp \
#      $$SRC_DIR/operatorsP0/region/pvarianceselection.cpp \
#      $$SRC_DIR/operatorsP0/region/pvolumeselection.cpp \
#      $$SRC_DIR/operatorsP0/regionfeaturesextraction/pareadisorderfactor.cpp \
#      $$SRC_DIR/operatorsP0/regionfeaturesextraction/pregionarea.cpp \
#      $$SRC_DIR/operatorsP0/regionfeaturesextraction/pregioncompactness.cpp \
#      $$SRC_DIR/operatorsP0/regionfeaturesextraction/pregionconvexity.cpp \
#      $$SRC_DIR/operatorsP0/regionfeaturesextraction/pregiondensity.cpp \
#      $$SRC_DIR/operatorsP0/regionfeaturesextraction/pregiondepth.cpp \
#      $$SRC_DIR/operatorsP0/regionfeaturesextraction/pregioneccentricity.cpp \
#      $$SRC_DIR/operatorsP0/regionfeaturesextraction/pregionelongation.cpp \
#      $$SRC_DIR/operatorsP0/regionfeaturesextraction/pregionenergy.cpp \
#      $$SRC_DIR/operatorsP0/regionfeaturesextraction/pregioneulernumber.cpp \
#      $$SRC_DIR/operatorsP0/regionfeaturesextraction/pregionheight.cpp \
#      $$SRC_DIR/operatorsP0/regionfeaturesextraction/pregionmaximum.cpp \
#      $$SRC_DIR/operatorsP0/regionfeaturesextraction/pregionmean.cpp \
#      $$SRC_DIR/operatorsP0/regionfeaturesextraction/pregionminimum.cpp \
#      $$SRC_DIR/operatorsP0/regionfeaturesextraction/pregionorientation.cpp \
#      $$SRC_DIR/operatorsP0/regionfeaturesextraction/pregionperimeter.cpp \
#      $$SRC_DIR/operatorsP0/regionfeaturesextraction/pregionrectangularity.cpp \
#      $$SRC_DIR/operatorsP0/regionfeaturesextraction/pregionsphericity.cpp \
#      $$SRC_DIR/operatorsP0/regionfeaturesextraction/pregionvariance.cpp \
#      $$SRC_DIR/operatorsP0/regionfeaturesextraction/pregionvolume.cpp \
#      $$SRC_DIR/operatorsP0/regionfeaturesextraction/pregionwidth.cpp \
#      $$SRC_DIR/operatorsP0/segmentation/pboundarylabeling.cpp \
#      $$SRC_DIR/operatorsP0/segmentation/pboundarymerging.cpp \
#      $$SRC_DIR/operatorsP0/segmentation/pcolorquantization.cpp \
#      $$SRC_DIR/operatorsP0/segmentation/pcontrast1quadtree.cpp \
#      $$SRC_DIR/operatorsP0/segmentation/pcontrastaggregation.cpp \
#      $$SRC_DIR/operatorsP0/segmentation/pcontrastmerging.cpp \
#      $$SRC_DIR/operatorsP0/segmentation/pcontrastquadtree.cpp \
#      $$SRC_DIR/operatorsP0/segmentation/pedgebasedragpruning.cpp \
#      $$SRC_DIR/operatorsP0/segmentation/pentropymerging.cpp \
#      $$SRC_DIR/operatorsP0/segmentation/pentropyquadtree.cpp \
#      $$SRC_DIR/operatorsP0/segmentation/pgaussaggregation.cpp \
#      $$SRC_DIR/operatorsP0/segmentation/pgraphbasedsegmentation.cpp \
#      $$SRC_DIR/operatorsP0/segmentation/phistomerging.cpp \
#      $$SRC_DIR/operatorsP0/segmentation/pinnermerging.cpp \
#      $$SRC_DIR/operatorsP0/segmentation/pinnermostmerging.cpp \
#      $$SRC_DIR/operatorsP0/segmentation/plabeling.cpp \
#      $$SRC_DIR/operatorsP0/segmentation/plabelmerging.cpp \
#      $$SRC_DIR/operatorsP0/segmentation/pmeanaggregation.cpp \
#      $$SRC_DIR/operatorsP0/segmentation/pmeanmerging.cpp \
#      $$SRC_DIR/operatorsP0/segmentation/pmeanshiftsegmentation.cpp \
#      $$SRC_DIR/operatorsP0/segmentation/pmumfordshahmerging.cpp \
#      $$SRC_DIR/operatorsP0/segmentation/pseedplacement.cpp \
#      $$SRC_DIR/operatorsP0/segmentation/psimplelineariterativeclustering.cpp \
#      $$SRC_DIR/operatorsP0/segmentation/psuperpixelsegmentation.cpp \
#      \# $$SRC_DIR/operatorsP0/segmentation/puniformitymerging.cpp \
#      $$SRC_DIR/operatorsP0/segmentation/puniformityquadtree.cpp \
#      $$SRC_DIR/operatorsP0/segmentation/pvarianceaggregation.cpp \
#      \# $$SRC_DIR/operatorsP0/segmentation/pvariancemerging.cpp \
#      $$SRC_DIR/operatorsP0/segmentation/pvariancequadtree.cpp \
#      $$SRC_DIR/operatorsP0/segmentation/pvoronoi.cpp \
#      $$SRC_DIR/operatorsP0/surfacefitting/plegendrepolynomialfitting.cpp \
#      $$SRC_DIR/operatorsP0/surfacefitting/plinearregression.cpp \
#      $$SRC_DIR/operatorsP0/surfacefitting/ppolynomialfitting.cpp \
#      $$SRC_DIR/operatorsP0/templatematching/pcrosscorrelation.cpp \
#      $$SRC_DIR/operatorsP0/thresholding/padaptivemeanbinarization.cpp \
#      $$SRC_DIR/operatorsP0/thresholding/pbinarization.cpp \
#      $$SRC_DIR/operatorsP0/thresholding/pchanda.cpp \
#      $$SRC_DIR/operatorsP0/thresholding/pcontrastbinarization.cpp \
#      $$SRC_DIR/operatorsP0/thresholding/pcontrastthresholding.cpp \
#      $$SRC_DIR/operatorsP0/thresholding/pcorrelationbinarization.cpp \
#      $$SRC_DIR/operatorsP0/thresholding/pderavi.cpp \
#      $$SRC_DIR/operatorsP0/thresholding/pentropybinarization.cpp \
#      $$SRC_DIR/operatorsP0/thresholding/pentropythresholding.cpp \
#      $$SRC_DIR/operatorsP0/thresholding/pfisher.cpp \
#      $$SRC_DIR/operatorsP0/thresholding/pfuzzyclustering.cpp \
#      $$SRC_DIR/operatorsP0/thresholding/phistothresholding.cpp \
#      $$SRC_DIR/operatorsP0/thresholding/pmassbinarization.cpp \
#      $$SRC_DIR/operatorsP0/thresholding/pniblackbinarization.cpp \
#      $$SRC_DIR/operatorsP0/thresholding/prankthresholding.cpp \
#      $$SRC_DIR/operatorsP0/thresholding/pthresholding.cpp \
#      $$SRC_DIR/operatorsP0/thresholding/pvariancebinarization.cpp \
#      $$SRC_DIR/operatorsP0/thresholding/pweszka.cpp \
#      $$SRC_DIR/operatorsP0/transformation/paddborder.cpp \
#      $$SRC_DIR/operatorsP0/transformation/pbellrescale.cpp \
#      $$SRC_DIR/operatorsP0/transformation/pbicubicrescale.cpp \
#      $$SRC_DIR/operatorsP0/transformation/pextrude1d22d.cpp \
#      $$SRC_DIR/operatorsP0/transformation/pflip.cpp \
#      $$SRC_DIR/operatorsP0/transformation/phermiterescale.cpp \
#      $$SRC_DIR/operatorsP0/transformation/planczosrescale.cpp \
#      $$SRC_DIR/operatorsP0/transformation/plinearrescale.cpp \
#      $$SRC_DIR/operatorsP0/transformation/pmaxprojection.cpp \
#      $$SRC_DIR/operatorsP0/transformation/pmeanprojection.cpp \
#      $$SRC_DIR/operatorsP0/transformation/pmitchellrescale.cpp \
#      $$SRC_DIR/operatorsP0/transformation/prescale.cpp \
#      $$SRC_DIR/operatorsP0/transformation/presize.cpp \
#      $$SRC_DIR/operatorsP0/transformation/protation.cpp \
#      $$SRC_DIR/operatorsP0/transformation/pscrolling.cpp \
#      $$SRC_DIR/operatorsP0/transformation/ptranslation.cpp \
#      $$SRC_DIR/operatorsP0/transformation/ptransposition.cpp \
#      $$SRC_DIR/operatorsP0/utility/paddnoise.cpp \
#      $$SRC_DIR/operatorsP0/utility/paddslice.cpp \
#      $$SRC_DIR/operatorsP0/utility/pcliparea.cpp \
#      $$SRC_DIR/operatorsP0/utility/pcopyborder.cpp \
#      $$SRC_DIR/operatorsP0/utility/pdepth2graylevel.cpp \
#      $$SRC_DIR/operatorsP0/utility/pextractregion.cpp \
#      $$SRC_DIR/operatorsP0/utility/pextractsubimage.cpp \
#      $$SRC_DIR/operatorsP0/utility/pgetband.cpp \
#      $$SRC_DIR/operatorsP0/utility/pgetslice.cpp \
#      $$SRC_DIR/operatorsP0/utility/pgetwindowaroundpoints.cpp \
#      $$SRC_DIR/operatorsP0/utility/pgraylevel2depth.cpp \
#      $$SRC_DIR/operatorsP0/utility/pinsertregion.cpp \
#      $$SRC_DIR/operatorsP0/utility/pinsertsubimage.cpp \
#      $$SRC_DIR/operatorsP0/utility/pmergeimages.cpp \
#      $$SRC_DIR/operatorsP0/utility/pnewimage.cpp \
#      $$SRC_DIR/operatorsP0/utility/ppixelvalue.cpp \
#      $$SRC_DIR/operatorsP0/utility/premoveslice.cpp \
#      $$SRC_DIR/operatorsP0/utility/psetband.cpp \
#      $$SRC_DIR/operatorsP0/utility/psetborder.cpp \
#      $$SRC_DIR/operatorsP0/utility/psetpixel.cpp \
#      $$SRC_DIR/operatorsP0/utility/psetslice.cpp \
#      $$SRC_DIR/operatorsP0/utility/pshapedesign.cpp \
#      $$SRC_DIR/operatorsP0/utility/psplitimage.cpp \
#      $$SRC_DIR/operatorsP0/visualization/pcolorcube.cpp \
#      $$SRC_DIR/operatorsP0/visualization/pcolorize.cpp \
#      $$SRC_DIR/operatorsP0/visualization/pcontentsdisplay.cpp \
#      $$SRC_DIR/operatorsP0/visualization/pplot1d.cpp \
#      $$SRC_DIR/operatorsP0/visualization/psuperimposition.cpp





#$$SRC_DIR/operatorsP0/conversion/jpeg/cdjpeg.c \
#$$SRC_DIR/operatorsP0/conversion/jpeg/cjpeg.c \
#$$SRC_DIR/operatorsP0/conversion/jpeg/djpeg.c \
#$$SRC_DIR/operatorsP0/conversion/jpeg/jaricom.c \
#$$SRC_DIR/operatorsP0/conversion/jpeg/jcapimin.c \
#$$SRC_DIR/operatorsP0/conversion/jpeg/jcapistd.c \
#$$SRC_DIR/operatorsP0/conversion/jpeg/jcarith.c \
#$$SRC_DIR/operatorsP0/conversion/jpeg/jccoefct.c \
#$$SRC_DIR/operatorsP0/conversion/jpeg/jccolor.c \
#$$SRC_DIR/operatorsP0/conversion/jpeg/jcdctmgr.c \
#$$SRC_DIR/operatorsP0/conversion/jpeg/jchuff.c \
#$$SRC_DIR/operatorsP0/conversion/jpeg/jcinit.c \
#$$SRC_DIR/operatorsP0/conversion/jpeg/jcmainct.c \
#$$SRC_DIR/operatorsP0/conversion/jpeg/jcmarker.c \
#$$SRC_DIR/operatorsP0/conversion/jpeg/jcmaster.c \
#$$SRC_DIR/operatorsP0/conversion/jpeg/jcomapi.c \
#$$SRC_DIR/operatorsP0/conversion/jpeg/jcparam.c \
#$$SRC_DIR/operatorsP0/conversion/jpeg/jcprepct.c \
#$$SRC_DIR/operatorsP0/conversion/jpeg/jcsample.c \
#$$SRC_DIR/operatorsP0/conversion/jpeg/jdapimin.c \
#$$SRC_DIR/operatorsP0/conversion/jpeg/jdapistd.c \
#$$SRC_DIR/operatorsP0/conversion/jpeg/jdarith.c \
#$$SRC_DIR/operatorsP0/conversion/jpeg/jdatadst.c \
#$$SRC_DIR/operatorsP0/conversion/jpeg/jdatasrc.c \
#$$SRC_DIR/operatorsP0/conversion/jpeg/jdcoefct.c \
#$$SRC_DIR/operatorsP0/conversion/jpeg/jdcolor.c \
#$$SRC_DIR/operatorsP0/conversion/jpeg/jddctmgr.c \
#$$SRC_DIR/operatorsP0/conversion/jpeg/jdhuff.c \
#$$SRC_DIR/operatorsP0/conversion/jpeg/jdinput.c \
#$$SRC_DIR/operatorsP0/conversion/jpeg/jdmainct.c \
#$$SRC_DIR/operatorsP0/conversion/jpeg/jdmarker.c \
#$$SRC_DIR/operatorsP0/conversion/jpeg/jdmaster.c \
#$$SRC_DIR/operatorsP0/conversion/jpeg/jdmerge.c \
#$$SRC_DIR/operatorsP0/conversion/jpeg/jdpostct.c \
#$$SRC_DIR/operatorsP0/conversion/jpeg/jdsample.c \
#$$SRC_DIR/operatorsP0/conversion/jpeg/jerror.c \
#$$SRC_DIR/operatorsP0/conversion/jpeg/jfdctflt.c \
#$$SRC_DIR/operatorsP0/conversion/jpeg/jfdctfst.c \
#$$SRC_DIR/operatorsP0/conversion/jpeg/jfdctint.c \
#$$SRC_DIR/operatorsP0/conversion/jpeg/jidctflt.c \
#$$SRC_DIR/operatorsP0/conversion/jpeg/jidctfst.c \
#$$SRC_DIR/operatorsP0/conversion/jpeg/jidctint.c \
#$$SRC_DIR/operatorsP0/conversion/jpeg/jmemansi.c \
#$$SRC_DIR/operatorsP0/conversion/jpeg/jmemmgr.c \
#$$SRC_DIR/operatorsP0/conversion/jpeg/jmemnobs.c \
#$$SRC_DIR/operatorsP0/conversion/jpeg/jquant1.c \
#$$SRC_DIR/operatorsP0/conversion/jpeg/jquant2.c \
#$$SRC_DIR/operatorsP0/conversion/jpeg/jutils.c \
#$$SRC_DIR/operatorsP0/conversion/jpeg/rdcolmap.c \
#$$SRC_DIR/operatorsP0/conversion/panalyze2pan.cpp \
#$$SRC_DIR/operatorsP0/conversion/pany2pan.cpp \
#$$SRC_DIR/operatorsP0/conversion/pbmp2pan.cpp \
#$$SRC_DIR/operatorsP0/conversion/pfits2pan.cpp \
#$$SRC_DIR/operatorsP0/conversion/pgif2pan.cpp \
#$$SRC_DIR/operatorsP0/conversion/pjpeg2pan.cpp \
#$$SRC_DIR/operatorsP0/conversion/png/adler32.c \
#$$SRC_DIR/operatorsP0/conversion/png/compress.c \
#$$SRC_DIR/operatorsP0/conversion/png/cpng.c \
#$$SRC_DIR/operatorsP0/conversion/png/crc32.c \
#\# $$SRC_DIR/operatorsP0/conversion/png/deflate.c \
#$$SRC_DIR/operatorsP0/conversion/png/dpng.c \
#$$SRC_DIR/operatorsP0/conversion/png/gzclose.c \
#$$SRC_DIR/operatorsP0/conversion/png/gzlib.c \
#$$SRC_DIR/operatorsP0/conversion/png/gzread.c \
#\# $$SRC_DIR/operatorsP0/conversion/png/gzwrite.c \
#$$SRC_DIR/operatorsP0/conversion/png/infback.c \
#$$SRC_DIR/operatorsP0/conversion/png/inffast.c \
#\# $$SRC_DIR/operatorsP0/conversion/png/inflate.c \
#$$SRC_DIR/operatorsP0/conversion/png/inftrees.c \
#$$SRC_DIR/operatorsP0/conversion/png/png.c \
#$$SRC_DIR/operatorsP0/conversion/png/pngerror.c \
#$$SRC_DIR/operatorsP0/conversion/png/pngget.c \
#$$SRC_DIR/operatorsP0/conversion/png/pngmem.c \
#$$SRC_DIR/operatorsP0/conversion/png/pngpread.c \
#$$SRC_DIR/operatorsP0/conversion/png/pngread.c \
#$$SRC_DIR/operatorsP0/conversion/png/pngrio.c \
#$$SRC_DIR/operatorsP0/conversion/png/pngrtran.c \
#$$SRC_DIR/operatorsP0/conversion/png/pngrutil.c \
#$$SRC_DIR/operatorsP0/conversion/png/pngset.c \
#\# $$SRC_DIR/operatorsP0/conversion/png/pngtest.c \
#$$SRC_DIR/operatorsP0/conversion/png/pngtrans.c \
#$$SRC_DIR/operatorsP0/conversion/png/pngwio.c \
#$$SRC_DIR/operatorsP0/conversion/png/pngwrite.c \
#$$SRC_DIR/operatorsP0/conversion/png/pngwtran.c \
#$$SRC_DIR/operatorsP0/conversion/png/pngwutil.c \
#$$SRC_DIR/operatorsP0/conversion/png/trees.c \
#$$SRC_DIR/operatorsP0/conversion/png/uncompr.c \
#$$SRC_DIR/operatorsP0/conversion/png/zutil.c \
