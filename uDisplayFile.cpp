//---------------------------------------------------------------------------

#pragma hdrstop

#include "uDisplayFile.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


void DisplayFile::desenha(TCanvas *canvas, Janela mundo, Janela vp, int tipoReta)
{
  canvas->Pen->Width   = 2;


  canvas->Brush->Color = clWhite;
  canvas->FillRect(Rect(0,0,500,500));

  for (int x = 0; x < poligonos.size(); x++)
  {
	poligonos[x].desenha(canvas, mundo, vp, tipoReta);
  }
}

void DisplayFile::mostra(TListBox *lb)
{
	lb->Items->Clear();

	for (int x = 0; x < poligonos.size(); x++)
	{
		lb->Items->Add(poligonos[x].toString());
	}
}

