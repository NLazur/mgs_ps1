	opt	c+, at+, e+, n-
	section overlay.text

	xdef s16c_camera_800D2FEC
s16c_camera_800D2FEC:
	dw 0x24830020 ; 800D2FEC
	dw 0x9462003A ; 800D2FF0
	dw 0x00000000 ; 800D2FF4
	dw 0x34422000 ; 800D2FF8
	dw 0xA462003A ; 800D2FFC
	dw 0x9482027E ; 800D3000
	dw 0x2483005C ; 800D3004
	dw 0xA480005C ; 800D3008
	dw 0xA4620002 ; 800D300C
	dw 0x94820280 ; 800D3010
	dw 0xA4600006 ; 800D3014
	dw 0x00021040 ; 800D3018
	dw 0x03E00008 ; 800D301C
	dw 0xA4620004 ; 800D3020
