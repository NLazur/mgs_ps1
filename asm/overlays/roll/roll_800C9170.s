	opt	c+, at+, e+, n-
	section overlay.text

	xdef roll_800C9170
roll_800C9170:
	dw 0x27BDFFE8 ; 800C9170
	dw 0x14800005 ; 800C9174
	dw 0xAFBF0010 ; 800C9178
	dw 0x0C03250F ; 800C917C
	dw 0x00000000 ; 800C9180
	dw 0x08032467 ; 800C9184
	dw 0x00000000 ; 800C9188
	dw 0x0C032559 ; 800C918C
	dw 0x00000000 ; 800C9190
	dw 0x00021742 ; 800C9194
	dw 0x30420001 ; 800C9198
