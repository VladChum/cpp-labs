object Form1: TForm1
  Left = 0
  Top = 0
  BorderStyle = bsToolWindow
  Caption = #1044#1077#1088#1077#1074#1086
  ClientHeight = 561
  ClientWidth = 745
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
    Left = 64
    Top = 8
    Width = 71
    Height = 19
    Caption = #1060#1072#1084#1080#1083#1080#1103':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 3
    Top = 50
    Width = 123
    Height = 19
    Caption = #1053#1086#1084#1077#1088' '#1089#1090#1091#1076#1077#1085#1090#1072':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object TreeView1: TTreeView
    Left = 3
    Top = 285
    Width = 505
    Height = 271
    Indent = 19
    TabOrder = 0
  end
  object StringGrid1: TStringGrid
    Left = 254
    Top = 8
    Width = 254
    Height = 271
    ColCount = 2
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 1
    ColWidths = (
      114
      133)
  end
  object EditSecondName: TEdit
    Left = 141
    Top = 10
    Width = 107
    Height = 21
    TabOrder = 2
  end
  object EditNumber: TEdit
    Left = 141
    Top = 52
    Width = 107
    Height = 21
    TabOrder = 3
  end
  object Memo1: TMemo
    Left = 514
    Top = 8
    Width = 223
    Height = 271
    Lines.Strings = (
      'Memo1')
    ReadOnly = True
    ScrollBars = ssVertical
    TabOrder = 4
  end
  object Button5: TButton
    Left = 514
    Top = 367
    Width = 223
    Height = 34
    Caption = #1055#1088#1103#1084#1086#1081' '#1086#1073#1093#1086#1076
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 514
    Top = 285
    Width = 223
    Height = 36
    Caption = #1054#1073#1088#1072#1090#1085#1099#1081' '#1086#1073#1093#1086#1076
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 514
    Top = 327
    Width = 223
    Height = 34
    Caption = #1055#1086' '#1074#1086#1079#1088#1072#1089#1090#1072#1085#1080#1102
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
    OnClick = Button7Click
  end
  object ButtonExit: TButton
    Left = 648
    Top = 520
    Width = 89
    Height = 36
    Caption = 'Exit'
    TabOrder = 8
    OnClick = ButtonExitClick
  end
  object ButtonDelete: TButton
    Left = 141
    Top = 81
    Width = 107
    Height = 27
    Caption = #1059#1076#1072#1083#1080#1090#1100
    Enabled = False
    TabOrder = 9
    OnClick = ButtonDeleteClick
  end
  object ButtonAddClick: TButton
    Left = 3
    Top = 81
    Width = 123
    Height = 27
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100
    TabOrder = 10
    OnClick = ButtonAddClickClick
  end
  object ButtonScan: TButton
    Left = 3
    Top = 114
    Width = 245
    Height = 31
    Caption = #1055#1086#1080#1089#1082
    Enabled = False
    TabOrder = 11
    OnClick = ButtonScanClick
  end
  object ButtonBalansing: TButton
    Left = 3
    Top = 184
    Width = 245
    Height = 35
    Caption = #1041#1072#1083#1072#1085#1089#1080#1088#1086#1074#1082#1072
    Enabled = False
    TabOrder = 12
    OnClick = ButtonBalansingClick
  end
  object ButtonMidl: TButton
    Left = 3
    Top = 225
    Width = 245
    Height = 40
    Caption = #1057#1088#1077#1076#1085#1077#1077' '#1079#1085#1072#1095#1077#1085#1080#1077
    Enabled = False
    TabOrder = 13
    OnClick = ButtonMidlClick
  end
end
