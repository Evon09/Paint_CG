//---------------------------------------------------------------------------

#pragma hdrstop

#include "ujanela.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Janela::Janela (double nxmin, double nymin,
				double nxmax, double nymax){
  xmin = nxmin;
  ymin = nymin;
  xmax = nxmax;
  ymax = nymax;
}


Janela Janela::AtMundo(Janela mundo,float nxmin, float nxmax,float nymin,float nymax){

	mundo.xmin = mundo.xmin - (mundo.xmin * nxmin);
	mundo.xmax = mundo.xmax - (mundo.xmax * nxmax);
	mundo.ymin = mundo.ymin - (mundo.ymin * nymin);
	mundo.ymax = mundo.ymax - (mundo.ymax * nymax);
	return mundo;
}


