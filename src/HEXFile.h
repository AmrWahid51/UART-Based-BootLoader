/*
 * HEXFile.h
 *
 *  Created on: Sep 15, 2023
 *      Author: dabou
 */

#ifndef HEXFILE_H_
#define HEXFILE_H_

#include "LIB/STD_TYPES.h"

#define NO_RECORDS                 102
#define NO_ELEMENTS_IN_RECORD      150

u8 HEX_arr [NO_RECORDS][NO_ELEMENTS_IN_RECORD] =
{
		":020000040800F2",
		":104000000000012061420008654200086742000884",
		":104010007D4200087F420008954200080000000031",
		":10402000000000000000000000000000AB4200089B",
		":10403000AD42000800000000AF420008B142000895",
		":10404000C5420008C5420008C5420008C542000834",
		":10405000C5420008C5420008C5420008C542000824",
		":10406000C5420008C5420008C5420008C542000814",
		":10407000C5420008C5420008C5420008C542000804",
		":10408000C5420008C5420008C54200080000000003",
		":10409000000000000000000000000000C542000811",
		":1040A000C5420008C5420008C5420008C5420008D4",
		":1040B000C5420008C5420008C5420008C5420008C4",
		":1040C000C5420008C5420008C5420008C5420008B4",
		":1040D000C5420008C5420008C542000800000000B3",
		":1040E000C5420008C5420008C542000800000000A3",
		":1040F000000000000000000000000000C5420008B1",
		":1041000000000000C5420008C5420008C542000882",
		":10411000000000000000000000000000000000009F",
		":10412000C5420008C5420008C5420008C542000853",
		":10413000C542000800000000000000000000000070",
		":10414000000000000000000000000000C542000860",
		":10415000C5420008C5420008C5420008C542000823",
		":10416000C5420008C5420008000000000000000031",
		":10417000000000000000000000000000000000003F",
		":1041800000000000C5420008000000000000000020",
		":10419000C542000807B500F0B7F8274B274883420F",
		":1041A00026D3274B274900208B422DD300F00AFA53",
		":1041B000254E264C01A9684600F09EF8A41BA410C9",
		":1041C0000025AC4229DC224E224CA41BA410002561",
		":1041D000AC4227DCDDE9000100F0F5F91E4D1F4C73",
		":1041E000641B0646A410002C21DC304600F080F849",
		":1041F000D3E900120C3353F8044C891A9442CED9F7",
		":10420000555815600432F9E753F8082B53F8044C5D",
		":104210009442C9D910600432FAE756F8253098471D",
		":104220000135CEE756F8253098470135D0E7013CF7",
		":1042300055F824309847D6E7C8420008E042000805",
		":10424000E0420008F0420008F0420008F042000896",
		":10425000F0420008F0420008F0420008F042000876",
		":1042600014480047FEE71EF0040F0CBFEFF3088070",
		":10427000EFF309807146104A1047FEE7FEE71EF093",
		":10428000040F0CBFEFF30880EFF3098071460B4A6F",
		":104290001047FEE71EF0040F0CBFEFF30880EFF3AA",
		":1042A00009807146064A1047FEE7FEE7FEE7FEE793",
		":1042B00070470000954100087B42000893420008C7",
		":0642C000A9420008FEE720",
		":1042C80008460008000000200800002008460008F2",
		":1042D8000000001000000010080000200C00002062",
		":0842E8000000001000000010AE",
		":1042F00008B500F015F8000001230360014B0B60C6",
		":10430000704700BF0000002008B500F01BF8024B0A",
		":10431000024A9A6008BD00BF00ED00E000400008BE",
		":10432000BFF34F8F0549064BCA6802F4E06213439E",
		":10433000CB60BFF34F8F00BFFDE700BF00ED00E093",
		":104340000400FA050C4B1A68002142F001021A60C1",
		":1043500099601A6822F0847222F480321A60074A47",
		":104360005A601A6822F480221A60D960044B4FF018",
		":1043700000629A60704700BF00380240103000248D",
		":1043800000ED00E0194B1A6822F400221A609A68C6",
		":1043900022F002029A609A6842F001029A609A68DA",
		":1043A00022F0F0029A609A689A609A6822F4E052C9",
		":1043B0009A609A689A609A6822F460429A609A6851",
		":1043C0009A601A6842F480221A601A6842F48032B5",
		":1043D0001A601A689203FCD51A6822F001021A606A",
		":1043E0001A6822F080721A60704700BF00380240DD",
		":1043F0000138072844D8DFE800F0040C141C242CF2",
		":10440000343C204A0123106B03FA01F1014311638C",
		":1044100070471C4A0123506B03FA01F101435163B9",
		":104420007047184A0123106C03FA01F1014311642B",
		":104430007047144A0123506C03FA01F1014351649F",
		":104440007047104A0123106D03FA01F10143116511",
		":1044500070470C4A0123506D03FA01F10143516585",
		":104460007047084A0123106E03FA01F101431166F7",
		":104470007047044A0123506E03FA01F1014351666B",
		":10448000704700BF003802400F2910B506D8032A34",
		":1044900004D8012811D002D3022810D010BD094B36",
		":1044A0001868490003248C4020EA0400186018684A",
		":1044B00002FA01F101431960F0E7034BF0E7034B07",
		":1044C000EEE700BF00000240000402400008024086",
		":1044D000012A15D101280AD002D302280ED0704734",
		":1044E000124B58688A4020EA02025A607047104A0C",
		":1044F0005368884023EA0000506070470D4BF0E796",
		":10450000002AF3D1012809D002D302280CD0704729",
		":10451000064B586801228A400243E6E7044B5A687A",
		":104520008840104358607047024BF2E70000024099",
		":1045300000040240000802400F2910B506D8032AE3",
		":1045400004D8012811D002D3022810D010BD094B85",
		":104550009868490003248C4020EA04009860986819",
		":1045600002FA01F101439960F0E7034BF0E7034BD6",
		":10457000EEE700BF000002400004024000080240D5",
		":10458000012810B50AD002D3022812D010BD0A4B60",
		":10459000586901248C4020EA040004E0074B5C6960",
		":1045A000884024EA0000586158698A4002435A61F1",
		":1045B000ECE7034BECE700BF0000024000040240C0",
		":1045C00000080240704708B5FFF7DCFE002101201B",
		":1045D000FFF70EFF012211460020FFF755FF0122D1",
		":1045E00011460020FFF774FF002201211046FFF75B",
		":1045F000A3FF012211460020FFF7C2FF0022012184",
		":084600001046FFF7BDFFF4E7CF",
		":08460800080000200000000082",
		":040000050800419519",
		":00000001FF"
};
#endif /* HEXFILE_H_ */