//---------------------------------------------------------------------------

#ifndef uPoligonoH
#define uPoligonoH
#include <vector>
#include "uPonto.h"
#include "Cord3D.h"

#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
//using namespace std;

class Poligono{
	public:
	  int id;
	  char tipo;
	  std::vector <Cord3D> cord3d;

	  void desenha(TCanvas *canvas, Janela mundo, Janela vp, int tipoReta);
	  void desenhaPonto(Ponto ponto, TCanvas*canvas, Janela mundo, Janela vp, int tipoReta);
	  UnicodeString toString();

      void moveTo(TCanvas *canvas, Janela mundo, Janela vp);
	  void DDA(Ponto P1, Ponto P2, TCanvas *canvas, Janela mundo, Janela vp, char tipo);
	  void Bresenham(Ponto P1, Ponto P2, TCanvas *canvas, Janela mundo, Janela vp);

	  void mostra(TListBox *lb);

	  Ponto pontoMedio();
      Cord3D pontoMedioZ();
	  void CHomo(float dx, float dy,float sx, float sy,double angulo,int tipo);
      void CHomo(float dx, float dy,float dz,float sx, float sy,float sz,
					double angulo,int tipo);


      void Circunferencia(double xc, double yc, double r, Poligono *aux);
	  void DesenhaCircunferencia(double xc, double yc, double x, double y, Poligono *aux);

      void transladar(float dx, float dy);
	  void escalonar(double dx, double dy);
	  void rotacao(double angulo);
	  void reflexao(double dx, double dy);


	  int Cohen(Janela clipping, double x, double y);
	  Poligono Clip(Janela clipping, Poligono pol);

      Poligono casteljau(Poligono *pol);
	  void desenhaCasteljauRec(Poligono*curva, Poligono aux);
	  double distanciaPontos(Ponto p1, Ponto p2);
	  Cord3D pontoMedio(Ponto p1, Ponto p2);
	  void subdividirCurva(Poligono aux, Poligono*curvaEsquerda,Poligono*curvaDireita);



	  void hermite(Poligono *pol);
	  void bezier(Poligono *pol);
	  void Bspline(Poligono *pol);
	  void forward(Poligono *pol);


};

#endif
