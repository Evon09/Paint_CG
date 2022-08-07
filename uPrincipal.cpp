//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <stdio.h>
#include <conio.h>
#include "ujanela.h"
#include "uPrincipal.h"
#include "uPonto.h"
#include "Cord3D.h"

#include "uDisplayFile.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "SHDocVw_OCX"
#pragma resource "*.dfm"
TForm1 *Form1;
Cord3D aux;
int ToInt;
Janela mundo(-250, -250, 250, 250);
Janela clipping(-100, -100, 100, 100);

Janela vp (0,0,500,500);
Poligono pol, clip1,clip2;
DisplayFile display;
int contaId = 0;
bool inicio= false;
#include "uPoligono.h"
//---------------------------------------------------------------------------
double TForm1::xVp2W(int x, Janela mundo, Janela vp){
  return (((x-vp.xmin)/(vp.xmax-vp.xmin)) *
		 (mundo.xmax - mundo.xmin)) + mundo.xmin;
}

double TForm1::yVp2W(int y, Janela mundo, Janela vp){
  return ((1-((y-vp.ymin)/(vp.ymax-vp.ymin))) *
		 (mundo.ymax - mundo.ymin)) + mundo.ymin;
}

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
  // eixo vertical
  pol.id     = contaId++;
  pol.tipo   = 'E';
  pol.cord3d.push_back(Cord3D(0, mundo.ymax,10));
  pol.cord3d.push_back(Cord3D(0, mundo.ymin,1));

  display.poligonos.push_back(pol);
  pol.cord3d.clear();

  // eixo horizontal
  pol.id     = contaId++;
  pol.tipo   = 'E';
  pol.cord3d.push_back(Cord3D(mundo.xmin, 0,1));
  pol.cord3d.push_back(Cord3D(mundo.xmax, 0,1));

  display.poligonos.push_back(pol);
  pol.cord3d.clear();

  //Clipping
  pol.cord3d.push_back(Cord3D(clipping.xmin, clipping.ymin,1));
  pol.cord3d.push_back(Cord3D(clipping.xmin, clipping.ymax,1));
  pol.cord3d.push_back(Cord3D(clipping.xmax, clipping.ymax,1));
  pol.cord3d.push_back(Cord3D(clipping.xmax, clipping.ymin,1));
  pol.cord3d.push_back(Cord3D(clipping.xmin, clipping.ymin,1));
  pol.id = contaId++;
  pol.tipo = 'C';
  display.poligonos.push_back(pol);
  pol.cord3d.clear();



  display.mostra(lbPoligonos);
  display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);

  xMin->Caption = ToInt=mundo.xmin;
  xMax->Caption = ToInt=mundo.xmax;
  yMin->Caption = ToInt=mundo.ymin;
  yMax->Caption = ToInt=mundo.ymax;

}
//---------------------------------------------------------------------------



void __fastcall TForm1::Image1MouseMove(TObject *Sender, TShiftState Shift, int X,
		  int Y)
{
   double nx, ny;

   nx = xVp2W(X, mundo, vp);
   ny = yVp2W(Y, mundo, vp);

   lbVp->Caption = "(" + IntToStr(X) + "," +
						 IntToStr(Y) + ")";
   lbMundo->Caption = "(" + FloatToStr(nx) + "," +
							FloatToStr(ny) + ")";

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{



	if(!Linha->Enabled){

		if ((rgTipoReta->ItemIndex) >= 0)
		{
			if (Button ==  mbLeft){
				UnicodeString a;

				aux.x = xVp2W(X, mundo, vp);
				aux.y = yVp2W(Y, mundo, vp);
				aux.z = 1 ;
				//ShowMessage(aux.toString());

				pol.cord3d.push_back(aux);
				pol.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
				}
				else{
					if(Button ==  mbRight){
						pol.id     = contaId++;
						pol.tipo   = 'P';

						display.poligonos.push_back(pol);
						pol.cord3d.clear();

						display.mostra(lbPoligonos);

					}
				}
	   }
	 }else{

			 pol.id = contaId++;
			 pol.tipo = 'O';

			 pol.Circunferencia(xVp2W(X, mundo, vp), yVp2W(Y, mundo, vp),
								StrToFloat(edRaio->Text), &pol);
			 display.poligonos.push_back(pol);
			 pol.cord3d.clear();

			 display.desenha(Image1->Canvas, mundo, vp,rgTipoReta->ItemIndex);
			 display.mostra(lbPoligonos);
			 pol.tipo = 'E';
	 }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::LinhaClick(TObject *Sender)
{
	Circulo->Enabled = true;
	Linha->Enabled = false;
}

void __fastcall TForm1::CirculoClick(TObject *Sender)
{
	Linha->Enabled = true;
	Circulo->Enabled = false ;
}

void __fastcall TForm1::lbPoligonosClick(TObject *Sender)
{
	display.poligonos[lbPoligonos->ItemIndex].mostra(lbPontos);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{

    mundo.xmin = StrToFloat(edxMin->Text);
    mundo.xmax = StrToFloat(edxMax->Text);
    mundo.ymin = StrToFloat(edyMin->Text);
    mundo.ymax = StrToFloat(edyMax->Text);

	display.poligonos[0].cord3d[0].y = mundo.ymax;
	display.poligonos[0].cord3d[1].y = mundo.ymin;

	display.poligonos[1].cord3d[0].x = mundo.xmin;
	display.poligonos[1].cord3d[1].x = mundo.xmax;

	display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);

	xMin->Caption = ToInt= mundo.xmin;
	xMax->Caption = ToInt= mundo.xmax;
	yMin->Caption = ToInt= mundo.ymin;
	yMax->Caption = ToInt= mundo.ymax;

	//xMin->Caption =  StrToFloat(edyMin->Text);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ZoomClick(TObject *Sender){

	mundo = mundo.AtMundo(mundo, 0.1,0.1,0.1,0.1);



	display.poligonos[0].cord3d[0].y = mundo.ymax;
	display.poligonos[0].cord3d[1].y = mundo.ymin;

	display.poligonos[1].cord3d[0].x = mundo.xmin;
	display.poligonos[1].cord3d[1].x = mundo.xmax;

	display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);


	xMin->Caption = ToInt=mundo.xmin;
	xMax->Caption = ToInt=mundo.xmax;
	yMin->Caption = ToInt=mundo.ymin;
	yMax->Caption = ToInt=mundo.ymax;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ZoomOutClick(TObject *Sender){
	mundo = mundo.AtMundo(mundo, -0.1,-0.1,-0.1,-0.1);


	display.poligonos[0].cord3d[0].y = mundo.ymax;
	display.poligonos[0].cord3d[1].y = mundo.ymin;

	display.poligonos[1].cord3d[0].x = mundo.xmin;
	display.poligonos[1].cord3d[1].x = mundo.xmax;

	display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);

	xMin->Caption = ToInt=mundo.xmin;
	xMax->Caption = ToInt=mundo.xmax;
	yMin->Caption = ToInt=mundo.ymin;
	yMax->Caption = ToInt=mundo.ymax;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SubirClick(TObject *Sender){
	 mundo = mundo.AtMundo(mundo, 0,0,0.1,-0.1);


	display.poligonos[0].cord3d[0].y = mundo.ymax;
	display.poligonos[0].cord3d[1].y = mundo.ymin;

	display.poligonos[1].cord3d[0].x = mundo.xmin;
	display.poligonos[1].cord3d[1].x = mundo.xmax;

	display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);

	xMin->Caption = ToInt=mundo.xmin;
	xMax->Caption = ToInt=mundo.xmax;
	yMin->Caption = ToInt=mundo.ymin;
	yMax->Caption = ToInt=mundo.ymax;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DescerClick(TObject *Sender){
	mundo = mundo.AtMundo(mundo, 0,0,-0.1,0.1);


	display.poligonos[0].cord3d[0].y = mundo.ymax;
	display.poligonos[0].cord3d[1].y = mundo.ymin;

	display.poligonos[1].cord3d[0].x = mundo.xmin;
	display.poligonos[1].cord3d[1].x = mundo.xmax;

	display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);

	xMin->Caption = ToInt=mundo.xmin;
	xMax->Caption = ToInt=mundo.xmax;
	yMin->Caption = ToInt=mundo.ymin;
	yMax->Caption = ToInt=mundo.ymax;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::EsquerdaClick(TObject *Sender){
	 mundo = mundo.AtMundo(mundo, -0.1 ,0.1,0,0);


	display.poligonos[0].cord3d[0].y = mundo.ymax;
	display.poligonos[0].cord3d[1].y = mundo.ymin;

	display.poligonos[1].cord3d[0].x = mundo.xmin;
	display.poligonos[1].cord3d[1].x = mundo.xmax;

	display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);

	xMin->Caption = ToInt=mundo.xmin;
	xMax->Caption = ToInt=mundo.xmax;
	yMin->Caption = ToInt=mundo.ymin;
	yMax->Caption = ToInt=mundo.ymax;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::DireitaClick(TObject *Sender){
	 mundo = mundo.AtMundo(mundo, 0.1,-0.1,0,0);


	display.poligonos[0].cord3d[0].y = mundo.ymax;
	display.poligonos[0].cord3d[1].y = mundo.ymin;

	display.poligonos[1].cord3d[0].x = mundo.xmin;
	display.poligonos[1].cord3d[1].x = mundo.xmax;

	display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);

	xMin->Caption = ToInt=mundo.xmin;
	xMax->Caption = ToInt=mundo.xmax;
	yMin->Caption = ToInt=mundo.ymin;
	yMax->Caption = ToInt=mundo.ymax;
}
//-------------------------------------------------------------------------


void __fastcall TForm1::rgTipoRetaClick(TObject *Sender)
{
    display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender)
{

	display.poligonos[lbPoligonos->ItemIndex].transladar(StrToFloat(edTransladarX->Text),
														 StrToFloat(edTransladarY->Text));
	display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{

	display.poligonos[lbPoligonos->ItemIndex].escalonar(StrToFloat(edScalarX->Text),
														 StrToFloat(edScalarY->Text));
	display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{
	display.poligonos[lbPoligonos->ItemIndex].rotacao((double)(StrToFloat(edAnguloZ->Text)));
	display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);

}
//---------------------------------------------------------------------------




void __fastcall TForm1::TranslacaoClick(TObject *Sender)
{

	if(lbPoligonos->ItemIndex > 2){

		display.poligonos[lbPoligonos->ItemIndex].CHomo(StrToFloat(edTransladarX->Text),
											  StrToFloat(edTransladarY->Text), 0,0,0,0);
		display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);

	}

}
//---------------------------------------------------------------------------



void __fastcall TForm1::EscalonamentoClick(TObject *Sender)
{

	if( lbPoligonos->ItemIndex > 2){

		display.poligonos[lbPoligonos->ItemIndex].CHomo(0, 0, StrToFloat(edScalarX->Text),StrToFloat(edScalarY->Text),0,1);
		display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
	}


}
//---------------------------------------------------------------------------

void __fastcall TForm1::RotacaoClick(TObject *Sender)
{

	if( display.poligonos[lbPoligonos->ItemIndex].tipo != 'E'){
		display.poligonos[lbPoligonos->ItemIndex].CHomo(0, 0, 0,0,
														StrToFloat(edAnguloZ->Text),2);
		display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
	}
}
//---------------------------------------------------------------------------



void __fastcall TForm1::ReflexcimaClick(TObject *Sender)
{

	if(display.poligonos[lbPoligonos->ItemIndex].tipo != 'E'){
		display.poligonos[lbPoligonos->ItemIndex].CHomo(0, 0, 0,0,0,3);
		display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ReflexLadoClick(TObject *Sender)
{
	if(display.poligonos[lbPoligonos->ItemIndex].tipo != 'E'){
		display.poligonos[lbPoligonos->ItemIndex].CHomo(0, 0, 0,0,0,4);
		display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ReflexDiagonalClick(TObject *Sender)
{
	if(display.poligonos[lbPoligonos->ItemIndex].tipo != 'E'){
		display.poligonos[lbPoligonos->ItemIndex].CHomo(0, 0, 0,0,0,5);
		display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	if (lbPoligonos->ItemIndex > 2) {
			clip1 = display.poligonos[lbPoligonos->ItemIndex];
			clip2 = display.poligonos[lbPoligonos->ItemIndex].Clip(clipping, clip1);
			if (clip2.cord3d.size() > 0) {
					clip2.id = contaId++;
					clip2.tipo = (display.poligonos[lbPoligonos->ItemIndex].tipo == 'O')?
					'r':'R';
					display.poligonos.push_back(clip2);
					display.mostra(lbPoligonos);
					clip2.cord3d.clear();
					display.desenha(Image1->Canvas, mundo, vp,rgTipoReta->ItemIndex);
					clip2.mostra(lbPontos);
				}
		}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	pol = display.poligonos[lbPoligonos->ItemIndex].casteljau(&pol);

	pol.id = contaId++;
	pol.tipo = '(';

	display.poligonos.push_back(pol);
	pol.cord3d.clear();
	display.mostra(lbPoligonos);
	display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	display.poligonos[lbPoligonos->ItemIndex].bezier(&pol);
	pol.id = contaId++;
	pol.tipo = '(';

	display.poligonos.push_back(pol);
	pol.cord3d.clear();
	display.mostra(lbPoligonos);
	display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	display.poligonos[lbPoligonos->ItemIndex].hermite(&pol);
	pol.id = contaId++;
	pol.tipo = '(';

	display.poligonos.push_back(pol);
	pol.cord3d.clear();
	display.mostra(lbPoligonos);
	display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button6Click(TObject *Sender)
{
	display.poligonos[lbPoligonos->ItemIndex].Bspline(&pol);
	pol.id = contaId++;
	pol.tipo = '(';

	display.poligonos.push_back(pol);
	pol.cord3d.clear();
	display.mostra(lbPoligonos);
	display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
	display.poligonos[lbPoligonos->ItemIndex].forward(&pol);
	pol.id = contaId++;
	pol.tipo = '(';
	display.poligonos.push_back(pol);
	pol.cord3d.clear();
	display.mostra(lbPoligonos);
	display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
}



void __fastcall TForm1::Button11Click(TObject *Sender)
{
	if( lbPoligonos->ItemIndex > 2){

		display.poligonos[lbPoligonos->ItemIndex].CHomo(StrToFloat(edTransladarX->Text)
		,StrToFloat(edTransladarY->Text),StrToFloat(edTransladarZ->Text),0,0,0,0,0);
		display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
	}
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button12Click(TObject *Sender)
{
    if( lbPoligonos->ItemIndex > 2){

		display.poligonos[lbPoligonos->ItemIndex].CHomo(0,0,0,
		StrToFloat(edScalarX->Text),StrToFloat(edScalarY->Text),StrToFloat(edScalarZ->Text),0,1);
		display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button13Click(TObject *Sender)
{
	if( lbPoligonos->ItemIndex > 2){
		display.poligonos[lbPoligonos->ItemIndex].CHomo(0, 0, 0,0,0,0,
											StrToFloat(edAnguloX->Text),2);
		display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button14Click(TObject *Sender)
{
	if( lbPoligonos->ItemIndex > 2){
		display.poligonos[lbPoligonos->ItemIndex].CHomo(0, 0, 0,0,0,0,
											StrToFloat(edAnguloY->Text),3);
		display.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FileopenFolderChange(TObject *Sender)
{
      ;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::btnOpenClick(TObject *Sender)
{
	FILE *arq = NULL;
	char Linha[100];
	char *result, *cord;
	char *arquivo = AnsiString(edText->Text).c_str();

	int i;

	arq = fopen( arquivo , "r");

    if (arq == NULL)  // Se houve erro na abertura
  {

     return;
  }else{


	while (!feof(arq))
	{


            result = fgets(Linha, 100, arq);


			aux.x = StrToFloat(strtok(result," \n"));

			aux.y = StrToFloat(strtok(NULL, " \n"));

			aux.z = StrToFloat(strtok(NULL, " \n"));


			pol.cord3d.push_back(aux);

			pol.desenha(Image1->Canvas, mundo, vp, rgTipoReta->ItemIndex);

	}
	  fclose(arq);

	  pol.id     = contaId++;
	  pol.tipo   = 'F';

	  display.poligonos.push_back(pol);
	  pol.cord3d.clear();

	  display.mostra(lbPoligonos);
  }

}
//---------------------------------------------------------------------------

