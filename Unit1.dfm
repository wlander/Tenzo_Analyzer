object Form1: TForm1
  Left = 279
  Top = 21
  BorderStyle = bsDialog
  Caption = 'CTorV 1.0 '#1056#1072#1089#1095#1077#1090' '#1082#1088#1091#1090#1080#1083#1100#1085#1099#1093'  '#1082#1086#1083#1077#1073#1072#1085#1080#1081
  ClientHeight = 681
  ClientWidth = 1239
  Color = 15397856
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 2
    Top = 0
    Width = 199
    Height = 489
    TabOrder = 0
    object SpeedButton3: TSpeedButton
      Left = 8
      Top = 44
      Width = 89
      Height = 33
      Caption = #1054#1090#1082#1088#1099#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      OnClick = SpeedButton3Click
    end
    object Label1: TLabel
      Left = 8
      Top = 102
      Width = 90
      Height = 13
      Caption = #1048#1085#1092#1086#1088#1084'. '#1082#1086#1085#1089#1086#1083#1100
    end
    object Label16: TLabel
      Left = 8
      Top = 80
      Width = 3
      Height = 13
      Caption = '-'
    end
    object ListBox1: TListBox
      Left = 8
      Top = 120
      Width = 185
      Height = 130
      BorderStyle = bsNone
      ItemHeight = 13
      TabOrder = 0
    end
    object ListBox2: TListBox
      Left = 8
      Top = 255
      Width = 185
      Height = 227
      BorderStyle = bsNone
      ItemHeight = 13
      TabOrder = 1
    end
    object ProgressBar1: TProgressBar
      Left = 8
      Top = 83
      Width = 185
      Height = 11
      Min = 0
      Max = 100
      TabOrder = 2
    end
    object Button4: TButton
      Left = 136
      Top = 102
      Width = 57
      Height = 17
      Caption = #1054#1095#1080#1089#1090#1080#1090#1100
      TabOrder = 3
      OnClick = Button4Click
    end
    object CheckBox7: TCheckBox
      Left = 150
      Top = 45
      Width = 43
      Height = 25
      Caption = '2 '#1092'.'
      TabOrder = 4
    end
    object RadioGroup4: TRadioGroup
      Left = 3
      Top = 8
      Width = 115
      Height = 33
      Columns = 3
      Items.Strings = (
        #1058#1085
        #1069#1085
        #1069#1085#1085)
      TabOrder = 5
      OnClick = RadioGroup4Click
    end
    object GroupBox9: TGroupBox
      Left = 118
      Top = 8
      Width = 75
      Height = 33
      TabOrder = 6
      object RadioButton1: TRadioButton
        Left = 5
        Top = 8
        Width = 41
        Height = 25
        Caption = 'Txt'
        Checked = True
        Color = 15397856
        ParentColor = False
        TabOrder = 0
        TabStop = True
      end
      object RadioButton2: TRadioButton
        Left = 38
        Top = 8
        Width = 33
        Height = 25
        Caption = 'Bin'
        TabOrder = 1
      end
    end
    object CheckBox24: TCheckBox
      Left = 104
      Top = 48
      Width = 41
      Height = 17
      Caption = '"."'
      Checked = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -21
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      State = cbChecked
      TabOrder = 7
    end
  end
  object PageControl1: TPageControl
    Left = 2
    Top = 536
    Width = 207
    Height = 137
    ActivePage = TabSheet7
    TabIndex = 2
    TabOrder = 1
    object TabSheet1: TTabSheet
      Caption = #1054#1073#1088#1072#1073#1086#1090#1082#1072
      object GroupBox2: TGroupBox
        Left = 0
        Top = -4
        Width = 185
        Height = 205
        TabOrder = 0
        object GroupBox6: TGroupBox
          Left = 8
          Top = 12
          Width = 169
          Height = 85
          TabOrder = 0
          object LabeledEdit14: TLabeledEdit
            Left = 72
            Top = 50
            Width = 33
            Height = 21
            EditLabel.Width = 61
            EditLabel.Height = 13
            EditLabel.Caption = #1054#1082#1085#1086' '#1091#1089#1088#1077#1076'.'
            LabelPosition = lpLeft
            LabelSpacing = 3
            TabOrder = 0
            Text = '2'
          end
          object LabeledEdit1: TLabeledEdit
            Left = 56
            Top = 8
            Width = 49
            Height = 21
            AutoSize = False
            EditLabel.Width = 49
            EditLabel.Height = 13
            EditLabel.Caption = #1055#1086#1088#1086#1075' '#1086#1073'.'
            LabelPosition = lpLeft
            LabelSpacing = 3
            TabOrder = 1
            Text = '100'
            OnKeyPress = LabeledEdit1KeyPress
          end
          object CheckBox4: TCheckBox
            Left = 109
            Top = 8
            Width = 60
            Height = 17
            Caption = #1086#1090' '#1089#1088#1077#1076
            TabOrder = 2
          end
        end
      end
    end
    object TabSheet2: TTabSheet
      Caption = #1044#1072#1085#1085#1099#1077
      ImageIndex = 1
      object GroupBox8: TGroupBox
        Left = 8
        Top = 8
        Width = 177
        Height = 81
        Caption = #1042#1099#1095#1077#1090' '#1089#1084#1077#1097#1077#1085#1080#1103
        TabOrder = 0
        object Label15: TLabel
          Left = 64
          Top = 56
          Width = 54
          Height = 13
          Caption = #1047#1085#1072#1095#1077#1085#1080#1077': '
        end
        object Button3: TButton
          Left = 8
          Top = 20
          Width = 49
          Height = 25
          Caption = #1057#1085#1103#1090#1100
          TabOrder = 0
          OnClick = Button3Click
        end
        object LabeledEdit17: TLabeledEdit
          Left = 64
          Top = 32
          Width = 49
          Height = 21
          EditLabel.Width = 29
          EditLabel.Height = 13
          EditLabel.Caption = #1057#1090#1072#1088#1090
          LabelPosition = lpAbove
          LabelSpacing = 3
          TabOrder = 1
        end
        object LabeledEdit18: TLabeledEdit
          Left = 120
          Top = 32
          Width = 49
          Height = 21
          EditLabel.Width = 24
          EditLabel.Height = 13
          EditLabel.Caption = #1057#1090#1086#1087
          LabelPosition = lpAbove
          LabelSpacing = 3
          TabOrder = 2
        end
        object Button11: TButton
          Left = 8
          Top = 50
          Width = 50
          Height = 25
          Caption = #1042#1099#1095#1077#1089#1090#1100
          TabOrder = 3
          OnClick = Button11Click
        end
      end
    end
    object TabSheet7: TTabSheet
      Caption = #1069#1085#1082
      ImageIndex = 3
      object BitBtn1: TBitBtn
        Left = 98
        Top = 72
        Width = 89
        Height = 25
        Caption = #1057#1080#1085#1090#1077#1079
        Enabled = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
        OnClick = BitBtn1Click
      end
      object LabeledEdit24: TLabeledEdit
        Left = 40
        Top = 40
        Width = 33
        Height = 21
        EditLabel.Width = 31
        EditLabel.Height = 13
        EditLabel.Caption = #1055#1086#1088#1086#1075
        LabelPosition = lpLeft
        LabelSpacing = 3
        TabOrder = 1
        Text = '11350'
      end
      object CheckBox14: TCheckBox
        Left = 96
        Top = 40
        Width = 41
        Height = 17
        Caption = #1040#1074#1090
        TabOrder = 2
      end
      object RadioGroup5: TRadioGroup
        Left = 16
        Top = 0
        Width = 153
        Height = 33
        Columns = 2
        Items.Strings = (
          #1069#1085#1082
          #1051#1077#1085#1090#1072)
        TabOrder = 3
        OnClick = RadioGroup5Click
      end
      object Button15: TButton
        Left = 3
        Top = 72
        Width = 89
        Height = 25
        Caption = #1040#1085#1072#1083#1080#1079
        Enabled = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 4
        OnClick = Button15Click
      end
      object Button30: TButton
        Left = 48
        Top = 0
        Width = 41
        Height = 25
        Caption = 'Button30'
        Enabled = False
        TabOrder = 5
        Visible = False
        OnClick = Button30Click
      end
    end
  end
  object GroupBox4: TGroupBox
    Left = 4
    Top = 491
    Width = 195
    Height = 49
    TabOrder = 2
    object SpeedButton4: TSpeedButton
      Left = 5
      Top = 10
      Width = 180
      Height = 30
      Caption = #1043#1072#1088#1084'. '#1072#1085#1072#1083#1080#1079
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      OnClick = SpeedButton4Click
    end
  end
  object PageControl2: TPageControl
    Left = 208
    Top = 0
    Width = 1025
    Height = 673
    ActivePage = TabSheet4
    TabIndex = 0
    TabOrder = 3
    object TabSheet4: TTabSheet
      Caption = #1048#1089#1093#1086#1076#1085#1099#1077' '#1044#1072#1085#1085#1099#1077
      object Label2: TLabel
        Left = 969
        Top = 0
        Width = 48
        Height = 13
        AutoSize = False
        Caption = '             '
      end
      object Label4: TLabel
        Left = 969
        Top = 20
        Width = 48
        Height = 13
        AutoSize = False
        Caption = '           '
      end
      object Label6: TLabel
        Left = 969
        Top = 232
        Width = 48
        Height = 13
        AutoSize = False
        Caption = '           '
      end
      object Label7: TLabel
        Left = 969
        Top = 257
        Width = 48
        Height = 13
        AutoSize = False
        Caption = '           '
      end
      object Label8: TLabel
        Left = 969
        Top = 282
        Width = 48
        Height = 13
        AutoSize = False
        Caption = '         '
      end
      object Label5: TLabel
        Left = 969
        Top = 44
        Width = 48
        Height = 13
        AutoSize = False
        Caption = '          '
      end
      object Label18: TLabel
        Left = 136
        Top = 504
        Width = 50
        Height = 13
        Caption = #1055#1086#1079#1080#1094#1080#1103': '
      end
      object Label20: TLabel
        Left = 688
        Top = 634
        Width = 12
        Height = 13
        Caption = '    '
      end
      object Chart1: TChart
        Left = 0
        Top = 0
        Width = 969
        Height = 260
        Hint = #1082#1091#1082#1091
        Legend.Visible = False
        Title.Text.Strings = (
          'TChart')
        Title.Visible = False
        OnUndoZoom = Chart1UndoZoom
        OnZoom = Chart1Zoom
        BottomAxis.Automatic = False
        BottomAxis.AutomaticMaximum = False
        BottomAxis.AutomaticMinimum = False
        BottomAxis.Maximum = 2048
        Shadow.Visible = False
        View3D = False
        View3DWalls = False
        BevelOuter = bvNone
        Color = 16119285
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
        OnDblClick = Chart1DblClick
        OnMouseDown = Chart1MouseDown
        OnMouseMove = Chart1MouseMove
        object Label22: TLabel
          Left = 440
          Top = 0
          Width = 45
          Height = 13
          Caption = #1054#1073'/'#1084#1080#1085': '
        end
        object Series1: TFastLineSeries
          Marks.Arrow.Visible = True
          Marks.Callout.Brush.Color = clBlack
          Marks.Callout.Arrow.Visible = True
          Marks.Visible = False
          LinePen.Color = clRed
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
        object Series30: TFastLineSeries
          Marks.Arrow.Visible = True
          Marks.Callout.Brush.Color = clBlack
          Marks.Callout.Arrow.Visible = True
          Marks.Visible = False
          LinePen.Color = clGreen
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
        object Series34: TVolumeSeries
          Marks.Arrow.Visible = True
          Marks.Callout.Brush.Color = clBlack
          Marks.Callout.Arrow.Visible = True
          Marks.Visible = False
          SeriesColor = 16744703
          LinePen.Color = 16744703
          VolumeValues.Name = 'Y'
          VolumeValues.Order = loNone
          XValues.Name = 'X'
          XValues.Order = loAscending
        end
      end
      object Chart2: TChart
        Left = 0
        Top = 250
        Width = 969
        Height = 211
        Legend.Visible = False
        Title.Text.Strings = (
          'TChart')
        Title.Visible = False
        OnUndoZoom = Chart2UndoZoom
        OnZoom = Chart2Zoom
        BottomAxis.Automatic = False
        BottomAxis.AutomaticMaximum = False
        BottomAxis.AutomaticMinimum = False
        BottomAxis.Maximum = 2048
        Shadow.Visible = False
        View3D = False
        View3DWalls = False
        BevelOuter = bvNone
        Color = 16119285
        TabOrder = 1
        OnMouseMove = Chart2MouseMove
        object Series2: TFastLineSeries
          Marks.Arrow.Visible = True
          Marks.Callout.Brush.Color = clBlack
          Marks.Callout.Arrow.Visible = True
          Marks.Visible = False
          LinePen.Color = clRed
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
        object Series4: TFastLineSeries
          Marks.Arrow.Visible = True
          Marks.Callout.Brush.Color = clBlack
          Marks.Callout.Arrow.Visible = True
          Marks.Visible = False
          LinePen.Color = clGreen
          LinePen.Width = 2
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
        object Series35: TVolumeSeries
          Marks.Arrow.Visible = True
          Marks.Callout.Brush.Color = clBlack
          Marks.Callout.Arrow.Visible = True
          Marks.Visible = False
          SeriesColor = 16734719
          LinePen.Color = 16734719
          VolumeValues.Name = 'Y'
          VolumeValues.Order = loNone
          XValues.Name = 'X'
          XValues.Order = loAscending
        end
      end
      object GroupBox7: TGroupBox
        Left = 24
        Top = 548
        Width = 265
        Height = 69
        Caption = #1043#1088#1072#1085#1080#1094#1099
        TabOrder = 2
        object Button5: TButton
          Left = 213
          Top = 32
          Width = 44
          Height = 25
          Caption = #1057#1073#1088#1086#1089
          TabOrder = 0
          OnClick = Button5Click
        end
        object LabeledEdit11: TLabeledEdit
          Left = 5
          Top = 36
          Width = 76
          Height = 21
          EditLabel.Width = 37
          EditLabel.Height = 13
          EditLabel.BiDiMode = bdLeftToRight
          EditLabel.Caption = #1053#1072#1095#1072#1083#1086
          EditLabel.ParentBiDiMode = False
          LabelPosition = lpAbove
          LabelSpacing = 3
          TabOrder = 1
          Text = '0'
        end
        object LabeledEdit13: TLabeledEdit
          Left = 85
          Top = 36
          Width = 76
          Height = 21
          EditLabel.Width = 31
          EditLabel.Height = 13
          EditLabel.Caption = #1050#1086#1085#1077#1094
          LabelPosition = lpAbove
          LabelSpacing = 3
          TabOrder = 2
        end
        object Button6: TButton
          Left = 165
          Top = 32
          Width = 44
          Height = 25
          Caption = #1054#1050
          TabOrder = 3
          OnClick = Button6Click
        end
      end
      object TrackBar1: TTrackBar
        Left = 0
        Top = 462
        Width = 313
        Height = 21
        Orientation = trHorizontal
        Frequency = 1
        Position = 0
        SelEnd = 0
        SelStart = 0
        TabOrder = 3
        TickMarks = tmBottomRight
        TickStyle = tsAuto
        OnChange = TrackBar1Change
      end
      object UpDown2: TUpDown
        Left = 136
        Top = 480
        Width = 49
        Height = 21
        Min = 0
        Orientation = udHorizontal
        Position = 0
        TabOrder = 4
        Wrap = False
        OnClick = UpDown2Click
      end
      object Chart6: TChart
        Left = 672
        Top = 459
        Width = 353
        Height = 175
        Legend.Visible = False
        Title.Text.Strings = (
          'TChart')
        Title.Visible = False
        Shadow.Visible = False
        View3D = False
        View3DOptions.Orthogonal = False
        Color = 15658734
        TabOrder = 5
        OnDblClick = Chart6DblClick
        object Series29: TFastLineSeries
          Marks.Arrow.Visible = True
          Marks.Callout.Brush.Color = clBlack
          Marks.Callout.Arrow.Visible = True
          Marks.Visible = False
          LinePen.Color = clRed
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
      end
      object CheckBox10: TCheckBox
        Left = 971
        Top = 444
        Width = 50
        Height = 17
        Caption = #1057#1098#1077#1084
        TabOrder = 6
      end
      object CheckBox16: TCheckBox
        Left = 24
        Top = 528
        Width = 105
        Height = 17
        Caption = #1057#1088#1077#1076#1085#1077#1077' '#1087#1086' '#1069#1085#1082
        TabOrder = 7
        Visible = False
      end
      object Chart9: TChart
        Left = 312
        Top = 459
        Width = 369
        Height = 185
        Legend.Visible = False
        Title.Text.Strings = (
          'TChart')
        Title.Visible = False
        View3D = False
        Color = 15658734
        TabOrder = 8
        OnDblClick = Chart9DblClick
        OnMouseDown = Chart9MouseDown
        object Series31: TFastLineSeries
          Marks.Arrow.Visible = True
          Marks.Callout.Brush.Color = clBlack
          Marks.Callout.Arrow.Visible = True
          Marks.Visible = False
          LinePen.Color = clRed
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
        object Series32: TFastLineSeries
          Marks.Arrow.Visible = True
          Marks.Callout.Brush.Color = clBlack
          Marks.Callout.Arrow.Visible = True
          Marks.Visible = False
          LinePen.Color = clGreen
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
      end
      object CheckBox19: TCheckBox
        Left = 967
        Top = 200
        Width = 50
        Height = 25
        Caption = #1052#1077#1090#1082#1080
        TabOrder = 9
        OnClick = CheckBox19Click
      end
      object GroupBox14: TGroupBox
        Left = 970
        Top = 96
        Width = 39
        Height = 81
        TabOrder = 10
        object Button20: TButton
          Left = 2
          Top = 23
          Width = 17
          Height = 16
          Caption = '+'
          TabOrder = 0
          OnClick = Button20Click
        end
        object Button21: TButton
          Left = 18
          Top = 23
          Width = 17
          Height = 17
          Caption = '-'
          TabOrder = 1
          OnClick = Button21Click
        end
        object Button22: TButton
          Left = 10
          Top = 39
          Width = 17
          Height = 17
          Caption = '-'
          TabOrder = 2
          OnClick = Button22Click
        end
        object Button23: TButton
          Left = 10
          Top = 6
          Width = 17
          Height = 17
          Caption = '+'
          TabOrder = 3
          OnClick = Button23Click
        end
        object CheckBox20: TCheckBox
          Left = 0
          Top = 59
          Width = 37
          Height = 17
          Caption = #1072#1074#1090
          Checked = True
          State = cbChecked
          TabOrder = 4
          OnClick = CheckBox20Click
        end
      end
    end
    object TabSheet5: TTabSheet
      Caption = #1043#1072#1088#1084#1086#1085#1080#1095#1077#1089#1082#1080#1081' '#1040#1085#1072#1083#1080#1079
      ImageIndex = 1
      object Label9: TLabel
        Left = 960
        Top = 392
        Width = 73
        Height = 13
        AutoSize = False
        Caption = 'Label5'
      end
      object Label11: TLabel
        Left = 960
        Top = 336
        Width = 73
        Height = 13
        AutoSize = False
        Caption = 'Label5'
      end
      object Label12: TLabel
        Left = 960
        Top = 368
        Width = 73
        Height = 13
        AutoSize = False
        Caption = 'Label5'
      end
      object Label13: TLabel
        Left = 960
        Top = 420
        Width = 73
        Height = 17
        AutoSize = False
        Caption = 'Label13'
      end
      object Chart3: TChart
        Left = -16
        Top = -2
        Width = 1041
        Height = 323
        Legend.Alignment = laBottom
        Legend.ColorWidth = 25
        Legend.FontSeriesColor = True
        Legend.LegendStyle = lsSeries
        Legend.Shadow.Visible = False
        Legend.Symbol.Shadow.Color = 11579568
        Legend.Symbol.Shadow.Visible = False
        Legend.Symbol.Visible = False
        Legend.Symbol.Width = 25
        Legend.Transparent = True
        Title.Text.Strings = (
          #1054#1073'/'#1084#1080#1085': ')
        Shadow.Visible = False
        View3D = False
        View3DWalls = False
        BevelOuter = bvNone
        Color = 16119285
        TabOrder = 0
        OnDblClick = Chart3DblClick
        OnMouseDown = Chart3MouseDown
        OnMouseMove = Chart3MouseMove
        PrintMargins = (
          15
          37
          15
          37)
        object Label21: TLabel
          Left = 312
          Top = 8
          Width = 135
          Height = 13
          Caption = #1054#1073'/'#1084#1080#1085':                               '
          Visible = False
        end
        object Series5: TFastLineSeries
          Marks.Arrow.Visible = True
          Marks.Callout.Brush.Color = clBlack
          Marks.Callout.Arrow.Visible = True
          Marks.Visible = False
          Title = 'G0     '
          LinePen.Color = clRed
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
        object Series6: TFastLineSeries
          Marks.Arrow.Visible = True
          Marks.Callout.Brush.Color = clBlack
          Marks.Callout.Arrow.Visible = True
          Marks.Visible = False
          SeriesColor = 8421631
          Title = 'G1'
          LinePen.Color = 8421631
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
        object Series7: TFastLineSeries
          Marks.Arrow.Visible = True
          Marks.Callout.Brush.Color = clBlack
          Marks.Callout.Arrow.Visible = True
          Marks.Visible = False
          SeriesColor = 4210816
          Title = 'G2'
          LinePen.Color = 4210816
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
        object Series8: TFastLineSeries
          Marks.Arrow.Visible = True
          Marks.Callout.Brush.Color = clBlack
          Marks.Callout.Arrow.Visible = True
          Marks.Visible = False
          SeriesColor = clMaroon
          Title = 'G3'
          LinePen.Color = clMaroon
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
        object Series9: TFastLineSeries
          Marks.Arrow.Visible = True
          Marks.Callout.Brush.Color = clBlack
          Marks.Callout.Arrow.Visible = True
          Marks.Visible = False
          SeriesColor = 64
          Title = 'G4'
          LinePen.Color = 64
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
        object Series10: TFastLineSeries
          Marks.Arrow.Visible = True
          Marks.Callout.Brush.Color = clBlack
          Marks.Callout.Arrow.Visible = True
          Marks.Visible = False
          SeriesColor = 16512
          Title = 'G5'
          LinePen.Color = 16512
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
        object Series11: TFastLineSeries
          Marks.Arrow.Visible = True
          Marks.Callout.Brush.Color = clBlack
          Marks.Callout.Arrow.Visible = True
          Marks.Visible = False
          SeriesColor = clBlack
          Title = 'G6'
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
        object Series12: TFastLineSeries
          Marks.Arrow.Visible = True
          Marks.Callout.Brush.Color = clBlack
          Marks.Callout.Arrow.Visible = True
          Marks.Visible = False
          SeriesColor = clOlive
          Title = 'G7'
          LinePen.Color = clOlive
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
        object Series13: TFastLineSeries
          Marks.Arrow.Visible = True
          Marks.Callout.Brush.Color = clBlack
          Marks.Callout.Arrow.Visible = True
          Marks.Visible = False
          SeriesColor = 8454016
          Title = 'G8'
          LinePen.Color = 8454016
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
        object Series14: TFastLineSeries
          Marks.Arrow.Visible = True
          Marks.Callout.Brush.Color = clBlack
          Marks.Callout.Arrow.Visible = True
          Marks.Visible = False
          Title = 'G9'
          LinePen.Color = clGreen
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
        object Series15: TFastLineSeries
          Marks.Arrow.Visible = True
          Marks.Callout.Brush.Color = clBlack
          Marks.Callout.Arrow.Visible = True
          Marks.Visible = False
          SeriesColor = 16384
          Title = 'G10'
          LinePen.Color = 16384
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
        object Series16: TFastLineSeries
          Marks.Arrow.Visible = True
          Marks.Callout.Brush.Color = clBlack
          Marks.Callout.Arrow.Visible = True
          Marks.Visible = False
          SeriesColor = clTeal
          Title = 'G11'
          LinePen.Color = clTeal
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
        object Series17: TFastLineSeries
          Marks.Arrow.Visible = True
          Marks.Callout.Brush.Color = clBlack
          Marks.Callout.Arrow.Visible = True
          Marks.Visible = False
          SeriesColor = 4210688
          Title = 'G12'
          LinePen.Color = 4210688
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
        object Series18: TFastLineSeries
          Marks.Arrow.Visible = True
          Marks.Callout.Brush.Color = clBlack
          Marks.Callout.Arrow.Visible = True
          Marks.Visible = False
          Title = 'G13'
          LinePen.Color = clAqua
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
        object Series19: TFastLineSeries
          Marks.Arrow.Visible = True
          Marks.Callout.Brush.Color = clBlack
          Marks.Callout.Arrow.Visible = True
          Marks.Visible = False
          SeriesColor = 8404992
          Title = 'G14'
          LinePen.Color = 8404992
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
        object Series20: TFastLineSeries
          Marks.Arrow.Visible = True
          Marks.Callout.Brush.Color = clBlack
          Marks.Callout.Arrow.Visible = True
          Marks.Visible = False
          Title = 'G15'
          LinePen.Color = clBlue
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
        object Series21: TFastLineSeries
          Marks.Arrow.Visible = True
          Marks.Callout.Brush.Color = clBlack
          Marks.Callout.Arrow.Visible = True
          Marks.Visible = False
          SeriesColor = clNavy
          Title = 'G16'
          LinePen.Color = clNavy
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
        object Series22: TFastLineSeries
          Marks.Arrow.Visible = True
          Marks.Callout.Brush.Color = clBlack
          Marks.Callout.Arrow.Visible = True
          Marks.Visible = False
          SeriesColor = 16744448
          Title = 'G17'
          LinePen.Color = 16744448
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
        object Series23: TFastLineSeries
          Marks.Arrow.Visible = True
          Marks.Callout.Brush.Color = clBlack
          Marks.Callout.Arrow.Visible = True
          Marks.Visible = False
          SeriesColor = 12615680
          Title = 'G18'
          LinePen.Color = 12615680
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
        object Series24: TFastLineSeries
          Marks.Arrow.Visible = True
          Marks.Callout.Brush.Color = clBlack
          Marks.Callout.Arrow.Visible = True
          Marks.Visible = False
          SeriesColor = 16744576
          Title = 'G19'
          LinePen.Color = 16744576
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
        object Series25: TFastLineSeries
          Marks.Arrow.Visible = True
          Marks.Callout.Brush.Color = clBlack
          Marks.Callout.Arrow.Visible = True
          Marks.Visible = False
          SeriesColor = 12615935
          Title = 'G20'
          LinePen.Color = 12615935
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
        object Series26: TFastLineSeries
          Marks.Arrow.Visible = True
          Marks.Callout.Brush.Color = clBlack
          Marks.Callout.Arrow.Visible = True
          Marks.Visible = False
          SeriesColor = 12615808
          Title = 'G21'
          LinePen.Color = 12615808
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
        object Series27: TFastLineSeries
          Marks.Arrow.Visible = True
          Marks.Callout.Brush.Color = clBlack
          Marks.Callout.Arrow.Visible = True
          Marks.Visible = False
          SeriesColor = 16744703
          Title = 'G22'
          LinePen.Color = 16744703
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
        object Series28: TFastLineSeries
          Marks.Arrow.Visible = True
          Marks.Callout.Brush.Color = clBlack
          Marks.Callout.Arrow.Visible = True
          Marks.Visible = False
          SeriesColor = 16711808
          Title = 'G23'
          LinePen.Color = 16711808
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
        object Series33: TFastLineSeries
          Marks.Arrow.Visible = True
          Marks.Callout.Brush.Color = clBlack
          Marks.Callout.Arrow.Visible = True
          Marks.Visible = False
          Title = 'G24'
          LinePen.Color = clWhite
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
      end
      object CheckListBox1: TCheckListBox
        Left = 48
        Top = 300
        Width = 945
        Height = 17
        BorderStyle = bsNone
        Columns = 25
        ItemHeight = 13
        Items.Strings = (
          '0'
          '1'
          '2'
          '3'
          '4'
          '5'
          '6'
          '7'
          '8'
          '9'
          '10'
          '11'
          '12'
          '13'
          '14'
          '15'
          '16'
          '17'
          '18'
          '19'
          '20'
          '21'
          '22'
          '23'
          '24')
        TabOrder = 1
        OnClick = CheckListBox1Click
      end
      object CheckBox6: TCheckBox
        Left = 8
        Top = 260
        Width = 41
        Height = 17
        Caption = #1042#1089#1077
        TabOrder = 2
        Visible = False
        OnClick = CheckBox6Click
      end
      object GroupBox5: TGroupBox
        Left = 712
        Top = 586
        Width = 241
        Height = 39
        TabOrder = 3
        object RadioButton5: TRadioButton
          Left = 61
          Top = 15
          Width = 57
          Height = 17
          Caption = #1043#1072#1088#1084
          Checked = True
          Enabled = False
          TabOrder = 0
          TabStop = True
          OnClick = RadioButton5Click
        end
        object RadioButton6: TRadioButton
          Left = 117
          Top = 15
          Width = 57
          Height = 17
          Caption = #1054#1073'/'#1084#1080#1085
          TabOrder = 1
          OnClick = RadioButton6Click
        end
        object CheckBox5: TCheckBox
          Left = 5
          Top = 15
          Width = 50
          Height = 17
          Caption = #1057#1098#1077#1084
          Enabled = False
          TabOrder = 2
          OnClick = CheckBox5Click
        end
        object RadioButton9: TRadioButton
          Left = 181
          Top = 15
          Width = 57
          Height = 17
          Caption = #1059#1089#1088#1054#1073
          TabOrder = 3
          OnClick = RadioButton9Click
        end
      end
      object RadioGroup2: TRadioGroup
        Left = 496
        Top = 588
        Width = 137
        Height = 37
        Caption = #1043#1072#1088#1084'.'
        Columns = 2
        Items.Strings = (
          #1059#1089#1088'.'
          #1048#1089#1093'.')
        TabOrder = 4
        OnClick = RadioGroup2Click
      end
      object Chart5: TChart
        Left = -2
        Top = 376
        Width = 491
        Height = 209
        Legend.Visible = False
        Title.Text.Strings = (
          #1054#1073'/'#1084#1080#1085': ')
        Shadow.Visible = False
        View3D = False
        View3DWalls = False
        BevelOuter = bvNone
        Color = 16119285
        TabOrder = 5
        OnDblClick = Chart5DblClick
        OnMouseMove = Chart4MouseMove
        object Label23: TLabel
          Left = 0
          Top = 0
          Width = 135
          Height = 13
          Caption = #1054#1073'/'#1084#1080#1085':                               '
          Visible = False
        end
        object FastLineSeries1: TFastLineSeries
          Marks.Arrow.Visible = True
          Marks.Callout.Brush.Color = clBlack
          Marks.Callout.Arrow.Visible = True
          Marks.Visible = False
          LinePen.Color = clRed
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
      end
      object Chart4: TChart
        Left = 496
        Top = 378
        Width = 457
        Height = 207
        Legend.Visible = False
        Title.Text.Strings = (
          'TChart')
        Title.Visible = False
        Shadow.Visible = False
        View3D = False
        View3DWalls = False
        BevelOuter = bvNone
        Color = 16119285
        TabOrder = 6
        OnDblClick = Chart4DblClick
        OnMouseMove = Chart4MouseMove
        object Series3: TBarSeries
          BarPen.Color = clRed
          Marks.Arrow.Visible = True
          Marks.Callout.Brush.Color = clBlack
          Marks.Callout.Arrow.Visible = True
          Marks.Callout.Length = 8
          Marks.Visible = False
          Gradient.Direction = gdTopBottom
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Bar'
          YValues.Order = loNone
        end
        object Series36: TFastLineSeries
          Marks.Arrow.Visible = True
          Marks.Callout.Brush.Color = clBlack
          Marks.Callout.Arrow.Visible = True
          Marks.Visible = False
          LinePen.Color = clGreen
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
      end
      object Button7: TButton
        Left = 5
        Top = 330
        Width = 60
        Height = 20
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
        TabOrder = 7
        OnClick = Button7Click
      end
      object Button8: TButton
        Left = 8
        Top = 584
        Width = 65
        Height = 17
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
        TabOrder = 8
        OnClick = Button8Click
      end
      object TrackBar2: TTrackBar
        Left = 328
        Top = 336
        Width = 465
        Height = 25
        Orientation = trHorizontal
        Frequency = 1
        Position = 0
        SelEnd = 0
        SelStart = 0
        TabOrder = 9
        TickMarks = tmBottomRight
        TickStyle = tsAuto
        OnChange = TrackBar2Change
      end
      object UpDown3: TUpDown
        Left = 800
        Top = 336
        Width = 33
        Height = 17
        Min = 0
        Orientation = udHorizontal
        Position = 0
        TabOrder = 10
        Wrap = False
        OnClick = UpDown3Click
      end
      object Button9: TButton
        Left = 848
        Top = 336
        Width = 25
        Height = 17
        Caption = '+'
        TabOrder = 11
        Visible = False
      end
      object Button10: TButton
        Left = 872
        Top = 336
        Width = 25
        Height = 17
        Caption = '-'
        TabOrder = 12
        Visible = False
      end
      object Edit1: TEdit
        Left = 88
        Top = 330
        Width = 41
        Height = 21
        TabOrder = 13
        Text = '0'
      end
      object Edit2: TEdit
        Left = 128
        Top = 330
        Width = 41
        Height = 21
        TabOrder = 14
        Text = '0'
      end
      object Button2: TButton
        Left = 168
        Top = 330
        Width = 73
        Height = 20
        Caption = #1042' '#1087#1083#1086#1093#1080#1077' '#1086#1073
        TabOrder = 15
        OnClick = Button2Click
      end
      object Button19: TButton
        Left = 248
        Top = 330
        Width = 57
        Height = 20
        Caption = #1054#1095#1080#1089#1090#1080#1090#1100
        TabOrder = 16
        OnClick = Button19Click
      end
      object GroupBox16: TGroupBox
        Left = 982
        Top = -7
        Width = 39
        Height = 81
        TabOrder = 17
        object Button24: TButton
          Left = 2
          Top = 23
          Width = 17
          Height = 16
          Caption = '+'
          TabOrder = 0
          OnClick = Button20Click
        end
        object Button25: TButton
          Left = 18
          Top = 23
          Width = 17
          Height = 17
          Caption = '-'
          TabOrder = 1
          OnClick = Button21Click
        end
        object Button26: TButton
          Left = 10
          Top = 39
          Width = 17
          Height = 17
          Caption = '-'
          TabOrder = 2
          OnClick = Button22Click
        end
        object Button27: TButton
          Left = 10
          Top = 6
          Width = 17
          Height = 17
          Caption = '+'
          TabOrder = 3
          OnClick = Button23Click
        end
        object CheckBox22: TCheckBox
          Left = 0
          Top = 59
          Width = 37
          Height = 17
          Caption = #1072#1074#1090
          Checked = True
          State = cbChecked
          TabOrder = 4
          OnClick = CheckBox20Click
        end
      end
      object CheckBox23: TCheckBox
        Left = 232
        Top = 584
        Width = 49
        Height = 17
        Caption = '4 '#1054#1073
        TabOrder = 18
      end
    end
    object TabSheet6: TTabSheet
      Caption = #1069#1085#1082#1086#1076#1077#1088
      Enabled = False
      ImageIndex = 2
      TabVisible = False
      object Label17: TLabel
        Left = 224
        Top = 608
        Width = 54
        Height = 13
        Caption = #1057#1084#1077#1097#1077#1085#1080#1077
      end
      object Chart7: TChart
        Left = 8
        Top = 8
        Width = 1025
        Height = 313
        Legend.Visible = False
        Title.Text.Strings = (
          'TChart')
        Title.Visible = False
        OnUndoZoom = Chart1UndoZoom
        OnZoom = Chart1Zoom
        LeftAxis.Automatic = False
        LeftAxis.AutomaticMaximum = False
        LeftAxis.AutomaticMinimum = False
        LeftAxis.Maximum = 720
        LeftAxis.Minimum = 202.5
        Shadow.Visible = False
        View3D = False
        View3DWalls = False
        BevelOuter = bvNone
        Color = 16119285
        TabOrder = 0
        OnMouseDown = Chart1MouseDown
        OnMouseMove = Chart1MouseMove
        object FastLineSeries2: TFastLineSeries
          Marks.Arrow.Visible = True
          Marks.Callout.Brush.Color = clBlack
          Marks.Callout.Arrow.Visible = True
          Marks.Visible = False
          LinePen.Color = clRed
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
      end
      object Button13: TButton
        Left = 104
        Top = 608
        Width = 81
        Height = 25
        Caption = 'Read'
        TabOrder = 1
        OnClick = Button13Click
      end
      object Button14: TButton
        Left = 32
        Top = 608
        Width = 73
        Height = 25
        Caption = 'Open'
        TabOrder = 2
        OnClick = Button14Click
      end
      object Chart8: TChart
        Left = 8
        Top = 296
        Width = 1025
        Height = 313
        Legend.Visible = False
        Title.Text.Strings = (
          'TChart')
        Title.Visible = False
        OnUndoZoom = Chart1UndoZoom
        OnZoom = Chart1Zoom
        Shadow.Visible = False
        View3D = False
        View3DWalls = False
        BevelOuter = bvNone
        Color = 16119285
        TabOrder = 3
        OnMouseDown = Chart1MouseDown
        OnMouseMove = Chart1MouseMove
        object FastLineSeries3: TFastLineSeries
          Marks.Arrow.Visible = True
          Marks.Callout.Brush.Color = clBlack
          Marks.Callout.Arrow.Visible = True
          Marks.Visible = False
          LinePen.Color = clRed
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
      end
      object Edit3: TEdit
        Left = 288
        Top = 608
        Width = 81
        Height = 21
        TabOrder = 4
        Text = '0'
      end
      object CheckBox11: TCheckBox
        Left = 400
        Top = 608
        Width = 121
        Height = 17
        Caption = #1056#1086#1082#1080#1088#1086#1074#1082#1072' '#1073#1072#1081#1090#1086#1074
        TabOrder = 5
      end
      object CheckBox12: TCheckBox
        Left = 536
        Top = 616
        Width = 81
        Height = 17
        Caption = #1087#1088#1086#1087#1091#1089#1082' 2'#1073
        TabOrder = 6
      end
    end
    object TabSheet8: TTabSheet
      Caption = #1044#1086#1087#1086#1083#1085#1080#1090#1077#1083#1100#1085#1086
      ImageIndex = 3
      object SpeedButton1: TSpeedButton
        Left = 8
        Top = 483
        Width = 25
        Height = 18
        Caption = '-'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        Visible = False
        OnClick = SpeedButton1Click
      end
      object SpeedButton2: TSpeedButton
        Left = 8
        Top = 499
        Width = 25
        Height = 18
        Caption = '+'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        Visible = False
        OnClick = SpeedButton2Click
      end
      object Label14: TLabel
        Left = 72
        Top = 424
        Width = 32
        Height = 13
        Caption = #1057#1090#1072#1088#1090':'
        Visible = False
      end
      object Label19: TLabel
        Left = 128
        Top = 424
        Width = 27
        Height = 13
        Caption = #1057#1090#1086#1087':'
        Visible = False
      end
      object GroupBox10: TGroupBox
        Left = 16
        Top = 8
        Width = 289
        Height = 369
        Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099
        TabOrder = 0
        object PageControl3: TPageControl
          Left = 8
          Top = 16
          Width = 273
          Height = 337
          ActivePage = TabSheet9
          TabIndex = 0
          TabOrder = 0
          object TabSheet9: TTabSheet
            Caption = #1054#1073#1088#1072#1073#1086#1090#1082#1072
            object Label10: TLabel
              Left = 56
              Top = 24
              Width = 51
              Height = 13
              Caption = #1058#1072#1082#1090#1085' '#1044#1074'.'
            end
            object LabeledEdit2: TLabeledEdit
              Left = 55
              Top = 80
              Width = 44
              Height = 21
              EditLabel.Width = 39
              EditLabel.Height = 13
              EditLabel.Caption = #1054#1096#1080#1073' %'
              LabelPosition = lpLeft
              LabelSpacing = 3
              TabOrder = 0
              Text = '5'
            end
            object CheckBox15: TCheckBox
              Left = 112
              Top = 80
              Width = 41
              Height = 17
              Caption = #1042#1082#1083
              TabOrder = 1
            end
            object LabeledEdit10: TLabeledEdit
              Left = 8
              Top = 40
              Width = 41
              Height = 21
              EditLabel.Width = 39
              EditLabel.Height = 13
              EditLabel.Caption = #1056#1077#1076#1091#1082#1094'.'
              LabelPosition = lpAbove
              LabelSpacing = 3
              TabOrder = 2
              Text = '1,0'
              OnKeyPress = LabeledEdit10KeyPress
            end
            object ComboBox1: TComboBox
              Left = 56
              Top = 40
              Width = 47
              Height = 21
              ItemHeight = 13
              TabOrder = 3
              Text = '4'
              OnChange = ComboBox1Change
              Items.Strings = (
                '2'
                '4')
            end
            object LabeledEdit12: TLabeledEdit
              Left = 119
              Top = 40
              Width = 41
              Height = 21
              EditLabel.Width = 29
              EditLabel.Height = 13
              EditLabel.Caption = #1043#1072#1088#1084'.'
              LabelPosition = lpAbove
              LabelSpacing = 3
              TabOrder = 4
              Text = '25'
            end
            object LabeledEdit15: TLabeledEdit
              Left = 59
              Top = 114
              Width = 33
              Height = 21
              EditLabel.Width = 50
              EditLabel.Height = 13
              EditLabel.Caption = '% '#1086#1096#1080#1073'. A'
              LabelPosition = lpLeft
              LabelSpacing = 3
              TabOrder = 5
              Text = '50'
            end
            object GroupBox3: TGroupBox
              Left = 32
              Top = 160
              Width = 177
              Height = 33
              TabOrder = 6
              Visible = False
              object RadioButton3: TRadioButton
                Left = 8
                Top = 8
                Width = 73
                Height = 17
                Caption = #1042#1077#1089#1100' '#1092#1072#1081#1083
                TabOrder = 0
              end
              object RadioButton4: TRadioButton
                Left = 96
                Top = 8
                Width = 81
                Height = 17
                Caption = #1042#1099#1073#1088#1072#1085#1085#1099#1081
                Checked = True
                TabOrder = 1
                TabStop = True
              end
            end
            object GroupBox13: TGroupBox
              Left = 8
              Top = 216
              Width = 177
              Height = 49
              Caption = #1044#1077#1090#1077#1082#1090#1086#1088' '#1087#1083#1086#1093#1080#1093' '#1086#1073#1086#1088#1086#1090#1086#1074
              TabOrder = 7
              object CheckBox18: TCheckBox
                Left = 40
                Top = 16
                Width = 49
                Height = 25
                Caption = #1042#1082#1083
                Checked = True
                State = cbChecked
                TabOrder = 0
              end
            end
          end
          object TabSheet10: TTabSheet
            Caption = #1044#1072#1085#1085#1099#1077
            ImageIndex = 1
            object LabeledEdit5: TLabeledEdit
              Left = 45
              Top = 8
              Width = 41
              Height = 21
              EditLabel.Width = 41
              EditLabel.Height = 13
              EditLabel.Caption = #1085#1086#1088#1084' '#1082'1'
              LabelPosition = lpLeft
              LabelSpacing = 3
              TabOrder = 0
              Text = '0'
            end
            object LabeledEdit6: TLabeledEdit
              Left = 45
              Top = 34
              Width = 41
              Height = 21
              EditLabel.Width = 41
              EditLabel.Height = 13
              EditLabel.Caption = #1085#1086#1088#1084' '#1082'2'
              LabelPosition = lpLeft
              LabelSpacing = 3
              TabOrder = 1
              Text = '0'
            end
            object CheckBox2: TCheckBox
              Left = 90
              Top = 8
              Width = 49
              Height = 17
              Caption = #1040#1074#1090#1086
              Checked = True
              State = cbChecked
              TabOrder = 2
              OnClick = CheckBox2Click
            end
            object CheckBox3: TCheckBox
              Left = 90
              Top = 34
              Width = 57
              Height = 17
              Caption = 'Abs_K2'
              TabOrder = 3
              OnClick = CheckBox3Click
            end
            object CheckBox1: TCheckBox
              Left = 145
              Top = 4
              Width = 38
              Height = 25
              Caption = #1084#1042
              TabOrder = 4
            end
            object LabeledEdit16: TLabeledEdit
              Left = 8
              Top = 80
              Width = 49
              Height = 21
              EditLabel.Width = 80
              EditLabel.Height = 13
              EditLabel.Caption = #1041#1083#1086#1082' '#1087#1088#1086#1082#1088#1091#1090#1082#1080
              LabelPosition = lpAbove
              LabelSpacing = 3
              TabOrder = 5
              Text = '1024'
              Visible = False
              OnKeyPress = LabeledEdit16KeyPress
            end
            object LabeledEdit19: TLabeledEdit
              Left = 104
              Top = 80
              Width = 41
              Height = 21
              EditLabel.Width = 70
              EditLabel.Height = 13
              EditLabel.Caption = #1050#1086#1101#1092#1092#1080#1094#1080#1077#1085#1090
              LabelPosition = lpAbove
              LabelSpacing = 3
              TabOrder = 6
              Text = '1,0'
            end
            object Button12: TButton
              Left = 182
              Top = 80
              Width = 33
              Height = 21
              Caption = #1054#1050
              TabOrder = 7
              OnClick = Button12Click
            end
            object GroupBox11: TGroupBox
              Left = 8
              Top = 128
              Width = 249
              Height = 105
              Caption = #1040#1062#1055
              TabOrder = 8
              object Label3: TLabel
                Left = 152
                Top = 8
                Width = 77
                Height = 13
                Caption = #1044#1080#1072#1087#1072#1079#1086#1085' '#1040#1062#1055
              end
              object LabeledEdit7: TLabeledEdit
                Left = 8
                Top = 48
                Width = 33
                Height = 21
                EditLabel.Width = 54
                EditLabel.Height = 13
                EditLabel.Caption = #1056#1072#1079#1088'. '#1040#1062#1055
                LabelPosition = lpAbove
                LabelSpacing = 3
                TabOrder = 0
                Text = '12'
              end
              object UpDown1: TUpDown
                Left = 41
                Top = 48
                Width = 16
                Height = 21
                Min = 8
                Max = 16
                Position = 12
                TabOrder = 1
                Wrap = False
              end
              object LabeledEdit9: TLabeledEdit
                Left = 72
                Top = 48
                Width = 41
                Height = 21
                EditLabel.Width = 30
                EditLabel.Height = 13
                EditLabel.Caption = 'Fd, '#1043#1094
                LabelPosition = lpAbove
                LabelSpacing = 3
                TabOrder = 2
                Text = '3472'
                OnEnter = LabeledEdit9Enter
                OnKeyPress = LabeledEdit9KeyPress
              end
              object LabeledEdit8: TLabeledEdit
                Left = 144
                Top = 48
                Width = 41
                Height = 21
                EditLabel.Width = 21
                EditLabel.Height = 13
                EditLabel.Caption = #1052#1080#1085
                LabelPosition = lpAbove
                LabelSpacing = 3
                TabOrder = 3
                Text = '0'
              end
              object LabeledEdit4: TLabeledEdit
                Left = 200
                Top = 48
                Width = 41
                Height = 21
                EditLabel.Width = 27
                EditLabel.Height = 13
                EditLabel.Caption = #1052#1072#1082#1089
                LabelPosition = lpAbove
                LabelSpacing = 3
                TabOrder = 4
                Text = '3300'
              end
            end
          end
          object TabSheet11: TTabSheet
            Caption = #1069#1085#1082#1086#1076#1077#1088
            ImageIndex = 2
            object LabeledEdit22: TLabeledEdit
              Left = 88
              Top = 112
              Width = 49
              Height = 21
              EditLabel.Width = 28
              EditLabel.Height = 13
              EditLabel.Caption = #1053#1086#1088#1084
              LabelPosition = lpLeft
              LabelSpacing = 3
              TabOrder = 0
              Text = '258000'
            end
            object LabeledEdit25: TLabeledEdit
              Left = 88
              Top = 140
              Width = 33
              Height = 21
              EditLabel.Width = 54
              EditLabel.Height = 13
              EditLabel.Caption = #1054#1096#1080#1073' '#1086#1073' %'
              LabelPosition = lpLeft
              LabelSpacing = 3
              TabOrder = 1
              Text = '99'
            end
            object LabeledEdit21: TLabeledEdit
              Left = 88
              Top = 80
              Width = 81
              Height = 21
              EditLabel.Width = 49
              EditLabel.Height = 13
              EditLabel.Caption = 'ABSVOLT'
              LabelPosition = lpLeft
              LabelSpacing = 3
              TabOrder = 2
              Text = '0.000232544'
            end
            object LabeledEdit27: TLabeledEdit
              Left = 88
              Top = 192
              Width = 33
              Height = 21
              EditLabel.Width = 67
              EditLabel.Height = 13
              EditLabel.Caption = #1082#1086#1101#1092'. '#1087#1086#1088#1086#1075#1072
              LabelPosition = lpLeft
              LabelSpacing = 3
              TabOrder = 3
              Text = '1,01'
            end
            object LabeledEdit28: TLabeledEdit
              Left = 88
              Top = 224
              Width = 33
              Height = 21
              EditLabel.Width = 78
              EditLabel.Height = 13
              EditLabel.Caption = #1050#1086#1101#1092'. '#1087#1086#1088#1086#1075#1072' '#1058
              LabelPosition = lpLeft
              LabelSpacing = 3
              TabOrder = 4
              Text = '1,1'
            end
            object CheckBox13: TCheckBox
              Left = 88
              Top = 248
              Width = 105
              Height = 17
              Caption = #1058#1072#1073#1083#1080#1094#1072' '#1084#1077#1090#1086#1082
              TabOrder = 5
              OnClick = CheckBox13Click
            end
            object LabeledEdit26: TLabeledEdit
              Left = 88
              Top = 168
              Width = 41
              Height = 21
              EditLabel.Width = 64
              EditLabel.Height = 13
              EditLabel.Caption = #1054#1082#1085#1086' '#1087#1086#1088#1086#1075#1072
              LabelPosition = lpLeft
              LabelSpacing = 3
              TabOrder = 6
              Text = '650'
            end
            object LabeledEdit20: TLabeledEdit
              Left = 88
              Top = 8
              Width = 41
              Height = 21
              EditLabel.Width = 53
              EditLabel.Height = 13
              EditLabel.Caption = #1050#1086#1083' '#1084#1077#1090#1086#1082
              LabelPosition = lpLeft
              LabelSpacing = 3
              TabOrder = 7
              Text = '215'
              OnKeyPress = LabeledEdit20KeyPress
            end
            object LabeledEdit23: TLabeledEdit
              Left = 88
              Top = 40
              Width = 57
              Height = 21
              EditLabel.Width = 30
              EditLabel.Height = 13
              EditLabel.Caption = 'Fd, '#1043#1094
              LabelPosition = lpLeft
              LabelSpacing = 3
              TabOrder = 8
              Text = '320000'
              OnKeyPress = LabeledEdit23KeyPress
            end
            object Button28: TButton
              Left = 192
              Top = 248
              Width = 57
              Height = 20
              Caption = #1054#1090#1082#1088#1099#1090#1100
              Enabled = False
              TabOrder = 9
              OnClick = Button28Click
            end
            object LabeledEdit29: TLabeledEdit
              Left = 88
              Top = 280
              Width = 49
              Height = 21
              EditLabel.Width = 67
              EditLabel.Height = 13
              EditLabel.Caption = #1052#1077#1090#1086#1082' '#1091#1089#1088#1077#1076'.'
              LabelPosition = lpLeft
              LabelSpacing = 3
              TabOrder = 10
              Text = '430'
              OnKeyPress = LabeledEdit29KeyPress
            end
          end
        end
      end
      object Button16: TButton
        Left = 142
        Top = 576
        Width = 90
        Height = 33
        Caption = #1059#1089#1088#1077#1076#1085#1077#1085#1080#1077
        Enabled = False
        TabOrder = 1
        Visible = False
        OnClick = Button16Click
      end
      object Button1: TButton
        Left = 8
        Top = 539
        Width = 57
        Height = 18
        Caption = #1052#1072#1089#1096#1090#1072#1073
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -8
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
        Visible = False
      end
      object RadioGroup1: TRadioGroup
        Left = 24
        Top = 576
        Width = 65
        Height = 33
        Columns = 3
        Items.Strings = (
          'Abs'
          'Re'
          'Im')
        TabOrder = 3
        Visible = False
      end
      object RadioButton8: TRadioButton
        Left = 24
        Top = 612
        Width = 25
        Height = 17
        Caption = 'FFT'
        TabOrder = 4
        Visible = False
        OnClick = RadioButton8Click
      end
      object LabeledEdit3: TLabeledEdit
        Left = 255
        Top = 584
        Width = 42
        Height = 21
        EditLabel.Width = 37
        EditLabel.Height = 13
        EditLabel.Caption = #1054#1082#1085#1086' '#1084
        LabelPosition = lpAbove
        LabelSpacing = 3
        TabOrder = 5
        Text = '100'
        Visible = False
      end
      object RadioGroup3: TRadioGroup
        Left = 320
        Top = 576
        Width = 73
        Height = 33
        Columns = 3
        Items.Strings = (
          #1057#1080#1075#1085#1072#1083
          #1054#1073'/'#1084#1080#1085
          #1058#1086#1073#1086#1088)
        TabOrder = 6
        Visible = False
      end
      object Button17: TButton
        Left = 72
        Top = 440
        Width = 113
        Height = 22
        Caption = #1059#1076#1072#1083#1080#1090#1100' '#1087#1083#1086#1093#1080#1077' '#1086#1073'.'
        Enabled = False
        TabOrder = 7
        Visible = False
        OnClick = Button17Click
      end
      object Button18: TButton
        Left = 184
        Top = 440
        Width = 57
        Height = 22
        Caption = #1042#1099#1076#1077#1083#1080#1090#1100
        Enabled = False
        TabOrder = 8
        Visible = False
        OnClick = Button18Click
      end
      object GroupBox15: TGroupBox
        Left = 928
        Top = 80
        Width = 39
        Height = 87
        TabOrder = 9
        Visible = False
        object UpDown4: TUpDown
          Left = 10
          Top = 6
          Width = 17
          Height = 58
          Min = 0
          Position = 0
          TabOrder = 0
          Wrap = False
        end
        object UpDown5: TUpDown
          Left = 0
          Top = 26
          Width = 38
          Height = 17
          Min = 0
          Orientation = udHorizontal
          Position = 0
          TabOrder = 1
          Wrap = False
        end
        object CheckBox21: TCheckBox
          Left = 1
          Top = 70
          Width = 35
          Height = 17
          Caption = #1072#1074#1090
          TabOrder = 2
        end
      end
      object GroupBox12: TGroupBox
        Left = 930
        Top = 192
        Width = 55
        Height = 97
        Caption = #1052#1072#1089#1096
        TabOrder = 10
        Visible = False
        object CheckBox17: TCheckBox
          Left = 5
          Top = 24
          Width = 49
          Height = 17
          Caption = #1040#1074#1090#1086
          TabOrder = 0
        end
        object Edit4: TEdit
          Left = 5
          Top = 48
          Width = 45
          Height = 21
          TabOrder = 1
          Text = '0'
        end
        object Edit5: TEdit
          Left = 5
          Top = 72
          Width = 45
          Height = 21
          TabOrder = 2
          Text = '1000'
        end
      end
      object CheckBox9: TCheckBox
        Left = 933
        Top = 311
        Width = 33
        Height = 17
        Caption = 'G0'
        TabOrder = 11
        Visible = False
        OnClick = CheckBox9Click
      end
      object RadioButton7: TRadioButton
        Left = 453
        Top = 287
        Width = 49
        Height = 17
        Caption = 'T'#1086#1073#1086#1088
        TabOrder = 12
        Visible = False
        OnClick = RadioButton7Click
      end
      object CheckBox8: TCheckBox
        Left = 437
        Top = 247
        Width = 57
        Height = 17
        Caption = #1055#1086' '#1080#1084#1087'.'
        TabOrder = 13
        Visible = False
        OnClick = CheckBox8Click
      end
      object Button29: TButton
        Left = 552
        Top = 480
        Width = 65
        Height = 25
        Caption = 'Write INI'
        TabOrder = 14
        Visible = False
        OnClick = Button29Click
      end
    end
  end
  object SaveDialog1: TSaveDialog
    Left = 1176
    Top = 568
  end
  object OpenDialog1: TOpenDialog
    Left = 1176
    Top = 536
  end
  object OpenDialog2: TOpenDialog
    Left = 864
    Top = 368
  end
end
