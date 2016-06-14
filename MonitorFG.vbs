Set rw = CreateObject("RadWin32")

Const GWL_EXSTYLE = -20
Const GWL_STYLE = -16
Const GWL_ID = -12

Const WS_VISIBLE = &H10000000

'Set fw = rw.ForegroundWindow

'WScript.Echo Hex(fw.hWnd), fw.Text

Function ToHex(v)
    ToHex = Right(String(8, "0") + Hex(v), 8)
End Function

Function Equal(a, b)
    If (a Is Nothing) Then
		Equal = False
	Elseif (b Is Nothing) Then
		Equal = False
	Else
		Equal = (CLng(w.hWnd) = CLng(nw.hWnd))
	End If
End Function

Set w = Nothing
'WScript.Echo "IsNothing", (w Is Nothing)
'WScript.Echo "IsNull", IsNull(w)
While True
	Set nw = rw.ForegroundWindow
	If Not Equal(w, nw) Then
		Set w = nw
		WScript.Echo "-", ToHex(w.hWnd), """" & w.Text & """", "[" & w.Class & "]"
	End If
	WScript.Sleep(1000)
WEnd
