	opt	c+, at+, e+, n-
	section overlay.text

	xdef roll_800C4F80
roll_800C4F80:
	dw 0x3C02800D ; 800C4F80
	dw 0x24429C38 ; 800C4F84
	dw 0x240400A0 ; 800C4F88
	dw 0x24430004 ; 800C4F8C
	dw 0xAC600008 ; 800C4F90
	dw 0xAC600004 ; 800C4F94
	dw 0xAC600000 ; 800C4F98
	dw 0x24630010 ; 800C4F9C
	dw 0xAC400000 ; 800C4FA0
	dw 0x2484FFFC ; 800C4FA4
	dw 0x1C80FFF9 ; 800C4FA8
	dw 0x24420010 ; 800C4FAC
	dw 0x03E00008 ; 800C4FB0
	dw 0x00000000 ; 800C4FB4
