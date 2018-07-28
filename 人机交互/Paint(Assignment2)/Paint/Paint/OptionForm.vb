Public Class OptionForm
    Private myPaint As New Form1
    Private Sub ComboBox1_SelectedIndexChanged(sender As Object, e As EventArgs) Handles ComboBox1.SelectedIndexChanged
        myPaint.setSize(ComboBox1.SelectedIndex)
    End Sub

    Private Sub BtnColor_Click(sender As Object, e As EventArgs) Handles BtnColor.Click
        ColorDialogBrush.ShowDialog()
        Try
            myPaint.setColor(ColorDialogBrush.Color)
            lblColor.Text = myPaint.PaintConvas1.GraphicsColor.ToString

        Catch ex As Exception
            MessageBox.Show(ex.Message)
        End Try
    End Sub

    Private Sub BtnClear_Click(sender As Object, e As EventArgs) Handles BtnClear.Click
        myPaint.PaintConvas1.clearCanvas()
    End Sub

    Private Sub OptionForm_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        ComboBox1.SelectedIndex = 0
        myPaint.Show()
        lblColor.Text = myPaint.PaintConvas1.GraphicsColor.ToString

    End Sub
End Class