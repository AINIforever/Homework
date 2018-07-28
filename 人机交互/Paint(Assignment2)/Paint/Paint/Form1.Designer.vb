<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form 重写 Dispose，以清理组件列表。
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Windows 窗体设计器所必需的
    Private components As System.ComponentModel.IContainer

    '注意: 以下过程是 Windows 窗体设计器所必需的
    '可以使用 Windows 窗体设计器修改它。  
    '不要使用代码编辑器修改它。
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.PaintConvas1 = New Paint.PaintConvas()
        Me.SuspendLayout()
        '
        'PaintConvas1
        '
        Me.PaintConvas1.Dock = System.Windows.Forms.DockStyle.Fill
        Me.PaintConvas1.Location = New System.Drawing.Point(0, 0)
        Me.PaintConvas1.Name = "PaintConvas1"
        Me.PaintConvas1.Size = New System.Drawing.Size(465, 357)
        Me.PaintConvas1.TabIndex = 0
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 12.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(465, 357)
        Me.Controls.Add(Me.PaintConvas1)
        Me.Name = "Form1"
        Me.Text = "Paint VB"
        Me.ResumeLayout(False)

    End Sub

    Friend WithEvents PaintConvas1 As PaintConvas
End Class
