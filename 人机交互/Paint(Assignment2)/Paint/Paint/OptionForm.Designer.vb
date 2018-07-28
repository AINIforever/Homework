<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class OptionForm
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
        Me.Label1 = New System.Windows.Forms.Label()
        Me.ComboBox1 = New System.Windows.Forms.ComboBox()
        Me.BtnColor = New System.Windows.Forms.Button()
        Me.lblColor = New System.Windows.Forms.Label()
        Me.Label3 = New System.Windows.Forms.Label()
        Me.BtnClear = New System.Windows.Forms.Button()
        Me.ColorDialogBrush = New System.Windows.Forms.ColorDialog()
        Me.SuspendLayout()
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(36, 27)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(65, 12)
        Me.Label1.TabIndex = 0
        Me.Label1.Text = "Brush Size"
        '
        'ComboBox1
        '
        Me.ComboBox1.FormattingEnabled = True
        Me.ComboBox1.Items.AddRange(New Object() {"Small", "Medium", "Large"})
        Me.ComboBox1.Location = New System.Drawing.Point(38, 53)
        Me.ComboBox1.Name = "ComboBox1"
        Me.ComboBox1.Size = New System.Drawing.Size(152, 20)
        Me.ComboBox1.TabIndex = 0
        '
        'BtnColor
        '
        Me.BtnColor.Location = New System.Drawing.Point(38, 111)
        Me.BtnColor.Name = "BtnColor"
        Me.BtnColor.Size = New System.Drawing.Size(152, 24)
        Me.BtnColor.TabIndex = 2
        Me.BtnColor.Text = "Change Color"
        Me.BtnColor.UseVisualStyleBackColor = True
        '
        'lblColor
        '
        Me.lblColor.AutoSize = True
        Me.lblColor.Location = New System.Drawing.Point(38, 93)
        Me.lblColor.Name = "lblColor"
        Me.lblColor.Size = New System.Drawing.Size(71, 12)
        Me.lblColor.TabIndex = 3
        Me.lblColor.Text = "Brush Color"
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.Location = New System.Drawing.Point(40, 160)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(77, 12)
        Me.Label3.TabIndex = 4
        Me.Label3.Text = "Clear Canvas"
        '
        'BtnClear
        '
        Me.BtnClear.Location = New System.Drawing.Point(42, 185)
        Me.BtnClear.Name = "BtnClear"
        Me.BtnClear.Size = New System.Drawing.Size(148, 22)
        Me.BtnClear.TabIndex = 5
        Me.BtnClear.Text = "New Canvas"
        Me.BtnClear.UseVisualStyleBackColor = True
        '
        'OptionForm
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 12.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(284, 261)
        Me.Controls.Add(Me.BtnClear)
        Me.Controls.Add(Me.Label3)
        Me.Controls.Add(Me.lblColor)
        Me.Controls.Add(Me.BtnColor)
        Me.Controls.Add(Me.ComboBox1)
        Me.Controls.Add(Me.Label1)
        Me.Name = "OptionForm"
        Me.Text = "OptionForm"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents Label1 As Label
    Friend WithEvents ComboBox1 As ComboBox
    Friend WithEvents BtnColor As Button
    Friend WithEvents lblColor As Label
    Friend WithEvents Label3 As Label
    Friend WithEvents BtnClear As Button
    Friend WithEvents ColorDialogBrush As ColorDialog
End Class
