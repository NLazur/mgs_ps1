	opt	c+, at+, e+, n-
	section overlay.text

	xdef s16c_command_800CF060
s16c_command_800CF060:
	dw 0x0085102A ; 800CF060
	dw 0x10400002 ; 800CF064
	dw 0x00000000 ; 800CF068
	dw 0x00A02021 ; 800CF06C
	dw 0x03E00008 ; 800CF070
	dw 0x00801021 ; 800CF074
