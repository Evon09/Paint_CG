//---------------------------------------------------------------------------

#ifndef uDisplayFileH
#define uDisplayFileH
#include <vector>
#include "uPoligono.h"
#include <Vcl.ExtCtrls.hpp>
#include "ujanela.h"
#include "Cord3D.h"
//---------------------------------------------------------------------------
class DisplayFile{
	public:
		std::vector <Poligono> poligonos;
		//td::vector <Cord3D> cord3d;

		void desenha(TCanvas *canvas, Janela mundo, Janela vp, int tipoReta);

		void mostra(TListBox *lb);
};
#endif
