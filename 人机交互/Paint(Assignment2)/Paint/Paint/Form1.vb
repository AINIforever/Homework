Public Class Form1
    Public Sub setSize(ByVal size As Integer)
        If size = 0 Then
            PaintConvas1.GraphicsSize = PaintConvas.GraphicsSizes.small
        ElseIf size = 1 Then
            PaintConvas1.GraphicsSize = PaintConvas.GraphicsSizes.Medium
        ElseIf size = 2 Then
            PaintConvas1.GraphicsSize = PaintConvas.GraphicsSizes.Large
        End If
    End Sub

    Public Sub setColor(ByVal color As Color)
        PaintConvas1.GraphicsColor = color
    End Sub
End Class
