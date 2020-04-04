object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 260
  ClientWidth = 390
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object LabelTranslated: TLabel
    Left = 7
    Top = 92
    Width = 23
    Height = 16
    Caption = #1055#1060':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object LabelAnswer: TLabel
    Left = 8
    Top = 180
    Width = 40
    Height = 16
    Caption = #1054#1090#1074#1077#1090':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object LabelExercise: TLabel
    Left = 8
    Top = 9
    Width = 49
    Height = 16
    Caption = #1055#1088#1080#1084#1077#1088':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object LabelA: TLabel
    Left = 8
    Top = 49
    Width = 13
    Height = 16
    Caption = #1040':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object LabelB: TLabel
    Left = 80
    Top = 49
    Width = 12
    Height = 16
    Caption = 'B:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object LabelC: TLabel
    Left = 149
    Top = 49
    Width = 13
    Height = 16
    Caption = 'C:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object LabelD: TLabel
    Left = 229
    Top = 49
    Width = 13
    Height = 16
    Caption = 'D:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object LabelE: TLabel
    Left = 304
    Top = 49
    Width = 12
    Height = 16
    Caption = 'E:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object EditForEx: TEdit
    Left = 60
    Top = 8
    Width = 309
    Height = 21
    TabOrder = 0
  end
  object EditTranslated: TEdit
    Left = 36
    Top = 91
    Width = 333
    Height = 21
    TabOrder = 1
  end
  object ButtonToSolve: TButton
    Left = 60
    Top = 129
    Width = 289
    Height = 33
    Caption = #1056#1072#1089#1089#1095#1080#1090#1072#1090#1100
    TabOrder = 2
    OnClick = ButtonToSolveClick
  end
  object ButtonClear: TButton
    Left = 8
    Top = 214
    Width = 89
    Height = 25
    Caption = #1054#1095#1080#1089#1090#1080#1090#1100
    TabOrder = 3
    OnClick = ButtonClearClick
  end
  object ButtonExit: TButton
    Left = 280
    Top = 214
    Width = 89
    Height = 25
    Caption = #1042#1099#1093#1086#1076
    TabOrder = 4
    OnClick = ButtonExitClick
  end
  object EditAnswer: TEdit
    Left = 63
    Top = 179
    Width = 234
    Height = 21
    TabOrder = 5
  end
  object EditA: TEdit
    Left = 27
    Top = 48
    Width = 46
    Height = 21
    TabOrder = 6
  end
  object EditB: TEdit
    Left = 99
    Top = 48
    Width = 46
    Height = 21
    TabOrder = 7
  end
  object EditC: TEdit
    Left = 168
    Top = 48
    Width = 49
    Height = 21
    TabOrder = 8
  end
  object EditD: TEdit
    Left = 248
    Top = 48
    Width = 46
    Height = 21
    TabOrder = 9
  end
  object EditE: TEdit
    Left = 323
    Top = 48
    Width = 46
    Height = 21
    TabOrder = 10
  end
end
