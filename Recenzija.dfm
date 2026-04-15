object FormRecenzija: TFormRecenzija
  Left = 0
  Top = 0
  Caption = 'FormRecenzija'
  ClientHeight = 921
  ClientWidth = 1339
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnCreate = FormCreate
  TextHeight = 15
  object GroupBoxRecenzija: TGroupBox
    Left = 96
    Top = 56
    Width = 1041
    Height = 689
    TabOrder = 0
    object Label1: TLabel
      Left = 384
      Top = 273
      Width = 88
      Height = 15
      Caption = 'Datum recenzije:'
    end
    object Label2: TLabel
      Left = 435
      Top = 307
      Width = 26
      Height = 15
      Caption = 'Film:'
    end
    object Label4: TLabel
      Left = 328
      Top = 168
      Width = 40
      Height = 15
      Caption = 'Ocjena:'
    end
    object LabelOcjena: TLabel
      Left = 392
      Top = 200
      Width = 6
      Height = 15
      Caption = '1'
    end
    object LabelOcjena2: TLabel
      Left = 424
      Top = 200
      Width = 6
      Height = 15
      Caption = '2'
    end
    object LabelOcjena3: TLabel
      Left = 455
      Top = 200
      Width = 6
      Height = 15
      Caption = '3'
    end
    object LabelOcjena4: TLabel
      Left = 488
      Top = 200
      Width = 6
      Height = 15
      Caption = '4'
    end
    object LabelOcjena5: TLabel
      Left = 520
      Top = 200
      Width = 6
      Height = 15
      Caption = '5'
    end
    object LabelOcjena6: TLabel
      Left = 552
      Top = 200
      Width = 6
      Height = 15
      Caption = '6'
    end
    object LabelOcjena7: TLabel
      Left = 584
      Top = 200
      Width = 6
      Height = 15
      Caption = '7'
    end
    object LabelOcjena8: TLabel
      Left = 616
      Top = 200
      Width = 6
      Height = 15
      Caption = '8'
    end
    object LabelOcjena9: TLabel
      Left = 648
      Top = 200
      Width = 6
      Height = 15
      Caption = '9'
    end
    object LabelOcjena10: TLabel
      Left = 672
      Top = 200
      Width = 12
      Height = 15
      Caption = '10'
    end
    object ButtonSpremiRecenziju: TButton
      Left = 288
      Top = 528
      Width = 225
      Height = 94
      Caption = 'Spremi'
      TabOrder = 0
      OnClick = ButtonSpremiRecenzijuClick
    end
    object ButtonOdustani: TButton
      Left = 544
      Top = 528
      Width = 225
      Height = 94
      Caption = 'Odustani'
      TabOrder = 1
      OnClick = ButtonOdustaniClick
    end
    object memTekst: TMemo
      Left = 288
      Top = 365
      Width = 481
      Height = 97
      Lines.Strings = (
        'memTekst')
      TabOrder = 2
    end
    object dtpDatum: TDateTimePicker
      Left = 495
      Top = 265
      Width = 186
      Height = 23
      Date = 46109.000000000000000000
      Time = 0.531559131944959500
      TabOrder = 3
    end
    object edtFilm: TEdit
      Left = 495
      Top = 304
      Width = 186
      Height = 23
      TabOrder = 4
    end
    object TrackBarOcjena: TTrackBar
      Left = 384
      Top = 168
      Width = 310
      Height = 45
      Min = 1
      Position = 1
      TabOrder = 5
    end
  end
  object cmbFilm: TComboBox
    Left = 563
    Top = 114
    Width = 145
    Height = 23
    TabOrder = 1
    OnChange = cmbFilmChange
  end
end
