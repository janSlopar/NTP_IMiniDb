object FormSviFilmovi: TFormSviFilmovi
  Left = 0
  Top = 0
  ClientHeight = 1000
  ClientWidth = 1257
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnCreate = FormCreate
  TextHeight = 15
  object Label6: TLabel
    Left = 780
    Top = 147
    Width = 62
    Height = 15
    Caption = 'Naziv filma:'
  end
  object Label7: TLabel
    Left = 801
    Top = 176
    Width = 41
    Height = 15
    Caption = 'Godina:'
  end
  object Image1: TImage
    Left = 871
    Top = 520
    Width = 386
    Height = 481
  end
  object Label8: TLabel
    Left = 798
    Top = 213
    Width = 44
    Height = 15
    Caption = 'Trajanje:'
  end
  object Label9: TLabel
    Left = 815
    Top = 239
    Width = 27
    Height = 15
    Caption = 'Opis:'
  end
  object ButtonDodajWatchlistu: TButton
    Left = 275
    Top = 8
    Width = 145
    Height = 57
    Caption = 'Dodaj u Listu'
    TabOrder = 0
  end
  object EditNoviNaziv: TEdit
    Left = 864
    Top = 144
    Width = 177
    Height = 23
    TabOrder = 1
  end
  object EditNovaGodina: TEdit
    Left = 864
    Top = 173
    Width = 177
    Height = 23
    TabOrder = 2
  end
  object ButtonOmiljeniFilmovi: TButton
    Left = 1099
    Top = 144
    Width = 145
    Height = 57
    Caption = 'Omiljeni Filmovi'
    TabOrder = 3
    OnClick = ButtonOmiljeniFilmoviClick
  end
  object listViewOFilmovi: TListView
    Left = 7
    Top = 495
    Width = 858
    Height = 497
    Columns = <
      item
        Caption = 'Naslov'
      end
      item
        Caption = 'Godina'
      end
      item
        Caption = 'Trajanje'
      end
      item
        Caption = 'Opis'
      end>
    HideSelection = False
    TabOrder = 4
    ViewStyle = vsReport
  end
  object ButtonHRV: TButton
    Left = 1110
    Top = 8
    Width = 134
    Height = 34
    Caption = 'Hrvatski'
    TabOrder = 5
    OnClick = ButtonHRVClick
  end
  object ButtonENG: TButton
    Left = 1110
    Top = 48
    Width = 134
    Height = 34
    Caption = 'English'
    TabOrder = 6
    OnClick = ButtonENGClick
  end
  object ButtonDodajNoviOFilm: TButton
    Left = 1099
    Top = 207
    Width = 150
    Height = 58
    Caption = 'Dodaj novi'
    TabOrder = 7
    OnClick = ButtonDodajNoviOFilmClick
  end
  object ButtonUkloni: TButton
    Left = 1099
    Top = 271
    Width = 150
    Height = 58
    Caption = 'Ukloni '
    TabOrder = 8
    OnClick = ButtonUkloniClick
  end
  object EditNovoTrajanje: TEdit
    Left = 864
    Top = 207
    Width = 177
    Height = 23
    TabOrder = 9
  end
  object MemoOpisNovogFilma: TMemo
    Left = 864
    Top = 236
    Width = 177
    Height = 93
    Lines.Strings = (
      'MemoOpisNovogFilma')
    TabOrder = 10
  end
  object XMLDocumentOmiljeniFilmovi: TXMLDocument
    FileName = 'C:\Users\Jan\Desktop\4sem\NTP\omiljeniFilmovi.xml'
    Left = 416
    Top = 672
  end
end
