	opt	c+, at+, e+, n-
	section overlay.text

	xdef s00a_fadeio_or_telop_800DD550
s00a_fadeio_or_telop_800DD550:
	dw 0x27BDFFD0 ; 800DD550
	dw 0xAFB50024 ; 800DD554
	dw 0x0080A821 ; 800DD558
	dw 0xAFB10014 ; 800DD55C
	dw 0x00A08821 ; 800DD560
	dw 0xAFB40020 ; 800DD564
	dw 0x00C0A021 ; 800DD568
	dw 0xAFB20018 ; 800DD56C
	dw 0x00E09021 ; 800DD570
	dw 0xAFB00010 ; 800DD574
	dw 0x26B00008 ; 800DD578
	dw 0xAFB3001C ; 800DD57C
	dw 0x8FB30040 ; 800DD580
	dw 0xAFBF0028 ; 800DD584
	dw 0x0C037EC7 ; 800DD588
	dw 0x02002021 ; 800DD58C
	dw 0x02002021 ; 800DD590
	dw 0x0C024916 ; 800DD594
	dw 0x24050001 ; 800DD598
	dw 0xA2000004 ; 800DD59C
	dw 0xA2000005 ; 800DD5A0
	dw 0xA2000006 ; 800DD5A4
	dw 0xA6110008 ; 800DD5A8
	dw 0xA614000A ; 800DD5AC
	dw 0x92620008 ; 800DD5B0
	dw 0x00000000 ; 800DD5B4
	dw 0xA202000C ; 800DD5B8
	dw 0x92620009 ; 800DD5BC
	dw 0x00000000 ; 800DD5C0
	dw 0xA202000D ; 800DD5C4
	dw 0x9262000A ; 800DD5C8
	dw 0x00000000 ; 800DD5CC
	dw 0x24420001 ; 800DD5D0
	dw 0xA6020010 ; 800DD5D4
	dw 0x9262000B ; 800DD5D8
	dw 0x00000000 ; 800DD5DC
	dw 0x24420001 ; 800DD5E0
	dw 0xA6020012 ; 800DD5E4
	dw 0x96620006 ; 800DD5E8
	dw 0x00000000 ; 800DD5EC
	dw 0xA602000E ; 800DD5F0
	dw 0x8EA80008 ; 800DD5F4
	dw 0x8EA9000C ; 800DD5F8
	dw 0x8EAA0010 ; 800DD5FC
	dw 0x8EAB0014 ; 800DD600
	dw 0xAEA80024 ; 800DD604
	dw 0xAEA90028 ; 800DD608
	dw 0xAEAA002C ; 800DD60C
	dw 0xAEAB0030 ; 800DD610
	dw 0x8EA80018 ; 800DD614
	dw 0x00000000 ; 800DD618
	dw 0xAEA80034 ; 800DD61C
	dw 0x92420008 ; 800DD620
	dw 0x26B10024 ; 800DD624
	dw 0xA222000C ; 800DD628
	dw 0x92420009 ; 800DD62C
	dw 0x26B4001C ; 800DD630
	dw 0xA222000D ; 800DD634
	dw 0x9242000A ; 800DD638
	dw 0x02802021 ; 800DD63C
	dw 0x24420001 ; 800DD640
	dw 0xA6220010 ; 800DD644
	dw 0x9242000B ; 800DD648
	dw 0x00002821 ; 800DD64C
	dw 0x24420001 ; 800DD650
	dw 0xA6220012 ; 800DD654
	dw 0x96420006 ; 800DD658
	dw 0x24060001 ; 800DD65C
	dw 0xA622000E ; 800DD660
	dw 0x96420004 ; 800DD664
	dw 0x2412FF9F ; 800DD668
	dw 0x00521024 ; 800DD66C
	dw 0x0C02492A ; 800DD670
	dw 0x34470020 ; 800DD674
	dw 0x02A02021 ; 800DD678
	dw 0x00002821 ; 800DD67C
	dw 0x96620004 ; 800DD680
	dw 0x24060001 ; 800DD684
	dw 0x00521024 ; 800DD688
	dw 0x0C02492A ; 800DD68C
	dw 0x34470040 ; 800DD690
	dw 0x02A02021 ; 800DD694
	dw 0x0C037ED7 ; 800DD698
	dw 0x02002821 ; 800DD69C
	dw 0x02802021 ; 800DD6A0
	dw 0x0C037ED7 ; 800DD6A4
	dw 0x02202821 ; 800DD6A8
	dw 0x02A02021 ; 800DD6AC
	dw 0x0C037ED7 ; 800DD6B0
	dw 0x02802821 ; 800DD6B4
	dw 0x26A30038 ; 800DD6B8
	dw 0x02A01021 ; 800DD6BC
	dw 0x26A40030 ; 800DD6C0
	dw 0x8C480000 ; 800DD6C4
	dw 0x8C490004 ; 800DD6C8
	dw 0x8C4A0008 ; 800DD6CC
	dw 0x8C4B000C ; 800DD6D0
	dw 0xAC680000 ; 800DD6D4
	dw 0xAC690004 ; 800DD6D8
	dw 0xAC6A0008 ; 800DD6DC
	dw 0xAC6B000C ; 800DD6E0
	dw 0x24420010 ; 800DD6E4
	dw 0x1444FFF6 ; 800DD6E8
	dw 0x24630010 ; 800DD6EC
	dw 0x8C480000 ; 800DD6F0
	dw 0x8C490004 ; 800DD6F4
	dw 0xAC680000 ; 800DD6F8
	dw 0xAC690004 ; 800DD6FC
	dw 0xAEA00070 ; 800DD700
	dw 0xAEA00080 ; 800DD704
	dw 0xAEA0007C ; 800DD708
	dw 0x8FBF0028 ; 800DD70C
	dw 0x8FB50024 ; 800DD710
	dw 0x8FB40020 ; 800DD714
	dw 0x8FB3001C ; 800DD718
	dw 0x8FB20018 ; 800DD71C
	dw 0x8FB10014 ; 800DD720
	dw 0x8FB00010 ; 800DD724
	dw 0x03E00008 ; 800DD728
	dw 0x27BD0030 ; 800DD72C
