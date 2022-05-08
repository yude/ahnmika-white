@echo OFF
REM 割り込みハンドラないし、CHOICE 関数は待機時間の最小単位 1s だしブチギレ
echo "終了時には Ctrl + C ではなく C を入力"

REM 変数初期化
set ERRORLEVEL = 255
set REPEAT = 0
set SIGNAL = False


:LOOP

set /a R=100+%RANDOM%*900/32768
echo 白って%R%色あんねん
set /a REPEAT = %REPEAT% + 1

CHOICE /C CN /T 1 /D N /N

REM C が選択されたら
if /i %ERRORLEVEL% equ 1 (
	echo %REPEAT%人のアンミカ
	pause
	exit
)

GOTO :LOOP

