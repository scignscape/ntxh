
// // license___here_h

#include "ChannelInfo.h"

// // package facsanadu.data;

// // Information about one channel
ChannelInfo::ChannelInfo(QString label, QString name)
 :  label_(label), name_(name)
{
}

QString ChannelInfo::formatName()
{
 if( !name_.isEmpty() )
 {
  if( !label_.isEmpty() )
    return label_ + " - " + name_;
  else
    return name_;
 }
 else
   return label_;
}

QString ChannelInfo::getShortestName()
{
 if( !label_.isEmpty() )
   return label_;
 return name_;
} 


