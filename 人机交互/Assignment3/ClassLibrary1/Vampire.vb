Public Class Vampire
    Inherits Enemy
    Public ReadOnly VamPireAttacks() As String = {"Shoot", "Stab", "Explode"}
    Public ReadOnly VampireAttackDamage()
    Sub New()
        strName = "VamPire"
        Attacks(0) = "Shoot"
        Attacks(1) = "Stab"
        Attacks(2) = "Explode"
        AttackDamage(0) = 10
        AttackDamage(1) = 8
        AttackDamage(2) = 12
    End Sub
    Public Overrides Sub Attack(ByRef userHealth As Integer)
        Dim gen As New Random
        Dim attackNum As Integer = gen.Next(0, 2)
        Select Case attackNum
            Case 0
                userHealth -= 10
            Case 1
                userHealth -= 8
            Case 2
                userHealth -= 12
        End Select
    End Sub
End Class
