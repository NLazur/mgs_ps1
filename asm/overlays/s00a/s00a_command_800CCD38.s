	opt	c+, at+, e+, n-
	section overlay.text

	xdef s00a_command_800CCD38
s00a_command_800CCD38:
	dw 0x00802821 ; 800CCD38
	dw 0x3C030001 ; 800CCD3C
	dw 0x8CA20B38 ; 800CCD40
	dw 0x8CA40B28 ; 800CCD44
	dw 0x00431825 ; 800CCD48
	dw 0x14800005 ; 800CCD4C
	dw 0xACA30B38 ; 800CCD50
	dw 0x3C020020 ; 800CCD54
	dw 0x00621025 ; 800CCD58
	dw 0x08033361 ; 800CCD5C
	dw 0xACA20B38 ; 800CCD60
	dw 0x84A200B6 ; 800CCD64
	dw 0x00000000 ; 800CCD68
	dw 0x14400003 ; 800CCD6C
	dw 0x2C82001F ; 800CCD70
	dw 0x14400004 ; 800CCD74
	dw 0x00001021 ; 800CCD78
	dw 0x03E00008 ; 800CCD7C
	dw 0x24020001 ; 800CCD80
	dw 0x00001021 ; 800CCD84
	dw 0x8CA30B28 ; 800CCD88
	dw 0x94A40C28 ; 800CCD8C
	dw 0x24630001 ; 800CCD90
	dw 0xA4A40B48 ; 800CCD94
	dw 0x03E00008 ; 800CCD98
	dw 0xACA30B28 ; 800CCD9C
