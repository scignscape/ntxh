#ifndef paraview_server_manager_h
 #define paraview_server_manager_h
 
 #include "paraview_server_manager_data.h"
 #include <string>
 #include <vector>
 
 void paraview_server_manager_initialize(std::vector<std::string>& xmls)
 {
   (void)xmls;
   {
     char *init_string = paraview_server_managercore_sourcesGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerextraction_filtersGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managermisc_filtersGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managermisc_utilitiesGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerrendering_sourcesGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerfilters_filtersrenderingGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_manager3dwidgets_remotingviewsGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerextractors_remotingviewsGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerrenderingGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managersources_remotingviewsGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerutilities_remotingviewsGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerviews_and_representationsGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerrendering_remotingpythonGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerpointsGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerfilters_pv_iocoreGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerreaders_pv_iocoreGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerwriters_pv_iocoreGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerreaders_pv_iospcthGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerreaders_pv_ioimageGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerwriters_pv_ioimageGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerreaders_ioexodusGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerwriters_ioexodusGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerreaders_pv_ioensightGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerreaders_pv_ioamrGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerstatistics_filtersGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerpython_filtersGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerpython_miscGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerpython_sourcesGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managermaterial_interface_filtersGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managergeneral_mpi_filtersGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerproxies_conduitGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerCGNSWriterGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerCGNSReaderGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_manageranimationGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerwriters_animationGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_manageranimation_pythonGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_manageranimation_oggtheoraGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerutilities_settingsGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_manageramr_filtersGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managergeneral_filtersGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managergeneral_sourcesGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerextractorsGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerinternal_writersGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerutilitiesGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerproxies_computationalgeometryGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerfilters_domainschemistryGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerreaders_domainschemistryGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerfilters_filtersamrGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managersources_filtersamrGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerfilters_filterscoreGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managersources_filterscoreGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerfilters_filtersextractionGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerfilters_filtersflowpathsGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerfilters_filtersgeneralGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managersources_filtersgeneralGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerfilters_plotonintersectioncurvesGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerfilters_normalglyphsGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerfilters_filtersgenericGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerfilters_filtersgeometryGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerfilters_filtersparallelGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerfilters_filtersparallelmpiGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerfilters_filtershybridGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerreaders_filtershybridGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerfilters_filtershypertreeGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerfilters_filtersmodelingGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managersources_filterssourcesGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerfilters_filtersstatisticsGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerfilters_imagingcoreGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managersources_imagingcoreGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerfilters_imagingfourierGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerfilters_imaginggeneralGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerfilters_imaginghybridGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managersources_imagingsourcesGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerfilters_filtersparalleldiy2GetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerfilters_filtersparallelverdictGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerfilters_filterstextureGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerfilters_filtersverdictGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerreaders_ioxmlGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerwriters_ioxmlGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerreaders_ionetcdfGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerreaders_ioparallelnetcdfGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerproxies_xdmf2GetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerproxies_citygmlGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerproxies_segyGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerwriters_iolegacyGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerreaders_iogeometryGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerwriters_iogeometryGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerreaders_ioplyGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerreaders_ioparallelGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerwriters_ensightGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerreaders_lsdynaGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerreaders_ioinfovisGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerreaders_iotecplottableGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerreaders_iovpicGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerreaders_iotruchasGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerreaders_ioveraoutGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerreaders_ioh5partGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerreaders_iopioGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerreaders_ioconvergecfdGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managersources_renderingfreetypeGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerproxies_interactionwidgetsGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerfilters_selectionfftovertimeGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerreaders_openpmdGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managergeneral_readersGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managergeneral_writersGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managersources_remotingmiscGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerlive_utilitiesGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
   {
     char *init_string = paraview_server_managerexportersGetInterfaces();
     xmls.push_back(init_string);
     delete [] init_string;
   }
 }
 
 #endif
