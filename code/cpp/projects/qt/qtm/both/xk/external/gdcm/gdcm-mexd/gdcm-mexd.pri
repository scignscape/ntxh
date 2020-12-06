
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

include($$ROOT_DIR/../preferred/sysr.pri)

include($$ROOT_DIR/../preferred/gdcm.pri)

INCLUDEPATH += $$SRC_GROUP_DIR


INCLUDEPATH += $$SRC_GROUP_DIR/gdcm-common
INCLUDEPATH += $$SRC_GROUP_DIR/gdcm-dsed
INCLUDEPATH += $$SRC_GROUP_DIR/gdcm-dict
INCLUDEPATH += $$SRC_GROUP_DIR/gdcm-msff
INCLUDEPATH += $$SRC_GROUP_DIR/Utilities/socketxx
INCLUDEPATH += $$SRC_GROUP_DIR/Utilities/socketxx/socket++


#$$SRC_GROUP_DIR/Utilities \
#  $$SRC_GROUP_DIR/gdcm-common \

#  $$SRC_GROUP_DIR/gdcm-dsed \
#  $$SRC_GROUP_DIR/Testing/Source/Data \




HEADERS += \
  $$SRC_DIR/gdcmAAbortPDU.h \
  $$SRC_DIR/gdcmAAssociateACPDU.h \
  $$SRC_DIR/gdcmAAssociateRJPDU.h \
  $$SRC_DIR/gdcmAAssociateRQPDU.h \
  $$SRC_DIR/gdcmAbstractSyntax.h \
  $$SRC_DIR/gdcmApplicationContext.h \
  $$SRC_DIR/gdcmAReleaseRPPDU.h \
  $$SRC_DIR/gdcmAReleaseRQPDU.h \
  $$SRC_DIR/gdcmARTIMTimer.h \
  $$SRC_DIR/gdcmAsynchronousOperationsWindowSub.h \
  $$SRC_DIR/gdcmBaseCompositeMessage.h \
  $$SRC_DIR/gdcmBaseNormalizedMessage.h \
  $$SRC_DIR/gdcmBasePDU.h \
  $$SRC_DIR/gdcmBaseQuery.h \
  $$SRC_DIR/gdcmBaseRootQuery.h \
  $$SRC_DIR/gdcmCEchoMessages.h \
  $$SRC_DIR/gdcmCFindMessages.h \
  $$SRC_DIR/gdcmCMoveMessages.h \
  $$SRC_DIR/gdcmCommandDataSet.h \
  $$SRC_DIR/gdcmCompositeMessageFactory.h \
  $$SRC_DIR/gdcmCompositeNetworkFunctions.h \
  $$SRC_DIR/gdcmCStoreMessages.h \
  $$SRC_DIR/gdcmDIMSE.h \
  $$SRC_DIR/gdcmFindPatientRootQuery.h \
  $$SRC_DIR/gdcmFindStudyRootQuery.h \
  $$SRC_DIR/gdcmImplementationClassUIDSub.h \
  $$SRC_DIR/gdcmImplementationUIDSub.h \
  $$SRC_DIR/gdcmImplementationVersionNameSub.h \
  $$SRC_DIR/gdcmMaximumLengthSub.h \
  $$SRC_DIR/gdcmModalityPerformedProcedureStepCreateQuery.h \
  $$SRC_DIR/gdcmModalityPerformedProcedureStepSetQuery.h \
  $$SRC_DIR/gdcmMovePatientRootQuery.h \
  $$SRC_DIR/gdcmMoveStudyRootQuery.h \
  $$SRC_DIR/gdcmNActionMessages.h \
  $$SRC_DIR/gdcmNCreateMessages.h \
  $$SRC_DIR/gdcmNDeleteMessages.h \
  $$SRC_DIR/gdcmNetworkEvents.h \
  $$SRC_DIR/gdcmNetworkStateID.h \
  $$SRC_DIR/gdcmNEventReportMessages.h \
  $$SRC_DIR/gdcmNGetMessages.h \
  $$SRC_DIR/gdcmNormalizedMessageFactory.h \
  $$SRC_DIR/gdcmNormalizedNetworkFunctions.h \
  $$SRC_DIR/gdcmNSetMessages.h \
  $$SRC_DIR/gdcmPDataTFPDU.h \
  $$SRC_DIR/gdcmPDUFactory.h \
  $$SRC_DIR/gdcmPresentationContext.h \
  $$SRC_DIR/gdcmPresentationContextAC.h \
  $$SRC_DIR/gdcmPresentationContextGenerator.h \
  $$SRC_DIR/gdcmPresentationContextRQ.h \
  $$SRC_DIR/gdcmPresentationDataValue.h \
  $$SRC_DIR/gdcmQueryBase.h \
  $$SRC_DIR/gdcmQueryFactory.h \
  $$SRC_DIR/gdcmQueryImage.h \
  $$SRC_DIR/gdcmQueryPatient.h \
  $$SRC_DIR/gdcmQuerySeries.h \
  $$SRC_DIR/gdcmQueryStudy.h \
  $$SRC_DIR/gdcmRoleSelectionSub.h \
  $$SRC_DIR/gdcmServiceClassApplicationInformation.h \
  $$SRC_DIR/gdcmServiceClassUser.h \
  $$SRC_DIR/gdcmSOPClassExtendedNegociationSub.h \
  $$SRC_DIR/gdcmTransferSyntaxSub.h \
  $$SRC_DIR/gdcmULAction.h \
  $$SRC_DIR/gdcmULActionAA.h \
  $$SRC_DIR/gdcmULActionAE.h \
  $$SRC_DIR/gdcmULActionAR.h \
  $$SRC_DIR/gdcmULActionDT.h \
  $$SRC_DIR/gdcmULBasicCallback.h \
  $$SRC_DIR/gdcmULConnection.h \
  $$SRC_DIR/gdcmULConnectionCallback.h \
  $$SRC_DIR/gdcmULConnectionInfo.h \
  $$SRC_DIR/gdcmULConnectionManager.h \
  $$SRC_DIR/gdcmULEvent.h \
  $$SRC_DIR/gdcmULTransitionTable.h \
  $$SRC_DIR/gdcmULWritingCallback.h \
  $$SRC_DIR/gdcmUserInformation.h \
  $$SRC_DIR/gdcmWLMFindQuery.h \


SOURCES += \
  $$SRC_DIR/gdcmAAbortPDU.cxx \
  $$SRC_DIR/gdcmAAssociateACPDU.cxx \
  $$SRC_DIR/gdcmAAssociateRJPDU.cxx \
  $$SRC_DIR/gdcmAAssociateRQPDU.cxx \
  $$SRC_DIR/gdcmAbstractSyntax.cxx \
  $$SRC_DIR/gdcmApplicationContext.cxx \
  $$SRC_DIR/gdcmAReleaseRPPDU.cxx \
  $$SRC_DIR/gdcmAReleaseRQPDU.cxx \
  $$SRC_DIR/gdcmARTIMTimer.cxx \
  $$SRC_DIR/gdcmAsynchronousOperationsWindowSub.cxx \
  $$SRC_DIR/gdcmBaseQuery.cxx \
  $$SRC_DIR/gdcmBaseRootQuery.cxx \
  $$SRC_DIR/gdcmCEchoMessages.cxx \
  $$SRC_DIR/gdcmCFindMessages.cxx \
  $$SRC_DIR/gdcmCMoveMessages.cxx \
  $$SRC_DIR/gdcmCommandDataSet.cxx \
  $$SRC_DIR/gdcmCompositeMessageFactory.cxx \
  $$SRC_DIR/gdcmCompositeNetworkFunctions.cxx \
  $$SRC_DIR/gdcmCStoreMessages.cxx \
  $$SRC_DIR/gdcmFindPatientRootQuery.cxx \
  $$SRC_DIR/gdcmFindStudyRootQuery.cxx \
  $$SRC_DIR/gdcmImplementationClassUIDSub.cxx \
  $$SRC_DIR/gdcmImplementationUIDSub.cxx \
  $$SRC_DIR/gdcmImplementationVersionNameSub.cxx \
  $$SRC_DIR/gdcmMaximumLengthSub.cxx \
  $$SRC_DIR/gdcmModalityPerformedProcedureStepCreateQuery.cxx \
  $$SRC_DIR/gdcmModalityPerformedProcedureStepSetQuery.cxx \
  $$SRC_DIR/gdcmMovePatientRootQuery.cxx \
  $$SRC_DIR/gdcmMoveStudyRootQuery.cxx \
  $$SRC_DIR/gdcmNActionMessages.cxx \
  $$SRC_DIR/gdcmNCreateMessages.cxx \
  $$SRC_DIR/gdcmNDeleteMessages.cxx \
  $$SRC_DIR/gdcmNEventReportMessages.cxx \
  $$SRC_DIR/gdcmNGetMessages.cxx \
  $$SRC_DIR/gdcmNormalizedMessageFactory.cxx \
  $$SRC_DIR/gdcmNormalizedNetworkFunctions.cxx \
  $$SRC_DIR/gdcmNSetMessages.cxx \
  $$SRC_DIR/gdcmPDataTFPDU.cxx \
  $$SRC_DIR/gdcmPDUFactory.cxx \
  $$SRC_DIR/gdcmPresentationContext.cxx \
  $$SRC_DIR/gdcmPresentationContextAC.cxx \
  $$SRC_DIR/gdcmPresentationContextGenerator.cxx \
  $$SRC_DIR/gdcmPresentationContextRQ.cxx \
  $$SRC_DIR/gdcmPresentationDataValue.cxx \
  $$SRC_DIR/gdcmQueryBase.cxx \
  $$SRC_DIR/gdcmQueryFactory.cxx \
  $$SRC_DIR/gdcmQueryImage.cxx \
  $$SRC_DIR/gdcmQueryPatient.cxx \
  $$SRC_DIR/gdcmQuerySeries.cxx \
  $$SRC_DIR/gdcmQueryStudy.cxx \
  $$SRC_DIR/gdcmRoleSelectionSub.cxx \
  $$SRC_DIR/gdcmServiceClassApplicationInformation.cxx \
  $$SRC_DIR/gdcmServiceClassUser.cxx \
  $$SRC_DIR/gdcmSOPClassExtendedNegociationSub.cxx \
  $$SRC_DIR/gdcmTransferSyntaxSub.cxx \
  $$SRC_DIR/gdcmULActionAA.cxx \
  $$SRC_DIR/gdcmULActionAE.cxx \
  $$SRC_DIR/gdcmULActionAR.cxx \
  $$SRC_DIR/gdcmULActionDT.cxx \
  $$SRC_DIR/gdcmULBasicCallback.cxx \
  $$SRC_DIR/gdcmULConnection.cxx \
  $$SRC_DIR/gdcmULConnectionInfo.cxx \
  $$SRC_DIR/gdcmULConnectionManager.cxx \
  $$SRC_DIR/gdcmULTransitionTable.cxx \
  $$SRC_DIR/gdcmULWritingCallback.cxx \
  $$SRC_DIR/gdcmUserInformation.cxx \
  $$SRC_DIR/gdcmWLMFindQuery.cxx \



