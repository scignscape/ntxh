
// // license___here_h


#ifndef ColorSet__H
#define ColorSet__H


#include <QList>
#include <QSet>


// package facsanadu.gui.colors;

class GateColor;


// // Set of colors
class ColorSet
{
 QList<GateColor*> colors_; //= new LinkedList<GateColor>();
 
 
/*
 static
  {
  try
   {
   colorset.parseStandardColors();
   }
  catch (IOException e)
   {
   e.printStackTrace();
   }
  }
*/
 
 void parseStandardColors(); // throws IOException;

public:

 ColorSet();

 static ColorSet* colorset; //= new ColorSet();

 GateColor* get(int curcol);

 int size();

 GateColor* getRandomColor();

 GateColor* getUnusedColor(QSet<GateColor*> colset);

};

#endif // __H
 

