Public Class Dragen
    Inherits Enemy
    Public ReadOnly DragenAttacks() As String = {"Blow Fire", "Claw", "Tail Smash"}
    Public ReadOnly DragenAttackDamage()
    Sub New()
        strName = "Dragen"
        Attacks(0) = "Blow Fire"
        Attacks(1) = "Claw"
        Attacks(2) = "Tail Smash"
        AttackDamage(0) = 15
        AttackDamage(1) = 8
        AttackDamage(2) = 10
    End Sub
    Public Overrides Sub Attack(ByRef userHealth As Integer)
        Dim gen As New Random
        Dim attackNum As Integer = gen.Next(0, 2)
        Select Case attackNum
            Case 0
                userHealth -= 15
            Case 1
                userHealth -= 8
            Case 2
                userHealth -= 10
        End Select
    End Sub
End Class
