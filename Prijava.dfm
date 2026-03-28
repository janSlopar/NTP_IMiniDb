object FormPrijava: TFormPrijava
  Left = 0
  Top = 0
  Caption = 'Prijava'
  ClientHeight = 638
  ClientWidth = 1131
  Color = clBisque
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object GroupBoxPrijava: TGroupBox
    Left = 360
    Top = 160
    Width = 361
    Height = 225
    TabOrder = 0
    object Label1: TLabel
      Left = 64
      Top = 40
      Width = 81
      Height = 15
      Caption = 'Korisni'#269'ko ime:'
    end
    object Label2: TLabel
      Left = 64
      Top = 80
      Width = 40
      Height = 15
      Caption = 'lozinka:'
    end
    object ButtonPrijava: TButton
      Left = 64
      Top = 160
      Width = 225
      Height = 25
      Caption = 'Prijavi se!'
      TabOrder = 0
      OnClick = ButtonPrijavaClick
    end
    object EditKorImePrijava: TEdit
      Left = 167
      Top = 37
      Width = 121
      Height = 23
      TabOrder = 1
    end
    object EditLozinkaPrijava: TEdit
      Left = 167
      Top = 74
      Width = 121
      Height = 23
      PasswordChar = '*'
      TabOrder = 2
    end
  end
end
