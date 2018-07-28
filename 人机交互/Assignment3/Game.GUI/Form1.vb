Public Class form1
    Private currentEnemy As ClassLibrary1.Enemy
    Private Hero As New Popeye
    Private intSpinach As Integer = 3
    Private newLog As New EventLog
    Private logShown As Boolean = True

    Private Sub btnSpawn_Click(sender As Object, e As EventArgs) Handles btnSpawn.Click
        GenerateEnemy()
    End Sub

    Private Sub GenerateEnemy()
        Dim generator As New Random
        Dim enemyType As Integer = generator.Next(1, 4)
        Select Case enemyType
            Case 1
                If Not pictureEnemy.Image.Equals(My.Resources.zombie) Then
                    currentEnemy = New ClassLibrary1.Zombie
                    ProgressBarEnemy.Value = ClassLibrary1.Enemy.StartHealth
                    pictureEnemy.Image = My.Resources.zombie
                Else
                    GenerateEnemy()
                End If

            Case 2
                If Not pictureEnemy.Image.Equals(My.Resources.vampire) Then
                    currentEnemy = New ClassLibrary1.Vampire
                    ProgressBarEnemy.Value = ClassLibrary1.Enemy.StartHealth
                    pictureEnemy.Image = My.Resources.vampire
                Else
                    GenerateEnemy()
                End If

            Case 3
                If Not pictureEnemy.Image.Equals(My.Resources.dragon) Then
                    currentEnemy = New ClassLibrary1.Dragen
                    ProgressBarEnemy.Value = ClassLibrary1.Enemy.StartHealth
                    pictureEnemy.Image = My.Resources.dragon
                Else
                    GenerateEnemy()
                End If

        End Select
        UpdateEnemyHealth()
    End Sub

    Private Sub Form1_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        newLog.Show()
        newLog.Location = New Point(Me.Location.X + 700, Me.Location.Y)
        UpdatePopHealth()
        GenerateEnemy()
    End Sub

    Private Sub btnAttack_Click(sender As Object, e As EventArgs) Handles btnAttack.Click
        If intSpinach = 0 Then
            raidoSpinach.Checked = False
            raidoSpinach.Enabled = False
        End If
        If raidoSpinach.Checked = True And intSpinach > 0 Then
            Hero.hasSpinach = True
            intSpinach -= 1
            lblSpinachLeft.Text = "Spinach Left: " & intSpinach.ToString
        End If
        Hero.Attack(currentEnemy.Health)
        newLog.AddEvent(CreatEvent(Popeye.Name))
        Hero.hasSpinach = False
        Try
            UpdateEnemyHealth()
            timerDelay.Start()
        Catch
            ProgressBarEnemy.Value = 0
            MessageBox.Show("Popeye has won!")
            newLog.AddEvent("----------------------------------------")
            newLog.AddEvent("Popeye has won!")
            newLog.AddEvent("----------------------------------------")
            GenerateEnemy()
        End Try
    End Sub

    Private Sub timerDelay_Tick(sender As Object, e As EventArgs) Handles timerDelay.Tick
        EnemyAttack()
    End Sub
    Private Sub EnemyAttack()
        currentEnemy.Attack(Hero.Health)
        newLog.AddEvent(CreatEvent(currentEnemy.strName))
        timerDelay.Stop()
        Try
            UpdatePopHealth()
        Catch
            ProgressBarPopeye.Value = 0
            MessageBox.Show("Popeye has lost!")
            newLog.AddEvent("----------------")
            newLog.AddEvent("Popeye has lost!")
            newLog.AddEvent("----------------")
            Hero.Health = Popeye.StartHealth
            UpdatePopHealth()
        End Try
    End Sub

    Private Sub UpdateEnemyHealth()
        ProgressBarEnemy.Value = currentEnemy.Health
        lblEnemyHealth.Text = "Health: " & currentEnemy.Health
    End Sub

    Private Sub UpdatePopHealth()
        If Hero.Health = 0 Then
            Throw New Exception
        End If
        ProgressBarPopeye.Value = Hero.Health
        lblPopHealth.Text = "Health: " & Hero.Health
    End Sub

    Private Function CreatEvent(ByVal strName As String) As String
        If strName = Popeye.Name Then
            Dim damage As Integer = Hero.AttackDamage(Hero.attackNum)
            If Hero.hasSpinach Then
                damage *= 2
            End If
            Return strName + " has used " + "[" + Hero.Attacks(Hero.attackNum) + "] for [" + damage.ToString + "] damage"
        Else
            Return strName + " has used " + "[" + currentEnemy.Attacks(currentEnemy.attackNum) + "] for [" + currentEnemy.AttackDamage(currentEnemy.attackNum).ToString + "] damage"
        End If
    End Function

    Private Sub Form1_Move(sender As Object, e As EventArgs) Handles MyBase.Move
        newLog.Location = New Point(Me.Location.X + 700, Me.Location.Y)
    End Sub

    Private Sub btnHideAndShow_Click(sender As Object, e As EventArgs) Handles btnHideAndShow.Click
        If logShown Then
            newLog.Hide()
            btnHideAndShow.Text = "Show Log"
            logShown = Not logShown
        Else
            newLog.Show()
            btnHideAndShow.Text = "Hide Log"
            logShown = Not logShown
        End If
    End Sub

End Class
