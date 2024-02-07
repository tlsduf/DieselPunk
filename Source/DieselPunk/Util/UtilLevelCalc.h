#pragma once


// (임시) 레벨 간단하게 구현하기 위한 정보입니다. 레벨당 경험치, 레벨당 체력 등

namespace UtilLevelCal
{
	FORCEINLINE int LevelCalc(int inExp)
	{
		return
		  (0 <= inExp && inExp < 10) ? 1
		: (10 <= inExp && inExp < 25) ? 2
		: (25 <= inExp && inExp < 45) ? 3
		: (45 <= inExp && inExp < 70) ? 4
		: (70 <= inExp && inExp < 100) ? 5
		: (100 <= inExp && inExp < 135) ? 6
		: (135 <= inExp && inExp < 175) ? 7
		: (175 <= inExp && inExp < 220) ? 8
		: (220 <= inExp && inExp < 270) ? 9
		: (270 <= inExp && inExp < 325) ? 10
		: (325 <= inExp && inExp < 385) ? 11
		: (385 <= inExp && inExp < 450) ? 12
		: (450 <= inExp && inExp < 515) ? 13
		: (515 <= inExp && inExp < 585) ? 14
		: (585 <= inExp && inExp < 660) ? 15
		: (660 <= inExp && inExp < 740) ? 16
		: (740 <= inExp && inExp < 825) ? 17
		: (825 <= inExp && inExp < 915) ? 18
		: (915 <= inExp && inExp < 1010) ? 19
		: (1010 <= inExp && inExp < 1110) ? 20
		: (1110 <= inExp && inExp < 1215) ? 21
		: (1215 <= inExp && inExp < 1325) ? 22
		: (1325 <= inExp && inExp < 1440) ? 23
		: (1440 <= inExp && inExp < 1560) ? 24
		: 25	//End
		;
	}

	FORCEINLINE int MaxHealthCalc(int inLevel)
	{
		return
		  (inLevel == 1) ? 200
		: (inLevel == 2) ? 210
		: (inLevel == 3) ? 220
		: (inLevel == 4) ? 230
		: (inLevel == 5) ? 240
		: (inLevel == 6) ? 250
		: (inLevel == 7) ? 260
		: (inLevel == 8) ? 270
		: (inLevel == 9) ? 280
		: (inLevel == 10) ? 290
		: (inLevel == 11) ? 200
		: (inLevel == 12) ? 210
		: (inLevel == 13) ? 220
		: (inLevel == 14) ? 230
		: (inLevel == 15) ? 240
		: (inLevel == 16) ? 250
		: (inLevel == 17) ? 260
		: (inLevel == 18) ? 270
		: (inLevel == 19) ? 280
		: (inLevel == 20) ? 290
		: (inLevel == 21) ? 300
		: (inLevel == 22) ? 310
		: (inLevel == 23) ? 320
		: (inLevel == 24) ? 330
		: 340
		;
	}

	FORCEINLINE int MaxExpCalc(int inLevel)
	{
		return 
		  (inLevel == 1) ? 10
		: (inLevel == 2) ? 25
		: (inLevel == 3) ? 45
		: (inLevel == 4) ? 70
		: (inLevel == 5) ? 100
		: (inLevel == 6) ? 135
		: (inLevel == 7) ? 175
		: (inLevel == 8) ? 220
		: (inLevel == 9) ? 270
		: (inLevel == 10) ? 325
		: (inLevel == 11) ? 385
		: (inLevel == 12) ? 450
		: (inLevel == 13) ? 515
		: (inLevel == 14) ? 585
		: (inLevel == 15) ? 660
		: (inLevel == 16) ? 740
		: (inLevel == 17) ? 825
		: (inLevel == 18) ? 915
		: (inLevel == 19) ? 1010
		: (inLevel == 20) ? 1110
		: (inLevel == 21) ? 1215
		: (inLevel == 22) ? 1325
		: (inLevel == 23) ? 1440
		: (inLevel == 24) ? 1560
		: 9999
	  ;
	}
}
