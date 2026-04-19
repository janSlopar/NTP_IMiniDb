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
      Left = 143
      Top = 528
      Width = 225
      Height = 94
      Caption = 'Spremi'
      TabOrder = 0
      OnClick = ButtonSpremiRecenzijuClick
    end
    object ButtonOdustani: TButton
      Left = 435
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
    object ButtonPDF: TButton
      Left = 720
      Top = 528
      Width = 217
      Height = 94
      Caption = 'PDF'
      TabOrder = 6
      OnClick = ButtonPDFClick
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
  object frxReportRecenzija: TfrxReport
    Version = '2024.1.2'
    DotMatrixReport = False
    IniFile = '\Software\Fast Reports'
    PreviewOptions.Buttons = [pbPrint, pbLoad, pbSave, pbExport, pbZoom, pbFind, pbOutline, pbPageSetup, pbTools, pbEdit, pbNavigator, pbExportQuick, pbCopy, pbSelection, pbWatermarks]
    PreviewOptions.Zoom = 1.000000000000000000
    PrintOptions.Printer = 'Default'
    PrintOptions.PrintOnSheet = 0
    ReportOptions.CreateDate = 46130.617870405090000000
    ReportOptions.LastChange = 46130.617870405090000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      'begin'
      ''
      'end.')
    Left = 1216
    Top = 112
    Datasets = <>
    Variables = <>
    Style = <>
    Watermarks = <>
    object Data: TfrxDataPage
      Height = 1000.000000000000000000
      Width = 1000.000000000000000000
    end
    object Page1: TfrxReportPage
      PaperWidth = 215.900000000000000000
      PaperHeight = 279.400000000000000000
      PaperSize = 1
      LeftMargin = 10.000000000000000000
      RightMargin = 10.000000000000000000
      TopMargin = 10.000000000000000000
      BottomMargin = 10.000000000000000000
      Frame.Typ = []
      MirrorMode = []
    end
  end
  object FDConnectionIMiniDB: TFDConnection
    Params.Strings = (
      'Database=iminidb'
      'User_Name=root'
      'Password=admin'
      'DriverID=MySQL')
    Connected = True
    LoginPrompt = False
    Left = 1208
    Top = 208
  end
  object FDQueryUnosRecenzije: TFDQuery
    Connection = FDConnectionIMiniDB
    Left = 8
    Top = 16
  end
  object FDPhysMySQLDriverLink1: TFDPhysMySQLDriverLink
    VendorLib = 'C:\Users\Jan\Desktop\4sem\NTP\libmysql.dll'
    Left = 1216
    Top = 272
  end
  object FDTableRecenzije: TFDTable
    Active = True
    IndexFieldNames = 'id'
    Connection = FDConnectionIMiniDB
    ResourceOptions.AssignedValues = [rvEscapeExpand]
    TableName = 'iminidb.recenzija'
    Left = 1168
    Top = 344
  end
  object FDTableKorisnik: TFDTable
    Active = True
    IndexFieldNames = 'id'
    Connection = FDConnectionIMiniDB
    ResourceOptions.AssignedValues = [rvEscapeExpand]
    TableName = 'iminidb.korisnik'
    Left = 1272
    Top = 344
  end
  object frxReportRecenzije: TfrxReport
    Version = '2024.1.2'
    DotMatrixReport = False
    IniFile = '\Software\Fast Reports'
    PreviewOptions.Buttons = [pbPrint, pbLoad, pbSave, pbExport, pbZoom, pbFind, pbOutline, pbPageSetup, pbTools, pbEdit, pbNavigator, pbExportQuick, pbCopy, pbSelection, pbWatermarks]
    PreviewOptions.Zoom = 1.000000000000000000
    PrintOptions.Printer = 'Default'
    PrintOptions.PrintOnSheet = 0
    ReportOptions.CreateDate = 46131.500789675900000000
    ReportOptions.LastChange = 46131.514413611110000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      'begin'
      ''
      'end.')
    Left = 1224
    Top = 672
    Datasets = <
      item
        DataSet = frxDBDatasetRecenzije
        DataSetName = 'frxDBDatasetRecenzije'
      end
      item
        DataSet = frxDBDatasetKorisnik
        DataSetName = 'frxDBDatasetKorisnik'
      end>
    Variables = <>
    Style = <>
    Watermarks = <>
    object Data: TfrxDataPage
      Height = 1000.000000000000000000
      Width = 1000.000000000000000000
    end
    object Page1: TfrxReportPage
      PaperWidth = 215.900000000000000000
      PaperHeight = 279.400000000000000000
      PaperSize = 1
      LeftMargin = 10.000000000000000000
      RightMargin = 10.000000000000000000
      TopMargin = 10.000000000000000000
      BottomMargin = 10.000000000000000000
      Frame.Typ = []
      MirrorMode = []
      object ReportTitle1: TfrxReportTitle
        FillType = ftBrush
        FillGap.Top = 0
        FillGap.Left = 0
        FillGap.Bottom = 0
        FillGap.Right = 0
        Frame.Typ = []
        Height = 22.677180000000000000
        Top = 18.897650000000000000
        Width = 740.409927000000000000
        object Memo1: TfrxMemoView
          AllowVectorExport = True
          Left = 260.787570100000000000
          Top = 3.779529770000000000
          Width = 253.228509780000000000
          Height = 18.897649770000000000
          ContentScaleOptions.Constraints.MaxIterationValue = 0
          ContentScaleOptions.Constraints.MinIterationValue = 0
          Frame.Typ = []
          Memo.UTF8W = (
            'IZVJE'#352'TAJ KORISNI'#268'KIH RECENZIJA')
        end
      end
      object MasterData1: TfrxMasterData
        FillType = ftBrush
        FillGap.Top = 0
        FillGap.Left = 0
        FillGap.Bottom = 0
        FillGap.Right = 0
        Frame.Typ = []
        Height = 60.472480000000000000
        Top = 102.047310000000000000
        Width = 740.409927000000000000
        DataSet = frxDBDatasetKorisnik
        DataSetName = 'frxDBDatasetKorisnik'
        RowCount = 0
        object Memo2: TfrxMemoView
          AllowVectorExport = True
          Left = 0.000000190000000000
          Top = 11.338592400000000000
          Width = 128.504018830000000000
          Height = 18.897651670000000000
          ContentScaleOptions.Constraints.MaxIterationValue = 0
          ContentScaleOptions.Constraints.MinIterationValue = 0
          Frame.Typ = []
          Memo.UTF8W = (
            'Recenzije korisnika: ')
        end
        object MemofrxDBDatasetKorisnikkorisnicko_ime: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 132.283550000000000000
          Top = 11.338590000000000000
          Width = 400.630180000000000000
          Height = 18.897650000000000000
          ContentScaleOptions.Constraints.MaxIterationValue = 0
          ContentScaleOptions.Constraints.MinIterationValue = 0
          DataField = 'korisnicko_ime'
          DataSet = frxDBDatasetKorisnik
          DataSetName = 'frxDBDatasetKorisnik'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBDatasetKorisnik."korisnicko_ime"]')
        end
      end
      object DetailData1: TfrxDetailData
        FillType = ftBrush
        FillGap.Top = 0
        FillGap.Left = 0
        FillGap.Bottom = 0
        FillGap.Right = 0
        Frame.Typ = []
        Height = 200.315090000000000000
        Top = 185.196970000000000000
        Width = 740.409927000000000000
        DataSet = frxDBDatasetRecenzije
        DataSetName = 'frxDBDatasetRecenzije'
        RowCount = 0
        object Memo3: TfrxMemoView
          AllowVectorExport = True
          Left = 75.590600100000000000
          Top = 3.779526410000000000
          Width = 64.252009780000000000
          Height = 18.897659300000000000
          ContentScaleOptions.Constraints.MaxIterationValue = 0
          ContentScaleOptions.Constraints.MinIterationValue = 0
          Frame.Typ = []
          Memo.UTF8W = (
            'Film: ')
        end
        object MemofrxDBDatasetRecenzijenaslov: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 166.299320000000000000
          Top = 3.779530000000000000
          Width = 400.630180000000000000
          Height = 18.897650000000000000
          ContentScaleOptions.Constraints.MaxIterationValue = 0
          ContentScaleOptions.Constraints.MinIterationValue = 0
          DataField = 'naslov'
          DataSet = frxDBDatasetRecenzije
          DataSetName = 'frxDBDatasetRecenzije'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBDatasetRecenzije."naslov"]')
        end
        object Memo4: TfrxMemoView
          AllowVectorExport = True
          Left = 75.590600100000000000
          Top = 34.015762980000000000
          Width = 64.252009780000000000
          Height = 18.897659300000000000
          ContentScaleOptions.Constraints.MaxIterationValue = 0
          ContentScaleOptions.Constraints.MinIterationValue = 0
          Frame.Typ = []
          Memo.UTF8W = (
            'Ocjena:')
        end
        object MemofrxDBDatasetRecenzijeocjena: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 166.299320000000000000
          Top = 34.015770000000000000
          Width = 79.370130000000000000
          Height = 18.897650000000000000
          ContentScaleOptions.Constraints.MaxIterationValue = 0
          ContentScaleOptions.Constraints.MinIterationValue = 0
          DataField = 'ocjena'
          DataSet = frxDBDatasetRecenzije
          DataSetName = 'frxDBDatasetRecenzije'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBDatasetRecenzije."ocjena"]')
        end
        object Memo5: TfrxMemoView
          AllowVectorExport = True
          Left = 75.590600100000000000
          Top = 71.811066320000000000
          Width = 109.606369780000000000
          Height = 18.897659300000000000
          ContentScaleOptions.Constraints.MaxIterationValue = 0
          ContentScaleOptions.Constraints.MinIterationValue = 0
          Frame.Typ = []
          Memo.UTF8W = (
            'Datum recenzije:')
        end
        object MemofrxDBDatasetRecenzijedatum: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 192.756030000000000000
          Top = 71.811070000000000000
          Width = 264.567100000000000000
          Height = 18.897650000000000000
          ContentScaleOptions.Constraints.MaxIterationValue = 0
          ContentScaleOptions.Constraints.MinIterationValue = 0
          DataField = 'datum'
          DataSet = frxDBDatasetRecenzije
          DataSetName = 'frxDBDatasetRecenzije'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBDatasetRecenzije."datum"]')
        end
        object Memo6: TfrxMemoView
          AllowVectorExport = True
          Left = 75.590600100000000000
          Top = 109.606358650000000000
          Width = 71.811069780000000000
          Height = 18.897674560000000000
          ContentScaleOptions.Constraints.MaxIterationValue = 0
          ContentScaleOptions.Constraints.MinIterationValue = 0
          Frame.Typ = []
          Memo.UTF8W = (
            'Recenzija:')
        end
        object MemofrxDBDatasetRecenzijetekst: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 158.740260000000000000
          Top = 109.606370000000000000
          Width = 642.520100000000000000
          Height = 18.897650000000000000
          ContentScaleOptions.Constraints.MaxIterationValue = 0
          ContentScaleOptions.Constraints.MinIterationValue = 0
          DataField = 'tekst'
          DataSet = frxDBDatasetRecenzije
          DataSetName = 'frxDBDatasetRecenzije'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxDBDatasetRecenzije."tekst"]')
        end
      end
    end
  end
  object frxDBDatasetRecenzije: TfrxDBDataset
    UserName = 'frxDBDatasetRecenzije'
    CloseDataSource = False
    DataSet = FDTableRecenzije
    BCDToCurrency = False
    DataSetOptions = []
    Left = 1136
    Top = 752
  end
  object frxDBDatasetKorisnik: TfrxDBDataset
    UserName = 'frxDBDatasetKorisnik'
    CloseDataSource = False
    DataSet = FDTableKorisnik
    BCDToCurrency = False
    DataSetOptions = []
    Left = 1264
    Top = 744
  end
  object PReportRecenzije: TPReport
    FileName = 'recenzije.pdf'
    CreationDate = 46131.518686076390000000
    UseOutlines = False
    ViewerPreference = []
    Left = 1192
    Top = 832
  end
end
