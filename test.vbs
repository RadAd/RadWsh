Set rw = CreateObject("RadWin32")

Const GWL_STYLE = -16

Const WS_VISIBLE = &H10000000

'Set fw = rw.ForegroundWindow

'WScript.Echo Hex(fw.hWnd), fw.Text

Function ToHex(v)
    ToHex = Right(String(8, "0") + Hex(v), 8)
End Function

Sub Process(w, d)
    WScript.Echo Space(d) + ToHex(w.hWnd), ToHex(w.Long(GWL_STYLE)), w.Text, "[" & w.Class & "]"
    For Each cw in w.Children
        If cw.Long(GWL_STYLE) And WS_VISIBLE Then
            Process cw, d + 1
        End If
    Next
End Sub

'WScript.Echo rw.Windows.Count
For Each w in rw.Windows
	If w.Long(GWL_STYLE) And WS_VISIBLE Then
		Process w, 0
	End If
Next
