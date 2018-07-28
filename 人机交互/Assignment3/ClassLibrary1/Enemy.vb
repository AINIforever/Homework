Public Class Enemy
    Public Shared StartHealth As Integer = 100
    Public strName As String
    Public attackNum As Integer
    Private IntHealth As Integer
    Public ReadOnly Attacks(3) As String
    Public ReadOnly AttackDamage(3) As String
    Sub New()
        IntHealth = StartHealth
    End Sub
    Public Overridable Sub Attack(ByRef userHealth As Integer)

    End Sub
    Public Property Health() As Integer
        Get
            Return IntHealth
        End Get
        Set(ByVal value As Integer)
            IntHealth = value
        End Set
    End Property
End Class