	opt	c+, at+, e+, n-
	section overlay.text

	xdef s16c_command_800CFB00
s16c_command_800CFB00:
	dw 0x27BDFFE0 ; 800CFB00
	dw 0xAFB10014 ; 800CFB04
	dw 0x00808821 ; 800CFB08
	dw 0xAFB20018 ; 800CFB0C
	dw 0x00009021 ; 800CFB10
	dw 0xAFBF001C ; 800CFB14
	dw 0x1220000B ; 800CFB18
	dw 0xAFB00010 ; 800CFB1C
	dw 0x0C00827A ; 800CFB20
	dw 0x02202021 ; 800CFB24
	dw 0x0C0082A9 ; 800CFB28
	dw 0x00408021 ; 800CFB2C
	dw 0x00408821 ; 800CFB30
	dw 0x02002021 ; 800CFB34
	dw 0x0C007FCB ; 800CFB38
	dw 0x00002821 ; 800CFB3C
	dw 0x1620FFF7 ; 800CFB40
	dw 0x26520001 ; 800CFB44
	dw 0x02401021 ; 800CFB48
	dw 0x8FBF001C ; 800CFB4C
	dw 0x8FB20018 ; 800CFB50
	dw 0x8FB10014 ; 800CFB54
	dw 0x8FB00010 ; 800CFB58
	dw 0x03E00008 ; 800CFB5C
	dw 0x27BD0020 ; 800CFB60
