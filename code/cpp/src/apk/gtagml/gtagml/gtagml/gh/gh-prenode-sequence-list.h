
// licence_h

#ifndef GH_PRENODE_SEQUENCE_LIST__H
#define GH_PRENODE_SEQUENCE_LIST__H


#include <QList>
#include <QPair>
#include <QString>


class GH_Prenode_Sequence;

class GH_Prenode_Sequence_List : public QList<QPair<QString, GH_Prenode_Sequence*>>
{
public:

 GH_Prenode_Sequence_List();

 void add_prenode();


};


#endif // GH_PRENODE_SEQUENCE_LIST__H


