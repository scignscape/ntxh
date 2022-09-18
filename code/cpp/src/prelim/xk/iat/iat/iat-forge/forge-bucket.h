
#ifndef FORGE_BUCKET__H
#define FORGE_BUCKET__H

#include <QStringList>

#include <QDateTime>

#include "accessors.h"
#include "global-types.h"

class Forge_Bucket
{
 enum class Access_Level
 {
  Full,
  Read
 };

 struct BucketPermissions
 {
  QString authentication_id;
  Access_Level access_level;

  QString get_access() const
  {
   static QStringList permission_categories { "full", "read" };
   return permission_categories.at((int) access_level);
  }
 };

 enum class Policy_Options {
   Transient,
   Temporary,
   Persistent
 };

 QString bucket_key_;
 QString owner_;
 n8 created_date_;
 QList<BucketPermissions> permissions_;
 Policy_Options policy_;

public:

 Forge_Bucket(QString bucket_key = "",
     QString owner = "",
     n8 created_date = 0,
     Policy_Options policy = Policy_Options::Transient);

 ACCESSORS(QString ,bucket_key)
 ACCESSORS(QString ,owner)
 ACCESSORS(n8 ,created_date)
 ACCESSORS__RGET(QList<BucketPermissions> ,permissions)
 ACCESSORS(Policy_Options ,policy)

 QString get_policy_key() const
 {
  static QStringList static_list { "transient",
     "temporary", "persistent" };
  return static_list.value((u1) policy_);
 }

 QDateTime created_datetime()
 {
  return QDateTime::fromMSecsSinceEpoch(created_date_);
 }

};




#ifdef HIDE
namespace Forge {

static QStringList policy_categories = {
		"transient",
		"temporary",
		"persistent",
	};

enum class POLICY {
	TRANSIENT,
	TEMPORARY,
	PERSISTENT
};


static QStringList permission_categories = {
	"full",
	"read"
};

enum class ACCESS
{
	FULL,
	READ
};

struct BucketPermissions
{
	QString authId;
	ACCESS access;

	QString get_auth_id() const
	{
		return authId;
	}

	QString get_access() const
	{
		return permission_categories.at(static_cast<int>(access));
	}





};




}

#endif // HIDE

#endif // FORGE_BUCKET__H
