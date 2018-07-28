Public Class Zombie
    Inherits Enemy
    Public ReadOnly ZombieAttacks() As String = {"Eat brains", "Claw", "Throw up"}
    Public ReadOnly ZombieAttackDamage()
    Sub New()
        strName = "Zombie"
        Attacks(0) = "Eat brains"
        Attacks(1) = "Claw"
        Attacks(2) = "Throw up"
        AttackDamage(0) = 15
        AttackDamage(1) = 5
        AttackDamage(2) = 2
    End Sub
    Public Overrides Sub Attack(ByRef userHealth As Integer)
        Dim gen As New Random
        Dim attackNum As Integer = gen.Next(0, 2)
        Select Case attackNum
            Case 0
                userHealth -= 15
            Case 1
                userHealth -= 5
            Case 2
                userHealth -= 2
        End Select
    End Sub
End Class
