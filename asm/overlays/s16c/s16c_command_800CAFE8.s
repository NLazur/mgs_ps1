	opt	c+, at+, e+, n-
	section overlay.text

	xdef s16c_command_800CAFE8
s16c_command_800CAFE8:
	dw 0x24020002 ; 800CAFE8
	dw 0xA4820B22 ; 800CAFEC
	dw 0x24020005 ; 800CAFF0
	dw 0xA4820B24 ; 800CAFF4
	dw 0x03E00008 ; 800CAFF8
	dw 0xAC800B28 ; 800CAFFC
