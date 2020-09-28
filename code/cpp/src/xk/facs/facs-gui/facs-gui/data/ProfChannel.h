

// // license___here_h

#ifndef ProfChannel__H
#define ProfChannel__H

// package facsanadu.data;

class LengthProfileData;

// // One profile channel
class ProfChannel
{
 int channel_;
 int from_; // =50;
 int to_; // =100;

 bool forNormalized_; //=true;
 //TODO boolean, on normalized or not?
 

public:

 QString getName();

 void set_channel(int channel) { channel_ = channel; }
 void set_forNormalized(bool b) { forNormalized_ = b; }


 double calc(LengthProfileData* data);

};


#endif // ProfChannel__H


