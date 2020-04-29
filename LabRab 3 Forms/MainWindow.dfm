object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'students'
  ClientHeight = 411
  ClientWidth = 770
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object LabelShowAll: TLabel
    Left = 46
    Top = 13
    Width = 126
    Height = 13
    Caption = #1042#1099#1074#1077#1089#1090#1080' '#1074#1089#1077#1093' '#1089#1090#1091#1076#1077#1085#1090#1086#1074
  end
  object LabelShowBySecondName: TLabel
    Left = 16
    Top = 82
    Width = 156
    Height = 13
    Caption = #1042#1099#1074#1077#1089#1090#1080' '#1089#1090#1091#1076#1077#1085#1090#1072' '#1087#1086' '#1092#1072#1084#1080#1083#1080#1080
  end
  object LabelShowByExp: TLabel
    Left = 8
    Top = 143
    Width = 193
    Height = 13
    Caption = #1042#1099#1074#1077#1089#1090#1080' '#1089#1090#1091#1076#1077#1085#1090#1072' '#1089' '#1076#1086#1093#1086#1076#1086#1084' '#1085#1077' '#1085#1084#1078#1077
  end
  object LabelShowByLastName: TLabel
    Left = 6
    Top = 199
    Width = 220
    Height = 13
    Caption = 'C'#1090#1091#1076#1077#1085#1090's '#1089' '#1076#1086#1093#1086#1076#1086#1084' '#1074#1099#1096#1077' '#1076#1074#1091#1093' '#1084#1080#1085#1080#1084#1072#1083#1086#1082
  end
  object LabelEmployee: TLabel
    Left = 622
    Top = 0
    Width = 56
    Height = 13
    Caption = #1057#1086#1090#1088#1091#1076#1085#1080#1082
  end
  object LabelLastName: TLabel
    Left = 527
    Top = 35
    Width = 44
    Height = 13
    Caption = #1060#1072#1084#1080#1083#1080#1103
  end
  object LabelName: TLabel
    Left = 527
    Top = 68
    Width = 19
    Height = 13
    Caption = #1048#1084#1103
  end
  object LabelFatherName: TLabel
    Left = 527
    Top = 101
    Width = 49
    Height = 13
    Caption = #1054#1090#1095#1077#1089#1090#1074#1086
  end
  object LabelGroup: TLabel
    Left = 527
    Top = 143
    Width = 53
    Height = 13
    Caption = #8470' '#1075#1088#1091#1087#1087#1099
  end
  object LabelMaks: TLabel
    Left = 527
    Top = 186
    Width = 65
    Height = 13
    Caption = #1057#1088#1077#1076#1085#1080#1081' '#1073#1072#1083
  end
  object IncomePerson: TLabel
    Left = 519
    Top = 227
    Width = 113
    Height = 13
    Caption = #1044#1086#1093#1086#1076' '#1085#1072' '#1095#1083#1077#1085#1072' '#1089#1077#1084#1100#1080
  end
  object LabelLastNameM: TLabel
    Left = 638
    Top = 35
    Width = 64
    Height = 13
    Caption = '----------------'
  end
  object LabelNameM: TLabel
    Left = 638
    Top = 68
    Width = 64
    Height = 13
    Caption = '----------------'
  end
  object LabelFatherNameM: TLabel
    Left = 638
    Top = 101
    Width = 64
    Height = 13
    Caption = '----------------'
  end
  object LabelMaksM: TLabel
    Left = 638
    Top = 186
    Width = 64
    Height = 13
    Caption = '----------------'
  end
  object LabelGruppM: TLabel
    Left = 638
    Top = 143
    Width = 36
    Height = 13
    Caption = '---------'
  end
  object LabelIncomeM: TLabel
    Left = 646
    Top = 227
    Width = 32
    Height = 13
    Caption = '--------'
  end
  object Label1: TLabel
    Left = 6
    Top = 255
    Width = 167
    Height = 13
    Caption = 'C'#1090#1091#1076#1077#1085#1090#1099' '#1089' '#1089#1088#1077#1076#1085#1080#1084' '#1073#1072#1083#1086#1084' '#1085#1080#1078#1077
  end
  object ListBoxMain: TListBox
    Left = 248
    Top = 8
    Width = 265
    Height = 395
    ItemHeight = 13
    TabOrder = 0
    OnMouseUp = ListBoxMainMouseUp
  end
  object ButtonExit: TButton
    Left = 646
    Top = 376
    Width = 110
    Height = 32
    Caption = #1042#1099#1093#1086#1076
    TabOrder = 1
    OnClick = ButtonExitClick
  end
  object ButtonShowAllOK: TButton
    Left = 54
    Top = 32
    Width = 98
    Height = 33
    Caption = #1054#1050
    TabOrder = 2
    OnClick = ButtonShowAllOKClick
  end
  object ButtonShowByIncomeTwoOK: TButton
    Left = 153
    Top = 218
    Width = 89
    Height = 33
    Caption = #1054#1050
    TabOrder = 3
    OnClick = ButtonShowByIncomeTwoOKClick
  end
  object EditShowByIncomeTwo: TEdit
    Left = 6
    Top = 228
    Width = 141
    Height = 21
    TabOrder = 4
  end
  object EditShowByIncome: TEdit
    Left = 6
    Top = 168
    Width = 141
    Height = 21
    TabOrder = 5
  end
  object ButtonShowByIncomeOK: TButton
    Left = 153
    Top = 162
    Width = 89
    Height = 33
    Caption = #1054#1050
    TabOrder = 6
    OnClick = ButtonShowByIncomeOKClick
  end
  object EditShowByLastName: TEdit
    Left = 6
    Top = 101
    Width = 141
    Height = 21
    TabOrder = 7
  end
  object ButtonShowByLastNameOK: TButton
    Left = 153
    Top = 101
    Width = 89
    Height = 33
    Caption = #1054#1050
    TabOrder = 8
    OnClick = ButtonShowByLastNameOKClick
  end
  object EditLastName: TEdit
    Left = 638
    Top = 32
    Width = 118
    Height = 21
    TabOrder = 9
    Visible = False
  end
  object EditName: TEdit
    Left = 638
    Top = 65
    Width = 118
    Height = 21
    TabOrder = 10
    Visible = False
  end
  object EditFatherName: TEdit
    Left = 638
    Top = 98
    Width = 118
    Height = 21
    TabOrder = 11
    Visible = False
  end
  object EditGrupp: TEdit
    Left = 638
    Top = 140
    Width = 84
    Height = 21
    TabOrder = 12
    Visible = False
  end
  object EditMaks: TEdit
    Left = 638
    Top = 183
    Width = 84
    Height = 21
    TabOrder = 13
    Visible = False
  end
  object ButtonDelete: TButton
    Left = 646
    Top = 338
    Width = 110
    Height = 32
    Caption = #1059#1076#1072#1083#1080#1090#1100
    TabOrder = 14
    OnClick = ButtonDeleteClick
  end
  object ButtonAdd: TButton
    Left = 533
    Top = 338
    Width = 110
    Height = 32
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100
    TabOrder = 15
    OnClick = ButtonAddClick
  end
  object ButtonAddOK: TButton
    Left = 622
    Top = 268
    Width = 49
    Height = 32
    Caption = #1054#1050
    TabOrder = 16
    Visible = False
    OnClick = ButtonAddOKClick
  end
  object EditIncome: TEdit
    Left = 638
    Top = 224
    Width = 84
    Height = 21
    TabOrder = 17
    Visible = False
  end
  object ButtonOpenFile: TButton
    Left = 15
    Top = 371
    Width = 95
    Height = 32
    Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100
    TabOrder = 18
    OnClick = ButtonOpenFileClick
  end
  object ButtonSaveFile: TButton
    Left = 131
    Top = 371
    Width = 95
    Height = 32
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
    TabOrder = 19
    OnClick = ButtonSaveFileClick
  end
  object EditShowByMaks: TEdit
    Left = 6
    Top = 280
    Width = 141
    Height = 21
    TabOrder = 20
  end
  object OpenFile: TOpenDialog
    Filter = '|*.txt'
    Left = 47
    Top = 323
  end
  object SaveFile: TSaveDialog
    Filter = '|*.txt'
    Left = 151
    Top = 323
  end
end
