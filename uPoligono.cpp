//---------------------------------------------------------------------------

#pragma hdrstop
#define SIGN(x) ((x) < 0 ? (-1): (1))
#define ABS(x) ((x) < 0 ? (-x) : (x))
#define FLOOR(x) ((x) < 0 ? ( (x) - (double)(x) != 0 ? ((double)(x) - 1) : ((int)(x))) : (double)(x))
#include <math.h>
#include "uPoligono.h"
#include "uJanela.h"
#include "Cord3D.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)



//
// Seletor de Retas
//
void Poligono::desenha(TCanvas *canvas, Janela mundo, Janela vp, int tipoReta)
{
	if(tipo == 'O' || tipo == 'r'){
	   for(int x = 0; x < cord3d.size() - 1; x++) {
		   canvas->Pixels[cord3d[x].xW2Vp(mundo, vp)][cord3d[x].yW2Vp(mundo, vp)]
		   = (tipo == 'O')? clWebOrangeRed : clWebLimeGreen;
		}
	} else
	{
		switch (tipoReta){

			case 0:moveTo(canvas,mundo,vp);
			break;

			case 1:
			for(float x = 0; x < cord3d.size() - 1; x++) {
				DDA(cord3d[x], cord3d[x+1], canvas, mundo, vp, tipo);
			}
			break;

			case 2:
			for(int x = 0; x < cord3d.size() - 1; x++) {
				Bresenham(cord3d[x], cord3d[x+1], canvas, mundo, vp);
			}
			break;
        }

	}

}

//
// Moved To
//
void Poligono::moveTo(TCanvas *canvas, Janela mundo, Janela vp){

	for (int x = 0; x < cord3d.size(); x++){
		if (x==0)
		  canvas->MoveTo(cord3d[x].xW2Vp(mundo, vp),
						 cord3d[x].yW2Vp(mundo, vp));
		 else{

			if(tipo == 'R')
				canvas->Pen->Color = clWebLimeGreen;
			else
				canvas->Pen->Color = clWebDarkSlategray;
			canvas->LineTo(cord3d[x].xW2Vp(mundo, vp),cord3d[x].yW2Vp(mundo, vp));
		 }
	  }


}

//
//DDA
//
void Poligono::DDA(Ponto P1, Ponto P2, TCanvas *canvas, Janela mundo, Janela vp, char tipo) {

double x, x1, x2, y, y1, y2, lenght, deltax, deltay;
	x1 = P1.xW2Vp(mundo,vp);
	x2 = P2.xW2Vp(mundo,vp);
	y1 = P1.yW2Vp(mundo,vp);
	y2 = P2.yW2Vp(mundo,vp);

	if(ABS((x2 - x1)) >= ABS((y2 - y1))) {
		lenght = ABS((x2 - x1));
	}
	else {
		lenght = ABS((y2 - y1));
	}

	deltax = (x2-x1 != 0 )? (x2 -x1) / lenght : 0 ;
	deltay = (y2-y1 != 0 )? (y2 - y1) / lenght: 0 ;
	x = x1 + 0.5 * SIGN(deltax);
	y = y1 + 0.5 * SIGN(deltay);

	for ( int i = 0; i < lenght; i++) {
		if(tipo == 'R')
			canvas->Pixels[FLOOR(x)][FLOOR(y)] = clWebLimeGreen;
		else
			canvas->Pixels[FLOOR(x)][FLOOR(y)] = clWebSlateBlue;
		x = x + deltax;
		y = y + deltay;
    }

}

//
//Bresenham
//
void Poligono:: Bresenham(Ponto P1, Ponto P2, TCanvas *canvas, Janela mundo, Janela vp){

float x, x1, x2, y, y1, y2, tmp, erro;
double deltax, deltay, signalx, signaly;
int interchange;

	x1 = P1.xW2Vp(mundo,vp);
	x2 = P2.xW2Vp(mundo,vp);
	y1 = P1.yW2Vp(mundo,vp);
	y2 = P2.yW2Vp(mundo,vp);

	deltax = ABS((x2 - x1));
	deltay = ABS((y2 - y1));
	signalx = SIGN((x2 - x1));
	signaly = SIGN((y2 - y1));
	x = x1;
	y = y1;

	if (signalx < 0) {
		x = x - 1;
	}
	if(signaly < 0) {
		y = y - 1;
	}

	interchange = false;
	if (deltay > deltax) {
		tmp = deltax;
		deltax = deltay;
		deltay = tmp;
		interchange = true;
	}

	erro = 2 * deltay - deltax;

	for(int i = 0; i < deltax; i++) {
        if(tipo == 'R')
			canvas->Pixels[FLOOR(x)][FLOOR(y)] = clWebLimeGreen;
		else
			canvas->Pixels[FLOOR(x)][FLOOR(y)] = clWebSteelBlue;
		while (erro >= 0) {
			if (interchange) {
				x = x + signalx;
			}
			else  {
				y = y + signaly;
			}

			erro = erro - 2 * deltax;
		}
		if(interchange) {
			y = y + signaly;
		}
		else  {
			x = x + signalx;
        }

		erro = erro + 2 * deltay;
	}

}



UnicodeString Poligono::toString()
{
  return IntToStr(id) + " - " + tipo + " - " + IntToStr((int)cord3d.size()) + " Pontos";
}

void Poligono::mostra(TListBox *lb)
{
	lb->Items->Clear();

	for (int x = 0; x < cord3d.size(); x++)
	{
		lb->Items->Add(cord3d[x].toString());
	}
}

void Poligono::transladar(float dx, float dy) {
	for (int x = 0; x < cord3d.size(); x++) {
		cord3d[x].transladar(dx, dy);
	}
}

void Poligono::escalonar(double dx, double dy) {
	for (int x = 0; x < cord3d.size(); x++) {
		cord3d[x].escalonar(dx, dy);
	}
}

void Poligono::rotacao(double angulo) {
	for (int x = 0; x < cord3d.size(); x++) {
		cord3d[x].rotacao(angulo);
	}
}

void Poligono::reflexao(double dx, double dy) {
		for (int x = 0; x < cord3d.size(); x++) {
			cord3d[x].transladar(dx, dy);
		}
}

Ponto Poligono::pontoMedio(){

	double somaX = 0;
	double somaY = 0;

	for (int i = 0; i < cord3d.size(); i++)
	{
		somaX += cord3d[i].x;
		somaY += cord3d[i].y;
	}

	somaX = somaX / cord3d.size();
	somaY = somaY / cord3d.size();

	return Cord3D(somaX, somaY, 0);

}

Cord3D Poligono::pontoMedioZ(){

	double somaX = 0;
	double somaY = 0;
	double somaZ = 0;

	for (int i = 0; i < cord3d.size(); i++)
	{
		somaX += cord3d[i].x;
		somaY += cord3d[i].y;
		somaZ += cord3d[i].z;
	}

	somaX = somaX / cord3d.size();
	somaY = somaY / cord3d.size();
	somaZ = somaZ / cord3d.size();

	return Cord3D(somaX, somaY, somaZ);

}




void Poligono::CHomo(float dx, float dy,float sx, float sy,double angulo,int tipo)
{
	float matrix[3][3]={0,0,0,0,0,0,0,0,0};
	float aux[1][3] = {0,0,0};
	float px,py;
	float poli[1][3] = {1,1 , 1};
	Ponto centro;
	double grau;

	grau = (angulo * 3.14) / 180;

	switch (tipo){


	case 0:
		matrix[0][0] = 1; matrix[1][1] = 1; matrix[2][2] = 1;
		matrix[2][0]=dx;matrix[2][1]=dy;
		break;

	case 1:
		matrix[0][0] = sx; matrix[1][1] = sy; matrix[2][2] = 1;
		break;

	case 2:
		centro = pontoMedio();
		CHomo(-centro.x,-centro.y, 0,0,0,0);
		matrix[0][0] = (cos(grau));matrix[0][1] = (sin(grau));
		matrix[1][1] = (cos(grau));matrix[2][2] = 1;matrix[1][0] = -sin(grau);
		break;

	case 3:
		matrix[0][0] = 1; matrix[1][1] = -1; matrix[2][2] = 1;
		break;

	case 4:
		matrix[0][0] = -1;matrix[1][1] = 1; matrix[2][2] = 1;
		break;
	case 5:
		matrix[0][0] = -1;matrix[1][1] = -1; matrix[2][2] = 1;
		break;

	}




	for(int x=0; x<cord3d.size(); x++ ){

		px=cord3d[x].x;
		py=cord3d[x].y;
		poli[0][0] = px;
		poli[0][1] = py;

		for(int i = 0 ; i < 1 ; i++){
			for(int j=0; j<3 ; j++){

				aux[i][j] = 0;

				for(int k = 0; k<3 ; k++){

					aux[i][j] = aux[i][j] + poli[i][k] * matrix[k][j] ;

				}

			}

		}

		 cord3d[x].x = aux[0][0];
		 cord3d[x].y = aux[0][1];
	}


	if(tipo == 2){CHomo(centro.x,centro.y, 0,0,0,0);}


}



void Poligono::CHomo(float dx, float dy, float dz,float sx, float sy,float sz,
double angulo,int tipo)
{


	float matrix[4][4]={0,0,0,0,0,0,0,0,0,0,0,0,0};
	float aux[1][3] = {0,0,0};
	float px,py,pz;
	float poli[1][4] = {1,1,1,1};
	Cord3D centro;
	double grau;

    grau = (angulo * 3.14) / 180;

	switch (tipo){


		case 0:
			matrix[0][0] = 1; matrix[1][1] = 1; matrix[2][2] = 1;matrix[3][3] = 1;
			matrix[3][0]=dx;matrix[3][1]=dy;matrix[3][2]=dz;
			break;

		case 1:
			matrix[0][0] = sx; matrix[1][1] = sy; matrix[2][2] = sz;
			matrix[3][3] = sz;matrix[4][4] = 1;
			break;

		case 2:
			centro = pontoMedioZ();
			CHomo(-centro.x,-centro.y,-centro.z,0,0,0,0,0);

			matrix[2][2] = (cos(grau)); matrix[1][2] = (sin(grau)); matrix[0][0] = 1;
			matrix[1][1] = (cos(grau)); matrix[3][3] = 1; matrix[2][1] = (-sin(grau));

			break;

		case 3:

			centro = pontoMedioZ();
			CHomo(-centro.x,-centro.y,-centro.z,0,0,0,0,0);

			matrix[0][0] = (cos(grau)); matrix[2][0] = (sin(grau)); matrix[3][3] = 1;
			matrix[2][2] = (cos(grau)); matrix[1][1] = 1; matrix[0][2] = (-sin(grau));

			break;


	}




	for(int x=0; x < cord3d.size(); x++ ){

		px=cord3d[x].x;
		py=cord3d[x].y;
		pz=cord3d[x].z;
		poli[0][0] = px;
		poli[0][1] = py;
		poli[0][2] = pz;

		for(int i = 0 ; i < 1 ; i++){
			for(int j=0; j<4 ; j++){

				aux[i][j] = 0;

				for(int k = 0; k<4 ; k++){

					aux[i][j] = aux[i][j] + poli[i][k] * matrix[k][j] ;

				}

			}

		}

		 cord3d[x].x = aux[0][0];
		 cord3d[x].y = aux[0][1];
		 cord3d[x].z = aux[0][2];
	}


	if(tipo == 2 || tipo == 3){CHomo(centro.x,centro.y,centro.z,0,0,0,0,0);}


}





void Poligono::Circunferencia( double xc, double yc, double r, Poligono *aux) {
	double x, y, p;
	x  = 0;
	y = r;

	DesenhaCircunferencia(xc, yc, x, y, aux);
	p = 1 - r;

	while(x<y) {
		if(p<0) {
			x++;
		}
		else {
			x++;
			y--;
		}
		if(p<0) {
			p = p + 2 * x + 1;
		}
		else {
			p = p + 2 * (x - y) + 1;
		}
		DesenhaCircunferencia(xc, yc, x, y, aux);
	}
}

void Poligono::DesenhaCircunferencia(double xc, double yc, double x, double y, Poligono *aux) {

	aux->cord3d.push_back(Cord3D(xc + x, yc + y,0));
	aux->cord3d.push_back(Cord3D(xc - x, yc + y,0));
	aux->cord3d.push_back(Cord3D(xc - y ,yc + x,0));
	aux->cord3d.push_back(Cord3D(xc - y, yc - x,0));
	aux->cord3d.push_back(Cord3D(xc - x, yc - y,0));
	aux->cord3d.push_back(Cord3D(xc + x, yc - y,0));
	aux->cord3d.push_back(Cord3D(xc + y, yc - x,0));
	aux->cord3d.push_back(Cord3D(xc + y, yc + x,0));

}
















int Poligono::Cohen(Janela clipping, double x, double y) {
		int cohem = 0;

		cohem |= (x < clipping.xmin) ?  1 : 0 ;

		cohem |= (x > clipping.xmax) ?  2 : 0;

		cohem |= (y < clipping.ymin) ?  4 : 0;

		cohem |= (y > clipping.ymax) ? 8 : 0;

		return cohem;
	}

Poligono Poligono::Clip(Janela clipping, Poligono pol)
	{
		Poligono aux;
		Cord3D p1, p2;
		int code1, code2, code_out; ;
		for (int i = 1; i < pol.cord3d.size(); i++) {
				p1 = pol.cord3d[i - 1];
				p2 = pol.cord3d[i];
				code1 = Cohen(clipping, p1.x, p1.y);
				code2 = Cohen(clipping, p2.x, p2.y);

				bool accept = false;




				while (accept == false) {
					if ((code1 == 0) && (code2 == 0)) {
								accept = true;

					}
					else
					if (code1 & code2) {
                        break;
					}
					else {

							int code_out;
							double x, y;

							code_out = (code1 != 0) ? code1 : code2;

							if (code_out & 8) {

									x = p1.x + (p2.x - p1.x) *
									(clipping.ymax - p1.y) /
									(p2.y - p1.y);
									y = clipping.ymax;
								}
							else if (code_out & 4) {
									x = p1.x + (p2.x - p1.x) *
									(clipping.ymin - p1.y) /
									(p2.y - p1.y);
									y = clipping.ymin;
								}
							else if (code_out & 2) {
									y = p1.y + (p2.y - p1.y) *
									(clipping.xmax - p1.x) /
									(p2.x - p1.x);
									x = clipping.xmax;
								}
							else if (code_out & 1) {
									y = p1.y + (p2.y - p1.y) *
									(clipping.xmin - p1.x) /
									(p2.x - p1.x);
									x = clipping.xmin;
								}
							if (code_out == code1) {
									p1.x = x;
									p1.y = y;
									code1 = Cohen(clipping,
									p1.x, p1.y);
								}
							else {
									p2.x = x;
									p2.y = y;
									code2 = Cohen(clipping,
									p2.x, p2.y);
								}
						}
				}

				if(accept){
					aux.cord3d.push_back(p1);
					aux.cord3d.push_back(p2);
				}


			}
		return aux;

	}



Poligono Poligono::casteljau(Poligono *pol){

		Poligono curva;
		Poligono aux;
		aux.cord3d.push_back(pol->cord3d[0]);
		aux.cord3d.push_back(pol->cord3d[1]);
		aux.cord3d.push_back(pol->cord3d[2]);
		curva.cord3d.push_back(pol->cord3d[0]);
		desenhaCasteljauRec(&curva, aux);
		return curva;
}
void Poligono::desenhaCasteljauRec(Poligono*curva, Poligono aux) {
	Poligono curvaEsquerda;
	Poligono curvaDireita;
	if (distanciaPontos(aux.cord3d[0], aux.cord3d[2]) < 1) {
			curva->cord3d.push_back(aux.cord3d[0]);
		}
	else {
			subdividirCurva(aux, &curvaEsquerda, &curvaDireita);
			desenhaCasteljauRec(curva, curvaEsquerda);
			desenhaCasteljauRec(curva, curvaDireita);
		}
}

double Poligono::distanciaPontos(Ponto p1, Ponto p2) {
		return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}

void Poligono::subdividirCurva(Poligono aux, Poligono*curvaEsquerda,
	Poligono*curvaDireita) {
	Cord3D pontoMedio1 = pontoMedio(aux.cord3d[0],
		aux.cord3d[1]);
	Cord3D pontoMedio2 = pontoMedio(aux.cord3d[1],
		aux.cord3d[2]);
	Cord3D pontoMedio3 = pontoMedio(pontoMedio1, pontoMedio2);

	curvaEsquerda->cord3d.push_back(aux.cord3d[0]);
	curvaEsquerda->cord3d.push_back(pontoMedio1);
	curvaEsquerda->cord3d.push_back(pontoMedio3);

	curvaDireita->cord3d.push_back(pontoMedio3);
	curvaDireita->cord3d.push_back(pontoMedio2);
	curvaDireita->cord3d.push_back(aux.cord3d[2]);
}


Cord3D Poligono::pontoMedio(Ponto p1, Ponto p2) {
	Cord3D medio;
	medio.x = (p1.x + p2.x) / 2;
	medio.y = (p1.y + p2.y) / 2;
	return medio;
}



void Poligono::hermite(Poligono *pol) {
	double Gx[4], Gy[4];
	int M[4][4] = {2, -2, 1, 1, -3, 3, -2, -1, 0, 0, 1, 0, 1, 0, 0, 0};

	Gx[0] = cord3d[0].x;
	Gx[1] = cord3d[3].x;
	Gx[2] = cord3d[1].x - cord3d[0].x;
	Gx[3] = cord3d[3].x - cord3d[2].x;

	Gy[0] = cord3d[0].y;
	Gy[1] = cord3d[3].y;
	Gy[2] = cord3d[1].y - cord3d[0].y;
	Gy[3] = cord3d[3].y - cord3d[2].y;

	double Cx[4] = {
		Gx[0] * M[0][0] + Gx[1] * M[0][1] + Gx[2] * M[0][2] + Gx[3] * M[0][3],
		Gx[0] * M[1][0] + Gx[1] * M[1][1] + Gx[2] * M[1][2] + Gx[3] * M[1][3],
		Gx[0] * M[2][0] + Gx[1] * M[2][1] + Gx[2] * M[2][2] + Gx[3] * M[2][3],
		Gx[0] * M[3][0] + Gx[1] * M[3][1] + Gx[2] * M[3][2] + Gx[3] * M[3][3]};

	double Cy[4] = {
		Gy[0] * M[0][0] + Gy[1] * M[0][1] + Gy[2] * M[0][2] + Gy[3] * M[0][3],
		Gy[0] * M[1][0] + Gy[1] * M[1][1] + Gy[2] * M[1][2] + Gy[3] * M[1][3],
		Gy[0] * M[2][0] + Gy[1] * M[2][1] + Gy[2] * M[2][2] + Gy[3] * M[2][3],
		Gy[0] * M[3][0] + Gy[1] * M[3][1] + Gy[2] * M[3][2] + Gy[3] * M[3][3]};

	for (float t = 0; t <= 1; t += 0.001) {
		pol->cord3d.push_back(Cord3D((pow(t, 3)*Cx[0]) + (pow(t, 2)*Cx[1]) +
			(t*Cx[2]) + Cx[3], (pow(t, 3)*Cy[0]) + (pow(t, 2)*Cy[1]) +
			(t*Cy[2]) + Cy[3],0));
	}
}

void Poligono::bezier(Poligono *pol) {
	double Gx[4], Gy[4];
	int M[4][4] = {2, -2, 1, 1, -3, 3, -2, -1, 0, 0, 1, 0, 1, 0, 0, 0};

	Gx[0] = cord3d[0].x;
	Gx[1] = cord3d[3].x;
	Gx[2] = 3 * (cord3d[1].x - cord3d[0].x);
	Gx[3] = 3 * (cord3d[3].x - cord3d[2].x);

	Gy[0] = cord3d[0].y;
	Gy[1] = cord3d[3].y;
	Gy[2] = 3 * (cord3d[1].y - cord3d[0].y);
	Gy[3] = 3 * (cord3d[3].y - cord3d[2].y);

	double Cx[4] = {
		Gx[0] * M[0][0] + Gx[1] * M[0][1] + Gx[2] * M[0][2] + Gx[3] * M[0][3],
		Gx[0] * M[1][0] + Gx[1] * M[1][1] + Gx[2] * M[1][2] + Gx[3] * M[1][3],
		Gx[0] * M[2][0] + Gx[1] * M[2][1] + Gx[2] * M[2][2] + Gx[3] * M[2][3],
		Gx[0] * M[3][0] + Gx[1] * M[3][1] + Gx[2] * M[3][2] + Gx[3] * M[3][3]};

	double Cy[4] = {
		Gy[0] * M[0][0] + Gy[1] * M[0][1] + Gy[2] * M[0][2] + Gy[3] * M[0][3],
		Gy[0] * M[1][0] + Gy[1] * M[1][1] + Gy[2] * M[1][2] + Gy[3] * M[1][3],
		Gy[0] * M[2][0] + Gy[1] * M[2][1] + Gy[2] * M[2][2] + Gy[3] * M[2][3],
		Gy[0] * M[3][0] + Gy[1] * M[3][1] + Gy[2] * M[3][2] + Gy[3] * M[3][3]};

	for (float t = 0; t <= 1; t += 0.001) {
		pol->cord3d.push_back(Cord3D((pow(t, 3)*Cx[0]) + (pow(t, 2)*Cx[1]) +
			(t*Cx[2]) + Cx[3], (pow(t, 3)*Cy[0]) + (pow(t, 2)*Cy[1]) +
			(t*Cy[2]) + Cy[3],0));
	}
}

void Poligono::Bspline(Poligono *pol) {
	double xt, yt;
	for (int i = 3; i < cord3d.size(); i++)
		for (double t = 0; t <= 1; t += 0.01) {
			xt = (cord3d[i - 3].x * pow((1 - t), 3)) / 6 +
				(cord3d[i - 2].x * (3 * pow(t, 3) - 6 * pow(t, 2) + 4)) / 6 +
				(cord3d[i - 1].x * (3 * (-1 * pow(t, 3) + pow(t, 2) + t) + 1))
				/ 6 + (cord3d[i].x * pow(t, 3)) / 6;
			yt = (cord3d[i - 3].y * pow((1 - t), 3)) / 6 +
				(cord3d[i - 2].y * (3 * pow(t, 3) - 6 * pow(t, 2) + 4)) / 6 +
				(cord3d[i - 1].y * (3 * (-1 * pow(t, 3) + pow(t, 2) + t) + 1))
				/ 6 + (cord3d[i].y * pow(t, 3)) / 6;
			pol->cord3d.push_back(Cord3D(xt, yt,0));
		}
}

void Poligono::forward(Poligono *pol) {
	double xt, yt;
	float ax, ay, bx, by, cx, cy;

	cx = 3 * (cord3d[1].x - cord3d[0].x);
	cy = 3 * (cord3d[1].y - cord3d[0].y);

	bx = 3 * (cord3d[2].x - cord3d[1].x) - cx;
	by = 3 * (cord3d[2].y - cord3d[1].y) - cy;

	ax = cord3d[3].x - cord3d[0].x - cx - bx;
	ay = cord3d[3].y - cord3d[0].y - cy - by;

	float h = 1.0f / 1000, hh = h * h, hhh = hh * h;
	float d1x, d1y, d2x, d2y, d3x, d3y;

	d1x = ax * hhh + bx * hh + cx * h;
	d1y = ay * hhh + by * hh + cy * h;

	d2x = 6 * ax * hhh + 2 * bx * hh;
	d2y = 6 * ay * hhh + 2 * by * hh;

	d3x = 6 * ax * hhh;
	d3y = 6 * ay * hhh;

	float currentX = cord3d[0].x, currentY = cord3d[0].y;

	for (int i = 1; i < 1000; i++) {
		currentX += d1x;
		currentY += d1y;

		d1x += d2x;
		d1y += d2y;
		d2x += d3x;
		d2y += d3y;

		pol->cord3d.push_back(Cord3D(currentX, currentY,0));
	}

	pol->cord3d.push_back(cord3d[3]);
}
