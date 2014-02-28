Set rw = CreateObject("RadWin32")

Const GWL_STYLE = -16

Const WS_VISIBLE = &H10000000

'Set fw = rw.ForegroundWindow

'WScript.Echo Hex(fw.hWnd), fw.Text

Function ToHex(v)
    ToHex = Right(String(8, "0") + Hex(v), 8)
End Function

Set ws = rw.Windows
WScript.Echo ws.Count
For Each w in ws
	'WScript.Echo ws.Count
	If w.Long(GWL_STYLE) And WS_VISIBLE Then
		WScript.Echo ToHex(w.hWnd), ToHex(w.Long(GWL_STYLE)), w.Text, "[" & w.Class & "]"
	End If
Next
