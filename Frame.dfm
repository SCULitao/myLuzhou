object Frame2: TFrame2
  Left = 0
  Top = 0
  Width = 751
  Height = 250
  TabOrder = 0
  object PanelInFrame: TRzPanel
    Left = 0
    Top = 0
    Width = 1369
    Height = 233
    BorderOuter = fsNone
    Color = clWindowFrame
    TabOrder = 0
    DesignSize = (
      1369
      233)
    object iPipe1: TiPipe
      Left = -680
      Top = 0
      Width = 2081
      Height = 33
      Hint = #21491#38190#28155#21152#20809#24863#22120
      ShowHint = True
      Anchors = [akLeft, akTop, akRight]
      AutoFrameRate = True
      FlowInterval = 50
      FlowOn = True
      FlowReverse = False
      FlowIndicatorStyle = ipfisCircle
      FlowIndicatorSize = 6
      FlowIndicatorSpacing = 8
      FlowIndicatorColor = clRed
      FlowIndicatorUseTubeColor = True
      FlowIndicatorHideWhenOff = True
      TubeColor = clTeal
    end
  end
end
