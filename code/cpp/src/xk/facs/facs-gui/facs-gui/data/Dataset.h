
// // license___here_h

#ifndef Dataset__H
#define Dataset__H

// package facsanadu.data;


#include <QList>
#include <QMap>

// // One data block - an FCS file can contain multiple but the standard encourages against

// //  Note: should separate this from FCS parsing!

class ChannelInfo;
class LengthProfile;

class LengthProfileData;
class FacsanaduProject;
class ProfChannel;

class QVector_Matrix_R8;


class Dataset
{
 int numChannel_; // =0;
 int numPc_; //=0;

 QVector_Matrix_R8* eventsFloat_;

 QVector_Matrix_R8* eventsFloatCompensated_;

 QVector<QPair<double, double>> extrema_;

 QVector_Matrix_R8* test_compensation_matrix_;

  //QList<QList<double>> eventsFloat_; //=new ArrayList<double[]>();

// QList<QList<double>> eventsFloatCompensated_; //=new ArrayList<double[]>();

 int numCompensated_; // = 0;

 QList<ChannelInfo*> channelInfo_; // =new ArrayList<ChannelInfo>();
 QFile source_;
 
 QList<LengthProfile*> lengthprofsInfo_; //=new ArrayList<LengthProfile>();
 QList<LengthProfileData*> lengthprofsData_; //=new ArrayList<LengthProfileData>();

 QMap<QString, QString> metaKeyName_; //=new TreeMap<String, String>();

 void do_preliminary_compensation();

public:

 Dataset(QVector_Matrix_R8* eventsFloat = nullptr);
 
 QList<ChannelInfo*> getChannelInfo();

 QVector<QPair<double, double>>& extrema()
 {
  return extrema_;
 }
 
 int getNumObservations();

 int getNumChannels();

 int getNumLengthProfiles();

 QString getName();

 QString get_file_source_name();

 double getAsFloatCompensated(int obs, int indexChan);

 QVector<double> getAsFloatCompensated(int obs);
 
 // // Compute profile channels. or only one if not null
 void computeProfChannel(FacsanaduProject* proj, ProfChannel* forPc);

 ChannelInfo* getChannelInfoForProf(ProfChannel* pc);

//? void setEvents(QList<QList<double>> e);

 void setEvents(QVector_Matrix_R8* e);

 // // Resize the events. Used to make space for virtual channels
 void resizeEvents(int newsize);
};

#endif // Dataset__H

