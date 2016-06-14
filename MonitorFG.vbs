Set rw = CreateObject("RadWin32")

Function ToHex(v)
    ToHex = Right(String(8, "0") + Hex(v), 8)
End Function

Set w = Nothing
While True
	Set nw = rw.ForegroundWindow
	If Not w Is nw Then
		Set w = nw
		WScript.Echo "-", ToHex(w.hWnd), w.pid, """" & w.Text & """", "[" & w.Class & "]"
	Else
		WScript.Sleep(1000)
	End If
WEnd
