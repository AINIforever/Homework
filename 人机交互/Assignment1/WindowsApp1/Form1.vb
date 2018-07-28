

Public Class Form1
    Dim op1 As Double
    Dim op2 As Double
    Dim result As Double
    Dim opr As String

    Private Sub TextBox1_TextChanged(sender As Object, e As EventArgs) Handles TextBox1.TextChanged

    End Sub

    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
        TextBox1.Text = TextBox1.Text + "1"
    End Sub

    Private Sub Button9_Click(sender As Object, e As EventArgs) Handles Button9.Click
        TextBox1.Text = TextBox1.Text + "9"
    End Sub

    Private Sub Button8_Click(sender As Object, e As EventArgs) Handles Button8.Click
        TextBox1.Text = TextBox1.Text + "8"
    End Sub

    Private Sub Button7_Click(sender As Object, e As EventArgs) Handles Button7.Click
        TextBox1.Text = TextBox1.Text + "7"
    End Sub

    Private Sub Button6_Click(sender As Object, e As EventArgs) Handles Button6.Click
        TextBox1.Text = TextBox1.Text + "6"
    End Sub

    Private Sub Button5_Click(sender As Object, e As EventArgs) Handles Button5.Click
        TextBox1.Text = TextBox1.Text + "5"
    End Sub

    Private Sub Button4_Click(sender As Object, e As EventArgs) Handles Button4.Click
        TextBox1.Text = TextBox1.Text + "4"
    End Sub

    Private Sub Button3_Click(sender As Object, e As EventArgs) Handles Button3.Click
        TextBox1.Text = TextBox1.Text + "3"
    End Sub

    Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
        TextBox1.Text = TextBox1.Text + "2"
    End Sub

    Private Sub Button0_Click(sender As Object, e As EventArgs) Handles Button0.Click
        TextBox1.Text = TextBox1.Text + "0"
    End Sub

    Private Sub ButtonEqual_Click(sender As Object, e As EventArgs) Handles ButtonEqual.Click
        Try
            op2 = CType(TextBox1.Text(), Double)
        Catch ex As Exception
            MsgBox("The op is not a number")
        End Try
        Select Case opr
            Case "+"
                result = op1 + op2
            Case "-"
                result = op1 - op2
            Case "*"
                result = op1 * op2
            Case "/"
                result = op1 / op2
            Case "sin"
                result = Math.Sin(op2)
            Case "cos"
                result = Math.Cos(op2)
            Case "tan"
                result = Math.Tan(op2)
            Case "sqrt"
                result = Math.Sqrt(op2)
            Case "^"
                result = Math.Pow(op1, op2)
            Case Else
                MsgBox("The expreesion you input is illegal!")
        End Select
        TextBox1.Text = result
        op1 = 0
        op2 = 0
    End Sub

    Private Sub ButtonAC_Click(sender As Object, e As EventArgs) Handles ButtonAC.Click
        TextBox1.Text = ""
    End Sub

    Private Sub ButtonDot_Click(sender As Object, e As EventArgs) Handles ButtonDot.Click
        TextBox1.Text = TextBox1.Text + "."
    End Sub

    Private Sub ButtonSin_Click(sender As Object, e As EventArgs) Handles ButtonSin.Click
        TextBox1.Text = ""
        opr = "sin"
    End Sub

    Private Sub ButtonCos_Click(sender As Object, e As EventArgs) Handles ButtonCos.Click
        TextBox1.Text = ""
        opr = "cos"
    End Sub

    Private Sub ButtonTan_Click(sender As Object, e As EventArgs) Handles ButtonTan.Click
        TextBox1.Text = ""
        opr = "tan"
    End Sub

    Private Sub ButtonMul_Click(sender As Object, e As EventArgs) Handles ButtonMul.Click
        Try
            op1 = CType(TextBox1.Text(), Double)
        Catch ex As Exception
            MsgBox("The op is not a number")
        End Try

        opr = "*"
        TextBox1.Text = ""
    End Sub

    Private Sub ButtonSqrt_Click(sender As Object, e As EventArgs) Handles ButtonSqrt.Click
        TextBox1.Text = ""
        opr = "sqrt"
    End Sub

    Private Sub ButtonDiv_Click(sender As Object, e As EventArgs) Handles ButtonDiv.Click
        Try
            op1 = CType(TextBox1.Text(), Double)
        Catch ex As Exception
            MsgBox("The op is not a number")
        End Try
        opr = "/"
        TextBox1.Text = ""
    End Sub

    Private Sub ButtonPlus_Click(sender As Object, e As EventArgs) Handles ButtonPlus.Click
        Try
            op1 = CType(TextBox1.Text(), Double)
        Catch ex As Exception
            MsgBox("The op is not a number")
        End Try
        opr = "+"
        TextBox1.Text = ""
    End Sub

    Private Sub ButtonMinus_Click(sender As Object, e As EventArgs) Handles ButtonMinus.Click
        Try
            op1 = CType(TextBox1.Text(), Double)
        Catch ex As Exception
            MsgBox("The op is not a number")
        End Try
        opr = "-"
        TextBox1.Text = ""
    End Sub

    Private Sub ButtonPower_Click(sender As Object, e As EventArgs) Handles ButtonPower.Click
        Try
            op1 = CType(TextBox1.Text(), Double)
        Catch ex As Exception
            MsgBox("The op is not a number")
        End Try
        opr = "^"
        TextBox1.Text = ""
    End Sub

    Private Sub ButtonDele_Click(sender As Object, e As EventArgs) Handles ButtonDele.Click
        If (Len(TextBox1.Text) >= 1) Then
            TextBox1.Text = TextBox1.Text.Substring(0, Len(TextBox1.Text) - 1)
        End If

    End Sub

    Private Sub ButtonPI_Click(sender As Object, e As EventArgs) Handles ButtonPI.Click
        TextBox1.Text = "3.14"
    End Sub
End Class
