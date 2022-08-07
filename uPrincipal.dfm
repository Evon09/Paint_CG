object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'UOF7'
  ClientHeight = 565
  ClientWidth = 990
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  PrintScale = poNone
  PixelsPerInch = 96
  TextHeight = 13
  object Footer: TPanel
    Left = 0
    Top = 516
    Width = 990
    Height = 49
    Align = alBottom
    BorderWidth = 20
    TabOrder = 0
    ExplicitWidth = 976
    object lbMundo: TLabel
      Left = 468
      Top = 20
      Width = 40
      Height = 13
      Caption = 'lbMundo'
    end
    object lbVp: TLabel
      Left = 41
      Top = 20
      Width = 20
      Height = 13
      Caption = 'lbVp'
    end
    object Label5: TLabel
      Left = 220
      Top = 27
      Width = 26
      Height = 13
      Caption = 'yMax'
    end
    object Label7: TLabel
      Left = 220
      Top = 8
      Width = 26
      Height = 13
      Caption = 'xMax'
    end
    object Label8: TLabel
      Left = 296
      Top = 8
      Width = 22
      Height = 13
      Caption = 'xMin'
    end
    object Label9: TLabel
      Left = 296
      Top = 27
      Width = 22
      Height = 13
      Caption = 'yMin'
    end
    object xMax: TLabel
      Left = 252
      Top = 8
      Width = 26
      Height = 13
      Caption = 'xMax'
    end
    object xMin: TLabel
      Left = 324
      Top = 9
      Width = 22
      Height = 13
      Caption = 'xMin'
    end
    object yMax: TLabel
      Left = 252
      Top = 27
      Width = 26
      Height = 13
      Caption = 'yMax'
    end
    object yMin: TLabel
      Left = 324
      Top = 27
      Width = 22
      Height = 13
      Caption = 'yMin'
    end
  end
  object Canvas: TPanel
    Left = 22
    Top = 8
    Width = 502
    Height = 502
    TabOrder = 2
    object Image1: TImage
      Left = 1
      Top = 1
      Width = 500
      Height = 500
      Align = alClient
      OnMouseDown = Image1MouseDown
      OnMouseMove = Image1MouseMove
      ExplicitLeft = 7
      ExplicitTop = 19
    end
  end
  object Control: TPanel
    Left = 547
    Top = 0
    Width = 443
    Height = 516
    Align = alRight
    BevelWidth = 2
    TabOrder = 1
    ExplicitLeft = 530
    ExplicitTop = -6
    object Label1: TLabel
      Left = 8
      Top = 27
      Width = 33
      Height = 13
      Caption = 'Pontos'
    end
    object Label2: TLabel
      Left = 9
      Top = 149
      Width = 45
      Height = 13
      Caption = 'Poligonos'
    end
    object lbPoligonos: TListBox
      Left = 8
      Top = 168
      Width = 123
      Height = 97
      ItemHeight = 13
      TabOrder = 0
      OnClick = lbPoligonosClick
    end
    object lbPontos: TListBox
      Left = 8
      Top = 46
      Width = 121
      Height = 97
      ItemHeight = 13
      TabOrder = 1
    end
    object Move: TPanel
      Left = 136
      Top = 197
      Width = 121
      Height = 60
      Align = alCustom
      TabOrder = 2
      object Direita: TButton
        Left = 66
        Top = 32
        Width = 20
        Height = 20
        Caption = #9654
        TabOrder = 0
        OnClick = DireitaClick
      end
      object Subir: TButton
        Left = 40
        Top = 13
        Width = 20
        Height = 20
        Caption = #55357#56636
        TabOrder = 1
        OnClick = SubirClick
      end
      object Descer: TButton
        Left = 40
        Top = 32
        Width = 20
        Height = 20
        Caption = #55357#56637
        TabOrder = 2
        OnClick = DescerClick
      end
      object Esquerda: TButton
        Left = 14
        Top = 32
        Width = 20
        Height = 20
        Caption = #9664
        TabOrder = 3
        OnClick = EsquerdaClick
      end
      object Zoom: TButton
        Left = 92
        Top = 6
        Width = 20
        Height = 20
        Caption = #10133
        TabOrder = 4
        OnClick = ZoomClick
      end
      object ZoomOut: TButton
        Left = 92
        Top = 32
        Width = 20
        Height = 20
        Caption = #10134
        TabOrder = 5
        OnClick = ZoomOutClick
      end
    end
    object rgTipoReta: TRadioGroup
      Left = 8
      Top = 272
      Width = 122
      Height = 116
      Caption = 'Tipo de reta'
      ItemIndex = 0
      Items.Strings = (
        'Move To'
        'DDA'
        'Bresenham')
      TabOrder = 3
      OnClick = rgTipoRetaClick
    end
    object AttMundo: TPanel
      Left = 137
      Top = 27
      Width = 144
      Height = 164
      TabOrder = 4
      object Label3: TLabel
        Left = 96
        Top = 58
        Width = 26
        Height = 13
        Caption = 'yMax'
      end
      object Label4: TLabel
        Left = 95
        Top = 11
        Width = 26
        Height = 13
        Caption = 'xMax'
      end
      object label49: TLabel
        Left = 27
        Top = 12
        Width = 22
        Height = 13
        Caption = 'xMin'
      end
      object Label6: TLabel
        Left = 28
        Top = 58
        Width = 22
        Height = 13
        Caption = 'yMin'
      end
      object Button1: TButton
        Left = 31
        Top = 117
        Width = 81
        Height = 25
        Caption = 'Atualiza Mundo'
        TabOrder = 0
        OnClick = Button1Click
      end
      object edxMax: TEdit
        Left = 87
        Top = 30
        Width = 50
        Height = 21
        TabOrder = 1
        Text = '250'
      end
      object edxMin: TEdit
        Left = 15
        Top = 31
        Width = 50
        Height = 21
        TabOrder = 2
        Text = '-250'
      end
      object edyMax: TEdit
        Left = 87
        Top = 77
        Width = 50
        Height = 21
        TabOrder = 3
        Text = '250'
      end
      object edyMin: TEdit
        Left = 15
        Top = 77
        Width = 50
        Height = 21
        TabOrder = 4
        Text = '-250'
      end
    end
    object Ed: TPanel
      Left = 136
      Top = 319
      Width = 297
      Height = 170
      TabOrder = 5
      object Label10: TLabel
        Left = 24
        Top = 7
        Width = 13
        Height = 13
        Caption = 'DX'
      end
      object Label11: TLabel
        Left = 72
        Top = 7
        Width = 13
        Height = 13
        Caption = 'DY'
      end
      object Label12: TLabel
        Left = 24
        Top = 53
        Width = 12
        Height = 13
        Caption = 'SX'
      end
      object Label13: TLabel
        Left = 72
        Top = 53
        Width = 12
        Height = 13
        Caption = 'SY'
      end
      object Label14: TLabel
        Left = 8
        Top = 112
        Width = 33
        Height = 13
        Caption = 'Angulo'
      end
      object Label15: TLabel
        Left = 168
        Top = 8
        Width = 7
        Height = 13
        Caption = 'H'
      end
      object Label16: TLabel
        Left = 213
        Top = 7
        Width = 7
        Height = 13
        Caption = 'N'
      end
      object Label17: TLabel
        Left = 120
        Top = 7
        Width = 13
        Height = 13
        Caption = 'DZ'
      end
      object Label18: TLabel
        Left = 160
        Top = 96
        Width = 6
        Height = 13
        Caption = 'Z'
      end
      object Label19: TLabel
        Left = 62
        Top = 96
        Width = 6
        Height = 13
        Caption = 'X'
      end
      object Label20: TLabel
        Left = 113
        Top = 96
        Width = 6
        Height = 13
        Caption = 'Y'
      end
      object Label21: TLabel
        Left = 256
        Top = 6
        Width = 13
        Height = 13
        Caption = '3D'
      end
      object Label22: TLabel
        Left = 120
        Top = 53
        Width = 12
        Height = 13
        Caption = 'SZ'
      end
      object edTransladarX: TEdit
        Left = 8
        Top = 26
        Width = 42
        Height = 21
        TabOrder = 0
        Text = '0'
      end
      object edTransladarY: TEdit
        Left = 56
        Top = 26
        Width = 42
        Height = 21
        TabOrder = 1
        Text = '0'
      end
      object Translacao: TButton
        Left = 150
        Top = 26
        Width = 41
        Height = 21
        Caption = 'Tran'
        TabOrder = 2
        OnClick = TranslacaoClick
      end
      object edScalarY: TEdit
        Left = 56
        Top = 69
        Width = 42
        Height = 21
        TabOrder = 3
        Text = '0'
      end
      object edScalarX: TEdit
        Left = 8
        Top = 69
        Width = 42
        Height = 21
        TabOrder = 4
        Text = '0'
      end
      object Escalonamento: TButton
        Left = 150
        Top = 69
        Width = 41
        Height = 21
        Caption = 'Esca'
        TabOrder = 5
        OnClick = EscalonamentoClick
      end
      object edAnguloZ: TEdit
        Left = 143
        Top = 112
        Width = 42
        Height = 21
        TabOrder = 6
        Text = '0'
      end
      object Rotacao: TButton
        Left = 192
        Top = 112
        Width = 41
        Height = 21
        Caption = 'Rota'
        TabOrder = 7
        OnClick = RotacaoClick
      end
      object Button2: TButton
        Left = 191
        Top = 139
        Width = 80
        Height = 25
        Caption = 'Clipping'
        TabOrder = 8
        OnClick = Button2Click
      end
      object Button8: TButton
        Left = 197
        Top = 26
        Width = 41
        Height = 21
        Caption = 'Tran'
        TabOrder = 9
        OnClick = Button8Click
      end
      object Button9: TButton
        Left = 197
        Top = 69
        Width = 41
        Height = 21
        Caption = 'Esca'
        TabOrder = 10
        OnClick = Button9Click
      end
      object Button10: TButton
        Left = 239
        Top = 112
        Width = 41
        Height = 21
        Caption = 'Rota'
        TabOrder = 11
        OnClick = Button10Click
      end
      object Button11: TButton
        Left = 244
        Top = 25
        Width = 39
        Height = 21
        Caption = 'Tran'
        TabOrder = 12
        OnClick = Button11Click
      end
      object Button12: TButton
        Left = 244
        Top = 70
        Width = 42
        Height = 21
        Caption = 'Esca'
        TabOrder = 13
        OnClick = Button12Click
      end
      object edTransladarZ: TEdit
        Left = 104
        Top = 26
        Width = 42
        Height = 21
        TabOrder = 14
        Text = '0'
      end
      object edAnguloX: TEdit
        Left = 47
        Top = 112
        Width = 42
        Height = 21
        TabOrder = 15
        Text = '0'
      end
      object edAnguloY: TEdit
        Left = 95
        Top = 112
        Width = 42
        Height = 21
        TabOrder = 16
        Text = '0'
      end
      object Button13: TButton
        Left = 48
        Top = 139
        Width = 41
        Height = 22
        Caption = 'Rota'
        TabOrder = 17
        OnClick = Button13Click
      end
      object Button14: TButton
        Left = 95
        Top = 139
        Width = 43
        Height = 22
        Caption = 'Rota'
        TabOrder = 18
        OnClick = Button14Click
      end
      object edScalarZ: TEdit
        Left = 104
        Top = 69
        Width = 42
        Height = 21
        TabOrder = 19
        Text = '0'
      end
    end
    object TPanel
      Left = 8
      Top = 394
      Width = 122
      Height = 95
      TabOrder = 6
      object Reflexcima: TButton
        Left = 16
        Top = 25
        Width = 42
        Height = 25
        Caption = #55357#56636#55357#56637
        TabOrder = 0
        OnClick = ReflexcimaClick
      end
      object ReflexLado: TButton
        Left = 64
        Top = 25
        Width = 40
        Height = 25
        Caption = #9664#9654
        TabOrder = 1
        OnClick = ReflexLadoClick
      end
      object ReflexDiagonal: TButton
        Left = 16
        Top = 56
        Width = 89
        Height = 25
        Caption = 'Diagonal'
        TabOrder = 2
        OnClick = ReflexDiagonalClick
      end
    end
    object Panel1: TPanel
      Left = 287
      Top = 27
      Width = 82
      Height = 164
      TabOrder = 7
      object Button3: TButton
        Left = 5
        Top = 7
        Width = 70
        Height = 25
        Caption = 'Casteljau'
        TabOrder = 0
        OnClick = Button3Click
      end
      object Button4: TButton
        Left = 5
        Top = 38
        Width = 70
        Height = 25
        Caption = 'Bezier'
        TabOrder = 1
        OnClick = Button4Click
      end
      object Button5: TButton
        Left = 5
        Top = 69
        Width = 70
        Height = 25
        Caption = 'Hermite'
        TabOrder = 2
        OnClick = Button5Click
      end
      object Button6: TButton
        Left = 5
        Top = 100
        Width = 70
        Height = 25
        Caption = 'Bspline'
        TabOrder = 3
        OnClick = Button6Click
      end
      object Button7: TButton
        Left = 5
        Top = 131
        Width = 70
        Height = 25
        Caption = 'Forward'
        TabOrder = 4
        OnClick = Button7Click
      end
    end
    object Tipo: TPanel
      Left = 137
      Top = 263
      Width = 121
      Height = 50
      TabOrder = 8
      object Linha: TButton
        Left = 8
        Top = 3
        Width = 49
        Height = 25
        Caption = 'Linha'
        Enabled = False
        TabOrder = 0
        OnClick = LinhaClick
      end
      object Circulo: TButton
        Left = 63
        Top = 3
        Width = 49
        Height = 25
        Caption = 'Circulo '
        TabOrder = 1
        OnClick = CirculoClick
      end
      object edRaio: TEdit
        Left = 32
        Top = 29
        Width = 49
        Height = 15
        TabOrder = 2
        Text = '0'
      end
    end
    object Files: TPanel
      Left = 263
      Top = 197
      Width = 106
      Height = 116
      TabOrder = 9
      object edText: TEdit
        Left = 5
        Top = 24
        Width = 92
        Height = 21
        TabOrder = 0
      end
      object btnOpen: TButton
        Left = 16
        Top = 64
        Width = 75
        Height = 25
        Caption = 'Abrir'
        TabOrder = 1
        OnClick = btnOpenClick
      end
    end
  end
end
