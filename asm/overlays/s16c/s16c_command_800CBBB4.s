	opt	c+, at+, e+, n-
	section overlay.text

	xdef s16c_command_800CBBB4
s16c_command_800CBBB4:
	dw 0x27BDFFE0 ; 800CBBB4
	dw 0x00801021 ; 800CBBB8
	dw 0x00A02021 ; 800CBBBC
	dw 0x00402821 ; 800CBBC0
	dw 0xAFBF0018 ; 800CBBC4
	dw 0x0C005B50 ; 800CBBC8
	dw 0x27A60010 ; 800CBBCC
	dw 0x0C005BBE ; 800CBBD0
	dw 0x27A40010 ; 800CBBD4
	dw 0x8FBF0018 ; 800CBBD8
	dw 0x00000000 ; 800CBBDC
	dw 0x03E00008 ; 800CBBE0
	dw 0x27BD0020 ; 800CBBE4
