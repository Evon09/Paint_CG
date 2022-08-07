//---------------------------------------------------------------------------

#ifndef uPrincipalH
#define uPrincipalH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtDlgs.hpp>
#include "SHDocVw_OCX.h"
#include <Vcl.OleCtrls.hpp>
#include <Vcl.FileCtrl.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Canvas;
	TImage *Image1;
	TLabel *lbVp;
	TLabel *lbMundo;
	TListBox *lbPontos;
	TLabel *Label1;
	TListBox *lbPoligonos;
	TLabel *Label2;
	TEdit *edxMin;
	TEdit *edxMax;
	TEdit *edyMin;
	TEdit *edyMax;
	TLabel *label49;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TButton *Button1;
	TButton *Direita;
	TButton *Subir;
	TButton *Descer;
	TButton *Esquerda;
	TPanel *Move;
	TButton *Zoom;
	TButton *ZoomOut;
	TPanel *Control;
	TPanel *Footer;
	TLabel *xMin;
	TLabel *yMin;
	TLabel *xMax;
	TLabel *yMax;
	TLabel *Label3;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TRadioGroup *rgTipoReta;
	TPanel *AttMundo;
	TPanel *Ed;
	TEdit *edTransladarX;
	TEdit *edTransladarY;
	TButton *Translacao;
	TEdit *edScalarY;
	TEdit *edScalarX;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TLabel *Label13;
	TButton *Escalonamento;
	TEdit *edAnguloZ;
	TButton *Rotacao;
	TLabel *Label14;
	TButton *Reflexcima;
	TButton *ReflexLado;
	TButton *ReflexDiagonal;
	TButton *Button2;
	TPanel *Panel1;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TButton *Button7;
	TButton *Button8;
	TButton *Button9;
	TButton *Button10;
	TLabel *Label15;
	TLabel *Label16;
	TButton *Linha;
	TPanel *Tipo;
	TButton *Circulo;
	TEdit *edRaio;
	TButton *Button11;
	TButton *Button12;
	TEdit *edTransladarZ;
	TLabel *Label17;
	TEdit *edAnguloX;
	TEdit *edAnguloY;
	TLabel *Label18;
	TLabel *Label19;
	TLabel *Label20;
	TButton *Button13;
	TButton *Button14;
	TLabel *Label21;
	TEdit *edScalarZ;
	TLabel *Label22;
	TPanel *Files;
	TEdit *edText;
	TButton *btnOpen;
	void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall lbPoligonosClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall ZoomClick(TObject *Sender);
	void __fastcall ZoomOutClick(TObject *Sender);
	void __fastcall SubirClick(TObject *Sender);
	void __fastcall DescerClick(TObject *Sender);
	void __fastcall EsquerdaClick(TObject *Sender);
	void __fastcall DireitaClick(TObject *Sender);
	void __fastcall rgTipoRetaClick(TObject *Sender);
	void __fastcall TranslacaoClick(TObject *Sender);
	void __fastcall EscalonamentoClick(TObject *Sender);
	void __fastcall RotacaoClick(TObject *Sender);
	void __fastcall ReflexcimaClick(TObject *Sender);
	void __fastcall ReflexLadoClick(TObject *Sender);
	void __fastcall ReflexDiagonalClick(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall LinhaClick(TObject *Sender);
	void __fastcall CirculoClick(TObject *Sender);
	void __fastcall Button11Click(TObject *Sender);
	void __fastcall Button12Click(TObject *Sender);
	void __fastcall Button13Click(TObject *Sender);
	void __fastcall Button14Click(TObject *Sender);
	void __fastcall FileopenFolderChange(TObject *Sender);
	void __fastcall btnOpenClick(TObject *Sender);

private:	// User declarations

public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
	double xVp2W(int x, Janela mundo, Janela vp);
	double yVp2W(int y, Janela mundo, Janela vp);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
