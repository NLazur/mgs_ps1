	opt	c+, at+, e+, n-
	section overlay.text

	xdef s00a_command_800CC210
s00a_command_800CC210:
	dw 0x27BDFFE8 ; 800CC210
	dw 0xAFB00010 ; 800CC214
	dw 0x00808021 ; 800CC218
	dw 0x26040020 ; 800CC21C
	dw 0xAFBF0014 ; 800CC220
	dw 0x0C033077 ; 800CC224
	dw 0x26050BE0 ; 800CC228
	dw 0xA6020B48 ; 800CC22C
	dw 0x8FBF0014 ; 800CC230
	dw 0x8FB00010 ; 800CC234
	dw 0x03E00008 ; 800CC238
	dw 0x27BD0018 ; 800CC23C
