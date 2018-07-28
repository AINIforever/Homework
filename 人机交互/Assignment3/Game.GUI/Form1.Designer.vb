<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class form1
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
        Me.components = New System.ComponentModel.Container()
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(form1))
        Me.picturPopeye = New System.Windows.Forms.PictureBox()
        Me.pictureEnemy = New System.Windows.Forms.PictureBox()
        Me.btnAttack = New System.Windows.Forms.Button()
        Me.ProgressBarPopeye = New System.Windows.Forms.ProgressBar()
        Me.ProgressBarEnemy = New System.Windows.Forms.ProgressBar()
        Me.btnSpawn = New System.Windows.Forms.Button()
        Me.raidoSpinach = New System.Windows.Forms.RadioButton()
        Me.lblSpinachLeft = New System.Windows.Forms.Label()
        Me.timerDelay = New System.Windows.Forms.Timer(Me.components)
        Me.lblPopHealth = New System.Windows.Forms.Label()
        Me.lblEnemyHealth = New System.Windows.Forms.Label()
        Me.btnHideAndShow = New System.Windows.Forms.Button()
        CType(Me.picturPopeye, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.pictureEnemy, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'picturPopeye
        '
        Me.picturPopeye.Image = CType(resources.GetObject("picturPopeye.Image"), System.Drawing.Image)
        Me.picturPopeye.Location = New System.Drawing.Point(12, 46)
        Me.picturPopeye.Name = "picturPopeye"
        Me.picturPopeye.Size = New System.Drawing.Size(146, 179)
        Me.picturPopeye.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage
        Me.picturPopeye.TabIndex = 0
        Me.picturPopeye.TabStop = False
        '
        'pictureEnemy
        '
        Me.pictureEnemy.Image = Global.Game.GUI.My.Resources.Resources.vampire
        Me.pictureEnemy.Location = New System.Drawing.Point(408, 46)
        Me.pictureEnemy.Name = "pictureEnemy"
        Me.pictureEnemy.Size = New System.Drawing.Size(148, 179)
        Me.pictureEnemy.TabIndex = 1
        Me.pictureEnemy.TabStop = False
        '
        'btnAttack
        '
        Me.btnAttack.Location = New System.Drawing.Point(12, 12)
        Me.btnAttack.Name = "btnAttack"
        Me.btnAttack.Size = New System.Drawing.Size(146, 23)
        Me.btnAttack.TabIndex = 2
        Me.btnAttack.Text = "Attack"
        Me.btnAttack.UseVisualStyleBackColor = True
        '
        'ProgressBarPopeye
        '
        Me.ProgressBarPopeye.Location = New System.Drawing.Point(12, 231)
        Me.ProgressBarPopeye.Maximum = 250
        Me.ProgressBarPopeye.Name = "ProgressBarPopeye"
        Me.ProgressBarPopeye.Size = New System.Drawing.Size(146, 23)
        Me.ProgressBarPopeye.TabIndex = 3
        '
        'ProgressBarEnemy
        '
        Me.ProgressBarEnemy.Location = New System.Drawing.Point(408, 231)
        Me.ProgressBarEnemy.Name = "ProgressBarEnemy"
        Me.ProgressBarEnemy.Size = New System.Drawing.Size(148, 23)
        Me.ProgressBarEnemy.TabIndex = 4
        '
        'btnSpawn
        '
        Me.btnSpawn.FlatStyle = System.Windows.Forms.FlatStyle.System
        Me.btnSpawn.Location = New System.Drawing.Point(408, 12)
        Me.btnSpawn.Name = "btnSpawn"
        Me.btnSpawn.Size = New System.Drawing.Size(148, 23)
        Me.btnSpawn.TabIndex = 5
        Me.btnSpawn.Text = "Spawn Enemy"
        Me.btnSpawn.UseVisualStyleBackColor = True
        '
        'raidoSpinach
        '
        Me.raidoSpinach.AutoSize = True
        Me.raidoSpinach.Location = New System.Drawing.Point(178, 15)
        Me.raidoSpinach.Name = "raidoSpinach"
        Me.raidoSpinach.Size = New System.Drawing.Size(89, 16)
        Me.raidoSpinach.TabIndex = 6
        Me.raidoSpinach.TabStop = True
        Me.raidoSpinach.Text = "Use Spinach"
        Me.raidoSpinach.UseVisualStyleBackColor = True
        '
        'lblSpinachLeft
        '
        Me.lblSpinachLeft.AutoSize = True
        Me.lblSpinachLeft.Location = New System.Drawing.Point(176, 59)
        Me.lblSpinachLeft.Name = "lblSpinachLeft"
        Me.lblSpinachLeft.Size = New System.Drawing.Size(89, 12)
        Me.lblSpinachLeft.TabIndex = 7
        Me.lblSpinachLeft.Text = "Spinach left:3"
        '
        'timerDelay
        '
        Me.timerDelay.Interval = 1000
        '
        'lblPopHealth
        '
        Me.lblPopHealth.AutoSize = True
        Me.lblPopHealth.Location = New System.Drawing.Point(12, 269)
        Me.lblPopHealth.Name = "lblPopHealth"
        Me.lblPopHealth.Size = New System.Drawing.Size(41, 12)
        Me.lblPopHealth.TabIndex = 8
        Me.lblPopHealth.Text = "Health"
        '
        'lblEnemyHealth
        '
        Me.lblEnemyHealth.AutoSize = True
        Me.lblEnemyHealth.Location = New System.Drawing.Point(406, 269)
        Me.lblEnemyHealth.Name = "lblEnemyHealth"
        Me.lblEnemyHealth.Size = New System.Drawing.Size(41, 12)
        Me.lblEnemyHealth.TabIndex = 9
        Me.lblEnemyHealth.Text = "Health"
        '
        'btnHideAndShow
        '
        Me.btnHideAndShow.Location = New System.Drawing.Point(12, 284)
        Me.btnHideAndShow.Name = "btnHideAndShow"
        Me.btnHideAndShow.Size = New System.Drawing.Size(544, 25)
        Me.btnHideAndShow.TabIndex = 10
        Me.btnHideAndShow.Text = "Hide Log"
        Me.btnHideAndShow.UseVisualStyleBackColor = True
        '
        'form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 12.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(568, 321)
        Me.Controls.Add(Me.btnHideAndShow)
        Me.Controls.Add(Me.lblEnemyHealth)
        Me.Controls.Add(Me.lblPopHealth)
        Me.Controls.Add(Me.lblSpinachLeft)
        Me.Controls.Add(Me.raidoSpinach)
        Me.Controls.Add(Me.btnSpawn)
        Me.Controls.Add(Me.ProgressBarEnemy)
        Me.Controls.Add(Me.ProgressBarPopeye)
        Me.Controls.Add(Me.btnAttack)
        Me.Controls.Add(Me.pictureEnemy)
        Me.Controls.Add(Me.picturPopeye)
        Me.Name = "form1"
        Me.Text = "Spinach left:3"
        CType(Me.picturPopeye, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.pictureEnemy, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents picturPopeye As PictureBox
    Friend WithEvents pictureEnemy As PictureBox
    Friend WithEvents btnAttack As Button
    Friend WithEvents ProgressBarPopeye As ProgressBar
    Friend WithEvents ProgressBarEnemy As ProgressBar
    Friend WithEvents btnSpawn As Button
    Friend WithEvents raidoSpinach As RadioButton
    Friend WithEvents lblSpinachLeft As Label
    Friend WithEvents timerDelay As Timer
    Friend WithEvents lblPopHealth As Label
    Friend WithEvents lblEnemyHealth As Label
    Friend WithEvents btnHideAndShow As Button
End Class
