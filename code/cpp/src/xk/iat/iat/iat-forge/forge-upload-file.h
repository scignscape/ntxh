
#ifndef FORGE_UPLOAD_FILE__H
#define FORGE_UPLOAD_FILE__H

#include <QStringList>

#include "accessors.h"
#include "global-types.h"

class Forge_Upload_File
{
 QString local_path_;

 QString request_filename_;
 QString mime_type_;

public:

 Forge_Upload_File(QString local_path);

 ACCESSORS(QString ,local_path)
 ACCESSORS(QString ,request_filename)
 ACCESSORS(QString ,mime_type)
};

#endif // FORGE_UPLOAD_FILE__H
