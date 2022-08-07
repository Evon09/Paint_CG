//---------------------------------------------------------------------------

#ifndef ujanelaH
#define ujanelaH
//---------------------------------------------------------------------------
class Janela {
	public:
	  double xmin;
	  double xmax;
	  double ymin;
	  double ymax;

	  Janela (double, double, double, double);
      Janela AtMundo(Janela mundo, float, float, float , float );
};

#endif
