#include <iostream>
 #include <cstring>
#include <ncurses.h>
#include <cstdlib>
#include <cstdio>
extern "C"
{
#include <stdarg.h>
}
#include "BioCoder.h"

using namespace std;
#define DEFAULT 25000000

//?FILE* fp;

//initiallization of flags
u4 print_reagents = 1;
u4 print_parameters = 1;
u4 first = 0;
u4 options_flag = 0;
u4 option_no = 1;
u4 sub_step_flag = 0;
u4 prev_cont = 1;

//initiallization of number of containers, equipment, etc.
u4 equip_no = 0;
u4 microfuge_no = 1;
u4 centrifuge_no = 1;
u4 incubator_no = 1;
u4 electrophoresis_no = 1;
u4 mortar_no = 1;
u4 thermocycler_no = 1;
u4 electro_no = 1;
u4 shaker_no = 1;
u4 spectrophotometer_no = 1;
u4 cont_no = 0;
u4 container_count[24] ={0};

QStringList containers;
QStringList equipments;
QString filename;
 
// // char* containers[20];
// // char* equipments[20];
// // char* filename;

//variables required for keeping track of usage of fluids and containers
// // Fluid usage_list_fluids[200];
// // Container usage_list_containers[100];

QList<Fluid> usage_list_fluids;
QList<Container> usage_list_containers;

u4 list_fluid_no = 0;
u4 list_container_no = 0;
//char* prev_container;

QString prev_container;


//variable required for keeping track of time required for completion of the protocol
u4 total_time_required = 0;

//operation typedef-ed to Fluid
typedef Fluid Operation;

Fluid new_operation(QString name) 
{
 Operation result ={0};
 result.new_name = name;
 result.original_name = name;
 result.type = OPERATION;
 return result;
}

//class Time
Time::Time(r4 x, time_unit unit)
{
 value = x; 
 unit_choice = unit;
}

void Time::display_time()
{
 r4 max_time_value = 0;
 switch(unit_choice)
 {
 case SECS:
  if (value == 1) unit = "sec"; 
  else unit = "secs";
  mul = 1;
  break;
 case MINS:
  if (value == 1) 
   unit = "min"; 
  else unit = "mins";
  mul = 60;
  break;
 case HRS:
  if (value == 1) 
   unit = "hr"; 
  else 
   unit = "hrs";
  mul = 3600;
  break;
 default:
  break;
 }
 if ((value == OVERNIGHT) && (unit == "hrs"))
   qts_write( "<b><font color=#357EC7>12 hrs</font></b>(overnight)");
 else if (value == 0)
   qts_write("<b>immediately</b>");
 else if (value == FOREVER)
   qts_write("<b><font color=#357EC7>forever</font></b>(until taken out from the thermocycler)");
 else if (value == XVAL)
   qts_write("<b><font color=#357EC7>X</font></b>");
 else 
   qts_write( QString("<b><font color=#357EC7>%1 %2</font></b>").arg( value.arg( unit));
 if((option_no == 2) && (options_flag == 1))
   max_time_value = value * mul;
 else if(option_no > 2)
 {
  if(max_time_value > value*mul)
    total_time_required = total_time_required + max_time_value;
  else 
  {
   total_time_required = total_time_required + value * mul;
   max_time_value = value*mul;
  }
 }
 else 
   total_time_required = total_time_required + value * mul;
}

Minimum_time::Minimum_time (r4 x, time_unit unit)
{
 value = x; 
 unit_choice = unit;
}

void Minimum_time::display_time()
{
 r4 max_time_value = 0;

 switch(unit_choice)
 {
 case SECS:
  if (value == 1) 
    unit = "sec"; 
  else 
    unit = "secs";
  mul = 1;
  break;
 case MINS:
  if (value == 1)  
    unit = "min"; 
  else 
    unit = "mins";
  mul = 60;
  break;
 case HRS:
  if (value == 1) 
    unit = "hr"; 
  else 
    unit = "hrs";
  mul = 3600;
  break;
 default:
  break;
 }
 qts_write(QString("at least <b><font color=#357EC7>%1 %2</font></b>").arg( value, unit));

 if((option_no == 2) && (options_flag == 1))
   max_time_value = value * mul;
 else if(option_no > 2)
 {
  if(max_time_value > value*mul)
    total_time_required = total_time_required + max_time_value;
  else 
  {
   total_time_required = total_time_required + value * mul;
   max_time_value = value*mul;
  }
 }
 else 
   total_time_required = total_time_required + value * mul;
}

Maximum_time::Maximum_time(r4 x, time_unit unit)
{
 value = x; 
 unit_choice = unit;
}


void Maximum_time::display_time()
{ 
 r4 max_time_value = 0;
 switch(unit_choice)
 {
  case SECS:
   if (value == 1) 
     unit = "sec";
   else unit = "secs";
   mul = 1;
   break;
  case MINS:
   if (value == 1) 
     unit = "min"; 
   else unit = "mins";
   mul = 60;
   break;
  case HRS:
   if (value == 1) 
     unit = "hr"; 
   else unit = "hrs";
   mul = 3600;
   break;
  default:
   break;
 }
 qts_write(QString("at most <b><font color=#357EC7>%1 %2</font></b>").arg( value, unit));
 if((option_no == 2) && (options_flag == 1))
   max_time_value = value * mul;
 else if(option_no > 2)
 {
  if(max_time_value > value*mul)
    total_time_required = total_time_required + max_time_value;
  else 
  {
   total_time_required = total_time_required + value * mul;
   max_time_value = value*mul;
  }
 }
 else 
   total_time_required = total_time_required + value * mul;
}

Approx_time::Approx_time(r4 x, time_unit unit)
{
 value = x; 
 unit_choice = unit;
}


void Approx_time::display_time()
{ 
 r4 max_time_value = 0;
 switch(unit_choice)
 {
 case SECS:
  if (value == 1) 
    unit = "sec"; 
  else 
    unit = "secs";
  mul = 1;
  break;
 case MINS:
  if (value == 1) 
    unit = "min"; 
  else 
    unit = "mins";
  mul = 60;
  break;
 case HRS:
  if (value == 1) 
    unit = "hr"; 
  else unit = "hrs";
  mul = 3600;
  break;
 default:
  break;
 }
 qts_write(QString("~<b><font color=#357EC7>%1 %2</font></b>").arg( value, unit));
 if((option_no == 2) && (options_flag == 1))
   max_time_value = value * mul;
 else if(option_no > 2)
 {
  if(max_time_value > value*mul)
    total_time_required = total_time_required + max_time_value;
  else 
  {
   total_time_required = total_time_required + value * mul;
   max_time_value = value*mul;
  }
 }
 else 
   total_time_required = total_time_required + value * mul;
}

Time_range::Time_range(r4 x, r4 y, time_unit unit)
{
 value1 = x; 
 value = y; 
 unit_choice = unit;
}

void Time_range::display_time ()
{
 r4 max_time_value = 0;
 switch(unit_choice)
 {
 case SECS:
  if (value1 == 1)
    unit = "sec"; 
  else 
    unit = "secs";
  mul = 1;
  break;
 case MINS:
  if (value1 == 1) 
    unit = "min"; 
  else 
    unit = "mins";
  mul = 60;
  break;
 case HRS:
  if (value1 == 1) 
    unit = "hr"; 
  else 
    unit = "hrs";
  mul = 3600;
  break;
 default:
  break;
}
 if ((value1 == 12) && (unit == "hrs"))
   qts_write( QString("<b><font color=#357EC7>%1(overnight) - %2 %3</font></b>").arg( value1).arg(value).arg(unit));
 else if ((value == 12) && (unit == "hrs"))
   qts_write( QString("<b><font color=#357EC7>%1 - %2 %3(overnight)</font></b>").arg( value1).arg(value).arg(unit));
 else
   qts_write( QString("<b><font color=#357EC7>%1 - %2 %3</font></b>").arg( value1).arg(value).arg(unit));
 if((option_no == 2) && (options_flag == 1))
   max_time_value = value * mul;
 else if(option_no > 2)
{
  if(max_time_value > value*mul)
    total_time_required = total_time_required + max_time_value;
  else 
 {
   total_time_required = total_time_required + value * mul;
   max_time_value = value*mul;
 }
}
 else 
   total_time_required = total_time_required + value * mul;
}

Symbolic_time::Symbolic_time(Symbol_t& s) 
{
 s1.symbol = s.symbol; 
 s1.unit = s.unit; 
 s1.value = s.value; 
 value = s1.value;
}

void Symbolic_time:: display_time()
{
 Time* time1;
 if (s1.value == DEFAULT)
   qts_write(QString("<b><font color=#357EC7>%1 secs</font></b>").arg( s1.symbol)); 
 else 
 {
  time1 = time(s1.value, s1.unit);
  time1->display_time();
 }
}

//class Speed
Speed::Speed(r4 x,  speed_type unit)
{
 value = x; 
 unit_choice = unit;
}

void Speed::display_speed()
{ 
 switch(unit_choice)
{
  case RPM: unit = "rpm";break;
  case G: unit = "Xg";break;
  default:break;
}
 if (value == SPEED_MAX)
   qts_write( "<font color=#357EC7>maximum speed</font>");
 else
  qts_write( QString("a speed of <font color=#357EC7>%1 %2</font>").arg( value).arg(unit));
}

Minimum_speed::Minimum_speed (r4 x).arg(speed_type unit)
{
 value = x; 
 unit_choice = unit;
}

void Minimum_speed::display_speed()
{
 switch(unit_choice)
{
  case RPM: unit = "rpm";break;
  case G: unit = "Xg";break;
  default:break;
}
 qts_write(QString("a speed of at least <font color=#357EC7>%1 %2</font>").arg( value).arg(unit));
}

Maximum_speed::Maximum_speed(r4 x, speed_type unit)
{
 value = x; 
 unit_choice = unit;
}

void Maximum_speed::display_speed()
{
 switch(unit_choice)
{
  case RPM: unit = "rpm";break;
  case G: unit = "Xg";break;
  default:break;
}
 qts_write(QString("a speed of at most <font color=#357EC7>%1 %2</font>").arg( value).arg(unit)); 
}

Approx_speed::Approx_speed(r4 x, speed_type unit)
{
 value = x; 
 unit_choice = unit;
}


void Approx_speed::display_speed()
{
 switch(unit_choice)
{
  case RPM: unit = "rpm";break;
  case G: unit = "Xg";break;
  default:break;
}
 qts_write(QString("a speed of ~<font color=#357EC7>%1 %2</font>").arg( value).arg(unit)); 
}

Speed_range::Speed_range(r4 x, r4 y, speed_type unit)
{
 value1 = x; 
 value = y; 
 unit_choice = unit;
}

void Speed_range::display_speed ()
{
 switch(unit_choice)
{
  case RPM: unit = "rpm";break;
  case G: unit = "Xg";break;
  default:break;
}
 qts_write( QString("a speed of <font color=#357EC7>%1 - %2 %3</font>").arg( value1).arg(value).arg(unit));
}

//class Volume
Volume::Volume(r4 x,  vol_unit unit1)
{
 value = x; 
 unit_choice = unit1;
 switch(unit_choice)
{
  case UL: unit = "mcL";mul = MICRO;break;
  case ML: unit = "ml";mul = MILLI;break;
  case L: unit = "l";mul = LITRE;break;
  default : unit = "mcL";mul = MICRO;break;
 }
}
void Volume::display_vol() 
{
 qts_write(QString("<b><font color=#357EC7>%1 %2</font></b>").arg( value).arg(unit));
}

Symbolic_vol::Symbolic_vol(Symbol& s){s1.symbol = s.symbol; s1.unit = s.unit; s1.value = s.value; value = s1.value;}

void Symbolic_vol:: display_vol()
{
 Volume* vol1;
 if (s1.value == DEFAULT)
  qts_write(QString("<b><font color=#357EC7>%1 mcL</font></b>").arg( s1.symbol)); 
 else 
{
  vol1 = vol(s1.value, s1.unit);
  vol1->display_vol();
 }
}

Volume_range::Volume_range(r4 x, r4 y,  vol_unit unit1)
{
 value1 = x;
 value = y;
 unit_choice = unit1;
 switch(unit_choice){
 case UL: unit = "mcL";mul = MICRO;break;
 case ML: unit = "ml";mul = MILLI;break;  
 case L: unit = "l";mul = LITRE;break;
 default : unit = "mcL";mul = MICRO;break;
 }
}
void Volume_range:: display_vol()
{
 qts_write(QString("<b><font color=#357EC7>%1 - %2 %3</font></b>").arg( value1).arg(value).arg(unit));
}
Approx_volume::Approx_volume(r4 x,  vol_unit unit1)
{
 value = x; 
 unit_choice = unit1;
 switch(unit_choice){
 case UL: unit = "mcL";mul = MICRO;break;
 case ML: unit = "ml";mul = MILLI;break;
 case L: unit = "l";mul = LITRE;break;
 default : unit = "mcL";mul = MICRO;break;
 }
}
void Approx_volume::display_vol() 
{
 qts_write(QString("<b><font color=#357EC7>~%1 %2</font></b>").arg( value).arg(unit));
}

//functions used to call time, speed and volume
Time* time (r4 x,  time_unit unit)
{
 Time *temp = new Time(x, unit);
 return temp;
}
Time_range* time_range (r4 x, r4 y,  time_unit unit)
{
 Time_range *temp = new Time_range(x, y, unit);
 return temp;
}

Minimum_time* min_time(r4 x,  time_unit unit)
{
 Minimum_time *temp = new Minimum_time(x, unit);
 return temp;
}
Maximum_time* max_time(r4 x,  time_unit unit)
{
 Maximum_time *temp = new Maximum_time(x, unit);
 return temp;
}
Approx_time* approx_time(r4 x,  time_unit unit)
{
 Approx_time *temp = new Approx_time(x, unit);
 return temp;
}

Speed* speed (r4 x,  speed_type unit)
{
 Speed *temp = new Speed(x, unit);
 return temp;
}
Speed_range* speed_range(r4 x, r4 y,  speed_type unit)
{
 Speed_range *temp = new Speed_range(x, y, unit);
 return temp;
}

Minimum_speed* min_speed(r4 x,  speed_type unit)
{
 Minimum_speed *temp = new Minimum_speed(x, unit);
 return temp;
}
Maximum_speed* max_speed(r4 x,  speed_type unit)
{
 Maximum_speed *temp = new Maximum_speed(x, unit);
 return temp;
}
Approx_speed* approx_speed(r4 x,  speed_type unit)
{
 Approx_speed* temp = new Approx_speed(x, unit);
 return temp;
}

Volume* vol(r4 x,  vol_unit unit)
{
 Volume* result = new Volume(x, unit);
 return result;
}

Symbolic_vol* s_vol(Symbol s)
{
 Symbolic_vol* result = new Symbolic_vol(s);
 return result;
}

Symbolic_time* s_time(Symbol_t s)
{
 Symbolic_time* result = new Symbolic_time(s);
 return result;
}

Volume_range* vol_range(r4 x, r4 y,  vol_unit unit)
{
 Volume_range* result = new Volume_range(x, y, unit);
 return result;
}
Approx_volume* approx_vol(r4 x,  vol_unit unit)
{
 Approx_volume* result = new Approx_volume(x, unit);
 return result;
}

void start_protocol(char* name)
{
 filename = name;
 char* temp1 = "";
 temp1 = (char *)calloc(strlen(name)+ 10, sizeof(char));
 temp1 = strcat(temp1, name);
 temp1 = strcat(temp1, ".htm");
 fp = fopen(temp1, "w");
 qts_write(QString("<h1 style=\"font-size = 25px;\">%1</h1>").arg( name));
}

void first_step()
{
 first = 1;
 qts_write("</ul><h2>Steps:</h2><ol>");
 qts_write("<p><li>");
}

void first_step(char* step_name)
{
 first = 1;
 qts_write("</ul><h2>Steps:</h2><ol>");
 qts_write(QString("<p><li><b><font size=3>%1</font></b><br>").arg( step_name));
}

void next_step(char* step_name)
{
 first = 0;
 if (sub_step_flag == 1)
 {
  qts_write("</li></p></ol>");
  sub_step_flag = 0;
 }
 qts_write(QString("</li></p><p><li><b><font size=3>%1</font></b><br>").arg( step_name));
}

void next_step()
{
 first = 0;
 if (sub_step_flag == 1)
{
  qts_write("</li></p></ol>");
  sub_step_flag = 0;
 }
 qts_write("</li></p><p><li>");
}

void optional_step()
{
 first = 0;
 if (sub_step_flag == 1)
{
  qts_write("</li></p></ol>");
  sub_step_flag = 0;
 }
 qts_write("</li></p><p><b><font size=3>(Optional)</font></b><br>");
}

void optional_step(char* name)
{
 first = 0;
 if (sub_step_flag == 1)
{
  qts_write("</li></p></ol>");
  sub_step_flag = 0;
 }
 qts_write(QString("</li></p><p><b><font size=3>%1 (Optional)</font></b><br>").arg( name));
}

void parallel_step()
{
 first = 0;
 if (sub_step_flag == 1)
{
  qts_write("</li></p></ol>");
  sub_step_flag = 0;
 }
 qts_write("</li></p><p><li><b>Meanwhile:</b><br>");
}

void first_sub_step()
{
 first = 0;
 qts_write("<ol type=\"a\"><p><li>");
 sub_step_flag = 1;
}

void next_sub_step()
{
 qts_write("</li></p><p><li>");
 sub_step_flag = 1;
}

void repeat(u4 step_no)
{
 qts_write(QString("Repeat Step %1. <br>").arg( step_no));
}

void first_option()
{
 options_flag = 1;
 qts_write(QString("<p><b>Option %1: </b>").arg( option_no));
 option_no++;
}

void first_option(char* name)
{
 options_flag = 1;
 qts_write(QString("<p><b>Option %1: %2</b>").arg( option_no).arg(name));
 option_no++;
}

void next_option()
{
 options_flag = 1;
 if (sub_step_flag == 1)
 {
  qts_write("</li></p></ol>");
  sub_step_flag = 0;
 }
 qts_write(QString("(or)<br><b>Option %1: </b>").arg(option_no));
 option_no++;
}

void next_option(char* name)
{
 options_flag = 1;
 if (sub_step_flag == 1)
 {
  qts_write("</li></p></ol>");
  sub_step_flag = 0;
 }
 qts_write(QString("(or)<p><b>Option %1: %2</b>").arg(option_no).arg(name));
 option_no++;
}

void end_option()
{
 options_flag = 0;
 if (sub_step_flag == 1)
 {
  qts_write("</li></p></ol>");
  sub_step_flag = 0;
 }
 qts_write("</p><p>");
 option_no=1;
}

void display_equip()
{
 u4 i;
 qts_write("<div style=\"top: 25px; margin-top: 50px; margin-left: 700px; position: absolute; z-index: 1; visibility: show;\">");
 qts_write("<h2>Equipment:</h2><ul type=\"circle\">");
 for(i=0; i<equip_no; i++)
  qts_write(QString("<li>%1</li>").arg( equipments[i]));
 for(i=0; i<cont_no; i++)
  qts_write(QString("<li>%1</li>").arg( containers[i]));
 qts_write("</ul></div>");
}

void usage_details()
{
 u4 i;
 u4 count1 = 0;
 u4 count2 = 0;
 for(i=0;i<list_fluid_no;i++)
 {
  if (usage_list_fluids[i].used == 1)
   continue;
  if (count1 == 0)
  {
   qts_write("<font color = red>Warning: The following reagents/materials were declared but not used in the protocol:</font><ul>");
   qts_write(QString("<li>%1</li>").arg( usage_list_fluids[i].original_name));
   count1++;
  }
  else
   qts_write(QString("<li>%1</li>").arg( usage_list_fluids[i].original_name));
 }
 qts_write("</ul>");
 for(i=0;i<list_container_no;i++)
 {
  if (usage_list_containers[i].used == 1)
   continue;
  if (count2 == 0)
  {
   qts_write("<font color = red>Warning: The following equipment were declared but not used in the protocol:</font><ul>");
   qts_write(QString("<li>%1</li>").arg( usage_list_containers[i].name));
   count1++;
  }
  else
   qts_write(QString("<li>%1</li>").arg( usage_list_containers[i].name));
 }
 qts_write("</ul>");
}

void timing_details()
{
 u4 time_hrs = total_time_required/3600;
 u4 time_mins = (total_time_required%3600)/60;
 if (time_hrs == 0)
  qts_write(QString("<p><b>TOTAL TIME REQUIRED FOR THE COMPLETION OF THE PROTOCOL :<font color=#357EC7>~ %1 mins</font></b></p>").arg( time_mins));
 else if (time_hrs == 1)
  qts_write(QString("<p><b>TOTAL TIME REQUIRED FOR THE COMPLETION OF THE PROTOCOL :<font color=#357EC7>~ %1 hr, %2 mins</font></b></p>").arg( time_hrs).arg(time_mins));
 else
  qts_write(QString("<p><b>TOTAL TIME REQUIRED FOR THE COMPLETION OF THE PROTOCOL :<font color=#357EC7>~ %1 hrs, %2 mins</font></b></p>").arg( time_hrs).arg(time_mins));
 total_time_required = 0;
}

void end_protocol()
{
 u4 i;
 export_graph(filename);
 qts_write("</li></p></ol>");
 display_equip();
 usage_details();
 //timing_details();
 print_reagents = 1;
 print_parameters = 1;
 option_no = 1;
 equip_no = 0;
 microfuge_no = 1;
 centrifuge_no = 1;
 incubator_no = 1;
 electrophoresis_no = 1;
 mortar_no = 1;
 thermocycler_no = 1;
 electro_no = 1;
 shaker_no = 1;
 spectrophotometer_no = 1;
 cont_no = 0;
 prev_cont = 1;
 list_fluid_no = 0;
 total_time_required = 0;
 list_container_no = 0;
 fclose(fp);
}

void check_container(Container& container1)
{
 if ((first == 1) || (prev_cont == 1)||(prev_container != container1.name))
 {
  prev_container = container1.name;
  qts_write( //?"%s", 
    container1.name);
 }
}

void to_do(char* clarify)
{
 qts_write(QString("<font color = \"red\"><i>%1</i></font><br>").arg( clarify));
}

void comment(char* comm)
{
 qts_write(QString("<font color = \"#800517\"><i>%1</i></font><br>").arg( comm));
}

Fluid new_fluid(char *name)
{
 Fluid result ={0};
 result.state = "";
 result.original_name = name;
 result.new_name = name;
 result.type = FLUID;
 result.volume = DEFAULT;
 result.unit = L;
 if(print_reagents == 1)
 {
  qts_write("<h2 style=\"margin-top:50px;\">Solutions/reagents:</h2><ul type=\"circle\">");
  print_reagents++;
 }
 qts_write(QString("<li>%1</li>").arg( name));
 result.used = 0;
 usage_list_fluids[list_fluid_no] = result;
 result.usage_index = list_fluid_no;
 list_fluid_no++;
 return result;
}

Fluid new_fluid(char*name, r4 temp)
{ 
 char* t1="";
 Fluid result ={0};
 result.original_name = name;
 result.new_name = name;
 result.state="";
 result.type = FLUID;
 result.volume = DEFAULT;
 result.unit = L;
 if(print_reagents == 1)
 {
  qts_write("<h2 style=\"margin-top:50px;\">Solutions/reagents:</h2><ul type=\"circle\">");
  print_reagents++;
 }
 if(temp == ICE_COLD)
 {
  qts_write(QString("<li>ice-cold %1</li>").arg( name)); //?.arg(temp));
  t1 = (char *)calloc(strlen(t1) + strlen(name) + 10, sizeof(char));
  strcat(t1, "ice-cold ");
  strcat(t1, name);
  result.new_name = t1;
 }
 else if(temp == RT)
  qts_write(QString("<li>%1 stored at room temperature</li>").arg( name));
 else
  qts_write(QString("<li>%1 stored at %2%3C</li>").arg( name).arg(temp).arg(0x00B0));
 result.used = 0;
 usage_list_fluids[list_fluid_no] = result;
 result.usage_index = list_fluid_no;
 list_fluid_no++;
 return result;
}

Fluid new_fluid(char*name, char* state)
{
 char* t1 = "";
 Fluid result ={0};
 result.original_name = name;
 result.new_name = name;
 result.state= state;
 result.type = FLUID;
 result.volume = DEFAULT;
 result.unit = L;
 if(print_reagents == 1)
 {
  qts_write("<h2 style=\"margin-top:50px;\">Solutions/reagents:</h2><ul type=\"circle\">");
  print_reagents++;
 }
 qts_write(QString("<li> <a name=\"%1\">%2 <i><br><tab><div style=\"margin-right: 600px;\">(%3)</div></i></a></li>").arg( name).arg(name).arg(state));
 result.used = 0;
 usage_list_fluids[list_fluid_no] = result;
 result.usage_index = list_fluid_no;
 list_fluid_no++;
 return result;
}

Fluid new_fluid (char* name, char* state, r4 temp)
{
 char* t1="";
 Fluid result ={0};
 result.original_name = name;
 result.new_name = name;
 result.state= state;
 result.type = FLUID;
 result.volume = DEFAULT;
 result.unit = L;
 if(print_reagents == 1)
 {
  qts_write("<h2 style=\"margin-top:50px;\">Solutions/reagents:</h2><ul type=\"circle\">");
  print_reagents++;
 }
 if(temp == ICE_COLD)
 {
  t1 = (char *)calloc(strlen(t1) + strlen(name) + 10, sizeof(char));
  strcat(t1, "ice-cold ");
  strcat(t1, name);
  result.new_name = t1;
  qts_write(QString("<li> <a name=\"%1\"> %2 <i><br><tab><div style=\"margin-right: 600px;\">(%3)</div></i></a></li>").arg( result.new_name).arg(result.new_name).arg(state));
 }
 else if(temp >= 35)
   qts_write(QString("<li> <a name=\"%1\">%2 preheated in a water bath set at <b><font color=#357EC7>%3%4C</font></b> <i>%5</i></a></li>").arg( name).arg(name).arg(temp).arg(0x00B0).arg(state));
 else
   qts_write(QString("<li> <a name=\"%1\">%2 <i>%3</i> </a> at <b><font color=#357EC7>%4%5C</font></b></li>").arg( name).arg(name).arg(state).arg(temp).arg(0x00B0));
 result.used = 0;
 usage_list_fluids[list_fluid_no] = result;
 result.usage_index = list_fluid_no;
 list_fluid_no++;
 return result;
}

Fluid new_fluid(char *name, Volume* volume1)
{
 char* t1 = "";
 char* t2 = "";
 Fluid result ={0};
 result.state = "";
 result.type = FLUID;
 result.unit = vol_unit(volume1->unit_choice);
 result.volume = volume1->value * volume1->mul;
 result.original_name = name;
 result.new_name = name;
 if(print_reagents == 1)
 {
  qts_write("<h2 style=\"margin-top:50px;\">Solutions/reagents:</h2><ul type=\"circle\">");
  print_reagents++;
 }
 qts_write(QString("<li>%1</li>").arg( name));
 result.used = 0;
 usage_list_fluids[list_fluid_no] = result;
 result.usage_index = list_fluid_no;
 list_fluid_no++;
 return result;
}

Fluid new_fluid(char*name, r4 temp, Volume* volume1)
{ 
 char* t1 = "";
 char* t2 = "";
 Fluid result ={0};
 result.state="";
 result.type = FLUID;
 result.original_name = name;
 result.new_name = name;
 result.volume = volume1->value * volume1->mul;
 result.unit = vol_unit(volume1->unit_choice);
 if(print_reagents == 1)
 {
  qts_write("<h2 style=\"margin-top:50px;\">Solutions/reagents:</h2><ul type=\"circle\">");
  print_reagents++;
 }
 if(temp == ICE_COLD)
 {
  qts_write(QString("<li>ice-cold %1</li>").arg( name)); //.arg(temp)); //?
  t1 = (char *)calloc(strlen(t1) + strlen(name) + 10, sizeof(char));
  strcat(t1, "ice-cold ");
  strcat(t1, name);
  result.new_name = t1;
 }
 else if(temp == RT)
  qts_write(QString("<li>%1 stored at room temperature</li>").arg( name));
 else
  qts_write(QString("<li>%1 stored at %2%3C</li>").arg( name).arg(temp).arg(0x00B0));
 result.used = 0;
 usage_list_fluids[list_fluid_no] = result;
 result.usage_index = list_fluid_no;
 list_fluid_no++;
 return result;
}

Fluid new_fluid(char*name, char* state, Volume* volume1)
{
 char* t1 = "";
 char* t2 = "";
 Fluid result ={0};
 result.state= state;
 result.original_name = name;
 result.new_name = name;
 result.type = FLUID;
 result.volume = volume1->value * volume1->mul;
 result.unit = vol_unit(volume1->unit_choice);
 if(print_reagents == 1)
 {
  qts_write("<h2 style=\"margin-top:50px;\">Solutions/reagents:</h2><ul type=\"circle\">");
  print_reagents++;
 }
 qts_write(QString("<li> <a name=\"%1\">%2 <i><br><tab><div style=\"margin-right: 600px;\">(%3)</div></i></a></li>").arg( name).arg(name).arg(state));
 result.used = 0;
 usage_list_fluids[list_fluid_no] = result;
 result.usage_index = list_fluid_no;
 list_fluid_no++;
 return result;
}

Fluid new_fluid (char* name, char* state, r4 temp, Volume* volume1)
{
 char* t1 = "";
 char* t2 = "";
 Fluid result ={0};
 result.state= state;
 result.original_name = name;
 result.new_name = name;
 result.type = FLUID;
 result.volume = volume1->value * volume1->mul;
 result.unit = vol_unit(volume1->unit_choice);
 if(print_reagents == 1)
 {
  qts_write("<h2 style=\"margin-top:50px;\">Solutions/reagents:</h2><ul type=\"circle\">");
  print_reagents++;
 }
 if(temp == ICE_COLD)
 {
  t1 = (char *)calloc(strlen(t1) + strlen(name) + 10, sizeof(char));
  strcat(t1, "ice-cold ");
  strcat(t1, name);
  result.new_name = t1;
  qts_write(QString("<li> <a name=\"%1\"> %2 <i><br><tab><div style=\"margin-right: 600px;\">(%3)</div></i></a></li>").arg( result.new_name).arg(result.new_name).arg(state));
 }
 else if(temp >= 35)
   qts_write(QString("<li> <a name=\"%1\">%2 preheated in a water bath set at <b><font color=#357EC7>%3%4C</font></b> <i>%5</i></a></li>").arg( name).arg(name).arg(temp).arg(0x00B0).arg(state));
 else
   qts_write(QString("<li> <a name=\"%1\">%2 <i>%3</i> </a> at <b><font color=#357EC7>%4%5C</font></b></li>").arg( name).arg(name).arg(state).arg(temp).arg(0x00B0));
 result.used = 0;
 usage_list_fluids[list_fluid_no] = result;
 result.usage_index = list_fluid_no;
 list_fluid_no++;
 return result;
}

Solid new_solid(char *name)
{
 char* t1 = "";
 Solid result ={0};
 result.state = "";
 result.original_name = name;
 result.new_name = name;
 result.type = SOLID;
 result.volume = 1000;
 if(print_reagents == 1)
 {
  qts_write("<h2 style=\"margin-top:50px;\">Solutions/reagents:</h2><ul type=\"circle\">");
  print_reagents++;
 }
 result.used = 0;
 usage_list_fluids[list_fluid_no] = result;
 result.usage_index = list_fluid_no;
 list_fluid_no++;
 qts_write(QString("<li>%1</li>").arg( name));
 return result;
}

Solid new_solid(char*name, r4 temp)
{ 
 char* t1 = "";
 Solid result ={0};
 result.original_name = name;
 result.new_name = name;
 result.state = "";
 result.type = SOLID;
 result.volume = 1000;
 if(print_reagents == 1)
 {
  qts_write("<h2 style=\"margin-top:50px;\">Solutions/reagents:</h2><ul type=\"circle\">");
  print_reagents++;
 }
 if(temp == ICE_COLD)
 {
  qts_write(QString("<li>ice-cold %1</li>").arg( name)); //? .arg(temp);
  t1 = (char *)calloc(strlen(t1) + strlen(name) + 10, sizeof(char));
  strcat(t1, "ice-cold ");
  strcat(t1, name);
  result.new_name=t1;
 }
 else
  qts_write(QString("<li>%1 at %2%3C</li>").arg( name).arg(temp).arg(0x00B0));
 result.used = 0;
 usage_list_fluids[list_fluid_no] = result;
 result.usage_index = list_fluid_no;
 list_fluid_no++;
 return result;
}

Solid new_solid(char*name, char* state)
{
 char* t1 = "";
 Solid result ={0};
 result.original_name = name;
 result.new_name = name;
 result.type = SOLID;
 result.volume = 1000;
 if(print_reagents == 1)
 {
  qts_write("<h2 style=\"margin-top:50px;\">Solutions/reagents:</h2><ul type=\"circle\">");
  print_reagents++;
 }
 qts_write(QString("<li> <a name=\"%1\">%2 <i><br><tab>(%3)<br></i></a></li>").arg( name).arg(name).arg(state));
 result.used = 0;
 usage_list_fluids[list_fluid_no] = result;
 result.usage_index = list_fluid_no;
 list_fluid_no++;
 return result;
}

Solid new_solid (char* name, char*state, r4 temp)
{
 char* t1 = "";
 Solid result ={0};
 result.original_name = name;
 result.new_name = name;
 result.state = state;
 result.type = SOLID;
 result.volume = 1000;
 if(print_reagents == 1)
 {
  qts_write("<h2 style=\"margin-top:50px;\">Solutions/reagents:</h2><ul type=\"circle\">");
  print_reagents++;
 }
 if(temp == ICE_COLD)
 {
  qts_write(QString("<li> <a name=\"%1\">ice-cold %2 <i><br><tab>(%3)<br></i></a></li>").arg( name).arg(name).arg(state));
  t1 = (char *)calloc(strlen(t1) + strlen(name) + 10, sizeof(char));
  strcat(t1, "ice-cold ");
  strcat(t1, name);
  result.new_name = t1;
 }
 else if(temp >= 35)
  qts_write(QString("<li> <a name=\"%1\">%2 preheated in a water bath set at <b><font color=#357EC7>%3%4C</font></b> <i>%5</i></a></li>").arg( name).arg(name).arg(temp).arg(0x00B0).arg(state));
 else
  qts_write(QString("<li> <a name=\"%1\">%2 <i>%3</i> </a> at <b><font color=#357EC7>%4%5C</font></b></li>").arg( name).arg(name).arg(state).arg(temp).arg(0x00B0));
 result.used = 0;
 usage_list_fluids[list_fluid_no] = result;
 result.usage_index = list_fluid_no;
 list_fluid_no++;
 return result;
}

void store_container_names (u4 i, char* name)
{
 if(container_count[i] == 0)
 {
  containers[cont_no] = name;
  cont_no++;
 }
}

Container new_container( container_type cont_id)
{
 Container result ={0};
 result.type = CONTAINER;
 result.volume = 0;
 result.contents.new_name = "";
 char* temp;
 char* temp1 = (char *)calloc(50, sizeof(char));
 char* temp2 = (char *)calloc(50, sizeof(char));
 result.id = cont_id;
 switch(cont_id)
 {
 case STERILE_MICROFUGE_TUBE:
   sprintf(temp2, " (%d)", container_count[0]+1); temp1 = strcat(temp1, "sterile 1.5-ml microcentrifuge tube");temp1 = strcat(temp1, temp2);result.name = temp1;temp = "Sterile 1.5-ml microcentrifuge tubes"; store_container_names(0, temp); container_count[0]++;break;
 case CENTRIFUGE_TUBE_15ML:
  sprintf(temp2, " (%d)", container_count[1]+1); 
  temp1 = strcat(temp1, "sterile 15-ml centrifuge tube");
  temp1 = strcat(temp1, temp2);
  result.name = temp1;
  temp = "Sterile 15-ml centrifuge tubes";
  store_container_names(1, temp);
  container_count[1]++;
  break;
 case FLASK:
  sprintf(temp2, " (%d)", container_count[2]+1); 
  temp1 = strcat(temp1, "flask");
  temp1 = strcat(temp1, temp2);
  result.name = temp1; 
  temp = "Flasks of appropriate volumes";
  store_container_names(2, temp);
  container_count[2]++;
  break;
 case CENTRIFUGE_BOTTLE:
  sprintf(temp2, " (%d)", container_count[3]+1); temp1 = strcat(temp1, "centrifuge bottle");
  temp1 = strcat(temp1, temp2);
  result.name = temp1; 
  temp = "Centrifuge bottles";
  store_container_names(3, temp);container_count[3]++;
  break;
 case GRADUATED_CYLINDER:
  result.name = "a graduated cylinder"; 
  temp = "Graduated cylinders";
  store_container_names(4, temp);
  container_count[4]++; 
  break;
 case RXN_TUBE:sprintf(temp2, " (%d)", container_count[5]+1); 
  temp1 = strcat(temp1, "reaction tube");
  temp1 = strcat(temp1, temp2);
  result.name = temp1; 
  temp = "Reaction tubes"; 
  store_container_names(5, temp);
  container_count[5]++; 
  break;
 case FRESH_COLL_TUBE:
  sprintf(temp2, " (%d)", container_count[6]+1); 
  temp1 = strcat(temp1, "fresh collection tube");
  temp1 = strcat(temp1, temp2);
  result.name = temp1;
  temp = "Collection tubes";
  store_container_names(6, temp);
  container_count[6]++;
  break;
 case LIQUID_NITROGEN:
  result.name = "a container with liquid nitrogen"; 
  temp = "Container with liquid nitrogen";
  store_container_names(7, temp);
  container_count[7]++; 
  break;
 case PLG:
  result.name = "a 50- ml PLG tube"; 
  temp = "50-ml PLG tubes";
  store_container_names(8, temp);
  container_count[8]++; 
  break;
 case OAKRIDGE:
  sprintf(temp2, " (%d)", container_count[9]+1); 
  temp1 = strcat(temp1, "Oakridge tube");
  temp1 = strcat(temp1, temp2);
  result.name = temp1;
  temp = "Oakridge tubes";
  store_container_names(9, temp); 
  container_count[9]++;
  break;
 case QIA_CARTRIDGE:
  result.name= "a QIAfilter cartridge"; 
  temp = "QIAfilter cartridge";
  store_container_names(10, temp);
  container_count[10]++;
  break;
 case CUVETTE_ICE:
  result.name= "a cuvette stored on ice"; 
  temp = "Cuvettes stored on ice";
  store_container_names(11, temp);
  container_count[11]++;
  break;
 case SPEC_CUVETTE:
  result.name= "a spectrometry cuvette"; 
  temp = "Spectrometry cuvettes";
  store_container_names(12, temp); 
  container_count[12]++;
  break;
 case STOCK_PLATE_96:
  result.name = "a 96-well stock plate"; 
  temp = "96-well stock plates";
  store_container_names(13, temp);
  container_count[13]++;
  break;
 case WELL_BLOCK_96:
  result.name = "a 96-well block"; 
  temp = "96-well blocks";
  store_container_names(14, temp);
  container_count[14]++;
  break;
 case PCR_PLATE:
  result.name = "a 96-well PCR plate"; 
  temp = "96-well PCR plates";
  store_container_names(15, temp); 
  container_count[15]++;
  break;
 case LIQUID_BLOCK:
  result.name = "a 96-well liquid block"; 
  temp = "96-well liquid blocks";
  store_container_names(16, temp);
  container_count[16]++; 
  break;
 case CELL_CULT_CHAMBER:
  result.name = "a cell culture chamber"; 
  temp = "cell culture chamber";
  store_container_names(17, temp);
  container_count[17]++; 
  break;
 case EPPENDORF:sprintf(temp2, " (%d)", container_count[18]+1); 
  temp1 = strcat(temp1, "Eppendorf tube");
  temp1 = strcat(temp1, temp2);
  result.name = temp1;temp = "Eppendorf tubes";
  store_container_names(18, temp); 
  container_count[18]++; 
  break;
 case STERILE_MICROFUGE_TUBE2ML:
  sprintf(temp2, " (%d)", container_count[19]+1); 
  temp1 = strcat(temp1, "sterile 2-ml microcentrifuge tube");
  temp1 = strcat(temp1, temp2);
  result.name = temp1;
  temp = "Sterile 2-ml microcentrifuge tubes"; 
  store_container_names(19, temp); 
  container_count[19]++;
  break;
 case STERILE_PCR_TUBE:sprintf(temp2, " (%d)", container_count[20]+1); 
  temp1 = strcat(temp1, "sterile 0.6-ml microcentrifuge tube");
  temp1 = strcat(temp1, temp2);
  result.name = temp1;
  temp = "Sterile 0.6-ml tubes"; 
  store_container_names(20, temp);
  container_count[20]++;
  break;
 case CENTRI_TUBE_50ML:
  sprintf(temp2, " (%d)", container_count[21]+1); 
  temp1 = strcat(temp1, "50-ml centrifuge tube");
  temp1 = strcat(temp1, temp2);
  result.name = temp1;
  temp = "50-ml centrifuge tubes"; 
  store_container_names(21, temp); 
  container_count[21]++;
  break;
 case CRYO_VIAL:
  result.name = "a screw-topped cryo vial"; 
  temp = "screw-topped cryo vials"; 
  store_container_names(22, temp);
  container_count[22]++; 
  break;
 case SCREW_CAP_TUBE:
  sprintf(temp2, " (%d)", container_count[23]+1); 
  temp1 = strcat(temp1, "screw-cap tube");
  temp1 = strcat(temp1, temp2);
  result.name = temp1;
  temp = "Screw-cap tubes of appropriate volume"; 
  store_container_names(23, temp); 
  container_count[23]++;
  break;
 default:
  break;
 }
 result.used = 0;
 usage_list_containers[list_container_no] = result;
 result.usage_index = list_container_no;
 list_container_no++;
 return result;
}

Container new_container(container_type cont_id, Fluid& fluid1)
{
 Container result ={0};
 result.type = CONTAINER;
 result.contents.new_name = "";
 char* temp1 = (char *)calloc(50, sizeof(char));
 char* temp2 = (char *)calloc(50, sizeof(char));
 result.id = cont_id;
 switch(cont_id)
 {
 case STERILE_MICROFUGE_TUBE:
  sprintf(temp2, " (%d)", container_count[0]+1);temp1 = strcat(temp1, "sterile 1.5-ml microcentrifuge tube");
  temp1 = strcat(temp1, temp2);
  result.name = temp1;
  container_count[0]++;
  break;
 case CENTRIFUGE_TUBE_15ML:
  sprintf(temp2, " (%d)", container_count[1]+1);
  temp1 = strcat(temp1, "sterile 15-ml centrifuge tube");
  temp1 = strcat(temp1, temp2);
  result.name = temp1;
  container_count[1]++;
  break;
 case FLASK:
  sprintf(temp2, " (%d)", container_count[2]+1);
  temp1 = strcat(temp1, "flask");
  temp1 = strcat(temp1, temp2);
  result.name = temp1;
  container_count[2]++;
  break;
 case CENTRIFUGE_BOTTLE:
  sprintf(temp2, " (%d)", container_count[3]+1);
  temp1 = strcat(temp1, "centrifuge bottle");
  temp1 = strcat(temp1, temp2);
  result.name = temp1;
  break;
 case GRADUATED_CYLINDER:
  result.name = "a graduated cylinder";
  break;
 case RXN_TUBE:
  sprintf(temp2, " (%d)", container_count[5]+1);
  temp1 = strcat(temp1, "reaction tube");
  temp1 = strcat(temp1, temp2);
  result.name = temp1;
  container_count[5]++;
  break;
 case FRESH_COLL_TUBE:
  sprintf(temp2, " (%d)", container_count[6]+1);
  temp1 = strcat(temp1, "fresh collection tube");
  temp1 = strcat(temp1, temp2);
  result.name = temp1;
  container_count[6]++;
  break;
 case LIQUID_NITROGEN:
  result.name = "a container with liquid nitrogen";
  break;
 case PLG:
  result.name = "a 50- ml PLG tube"; 
  break;
 case OAKRIDGE:
  sprintf(temp2, " (%d)", container_count[9]+1);
  temp1 = strcat(temp1, "Oakridge tube");
  temp1 = strcat(temp1, temp2);
  result.name = temp1;
  container_count[9]++;
  break;
 case QIA_CARTRIDGE:
  result.name= "a QIAfilter cartridge";
  break;
 case CUVETTE_ICE:
  result.name= "a cuvette stored on ice";
  break;
 case SPEC_CUVETTE:
  result.name= "a spectrometry cuvette";
  break;
 case STOCK_PLATE_96:
  result.name = "a 96-well stock plate";
  break;
 case WELL_BLOCK_96:
  result.name = "a 96-well block";
  break;
 case PCR_PLATE:
  result.name = "a 96-well PCR plate";
  break;
 case LIQUID_BLOCK:
  result.name = "a 96-well liquid block";
  break;
 case CELL_CULT_CHAMBER:
  result.name = "a cell culture chamber";
  break;
 case EPPENDORF:
  sprintf(temp2, " (%d)", container_count[18]+1);temp1 = strcat(temp1, "Eppendorf tube");temp1 = strcat(temp1, temp2);result.name = temp1;container_count[18]++;
  break;
 case STERILE_MICROFUGE_TUBE2ML:
  printf(temp2, " (%d)", container_count[19]+1);
  temp1 = strcat(temp1, "sterile 2-ml microcentrifuge tube");
  temp1 = strcat(temp1, temp2);
  result.name = temp1;
  container_count[19]++;
  break;
 case STERILE_PCR_TUBE:
  sprintf(temp2, " (%d)", container_count[20]+1);temp1 = strcat(temp1, "sterile 0.6-ml microcentrifuge tube");
  temp1 = strcat(temp1, temp2);
  result.name = temp1;
  container_count[20]++;
  break;
 case CENTRI_TUBE_50ML:
  sprintf(temp2, " (%d)", container_count[21]+1);
  temp1 = strcat(temp1, "50-ml centrifuge tube");
  temp1 = strcat(temp1, temp2);
  result.name = temp1;
  container_count[21]++;
  break;
 case CRYO_VIAL:
  result.name = "a screw-topped cryo vial";
  break;
 case SCREW_CAP_TUBE:
  sprintf(temp2, " (%d)", container_count[23]+1);
  temp1 = strcat(temp1, "screw-cap tube");
  temp1 = strcat(temp1, temp2);
  result.name = temp1;
  container_count[23]++;
  break;
 default:
  break;
 }
 result.used = 0;
 usage_list_containers[list_container_no] = result;
 result.usage_index = list_container_no;
 list_container_no++;
 set_container(fluid1, result);
 return result;
}

void set_container(Fluid& fluid1, Container& container1)
{
 if (usage_list_fluids[fluid1.usage_index].original_name == fluid1.original_name)
 {
  usage_list_fluids[fluid1.usage_index].used = 1;
 }
 else 
 {
  fluid1.used = 1;
  usage_list_fluids[list_fluid_no] = fluid1;
  fluid1.usage_index = list_fluid_no;
  list_fluid_no++;
 } 
 fluid1.container = container1.id;
 container1.contents = fluid1;
 container1.volume = container1.contents.volume;
}

void measure_fluid(Fluid& fluid1, Container& container1)
{
 // graph maintenance
 {
  Operation o = new_operation("measure fluid");
  create_edge_from_fluids(&fluid1, &o);
  create_edge_from_fluid_to_container(&o, &container1);
 }
  if (fluid1.volume == 0)
   qts_write(QString("<font color = red>Warning: You are out of %1! Please make sure you have enough before carrying on with the protocol.<br></font>").arg( fluid1.new_name));
  if (usage_list_fluids[fluid1.usage_index].original_name == fluid1.original_name)
   usage_list_fluids[fluid1.usage_index].used = 1;
  else 
  {
   fluid1.used = 1;
   usage_list_fluids[list_fluid_no] = fluid1;
   fluid1.usage_index = list_fluid_no;
   list_fluid_no++;
  }  
  if (usage_list_containers[container1.usage_index].name == container1.name)
   usage_list_containers[container1.usage_index].used = 1;
  else 
  {
   container1.used = 1;
   usage_list_containers[list_container_no] = container1;
   container1.usage_index = list_container_no;
   list_container_no++;
  }
  if (first == 1)
  {
   prev_container = container1.name;
   if (container1.contents.new_name == "")
   {
    if(fluid1.state == "")
     qts_write(QString("Measure out %1 into %2.<br>").arg( fluid1.new_name).arg(container1.name));
    else
     qts_write(QString("Measure out <a href=\"#%1\" ><font color=#357EC7>%2</font></a> into %3.<br>").arg( fluid1.new_name).arg(fluid1.new_name).arg(container1.name));
    first = 0;
    prev_cont++;
   }
   else
   {
    if(fluid1.state == "")
     qts_write(QString("Measure out %1 into %2.<br>").arg( fluid1.new_name).arg(container1.contents.new_name));
    else
     qts_write(QString("Measure out <a href=\"#%1\" ><font color=#357EC7>%2</font></a> into %3.<br>").arg( fluid1.new_name).arg(fluid1.new_name).arg(container1.contents.new_name));
    first = 0;
    prev_cont++;
   }
  }
  else if (prev_cont == 1)
  {
   prev_container = container1.name;
   if(fluid1.state == "")
    qts_write(QString("Measure out %1 into %2.<br>").arg( fluid1.new_name).arg(container1.name));
   else
    qts_write(QString("Measure out <a href=\"#%1\" ><font color=#357EC7>%2</font></a> into %3.<br>").arg( fluid1.new_name).arg(fluid1.new_name).arg(container1.name));
   prev_cont++;
  }
  else if(prev_container == container1.name)
  {
   qts_write(QString("Add <font color=#357EC7>%1</font> to %2.<br>").arg( fluid1.new_name).arg(container1.contents.new_name));
   prev_container = container1.name;
  }
  else if(fluid1.state == "")
  {
   qts_write(QString("Measure out %1 into %2.<br>").arg( fluid1.new_name).arg(container1.name));
   prev_container = container1.name;
  }
  else
  {
   qts_write(QString("Measure out <a href=\"#%1\" ><font color=#357EC7>%2</font></a> into %3.<br>").arg( fluid1.new_name).arg(fluid1.new_name).arg(container1.name));
   prev_container = container1.name;
  }
  fluid1.container = container1.id;
  container1.contents = fluid1;
  container1.volume = container1.volume + fluid1.volume;
}

void measure_fluid(Container& container, Container& container1)
{
 // graph maintenance
 {
  Operation o = new_operation("measure fluid");
  create_edge_from_container_to_fluid(&container, &o);
  create_edge_from_fluid_to_container(&o, &container1);
 }
  if (container.volume == 0)
   qts_write(QString("<font color = red>Warning: You are out of %1! Please make sure you have enough before carrying on with the protocol.<br></font>").arg( container.contents.new_name));
  if (usage_list_containers[container.usage_index].name == container.name)
   usage_list_containers[container.usage_index].used = 1;
  else 
  {
   container.used = 1;
   usage_list_containers[list_container_no] = container;
   container.usage_index = list_container_no;
   list_container_no++;
  }  
  if (usage_list_containers[container1.usage_index].name == container1.name)
   usage_list_containers[container1.usage_index].used = 1;
  else 
  {
   container1.used = 1;
   usage_list_containers[list_container_no] = container1;
   container1.usage_index = list_container_no;
   list_container_no++;
  }
  if (first == 1)
  {
   prev_container = container1.name;
   if (container1.contents.new_name == "")
   {
    if(container.contents.state == "")
     qts_write(QString("Measure out %1 into %2.<br>").arg( container.contents.new_name).arg(container1.name));
    else
     qts_write(QString("Measure out <a href=\"#%1\" ><font color=#357EC7>%2</font></a> into %3.<br>").arg( container.contents.new_name).arg(container.contents.new_name).arg(container1.name));
    first = 0;
    prev_cont++;
   }
   else
   {
    if(container.contents.state == "")
     qts_write(QString("Measure out %1 into %2.<br>").arg( container.contents.new_name).arg(container1.contents.new_name));
    else
     qts_write(QString("Measure out <a href=\"#%1\" ><font color=#357EC7>%2</font></a> into %3.<br>").arg( container.contents.new_name).arg(container.contents.new_name).arg(container1.contents.new_name));
    first = 0;
    prev_cont++;
   }
  }
  else if (prev_cont == 1)
  {
   prev_container = container1.name;
   if(container.contents.state == "")
    qts_write(QString("Measure out %1 into %2.<br>").arg( container.contents.new_name).arg(container1.name));
   else
    qts_write(QString("Measure out <a href=\"#%1\" ><font color=#357EC7>%2</font></a> into %3.<br>").arg( container.contents.new_name).arg(container.contents.new_name).arg(container1.name));
   prev_cont++;
  }
  else if(prev_container == container1.name)
  {
   qts_write(QString("Add <font color=#357EC7>%1</font> to %2.<br>").arg( container.contents.new_name).arg(container1.contents.new_name));
   prev_container = container1.name;
  }
  else if(container.contents.state == "")
  {
   qts_write(QString("Measure out %1 into %2.<br>").arg( container.contents.new_name).arg(container1.name));
   prev_container = container1.name;
  }
  else
  {
   qts_write(QString("Measure out <a href=\"#%1\" ><font color=#357EC7>%2</font></a> into %3.<br>").arg( container.contents.new_name).arg(container.contents.new_name).arg(container1.name));
   prev_container = container1.name;
  }
  container.contents.container = container1.id;
  container1.contents = container.contents;
  container1.volume = container1.volume + container.volume;
}

void measure_fluid(Fluid& fluid1, Volume* volume1)
{
 // graph maintenance
 {
  Operation o = new_operation("measure fluid");
  create_edge_from_fluids(&fluid1, &o);
 }
  if ((fluid1.volume == 0)|| (fluid1.volume < (volume1->value*volume1->mul)))
   qts_write(QString("<font color = red>Warning: You are out of %1! Please make sure you have enough before carrying on with the protocol.<br></font>").arg( fluid1.new_name));
  if (usage_list_fluids[fluid1.usage_index].original_name == fluid1.original_name)
   usage_list_fluids[fluid1.usage_index].used = 1;
  else 
  {
   fluid1.used = 1;
   usage_list_fluids[list_fluid_no] = fluid1;
   fluid1.usage_index = list_fluid_no;
   list_fluid_no++;
  }  
  qts_write("Measure out ");
  volume1->display_vol();
  if(fluid1.state == "")
   qts_write(QString(" of %1.<br>").arg( fluid1.new_name));
  else
   qts_write(QString(" of <a href=\"#%1\" ><font color=#357EC7>%2</font></a>.<br>").arg( fluid1.new_name).arg(fluid1.new_name));
  fluid1.volume = fluid1.volume - volume1->value * volume1->mul;
}

void measure_fluid(Fluid &fluid1, Volume* volume1, Container& container1)
{
 // graph maintenance
 {
  Operation o = new_operation("measure fluid");
  create_edge_from_fluids(&fluid1, &o);
  create_edge_from_fluid_to_container(&o, &container1);
 }
  if ((fluid1.volume == 0)|| (fluid1.volume < (volume1->value*volume1->mul)))
   qts_write(QString("<font color = red>Warning: You are out of %1! Please make sure you have enough before carrying on with the protocol.<br></font>").arg( fluid1.new_name));
  if (usage_list_fluids[fluid1.usage_index].original_name == fluid1.original_name)
   usage_list_fluids[fluid1.usage_index].used = 1;
  else 
  {
   fluid1.used = 1;
   usage_list_fluids[list_fluid_no] = fluid1;
   fluid1.usage_index = list_fluid_no;
   list_fluid_no++;
  }  
  if (usage_list_containers[container1.usage_index].name == container1.name)
   usage_list_containers[container1.usage_index].used = 1;
  else 
  {
   container1.used = 1;
   usage_list_containers[list_container_no] = container1;
   container1.usage_index = list_container_no;
   list_container_no++;
  }
  if (first == 1)
  {
   fluid1.volume = fluid1.volume - volume1->value * volume1->mul;
   prev_container = container1.name;
   qts_write("Measure out ");
   volume1->display_vol();
   if (container1.contents.new_name == "")
   {
    if(fluid1.state == "")
     qts_write(QString(" of <font color=#357EC7>%1</font> into %2.<br>").arg( fluid1.new_name).arg(container1.name));
    else
     qts_write(QString(" of <a href=\"#%1\" ><font color=#357EC7>%2</font></a> into %3.<br>").arg( fluid1.new_name).arg(fluid1.new_name).arg(container1.name));
    first = 0;
    prev_cont++;
   }
   else
   {
    if(fluid1.state == "")
     qts_write(QString(" of <font color=#357EC7>%1</font> into %2.<br>").arg( fluid1.new_name).arg(container1.contents.new_name));
    else
     qts_write(QString(" of <a href=\"#%1\" ><font color=#357EC7>%2</font></a> into %3.<br>").arg( fluid1.new_name).arg(fluid1.new_name).arg(container1.contents.new_name));
    first = 0;
    prev_cont++;
   }
  }
  else if (prev_cont == 1)
  {
   fluid1.volume = fluid1.volume - volume1->value * volume1->mul;
   prev_container = container1.name;
   qts_write("Measure out ");
   volume1->display_vol();
   if(fluid1.state == "")
    qts_write(QString(" of <font color=#357EC7>%1</font> into %2.<br>").arg( fluid1.new_name).arg(container1.name));
   else
    qts_write(QString(" of <a href=\"#%1\" ><font color=#357EC7>%2</font></a> into %3.<br>").arg( fluid1.new_name).arg(fluid1.new_name).arg(container1.name));
   prev_cont++;
  }
  else if (prev_container == container1.name)
  {
   fluid1.volume = fluid1.volume - volume1->value * volume1->mul;
   if(fluid1.state == "")
   {
    qts_write("Add ");
    volume1->display_vol();
    qts_write(QString(" of <font color=#357EC7>%1</font>.<br>").arg( fluid1.new_name));
   }
   else
   {
    qts_write("Add ");
    volume1->display_vol();
    qts_write(QString(" of <a href=\"#%1\" ><font color=#357EC7>%2</font></a>.<br>").arg( fluid1.new_name).arg(fluid1.new_name));
   }
  }
  else
  {
   fluid1.volume = fluid1.volume - volume1->value * volume1->mul;
   qts_write("Measure out ");
   volume1->display_vol();
   if(fluid1.state == "")
   {
    qts_write(QString(" of <font color=#357EC7>%1</font> into %2.<br>").arg( fluid1.new_name).arg(container1.name));
    prev_container = container1.name;
   }
   else
   {
    qts_write(QString(" of <a href=\"#%1\" ><font color=#357EC7>%2</font></a> into %3.<br>").arg( fluid1.new_name).arg(fluid1.new_name).arg(container1.name));
    prev_container = container1.name;
   }
  }
  fluid1.container = container1.id;
  container1.contents = fluid1;
  container1.volume = container1.volume + volume1->value * volume1->mul;
}

void measure_fluid(Container& con, Volume* volume1, Container& container1)
{
 // graph maintenance
 {
  Operation o = new_operation("measure fluid");
  create_edge_from_container_to_fluid(&con, &o);
  create_edge_from_fluid_to_container(&o, &container1);
 }
  if ((con.volume == 0)|| (con.volume < (volume1->value*volume1->mul)))
   qts_write(QString("<font color = red>Warning: You are measuing out more than the available volume of %1! Please make sure you have enough before carrying on with the protocol.<br></font>").arg( con.contents.new_name));
  if (usage_list_containers[con.usage_index].name == con.name)
   usage_list_containers[con.usage_index].used = 1;
  else 
  {
   con.used = 1;
   usage_list_containers[list_container_no] = con;
   con.usage_index = list_container_no;
   list_container_no++;
  }  
  if (usage_list_containers[container1.usage_index].name == container1.name)
   usage_list_containers[container1.usage_index].used = 1;
  else 
  {
   container1.used = 1;
   usage_list_containers[list_container_no] = container1;
   container1.usage_index = list_container_no;
   list_container_no++;
  }
  if (first == 1)
  {
   con.contents.volume = con.contents.volume - volume1->value * volume1->mul;
   prev_container = container1.name;
   qts_write("Measure out ");
   volume1->display_vol();
   if (container1.contents.new_name == "")
   {
    if(con.contents.state == "")
     qts_write(QString(" of <font color=#357EC7>%1</font> into %2.<br>").arg( con.contents.new_name).arg(container1.name));
    else
     qts_write(QString(" of <a href=\"#%1\" ><font color=#357EC7>%2</font></a> into %3.<br>").arg( con.contents.new_name).arg(con.contents.new_name).arg(container1.name));
    first = 0;
    prev_cont++;
   }
   else
   {
    if(con.contents.state == "")
     qts_write(QString(" of <font color=#357EC7>%1</font> into %2.<br>").arg( con.contents.new_name).arg(container1.contents.new_name));
    else
     qts_write(QString(" of <a href=\"#%1\" ><font color=#357EC7>%2</font></a> into %3.<br>").arg( con.contents.new_name).arg(con.contents.new_name).arg(container1.contents.new_name));
    first = 0;
    prev_cont++;
   }
  }
  else if (prev_cont == 1)
  {
   con.contents.volume = con.contents.volume - volume1->value * volume1->mul;
   prev_container = container1.name;
   qts_write("Measure out ");
   volume1->display_vol();
   if(con.contents.state == "")
    qts_write(QString(" of <font color=#357EC7>%1</font> into %2.<br>").arg( con.contents.new_name).arg(container1.name));
   else
    qts_write(QString(" of <a href=\"#%1\" ><font color=#357EC7>%2</font></a> into %3.<br>").arg( con.contents.new_name).arg(con.contents.new_name).arg(container1.name));
   prev_cont++;
  }
  else if (prev_container == container1.name)
  {
   con.contents.volume = con.contents.volume + volume1->value * volume1->mul;
   if(con.contents.state == "")
   {
    qts_write("Add ");
    volume1->display_vol();
    qts_write(QString(" of <font color=#357EC7>%1</font>.<br>").arg( con.contents.new_name));
   }
   else
   {
    qts_write("Add ");
    volume1->display_vol();
    qts_write(QString(" of <a href=\"#%1\" ><font color=#357EC7>%2</font></a>.<br>").arg( con.contents.new_name).arg(con.contents.new_name));
   }
  }
  else
  {
   con.contents.volume = con.contents.volume - volume1->value * volume1->mul;
   qts_write("Measure out ");
   volume1->display_vol();
   if(con.contents.state == "")
   {
    qts_write(QString(" of <font color=#357EC7>%1</font> into %2.<br>").arg( con.contents.new_name).arg(container1.name));
    prev_container = container1.name;
   }
   else
   {
    qts_write(QString(" of <a href=\"#%1\" ><font color=#357EC7>%2</font></a> into %3.<br>").arg( con.contents.new_name).arg(con.contents.new_name).arg(container1.name));
    prev_container = container1.name;
   }
  }
  con.contents.container = container1.id;
  container1.contents = con.contents;
  container1.volume = container1.volume + volume1->value * volume1->mul;
}

void set_temp(Container& container1, r4 temp)
{
 // graph maintenance
 {
  Operation o = new_operation("set temp");
  create_edge_from_container_to_fluid(&container1, &o);
  container1.node = create_node("container with contents at new temperature");
  create_edge(o.node, container1.node);
 }
  if (temp >= 35)
   qts_write(QString("Pre-heat %1 in a water bath set at <b><font color=#357EC7>65%2C</font></b>.<br>").arg( container1.contents.new_name, 0x00B0));
  else
   qts_write(QString("Set the temperature of %1 to <b><font color=#357EC7>%2%3C</font></b>.<br>").arg( container1.contents.new_name).arg(temp).arg(0x00B0));
}

void measure_prop(Container& dest, Container& source, r4 prop)
{
 // graph maintenance
 {
  Operation o = new_operation("measure prop");
  create_edge_from_container_to_fluid(&source, &o);
  create_edge_from_fluid_to_container(&o, &dest);
 }
  if ((source.contents.volume == 0)|| (source.contents.volume < (dest.volume * prop)))
   qts_write(QString("<font color = red>Warning: You are measuing out more than the available volume of %1! Please make sure you have enough before carrying on with the protocol.<br></font>").arg( source.contents.new_name));
  if (usage_list_containers[dest.usage_index].name == dest.name)
   usage_list_containers[dest.usage_index].used = 1;
  else 
  {
   dest.used = 1;
   usage_list_containers[list_container_no] = dest;
   dest.usage_index = list_container_no;
   list_container_no++;
  }  
  if (usage_list_containers[source.usage_index].name == source.name)
   usage_list_containers[source.usage_index].used = 1;
  else 
  {
   source.used = 1;
   usage_list_containers[list_container_no] = source;
   source.usage_index = list_container_no;
   list_container_no++;
  }
  if (first == 1)
  {
   prev_container = dest.name;
   if(source.contents.state == "")
   {
    if (prop > 1)
     qts_write(QString("Measure out <b><font color=#357EC7>%1</font></b> volumes <font color=#357EC7>%2</font> into %3.<br>").arg( prop).arg(source.contents.new_name).arg(dest.contents.new_name));
    else
     qts_write(QString("Measure out <b><font color=#357EC7>%1</font></b> volume <font color=#357EC7>%2</font> into %3.<br>").arg( prop).arg(source.contents.new_name).arg(dest.contents.new_name));
   }
   else
   {
    if (prop > 1)
     qts_write(QString("Measure out <b><font color=#357EC7>%1</font></b> volumes <a href=\"#%2\" ><font color=#357EC7>%3</font></a> into %4.<br>").arg( prop).arg(source.contents.new_name).arg(source.contents.new_name).arg(dest.contents.new_name));
    else
     qts_write(QString("Measure out <b><font color=#357EC7>%1</font></b> volume <a href=\"#%2\" ><font color=#357EC7>%3</font></a> into %4.<br>").arg( prop).arg(source.contents.new_name).arg(source.contents.new_name).arg(dest.contents.new_name));
   }
  }
  else if (prev_container == dest.name)
  {
   dest.contents.volume = dest.contents.volume +  prop * dest.contents.volume;
   if(source.contents.state != "")
   {
    if (prop > 1)
     qts_write(QString("Add <b><font color=#357EC7>%1</font></b> volumes <a href=\"#%1\" ><font color=#357EC7>%2</font></a>.<br>").arg( prop).arg(source.contents.new_name).arg(source.contents.new_name));
    else 
     qts_write(QString("Add <b><font color=#357EC7>%1</font></b> volume <a href=\"#%1\" ><font color=#357EC7>%2</font></a>.<br>").arg( prop).arg(source.contents.new_name).arg(source.contents.new_name));
   }
   else 
   {
    if (prop > 1)
     qts_write(QString("Add  <b><font color=#357EC7>%1</font></b> volumes <font color=#357EC7>%2</font>.<br>").arg( prop).arg(source.contents.new_name));
    else
     qts_write(QString("Add  <b><font color=#357EC7>%1</font></b> volume <font color=#357EC7>%2</font>.<br>").arg( prop).arg(source.contents.new_name));
   }
  }
  else
  {
   dest.contents.volume = dest.contents.volume -  prop * dest.contents.volume;
   if(source.contents.state != "")
   {
    if (prop > 1)
     qts_write(QString("Add <b><font color=#357EC7>%1</font></b> volumes <a href=\"#%1\" ><font color=#357EC7>%2</font></a> to %3.<br>").arg( prop).arg(source.contents.new_name).arg(source.contents.new_name).arg(dest.name).arg(dest.name));
    else 
     qts_write(QString("Add <b><font color=#357EC7>%1</font></b> volume <a href=\"#%1\" ><font color=#357EC7>%2</font></a> to %3.<br>").arg( prop).arg(source.contents.new_name).arg(source.contents.new_name).arg(dest.name));
   }
   else 
   {
    if (prop > 1)
     qts_write(QString("Add  <b><font color=#357EC7>%1</font></b> volumes <font color=#357EC7>%2</font> to %3.<br>").arg( prop).arg(source.contents.new_name).arg(dest.name));
    else
      qts_write(QString("Add  <b><font color=#357EC7>%1</font></b> volume <font color=#357EC7>%2</font> to %3.<br>").arg( prop).arg(source.contents.new_name).arg(dest.name));
   }
  }
  prev_container = dest.name;
  dest.volume = dest.volume +  prop * dest.volume;
}

void measure_prop(Container& dest, Fluid& source, r4 prop)
{
 // graph maintenance
 {
  Operation o = new_operation("measure prop");
  create_edge_from_fluids(&source, &o);
  create_edge_from_fluid_to_container(&o, &dest);  
 }
  if ((source.volume == 0)|| (source.volume < (dest.volume*prop)))
   qts_write(QString("<font color = red>Warning: You are measuing out more than the available volume of %1! Please make sure you have enough before carrying on with the protocol.<br></font>").arg( source.new_name));
  if (usage_list_fluids[source.usage_index].original_name == source.original_name)
   usage_list_fluids[source.usage_index].used = 1;
  else 
  {
   source.used = 1;
   usage_list_fluids[list_fluid_no] = source;
   source.usage_index = list_fluid_no;
   list_fluid_no++;
  }  
  if (usage_list_containers[dest.usage_index].name == dest.name)
   usage_list_containers[dest.usage_index].used = 1;
  else 
  {
   dest.used = 1;
   usage_list_containers[list_container_no] = dest;
   dest.usage_index = list_container_no;
   list_container_no++;
  }
  if (first == 1)
  {
   prev_container = dest.name;
   if(source.state == "")
   {
    if (prop > 1)
     qts_write(QString("Measure out <b><font color=#357EC7>%1</font></b> volumes <font color=#357EC7>%2</font> into %3.<br>").arg( prop).arg(source.new_name).arg(dest.contents.new_name));
    else
     qts_write(QString("Measure out <b><font color=#357EC7>%1</font></b> volume <font color=#357EC7>%2</font> into %3.<br>").arg( prop).arg(source.new_name).arg(dest.contents.new_name));
   }
   else
   {
    if (prop > 1)
     qts_write(QString("Measure out <b><font color=#357EC7>%1</font></b> volumes <a href=\"#%2\" ><font color=#357EC7>%3</font></a> into %4.<br>").arg( prop).arg(source.new_name).arg(source.new_name).arg(dest.contents.new_name));
    else
     qts_write(QString("Measure out <b><font color=#357EC7>%1</font></b> volume <a href=\"#%2\" ><font color=#357EC7>%3</font></a> into %4.<br>").arg( prop).arg(source.new_name).arg(source.new_name).arg(dest.contents.new_name));
   }
  }
  else if (prev_container == dest.name)
  {
   dest.contents.volume = dest.contents.volume +  prop * dest.contents.volume;
   if(source.state != "")
   {
    if (prop > 1)
     qts_write(QString("Add <b><font color=#357EC7>%1</font></b> volumes <a href=\"#%2\" ><font color=#357EC7>%3</font></a>.<br>").arg( prop).arg(source.new_name).arg(source.new_name));
    else 
     qts_write(QString("Add <b><font color=#357EC7>%1</font></b> volume <a href=\"#%2\" ><font color=#357EC7>%3</font></a>.<br>").arg( prop).arg(source.new_name).arg(source.new_name));
   }
   else 
   {
    if (prop > 1)
     qts_write(QString("Add  <b><font color=#357EC7>%1</font></b> volumes <font color=#357EC7>%2</font>.<br>").arg( prop).arg(source.new_name));
    else
     qts_write(QString("Add  <b><font color=#357EC7>%1</font></b> volume <font color=#357EC7>%2</font>.<br>").arg( prop).arg(source.new_name));
   }
  }
  else
  {
   dest.contents.volume = dest.contents.volume -  prop * dest.contents.volume;
   if(source.state != "")
   {
    if (prop > 1)
     qts_write(QString("Add <b><font color=#357EC7>%1</font></b> volumes <a href=\"#%2\" ><font color=#357EC7>%3</font></a> to %4.<br>").arg( prop).arg(source.new_name).arg(source.new_name).arg(dest.name));
    else 
     qts_write(QString("Add <b><font color=#357EC7>%1</font></b> volume <a href=\"#%2\" ><font color=#357EC7>%3</font></a> to %4.<br>").arg( prop).arg(source.new_name).arg(source.new_name).arg(dest.name));
   }
   else 
   {
    if (prop > 1)
     qts_write(QString("Add  <b><font color=#357EC7>%1</font></b> volumes <font color=#357EC7>%2</font> to %3.<br>").arg( prop).arg(source.new_name).arg(dest.name));
    else
     qts_write(QString("Add  <b><font color=#357EC7>%1</font></b> volume <font color=#357EC7>%2</font> to %3.<br>").arg( prop).arg(source.new_name).arg(dest.name));
   }
  }

  prev_container = dest.name;
  dest.volume = dest.volume +  prop * dest.volume;
}

void combine_helper (u4 count, Container &container1, va_list ap)
{
 u4 i;
 Container sample, result1;
 char* plus = "+";
 char* str3 = "";
 char* str4 = "";
 Operation o;
 // graph  maintenance
 {
  result1.node = create_node("container with mixture");
  o = new_operation("combine");
  create_edge_from_fluids(&o, &result1);
 }
  for(i=0; i<count; i++)
  {
   if (i == 0)
   {
    sample = container1;
    qts_write(QString("Combine the %1").arg( sample.contents.new_name));
    result1.contents.new_name = container1.contents.new_name;
    result1.volume = container1.volume;
   } 
   else
   {
    sample = va_arg (ap, Container);
    qts_write(QString(",%1").arg( sample.contents.new_name));
    str3 = (char *)calloc(strlen(str3) + strlen(sample.contents.new_name) + 2, sizeof(char));
    strcat(str3, plus);
    strcat(str3, sample.contents.new_name);
    result1.volume = result1.volume + sample.volume;
   }
   // graph maintenance
   {
    create_edge_from_container_to_fluid(&sample, &o);
   }

  }

  str4=(char *)calloc(strlen(result1.contents.new_name) + strlen(str3) + 1, sizeof(char));
  strcat(str4, result1.contents.new_name);
  strcat(str4, str3);
  result1.contents.new_name = str4;

  container1 = result1;
  qts_write("<br>");
}

void combine (u4 count, Container &container1, ...) 
{
 va_list ap;
 va_start(ap, container1);
 combine_helper(count, container1, ap);
 va_end(ap);
}

void transfer (Container &container1, Container& container2)
{
 // graph maintenance
 {
  Operation o = new_operation("transfer");
  create_edge_from_container_to_fluid(&container1, &o);
  create_edge_from_fluid_to_container(&o, &container2);
 }
  if (container1.volume == 0)
   qts_write(QString("<font color = red>Warning: You are out of %1! Please make sure you have enough before carrying on with the protocol.<br></font>").arg( container1.contents.new_name));
  if (usage_list_containers[container2.usage_index].name == container2.name)
   usage_list_containers[container2.usage_index].used = 1;
  else 
  {
   container2.used = 1;
   usage_list_containers[list_container_no] = container2;
   container2.usage_index = list_container_no;
   list_container_no++;
  }  
  if (usage_list_containers[container1.usage_index].name == container1.name)
   usage_list_containers[container1.usage_index].used = 1;
  else 
  {
   container1.used = 1;
   usage_list_containers[list_container_no] = container1;
   container1.usage_index = list_container_no;
   list_container_no++;
  }
  qts_write(QString("Transfer %1 into %2.<br>").arg(container1.contents.new_name).arg(container2.name));
  container2.contents = container1.contents;
  container2.contents.container = container2.id;
  container2.volume = container1.volume;
  container1.volume = 0;
}

void centrifuge_pellet(Container& container1, Speed* speed1, r4 temp, Time* time1, Volume* expected_vol)
{
 qts_write("Centrifuge ");
 check_container(container1);
 qts_write(" at "); 
 speed1->display_speed();
 qts_write(" for ");
 time1->display_time();
 if(temp == RT)
  qts_write("at <b><font color=#357EC7>room temperature</font></b>, gently aspirate out the supernatant and discard it.<br>");
 else
  qts_write(QString("at <b><font color=#357EC7>%1%2C</font></b>, gently aspirate out the supernatant and discard it.<br>").arg( temp).arg(0x00B0));
 qts_write("<i>The expected volume of supernatant is ");
 expected_vol->display_vol();
 qts_write(".</i><br>");
 name_sample(container1, "pellet");
 container1.volume = 0;
 if(microfuge_no == 1)
 {
  equipments[equip_no] = "Centrifuge";
  equip_no++;
  microfuge_no++;
 }
 // graph maintenance
 {
  Operation o = new_operation("centrifuge pellet");
  create_edge_from_container_to_fluid(&container1, &o);
  container1.node = create_node("container with pellet");
  create_edge(o.node, container1.node);
  o.node->time = time1->value;
  o.node->unit = time1->unit;
  o.node->pcr_or_centrifuge = 1;
 }
}

void centrifuge_pellet(Container &container1, Speed* speed1, r4 temp, Time* time1)
{
 qts_write("Centrifuge ");
 check_container(container1);
 qts_write(" at "); 
 speed1->display_speed();
 qts_write(" for ");
 time1->display_time();
 if(temp == RT)
  qts_write(" at <b><font color=#357EC7>room temperature</font></b>, gently aspirate out the supernatant and discard it.<br>");
 else
  qts_write(QString(" at <b><font color=#357EC7>%1%2C</font></b>, gently aspirate out the supernatant and discard it.<br>").arg( temp).arg(0x00B0));
 name_sample(container1, "pellet");
 container1.volume = 0;
 if(centrifuge_no == 1)
 {
  equipments[equip_no] = "Centrifuge";
  equip_no++;
  centrifuge_no++;
 }
 // graph maintenance
 {
  Operation o = new_operation("centrifuge pellet");
  create_edge_from_container_to_fluid(&container1, &o);
  container1.node = create_node("container with pellet");
  create_edge(o.node, container1.node);
  o.node->time = time1->value;
  o.node->unit = time1->unit;
  o.node->pcr_or_centrifuge = 1;
 }
}

void centrifuge_phases_top(Container &container1, Speed* speed1, r4 temp, Time* time1, Volume* aspirate_vol, Container &container2)
{
 // graph maintenance
 Operation o = new_operation("centrifuge phases -- top phase");
 create_edge_from_container_to_fluid(&container1, &o);
 create_edge_from_fluid_to_container(&o, &container2);

 if (usage_list_containers[container2.usage_index].name == container2.name)
  usage_list_containers[container2.usage_index].used = 1;
 else 
 {
  container2.used = 1;
  usage_list_containers[list_container_no] = container2;
  container2.usage_index = list_container_no;
  list_container_no++;
 }
 qts_write("Centrifuge ");
 check_container(container1);
 qts_write(" at "); 
 speed1->display_speed();
 qts_write(" for ");
 time1->display_time();
 if(temp == RT)
  qts_write(" at <b><font color=#357EC7><b><font color=#357EC7>room temperature</font></b></font></b>");
 else
  qts_write(QString(" at <b><font color=#357EC7>%1%2C</font></b>").arg( temp).arg(0x00B0));
 qts_write(" and aspirate out ");
 aspirate_vol->display_vol();
 qts_write(QString(" of top layer into %1.<br>").arg( container2.name));
 name_sample(container1, "top aqueous layer");
 container2.volume = aspirate_vol->value;
 container2.contents = container1.contents;
 name_sample(container1, "bottom layer");
 discard(container1);
 if(centrifuge_no == 1)
 {
  equipments[equip_no] = "Centrifuge";
  equip_no++;
  centrifuge_no++;
 }
 o.node->time = time1->value;
 o.node->unit = time1->unit;
 o.node->pcr_or_centrifuge = 1;
}

void centrifuge_phases_top(Container &container1, Speed* speed1, r4 temp, Time* time1, Container &container2)
{
 // graph maintenance
 Operation o = new_operation("centrifuge phases -- top phase");
 create_edge_from_container_to_fluid(&container1, &o);
 create_edge_from_fluid_to_container(&o, &container2);

 if (usage_list_containers[container2.usage_index].name == container2.name)
  usage_list_containers[container2.usage_index].used = 1;
 else 
 {
  container2.used = 1;
  usage_list_containers[list_container_no] = container2;
  container2.usage_index = list_container_no;
  list_container_no++;
 }
 qts_write("Centrifuge ");
 check_container(container1);
 qts_write(" at "); 
 speed1->display_speed();
 qts_write(" for ");
 time1->display_time();
 if(temp == RT)
  qts_write(" at <b><font color=#357EC7><b><font color=#357EC7>room temperature</font></b></font></b>");
 else
  qts_write(QString(" at <b><font color=#357EC7>%1%2C</font></b>").arg( temp).arg(0x00B0));
 qts_write(QString(" and aspirate out the top layer into %1.<br>").arg( container2.name));
 name_sample(container1, "top aqueous layer");
 container2.contents = container1.contents;
 container2.volume = 0.5 * container1.volume;
 name_sample(container1, "bottom layer");
 discard(container1);
 if(centrifuge_no == 1)
 {
  equipments[equip_no] = "Centrifuge";
  equip_no++;
  centrifuge_no++;
 }
 o.node->time = time1->value;
 o.node->unit = time1->unit;
 o.node->pcr_or_centrifuge = 1;
}

void centrifuge(Container &container1, Speed* speed1, r4 temp, Time* time1)
{
 qts_write("Centrifuge ");
 check_container(container1);
 qts_write(" at "); 
 speed1->display_speed();
 qts_write(" for ");
 time1->display_time();
 if(temp == RT)
  qts_write(" at <b><font color=#357EC7><b><font color=#357EC7>room temperature</font></b></font></b>.<br>");
 else
  qts_write(QString(" at <b><font color=#357EC7>%1%2C</font></b>.<br>").arg( temp).arg(0x00B0));
 if(centrifuge_no == 1)
 {
  equipments[equip_no] = "Centrifuge";
  equip_no++;
  centrifuge_no++;
 }
 // graph maintenance
 {
  Operation o = new_operation("centrifuge");
  create_edge_from_container_to_fluid(&container1, &o);
  container1.node = create_node("container with contents centrifuged");
  create_edge(o.node, container1.node);
  o.node->time = time1->value;
  o.node->unit = time1->unit;
  o.node->pcr_or_centrifuge = 1;
 }
}

void discard(Container& container1)  
{ 
 // graph maintenance
 {
  Operation o = new_operation("discard");
  create_edge_from_container_to_fluid(&container1, &o);
  container1.node = create_node("contents of container discarded");
  create_edge(o.node, container1.node);
 }
  qts_write(QString("Discard %1.<br>").arg( container1.contents.new_name));
  container1.volume = 0;

}

void mix (Container &container1,  mixing type, Time* time1)     
{
 switch(type)
 {
 case TAPPING: qts_write("Gently tap the mixture for ");
  time1->display_time();
  qts_write(" .<br>"); 
  break;
 case STIRRING: 
  qts_write("Stir the mixture for ");
  time1->display_time();
  qts_write(" .<br>"); 
  break;
 case INVERTING: 
  qts_write("Close the tube tightly and invert the tube ");
  time1->display_time();
  qts_write(" times.<br>"); 
  break;
 case VORTEXING: 
  qts_write("Vortex the mixture for ");
  time1->display_time();
  qts_write(" .<br>"); 
  break;
 default: 
  qts_write("Invalid entry.<br>");
 }
 // graph maintenance
 {
  Operation o = new_operation("mix");
  create_edge_from_container_to_fluid(&container1, &o);
  container1.node = create_node("container with contents mixed");
  create_edge(o.node, container1.node);
  o.node->time = time1->value;
  o.node->unit = time1->unit;
 }
}

void mix (Container &container1,  mixing type, u4 times)     
{
 switch(type){
 case INVERTING: 
  qts_write(QString("Close the tube tightly and invert the tube <b><font color=#357EC7>%1 times</font></b>.<br>").arg( times)); 
  break;
 default: qts_write("Invalid entry.<br>");
 }
 // graph maintenance
 {
  Operation o = new_operation("mix");
  create_edge_from_container_to_fluid(&container1, &o);
  container1.node = create_node("container with contents mixed");
  create_edge(o.node, container1.node);
 }
}

void mix (Container &container1,  mixing type, u4 min_times, u4 max_times)     
{
 switch(type){
 case INVERTING: 
  qts_write(QString("Close the tube tightly and invert the tube <b><font color=#357EC7>%1 - %2 times</font></b>.<br>").arg( min_times).arg(max_times)); break;
 default: qts_write("Invalid entry.<br>");
 }
 // graph maintenance
 {
  Operation o = new_operation("mix");
  create_edge_from_container_to_fluid(&container1, &o);
  container1.node = create_node("container with contents mixed");
  create_edge(o.node, container1.node);
 }
}

void mix (Container &container1,  mixing type)     
{
 switch(type){
 case TAPPING: qts_write("Gently tap the mixture for a few secs.<br>"); break;
 case STIRRING: qts_write("Stir the mixture for a few secs.<br>"); break;
 case INVERTING: qts_write("Close the tube tightly and gently mix the contents by inverting the tube.<br>"); break;
 case VORTEXING: qts_write("Vortex the mixture for a few secs.<br>"); break;
 case RESUSPENDING:qts_write("Resuspend pellet by vortexing/by shaking vigorously.<br>"); break;
 case DISSOLVING:qts_write("Dissolve the pellet in the solution.<br>");break;
 case PIPETTING:qts_write("Mix solution by pipetting up and down several times.<br>");break;
 default: qts_write("Invalid entry.<br>");
 }
 // graph maintenance
 {
  Operation o = new_operation("mix");
  create_edge_from_container_to_fluid(&container1, &o);
  container1.node = create_node("container with contents mixed");
  create_edge(o.node, container1.node);
 }
}

void mix (Container &container1,  until event1)     
{
 if (event1 == PPT_STOPS_STICKING)
 qts_write("Close the tube tightly and gently mix the contents by inverting the tube until precipitate stops sticking to walls of the tube.<br>");
 if (event1 == PELLET_DISLODGES)
  qts_write("Gently mix the contents of the tube until the pellet dislodges.<br>");
 // graph maintenance
 {
  Operation o = new_operation("mix");
  create_edge_from_container_to_fluid(&container1, &o);
  container1.node = create_node("container with contents mixed");
  create_edge(o.node, container1.node);
 }
}

void tap (Container& container1,  until event1)
{
 mix(container1, event1);
}

void tap(Container &container1, Time* time1)
{
 mix(container1, TAPPING, time1);
}

void tap(Container &container1)
{
 mix(container1, TAPPING);
}

void stir(Container& container1)
{
 mix(container1, STIRRING);
}

void stir(Container& container1, Time* time1)
{
 mix(container1, STIRRING, time1);
}

void invert(Container &container1, u4 times)
{
 mix(container1, INVERTING, times);
}

void invert(Container &container1, u4 min_times, u4 max_times)
{
 mix(container1, INVERTING, min_times, max_times);
}

void invert(Container &container1)
{
 mix(container1, INVERTING);
}

void invert(Container& container1,  until event1)
{
 mix(container1, event1);
}

void vortex(Container &container1, Time* time1)
{
 mix(container1, VORTEXING, time1);
}

void vortex(Container &container1)
{
 mix(container1, VORTEXING);
}

void resuspend(Container &container1)
{
 mix(container1, RESUSPENDING);
}

void dissolve (Container &container1)
{
 mix(container1, DISSOLVING);
}

void pipet (Container &container1)
{

 mix(container1, PIPETTING);
}

void wait(Container& container1, Time* time1)
{
 qts_write(QString("Keep %1 aside for ").arg( container1.contents.new_name));
 time1->display_time();
 qts_write(".<br>");
 // graph maintenance
 {
  Operation o = new_operation("wait");
  create_edge_from_container_to_fluid(&container1, &o);
  container1.node = create_node("container with contents after waiting");
  create_edge(o.node, container1.node);
  o.node->time = time1->value;
  o.node->unit = time1->unit;
 }
}

void combine_and_mix ( mixing type, Time* time1, u4 count, Container &container1, ...)
{
 va_list ap;
 va_start(ap, container1);
 combine_helper(count, container1, ap);
 va_end(ap);
 mix(container1, type, time1);
}

void combine_and_mix ( mixing type, u4 count, Container &container1, ...)
{
 va_list ap;
 va_start(ap, container1);
 combine_helper(count, container1, ap);
 va_end(ap);
 mix(container1, type);
}

void inoculation(Container& medium, Fluid& sample1, Volume* volume1, r4 temp, Time* time1, int shaking_type)
{
 char* unit;
 r4 result;
 if ((sample1.volume == 0)|| (sample1.volume < (volume1->value*volume1->mul)))
 {
  qts_write(
  QString("<font color = red>Warning: You are measuing out more than the available volume of %1!  Please make sure you have enough before carrying on with the protocol.<br></font>").arg(sample1.new_name));
 }
 if (usage_list_fluids[sample1.usage_index].original_name == sample1.original_name)
   usage_list_fluids[sample1.usage_index].used = 1;
 else 
 {
  sample1.used = 1;
  usage_list_fluids[list_fluid_no] = sample1;
  sample1.usage_index = list_fluid_no;
  list_fluid_no++;
 }  
 if(usage_list_containers[medium.usage_index].name == medium.name)
   usage_list_containers[medium.usage_index].used = 1;
 else 
 {
  medium.used = 1;
  usage_list_containers[list_container_no] = medium;
  medium.usage_index = list_container_no;
  list_container_no++;
 }
 if(medium.volume != DEFAULT)
 {
  switch(medium.contents.unit){
   case UL: unit = "mcL"; result = medium.volume; 
    break;
   case ML: unit = "ml"; result = medium.volume/1000; 
    break;
   case L: unit = "l"; result = medium.volume/1000000; 
    break;
   default:
    break;
  }
  qts_write(QString("Inoculate <font color=#357EC7>%1 %2 %3</font> with ").arg(result).arg(unit).arg(medium.contents.new_name));
 }
 else
  qts_write(QString("Inoculate <font color=#357EC7>%1</font> with ")
  .arg(medium.contents.new_name));
 volume1->display_vol();
 switch(shaking_type)
 {
  case 1:
   qts_write(QString(" of <font color=#357EC7>%1</font> and incubate with shaking for ").arg(sample1.new_name));
   break;
  case 2:
   qts_write(QString(" of <font color=#357EC7>%1</font> and incubate without shaking for ").arg(sample1.new_name));
   break;
  default:qts_write("Invalid inputs.");
   break;
 }
 time1->display_time();
 qts_write(QString(" at <b><font color=#357EC7>%1%2C</font></b>.<br>").arg(temp).arg(0x00B0)); // // degree ... 
 medium.volume = medium.volume + volume1->value * volume1->mul;
 if(incubator_no == 1)
 {
  equipments[equip_no] = "Incubator";
  equip_no++;
  incubator_no++;
 }
 name_sample(medium, "culture");
 // graph maintenance
 {
  Operation o = new_operation("inoculation");
  create_edge_from_container_to_fluid(&medium, &o);
  medium.node = create_node("container with contents after inoculation");
  create_edge(o.node, medium.node);
  o.node->time = time1->value;
  o.node->unit = time1->unit;
 }
}

void inoculation(Container& medium, Fluid& sample1, Volume* volume1, r4 temp, Time* time1, r4 cell_density, int shaking_type)
{
 char* unit;
 r4 result;
 if ((sample1.volume == 0)|| (sample1.volume < (volume1->value*volume1->mul)))
   qts_write(QString("<font color = red>Warning: You are measuing out more than the available volume of %1! Please make sure you have enough before carrying on with the protocol.<br></font>").arg(sample1.new_name));

 if (usage_list_fluids[sample1.usage_index].original_name == sample1.original_name)
   usage_list_fluids[sample1.usage_index].used = 1;
 else 
 {
  sample1.used = 1;
  usage_list_fluids[list_fluid_no] = sample1;
  sample1.usage_index = list_fluid_no;
  list_fluid_no++;
 }  
 if(usage_list_containers[medium.usage_index].name == medium.name)
   usage_list_containers[medium.usage_index].used = 1;
 else 
 {
  medium.used = 1;
  usage_list_containers[list_container_no] = medium;
  medium.usage_index = list_container_no;
  list_container_no++;
 }
 if (medium.volume != DEFAULT)
 {
  switch(medium.contents.unit){
   case UL: 
    unit = "mcL"; result = medium.contents.volume; 
    break;
   case ML: 
    unit = "ml"; result = medium.contents.volume/1000; 
    break;
   case L: 
    unit = "l"; result = medium.contents.volume/1000000; 
    break;
   default:
    break;
  }
  qts_write(QString("Inoculate <font color=#357EC7>%1 %2 %3</font> with ").arg(result).arg(unit).arg(medium.contents.new_name));
 }
 else
  qts_write(QString("Inoculate <font color=#357EC7>%1</font> with ").arg(medium.contents.new_name));
 volume1->display_vol();
 switch(shaking_type)
 {
  case 1:
   qts_write(QString(" of <font color=#357EC7>%1</font> and incubate with shaking for ").arg(sample1.new_name));
   break;
  case 2:
   qts_write(QString(" of <font color=#357EC7>%1</font> and incubate without shaking for ").arg(sample1.new_name));
   break;
  default:qts_write("Invalid inputs.");
   break;
 }
 time1->display_time();
 qts_write(QString(" at <b><font color=#357EC7>%1%2C</font></b>.<br>".arg(temp).arg(0x00B0));
 qts_write(QString("Calibrate the spectrophotometer and make sure that the cell density of the culture has reached <b><font color=#357EC7>%1 X 10<sup>6</sup> cells/ml</font></b> before continuing.<br>").arg(cell_density));
 medium.volume = medium.volume + volume1->value * volume1->mul;
 if(spectrophotometer_no == 1)
 {
  equipments[equip_no] = "Spectrophotometer";
  equip_no++;
  incubator_no++;
 }
 if(incubator_no == 1)
 {
  equipments[equip_no] = "Incubator";
  equip_no++;
  incubator_no++;
 }
 name_sample(medium, "culture");
 // graph maintenance
 {
  Operation o = new_operation("inoculation");
  create_edge_from_container_to_fluid(&medium, &o);
  medium.node = create_node("container with contents at required OD after inoculation");
  create_edge(o.node, medium.node);
  o.node->time = time1->value;
  o.node->unit = time1->unit;
 }
}

void inoculation(Container& medium, Solid& sample1, r4 temp, Time* time1, int shaking_type)
{
 char* unit;
 r4 result;
 if (usage_list_fluids[sample1.usage_index].original_name == sample1.original_name)
  usage_list_fluids[sample1.usage_index].used = 1;
 else 
 {
  sample1.used = 1;
  usage_list_fluids[list_fluid_no] = sample1;
  sample1.usage_index = list_fluid_no;
  list_fluid_no++;
 }  
 if (usage_list_containers[medium.usage_index].name == medium.name)
  usage_list_containers[medium.usage_index].used = 1;
 else 
 {
  medium.used = 1;
  usage_list_containers[list_container_no] = medium;
  medium.usage_index = list_container_no;
  list_container_no++;
 }
 if (medium.volume != DEFAULT)
 {
  switch(medium.contents.unit){
   case UL: unit = "mcL"; result = medium.contents.volume; 
    break;
   case ML: unit = "ml"; result = medium.contents.volume/1000; 
    break;
   case L: unit = "l"; result = medium.contents.volume/1000000; 
    break;
   default:
    break;
  }
  qts_write(QString("Inoculate <font color=#357EC7>%1 %2 %3</font> with ".arg(result).arg(unit).arg(medium.contents.new_name));
 }
 else
  qts_write(QString("Inoculate <font color=#357EC7>%1</font> with ").arg(medium.contents.new_name));
 switch(shaking_type)
 {
  case 1:
   qts_write(QString("<font color=#357EC7>%1</font> and incubate with shaking for ").arg(sample1.new_name));
   time1->display_time();
   qts_write(QString(" at <b><font color=#357EC7>%1%2C</font></b>.<br>".arg(temp).arg(0x00B0));
   break;
  case 2:
   qts_write(QString("<font color=#357EC7>%1</font> and incubate without shaking for ").arg(sample1.new_name));
   time1->display_time();
   qts_write(QString(" at <b><font color=#357EC7>%1%2C</font></b>.<br>".arg(temp).arg(0x00B0));
   break;
  default:qts_write("Invalid inputs.");
   break;
 }

 if(incubator_no == 1)
 {
  equipments[equip_no] = "Incubator";
  equip_no++;
  incubator_no++;
 }
 name_sample(medium, "culture");
 // graph maintenance
 {
  Operation o = new_operation("inoculation");
  create_edge_from_container_to_fluid(&medium, &o);
  medium.node = create_node("container with contents after inoculation");
  create_edge(o.node, medium.node);
  o.node->time = time1->value;
  o.node->unit = time1->unit;
 }
}

void inoculation(Container& medium, Solid& sample1, r4 temp, Time* time1, r4 cell_density, int shaking_type)
{
 char* unit;
 r4 result;
 if (usage_list_fluids[sample1.usage_index].original_name == sample1.original_name)
  usage_list_fluids[sample1.usage_index].used = 1;
 else 
 {
  sample1.used = 1;
  usage_list_fluids[list_fluid_no] = sample1;
  sample1.usage_index = list_fluid_no;
  list_fluid_no++;
 }  
 if (usage_list_containers[medium.usage_index].name == medium.name)
  usage_list_containers[medium.usage_index].used = 1;
 else 
 {
  medium.used = 1;
  usage_list_containers[list_container_no] = medium;
  medium.usage_index = list_container_no;
  list_container_no++;
 }
 if (medium.volume != DEFAULT)
 {
  switch(medium.contents.unit)
  {
   case UL: unit = "mcL"; result = medium.contents.volume; 
    break;
   case ML: unit = "ml"; result = medium.contents.volume/1000; 
    break;
   case L: unit = "l"; result = medium.contents.volume/1000000; 
    break;
   default:
    break;
  }
  qts_write(QString("Inoculate <font color=#357EC7>%1 %2 %3</font> with ").arg(result).arg(unit).arg(medium.contents.new_name));
 }
 else
  qts_write(QString("Inoculate <font color=#357EC7>%1</font> with ").arg(medium.contents.new_name));
 switch(shaking_type)
 {
  case 1:
   qts_write(QString("<font color=#357EC7>%1</font> and incubate with shaking for ").arg( sample1.new_name);
   time1->display_time();
   qts_write(QString(" at <b><font color=#357EC7>%1%2C</font></b>.<br>").arg( temp).arg(0x00B0));
   break;
  case 2:
   qts_write(QString("<font color=#357EC7>%1</font> and incubate without shaking for ").arg( sample1.new_name));
   time1->display_time();
   qts_write(" at <b><font color=#357EC7>%1%2C</font></b>.<br>").arg( temp).arg(0x00B0));
   break;
  default:qts_write("Invalid inputs.");
   break;
 }
 qts_write("Calibrate the spectrophotometer and make sure that the cell density of the culture has reached <b><font color=#357EC7>%1 X 10<sup>6</sup> cells/ml</font></b> before continuing.<br>").arg( cell_density));
 if(spectrophotometer_no == 1)
 {
  equipments[equip_no] = "Spectrophotometer";
  equip_no++;
  incubator_no++;
 }
 if(incubator_no == 1)
 {
  equipments[equip_no] = "Incubator";
  equip_no++;
  incubator_no++;
 }
 name_sample(medium, "culture");
 // graph maintenance
 {
  Operation o = new_operation("inoculation");
  create_edge_from_container_to_fluid(&medium, &o);
  medium.node = create_node("container with contents at required OD after inoculation");
  create_edge(o.node, medium.node);
  o.node->time = time1->value;
  o.node->unit = time1->unit;
 }
}

void store(Container& container1, r4 temp)
{
 // graph maintenance
 {
  Operation o = new_operation("store");
  create_edge_from_container_to_fluid(&container1, &o);
  container1.node = create_node("container stored at required temperature");
  create_edge(o.node, container1.node);
 }
  if(temp == ON_ICE)
  {
   qts_write("Store ");
   check_container(container1);
   qts_write(" <b><font color=#357EC7>on ice</font></b>.<br>");
  }
  else if(temp == BOILING_WATER)
   qts_write("Immerse the tube in boiling water.");
  else 
  {
   qts_write("Store ");
   check_container(container1);
   qts_write(QString(" at <b><font color=#357EC7>%1%2C</font></b>.<br>").arg( temp).arg(0x00B0));
  }
}

void store_for(Container& container1, r4 temp, Time* time1)
{
 if(temp == ON_ICE)
 {
  qts_write("Store ");
  check_container(container1);
  qts_write(" <b><font color=#357EC7>on ice</font></b> for ");
 }
 else if(temp == BOILING_WATER)
 {
  qts_write("Immerse ");
  check_container(container1);
  qts_write(" in boiling water for ");
 }
 else if (temp == RT)
 {
  qts_write("Store ");
  check_container(container1);
  qts_write(" at <b><font color=#357EC7><b><font color=#357EC7>room temperature</font></b></font></b> for ");
 }
 else 
 {
  qts_write("Store ");
  check_container(container1);
  qts_write(QString(" at <b><font color=#357EC7>%1%2C</font></b> for ").arg( temp).arg(0x00B0));
 }
 time1->display_time();
 qts_write(".<br>");
 // graph maintenance
 {
  Operation o = new_operation("store for");
  create_edge_from_container_to_fluid(&container1, &o);
  container1.node = create_node("container stored at required temperature");
  create_edge(o.node, container1.node);
  o.node->time = time1->value;
  o.node->unit = time1->unit;
 }
}

void store_for(Container& sample1, r4 temp, Time* time1,  func function)
{
 if(function == 1)
 {
  qts_write("Denature ");
  check_container(sample1);
  qts_write(QString(" at <b><font color=#357EC7>%1%2C</font></b> for ").arg( temp).arg(0x00B0));
 }
 else if (function == 2)
 {
  qts_write("Perform enzyme inactivation by storing ");
  check_container(sample1);
  qts_write(QString(" at <b><font color=#357EC7>%1%2C</font></b> for ").arg( temp).arg(0x00B0));
 }
 time1->display_time();
 qts_write(".<br>");
 // graph maintenance
 {
  Operation o = new_operation("store for");
  create_edge_from_container_to_fluid(&sample1, &o);
  sample1.node = create_node("container stored at required temperature");
  create_edge(o.node, sample1.node);
  o.node->time = time1->value;
  o.node->unit = time1->unit;
 }
}

void store_until(Container& container1, r4 temp,  until type)
{
 // graph maintenance
 {
  Operation o = new_operation("store until");
  create_edge_from_container_to_fluid(&container1, &o);
  container1.node = create_node("container stored at required temperature");
  create_edge(o.node, container1.node);
 }
  switch(type)
  {
   case ETHANOL_EVAP:
    if (temp == RT)
      qts_write(QString("Store %1 at <b><font color=#357EC7>room temperature</font></b> until the ethanol has evaporated and no fluid is visible in the tube.<br>").arg( container1.contents.new_name));
    else
      qts_write(QString("Store %1 at <b><font color=#357EC7>%2%3C</font></b> until the ethanol has evaporated and no fluid is visible in the tube.<br>").arg( container1.contents.new_name).arg(temp).arg(0x00B0));
    break;
   case OD:
    qts_write(QString("Incubate %1 at <b><font color=#357EC7>%2%3C</font></b> until the O.D.600 reaches 0.6.<br>").arg( container1.contents.new_name).arg(temp).arg(0x00B0));
    break;
   case THAW:
    qts_write(QString("Allow %1 to thaw at <b><font color=#357EC7>room temperature</font></b>.<br>").arg( container1.contents.new_name));
    break;
   case COOLED:
    qts_write(QString("Keep %1 at <b><font color=#357EC7>room temperature</font></b> until cooled.<br>").arg( container1.contents.new_name));
    break;
   case COLOUR_DEVELOPS:
    qts_write("Wait for the colour to develop.<br>");
    break;
   case THAW_ICE:
    qts_write(QString("Allow %1 to thaw on <b><font color=#357EC7>ice</font></b>.<br>").arg( container1.contents.new_name));
    break;
   default: 
    break;
  }
}

void store_until(Container& container1, r4 temp,  until type, Time* time1)
{
 switch(type)
 {
  case ETHANOL_EVAP:
   if (temp == RT)
     qts_write(QString("Store %1 at <b><font color=#357EC7>room temperature</font></b> until the ethanol has evaporated and no fluid is visible in the tube (~").arg( container1.contents.new_name));
   else 
     qts_write(QString("Store %1 at <b><font color=#357EC7>%2%3C</font></b> until the ethanol has evaporated and no fluid is visible in the tube (~").arg( container1.contents.new_name));
   break;
  case OD:
   qts_write(QString("Incubate %1 at <b><font color=#357EC7>%2%3C</font></b> until the O.D.600 reaches 0.6 (~").arg( container1.contents.new_name));
   break;
  case THAW:
   qts_write(QString("Allow %1 to thaw at <b><font color=#357EC7>room temperature</font></b> (~").arg( container1.contents.new_name));
   break;
  case COOLED:
   qts_write(QString("Keep %1 at <b><font color=#357EC7>room temperature</font></b> until cooled (~").arg( container1.contents.new_name));
   break;
  case COLOUR_DEVELOPS:
   qts_write(QString("Wait for the colour to develop (~").arg( container1.contents.new_name));
   break;
  default:
   break;
 }
 time1->display_time();
 qts_write(").<br>");
 // graph maintenance
 {
  Operation o = new_operation("store until");
  create_edge_from_container_to_fluid(&container1, &o);
  container1.node = create_node("container stored at required temperature");
  create_edge(o.node, container1.node);
  o.node->time = time1->value;
  o.node->unit = time1->unit;
 }
}

void invert_dry(Container& container1, r4 temp, Time* time1)
{
 if(temp == RT)
 {
  qts_write(QString("Stand the tube containing %1 for ").arg( container1.contents.new_name));
  time1->display_time();
  qts_write(" in an inverted position on a paper towel to allow all of the fluid to drain away.<br>");
 }
 else 
 {
  qts_write(QString("Stand the tube containing %1 in an inverted position on a paper towel to allow all of the fluid to drain away. Dry at <b><font color=#357EC7>%2%3C</font></b> for ").arg( container1.contents.new_name).arg(temp).arg(0x00B0));
  time1->display_time();
  qts_write(".<br>");
 }
 container1.volume = 0;
 // graph maintenance
 {
  Operation o = new_operation("invert dry");
  create_edge_from_container_to_fluid(&container1, &o);
  container1.node = create_node("container after drying");
  create_edge(o.node, container1.node);
  o.node->time = time1->value;
  o.node->unit = time1->unit;
 }
}

void invert_dry(Container& container1, r4 temp)
{
 // graph maintenance
 {
  Operation o = new_operation("invert dry");
  create_edge_from_container_to_fluid(&container1, &o);
  container1.node = create_node("container after drying");
  create_edge(o.node, container1.node);
 }
  if(temp == RT)
    qts_write(QString("Stand the tube containing %1 in an inverted position on a tissue paper to allow all of the fluid to drain away.<br>").arg( container1.contents.new_name));
  else 
    qts_write(QString("Stand the tube containing %1 in an inverted position on a tissue paper to allow all of the fluid to drain away.<br>").arg( container1.contents.new_name));
  container1.volume = 0;
}

void incubate(Container& container1, r4 temp, Time* time1, int rpm)
{
 if(temp == RT)
 {
  qts_write("Incubate ");
  check_container(container1);
  qts_write(qts," at <b><font color=#357EC7><b><font color=#357EC7>room temperature</font></b></font></b> for ");
 }
 else if((temp == ON_ICE)||(temp == 0))
 {
  qts_write("Incubate ");
  check_container(container1);
  qts_write(" on <b><font color=#357EC7><b><font color=#357EC7>ice</font></b></font></b> for ");
 }
 else
 {
  qts_write("Incubate ");
  check_container(container1);
  qts_write(QString(" at <b><font color=#357EC7>%1%2C</font></b> for ").arg( temp).arg(0x00B0));
 }
 time1->display_time();
 qts_write(QString(" with shaking at %1 rpm.<br>").arg( rpm));
 if(incubator_no == 1)
 {
  equipments[equip_no] = "Incubator";
  equip_no++;
  incubator_no++;
 }
 // graph maintenance
 {
  Operation o = new_operation("incubate");
  create_edge_from_container_to_fluid(&container1, &o);
  container1.node = create_node("container after incubation");
  create_edge(o.node, container1.node);
  o.node->time = time1->value;
  o.node->unit = time1->unit;
 }
}

void incubate_and_mix(Container& container1, r4 temp, Time* time1, Time* time_mix,  mixing type)
{
 qts_write("Incubate ");
 check_container(container1);
 switch (type)
 {
 case STIRRING: 
  qts_write(QString(" at <b><font color=#357EC7>%1%2C</font></b> for ").arg( temp).arg(0x00B0)); 
  time1->display_time(); 
  qts_write(", mixing gently by stirring the tube every "); 
  time_mix->display_time(); 
  qts_write(". <br>");
  break;
 case INVERTING: 
  qts_write(QString(" at <b><font color=#357EC7>%1%2C</font></b> for ").arg( temp).arg(0x00B0)); 
  time1->display_time(); 
  qts_write(", mixing gently by inverting the tube every "); 
  time_mix->display_time(); 
  qts_write(". <br>");
  break;
 case VORTEXING: 
  qts_write(QString(" at <b><font color=#357EC7>%1%2C</font></b> for ").arg( temp, 0x00B0)); 
  time1->display_time(); 
  qts_write(", mixing gently by vortexing the tube every "); 
  time_mix->display_time(); 
  qts_write(". <br>");
  break;
 default:
  break;
 }
 if(incubator_no == 1)
 {
  equipments[equip_no] = "Incubator";
  equip_no++;
  incubator_no++;
 }
 // graph maintenance
 {
  Operation o = new_operation("incubate and mix");
  create_edge_from_container_to_fluid(&container1, &o);
  container1.node = create_node("container after incubation with mixing at periodic intervals");
  create_edge(o.node, container1.node);
  o.node->time = time1->value;
  o.node->unit = time1->unit;
 }
}

void name_sample(Container& container1, char* new_name)
{
 container1.contents.new_name = new_name;
 container1.contents.state = "";
 container1.contents.used = 1;
 usage_list_fluids[list_fluid_no] = container1.contents;
 container1.contents.usage_index = list_fluid_no;
 list_fluid_no++;
}

void name_column(Column& column1, char* new_name)
{
 column1.name = new_name;
 usage_list_containers[column1.usage_index].name = new_name;
}

void nanodrop(Container& container1)
{
 // graph maintenance
 {
  Operation o = new_operation("nanodrop");
  create_edge_from_container_to_fluid(&container1, &o);
  container1.node = create_node("nonodrop results");
  create_edge(o.node, container1.node);
 }
  qts_write(QString("Measure the concentration of %1 in your final samples with the Nanodrop.<br>").arg( container1.contents.new_name);
}

void time_constraint(Container& container1, Time* time1,  time_constraint_type type)
{
 switch (type)
 {
 case CURRENT_FLUID: 
  if (time1 == 0)
    qts_write(QString("<font color=red>NOTE: Use %1 ").arg( container1.contents.new_name));
  else
  {
   qts_write(QString("<font color=red>NOTE: Use %1 within ").arg( container1.contents.new_name));
  }
  time1->display_time(); 
  qts_write(".</font><br>"); 
  break;
 case NEXTSTEP: 
  if (time1 == 0)
    qts_write("<font color=red>NOTE: Proceed to the next step ");
  else
    qts_write("<font color=red>NOTE: Proceed to the next step within ");
  time1->display_time();
   qts_write("!</font><br>");
  break;
 default:
  break;
 }
 // graph maintenance
 {
  Operation o = new_operation("time constraint");
  create_edge_from_container_to_fluid(&container1, &o);
  o.node->time = time1->value;
  o.node->unit = time1->unit;
 }
}

void use_or_store(Container &container1, Time* time1, r4 temp_use, r4 temp_store)
{
 qts_write(QString("NOTE: If %1 is/are used within ").arg( container1.contents.new_name));
 time1->display_time();
 qts_write(QString(", set temperature to <b><font color=#357EC7>%1%2C</font></b> and use, else store it at <b><font color=#357EC7>%3%4C</font></b>.").arg( temp_use).arg(0x00B0).arg(temp_store).arg(0x00B0));

 // graph maintenance
 {
  Operation o = new_operation("use or store");
  create_edge_from_container_to_fluid(&container1, &o);
  container1.node = create_node("container either used or stored");
  create_edge(o.node, container1.node);
 }

}

void mixing_table(u4 no_rows, u4 no_columns, Volume* rxn_vol, Fluid array1[], char* tube[], r4 *vol, Container& container1)
{
 u4 i,j;
 for(i=0; i<no_columns-1;i++)
 {
  if (usage_list_fluids[array1[i].usage_index].original_name == array1[i].original_name)
   usage_list_fluids[array1[i].usage_index].used = 1;
  else 
  {
   array1[i].used = 1;
   usage_list_fluids[list_fluid_no] = array1[i];
   array1[i].usage_index = list_fluid_no;
   list_fluid_no++;
  } 
 }
 if (usage_list_containers[container1.usage_index].name == container1.name)
  usage_list_containers[container1.usage_index].used = 1;
 else 
 {
  container1.used = 1;
  usage_list_containers[list_container_no] = container1;
  container1.usage_index = list_container_no;
  list_container_no++;
 }
 if(no_rows-1 == 1)
  qts_write(QString("Use the following table as a checklist for preparing the reaction in %1:<br><br>").arg( container1.name));
 else 
  qts_write(QString("Use the following table as a checklist for preparing the reactions in %1:<br><br>").arg( container1.name));
 qts_write("<table border cellpadding=5 rules=all frame=void bordercolor=#357EC7>");
 for(i=0; i<no_rows; i++)
 {
  for(j=0; j<no_columns; j++)
  {
   if((i == 0) && (j == 0))
     qts_write("<thead><tr><td>&nbsp;</td>");
   else if((i == 0) && (j != 0))
   {
    qts_write(QString("<td><font color=#357EC7>%1</font></td>").arg( (array1[j-1]).new_name));
    if (j == no_columns-1)
      qts_write("</tr></thead>");
   }
   else if((i != 0) && (j == 0))
     qts_write(QString("<tbody><tr><td><font color=#357EC7>%1</font></td>").arg( tube[i-1]));
   else 
   {
    if((i == no_rows-1 )&& (j == no_columns-1) && ((*(vol+(no_columns-1)*(i-1)+(j-1)) == XVAL)))
    {
     qts_write("<td><b><font color=#357EC7>Make up the volume to ");
     rxn_vol->display_vol();
     qts_write("</font></b></td>");
    }
    else if (*(vol+(no_columns-1)*(i-1)+(j-1)) == NA)
      qts_write("<td><b><font color=#357EC7>--</font></b></td>"); 
    else if (*(vol+(no_columns-1)*(i-1)+(j-1)) == XVAL)
      qts_write("<td><b><font color=#357EC7>X</font></b></td>");
    else
      qts_write(QString("<td><b><font color=#357EC7>%1</font></b></td>").arg( //?*
      (vol+(no_columns-1)*(i-1)+(j-1))));
    if (j == no_columns-1)
      qts_write("</tr></body>");
   }
  }
 }
 qts_write("</table>");
 name_sample(container1, "reaction mix");
 container1.volume = 0;
 Operation o = new_operation("mixing table");
 for(i=1; i<no_rows; i++)
 {
  for(j=1; j<no_columns; j++)
  {
   if ((array1[j-1].volume == 0)|| (array1[j-1].volume < (*(vol+(no_columns-1)*(i-1)+(j-1))* rxn_vol->mul)))
   {
    qts_write(QString("<font color = red>Warning: You are measuing out more than the available volume of %1! Please make sure you have enough before carrying on with the protocol.<br></font>").arg( array1[j-1].new_name));

   }
   container1.volume = container1.volume + *(vol+(no_columns-1)*(i-1)+(j-1));
  }
 }
 for(j=1; j<no_columns; j++)
 {
  // graph maintenance
  create_edge_from_fluids(&array1[j-1], &o);
 }
 create_edge_from_fluid_to_container(&o, &container1);
 if (container1.volume > ((no_rows-1)*rxn_vol->value))
   qts_write("<font color = red>Warning: The total reaction volume is greater than the required reaction volume.</font><br>");
 else if (container1.volume < ((no_rows-1)*rxn_vol->value))
   qts_write("<font color = red>Warning: The total reaction volume is less than the required reaction volume.</font><br>");
 container1.contents.volume = container1.volume;
}

void mixing_table(u4 no_rows,u4 no_columns, Fluid array1[], char* tube[], Volume* volumes[], Volume* rxn_vol, Container& container1)
{
 u4 i,j;
 u4 flag = 0;
 u4 make_vol_up = 0;
 r4 sum = 0;
 for(i=0; i<no_columns-1;i++)
 {
  if (usage_list_fluids[array1[i].usage_index].original_name == array1[i].original_name)
   usage_list_fluids[array1[i].usage_index].used = 1;
  else 
  {
   array1[i].used = 1;
   usage_list_fluids[list_fluid_no] = array1[i];
   array1[i].usage_index = list_fluid_no;
   list_fluid_no++;
  } 
 }
 if (usage_list_containers[container1.usage_index].name == container1.name)
   usage_list_containers[container1.usage_index].used = 1;
 else 
 {
  container1.used = 1;
  usage_list_containers[list_container_no] = container1;
  container1.usage_index = list_container_no;
  list_container_no++;
 }
 if(no_rows-1 == 1)
   qts_write(QString("Use the following table as a checklist for preparing the reaction in %1:<br><br>").arg( container1.name));
 else 
   qts_write(QString("Use the following table as a checklist for preparing the reactions in %1:<br><br>").arg( container1.name));
 qts_write("<table border cellpadding=5 rules=all frame=void bordercolor=#357EC7>");
 for(i=0; i<no_rows; i++)
 {
  for(j=0; j<no_columns; j++)
  {
   if((i == 0) && (j == 0))
     qts_write("<thead><tr><td>&nbsp;</td>");

   else if((i == 0) && (j!=0))
   {
    qts_write(QString("<td><font color=#357EC7>%1</font></td>").arg( (array1[j-1]).new_name));
    if (j == no_columns-1)
      qts_write("</tr></thead>");
   }
   else if((i!=0) && (j == 0))
     qts_write(QString("<tbody><tr><td><font color=#357EC7>%1</font></td>").arg( tube[i-1]));
   else 
   {
    if((i == no_rows-1) && (j == no_columns-1) && (volumes[j-1]->value == XVAL))//||(*(vol+(no_columns-1)*(i-1)+(j-1))!='--')))
    {
     make_vol_up = 1;
     qts_write("<td><b><font color=#357EC7>Make up the volume to ");
     rxn_vol->display_vol();
     qts_write("</font></b></td>");
    }
    else if (volumes[i]->value == NA)
    {
     qts_write("<td><b><font color=#357EC7>--</font></b></td>"); 
     volumes[i]->value = 0;
    }
    else if (volumes[i]->value == XVAL)
    {
     qts_write("<td><b><font color=#357EC7>X</font></b></td>");
     volumes[i]->value = DEFAULT;
    }
    else
    {
     qts_write("<td><b>");
     volumes[j-1]->display_vol();
     qts_write("</td>");
    }
    if (j == no_columns-1)
      qts_write("</tr></body>");
   }
  }
 }
 qts_write("</table>");
 name_sample(container1, "reaction mix");
 container1.volume = 0;
 if (make_vol_up == 1)
 {
  for (j=0; j<no_columns-2;j++)
  {
   if (volumes[j]->value == DEFAULT||volumes[j]->value < 0)
     break;
   sum = sum + volumes[j]->value;
  }
  volumes[no_columns-2]->value = rxn_vol->value - sum;
 }
 Operation o = new_operation("mixing table");
 for (i=0; i<no_columns-1;i++)
 {
  if (volumes[i]->value == DEFAULT)
    break;
  else
  {
   if ((array1[i].volume == 0)|| (array1[i].volume < (volumes[i]->value*volumes[i]->mul)))
   {
    qts_write(QString("<font color = red>Warning: You are measuing out more than the available volume of %1! Please make sure you have enough before carrying on with the protocol.<br></font>").arg( array1[i].new_name));
   }
   else if (volumes[i]->value < 0)
   {
    qts_write("<font color = red>Warning: Negative volume input.</font><br>");
    break;
   }
   else
   {
    flag++;
    container1.volume = container1.volume + volumes[i]->value;
   }
  }
 }
 for(i=0; i<no_columns-1; i++)
 {
  // graph maintenance
  create_edge_from_fluids(&array1[i], &o);
 }
 create_edge_from_fluid_to_container(&o, &container1);
 if (flag == (no_columns-1))
 {
  if (container1.volume > rxn_vol->value)
    qts_write("<font color = red>Warning: The total reaction volume is greater than the required reaction volume.</font><br>");
  else if (container1.volume < rxn_vol->value)
    qts_write("<font color = red>Warning: The total reaction volume is less than the required reaction volume.</font><br>");
 }
 container1.contents.volume = container1.volume;
}

Plate new_plate(char *name)
{
 char* t1 = "";
 Plate result ={0};
 result.state ="";
 result.new_name = name;
 result.original_name = name;
 result.type = SOLID;
 qts_write(QString("<li>%1</li>").arg( name));
 result.used = 0;
 usage_list_fluids[list_fluid_no] = result;
 result.usage_index = list_fluid_no;
 list_fluid_no++;
 return result;
}


Plate new_plate(char*name, char* state)
{
 char* t1 = "";
 Plate result ={0};
 result.new_name = name;
 result.original_name = name;
 result.state = state;
 result.type = SOLID;
 qts_write(QString("<li> <a name=\"%1\">%2 <i><br><tab>(%3)<br></i></a></li>").arg( name).arg(name).arg(state));
 result.used = 0;
 usage_list_fluids[list_fluid_no] = result;
 result.usage_index = list_fluid_no;
 list_fluid_no++;
 return result;
}


void plate_out(Plate& plate1, Container& container1, Volume* volume1)
{
 // graph maintenance
 {
  Operation o = new_operation("plate out");
  create_edge_from_container_to_fluid(&container1, &o);
  create_edge_from_fluids(&o, &plate1);
 }
  if ((container1.volume == 0)|| (container1.volume < (volume1->value*volume1->mul)))
  {
   qts_write(QString("<font color = red>Warning: You are measuing out more than the available volume of %1! Please make sure you have enough before carrying on with the protocol.<br></font>").arg( container1.contents.new_name));

  }
  if (usage_list_fluids[plate1.usage_index].original_name == plate1.original_name)
   usage_list_fluids[plate1.usage_index].used = 1;
  else 
  {
   plate1.used = 1;
   usage_list_fluids[list_fluid_no] = plate1;
   plate1.usage_index = list_fluid_no;
   list_fluid_no++;
  }
  if (usage_list_containers[container1.usage_index].name == container1.name)
   usage_list_containers[container1.usage_index].used = 1;
  else 
  {
   container1.used = 1;
   usage_list_containers[list_container_no] = container1;
   container1.usage_index = list_container_no;
   list_container_no++;
  }
  qts_write("Plate out ");
  volume1->display_vol();
  qts_write(QString(" of %1 onto ").arg( container1.contents.new_name));
  if(plate1.state == "")
   qts_write(QString("<font color=#357EC7>%1</font>.<br>").arg( plate1.new_name));
  else
   qts_write(QString("<a href=\"#%1\" ><font color=#357EC7>%2</font></a>.<br>").arg( plate1.new_name).arg(plate1.new_name));
  container1.volume = container1.volume - volume1->value * volume1->mul;
}

void plate_out(Plate& plate1, Container& container1)
{
 // graph maintenance
 {
  Operation o = new_operation("plate out");
  create_edge_from_container_to_fluid(&container1, &o);
  create_edge_from_fluids(&o, &plate1);
 }
  if (usage_list_fluids[plate1.usage_index].original_name == plate1.original_name)
   usage_list_fluids[plate1.usage_index].used = 1;
  else 
  {
   plate1.used = 1;
   usage_list_fluids[list_fluid_no] = plate1;
   plate1.usage_index = list_fluid_no;
   list_fluid_no++;
  }
  if (usage_list_containers[container1.usage_index].name == container1.name)
   usage_list_containers[container1.usage_index].used = 1;
  else 
  {
   container1.used = 1;
   usage_list_containers[list_container_no] = container1;
   container1.usage_index = list_container_no;
   list_container_no++;
  }
  if(plate1.state == "") 
   qts_write(QString("Plate out %1 onto <font color=#357EC7>%2</font>.<br>").arg(container1.contents.new_name).arg(plate1.new_name));
  else
   qts_write(QString("Plate out %1 onto <a href=\"#%2\" ><font color=#357EC7>%3</font></a>.<br>").arg( container1.contents.new_name).arg(plate1.new_name).arg(plate1.new_name));
  container1.volume = 0;
}

void name_container(Container& container1, char* name)
{
 qts_write(QString("Set aside a fresh %1. Call it %2. <br>").arg( container1.name).arg(name));
 container1.name = name;
 usage_list_containers[container1.usage_index].name = name;
 if (usage_list_containers[container1.usage_index].name == container1.name)
  usage_list_containers[container1.usage_index].used = 1;
 else 
 {
  container1.used = 1;
  usage_list_containers[list_container_no] = container1;
  container1.usage_index = list_container_no;
  list_container_no++;
 }
}

void name_plate(Plate& plate1, char* name)
{
 plate1.new_name = name;
}

void thermocycler (Container& master_mix, u4 cycles, r4 temp1, Time* time1, r4 temp2, Time* time2, r4 temp3, Time* time3,  pcr_type type)
{
 u4 ttr1 = total_time_required;
 u4 ttr2;
 if(type == NORMAL)
 {
  qts_write(QString("Thermocycling<br><ul><li>No. of cycles: <b><font color=#357EC7>%1</font></b></li>").arg( cycles));
  qts_write(QString("<li>Denature: <b><font color=#357EC7>%1%2C</font></b>, ").arg( temp1).arg(0x00B0));
  time1->display_time();
  qts_write(QString("</li> <li> Anneal: <b><font color=#357EC7>%1%2C</font></b>, ").arg( temp2).arg(0x00B0));
  time2->display_time();
  qts_write(QString("</li> <li>Elongate: <b><font color=#357EC7>%1%2C</font></b>, ").arg( temp3).arg(0x00B0));
  time3->display_time();
  qts_write("</li></ul>");
  ttr2 = total_time_required-ttr1;
  total_time_required = total_time_required + ttr2 * cycles;
 }
 else if(type == COLONY)
  qts_write(QString("Carry out colony PCR of %1.<br>").arg( master_mix.contents.new_name));
 if(thermocycler_no == 1)
 {
  equipments[equip_no] = "Thermocycler";
  equip_no++;
  thermocycler_no++;
 }
 // graph maintenance
 {
  Operation o = new_operation("thermocycler");
  create_edge_from_container_to_fluid(&master_mix, &o);
  master_mix.node = create_node("container with thermocycled contents");
  create_edge(o.node, master_mix.node);
  o.node->time = (time1->value*time1->mul + time2->value*time2->mul + time3->value*time3->mul) * cycles;
  o.node->unit = "secs";
  o.node->pcr_or_centrifuge = 1;
 }
}

void thermocycler (Container& master_mix, u4 cycles, r4 temp1, Time* time1, r4 temp2, Time* time2, r4 temp3, Time* time3,  pcr_type type, r4 grad_temp)
{
 u4 ttr1 = total_time_required;
 u4 ttr2;
 if(type == NORMAL)
 {
  qts_write(QString("Thermocycling<br><ul><li>No. of cycles: <b><font color=#357EC7>%1</font></b></li>").arg( cycles));
  qts_write(QString("<li>Denature: <b><font color=#357EC7>%1%2C</font></b>, ").arg( temp1).arg(0x00B0));
  time1->display_time();
  qts_write(QString("</li> <li> Anneal: <b><font color=#357EC7>%1%2C</font></b>, ").arg( temp2).arg(0x00B0));
  time2->display_time();
  qts_write(QString("</li> <li>Elongate: <b><font color=#357EC7>%1%2C</font></b>, ").arg( temp3).arg(0x00B0));
  time3->display_time();
  qts_write("</li></ul>");
  ttr2 = total_time_required-ttr1;
  total_time_required = total_time_required + ttr2 * cycles;
 }
 else if(type == GRADIENT)
 {
  qts_write(QString("Thermocycling<br><ul><li>No. of cycles: <b><font color=#357EC7>%1</font></b></li>").arg( cycles));
  qts_write(QString("<li>Denature: <b><font color=#357EC7>%1%2C</font></b>, ").arg( temp1).arg(0x00B0));
  time1->display_time();
  qts_write(QString("</li> <li> Anneal: <b><font color=#357EC7>%1%2C- %3%4C (gradient PCR)</font></b>, ").arg( temp2).arg(0x00B0).arg(grad_temp).arg(0x00B0));
  time2->display_time();
  qts_write(QString("</li> <li>Elongate: <b><font color=#357EC7>%1%2C</font></b>, ").arg( temp3).arg(0x00B0));
  time3->display_time();
  qts_write("</li></ul>");
  ttr2 = total_time_required-ttr1;
  total_time_required = total_time_required + ttr2 * cycles;
 }
 else if(type == COLONY)
  qts_write(QString("Carry out colony PCR of %1.<br>").arg( master_mix.contents.new_name));

 if(thermocycler_no == 1)
 {
  equipments[equip_no] = "Thermocycler";
  equip_no++;
  thermocycler_no++;
 }
 // graph maintenance
 {
  Operation o = new_operation("thermocycler");
  create_edge_from_container_to_fluid(&master_mix, &o);
  master_mix.node = create_node("container with thermocycled contents");
  create_edge(o.node, master_mix.node);
  o.node->time = (time1->value*time1->mul + time2->value*time2->mul + time3->value*time3->mul) * cycles;
  o.node->unit = "secs";
  o.node->pcr_or_centrifuge = 1;
 }
}

void thermocycler (Container& master_mix, u4 cycles, r4 temp1, Time* time1, r4 temp2, Time* time2)
{
 u4 ttr1 = total_time_required;
 u4 ttr2;
 qts_write(QString("Thermocycling<br><ul><li>No. of cycles: <b><font color=#357EC7>%1</font></b></li>").arg( cycles));
 qts_write(QString("<li>Denature: <b><font color=#357EC7>%1%2C</font></b>, ").arg( temp1).arg(0x00B0));
 time1->display_time();
 qts_write(QString("</li> <li> Anneal: <b><font color=#357EC7>%1%2C</font></b>, ").arg( temp2).arg(0x00B0));
 time2->display_time();
 qts_write("</li></ul>");
 ttr2 = total_time_required-ttr1;
 total_time_required = total_time_required + ttr2 * cycles;
 if(thermocycler_no == 1)
 {
  equipments[equip_no] = "Thermocycler";
  equip_no++;
  thermocycler_no++;
 }
 // graph maintenance
 {
  Operation o = new_operation("thermocycler");
  create_edge_from_container_to_fluid(&master_mix, &o);
  master_mix.node = create_node("container with thermocycled contents");
  create_edge(o.node, master_mix.node);
  o.node->time = (time1->value*time1->mul + time2->value*time2->mul) * cycles;
  o.node->unit = "secs";
  o.node->pcr_or_centrifuge = 1;
 }
}

void thermocycler (Container& master_mix, r4 temp1, Time* time1, r4 temp2, Time* time2)
{
 qts_write("Set the thermocycler to run the following program:<br>");

 qts_write(QString("<ul><li><b><font color=#357EC7>%1%2C</font></b>, ").arg( temp1).arg(0x00B0));
 time1->display_time();
 qts_write(QString("</li> <li><b><font color=#357EC7>%1%2C</font></b>, ").arg( temp2).arg(0x00B0));
 time2->display_time();
 qts_write("</li></ul>");
 if(thermocycler_no == 1)
 {
  equipments[equip_no] = "Thermocycler";
  equip_no++;
  thermocycler_no++;
 }
 // graph maintenance
 {
  Operation o = new_operation("thermocycler");
  create_edge_from_container_to_fluid(&master_mix, &o);
  master_mix.node = create_node("container with thermocycled contents");
  create_edge(o.node, master_mix.node);
  o.node->time = (time1->value*time1->mul + time2->value*time2->mul);
  o.node->unit = "secs";
  o.node->pcr_or_centrifuge = 1;
 }
}

void thermocycler (Plate& plate1,  pcr_type type)
{
 // graph maintenance
 {
  Operation o = new_operation("thermocycler");
  create_edge_from_fluids(&plate1, &o);
  plate1.node = create_node("container with thermocycled contents");
  create_edge(o.node, plate1.node);
  o.node->pcr_or_centrifuge = 1;
 }
  if(type == COLONY)
   qts_write(QString("Carry out colony PCR on %1.<br>").arg( plate1.new_name));

  if(thermocycler_no == 1)
  {
   equipments[equip_no] = "Thermocycler";
   equip_no++;
   thermocycler_no++;
  }
}

void thermocycler(Container& container1, r4 temp1, Time* time1)
{
 qts_write(QString("Set the thermocycler to run the following program:<br>");
 qts_write("<ul><li><b><font color=#357EC7>%1%2C</font></b>, ").arg( temp1).arg(0x00B0));
 time1->display_time();
 qts_write("</li></ul>");
 if(thermocycler_no == 1)
 {
  equipments[equip_no] = "Thermocycler";
  equip_no++;
  thermocycler_no++;
 }
 // graph maintenance
 {
  Operation o = new_operation("thermocycler");
  create_edge_from_container_to_fluid(&container1, &o);
  container1.node = create_node("container with thermocycled contents");
  create_edge(o.node, container1.node);
  o.node->time = time1->value*time1->mul;
  o.node->unit = "secs";
  o.node->pcr_or_centrifuge = 1;
 }
}

void ce_detect (Container& container1, r4 length, r4 volt_per_cm, Fluid& fluid1)
{
 // graph maintenance
 {
  Operation o = new_operation("ce detect");
  create_edge_from_container_to_fluid(&container1, &o);
  create_edge_from_fluids(&fluid1, &o);
  container1.node = create_node("results of capillary electrophoresis");
  create_edge(o.node, container1.node);
 }
  if (usage_list_fluids[fluid1.usage_index].original_name == fluid1.original_name)
   usage_list_fluids[fluid1.usage_index].used = 1;
  else 
  {
   fluid1.used = 1;
   usage_list_fluids[list_fluid_no] = fluid1;
   fluid1.usage_index = list_fluid_no;
   list_fluid_no++;
  } 
  if (usage_list_containers[container1.usage_index].name == container1.name)
   usage_list_containers[container1.usage_index].used = 1;
  else 
  {
   container1.used = 1;
   usage_list_containers[list_container_no] = container1;
   container1.usage_index = list_container_no;
   list_container_no++;
  }
  qts_write(QString("Detect/separate %1 by capillary electrophoresis with the following settings - <b><font color=#357EC7>%2</font></b> cm at <b><font color=#357EC7>%3</font></b> V/cm using %4.<br>").arg( container1.contents.new_name).arg(length).arg(volt_per_cm).arg(fluid1));
  name_sample(container1, "separated flow");
}

void ce_detect (Container& container1, r4 length, r4 volt_per_cm, Fluid& fluid1, Time* time1)
{
 if (usage_list_fluids[fluid1.usage_index].original_name == fluid1.original_name)
  usage_list_fluids[fluid1.usage_index].used = 1;
 else 
 {
  fluid1.used = 1;
  usage_list_fluids[list_fluid_no] = fluid1;
  fluid1.usage_index = list_fluid_no;
  list_fluid_no++;
 } 
 if (usage_list_containers[container1.usage_index].name == container1.name)
  usage_list_containers[container1.usage_index].used = 1;
 else 
 {
  container1.used = 1;
  usage_list_containers[list_container_no] = container1;
  container1.usage_index = list_container_no;
  list_container_no++;
 }
 qts_write(QString("Detect/separate %1 by capillary electrophoresis with the following settings - <b><font color=#357EC7>%2</font></b> cm at <b><font color=#357EC7>%3</font></b> V/cm using %4 for ").arg( container1.contents.new_name).arg(length).arg(volt_per_cm).arg(fluid1.new_name));
 time1->display_time();
 qts_write(".<br>");
 name_sample(container1, "separated flow");
 // graph maintenance
 {
  Operation o = new_operation("ce detect");
  create_edge_from_container_to_fluid(&container1, &o);
  create_edge_from_fluids(&fluid1, &o);
  container1.node = create_node("results of capillary electrophoresis");
  create_edge(o.node, container1.node);
  o.node->time = time1->value;
  o.node->unit = time1->unit;
 }
}

void measure_fluorescence (Container& container1)
{
 // graph maintenance
 {
  Operation o = new_operation("measure fluorescence");
  create_edge_from_container_to_fluid(&container1, &o);
  container1.node = create_node("results of fluorescence measurement");
  create_edge(o.node, container1.node);
 }
  qts_write(QString("Measure the fluorescence of %1.<br>").arg( container1.contents.new_name));

}

Column new_column(char*name)
{
 Column result ={0};
 result.name = name;
 qts_write(QString("<li>%1</li>").arg( name));
 result.used = 0;
 usage_list_containers[list_container_no] = result;
 result.usage_index = list_container_no;
 list_container_no++;
 return result;
}

void centrifuge_column(Column& column1, Speed* speed1, r4 temp, Time* time1)
{
 qts_write("Centrifuge "); 
 check_container(column1);
 qts_write(" at ");
 speed1->display_speed();
 qts_write(" for ");
 time1->display_time();
 if(temp==RT);
 else
   qts_write(QString("at <b><font color=#357EC7>%1%2C</font></b>s").arg( temp).arg(0x00B0));
 qts_write(".<br>");
 if(centrifuge_no == 1)
 {
  equipments[equip_no] = "Centrifuge";
  equip_no++;
  centrifuge_no++;
 }
 qts_write("Discard the flow-through.<br>"); 
 column1.volume = 0;
 name_column(column1, "column"); 
 // graph maintenance
 {
  Operation o = new_operation("centrifuge column");
  create_edge_from_container_to_fluid(&column1, &o);
  column1.node = create_node("centrifuged column");
  create_edge(o.node, column1.node);
  o.node->time = time1->value;
  o.node->unit = time1->unit;
  o.node->pcr_or_centrifuge = 1;
 }
}

void centrifuge_column(Column& column1, r4 temp, Time* time1)
{
 qts_write("Microfuge "); 
 check_container(column1);
 qts_write(" for ");
 time1->display_time();
 if(temp==RT);
 else
   qts_write(QString("at <b><font color=#357EC7>%1%2C</font></b>s").arg( temp).arg(0x00B0));
 qts_write(".<br>");
 if(centrifuge_no == 1)
 {
  equipments[equip_no] = "Centrifuge";
  equip_no++;
  centrifuge_no++;
 }
 qts_write("Discard the flow-through.<br>"); 
 column1.volume = 0;
 name_column(column1, "column");
 // graph maintenance
 {
  Operation o = new_operation("centrifuge column");
  create_edge_from_container_to_fluid(&column1, &o);
  column1.node = create_node("centrifuged column");
  create_edge(o.node, column1.node);
  o.node->time = time1->value;
  o.node->unit = time1->unit;
  o.node->pcr_or_centrifuge = 1;
 }
}

void centrifuge_flow_through(Column& column1, Speed* speed1, r4 temp, Time* time1, Container& container1)
{
 qts_write("Centrifuge "); 
 check_container(column1);
 qts_write(" at ");
 speed1->display_speed();
 qts_write(" for ");
 time1->display_time();
 if(temp==RT);
 else
  qts_write(QString("at <b><font color=#357EC7>%1%2C</font></b>s").arg( temp).arg(0x00B0));
 qts_write(".<br>");

 qts_write("Discard the column.<br>");
 if(centrifuge_no == 1)
 {
  equipments[equip_no] = "Centrifuge";
  equip_no++;
  centrifuge_no++;
 }
 container1.contents.new_name = "flow-through";
 container1.volume = column1.volume;
 column1.volume = 0;
 // graph maintenance
 {
  Operation o = new_operation("centrifuge flow through");
  create_edge_from_container_to_fluid(&column1, &o);
  create_edge_from_fluid_to_container(&o, &container1);
  o.node->time = time1->value;
  o.node->unit = time1->unit;
  o.node->pcr_or_centrifuge = 1;
 }
}

void centrifuge_flow_through(Column& column1, r4 temp, Time* time1, Container& container1)
{
 qts_write("Centrifuge "); 
 check_container(column1);
 qts_write(" at ");
 time1->display_time();
 if(temp==RT);
 else
  qts_write(QString("at <b><font color=#357EC7>%1%2C</font></b>s").arg( temp).arg(0x00B0));
 qts_write(".<br>");
 qts_write("Discard the column.<br>");
 if(microfuge_no == 1)
 {
  equipments[equip_no] = "Microfuge";
  equip_no++;
  microfuge_no++;
 }

 container1.contents.new_name = "flow-through";
 container1.volume = column1.volume;
 column1.volume = 0;
 // graph maintenance
 {
  Operation o = new_operation("centrifuge flow through");
  create_edge_from_container_to_fluid(&column1, &o);
  create_edge_from_fluid_to_container(&o, &container1);
  o.node->time = time1->value;
  o.node->unit = time1->unit;
  o.node->pcr_or_centrifuge = 1;
 }
}

void add_to_column(Column& column1, Fluid& fluid1, Volume* volume1)
{
 // graph maintenance
 {
  Operation o = new_operation("add to column");
  create_edge_from_fluids(&fluid1, &o);
  create_edge_from_fluid_to_container(&o, &column1);
 }
  if ((fluid1.volume == 0)|| (fluid1.volume < (volume1->value*volume1->mul)))
  {
   qts_write(QString("<font color = red>Warning: You are measuing out more than the available volume of %1! Please make sure you have enough before carrying on with the protocol.<br></font>").arg( fluid1.new_name));

  }
  if (usage_list_containers[column1.usage_index].name == column1.name)
   usage_list_containers[column1.usage_index].used = 1;
  else 
  {
   column1.used = 1;
   usage_list_containers[list_container_no] = column1;
   column1.usage_index = list_container_no;
   list_container_no++;
  }  
  if (usage_list_fluids[fluid1.usage_index].original_name == fluid1.original_name)
   usage_list_fluids[fluid1.usage_index].used = 1;
  else 
  {
   fluid1.used = 1;
   usage_list_fluids[list_fluid_no] = fluid1;
   fluid1.usage_index = list_fluid_no;
   list_fluid_no++;
  }
  qts_write("Add ");
  volume1->display_vol();
  if(fluid1.state == "")
   qts_write(QString(" of <font color=#357EC7>%1</font> to %1.<br>").arg( fluid1.new_name).arg(column1.name));
  else 
   qts_write(QString(" of <a href=\"#%1\" ><font color=#357EC7>%2</font></a> to %3.<br>").arg( fluid1.new_name).arg(fluid1.new_name).arg(column1.name));
  column1.contents = fluid1;
  column1.volume = column1.volume + volume1->value * volume1->mul;
  fluid1.volume = fluid1.volume - volume1->value * volume1->mul;
}

void add_to_column(Column& column1, Container& container1, Volume* volume1)
{
 // graph maintenance
 {
  Operation o = new_operation("add to column");
  create_edge_from_container_to_fluid(&container1, &o);
  create_edge_from_fluid_to_container(&o, &column1);
 }
  if ((container1.volume == 0)|| (container1.volume < (volume1->value*volume1->mul)))
  {
   qts_write(QString("<font color = red>Warning: You are measuing out more than the available volume of %1! Please make sure you have enough before carrying on with the protocol.<br></font>").arg( container1.contents.new_name));

  }
  if (usage_list_containers[column1.usage_index].name == column1.name)
   usage_list_containers[column1.usage_index].used = 1;
  else 
  {
   column1.used = 1;
   usage_list_containers[list_container_no] = column1;
   column1.usage_index = list_container_no;
   list_container_no++;
  }  
  if (usage_list_containers[container1.usage_index].name == container1.name)
   usage_list_containers[container1.usage_index].used = 1;
  else 
  {
   container1.used = 1;
   usage_list_containers[list_container_no] = container1;
   container1.usage_index = list_container_no;
   list_container_no++;
  }
  qts_write("Add ");
  volume1->display_vol();
  if(container1.contents.state == "")
   qts_write(QString(" of <font color=#357EC7>%1</font> %2.<br>").arg( container1.contents.new_name));
  else
   qts_write(QString(" of <a href=\"#%1\" ><font color=#357EC7>%2</font></a> %3.<br>").arg( container1.contents.new_name).arg(container1.contents.new_name));
  column1.contents = container1.contents;
  column1.volume = column1.volume + volume1->value * volume1->mul;
  container1.volume = container1.volume - volume1->value * volume1->mul;
}

void add_to_column(Column& column1, Container& container1)
{
 // graph maintenance
 {
  Operation o = new_operation("add to column");
  create_edge_from_container_to_fluid(&container1, &o);
  create_edge_from_fluid_to_container(&o, &column1);
 }
  if (usage_list_containers[column1.usage_index].name == column1.name)
   usage_list_containers[column1.usage_index].used = 1;
  else 
  {
   column1.used = 1;
   usage_list_containers[list_container_no] = column1;
   column1.usage_index = list_container_no;
   list_container_no++;
  }  
  if (usage_list_containers[container1.usage_index].name == container1.name)
   usage_list_containers[container1.usage_index].used = 1;
  else 
  {
   container1.used = 1;
   usage_list_containers[list_container_no] = container1;
   container1.usage_index = list_container_no;
   list_container_no++;
  }
  qts_write(QString("Add <font color=#357EC7>%1</font> to %2.<br>").arg( container1.contents.new_name).arg(column1.name));
  column1.contents = container1.contents;
  column1.volume = container1.volume;
  container1.volume = 0;
}

void transfer_column(Column& column1, Container& container1)
{
 // graph maintenance
 {
  Operation o = new_operation("transfer column");
  create_edge_from_container_to_fluid(&column1, &o);
  create_edge_from_fluid_to_container(&o, &container1);
 }
  if (usage_list_containers[column1.usage_index].name == column1.name)
   usage_list_containers[column1.usage_index].used = 1;
  else 
  {
   column1.used = 1;
   usage_list_containers[list_container_no] = column1;
   column1.usage_index = list_container_no;
   list_container_no++;
  }  
  if (usage_list_containers[container1.usage_index].name == container1.name)
   usage_list_containers[container1.usage_index].used = 1;
  else 
  {
   container1.used = 1;
   usage_list_containers[list_container_no] = container1;
   container1.usage_index = list_container_no;
   list_container_no++;
  }
  qts_write(QString("Transfer %1 into %2.<br>").arg( column1.name).arg(container1.name));
}

void vortex_column(Column& column1)
{
 // graph maintenance
 {
  Operation o = new_operation("vortex column");
  create_edge_from_container_to_fluid(&column1, &o);
  column1.node = create_node("vortexed column");
  create_edge(o.node, column1.node);
 }
  qts_write(QString("Vortex %1 gently.<br>").arg(column1.name));
}

void drain(Container& container1)
{
 // graph maintenance
 {
  Operation o = new_operation("drain column");
  create_edge_from_container_to_fluid(&container1, &o);
  container1.node = create_node("drained column");
  create_edge(o.node, container1.node);
 }
  qts_write(QString("Drain %1.<br>").arg( container1.name));
  container1.volume = 0;
}

void wash_cells(Container& chamber, Fluid& sample1)
{
 // graph maintenance
 {
  Operation o = new_operation("wash cells");
  create_edge_from_fluids(&sample1, &o);
  create_edge_from_fluid_to_container(&o, &chamber);
 }
  usage_list_fluids[sample1.usage_index].used = 1;
  usage_list_containers[chamber.usage_index].used = 1;
  qts_write(QString("Wash cells with %1.<br>").arg( sample1.new_name));
}

void collect_tissue(Tissue& sample1, r4 wt,  weight_unit unit, Container& container1)
{
 // graph maintenance
 {
  Operation o = new_operation("collect tissue");
  create_edge_from_fluids(&sample1, &o);
  create_edge_from_fluid_to_container(&o, &container1);
 }
  u4 mul;
  char* wu;
  if (usage_list_fluids[sample1.usage_index].original_name == sample1.original_name)
   usage_list_fluids[sample1.usage_index].used = 1;
  else 
  {
   sample1.used = 1;
   usage_list_fluids[list_fluid_no] = sample1;
   sample1.usage_index = list_fluid_no;
   list_fluid_no++;
  }  
  if (usage_list_containers[container1.usage_index].name == container1.name)
   usage_list_containers[container1.usage_index].used = 1;
  else 
  {
   container1.used = 1;
   usage_list_containers[list_container_no] = container1;
   container1.usage_index = list_container_no;
   list_container_no++;
  }
  switch(unit)
  {
   case UG: wu="mcg";mul = MICRO;break;
   case MG: wu="mg";mul = MICRO; break;
   case GR: wu="g";mul = MICRO;break;
   default: break;
  }
  name_sample(container1, "tissue");
  qts_write(QString("Collect <b><font color=#357EC7>%1 %2</font></b> of %3 in  %4. <br>").arg( wt).arg(wu).arg(sample1.new_name).arg(container1.name));
  container1.contents = sample1;
  container1.volume = wt*mul;
}

void collect_tissue(Tissue& sample1, Container& container1)
{
 // graph maintenance
 {
  Operation o = new_operation("collect tissue");
  create_edge_from_fluids(&sample1, &o);
  create_edge_from_fluid_to_container(&o, &container1);
 }
  if (usage_list_fluids[sample1.usage_index].original_name == sample1.original_name)
   usage_list_fluids[sample1.usage_index].used = 1;
  else 
  {
   sample1.used = 1;
   usage_list_fluids[list_fluid_no] = sample1;
   sample1.usage_index = list_fluid_no;
   list_fluid_no++;
  }
  qts_write(QString("Collect %1 into %2 and snap-freeze in liquid nitrogen.<br>").arg( sample1.new_name).arg(container1.name));
  sample1.volume = DEFAULT;
}

void homogenize_tissue(Container& container1)
{
 // graph maintenance
 {
  Operation o = new_operation("homogenize tissue");
  create_edge_from_container_to_fluid(&container1, &o);
  container1.node = create_node("homogenized tissue");
  create_edge(o.node, container1.node);
 }
  if (usage_list_containers[container1.usage_index].name == container1.name)
   usage_list_containers[container1.usage_index].used = 1;
  else 
  {
   container1.used = 1;
   usage_list_containers[list_container_no] = container1;
   container1.usage_index = list_container_no;
   list_container_no++;
  }
  qts_write("Pre-cool the mortars by pouring liquid nitrogen into them.<br>");
  qts_write(QString("Add %1 into the mortar containing liquid nitrogen and grind with a pestle until it is a fine powder.<br>").arg( container1.contents.new_name));
  comment("Use gloves!");
  if(mortar_no==1)
  {
   equipments[equip_no]="Micropestles/ Mortar and pestle";
   equip_no++;
   mortar_no++;
  }
  name_sample(container1, "homogenized tissue");
}

void homogenize_tissue(Container& container1, Fluid& fluid1)
{
 // graph maintenance
 {
  Operation o = new_operation("homogenize tissue");
  create_edge_from_fluids(&fluid1, &o);
  create_edge_from_container_to_fluid(&container1, &o);
  container1.node = create_node("homogenized tissue");
  create_edge(o.node, container1.node);
 }
  if (usage_list_fluids[fluid1.usage_index].original_name == fluid1.original_name)
   usage_list_fluids[fluid1.usage_index].used = 1;
  else 
  {
   fluid1.used = 1;
   usage_list_fluids[list_fluid_no] = fluid1;
   fluid1.usage_index = list_fluid_no;
   list_fluid_no++;
  }  
  if (usage_list_containers[container1.usage_index].name == container1.name)
   usage_list_containers[container1.usage_index].used = 1;
  else 
  {
   container1.used = 1;
   usage_list_containers[list_container_no] = container1;
   container1.usage_index = list_container_no;
   list_container_no++;
  }
  qts_write(QString("Homogenize %1 in %2.<br>").arg( container1.contents.new_name).arg(fluid1.new_name));
  name_sample(container1, "homogenized tissue");
  container1.volume = fluid1.volume;
  fluid1.volume = 0;
}

void dry_pellet(Container& container1, drying type, Time* time1)
{
 char* additional;
 switch(type)
 {
  case IN_AIR: additional = "in air"; break;
  case IN_VACUUM: additional = "in vacuum"; break;
  default: additional = "in air"; break;
 }
 qts_write(QString("Dry the pellet %1 for ").arg( additional));
 time1->display_time();
 qts_write(".<br>");
 container1.volume = 0;
 // graph maintenance
 {
  Operation o = new_operation("dry pellet");
  create_edge_from_container_to_fluid(&container1, &o);
  container1.node = create_node("container with dried pellet");
  create_edge(o.node, container1.node);
  o.node->time = time1->value;
  o.node->unit = time1->unit;
 }
}

void dry_pellet(Container& container1, drying type)
{
 char* additional;
 // graph maintenance
 {
  Operation o = new_operation("dry pellet");
  create_edge_from_container_to_fluid(&container1, &o);
  container1.node = create_node("container with dried pellet");
  create_edge(o.node, container1.node);
 }
  switch(type)
  {
   case IN_AIR: additional = "in air"; break;
   case IN_VACUUM: additional = "in vacuum"; break;
   default: additional = "in air"; break;
  }
  qts_write(QString("Dry the pellet %1. <br>").arg(additional));
  container1.volume = 0;
}

void mixing_table_pcr(u4 no_rows, Volume* rxn_vol, Fluid array1[], char*initial_conc[], char* final_conc[], Volume* vol[], Container& container1)
{
 u4 i,j;
 u4 flag = 0;
 u4 make_vol_up = 0;
 r4 sum = 0;
 for(i=0; i<no_rows-1;i++)
 {
  if (usage_list_fluids[array1[i].usage_index].original_name == array1[i].original_name)
   usage_list_fluids[array1[i].usage_index].used = 1;
  else 
  {
   array1[i].used = 1;
   usage_list_fluids[list_fluid_no] = array1[i];
   array1[i].usage_index = list_fluid_no;
   list_fluid_no++;
  } 
 }
 if (usage_list_containers[container1.usage_index].name == container1.name)
  usage_list_containers[container1.usage_index].used = 1;
 else 
 {
  container1.used = 1;
  usage_list_containers[list_container_no] = container1;
  container1.usage_index = list_container_no;
  list_container_no++;
 }
 qts_write(QString("Set up a reaction in %1 as follows on ice:<br><br>").arg( container1.name));
 qts_write("<table border cellpadding=5 rules=all frame=void bordercolor=#357EC7>");
 for(i=0;i<no_rows;i++)
 {
  for(j=0;j<4;j++)
  {
   if((i==0)&&(j==0))
   {
    fprintf(fp,"<thead><tr><td>&nbsp;</td>");
   }
   else if((i==0)&&(j!=0))
   {
    if(j==1)
    {
     fprintf(fp,"<td><font color=#357EC7>Initial concentration</font></td>");
    }
    if(j==2)
     fprintf(fp,"<td><font color=#357EC7>Final concentration</font></td>");
    if (j==3)
    {
     fprintf(fp,"<td><font color=#357EC7>Final volume per ");
     rxn_vol->display_vol();
     fprintf(fp," reaction</font></td>");
     fprintf(fp,"</tr></thead>");
    }
   }
   else if((i!=0)&&(j==0))
    qts_write(QString("<tbody><tr><td><font color=#357EC7>%1</font></td>").arg(array1[i-1].new_name));
   else 
   {
    if(j==1)
    {
     qts_write(QString("<td><b><font color=#357EC7>%1</font></b></td>").arg(initial_conc[i-1]));
    }
    if(j==2)
    {
     qts_write(QString("<td><b><font color=#357EC7>%1</font></b></td>").arg(final_conc[i-1]));
    }
    if(j==3)
    {
     if ((i==no_rows-1)&&((vol[i-1]->value==XVAL)||(vol[i-1]->value==NA)))
     {
      make_vol_up = 1;
      fprintf(fp,"<td><b><font color=#357EC7>Make up volume to ");
      rxn_vol->display_vol();
      qts_write("</font></b></td>");
     }
     else if (vol[i-1]->value== XVAL)
     {
      fprintf(fp,"<td><b><font color=#357EC7>X</font></b></td>");
      vol[i-1]->value = DEFAULT;
     }
     else if (vol[i-1]->value== NA)
     {
      fprintf(fp,"<td><b><font color=#357EC7>--</font></b></td>");
      vol[i-1]->value = 0;
     }
     else
     {
      qts_write("<td><b>");
      vol[i-1]->display_vol();
      qts_write("</font></b></td>");
     }
     qts_write("</tr></body>");
    }


   }
  }
 }
 fprintf(fp,"</table>");
 name_sample(container1, "reaction mix");
 container1.volume = 0;
 if (make_vol_up == 1)
 {
  for (j=0; j<no_rows-2;j++)
  {
   if (vol[j]->value == DEFAULT||vol[j]->value < 0)
    break;
   sum = sum + vol[j]->value;
  }
  vol[no_rows-2]->value = rxn_vol->value - sum;
 }
 Operation o = new_operation("mixing table pcr");
 for (i=1; i<no_rows-1;i++)
 {
  if (vol[i]->value == DEFAULT)
   break;
  else
  {
   if ((array1[i].volume == 0)|| (array1[i].volume < (vol[i]->value*vol[i]->mul)))
   {
    qts_write(QString("<font color = red>Warning: You are measuing out more than the available volume of %1! Please make sure you have enough before carrying on with the protocol.<br></font>").arg( array1[i].new_name));

   }
   else if (vol[i]->value < 0)
   {
    qts_write("<font color = red>Warning: Negative volume input.</font><br>");
    break;
   }
   else
   {
    flag++;
    container1.volume = container1.volume + vol[i]->value;
   }
  }
 }
 for(i=0; i<no_rows-1; i++)
 {
  // graph maintenance
  create_edge_from_fluids(&array1[i], &o);
 }
 create_edge_from_fluid_to_container(&o, &container1);
 if (flag == (no_rows-1))
 {
  if (container1.volume > rxn_vol->value)
   qts_write("<font color = red>Warning: The total reaction volume is greater than the required reaction volume.</font><br>");
  else if (container1.volume < rxn_vol->value)
   qts_write("<font color = red>Warning: The total reaction volume is less than the required reaction volume.</font><br>");
 }
 container1.contents.volume = container1.volume;
}

void electrophoresis(u4 no_samples, Container container_array[], r4 agar_conc, Volume* pdt_vol, Volume* loading_buff_vol)
{
 u4 i;
 // graph maintenance
 {
  Operation o = new_operation("electrophoresis");
  for(i=0; i<no_samples; i++)
   create_edge_from_container_to_fluid(&container_array[i], &o);
  container_array[1].node = create_node("results of electrophoresis");
  create_edge(o.node, container_array[1].node);
 }
  qts_write(QString("Perform %1&#37 agarose gel electrophoresis of ").arg(agar_conc));
  if(no_samples == 2)
   qts_write(QString("%1 and %2 (").arg( container_array[0].contents.new_name).arg(container_array[1].contents.new_name));
  else
  {
   for(i=0; i<no_samples;i++)
   {
    if(i=no_samples-1)
     qts_write(QString("%1 (").arg( container_array[i].contents.new_name));        
    else if(i=no_samples-2)
     qts_write(QString("%1 and ").arg( container_array[i].contents.new_name));
    else
     qts_write(QString("%1, ").arg( container_array[i].contents.new_name));
    container_array[i].contents.volume = container_array[i].contents.volume - pdt_vol->value * pdt_vol->mul;
   }       
  }
  pdt_vol->display_vol();
  qts_write(" sample and ");
  loading_buff_vol->display_vol();
  qts_write(" loading buffer), mixed with ethidium bromide and visualize with UV transilluminator to confirm the presence of required product.<br>");
  if(electrophoresis_no==1)
  {
   equipments[equip_no]="Electrophoretic unit";
   equip_no++;
   electrophoresis_no++;
  }
}

void electrophoresis(Container& container1,r4 agar_conc)
{
 // graph maintenance
 {
  Operation o = new_operation("electrophoresis");
  create_edge_from_container_to_fluid(&container1, &o);
  container1.node = create_node("results of electrophoresis");
  create_edge(o.node, container1.node);
 }
  qts_write(QString("Perform %1&#37 agarose gel electrophoresis of appropriate quantity of  %1 mixed with ethidium bromide and visualize with UV transilluminator to confirm the presence of required product.<br>").arg(agar_conc).arg(container1.contents.new_name));
  if(electrophoresis_no==1)
  {
   equipments[equip_no]="Electrophoretic unit";
   equip_no++;
   electrophoresis_no++;
  }
}

void electrophoresis(Container& container1)
{
 // graph maintenance
 {
  Operation o = new_operation("electrophoresis");
  create_edge_from_container_to_fluid(&container1, &o);
  container1.node = create_node("results of electrophoresis");
  create_edge(o.node, container1.node);
 }
  qts_write(QString("Perform agarose gel electrophoresis of appropriate quantity of  %1 mixed with ethidium bromide and visualize with UV transilluminator to confirm the presence of required product.<br>").arg( container1.contents.new_name));
  if(electrophoresis_no==1)
  {
   equipments[equip_no]="Electrophoretic unit";
   equip_no++;
   electrophoresis_no++;
  }
}

void pcr_init_denat(Container& container1, r4 temp, Time* time1)
{
 qts_write("Program a standard thermocycler to run the reaction using the following parameters:<br>");
 qts_write(QString("Initial denaturation<br><ul><li>Denature: <b><font color=#357EC7>%1%2C</font></b>, ").arg( temp).arg(0x00B0));
 time1->display_time();
 qts_write("</li></ul>");
 // graph maintenance
 {
  Operation o = new_operation("pcr init denat");
  create_edge_from_container_to_fluid(&container1, &o);
  container1.node = create_node("container after PCR initial denaturation");
  create_edge(o.node, container1.node);
  o.node->time = time1->value;
  o.node->unit = time1->unit;
  o.node->pcr_or_centrifuge = 1;
 }
}

void pcr_final_ext(Container& sample1, r4 temp_ext, Time* time_ext, r4 temp_halt, Time* time_halt, r4 temp_hold)
{
 qts_write("Termination<ul>");
 qts_write(QString("<li>Elongate: <b><font color=#357EC7>%1%2C</font></b>, ").arg( temp_ext).arg(0x00B0)); 
 time_ext->display_time();
 qts_write( QString("</li><li>Halt reaction: <b><font color=#357EC7>%1%2C</font></b>, ").arg( temp_halt).arg(0x00B0));
 time_halt->display_time();
 qts_write( QString("</li><li>Hold: <b><font color=#357EC7>%1%2C</font></b>, until removed from machine </li></ul>").arg( temp_hold).arg(0x00B0));
 // graph maintenance
 {
  Operation o = new_operation("pcr final ext");
  create_edge_from_container_to_fluid(&sample1, &o);
  sample1.node = create_node("container after PCR final extension");
  create_edge(o.node, sample1.node);
  o.node->time = time_ext->value + time_halt->value;
  o.node->unit = time_ext->unit;
  o.node->pcr_or_centrifuge = 1;
 }
}

void pcr_final_ext(Container& sample1, r4 temp_ext, Time* time_ext, r4 temp_hold)
{
 fprintf(fp,"Termination<ul>");
 qts_write(QString("<li>Elongate: <b><font color=#357EC7>%1%2C</font></b>, ").arg( temp_ext).arg(0x00B0); 
 time_ext->display_time();
 qts_write( QString("</li><li>Hold: <b><font color=#357EC7>%1%2C</font></b>, until removed from machine </li></ul>").arg( temp_hold).arg(0x00B0));
 // graph maintenance
 {
  Operation o = new_operation("pcr final ext");
  create_edge_from_container_to_fluid(&sample1, &o);
  sample1.node = create_node("container after PCR final extension");
  create_edge(o.node, sample1.node);
  o.node->time = time_ext->value;
  o.node->unit = time_ext->unit;
  o.node->pcr_or_centrifuge = 1;
 }
}

void centrifuge_phases_bottom(Container& container1, Speed* speed1, r4 temp, Time* time1, Volume* aspirate_vol, Volume* leave_behind)
{
 qts_write("Centrifuge "); 
 check_container(container1);
 qts_write(" at ");
 speed1->display_speed();
 qts_write(" for ");
 time1->display_time();
 qts_write(" and gently aspirate out ");
 aspirate_vol->display_vol();
 qts_write(" of the supernatant and discard it.<br>Leave behind ");
 leave_behind->display_vol();
 qts_write(".<br>");

 name_sample(container1, "remaining portion");
 container1.volume = leave_behind->value;
 // graph maintenance
 {
  Operation o = new_operation("centrifuge phases -- bottom");
  create_edge_from_container_to_fluid(&container1, &o);
  container1.node = create_node("container with bottom layer");
  create_edge(o.node, container1.node);
  o.node->time = time1->value;
  o.node->unit = time1->unit;
  o.node->pcr_or_centrifuge = 1;
 }
}

void patch(Plate& plate1,Plate& colony)
{
 // graph maintenance
 {
  Operation o = new_operation("patch");
  create_edge_from_fluids(&colony, &o);
  create_edge_from_fluids(&o, &plate1);
 }
  if (usage_list_fluids[plate1.usage_index].original_name == plate1.original_name)
   usage_list_fluids[plate1.usage_index].used = 1;
  else 
  {
   plate1.used = 1;
   usage_list_fluids[list_fluid_no] = plate1;
   plate1.usage_index = list_fluid_no;
   list_fluid_no++;
  }  
  if (usage_list_fluids[colony.usage_index].original_name == colony.original_name)
   usage_list_fluids[colony.usage_index].used = 1;
  else 
  {
   colony.used = 1;
   usage_list_fluids[list_fluid_no] = colony;
   colony.usage_index = list_fluid_no;
   list_fluid_no++;
  }
  qts_write(QString("Patch <font color=#357EC7>%1</font> onto %2.<br>").arg( colony.new_name).arg(plate1.new_name));
}

void incubate_plate(Plate& plate1, r4 temp, Time* time1)
{
 if (usage_list_fluids[plate1.usage_index].original_name == plate1.original_name)
  usage_list_fluids[plate1.usage_index].used = 1;
 else 
 {
  plate1.used = 1;
  usage_list_fluids[list_fluid_no] = plate1;
  plate1.usage_index = list_fluid_no;
  list_fluid_no++;
 }
 if(temp == RT)
  qts_write( QString("Incubate %1 at <b><font color=#357EC7><b><font color=#357EC7>room temperature</font></b></font></b> for ").arg( plate1.new_name));
 else if((temp == ON_ICE)||(temp == 0))
  qts_write( QString("Incubate %1 on <b><font color=#357EC7><b><font color=#357EC7>ice</font></b></font></b> for ").arg( plate1.new_name));
 else
  qts_write( QString("Incubate %1 at <b><font color=#357EC7>%2%3C</font></b> for ").arg( plate1.new_name).arg(temp).arg(0x00B0));
 time1->display_time();
 qts_write(".<br>");
 if(incubator_no == 1)
 {
  equipments[equip_no] = "Incubator";
  equip_no++;
  incubator_no++;
 }
 // graph maintenance
 {
  Operation o = new_operation("incubate plate");
  create_edge_from_fluids(&plate1, &o);
  plate1.node = create_node("incubated plate");
  create_edge(o.node, plate1.node);
  o.node->time = time1->value;
  o.node->unit = time1->unit;
 }
}

void sequencing(Container& container1)
{
 // graph maintenance
 {
  Operation o = new_operation("sequencing");
  create_edge_from_container_to_fluid(&container1, &o);
  container1.node = create_node("results of sequencing");
  create_edge(o.node, container1.node);
 }
  qts_write(QString("Dilute %1 to <font color=#357EC7>100ng/ mcL</font> and send <font color=#357EC7>1 mcg (10 mcL)</font> for sequencing.<br>").arg( container1.contents.new_name));
}

void weigh(Container& container1)
{
 // graph maintenance
 {
  Operation o = new_operation("weigh");
  create_edge_from_container_to_fluid(&container1, &o);
  container1.node = create_node("results of weighing");
  create_edge(o.node, container1.node);
 }
  qts_write( QString("Weigh the amount of %1 present.<br>").arg( container1.contents.new_name));
} 

void thermocycler_anneal(Container& container1, r4 cool_to_temp, r4 gradient, Time* time1)
{
 if (cool_to_temp==RT)
   qts_write( QString("Cool %1 to room temperature at the rate of <b><font color=#357EC7>%2%3C</font></b> every ").arg( container1.contents.new_name, gradient, 0x00B0));
 else
   qts_write( QString("Cool %1 to <b><font color=#357EC7>%2%3C</font></b> at the rate of <b><font color=#357EC7>%4%5C</font></b> every ").arg( container1.contents.new_name).arg(cool_to_temp).arg(0x00B0).arg(gradient).arg(0x00B0));
 time1->display_time();
 qts_write(".<br>");
 // graph maintenance
 {
  Operation o = new_operation("thermocycler anneal");
  create_edge_from_container_to_fluid(&container1, &o);
  container1.node = create_node("container after products have annealed");
  create_edge(o.node, container1.node);
  o.node->time = time1->value;
  o.node->unit = time1->unit;
 }
}

Slide new_slide(char* name)
{
 Slide result ={0};
 result.name = name;
 result.used = 0;
 usage_list_containers[list_container_no] = result;
 result.usage_index = list_container_no;
 list_container_no++;
 return result;
}

void immerse_slide(Slide& slide1,Fluid& sample1, Time* time1,  func function, u4 no_of_times)
{
 char* noft;
 u4 ttr1 = total_time_required;
 u4 ttr2;
 if (usage_list_fluids[sample1.usage_index].original_name == sample1.original_name)
  usage_list_fluids[sample1.usage_index].used = 1;
 else 
 {
  sample1.used = 1;
  usage_list_fluids[list_fluid_no] = sample1;
  sample1.usage_index = list_fluid_no;
  list_fluid_no++;
 }  
 if (usage_list_containers[slide1.usage_index].name == slide1.name)
  usage_list_containers[slide1.usage_index].used = 1;
 else 
 {
  slide1.used = 1;
  usage_list_containers[list_container_no] = slide1;
  slide1.usage_index = list_container_no;
  list_container_no++;
 }
 switch(no_of_times)
 {
  case 1: noft = "";
   break;
  case 2: noft = "twice";
   break;
  case 3: noft = "thrice";
   break;
  case 4: noft = "four times";
   break;
  case 5: noft = "five times";
   break;
  default: noft = "";
   break;
 }

 if (sample1.state == "")
 {
  switch(function)
  {
  case DEWAX: 
   qts_write(QString("Dewax %1 in <b><font color=#357EC7>%2</font></b> for ").arg(slide1.name).arg(sample1.new_name));
   break;
  default:
   break;
  }
 }
 else
 {
  switch(function)
  {
  case DEWAX: 
   qts_write(QString("Dewax %1 in <a href=\"#%2\" >%3</a> for ").arg(slide1.name).arg(sample1.new_name).arg(sample1.new_name));
   break;
  default:
   break;
  }
 }
 time1->display_time();
 qts_write(QString(" %1.<br>").arg(noft));
 ttr2 = total_time_required-ttr1;
 total_time_required = total_time_required + ttr2 * no_of_times;
 // graph maintenance
 {
  Operation o = new_operation("immerse slide");
  create_edge_from_container_to_fluid(&slide1, &o);
  create_edge_from_fluids(&sample1, &o);
  slide1.node = create_node("slide immersed");
  create_edge(o.node, slide1.node);
  o.node->time = time1->value * no_of_times;
  o.node->unit = time1->unit;
 }
}

void immerse_slide(Slide& slide1, Fluid& sample1, Time* time1, u4 no_of_times)
{
 QString noft;
 u4 ttr1 = total_time_required;
 u4 ttr2;
 if (usage_list_fluids[sample1.usage_index].original_name == sample1.original_name)
  usage_list_fluids[sample1.usage_index].used = 1;
 else 
 {
  sample1.used = 1;
  usage_list_fluids[list_fluid_no] = sample1;
  sample1.usage_index = list_fluid_no;
  list_fluid_no++;
 }  
 if (usage_list_containers[slide1.usage_index].name == slide1.name)
  usage_list_containers[slide1.usage_index].used = 1;
 else 
 {
  slide1.used = 1;
  usage_list_containers[list_container_no] = slide1;
  slide1.usage_index = list_container_no;
  list_container_no++;
 }
 switch(no_of_times)
 {
 case 1: noft = "";
  break;
 case 2: noft = "twice";
  break;
 case 3: noft = "thrice";
  break;
 case 4: noft = "four times";
  break;
 case 5: noft = "five times";
  break;
 default: noft = "";
  break;
 }

 if(sample1.state == "")
  qts_write(QString( QString("Immerse %1 in <b><font color=#357EC7>%2</font></b> for ").arg( slide1.name).arg(sample1.new_name));
 else 
  qts_write(QString( QString("Immerse %1 in <a href=\"#%2\" >%3</a> for ").arg( slide1.name).arg(sample1.new_name).arg(sample1.new_name));
 time1->display_time();
 qts_write(QString( QString(" %1.<br>").arg( noft));
 ttr2 = total_time_required-ttr1;
 total_time_required = total_time_required + ttr2 * no_of_times;
 // graph maintenance
 {
  Operation o = new_operation("immerse slide");
  create_edge_from_container_to_fluid(&slide1, &o);
  create_edge_from_fluids(&sample1, &o);
  slide1.node = create_node("slide immersed");
  create_edge(o.node, slide1.node);
  o.node->time = time1->value * no_of_times;
  o.node->unit = time1->unit;
 }
}

void immerse_slide(Slide& slide1,Fluid& sample1, u4 no_of_times)
{
 // graph maintenance
 {
  Operation o = new_operation("immerse slide");
  create_edge_from_container_to_fluid(&slide1, &o);
  create_edge_from_fluids(&sample1, &o);
  slide1.node = create_node("slide immersed");
  create_edge(o.node, slide1.node);
 }
  char* noft;
  u4 ttr1 = total_time_required;
  u4 ttr2;
  if (usage_list_fluids[sample1.usage_index].original_name == sample1.original_name)
   usage_list_fluids[sample1.usage_index].used = 1;
  else 
  {
   sample1.used = 1;
   usage_list_fluids[list_fluid_no] = sample1;
   sample1.usage_index = list_fluid_no;
   list_fluid_no++;
  }  
  if (usage_list_containers[slide1.usage_index].name == slide1.name)
   usage_list_containers[slide1.usage_index].used = 1;
  else 
  {
   slide1.used = 1;
   usage_list_containers[list_container_no] = slide1;
   slide1.usage_index = list_container_no;
   list_container_no++;
  }
  switch(no_of_times)
  {
  case 1: noft = "";
   break;
  case 2: noft = "twice";
   break;
  case 3: noft = "thrice";
   break;
  case 4: noft = "four times";
   break;
  case 5: noft = "five times";
   break;
  default: noft = "";
   break;
  }

  if((sample1.state == "")&&(no_of_times == 1))
    qts_write(QString( QString("Immerse %1 in %2.<br>").arg( slide1.name).arg(sample1.new_name));
  else if((sample1.state == "")&&(no_of_times > 1))
    qts_write(QString( QString("Immerse %1 in %2 %3.<br>").arg( slide1.name).arg(sample1.new_name).arg(noft));
  else if (no_of_times > 1)
    qts_write(QString( QString("Immerse %1 in <a href=\"#%2\" >%3</a> %4.<br>").arg( slide1.name).arg(sample1.new_name).arg(sample1.new_name).arg(noft));
  else 
    qts_write(QString( QString("Immerse %1 in <a href=\"#%2\" >%3</a>.<br>").arg( slide1.name).arg(sample1.new_name).arg(sample1.new_name));
  ttr2 = total_time_required-ttr1;
  total_time_required = total_time_required + ttr2 * no_of_times;
}

void remove_slide(Slide& slide1, Fluid& sample1)
{
 // graph maintenance
 {
  Operation o = new_operation("remove slide");
  create_edge_from_container_to_fluid(&slide1, &o);
  create_edge_from_fluids(&sample1, &o);
  slide1.node = create_node("slide removed");
  create_edge(o.node, slide1.node);
 }
  qts_write(QString("Take out %1 from %2.<br>").arg( slide1.name).arg(sample1.new_name));
}

void wash_tissue(Tissue& tissue1, Fluid& sample1,  wash_type type, r4 temp, u4 shaking)
{
 // graph maintenance
 {
  Operation o = new_operation("wash tissue");
  create_edge_from_fluids(&tissue1, &o);
  create_edge_from_fluids(&sample1, &o);
  tissue1.node = create_node("tissue washed");
  create_edge(o.node, tissue1.node);
 }
  AString shake_type;
  if (usage_list_fluids[sample1.usage_index].original_name == sample1.original_name)
   usage_list_fluids[sample1.usage_index].used = 1;
  else 
  {
   sample1.used = 1;
   usage_list_fluids[list_fluid_no] = sample1;
   sample1.usage_index = list_fluid_no;
   list_fluid_no++;
  }  
  if (usage_list_fluids[tissue1.usage_index].original_name == tissue1.original_name)
   usage_list_fluids[tissue1.usage_index].used = 1;
  else 
  {
   tissue1.used = 1;
   usage_list_fluids[list_fluid_no] = tissue1;
   tissue1.usage_index = list_fluid_no;
   list_fluid_no++;
  }
  switch(shaking)
  {
   case 0: shake_type = " without shaking";break;
   case 1: shake_type = " with shaking";break;
   default: shake_type = "";break;
  }
  if(sample1.state == "")
  {
   switch(type)
   {
    case WASHING:qts_write(QString("Wash %1 in <font color=#357EC7>%2</font>").arg( tissue1.new_name).arg(sample1.new_name));break;
    case RINSING:qts_write(QString("Rinse %1 in <font color=#357EC7>%2</font>").arg( tissue1.new_name).arg(sample1.new_name));break;
    default:qts_write(QString("Wash %1 in <font color=#357EC7>%2</font>").arg( tissue1.new_name).arg(sample1.new_name));break;
   }
  }
  else
  {
   switch(type)
   {
    case WASHING:qts_write(QString("Wash %1 in <a href=\"#%2\" >%3</a>").arg( tissue1.new_name).arg(sample1.new_name).arg(sample1.new_name));break;
    case RINSING:qts_write(QString("Rinse %1 in <a href=\"#%2\" >%3</a>").arg( tissue1.new_name).arg(sample1.new_name).arg(sample1.new_name));break;
    default:qts_write(QString("   Wash %1 in <a href=\"#%2\" >%3</a>").arg( tissue1.new_name).arg(sample1.new_name).arg(sample1.new_name));break;
   }
  }
  if (temp == RT)
   qts_write(QString(" at <b><font color=#357EC7>room temperature</font></b>%1.<br>").arg( shake_type));
  else
   qts_write(QString(" at <b><font color=#357EC7>%1%2C</font></b>%3.<br>").arg( temp).arg(0x00B0).arg(shake_type));
  if(shaking == 1)
  {
   if(shaker_no == 1)
   {
    equipments[equip_no]="Shaker";
    equip_no++;
    shaker_no++;
   }
  }
}

void wash_tissue(Tissue& tissue1, Fluid& sample1,  wash_type type, Time* time1, u4 no_of_times, r4 temp, u4 shaking)
{
 char *noft, *shake_type;
 u4 ttr1 = total_time_required;
 u4 ttr2;
 if (usage_list_fluids[sample1.usage_index].original_name == sample1.original_name)
  usage_list_fluids[sample1.usage_index].used = 1;
 else 
 {
  sample1.used = 1;
  usage_list_fluids[list_fluid_no] = sample1;
  sample1.usage_index = list_fluid_no;
  list_fluid_no++;
 }  
 if (usage_list_fluids[tissue1.usage_index].original_name == tissue1.original_name)
  usage_list_fluids[tissue1.usage_index].used = 1;
 else 
 {
  tissue1.used = 1;
  usage_list_fluids[list_fluid_no] = tissue1;
  tissue1.usage_index = list_fluid_no;
  list_fluid_no++;
 }
 switch(no_of_times)
 {
  case 1: noft="";break;
  case 2: noft="twice";break;
  case 3: noft="thrice";break;
  case 4: noft="four times";break;
  case 5: noft="five times";break;
  default: noft="";break;
 }

 switch(shaking)
 {
  case 0: shake_type = " without shaking";break;
  case 1: shake_type = " with shaking";break;
  default: shake_type = "";break;
 }
 if(sample1.state == "")
 {
  if (no_of_times == 1)
  {
   switch(type)
   {
   case WASHING:
    qts_write(QString("Wash %1 in <font color=#357EC7>%2</font> for ").arg( tissue1.new_name).arg(sample1.new_name));
    break;
   case RINSING:
    qts_write(QString("Rinse %1 in <font color=#357EC7>%2</font> for ").arg( tissue1.new_name).arg(sample1.new_name));
    break;
   default:
    break;
   }
   time1->display_time();
   if (temp == RT)
    qts_write(QString(" at <b><font color=#357EC7>room temperature</font></b>%1.<br>").arg( shake_type));
   else 
    qts_write(QString(" at <b><font color=#357EC7>%1%2C</font></b>%3.<br>").arg( temp).arg(0x00B0).arg(shake_type));
  }
  else
  {
   switch(type)
   {
    case WASHING:qts_write(QString("Wash %1 in <font color=#357EC7>%2</font>, <b><font color=#357EC7>%3</font></b> for ").arg( tissue1.new_name).arg(sample1.new_name).arg(noft));break;
    case RINSING:qts_write(QString("Rinse %1 in <font color=#357EC7>%2</font>, <b><font color=#357EC7>%3</font></b> for ").arg( tissue1.new_name).arg(sample1.new_name).arg(noft));break;
    default:break;
   }
   time1->display_time();
   if (temp == RT)
    qts_write(QString(" each at <b><font color=#357EC7>room temperature</font></b>%1.<br>").arg( shake_type));
   else
    qts_write(QString(" each at <b><font color=#357EC7>%1%2C</font></b>%3.<br>").arg( temp).arg(0x00B0).arg(shake_type));
  }
 }
 else 
 {
  if (no_of_times == 1)
  {
   switch(type)
   {
   case WASHING:
     qts_write(QString("Wash %1 in <a href=\"#%2\" >%3</a> for ").arg( tissue1.new_name).arg(sample1.new_name).arg(sample1.new_name));break;
    case RINSING:qts_write(QString("Rinse %1 in <a href=\"#%2\" >%3</a> for ").arg( tissue1.new_name).arg(sample1.new_name).arg(sample1.new_name));break;
    default:break;
   }
   time1->display_time();
   if (temp == RT)
    qts_write(QString(" at <b><font color=#357EC7>room temperature</font></b>%1.<br>").arg( shake_type));
   else
    qts_write(QString(" at <b><font color=#357EC7>%1%2C</font></b>%3.<br>").arg( temp).arg(0x00B0).arg(shake_type));
  }
  else
  {
   switch(type)
   {
    case WASHING:qts_write(QString("Wash %1 in <a href=\"#%2\" >%3</a>, <b><font color=#357EC7>%4</font></b> for ").arg(tissue1.new_name).arg(sample1.new_name).arg(sample1.new_name).arg(noft));break;
    case RINSING:qts_write(QString("Rinse %1 in <a href=\"#%2\" >%3</a>, <b><font color=#357EC7>%4</font></b> for ").arg(tissue1.new_name).arg(sample1.new_name).arg(sample1.new_name).arg(noft));break;
    default:break;
   }
   time1->display_time();
   if (temp == RT)
    qts_write(QString(" each at <b><font color=#357EC7>room temperature</font></b>%1.<br>").arg( shake_type));
   else
    qts_write(QString(" each at <b><font color=#357EC7>%1%2C</font></b>%3.<br>").arg( temp).arg(0x00B0).arg(shake_type));
  }
 }
 if(shaking == 1)
 {
  if(shaker_no==1)
  {
   equipments[equip_no]="Shaker";
   equip_no++;
   shaker_no++;
  }
 }
 ttr2 = total_time_required-ttr1;
 total_time_required = total_time_required + ttr2 * no_of_times;
 // graph maintenance
 {
  Operation o = new_operation("wash tissue");
  create_edge_from_fluids(&tissue1, &o);
  create_edge_from_fluids(&sample1, &o);
  tissue1.node = create_node("tissue washed");
  create_edge(o.node, tissue1.node);
  o.node->time = time1->value * no_of_times;
  o.node->unit = time1->unit;
 }
}

void immerse_slide_and_incubate(Slide& slide1, Fluid& sample1, r4 temp, Time* time1)
{
 if (usage_list_fluids[sample1.usage_index].original_name == sample1.original_name)
  usage_list_fluids[sample1.usage_index].used = 1;
 else 
 {
  sample1.used = 1;
  usage_list_fluids[list_fluid_no] = sample1;
  sample1.usage_index = list_fluid_no;
  list_fluid_no++;
 }  
 if (usage_list_containers[slide1.usage_index].name == slide1.name)
  usage_list_containers[slide1.usage_index].used = 1;
 else 
 {
  slide1.used = 1;
  usage_list_containers[list_container_no] = slide1;
  slide1.usage_index = list_container_no;
  list_container_no++;
 }
 qts_write(QString("Incubate %1 for ").arg( slide1.name));
 time1->display_time();
 if(sample1.state == "")
 {
  if(temp==RT)
   qts_write(QString(" in <b><font color=#357EC7>%1</font></b> at <b><font color=#357EC7>room temperature</font></b>.<br>").arg( sample1.new_name));
  else
   qts_write(QString(" in <b><font color=#357EC7>%1</font></b> at <b><font color=#357EC7>%2%3C</font></b>.<br>").arg( sample1.new_name).arg(temp).arg(0x00B0));
 }
 else
 {
  if(temp==RT)
   qts_write(QString(" in <a href=\"#%1\" >%2</a> at <b><font color=#357EC7>room temperature</font></b>.<br>").arg( sample1.new_name).arg(sample1.new_name));
  else
   qts_write(QString(" in <a href=\"#%1\" >%2</a> at <b><font color=#357EC7>%3%4C</font></b>.<br>").arg( sample1.new_name).arg(sample1.new_name).arg(temp).arg(0x00B0));
 }
 // graph maintenance
 {
  Operation o = new_operation("immerse slide and incubate");
  create_edge_from_container_to_fluid(&slide1, &o);
  create_edge_from_fluids(&sample1, &o);
  slide1.node = create_node("slide immersed and incubated");
  create_edge(o.node, slide1.node);
  o.node->time = time1->value;
  o.node->unit = time1->unit;
 }
}

void immerse_slide_and_incubate(Slide& slide1, Fluid& sample1, r4 temp, Time* time1,  container_type type)
{
 if (usage_list_fluids[sample1.usage_index].original_name == sample1.original_name)
 usage_list_fluids[sample1.usage_index].used = 1;
 else 
 {
  sample1.used = 1;
  usage_list_fluids[list_fluid_no] = sample1;
  sample1.usage_index = list_fluid_no;
  list_fluid_no++;
 }  
 if (usage_list_containers[slide1.usage_index].name == slide1.name)
  usage_list_containers[slide1.usage_index].used = 1;
 else 
 {
  slide1.used = 1;
  usage_list_containers[list_container_no] = slide1;
  slide1.usage_index = list_container_no;
  list_container_no++;
 }
 switch(type){
  case 5:
   qts_write(QString("Incubate %1 for ").arg( slide1.name));
   time1->display_time();
   if(sample1.new_name == "")
   {
    if(type == HUMIDIFIED_CHAMBER)
     qts_write(QString(" in <b><font color=#357EC7>%1</font></b> at <b><font color=#357EC7>room temperature</font></b> in humidified chamber.<br>").arg( sample1.new_name));
   }
   else
   {
    if(type == HUMIDIFIED_CHAMBER)
     qts_write(QString(" in <a href=\"#%1\" >%2</a> at <b><font color=#357EC7>room temperature</font></b> in humidified chamber.<br>").arg( sample1.new_name).arg(sample1.new_name));
   }
   break;
  default:break;
 }
 // graph maintenance
 {
  Operation o = new_operation("immerse slide");
  create_edge_from_container_to_fluid(&slide1, &o);
  create_edge_from_fluids(&sample1, &o);
  slide1.node = create_node("slide immersed and incubated");
  create_edge(o.node, slide1.node);
  o.node->time = time1->value;
  o.node->unit = time1->unit;
 }
}

void add_to_slide(Slide& slide1, Fluid& sample1, Volume* volume1)
{
 // graph maintenance
 {
  Operation o = new_operation("add to slide");
  create_edge_from_fluids(&sample1, &o);
  create_edge_from_fluid_to_container(&o, &slide1);
 }
  if ((sample1.volume == 0)|| (sample1.volume < (volume1->value*volume1->mul)))
  {
   qts_write(QString("<font color = red>Warning: You are measuing out more than the available volume of %1! Please make sure you have enough before carrying on with the protocol.<br></font>").arg( sample1.new_name));

  }
  if (usage_list_fluids[sample1.usage_index].original_name == sample1.original_name)
   usage_list_fluids[sample1.usage_index].used = 1;
  else 
  {
   sample1.used = 1;
   usage_list_fluids[list_fluid_no] = sample1;
   sample1.usage_index = list_fluid_no;
   list_fluid_no++;
  }  
  if (usage_list_containers[slide1.usage_index].name == slide1.name)
   usage_list_containers[slide1.usage_index].used = 1;
  else 
  {
   slide1.used = 1;
   usage_list_containers[list_container_no] = slide1;
   slide1.usage_index = list_container_no;
   list_container_no++;
  }
  if(sample1.state == "")
  {
   qts_write("Add ");
   volume1->display_vol();
   qts_write(QString(" of <b><font color=#357EC7>%1</font></b> to each of the %2.<br>").arg( sample1.new_name).arg(slide1.name));
  }
  else
  {
   qts_write("Add ");
   volume1->display_vol();
   qts_write(QString(" of <a href=\"#%1\" >%2</a> to each of the %3.<br>").arg( sample1.new_name).arg(sample1.new_name).arg(slide1.name));
  }
}

void dry_slide(Slide& slide1)
{
 // graph maintenance
 {
  Operation o = new_operation("dry slide");
  create_edge_from_container_to_fluid(&slide1, &o);
  slide1.node = create_node("dried slide");
  create_edge(o.node, slide1.node);
 }
  qts_write(QString("Dry %1.<br>").arg( slide1.name));
}

void mount_observe_slide(Slide& slide1, Fluid& fluid1, char* device)
{
 // graph maintenance
 {
  Operation o = new_operation("mount observe slide");
  create_edge_from_container_to_fluid(&slide1, &o);
  create_edge_from_fluids(&fluid1, &o);
  slide1.node = create_node("results of observing slide");
  create_edge(o.node, slide1.node);
 }
  if (usage_list_fluids[fluid1.usage_index].original_name == fluid1.original_name)
   usage_list_fluids[fluid1.usage_index].used = 1;
  else 
  {
   fluid1.used = 1;
   usage_list_fluids[list_fluid_no] = fluid1;
   fluid1.usage_index = list_fluid_no;
   list_fluid_no++;
  }  
  qts_write(QString("Mount %1 with <b><font color=#357EC7>%2</font></b>, let it solidify and view under %3.<br>").arg( slide1.name).arg(fluid1.new_name).arg(device));
}

void facs(Container& container1)
{
 // graph maintenance
 {
  Operation o = new_operation("facs");
  create_edge_from_container_to_fluid(&container1, &o);
  container1.node = create_node("results of facs");
  create_edge(o.node, container1.node);
 }
  qts_write(QString("FACS: sort %1 based on fluorescence.").arg( container1.contents.new_name));
}

void cell_culture(Container& cells,Fluid& medium, u4 centri_speed, r4 temp, r4 time, r4 percent_CO2, Fluid& for_wash_valves, Fluid& for_wash_chambers, Fluid& for_trypsinization, r4 for_feeding)
{
 // graph maintenance
 {
  Operation o = new_operation("cell culture");
  create_edge_from_container_to_fluid(&cells, &o);
  cells.node = create_node("cultured cell");
  create_edge(o.node, cells.node);
 }
  fprintf(fp,"Perform cell culture with the specified parameters.");
}

void transfection(Container& container1, Fluid& medium, Fluid& dna)
{
 // graph maintenance
 {
  Operation o = new_operation("transfection");
  create_edge_from_container_to_fluid(&container1, &o);
  create_edge_from_fluids(&medium, &o);
  create_edge_from_fluids(&dna, &o);
  container1.node = create_node("transfected cell");
  create_edge(o.node, container1.node);
 }
  qts_write(QString("Transfect %1 with %2.").arg( container1.contents.new_name).arg(dna.new_name));
}

void electroporate (Container& container1, r4 voltage, u4 no_pulses)
{
 // graph maintenance
 {
  Operation o = new_operation("electroporate");
  create_edge_from_container_to_fluid(&container1, &o);
  container1.node = create_node("container with contents electroporated");
  create_edge(o.node, container1.node);
 }
  qts_write(QString("Set the electroporator to deliver <b><font color=#357EC7>%1 V</font></b>, and then press the PULSE button <b><font color=#357EC7>%2</font></b> times. <br>").arg( voltage).arg(no_pulses));
  if(electro_no==1)
  {
   equipments[equip_no]="Electroporator";
   equip_no++;
   electro_no++;
  }
}

void store_plate(Plate& plate1, r4 temp)
{
 // graph maintenance
 {
  Operation o = new_operation("store plate");
  create_edge_from_fluids(&plate1, &o);
  plate1.node = create_node("plate incubated");
  create_edge(o.node, plate1.node);
 }
  if (usage_list_fluids[plate1.usage_index].original_name == plate1.original_name)
   usage_list_fluids[plate1.usage_index].used = 1;
  else 
  {
   plate1.used = 1;
   usage_list_fluids[list_fluid_no] = plate1;
   plate1.usage_index = list_fluid_no;
   list_fluid_no++;
  }
  qts_write(QString("Store %1 at <b><font color=#357EC7>%2%3C</font></b>.<br>").arg( plate1.new_name).arg(temp).arg(0x00B0));
}

void wash_slide(Slide& slide1, Fluid& sample1,  wash_type type)
{
 if (usage_list_fluids[sample1.usage_index].original_name == sample1.original_name)
 usage_list_fluids[sample1.usage_index].used = 1;
 else 
 {
  sample1.used = 1;
  usage_list_fluids[list_fluid_no] = sample1;
  sample1.usage_index = list_fluid_no;
  list_fluid_no++;
 }  
 if (usage_list_containers[slide1.usage_index].name == slide1.name)
  usage_list_containers[slide1.usage_index].used = 1;
 else 
 {
  slide1.used = 1;
  usage_list_containers[list_container_no] = slide1;
  slide1.usage_index = list_container_no;
  list_container_no++;
 }
 if(sample1.state == "")
 {
  switch(type)
  {
   case WASHING:qts_write(QString("Wash %1 in <b><font color=#357EC7>%2</font></b>.<br>").arg( slide1.name).arg(sample1.new_name));break;
   case RINSING:qts_write(QString("Rinse %1 in <b><font color=#357EC7>%2</font></b>.<br>").arg( slide1.name).arg(sample1.new_name));break;
   default:qts_write(QString("Wash %1 in <b><font color=#357EC7>%2</font></b>.<br>").arg( slide1.name).arg(sample1.new_name));break;
  }
 }
 else
 {
  switch(type)
  {
   case WASHING:qts_write(QString("Wash %1 in <a href=\"#%2\" >%3</a>.<br>").arg( slide1.name).arg(sample1.new_name).arg(sample1.new_name));break;
   case RINSING:qts_write(QString("Rinse %1 in <a href=\"#%2\" >%3</a>.<br>").arg( slide1.name).arg(sample1.new_name).arg( sample1.new_name));break;
   default:qts_write(QString("   Wash %1 in <a href=\"#%2\" >%3</a>.<br>").arg( slide1.name).arg(sample1.new_name).arg(sample1.new_name));break;
  }
 }
}

void wash_slide(Slide& slide1, Fluid& sample1,  wash_type type, Time* time1, u4 no_of_times)
{
 char *noft;
 u4 ttr1 = total_time_required;
 u4 ttr2;
 if (usage_list_fluids[sample1.usage_index].original_name == sample1.original_name)
  usage_list_fluids[sample1.usage_index].used = 1;
 else 
 {
  sample1.used = 1;
  usage_list_fluids[list_fluid_no] = sample1;
  sample1.usage_index = list_fluid_no;
  list_fluid_no++;
 }  
 if (usage_list_containers[slide1.usage_index].name == slide1.name)
  usage_list_containers[slide1.usage_index].used = 1;
 else 
 {
  slide1.used = 1;
  usage_list_containers[list_container_no] = slide1;
  slide1.usage_index = list_container_no;
  list_container_no++;
 }
 switch(no_of_times)
 {
  case 1: noft="";break;
  case 2: noft="twice";break;
  case 3: noft="thrice";break;
  case 4: noft="four times";break;
  case 5: noft="five times";break;
  default: noft="";break;
 }
 if(sample1.state == "")
 {
  if (no_of_times == 1)
  {
   switch(type)
   {
    case WASHING:qts_write(QString("Wash %1 in <font color=#357EC7>%2</font> for ").arg( slide1.name).arg(sample1.new_name));break;
    case RINSING:qts_write(QString("Rinse %1 in <font color=#357EC7>%2</font> for ").arg( slide1.name).arg(sample1.new_name));break;
    default:break;
   }
   time1->display_time();
   qts_write(".<br>");
  }
  else
  {
   switch(type)
   {
    case WASHING:qts_write(QString("Wash %1 in <font color=#357EC7>%2</font>, <b><font color=#357EC7>%3</font></b> for ").arg( slide1.name).arg(sample1.new_name).arg(noft));break;
    case RINSING:qts_write(QString("Rinse %1 in <font color=#357EC7>%2</font>, <b><font color=#357EC7>%3</font></b> for ").arg( slide1.name).arg(sample1.new_name).arg(noft));break;
    default:break;
   }
   time1->display_time();
   qts_write(" each.<br>");
  }
 }
 else 
 {
  if (no_of_times == 1)
  {
   switch(type)
   {
    case WASHING:qts_write(QString("Wash %1 in <a href=\"#%2\" >%3</a> for ").arg( slide1.name).arg(sample1.new_name).arg(sample1.new_name));break;
    case RINSING:qts_write(QString("Rinse %1 in <a href=\"#%2\" >%3</a> for ").arg( slide1.name).arg(sample1.new_name).arg(sample1.new_name));break;
    default:break;
   }
   time1->display_time();
   qts_write(".<br>");
  }
  else
  {
   switch(type)
   {
    case WASHING:qts_write(QString("Wash %1 in <a href=\"#%2\" >%3</a>, <font color=#357EC7>%4</font> for ").arg( slide1.name).arg(sample1.new_name).arg(sample1.new_name).arg(noft));break;
    case RINSING:qts_write(QString("Rinse %1 in <a href=\"#%2\" >%3</a>, <font color=#357EC7>%4</font> for ").arg( slide1.name).arg(sample1.new_name).arg(sample1.new_name).arg(noft));break;
    default:break;
   }
   time1->display_time();
   qts_write(" each.<br>");
  }
 }
 ttr2 = total_time_required-ttr1;
 total_time_required = total_time_required + ttr2 * no_of_times;
 // graph maintenance
 {
  Operation o = new_operation("wash slide");
  create_edge_from_container_to_fluid(&slide1, &o);
  create_edge_from_fluids(&sample1, &o);
  slide1.node = create_node("slide washed");
  create_edge(o.node, slide1.node);
  o.node->time = time1->value * no_of_times;
  o.node->unit = time1->unit;
 }
}

void measure_solid(Solid& solid1, r4 weight,  weight_unit unit, Container& container1)
{
 // graph maintenance
 {
  Operation o = new_operation("measure solid");
  create_edge_from_fluids(&solid1, &o);
  create_edge_from_fluid_to_container(&o, &container1);
 }
  char *type;
  u4 mul;

  if (usage_list_fluids[solid1.usage_index].original_name == solid1.original_name)
   usage_list_fluids[solid1.usage_index].used = 1;
  else 
  {
   solid1.used = 1;
   usage_list_fluids[list_fluid_no] = solid1;
   solid1.usage_index = list_fluid_no;
   list_fluid_no++;
  }  
  if (usage_list_containers[container1.usage_index].name == container1.name)
   usage_list_containers[container1.usage_index].used = 1;
  else 
  {
   container1.used = 1;
   usage_list_containers[list_container_no] = container1;
   container1.usage_index = list_container_no;
   list_container_no++;
  }
  switch(unit)
  {
  case UG: type = "mcg"; mul = MICRO;
   break;
  case MG: type = "mg"; mul = MICRO;
   break;
  case GR: type = "g"; mul = MICRO;
   break;
  default : type = "mg";mul = MICRO;
   break;
  }
  if(prev_cont == 1)
  {
   if(solid1.state == "")
     qts_write(QString("Measure out <b><font color=#357EC7>%1 %2</font></b> of <font color=#357EC7>%2</font> into %2.<br>").arg( weight).arg(type).arg(solid1.new_name).arg(container1.name));
   else
     qts_write(QString("Measure out <b><font color=#357EC7>%1 %2</font></b> of <a href=\"#%3\" ><font color=#357EC7>%4</font></a> into %5.<br>").arg( weight).arg(type).arg(solid1.new_name).arg(solid1.new_name).arg(container1.name));
   prev_container = container1.name;
   prev_cont++;
  }
  else if( prev_container == container1.name)
  {
   if (solid1.state == "")
     qts_write(QString("Add <b><font color=#357EC7> %1 %2</font></b> of <font color=#357EC7>%3</font>.<br>").arg( weight).arg(type).arg(solid1.new_name));
   else
     qts_write(QString("Add <b><font color=#357EC7> %1 %2</font></b> of <a href=\"#%3\" ><font color=#357EC7>%4</font></a>.<br>").arg( weight).arg(type).arg(solid1.new_name).arg(solid1.new_name));
  }
  else if(solid1.state == "")
  {
   qts_write(QString("Measure out <b><font color=#357EC7>%1 %2</font></b> of <font color=#357EC7>%3</font> into %4.<br>").arg( weight).arg(type).arg(solid1.new_name).arg(container1.name));
   prev_container = container1.name;
  }
  else
  {
   qts_write(QString("Measure out <b><font color=#357EC7>%1 %2</font></b> of <a href=\"#%3\" ><font color=#357EC7>%4</font></a> into %5.<br>").arg( weight).arg(type).arg(solid1.new_name).arg(solid1.new_name).arg(container1.name));
   prev_container = container1.name;
  }

  solid1.container = container1.id;
  container1.contents = solid1;
  container1.volume = weight * mul;
}

void measure_solid(Solid& solid1, Container& container1)
{
 // graph maintenance
 {
  Operation o = new_operation("measure solid");
  create_edge_from_fluids(&solid1, &o);
  create_edge_from_fluid_to_container(&o, &container1);
 }
  if (usage_list_fluids[solid1.usage_index].original_name == solid1.original_name)
   usage_list_fluids[solid1.usage_index].used = 1;
  else 
  {
   solid1.used = 1;
   usage_list_fluids[list_fluid_no] = solid1;
   solid1.usage_index = list_fluid_no;
   list_fluid_no++;
  }  
  if (usage_list_containers[container1.usage_index].name == container1.name)
   usage_list_containers[container1.usage_index].used = 1;
  else 
  {
   container1.used = 1;
   usage_list_containers[list_container_no] = container1;
   container1.usage_index = list_container_no;
   list_container_no++;
  }
  if (prev_cont == 1)
  {
   if (solid1.state == "")
    qts_write(QString("Measure out <font color=#357EC7>%1</font> into %2.<br>").arg( solid1.new_name).arg(container1.name));
   else
    qts_write(QString("Measure out <a href=\"#%1\" ><font color=#357EC7>%2</font></a> into %3.<br>").arg( solid1.new_name).arg(solid1.new_name).arg(container1.name));
   prev_container = container1.name;
   prev_cont++;
  }
  else if( prev_container == container1.name)
  {
   if (solid1.state == "")
    qts_write(QString("Add <font color=#357EC7>%1</font>.<br>").arg( solid1.new_name));
   else
    qts_write(QString("Add <a href=\"#%1\" ><font color=#357EC7>%2</font></a>.<br>").arg( solid1.new_name).arg(solid1.new_name));
  }
  else if (solid1.state == "")
  {
   qts_write(QString("Measure out <font color=#357EC7>%1</font> into %2.<br>").arg( solid1.new_name).arg(container1.name));
   prev_container = container1.name;
  }
  else
  {
   qts_write(QString("Measure out <a href=\"#%1\" ><font color=#357EC7>%2</font></a> into %3.<br>").arg( solid1.new_name).arg(solid1.new_name).arg(container1.name));
   prev_container = container1.name;
  }

  solid1.container = container1.id;
  container1.contents = solid1;
  container1.volume = solid1.volume;
  solid1.volume = 0;
}

Symbol new_symbol(char* symbol, char* def)
{
 Symbol s1;
 s1.value = DEFAULT;
 s1.symbol = symbol;
 s1.unit = UL;
 if(print_parameters == 1)
 {
  qts_write("</ul><h2>Parameters:</h2><ul type=\"circle\">");
  print_parameters++;
 }
 qts_write(QString("<li>%1 - %2</li>").arg( symbol).arg(def));
 return s1;
}

Symbol_t new_symbol_t(char* symbol, char* def)
{
 Symbol_t s1;
 s1.value = DEFAULT;
 s1.symbol = symbol;
 s1.unit = SECS;
 if(print_parameters == 1)
 {
  qts_write("</ul><h2>Parameters:</h2><ul type=\"circle\">");
  print_parameters++;
 }
 qts_write(QString("<li>%1 - %2</li>").arg( symbol).arg(def));
 return s1;
}

void set_value(Symbol& symbol1, r4 value,  vol_unit unit)
{
 symbol1.value = value;
 symbol1.unit = unit;
}

void set_value(Symbol_t& symbol1, r4 value,  time_unit unit)
{
 symbol1.value = value;
 symbol1.unit = unit;
}

void assign(Symbol& s1, Symbol& s2)
{
 qts_write(QString("Let %1 = %2.\n").arg( s1.symbol, s2.symbol));
 s1.value = s2.value;
}

void assign(Symbol_t& s1, Symbol_t& s2)
{
 qts_write(QString("Let %1 = %2.\n").arg( s1.symbol, s2.symbol));
 s1.value = s2.value;
}

Symbol subtract(Symbolic_vol* s1, Volume* vol1)
{
 Symbol y;
 char* temp2 = "";
 char* temp1="";
 temp1 = (char *)calloc(strlen(s1->s1.symbol)+ 10, sizeof(char));
 temp2 = (char *)calloc(strlen(s1->s1.symbol)+ 10, sizeof(char));
 strcat(temp1, s1->s1.symbol);
 strcat(temp1, "-");
 sprintf(temp2, "%g", vol1->value);
 strcat(temp1, temp2);
 y.symbol= temp1;
 if ((vol1->value != DEFAULT)&&(s1->value != DEFAULT))
  y.value = s1->value - vol1->value;
 else 
  y.value = DEFAULT;
 return y;
}

Symbol subtract(Volume* s1, Symbolic_vol* vol1)
{
 Symbol y;
 char* temp2 = "";
 char* temp1="";
 temp1 = (char *)calloc(strlen(vol1->s1.symbol)+ 10, sizeof(char));
 temp2 = (char *)calloc(strlen(vol1->s1.symbol)+ 10, sizeof(char));
 sprintf(temp2, "%g", s1->value);
 strcat(temp1, temp2);
 strcat(temp1, "-");
 strcat(temp1, vol1->s1.symbol);
 y.symbol= temp1;
 if ((s1->value != DEFAULT)&&(vol1->value != DEFAULT))
  y.value = s1->value - vol1->value;
 else 
  y.value = DEFAULT;
 return y;
}

Symbol subtract(Symbolic_vol* vol1, Symbolic_vol* vol2)
{
 Symbol y;
 char* temp1="";
 temp1 = (char *)calloc(strlen(vol1->s1.symbol)+ strlen(vol2->s1.symbol), sizeof(char));
 strcat(temp1, vol1->s1.symbol);
 strcat(temp1, "-");
 strcat(temp1, vol2->s1.symbol);
 y.symbol= temp1;
 if ((vol1->value != DEFAULT)&&(vol2->value != DEFAULT))
  y.value = vol1->value - vol2->value;
 else 
  y.value = DEFAULT;
 return y;
}

Symbol add(Symbolic_vol* vol1, Volume* vol2)
{
 Symbol y;
 char* temp2 = "";
 char* temp1="";
 temp1 = (char *)calloc(strlen(vol1->s1.symbol)+ 10, sizeof(char));
 temp2 = (char *)calloc(strlen(vol1->s1.symbol)+ 10, sizeof(char));
 strcat(temp1, vol1->s1.symbol);
 strcat(temp1, "+");
 sprintf(temp2, "%g", vol2->value);
 strcat(temp1, temp2);
 y.symbol= temp1;
 if ((vol1->value != DEFAULT)&&(vol2->value != DEFAULT))
  y.value = vol1->value + vol2->value;
 else 
  y.value = DEFAULT;
 return y;
}


Symbol add(Symbolic_vol* vol1, Symbolic_vol* vol2)
{
 Symbol y;
 char* temp1="";
 temp1 = (char *)calloc(strlen(vol1->s1.symbol)+ strlen(vol2->s1.symbol), sizeof(char));
 strcat(temp1, vol1->s1.symbol);
 strcat(temp1, "+");
 strcat(temp1, vol2->s1.symbol);
 y.symbol= temp1;
 if ((vol1->value != DEFAULT)&&(vol2->value != DEFAULT))
  y.value = vol1->value + vol2->value;
 else 
  y.value = DEFAULT;
 return y;
}

Symbol multiply(Symbolic_vol* vol1, Volume* vol2)
{
 Symbol y;
 char* temp2 = "";
 char* temp1="";
 temp1 = (char *)calloc(strlen(vol1->s1.symbol)+ 10, sizeof(char));
 temp2 = (char *)calloc(strlen(vol1->s1.symbol)+ 10, sizeof(char));
 strcat(temp1, vol1->s1.symbol);
 strcat(temp1, "*");
 sprintf(temp2, "%g", vol2->value);
 strcat(temp1, temp2);
 if ((vol1->value != DEFAULT)&&(vol2->value != DEFAULT))
  y.value = vol1->value * vol2->value;
 else 
  y.value = DEFAULT;
 y.symbol= temp1;
 return y;
}

Symbol multiply(Symbolic_vol* vol1, Symbolic_vol* vol2)
{
 Symbol y;
 char* temp1="";
 temp1 = (char *)calloc(strlen(vol1->s1.symbol)+ strlen(vol2->s1.symbol), sizeof(char));
 strcat(temp1, vol1->s1.symbol);
 strcat(temp1, "*");
 strcat(temp1, vol2->s1.symbol);
 y.symbol= temp1;
 if ((vol1->value != DEFAULT)&&(vol2->value != DEFAULT))
  y.value = vol1->value * vol2->value;
 else 
  y.value = DEFAULT;
 return y;
}
Symbol divide(Symbolic_vol* vol1, Volume* vol2)
{
 Symbol y;
 char* temp2 = "";
 char* temp1="";
 temp1 = (char *)calloc(strlen(vol1->s1.symbol)+ 10, sizeof(char));
 temp2 = (char *)calloc(strlen(vol1->s1.symbol)+ 10, sizeof(char));
 strcat(temp1, vol1->s1.symbol);
 strcat(temp1, "/");
 sprintf(temp2, "%g", vol2->value);
 strcat(temp1, temp2);
 y.symbol= temp1;
 if ((vol1->value != DEFAULT)&&(vol2->value != DEFAULT))
  y.value = vol1->value / vol2->value;
 else 
  y.value = DEFAULT;
 return y;
}


Symbol divide(Volume*vol1, Symbolic_vol* vol2)
{
 Symbol y;
 char* temp2 = "";
 char* temp1="";
 temp1 = (char *)calloc(strlen(vol2->s1.symbol)+ 10, sizeof(char));
 temp2 = (char *)calloc(strlen(vol2->s1.symbol)+ 10, sizeof(char));
 sprintf(temp2, "%g", vol1->value);
 strcat(temp1, temp2);
 strcat(temp1, "/");
 strcat(temp1, vol2->s1.symbol);
 y.symbol= temp1;
 if ((vol1->value != DEFAULT)&&(vol2->value != DEFAULT))
  y.value = vol1->value / vol2->value;
 else 
  y.value = DEFAULT;
 return y;
}


Symbol divide(Symbolic_vol* vol1, Symbolic_vol* vol2)
{
 Symbol y;
 char* temp1="";
 temp1 = (char *)calloc(strlen(vol1->s1.symbol)+ strlen(vol2->s1.symbol), sizeof(char));
 strcat(temp1, vol1->s1.symbol);
 strcat(temp1, "/");
 strcat(temp1, vol2->s1.symbol);
 y.symbol= temp1;
 if ((vol1->value != DEFAULT)&&(vol2->value != DEFAULT))
  y.value = vol1->value / vol2->value;
 else 
  y.value = DEFAULT;
 return y;
}

r4 get_ttr()
{
 return total_time_required;
}

void streak_plate(Plate& plate1, Plate& colony)
{
 // graph maintenance
 {
  Operation o = new_operation("streak");
  create_edge_from_fluids(&colony, &o);
  create_edge_from_fluids(&o, &plate1);
 }
  if (usage_list_fluids[plate1.usage_index].original_name == plate1.original_name)
   usage_list_fluids[plate1.usage_index].used = 1;
  else 
  {
   plate1.used = 1;
   usage_list_fluids[list_fluid_no] = plate1;
   plate1.usage_index = list_fluid_no;
   list_fluid_no++;
  }  
  if (usage_list_fluids[colony.usage_index].original_name == colony.original_name)
   usage_list_fluids[colony.usage_index].used = 1;
  else 
  {
   colony.used = 1;
   usage_list_fluids[list_fluid_no] = colony;
   colony.usage_index = list_fluid_no;
   list_fluid_no++;
  }
  qts_write(QString("Use a sterile toothpick or disposable loop to transfer a small segement of %1 to a streak or patch on %2. <br>").arg( colony.new_name).arg(plate1.new_name));
}


