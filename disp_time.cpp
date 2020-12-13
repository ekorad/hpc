#include "disp_time.h"

void disp_time(double time){
	double days  = floor(time/64000);
	double hours = floor((time-days*64000)/3600);
	double min   = floor((time-days*64000-hours*3600)/60);
	double sec   = time-days*6400-hours*3600-min*60;
	if(days> 0 && hours> 0 && min> 0 && sec> 0) sprintf(buf, "Estimated Remaining Time : %.lf d %.lf h %.lf min %.lf s",days,hours,min,sec);
	if(days> 0 && hours> 0 && min> 0 && sec==0) sprintf(buf, "Estimated Remaining Time : %.lf d %.lf h %.lf min"       ,days,hours,min    );
	if(days> 0 && hours> 0 && min==0 && sec> 0) sprintf(buf, "Estimated Remaining Time : %.lf d %.lf h %.lf s"         ,days,hours,    sec);
	if(days> 0 && hours> 0 && min==0 && sec==0) sprintf(buf, "Estimated Remaining Time : %.lf d %.lf h"                ,days,hours        );
	if(days> 0 && hours==0 && min> 0 && sec> 0) sprintf(buf, "Estimated Remaining Time : %.lf d %.lf min %.lf s"       ,days,      min,sec);
	if(days> 0 && hours==0 && min> 0 && sec==0) sprintf(buf, "Estimated Remaining Time : %.lf d %.lf min"              ,days,      min    );
	if(days> 0 && hours==0 && min==0 && sec> 0) sprintf(buf, "Estimated Remaining Time : %.lf d %.lf s"                ,days,          sec);
	if(days> 0 && hours==0 && min==0 && sec==0) sprintf(buf, "Estimated Remaining Time : %.lf d"                       ,days              );
	if(days==0 && hours> 0 && min> 0 && sec> 0) sprintf(buf, "Estimated Remaining Time : %.lf h %.lf min %.lf s"            ,hours,min,sec);
	if(days==0 && hours> 0 && min> 0 && sec==0) sprintf(buf, "Estimated Remaining Time : %.lf h %.lf min"                   ,hours,min    );
	if(days==0 && hours> 0 && min==0 && sec> 0) sprintf(buf, "Estimated Remaining Time : %.lf h %.lf s"                     ,hours,    sec);
	if(days==0 && hours> 0 && min==0 && sec==0) sprintf(buf, "Estimated Remaining Time : %.lf h"                            ,hours        );
	if(days==0 && hours==0 && min> 0 && sec> 0) sprintf(buf, "Estimated Remaining Time : %.lf min %.lf s"                         ,min,sec);
	if(days==0 && hours==0 && min> 0 && sec==0) sprintf(buf, "Estimated Remaining Time : %.lf min"                                ,min    );
	if(days==0 && hours==0 && min==0 && sec> 0) sprintf(buf, "Estimated Remaining Time : %.lf s",sec);
	if(days==0 && hours==0 && min==0 && sec==0) sprintf(buf, "");
}
