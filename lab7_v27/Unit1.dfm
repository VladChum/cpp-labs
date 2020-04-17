object Form1: TForm1
  Left = 0
  Top = 0
  BorderStyle = bsToolWindow
  Caption = 'Tabel'
  ClientHeight = 336
  ClientWidth = 602
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 9
    Width = 61
    Height = 16
    Caption = #1047#1085#1072#1095#1077#1085#1080#1077':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 33
    Top = 164
    Width = 36
    Height = 16
    Caption = #1050#1083#1102#1095':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 75
    Top = 10
    Width = 202
    Height = 21
    TabOrder = 0
  end
  object ButtonAdd: TButton
    Left = 8
    Top = 47
    Width = 129
    Height = 50
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = ButtonAddClick
  end
  object ButtonDelete: TButton
    Left = 152
    Top = 204
    Width = 125
    Height = 50
    Caption = #1059#1076#1072#1083#1080#1090#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = ButtonDeleteClick
  end
  object ButtonSearch: TButton
    Left = 8
    Top = 205
    Width = 129
    Height = 49
    Caption = #1055#1086#1080#1089#1082
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = ButtonSearchClick
  end
  object ButtonMidlValue: TButton
    Left = 152
    Top = 48
    Width = 125
    Height = 49
    Caption = #1057#1088#1077#1076#1085#1077#1077' '#1079#1085#1072#1095#1077#1085#1080#1077
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = ButtonMidlValueClick
  end
  object Memo1: TMemo
    Left = 294
    Top = 8
    Width = 299
    Height = 313
    Lines.Strings = (
      'Memo1')
    ReadOnly = True
    ScrollBars = ssBoth
    TabOrder = 5
  end
  object Edit2: TEdit
    Left = 75
    Top = 163
    Width = 202
    Height = 21
    TabOrder = 6
  end
  object ButtonClose: TButton
    Left = 202
    Top = 296
    Width = 75
    Height = 25
    Caption = 'Exit'
    TabOrder = 7
    OnClick = ButtonCloseClick
  end
end
