#include "pluginmanager.h"
#include <QObject>
#include <qapplication.h>
#include <QPluginLoader>
#include <QDebug>
#include <vcg/complex/algorithms/create/platonic.h>

#include "mlexception.h"

static QStringList fileNamePluginDLLs() {
	QStringList l;
#if defined(Q_OS_WIN)
	l.push_back("*.dll");
	return l;
#elif defined(Q_OS_MAC)
	l.push_back("*.dylib");
	l.push_back("*.so");
	return l;
#else //linux
	l.push_back("*.so");
	return l;
#endif
}

static QString fileNamePrefixPluginDLLs() {
#if defined(Q_OS_WIN)
	return QString("");
#else //macos and linux
	return QString("lib");
#endif
}

PluginManager::PluginManager()
{
	//pluginsDir=QDir(getPluginDirPath());
	// without adding the correct library path in the mac the loading of jpg (done via qt plugins) fails
	//qApp->addLibraryPath(getPluginDirPath());
	//qApp->addLibraryPath(getBaseDirPath());
}

PluginManager::~PluginManager()
{
	meshIOPlug.clear();
	meshFilterPlug.clear();
	meshRenderPlug.clear();
	meshDecoratePlug.clear();
	for (PluginInterface* plugin : ownerPlug)
		delete plugin;
	ownerPlug.clear();
	
	for (int ii = 0; ii < meshEditInterfacePlug.size(); ++ii)
		delete meshEditInterfacePlug[ii];
	meshEditInterfacePlug.clear();
}



void PluginManager::loadPlugins(RichParameterList& defaultGlobal)
{
	loadPlugins(defaultGlobal, QDir(getDefaultPluginDirPath()));
}

void PluginManager::loadPlugins(RichParameterList& defaultGlobal, const QDir& pluginsDirectory)
{
	pluginsDir = pluginsDirectory;
	// without adding the correct library path in the mac the loading of jpg (done via qt plugins) fails
	qApp->addLibraryPath(getDefaultPluginDirPath());
	qApp->addLibraryPath(getBaseDirPath());
	QStringList nameFiltersPlugins = fileNamePluginDLLs();
	
	//only the file with extension pluginfilters will be listed by function entryList()
	pluginsDir.setNameFilters(nameFiltersPlugins);
	
	qDebug("Current Plugins Dir is: %s ", qUtf8Printable(pluginsDir.absolutePath()));
	for(QString fileName : pluginsDir.entryList(QDir::Files))
	{
		//      qDebug() << fileName;
		QString absfilepath = pluginsDir.absoluteFilePath(fileName);
		QFileInfo fin(absfilepath);
		QPluginLoader loader(absfilepath);
		QObject *plugin = loader.instance();
		if (plugin)
		{
			pluginsLoaded.push_back(fileName);
			PluginInterface *iCommon = nullptr;
			FilterPluginInterface *iFilter = qobject_cast<FilterPluginInterface *>(plugin);
			if (iFilter)
			{
				iCommon = iFilter;
				meshFilterPlug.push_back(iFilter);
				for(QAction *filterAction : iFilter->actions())
				{
					filterAction->setData(QVariant(fileName));
					actionFilterMap.insert(filterAction->text(), filterAction);
					stringFilterMap.insert(filterAction->text(), iFilter);
					if(iFilter->getClass(filterAction)==FilterPluginInterface::Generic)
						throw MLException("Missing class for "        +fileName+filterAction->text());
					if(iFilter->getRequirements(filterAction) == int(MeshModel::MM_UNKNOWN))
						throw MLException("Missing requirements for " +fileName+filterAction->text());
					if(iFilter->getPreConditions(filterAction) == int(MeshModel::MM_UNKNOWN))
						throw MLException("Missing preconditions for "+fileName+filterAction->text());
					if(iFilter->postCondition(filterAction) == int(MeshModel::MM_UNKNOWN ))
						throw MLException("Missing postcondition for "+fileName+filterAction->text());
					if(iFilter->filterArity(filterAction) == FilterPluginInterface::UNKNOWN_ARITY )
						throw MLException("Missing Arity for "        +fileName+filterAction->text());
				}
			}
			IOPluginInterface *iIO = qobject_cast<IOPluginInterface *>(plugin);
			if (iIO)
			{
				iCommon = iIO;
				meshIOPlug.push_back(iIO);
			}
			
			DecoratePluginInterface *iDecorator = qobject_cast<DecoratePluginInterface *>(plugin);
			if (iDecorator)
			{
				iCommon = iDecorator;
				meshDecoratePlug.push_back(iDecorator);
				foreach(QAction *decoratorAction, iDecorator->actions())
				{
					decoratorActionList.push_back(decoratorAction);
					iDecorator->initGlobalParameterList(decoratorAction, defaultGlobal);
				}
			}
			
			RenderPluginInterface *iRender = qobject_cast<RenderPluginInterface *>(plugin);
			if (iRender)
			{
				iCommon = iRender;
				meshRenderPlug.push_back(iRender);
			}
			
			EditPluginInterfaceFactory *iEditFactory = qobject_cast<EditPluginInterfaceFactory *>(plugin);
			if (iEditFactory)
			{
				meshEditInterfacePlug.push_back(iEditFactory);
				foreach(QAction* editAction, iEditFactory->actions())
					editActionList.push_back(editAction);
			}
			else if (iCommon)
			{
				ownerPlug.push_back(iCommon);
			} else {
				// qDebug("Plugin %s was loaded, but could not be casted to any known type.", qUtf8Printable(fileName));
			}
		}
		else
			qDebug() << loader.errorString();
	}
	knownIOFormats();
}

int PluginManager::numberIOPlugins() const
{
	return meshIOPlug.size();
}

// Search among all the decorator plugins the one that contains a decoration with the given name
DecoratePluginInterface *PluginManager::getDecoratorInterfaceByName(const QString& name)
{
	foreach(DecoratePluginInterface *tt, this->meshDecoratePlugins())
	{
		foreach( QAction *ac, tt->actions())
			if( name == tt->decorationName(ac) ) return tt;
	}
	assert(0);
	return 0;
}

/*
This function create a map from filtername to dummy RichParameterSet.
containing for each filtername the set of parameter that it uses.
*/
QMap<QString, RichParameterList> PluginManager::generateFilterParameterMap()
{
	QMap<QString, RichParameterList> FPM;
	MeshDocument md;
	MeshModel* mm = md.addNewMesh("", "dummy", true);
	vcg::tri::Tetrahedron<CMeshO>(mm->cm);
	mm->updateDataMask(MeshModel::MM_ALL);
	QMap<QString, QAction*>::iterator ai;
	for (ai = this->actionFilterMap.begin(); ai != this->actionFilterMap.end(); ++ai)
	{
		QString filterName = ai.key();//  ->filterName();
		//QAction act(filterName,NULL);
		RichParameterList rp;
		stringFilterMap[filterName]->initParameterList(ai.value(), md, rp);
		FPM[filterName] = rp;
	}
	return FPM;
}

QString PluginManager::getBaseDirPath()
{
	QDir baseDir(qApp->applicationDirPath());
	
#if defined(Q_OS_WIN)
	// Windows:
	// during development with visual studio binary could be in the debug/release subdir.
	// once deployed plugins dir is in the application directory, so
	if (baseDir.dirName() == "debug" || baseDir.dirName() == "release")		baseDir.cdUp(); 
#endif
	
#if defined(Q_OS_MAC)
	// Mac: during developmentwith xcode  and well deployed the binary is well buried.
	for(int i=0;i<6;++i){
		if(baseDir.exists("plugins")) break;
		baseDir.cdUp();
	}
	qDebug("The base dir is %s", qUtf8Printable(baseDir.absolutePath()));
#endif
	return baseDir.absolutePath();
}

QString PluginManager::getDefaultPluginDirPath()
{
	QDir pluginsDir(getBaseDirPath());
#if defined(Q_OS_WIN)
	QString d = pluginsDir.dirName();
	QString dLower = d.toLower();
	if (dLower == "release" || dLower == "relwithdebinfo" || dLower == "debug" ||
			dLower == "minsizerel") {
		// This is a configuration directory for MS Visual Studio.
		pluginsDir.cdUp();
	} else {
		d.clear();
	}
#endif
	if (pluginsDir.exists("plugins")) {
		pluginsDir.cd("plugins");
		
#if defined(Q_OS_WIN)
		// Re-apply the configuration dir, if any.
		if (!d.isEmpty() && pluginsDir.exists(d)) {
			pluginsDir.cd(d);
		}
#endif
		
		return pluginsDir.absolutePath();
	}
#if !defined(Q_OS_MAC) && !defined(Q_OS_WIN)
	else if (pluginsDir.dirName() == "bin") {
		pluginsDir.cdUp();
		pluginsDir.cd("lib");
		pluginsDir.cd("meshlab");
		if (pluginsDir.exists("plugins")) {
			pluginsDir.cd("plugins");
			return pluginsDir.absolutePath();
		}
	}
#endif
	//QMessageBox::warning(0,"Meshlab Initialization","Serious error. Unable to find the plugins directory.");
	qDebug("Meshlab Initialization: Serious error. Unable to find the plugins directory.");
	return {};
}



void PluginManager::knownIOFormats()
{
	for (int inpOut = 0; inpOut < 2; ++inpOut)
	{
		QStringList* formatFilters = NULL;
		QString allKnownFormatsFilter = QObject::tr("All known formats (");
		for (QVector<IOPluginInterface*>::iterator itIOPlugin = meshIOPlug.begin(); itIOPlugin != meshIOPlug.end(); ++itIOPlugin)
		{
			IOPluginInterface* pMeshIOPlugin = *itIOPlugin;
			QList<IOPluginInterface::Format> format;
			QMap<QString, IOPluginInterface*>* map = NULL;
			if (inpOut == int(IMPORT))
			{
				map = &allKnowInputFormats;
				formatFilters = &inpFilters;
				format = pMeshIOPlugin->importFormats();
			}
			else
			{
				map = &allKnowOutputFormats;
				formatFilters = &outFilters;
				format = pMeshIOPlugin->exportFormats();
			}
			for (QList<IOPluginInterface::Format>::iterator itf = format.begin(); itf != format.end(); ++itf)
			{
				IOPluginInterface::Format currentFormat = *itf;
				
				QString currentFilterEntry = currentFormat.description + " (";
				
				//a particular file format could be associated with more than one file extension
				QStringListIterator itExtension(currentFormat.extensions);
				while (itExtension.hasNext())
				{
					QString currentExtension = itExtension.next().toLower();
					if (!map->contains(currentExtension))
					{
						map->insert(currentExtension, pMeshIOPlugin);
						allKnownFormatsFilter.append(QObject::tr(" *."));
						allKnownFormatsFilter.append(currentExtension);
					}
					currentFilterEntry.append(QObject::tr(" *."));
					currentFilterEntry.append(currentExtension);
				}
				currentFilterEntry.append(')');
				formatFilters->append(currentFilterEntry);
			}
			
		}
		allKnownFormatsFilter.append(')');
		if (formatFilters != NULL)
			formatFilters->push_front(allKnownFormatsFilter);
	}
}

QString PluginManager::osIndependentPluginName(const QString& plname)
{
	QFileInfo fi(plname);
	QString res = fi.baseName();
	QString pref = fileNamePrefixPluginDLLs();
	return res.remove(0, pref.size());
}

