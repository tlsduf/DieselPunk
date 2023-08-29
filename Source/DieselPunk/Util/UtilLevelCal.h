


#pragma once


namespace UtilLevelCal
{
	FORCEINLINE int LevelCal(int inExp)
	{
		return
		  (1 <= inExp && inExp < 10) ? 1
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

	FORCEINLINE int MaxHealthCal(int inLevel)
	{
		return
		  (inLevel == 1) ? 100
		: (inLevel == 2) ? 110
		: (inLevel == 3) ? 120
		: (inLevel == 4) ? 130
		: (inLevel == 5) ? 140
		: (inLevel == 6) ? 150
		: (inLevel == 7) ? 160
		: (inLevel == 8) ? 170
		: (inLevel == 9) ? 180
		: (inLevel == 10) ? 190
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

	FORCEINLINE int MaxExpCal(int inLevel)
	{
		return 1;
	}
}
