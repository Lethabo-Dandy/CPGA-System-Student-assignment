object frmAssignm: TfrmAssignm
  Left = 0
  Top = 0
  Caption = '  Student'#39's Assignments'
  ClientHeight = 362
  ClientWidth = 407
  Color = clSilver
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label9: TLabel
    Left = 8
    Top = 22
    Width = 196
    Height = 24
    Caption = 'Captured Assignments'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clPurple
    Font.Height = -19
    Font.Name = 'Trebuchet MS'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label14: TLabel
    Left = 8
    Top = 62
    Width = 391
    Height = 16
    Caption = 
      'Name && Surname    Code     Ass1       Ass2       Ass3       Ass' +
      '4        Ass5       Ass6'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -11
    Font.Name = 'Sitka Text Semibold'
    Font.Style = []
    ParentFont = False
  end
  object lstResults: TListBox
    Left = 8
    Top = 81
    Width = 391
    Height = 167
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = []
    ItemHeight = 14
    ParentFont = False
    TabOrder = 0
    TabWidth = 26
    OnClick = lstResultsClick
  end
  object pnlCompFinalScore: TPanel
    Left = 9
    Top = 254
    Width = 390
    Height = 47
    TabOrder = 1
    object Label10: TLabel
      Left = 14
      Top = 13
      Width = 96
      Height = 20
      Caption = 'Student'#39's Avg'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -15
      Font.Name = 'Trebuchet MS'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label11: TLabel
      Left = 164
      Top = 13
      Width = 33
      Height = 18
      Caption = 'Code'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      WordWrap = True
    end
    object Label12: TLabel
      Left = 278
      Top = 13
      Width = 54
      Height = 18
      Caption = 'Average'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      WordWrap = True
    end
    object lblAverage: TLabel
      Left = 340
      Top = 12
      Width = 29
      Height = 19
      Caption = 'avg'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clPurple
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      WordWrap = True
    end
    object imgLet1: TImage
      Left = 203
      Top = 5
      Width = 24
      Height = 30
    end
    object imgLet2: TImage
      Left = 226
      Top = 5
      Width = 24
      Height = 30
    end
    object imgLet3: TImage
      Left = 249
      Top = 5
      Width = 24
      Height = 30
    end
  end
  object btnBest: TButton
    Left = 212
    Top = 307
    Width = 187
    Height = 25
    Caption = 'Best Student?'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clMaroon
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
    OnClick = btnBestClick
  end
  object btnSaveResultsToFile: TButton
    Left = 228
    Top = 37
    Width = 170
    Height = 25
    Caption = 'Save to File "Assigns(N).txt"'
    TabOrder = 3
    OnClick = btnSaveResultsToFileClick
  end
  object btnRead: TButton
    Left = 228
    Top = 7
    Width = 170
    Height = 25
    Caption = 'Read Student'#39's Assignments'
    TabOrder = 4
    OnClick = btnReadClick
  end
  object btnValidate: TButton
    Left = 8
    Top = 307
    Width = 198
    Height = 25
    Caption = 'Validate Student Code'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 5
    OnClick = btnValidateClick
  end
  object pnlFaulty: TPanel
    Left = 0
    Top = 340
    Width = 407
    Height = 22
    Align = alBottom
    Color = clLime
    ParentBackground = False
    TabOrder = 6
    Visible = False
    object Label1: TLabel
      Left = 8
      Top = 4
      Width = 170
      Height = 13
      Caption = 'Line numbers for faulty codes '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object edtFaulty: TEdit
      Left = 189
      Top = 1
      Width = 217
      Height = 20
      Align = alRight
      TabOrder = 0
      ExplicitHeight = 21
    end
  end
end
