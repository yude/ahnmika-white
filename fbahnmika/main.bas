Rem コンパイルするときは文字コードに注意。
Rem 終了時はCtrl+CではなくCを押して下さい。

Dim count as Integer
Dim colors as Integer

Do
    colors = Int(Rnd() * 901 + 100)
    print "白って" & colors & "色あんねん"
    count += 1
Loop Until Inkey = "c"
Print count & "人のアンミカ"
