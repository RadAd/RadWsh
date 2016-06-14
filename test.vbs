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

Sub Process(w, d)
    If w.Style And WS_VISIBLE Then
        'WScript.Echo Space(d) + ToHex(w.hWnd), ToHex(w.Parent.hWnd), ToHex(w.Long(GWL_STYLE)), ToHex(w.Long(GWL_EXSTYLE)), w.Text, "[" & w.Class & "]"
        WScript.Echo Space(d) + ToHex(w.hWnd), ToHex(w.Style), ToHex(w.ExStyle), w.Text, "[" & w.Class & "]"
        For Each cw in w.Children
            Process cw, d + 1
        Next
    End If
End Sub

Set w = rw.Window(&h10124)
Process w, 0
