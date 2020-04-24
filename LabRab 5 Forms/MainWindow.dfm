object Form1: TForm1
  Left = 0
  Top = 55
  Caption = 'Form1'
  ClientHeight = 480
  ClientWidth = 364
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 58
    Top = 8
    Width = 71
    Height = 13
    Caption = 'Write Numbers'
  end
  object Label2: TLabel
    Left = 167
    Top = 8
    Width = 10
    Height = 13
    Caption = 'or'
  end
  object Label3: TLabel
    Left = 64
    Top = 77
    Width = 26
    Height = 13
    Caption = 'Input'
  end
  object Label4: TLabel
    Left = 272
    Top = 77
    Width = 40
    Height = 13
    Caption = 'New List'
  end
  object Label6: TLabel
    Left = 149
    Top = 229
    Width = 21
    Height = 13
    Caption = 'MAX'
  end
  object Label7: TLabel
    Left = 149
    Top = 189
    Width = 19
    Height = 13
    Caption = 'MIN'
  end
  object EditInput: TEdit
    Left = 29
    Top = 40
    Width = 316
    Height = 21
    TabOrder = 0
  end
  object ButtonOK: TButton
    Left = 149
    Top = 96
    Width = 80
    Height = 41
    Caption = 'OK'
    TabOrder = 1
    OnClick = ButtonOKClick
  end
  object ListBox: TListBox
    Left = 29
    Top = 96
    Width = 100
    Height = 377
    ItemHeight = 13
    TabOrder = 2
  end
  object ButtonRandom: TButton
    Left = 209
    Top = 1
    Width = 107
    Height = 29
    Caption = 'Random'
    TabOrder = 3
    OnClick = ButtonRandomClick
  end
  object ListBoxFirst: TListBox
    Left = 245
    Top = 96
    Width = 100
    Height = 377
    ItemHeight = 13
    TabOrder = 4
  end
  object EditMin: TEdit
    Left = 172
    Top = 186
    Width = 57
    Height = 21
    TabOrder = 5
  end
  object EditMax: TEdit
    Left = 172
    Top = 226
    Width = 57
    Height = 21
    TabOrder = 6
  end
end
