	opt	c+, at+, e+, n-
	section overlay.text

	xdef s16c_command_800CAC18
s16c_command_800CAC18:
	dw 0x24020007 ; 800CAC18
	dw 0xA4820B22 ; 800CAC1C
	dw 0x2402000E ; 800CAC20
	dw 0xA4820B24 ; 800CAC24
	dw 0x03E00008 ; 800CAC28
	dw 0xAC800B28 ; 800CAC2C
