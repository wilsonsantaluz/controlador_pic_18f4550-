object Form1: TForm1
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'Pic Controler'
  ClientHeight = 477
  ClientWidth = 609
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 0
    Top = 0
    Width = 609
    Height = 477
    Align = alClient
    Color = 8454143
    ParentBackground = False
    ParentColor = False
    TabOrder = 0
    ExplicitWidth = 466
    ExplicitHeight = 397
    object Label1: TLabel
      Left = 8
      Top = 3
      Width = 56
      Height = 13
      Caption = 'Dispositivos'
    end
    object Label2: TLabel
      Left = 8
      Top = 82
      Width = 42
      Height = 13
      Caption = 'Detalhes'
    end
    object Label3: TLabel
      Left = 8
      Top = 244
      Width = 39
      Height = 13
      Caption = 'Retorno'
    end
    object Label4: TLabel
      Left = 100
      Top = 423
      Width = 18
      Height = 13
      Caption = 'B00'
    end
    object Label5: TLabel
      Left = 146
      Top = 423
      Width = 18
      Height = 13
      Caption = 'B01'
    end
    object Label6: TLabel
      Left = 178
      Top = 423
      Width = 18
      Height = 13
      Caption = 'B02'
    end
    object Label7: TLabel
      Left = 210
      Top = 423
      Width = 18
      Height = 13
      Caption = 'B03'
    end
    object Label8: TLabel
      Left = 242
      Top = 423
      Width = 18
      Height = 13
      Caption = 'B04'
    end
    object Label9: TLabel
      Left = 274
      Top = 423
      Width = 18
      Height = 13
      Caption = 'B05'
    end
    object Label10: TLabel
      Left = 306
      Top = 423
      Width = 18
      Height = 13
      Caption = 'B06'
    end
    object Label11: TLabel
      Left = 339
      Top = 423
      Width = 18
      Height = 13
      Caption = 'B07'
    end
    object Label12: TLabel
      Left = 371
      Top = 423
      Width = 18
      Height = 13
      Caption = 'B08'
    end
    object ListBox2: TListBox
      Left = 8
      Top = 22
      Width = 353
      Height = 46
      Color = clWhite
      ItemHeight = 13
      TabOrder = 0
      OnClick = ListBox2Click
    end
    object ListBox1: TListBox
      Left = 8
      Top = 101
      Width = 353
      Height = 97
      ItemHeight = 13
      TabOrder = 1
    end
    object Memo1: TMemo
      Left = 8
      Top = 297
      Width = 444
      Height = 97
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      ScrollBars = ssVertical
      TabOrder = 2
    end
    object Button2: TButton
      Left = 85
      Top = 200
      Width = 75
      Height = 28
      Caption = 'Detalhes...'
      TabOrder = 3
      OnClick = Button2Click
    end
    object Button3: TButton
      Left = 8
      Top = 400
      Width = 75
      Height = 25
      Caption = 'Enviar ->'
      TabOrder = 4
      OnClick = Button3Click
    end
    object Edit1: TEdit
      Left = 97
      Top = 400
      Width = 30
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      MaxLength = 3
      ParentFont = False
      TabOrder = 5
      Text = '00'
      OnKeyPress = Edit1KeyPress
    end
    object Edit2: TEdit
      Left = 143
      Top = 400
      Width = 30
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      MaxLength = 3
      ParentFont = False
      TabOrder = 6
      Text = '00'
      OnKeyPress = Edit2KeyPress
    end
    object Edit3: TEdit
      Left = 175
      Top = 400
      Width = 30
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      MaxLength = 3
      ParentFont = False
      TabOrder = 7
      Text = '00'
      OnKeyPress = Edit3KeyPress
    end
    object Edit4: TEdit
      Left = 207
      Top = 400
      Width = 30
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      MaxLength = 3
      ParentFont = False
      TabOrder = 8
      Text = '00'
      OnKeyPress = Edit4KeyPress
    end
    object Edit5: TEdit
      Left = 239
      Top = 400
      Width = 30
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      MaxLength = 3
      ParentFont = False
      TabOrder = 9
      Text = '00'
      OnKeyPress = Edit5KeyPress
    end
    object Edit6: TEdit
      Left = 271
      Top = 400
      Width = 30
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      MaxLength = 3
      ParentFont = False
      TabOrder = 10
      Text = '00'
      OnKeyPress = Edit6KeyPress
    end
    object Edit7: TEdit
      Left = 303
      Top = 400
      Width = 30
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      MaxLength = 3
      ParentFont = False
      TabOrder = 11
      Text = '00'
      OnKeyPress = Edit7KeyPress
    end
    object Edit8: TEdit
      Left = 335
      Top = 400
      Width = 30
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      MaxLength = 3
      ParentFont = False
      TabOrder = 12
      Text = '00'
      OnKeyPress = Edit8KeyPress
    end
    object Button1: TButton
      Left = 8
      Top = 199
      Width = 75
      Height = 28
      Caption = 'Reset'
      TabOrder = 13
      OnClick = Button1Click
    end
    object Edit9: TEdit
      Left = 8
      Top = 260
      Width = 444
      Height = 21
      Font.Charset = ANSI_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      ReadOnly = True
      TabOrder = 14
    end
    object Button4: TButton
      Left = 367
      Top = 53
      Width = 75
      Height = 25
      Caption = 'Apaga Led'
      TabOrder = 15
      OnClick = Button4Click
    end
    object Button5: TButton
      Left = 367
      Top = 22
      Width = 75
      Height = 25
      Caption = 'Acende Led'
      TabOrder = 16
      OnClick = Button5Click
    end
    object Edit10: TEdit
      Left = 367
      Top = 400
      Width = 30
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      MaxLength = 3
      ParentFont = False
      TabOrder = 17
      Text = '00'
      OnKeyPress = Edit8KeyPress
    end
  end
  object XPManifest1: TXPManifest
    Left = 448
    Top = 360
  end
end
