#include <windows.h>
#include <winsock.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <io.h>
#include <conio.h> //getch() and kbhit()
#include <ctype.h> //toupper(), isspace(), isdigit(), isalpha()
#include <setjmp.h> //simulate try/catch in C

#include "zlib.h"
//this all the lib's required to compile this, it's ignored in C-Free
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "zlib.lib")

#define IMAGE_BITMAP 0
//#define LR_LOADFROMFILE     0x0010
//#define LR_CREATEDIBSECTION 0x2000

struct _msExcInfo;
struct _msExcExt;
struct _msRttiDscr;
struct SHIP_SETTINGS;
struct SERVERSIDE_ARENA_SETTINGS;
struct VOICE_UPLOAD_STRUCT;
struct PLAYER;
struct SOCCER_BALL;
struct FLAG;
struct SCORE;
struct BRICK;
struct MAP_TILE;
struct SECURITY_PACKET_STRUCT;
struct PRIZE_PACKET_STRUCT;
struct PLAYER_DATA_BILLER_PACKET_STRUCT;
struct CONNECTION;
struct KICK;
struct TEMPLATE_SSS;
struct SETTING_CATEGORY;
struct SETTING;
struct struc_2;
struct CHAT;
struct TEXT_FILE_STRUCT;
struct SERVER_BIG_ARRAY;
struct PACKET;
struct PACKET_ADVERTISEMENT;
struct PACKET_ATTACHMENT_HISTORY;
struct PACKET_ATTACHMENT_SUB_STRUCT;
struct PACKET_ATTACHMENT;
struct _msExcept;
struct ARENA_SETTINGS;
struct ARENA;
struct BILLING_SERVER_STRUCT;
struct BMP_FILE_STRUCT;
struct HUGE_CHUNK_STRUCT;

// sizeof(_msExcInfo) = 8
struct _msExcInfo
{
    /* 0x0/0 */ unsigned int Id;
    /* 0x4/4 */ void *Proc;
};
// sizeof(_msExcExt) = 20
struct _msExcExt
{
    /* 0x0/0 */ unsigned int _unk[3];
    /* 0xC/12 */ unsigned int Count;
    /* 0x10/16 */ void *RttiBlkPtr;
};
// sizeof(_msRttiDscr) = 16
struct _msRttiDscr
{
    /* 0x0/0 */ unsigned int _unk;
    /* 0x4/4 */ void *RttiPtr;
    /* 0x8/8 */ unsigned int spoff;
    /* 0xC/12 */ void *Dtr;
};
// sizeof(struct BILLING_SERVER_STRUCT) = 24
struct BILLING_SERVER_STRUCT
{
    /* 0x0/0 */ struct PACKET_ATTACHMENT *MainServerStructure;
    /* 0x4/4 */ struct CONNECTION *connection;
    /* 0x8/8 */ unsigned int f8;
    /* 0xC/12 */ unsigned int HandleBillerPacketFunctionAddress;
    /* 0x10/16 */ unsigned int GetTickCountValue;
    /* 0x14/20 */ unsigned int ZeroValue;
};
// sizeof(BMP_FILE_STRUCT) = 272
struct BMP_FILE_STRUCT
{
    /* 0x0/0 */ char FileName[256];
    /* 0x100/256 */ unsigned int BMPFileSizeOffset;
    /* 0x104/260 */ unsigned int field_104;
    /* 0x108/264 */ int *BMPPointer;
    /* 0x10C/268 */ unsigned int TotalMapTiles;
};
// sizeof(HUGE_CHUNK_STRUCT) = 20
struct HUGE_CHUNK_STRUCT
{
    /* 0x0/0 */ unsigned char *PacketBuffer;
    /* 0x4/4 */ unsigned int TotalLength;
    /* 0x8/8 */ unsigned int SentLength;
    /* 0xC/12 */ unsigned int IsMemoryAllocated;
    /* 0x10/16 */ unsigned int field_10;
};
// sizeof(struct SOCCER_BALL) = 15
struct SOCCER_BALL
{
    /* 0x0/0 */ unsigned char PowerBallId;
    /* 0x1/1 */ unsigned short XPixels;
    /* 0x3/3 */ unsigned short YPixels;
    /* 0x5/5 */ unsigned short XVelocity;
    /* 0x7/7 */ unsigned short YVelocity;
    /* 0x9/9 */ unsigned short PlayerId;
    /* 0xB/11 */ unsigned int StartTimeDelay;
};
// sizeof(FLAG) = 16
struct FLAG
{
    /* 0x0/0 */ unsigned int XTile;
    /* 0x4/4 */ unsigned int YTile;
    /* 0x8/8 */ unsigned int Team;
    /* 0xA/10 */ unsigned int CarrierPlayerId;
    /* 0xC/12 */ unsigned int OwnerFreq;
};
// sizeof(SCORE) = 18
struct SCORE
{
    /* 0x0/0 */ unsigned int UserId;
    /* 0x4/4 */ unsigned short Wins;
    /* 0x6/6 */ unsigned short Deaths;
    /* 0x8/8 */ unsigned short Goals;
    /* 0xA/10 */ unsigned int KillPoints;
    /* 0xE/14 */ unsigned int FlagPoints;
};
// sizeof(BRICK) = 16
struct BRICK
{
    /* 0x0/0 */ unsigned short X1Tile;
    /* 0x2/2 */ unsigned short Y1Tile;
    /* 0x4/4 */ unsigned short X2Tile;
    /* 0x6/6 */ unsigned short Y2Tile;
    /* 0x8/8 */ unsigned short Team;
    /* 0xA/10 */ unsigned short BrickId;
    /* 0xC/12 */ unsigned int BrickTimeStamp;
};
// sizeof(MAP_TILE) = 16
struct MAP_TILE
{
    /* 0x0/0 */ unsigned int XCoordinate;
    /* 0x4/4 */ unsigned int YCoordinate;
    /* 0x8/8 */ unsigned int field_8;
    /* 0xC/12 */ unsigned int field_C;
};
// sizeof(SECURITY_PACKET_STRUCT) = 40
struct SECURITY_PACKET_STRUCT
{
    /* 0x0/0 */ unsigned char SecurityPacketCache;
    /* 0x1/1 */ unsigned int WeaponCount;
    /* 0x5/5 */ unsigned int SettingsChecksum;
    /* 0x9/9 */ unsigned int SubspaceEXEChecksum;
    /* 0xD/13 */ unsigned int MapLVLChecksum;
    /* 0x11/17 */ unsigned int S2CCurrentTotalSlow;
    /* 0x15/21 */ unsigned int S2CCurrentTotalFast;
    /* 0x19/25 */ unsigned short S2CCurrentSlow;
    /* 0x1B/27 */ unsigned short S2CCurrentFast;
    /* 0x1D/29 */ unsigned short S2CAverageLatency;
    /* 0x1F/31 */ unsigned short CurrentPing;
    /* 0x21/33 */ unsigned short AveragePing;
    /* 0x23/35 */ unsigned short LowPing;
    /* 0x25/37 */ unsigned short HighPing;
    /* 0x27/39 */ unsigned char SlowFrameDetectedSomething;
};
// sizeof(PRIZE_PACKET_STRUCT) = 11
struct PRIZE_PACKET_STRUCT
{
    /* 0x0/0 */ unsigned char PrizePacketId;
    /* 0x1/1 */ unsigned int PrizeTimeStamp;
    /* 0x5/5 */ unsigned short PrizeXTile;
    /* 0x7/7 */ unsigned short PrizeYTile;
    /* 0x9/9 */ unsigned short PrizeId;
};
// sizeof(PLAYER_DATA_BILLER_PACKET_STRUCT) = 172
struct PLAYER_DATA_BILLER_PACKET_STRUCT
{
    /* 0x0/0 */ unsigned char Name[24];
    /* 0x18/24 */ unsigned char Squad[24];
    /* 0x30/48 */ unsigned char BannerData[96];
    /* 0x90/144 */ unsigned int UsageTotalSeconds;
    /* 0x94/148 */ unsigned short AccountCreationYear;
    /* 0x96/150 */ unsigned short AccountCreationMonth;
    /* 0x98/152 */ unsigned short AccountCreationDay;
    /* 0x9A/154 */ unsigned short AccountCreationHour;
    /* 0x9C/156 */ unsigned short AccountCreationMinute;
    /* 0x9E/158 */ unsigned short AccountCreationSecond;
    /* 0xA0/160 */ unsigned int Extra1;
    /* 0xA4/164 */ signed int UserId;
    /* 0xA8/168 */ unsigned int Extra2;
};
// sizeof(struct CONNECTION) = 3190
struct CONNECTION
{
    /* 0x0/0 */ struct in_addr RemoteIP;
    /* 0x4/4 */ unsigned short RemotePort;
    /* 0x6/6 */ unsigned int dword6;
    /* 0xA/10 */ unsigned int dwordA;
    /* 0xE/14 */ unsigned int SyncResponseLocalTimeStamp;
    /* 0x12/18 */ unsigned int dword12;
    /* 0x16/22 */ unsigned int dword16;
    /* 0x1A/26 */ unsigned int TotalSyncResponses;
    /* 0x1E/30 */ unsigned int dword1E;
    /* 0x22/34 */ unsigned int LowestSyncResponseDelay;
    /* 0x26/38 */ unsigned int HighestSyncResponseDelay;
    /* 0x2A/42 */ struct PACKET_ATTACHMENT *MyPacketAttachment;
    /* 0x2E/46 */ unsigned int PlayerId;
    /* 0x32/50 */ unsigned int state;
    /* 0x36/54 */ unsigned int KeepAliveDelayTimer;
    /* 0x3A/58 */ unsigned int MenuKickOutDelayTimer;
    /* 0x3E/62 */ int ServerKey;
    /* 0x42/66 */ unsigned int ProtocolVersion;
    /* 0x46/70 */ unsigned char SSEncryptionTable[520];
    /* 0x24E/590 */ unsigned int SmallChunkPacketSize;
    /* 0x252/594 */ char *SmallChunkPacketBuffer;
    /* 0x256/598 */ unsigned int CurrentReliableMessageACKID;
    /* 0x25A/602 */ unsigned int HighestRecievedReliableMessageACKID;
    /* 0x25E/606 */ unsigned int ReliablePacketsCurrent;
    /* 0x262/610 */ unsigned int ReliablePacketsPending;
    /* 0x266/614 */ unsigned int MaxOutPacketSizeQueue;
    /* 0x26A/618 */ unsigned char *ReliableInPackets[256];	//256 pointers to byte buffers, RECV
    /* 0x66A/1642 */ unsigned char *ReliableOutPackets[256]; //256 pointers to byte buffers, SEND
    /* 0xA6A/2666 */ unsigned int TotalPacketsSent;
    /* 0xA6E/2670 */ unsigned int TotalPacketsRecieved;
    /* 0xA72/2674 */ unsigned int TotalPacketsClientRecieved;
    /* 0xA76/2678 */ unsigned int TotalPacketsClientSent;
    /* 0xA7A/2682 */ unsigned int ServerToYou;
    /* 0xA7E/2686 */ unsigned int YouToServer;
    /* 0xA82/2690 */ unsigned int RatioBytesSent;
    /* 0xA86/2694 */ unsigned int TotalBytesSent;
    /* 0xA8A/2698 */ unsigned int LastTotalBytesSent;
    /* 0xA8E/2702 */ unsigned int LastRatioSendTime;
    /* 0xA92/2706 */ unsigned char ClusterPacket[384];
    /* 0xC12/3090 */ unsigned int ClusterPacketLength;
    /* 0xC16/3094 */ struct HUGE_CHUNK_STRUCT HugeChunk[4];
    /* 0xC66/3174 */ unsigned int TotalHugeChunks;
    /* 0xC6A/3178 */ char *HugeChunkRecievePacket;
    /* 0xC6E/3182 */ unsigned int HugeChunkRecieveTotalSize;
    /* 0xC72/3186 */ unsigned int HugeChunkRecievedSize;
};
// sizeof(struct KICK) = 12
struct KICK
{
    /* 0x0/0 */ unsigned int MachineId;
    /* 0x4/4 */ unsigned int KickStartTime;
    /* 0x8/8 */ unsigned int KickDelayMilliseconds;
};
// sizeof(struct TEMPLATE_SSS) = 338
struct TEMPLATE_SSS
{
    /* 0x0/0 */ char SomeString32[32];
    /* 0x20/32 */ char KeyName[40];
    /* 0x48/72 */ unsigned int someInteger;
    /* 0x4C/76 */ unsigned int someInteger2;
    /* 0x50/80 */ char SomeString256[256];
    /* 0x150/336 */ unsigned char SomeChar1a;
    /* 0x151/337 */ unsigned char SomeChar1b;
};
// sizeof(struct SETTING_CATEGORY) = 38
struct SETTING_CATEGORY
{
    /* 0x0/0 */ char CategoryName[30];
    /* 0x1E/30 */ unsigned int SettingId;
    /* 0x22/34 */ unsigned int SettingsInCategory;
};
// sizeof(struct SETTING) = 140
struct SETTING
{
    /* 0x0/0 */ unsigned int SettingId;
    /* 0x4/4 */ char SettingName[36];
    /* 0x28/40 */ char SettingValue[100];
};
// sizeof(struct struc_2) = 177996
struct struc_2
{
    /* 0x0/0 */ struct SETTING_CATEGORY SettingCategory[256];
    /* 0x2600/9728 */ unsigned int TotalSettingsCategoryCount;
    /* 0x2604/9732 */ struct SETTING Setting[1200];
    /* 0x2B644/177732 */ unsigned int TotalSettingsCount;
    /* 0x2B648/177736 */ unsigned int ShouldCreateFile;
    /* 0x2B64C/177740 */ char Filename[256];
};
// sizeof(CHAT) = 364
struct CHAT
{
    /* 0x0/0 */ char ChatMessage[300];
    /* 0x12C/300 */ char PlayerName[32];
    /* 0x14C/332 */ unsigned char field_14C[32];
};
// sizeof(TEXT_FILE_STRUCT) = 276
struct TEXT_FILE_STRUCT
{
    /* 0x0/0 */ char FileName[256];
    /* 0x100/256 */ char **Pointer;
    /* 0x104/260 */ unsigned int Counter;
    /* 0x108/264 */ unsigned int MakeUpperCase;
    /* 0x10C/268 */ unsigned int AddAll; //Crap removed
    /* 0x110/272 */ unsigned int LastFileEditTime;
};
// sizeof(struct SERVER_BIG_ARRAY) = 4036
struct SERVER_BIG_ARRAY
{
    /* 0x0/0 */ char *Subspace131EXEBytes;
    /* 0x4/4 */ char *Subspace133EXEBytes;
    /* 0x8/8 */ char *Subspace132EXEBytes;
    /* 0xC/12 */ unsigned long Subspace131FileSize; //changed to 8 bytes to remove warning
    /* 0x10/16 */ unsigned long Subspace133FileSize; //changed to 8 bytes to remove warning
    /* 0x14/20 */ unsigned long Subspace132FileSize; //changed to 8 bytes to remove warning
    /* 0x18/24 */ int SubspaceEXEChecksum;
    /* 0x1C/28 */ unsigned char ScrtyData[4000];
    /* 0xFBC/4028 */ struct TEXT_FILE_STRUCT *IPBlockText;
    /* 0xFC0/4032 */ struct TEXT_FILE_STRUCT *IPAllowText;
};
// sizeof(PACKET) = 14
struct PACKET
{
    /* 0x0/0 */ unsigned char byte0;
    /* 0x1/1 */ unsigned char EncryptionCommand;
    /* 0x2/2 */ unsigned int EncryptSeedOrSizeDWORD;
    /* 0x6/6 */ unsigned char char6;
    /* 0x7/7 */ unsigned char f7[3];
    /* 0xA/10 */ unsigned int dwordA;
};
// sizeof(PACKET_ADVERTISEMENT) = 8
struct PACKET_ADVERTISEMENT
{
    /* 0x0/0 */ unsigned int TotalPacketLength;
    /* 0x4/4 */ char *PacketBuffer;
};
// sizeof(PACKET_ATTACHMENT_HISTORY) = 540
struct PACKET_ATTACHMENT_HISTORY
{
    /* 0x0/0 */ unsigned char PacketBuffer[512];
    /* 0x200/512 */ unsigned char gap_200[20];
    /* 0x214/532 */ struct in_addr RemoteIP;
    /* 0x218/536 */ unsigned short PacketLength;
    /* 0x21A/538 */ unsigned short RemotePort;
};
// sizeof(PACKET_ATTACHMENT_SUB_STRUCT) = 140
struct PACKET_ATTACHMENT_SUB_STRUCT
{
    /* 0x0/0 */ unsigned char SmallPacketBuffer[128];
    /* 0x80/128 */ char *LargePacketBuffer;
    /* 0x84/132 */ unsigned int PacketLength;
    /* 0x88/136 */ struct CONNECTION *connection;
};
// sizeof(PACKET_ATTACHMENT) = 35932
struct PACKET_ATTACHMENT
{
    /* 0x0/0 */ unsigned int NewConnectionRequestAddress;
    /* 0x4/4 */ unsigned int PlayerHandleGamePacketWrapperAddress;
    /* 0x8/8 */ unsigned short Port;
    /* 0xA/10 */ unsigned char fA[2];
    /* 0xC/12 */ unsigned int MaxConnections;
    /* 0x10/16 */ unsigned int TotalPacketClustersCalls;
    /* 0x14/20 */ struct CONNECTION *FreshConnections;
    /* 0x18/24 */ unsigned int Socket;
    /* 0x1C/28 */ unsigned int TickCountDividedBy10Two;
    /* 0x20/32 */ unsigned int EncryptMode;
    /* 0x24/36 */ unsigned int dword24;
    /* 0x28/40 */ struct PACKET_ATTACHMENT_HISTORY *recievePacketBuffer;
    /* 0x2C/44 */ unsigned int PacketHistoryMax;
    /* 0x30/48 */ unsigned int PacketCurrentHistory;
    /* 0x34/52 */ struct PACKET_ATTACHMENT_SUB_STRUCT field_34[256];
    /* 0x8C34/35892 */ unsigned int dword8C34;
    /* 0x8C38/35896 */ unsigned int SomeCounter;
    /* 0x8C3C/35900 */ unsigned int TotalPacketSendLength;
    /* 0x8C40/35904 */ unsigned int TotalPacketSendCalls;
    /* 0x8C44/35908 */ unsigned int TotalPacketRecvLength;
    /* 0x8C48/35912 */ unsigned int TotalPacketRecvCalls;
    /* 0x8C4C/35916 */ unsigned int TickCountDividedBy10;
    /* 0x8C50/35920 */ unsigned int CommsTransportBufferSizeLimited;
    /* 0x8C54/35924 */ struct CONNECTION **Connections;
    /* 0x8C58/35928 */ unsigned int TotalConnections;
};
// sizeof(_msExcept) = 32
struct _msExcept
{
    /* 0x0/0 */ unsigned int Magic;
    /* 0x4/4 */ unsigned int Count;
    /* 0x8/8 */ void *InfoPtr;
    /* 0xC/12 */ unsigned int CountDtr;
    /* 0x10/16 */ void *DtrPtr;
    /* 0x14/20 */ unsigned int _unk[3];
    /* 0x20/32 */ struct _msExcInfo Info;
};
// sizeof(SHIP_SETTINGS) = 144
struct SHIP_SETTINGS
{
    /* 0x0/0 */ unsigned short SuperTime;
    /* 0x2/2 */ unsigned short UNKNOWN0;
    /* 0x4/4 */ unsigned short ShieldsTime;
    /* 0x6/6 */ unsigned short UNKNOWN1;
    /* 0x8/8 */ unsigned short Gravity;
    /* 0xA/10 */ unsigned short GravityTopSpeed;
    /* 0xC/12 */ unsigned short BulletFireEnergy;
    /* 0xE/14 */ unsigned short MultiFireEnergy;
    /* 0x10/16 */ unsigned short BombFireEnergy;
    /* 0x12/18 */ unsigned short BombFireEnergyUpgrade;
    /* 0x14/20 */ unsigned short MineFireEnergy;
    /* 0x16/22 */ unsigned short MineFireEnergyUpgrade;
    /* 0x18/24 */ unsigned short BulletSpeed;
    /* 0x1A/26 */ unsigned short BombSpeed;
    /* 0x1C/28 */ unsigned short MultiFireAngleBits1;
    /* 0x1E/30 */ unsigned short MultiFireAngleBits2;
    /* 0x20/32 */ unsigned short CloakEnergy;
    /* 0x22/34 */ unsigned short StealthEnergy;
    /* 0x24/36 */ unsigned short AntiWarpEnergy;
    /* 0x26/38 */ unsigned short XRadarEnergy;
    /* 0x28/40 */ unsigned short MaximumRotation;
    /* 0x2A/42 */ unsigned short MaximumThrust;
    /* 0x2C/44 */ unsigned short MaxmimumSpeed;
    /* 0x2E/46 */ unsigned short MaximumRecharge;
    /* 0x30/48 */ unsigned short MaximumEnergy;
    /* 0x32/50 */ unsigned short InitalRotation;
    /* 0x34/52 */ unsigned short InitalThrust;
    /* 0x36/54 */ unsigned short InitalSpeed;
    /* 0x38/56 */ unsigned short InitialRecharge;
    /* 0x3A/58 */ unsigned short InitialEnergy;
    /* 0x3C/60 */ unsigned short UpgradeRotation;
    /* 0x3E/62 */ unsigned short UpgradeThrust;
    /* 0x40/64 */ unsigned short UpgradeSpeed;
    /* 0x42/66 */ unsigned short UpgradeRecharge;
    /* 0x44/68 */ unsigned short UpgradeEnergy;
    /* 0x46/70 */ unsigned short AfterburnerEnergy;
    /* 0x48/72 */ unsigned short BombThrust;
    /* 0x4A/74 */ unsigned short BurstSpeed;
    /* 0x4C/76 */ unsigned short TurretThrustPenalty;
    /* 0x4E/78 */ unsigned short TurretSpeedPenalty;
    /* 0x50/80 */ unsigned short BulletFireDelay;
    /* 0x52/82 */ unsigned short MultiFireDelay;
    /* 0x54/84 */ unsigned short BombFireDelay;
    /* 0x56/86 */ unsigned short LandmineFireDelay;
    /* 0x58/88 */ unsigned short RocketTime;
    /* 0x5A/90 */ unsigned short InitialBounty;
    /* 0x5C/92 */ unsigned short DamageFactor;
    /* 0x5E/94 */ unsigned short PrizeShareLimit;
    /* 0x60/96 */ unsigned short AttachBounty;
    /* 0x62/98 */ unsigned short SoccerThrowTime;
    /* 0x64/100 */ unsigned short SoccerBallFriction;
    /* 0x66/102 */ unsigned short SoccerBallProximity;
    /* 0x68/104 */ unsigned short SoccerBallSpeed;
    /* 0x6A/106 */ unsigned char TurretLimit;
    /* 0x6B/107 */ unsigned char BurstShrapnel;
    /* 0x6C/108 */ unsigned char MaxMines;
    /* 0x6D/109 */ unsigned char RepelMax;
    /* 0x6E/110 */ unsigned char BurstMax;
    /* 0x6F/111 */ unsigned char DecoyMax;
    /* 0x70/112 */ unsigned char ThorMax;
    /* 0x71/113 */ unsigned char BrickMax;
    /* 0x72/114 */ unsigned char RocketMax;
    /* 0x73/115 */ unsigned char PortalMax;
    /* 0x74/116 */ unsigned char InitialRepel;
    /* 0x75/117 */ unsigned char InitialBurst;
    /* 0x76/118 */ unsigned char InitialBrick;
    /* 0x77/119 */ unsigned char InitialRocket;
    /* 0x78/120 */ unsigned char InitialThor;
    /* 0x79/121 */ unsigned char InitialDecoy;
    /* 0x7A/122 */ unsigned char InitialPortal;
    /* 0x7B/123 */ unsigned char BombBounceCount;
    /* 0x7C/124 */ unsigned int LotsOfBitFields;
    /* 0x80/128 */ unsigned char UNKNOWN3_1;
    /* 0x81/129 */ unsigned char UNKNOWN3_2;
    /* 0x82/130 */ unsigned char UNKNOWN3_3;
    /* 0x83/131 */ unsigned char UNKNOWN3_4;
    /* 0x84/132 */ unsigned char UNKNOWN3_5;
    /* 0x85/133 */ unsigned char UNKNOWN3_6;
    /* 0x86/134 */ unsigned char UNKNOWN3_7;
    /* 0x87/135 */ unsigned char UNKNOWN3_8;
    /* 0x88/136 */ unsigned char UNKNOWN3_9;
    /* 0x89/137 */ unsigned char UNKNOWN3_10;
    /* 0x8A/138 */ unsigned char UNKNOWN3_11;
    /* 0x8B/139 */ unsigned char UNKNOWN3_12;
    /* 0x8C/140 */ unsigned char UNKNOWN3_13;
    /* 0x8D/141 */ unsigned char UNKNOWN3_14;
    /* 0x8E/142 */ unsigned char UNKNOWN3_15;
    /* 0x8F/143 */ unsigned char UNKNOWN3_16;
};
// sizeof(ARENA_BUY_SETTINGS) = 24
struct ARENA_BUY_SETTINGS
{
    /* 0x0/0 */ char ItemName[16];
    /* 0x10/16 */ unsigned int ItemPrice;
    /* 0x14/20 */ unsigned int ItemId;
};
// sizeof(struct ARENA_SETTINGS) = 1428
struct ARENA_SETTINGS
{
    /* 0x0/0 */ unsigned int VersionAndManyBitFields;
    /* 0x4/4 */ struct SHIP_SETTINGS ShipSettings[8];
    /* 0x484/1156 */ unsigned int BulletDamageLevel;
    /* 0x488/1160 */ unsigned int BombDamageLevel;
    /* 0x48C/1164 */ unsigned int BulletAliveTime;
    /* 0x490/1168 */ unsigned int BombAliveTime;
    /* 0x494/1172 */ unsigned int DecoyAliveTime;
    /* 0x498/1176 */ unsigned int SafetyLimit;
    /* 0x49C/1180 */ unsigned int FrequencyShift;
    /* 0x4A0/1184 */ unsigned int MaxFrequency;
    /* 0x4A4/1188 */ unsigned int RepelSpeed;
    /* 0x4A8/1192 */ unsigned int MineAliveTime;
    /* 0x4AC/1196 */ unsigned int BurstDamageLevel;
    /* 0x4B0/1200 */ unsigned int BulletDamageUpgrade;
    /* 0x4B4/1204 */ unsigned int FlagDropDelay;
    /* 0x4B8/1208 */ unsigned int EnterGameFlaggingDelay;
    /* 0x4BC/1212 */ unsigned int RocketThrust;
    /* 0x4C0/1216 */ unsigned int RocketSpeed;
    /* 0x4C4/1220 */ unsigned int InactiveShrapnelDamage;
    /* 0x4C8/1224 */ unsigned int WormholeSwitchTime;
    /* 0x4CC/1228 */ unsigned int ActivateAppShutdownTime;
    /* 0x4D0/1232 */ unsigned int ShrapnelSpeed;
    /* 0x4D4/1236 */ unsigned char UNKNOWN0[16];
    /* 0x4E4/1252 */ unsigned short SendRoutePercent;
    /* 0x4E6/1254 */ unsigned short BombExplodeDelay;
    /* 0x4E8/1256 */ unsigned short SendPositionDelay;
    /* 0x4EA/1258 */ unsigned short BombExplodePixels;
    /* 0x4EC/1260 */ unsigned short DeathPrizeTime;
    /* 0x4EE/1262 */ unsigned short JitterTime;
    /* 0x4F0/1264 */ unsigned short EnterDelay;
    /* 0x4F2/1266 */ unsigned short EngineShutdownTime;
    /* 0x4F4/1268 */ unsigned short ProximityDistance;
    /* 0x4F6/1270 */ unsigned short BountyIncreaseForKill;
    /* 0x4F8/1272 */ unsigned short BounceFactor;
    /* 0x4FA/1274 */ unsigned short MapZoomFactor;
    /* 0x4FC/1276 */ unsigned short MaxBonus;
    /* 0x4FE/1278 */ unsigned short MaxPenalty;
    /* 0x500/1280 */ unsigned short RewardBase;
    /* 0x502/1282 */ unsigned short RepelTime;
    /* 0x504/1284 */ unsigned short RepelDistance;
    /* 0x506/1286 */ unsigned short HelpTickerDelay;
    /* 0x508/1288 */ unsigned short FlaggerOnRadar;
    /* 0x50A/1290 */ unsigned short FlaggerKillMultiplier;
    /* 0x50C/1292 */ unsigned short PrizeFactor;
    /* 0x50E/1294 */ unsigned short PrizeDelay;
    /* 0x510/1296 */ unsigned short PrizeMinimumVirtual;
    /* 0x512/1298 */ unsigned short PrizeUpgradeVirtual;
    /* 0x514/1300 */ unsigned short PrizeMaxExist;
    /* 0x516/1302 */ unsigned short PrizeMinExist;
    /* 0x518/1304 */ unsigned short PrizeNegativeFactor;
    /* 0x51A/1306 */ unsigned short DoorDelay;
    /* 0x51C/1308 */ unsigned short AntiwarpPixels;
    /* 0x51E/1310 */ unsigned short DoorMode;
    /* 0x520/1312 */ unsigned short FlagBlankDelay;
    /* 0x522/1314 */ unsigned short NoDataFlagDropDelay;
    /* 0x524/1316 */ unsigned short MultiPrizeCount;
    /* 0x526/1318 */ unsigned short BrickTime;
    /* 0x528/1320 */ unsigned short WarpRadiusLimit;
    /* 0x52A/1322 */ unsigned short EBombShutdownTime;
    /* 0x52C/1324 */ unsigned short EBombDamagePercent;
    /* 0x52E/1326 */ unsigned short RadarNeutralSize;
    /* 0x530/1328 */ unsigned short WarpPointDelay;
    /* 0x532/1330 */ unsigned short NearDeathLevel;
    /* 0x534/1332 */ unsigned short BBombDamagePercent;
    /* 0x536/1334 */ unsigned short ShrapnelDamagePercent;
    /* 0x538/1336 */ unsigned short ClientSlowPacketTime;
    /* 0x53A/1338 */ unsigned short FlagDropResetReward;
    /* 0x53C/1340 */ unsigned short FlaggerFireCostPercent;
    /* 0x53E/1342 */ unsigned short FlaggerDamagePercent;
    /* 0x540/1344 */ unsigned short FlaggerBombFireDelay;
    /* 0x542/1346 */ unsigned short SoccerPassDelay;
    /* 0x544/1348 */ unsigned short SoccerBallBlankDelay;
    /* 0x546/1350 */ unsigned short S2CNoDataKickoutDelay;
    /* 0x548/1352 */ unsigned short FlaggerThrustAdjustment;
    /* 0x54A/1354 */ unsigned short FlaggerSpeedAdjustment;
    /* 0x54C/1356 */ unsigned short ClientSlowPacketSampleSize;
    /* 0x54E/1358 */ unsigned char UNKNOWN1[10];
    /* 0x558/1368 */ unsigned char RandomShrapnel;
    /* 0x559/1369 */ unsigned char SoccerBallBounce;
    /* 0x55A/1370 */ unsigned char SoccerAllowBombs;
    /* 0x55B/1371 */ unsigned char SoccerAllowGuns;
    /* 0x55C/1372 */ unsigned char SoccerMode;
    /* 0x55D/1373 */ unsigned char MaxPerTeam;
    /* 0x55E/1374 */ unsigned char MaxPerPrivateTeam;
    /* 0x55F/1375 */ unsigned char TeamMaxMines;
    /* 0x560/1376 */ unsigned char WormholeGravityBombs;
    /* 0x561/1377 */ unsigned char BombSafety;
    /* 0x562/1378 */ unsigned char MessageReliable;
    /* 0x563/1379 */ unsigned char TakePrizeReliable;
    /* 0x564/1380 */ unsigned char AllowAudioMessages;
    /* 0x565/1381 */ unsigned char PrizeHideCount;
    /* 0x566/1382 */ unsigned char ExtraPositionData;
    /* 0x567/1383 */ unsigned char SlowFrameCheck;
    /* 0x568/1384 */ unsigned char CarryFlags;
    /* 0x569/1385 */ unsigned char AllowSavedShip;
    /* 0x56A/1386 */ unsigned char RadarMode;
    /* 0x56B/1387 */ unsigned char VictoryMusic;
    /* 0x56C/1388 */ unsigned char FlaggerGunUpgrade;
    /* 0x56D/1389 */ unsigned char FlaggerBombUpgrade;
    /* 0x56E/1390 */ unsigned char SoccerUseFlagger;
    /* 0x56F/1391 */ unsigned char SoccerBallLocation;
    /* 0x570/1392 */ unsigned char SomeUnknownStuffToo[7];
    /* 0x577/1399 */ unsigned char PrizeAddressAnchor;
    /* 0x578/1400 */ unsigned char PrizeWeightQuickCharge;
    /* 0x579/1401 */ unsigned char PrizeWeightEnergy;
    /* 0x57A/1402 */ unsigned char PrizeWeightRotation;
    /* 0x57B/1403 */ unsigned char PrizeWeightStealth;
    /* 0x57C/1404 */ unsigned char PrizeWeightCloak;
    /* 0x57D/1405 */ unsigned char PrizeWeightXRadar;
    /* 0x57E/1406 */ unsigned char PrizeWeightWarp;
    /* 0x57F/1407 */ unsigned char PrizeWeightGun;
    /* 0x580/1408 */ unsigned char PrizeWeightBomb;
    /* 0x581/1409 */ unsigned char PrizeWeightBouncingBullets;
    /* 0x582/1410 */ unsigned char PrizeWeightThruster;
    /* 0x583/1411 */ unsigned char PrizeWeightTopSpeed;
    /* 0x584/1412 */ unsigned char PrizeWeightRecharge;
    /* 0x585/1413 */ unsigned char PrizeWeightGlue;
    /* 0x586/1414 */ unsigned char PrizeWeightMultiFire;
    /* 0x587/1415 */ unsigned char PrizeWeightProximity;
    /* 0x588/1416 */ unsigned char PrizeWeightAllWeapons;
    /* 0x589/1417 */ unsigned char PrizeWeightShields;
    /* 0x58A/1418 */ unsigned char PrizeWeightShrapnel;
    /* 0x58B/1419 */ unsigned char PrizeWeightAntiWarp;
    /* 0x58C/1420 */ unsigned char PrizeWeightRepel;
    /* 0x58D/1421 */ unsigned char PrizeWeightBurst;
    /* 0x58E/1422 */ unsigned char PrizeWeightDecoy;
    /* 0x58F/1423 */ unsigned char PrizeWeightThor;
    /* 0x590/1424 */ unsigned char PrizeWeightMultiPrize;
    /* 0x591/1425 */ unsigned char PrizeWeightBrick;
    /* 0x592/1426 */ unsigned char PrizeWeightRocket;
    /* 0x593/1427 */ unsigned char PrizeWeightPortal;
};
// sizeof(struct SERVERSIDE_ARENA_SETTINGS) = 1208
struct SERVERSIDE_ARENA_SETTINGS
{
    /* 0x0/0 */ unsigned int OwnerUserId;
    /* 0x4/4 */ unsigned int CustomSaveStatsTime;
    /* 0x8/8 */ unsigned int MiscBannerPoints;
    /* 0xC/12 */ unsigned int FlagResetDelay;
    /* 0x10/16 */ unsigned int TerritoryRewardDelay;
    /* 0x14/20 */ unsigned int TerritoryRewardBaseFlags;
    /* 0x18/24 */ unsigned int TerritoryRewardMinimumPlayers;
    /* 0x1C/28 */ unsigned int TerritoryRewardPoints;
    /* 0x20/32 */ unsigned int PeriodicRewardDelay;
    /* 0x24/36 */ unsigned int PeriodicRewardMinimumPlayers;
    /* 0x28/40 */ unsigned int PeriodicRewardPoints;
    /* 0x2C/44 */ unsigned int KillDebtKills;
    /* 0x30/48 */ unsigned int KillPointsPerFlag;
    /* 0x34/52 */ unsigned int KillPointsMinimumBounty;
    /* 0x38/56 */ unsigned int KillNoRewardKillDelay;
    /* 0x3C/60 */ unsigned int KillBountyRewardPercent;
    /* 0x40/64 */ unsigned int KillFixedKillReward;
    /* 0x44/68 */ unsigned int PacketLossC2SKickOutPercent;
    /* 0x48/72 */ unsigned int PacketLossC2SNegativeKickOutPercent;
    /* 0x4C/76 */ unsigned int PacketLossS2CKickOutPercent;
    /* 0x50/80 */ unsigned int PacketLossSpectatorPercentAdjust;
    /* 0x54/84 */ unsigned int TeamDesiredTeams;
    /* 0x58/88 */ unsigned int RandomFlags;
    /* 0x5C/92 */ unsigned int MaxFlags;
    /* 0x60/96 */ unsigned int FlagReward;
    /* 0x64/100 */ unsigned int FlagRewardMode;
    /* 0x68/104 */ unsigned int FlagFriendlyTransfer;
    /* 0x6C/108 */ unsigned int TeamSpectatorFrequency;
    /* 0x70/112 */ unsigned int MiscMaxLossesToPlay;
    /* 0x74/116 */ unsigned int MiscSpectatorQuiet;
    /* 0x78/120 */ unsigned int MessageBongAllowed;
    /* 0x7C/124 */ unsigned int FlagMode;
    /* 0x80/128 */ unsigned int KillJackpotBountyPercent;
    /* 0x84/132 */ unsigned int MiscTimedGame;
    /* 0x88/136 */ unsigned int FlagTerritoryRadius;
    /* 0x8C/140 */ unsigned int FlagTerritoryRadiusCentroid;
    /* 0x90/144 */ unsigned int BrickSpan;
    /* 0x94/148 */ unsigned int CostPurchaseAnytime;
    /* 0x98/152 */ unsigned int MiscFrequencyShipTypes;
    /* 0x9C/156 */ unsigned int TeamForceEvenTeams;
    /* 0xA0/160 */ unsigned int MessageQuickMessageLimit;
    /* 0xA4/164 */ unsigned int MessageReliable;
    /* 0xA8/168 */ unsigned int MessageTeamReliable;
    /* 0xAC/172 */ unsigned int MessageDistance;
    /* 0xB0/176 */ unsigned int SecurityS2CKickOutPercentWeapons;
    /* 0xB4/180 */ unsigned int dwordB4;
    /* 0xB8/184 */ unsigned int SecuritySuicideLimit;
    /* 0xBC/188 */ unsigned int SecurityMaxShipTypeSwitchCount;
    /* 0xC0/192 */ unsigned int SecurityPacketModificationMax;
    /* 0xC4/196 */ unsigned int SecurityMaxDeathWithoutFiring;
    /* 0xC8/200 */ unsigned int LatencyKickOutDelay;
    /* 0xCC/204 */ unsigned int LatencyNoFlagDelay;
    /* 0xD0/208 */ unsigned int LatencyNoFlagPenalty;
    /* 0xD4/212 */ unsigned int LatencySlowPacketKickoutPercent;
    /* 0xD8/216 */ unsigned int LatencyClientSlowPacketKickoutPercent;
    /* 0xDC/220 */ unsigned char fDC[4];
    /* 0xE0/224 */ unsigned int LatencySlowPacketTime;
    /* 0xE4/228 */ unsigned int LatencySlowPacketSampleSize;
    /* 0xE8/232 */ unsigned int LatencyMaxLatencyForWeapons;
    /* 0xEC/236 */ unsigned int LatencyMaxLatencyForPrizes;
    /* 0xF0/240 */ unsigned int LatencyMaxLatencyForKickOut;
    /* 0xF4/244 */ unsigned int LatencyKickOutTime;
    /* 0xF8/248 */ unsigned int MiscMaxPlaying;
    /* 0xFC/252 */ unsigned int LatencyCutbackWatermark;
    /* 0x100/256 */ unsigned int PacketLossDisableWeapons;
    /* 0x104/260 */ unsigned int PrizeS2CTakePrizeReliable;
    /* 0x108/264 */ unsigned int RoutingRadarFavor;
    /* 0x10C/268 */ unsigned int RoutingCloseEnoughBulletAdjust;
    /* 0x110/272 */ unsigned int RoutingCloseEnoughBombAdjust;
    /* 0x114/276 */ unsigned int RoutingDeathDistance;
    /* 0x118/280 */ unsigned int RoutingDoubleSendPercent;
    /* 0x11C/284 */ unsigned int RoutingWallResendCount;
    /* 0x120/288 */ unsigned int KingDeathCount;
    /* 0x124/292 */ unsigned int KingExpireTime;
    /* 0x128/296 */ unsigned int KingNonCrownAdjustTime;
    /* 0x12C/300 */ unsigned int KingNonCrownMinimumBounty;
    /* 0x130/304 */ unsigned int KingRewardFactor;
    /* 0x134/308 */ unsigned int KingCrownRecoverKills;
    /* 0x138/312 */ unsigned int SoccerBallCount;
    /* 0x13C/316 */ unsigned int SoccerSendTime;
    /* 0x140/320 */ unsigned int SoccerReward;
    /* 0x144/324 */ unsigned int SoccerCapturePoints;
    /* 0x148/328 */ unsigned int SoccerCatchPoints;
    /* 0x14C/332 */ unsigned int SoccerWinBy;
    /* 0x150/336 */ unsigned int SoccerCatchMinimum;
    /* 0x154/340 */ unsigned int MiscResetScoreOnFrequencyChange;
    /* 0x158/344 */ struct ARENA_BUY_SETTINGS BuySettings[24];
    /* 0x398/920 */ char MiscSheepMessage[256];
    /* 0x498/1176 */ char OwnerName[32];
};
// sizeof(VOICE_UPLOAD_STRUCT) = 8
struct VOICE_UPLOAD_STRUCT
{
    /* 0x0/0 */ unsigned char* VoiceMemoryPointer;
    /* 0x4/4 */ unsigned int VoiceSize;
};
// sizeof(struct PLAYER) = 861
struct PLAYER
{
    /* 0x0/0 */ struct _PROCESS_INFORMATION *ProcessInformation;
    /* 0x4/4 */ unsigned int dword4;
    /* 0x8/8 */ unsigned int dword8;
    /* 0xC/12 */ unsigned int dwordC;
    /* 0x10/16 */ unsigned int BillerPlayerId;
    /* 0x14/20 */ unsigned short PlayerId;
    /* 0x16/22 */ unsigned char gap_16[2];
    /* 0x18/24 */ unsigned int SubspaceEXEChecksumIndex;
    /* 0x1C/28 */ struct ARENA *MyArena;
    /* 0x20/32 */ struct ARENA *MyLastArena;
    /* 0x24/36 */ unsigned int LastAdvertisementTime;
    /* 0x28/40 */ struct CONNECTION *connection;
    /* 0x2C/44 */ unsigned int ConnectType;
    /* 0x30/48 */ unsigned int ForceWearBanner;
    /* 0x34/52 */ unsigned int SlowModem;
    /* 0x38/56 */ unsigned int AlreadySentReliablePacket;
    /* 0x3C/60 */ unsigned int field_3C;
    /* 0x40/64 */ unsigned int IsSilenced;
    /* 0x44/68 */ unsigned int IsEnergyShowing;
    /* 0x48/72 */ unsigned int DemoPlayer;
    /* 0x4C/76 */ signed int field_4C;
    /* 0x50/80 */ signed int field_50;
    /* 0x54/84 */ signed int field_54;
    /* 0x58/88 */ signed int field_58;
    /* 0x5C/92 */ signed int field_5C;
    /* 0x60/96 */ signed int field_60;
    /* 0x64/100 */ unsigned char SubspaceVersion;
    /* 0x65/101 */ unsigned char gap_65[3];
    /* 0x68/104 */ char someStringBuffer[64];
    /* 0xA8/168 */ unsigned int field_A8;
    /* 0xAC/172 */ unsigned int KickOffDelayTimer;
    /* 0xB0/176 */ unsigned char gap_B0[4];
    /* 0xB4/180 */ unsigned int LastSecurityPacketReturnedTime;
    /* 0xB8/184 */ unsigned int LatencyKickOutDelayTimer;
    /* 0xBC/188 */ unsigned int DeathsWithoutFiring;
    /* 0xC0/192 */ unsigned int DebtKills;
    /* 0xC4/196 */ unsigned int C2SCurrentFast;
    /* 0xC8/200 */ unsigned int C2SCurrentSlow;
    /* 0xCC/204 */ unsigned int C2SCurrentTotalFast;
    /* 0xD0/208 */ unsigned int C2SCurrentTotalSlow;
    /* 0xD4/212 */ unsigned int KingCrownKills;
    /* 0xD8/216 */ unsigned int MySoccerReward;
    /* 0xDC/220 */ unsigned char PositionByteThree;
    /* 0xDD/221 */ unsigned char ShipDirection;
    /* 0xDE/222 */ unsigned int PingTimestamp;
    /* 0xE2/226 */ unsigned short XVelocity;
    /* 0xE4/228 */ unsigned short YPixels;
    /* 0xE6/230 */ unsigned char PositionPacketChecksum;
    /* 0xE7/231 */ unsigned char ShipTogglables;
    /* 0xE8/232 */ unsigned short XPixels;
    /* 0xEA/234 */ unsigned short YVelocity;
    /* 0xEC/236 */ unsigned short Bounty;
    /* 0xEE/238 */ unsigned short Energy;
    /* 0xF0/240 */ unsigned short WeaponsInfo;
    /* 0xF2/242 */ struct PRIZE_PACKET_STRUCT PrizePacket;
    /* 0xFD/253 */ unsigned int SendWeaponUpdatePacket;
    /* 0x101/257 */ unsigned int EnergyOptional;
    /* 0x105/261 */ unsigned int TimerOptional;
    /* 0x109/265 */ unsigned short SharpnelMinesBombsBulletsMultifireInformationOptional;
    /* 0x10B/267 */ unsigned int field_10B;
    /* 0x10F/271 */ unsigned int field_10F;
    /* 0x113/275 */ unsigned int Ship;
    /* 0x117/279 */ signed int Frequency;
    /* 0x11B/283 */ unsigned char gap_11B[4];
    /* 0x11F/287 */ unsigned int SecurityWeaponCountyTotalNew;
    /* 0x123/291 */ unsigned int SecurityWeaponCountTotal;
    /* 0x127/295 */ unsigned int SecurityWeaponCount;
    /* 0x12B/299 */ struct SECURITY_PACKET_STRUCT SecurityPacketCache;
    /* 0x153/339 */ unsigned int field_153;
    /* 0x157/343 */ unsigned int CurrentSecurityPacketModifcationCount;
    /* 0x15B/347 */ unsigned int field_15B;
    /* 0x15F/351 */ signed int MyArenaScoreIndex;
    /* 0x163/355 */ unsigned int LooksLikeX1BigOfSomething;
    /* 0x167/359 */ unsigned int LooksLikeXSmallOfSomething;
    /* 0x16B/363 */ unsigned int LooksLikeYBigOfSomething;
    /* 0x16F/367 */ unsigned int LooksLikeYSmallOfSomething;
    /* 0x173/371 */ signed int ArenaPlayerIndex;
    /* 0x177/375 */ struct PLAYER_DATA_BILLER_PACKET_STRUCT PlayerDataBillerPacket;
    /* 0x223/547 */ unsigned short CurrentWins;
    /* 0x225/549 */ unsigned short CurrentDeaths;
    /* 0x227/551 */ unsigned short CurrentGoals;
    /* 0x229/553 */ unsigned int KillPoints;
    /* 0x22D/557 */ unsigned int FlagPoints;
    /* 0x231/561 */ unsigned short PersonalBestWins;
    /* 0x233/563 */ unsigned short PersonalBestLosses;
    /* 0x235/565 */ unsigned short PersonalBestGoalCount;
    /* 0x237/567 */ unsigned int PersonalBestKillPoints;
    /* 0x23B/571 */ unsigned int PersonalBestFlagPoints;
    /* 0x23F/575 */ unsigned short WinsSomething;
    /* 0x241/577 */ unsigned short DeathsSomething;
    /* 0x243/579 */ unsigned short GoalsSomething;
    /* 0x245/581 */ unsigned int KillPointsSomething;
    /* 0x249/585 */ unsigned int FlagPointsSomething;
    /* 0x24D/589 */ unsigned short LastCurrentWins;
    /* 0x24F/591 */ unsigned short LastCurrentDeaths;
    /* 0x251/593 */ unsigned short LastGoalCount;
    /* 0x253/595 */ unsigned int LastKillPoints;
    /* 0x257/599 */ unsigned int LastFlagPoints;
    /* 0x25B/603 */ unsigned int field_25B;
    /* 0x25F/607 */ unsigned int NoPasswordPacketDelayTimer;
    /* 0x263/611 */ signed int AttachedToPlayerId;
    /* 0x267/615 */ unsigned int AllowAudioByte1;
    /* 0x26B/619 */ unsigned int XResolution;
    /* 0x26F/623 */ unsigned int YResolution;
    /* 0x273/627 */ unsigned int AllowAudioByte2;
    /* 0x277/631 */ unsigned int IsSysop;
    /* 0x27B/635 */ unsigned int IsSuperModerator;
    /* 0x27F/639 */ unsigned int IsModerator;
    /* 0x283/643 */ unsigned int field_283;
    /* 0x287/647 */ unsigned int field_287;
    /* 0x28B/651 */ unsigned int field_28B;
    /* 0x28F/655 */ unsigned int LastMessageSpamResetCheckTime;
    /* 0x293/659 */ unsigned int MessageSpamTotal;
    /* 0x297/663 */ unsigned int CurrentSuicideCount;
    /* 0x29B/667 */ unsigned int field_29B;
    /* 0x29F/671 */ unsigned int field_29F;
    /* 0x2A3/675 */ unsigned char PlayerName[24];
    /* 0x2BB/699 */ unsigned char TypedName[32];
    /* 0x2DB/731 */ unsigned char gap_2DB[16];
    /* 0x2EB/747 */ unsigned int IsSpeced;
    /* 0x2EF/751 */ unsigned int TotalShipChanges;
    /* 0x2F3/755 */ struct in_addr IPAddressDWORD;
    /* 0x2F7/759 */ unsigned short Port;
    /* 0x2F9/761 */ unsigned int MachineId;
    /* 0x2FD/765 */ time_t UsageSessionSeconds; //TODO: although it's 4 bytes.. time_t can be 8 bytes too.. heh so always use sizeof(PLAYER)!!!
    /* 0x301/769 */ unsigned int TimeZoneBias;
    /* 0x305/773 */ unsigned int field_305;
    /* 0x309/777 */ unsigned int field_309;
    /* 0x30D/781 */ unsigned int ScoreReset;
    /* 0x311/785 */ unsigned int KotHDeathCount;
    /* 0x315/789 */ unsigned int DisconnectReason;
    /* 0x319/793 */ unsigned int C2SAverageLatencyFirst;
    /* 0x31D/797 */ unsigned int C2SAverageLatencySecond;
    /* 0x321/801 */ unsigned int S2CPacketLossPercentage;
    /* 0x325/805 */ unsigned int C2SPacketLossPercentage;
    /* 0x329/809 */ FILE *pfile329;
    /* 0x32D/813 */ unsigned char char32d;
    /* 0x32E/814 */ unsigned char gap_32E[15];
    /* 0x33D/829 */ struct VOICE_UPLOAD_STRUCT VoiceUploads[4];
};
// sizeof(struct ARENA) = 119822
struct ARENA {
    /* 0x0/0 */ struct PLAYER *PlayerPointers[1025]; //unknown 1024x4 = 4096 bytes?
    /* 0x1004/4100 */ unsigned char gap_1004[11972]; //unknown 11972 bytes?
    /* 0x3EC8/16072 */ unsigned int PlayerPointersTest[1024]; //unknown 1024x4 = 4096 bytes
    /* 0x4EC8/20168 */ unsigned char gap_4EC8[44088]; //unknown 44088 bytes [ALL ABOVE ADDS TO 64252 bytes] [IF YOU DIVIDE [64252 / 861] you only get ~74.6, if it's a array of struct of PLAYERS]
    /* 0xFB00/64256 */ char ArenaName[32];
    /* 0xFB20/64288 */ struct PLAYER *ArenaPlayers[250]; //4 address x 250=1000 bytes? [maybe it uses 1 byte per player which makes 1000 PLAYERS PER ARENA!]
    /* 0xFF08/65288 */ unsigned int NeedSettingsUpdate;
    /* 0xFF0C/65292 */ unsigned int ArenaPlayerCount;
    /* 0xFF10/65296 */ unsigned int LastArenaSettingsUpdateTime;
    /* 0xFF14/65300 */ unsigned int LastTerritoryRewardTime;
    /* 0xFF18/65304 */ unsigned int LastPeriodicRewardTime;
    /* 0xFF1C/65308 */ unsigned int LastCheckArenaEmptyTime;
    /* 0xFF20/65312 */ unsigned int field_FF20;
    /* 0xFF24/65316 */ unsigned int DoorSeedValue;
    /* 0xFF28/65320 */ unsigned int PrizeSeedValue;
    /* 0xFF2C/65324 */ unsigned int SynchronizationTimeStamp;
    /* 0xFF30/65328 */ unsigned int SecurityChecksumCounterOddValue;
    /* 0xFF34/65332 */ unsigned int RandomScrtyDataIndex;
    /* 0xFF38/65336 */ unsigned int SettingsChecksum;
    /* 0xFF3C/65340 */ unsigned int MapLVLChecksum;
    /* 0xFF40/65344 */ unsigned short BrickIdCounter;
    /* 0xFF42/65346 */ unsigned int LastFlagResetTime;
    /* 0xFF46/65350 */ unsigned int LastTimedGameTime;
    /* 0xFF4A/65354 */ unsigned int LastKotHTimer;
    /* 0xFF4E/65358 */ unsigned int field_FF4E;
    /* 0xFF52/65362 */ unsigned int GameTimeStart;
    /* 0xFF56/65366 */ unsigned int field_FF56;
    /* 0xFF5A/65370 */ unsigned int GameTimePassed;
    /* 0xFF5E/65374 */ unsigned int ArenaLocked;
    /* 0xFF62/65378 */ unsigned int RecordPointsToLog;
    /* 0xFF66/65382 */ unsigned int ArenaJackpot;
    /* 0xFF6A/65386 */ unsigned int TotalFlags;
    /* 0xFF6E/65390 */ unsigned int TotalSoccerBalls;
    /* 0xFF72/65394 */ struct SOCCER_BALL SoccerBalls[8];
    /* 0xFFEA/65514 */ unsigned int SoccerBallTimers[8];
    /* 0x1000A/65546 */ unsigned int Freq1Score;
    /* 0x1000E/65550 */ unsigned int Freq2Score;
    /* 0x10012/65554 */ unsigned int Freq3Score;
    /* 0x10016/65558 */ unsigned int Freq4Score;
    /* 0x1001A/65562 */ unsigned int field_1001A;
    /* 0x1001E/65566 */ unsigned int LastKotHGameResetCheckTime;
    /* 0x10022/65570 */ unsigned int HasScoreFile;
    /* 0x10026/65574 */ unsigned int ArenaRecycling;
    /* 0x1002A/65578 */ unsigned int AllMessagesLocked;
    /* 0x1002E/65582 */ unsigned int AllMessagesLockedAgainSomething;
    /* 0x10032/65586 */ unsigned int PrivateMessagesLocked;
    /* 0x10036/65590 */ unsigned int SpecMessageLock;
    /* 0x1003A/65594 */ unsigned int TotalScoreStructs;
    /* 0x1003E/65598 */ struct SCORE StructToScore[1000];
    /* 0x1468E/83598 */ unsigned int LastSaveStatsTime;
    /* 0x14692/83602 */ unsigned int TotalNumScoresInFile;
    /* 0x14696/83606 */ struct SCORE * ScoreFilePointer;
    /* 0x1469A/83610 */ struct BRICK Bricks[1024];
    /* 0x1869A/99994 */ unsigned int NumOfBricksInArena;
    /* 0x1869E/99998 */ struct FLAG Flags[510];
    /* 0x1A67E/108158 */ unsigned char field_1A67E[32];
    /* 0x1A69E/108190 */ unsigned int FlagCounter;
    /* 0x1A6A2/108194 */ struct ARENA_SETTINGS ArenaSettings;
    /* 0x1AC36/109622 */ struct SERVERSIDE_ARENA_SETTINGS ServersideArenaSettings;
    /* 0x1B0EE/110830 */ char SettingsFilename[256];
    /* 0x1B1EE/111086 */ char MapFilename[256];
    /* 0x1B2EE/111342 */ char SetLevelMapFilename[256];
    /* 0x1B3EE/111598 */ unsigned int LastSettingsWrittenTime;
    /* 0x1B3F2/111602 */ unsigned int MasterPrizeWeightPoolValue;
    /* 0x1B3F6/111606 */ unsigned int CalculatedMapZoomFactor;
    /* 0x1B3FA/111610 */ char *CompressedMap;
    /* 0x1B3FE/111614 */ unsigned long MapFileSize;	//changed to 8 bytes to remove warning
    /* 0x1B402/111618 */ unsigned int MapChecksum;
    /* 0x1B406/111622 */ struct FLAG TurfFlagsCoordinates[510]; //odd TurfFlags get 510 flags and not 255
    /* 0x1D3E6/119782 */ unsigned char field_1D3E6[32];
    /* 0x1D406/119814 */ unsigned int TotalMapTurfFlags;
    /* 0x1D40A/119818 */ unsigned char *MapData;
};

//-------------------------------------------------------------------------
// Data declarations

// _UNKNOWN _local_unwind2; weak
//_UNKNOWN sub_4210D6; // weak
// _UNKNOWN sub_42110A; weak
int dword_429128[2]; // weak
int dword_429140[2]; // weak
int LastBillerPlayerId; // weak
int UseBillingServer = 1; // weak
const char *ShipNames[8] = {"Warbird", "Javelin", "Spider", "Leviathan", "Terrier", "Weasel", "Lancaster", "Shark" }; //off_42C848
//int RNGSeed; // weak
//FILE stdout; // idb
//int (__cdecl *off_42E734)(unsigned int, unsigned int, unsigned int, unsigned int); // weak
void *off_430988; // weak
void *off_430994; // weak
int dword_43099C; // weak
int dword_430A30; // weak
int dword_430A34; // weak
int dword_430A38; // weak
int dword_430A40; // weak
int dword_430A44; // weak
int dword_430A48; // weak
int dword_430E60[6]; // weak
int dword_430E78[6]; // weak
int dword_431490; // weak
HANDLE hConsoleHandle; // idb
int AdvertiseSendMode; // weak
char DirectoryIPAddresses[512];
char ServerCFGFilePath[256];
struct PACKET_ADVERTISEMENT RegisteredAd[128];
int LastTimeServerINIWasEdited; // weak
int DirectoryConnectSockets[8];
int DirectoryPort; // idb
int RadarValue; // weak
struct PACKET_ADVERTISEMENT SharewareAd[128];
struct BILLING_SERVER_STRUCT *BillingConnectionStructPointer; // idb
int ArenaArrayLength; // weak
int ServerIterations; // weak
int ArenaMinimumPlayers; // weak
int LastTimeMasterCFGWasEdited; // weak
int RecycleServer; // weak
struct CHAT ChatRelatedArray[64];
struct PACKET_ATTACHMENT *ServerPacketAttachment; // idb
unsigned char *CompressedServerMap; // idb
int ArenaSpawnKeepScores; // weak
int dword_437B14; // weak
char ServerINIFilePath[256]; // idb
int DoubleValue; // weak
int BillingAttemptTime; // weak
char DirectoryNamePassword[128];
int CommsMaxQueueToLogin; // weak
int CurrentLogLine; // weak
int IsServerRunning; // weak
struct PACKET_ADVERTISEMENT BothAd[128]; // idb
int ArenaMaxPlayers; // weak
int CommsPacketHistoryMax;
char SuperModeratorPassword[64];
char ModeratorPassword[64];
int MiscMaxSharewarePlayer; // weak
struct ARENA_SETTINGS ArenaSettings;
int MachineIdArrayCount; // weak
char BillingPassword[32];
int MapChecksum; // weak
int TotalSentForEachPacketType[256];
unsigned short BillingPort; // idb
LPVOID CompressedNewsMemory; // idb
int MiscLogPoints; // weak
struct TEXT_FILE_STRUCT * ObscenePointer; // idb
int ScreenValue; // weak
int CPUSlowIterationWarningLevel; // weak
int MaxArenasMemory; // weak
int PermissionMode; // weak
int CommsEncryptMode; // weak
struct TEXT_FILE_STRUCT *ModeratePointer; // idb
char VIPPassword[64];
struct TEXT_FILE_STRUCT *PermitPointer; // idb
struct BMP_FILE_STRUCT *BMPFilePointer; // idb
int MiscMaxPlayers; // weak
int BillingReconnectTime; // weak
int PermissionMinimumSecondsToLogin; // weak
struct TEMPLATE_SSS TotalTemplateSSSList[1400];
char EnergyPassword[64];
int PermissionMaxPoints; // weak
struct CONNECTION* EncryptionStruct; // idb
int BillingGroupId; // idb
int BillingServerId; // idb
struct KICK KickedUsers[1000]; // weak
int MiscKeepAliveDelay; // weak
int AutoPermissionPoints; // weak
char SysopPassword[64];
unsigned int CPUSleepTime; // idb
int TotalSentSizeForEachPacketType[256];
char DirectoryDescription[256];
char BillingIP[128];
int dword_4AF8F8; // weak
int dword_4AF8FC[5]; // weak
char byte_4AF911[1234]; // weak //FIX 1234 with real value (UNKNOWN ATM)
int dword_4C8F38; // weak
int dword_4C8F3C; // weak
struct PLAYER *ZonePlayers[1024];
int CPUSleepPerIteration; // weak
char MiscDefaultLevelFile[256];
struct SERVERSIDE_ARENA_SETTINGS ServersideArenaSettings;
char PermissionAutoPermissionMessage[256];
int ServerListenPort; // idb
int MiscPointUpdateDiff; // weak
char PermissionAutoPermissionIDList[512];
int BillingLogMessages; // weak
int IncreasesRadarValueSomeHow; // weak
struct SERVER_BIG_ARRAY Security[10];
int CustomArenaMode; // weak
struct PLAYER *ZonePlayerList[1025];
int MiscServerLog; // weak
int dword_4D55D0; // weak
int MiscMaxSharkwareTime; // weak
int MiscMenuKickOutDelay; // weak
struct TEXT_FILE_STRUCT * ReservedPointer; // idb
struct ARENA *Arenas[200];
int PermissionAllowLowBandwidth; // weak
int CPUProcessMaxTime; // weak
int MaxArenas; // weak
int MiscJackpotBroadcastPoints; // weak
int MiscRegisterKickShareware; // weak
int NewsTxtFileChecksum; // weak
int MiscDisableShareware; // weak
int CommsIncomingBufferSize; // idb
int IsEditedServerINIorCFG; // weak
int LastTimeNewsTxtWasEdited; // weak
int ArenaDesiredPlayers; // weak
char LogArray[12288]; // weak
int AdvertiseDuration; // weak
int BillingScoreId; // idb
unsigned char *ServerMapData; // idb
int CommsOutgoingBufferSize; // idb
char BillingServerName[128];
int ZonePingSocket; // idb
int BillerSocket; // idb
int Wave; // weak
char ShutdownArguments; // idb
struct TEXT_FILE_STRUCT * IDBlockPointer; // idb
struct PACKET_ATTACHMENT *BillerPacketAttachment; // idb
int AdvertiseDisplayMode; // weak
int ZonePlayerCount; // idb
int MiscDisableSharewareScores; // weak
int TotalTemplateSSSEntries; // weak
unsigned long NewsTxtFileSize; // idb
signed int CommsTransportBufferSize; // idb
unsigned long MapFileSize; //changed to 8 bytes to remove warning
int LastServerStatsAndKickedPlayersTime; // weak
int HighestPlayerCountMaybeSomething; // weak
int SharewareAdvertisementsFound; // weak
int RegisteredAdvertisementsFound; // weak
int BothAdvertisementsFound; // weak
FILE *PointsFileHandle; // idb
FILE *SubGameLogFileHandle; // idb
int dword_4D8B14; // weak
int ChatCounter64Max; // weak
int dword_4D8B38; // weak
int dword_4D8B44; // weak
int dword_4D8B88; // weak
int dword_4D8B8C; // weak
//int (__cdecl *dword_4D8BDC)(unsigned int, unsigned int, unsigned int, unsigned int); // weak
int dword_4D8C18; // weak
struct _TIME_ZONE_INFORMATION TimeZoneInformation; // idb

//-------------------------------------------------------------------------
// Function declarations

void __cdecl InitializeNewArena(struct ARENA *arena, const char *Source);
void __cdecl ShutdownArena(struct ARENA *arena);
void __cdecl DropBrick(struct ARENA *arena, int XTiles, int YTiles, short Team); // idb
void __cdecl PlayerEntering(struct ARENA *arena, struct PLAYER *player);
void __cdecl PlayerLeaveArena(struct ARENA *arenaa, struct PLAYER *player);
bool __cdecl ProcessArena(struct ARENA *arena);
int __cdecl PtFuncCompare(struct PLAYER **a1, struct ARENA *a2);
void __cdecl ArenaScoreReset(struct ARENA *arena, bool BooleanSendScoreReset);
void __cdecl CreateSoccerBall(struct ARENA *arena, int PowerBallId); // idb
void __cdecl FlagPositionUpdateSomething(struct ARENA *arena, int a2);
void __cdecl CarryFlagsSomething(struct ARENA *arena, int a2, int a3); // idb
void __cdecl ResetJackpotFlags(struct ARENA *arena); // weak
int __cdecl GetNextFrequencyToJoin(struct ARENA *arena);
void __cdecl SendArenaPacket(struct ARENA *arena, const void *buf, int len, int IsReliableSend);
void __cdecl SpawnOnMap(struct ARENA *arena, int *ReturnXTile, int *ReturnYTile, int XStart, int YStart, int Radius);
void __cdecl sub_404980(struct ARENA *arena, struct PLAYER *player, int a3, int a4);
void __cdecl AddPlayerToArenaSomething(struct ARENA *arena, struct PLAYER *player, signed int a3, signed int a4); // idb
void __cdecl LoadArenaSettings(struct ARENA *arena); // idb
void __cdecl LoadArenaMap(struct ARENA *arena);
int __cdecl GetDeathPrizeGreenId(struct ARENA *arena); // idb
signed int __cdecl ChangeSettings(struct ARENA *arena, struct PLAYER *player, const char *a3); // idb
void __cdecl sub_405360(struct ARENA *arena, int BooleanSendScoreReset);
void __cdecl SoccerGameSomething(struct ARENA *arena, int a2);
char __cdecl sub_4055D0(struct ARENA *arena, int Frequency, int a3, signed int a4);
void __cdecl GetScore(struct ARENA *arena, struct PLAYER *player);
unsigned int __cdecl GetArenaMemoryTotal(struct ARENA *arena);
int __cdecl GetTotalPlayingPlayers(struct ARENA *arena);
void __cdecl SendBillerServerConnectPacket(struct BILLING_SERVER_STRUCT *billingStruct, int HandleBillerPacketFuncAddress, const char *ServerName, int ServerId, int GroupId, int ScoreId, const char *Password, struct PACKET_ATTACHMENT *mainServerStructure, struct CONNECTION *connection); // idb
int __cdecl CleanUpBilling(struct BILLING_SERVER_STRUCT *billingServerStruct);
void __cdecl SendBillerUserBannerPacket(struct BILLING_SERVER_STRUCT *billingServerStruct, int a2, const void *a3);
void __cdecl SendBillerUserDemographicsPacket(struct BILLING_SERVER_STRUCT *billingServerStruct, int PlayerId, unsigned char *UserDemographics);
void __cdecl SendBillerUnknownPacket(struct BILLING_SERVER_STRUCT *billingServerStruct, int a1, int a2, const char *a3);
void __cdecl SendBillerUserChannelChatPacket(struct BILLING_SERVER_STRUCT *billingServerStruct, int PlayerId, const char *ChannelName, const char *ChatText);
void __cdecl SendBillerWarningPacket(struct BILLING_SERVER_STRUCT *billingServerStruct, int PlayerId, const char *WarningMessage);
void __cdecl SendBillerUserCommandPacket(struct BILLING_SERVER_STRUCT *billingServerStruct, int a2, const char *UserCommand);
void __cdecl SendBillerUserLoginPacket(struct BILLING_SERVER_STRUCT *billingServerStruct, const char *Username, const char *Password, struct in_addr IPAddress, int MachineId, int Timezone, char IsNewUser, int PlayerId, char Unused0, char isSysop);
void __cdecl SendBillerUserLogoffPacket(struct BILLING_SERVER_STRUCT *billingServerStruct, struct PLAYER *player, __int16 Latency, __int16 Ping, bool IsNotSendPlayerScore);
void __cdecl SendBillerUserScorePacket(struct BILLING_SERVER_STRUCT * billingServerStruct, int PlayerId, const void *Score, unsigned int Size);
void __cdecl SendBillerPlayerNamePacketSomething(struct BILLING_SERVER_STRUCT *billingServerStruct, int a2, int a3, const void *a4, unsigned int len);
void __cdecl SendBillerUserPrivateChatPacket(struct BILLING_SERVER_STRUCT *billingServerStruct, int PlayerId, int BillingGroupId, const void *a4, unsigned int len);
void __cdecl SendBillerZoneRevokePermitPacket(struct BILLING_SERVER_STRUCT *billingServerStruct, int a1, int a2, const void *a3, unsigned int len);
int __cdecl GetBillerLastReconnectTime(struct BILLING_SERVER_STRUCT *billingServerStruct); // weak
signed int __cdecl IsBillingServerDisconnected(struct BILLING_SERVER_STRUCT *billingServerStruct);
void __cdecl ReadCompleteSettings(struct struc_2 *ConfigSETPointer, const char *Filename);
void __cdecl WriteCompleteSettings(struct struc_2 *struc2);
int __cdecl GetCFGSettingInteger(struct struc_2 *Str1, const char *Str2, const char *a3, int a4);
void __cdecl GetCFGSettingString(struct struc_2 *Str1, char *Str2, char *a3, char *Source, char *Dest, size_t Count);
void __cdecl sub_4066B0(struct struc_2 *strucValue, const char *Str2, const char *a3, const char *Source, char *Dest, size_t Count);
void __cdecl FillArenaSettingsStruct(struct struc_2 *Str1, const char *Str2, const char *a3, const char *Source);
void __cdecl LoadBMPHeader(struct BMP_FILE_STRUCT *Filename, const char *Source);
void __cdecl sub_406B30(struct BMP_FILE_STRUCT *BMPFileStruct);
void __cdecl GetTileValue(struct BMP_FILE_STRUCT *BMPFile, int TileCounter, int *TileValuePointer);
void __cdecl DoBrickDrop(unsigned char *MapData, int XTiles, int YTiles, int *X1Tile, int *Y1Tile, int *X2Tile, int *Y2Tile, int BrickSpanSize); // idb
signed int __cdecl GenerateLVLChecksum(unsigned char *MapData, signed int Key);
bool __cdecl IsMapFileValid(const char *Filename);
void __cdecl InitializeTextFile(struct TEXT_FILE_STRUCT *textFile, const char *Source, int makeUpperCase);
void __cdecl CleanTextFileMemory(struct TEXT_FILE_STRUCT *textFile); // weak
void __cdecl LoadTextFile(struct TEXT_FILE_STRUCT *textFile, int a2);
void __cdecl WriteTextFileToFile(struct TEXT_FILE_STRUCT *textFile);
int __cdecl TextFileTotalLines(struct TEXT_FILE_STRUCT *textFile);
char * __cdecl TextFileByIndex(struct TEXT_FILE_STRUCT *textFile, int listMachineIndex); // idb
void __cdecl AddLineTextFile(struct TEXT_FILE_STRUCT *textFile,  char *ChatMsgBuffer);
void __cdecl RemoveLineTextFile(struct TEXT_FILE_STRUCT *textFile, int Number);
int __cdecl IsLineExistTextFile(struct TEXT_FILE_STRUCT *textFile, char *MachineId);
int __cdecl StringCompare(int ElementString, int ArrayPointer);
int __cdecl SomeOtherCompare(int _connection, int _ConnectionsArray);
char *__cdecl GetSplitNextDirectoryIP(char *a1, char *Src);
BOOL __cdecl IsFileLastWrittenTime(char * lpFileName, unsigned int *a2);
int __cdecl BinarySearch(int ElementToFind, int Array, unsigned int TotalElements, unsigned int ElementSize, int (__cdecl *CompareFunc)(int, int), bool *IsFoundPointer);
unsigned int __cdecl ReadIntegerINI(char * lpAppName, char * lpKeyName, unsigned int a3, char * lpFileName);
BOOL __cdecl ReadStringINI(char * lpAppName, char * lpKeyName, const char *a3, LPSTR lpString, unsigned int nSize, char * lpFileName);
void __cdecl Trim(unsigned char *s); // weak
unsigned int __cdecl CRC32(char *buffer, int fileSize);
void __cdecl CopyFileCFG(char *destination, const char *source);
//int nullsub_1(void); // weak
void *__cdecl AllocateMemory(int bytes);
char *__cdecl ExpandMemory(void *lpAddress, unsigned long Bytes, unsigned long MaxSize);
void __stdcall FreeMemory(LPVOID ptr);
void __cdecl ConnectSocket(int *Socket, const char *Hostname, unsigned short ConnectPort, unsigned short ListenPort);
void __cdecl CloseSocketWrapper(int socket);
void __cdecl SendDirectoryServerZoneUpdatePacket(int Socket, const void *a2, unsigned int a3);
int __cdecl GetSocketRecvLag(int Socket, int *TimeElapsed);
void __cdecl ListenOnPort(int *Socket, unsigned short hostshort);
void __cdecl ProcessZonePingPlayerCount(int Socket, int ZonePopulation); // idb
struct PLAYER *__cdecl CreateNewPlayer(struct PLAYER *player, struct in_addr a2, short a3, struct CONNECTION *connection); // idb
void __cdecl DisconnectUser(struct PLAYER *player);
void __cdecl PlayerHandleGamePacket(struct PLAYER *player, unsigned char *packet, int packetSize);
void __cdecl SecurityViolation(struct PLAYER *player, int a2); // idb
void __cdecl UpdatePowerBallPositions(struct PLAYER *player); // idb
bool __cdecl sub_40CF10(struct PLAYER *player);
void __cdecl sub_40D870(struct PLAYER *player);
void __cdecl PlayerChangeFrequency(struct PLAYER *player, signed int NewFrequencyy);
void __cdecl SetPlayerShip(struct PLAYER *player, signed int Ship); // idb
void __cdecl sub_40DEA0(struct PLAYER *player, const void *buf, unsigned int len, int a4);
void __cdecl SendPlayerReliablePacket(struct PLAYER *player, const void *buf, unsigned int len, int a4);
void __cdecl SendToSpectators(struct PLAYER *player, char *buf, int len, int a4, int a5, int a6);
void __cdecl SendEverybodyButYourself(struct PLAYER *player, const void *buf, unsigned int len, int a4);
void __cdecl SendPacketToMyFrequency(struct PLAYER *player, const void *buf, unsigned int len, int IsReliableSend);
void __cdecl SomethingWithAttachedPlayer(struct PLAYER *player, const void *buf, unsigned int len, int a4, int a5, int a6);
void __cdecl sub_40E220(struct PLAYER *player, const void *buf, unsigned int len, int a4, int a5, int a6);
void __stdcall SomethingWithAudioByteAndShip8(int ArenaPlayerIndex, const void *buf, unsigned int len, int a4, int a5, int a6);
void __cdecl sub_40E300(struct PLAYER *player, int a2, char *buf, int len, int a4, int a6, int a7);
void __cdecl SendArenaMessage(struct PLAYER *player, const char *a2, char SoundByte);
void __cdecl SendChannelMessage(struct PLAYER *player, const char *a2);
void __cdecl SendArenaMessagePlayer(struct PLAYER *player, const char *a2, char SoundByte);
void __cdecl GetServerFile(struct PLAYER *player, const char *Source);
struct ARENA *__cdecl ArenaHandler(struct PLAYER *player, int ArenaIndex, const char *ArenaName); // idb
void __cdecl SendWeaponPacket(struct PLAYER *player);
void __cdecl SendResetScoresPacket(struct PLAYER *player);
void __cdecl SendPlayerScoreUpdate(struct PLAYER *player); // idb
bool __cdecl SendPlayerScoreUpdateAll(struct PLAYER *player);
void __cdecl SendAdvertisement(struct PLAYER *player, bool ForceAdvertisement);
void __cdecl LoadZoneCFGSettings(struct ARENA_SETTINGS *arenaSettings, struct SERVERSIDE_ARENA_SETTINGS *serverArenaSettings, const char *a3);
char __cdecl SoccerRelatedMath(int SoccerMode, int a2, signed int a3);
void __cdecl ServerInitialize();
signed int __cdecl NewConnectionRequest(struct in_addr IPAddress, unsigned short Port, struct CONNECTION *connection);
void __cdecl PlayerHandleGamePacketWrapper(unsigned char *packet, int packetSize, struct CONNECTION *a3);
void __cdecl ServerMainLoop();
int __cdecl IncreaseRadarValueShowHomeOverFourThousand();
void __cdecl ServerUninitialize();
void __cdecl HandleBillerPacket(char *packetBuffer, int packetSize);
void FormatMessageArena(struct ARENA *arena, const char *Format, ...);
void WriteSubGameLog(const char *Format, ...);
bool __cdecl IsOffensiveName(char *a1);
signed int __cdecl IsBannedIPAddress(int a1, const char *a2);
void __cdecl SendBillerWarnings(const char *a1, struct PLAYER *player); // idb
void __cdecl ChatProcessor(struct PLAYER *player, int a4, int arenaPlayerIndex, char *ChatText, char a7);
void __cdecl SomethingWithSendingChatTypes(struct PLAYER *player, char ChatType, signed int TargetPlayerId, char *ChatText, char SoundByte);
void __cdecl AppendPointsLog(struct PLAYER *player, int a2, int a3); // idb
void __cdecl ReadServerINI();
void __cdecl LoadTemplateSSS();
void __cdecl LoadDefaultServerMap();
void __cdecl LoadAdvertisements();
void __cdecl CleanUpAdvertiseMemory();
int __cdecl LoadWinsock();
void __cdecl StartServerListener(struct PACKET_ATTACHMENT *packetAttachment, int a2, int a3, int MaxConnections, int ServerListenPort, int OutgoingBufferSize, int IncomingBufferSize, int PacketHistoryMax); // idb
void __cdecl CleanUpPacketAttachment(struct PACKET_ATTACHMENT *packetAttachment);
void __cdecl SetPacketAttachmentEncryptMode(struct PACKET_ATTACHMENT *packetAttachment, int CommsEncryptMode);
struct CONNECTION *__cdecl ConnectToBiller(struct PACKET_ATTACHMENT *packetAttachment, const char *BillingIP, unsigned short hostshort, int EncryptionServerKey, int a5);
void __cdecl DumpPacketHistory(struct PACKET_ATTACHMENT *packetAttachment, const char *Filename);
char * __cdecl PlayerReadPackets(struct PACKET_ATTACHMENT *packetAttachment, int *RecvLength, struct in_addr *RemoteIP, int *RemotePort);
bool __cdecl ProcessPackets(struct PACKET_ATTACHMENT *packetAttachment); // weak
void __cdecl PlayerHandlePacket(struct PACKET_ATTACHMENT *packetAttachment, unsigned char *buffer, signed int RecvLength, struct in_addr RemoteIP, unsigned short RemotePort);
void __cdecl ProcessRegularPackets(struct PACKET_ATTACHMENT *packetAttachment, char *buffer, int packetLength, struct CONNECTION *connection, int a5);
char * __cdecl sub_41B1B0(struct PACKET_ATTACHMENT *packetAttachment, int *PacketLength, struct CONNECTION *connection);
void __cdecl ResetPacketStatistics(struct PACKET_ATTACHMENT *packetAttachment); // weak
void __cdecl GetPacketStatistics(struct PACKET_ATTACHMENT *packetAttachment, int *TotalPacketSendLength, int *TotalPacketSendCalls, int *TotalPacketRecvLength, int *TotalPacketRecvCalls, int *TotalPacketClustersCalls);
void __cdecl sub_41B430(struct PACKET_ATTACHMENT *packetAttachment, signed int CommsTransportBufferSize); // idb
void __cdecl SendPacketsToEverybody(struct PACKET_ATTACHMENT *packetAttachment);
int __stdcall sub_41B570(int a1);  // weak
void __cdecl InitializeEncryption(struct CONNECTION *connection, struct PACKET_ATTACHMENT *packetAttachment, int state, int PlayerId, struct in_addr RemoteIP, unsigned short RemotePort, signed int ServerKey, int ProtocolVersion, int alwaysZero); // idb
void __cdecl sub_41B7A0(struct CONNECTION *connection);
int __cdecl CheckState(struct CONNECTION *connection); // weak
int __cdecl GetProtocolVersion(struct CONNECTION *connection); // weak
int __cdecl GetBillingServerRelOut(struct CONNECTION *connection, int *a2); // idb
void __cdecl SendPacket(struct CONNECTION *connection, unsigned char *buf, unsigned int len); // idb
void __cdecl ProcessCorePackets(struct CONNECTION *connection, unsigned char *buffer, int PacketLength, int a4); // idb
void __cdecl SendBiDirectionalCorePackets(struct CONNECTION *connection);
bool __cdecl SendReliablePacket(struct CONNECTION *connection, unsigned char *buffer, unsigned int len, int IsSendReliable); // idb
void __cdecl SaveLostReliablePackets(struct CONNECTION *connection, const char *Filename);
void __cdecl SendHugeChunkPacketAllocated(struct CONNECTION *connection, unsigned char *MemoryPointer, int TotalLength, int a4);
void __cdecl SendHugeChunkPacketNotAllocated(struct CONNECTION *connection, unsigned char *MemoryPointer, int TotalLength, int a4);
void __cdecl GetHugeChunkRecieveStats(struct CONNECTION *connection, int *HugeChunkRecieveTotalSize, int *HugeChunkRecievedSize);
void __cdecl GetHugeChunkSendStats(struct CONNECTION *connection, int *HugeChunkSendTotalSize, int *HugeChunkSendSize);
void __cdecl SendPacketCluster(struct CONNECTION *connection, unsigned char *buf, unsigned int len); // idb
void __cdecl sub_41CB20(struct CONNECTION *connection);
void __cdecl GetPingLOSSSomething(struct CONNECTION *connection, int *ServerToYou, int *YouToServer);
void __cdecl GetPacketCountInfoSomething(struct CONNECTION *connection, int *a2, int *a3, int *a4, int *a5);
void __cdecl OrderDisconnect(struct CONNECTION *connection);
char *__cdecl GetIPAddressString(struct in_addr in);
int __cdecl SubspaceEXEChecksum(char *Filename);
char * __cdecl CompressFile(const char *Filename, unsigned long *OutSize, int *CRC_32, const void *Buffer, unsigned int bytes, int DoFileCompression);
// int __stdcall compress(unsigned int, unsigned int, unsigned int, unsigned int); weak
// int __stdcall send(int s, const char *buf, int len, int flags);
// int __stdcall connect(int s, const struct sockaddr *name, int namelen);
// struct hostent *__stdcall gethostbyname(const char *name);
// unsigned int __stdcall inet_addr(const char *cp);
// int __stdcall bind(int s, const struct sockaddr *name, int namelen);
// unsigned long __stdcall htonl(unsigned long hostlong);
// unsigned short __stdcall htons(unsigned short hostshort);
// int __stdcall setsockopt(int s, int level, int optname, const char *optval, int optlen);
// int __stdcall ioctlsocket(int s, int cmd, unsigned long *argp);
// int __stdcall socket(int af, int type, int protocol);
// int __stdcall closesocket(int s);
// int __stdcall recv(int s, char *buf, int len, int flags);
// int __stdcall sendto(int s, const char *buf, int len, int flags, const struct sockaddr *to, int tolen);
// int __stdcall recvfrom(int s, char *buf, int len, int flags, struct sockaddr *from, int *fromlen);
// int __stdcall WSAStartup(WORD wVersionRequested, LPWSADATA lpWSAData);
// int __stdcall WSACleanup();
// char *__stdcall inet_ntoa(struct in_addr in);
//void __cdecl setRNGSeed(int SeedRNG); // idb
// int __cdecl rand();
// int printf(const char *Format, ...);
// time_t __cdecl time(time_t *Time);
// int sprintf(char *Dest, const char *Format, ...);
// char *__cdecl strrchr(const char *Str, int Ch);
// int __cdecl fclose(FILE *File);
// size_t __cdecl fread(void *DstBuf, size_t ElementSize, size_t Count, FILE *File);
// FILE *__cdecl fopen(const char *Filename, const char *Mode);
// char *__cdecl strncpy(char *Dest, const char *Source, size_t Count);
// size_t __cdecl fwrite(const void *Str, size_t Size, size_t Count, FILE *File);
// void __cdecl _alloca_probe(unsigned int a1, char a2);
// void __cdecl memcpy(void *Dst, const void *Src, size_t Size);
// void __cdecl qsort(void *Base, size_t NumOfElements, size_t SizeOfElements, int (__cdecl *PtFuncCompare)(const void *, const void *));
// unsigned int __cdecl shortsort(unsigned int, unsigned int, unsigned int, unsigned int); weak
// unsigned int __cdecl swap(unsigned int, unsigned int, unsigned int); weak
// int __cdecl free(void *Memory); idb
// void __cdecl malloc(unsigned int); idb
// int __cdecl __CxxFrameHandler(struct EHExceptionRecord *ExceptionRecord, struct EHRegistrationNode *, int, int); idb
// int __cdecl atoi(const char *Str);
// int __cdecl isalpha(int C);
// int __cdecl isdigit(int C);
// int __cdecl isspace(int C);
// char *__cdecl fgets(char *Buf, int MaxCount, FILE *File);
// int fprintf(FILE *File, const char *Format, ...);
// int __cdecl fseek(FILE *File, int Offset, int Origin);
// unsigned int __cdecl _chsize(unsigned int, unsigned int); weak
// char *__cdecl strstr(const char *Str, const char *SubStr);
// int __cdecl toupper(int C);
// void __cdecl exit(int Code);
// void __cdecl malloc(size_t Size);
// void __cdecl realloc(void *Memory, size_t NewSize);
// void __cdecl free(void *Memory);
//int __cdecl system(int a1);
// int __cdecl _spawnlp(int, char *Str, int); idb
// clock_t __cdecl clock();
// int __cdecl fflush(FILE *File);
// int __cdecl vsprintf(char *Dest, const char *Format, va_list Args);
// char *__cdecl asctime(const struct tm *Tm);
// struct tm *__cdecl localtime(const time_t *Time);
// double __cdecl difftime(time_t Time1, time_t Time2);
// char *__cdecl strchr(const char *Str, int Val);
// unsigned int __cdecl _filelength(unsigned int); weak
// int __cdecl sub_4210C9(int a1);
//void __cdecl sub_421101();
// int __cdecl ExFilterRethrow(struct _EXCEPTION_POINTERS *); idb
//void __cdecl sub_4214B0(int a1, int a2, int a3, int a4);
void __cdecl j__abort();
//void __cdecl sub_421540(int a1, int a2, int a3, int a4);
int loc_42157F(); // weak
int __cdecl sub_4215AE(unsigned int a, unsigned int b, unsigned int c, unsigned int d); // weak
// int __cdecl _spawnvpe(int, char *Str, int, LPVOID lpEnvironment); idb
// signed int __cdecl _spawnve(int a1, char *Str, int a3, LPVOID lpEnvironment);
// int __cdecl comexecmd(int, void *lpApplicationName, int, LPVOID lpEnvironment); idb
// int __cdecl _access(char * lpFileName, char); idb
// char *__cdecl getenv(const char *VarName);
// unsigned int __cdecl _ftime(unsigned int); weak
//signed int __cdecl DateFunction(int a1);
// unsigned int __cdecl cvtdate(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int); weak
// int __cdecl unknown_libname_6(int, PVOID TargetFrame, int); idb
// int __cdecl _mbsrchr(char *Str, int); idb
// int __cdecl _mbschr(char *Str, int Val); idb
// unsigned int __cdecl _ld12cvt(unsigned int, unsigned int, unsigned int); weak
int __cdecl sub_426670(int a1, int a2);
int __cdecl sub_426690(int a1, int a2);
//int __cdecl sub_4266B0(int a1, int a2);
//int __cdecl sub_4266F0(int a1, int a2);
// unsigned int __cdecl __strgtold12(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int); weak
//int _fileno(FILE *File);
//int stricmp(const char *Str1, const char *Str2);
char* strupr( char* s1 );
//HANDLE getch();
int kbhit( void );
// unsigned int __cdecl _getextendedkeycode(unsigned int); weak
int memicmp(const void *Buf1, const void *Buf2, size_t Size);
// int __initconin(void); weak
//int __cdecl sub_428770(int a1);
//int __cdecl SEH_404B10(struct EHExceptionRecord *a1, struct EHRegistrationNode *a2, int a3, int a4);
//int __cdecl sub_428790(int a1);
//int __cdecl sub_42879B(int a1);
//int __cdecl SEH_40E620(struct EHExceptionRecord *a1, struct EHRegistrationNode *a2, int a3, int a4);
//int __cdecl sub_4287B0(int a1);
//int __cdecl sub_4287E0(int a1);
//int __cdecl sub_4287EE(int a1);
//int __cdecl sub_4287FC(int a1);
//int __cdecl sub_42880A(int a1);
//int __cdecl sub_428818(int a1);
//int __cdecl sub_428826(int a1);
//int __cdecl sub_428834(int a1);
//int __cdecl sub_428842(int a1);
//int __cdecl sub_428850(int a1);
//int __cdecl sub_42885E(int a1);
//int __cdecl sub_42886C(int a1);
//int __cdecl sub_42887A(int a1);
//int __cdecl sub_428888(int a1);
//int __cdecl sub_428896(int a1);
//int __cdecl SEH_412D50(struct EHExceptionRecord *a1, struct EHRegistrationNode *a2, int a3, int a4);
//int __cdecl sub_4288D0(int a1);
//int __cdecl sub_4288DE(struct EHExceptionRecord *a1, struct EHRegistrationNode *a2, int a3, int a4);
//int __cdecl sub_4288F0(int a1);
// int __stdcall GetObjectA(HANDLE h, int c, LPVOID pv);
// BOOL __stdcall DeleteObject(HGDIOBJ ho);
// unsigned int __stdcall GetModuleFileNameA(HMODULE hModule, LPSTR lpFilename, unsigned int nSize);
// BOOL __stdcall WritePrivateProfileStringA(char * lpAppName, char * lpKeyName, char * lpString, char * lpFileName);
// unsigned int __stdcall GetTickCount();
// BOOL __stdcall CloseHandle(HANDLE hObject);
// BOOL __stdcall GetFileTime(HANDLE hFile, LPFILETIME lpCreationTime, LPFILETIME lpLastAccessTime, LPFILETIME lpLastWriteTime);
// HANDLE __stdcall CreateFileA(char * lpFileName, unsigned int dwDesiredAccess, unsigned int dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, unsigned int dwCreationDisposition, unsigned int dwFlagsAndAttributes, HANDLE hTemplateFile);
// unsigned int __stdcall GetPrivateProfileIntA(char * lpAppName, char * lpKeyName, INT nDefault, char * lpFileName);
// unsigned int __stdcall GetPrivateProfileStringA(char * lpAppName, char * lpKeyName, char * lpDefault, LPSTR lpReturnedString, unsigned int nSize, char * lpFileName);
// LPVOID __stdcall VirtualAlloc(LPVOID lpAddress, SIZE_T dwSize, unsigned int flAllocationType, unsigned int flProtect);
// BOOL __stdcall VirtualFree(LPVOID lpAddress, SIZE_T dwSize, unsigned int dwFreeType);
// BOOL __stdcall TerminateProcess(HANDLE hProcess, unsigned int uExitCode);
// BOOL __stdcall GetExitCodeProcess(HANDLE hProcess, LPunsigned int lpExitCode);
// BOOL __stdcall CreateProcessA(char * lpApplicationName, LPSTR lpCommandLine, LPSECURITY_ATTRIBUTES lpProcessAttributes, LPSECURITY_ATTRIBUTES lpThreadAttributes, BOOL bInheritHandles, unsigned int dwCreationFlags, LPVOID lpEnvironment, char * lpCurrentDirectory, LPSTARTUPINFOA lpStartupInfo, LPPROCESS_INFORMATION lpProcessInformation);
// LPSTR __stdcall GetCommandLineA();
// BOOL __stdcall SetConsoleTitleA(char * lpConsoleTitle);
// void __stdcall Sleep(unsigned int dwMilliseconds);
// BOOL __stdcall GetNumberOfConsoleInputEvents(HANDLE hConsoleInput, LPunsigned int lpNumberOfEvents);
// BOOL __stdcall PeekConsoleInputA(HANDLE hConsoleInput, PINPUT_RECORD lpBuffer, unsigned int nLength, LPunsigned int lpNumberOfEventsRead);
// BOOL __stdcall GetConsoleMode(HANDLE hConsoleHandle, LPunsigned int lpMode);
// BOOL __stdcall SetConsoleMode(HANDLE hConsoleHandle, unsigned int dwMode);
// BOOL __stdcall ReadConsoleInputA(HANDLE hConsoleInput, PINPUT_RECORD lpBuffer, unsigned int nLength, LPunsigned int lpNumberOfEventsRead);
// int __stdcall MessageBoxA(HWND hWnd, char * lpText, char * lpCaption, unsigned int uType);
// HANDLE __stdcall LoadImageA(HINSTANCE hInst, char * name, unsigned int type, int cx, int cy, unsigned int fuLoad);
char __OFSUB__(int x, int y);
char __SETS__(int x);

static jmp_buf s_jumpBuffer;

//----- (00411E30) --------------------------------------------------------
int __cdecl main(int argc, char *argv[])
{
    //const char *v3; // eax@1
    char *v4; // eax@1
    int result; // eax@2
    char *v6; // eax@3
    //int v7; //       edi@4
    //signed int v8; // ecx@4
    //bool v9; // zf@6
    //unsigned int v10; // ecx@7
    //int v11; // esi@7
    //char v12; // al@7
    //void *v13; // edi@7
    //int v14; // edx@8
    //int v15; // edi@8
    //signed int v16; // ecx@8
    //unsigned int v17; // ecx@12
    char *v18; // eax@12
    //int v19; // edi@13
    //signed int v20; // ecx@13
    //unsigned int v21; // ecx@16
    //char v22; // dl@16
    //const void *v23; // esi@16
    //void *v24; // edi@16
    //int v25; // esi@16
    //char v26; // cl@16
    //void *v27; // edx@17
    //int v28; // edi@17
    //signed int v29; // ecx@17
    //unsigned int v30; // ecx@20
    //char v31; // al@20
    //const void *v32; // esi@20
    //int v33; // edi@22
    //const char **v34; // esi@22
    int v35; // [sp+0h] [bp-70h]@1
    STARTUPINFO StartupInfo; // [sp+Ch] [bp-64h]@30
    PROCESS_INFORMATION ProcessInformation; // [sp+50h] [bp-20h]@30
    int *v38; // [sp+60h] [bp-10h]@1
    //int v39; // [sp+6Ch] [bp-4h]@28

    v38 = &v35;
    v4 = strstr(*argv, "/SPAWN");
    if ( v4 )
    {
        result = system(&v4[7]); //    /SPAWN and SPACE.
    }
    else
    {
        GetModuleFileNameA(0, ServerINIFilePath, 0x100);
        v6 = strrchr(ServerINIFilePath, '\\');
        if ( v6 ) //Could buffer over-run if path is full 0x100 bytes.
            strcpy(&v6[1], "server.ini");
        else
            strcpy(ServerINIFilePath, "server.ini");

        GetModuleFileNameA(0, ServerCFGFilePath, 0x100);
        v18 = strrchr(ServerCFGFilePath, '\\');
        if ( v18 ) //Could buffer over-run if path is full 0x100 bytes.
            strcpy(&v18[1], "server.cfg");
        else
            strcpy(ServerCFGFilePath, "server.cfg");

        if ( argc > 1 )
        {
            do
            {
                if ( !stricmp(argv[1], "/nb") )
                    UseBillingServer = 0;
                ++argv;
                --argc;
            }
            while ( argc );
        }
        ShutdownArguments = 0;

        ServerInitialize();

        if (setjmp(s_jumpBuffer)) {
            // The longjmp was executed and returned control here
            printf("Exception occurred, dumping packet history\n");
            if ( ServerPacketAttachment ) //Dumps packets in case of server crash, to figure out problem/hackers.
                DumpPacketHistory(ServerPacketAttachment, "packet.log");
        } else {
            // Normal code execution starts here
            IsServerRunning = 0;
            while ( !IsServerRunning )
                ServerMainLoop();
        }

        ServerUninitialize();

        if ( ShutdownArguments )
        {
            memset(&StartupInfo, 0, sizeof(StartupInfo));
            StartupInfo.cb = 68;
            StartupInfo.lpTitle = "Spawned Command";
            CreateProcessA(0, &ShutdownArguments, 0, 0, 0, 0x210, 0, 0, &StartupInfo, &ProcessInformation);
        }
        result = 0;
    }
    return result;
}

//----- (00401000) --------------------------------------------------------
void __cdecl InitializeNewArena(struct ARENA *arena, const char *Source)
{
    //struct ARENA *arena; // ebp@1
    int v3; // eax@6
    //unsigned int (__stdcall *GetTickCount)(); // esi@8
    //int v5; // edi@9
    //signed int v6; // ecx@9
    //bool v7; // zf@11
    //signed int v8; // ecx@12
    //const void *v9; // esi@12
    //char *v10; // edi@12
    //unsigned int v11; // edx@12
    //signed int v12; // ecx@12
    FILE *v13; // eax@15
    FILE *v14; // esi@15
    int v15; // eax@16
    unsigned int v16; // eax@16
    //int v17; // eax@16
    char *v18; // eax@18
    int v19; // eax@26
    //int v20; // eax@28
    //int v21; // edx@30
    //int v22; // edi@32
    //int v23; // edi@32
    //unsigned int v24; // eax@32
    //signed long v25; // qax@32
    //int v26; // eax@38
    int v27; // ecx@39
    //char *v28; // eax@40
    char ArenaScoreFileName[32]; // [sp+10h] [bp-120h]@9
    char Str[256]; // [sp+30h] [bp-100h]@18

    arena->MapData = 0;
    arena->ArenaRecycling = 0;
    arena->SecurityChecksumCounterOddValue = 0;
    if ( stricmp(Source, "server") ) //TODO: Don't think it's ever "server" unless ?go server
    {
        strncpy(arena->ArenaName, Source, 0x20u);
        arena->ArenaName[31] = 0;
    }
    else
    {
        strcpy(arena->ArenaName, "unnamed");
    }
    v3 = CustomArenaMode > 0 && arena->ArenaName[0];
    arena->HasScoreFile = v3;
    arena->TotalNumScoresInFile = 0;
    arena->ScoreFilePointer = 0;
    arena->LastSaveStatsTime = GetTickCount() / 0xA;
    arena->NeedSettingsUpdate = 0;
    arena->AllMessagesLocked = 0;
    arena->AllMessagesLockedAgainSomething = 0;
    arena->PrivateMessagesLocked = 0;
    arena->SpecMessageLock = 0;
    if ( arena->HasScoreFile )
    {
        strcpy(ArenaScoreFileName, arena->ArenaName);
        strcat(ArenaScoreFileName, ".scr");

        v13 = fopen(ArenaScoreFileName, "rb");
        if ( v13 )
        {
            v15 = _fileno(v13);
            arena->TotalNumScoresInFile = _filelength(v15) / 0x12;
            arena->ScoreFilePointer = (struct SCORE *)ExpandMemory(0, sizeof(struct SCORE) * arena->TotalNumScoresInFile, 1);
            fread(arena->ScoreFilePointer, 0x12, arena->TotalNumScoresInFile, v13);
            fclose(v13);
        }
    }
    memset(arena, 0, 0xFB00); //TODO: Wonder what this is. Over 64,000 bytes!
    GetModuleFileNameA(0, Str, 0x100);
    v18 = strrchr(Str, '\\');
    if ( v18 )
        *v18 = 0;
    else
        Str[0] = 0;
    if ( arena->HasScoreFile )
    {
        sprintf(arena->SettingsFilename, "%s\\%s.cfg", Str, arena->ArenaName);
        sprintf(arena->MapFilename, "%s.lvl", arena->ArenaName);
        sprintf(arena->SetLevelMapFilename, "%s.lvl", arena->ArenaName);
        if ( _access(arena->SettingsFilename, 0) ) //arena settings file doesn't exist.
            CopyFileCFG(arena->SettingsFilename, "server.cfg");
        if ( !IsMapFileValid(arena->SetLevelMapFilename) )
        {   //If Map File isn't valid it loads the default server map.
            strcpy(arena->MapFilename, MiscDefaultLevelFile);
        }
        v19 = time(0);
        sprintf(ArenaScoreFileName, "%d", v19);
        WritePrivateProfileStringA("Owner", "LastUsedStamp", ArenaScoreFileName, arena->SettingsFilename);
    }
    else
    {
        sprintf(arena->SettingsFilename, "%s\\server.cfg", Str);
        strcpy(arena->MapFilename, MiscDefaultLevelFile);
        strcpy(arena->SetLevelMapFilename, MiscDefaultLevelFile);
    }
    printf("Arena Created: (%s) using parameters: %s\n", arena->ArenaName, arena->SettingsFilename);
    LoadArenaSettings(arena);
    LoadArenaMap(arena);
    arena->field_1001A = 0;
    arena->LastKotHGameResetCheckTime = GetTickCount() / 0xA;
    arena->LastArenaSettingsUpdateTime = GetTickCount() / 0xA;
    arena->LastTerritoryRewardTime = GetTickCount() / 0xA;
    arena->LastPeriodicRewardTime = GetTickCount() / 0xA;
    arena->NumOfBricksInArena = 0;
    arena->ArenaPlayerCount = 0;
    arena->TotalScoreStructs = 0;
    arena->ArenaLocked = 0;
    arena->ArenaJackpot = 0;
    arena->Freq1Score = 0;
    arena->Freq2Score = 0;
    arena->Freq3Score = 0;
    arena->Freq4Score = 0;
    arena->FlagCounter = 0;
    arena->TotalSoccerBalls = 0;
    if ( arena->ServersideArenaSettings.RandomFlags && arena->ServersideArenaSettings.MaxFlags > 0 )
        arena->TotalFlags = rand() % arena->ServersideArenaSettings.MaxFlags + 1;
    else
        arena->TotalFlags = arena->ServersideArenaSettings.MaxFlags;
    arena->LastFlagResetTime = GetTickCount() / 0xA;
    arena->DoorSeedValue = rand() * rand();
    arena->PrizeSeedValue = rand() * rand();
    arena->RandomScrtyDataIndex = 0;
    arena->SynchronizationTimeStamp = GetTickCount() / 0xA & 0x7FFFFFFF;
    arena->SettingsChecksum = 0;
    arena->MapLVLChecksum = 0;
    arena->BrickIdCounter = 0;
    arena->GameTimeStart = 0;
    arena->GameTimePassed = 0;
    arena->field_FF56 = 0;
    arena->field_FF20 = 0;
    arena->RecordPointsToLog = 1;
    arena->field_FF4E = GetTickCount() / 0xA;
    if ( arena->ArenaName[0] && !ArenaSpawnKeepScores )
        arena->RecordPointsToLog = 0;
    if ( arena->HasScoreFile )
        arena->RecordPointsToLog = 0;
    if ( arena->ServersideArenaSettings.FlagMode == 2 )
    {
        if ( arena->FlagCounter < arena->TotalMapTurfFlags )
        {
            v27 = 0;
            arena->FlagCounter = arena->TotalMapTurfFlags;
            if ( arena->TotalMapTurfFlags > 0 )
            {
                do
                {
                    arena->Flags[v27].XTile = arena->TurfFlagsCoordinates[v27].XTile;
                    arena->Flags[v27].YTile = arena->TurfFlagsCoordinates[v27].YTile;
                    arena->Flags[v27].OwnerFreq = -1;
                    arena->Flags[v27].CarrierPlayerId = -1;
                    ++v27;
                }
                while ( v27 < arena->TotalMapTurfFlags );
            }
        }
    }
    ArenaScoreReset(arena, 0);
    arena->TotalScoreStructs = 0;
    arena->LastTimedGameTime = GetTickCount() / 0xA;
    arena->field_FF20 = 0;
    SoccerGameSomething(arena, -1);
}
// 41F1B0: using guessed type unsigned int __cdecl _filelength(unsigned int);
// 437B10: using guessed type int ArenaSpawnKeepScores;
// 4D45C0: using guessed type int CustomArenaMode;

//----- (00401590) --------------------------------------------------------
void __cdecl ShutdownArena(struct ARENA *arena)
{
    //struct ARENA *arena; // ebx@1
    int v2; // esi@1
    //struct PLAYER **v3; // eax@2
    int v4; // ecx@5
    //char *v5; // edx@6
    //int v6; // ecx@6
    //struct PLAYER *v7; // ecx@7
    unsigned char *v8; // eax@8
    void *v9; // eax@11
    //int v11; // eax@15
    //int v12; // edi@16
    //signed int v13; // ecx@16
    //bool v14; // zf@18
    //signed int v15; // ecx@19
    //const void *v16; // esi@19
    //char *v17; // edi@19
    //unsigned int v18; // edx@19
    //signed int v19; // ecx@19
    FILE *fileHandle; // eax@22
    char ArenaSaveFile[32]; // [sp+10h] [bp-20h]@16


    v2 = 0;
    if ( arena->ArenaPlayerCount > 0 )
    {
        do
        {
            if ( !arena->ServersideArenaSettings.MiscTimedGame )
            {
                if ( arena->HasScoreFile )
                {
                    if (arena->ArenaPlayers[v2]->MyArenaScoreIndex >= 0 ) //Can save this player's save, (must have old score).
                    {
                        arena->ScoreFilePointer[v4].Wins = arena->ArenaPlayers[v2]->CurrentWins;
                        arena->ScoreFilePointer[v4].Deaths = arena->ArenaPlayers[v2]->CurrentDeaths;
                        arena->ScoreFilePointer[v4].Goals = arena->ArenaPlayers[v2]->CurrentGoals;
                        arena->ScoreFilePointer[v4].KillPoints = arena->ArenaPlayers[v2]->KillPoints;
                        arena->ScoreFilePointer[v4].FlagPoints = arena->ArenaPlayers[v2]->FlagPoints;
                    }
                }
            }
            arena->ArenaPlayers[v2]->MyArena = 0;
            arena->ArenaPlayers[v2]->AlreadySentReliablePacket = 1;
            ++v2;
        }
        while ( v2 < arena->ArenaPlayerCount );
    }
    v8 = arena->MapData;
    if ( v8 && v8 != ServerMapData )
        FreeMemory(arena->MapData);
    v9 = arena->CompressedMap;
    if ( v9 && v9 != CompressedServerMap )
        FreeMemory(arena->CompressedMap);
    if ( arena->ScoreFilePointer ) //Can save arena scores to file.
    {
        arena->LastSaveStatsTime = GetTickCount() / 0xA;
        if ( arena->HasScoreFile )
        {
            strcpy(ArenaSaveFile, arena->ArenaName);
            strcat(ArenaSaveFile, ".scr");

            fileHandle = fopen(ArenaSaveFile, "wb");
            if ( fileHandle )
            {
                fwrite((const void *)arena->ScoreFilePointer, 0x12, arena->TotalNumScoresInFile, fileHandle);
                fclose(fileHandle);
            }
        }
        FreeMemory((LPVOID)arena->ScoreFilePointer);
    }
}

//----- (00401720) --------------------------------------------------------
void __cdecl DropBrick(struct ARENA *arena, signed int XTiles, signed int YTiles, short Team)
{
    //ARENA *arena; // esi@1
    int BrickResendCounter; // ebp@4
    //int v6; // ecx@4
    //int v7; // eax@4
    int v8; // ebx@5
    struct PLAYER **v9; // edi@6
    int v10; // ebx@11
    struct PLAYER **v11; // edi@12
    signed int Y2Tile; // [sp+10h] [bp-110h]@2
    int Y1Tile; // [sp+14h] [bp-10Ch]@2
    int X2Tile; // [sp+18h] [bp-108h]@2
    int X1Tile; // [sp+1Ch] [bp-104h]@2
    char buf[256]; // [sp+20h] [bp-100h]@4

    if ( arena->NumOfBricksInArena < 1024 )
    {
        DoBrickDrop(
            arena->MapData,
            XTiles,
            YTiles,
            &X1Tile,
            &Y1Tile,
            &X2Tile,
            &Y2Tile,
            arena->ServersideArenaSettings.BrickSpan);

        if ( X1Tile != X2Tile ||  Y1Tile != Y2Tile )
        {
            arena->Bricks[arena->NumOfBricksInArena].X1Tile = X1Tile;
            arena->Bricks[arena->NumOfBricksInArena].Y1Tile = Y1Tile;
            arena->Bricks[arena->NumOfBricksInArena].X2Tile = X2Tile;
            arena->Bricks[arena->NumOfBricksInArena].Y2Tile = Y2Tile;
            arena->Bricks[arena->NumOfBricksInArena].Team = Team;
            arena->Bricks[arena->NumOfBricksInArena].BrickId = arena->BrickIdCounter++;
            arena->Bricks[arena->NumOfBricksInArena].BrickTimeStamp = GetTickCount() / 0xA & 0x7FFFFFFF;

            buf[0] = 0x21; //0x21 - Brick Dropped
            *(unsigned short *)&buf[1] = *(unsigned short *)&arena->Bricks[arena->NumOfBricksInArena].X1Tile;
            *(unsigned short *)&buf[3] = *(unsigned short *)&arena->Bricks[arena->NumOfBricksInArena].Y1Tile;
            *(unsigned short *)&buf[5] = *(unsigned short *)&arena->Bricks[arena->NumOfBricksInArena].X2Tile;
            *(unsigned short *)&buf[7] = *(unsigned short *)&arena->Bricks[arena->NumOfBricksInArena].Y2Tile;
            *(unsigned short *)&buf[9] = *(unsigned short *)&arena->Bricks[arena->NumOfBricksInArena].Team;
            *(unsigned short *)&buf[11] = *(unsigned short *)&arena->Bricks[arena->NumOfBricksInArena].BrickId;
            *(unsigned int *)&buf[13] = arena->Bricks[arena->NumOfBricksInArena].BrickTimeStamp;

            BrickResendCounter = 0;

            if ( arena->ServersideArenaSettings.RoutingWallResendCount > 0 )
            {
                do
                {
                    SendArenaPacket(arena, buf, 0x11, 0); //non-reliable send with re-send spam
                    SendPacketsToEverybody(ServerPacketAttachment);
                    ++BrickResendCounter;
                }
                while ( BrickResendCounter < arena->ServersideArenaSettings.RoutingWallResendCount );
            }

            SendArenaPacket(arena, buf, 0x11, 1); //reliable send
            ++arena->NumOfBricksInArena;
        }
    }
}

//----- (00401920) --------------------------------------------------------
void __cdecl PlayerEntering(struct ARENA *arena, struct PLAYER *player)
{
    //struct ARENA *arena; // ebx@1
    //int v3; // esi@1
    //int v4; // edi@1
    //int v5; // edx@4
    bool IsStaffBoolean; // eax@5
    //int playerUserId; // edi@15
    int maxCounter; // eax@16
    //int scoreFileAddress; // edx@16
    int each_count; // esi@16
    struct SCORE *CurrentScore; // ecx@16
    //int v13; // eax@20
    //int v14; // edx@20
    //int v15; // eax@21
    //__int16 *v16; // edx@21
    //int v17; // ecx@21
    //__int16 *v18; // edi@23
    int each_score_count; // eax@23
    //int v20; // esi@23
    //int v21; // edx@24
    //char *v22; // ecx@25
    //signed int v23; // eax@32
    //int v24; // edi@32
    //int v25; // esi@36
    int v26; // ecx@37
    int v27; // edx@37
    //struct PLAYER **v28; // eax@38
    //int v29; // eax@46
    int v30; // eax@55
    //int v31; // esi@58
    char *v32; // ecx@58
    //char *v33; // eax@59
    int v34; // edx@59
    //__int16 v35; // di@60
    int flag_count; // edi@62
    //struct FLAG *v37; // esi@63
    //__int16 v38; // cx@66
    //__int16 v39; // dx@66
    char *ArenaPlayersPacketPointer; // esi@68
    //struct PLAYER **v41; // edx@70
    //struct PLAYER *v42; // edi@70
    //char v43; // al@70
    int v44; // ecx@71
    //int v45; // edx@72
    //char *v46; // eax@72
    //int v47; // ecx@78
    //bool v48; // sf@78
    //unsigned char v49; // of@78
    //int v50; // eax@81
    //struct PLAYER *v51; // eax@83
    //int v52; // edi@85
    //signed int v53; // ecx@85
    //char *v54; // esi@85
    //bool v55; // zf@85
    //__int16 v56; // ax@89
    //int v57; // ecx@90
    //int v58; // eax@91
    //unsigned int v59; // ecx@91
    //int v60; // edx@94
    //int v61; // eax@94
    //__int16 v62; // dx@94
    //__int16 v63; // cx@94
    //char v64; // al@94
    //__int16 v65; // dx@94
    //__int16 v66; // ax@94
    //int v67; // ecx@94
    //int v68; // edx@94
    //signed int v69; // ecx@96
    //char *v70; // edi@96
    //char *v71; // esi@96
    //bool v72; // zf@96
    //__int16 *result; // eax@101
    //int v74; // edx@101
    //int v75; // ecx@101
    //char *v76; // [sp-4h] [bp-5454h]@53
    char YouAreNowInGamePacket; // [sp+13h] [bp-543Dh]@94
    //struct PLAYER **v78; // [sp+14h] [bp-543Ch]@69
    int v79; // [sp+18h] [bp-5438h]@68
    //__int16 *v80; // [sp+1Ch] [bp-5434h]@14
    //const void *v81; // [sp+20h] [bp-5430h]@85
    char buffer1[16]; // [sp+24h] [bp-542Ch]@13
    char SyncRequestPacket[20]; // [sp+34h] [bp-541Ch]@94
    char MyEnteringPlayerPacket[64]; // [sp+48h] [bp-5408h]@94
    char MapInformationPacket[24]; // [sp+88h] [bp-53C8h]@91
    char BannerChangedPacket[99]; // [sp+A0h] [bp-53B0h]@89
    char EmptyBanner[96]; // [sp+104h] [bp-534Ch]@68
    char ArenaPlayersPacket[460]; // [sp+184h] [bp-52CCh]@68
    char buf[4096]; // [sp+350h] [bp-5100h]@58
    char BrickPacket[16640]; // [sp+1350h] [bp-4100h]@91

    if ( arena->HasScoreFile )
    {
        if ( arena->ServersideArenaSettings.OwnerUserId == -1 )
        {
            if ( !arena->ArenaPlayerCount )
            {
                if ( player->PlayerDataBillerPacket.UserId >= 0 )
                {
                    IsStaffBoolean = false;
                    switch ( CustomArenaMode )
                    {
                    case 2:
                        if ( player->IsModerator )
                            IsStaffBoolean = true;
                        break;
                    case 3:
                        if ( player->IsSuperModerator )
                            IsStaffBoolean = true;
                        break;
                    case 4:
                        if ( player->IsSysop )
                            IsStaffBoolean = true;
                        break;
                    case 1:
                        IsStaffBoolean = true;
                        break;
                    default:
                        break;
                    }
                    if ( IsStaffBoolean )
                    {
                        arena->ServersideArenaSettings.OwnerUserId = player->PlayerDataBillerPacket.UserId;
                        strcpy(arena->ServersideArenaSettings.OwnerName, player->PlayerDataBillerPacket.Name);
                        sprintf(buffer1, "%d", player->PlayerDataBillerPacket.UserId);
                        WritePrivateProfileStringA("Owner", "UserId", buffer1, arena->SettingsFilename);
                        WritePrivateProfileStringA("Owner", "Name", player->PlayerDataBillerPacket.Name, arena->SettingsFilename);
                    }
                }
            }
        }
    }

    player->LastCurrentWins = player->CurrentWins;
    player->LastCurrentDeaths = player->CurrentDeaths;
    player->LastGoalCount = player->CurrentGoals;
    player->LastKillPoints = player->KillPoints;
    player->LastFlagPoints = player->FlagPoints;

    arena->ArenaPlayers[arena->ArenaPlayerCount++] = player;
    player->MyArena = arena;
    *(unsigned int *)&player->PositionByteThree = 0;
    *(unsigned int *)&player->PingTimestamp = 0;
    *(unsigned int *)&player->YPixels = 0;
    *(unsigned int *)&player->XPixels = 0;
    *(unsigned int *)&player->Bounty = 0;
    player->WeaponsInfo = 0;
    player->Bounty = 10000;
    player->LastSecurityPacketReturnedTime = 0;
    player->SecurityWeaponCountyTotalNew = 0;
    player->SecurityWeaponCountTotal = 0;
    player->SecurityWeaponCount = 0;
    player->AttachedToPlayerId = -1;
    player->DebtKills = arena->ServersideArenaSettings.KillDebtKills;
    player->KotHDeathCount = 0;
    player->KingCrownKills = 0;
    player->MySoccerReward = 0;
    player->MyArenaScoreIndex = -1;
    if ( arena->HasScoreFile )
    {
        if ( player->PlayerDataBillerPacket.UserId >= 0 )
        {
            each_count = 0;

            //Check if UserId of entering player exists in the scores file.
            for ( CurrentScore = arena->ScoreFilePointer;
                    each_count < arena->TotalNumScoresInFile;
                    ++each_count )
            {
                if ( CurrentScore->UserId == player->PlayerDataBillerPacket.UserId )
                    break;
                ++CurrentScore;
            }

            if ( each_count == maxCounter )           // Hit Last Score in file, append to score file.
            {
                arena->TotalNumScoresInFile++;
                arena->ScoreFilePointer = (struct SCORE *)ExpandMemory(arena->ScoreFilePointer, sizeof(struct SCORE) * arena->TotalNumScoresInFile, 65536); //18 is total bytes of SCORE STRUCTURE.

                arena->ScoreFilePointer[each_count].UserId = player->PlayerDataBillerPacket.UserId;
                arena->ScoreFilePointer[each_count].Wins = 0;
                arena->ScoreFilePointer[each_count].Deaths = 0;
                arena->ScoreFilePointer[each_count].Goals = 0;
                arena->ScoreFilePointer[each_count].KillPoints = 0;
                arena->ScoreFilePointer[each_count].FlagPoints = 0;
            }

            player->MyArenaScoreIndex = each_count;
            player->CurrentWins = arena->ScoreFilePointer[each_count].Wins;
            player->CurrentDeaths = arena->ScoreFilePointer[each_count].Deaths;
            player->CurrentGoals = arena->ScoreFilePointer[each_count].Goals;
            player->KillPoints = arena->ScoreFilePointer[each_count].KillPoints;
            player->FlagPoints = arena->ScoreFilePointer[each_count].FlagPoints;

            player->PersonalBestWins = arena->ScoreFilePointer[each_count].Wins;
            player->PersonalBestGoalCount = arena->ScoreFilePointer[each_count].Goals;
        }
    }
    if ( arena->ServersideArenaSettings.MiscTimedGame > 0 )
    {
        player->CurrentWins = 0;
        player->CurrentDeaths = 0;
        player->KillPoints = 0;
        player->FlagPoints = 0;
        player->CurrentGoals = 0;

        each_score_count = 0;

        if ( player->PlayerDataBillerPacket.UserId >= 0 )
        {
            if ( arena->TotalScoreStructs > 0 )
            {
                //Check StructToScore until we find our player by UserId
                while ( arena->StructToScore[each_score_count].UserId != player->PlayerDataBillerPacket.UserId )
                {
                    ++each_score_count;
                    if ( each_score_count >= arena->TotalScoreStructs )
                        goto SCORE_NOT_FOUND;
                }

                player->CurrentWins = arena->StructToScore[each_score_count].Wins;
                player->CurrentDeaths = arena->StructToScore[each_score_count].Deaths;
                player->KillPoints = arena->StructToScore[each_score_count].KillPoints;
                player->FlagPoints = arena->StructToScore[each_score_count].FlagPoints;
                player->CurrentGoals = arena->StructToScore[each_score_count].Goals;
            }
SCORE_NOT_FOUND:
            if ( each_score_count == arena->TotalScoreStructs )
            {
                player->CurrentWins = 0;
                player->CurrentDeaths = 0;
                player->KillPoints = 0;
                player->FlagPoints = 0;
                player->CurrentGoals = 0;
            }
        }
    }

    if ( arena->ServersideArenaSettings.MiscMaxLossesToPlay > 0 && player->CurrentDeaths >= arena->ServersideArenaSettings.MiscMaxLossesToPlay )
        player->Ship = 8;
    if ( !player->IsModerator )
    {
        if ( arena->ServersideArenaSettings.MiscMaxPlaying > 0 )
        {
            v26 = 0;
            v27 = 0;
            if ( v26 > 0 )
            {
                do
                {
                    if ( arena->ArenaPlayers[v26]->Ship != 8 ) //Count Total players in a ship, not specced.
                        ++v27;
                    ++v26;
                }
                while ( v26 < arena->ArenaPlayerCount );
            }
            if ( v27 > arena->ServersideArenaSettings.MiscMaxPlaying )
                player->Ship = 8;
        }
    }
    if ( player->DemoPlayer )
    {
        if ( player->Ship == 5 || player->Ship == 6 || player->Ship == 4 || player->Ship == 7 )
            player->Ship = 8;
    }
    if ( arena->ArenaLocked )
        player->Ship = 8;

    if ( player->Ship == 8 )
    {
        printf("Player spectating game: %s\n", player->PlayerDataBillerPacket.Name);
        player->Frequency = arena->ServersideArenaSettings.TeamSpectatorFrequency;
    }
    else
    {
        printf("Player entering game: %s\n", player->PlayerDataBillerPacket.Name);
        player->Frequency = GetNextFrequencyToJoin(arena);
        if ( arena->ServersideArenaSettings.MiscFrequencyShipTypes )
            player->Ship = abs(player->Frequency) & 7;
    }
    SendPlayerReliablePacket(player, &arena->ArenaSettings, 0x594, 1);
    if ( arena->ServersideArenaSettings.FlagMode == 2 )
    {
        buf[0] = 0x22;                             // 0x22 - Turf Flag Update
        v32 = &buf[1];
        if ( arena->FlagCounter > 0 )
        {
            v34 = 0;
            do
            {   //Appends to packet ownerFreq's for each flag to 255 or up to 510 flags.
                *(unsigned short *)v32 = *(unsigned short *)&arena->Flags[v34].OwnerFreq;
                v32 += 2;
                ++v34;
            }
            while ( v34 < arena->FlagCounter );
        }
        SendPlayerReliablePacket(player, buf, 2 * arena->FlagCounter + 1, 1);
    } else {
        flag_count = 0;
        if ( arena->FlagCounter > 0 )
        {
            do
            {
                if ( arena->Flags[flag_count].CarrierPlayerId == -1 &&
                        arena->Flags[flag_count].XTile >= 0 &&
                        arena->Flags[flag_count].YTile >= 0 )
                {
                    buffer1[0] = 0x12; //0x12 - Flag Position
                    *(unsigned short *)&buffer1[1] = flag_count;
                    *(unsigned short *)&buffer1[3] = arena->Flags[flag_count].XTile;
                    *(unsigned short *)&buffer1[5] = arena->Flags[flag_count].YTile;
                    *(unsigned short *)&buffer1[7] = *(unsigned short*)arena->Flags[flag_count].OwnerFreq;
                    SendPlayerReliablePacket(player, buffer1, 9, 1);
                }
                ++flag_count;
            }
            while ( flag_count < arena->FlagCounter );
        }
    }
    memset(EmptyBanner, 0, sizeof(EmptyBanner)); //Zero banner data.

    if ( arena->ArenaPlayerCount > 0 )
    {
        v79 = 0;
        ArenaPlayersPacketPointer = ArenaPlayersPacket; //Start to pointer the ArenaPlayersPacket
        do
        {
            ArenaPlayersPacketPointer[0] = 0x03; //0x03 - Player Entering packet
            ArenaPlayersPacketPointer[1] = arena->ArenaPlayers[v79]->Ship;
            ArenaPlayersPacketPointer[2] = arena->ArenaPlayers[v79]->AllowAudioByte1;
            strncpy(&ArenaPlayersPacketPointer[3], arena->ArenaPlayers[v79]->PlayerDataBillerPacket.Name, 0x14);
            ArenaPlayersPacketPointer[22] = 0;
            strncpy(&ArenaPlayersPacketPointer[23], arena->ArenaPlayers[v79]->PlayerDataBillerPacket.Squad, 0x14);
            ArenaPlayersPacketPointer[42] = 0;
            *(unsigned int *)&ArenaPlayersPacketPointer[43] = arena->ArenaPlayers[v79]->KillPoints;
            *(unsigned int *)&ArenaPlayersPacketPointer[47] = arena->ArenaPlayers[v79]->FlagPoints;
            *(unsigned short *)&ArenaPlayersPacketPointer[51] = arena->ArenaPlayers[v79]->PlayerId;
            *(unsigned short *)&ArenaPlayersPacketPointer[53] = arena->ArenaPlayers[v79]->Frequency;
            *(unsigned short *)&ArenaPlayersPacketPointer[55] = arena->ArenaPlayers[v79]->CurrentWins;
            *(unsigned short *)&ArenaPlayersPacketPointer[57] = arena->ArenaPlayers[v79]->CurrentDeaths;
            *(unsigned short *)&ArenaPlayersPacketPointer[59] = arena->ArenaPlayers[v79]->AttachedToPlayerId;
            ArenaPlayersPacketPointer[63] = arena->ArenaPlayers[v79]->KotHDeathCount != 0;
            *(unsigned short *)&ArenaPlayersPacketPointer[61] = 0;                 // Flags Held

            if ( arena->ArenaSettings.CarryFlags )
            {
                if ( arena->FlagCounter > 0 )
                {
                    v44 = 0; //flag counter
                    do
                    {   //playerId matching going on here to, make a total flags held counter thingy for packet
                        if ( arena->Flags[v44].CarrierPlayerId == arena->ArenaPlayers[v79]->PlayerId )
                            ++*(unsigned short *)&ArenaPlayersPacketPointer[61];	                 // Flags Held
                        ++v44;
                    }
                    while ( v44 < arena->FlagCounter );
                }
            }
            ArenaPlayersPacketPointer += 64; //increase packet pointer offset's by 64, starts a new packet.
            if ( ArenaPlayersPacketPointer - ArenaPlayersPacket + 64 > 460) //packet limit over 460 bytes, send packet
            {
                SendPlayerReliablePacket(player, ArenaPlayersPacket, ArenaPlayersPacketPointer - ArenaPlayersPacket, 1);
                ArenaPlayersPacketPointer = ArenaPlayersPacket; //Start a new packet with zero'd offset.
            }
            v79++;
        }
        while ( v79 < arena->ArenaPlayerCount );

        //Any remaining packet(s) from above less then 460 in size, send it now
        if ( ArenaPlayersPacketPointer != ArenaPlayersPacket )
            SendPlayerReliablePacket(player, ArenaPlayersPacket, ArenaPlayersPacketPointer - ArenaPlayersPacket, 1);
    }

    if ( arena->ArenaPlayerCount > 0 )
    {
        v79 = 0;
        do
        {
            if ( arena->ArenaPlayers[v79]->FlagPoints + arena->ArenaPlayers[v79]->KillPoints >= arena->ServersideArenaSettings.MiscBannerPoints || arena->ArenaPlayers[v79]->ForceWearBanner )
            {
                //TODO: Trying to understand this seems EmptyBanner always is empty banner.
                //So it checks against your banner to see if it's not empty then it sends it.
                if ( !memicmp(arena->ArenaPlayers[v79]->PlayerDataBillerPacket.BannerData, EmptyBanner, 0x60) )
                {
                    BannerChangedPacket[0] = 0x1F;                       // 0x1F - Player Banner Changed
                    *(unsigned short *)&BannerChangedPacket[1] = arena->ArenaPlayers[v79]->PlayerId;
                    memcpy(&BannerChangedPacket[3], arena->ArenaPlayers[v79]->PlayerDataBillerPacket.BannerData, 0x60);
                    SendPlayerReliablePacket(player, BannerChangedPacket, 0x63, 1);
                }
            }
            v79++;
        }
        while ( v79 < arena->ArenaPlayerCount );
    }

    //Creates a possible huge packet with all bricks x 16 bytes per brick any length.
    BrickPacket[0] = 0x21;                               // 0x21 - Brick Dropped
    memcpy(&BrickPacket[1], arena->Bricks, sizeof(struct BRICK) * arena->NumOfBricksInArena);
    SendPlayerReliablePacket(player, BrickPacket, (sizeof(struct BRICK) * arena->NumOfBricksInArena) + 1, 1);

    //Send Map Checksum to check if need a New Map Download
    MapInformationPacket[0] = 0x29;                               // 0x29 - Map Information
    strcpy(&MapInformationPacket[1], arena->MapFilename);
    *(unsigned int *)&MapInformationPacket[17] = arena->MapChecksum;
    SendPlayerReliablePacket(player, MapInformationPacket, 0x15, 1);

    if ( AdvertiseSendMode == 3 || AdvertiseSendMode == 1 )
        SendAdvertisement(player, true);

    //This packet probably starts drawing my ship in game
    YouAreNowInGamePacket = 2;
    SendPlayerReliablePacket(player, &YouAreNowInGamePacket, 1, 1);

    player->XPixels = -9999;
    player->YPixels = -9999;
    SyncRequestPacket[0] = 0x18; //0x18 - Synchronization Request
    *(unsigned int *)&SyncRequestPacket[1] = arena->PrizeSeedValue;
    *(unsigned int *)&SyncRequestPacket[5] = arena->DoorSeedValue;
    *(unsigned int *)&SyncRequestPacket[9] = arena->SynchronizationTimeStamp;
    *(unsigned int *)&SyncRequestPacket[13] = 0;
    SendPlayerReliablePacket(player, SyncRequestPacket, 17, 1);

    //Show myself to everybody
    MyEnteringPlayerPacket[0] = 0x03; //0x03 - Player(s) Entering
    MyEnteringPlayerPacket[1] = player->Ship;
    MyEnteringPlayerPacket[2] = player->AllowAudioByte1;
    *(unsigned short *)&MyEnteringPlayerPacket[51] = player->PlayerId;
    *(unsigned short *)&MyEnteringPlayerPacket[53] = player->Frequency;
    *(unsigned short *)&MyEnteringPlayerPacket[57] = player->CurrentDeaths;
    *(unsigned short *)&MyEnteringPlayerPacket[59] = player->AttachedToPlayerId;
    *(unsigned short *)&MyEnteringPlayerPacket[55] = player->CurrentWins;
    *(unsigned short *)&MyEnteringPlayerPacket[57] = player->CurrentDeaths;
    *(unsigned int *)&MyEnteringPlayerPacket[43] = player->KillPoints;
    *(unsigned int *)&MyEnteringPlayerPacket[47] = player->FlagPoints;
    *(unsigned short *)&MyEnteringPlayerPacket[61] = 0;
    strncpy(&MyEnteringPlayerPacket[3], player->PlayerDataBillerPacket.Name, 0x14);
    MyEnteringPlayerPacket[22] = 0;
    strncpy(&MyEnteringPlayerPacket[23], player->PlayerDataBillerPacket.Squad, 0x14);
    MyEnteringPlayerPacket[42] = 0;
    SendEverybodyButYourself(player, MyEnteringPlayerPacket, 0x40, 1);

    //Wear my banner to everybody
    if ( player->KillPoints + player->FlagPoints >= arena->ServersideArenaSettings.MiscBannerPoints || player->ForceWearBanner )
    {
        if ( !memicmp(player->PlayerDataBillerPacket.BannerData, EmptyBanner, 0x60) )
        {
            BannerChangedPacket[0] = 0x1F;                           // 0x1F - Player Banner Changed
            *(unsigned short *)&BannerChangedPacket[1] = player->PlayerId;
            memcpy(&BannerChangedPacket[3], player->PlayerDataBillerPacket.BannerData, 0x60);
            SendEverybodyButYourself(player, BannerChangedPacket, 0x63, 1);
        }
    }
    player->WinsSomething = player->CurrentWins;
    player->DeathsSomething = player->CurrentDeaths;
    player->GoalsSomething = player->CurrentGoals;
    player->KillPointsSomething = player->KillPoints;
    player->FlagPointsSomething = player->FlagPoints;
}
// 4314B0: using guessed type int AdvertiseSendMode;
// 4D45C0: using guessed type int CustomArenaMode;

//----- (004022D0) --------------------------------------------------------
void __cdecl PlayerLeaveArena(struct ARENA *arena, struct PLAYER *player)
{
    int v4; // eax@1
    int v5; // ecx@1
    int v6; // ecx@5
    int v7; // eax@5
    char *v8; // edi@5
    struct PLAYER *v9; // ecx@5
    char *v10; // edx@6
    int v11; // ecx@10
    //int v12; // edx@11
    int v13; // eax@11
    char *v14; // ecx@12
    //int v15; // eax@17
    //bool v16; // zf@17
    //int v17; // edi@18
    //int v18; // edx@19
    signed int v19; // eax@19
    //struct SCORE *v20; // ecx@20
    //int v21; // eax@27
    //int v22; // eax@31
    //int v23; // edx@32
    //int v24; // eax@34
    struct PLAYER *v25; // eax@35
    int v26; // edi@38
    //int v27; // eax@38
    //struct PLAYER **v28; // ebp@39
    //char *v29; // ecx@44
    //char *v30; // ebx@44

    char buffer[3]; //fix

    UpdatePowerBallPositions(player);
    v4 = player->field_50;
    v5 = player->field_54;
    player->MyArena = 0;
    if ( (v4 >= 0 && v4 < 8) && (v5 >= 0 && v5 < 8)  )
    {
        v6 = 251 * (v5 + 8 * v4);
        v7 = 0;
        v8 = (char *)arena + 4 * v6;
        v9 = arena->PlayerPointers[v6 + 250];
        if ( (signed int)v9 > 0 )
        {
            v10 = v8;
            while ( *(struct PLAYER **)v10 != player )
            {
                ++v7;
                v10 += 4;
                if ( v7 >= v9 ) //TODO: defintely some kind of integers here not PLAYER pointers.
                    goto LABEL_11;
            }
            v11 = (int)((char *)v9 - 1);
            *((unsigned int *)v8 + 250) = v11;
            *(unsigned int *)&v8[4 * v7] = *(unsigned int *)&v8[4 * v11];
        }
    }
LABEL_11:
    if ( arena->ArenaPlayerCount > 0 )
    {
        v13 = 0;
        while ( arena->ArenaPlayers[v13] != player )
        {
            ++v13;
            if ( v13 >= arena->ArenaPlayerCount )
                goto PLAYER_NOT_FOUND;
        }
        //can easily be replaced with memmove (this was probably it's original method).
        memcpy(
            &arena->ArenaPlayers[v13],
            &arena->ArenaPlayers[v13 + 1],
            sizeof(arena->ArenaPlayers) * (arena->ArenaPlayerCount - v13 - 1));
        arena->ArenaPlayerCount--;
    }
PLAYER_NOT_FOUND:
    if ( arena->ServersideArenaSettings.MiscTimedGame > 0 )
    {
        if ( player->PlayerDataBillerPacket.UserId >= 0 )
        {
            v19 = 0;
            if ( arena->TotalScoreStructs > 0 )
            {
                while ( arena->StructToScore[v19].UserId != player->PlayerDataBillerPacket.UserId )
                {
                    ++v19;
                    if ( v19 >= arena->TotalScoreStructs )
                        goto LABEL_25;
                }
                arena->StructToScore[v19].Wins = player->CurrentWins;
                arena->StructToScore[v19].Deaths = player->CurrentDeaths;
                arena->StructToScore[v19].Goals = player->CurrentGoals;
                arena->StructToScore[v19].KillPoints = player->KillPoints;
                arena->StructToScore[v19].FlagPoints = player->FlagPoints;
            }
LABEL_25:
            if ( v19 == arena->TotalScoreStructs && v19 < 1000 ) //Proves ScoreStruct Array is less then 1000 indexes
            {
                arena->StructToScore[v19].UserId = player->PlayerDataBillerPacket.UserId;
                arena->StructToScore[v19].Wins = player->CurrentWins;
                arena->StructToScore[v19].Deaths = player->CurrentDeaths;
                arena->StructToScore[v19].Goals = player->CurrentGoals;
                arena->StructToScore[v19].KillPoints = player->KillPoints;
                arena->StructToScore[v19].FlagPoints = player->FlagPoints;
                ++arena->TotalScoreStructs;
            }
        }
    }
    if ( arena->ServersideArenaSettings.MiscTimedGame == 0 )
    {
        if ( arena->HasScoreFile )
        {
            if ( player->MyArenaScoreIndex >= 0 )
            {
                arena->ScoreFilePointer[player->MyArenaScoreIndex].Wins = player->CurrentWins;
                arena->ScoreFilePointer[player->MyArenaScoreIndex].Deaths = player->CurrentDeaths;
                arena->ScoreFilePointer[player->MyArenaScoreIndex].Goals = player->CurrentGoals;
                arena->ScoreFilePointer[player->MyArenaScoreIndex].KillPoints = player->KillPoints;
                arena->ScoreFilePointer[player->MyArenaScoreIndex].FlagPoints = player->FlagPoints;
            }
        }
    }
    if ( player->IsSysop )
    {
        if ( player->ArenaPlayerIndex >= 0 )
        {
            v25 = ZonePlayerList[player->ArenaPlayerIndex];
            *(unsigned short *)&buffer[0] = 0x1C; 	//0x1C - Put Player in Spectator Mode
            if ( v25 )
                SendPlayerReliablePacket(v25, buffer, 2, 1);
        }
    }
    if ( ZonePlayerCount > 0 )
    {

        buffer[0] = 0x04;                      //0x04 - Player Leaving
        *(unsigned short *)&buffer[1] = player->PlayerId;
        SendArenaPacket(arena, buffer, 3, 1);
    }
    CarryFlagsSomething(arena, player->PlayerId, 0);
    if ( !arena->RecordPointsToLog )
    {
        player->CurrentWins = player->LastCurrentWins;
        player->CurrentDeaths = player->LastCurrentDeaths;
        player->CurrentGoals = player->LastGoalCount;
        player->KillPoints = player->LastKillPoints;
        player->FlagPoints = player->LastFlagPoints;
    }
}

//----- (00402560) --------------------------------------------------------
bool __cdecl ProcessArena(struct ARENA *arena)
{
    int v3; // esi@3
    __int64 v4; // qax@3
    unsigned int v5; // ecx@7
    char *v6; // edi@7
    char *v7; // esi@7
    bool v8; // zf@7
    int v9; // edi@11
    struct PLAYER **v10; // esi@12
    __int64 v12; // qax@19
    int v13; // edi@22
    signed int v14; // ecx@22
    signed int v15; // ecx@25
    const void *v16; // esi@25
    char *v17; // edi@25
    unsigned int v18; // edx@25
    signed int v19; // ecx@25
    FILE *v20; // eax@28
    FILE *v21; // esi@28
    __int64 v22; // qax@31
    struct ARENA *v23; // eax@36
    unsigned int v24; // kr20_4@39
    int v25; // edi@39
    struct PLAYER **v26; // ebx@40
    bool v27; // sf@45
    unsigned char v28; // of@45
    int v29; // esi@47
    char *v30; // ecx@47
    char *v31; // eax@48
    int v32; // edx@48
    __int16 v33; // di@49
    unsigned int v34; // ebx@50
    int v35; // esi@50
    struct PLAYER **v36; // edi@51
    __int64 v37; // qax@56
    int v38; // edx@58
    int v39; // eax@59
    int v40; // ebx@62
    struct PLAYER **v41; // esi@63
    unsigned int v42; // kr04_4@65
    struct PLAYER *v43; // eax@65
    int v44; // eax@73
    int v45; // esi@74
    int v46; // eax@76
    int v47; // edx@77
    int v48; // ecx@77
    char *v49; // eax@77
    signed int v50; // ebx@77
    signed int v51; // edx@77
    int v52; // esi@78
    int v53; // edi@80
    struct PLAYER **v54; // esi@81
    int v55; // esi@86
    int v56; // esi@86
    int v57; // edx@86
    int v58; // esi@86
    int v59; // ecx@86
    int v60; // eax@86
    struct PLAYER **v61; // edi@87
    __int64 v62; // qax@91
    __int64 v63; // qax@94
    int v64; // eax@97
    int v65; // esi@97
    struct PLAYER **v66; // ebx@98
    int v67; // edi@102
    struct PLAYER **v68; // esi@103
    struct PLAYER *v69; // eax@104
    int v70; // ebx@106
    signed int v71; // ecx@106
    signed int v72; // eax@106
    signed int v73; // edi@106
    char *v74; // edx@107
    int v75; // esi@107
    struct PLAYER *v76; // eax@108
    signed int v77; // ecx@117
    int v78; // esi@119
    int v79; // eax@119
    struct PLAYER **v80; // ebx@120
    struct PLAYER *v81; // ebx@125
    int v82; // esi@126
    struct PLAYER *v83; // eax@127
    struct PLAYER **v84; // edi@128
    int v85; // esi@132
    struct PLAYER **v86; // edi@133
    int v87; // esi@137
    int v88; // eax@138
    __int64 v89; // qax@139
    int v90; // edi@141
    int *v91; // ebx@142
    int v92; // esi@142
    int v93; // edx@143
    int v94; // eax@144
    int *v95; // ecx@145
    int v96; // ecx@151
    struct PLAYER *v97; // eax@152
    signed int v98; // edx@159
    int v99; // eax@159
    char *v100; // ebx@166
    signed int v101; // esi@168
    int v102; // eax@169
    int v103; // ecx@169
    int v104; // ebx@170
    signed int v105; // ecx@170
    signed int v106; // edi@170
    int v107; // ecx@171
    struct PLAYER **v108; // ebx@174
    struct PLAYER *v109; // eax@175
    int v110; // esi@178
    int v111; // edi@185
    struct PLAYER **v112; // esi@186
    signed int v113; // ebx@194
    int v114; // eax@195
    struct PLAYER *v115; // eax@196
    int v116; // edi@197
    signed int v117; // ecx@197
    char *v118; // edx@198
    struct PLAYER *v119; // eax@200
    int v120; // edx@206
    char *v121; // eax@206
    int j; // ecx@208
    int v123; // ecx@216
    int v124; // esi@216
    struct PLAYER *v125; // eax@217
    int v126; // eax@221
    unsigned int v127; // eax@225
    signed int v128; // ecx@225
    int v129; // eax@225
    int v130; // ebx@225
    signed int v131; // esi@226
    struct PLAYER *v132; // ecx@227
    int v133; // edx@227
    int v134; // eax@228
    int v135; // edi@236
    struct PLAYER **v136; // esi@237
    int v137; // ebx@241
    struct PLAYER **v138; // esi@242
    struct PLAYER *v139; // eax@243
    int v140; // edi@246
    int v141; // eax@248
    int v142; // ecx@249
    int v143; // eax@249
    __int64 v144; // qax@259
    __int64 v145; // qax@262
    unsigned int v146; // kr10_4@263
    int v147; // eax@263
    int v148; // edx@263
    int *v149; // ebx@265
    int v150; // edi@265
    int v151; // esi@266
    signed int v152; // eax@267
    int *v153; // ecx@268
    struct PLAYER *v154; // eax@275
    int v155; // ecx@275
    int v156; // ebx@281
    char *v157; // edi@281
    int v158; // eax@282
    int v159; // esi@282
    int v160; // esi@283
    int *v161; // eax@286
    char *v162; // edi@286
    signed __int16 v163; // cx@286
    struct PLAYER **v164; // ebx@289
    struct PLAYER *v165; // eax@290
    int v166; // edi@293
    int v167; // ebx@300
    struct PLAYER **v168; // esi@301
    __int64 v169; // qax@307
    signed int v170; // eax@307
    int v171; // esi@308
    struct PLAYER **v172; // edi@309
    int v173; // eax@314
    int v174; // esi@314
    struct PLAYER **v175; // edi@315
    int v176; // esi@321
    struct PLAYER **v177; // edi@322
    int v178; // esi@325
    int v179; // eax@325
    int v180; // esi@330
    struct PLAYER **v181; // edi@331
    int v182; // esi@333
    unsigned int v183; // eax@333
    struct PLAYER *v184; // esi@334
    int v185; // edi@334
    signed int v186; // ecx@334
    char *v187; // edx@334
    int v188; // eax@336
    int v189; // ebx@339
    struct PLAYER **v190; // esi@340
    struct PLAYER *v191; // eax@341
    int v192; // ecx@343
    int v193; // eax@343
    int v194; // eax@344
    int v195; // ecx@345
    int v196; // edx@345
    int v197; // eax@355
    int v198; // esi@355
    struct PLAYER **v199; // edi@356
    int v200; // esi@361
    struct PLAYER **v201; // edi@362
    int v202; // esi@365
    void *v203; // ebx@365
    const void *v204; // edi@365
    int v205; // edx@367
    int v206; // ecx@368
    int v207; // esi@370
    struct SOCCER_BALL *soccerball; // ebx@370
    struct PLAYER *v209; // eax@374
    int v210; // esi@376
    int v211; // eax@376
    char v212; // dl@376
    struct PLAYER **v213; // edi@377
    int v214; // ecx@381
    struct ARENA **v215; // [sp+4h] [bp-27DCh]@35
    signed int v216; // [sp+4h] [bp-27DCh]@106
    int v217; // [sp+4h] [bp-27DCh]@124
    char *v218; // [sp+4h] [bp-27DCh]@142
    int v219; // [sp+4h] [bp-27DCh]@166
    int v220; // [sp+4h] [bp-27DCh]@364
    int *v221; // [sp+8h] [bp-27D8h]@167
    signed int v222; // [sp+8h] [bp-27D8h]@194
    signed int v223; // [sp+8h] [bp-27D8h]@264
    char *v224; // [sp+8h] [bp-27D8h]@365
    int v225; // [sp+Ch] [bp-27D4h]@34
    int v226; // [sp+Ch] [bp-27D4h]@119
    int v227; // [sp+Ch] [bp-27D4h]@142
    char *v228; // [sp+Ch] [bp-27D4h]@166
    int *v229; // [sp+Ch] [bp-27D4h]@265
    int v230; // [sp+Ch] [bp-27D4h]@288
    char *v231; // [sp+Ch] [bp-27D4h]@334
    int v232; // [sp+10h] [bp-27D0h]@173
    int v233; // [sp+10h] [bp-27D0h]@265
    int v234; // [sp+10h] [bp-27D0h]@288
    int v235; // [sp+10h] [bp-27D0h]@369
    char SoundByte; // [sp+14h] [bp-27CCh]@124
    int SoundBytea; // [sp+14h] [bp-27CCh]@141
    char *SoundByteb; // [sp+14h] [bp-27CCh]@265
    char a3[8]; // [sp+18h] [bp-27C8h]@97
    int i; // [sp+20h] [bp-27C0h]@159
    char buf[38]; // [sp+24h] [bp-27BCh]@22
    char PacketBuffer[1428]; // [sp+4Ch] [bp-2794h]@7
    int v243[384]; // [sp+5E0h] [bp-2200h]@149
    int v244[384]; // [sp+BE0h] [bp-1C00h]@142
    int FreqList[384]; // [sp+11E0h] [bp-1600h]@145
    char v246[512]; // [sp+17E0h] [bp-1000h]@47

    unsigned int pointsToGive;

    if ( arena->ArenaRecycling )
        return 1;
    v3 = -1;
    if ( (GetTickCount() / 0xA - arena->LastArenaSettingsUpdateTime) > 6000 || arena->NeedSettingsUpdate )
    {
        arena->LastArenaSettingsUpdateTime = GetTickCount() / 0xA;
        if ( IsFileLastWrittenTime(arena->SettingsFilename, &arena->LastSettingsWrittenTime) || arena->NeedSettingsUpdate )
        {
            arena->NeedSettingsUpdate = 0;
            memcpy(PacketBuffer, &arena->ArenaSettings, 0x594);
            LoadArenaSettings(arena);
            //Checks if arena settings have changed or not.
            if ( !memicmp(PacketBuffer, (char *)&arena->ArenaSettings, 0x594) ) {
                printf("Parameters resent for arena(%s)\n", arena->ArenaName);
                SendArenaPacket(arena, &arena->ArenaSettings, 0x594, 1);
                arena->SettingsChecksum = 0;
                arena->MapLVLChecksum = 0;
                v3 = -1;
            } else {
                v3 = -1;
            }
        }
        v12 = (GetTickCount() / 0xA - arena->LastSaveStatsTime);
        if ( (GetTickCount() / 0xA - arena->LastSaveStatsTime) > arena->ServersideArenaSettings.CustomSaveStatsTime )
        {
            if ( arena->ScoreFilePointer )
            {
                arena->LastSaveStatsTime = GetTickCount() / 0xA;
                if ( arena->HasScoreFile )
                {
                    strcpy(buf, arena->ArenaName);
                    strcat(buf, ".scr");

                    v20 = fopen(buf, "wb");
                    if ( v20 )
                    {
                        fwrite((const void *)arena->ScoreFilePointer, 0x12, arena->TotalNumScoresInFile, v20);
                        fclose(v20);
                    }
                    v3 = -1;
                }
            }
        }
        if ( (GetTickCount() / 0xA - arena->LastCheckArenaEmptyTime) > 60000 )
        {
            if ( arena->ArenaPlayerCount < ArenaMinimumPlayers )
            {
                if ( !arena->ArenaName[0] )
                {
                    v225 = 0;
                    if ( ArenaArrayLength > 0 )
                    {
                        v215 = Arenas;
                        do
                        {
                            v23 = *v215;
                            if ( *v215 == arena )
                                break;
                            if ( v23->ArenaPlayerCount < ArenaDesiredPlayers && !v23->ArenaName[0] )
                            {
                                PacketBuffer[0] = 7;
                                PacketBuffer[1] = 0;
                                PacketBuffer[2] = 2;
                                *(unsigned short *)&PacketBuffer[3] = 0;
                                strcpy(&PacketBuffer[5], "Long range scanners indicate enemy activity in another quadrant, type ?GO to warp.");
                                v24 = strlen("Long range scanners indicate enemy activity in another quadrant, type ?GO to warp.");
                                v25 = 0;
                                SendArenaPacket(arena, PacketBuffer, v24 + 6, 1);
                                arena->LastCheckArenaEmptyTime = GetTickCount() / 0xA;
                                v3 = -1;
                            }
                            v225++;
                            ++v215;
                        }
                        while ( v225 < ArenaArrayLength );
                    }
                }
            }
        }
        if ( arena->ServersideArenaSettings.FlagMode == 2 )
        {
            v246[0] = 0x22;                          // 0x22 - Turf Flag Update
            v30 = &v246[1];
            if ( arena->FlagCounter > 0 )
            {
                v32 = 0;
                do
                {   //Appends to packet ownerFreq's ofr each flag to 255 or up to 510 flags.
                    *(unsigned short *)v30  = *(unsigned short *)&arena->Flags[v32].OwnerFreq;
                    v30 += 2;
                    ++v32;
                }
                while ( v32 < arena->FlagCounter );
            }
            SendArenaPacket(arena, v246, 2 * arena->FlagCounter + 1, 1);
        }
        else
        {
            if ( (GetTickCount() / 0xA - arena->field_FF4E) > 12000 )
            {
                if ( arena->FlagCounter < arena->TotalFlags )
                {
                    do
                    {
                        arena->Flags[arena->FlagCounter].XTile = -1;
                        arena->Flags[arena->FlagCounter].YTile = -1;
                        arena->Flags[arena->FlagCounter].CarrierPlayerId = -1;
                        arena->Flags[arena->FlagCounter].OwnerFreq = -1;
                        arena->FlagCounter++;
                    }
                    while ( arena->FlagCounter < arena->TotalFlags );
                }
                if ( arena->FlagCounter > arena->TotalFlags )
                    arena->FlagCounter = arena->TotalFlags;
            }
            FlagPositionUpdateSomething(arena, 1);
        }
        v40 = 0;
        if ( arena->ArenaPlayerCount > 0 )
        {
            v41 = (struct PLAYER **)arena->ArenaPlayers;
            do
            {
                if ( (*v41)->LastSecurityPacketReturnedTime )
                {
                    v43 = *v41;
                    if ( (GetTickCount() / 0xA - (*v41)->LastSecurityPacketReturnedTime) > 5000 && !v43->IsSuperModerator )
                    {
                        if ( arena->ServersideArenaSettings.dwordB4 )
                        {
                            WriteSubGameLog("Player kicked off for not returning security packet: %s\n", v43->PlayerName);
                            (*v41)->DisconnectReason = 13;
                            (*v41)->AlreadySentReliablePacket = 1;
                        }
                        if ( GetBillingServerRelOut((*v41)->connection, 0) < 3 )
                        {
                            sprintf(
                                PacketBuffer,
                                "WARNING: Security checksum not returned {st=%d,et=%d}",
                                (*v41)->LastSecurityPacketReturnedTime,
                                GetTickCount() / 0xA);
                            SendBillerWarnings(PacketBuffer, *v41);
                        }
                    }
                    (*v41)->LastSecurityPacketReturnedTime = 0;
                }
                ++v40;
                ++v41;
            }
            while ( v40 < arena->ArenaPlayerCount );
        }
        if ( arena->TotalSoccerBalls != arena->ServersideArenaSettings.SoccerBallCount )
        {
            arena->TotalSoccerBalls = arena->ServersideArenaSettings.SoccerBallCount;
            for ( v45 = 0; v45 < arena->TotalSoccerBalls; ++v45 )
                CreateSoccerBall(arena, v45);
        }
        if ( arena->SecurityChecksumCounterOddValue++ & 1 ) //only works every other time, lol.
        {
            v48 = 0; //Computed ArenaSettings Checksum value
            v49 = (char *)&arena->ArenaSettings;
            arena->RandomScrtyDataIndex = rand() % 500; // Random value from Scrty File
            v50 = *(unsigned int *)&Security[0].ScrtyData[8 * arena->RandomScrtyDataIndex];
            v51 = 357; //Number of Checksum rounds / Total ArenaSettings values?
            do
            {
                v52 = *(unsigned int *)v49;
                v49 += 4;
                v48 += v50 ^ v52;
                --v51;
            }
            while ( v51 );
            arena->SettingsChecksum = v48;
            arena->MapLVLChecksum = GenerateLVLChecksum(arena->MapData, v50);
            if ( v50 )
            {
                v53 = 0;
                if ( arena->ArenaPlayerCount > 0 )
                {
                    v54 = (struct PLAYER **)arena->ArenaPlayers;
                    do
                    {
                        if ( !(*v54)->AlreadySentReliablePacket && !(*v54)->field_309 )
                            (*v54)->LastSecurityPacketReturnedTime = GetTickCount() / 0xA;
                        ++v53;
                        ++v54;
                    }
                    while ( v53 < arena->ArenaPlayerCount );
                }
            }

            arena->DoorSeedValue = rand() * rand();
            arena->PrizeSeedValue = rand() * rand();
            arena->SynchronizationTimeStamp = GetTickCount() / 0xA & 0x7FFFFFFF;

            buf[0] = 0x18;                           // 0x18 - Synchronization Request
            *(unsigned int *)&buf[1] = arena->PrizeSeedValue;
            *(unsigned int *)&buf[5] = arena->DoorSeedValue;
            *(unsigned int *)&buf[9] = arena->SynchronizationTimeStamp;
            *(unsigned int *)&buf[13] = v50;

            SendArenaPacket(arena, buf, 0x11, 1);
        }
    }

    if ( (GetTickCount() / 0xA - arena->LastKotHTimer) > 200 )
    {
        arena->LastKotHTimer = GetTickCount() / 0xA;
        if ( arena->ServersideArenaSettings.KingDeathCount > 0 )
        {
            if ( arena->LastKotHGameResetCheckTime )
            {
                if ( (GetTickCount() / 0xA - arena->LastKotHGameResetCheckTime) > 12000 )
                {
                    if ( arena->ArenaPlayerCount > 2 )
                    {
                        arena->LastKotHGameResetCheckTime = 0;
                        a3[0] = 0x2C;                      // 0x2C - KotH Game Reset
                        a3[1] = 1;
                        *(unsigned int *)&a3[2] = arena->ServersideArenaSettings.KingExpireTime;
                        *(unsigned short *)&a3[6] = -1;
                        SendArenaPacket(arena, a3, 8, 1);

                        if ( arena->ArenaPlayerCount > 0 )
                        {
                            v67 = 0;
                            do
                            {
                                v69 = arena->ArenaPlayers[v67];
                                SendArenaMessage(v69, "King of the Hill restarted", 103);
                                v69->KotHDeathCount = arena->ServersideArenaSettings.KingDeathCount;
                                ++v67;
                            }
                            while ( v67 < arena->ArenaPlayerCount );
                        }
                        arena->field_1001A = arena->ArenaPlayerCount
                                             * arena->ArenaPlayerCount
                                             * arena->ServersideArenaSettings.KingRewardFactor
                                             / 1000;
                    }
                    else
                    {
                        arena->LastKotHGameResetCheckTime = GetTickCount() / 0xA;
                    }
                }
            }
            else
            {
                v71 = -1;
                v72 = 0;
                v73 = 1;
                v216 = 0;
                if ( arena->ArenaPlayerCount > 0 )
                {
                    v75 = 0;
                    do
                    {
                        v76 = arena->ArenaPlayers[v75];
                        if ( v76->KotHDeathCount > 0 )
                        {
                            if ( v71 == -1 )
                                v71 = v76->Frequency;
                            if ( v76->Frequency == v71 )
                                ++v216;
                            else
                                v73 = 0;
                        }
                        ++v75;
                    }
                    while ( v75 < arena->ArenaPlayerCount );
                    v72 = v216;
                }
                if ( v73 )
                {
                    v77 = v72;
                    if ( v72 <= 1 )
                        v77 = 1;
                    v79 = arena->field_1001A / v77;
                    a3[0] = 0x2C;                        // 0x2C - KotH Game Reset
                    a3[1] = 0;
                    *(unsigned short *)&a3[6] = -1;
                    v226 = v79;
                    SendArenaPacket(arena, a3, 8, 1);

                    SoundByte = 103; // Victory bell
                    arena->LastKotHGameResetCheckTime = GetTickCount() / 0xA;

                    if ( arena->ArenaPlayerCount > 0 )
                    {
                        v217 = 0;
                        do
                        {
                            v81 = arena->ArenaPlayers[v217];
                            if ( v81->KotHDeathCount > 0 )
                            {
                                v81->KotHDeathCount = 0;
                                v81->FlagPoints += v226;

                                buf[0] = 9;                     // 0x09 - Player Score Update
                                *(unsigned short *)&buf[1] = v81->PlayerId;// PlayerId WORD
                                *(unsigned int *)&buf[3] = v81->KillPoints;// Kill Points DWORD
                                *(unsigned int *)&buf[7] = v81->FlagPoints;// Flag Points DWORD
                                *(unsigned short *)&buf[11] = v81->CurrentWins;// Wins WORD
                                *(unsigned short *)&buf[13] = v81->CurrentDeaths;// Losses WORD
                                SendArenaPacket(arena, buf, 0xF, 1);

                                sprintf(PacketBuffer, "King of the Hill: %s given %d points", v81->PlayerDataBillerPacket.Name, v226);
                                v85 = 0;

                                if ( arena->ArenaPlayerCount > 0 )
                                {
                                    v86 = (struct PLAYER **)arena->ArenaPlayers;
                                    do
                                    {
                                        SendArenaMessage(*v86, PacketBuffer, SoundByte);
                                        ++v85;
                                        ++v86;
                                    }
                                    while ( v85 < arena->ArenaPlayerCount );
                                }
                                SoundByte = 0;
                            }
                            ++v217;
                        }
                        while ( v217 < arena->ArenaPlayerCount );
                    }
                }
            }
        }
        if ( arena->FlagCounter <= 0 )
        {
LABEL_306:
            if ( arena->GameTimeStart > 0 )
            {
                v170 = arena->GameTimeStart - (GetTickCount() / 0xA - arena->GameTimePassed);
                if ( v170 > 0 )
                {
                    if ( v170 >= 6000 || arena->field_FF56 >= 2 )
                    {
                        if ( (v170 > 29000 && v170 < 30000) && arena->field_FF56 < 1 )
                        {
                            arena->field_FF56 = 1;
                            if ( arena->ArenaPlayerCount > 0 )
                            {
                                v176 = 0;
                                v177 = (struct PLAYER **)arena->ArenaPlayers;
                                do
                                {
                                    SendArenaMessage(*v177, "NOTICE: 5 minutes remaining.", 0);
                                    ++v176;
                                    ++v177;
                                }
                                while ( v176 < arena->ArenaPlayerCount );
                            }
                        }
                    }
                    else
                    {
                        arena->field_FF56 = 2;
                        if ( arena->ArenaPlayerCount > 0 )
                        {
                            v174 = 0;
                            v175 = (struct PLAYER **)arena->ArenaPlayers;
                            do
                            {
                                SendArenaMessage(*v175, "NOTICE: 1 minute remaining.", 0);
                                ++v174;
                                ++v175;
                            }
                            while ( v174 < arena->ArenaPlayerCount );
                        }
                    }
                }
                else
                {
                    if ( arena->ArenaPlayerCount > 0 )
                    {
                        v171 = 0;
                        v172 = (struct PLAYER **)arena->ArenaPlayers;
                        do
                        {
                            SendArenaMessage(*v172, "NOTICE: Game over", 5);
                            ++v171;
                            ++v172;
                        }
                        while ( v171 < arena->ArenaPlayerCount );
                    }
                    arena->GameTimeStart = 0;
                    arena->field_FF56 = 0;
                }
            }
            if ( arena->ServersideArenaSettings.MiscTimedGame > 0 )
            {
                v179 = arena->ServersideArenaSettings.MiscTimedGame - abs(GetTickCount() / 0xA - arena->LastTimedGameTime);
                if ( arena->LastTimedGameTime != 0 )
                    v179 = -1;
                if ( v179 > 0 )
                {
                    if ( v179 >= 6000 || arena->field_FF20 >= 2 )
                    {
                        if ( v179 < 30000 && arena->field_FF20 < 1 )
                        {
                            arena->field_FF20 = 1;
                            if ( arena->ArenaPlayerCount > 0 )
                            {
                                v200 = 0;
                                v201 = (struct PLAYER **)arena->ArenaPlayers;
                                do
                                {
                                    SendArenaMessage(*v201, "NOTICE: 5 minutes remaining in current game.", 0);
                                    ++v200;
                                    ++v201;
                                }
                                while ( v200 < arena->ArenaPlayerCount );
                            }
                        }
                    }
                    else
                    {
                        arena->field_FF20 = 2;
                        if ( arena->ArenaPlayerCount > 0 )
                        {
                            v198 = 0;
                            v199 = (struct PLAYER **)arena->ArenaPlayers;
                            do
                            {
                                SendArenaMessage(
                                    *v199,
                                    "NOTICE: 1 minute remaining in current game.",
                                    arena->ArenaSettings.VictoryMusic != 0 ? 0x64 : 0);
                                ++v198;
                                ++v199;
                            }
                            while ( v198 < arena->ArenaPlayerCount );
                        }
                    }
                }
                else
                {
                    if ( arena->ServersideArenaSettings.SoccerCapturePoints && arena->ServersideArenaSettings.SoccerBallCount )
                    {
                        GetScore(arena, 0);
                        if ( arena->ArenaPlayerCount > 0 )
                        {
                            v180 = 0;
                            v181 = (struct PLAYER **)arena->ArenaPlayers;
                            do
                            {
                                SendArenaMessage(*v181, "Soccer game over.", 103);
                                ++v180;
                                ++v181;
                            }
                            while ( v180 < arena->ArenaPlayerCount );
                        }
                        ArenaScoreReset(arena, 1);
                        v182 = 0;
                        arena->TotalScoreStructs = 0;
                    }
                    else
                    {
                        qsort(
                            arena->ArenaPlayers,
                            arena->ArenaPlayerCount,
                            4u,
                            (int (__cdecl *)(const void *, const void *))PtFuncCompare);

                        buf[0] = 0x24;                     // 0x24 - Speed Game Over
                        v187 = &buf[28]; //Id's 1-5
                        v231 = &buf[8]; //Score's 1-5
                        v186 = 0;
                        do
                        {
                            v184 = arena->ArenaPlayers[v186];
                            if ( v186 >= arena->ArenaPlayerCount )
                            {
                                *(unsigned short *)&v187[v186] = -1; //Id's = -1 not enough players in the game
                            }
                            else
                            {
                                *(unsigned short *)&v187[v186] = v184->PlayerId;
                                *(unsigned int *)&v231[v186] = v184->FlagPoints + v184->KillPoints;
                            }
                            ++v186;
                        }
                        while ( v186 < 5 ); //TOP 5.

                        if ( arena->ArenaPlayerCount > 0 )
                        {
                            v189 = 0;
                            do
                            {
                                v191 = arena->ArenaPlayers[v189];
                                *(unsigned int *)&buf[4] = v191->FlagPoints + v191->KillPoints; //Your Score
                                *(unsigned short *)&buf[2] = v189 + 1;
                                if ( v191->PersonalBestKillPoints + v191->PersonalBestFlagPoints >= *(unsigned int *)&buf[4] )
                                {
                                    buf[1] = 0;
                                }
                                else
                                {
                                    if ( arena->ArenaPlayerCount > 10 )
                                    {
                                        buf[1] = 1;

                                        v191->PersonalBestWins = v191->CurrentWins;
                                        v191->PersonalBestLosses = v191->CurrentDeaths;
                                        v191->PersonalBestGoalCount =  v191->CurrentGoals;
                                        v191->PersonalBestKillPoints =  v191->KillPoints;
                                        v191->PersonalBestFlagPoints =  v191->FlagPoints;

                                        if ( arena->HasScoreFile )
                                        {
                                            if ( v191->MyArenaScoreIndex >= 0 )
                                            {
                                                v196 = v191->MyArenaScoreIndex;
                                                arena->ScoreFilePointer[v196].Wins = v191->PersonalBestWins;
                                                arena->ScoreFilePointer[v196].Deaths = v191->PersonalBestLosses;
                                                arena->ScoreFilePointer[v196].Goals = v191->PersonalBestGoalCount;
                                                arena->ScoreFilePointer[v196].KillPoints = v191->PersonalBestKillPoints;
                                                arena->ScoreFilePointer[v196].FlagPoints = v191->PersonalBestFlagPoints;
                                            }
                                        }
                                        else
                                        {
                                            if ( BillingConnectionStructPointer && arena->RecordPointsToLog )
                                                SendBillerUserScorePacket(
                                                    BillingConnectionStructPointer,
                                                    v191->BillerPlayerId,
                                                    &v191->PersonalBestWins,
                                                    0xE);
                                        }
                                    }
                                }
                                SendPlayerReliablePacket(v191, buf, 0x26, 1);
                                ++v189;
                            }
                            while ( v189 < arena->ArenaPlayerCount );
                        }
                        v182 = 0;
                        ArenaScoreReset(arena, 0);
                        arena->TotalScoreStructs = 0;
                    }
                    arena->LastTimedGameTime = GetTickCount() / 0xA;
                    arena->field_FF20 = v182;
                    SoccerGameSomething(arena, -1);
                }
            }

            if ( arena->NumOfBricksInArena > 0 )
            {
                v220 = 0;
                do
                {
                    if ( (GetTickCount() / 0xA - arena->Bricks[v220].BrickTimeStamp) > arena->ArenaSettings.BrickTime )
                    {
                        memcpy(&arena->Bricks[v220],
                               &arena->Bricks[v220 + 1],
                               sizeof(struct BRICK) * (arena->NumOfBricksInArena + -v220)
                              );
                        arena->NumOfBricksInArena--;
                    }
                }
                while ( v220 < arena->NumOfBricksInArena );
            }
            goto LABEL_369;
        }
        if ( arena->ServersideArenaSettings.FlagMode == 2 )
        {
            if ( (GetTickCount() / 0xA - arena->LastTerritoryRewardTime) > arena->ServersideArenaSettings.TerritoryRewardDelay )
            {
                arena->LastTerritoryRewardTime = GetTickCount() / 0xA;
                if ( arena->ArenaPlayerCount >= 16 )
                {
                    v90 = 0;
                    SoundBytea = 0;
                    if ( arena->FlagCounter > 0 )
                    {
                        v91 = v244;
                        v218 = (char *)&arena->Flags[0].OwnerFreq;
                        v92 = 0;
                        v227 = arena->FlagCounter;
                        do
                        {
                            v93 = *(unsigned int *)v218;
                            if ( *(unsigned int *)v218 >= 0 )
                            {
                                v94 = 0;
                                if ( v92 > 0 )
                                {
                                    v95 = FreqList;
                                    while ( *v95 != v93 )
                                    {
                                        ++v94;
                                        ++v95;
                                        if ( v94 >= v90 )
                                            goto LABEL_150;
                                    }
                                    ++v243[v94];
                                }
LABEL_150:
                                if ( v94 == v90 )
                                {
                                    FreqList[v92] = v93;
                                    v243[v92] = 1;
                                    *v91 = 0;
                                    if ( arena->ArenaPlayerCount > 0 )
                                    {
                                        v96 = 0;
                                        do
                                        {
                                            v97 = arena->ArenaPlayers[v96];
                                            if ( v97->Frequency == v93 )
                                                ++*v91;
                                            ++v96;
                                        }
                                        while ( v96 < arena->ArenaPlayerCount );
                                        v90 = SoundBytea;
                                    }
                                    ++v90;
                                    ++v92;
                                    SoundBytea = v90;
                                    ++v91;
                                }
                            }
                            v8 = v227 == 1;
                            v218 += 16;
                            --v227;
                        }
                        while ( !v8 );
                    }
                    v98 = 0;
                    v99 = 0;
                    i = 0;
                    if ( v90 > 0 )
                    {
                        do
                        {
                            if ( v244[v99] >= arena->ServersideArenaSettings.TerritoryRewardMinimumPlayers
                                    && v243[v99] >= arena->ServersideArenaSettings.TerritoryRewardBaseFlags )
                                ++v98;
                            ++v99;
                        }
                        while ( v99 < v90 );
                        i = v98;
                    }
                    if ( v98 > 1 )
                    {
                        PacketBuffer[0] = 0x23;                      // 0x23 - Flag Reward Granted
                        v100 = &PacketBuffer[1];
                        v228 = &PacketBuffer[1];
                        v219 = 0;
                        if ( v90 > 0 )
                        {
                            v221 = FreqList;
                            do
                            {
                                if ( v244[v219] >= arena->ServersideArenaSettings.TerritoryRewardMinimumPlayers )
                                {
                                    v102 = v243[v219];
                                    v103 = arena->ServersideArenaSettings.TerritoryRewardBaseFlags;
                                    if ( v102 >= v103 )
                                    {
                                        v105 = arena->ArenaPlayerCount
                                               * arena->ServersideArenaSettings.TerritoryRewardPoints
                                               * (unsigned int)((char *)i - 1)
                                               * (v102 - v103);
                                        v106 = v105 / 50 / v244[v219];
                                        if ( v106 > 0 )
                                        {
                                            *(unsigned short *)v228 = *(unsigned short *)v221;
                                            v107 = v105 / 50 / v244[v219];
                                            if ( v106 >= 30000 )
                                                v107 = 30000;
                                            *((unsigned short *)v228 + 1) = v107;
                                            v228 += 4;
                                            if ( arena->ArenaPlayerCount > 0 )
                                            {
                                                v232 = 0;
                                                *(unsigned int *)a3 = *v221;
                                                do
                                                {
                                                    v109 = arena->ArenaPlayers[v232];
                                                    if ( arena->ArenaPlayers[v232]->Frequency == *(unsigned int *)a3 )
                                                    {
                                                        if ( v109->Ship != 8 )
                                                        {
                                                            if ( !(v109->ShipTogglables & 0x20) ) // Not In Safety
                                                            {
                                                                v110 = v109->KillPoints + v109->FlagPoints;
                                                                AppendPointsLog(v109, 0, v106);
                                                                if ( v110 < AutoPermissionPoints )
                                                                {
                                                                    if ( AutoPermissionPoints > 0
                                                                            && arena->ArenaPlayers[v232]->KillPoints + arena->ArenaPlayers[v232]->FlagPoints >= AutoPermissionPoints )
                                                                        SendArenaMessage(arena->ArenaPlayers[v232], PermissionAutoPermissionMessage, 0);
                                                                }
                                                            }
                                                        }
                                                    }
                                                    ++v232;
                                                }
                                                while ( v232 < arena->ArenaPlayerCount );
                                            }
                                        }
                                    }
                                }
                                v219++;
                                ++v221;
                            }
                            while ( v219 < SoundBytea );
                            v100 = v228;
                        }
                        SendArenaPacket(arena, PacketBuffer, v100 - PacketBuffer, 1);
                        dword_4C8F3C = 0;
                    }
                }
            }
            goto LABEL_261;
        }
        if ( arena->ServersideArenaSettings.FlagMode && arena->ServersideArenaSettings.FlagMode != 1 || arena->ServersideArenaSettings.FlagReward <= 0 )
        {
LABEL_261:
            if ( arena->ServersideArenaSettings.PeriodicRewardDelay > 0 )
            {
                if ( (GetTickCount() / 0xA - arena->LastPeriodicRewardTime) > arena->ServersideArenaSettings.PeriodicRewardDelay )
                {
                    arena->LastPeriodicRewardTime = GetTickCount() / 0xA;
                    if ( arena->ArenaPlayerCount > arena->ServersideArenaSettings.PeriodicRewardMinimumPlayers )
                    {
                        v223 = 0;
                        if ( arena->FlagCounter > 0 )
                        {
                            v149 = FreqList;
                            v229 = FreqList;
                            v150 = 0;
                            v233 = 0;
                            do
                            {
                                v151 = arena->Flags[v233].OwnerFreq;
                                if ( arena->Flags[v233].OwnerFreq >= 0 )
                                {
                                    v152 = 0;
                                    if ( v150 > 0 )
                                    {
                                        v153 = v244;
                                        while ( *v153 != v151 )
                                        {
                                            ++v152;
                                            ++v153;
                                            if ( v152 >= v223 )
                                                goto LABEL_273;
                                        }
                                        ++v243[v152];
                                    }
LABEL_273:
                                    if ( v152 == v223 )
                                    {
                                        v244[v150] = v151;
                                        v243[v150] = 1;
                                        *v149 = 0;
                                        if ( arena->ArenaPlayerCount > 0 )
                                        {
                                            v155 = 0;
                                            do
                                            {
                                                v154 = arena->ArenaPlayers[v155];
                                                v149 = v229;
                                                if ( v154->Frequency == v151 )
                                                    ++*v229;
                                                ++v155;
                                            }
                                            while ( v155 < arena->ArenaPlayerCount );
                                        }
                                        ++v150;
                                        ++v149;
                                        ++v223;
                                        v229 = v149;
                                    }
                                }
                                ++v233;
                            }
                            while ( v233 < arena->FlagCounter );
                        }
                        v156 = 0;
                        PacketBuffer[0] = 0x23;     //0x23 - Flag Reward Granted
                        v157 = &PacketBuffer[1];
                        for ( i = 0; v156 < v223; i = v156 )
                        {
                            v158 = arena->ServersideArenaSettings.PeriodicRewardPoints;
                            v159 = v243[v156];
                            if ( v158 <= 0 )
                                v160 = -(arena->ArenaPlayerCount * v158 * v159);
                            else
                                v160 = v158 * v159;
                            if ( v160 > 0 )
                            {
                                v161 = &v244[v156];
                                *(unsigned short *)v157 = LOWORD(v244[v156]);
                                v162 = v157 + 2;
                                v163 = v160;
                                if ( v160 >= 30000 )
                                    v163 = 30000;
                                *(unsigned short *)v162 = v163;
                                v157 = (char *)(v162 + 2);
                                v234 = 0;
                                if ( arena->ArenaPlayerCount > 0 )
                                {
                                    *(unsigned int *)a3 = *v161;
                                    do
                                    {
                                        if ( arena->ArenaPlayers[v234]->Frequency == *(unsigned int *)a3 )
                                        {
                                            if ( arena->ArenaPlayers[v234]->Ship != 8 )
                                            {
                                                if ( !(arena->ArenaPlayers[v234]->ShipTogglables & 0x20) ) //Not in Safety
                                                {
                                                    v166 = arena->ArenaPlayers[v234]->KillPoints + arena->ArenaPlayers[v234]->FlagPoints;
                                                    AppendPointsLog(arena->ArenaPlayers[v234], 0, v160);
                                                    if ( v166 < AutoPermissionPoints )
                                                    {
                                                        if ( AutoPermissionPoints > 0
                                                                && arena->ArenaPlayers[v234]->KillPoints + arena->ArenaPlayers[v234]->FlagPoints >= AutoPermissionPoints )
                                                            SendArenaMessage(arena->ArenaPlayers[v234], PermissionAutoPermissionMessage, 0);
                                                    }
                                                }
                                            }
                                        }
                                        ++v234;
                                    }
                                    while ( v234 < arena->ArenaPlayerCount );
                                    v156 = i;
                                }
                            }
                            ++v156;
                        }
                        SendArenaPacket(arena, PacketBuffer, v157 - PacketBuffer, 1);
                        dword_4C8F3C = 0;
                    }
                }
            }
            goto LABEL_306;
        }
        v113 = -1;
        if ( arena->ServersideArenaSettings.FlagMode )
        {
            //TODO: Why is the first flag's freq so important?
            if ( arena->ServersideArenaSettings.FlagMode != 1 || (arena->Flags[0].OwnerFreq < 0) || arena->Flags[0].CarrierPlayerId != -1 )
                goto LABEL_215;

            for ( j = 0; j < arena->FlagCounter; ++j )
            {
                if ( arena->Flags[j].CarrierPlayerId != -1 )
                    break;
                if ( arena->Flags[j].OwnerFreq != arena->Flags[0].OwnerFreq )
                    break;
            }

            if ( j != arena->FlagCounter )
                goto LABEL_215;
            v113 = *(unsigned int *)&arena->Flags[0].OwnerFreq;
        }
        else
        {
            v114 = arena->Flags[0].CarrierPlayerId;
            if ( v114 < 0 || (v115 = ZonePlayerList[v114]) == 0 )
                goto LABEL_215;
            v117 = 1;
            if ( arena->FlagCounter > 1 )
            {
                do
                {
                    v114 = arena->Flags[v117].CarrierPlayerId;
                    if ( v114 < 0 )
                        break;
                    v119 = ZonePlayerList[v114];
                    if ( !v119 )
                        break;
                    if ( v119->Frequency != v115->Frequency )
                        break;
                    ++v117;
                }
                while ( v117 < arena->FlagCounter );
            }
            if ( v117 != arena->FlagCounter )
                goto LABEL_215;
            v113 = v115->Frequency;
        }
LABEL_215:
        if ( v113 >= 0 )
        {
            v124 = 0; //Get number of players not in spec. (Playing)
            if ( arena->ArenaPlayerCount > 0 )
            {
                v123 = 0;
                do
                {
                    v125 = arena->ArenaPlayers[v123];
                    if ( v125->Ship != 8 )
                        ++v124;
                    ++v123;
                }
                while ( v123 < arena->ArenaPlayerCount );
            }
            arena->FlagCounter = 0;
            if ( arena->ServersideArenaSettings.RandomFlags && arena->ServersideArenaSettings.MaxFlags > 0 )
                arena->TotalFlags = rand() % arena->ServersideArenaSettings.MaxFlags + 1;
            else
                arena->TotalFlags = arena->ServersideArenaSettings.MaxFlags;
            v128 = arena->ServersideArenaSettings.FlagReward * v124 * v124;
            a3[0] = 0x14;                            // 0x14 - Flag Victory
            *(unsigned short *)&a3[1] = v113;
            arena->LastFlagResetTime = GetTickCount() / 0xA;
            v129 = arena->ServersideArenaSettings.FlagRewardMode;
            v130 = arena->ArenaJackpot + v128 / 1000;
            arena->ArenaJackpot = 0;
            pointsToGive = v130;
            *(unsigned int *)&a3[3] = v130;

            if ( v129 == 1 )
            {
                v131 = 0;
                if ( arena->ArenaPlayerCount > 0 )
                {
                    v133 = 0;
                    do
                    {
                        v132 = arena->ArenaPlayers[v133];
                        if ( v132->Frequency == v113 //Same frequency as winning flags.
                                && v132->Ship != 8 //Not ship 8 (Spec)
                                && !(v132->ShipTogglables & 0x20) ) //NOT in Safety (In safe)
                            ++v131; //Count of winning players.
                        ++v133; //Next player.
                    }
                    while ( v133 < arena->ArenaPlayerCount );
                }
                if ( v131 <= ((unsigned int)arena->ArenaSettings.MaxPerTeam / 2) )
                    v131 = (unsigned int)arena->ArenaSettings.MaxPerTeam / 2;
                pointsToGive = arena->ArenaSettings.MaxPerTeam * v130 / v131;
                *(unsigned int *)&a3[3] = pointsToGive;
            }
            SendArenaPacket(arena, a3, 7, 1);

            v137 = 0;
            if ( arena->ArenaPlayerCount > 0 ) //Scoring goals.
            {
                do
                {
                    if ( arena->ArenaPlayers[v137]->Frequency == v113
                            && arena->ArenaPlayers[v137]->Ship != 8
                            && !(arena->ArenaPlayers[v137]->ShipTogglables & 0x20) )
                    {
                        v140 = arena->ArenaPlayers[v137]->KillPoints + arena->ArenaPlayers[v137]->FlagPoints;
                        AppendPointsLog(arena->ArenaPlayers[v137], 0, pointsToGive);
                        ++arena->ArenaPlayers[v137]->CurrentGoals;
                        if ( !arena->ServersideArenaSettings.MiscTimedGame )
                        {
                            if ( arena->HasScoreFile )
                            {
                                v141 = arena->ArenaPlayers[v137]->MyArenaScoreIndex;
                                if ( v141 >= 0 )
                                {
                                    arena->ScoreFilePointer[v141].Wins = arena->ArenaPlayers[v137]->CurrentWins;
                                    arena->ScoreFilePointer[v141].Deaths = arena->ArenaPlayers[v137]->CurrentDeaths;
                                    arena->ScoreFilePointer[v141].Goals = arena->ArenaPlayers[v137]->CurrentGoals;
                                    arena->ScoreFilePointer[v141].KillPoints = arena->ArenaPlayers[v137]->KillPoints;
                                    arena->ScoreFilePointer[v141].FlagPoints = arena->ArenaPlayers[v137]->FlagPoints;
                                }
                            }
                            else
                            {
                                if ( BillingConnectionStructPointer && arena->RecordPointsToLog )
                                    SendBillerUserScorePacket(
                                        BillingConnectionStructPointer,
                                        arena->ArenaPlayers[v137]->BillerPlayerId,
                                        &arena->ArenaPlayers[v137]->CurrentWins,
                                        0x0E);
                            }
                        }
                        if ( v140 < AutoPermissionPoints
                                && AutoPermissionPoints > 0
                                && arena->ArenaPlayers[v137]->KillPoints + arena->ArenaPlayers[v137]->FlagPoints >= AutoPermissionPoints )
                            SendArenaMessage(arena->ArenaPlayers[v137], PermissionAutoPermissionMessage, 0);
                    }
                    ++v137;
                }
                while ( v137 < arena->ArenaPlayerCount );
            }
            dword_4C8F3C = 0;
        }
        if ( (GetTickCount() / 0xA - arena->LastFlagResetTime) > arena->ServersideArenaSettings.FlagResetDelay )
            ResetJackpotFlags(arena);
        goto LABEL_261;
    }
LABEL_369:
    v235 = 0;
    if ( arena->TotalSoccerBalls > 0 )
    {
        do
        {
            if ( abs(GetTickCount() / 0xA - arena->SoccerBallTimers[v235]) > arena->ServersideArenaSettings.SoccerSendTime )
            {
                if ( !arena->SoccerBalls[v235].StartTimeDelay )
                {
                    if ( arena->SoccerBalls[v235].PlayerId >= 0 )
                    {
                        if ( ZonePlayerList[arena->SoccerBalls[v235].PlayerId] )
                        {
                            arena->SoccerBalls[v235].XPixels = ZonePlayerList[arena->SoccerBalls[v235].PlayerId]->XPixels;
                            arena->SoccerBalls[v235].YPixels = ZonePlayerList[arena->SoccerBalls[v235].PlayerId]->YPixels;
                        }
                    }
                }
                arena->SoccerBallTimers[v235] = GetTickCount() / 0xA;
                buf[0] = 0x2E;                         // 0x2E - Power-Ball Position Update
                buf[1] = *(unsigned char *)&arena->SoccerBalls[v235].PowerBallId;
                *(unsigned short *)&buf[2] = *(unsigned short *)&arena->SoccerBalls[v235].XPixels;
                *(unsigned short *)&buf[4] = *(unsigned short *)&arena->SoccerBalls[v235].YPixels;
                *(unsigned short *)&buf[6] = *(unsigned short *)&arena->SoccerBalls[v235].XVelocity;
                *(unsigned short *)&buf[8] = *(unsigned short *)&arena->SoccerBalls[v235].YVelocity;
                *(unsigned short *)&buf[10] = *(unsigned short *)&arena->SoccerBalls[v235].PlayerId;
                *(unsigned int *)&buf[12] = *(unsigned int *)&arena->SoccerBalls[v235].StartTimeDelay;

                SendArenaPacket(arena, buf, 0x10, 0);
            }
            v235++;
        }
        while ( v235 < arena->TotalSoccerBalls  );
    }
    return arena->ArenaPlayerCount == 0;
}
// 4043C0: using guessed type int __cdecl ResetJackpotFlags(unsigned int);
// 431FF4: using guessed type int ArenaArrayLength;
// 431FFC: using guessed type int ArenaMinimumPlayers;
// 4AF32C: using guessed type int AutoPermissionPoints;
// 4C8F3C: using guessed type int dword_4C8F3C;
// 4D5928: using guessed type int ArenaDesiredPlayers;
// 402560: using guessed type int var_1C00[384];
// 402560: using guessed type int var_1600[384];
// 402560: using guessed type int var_2200[384];

//----- (00403F60) --------------------------------------------------------
int __cdecl PtFuncCompare(struct PLAYER **player, struct ARENA *arena)
{
//PlayerPointers[] array is unknown what the hell it is ATM, might have players... but it's not *THE* playerList!
    return arena->PlayerPointers[0]->KillPoints  // Guess just showing PLAYER** Matches with ARENA *
           + arena->PlayerPointers[0]->FlagPoints // Guess just showing PLAYER** Matches with ARENA *
           - (*player)->KillPoints
           - (*player)->FlagPoints;
}
//----- (00403F90) --------------------------------------------------------
void __cdecl ArenaScoreReset(struct ARENA *arena, bool BooleanSendScoreReset)
{
    //struct ARENA *arena; // esi@1
    int v2; // eax@1
    int v3; // ecx@1
    struct PLAYER **v4; // eax@2
    struct PLAYER *v5; // edx@3
    int v6; // eax@5
    int v7; // ebp@5
    struct PLAYER **v8; // ebx@6
    char buffer[4]; // [sp+14h] [bp+4h]@0

    v3 = 0;
    if ( arena->ArenaPlayerCount > 0 )
    {
        do
        {
            arena->ArenaPlayers[v3]->DebtKills = arena->ServersideArenaSettings.KillDebtKills;
            arena->ArenaPlayers[v3]->CurrentDeaths = 0;
            arena->ArenaPlayers[v3]->CurrentWins = 0;
            arena->ArenaPlayers[v3]->KillPoints = 0;
            arena->ArenaPlayers[v3]->FlagPoints = 0;
            arena->ArenaPlayers[v3]->CurrentGoals = 0;
            ++v3;
        }
        while ( v3 < arena->ArenaPlayerCount );
    }
    if ( BooleanSendScoreReset )
    {
        buffer[0] = 0x1A; 	//0x1A - Reset Score(s)
        *(unsigned short *)&buffer[1] = -1; //-1 means reset for everybody.

        SendArenaPacket(arena, buffer, 3, 1);
    }
}

//----- (00404050) --------------------------------------------------------
void __cdecl CreateSoccerBall(struct ARENA *arena, int PowerBallId)
{
    //struct ARENA *arena; // edi@1
    signed int v3; // eax@1
    short v4; // cx@3
    int v5; // esi@3
    short v6; // ax@3
    signed long v7; // qax@3
    int a2; // [sp+Ch] [bp-8h]@3
    int a3; // [sp+10h] [bp-4h]@3

    v3 = arena->ArenaSettings.PrizeMinimumVirtual + arena->ArenaSettings.PrizeUpgradeVirtual * arena->ArenaPlayerCount;
    if ( v3 >= 1024 )
        v3 = 1024;
    SpawnOnMap(arena, &a2, &a3, 512, 512, v3 / 2);

    //TODO: why even have a PowerBallId member if it's the array index?
    //I guess when it's not in array form and you want to move it around and still know Id.

    arena->SoccerBalls[PowerBallId].PowerBallId = PowerBallId;
    arena->SoccerBalls[PowerBallId].XPixels = 16 * a2;
    arena->SoccerBalls[PowerBallId].YPixels = 16 * a3;
    arena->SoccerBalls[PowerBallId].XVelocity = 0;
    arena->SoccerBalls[PowerBallId].YVelocity = 0;
    arena->SoccerBalls[PowerBallId].PlayerId = -1;
    arena->SoccerBalls[PowerBallId].StartTimeDelay = GetTickCount() / 0xA;
    arena->SoccerBallTimers[PowerBallId] = 0;
}

//----- (00404120) --------------------------------------------------------
void __cdecl FlagPositionUpdateSomething(struct ARENA *arena, int a2)
{
    //struct ARENA *arena; // edi@1
    struct FLAG *each_flag; // esi@2
    int v4; // ebx@3
    int v5; // eax@4
    int v6; // eax@7
    signed int v7; // eax@16
    __int16 v8; // cx@20
    __int16 v9; // dx@20
    int v10; // eax@20
    int v11; // ebp@20
    struct PLAYER **v12; // ebx@21
    int v13; // [sp-1Ch] [bp-30h]@15
    int v14; // [sp-18h] [bp-2Ch]@15
    int v15; // [sp-14h] [bp-28h]@15
    int v16; // [sp-10h] [bp-24h]@15
    int v17; // [sp+4h] [bp-10h]@1
    char buf[12]; // [sp+8h] [bp-Ch]@20

    v17 = 0;
    if ( arena->FlagCounter > 0 )
    {
        each_flag = arena->Flags;
        do
        {
            v6 = each_flag->XTile < 0 || (each_flag->YTile < 0) || each_flag->XTile >= 1024 || each_flag->YTile >= 1024;
            if ( each_flag->CarrierPlayerId == -1 && (a2 || v6) )
            {
                if ( v6 )
                {
                    if ( each_flag->XTile != -1 && arena->ServersideArenaSettings.FlagTerritoryRadius ) {
                        v16 = arena->ServersideArenaSettings.FlagTerritoryRadius;
                        v15 = abs(each_flag->YTile);
                        v14 = abs(each_flag->XTile);
                    } else {
                        v7 = arena->ArenaSettings.PrizeMinimumVirtual
                             + arena->ArenaSettings.PrizeUpgradeVirtual * arena->ArenaPlayerCount;
                        if ( v7 >= 1024 )
                            v7 = 1024;
                        v16 = v7 / 2;
                        v15 = 512;
                        v14 = 512;
                    }
                    SpawnOnMap(arena, &each_flag->XTile, &each_flag->YTile, v14, v15, v16);
                }
                buf[0] = 0x12;                         // 0x12 - Flag Position
                *(unsigned short *)&buf[1] = v17;                // Flag ID
                *(unsigned short *)&buf[3] = each_flag->XTile;                 // X Tiles
                *(unsigned short *)&buf[5] = each_flag->YTile;                 // Y Tiles
                *(unsigned short *)&buf[7] = each_flag->OwnerFreq;// Owner Frequency

                SendArenaPacket(arena, buf, 9, 1);
            }
            ++each_flag;
            ++v17;
        }
        while ( v17 < arena->FlagCounter );
    }
}

//----- (00404280) --------------------------------------------------------
void __cdecl CarryFlagsSomething(struct ARENA *arena, int a2, int a3)
{
    int v3; // ebx@1
    //struct ARENA *arena; // edi@1
    struct PLAYER *v5; // ecx@3
    int v6; // esi@3
    int v7; // eax@3
    int v8; // ebp@4
    int v9; // ebx@4
    int v10; // eax@6
    bool v11; // sf@8
    unsigned char v12; // of@8
    int v13; // edx@12
    int v14; // eax@17
    int v15; // edx@18
    int v16; // ecx@19
    int v17; // [sp+10h] [bp-4h]@5
    int v18; // [sp+10h] [bp-4h]@11

    v3 = a2;

    if ( a2 >= 0 && arena->ArenaSettings.CarryFlags )
    {
        v5 = ZonePlayerList[a2];
        v6 = -1;
        v7 = -1;
        if ( v5 )
        {
            v8 = v5->XPixels / 16;
            v9 = v5->YPixels / 16;
            if ( arena->ServersideArenaSettings.FlagTerritoryRadiusCentroid )
            {
                v17 = 0;
                while ( 1 )
                {
                    v10 = 2 * rand() % arena->ServersideArenaSettings.FlagTerritoryRadiusCentroid
                          - arena->ServersideArenaSettings.FlagTerritoryRadiusCentroid;
                    if ( (v10 + v8) > 1 && (v10 + v8) < 1024 )
                        break;

                    if(v17++ < 50) //50 attempts to get it right.
                        goto LABEL_11;
                }
                v8 += v10;
LABEL_11:
                v18 = 0;
                while ( 1 )
                {
                    v13 = rand() % (2 * arena->ServersideArenaSettings.FlagTerritoryRadiusCentroid)
                          - arena->ServersideArenaSettings.FlagTerritoryRadiusCentroid;
                    if ( (v13 + v9) > 1 && (v13 + v9) < 1024 )
                        break;

                    if(v18++ < 50) //50 attempts to get it right..
                        goto LABEL_17;
                }
                v9 += v13;
            }
LABEL_17:
            v14 = v9;
            v3 = a2;
            v6 = -abs(v8); //ABS negitive lol
            v7 = -abs(v14);  //ABS negitive lol
        }
        v15 = 0;
        if ( arena->FlagCounter > 0 )
        {
            do
            {
                if ( arena->Flags[v15].CarrierPlayerId == v3 )
                {
                    if ( !a3 )
                        arena->Flags[v15].OwnerFreq = -1;
                    arena->Flags[v15].CarrierPlayerId = -1;
                    arena->Flags[v15].XTile = v6;
                    arena->Flags[v15].YTile = v7;
                }
                ++v15;
            }
            while ( v15 < arena->FlagCounter );
        }
    }
}

//----- (004043C0) --------------------------------------------------------
void __cdecl ResetJackpotFlags(struct ARENA *arena)
{
    //struct ARENA *arena; // esi@1
    int v2; // ebx@1
    int v3; // eax@1
    int v4; // eax@2
    char *v5; // ecx@3
    int v6; // edi@5
    char *v7; // ecx@5
    int v8; // eax@6
    int v9; // edx@6
    __int16 v10; // bp@7
    unsigned int v11; // ebp@8
    int v12; // edi@8
    struct PLAYER **v13; // ebx@9
    int v14; // eax@14
    unsigned int v15; // kr00_4@18
    int v16; // eax@18
    struct PLAYER **v17; // edi@19
    char v18[8]; // [sp+10h] [bp-1008h]@18
    char buf[4096]; // [sp+18h] [bp-1000h]@5

    arena->ArenaJackpot = 0;
    if ( arena->ServersideArenaSettings.FlagMode == 2 )
    {
        if ( arena->FlagCounter > 0 )
        {
            v4 = 0;
            do
            {
                arena->Flags[v4].OwnerFreq = -1; //reset freq for all flags?
                ++v4;
            }
            while ( v4 < arena->FlagCounter );
        }
        buf[0] = 0x22;                             // 0x22 - Turf Flag Update
        v7 = &buf[1];
        if ( arena->FlagCounter > 0 )
        {
            v8 = (int)&arena->Flags[0].OwnerFreq;
            v9 = 0;
            do
            {
                *(unsigned short *)v7 = *(unsigned short *)&arena->Flags[v9].OwnerFreq; //Send -1's to players?
                v7 += 2;
                ++v9;
            }
            while ( v9 < arena->FlagCounter );
        }
        SendArenaPacket(arena, buf, 2 * arena->FlagCounter + 1, 1);
    }
    else
    {
        arena->FlagCounter = 0;
        if ( arena->ServersideArenaSettings.RandomFlags && arena->ServersideArenaSettings.MaxFlags > 0 )
            arena->TotalFlags = rand() % arena->ServersideArenaSettings.MaxFlags + 1;
        else
            arena->TotalFlags = arena->ServersideArenaSettings.MaxFlags;
        v18[0] = 0x14;                             // 0x14 - Flag Victory
        arena->LastFlagResetTime = GetTickCount() / 0xA;
        *(unsigned short *)&v18[1] = -1;                     // Team
        *(unsigned int *)&v18[3] = 0;                     // Jackpot Points

        SendArenaPacket(arena, v18, 7, 1);
    }
}
// 4043C0: using guessed type int __cdecl ResetJackpotFlags(unsigned int);

//----- (00404530) --------------------------------------------------------
int __cdecl GetNextFrequencyToJoin(struct ARENA *arena)
{
    //struct ARENA *arena; // ebx@1
    signed int TotalPlaying; // ebp@1
    struct PLAYER *eachPlayer; // edx@2
    int index; // esi@2
    int v5; // eax@3
    signed int CurrentFrequency; // esi@10
    int *NumPlayersPerFreqArrayy; // edi@10
    int NumPlayersThisFreq; // ecx@12
    //signed int TotalPlayingg; // [sp+10h] [bp-324h]@1
    int NumPlayersPerFreqArray[200]; // [sp+14h] [bp-320h]@1


    memset(NumPlayersPerFreqArray, 0, sizeof(NumPlayersPerFreqArray));
    TotalPlaying = 0;
    if ( arena->ArenaPlayerCount > 0 )
    {
        index = 0;
        do
        {
            eachPlayer = arena->ArenaPlayers[index];
            if ( eachPlayer->Frequency >= 0 && eachPlayer->Ship != 8 )
            {
                if ( eachPlayer->Frequency < 200 )
                    ++NumPlayersPerFreqArray[v5];
                ++TotalPlaying;
            }
            ++index;
        }
        while ( index < arena->ArenaPlayerCount);
    }
    CurrentFrequency = 0;
    while ( 1 )
    {
        if ( CurrentFrequency >= arena->ArenaSettings.MaxFrequency )
            return rand() % arena->ArenaSettings.MaxFrequency;
        NumPlayersThisFreq = NumPlayersPerFreqArray[CurrentFrequency];
        if ( !NumPlayersPerFreqArray[CurrentFrequency] )
            break;
        if ( NumPlayersThisFreq < arena->ArenaSettings.MaxPerTeam
                && NumPlayersThisFreq <= TotalPlaying / arena->ServersideArenaSettings.TeamDesiredTeams )
            break;
        ++CurrentFrequency;
        if ( CurrentFrequency >= 200 )
            return rand() % arena->ArenaSettings.MaxFrequency;
    }
    return CurrentFrequency;
}
// 404530: using guessed type int NumPlayersPerFreqArray[200];

//----- (00404600) --------------------------------------------------------
void __cdecl SendArenaPacket(struct ARENA *arena, const void *buf, int len, int IsReliableSend)
{
    //struct ARENA *arena; // ebx@1
    int v5; // edi@1
    int result; // eax@1
    struct PLAYER *player; // esi@2

    if ( arena->ArenaPlayerCount > 0 )
    {
        v5 = 0;
        do
        {
            player = arena->ArenaPlayers[v5];
            if ( !player->AlreadySentReliablePacket )
                SendPlayerReliablePacket(player, buf, len, IsReliableSend);
            ++v5;
        }
        while ( v5 < arena->ArenaPlayerCount );
    }
}

//----- (00404650) --------------------------------------------------------
void __cdecl SpawnOnMap(struct ARENA *arena, int *ReturnXTile, int *ReturnYTile, int XStart, int YStart, int Radius)
{
    signed int v6; // ebp@1
    int v7; // ebx@1
    int TwoDifference; // eax@1
    int XTile; // edi@3
    int YTile; // ebp@3
    struct ARENA *v11; // esi@7
    int v12[2]; // qax@9
    signed int v13; // eax@13
    int v14; // ebx@15
    int v15; // eax@15
    signed int v16; // eax@19
    int v17; // ecx@21
    signed int v18; // eax@25
    int v19; // ebx@27
    signed int v20; // esi@31
    signed int v21; // esi@36
    signed int v22; // esi@41
    int v23; // edx@43
    int v24; // esi@43
    signed int v25; // ecx@47
    struct ARENA *v26; // edx@53
    signed int v27; // eax@53
    int v28; // esi@55
    int v29; // ecx@55
    int v30; // eax@56
    //ARENA *arenaa; // [sp+8h] [bp-10h]@1
    int v32; // [sp+Ch] [bp-Ch]@1
    signed int v33; // [sp+10h] [bp-8h]@1
    int a4a; // [sp+24h] [bp+Ch]@1
    int a5a; // [sp+28h] [bp+10h]@1
    signed int a6a; // [sp+2Ch] [bp+14h]@7
    int a6b; // [sp+2Ch] [bp+14h]@21
    int a6c; // [sp+2Ch] [bp+14h]@33
    int a6d; // [sp+2Ch] [bp+14h]@38
    int a6e; // [sp+2Ch] [bp+14h]@49
    int a6f; // [sp+2Ch] [bp+14h]@55

    v6 = (2 * Radius);
    v7 = (YStart - Radius);
    TwoDifference = (XStart - YStart);
    v33 = 0;

    //9 Different types of axis movements, like snake game.
    //I figured out how it spawns the flags/soccerballs now :D -fatrolls

    while ( 1 )
    {
        XTile = ((v7 + TwoDifference) & ((v7 + TwoDifference < 0) - 1)) + rand() % v6;
        YTile = (v7 & ((v7 < 0) - 1)) + rand() % v6;

        //XTile, YTile
        if ( XTile < 0 || YTile < 0 || XTile >= 1024 || YTile >= 1024 )
            a6a = 1;
        else
            a6a = *(unsigned char *)(arena->MapData + (YTile << 10) + XTile);

        //XTile + 1, YTile
        if ( (XTile + 1) < 0 || YTile < 0 || (XTile + 1) >= 1024 || YTile >= 1024 )
            v13 = 1;
        else
            v13 = *(unsigned char *)(arena->MapData + (YTile << 10) + (XTile + 1));

        v14 = v13 + a6a;

        //XTile - 1, YTile
        if ( (XTile - 1) < 0 || YTile < 0 || (XTile - 1) >= 1024 || YTile >= 1024 )
            v16 = 1;
        else
            v16 = *(unsigned char *)(arena->MapData + (YTile << 10) + (XTile - 1));

        a6b = v16 + v14;

        //XTile, YTile + 1
        if ( XTile < 0 || (YTile + 1) < 0 || XTile >= 1024 || (YTile + 1) >= 1024 )
            v18 = 1;
        else
            v18 = *(unsigned char *)(arena->MapData + ((YTile + 1) << 10) + XTile);

        v19 = v18 + a6b;

        //XTile, YTile - 1
        if ( XTile < 0 || (YTile - 1) < 0 || XTile >= 1024 || (YTile - 1) >= 1024 )
            v20 = 1;
        else
            v20 = *(unsigned char *)(arena->MapData + ((YTile - 1) << 10) + XTile);

        a6c = v20 + v19;

        //YTile + 1,  XTile + 1
        if ( (YTile + 1) < 0 || (XTile + 1) < 0 || (XTile + 1) >= 1024 || (YTile + 1) >= 1024 )
            v21 = 1;
        else
            v21 = *(unsigned char *)(arena->MapData + ((YTile + 1) << 10) + (XTile + 1));

        a6d = v21 + a6c;

        //YTile + 1,  XTile - 1
        if ( (XTile + 1) < 0 || (YTile - 1) < 0 || (XTile + 1) >= 1024 || (YTile - 1) >= 1024 )
            v22 = 1;
        else
            v22 = *(unsigned char *)(arena->MapData + ((YTile - 1) << 10) + (XTile + 1));

        v23 = v22 + a6d;

        //XTile - 1, YTile + 1
        if ( (XTile - 1) < 0 || (YTile + 1) < 0 || (XTile - 1) >= 1024 || (YTile + 1) >= 1024 )
            v25 = 1;
        else
            v25 = *(unsigned char *)(arena->MapData + ((YTile + 1) << 10) + (XTile - 1));

        a6e = v25 + v23;

        //XTile - 1, YTile - 1
        if ( (XTile - 1) < 0 || (YTile - 1) < 0 || (XTile - 1) >= 1024 || (YTile - 1) >= 1024 )
            v27 = 1;
        else
            v27 = *(unsigned char *)(arena->MapData + ((YTile - 1) << 10) + (XTile - 1));

        a6f = v27 + a6e;

        v29 = 0;
        if ( arena->FlagCounter > 0 )
        {
            while ( arena->Flags[v29].XTile != XTile || arena->Flags[v29].YTile != YTile )
            {
                ++v29;
                if ( v29 >= arena->FlagCounter )
                    goto LABEL_62;
            }
            ++a6f;
        }
LABEL_62:
        v7--;
        if ( !a6f ) //how the fuck does it ever get to <=0? if it always increases?
            break;
        v6 += 2;
    }
    *ReturnXTile = XTile;
    *ReturnYTile = YTile;
}

//----- (00404980) --------------------------------------------------------
void __cdecl sub_404980(struct ARENA *arena, struct PLAYER *player, int a3, int a4)
{
    int v4; // eax@4
    int v5; // esi@4
    int v6; // ecx@4
    int v7; // edx@5
    int v8; // ecx@9

    if ( a3 >= 0 && a3 >= 0 && a3 < 8 && a4 < 8)
    {
        v4 = 0;
        v5 = (int)((char *)arena + 1004 * (a4 + 8 * a3));
        v6 = *(unsigned int *)(v5 + 1000);
        if ( v6 > 0 )
        {
            v7 = v5;
            while ( *(struct PLAYER **)v7 != player )
            {
                ++v4;
                v7 += 4;
                if ( v4 >= v6 )
                    return;
            }
            v8 = v6 - 1;
            *(unsigned int *)(v5 + 1000) = v8;
            *(unsigned int *)(v5 + 4 * v4) = *(unsigned int *)(v5 + 4 * v8);
        }
    }
}

//----- (004049F0) --------------------------------------------------------
void __cdecl AddPlayerToArenaSomething(struct ARENA *arena, struct PLAYER *player, signed int a3, signed int a4)
{
    int v4; // eax@4
    char *v5; // edx@4

    if ( a3 >=0 && a4 >= 0 && a3 < 8 && a4 < 8 )
    {
        v4 = a4 + 8 * a3;
        v5 = (char *)&arena->PlayerPointers[251 * v4 + 250];
        arena->PlayerPointers[(*(unsigned int *)v5)++ + 251 * v4] = player;
    }
}

//----- (00404A50) --------------------------------------------------------
void __cdecl LoadArenaSettings(struct ARENA *arena)
{
    //struct ARENA *arena; // ebx@1
    char *v2; // esi@1
    int v3; // eax@4
    int v4; // esi@5

    if ( stricmp(arena->SettingsFilename, ServerCFGFilePath) ) // Attempt to load arena settings from file
    {
        IsFileLastWrittenTime(arena->SettingsFilename, &arena->LastSettingsWrittenTime);
        LoadZoneCFGSettings(&arena->ArenaSettings, &arena->ServersideArenaSettings, arena->SettingsFilename);
    }
    else                                          // If fail occurs (arena.cfg is missing) uses default server.cfg settings.
    {
        memcpy(&arena->ArenaSettings, &ArenaSettings, sizeof(arena->ArenaSettings));
        memcpy(&arena->ServersideArenaSettings, &ServersideArenaSettings, sizeof(arena->ServersideArenaSettings));
    }
    arena->CalculatedMapZoomFactor = ((signed int)arena->ArenaSettings.MapZoomFactor << 14) / 96;

    //TODO: Figure this thing out.
    //Not a factorial thingy but definitely a fibonacci thingy that's for sure.
    //Adds up all the PrizeWeights together to make a Master Prize Weight Pool value.
    //Lowest Master Prize Pool value (with all prize weights 1) is 29.
    //Maximum Master Prize Pool value (with all prize weights 255) is 7395.
    //For very large prize weights over 255 which is -1 for each prize weight value is -29;

    v3 = 0;
    arena->MasterPrizeWeightPoolValue = 0;
    do
    {
        arena->MasterPrizeWeightPoolValue += *(&arena->ArenaSettings.PrizeAddressAnchor + v3++);
    } while ( v3 < 29 );
}

//----- (00404B10) --------------------------------------------------------
void __cdecl LoadArenaMap(struct ARENA *arena)
{
    const char *MapFileName; // ebx@1
    int v3; // esi@2
    struct BMP_FILE_STRUCT *v4; // edi@2
    int v5; // ebx@2
    signed int v6; // eax@4
    struct BMP_FILE_STRUCT *v7; // eax@8
    struct BMP_FILE_STRUCT *v8; // esi@9
    unsigned char* v9; // edi@11
    int v10; // edi@11
    int v11; // ebx@11
    signed int v12; // ecx@13
    unsigned int v13; // edx@15
    signed int v14; // edi@16
    signed int v15; // esi@17
    int v16; // ecx@18
    int v17; // eax@18
    unsigned char *v18; // eax@20
    int TileValue; // [sp+10h] [bp-2Ch]@12
    unsigned int v20; // [sp+14h] [bp-28h]@3
    int i; // [sp+18h] [bp-24h]@8
    char Buffer[17]; // [sp+1Ch] [bp-20h]@8
    int v23; // [sp+38h] [bp-4h]@8
    unsigned char TileId; //fix 1
    unsigned short TileX; //fix 2
    unsigned short TileY; //fix 3

    if ( stricmp(MiscDefaultLevelFile, arena->MapFilename) )
    {
        strcpy(&Buffer[1], arena->MapFilename);
        *(unsigned int *)Buffer = 0;
        Buffer[0] = 0x2A;                          // 0x2A - Compressed Map File
        *(unsigned int *)&Buffer[4] = 0;
        *(unsigned int *)&Buffer[8] = 0;
        *(unsigned int *)&Buffer[12] = 0;
        Buffer[16] = 0;
        arena->CompressedMap = CompressFile(arena->MapFilename, &arena->MapFileSize, &arena->MapChecksum, Buffer, 0x11, 1);
        v7 = malloc (sizeof (struct BMP_FILE_STRUCT));
        i = (int)v7;
        v23 = 0;
        if ( v7 )
            LoadBMPHeader(v7, arena->MapFilename);

        v23 = -1;
        arena->TotalMapTurfFlags = 0;
        arena->MapData = AllocateMemory(0x100000); //Each Map takes about 1 Megabyte of memory
        memset(arena->MapData, 0, 0x100000);
        v10 = v7->TotalMapTiles;
        v11 = 0;
        for ( i = v7->TotalMapTiles; v11 < v7->TotalMapTiles; ++v11 )
        {
            GetTileValue(v7, v11, &TileValue);
            TileId = (TileValue >> 24) & 0xFF;
            TileX = (TileValue >> 12) & 0xFFF;
            TileY = (TileValue & 0xFFF);
            if ( TileId == 0xAA )   // // 0xAA - Turf Flag Tile
            {
                // 510 Flags WOW.. I always thought the limit was 255 flags. [510/2=255] odd
                if ( arena->TotalMapTurfFlags < 510 )
                {
                    arena->TurfFlagsCoordinates[arena->TotalMapTurfFlags].XTile = TileX; // X Coord
                    arena->TurfFlagsCoordinates[arena->TotalMapTurfFlags].YTile = TileY; // Y Coord
                    arena->TotalMapTurfFlags++;
                }
            } else {
                arena->MapData[(1024 * TileX) + TileY] = TileId;

                if ( TileId >= 0xD8 )
                {
                    v14 = 0;
                    do
                    {
                        v15 = 0;
                        do
                        {
                            v16 = v14 + TileY; // Y Coord
                            v17 = v15 + TileX; // X Coord
                            if ( v16 < 1024 && v17 < 1024  )
                            {
                                if ( !arena->MapData[(1024 * v17) + v16] )
                                    arena->MapData[(1024 * v17) + v16] = 240; //0xF0
                            }
                            ++v15;
                        }
                        while ( v15 < 7 );
                        ++v14;
                    }
                    while ( v14 < 7 );
                    v10 = i;
                }
            }
        }
        if ( v7 )
        {
            sub_406B30(v7);
            free(v7);
        }
    } else {
        v3 = 0;
        arena->CompressedMap = CompressedServerMap;
        arena->MapFileSize = MapFileSize;
        arena->MapChecksum = MapChecksum;
        arena->MapData = ServerMapData;
        arena->TotalMapTurfFlags = 0;
        if ( BMPFilePointer->TotalMapTiles > 0 )
        {
            do
            {
                GetTileValue(BMPFilePointer, v3, &TileValue);
                TileId = (TileValue >> 24) & 0xFF;
                TileX = (TileValue >> 12) & 0xFFF;
                TileY = (TileValue & 0xFFF);

                if ( TileId == 0xAA ) // // 0xAA - Turf Flag Tile
                {
                    if ( arena->TotalMapTurfFlags < 510 ) // 510 Flags WOW.. I always thought the limit was 255 flags. [510/2=255] odd
                    {
                        arena->TurfFlagsCoordinates[arena->TotalMapTurfFlags].XTile = TileX; // X Coord
                        arena->TurfFlagsCoordinates[arena->TotalMapTurfFlags].YTile = TileY; // Y Coord
                        ++arena->TotalMapTurfFlags;
                    }
                }
                ++v3;
            } while ( v3 < BMPFilePointer->TotalMapTiles );
        }
    }
}
// 406BE0: using guessed type int __cdecl sub_406BE0(unsigned int);
// 4386F8: using guessed type int MapChecksum;
// 4D8AF0: using guessed type int MapFileSize;

//----- (00404E20) --------------------------------------------------------
int __cdecl GetDeathPrizeGreenId(struct ARENA *arena)
{
    //struct ARENA *arena; // edi@1
    int MasterPrizeWeightRandomPoolValue; // edx@1
    int CurrentMasterPrizeWeightValue; // ecx@1
    signed int  CurrentPrizeId; // esi@1
    //int ResultCurrentPrizeId; // eax@6
    int PrizeNegativeFactorRandomValue; // edx@7


    MasterPrizeWeightRandomPoolValue = rand() % arena->MasterPrizeWeightPoolValue;
    CurrentMasterPrizeWeightValue = 0;
    CurrentPrizeId = 0;
    while ( 1 )
    {
        if ( *(&arena->ArenaSettings.PrizeAddressAnchor + CurrentPrizeId) ) //Checks if the Prize Weight for this Prize is even set.
        {
            if ( MasterPrizeWeightRandomPoolValue >= CurrentMasterPrizeWeightValue )
            {
                CurrentMasterPrizeWeightValue += *(&arena->ArenaSettings.PrizeAddressAnchor + CurrentPrizeId);
                if ( MasterPrizeWeightRandomPoolValue < CurrentMasterPrizeWeightValue )
                    break;
            }
        }
        ++CurrentPrizeId;
        if ( CurrentPrizeId >= 29 )
            return 0;
    }

    //PrizeNegativeFactor of 1 will always give negitive prizes.
    PrizeNegativeFactorRandomValue = rand() % arena->ArenaSettings.PrizeNegativeFactor;

    if ( PrizeNegativeFactorRandomValue == 0 )
        return -CurrentPrizeId;
    else
        return CurrentPrizeId;
}

//----- (00404E80) --------------------------------------------------------
signed int __cdecl ChangeSettings(struct ARENA *arena, struct PLAYER *player, const char *a3)
{
    const char *v3; // eax@1
    char v4[256]; // qcx@1
    char *i; // edx@1
    char v6; // cl@4
    signed int result; // eax@5
    char v8; // cl@6
    int v9; // eax@6
    char *j; // edx@6
    char v11; // cl@9
    signed int v12; // ebp@11
    int v13; // edi@22
    int v14; // ebx@22
    struct TEMPLATE_SSS *v15; // esi@22
    const char *v16; // esi@41
    int v17; // [sp+10h] [bp-514h]@21
    int v18; // [sp+14h] [bp-510h]@21
    //struct ARENA *arena; // [sp+18h] [bp-50Ch]@1
    signed int v20; // [sp+1Ch] [bp-508h]@21
    int v21; // [sp+20h] [bp-504h]@21
    char Str2[256]; // [sp+24h] [bp-500h]@12
    char KeyName[256]; // [sp+124h] [bp-400h]@6
    char Str[256]; // [sp+224h] [bp-300h]@11
    char Str1[256]; // [sp+324h] [bp-200h]@1
    char messageBuffer[256]; // [sp+424h] [bp-100h]@35

    v3 = a3;
    v4[0] = *a3;
    for ( i = Str1; v4[0]; ++v3 )
    {
        if ( v4[0] == ':' )
            break;
        *i = v4[0];
        v4[0] = v3[1];
        ++i;
    }

    v6 = *v3;
    *i = 0;
    if ( !v6 )
        return 1;

    v8 = a3[1];
    v9 = (int)(a3 + 1);

    for ( j = KeyName; v8; ++v9 )
    {
        if ( v8 == ':' )
            break;
        *j = v8;
        v8 = *(unsigned char *)(v9 + 1);
        ++j;
    }

    v11 = *(unsigned char *)v9;
    *j = 0;
    if ( !v11 )
        return 1;
    strcpy(Str, (const char *)(v9 + 1));
    v12 = 0;

    if ( !player->IsSysop )
    {
        strcpy(Str2, Str1);
        if ( !stricmp(Str2, "Warbird")
                || !stricmp(Str2, "Javelin")
                || !stricmp(Str2, "Spider")
                || !stricmp(Str2, "Leviathan")
                || !stricmp(Str2, "Weasel")
                || !stricmp(Str2, "Terrier")
                || !stricmp(Str2, "Lancaster")
                || !stricmp(Str2, "Shark") )
            strcpy(Str2, "All");
        v18 = 0;
        v20 = 0;
        v17 = atoi(Str);
        v21 = 0;
        if ( TotalTemplateSSSEntries <= 0 )
        {
            v13 = v17;
            v14 = v17;
        }
        else
        {
            v13 = v17;
            v14 = v17;
            v15 = TotalTemplateSSSList;
            while ( 1 )
            {
                if ( !stricmp(v15->SomeString32, Str2) || !stricmp(v15->SomeString32, Str1) )
                {
                    if ( !stricmp(v15->KeyName, KeyName) )
                    {
                        if ( !v15->SomeChar1a )
                        {
                            v13 = v15->someInteger;
                            v14 = v15->someInteger2;
                            v12 = 1;
                            v18 = v15->SomeChar1b;
                            if ( v13 == -999 )
                                break;
                            if ( v17 >= v13 && v17 <= v14 )
                                break;
                        }
                    }
                }
                ++v15;
                ++v21;
                if ( v21 >= TotalTemplateSSSEntries )
                    goto LABEL_34;
            }
            v20 = 1;
        }
LABEL_34:
        if ( !v12 )
        {
            sprintf(messageBuffer, "%s:%s is not a valid user parameter.", Str1, KeyName);
            SendArenaMessage(player, messageBuffer, 0);
            return 1;
        }
        if ( !v20 )
        {
            sprintf(messageBuffer, "Valid range for parameter %s:%s is (%d through %d)", Str1, KeyName, v13, v14);
            SendArenaMessage(player, messageBuffer, 0);
            return 1;
        }
        if ( v18 )
        {
            arena->ArenaRecycling = 1;
            if ( !stricmp(arena->SettingsFilename, ServerCFGFilePath) )
                RecycleServer = 1;
        }
    }
    arena->NeedSettingsUpdate = 1;
    v16 = arena->SettingsFilename;
    if ( !stricmp(arena->SettingsFilename, ServerCFGFilePath) )
        IsEditedServerINIorCFG = 1;
    if ( stricmp(Str1, "All") )
    {
        WritePrivateProfileStringA(Str1, KeyName, Str, v16);
        result = 0;
    }
    else
    {
        WritePrivateProfileStringA("Warbird", KeyName, Str, v16);
        WritePrivateProfileStringA("Javelin", KeyName, Str, v16);
        WritePrivateProfileStringA("Spider", KeyName, Str, v16);
        WritePrivateProfileStringA("Leviathan", KeyName, Str, v16);
        WritePrivateProfileStringA("Terrier", KeyName, Str, v16);
        WritePrivateProfileStringA("Weasel", KeyName, Str, v16);
        WritePrivateProfileStringA("Lancaster", KeyName, Str, v16);
        WritePrivateProfileStringA("Shark", KeyName, Str, v16);
        result = 0;
    }
    return result;
}
// 432004: using guessed type int RecycleServer;
// 4D5920: using guessed type int IsEditedServerINIorCFG;
// 4D8AE4: using guessed type int TotalTemplateSSSEntries;

//----- (00405360) --------------------------------------------------------
void __cdecl sub_405360(struct ARENA *arena, int BooleanSendScoreReset)
{
    //struct ARENA *arena; // esi@1

    ArenaScoreReset(arena, BooleanSendScoreReset);
    arena->TotalScoreStructs = 0;
    arena->LastTimedGameTime = GetTickCount() / 0xA;
    arena->field_FF20 = 0;
    SoccerGameSomething(arena, -1);
}

//----- (004053B0) --------------------------------------------------------
void __cdecl SoccerGameSomething(struct ARENA *arena, int a2)
{
    int v2; // edx@1
    struct ARENA *v3; // ebp@1
    struct PLAYER *v4; // ebx@3
    int v5; // eax@6
    int v6; // eax@13
    struct PLAYER *v7; // ecx@14
    int v8; // esi@15
    int v9; // eax@16
    int BallCounter; // eax@18
    int v11; // esi@19
    int v12; // ecx@20
    int v13; // edi@20
    struct PLAYER **v14; // ebx@21
    int v15; // [sp+10h] [bp-118h]@2
    int v16; // [sp+10h] [bp-118h]@19
    int index; // [sp+14h] [bp-114h]@18
    char buf[16]; // [sp+18h] [bp-110h]@20
    char ArenaMessageBuffer[256]; // [sp+28h] [bp-100h]@7

    if ( a2 >= 0 )
    {
        if ( arena->ArenaPlayerCount > 0 )
        {
            v15 = 0;
            do
            {
                v4 = arena->ArenaPlayers[v15];
                if ( v4->Frequency != a2 || (v5 = v4->MySoccerReward, v5 <= 0) )
                {
                    strcpy(ArenaMessageBuffer, "Soccer game over.");
                }
                else
                {
                    sprintf(ArenaMessageBuffer, "Soccer game over.  Personal Reward: %d", v5);
                    AppendPointsLog(v4, 0, v4->MySoccerReward);
                }
                SendArenaMessage(v4, ArenaMessageBuffer, 103);
                if ( !SendPlayerScoreUpdateAll(v4) )
                    SendPlayerScoreUpdate(v4);
                ++v15;
            }
            while ( v15 < arena->ArenaPlayerCount );
        }
    }
    if ( arena->ArenaPlayerCount > 0 )
    {
        v6 = 0;
        do
        {
            arena->ArenaPlayers[v6]->MySoccerReward = 0;
            ++v6;
        }
        while ( v6 < arena->ArenaPlayerCount );
    }
    arena->Freq1Score = 0;
    arena->Freq2Score = 0;
    arena->Freq3Score = 0;
    arena->Freq4Score = 0;
    v9 = arena->ServersideArenaSettings.SoccerCapturePoints;
    if ( v9 > 0 )
    {
        arena->Freq1Score = v9;
        arena->Freq2Score = v9;
        arena->Freq3Score = v9;
        arena->Freq4Score = v9;
    }

    if ( arena->TotalSoccerBalls > 0 )
    {
        index = 0;
        do
        {
            arena->SoccerBalls[index].PowerBallId = index;
            arena->SoccerBalls[index].XPixels = 0;
            arena->SoccerBalls[index].YPixels = 0;
            arena->SoccerBalls[index].XVelocity = 0;
            arena->SoccerBalls[index].YVelocity = 0;
            arena->SoccerBalls[index].PlayerId = -1;
            arena->SoccerBalls[index].StartTimeDelay = 0;
            arena->SoccerBallTimers[index] = 0;

            buf[0] = 0x2E;	//0x2E - Power-Ball Position Update
            buf[1] =  arena->SoccerBalls[0].PowerBallId;
            *(unsigned short *)&buf[2] = arena->SoccerBalls[index].XPixels;
            *(unsigned short *)&buf[4] = arena->SoccerBalls[index].YPixels;
            *(unsigned short *)&buf[6] = arena->SoccerBalls[index].XVelocity;
            *(unsigned short *)&buf[8] = arena->SoccerBalls[index].YVelocity;
            *(unsigned short *)&buf[10] = arena->SoccerBalls[index].PlayerId;
            *(unsigned int *)&buf[12] = arena->SoccerBalls[index].StartTimeDelay;
            buf[15] = *(unsigned char *)(v11 + 11);
            SendArenaPacket(arena, buf, 0x10, 1);
            ++index;
        }
        while ( index < arena->TotalSoccerBalls );
    }
    arena->TotalSoccerBalls = 0;
}

//----- (004055D0) --------------------------------------------------------
char __cdecl sub_4055D0(struct ARENA *arena, int Frequency, int a3, signed int a4)
{
    //struct ARENA *arena; // esi@1
    int v5; // edi@1
    signed int v6; // ebx@1
    signed int v7; // ebp@1
    int v8; // eax@1
    int v9; // eax@11
    int v10; // edi@12
    struct PLAYER **v11; // ebx@13
    int v12; // ecx@18
    int v13; // edx@25
    signed int v14; // ecx@25
    int v15; // ecx@27


    v5 = -1;
    v6 = -1;
    v7 = 0;
    *((unsigned char*)&(v8)) = SoccerRelatedMath(arena->ArenaSettings.SoccerMode, a3, a4);
    switch ( arena->ArenaSettings.SoccerMode )
    {
    case 1:
    case 2:
        v7 = 2;
        v5 = Frequency & 1;
        v6 = v8;
        break;
    case 3:
    case 5:
        v7 = 4;
        v5 = Frequency & 3;
        v6 = v8;
        break;
    case 4:
    case 6:
        v7 = 4;
        v5 = Frequency & 3;
        switch ( v5 )
        {
        case 0:
            v6 = 3;
            break;
        case 1:
            v6 = 2;
            break;
        case 2:
            v6 = 1;
            break;
        case 3:
            v6 = 0;
            break;
        default:
            goto LABEL_9;
        }
        break;
    default:
        break;
    }
LABEL_9:
    if ( v5 >= 0 )
    {
        v8 = arena->ServersideArenaSettings.SoccerCapturePoints;
        if ( v8 <= 0 )
        {
            if ( v8 < 0 )
            {
                ++*(&arena->Freq1Score + v5);
                GetScore(arena, 0);
                v8 = *(&arena->Freq1Score + v5);
                if ( v8 >= -arena->ServersideArenaSettings.SoccerCapturePoints )
                {
                    v14 = 1;
                    if ( arena->ServersideArenaSettings.SoccerWinBy > 0 )
                    {
                        v8 = 0;
                        if ( v7 > 0 )
                        {
                            v15 = (int)&arena->Freq1Score;
                            while ( v8 == v5 || *(&arena->Freq1Score + v5) - *(unsigned int *)v15 >= arena->ServersideArenaSettings.SoccerWinBy )
                            {
                                ++v8;
                                v15 += 4;
                                if ( v8 >= v7 )
                                {
                                    v14 = 1;
                                    goto LABEL_33;
                                }
                            }
                            v14 = 0;
                        }
                    }
LABEL_33:
                    if ( v14 )
                        SoccerGameSomething(arena, Frequency);
                }
            }
        }
        else
        {
            v9 = *(&arena->Freq1Score + v6);
            if ( v9 )
            {
                *(&arena->Freq1Score + v6) = v9 - 1;
                ++*(&arena->Freq1Score + v5);
            }
            else
            {
                if ( arena->ArenaPlayerCount > 0 )
                {
                    v10 = 0;
                    v11 = arena->ArenaPlayers;
                    do
                    {
                        SendArenaMessage(*v11, "Enemy goal had no points to give.", 0);
                        ++v10;
                        ++v11;
                    }
                    while ( v10 < arena->ArenaPlayerCount );
                }
            }
            GetScore(arena, 0);
            v8 = 0;
            if ( v7 > 0 )
            {
                v12 = (int)&arena->Freq1Score;
                while ( *(unsigned int *)v12 != arena->ServersideArenaSettings.SoccerCapturePoints * v7 )
                {
                    ++v8;
                    v12 += 4;
                    if ( v8 >= v7 )
                        return v8;
                }
                SoccerGameSomething(arena, Frequency);
            }
        }
    }
    return v8;
}

//----- (004057C0) --------------------------------------------------------
void __cdecl GetScore(struct ARENA *arena, struct PLAYER *player)
{
    //struct ARENA *arena; // edi@1
    char v3; // al@3
    int v4; // ebx@16
    struct PLAYER **v5; // esi@17
    struct PLAYER *v6; // ecx@18
    const char *v7; // [sp-Ch] [bp-218h]@9
    char *v8; // [sp-8h] [bp-214h]@19
    char v9; // [sp-4h] [bp-210h]@19
    char Buffer1[256]; // [sp+Ch] [bp-200h]@6
    char Buffer2[256]; // [sp+10Ch] [bp-100h]@14

    if ( arena->ServersideArenaSettings.SoccerBallCount > 0 && arena->ServersideArenaSettings.SoccerCapturePoints )
    {
        if ( arena->ArenaSettings.SoccerMode == 1 || arena->ArenaSettings.SoccerMode == 2 )
        {
            if ( arena->ServersideArenaSettings.MiscFrequencyShipTypes )
                v7 = "SCORE: Warbirds:%d  Javelins:%d";
            else
                v7 = "SCORE: Evens:%d  Odds:%d";
            sprintf(Buffer1, v7, arena->Freq1Score, arena->Freq2Score);
        }
        else
        {
            if ( arena->ServersideArenaSettings.MiscFrequencyShipTypes )
                sprintf(
                    Buffer1,
                    "SCORE: Warbirds:%d  Javelins:%d  Spiders:%d  Leviathans:%d",
                    arena->Freq1Score,
                    arena->Freq2Score,
                    arena->Freq3Score,
                    arena->Freq4Score);
            else
                sprintf(
                    Buffer1,
                    "SCORE: Team0:%d  Team1:%d  Team2:%d  Team3:%d",
                    arena->Freq1Score,
                    arena->Freq2Score,
                    arena->Freq3Score,
                    arena->Freq4Score);
        }
        if ( player )
        {
            if ( player->MySoccerReward <= 0 )
            {
                SendArenaMessage(player, Buffer1, 0);
            }
            else
            {
                sprintf(Buffer2, "%s  REWARD:%d", Buffer1, player->MySoccerReward);
                SendArenaMessage(player, Buffer2, 0);
            }
        }
        else
        {
            if ( arena->ArenaPlayerCount > 0 )
            {
                v4 = 0;
                v5 = (struct PLAYER **)arena->ArenaPlayers;
                do
                {
                    v6 = *v5;
                    if ( (*v5)->MySoccerReward <= 0 )
                    {
                        v9 = 0;
                        v8 = Buffer1;
                    }
                    else
                    {
                        sprintf(Buffer2, "%s  REWARD:%d", Buffer1, (*v5)->MySoccerReward);
                        v9 = 0;
                        v8 = Buffer2;
                        v6 = *v5;
                    }
                    SendArenaMessage(v6, v8, v9);
                    ++v4;
                    ++v5;
                }
                while ( v4 < arena->ArenaPlayerCount );
            }
        }
    }
}

//----- (00405970) --------------------------------------------------------
unsigned int __cdecl GetArenaMemoryTotal(struct ARENA *arena)
{
    unsigned int v1; // edx@1

    v1 = 0x75;
    if ( arena->MapData != ServerMapData )
        v1 = 0x525;
    return v1 + ((unsigned int)(sizeof(struct SCORE) * arena->TotalNumScoresInFile) / 1024);
}

//----- (004059A0) --------------------------------------------------------
int __cdecl GetTotalPlayingPlayers(struct ARENA *arena)
{
    int index; // edx@1
    int result; // eax@1
    struct PLAYER *v3; // ecx@2

    result = 0;
    if ( arena->ArenaPlayerCount > 0 )
    {
        index = 0;
        v3 = arena->ArenaPlayers[index];
        do
        {
            if ( v3->Ship != 8 )
                ++result;
            ++index;
        }
        while ( index < arena->ArenaPlayerCount );
    }
    return result;
}

//----- (004059D0) --------------------------------------------------------
void __cdecl SendBillerServerConnectPacket(struct BILLING_SERVER_STRUCT *billingServerStruct, int HandleBillerPacketFuncAddress, const char *ServerName, int ServerId, int GroupId, int ScoreId, const char *Password, struct PACKET_ATTACHMENT *mainServerStructure, struct CONNECTION *connection)
{
    struct BILLING_SERVER_STRUCT *billingStructt; // esi@1
    struct CONNECTION *v10; // ecx@1
    char buf[173]; // [sp+8h] [bp-B0h]@1

    billingServerStruct->MainServerStructure = mainServerStructure;
    billingServerStruct->connection = connection;
    memset(buf, 0, 0xAC);
    buf[172] = 0;
    billingServerStruct->HandleBillerPacketFunctionAddress = HandleBillerPacketFuncAddress;
    billingServerStruct->ZeroValue = 0;
    buf[0] = 0x02;                                   // 0x02 - Billing Server Connect
    strncpy(&buf[13], ServerName, 0x80);
    buf[140] = 0;
    strncpy(&buf[141], Password, 0x20);
    *(unsigned int *)&buf[1] = ServerId;
    buf[172] = 0;
    *(unsigned int *)&buf[5] = GroupId;
    *(unsigned int *)&buf[9] = ScoreId;
    SendReliablePacket(billingServerStruct->connection, buf, 0xAD, 1);
    billingServerStruct->GetTickCountValue = GetTickCount() / 0xA;
}

//----- (00405AB0) --------------------------------------------------------
int __cdecl CleanUpBilling(struct BILLING_SERVER_STRUCT *billingServerStruct)
{
    unsigned int StartDelay; // esi@1
    int result; // eax@1
    char buf[1]; // [sp+1h] [bp-1h]@1

    buf[0] = 3;                                   // 0x03 - Billing Server DisconnectPacket
    SendReliablePacket(billingServerStruct->connection, buf, 1, 1);
    StartDelay = GetTickCount() / 0xA;
    for ( result = GetBillingServerRelOut(billingServerStruct->connection, 0);
            result > 0;
            result = GetBillingServerRelOut(billingServerStruct->connection, 0) )
    {
        result = abs(GetTickCount() / 0xA - StartDelay);
        if ( result >= 800 )                        // Process Player Packets for only 800 milliseconds?
            break;
        ProcessPackets(billingServerStruct->MainServerStructure);
    }
    return result;
}
// 41AC00: using guessed type int __cdecl ProcessPackets(unsigned int);

//----- (00405B30) --------------------------------------------------------
void __cdecl SendBillerUserBannerPacket(struct BILLING_SERVER_STRUCT *billingServerStruct, int a2, const void *a3)
{
    char buf[104]; // [sp+0h] [bp-68h]@2

    if ( a2 >= 0 )
    {
        *(unsigned int *)&buf[1] = a2;
        buf[0] = 0x10;                             // 0x10 - Billing User Banner Packet
        memcpy(&buf[5], a3, 0x60);
        SendReliablePacket(billingServerStruct->connection, buf, 0x65, 1);
    }
}

//----- (00405B70) --------------------------------------------------------
void __cdecl SendBillerUserDemographicsPacket(struct BILLING_SERVER_STRUCT *billingServerStruct, int PlayerId, unsigned char *UserDemographics)
{
    char buf[772]; // [sp+0h] [bp-304h]@2

    if ( PlayerId >= 0 )
    {
        *(unsigned int *)&buf[1] = PlayerId;
        buf[0] = 0x0D;                              // 0x0D - Billing User Demographics Packet
        memcpy(&buf[5], UserDemographics, 0x2FC);
        buf[769] = UserDemographics[764];
        SendReliablePacket(billingServerStruct->connection, buf, 0x302, 1);
    }
}
//----- (00405BC0) --------------------------------------------------------
void __cdecl SendBillerUnknownPacket(struct BILLING_SERVER_STRUCT *billingServerStruct, int a1, int a2, const char *a3)
{
    struct BILLING_SERVER_STRUCT *billingServerStructt; // edx@1
    char buf[2048]; // [sp+10h] [bp-9h]@1

    billingServerStructt = billingServerStruct;
    *(unsigned int *)&buf[1] = a1;
    *(unsigned int *)&buf[5] = a2;
    strcpy(&buf[9], a3);
    buf[0] = 0x0E;                                // 0x0E - Some Unknown Biller Packet (Contains a String)
    SendReliablePacket(billingServerStructt->connection, buf, strlen(a3) + 10, 1);
}

//----- (00405C40) --------------------------------------------------------
void __cdecl SendBillerUserChannelChatPacket(struct BILLING_SERVER_STRUCT *billingServerStruct, int PlayerId, const char *ChannelName, const char *ChatText)
{
    char buf[2048]; // [sp+4h] [bp-800h]@2

    if ( PlayerId >= 0 )
    {
        *(unsigned int *)&buf[1] = PlayerId;
        buf[0] = 0x14;                             // 0x14 - Billing User Channel Chat
        strncpy(&buf[5], ChannelName, 0x20);
        strcpy(&buf[37], ChatText);
        buf[36] = 0;
        SendReliablePacket(billingServerStruct->connection, buf, strlen(ChatText) + 38, 1);
    }
}

//----- (00405CD0) --------------------------------------------------------
void __cdecl SendBillerWarningPacket(struct BILLING_SERVER_STRUCT *billingServerStruct, int PlayerId, const char *WarningMessage)
{
    char buf[1024]; // [sp+4h] [bp-400h]@2

    if ( PlayerId >= 0 )
    {
        *(unsigned int *)&buf[1] = PlayerId;
        strcpy(&buf[5], WarningMessage);
        buf[0] = 0x0F;                              // 0x0F - Biller Warning Packet
        SendReliablePacket(billingServerStruct->connection, buf, strlen(WarningMessage) + 6, 1);
    }
}

//----- (00405D50) --------------------------------------------------------
void __cdecl SendBillerUserCommandPacket(struct BILLING_SERVER_STRUCT *billingServerStruct, int a2, const char *UserCommand)
{
    char buf[1024]; // [sp+4h] [bp-400h]@2

    if ( a2 >= 0 )
    {
        *(unsigned int *)&buf[1] = a2;
        strcpy(&buf[5], UserCommand);
        buf[0] = 0x13;                             // 0x13 - Billing User Command
        SendReliablePacket(billingServerStruct->connection, buf, strlen(UserCommand) + 6, 1);
    }
}
//----- (00405DD0) --------------------------------------------------------
void __cdecl SendBillerUserLoginPacket(struct BILLING_SERVER_STRUCT *billingServerStruct, const char *Username, const char *Password, struct in_addr IPAddress, int MachineId, int Timezone, char IsNewUser, int PlayerId, char Unused0, char isSysop)
{
    char buf[84]; // [sp+8h] [bp-54h]@2

    if ( PlayerId >= 0 )
    {
        buf[0] = 0x04;                                 // 0x04 - Billing User Login
        strncpy(&buf[6], Username, 0x20);
        buf[37] = 0;
        strncpy(&buf[38], Password, 0x20);
        *(unsigned int *)&buf[2] = IPAddress.s_addr;
        buf[1] = IsNewUser;
        *(unsigned int *)&buf[74] = MachineId;
        *(unsigned int *)&buf[78] = Timezone;
        buf[69] = 0;                                // Terminate with NULL Password
        *(unsigned int *)&buf[70] = PlayerId;
        buf[82] = Unused0;
        buf[83] = isSysop;
        SendReliablePacket(billingServerStruct->connection, buf, 0x54, 1);
    }
}

//----- (00405E70) --------------------------------------------------------
void __cdecl SendBillerUserLogoffPacket(struct BILLING_SERVER_STRUCT *billingServerStruct, struct PLAYER *player, __int16 Latency, __int16 Ping, bool IsNotSendPlayerScore)
{
    unsigned int Size; // eax@2
    char buf[1024]; // [sp+0h] [bp-400h]@2

    if ( player->BillerPlayerId >= 0 )
    {
        buf[0] = 0x05;                                 // 0x05 - Billing User Logoff
        *(unsigned int *)&buf[1] = player->BillerPlayerId;              // PlayerId
        *(unsigned short *)&buf[5] = player->DisconnectReason;       // Disconnect Reason
        *(unsigned short *)&buf[7] = Latency;                // Latency
        *(unsigned short *)&buf[9] = Ping;                   // Ping
        *(unsigned short *)&buf[13] = 10 * player->SecurityPacketCache.CurrentPing; //C2SPacketLoss
        *(unsigned short *)&buf[11] = 10 * player->C2SAverageLatencyFirst / (player->C2SAverageLatencySecond + 1); //S2CPacketLoss
        Size = 15;
        if ( IsNotSendPlayerScore )
        {
            *(unsigned short *)&buf[15] = player->CurrentWins;
            *(unsigned short *)&buf[17] = player->CurrentDeaths;
            *(unsigned short *)&buf[19] = player->CurrentGoals;
            *(unsigned int *)&buf[21] = player->KillPoints;
            *(unsigned int *)&buf[25] = player->FlagPoints;
            Size += 15;
        }
        SendReliablePacket(billingServerStruct->connection, buf, Size, 1);
    }
}
// 405E70: using guessed type char var_3F1[1009];

//----- (00405F20) --------------------------------------------------------
void __cdecl SendBillerUserScorePacket(struct BILLING_SERVER_STRUCT * billingServerStruct, int PlayerId, const void *Score, unsigned int Size)
{
    char buf[1024]; // [sp+0h] [bp-400h]@2

    if ( PlayerId >= 0 )
    {
        *(unsigned int *)&buf[1] = PlayerId;
        buf[0] = 0x11;                             // 0x11 - Billing User Score
        memcpy(&buf[5], Score, Size);
        SendReliablePacket(billingServerStruct->connection, buf, Size + 5, 1);
    }
}

//----- (00405F80) --------------------------------------------------------
void __cdecl SendBillerPlayerNamePacketSomething(struct BILLING_SERVER_STRUCT *billingServerStruct, int a1, int a2, const void *a3, unsigned int len)
{
    unsigned int v5; // ebp@1
    char *v7; // eax@1
    char *v8; // ebx@1
    unsigned int lena; // [sp+24h] [bp+10h]@1

    //TODO: Comment lol Subspace VIE Developers got lazy and stopped using static arrays.
    v7 = AllocateMemory(len + 9);
    v7[0] = 0x06;                             // 0x06 - Billing PlayerName Packet
    *(unsigned int *)(&v7[1]) = a1;
    *(unsigned int *)(&v7[5]) = a2;
    memcpy(&v7[9], a3, len); // 9 bytes in is this. weird stuff
    SendReliablePacket(billingServerStruct->connection, v7, len + 9, 1);
    FreeMemory(v7);
}

//----- (00406010) --------------------------------------------------------
void __cdecl SendBillerUserPrivateChatPacket(struct BILLING_SERVER_STRUCT *billingServerStruct, int PlayerId, int BillingGroupId, const void *a4, unsigned int len)
{
    unsigned int v5; // ebp@1
    char *v7; // eax@1
    char *v8; // ebx@1
    int lena; // [sp+24h] [bp+10h]@1

    //TODO: Comment lol Subspace VIE Developers got lazy and stopped using static arrays.
    v7 = AllocateMemory(len + 9);
    v7[0] = 0x07;                             // 0x07 - Billing User Private Chat
    *(unsigned int *)(&v7[1]) = PlayerId;
    *(unsigned int *)(&v7[5]) = BillingGroupId;
    memcpy(&v7[9], a4, len); // 9 bytes in is this. weird stuff
    SendReliablePacket(billingServerStruct->connection, v7, len + 9, 1);
    FreeMemory(v7);
}

//----- (004060A0) --------------------------------------------------------
void __cdecl SendBillerZoneRevokePermitPacket(struct BILLING_SERVER_STRUCT *billingServerStruct, int a1, int a2, const void *a3, unsigned int len)
{
    unsigned int v5; // ebp@1
    char *v7; // eax@1
    char *v8; // ebx@1
    unsigned int lena; // [sp+24h] [bp+10h]@1

    //TODO: Comment lol Subspace VIE Developers got lazy and stopped using static arrays.
    v7 = AllocateMemory(len + 9);
    v7[0] = 0x12;                         // 0x12 - Billing Something with Zone Player *Revoke or *Permit
    *(unsigned int *)(&v7[1]) = a1;
    *(unsigned int *)(&v7[5]) = a2;
    memcpy(&v7[9], a3, len); // 9 bytes in is this. weird stuff
    SendReliablePacket(billingServerStruct->connection, v7, len + 9, 1);
    FreeMemory(v7);
}

//----- (00406130) --------------------------------------------------------
int __cdecl GetBillerLastReconnectTime(struct BILLING_SERVER_STRUCT *billingServerStruct)
{
    return billingServerStruct->connection->MenuKickOutDelayTimer;
}
// 406130: using guessed type int __cdecl GetBillerLastReconnectTime(unsigned int);

//----- (00406140) --------------------------------------------------------
signed int __cdecl IsBillingServerDisconnected(struct BILLING_SERVER_STRUCT *billingServerStruct)
{
    __int64 v2; // qax@3
    char *packetBuffer; // eax@5
    void (__cdecl *v6)(char *, unsigned int); // ecx@6
    signed int result; // eax@9
    char buf; // [sp+Bh] [bp-9h]@4
    int packetSize; // [sp+Ch] [bp-8h]@5
    struct CONNECTION *connection; // [sp+10h] [bp-4h]@5

    if ( CheckState(billingServerStruct->connection) != 2 //2 = Encryption is initialized
            || GetBillingServerRelOut(billingServerStruct->connection, 0) >= 255 )
    {
        result = 1;
    }
    else
    {
        if ( (GetTickCount() / 0xA - billingServerStruct->GetTickCountValue) > 3000 )
        {
            billingServerStruct->GetTickCountValue = GetTickCount() / 0xA;
            buf = 1;
            SendReliablePacket(billingServerStruct->connection, &buf, 1, 1);
        }
        while ( packetBuffer = sub_41B1B0(billingServerStruct->MainServerStructure, &packetSize, connection) )
        {
            v6 = (void (__cdecl *)(char *, unsigned int))billingServerStruct->HandleBillerPacketFunctionAddress;
            if ( v6 )
                v6(packetBuffer, packetSize); //anonymous function call.
        }
        result = 0;
    }
    return result;
}
// 41B950: using guessed type int __cdecl CheckState(unsigned int);

//----- (00406210) --------------------------------------------------------
void __cdecl ReadCompleteSettings(struct struc_2 *ConfigSETPointer, const char *Filename)
{
    struct struc_2 *v2; // ebp@1
    int v3; // esi@1

    FILE *v4; // eax@1
    FILE *v5; // edi@1
    char *v6; // edx@4
    char v7; // al@4
    struct struc_4 *v8; // edi@4
    char *i; // ecx@4
    char *v10; // eax@10
    char *v11; // edx@10
    char j; // cl@10
    char k; // cl@14
    int v14; // eax@18
    char v15; // cl@18
    char *l; // edx@18
    FILE *v18; // [sp+10h] [bp-204h]@1
    char Buf[512]; // [sp+14h] [bp-200h]@3
    int count; //fix 1
    int equalsPosition; //fix 2
    char CategoryName[30]; //Fix 3
    char SettingName[36]; //Fix 4
    char SettingValue[100]; //Fix 5

    strcpy(ConfigSETPointer->Filename, Filename);             // FileName
    ConfigSETPointer->TotalSettingsCategoryCount = 0;
    ConfigSETPointer->TotalSettingsCount = 0;
    ConfigSETPointer->ShouldCreateFile = 0;
    v3 = -1;
    v4 = fopen(ConfigSETPointer->Filename, "rt");

    if ( v4 )
    {
        if ( !feof(v4) )
        {
            do
            {
                Buf[0] = 0;
                fgets(Buf, 512, v4);

                if ( Buf[0] == '[' )
                {
                    v3 = ConfigSETPointer->TotalSettingsCategoryCount;
                    ConfigSETPointer->TotalSettingsCategoryCount++;

                    count = 0;
                    while(count < 30)
                    {
                        if ( Buf[count + 1] == ']' )
                            break;
                        CategoryName[count] = Buf[count + 1]; //SomeString = Catagory like [PrizeWeight]
                        count++;
                    }
                    CategoryName[count] = 0;
                }
                else
                {
                    if ( isalpha(Buf[0]) && v3 != -1 )
                    {
                        count = 0;
                        while(count < 36)
                        {
                            if ( Buf[count] == ']' )
                                break;
                            if ( Buf[count] == '=' )
                                break;
                            if ( Buf[count] == ' ' )
                                break;
                            SettingName[count] = Buf[count]; //Last Setting Counter and SettingName = QuickCharge
                            count++;
                        }
                        SettingName[count] = 0;

                        equalsPosition = 0;
                        while(Buf[equalsPosition++] != '=');

                        if ( Buf[equalsPosition] ) //not null
                        {
                            count = 0;
                            while(count < 100)
                            {
                                if(!Buf[equalsPosition + count])
                                    break;
                                SettingValue[count] = Buf[equalsPosition + count]; //Settings Value goes here String or Number
                                count++;
                            }
                            SettingValue[count] = 0;
                            Trim(SettingValue);
                            FillArenaSettingsStruct(ConfigSETPointer, CategoryName, SettingName, SettingValue); //Str2 = PrizeWeight, a3 = QuickCharge, Source = 80
                        }
                    }
                }
            }
            while ( !feof(v4) );
        }
        fclose(v4);
    }
}
// 407730: using guessed type unsigned int __cdecl Trim(unsigned int);

//----- (004063F0) --------------------------------------------------------
void __cdecl WriteCompleteSettings(struct struc_2 *struc2)
{
    FILE *v2; // ebp@2
    int v3; // edi@4
    int v4; // ebx@6
    char *v5; // esi@7
    int v6; // [sp+8h] [bp-8h]@3
    char *v7; // [sp+Ch] [bp-4h]@1

    if ( struc2->ShouldCreateFile )
    {
        v2 = fopen(struc2->Filename, "wt");
        if ( v2 )
        {
            if ( struc2->TotalSettingsCategoryCount > 0 )
            {
                v3 = 0;
                do
                {
                    if ( struc2->SettingCategory[v3].SettingsInCategory > 0 )
                    {
                        fprintf(v2, "[%s]\n", struc2->SettingCategory[v3].CategoryName);

                        int SettingCounter = 0; //fix 1
                        while ( SettingCounter < struc2->TotalSettingsCount ) //while not equal
                        {
                            if ( struc2->Setting[SettingCounter].SettingId == struc2->SettingCategory[v3].SettingId ) {
                                v5 = struc2->Setting[SettingCounter].SettingName;
                                v7 = struc2->Setting[SettingCounter].SettingValue;
                                fprintf(v2, "%s=%s\n", v5, v7);
                            }
                            SettingCounter++;
                        }

                        fprintf(v2, "\n");
                    }
                    ++v3;
                }
                while ( v3 < struc2->TotalSettingsCategoryCount );
            }
            fclose(v2);
        }
    }
}

//----- (004064D0) --------------------------------------------------------
int __cdecl GetCFGSettingInteger(struct struc_2 *Str1, const char *Str2, const char *a3, int a4)
{
    struct struc_2 *v4; // ebp@1
    unsigned int CurrentCategoryId; // edi@2
    int CurrentSettingId; // esi@4
    int SettingCounter; // ebx@4
    const char *v8; // ebp@5
    int result; // eax@10
    int v10; // [sp+10h] [bp-18h]@1
    struct struc_2 *v11; // [sp+14h] [bp-14h]@1
    char Source[16]; // [sp+18h] [bp-10h]@10

    //If there is no Categories yet then it's the first time entering here.
    if ( Str1->TotalSettingsCategoryCount <= 0 ) {
        sprintf(Source, "%d", a4);
        FillArenaSettingsStruct(Str1, Str2, a3, Source); //Str2 = PrizeWeight, a3 = QuickCharge, Source = 80
        result = a4; //a4 = 80 (in decimal)
    } else {
        //Contains categories so keep it up.
        CurrentCategoryId = 0;
        CurrentSettingId = 0;

        //Find Settings Id for a specific Settings Category.
        while ( 1 )
        {
            if ( !stricmp( Str1->SettingCategory[CurrentCategoryId].CategoryName, Str2) ) //if equal go in
            {
                CurrentSettingId = Str1->SettingCategory[CurrentCategoryId].SettingId;
                //If Category has atleast one setting then it's useful otherwise it's just a corrupt place holder thingy.
                if ( Str1->SettingCategory[CurrentCategoryId].SettingsInCategory > 0 )
                    break;
            }
            ++CurrentCategoryId;
            //If Ran out of Categories then try to create a category by going into FillArenaSettingsStruct
            if ( CurrentCategoryId >= Str1->TotalSettingsCategoryCount ) {
                sprintf(Source, "%d", a4);
                FillArenaSettingsStruct(Str1, Str2, a3, Source); //Str2 = PrizeWeight, a3 = QuickCharge, Source = 80
                result = a4; //a4 = 80 (in decimal)
                break;
            }
        }

        SettingCounter = 0;
        //Find SettingName in Current Settings Category
        //Loops all Settings and filters them by only the same SettingId

        while ( SettingCounter < Str1->TotalSettingsCount ) //while not equal
        {
            //stricmp(Str1->Setting[v7].SettingName, a3)     //while not equal
            if ( Str1->Setting[SettingCounter].SettingId == CurrentSettingId ) {
                if ( !stricmp(Str1->Setting[SettingCounter].SettingName, a3) ) {     //if equals
                    result = atoi(Str1->Setting[SettingCounter].SettingValue);
                    break;
                }
            }
            SettingCounter++;
        }

        //Couldn't found the Setting with that SettingId
        if( SettingCounter >= Str1->TotalSettingsCategoryCount ) {
            sprintf(Source, "%d", a4);
            FillArenaSettingsStruct(Str1, Str2, a3, Source); //Str2 = PrizeWeight, a3 = QuickCharge, Source = 80
            result = a4; //a4 = 80 (in decimal)
        }
    }
    return result;
}

//----- (004065C0) --------------------------------------------------------
void __cdecl GetCFGSettingString(struct struc_2 *Str1, char *Str2, char *a3, char *Source, char *Dest, size_t Count)
{
    struct struc_2 *v4; // ebp@1
    unsigned int CurrentCategoryId; // edi@2
    int CurrentSettingId; // esi@4
    int SettingCounter; // ebx@4
    const char *v8; // ebp@5
    int v10; // [sp+10h] [bp-18h]@1
    struct struc_2 *v11; // [sp+14h] [bp-14h]@1
    char *result; // [sp-8h] [bp-20h]@10

    //If there is no Categories yet then it's the first time entering here.
    if ( Str1->TotalSettingsCategoryCount <= 0 ) {
        FillArenaSettingsStruct(Str1, Str2, a3, Source); //Str2 = PrizeWeight, a3 = QuickCharge, Source = 'String Answer'
        result = Source; //Just return what you put in, Source = 'Sheep Greeting Message -- dolly' (in string)
    } else {
        //Contains categories so keep it up.
        CurrentCategoryId = 0;
        CurrentSettingId = 0;

        //Find Settings Id for a specific Settings Category.
        while ( 1 )
        {
            if ( !stricmp( Str1->SettingCategory[CurrentCategoryId].CategoryName, Str2) ) //if equal go in
            {
                CurrentSettingId = Str1->SettingCategory[CurrentCategoryId].SettingId;
                //If Category has atleast one setting then it's useful otherwise it's just a corrupt place holder thingy.
                if ( Str1->SettingCategory[CurrentCategoryId].SettingsInCategory > 0 )
                    break;
            }
            ++CurrentCategoryId;
            //If Ran out of Categories then try to create a category by going into FillArenaSettingsStruct
            if ( CurrentCategoryId >= Str1->TotalSettingsCategoryCount ) {
                FillArenaSettingsStruct(Str1, Str2, a3, Source); //Str2 = PrizeWeight, a3 = QuickCharge, Source = 80
                result = Source; //Just returns what you put in, Source = 'Sheep Greeting Message -- dolly' (in string)
                break;
            }
        }

        SettingCounter = 0;
        //Find SettingName in Current Settings Category
        //Loops all Settings and filters them by only the same SettingId

        while ( SettingCounter < Str1->TotalSettingsCount ) //while not equal
        {
            //stricmp(Str1->Setting[v7].SettingName, a3)     //while not equal
            if ( Str1->Setting[SettingCounter].SettingId == CurrentSettingId ) {
                if ( !stricmp(Str1->Setting[SettingCounter].SettingName, a3) ) {     //if equals
                    result = Str1->Setting[SettingCounter].SettingValue;
                    break;
                }
            }
            SettingCounter++;
        }

        //Couldn't found the Setting with that SettingId
        if( SettingCounter >= Str1->TotalSettingsCount ) {
            FillArenaSettingsStruct(Str1, Str2, a3, Source); //Str2 = PrizeWeight, a3 = QuickCharge, Source = 80
            result = Source; //Just returns what you put in, Source = 'Sheep Greeting Message -- dolly' (in string)
        }
    }
    strncpy(Dest, result, Count);
    Dest[Count - 1] = 0;
}

//----- (004066B0) --------------------------------------------------------
void __cdecl sub_4066B0(struct struc_2 *strucValue, const char *Str2, const char *a3, const char *Source, char *Dest, size_t Count)
{
    struct struc_2 *v6; // ebx@1
    unsigned int v7; // edi@2
    int v8; // esi@4
    int v9; // ebp@4
    const char *v10; // ebx@5
    size_t v11; // edi@10
    char *v12; // [sp-8h] [bp-20h]@10
    size_t v13; // [sp-4h] [bp-1Ch]@10
    int v14; // [sp+10h] [bp-8h]@1
    struct struc_2 *v15; // [sp+14h] [bp-4h]@1

    v14 = 0;
    if ( strucValue->TotalSettingsCategoryCount <= 0 )
    {
LABEL_10:
        v12 = (char *)Source;
    }
    else
    {
        v7 = 0;
        while ( 1 )
        {
            if ( !stricmp(strucValue->SettingCategory[v7].CategoryName, Str2) )
            {
                v8 = strucValue->SettingCategory[v7].SettingId;
                v9 = 0;
                if ( strucValue->SettingCategory[v7].SettingsInCategory > 0 )
                    break;
            }
LABEL_9:
            ++v7;
            ++v14;
            if ( v14 >= strucValue->TotalSettingsCategoryCount )
                goto LABEL_10;
        }
        while ( stricmp(strucValue->Setting[v8].SettingName, a3) )
        {
            ++v9;
            ++v8;
            if ( v9 >= strucValue->SettingCategory[v7].SettingsInCategory )
            {
                goto LABEL_9;
            }
        }
        v12 = strucValue->Setting[v8].SettingValue; //what is this?
    }
    strncpy(Dest, v12, Count);
    Dest[Count - 1] = 0;
}

//----- (00406790) --------------------------------------------------------
void __cdecl FillArenaSettingsStruct(struct struc_2 *Str1, const char *Str2, const char *a3, const char *Source)
{
    struct struc_2 *v4; // ebp@1
    int CurrentCategoryId; // esi@1
    int v6; // eax@1
    int v7; // edi@2
    int v8; // eax@5
    char *v9; // esi@5
    int v10; // eax@5
    int v11; // ebx@7
    int v12; // ecx@7
    int v13; // esi@7
    const char *v14; // edi@8
    unsigned int v15; // ecx@13
    const char *v16; // edi@19
    signed int v17; // ecx@19
    bool v18; // zf@21
    int v19; // [sp+10h] [bp-Ch]@7
    char *v20; // [sp+14h] [bp-8h]@7
    int SettingCounter; //fix 1

    CurrentCategoryId = 0;

    if ( Str1->TotalSettingsCategoryCount <= 0 ) {
        //First time, first Category ONLY, Creates a new Settings Category and adds a new Setting.
        strcpy(Str1->SettingCategory[Str1->TotalSettingsCategoryCount].CategoryName, Str2); //Str2 = PrizeWeight
        Str1->SettingCategory[Str1->TotalSettingsCategoryCount].SettingId = Str1->TotalSettingsCount;
        Str1->SettingCategory[Str1->TotalSettingsCategoryCount].SettingsInCategory = 1;
        ++Str1->TotalSettingsCategoryCount;

        Str1->Setting[Str1->TotalSettingsCount].SettingId = Str1->TotalSettingsCount; //this is used to create a link with 2 arrays
        strcpy(Str1->Setting[Str1->TotalSettingsCount].SettingName, a3); //a3 = QuickCharge
        strncpy(Str1->Setting[Str1->TotalSettingsCount].SettingValue, Source, 0x64); //Source = 80
        Str1->Setting[Str1->TotalSettingsCount].SettingValue[99] = 0;
        ++Str1->TotalSettingsCount;
    } else {
        //Contains a Category Name, check all Categories to find right one.
        while ( 1 ) {
            if (stricmp(Str1->SettingCategory[CurrentCategoryId].CategoryName, Str2) ) //check all strings in SettingCategory against Str2
            {
                ++CurrentCategoryId;
                if ( CurrentCategoryId >= Str1->TotalSettingsCategoryCount ) {
                    //No more categories, Creates a new category & adds setting
                    strcpy(Str1->SettingCategory[Str1->TotalSettingsCategoryCount].CategoryName, Str2); //Str2 = PrizeWeight
                    Str1->SettingCategory[Str1->TotalSettingsCategoryCount].SettingId = Str1->TotalSettingsCount;
                    Str1->SettingCategory[Str1->TotalSettingsCategoryCount].SettingsInCategory = 1;
                    ++Str1->TotalSettingsCategoryCount;

                    Str1->Setting[Str1->TotalSettingsCount].SettingId = Str1->TotalSettingsCount; //this is used to create a link with 2 arrays
                    strcpy(Str1->Setting[Str1->TotalSettingsCount].SettingName, a3); //a3 = QuickCharge
                    strncpy(Str1->Setting[Str1->TotalSettingsCount].SettingValue, Source, 0x64); //Source = 80
                    Str1->Setting[Str1->TotalSettingsCount].SettingValue[99] = 0;
                    ++Str1->TotalSettingsCount;
                    return;
                }
            } else {
                break; //Found it.
            }
        }

        //At this point we have either a CurrentCategoryId which is either OLD or NEWLY CREATED.
        SettingCounter = 0;
        //Loops all Settings and filters them by only the same SettingId
        //If it's OLD ONLY then we have to replace it's values properly, otherwise create new setting.
        while ( SettingCounter < Str1->TotalSettingsCount ) //while not equal
        {
            //stricmp(Str1->Setting[v7].SettingName, a3)     //while not equal
            if ( Str1->Setting[SettingCounter].SettingId == Str1->SettingCategory[CurrentCategoryId].SettingId ) {
                if ( !stricmp(Str1->Setting[SettingCounter].SettingName, a3) )    //if equals
                    break;
            }
            SettingCounter++;
        }

        if( SettingCounter >= Str1->TotalSettingsCount ) { //Not Found
            strcpy(Str1->Setting[Str1->TotalSettingsCount].SettingName, a3);
            strncpy(Str1->Setting[Str1->TotalSettingsCount].SettingValue, Source, 0x64);
            Str1->Setting[Str1->TotalSettingsCount].SettingValue[99] = 0;
            Str1->Setting[Str1->TotalSettingsCount].SettingId = Str1->SettingCategory[CurrentCategoryId].SettingId;
            ++Str1->TotalSettingsCount;
            ++Str1->SettingCategory[CurrentCategoryId].SettingsInCategory;
        } else {
            //Overwrites old settings with new ones, I've omitted this code.
            //As it keeps overwriting all the settings with the default ones if any changes happen.
            /*
            if ( stricmp(Str1->Setting[SettingCounter].SettingValue, Source) )
                Str1->ShouldCreateFile = 1;
            strcpy(Str1->Setting[SettingCounter].SettingName, a3);
            strncpy(Str1->Setting[SettingCounter].SettingValue, Source, 0x64);
            Str1->Setting[SettingCounter].SettingValue[99] = 0;
            Str1->Setting[SettingCounter].SettingId = Str1->SettingCategory[CurrentCategoryId].SettingId;
            */
        }
    }
}

//----- (00406A30) --------------------------------------------------------
void __cdecl LoadBMPHeader(struct BMP_FILE_STRUCT *BMPFileStruct, const char *Source)
{
    struct BMP_FILE_STRUCT *v2; // esi@1
    FILE *fileHandle; // eax@1
    int v5; // eax@6
    int v6; // eax@6
    int v7; // eax@6
    int v8; // edx@6
    char DstBuf[6]; // [sp+Ch] [bp-8h]@2

    strncpy(BMPFileStruct->FileName, Source, 0x100);
    BMPFileStruct->FileName[255] = 0;
    BMPFileStruct->BMPPointer = 0;
    BMPFileStruct->TotalMapTiles = 0;
    fileHandle = fopen(BMPFileStruct->FileName, "rb");

    if ( fileHandle )
    {
        BMPFileStruct->BMPFileSizeOffset = 0;
        if ( fread(DstBuf, 1, 6, fileHandle) == 6 && DstBuf[0] == 'B' && DstBuf[1] == 'M' ) // Load BMP Header.
            BMPFileStruct->BMPFileSizeOffset = *(unsigned int *)&DstBuf[2];// 4 bytes after BM Header
        fseek(fileHandle, BMPFileStruct->BMPFileSizeOffset, 0);
        v5 = _fileno(fileHandle);
        BMPFileStruct->TotalMapTiles = (unsigned int)(_filelength(v5) - BMPFileStruct->BMPFileSizeOffset) / 4;
        BMPFileStruct->BMPPointer = AllocateMemory(4 * BMPFileStruct->TotalMapTiles);
        fread((void *)BMPFileStruct->BMPPointer, BMPFileStruct->TotalMapTiles, 4, fileHandle);
        fclose(fileHandle);
    }
    BMPFileStruct->field_104 = 0;
}
// 41F1B0: using guessed type unsigned int __cdecl _filelength(unsigned int);

//----- (00406B30) --------------------------------------------------------
void __cdecl sub_406B30(struct BMP_FILE_STRUCT *BMPFileStruct)
{
    struct BMP_FILE_STRUCT *v1; // esi@1
    FILE *v2; // edi@3
    int v3; // ST0C_4@5
    int v4; // eax@5
    int v5; // esi@6

    if ( BMPFileStruct->field_104 )
    {
        if ( BMPFileStruct->BMPPointer )
        {
            v2 = fopen(BMPFileStruct->FileName, "rb+");
            if ( v2 || (v2 = fopen(BMPFileStruct->FileName, "wb")) != 0 )
            {
                fseek(v2, BMPFileStruct->BMPFileSizeOffset, 0);
                fwrite((const void *)BMPFileStruct->BMPPointer, BMPFileStruct->TotalMapTiles, 4, v2);
                v3 = BMPFileStruct->BMPFileSizeOffset + 4 * BMPFileStruct->TotalMapTiles;
                v4 = _fileno(v2);
                _chsize(v4, v3);
                fclose(v2);
            }
        }
    }
    if ( BMPFileStruct->BMPPointer )
        FreeMemory(BMPFileStruct->BMPPointer);
}
// 41E210: using guessed type unsigned int __cdecl _chsize(unsigned int, unsigned int);

//----- (00406BF0) --------------------------------------------------------
void __cdecl GetTileValue(struct BMP_FILE_STRUCT *BMPFile, int TileCounter, int *TileValuePointer)
{
    int v3; // edx@1
    int v4; // eax@1
    int v5; // eax@1
    int v6; // esi@1
    int v7; // eax@1

    // //Looks very complicated with those XOR's and bitwise cleans
    v3 = *TileValuePointer ^ ((unsigned __int16)*TileValuePointer ^ (unsigned __int16)BMPFile->BMPPointer[TileCounter]) & 0xFFF;
    *TileValuePointer = v3;
    v4 = v3 ^ BMPFile->BMPPointer[TileCounter];
    v5 = v3 ^ v4 & 0xFFF000;
    *TileValuePointer = v5;
    v6 = BMPFile->BMPPointer[TileCounter];
    v7 = v6 ^ v5;
    *TileValuePointer = v6 ^ v7 & 0xFFFFFF;
}

//----- (00406C50) --------------------------------------------------------
void __cdecl DoBrickDrop(unsigned char *MapData, int XTiles, int YTiles, int *X1Tile, int *Y1Tile, int *X2Tile, int *Y2Tile, int BrickSpanSize)
{
    int v8; // ebx@1
    char *MapDatay; // esi@2
    int tempXTiles1; // ebx@7
    int i; // edi@7
    int tempXTiles2; // edi@10
    int tempYTiles; // ecx@12
    int v14; // eax@13
    int tempYTiles1; // ecx@16
    int YTiless; // esi@16
    char *v17; // eax@17
    int tempYTiles2; // esi@20
    int v19; // eax@22
    int v20; // eax@25
    signed int j; // ecx@27
    int v22; // eax@38
    signed int v23; // eax@40
    char *v24; // edi@41
    char *v25; // ebx@41

    v8 = XTiles;
    if ( XTiles >= 0 )
    {
        do
        {
            if ( *(&MapData[1024 * YTiles] + v8) )
                break;
            --v8;
        }
        while ( v8 >= 0 );
    }
    tempXTiles1 = v8 + 1;
    for ( i = XTiles; i < 1024; ++i )
    {
        if ( *(&MapData[1024 * YTiles] + i) )
            break;
    }
    tempXTiles2 = i - 1;
    if ( tempXTiles2 < tempXTiles1 )
        tempXTiles2 = tempXTiles1;
    tempYTiles = YTiles;
    if ( YTiles >= 0 )
    {
        v14 = (int)(&MapData[1024 * YTiles] + XTiles);
        do
        {
            if ( *(unsigned char *)v14 )
                break;
            --tempYTiles;
            v14 -= 1024;
        }
        while ( tempYTiles >= 0 );
    }
    tempYTiles1 = tempYTiles + 1;
    YTiless = YTiles;
    if ( YTiles < 1024 )
    {
        v17 = &MapData[1024 * YTiles] + XTiles;
        do
        {
            if ( *v17 )
                break;
            ++YTiless;
            v17 += 1024;
        }
        while ( YTiless < 1024 );
    }
    tempYTiles2 = YTiless - 1;
    if ( tempYTiles2 < tempYTiles1 )
        tempYTiles2 = tempYTiles1;
    v19 = BrickSpanSize / 2;
    if ( tempXTiles2 - tempXTiles1 >= tempYTiles2 - tempYTiles1 )
    {
        if ( tempYTiles1 <= YTiles - v19 )
            tempYTiles1 = YTiles - v19;
        v22 = YTiles + v19;
        if ( tempYTiles2 >= v22 )
            tempYTiles2 = v22;
        v23 = tempYTiles2 - tempYTiles1 + 1;
        if ( v23 < BrickSpanSize )
        {
            v24 = &MapData[1024 * tempYTiles1] + XTiles;
            v25 = &MapData[1024 * (tempYTiles2 + 1)] + XTiles;
            do
            {
                if ( tempYTiles1 - 1 < 0 || *(v24 - 1024) )
                {
                    if ( tempYTiles2 >= 1023 || *v25 )
                        break;
                    ++tempYTiles2;
                    v25 += 1024;
                }
                else
                {
                    --tempYTiles1;
                    v24 -= 1024;
                }
                ++v23;
            }
            while ( v23 < BrickSpanSize );
        }
        *Y1Tile = tempYTiles1;
        *Y2Tile = tempYTiles2;
        *X1Tile = XTiles;
        *X2Tile = XTiles;
    }
    else
    {
        if ( tempXTiles1 <= XTiles - v19 )
            tempXTiles1 = XTiles - v19;
        v20 = XTiles + v19;
        if ( tempXTiles2 >= v20 )
            tempXTiles2 = v20;
        for ( j = tempXTiles2 - tempXTiles1 + 1; j < BrickSpanSize; ++j )
        {
            if ( tempXTiles1 - 1 < 0 || *(&MapData[1024 * YTiles - 1] + tempXTiles1) )
            {
                if ( tempXTiles2 >= 1023 || *(&MapData[1024 * YTiles + 1] + tempXTiles2) )
                    break;
                ++tempXTiles2;
            }
            else
            {
                --tempXTiles1;
            }
        }
        *X1Tile = tempXTiles1;
        *X2Tile = tempXTiles2;
        *Y1Tile = YTiles;
        *Y2Tile = YTiles;
    }
}

//----- (00406E30) --------------------------------------------------------
signed int __cdecl GenerateLVLChecksum(unsigned char *MapData, signed int Key)
{
    signed int v2; // edi@1
    signed int v3; // ecx@1
    int v4; // eax@2
    char *v5; // esi@2
    unsigned int v6; // ebx@2
    int v7; // edx@3
    char *v8; // ecx@3
    char v9; // al@4
    int MapDataa; // [sp+8h] [bp+4h]@2

    v2 = Key;
    v3 = (unsigned char)((char)Key % -32);
    if ( v3 < 1024 )
    {
        v4 = 1024 - Key % 31;
        v5 = &MapData[1024 * v3] + Key % 31;
        MapDataa = 1024 - Key % 31;
        v6 = (unsigned int)(1055 - v3) >> 5;        // >> 5 same as divide by 32. (powers of 2), ignore this in checksums for speed lol
        do
        {
            v7 = (int)&v5[v4];
            v8 = v5;
            if ( v5 < &v5[v4] )
            {
                do
                {
                    v9 = *v8;
                    if ( *v8 && (unsigned char)v9 < 0xA1 || v9 == 0xAB )
                        Key += (unsigned char)*v8 ^ v2;
                    v8 += 31;
                }
                while ( (unsigned int)v8 < v7 );
                v4 = MapDataa;
            }
            v5 += 32768;
            --v6;
        }
        while ( v6 );
    }
    return Key;
}

//----- (00406ED0) --------------------------------------------------------
bool __cdecl IsMapFileValid(const char *Filename)
{
    FILE *fileHandle; // eax@1
    unsigned int BMPFileOffset; // edi@2
    int v5; // eax@6
    unsigned int v6; // eax@6
    unsigned int v7; // eax@8
    size_t v8; // esi@8
    int *v9; // edi@10
    int *v10; // ecx@11
    int v11; // edx@13
    bool result; // al@17
    char DstBuf[6]; // [sp+8h] [bp-8h]@2

    result = true;
    fileHandle = fopen(Filename, "rb");
    if ( fileHandle )
    {
        BMPFileOffset = 0;
        if ( fread(DstBuf, 1u, 6u, fileHandle) == 6 && DstBuf[0] == 'B' && DstBuf[1] == 'M' ) // Load BMP Header
            BMPFileOffset = *(unsigned int *)&DstBuf[2];
        v5 = _fileno(fileHandle);
        v6 = _filelength(v5);
        if ( BMPFileOffset >= v6
                || BMPFileOffset < 0
                || (v7 = v6 - BMPFileOffset, v8 = v7 / 4, 4 * (v7 / 4) != v7)
                || (fseek(fileHandle, BMPFileOffset, 0), (signed int)v8 <= 0) )
        {
            fclose(fileHandle);
            result = 0;
        }
        else
        {
            v9 = (int *)AllocateMemory(4 * v8);
            fread(v9, v8, 4, fileHandle);
            if ( v8 > 0 )
            {
                do
                {
                    if ( (v9[v8] & 0xFFF) > 0x400	//1024 [X]? or Y limit exceeded
                            || (v9[v8] & 0xFFF000) > 0x400000	//1024 X or [Y]? limit exceeded
                            || !(v9[v8] & 0xFF000000) ) //Tile Id is equal to zero I assume?
                        result = false; //can't return must FreeMemory below, optimize later.
                    --v8;
                }
                while ( v8 );
            }
            FreeMemory(v9);
            fclose(fileHandle);
        }
    }
    else
    {
        result = false;
    }
    return result;
}
// 41F1B0: using guessed type unsigned int __cdecl _filelength(unsigned int);

//----- (00407000) --------------------------------------------------------
void __cdecl InitializeTextFile(struct TEXT_FILE_STRUCT *textFile, const char *Source, int makeUpperCase)
{
    textFile->MakeUpperCase = makeUpperCase;
    if ( Source )
    {
        strncpy(textFile->FileName, Source, 0x100);
        textFile->FileName[255] = 0;
    }
    else
    {
        textFile->FileName[0] = 0;
    }
    textFile->Counter = 0;
    textFile->Pointer = 0;
    LoadTextFile(textFile, 1);
}

//----- (00407060) --------------------------------------------------------
void __cdecl CleanTextFileMemory(struct TEXT_FILE_STRUCT *textFile)
{
    int count; // edi@2

    if ( textFile->Pointer )
    {
        count = 0;
        if ( textFile->Counter > 0 )
        {
            do
                FreeMemory(&textFile->Pointer[count++]);
            while ( count < textFile->Counter );
        }
        ExpandMemory(textFile->Pointer, 0, 1);
        textFile->Pointer = 0;
        textFile->Counter = 0;
    }
}
// 407060: using guessed type int __cdecl CleanTextFileMemory(unsigned int);

//----- (004070D0) --------------------------------------------------------
void __cdecl LoadTextFile(struct TEXT_FILE_STRUCT *textFile, int a2)
{
    struct TEXT_FILE_STRUCT *textFilee; // ebp@1
    int i; // esi@5
    FILE *FileHandle; // eax@9
    FILE *v5; // esi@9
    char *j; // eax@12
    char Buf[512]; // [sp+10h] [bp-200h]@11

    if ( a2 || !textFile->FileName[0] || IsFileLastWrittenTime(textFile->FileName, &textFile->LastFileEditTime) )
    {
        if ( textFile->Pointer )
        {   //Clear Existing Text File.
            for ( i = 0; i < textFile->Counter; ++i )
                FreeMemory(&textFile->Pointer[i]);
            ExpandMemory(textFile->Pointer, 0, 1);
            textFile->Pointer = 0;
            textFile->Counter = 0;
        }
        if ( textFile->FileName[0] )
        {
            FileHandle = fopen(textFile->FileName, "rt");
            if ( FileHandle )
            {
                if ( !feof(FileHandle) )
                {
                    do
                    {
                        if ( fgets(Buf, 512, FileHandle) )
                        {
                            //Load line backwards and/or until a space is encountered
                            for ( j = &Buf[strlen(Buf)]; j != Buf; --j )
                            {
                                if ( *(j - 1) >= ' ' )
                                    break;
                            }
                            *j = 0;
                            if ( strlen(Buf) != 0 )
                                AddLineTextFile(textFile, Buf);
                        }
                    }
                    while ( !feof(FileHandle) );
                }
                fclose(FileHandle);
            }
        }
    }
}
// 4070D0: using guessed type char Buf[512];

//----- (00407200) --------------------------------------------------------
void __cdecl WriteTextFileToFile(struct TEXT_FILE_STRUCT *textFile)
{
    FILE *v2; // ebx@2
    int i; // esi@3

    if ( textFile->FileName[0] )
    {
        v2 = fopen(textFile->FileName, "wt");       // wt = Write In Text Mode
        if ( v2 )
        {
            for ( i = 0; i < textFile->Counter; ++i )
                fprintf(v2, "%s\n", textFile->Pointer[i]);
            fclose(v2);
        }
    }
}

//----- (00407260) --------------------------------------------------------
int __cdecl TextFileTotalLines(struct TEXT_FILE_STRUCT *textFile)
{
    return textFile->Counter;
}

//----- (00407270) --------------------------------------------------------
char * __cdecl TextFileByIndex(struct TEXT_FILE_STRUCT *textFile, int listMachineIndex)
{
    return textFile->Pointer[listMachineIndex];
}

//----- (00407280) --------------------------------------------------------
void __cdecl AddLineTextFile(struct TEXT_FILE_STRUCT *textFile, char *ChatMsgBuffer)
{
    int v3; // esi@1
    int v4; // eax@1
    int v5; // eax@5
    size_t v6; // ecx@5
    char *v7; // eax@5
    bool found; // [sp+10h] [bp-4h]@1

    v3 = 0;
    v4 = BinarySearch(
             (int)ChatMsgBuffer,
             (int)textFile->Pointer,
             textFile->Counter,
             sizeof(char *),
             (int (__cdecl *)(int, int))StringCompare,
             &found);
    if ( !found )
    {
        if ( v4 )
            v3 = (v4 - (unsigned int)textFile->Pointer) / sizeof(char *);

        textFile->Pointer = (char **)ExpandMemory(textFile->Pointer, sizeof(char *) * (textFile->Counter + 1), 2048);

        //Adds the pointer in between 2 pointers.
        memcpy(&textFile->Pointer[v3 + 1],
               &textFile->Pointer[v3],
               sizeof(char *) * (textFile->Counter + -v3));

        //(textFile->Counter + -v3));

        v7 = (char *)AllocateMemory(strlen(ChatMsgBuffer) + 1);// Make more memory for chat message
        strcpy(v7, ChatMsgBuffer);// Copy chat message into memory
        textFile->Pointer[v3] = v7;
        if ( textFile->MakeUpperCase )
            strupr(textFile->Pointer[v3]);// converts any lowercase characters in str to uppercase letters
        ++textFile->Counter;
    }
}

//----- (004073A0) --------------------------------------------------------
void __cdecl RemoveLineTextFile(struct TEXT_FILE_STRUCT *textFile, int Number)
{
    struct TEXT_FILE_STRUCT *v2; // esi@1
    int v3; // ecx@1
    //char *result; // eax@1

    FreeMemory(textFile->Pointer[Number]);

    memcpy(
        &textFile->Pointer[Number],
        &textFile->Pointer[Number + 1],
        sizeof(char *) * (textFile->Counter + -Number)); //any number multipled by 0x3FFFFFFF gives the negative of that number

    textFile->Pointer = (char **)ExpandMemory(textFile->Pointer, sizeof(char *) * textFile->Counter, 2048);
    textFile->Counter--;
}

//----- (00407420) --------------------------------------------------------
int __cdecl IsLineExistTextFile(struct TEXT_FILE_STRUCT *textFile, char *TextLine)
{
    int v3; // eax@1
    int result; // eax@2
    bool found; //fix 1

    v3 = BinarySearch(
             (int)TextLine,
             (int)textFile->Pointer,
             textFile->Counter,
             sizeof(char *),
             (int (__cdecl *)(int, int))StringCompare,
             &found);
    if ( found )
        result = (v3 - (unsigned int)textFile->Pointer) / sizeof(char *); //4 is probably pointer size so.. it might be 8 on 64bit pcs
    else
        result = -1;
    return result;
}

//----- (00407470) --------------------------------------------------------
int __cdecl StringCompare(int ElementString, int ArrayPointer)
{
    return _strcmpi((const char *)ElementString, *(const char **)ArrayPointer);
}

//----- (0041B580) --------------------------------------------------------
int __cdecl SomeOtherCompare(int _connection, int _ConnectionsArray)
{
    struct CONNECTION *v2; // ecx@1
    unsigned int v3; // esi@1
    int result; // eax@2
    int v5; // edx@5
    struct CONNECTION *connection = (struct CONNECTION *)_connection;
    struct CONNECTION **ConnectionsArray = (struct CONNECTION **)_ConnectionsArray;

    if ( connection->RemoteIP.s_addr <= (*ConnectionsArray)->RemoteIP.s_addr
            && connection->RemoteIP.s_addr >= (*ConnectionsArray)->RemoteIP.s_addr )
    {
        result = connection->RemotePort - (*ConnectionsArray)->RemotePort;
        if ( connection->dword6 != -1 )
        {
            if ( connection->RemotePort == (*ConnectionsArray)->RemotePort )
                result = connection->dword6 - (*ConnectionsArray)->PlayerId;
        }
    } else {
        result = 1;
    }
    return result;
}

//----- (00407490) --------------------------------------------------------
char *__cdecl GetSplitNextDirectoryIP(char *a1, char *Src)
{
    const char *v2; // esi@1
    int v3; // ecx@2
    char v4; // al@3
    char *i; // ecx@3

    *a1 = 0;
    v2 = Src;
    if ( isspace(*Src) == ' ' )
    {
        do
            v3 = (v2++)[1];
        while ( isspace(v3) == ' ' );
    }
    v4 = *v2;
    for ( i = a1; v4; ++v2 )
    {
        if ( v4 == ',' )
            break;
        *i = v4;
        v4 = v2[1];
        ++i;
    }
    *i = 0;
    if ( *v2 == ',' )
        ++v2;
    memcpy(Src, v2, strlen(v2) + 1);
    return a1;
}

//----- (00407510) --------------------------------------------------------
BOOL __cdecl IsFileLastWrittenTime(char * lpFileName, unsigned int *a2)
{
    unsigned int v2; // eax@1
    void *v3; // esi@1
    BOOL result; // eax@4
    struct _FILETIME LastWriteTime; // [sp+4h] [bp-18h]@2
    struct _FILETIME LastAccessTime; // [sp+Ch] [bp-10h]@2
    struct _FILETIME CreationTime; // [sp+14h] [bp-8h]@2

    v2 = (unsigned int)CreateFileA(lpFileName, 0x80000000, 0, 0, 3, 0x80, 0);
    v3 = (void *)v2;
    if ( v2 != -1 )
    {
        GetFileTime((HANDLE)v2, &CreationTime, &LastAccessTime, &LastWriteTime);
        CloseHandle(v3);
        v2 = LastWriteTime.dwLowDateTime;
    }
    if ( *a2 == v2 )
    {
        result = FALSE;
    }
    else
    {
        *a2 = v2;
        result = TRUE;
    }
    return result;
}

//----- (00407580) --------------------------------------------------------
int __cdecl BinarySearch(int ElementToFind, int Array, unsigned int TotalElements, unsigned int ElementSize, int (__cdecl *CompareFunc)(int, int), bool *IsFoundPointer)
{
    int mid; // esi@1
    int result; // eax@1
    int LowerBound; // ebp@2
    int UpperBound; // edi@2

    mid = 0;
    result = 0;
    *IsFoundPointer = false;
    if ( !TotalElements )
        return result; //NULL
    LowerBound = Array;
    UpperBound = Array + ElementSize * (TotalElements - 1);

    while ( 1 )
    {
        mid = LowerBound + ElementSize * ((UpperBound - LowerBound) / ElementSize / 2);
        result = CompareFunc(ElementToFind, mid);
        if ( result < 0 )
        {
            if ( mid == Array )
                return mid;
            UpperBound = mid - ElementSize;
            if ( LowerBound > UpperBound )
                return mid;
        }
        if(result == 0) //FOUND IT PRE-EXISTING ALREADY.
            *IsFoundPointer = true;
        if ( result <= 0 )
            break;
        LowerBound = mid + ElementSize;

        if ( LowerBound > UpperBound ) {
            if ( result > 0 )
                mid += ElementSize;
            return mid;
        }
    }
    if ( mid == Array ) {
        return Array;
    } else {
        while ( 1 )
        {
            mid -= ElementSize;

            if( CompareFunc(ElementToFind, mid) == 0 ) //FOUND IT PRE-EXISTING ALREADY.
                *IsFoundPointer = true;

            if ( CompareFunc(ElementToFind, mid) > 0 ) //ElementToFind != mid element.
                break;
            if ( mid == Array )
                return Array;
        }
        return mid + ElementSize;
    }
    return result;
}

//----- (00407630) --------------------------------------------------------
unsigned int __cdecl ReadIntegerINI(char * lpAppName, char * lpKeyName, unsigned int a3, char * lpFileName)
{
    unsigned int v4; // esi@1
    char Dest[16]; // [sp+10h] [bp-10h]@2

    v4 = GetPrivateProfileIntA(lpAppName, lpKeyName, -12345678, lpFileName);
    if ( v4 == -12345678 )
    {
        v4 = a3;
        sprintf(Dest, "%d", a3);
        WritePrivateProfileStringA(lpAppName, lpKeyName, Dest, lpFileName);
    }
    return v4;
}

//----- (00407690) --------------------------------------------------------
BOOL __cdecl ReadStringINI(char * lpAppName, char * lpKeyName, const char *a3, LPSTR lpString, unsigned int nSize, char * lpFileName)
{
    BOOL result; // eax@1

    GetPrivateProfileStringA(lpAppName, lpKeyName, "1x2y3z4", lpString, nSize, lpFileName);
    result = strcmp(lpString, "1x2y3z4");
    if ( !result )
    {
        strcpy(lpString, a3);
        result = WritePrivateProfileStringA(lpAppName, lpKeyName, lpString, lpFileName);
    }
    return result;
}

//----- (00407730) --------------------------------------------------------
void __cdecl Trim(unsigned char *s)
{
    int i;

    while (isspace (*s)) s++;   // skip left side white spaces
    for (i = strlen (s) - 1; (isspace (s[i])); i--) ;   // skip right side white spaces
    s[i + 1] = '\0';
}
// 407730: using guessed type unsigned int __cdecl Trim(unsigned int);

//----- (00407780) --------------------------------------------------------
unsigned int __cdecl CRC32(char *buffer, int fileSize)
{
    unsigned int v2; // ecx@1
    int v3; // eax@1
    int v4; // edx@2
    int v5; // eax@2
    //unsigned int v7[256]; // [sp+4h] [bp-400h]@1

    unsigned int CRC32Table[256] = {
        0x00000000, 0x77073096, 0xee0e612c, 0x990951ba,
        0x076dc419, 0x706af48f, 0xe963a535, 0x9e6495a3,
        0x0edb8832, 0x79dcb8a4, 0xe0d5e91e, 0x97d2d988,
        0x09b64c2b, 0x7eb17cbd, 0xe7b82d07, 0x90bf1d91,
        0x1db71064, 0x6ab020f2, 0xf3b97148, 0x84be41de,
        0x1adad47d, 0x6ddde4eb, 0xf4d4b551, 0x83d385c7,
        0x136c9856, 0x646ba8c0, 0xfd62f97a, 0x8a65c9ec,
        0x14015c4f, 0x63066cd9, 0xfa0f3d63, 0x8d080df5,
        0x3b6e20c8, 0x4c69105e, 0xd56041e4, 0xa2677172,
        0x3c03e4d1, 0x4b04d447, 0xd20d85fd, 0xa50ab56b,
        0x35b5a8fa, 0x42b2986c, 0xdbbbc9d6, 0xacbcf940,
        0x32d86ce3, 0x45df5c75, 0xdcd60dcf, 0xabd13d59,
        0x26d930ac, 0x51de003a, 0xc8d75180, 0xbfd06116,
        0x21b4f4b5, 0x56b3c423, 0xcfba9599, 0xb8bda50f,
        0x2802b89e, 0x5f058808, 0xc60cd9b2, 0xb10be924,
        0x2f6f7c87, 0x58684c11, 0xc1611dab, 0xb6662d3d,
        0x76dc4190, 0x01db7106, 0x98d220bc, 0xefd5102a,
        0x71b18589, 0x06b6b51f, 0x9fbfe4a5, 0xe8b8d433,
        0x7807c9a2, 0x0f00f934, 0x9609a88e, 0xe10e9818,
        0x7f6a0dbb, 0x086d3d2d, 0x91646c97, 0xe6635c01,
        0x6b6b51f4, 0x1c6c6162, 0x856530d8, 0xf262004e,
        0x6c0695ed, 0x1b01a57b, 0x8208f4c1, 0xf50fc457,
        0x65b0d9c6, 0x12b7e950, 0x8bbeb8ea, 0xfcb9887c,
        0x62dd1ddf, 0x15da2d49, 0x8cd37cf3, 0xfbd44c65,
        0x4db26158, 0x3ab551ce, 0xa3bc0074, 0xd4bb30e2,
        0x4adfa541, 0x3dd895d7, 0xa4d1c46d, 0xd3d6f4fb,
        0x4369e96a, 0x346ed9fc, 0xad678846, 0xda60b8d0,
        0x44042d73, 0x33031de5, 0xaa0a4c5f, 0xdd0d7cc9,
        0x5005713c, 0x270241aa, 0xbe0b1010, 0xc90c2086,
        0x5768b525, 0x206f85b3, 0xb966d409, 0xce61e49f,
        0x5edef90e, 0x29d9c998, 0xb0d09822, 0xc7d7a8b4,
        0x59b33d17, 0x2eb40d81, 0xb7bd5c3b, 0xc0ba6cad,
        0xedb88320, 0x9abfb3b6, 0x03b6e20c, 0x74b1d29a,
        0xead54739, 0x9dd277af, 0x04db2615, 0x73dc1683,
        0xe3630b12, 0x94643b84, 0x0d6d6a3e, 0x7a6a5aa8,
        0xe40ecf0b, 0x9309ff9d, 0x0a00ae27, 0x7d079eb1,
        0xf00f9344, 0x8708a3d2, 0x1e01f268, 0x6906c2fe,
        0xf762575d, 0x806567cb, 0x196c3671, 0x6e6b06e7,
        0xfed41b76, 0x89d32be0, 0x10da7a5a, 0x67dd4acc,
        0xf9b9df6f, 0x8ebeeff9, 0x17b7be43, 0x60b08ed5,
        0xd6d6a3e8, 0xa1d1937e, 0x38d8c2c4, 0x4fdff252,
        0xd1bb67f1, 0xa6bc5767, 0x3fb506dd, 0x48b2364b,
        0xd80d2bda, 0xaf0a1b4c, 0x36034af6, 0x41047a60,
        0xdf60efc3, 0xa867df55, 0x316e8eef, 0x4669be79,
        0xcb61b38c, 0xbc66831a, 0x256fd2a0, 0x5268e236,
        0xcc0c7795, 0xbb0b4703, 0x220216b9, 0x5505262f,
        0xc5ba3bbe, 0xb2bd0b28, 0x2bb45a92, 0x5cb36a04,
        0xc2d7ffa7, 0xb5d0cf31, 0x2cd99e8b, 0x5bdeae1d,
        0x9b64c2b0, 0xec63f226, 0x756aa39c, 0x026d930a,
        0x9c0906a9, 0xeb0e363f, 0x72076785, 0x05005713,
        0x95bf4a82, 0xe2b87a14, 0x7bb12bae, 0x0cb61b38,
        0x92d28e9b, 0xe5d5be0d, 0x7cdcefb7, 0x0bdbdf21,
        0x86d3d2d4, 0xf1d4e242, 0x68ddb3f8, 0x1fda836e,
        0x81be16cd, 0xf6b9265b, 0x6fb077e1, 0x18b74777,
        0x88085ae6, 0xff0f6a70, 0x66063bca, 0x11010b5c,
        0x8f659eff, 0xf862ae69, 0x616bffd3, 0x166ccf45,
        0xa00ae278, 0xd70dd2ee, 0x4e048354, 0x3903b3c2,
        0xa7672661, 0xd06016f7, 0x4969474d, 0x3e6e77db,
        0xaed16a4a, 0xd9d65adc, 0x40df0b66, 0x37d83bf0,
        0xa9bcae53, 0xdebb9ec5, 0x47b2cf7f, 0x30b5ffe9,
        0xbdbdf21c, 0xcabac28a, 0x53b39330, 0x24b4a3a6,
        0xbad03605, 0xcdd70693, 0x54de5729, 0x23d967bf,
        0xb3667a2e, 0xc4614ab8, 0x5d681b02, 0x2a6f2b94,
        0xb40bbe37, 0xc30c8ea1, 0x5a05df1b, 0x2d02ef8d,
    };

    v3 = -1;

    for ( v2 = 0; v2 < fileSize; ++v2 )
    {
        v4 = (unsigned char)buffer[v2] ^ (unsigned char)v3;
        v5 = v3 >> 8; //>> 8 same as divide by 256. (powers of 2), ignore this in computations/checksums
        v3 = CRC32Table[v4] ^ v5 & 0xFFFFFF;
    }
    return ~v3;
}

//----- (00408270) --------------------------------------------------------
void __cdecl CopyFileCFG(char *destination, const char *source)
{
    FILE *v3; // esi@1
    FILE *v4; // edi@2
    size_t v5; // eax@4
    char DstBuf[2048]; // [sp+8h] [bp-800h]@4

    v3 = fopen(source, "rb");
    if ( v3 )
    {
        v4 = fopen(destination, "wb");
        if ( v4 )
        {
            while ( !feof(v3) )
            {
                v5 = fread(DstBuf, 1, 0x800, v3);
                if ( v5 > 0 )
                    fwrite(DstBuf, 1, v5, v4);
            }
            fclose(v4);
        }
        fclose(v3);
    }
}

//----- (00408310) --------------------------------------------------------
void *__cdecl AllocateMemory(int bytes)
{
    void *v1; // eax@2
    void *v2; // esi@5
    char Dest[256]; // [sp+8h] [bp-100h]@8

    if ( (bytes + 4) <= 0x80000 )
        v1 = malloc(bytes + 4);
    else
        v1 = VirtualAlloc(0, bytes + 4, 0x1000, 4);
    if ( v1 )
    {
        *(unsigned int *)v1 = bytes + 4;
        v2 = (char *)v1 + 4;
    }
    else
    {
        v2 = 0;
    }
    if ( !v2 )
    {
        sprintf(Dest, "Out of memory (Alloc:%d)", bytes);
        MessageBoxA(0, Dest, "Error", 0x30);
        exit(1);
    }
    return v2;
}

//----- (004083A0) --------------------------------------------------------
char *__cdecl ExpandMemory(void *lpAddress, unsigned long Bytes, unsigned long MaxSize)
{
    signed int crap; // ecx@1
    int NewSize; // edi@3
    char *v5; // eax@5
    char *v6; // esi@8
    char *result; // eax@13
    void *v8; // eax@15
    signed int v9; // esi@18
    int v10; // edi@18
    char *v11; // eax@22
    char *v12; // eax@27
    char *v13; // ebp@30
    unsigned int v14; // ecx@35
    char *Memory; // [sp+10h] [bp-104h]@18
    char Text[256]; // [sp+14h] [bp-100h]@11

    if(MaxSize > 1)
        NewSize = (Bytes < MaxSize) ? Bytes : MaxSize;
    else
        NewSize = Bytes;

    if ( lpAddress )
    {
        if ( NewSize )
        {
            v9 = *((unsigned int *)lpAddress - 1);          // could be problems -_-? Okay minus 4 bytes from beginning of pointed data is size? (must be a special structure of some kind)
            Memory = (char *)lpAddress - 4; //could be problems -_-?
            if ( (NewSize + 4) == v9 )                          // Check if special attribute (Size?) exists and equals the New Size so it can ignore it.
            {
                result = (char *)lpAddress;
            } else {
                if ( v9 > 0x80000 || (NewSize + 4) > 0x80000 )
                {
                    if ( (NewSize + 4) <= 0x80000 )
                        v12 = (char *)malloc(NewSize + 4);
                    else
                        v12 = (char *)VirtualAlloc(0, (NewSize + 4), 0x1000, 4);
                    if ( v12 )
                    {
                        *(unsigned int *)&v12[0] = (NewSize + 4);	//first 4 bytes is the size
                        v13 = &v12[4];
                    }
                    else
                    {
                        v13 = 0;
                    }
                    if ( !v13 )
                    {
                        sprintf(Text, "Out of memory (Alloc:%d)", NewSize);
                        MessageBoxA(0, Text, "Error", 0x30);
                        exit(1);
                    }
                    v14 = v9 - 4;
                    if ( v9 - 4 >= NewSize )
                        v14 = NewSize;
                    memcpy(v13, lpAddress, v14);
                    if ( *(unsigned int *)&Memory[0] <= 0x80000 )
                    {
                        free(Memory);
                        result = v13;
                    } else {
                        VirtualFree(Memory, 0, 0x8000);
                        result = v13;
                    }
                }
                else
                {
                    v11 = (char *)realloc((char *)lpAddress - 4, (NewSize + 4));
                    if ( !v11 )
                    {
                        MessageBoxA(0, "Out of memory (Resize)", "Error", 0x30);
                        exit(1);
                    }
                    *(unsigned int *)&v11[0] = (NewSize + 4);
                    result = &v11[4];
                }
            }
        }
        else
        {
            v8 = (char *)lpAddress - 4;
            if ( *((unsigned int *)lpAddress - 1) <= 0x80000 ) {
                free(v8);
                result = 0;
            } else {
                VirtualFree(v8, 0, 0x8000);
                result = 0;
            }
        }
    }
    else
    {
        if ( NewSize + 4 <= 0x80000 )
            v5 = (char *)malloc(NewSize + 4);
        else
            v5 = (char *)VirtualAlloc(0, NewSize + 4, 0x1000, 4);
        if ( v5 ) {
            *(unsigned int *)&v5[0] = NewSize + 4;
            v6 = &v5[4];
        } else {
            v6 = 0;
        }
        if ( !v6 )
        {
            sprintf(Text, "Out of memory (Alloc:%d)", NewSize);
            MessageBoxA(0, Text, "Error", 0x30);
            exit(1);
        }
        result = v6;
    }
    return result;
}

//----- (004085C0) --------------------------------------------------------
void __stdcall FreeMemory(LPVOID ptr)
{
    if ( *((unsigned int *)ptr - 1) <= 0x80000 )
        free((char *)ptr - 4);
    else
        VirtualFree((char *)ptr - 4, 0, 0x8000);
}
// 4085C0: inconsistent function type and number of purged bytes

//----- (004085F0) --------------------------------------------------------
void __cdecl ConnectSocket(int *Socket, const char *Hostname, unsigned short ConnectPort, unsigned short ListenPort)
{
    //int v4; // esi@1
    //int v5; // eax@1
    //int v6; // ST00_4@1
    //int v7; // ST00_4@1
    //int v8; // ST00_4@1
    unsigned long v9; // eax@1
    //int v10; // ecx@1
    unsigned int v11; // edi@1
    struct hostent *v12; // eax@2
    unsigned int v13; // kr00_4@4
    //int v14; // eax@4
    int optval; // [sp+Ch] [bp-28h]@1
    unsigned long ioctl_nonblocking; // [sp+10h] [bp-24h]@1
    struct sockaddr_in name; // [sp+14h] [bp-20h]@1
    struct sockaddr_in v18; // [sp+24h] [bp-10h]@4

    *Socket = socket(AF_INET, SOCK_DGRAM, 0);
    ioctl_nonblocking = 1;
    ioctlsocket(*Socket, FIONBIO, &ioctl_nonblocking);

    optval = -1; //TODO: Why is it TCP when it should be UDP?
    setsockopt(*Socket, IPPROTO_TCP, TCP_NODELAY, (char *)&optval, sizeof(optval));

    optval = 1024; //1 KB SEND BUFFER
    setsockopt(*Socket, SOL_SOCKET, SO_SNDBUF, (char *)&optval, sizeof(optval));

    optval = 1024; //1 KB RECV BUFFER
    setsockopt(*Socket, SOL_SOCKET, SO_RCVBUF, (char *)&optval, sizeof(optval));

    memset(&(name.sin_zero), '\0', 8);
    name.sin_family = AF_INET;
    name.sin_addr.s_addr = htonl(INADDR_ANY); //Binds on IP 0.0.0.0 : ListenPort
    name.sin_port = htons(ListenPort);
    bind(*Socket, (struct sockaddr *)&name, sizeof(name));

    //Connect code, Sends the first packet to usually Port+1, no idea why.
    v11 = inet_addr(Hostname);
    if ( v11 == INADDR_NONE )
    {
        v12 = gethostbyname(Hostname);
        if ( v12 )
            memcpy(&v18.sin_addr, v12->h_addr_list[0], v12->h_length);
    } else {
        v18.sin_addr.s_addr = v11;
    }

    memset(&(v18.sin_zero), '\0', 8);
    v18.sin_family = AF_INET;
    v18.sin_port = htons(ConnectPort);
    connect(*Socket, (struct sockaddr *)&v18, sizeof(v18));
    //Socket[1] = -1; //TODO: what is this? seems it sets DWORD's for SOCKET twice.
    //Socket[2] = -1; //TODO: what is this?
    v13 = GetTickCount() / 0xA;
    send(*Socket, (const char *)&v13, 4, 0);
}

//----- (00408740) --------------------------------------------------------
void __cdecl CloseSocketWrapper(int socket)
{
    closesocket(socket);
}

//----- (00408750) --------------------------------------------------------
void __cdecl SendDirectoryServerZoneUpdatePacket(int Socket, const void *a2, unsigned int packetSize)
{
    void *v3; // ebx@1
    char *v4; // eax@3
    int finalPacketSize; // [sp-8h] [bp-418h]@3
    int v6; // [sp-4h] [bp-414h]@3
    char v7[4]; // [sp+Ch] [bp-404h]@4
    char buf[1024]; // [sp+10h] [bp-400h]@3

    if ( a2 != NULL && packetSize > 0 )
    {
        //Setting the 4 first bytes to 0. Certainly the message header !
        *(unsigned int *)buf = 0;
        memcpy(&buf[4], a2, packetSize);
        v6 = 0;
        finalPacketSize = packetSize + 4; //packet is 4 bytes bigger due to shifting elements right by 4.
        v4 = buf;
    }
    else
    {
        v6 = 0; //This else statement lets the Directory Server know your zone is still up. Keep-Alive packet.
        *(unsigned int *)v7 = GetTickCount() / 0xA;         // This just sends 4 bytes which is just the GetTickCount/10, It's called Directory Server Ping
        finalPacketSize = 4;
        v4 = v7;
    }
    send(Socket, v4, finalPacketSize, v6);
}
// 408750: using guessed type char var_3FC[1020];

//----- (004087D0) --------------------------------------------------------
int __cdecl GetSocketRecvLag(int Socket, int *TimeElapsed)
{
    void *v2; // edi@1
    int sizeRecieved; // esi@3
    char buf[4]; // [sp+Ch] [bp-200h]@2
    int v6; // [sp+10h] [bp-1FCh]@4
    int CheckTimeElapsed; //fix 1

    do
    {
        if ( recv(Socket, buf, 512, 2) == -1 )
            break;
        sizeRecieved = recv(Socket, buf, 512, 0);
        if ( sizeRecieved == 8 )
            CheckTimeElapsed = GetTickCount() / 0xA - *(unsigned int *)&buf[4];
    }
    while ( sizeRecieved != -1 );
    *TimeElapsed = CheckTimeElapsed;
    return *(unsigned int *)buf;
}

//----- (00408860) --------------------------------------------------------
void __cdecl ListenOnPort(int *Socket, unsigned short hostshort)
{
    int v3; // esi@1
    int v4; // eax@1
    int v5; // ST00_4@1
    int v6; // ST00_4@1
    int v7; // ST00_4@1
    unsigned long v8; // eax@1
    int v9; // ecx@1
    unsigned long ioctl_nonblocking; // [sp+4h] [bp-14h]@1
    struct sockaddr_in name; // [sp+8h] [bp-10h]@1
    int optval = 0; //fix 1

    *Socket = socket(AF_INET, SOCK_DGRAM, 0);
    ioctl_nonblocking = 1;
    ioctlsocket(*Socket, FIONBIO, &ioctl_nonblocking);
    optval = -1;
    setsockopt(*Socket, IPPROTO_TCP, IP_OPTIONS, (char *)&optval, sizeof(optval));
    optval = 8192;
    setsockopt(*Socket, SOL_SOCKET, SO_SNDBUF, (char *)&optval, sizeof(optval));
    optval = 8192;
    setsockopt(*Socket, SOL_SOCKET, SO_RCVBUF, (char *)&optval, sizeof(optval));
    name.sin_family = AF_INET;
    name.sin_port = htons(hostshort);
    name.sin_addr.s_addr = htonl(INADDR_ANY);
    bind(*Socket, (struct sockaddr *)&name, sizeof(name));
}

//----- (00408930) --------------------------------------------------------
void __cdecl ProcessZonePingPlayerCount(int Socket, int ZonePopulation)
{
    void *v2; // esi@1
    signed int v3; // ebp@1
    int v4; // ST00_4@2
    int v5; // eax@2
    void (__cdecl *v6)(unsigned int, char *, unsigned int); // ecx@5
    int v7; // eax@8
    int fromlen; // [sp+10h] [bp-21Ch]@2
    unsigned char OutBuffer[8]; // [sp+14h] [bp-218h]@8
    struct sockaddr_in from; // [sp+1Ch] [bp-210h]@2
    char buf[512]; // [sp+2Ch] [bp-200h]@2

    v3 = 0;
    do
    {
        fromlen = sizeof(from);
        v5 = recvfrom(Socket, buf, 512, 0, (struct sockaddr *)&from, &fromlen);
        if ( v5 == -1 )
            break;
        if ( (unsigned int)v5 >= 4 )
        {
            if ( *(unsigned int *)buf )
            {
                *(unsigned int *)&OutBuffer[0] = ZonePopulation;
                *(unsigned int *)&OutBuffer[4] = *(unsigned int *)&buf[0];
                sendto(Socket, OutBuffer, 8, 0, (struct sockaddr *)&from, fromlen);
            }
            else
            {
                v6 = (void (__cdecl *)(unsigned int, char *, unsigned int))*((unsigned int *)v2 + 1);
                if ( v6 )
                {
                    if ( (unsigned int)v5 > 4 )
                        v6(*(unsigned int *)&from.sin_addr.s_addr, &buf[4], v5 - 4);
                }
            }
        }
        ++v3;
    }
    while ( v3 < 20 );
}

//----- (004089E0) --------------------------------------------------------
struct PLAYER *__cdecl CreateNewPlayer(struct PLAYER *player, struct in_addr a2, short a3, struct CONNECTION *connection)
{
    struct PLAYER *v4; // esi@1
    //struct CONNECTION *connection; // edx@1
    int v6; // eax@1

    v4 = player;
    player->ProcessInformation = 0;
    player->dword4 = 0;
    player->dword8 = 0;
    player->dwordC = 0;
    memset(player->someStringBuffer, 0, sizeof(player->someStringBuffer));
    player->TypedName[0] = 0;
    player->DemoPlayer = 0;
    player->KingCrownKills = 0;
    player->KotHDeathCount = 0;
    player->MyArenaScoreIndex = -1;
    player->IsEnergyShowing = 0;
    player->field_60 = -1;
    player->field_5C = -1;
    player->field_58 = -1;
    player->IsSilenced = 0;
    player->field_15B = 0;
    player->field_50 = -1;
    player->field_54 = -1;
    player->CurrentSecurityPacketModifcationCount = 0;
    player->field_A8 = 0;
    player->DeathsWithoutFiring = 0;
    player->field_3C = 0;
    player->field_4C = -1;
    player->field_153 = 0;
    player->BillerPlayerId = LastBillerPlayerId++;
    player->field_305 = 0;
    player->SlowModem = 0;
    player->AlreadySentReliablePacket = 0;
    player->KickOffDelayTimer = 0;
    player->SendWeaponUpdatePacket = 0;
    player->connection = connection;
    player->MyArena = 0;
    player->MyLastArena = 0;
    memset(player->VoiceUploads, 0, sizeof(player->VoiceUploads));
    player->PlayerName[0] = 0;
    player->SecurityWeaponCountyTotalNew = 0;
    memset(&player->SecurityPacketCache, 0, 0x28);
    player->S2CPacketLossPercentage = 1000;
    player->C2SPacketLossPercentage = 1000;
    player->field_283 = 0;
    player->IPAddressDWORD.s_addr = a2.s_addr;
    player->Port = a3;
    player->pfile329 = 0;
    player->char32d = 0;
    player->Frequency = -1;
    player->IsSysop = 0;
    player->IsModerator = 0;
    player->IsSuperModerator = 0;
    player->AttachedToPlayerId = -1;
    memset(&player->PlayerDataBillerPacket, 0, sizeof(struct PLAYER_DATA_BILLER_PACKET_STRUCT));               // Struct = Name, Squad, BannerData, Usage,AccountCreated, UserId,Extra1,Extra2
    player->PlayerDataBillerPacket.UserId = -1;
    player->CurrentWins = 0;
    player->CurrentGoals = 0;
    player->KillPoints = 0;
    player->FlagPoints = 0;
    player->PersonalBestWins = 0;
    player->PersonalBestLosses = 0;
    player->PersonalBestGoalCount = 0;
    player->PersonalBestKillPoints = 0;
    player->PersonalBestFlagPoints = 0;
    player->ArenaPlayerIndex = -1;
    player->Ship = 8;
    player->IsSpeced = 0;
    player->TotalShipChanges = 0;
    player->ForceWearBanner = 0;
    player->PlayerId = player->connection->PlayerId;
    ZonePlayerList[player->PlayerId] = player;
    player->NoPasswordPacketDelayTimer = GetTickCount() / 0xA;
    v4->UsageSessionSeconds = time(0);
    v4->CurrentSuicideCount = 0;
    v4->field_287 = 0;
    v4->field_28B = 0;
    v4->field_29F = 0;
    v4->LastMessageSpamResetCheckTime = GetTickCount() / 0xA;
    v4->MessageSpamTotal = 0;
    v4->field_29B = 0;
    v4->field_29F = 0;
    v4->LastSecurityPacketReturnedTime = 0;
    v4->C2SCurrentFast = 0;
    v4->C2SCurrentSlow = 0;
    v4->C2SCurrentTotalFast = 0;
    v4->C2SCurrentTotalSlow = 0;
    v4->DisconnectReason = 0;
    v4->C2SAverageLatencyFirst = 0;
    v4->C2SAverageLatencySecond = 0;
    v4->ScoreReset = 0;
    v4->LatencyKickOutDelayTimer = 0;
    v4->field_309 = 1;
    return v4;
}
// 42A534: using guessed type int LastBillerPlayerId;

//----- (00408C30) --------------------------------------------------------
void __cdecl DisconnectUser(struct PLAYER *player)
{
    char *v2; // esi@7
    char *v3; // ebp@8
    int v4; // ecx@9
    int v5; // ebp@10
    char i; // al@13
    struct ARENA *v7; // ecx@17
    struct VOICE_UPLOAD_STRUCT *v9; // esi@19
    signed int v10; // ebp@19
    bool IsNotSendPlayerScore; // eax@24
    int *v12; // [sp-8h] [bp-C8h]@31
    unsigned int Size; // [sp-4h] [bp-C4h]@31
    unsigned int Ping; // [sp+10h] [bp-B0h]@19
    unsigned int Latency; // [sp+14h] [bp-ACh]@19
    int MiscTimedGame; // [sp+18h] [bp-A8h]@17
    char Dest[32]; // [sp+1Ch] [bp-A4h]@12
    char v18; // [sp+3Ch] [bp-84h]@12
    char Str[128]; // [sp+40h] [bp-80h]@8

    if ( player->ProcessInformation )
    {
        TerminateProcess(player->ProcessInformation->hProcess, 0);
        CloseHandle(player->ProcessInformation->hProcess);
    }
    if ( player->pfile329 )
    {
        fclose(player->pfile329);
        player->pfile329 = 0;
    }
    if ( AutoPermissionPoints > 0 )
    {
        if ( player->FlagPoints + player->KillPoints >= AutoPermissionPoints )
        {
            v2 = PermissionAutoPermissionIDList;
            if ( PermissionAutoPermissionIDList[0] )
            {
                do
                {
                    v3 = Str;
                    if ( isdigit(*v2) )
                    {
                        do
                        {
                            v4 = v2[1];
                            *v3++ = *v2++;
                        }
                        while ( isdigit(v4) );
                    }
                    *v3 = 0;
                    v5 = atoi(Str);
                    if ( v5 && BillingConnectionStructPointer )
                    {
                        Dest[0] = 1;
                        strncpy(&Dest[1], player->PlayerDataBillerPacket.Name, 0x20);
                        v18 = 0;
                        SendBillerPlayerNamePacketSomething(BillingConnectionStructPointer, -1, v5, Dest, 0x21);
                    }
                    for ( i = *v2; i; i = (v2++)[1] )
                    {
                        if ( isdigit(i) )
                            break;
                    }
                }
                while ( *v2 );
            }
        }
    }
    v7 = player->MyArena;
    MiscTimedGame = 0;
    if ( v7 )
    {
        MiscTimedGame = v7->ServersideArenaSettings.MiscTimedGame;
        PlayerLeaveArena(v7, player);
        player->MyArena = 0;
    }
    GetPingLOSSSomething(player->connection, &Latency, &Ping);
    Latency = 1000 - Latency;
    Ping = 1000 - Ping;
    sub_41B7A0(player->connection);
    ZonePlayerList[player->PlayerId] = 0;
    v10 = 0;
    do
    {
        if ( player->VoiceUploads[v10].VoiceMemoryPointer )
        {
            FreeMemory(player->VoiceUploads[v10].VoiceMemoryPointer);
            player->VoiceUploads[v10].VoiceMemoryPointer = 0;
        }
        ++v10;
    }
    while ( v10 < 4 );
    if ( BillingConnectionStructPointer )
    {
        IsNotSendPlayerScore = false;
        if ( player->DemoPlayer )
            IsNotSendPlayerScore = true;
        if ( MiscTimedGame || player->FlagPoints + player->KillPoints + player->CurrentWins + player->CurrentDeaths <= 5 && !player->ScoreReset )
            IsNotSendPlayerScore = true;

        SendBillerUserLogoffPacket(
            BillingConnectionStructPointer,
            player,
            Latency,
            Ping,
            IsNotSendPlayerScore);
    }
}
// 4AF32C: using guessed type int AutoPermissionPoints;

//----- (00408E80) --------------------------------------------------------
void __cdecl PlayerHandleGamePacket(struct PLAYER *player, unsigned char *packet, int packetSize)
{
    int packett; // ebx@1
    //struct PLAYER *player; // ebp@1
    int PacketType; // ecx@1
    struct ARENA *v6; // ecx@2
    int PowerBallIndex; // esi@3
    int v8; // eax@3
    int v9; // eax@5
    struct ARENA *v10; // ebp@5
    int v11; // eax@5
    int v12; // eax@5
    struct ARENA *v13; // esi@6
    int v14; // eax@7
    int v15; // edx@9
    int v16; // ecx@9
    struct PLAYER *v17; // eax@10
    int v18; // esi@14
    int v19; // esi@15
    struct ARENA *v20; // eax@20
    int v21; // ecx@21
    struct PLAYER *v22; // ebx@23
    unsigned int v23; // kr34_4@26
    const void *v24; // ecx@27
    unsigned int v25; // kr3C_4@29
    int v26; // esi@32
    bool v27; // sf@32
    unsigned char v28; // of@32
    struct ARENA *v29; // ecx@34
    short v30; // ax@37
    struct ARENA *v31; // ecx@37
    struct ARENA *v32; // ecx@38
    struct ARENA *v33; // ebp@39
    int v34; // eax@39
    struct SOCCER_BALL *v35; // eax@39
    struct ARENA *v36; // esi@40
    int v37; // edx@42
    int v38; // ecx@42
    struct SOCCER_BALL *v39; // eax@43
    struct ARENA *v40; // ebp@50
    int v41; // eax@50
    struct SOCCER_BALL *v42; // eax@50
    struct ARENA *v43; // ecx@52
    int v44; // eax@52
    unsigned int v45; // kr44_4@55
    char *v46; // esi@57
    unsigned int v47; // kr4C_4@59
    //const char v48; // al@59
    unsigned int v49; // kr54_4@61
    short v50; // ax@64
    short v51; // bx@66
    struct ARENA *v52; // eax@70
    char v53; // al@76
    int v54; // ecx@81
    char *v55; // eax@81
    signed int v56; // edx@81
    unsigned int v57; // eax@87
    int v58; // edx@87
    char v59; // al@87
    struct ARENA *v60; // edx@89
    int v61; // ecx@92
    int v62; // eax@92
    signed int v63; // esi@93
    char *v64; // eax@93
    signed int v65; // edx@93
    int v66; // eax@105
    int v67; // eax@109
    signed int v68; // esi@109
    struct ARENA *v69; // ecx@109
    unsigned int v70; // kr5C_4@113
    struct ARENA *v71; // eax@116
    unsigned char *NewsSendBuffer; // eax@118
    int v73; // edx@119
    int v74; // eax@120
    int v75; // ecx@120
    int v76; // eax@123
    int v77; // ecx@123
    struct ARENA *v78; // edi@126
    char OriginalPositionPacketChecksum; // dl@127
    char PositionPacketChecksum; // al@127
    int v81; // ecx@127
    signed int v82; // esi@127
    int v83; // esi@131
    unsigned int v84; // edx@142
    signed int v85; // esi@142
    struct ARENA *v86; // ecx@158
    unsigned int v87; // kr64_4@160
    short v88; // cx@167
    long v89; // qax@173
    long v90; // qax@174
    int v91; // eax@180
    int v92; // edx@180
    int v93; // eax@191
    struct PLAYER *v94; // eax@192
    short v95; // ax@197
    short v96; // dx@197
    int v97; // eax@199
    struct PLAYER *v98; // eax@200
    int v99; // eax@202
    short v100; // ax@204
    struct ARENA *v101; // ecx@204
    struct ARENA *v102; // edx@205
    short v103; // ax@207
    struct PLAYER *v104; // esi@210
    struct ARENA *v105; // ecx@213
    short v106; // ax@216
    struct ARENA *v107; // ecx@216
    int v108; // eax@216
    short v109; // ax@222
    struct ARENA *v110; // ecx@222
    struct ARENA *v111; // ecx@222
    int v112; // eax@222
    int v113; // eax@226
    int v114; // eax@227
    struct ARENA *v115; // ecx@228
    struct ARENA *v116; // eax@229
    struct ARENA *v117; // eax@232
    int v118; // eax@233
    int v119; // edx@233
    struct ARENA *v120; // eax@233
    int v121; // ecx@233
    short v122; // cx@235
    struct ARENA *v123; // ecx@235
    struct ARENA *v124; // eax@238
    int v125; // eax@243
    struct ARENA *v126; // edi@246
    int v127; // edx@248
    int v128; // eax@249
    short v129; // ax@257
    struct ARENA *v130; // ecx@257
    int v131; // eax@257
    int v132; // ebx@263
    struct ARENA *v133; // ecx@263
    int v134; // edi@263
    struct ARENA *v135; // ecx@267
    int v136; // edi@268
    int v137; // eax@269
    int v138; // edi@269
    int v139; // edx@271
    int v140; // eax@273
    int v141; // edi@277
    int v142; // eax@280
    int v143; // edx@280
    int v144; // ecx@281
    signed int v145; // ebx@286
    char *v146; // eax@286
    signed int v147; // eax@289
    int v148; // ebx@291
    int v149; // eax@292
    int v150; // eax@295
    struct ARENA *v151; // eax@295
    int v152; // edx@296
    int v153; // ecx@297
    char *v154; // esi@305
    int v155; // eax@305
    int v156; // edi@305
    int v157; // ebx@305
    int v158; // edi@305
    unsigned int v159; // kr6C_4@314
    char *v160; // edi@314
    struct ARENA *v161; // ecx@316
    short v162; // bx@316
    signed int v163; // esi@316
    struct ARENA *v164; // edi@317
    short v165; // ax@320
    short v166; // dx@320
    struct ARENA *v167; // ecx@320
    int v168; // esi@320
    struct ARENA *v169; // eax@322
    signed int v170; // edi@324
    struct PLAYER *v171; // eax@325
    int v172; // ecx@325
    int v173; // edx@326
    int v174; // ecx@328
    int v175; // ecx@332
    signed int v176; // ebx@333
    struct PLAYER *v177; // ecx@334
    struct PLAYER *v178; // esi@334
    int v179; // edx@334
    int v180; // edx@337
    int v181; // eax@339
    int v182; // esi@340
    int v183; // edx@345
    signed int v184; // edi@348
    long v185; // qax@348
    long v186; // qax@349
    int v187; // edx@352
    signed int v188; // eax@355
    struct ARENA *v189; // eax@366
    short v190; // ax@372
    short v191; // ax@374
    unsigned int v192; // edx@376
    struct ARENA *v193; // eax@379
    short v194; // dx@381
    short v195; // cx@381
    int v196; // edx@381
    short v197; // cx@381
    int v198; // ebx@381
    int v199; // edi@382
    signed int v200; // esi@383
    struct PLAYER *v201; // eax@384
    struct ARENA *v202; // eax@390
    struct ARENA *v203; // esi@395
    long v204; // qax@395
    short v205; // ax@396
    int v206; // ecx@396
    int v207; // edx@396
    int v208; // edi@399
    int v209; // eax@400
    short v210; // ax@407
    struct ARENA *v211; // eax@407
    struct ARENA *v212; // eax@411
    signed int v213; // ecx@412
    char v214; // cl@415
    unsigned int v215; // kr7C_4@424
    unsigned int v216; // kr84_4@430
    char v217; // al@432
    struct ARENA *v218; // eax@437
    short v219; // cx@438
    int v220; // edi@438
    signed int v221; // esi@439
    struct PLAYER *v222; // eax@440
    struct ARENA *v223; // ecx@445
    short v224; // ax@447
    struct ARENA *v225; // ecx@447
    int v226; // eax@447
    short v227; // bx@452
    int v228; // esi@457
    struct PLAYER *v229; // eax@458
    struct PLAYER *v230; // ecx@462
    int v231; // ebp@464
    struct PLAYER *v232; // ecx@465
    struct ARENA *v233; // eax@468
    struct ARENA *v234; // ecx@471
    struct VOICE_UPLOAD_STRUCT *v235; // ebp@473
    signed int v236; // esi@473
    struct ARENA *v237; // eax@480
    short v238; // dx@483
    char v239; // al@484
    short v240; // bx@489
    int v241; // ebx@494
    char *v242; // eax@494
    short ChatTargetPlayerId; // dx@502
    time_t v244; // qdi@504
    signed int v245; // ecx@504
    bool v246; // zf@506
    int v247; // eax@509
    struct ARENA *v248; // eax@515
    char v249; // al@522
    struct ARENA *v250; // ecx@524
    struct ARENA *v251; // eax@528
    struct ARENA *v252; // eax@530
    int v253; // eax@533
    unsigned int v254; // kr8C_4@537
    char *v255; // edx@539
    int v256; // eax@541
    struct PLAYER *v257; // eax@542
    unsigned int v258; // kr94_4@545
    char *v259; // edx@547
    char *v260; // edi@547
    unsigned int v261; // kr9C_4@549
    signed int CanUseFileTransferCommand; // esi@552
    char *v263; // edi@554
    unsigned int v264; // krA4_4@565
    FILE *v265; // eax@567
    FILE *v266; // esi@567
    unsigned int v267; // krAC_4@570
    int v268; // edi@575
    signed int v269; // ecx@575
    unsigned int v270; // ecx@578
    char v271; // al@578
    const void *v272; // esi@578
    unsigned int v273; // krB4_4@578
    int v274; // eax@585
    struct PLAYER *v275; // eax@588
    short v276; // dx@594
    int v277; // eax@594
    int v278; // ecx@594
    struct ARENA *v279; // eax@595
    int v280; // edi@596
    signed int v281; // esi@597
    struct PLAYER *v282; // eax@598
    struct ARENA *v283; // eax@606
    int v284; // ecx@609
    char *v285; // ebx@611
    signed int v286; // edi@611
    char *v287; // esi@611
    int v288; // ecx@625
    char v289; // al@630
    char *v290; // eax@643
    int v291; // eax@647
    int v292; // ecx@648
    int v293; // edx@655
    int TotalDemoPlayersCount; // esi@655
    struct PLAYER **v295; // eax@656
    int v296; // ecx@656
    char *v297; // edi@664
    signed int v298; // ecx@664
    unsigned int v299; // ecx@667
    char v300; // dl@667
    const void *v301; // esi@667
    int v302; // ebx@673
    struct PLAYER **v303; // eax@674
    struct PLAYER *v304; // eax@678
    int v305; // edi@679
    signed int v306; // ecx@679
    unsigned int v307; // ecx@682
    char v308; // al@682
    const void *v309; // esi@682
    unsigned int v310; // krBC_4@682
    void *v311; // ecx@687
    char *v312; // edi@699
    signed int v313; // ecx@699
    unsigned int v314; // ecx@702
    char v315; // al@702
    const void *v316; // esi@702
    int v317; // ecx@702
    int v318; // eax@702
    int v319; // eax@702
    int v320; // ecx@702
    int v321; // eax@702
    struct ARENA *v322; // eax@706
    long v323; // qax@710
    char *v324; // [sp-Ch] [bp-700h]@98
    const void *v325; // [sp-Ch] [bp-700h]@232
    unsigned int v326; // [sp-8h] [bp-6FCh]@27
    const char *v327; // [sp-8h] [bp-6FCh]@98
    char *v328; // [sp-8h] [bp-6FCh]@139
    unsigned int v329; // [sp-8h] [bp-6FCh]@232
    char *v330; // [sp-8h] [bp-6FCh]@436
    int v331; // [sp-4h] [bp-6F8h]@27
    struct PLAYER *v332; // [sp-4h] [bp-6F8h]@139
    int v333; // [sp-4h] [bp-6F8h]@232
    int v334; // [sp-4h] [bp-6F8h]@342
    struct PLAYER *v335; // [sp-4h] [bp-6F8h]@436
    char v336; // [sp-4h] [bp-6F8h]@510
    int Password; // [sp+10h] [bp-6E4h]@216
    int v338; // [sp+14h] [bp-6E0h]@1
    short v339; // [sp+1Ah] [bp-6DAh]@204
    int v340; // [sp+1Ch] [bp-6D8h]@17
    int a2; // [sp+20h] [bp-6D4h]@21
    struct PLAYER *playera; // [sp+24h] [bp-6D0h]@20
    unsigned char v343; // [sp+28h] [bp-6CCh]@634
    unsigned char v344[36]; // [sp+29h] [bp-6CBh]@634
    int v356; // [sp+55h] [bp-69Fh]@5
    short v357; // [sp+59h] [bp-69Bh]@5
    char v358; // [sp+5Bh] [bp-699h]@5
    unsigned char v359; // [sp+6Ch] [bp-688h]@629
    char v360; // [sp+6Dh] [bp-687h]@629
    int v361; // [sp+6Eh] [bp-686h]@629
    char v362; // [sp+7Fh] [bp-675h]@698
    char a3[512];// [sp+90h] [bp-664h]@29
    char v364[507]; // [sp+95h] [bp-65Fh]@29
    char a1[507]; // [sp+290h] [bp-464h]@18
    unsigned char v366; // [sp+390h] [bp-364h]@483
    short v367; // [sp+391h] [bp-363h]@483
    char v368; // [sp+393h] [bp-361h]@483
    char Dest[97]; // [sp+3F4h] [bp-300h]@18
    char buf[256]; // [sp+4F4h] [bp-200h]@26
    char v371; // [sp+4F5h] [bp-1FFh]@26
    char v372; // [sp+4F6h] [bp-1FEh]@26
    short v373; // [sp+4F7h] [bp-1FDh]@26
    char v374; // [sp+4F9h] [bp-1FBh]@26

    int playerIndex; //fix 1
    char buffer[16]; //fix 2
    char buffer2[5]; //fix 3
    char buffer3[7]; //fix 4
    char buffer4[32]; //fix 5
    char buffer5[100]; //fix 6
    char buffer6[3]; //fix 7
    struct PLAYER* player2; //fix 8
    char *nameReturn; //fix 9

    PacketType = packet[0];
    switch ( PacketType )
    {
    case 0x1F:                                  // 0x1F - Fire a Ball
        if ( player->MyArena )
        {
            PowerBallIndex = packet[1];            // Ball ID

            if ( player->MyArena->SoccerBalls[PowerBallIndex].PlayerId == player->PlayerId )
            {
                if ( !player->MyArena->SoccerBalls[PowerBallIndex].StartTimeDelay )
                {
                    player->MyArena->SoccerBalls[PowerBallIndex].PowerBallId = *(unsigned char *)PowerBallIndex;
                    player->MyArena->SoccerBalls[PowerBallIndex].XPixels = *(unsigned short *)&packet[2];
                    player->MyArena->SoccerBalls[PowerBallIndex].YPixels = *(unsigned short *)&packet[4];
                    player->MyArena->SoccerBalls[PowerBallIndex].XVelocity = *(unsigned short *)&packet[6];
                    player->MyArena->SoccerBalls[PowerBallIndex].YVelocity = *(unsigned short *)&packet[8];
                    player->MyArena->SoccerBalls[PowerBallIndex].PlayerId = *(unsigned short *)&packet[10];
                    player->MyArena->SoccerBalls[PowerBallIndex].StartTimeDelay = *(unsigned short *)&packet[12];

                    player->MyArena->SoccerBallTimers[*(unsigned char *)PowerBallIndex] = GetTickCount() / 0xA;
                    v11 = *(unsigned char *)PowerBallIndex;
                    buffer[0] = 0x2E;                  // 0x2E  Power-Ball Position Update
                    *(unsigned char *)&buffer[1] = *(unsigned char *)&player->MyArena->SoccerBalls[v11].PowerBallId;
                    *(unsigned short *)&buffer[2] = *(unsigned short *)&player->MyArena->SoccerBalls[v11].XPixels;
                    *(unsigned short *)&buffer[4] = *(unsigned short *)&player->MyArena->SoccerBalls[v11].YPixels;
                    *(unsigned short *)&buffer[6] = *(unsigned short *)&player->MyArena->SoccerBalls[v11].XVelocity;
                    *(unsigned short *)&buffer[8] = *(unsigned short *)&player->MyArena->SoccerBalls[v11].YVelocity;
                    *(unsigned short *)&buffer[10] = *(unsigned short *)&player->MyArena->SoccerBalls[v11].PlayerId;
                    *(unsigned int *)&buffer[12] = *(unsigned int *)&player->MyArena->SoccerBalls[v11].StartTimeDelay;
                    SendArenaPacket(player->MyArena, buffer, 0x10, 0);
                }
            }
        }
        return;
    case 0x21:                                    // 0x21 - Soccer goal scored
        v34 = packet[1];
        if ( !player->MyArena
                || (player->MyArena->SoccerBalls[v34].PlayerId != player->PlayerId)
                || !player->MyArena->SoccerBalls[v34].StartTimeDelay )
            return;
        v16 = 0;
        if ( player->MyArena->ArenaPlayerCount > 0 )
        {
            v15 = 0;
            do
            {
                if ( player->MyArena->ArenaPlayers[v15]->Ship != 8 )
                    ++v16;
                ++v15;
            }
            while ( v15 < player->MyArena->ArenaPlayerCount );
        }
        v18 = player->MyArena->ServersideArenaSettings.SoccerReward;
        if ( v18 >= 0 )
            v19 = v18 * v16 * v16 / 1000;
        else
            v19 = -v18;
        v340 = v19;
        if ( v19 )
        {
            sprintf(Dest, "Team Goal! by %s  Reward:%d", player->PlayerDataBillerPacket.Name, v19);
            sprintf(a1, "Enemy Goal! by %s  Reward:%d", player->PlayerDataBillerPacket.Name, v19);
        }
        else
        {
            sprintf(Dest, "Team Goal! by %s", player->PlayerDataBillerPacket.Name);
            sprintf(a1, "Enemy Goal! by %s", player->PlayerDataBillerPacket.Name);
        }
        playerIndex = 0;
        if ( player->MyArena->ArenaPlayerCount > 0 )
        {
            do
            {
                if ( player->MyArena->ArenaPlayers[playerIndex]->Frequency != player->Frequency
                        || player->MyArena->ArenaPlayers[playerIndex]->Ship == 8 )
                {
                    if ( player->MyArena->ArenaPlayers[playerIndex]->MyArena )
                    {
                        strcpy(&a3[5], a1);
                        a3[0] = 7;                        // 0x07 - Chat
                        a3[1] = 0;
                        a3[2] = 104;
                        *(unsigned short *)&a3[3] = -1;
                        if ( GetBillingServerRelOut(player->MyArena->ArenaPlayers[playerIndex]->connection, 0) < 128 )
                            SendPlayerReliablePacket(player->MyArena->ArenaPlayers[playerIndex], a3, strlen(a1) + 6, 1);
                    }
                }
                else
                {
                    player->MyArena->ArenaPlayers[playerIndex]->FlagPoints += v19;
                    ++player->MyArena->ArenaPlayers[playerIndex]->CurrentGoals;

                    if ( player->MyArena->ArenaPlayers[playerIndex]->MyArena )
                    {
                        strcpy(&buf[5], Dest);
                        buf[0] = 7;                       // 0x07 - Chat
                        buf[1] = 0;
                        buf[2] = 104;
                        *(unsigned short *)&buf[3] = -1;
                        if ( GetBillingServerRelOut(player->MyArena->ArenaPlayers[playerIndex]->connection, 0) < 128 )
                            SendPlayerReliablePacket(player->MyArena->ArenaPlayers[playerIndex], buf, strlen(Dest) + 6, 1);
                    }
                }
            }
            while( playerIndex < player->MyArena->ArenaPlayerCount);
        }
        if ( player->MyArena->ServersideArenaSettings.SoccerCapturePoints )
            sub_4055D0(player->MyArena, player->Frequency, *(unsigned short *)&packet[2], *(unsigned short *)&packet[4]);
        if ( v19 )
        {
            buffer3[0] = 0x0B;                  // 0x0B - Soccer Goal Made
            *(unsigned short *)&buffer3[1] = *((unsigned short*)&(player->Frequency));
            *(unsigned int *)&buffer3[3] = v19;
            SendArenaPacket(player->MyArena, buffer3, 7, 1);
        }

        if ( player->MyArena->TotalSoccerBalls > 0 )
        {
            CreateSoccerBall(player->MyArena, v34);
            player->MyArena->SoccerBallTimers[v34] = GetTickCount() / 0xA;
            buffer[0] = 0x2E;                      // 0x2E - Power-Ball Position Update
            *(unsigned short *)&buffer[2] = *(unsigned short *)&player->MyArena->SoccerBalls[v34].XPixels;
            *(unsigned short *)&buffer[4] = *(unsigned short *)&player->MyArena->SoccerBalls[v34].YPixels;
            *(unsigned short *)&buffer[6] = *(unsigned short *)&player->MyArena->SoccerBalls[v34].XVelocity;
            *(unsigned short *)&buffer[8] = *(unsigned short *)&player->MyArena->SoccerBalls[v34].YVelocity;
            *(unsigned short *)&buffer[10] = *(unsigned short *)&player->MyArena->SoccerBalls[v34].PlayerId;
            *(unsigned int *)&buffer[12] = *(unsigned int *)&player->MyArena->SoccerBalls[v34].StartTimeDelay;
            SendArenaPacket(player->MyArena, buffer, 0x10, 0);
        }
        return;
    case 0x20:                                    // 0x20 - Ball request
        if ( !player->MyArena || player->Ship == 8 )
            return;

        v38 = 0;
        v41 = packet[1]; //Dangerous for overflow, server crash possible?

        while ( player->MyArena->SoccerBalls[v38].StartTimeDelay || player->MyArena->SoccerBalls[v38].PlayerId != player->PlayerId )
        {
            ++v38;
            if ( v38 >= player->MyArena->TotalSoccerBalls )
                break;

            if ( player->MyArena->SoccerBalls[v41].StartTimeDelay == *(unsigned int *)&packet[2] )
            {
                if ( player->MyArena->ArenaPlayerCount > player->MyArena->ServersideArenaSettings.SoccerCatchMinimum )
                    player->MySoccerReward += player->MyArena->ServersideArenaSettings.SoccerCatchPoints;

                player->MyArena->SoccerBalls[v41].StartTimeDelay = 0;
                player->MyArena->SoccerBalls[v41].PlayerId = player->PlayerId;
                player->MyArena->SoccerBalls[v41].XPixels = player->XPixels;
                player->MyArena->SoccerBalls[v41].YPixels = player->YPixels;
                player->MyArena->SoccerBallTimers[v41] = GetTickCount() / 0xA;

                buffer[0] = 0x2E;                  // 0x2E - Power-Ball Position Update
                buffer[1] = v42->PowerBallId;
                *(unsigned short *)&buffer[2] = *(unsigned short *)&player->MyArena->SoccerBalls[v41].XPixels;
                *(unsigned short *)&buffer[4] = *(unsigned short *)&player->MyArena->SoccerBalls[v41].YPixels;
                *(unsigned short *)&buffer[6] = *(unsigned short *)&player->MyArena->SoccerBalls[v41].XVelocity;
                *(unsigned short *)&buffer[8] = *(unsigned short *)&player->MyArena->SoccerBalls[v41].YVelocity;
                *(unsigned short *)&buffer[10] = *(unsigned short *)&player->MyArena->SoccerBalls[v41].PlayerId;
                *(unsigned int *)&buffer[12] = *(unsigned int *)&player->MyArena->SoccerBalls[v41].StartTimeDelay;
                SendArenaPacket(player->MyArena, buffer, 0x10, 0);
            }
            return;
        }
        return;
    case 0x1D:                                    // 0x1D - Change Certain Arena Settings
        if ( player->IsSysop
                || (player->PlayerDataBillerPacket.UserId == player->MyArena->ServersideArenaSettings.OwnerUserId)
                && player->MyArena->ServersideArenaSettings.OwnerUserId >= 0 )
        {
            if ( packet[1] ) //Contains a possible string, first character isn't NULL.
            {
                v46 = (char *)&packet[1];
                v47 = 0;
                do
                {
                    if ( v47 >= packetSize )
                        break;
                    ChangeSettings(player->MyArena, player, v46);
                    v47 += strlen(v46) + 1; //Next Possible Arena Setting
                }
                while ( v46[v47] );
            }
            if ( player->MyArena )
            {
                a3[0] = 7;                            // 0x07 - Chat
                a3[1] = 0;
                a3[2] = 0;
                *(unsigned short *)&a3[3] = -1;
                strcpy(&a3[5], "Settings have been successfully changed.");
                v49 = strlen("Settings have been successfully changed.");
                if ( GetBillingServerRelOut(player->connection, 0) < 128 )
                    SendPlayerReliablePacket(player, a3, v49 + 6, 1);
            }
        } else {
            if ( player->MyArena )
            {
                strcpy(&a3[5], "Only the owner of this arena can change the settings.");
                a3[0] = 7;                            // 0x07 - Chat
                a3[1] = 0;
                a3[2] = 0;
                *(unsigned short *)&a3[3] = -1;
                v45 = strlen("Only the owner of this arena can change the settings.");
                if ( GetBillingServerRelOut(player->connection, 0) < 128 )
                    SendPlayerReliablePacket(player, a3, v45 + 6, 1);
            }
        }
        return;
    case 0x1C:                                    // 0x1C - Drop Brick
        if ( player->Ship != 8 )
        {
            v50 = *(unsigned short *)&packet[1];
            v51 = *(unsigned short *)&packet[3];
            if ( v50 < 0 || v50 >= 1024 || v51 < 0 || v51 >= 1024 )
            {
                if ( !player->IsSuperModerator )
                {
                    sprintf(a1, "Packet tampering(%d)", PacketType);
                    SendBillerWarnings(a1, player);
                    if ( player->MyArena )
                    {
                        if ( player->MyArena->ServersideArenaSettings.dwordB4 ) {
                            player->DisconnectReason = 0x10;   // 0x10 - Restricted Zone, Compare against local Subspace.exe to determine if an Update is needed.
                            player->AlreadySentReliablePacket = 1;
                            return;
                        }
                    }
                }
            }
            else
            {
                DropBrick(player->MyArena, v50, v51, player->Frequency);
            }
        }
        return;
    case 0x1B:                                    // 0x1B - Security violation
        SecurityViolation(player, packet[1]);
        return;
    case 0x22:                                    // 0x22 - Security Violation Unknown
        if ( player->MyArena && !player->IsSuperModerator )
        {
            if ( packet[17] )
            {
                SecurityViolation(player, packet[17]);
            }
            else
            {
                if ( *(unsigned int *)&Security[player->SubspaceEXEChecksumIndex].ScrtyData[4] != *(unsigned int *)&packet[9] )
                {
                    SendBillerWarnings("WARNING: Code checksum mismatch (unsolicited)", player);
                    if ( player->MyArena->ServersideArenaSettings.dwordB4 )
                    {
                        player->DisconnectReason = 3;     // 0x03 - Arena is Full
                        player->AlreadySentReliablePacket = 1;
                    }
                }
                v54 = 0;
                v55 = (char *)&player->MyArena->ArenaSettings;
                v56 = 357;
                do
                {
                    v54 += *(unsigned int *)v55;
                    v55 += 4;
                    --v56;
                }
                while ( v56 );
                if ( v54 != *(unsigned int *)&packet[5] )
                {
                    SendBillerWarnings("WARNING: Parameter checksum mismatch (unsolicited)", player);
                    if ( player->MyArena->ServersideArenaSettings.dwordB4 )
                    {
                        player->DisconnectReason = 3;
                        player->AlreadySentReliablePacket = 1;
                    }
                }
            }
        }
        return;
    case 0x1A:                                    // 0x1A - Security checksum
        if ( player->LastSecurityPacketReturnedTime )
        {
            player->LastSecurityPacketReturnedTime = 0;
            v338 = (GetTickCount() / 0xA) - player->LastSecurityPacketReturnedTime;
            player->SecurityWeaponCountTotal = player->SecurityWeaponCountyTotalNew;
            player->SecurityWeaponCount = *(unsigned int *)(packet + 1);// Weapon Count
            memcpy(&player->SecurityPacketCache, packet, 0x28);
            if ( packet[39] )  // Slow Frame Detected (Boolean)
            {
                SecurityViolation(player, packet[39]);
            }
            else
            {
                if ( player->MyArena && !player->IsSuperModerator && player->MyArena->SettingsChecksum )
                {
                    v61 = *(unsigned int *)&packet[9];      // Subspace.EXE Checksum from packet
                    if ( *(unsigned int *)(&Security[0].ScrtyData[8 * player->MyArena->RandomScrtyDataIndex + 4] + player->SubspaceEXEChecksumIndex * 4036) != v61 )
                    {
                        v63 = 0;
                        v64 = &Security[player->SubspaceEXEChecksumIndex].ScrtyData[4];
                        v65 = 500;
                        do
                        {
                            if ( *(unsigned int *)v64 == v61 )
                                v63 = 1;
                            v64 += 8;
                            --v65;
                        }
                        while ( v65 );
                        if ( v63 )
                            v327 = "WARNING: Code checksum mismatch - [%d] old match";
                        else
                            v327 = "WARNING: Code checksum mismatch - [%d] no possible match";
                        sprintf(a1, v327, *(unsigned int *)&packet[9]);// Subspace.EXE Checksum
                        SendBillerWarnings(a1, player);
                        if ( player->MyArena->ServersideArenaSettings.dwordB4 )
                        {
                            player->DisconnectReason = 3;   // 0x03 - Arena is Full
                            player->AlreadySentReliablePacket = 1;
                        }
                    }
                    if ( player->MyArena->SettingsChecksum != *(unsigned int *)&packet[5] ) // Settings Checksum
                    {
                        sprintf(a1, "WARNING: Parameter checksum mismatch: TimeSinceRequest:%d0 ms", v338);
                        SendBillerWarnings(a1, player);
                        if ( player->MyArena->ServersideArenaSettings.dwordB4 )
                        {
                            player->DisconnectReason = 3;   // 0x03 - Arena is Full
                            player->AlreadySentReliablePacket = 1;
                        }
                    }
                    v66 = *(unsigned int *)&packet[13];     // Map.LVL Checksum
                    if ( v66 != -12345678 )
                    {
                        if ( player->MyArena->MapLVLChecksum != v66 )
                        {
                            SendBillerWarnings("WARNING: Level checksum mismatch", player);
                            if ( player->MyArena->ServersideArenaSettings.dwordB4 )
                            {
                                player->DisconnectReason = 3; // 0x03 - Arena is Full
                                player->AlreadySentReliablePacket = 1;
                            }
                        }
                    }
                    v67 = *(unsigned short *)&packet[25];
                    v68 = *(unsigned short *)&packet[27] + v67;
                    if ( v68 > player->MyArena->ArenaSettings.ClientSlowPacketSampleSize
                            && player->Ship != 8
                            && 1000 * v67 / v68 > player->MyArena->ServersideArenaSettings.LatencyClientSlowPacketKickoutPercent )
                    {
                        if ( player->MyArena )
                        {
                            strcpy(v364, "You have been put in spectator mode due to high latency (S2C)");
                            a3[0] = 7;                            // 0x07 - Chat
                            a3[1] = 0;
                            a3[2] = 0;
                            *(unsigned short *)&a3[3] = -1;
                            v70 = strlen("You have been put in spectator mode due to high latency (S2C)");
                            if ( GetBillingServerRelOut(player->connection, 0) < 128 )
                                SendPlayerReliablePacket(player, a3, v70 + 6, 1);
                        }
                        SetPlayerShip(player, 8);
                    }
                }
            }
        }
        return;
    case 0x0C:                                    // 0x0C - Map.lvl Request
        if ( player->MyArena )
            SendHugeChunkPacketNotAllocated(
                player->connection,
                player->MyArena->CompressedMap,
                player->MyArena->MapFileSize,
                0);
        return;
    case 0x0D:                                    // 0x0D - News.txt Request
        NewsSendBuffer = AllocateMemory(NewsTxtFileSize);
        memcpy(NewsSendBuffer, CompressedNewsMemory, NewsTxtFileSize);
        SendHugeChunkPacketAllocated(player->connection, NewsSendBuffer, NewsTxtFileSize, 0);
        return;
    case 0x0B:                                    // 0x0B - SSUpdate.EXE Request
        if ( player->SubspaceVersion == 132
                && Security[player->SubspaceEXEChecksumIndex].Subspace132EXEBytes != 0 ) {
            //Send UPDATE2.EXE aka Subspace 1.32 installer
            SendHugeChunkPacketNotAllocated(
                player->connection,
                Security[player->SubspaceEXEChecksumIndex].Subspace132EXEBytes,
                Security[player->SubspaceEXEChecksumIndex].Subspace132FileSize,
                0);
        } else if ( player->SubspaceVersion == 133
                    && Security[player->SubspaceEXEChecksumIndex].Subspace133EXEBytes != 0 ) {
            //Send UPDATE1.EXE aka Subspace 1.33 installer
            SendHugeChunkPacketNotAllocated(
                player->connection,
                Security[player->SubspaceEXEChecksumIndex].Subspace133EXEBytes,
                Security[player->SubspaceEXEChecksumIndex].Subspace133FileSize,
                0);
        } else {
            //Send UPDATE.EXE aka Subspace 1.31 installer
            SendHugeChunkPacketNotAllocated(
                player->connection,
                Security[player->SubspaceEXEChecksumIndex].Subspace131EXEBytes,
                Security[player->SubspaceEXEChecksumIndex].Subspace131FileSize,
                0);
        }
        return;
    case 0x03:                                     // 0x03 - Position packet
        player->field_309 = 0;
        if ( !player->MyArena )
            return;
        OriginalPositionPacketChecksum = packet[10];            // Checksum BYTE
        PositionPacketChecksum = 0;
        packet[10] = 0;
        v81 = 0;
        v82 = 22;
        do
        {
            PositionPacketChecksum ^= packet[v81++];
            --v82;
        }
        while ( v82 );
        if ( PositionPacketChecksum != OriginalPositionPacketChecksum )
        {
            if ( !player->IsSysop )
            {
                player->CurrentSecurityPacketModifcationCount++;
                if ( player->CurrentSecurityPacketModifcationCount >= player->MyArena->ServersideArenaSettings.SecurityPacketModificationMax )
                {
                    SendBillerWarnings("C2S position packet checksum error", player);
                    if ( player->MyArena->ServersideArenaSettings.dwordB4 )
                    {
                        player->DisconnectReason = 3;     // 0x03 - Arena is Full
                        player->AlreadySentReliablePacket = 1;
                    }
                }
            }
            return;
        }
        if ( packet[11] & 0x40 && !player->field_3C ) // Togglables
            return;
        if ( *(unsigned short *)&packet[16] > 10000 && !player->IsSuperModerator && !player->field_305 ) // Bounty
        {
            sprintf(a1, "Packet tampering(%d)", PacketType);
            v332 = player;
            v328 = a1;
            goto LABEL_366;
        }
        if ( packet[20] & 0x1F )     // Weapon Info
            player->DeathsWithoutFiring = 0;
        v84 = ((player->connection->SyncResponseLocalTimeStamp + GetTickCount() / 0xA) & 0x7FFFFFFF) - *(unsigned int *)&packet[2]; // Timestamp
        v85 = v84;
        if ( (v84 & 0x80000000) != 0 || v84 > 30000 )
        {
            v85 = 0;
        }
        if ( v85 > player->MyArena->ServersideArenaSettings.LatencyMaxLatencyForWeapons )
            *(unsigned short *)&packet[20] &= 0x7F80;     // Weapon Info
        if ( v85 < player->MyArena->ServersideArenaSettings.LatencyMaxLatencyForKickOut || v85 > 800 || player->IsSysop )
            player->LatencyKickOutDelayTimer = GetTickCount() / 0xA;
        if ( v85 < player->MyArena->ServersideArenaSettings.LatencySlowPacketTime || v85 > 800 || player->IsSysop )
            ++player->C2SCurrentFast;
        else
            ++player->C2SCurrentSlow;
        if ( player->C2SCurrentSlow + player->C2SCurrentFast > player->MyArena->ServersideArenaSettings.LatencySlowPacketSampleSize )
        {
            player->C2SCurrentTotalFast += player->C2SCurrentFast;
            player->C2SCurrentTotalSlow += player->C2SCurrentSlow;
            if ( player->Ship != 8 )
            {
                if ( 1000 * player->C2SCurrentSlow / (player->C2SCurrentSlow + player->C2SCurrentFast) > player->MyArena->ServersideArenaSettings.LatencySlowPacketKickoutPercent )
                {
                    if ( player->MyArena )
                    {
                        strcpy(v364, "You have been put in spectator mode due to high latency (C2S)");
                        a3[0] = 7;                   // 0x07 - Chat
                        a3[1] = 0;
                        a3[2] = 0;
                        *(unsigned short *)&a3[33] = -1;
                        v87 = strlen("You have been put in spectator mode due to high latency (C2S)");
                        if ( GetBillingServerRelOut(player->connection, 0) < 128 )
                            SendPlayerReliablePacket(player, a3, v87 + 6, 1);
                    }
                    SetPlayerShip(player, 8);
                }
            }
            player->C2SCurrentFast = 0;
            player->C2SCurrentSlow = 0;
        }
        if ( v85 < 800 && v85 > 0 )
        {
            player->C2SAverageLatencyFirst += v85;
            ++player->C2SAverageLatencySecond;
        }
        v88 = *(unsigned short *)&packet[12];           // X Pixels (0 ... 16384)
        if ( v88 >= 0 && *(unsigned short *)&packet[8] >= 0 && player->Ship != 8 ) // Y Pixels (0 ... 16384)
        {
            if ( player->MyArena->ServersideArenaSettings.PacketLossDisableWeapons && rand() % 1000 < player->field_153 )
                *(unsigned short *)&packet[20] &= 0x7F80;
            if ( (*(unsigned short *)&packet[12] - player->XPixels) > 512 // X Pixels (0 ... 16384)
                    || (*(unsigned short *)&packet[8] - player->YPixels) > 512) // Y Pixels (0 ... 16384)
                player->field_10F = 1;
            if ( packet[11] & 0x20 && !(player->ShipTogglables & 0x20) ) // Togglables
                player->field_10F = 1;
            memcpy(&player->PositionByteThree, packet, 0x16);
            if ( (player->WeaponsInfo & 0x1F) == 8 )
            {
                v91 = player->field_283;
                v92 = player->field_283;
                if ( v91 >= 3 )
                    v92 = 3;
                if ( v92 >= 0 )
                {
                    if ( v91 >= 3 )
                        v91 = 3;
                }
                else
                {
                    v91 = 0;
                }
                player->WeaponsInfo = 32 * (v91 & 3) | player->WeaponsInfo & 0xFF9F;
            }
            if ( (unsigned int)packetSize > 0x16 )
            {
                player->EnergyOptional = *(unsigned int *)&packet[22];// Energy (Optional)
                player->TimerOptional = *(unsigned int *)&packet[26];// Timer (Optional)
                player->SharpnelMinesBombsBulletsMultifireInformationOptional = *(unsigned short *)&packet[30];
                player->field_10B = 1;
            }
            sub_40D870(player);
            player->SendWeaponUpdatePacket = 1;
            if ( player->WeaponsInfo & 0x1F )
                SendWeaponPacket(player);
            return;
        }
        if ( player->ArenaPlayerIndex < 0 )
        {
            if ( v88 < 0 || *(unsigned short *)&packet[8] < 0 ) // X Pixel & Y Pixel Checks
            {
                v95 = player->XPixels;
                v96 = player->YPixels;
                memcpy(&player->PositionByteThree, packet, 0x16);
                player->XPixels = v95;
                player->YPixels = v96;
            }
            else
            {
                memcpy(&player->PositionByteThree, packet, 0x16);
            }
        }
        else
        {
            if ( !ZonePlayerList[player->ArenaPlayerIndex] )
                goto LABEL_199;
            player->XPixels = ZonePlayerList[player->ArenaPlayerIndex]->XPixels;
            player->YPixels = ZonePlayerList[player->ArenaPlayerIndex]->YPixels;
        }
        sub_40D870(player);
LABEL_199:
        if ( player->AttachedToPlayerId >= 0 )
        {
            if ( ZonePlayerList[player->AttachedToPlayerId] )
            {
                player->XPixels = ZonePlayerList[player->AttachedToPlayerId]->XPixels;
                player->YPixels = ZonePlayerList[player->AttachedToPlayerId]->YPixels;
                sub_40D870(player);
            }
        }
        return;
    case 0x1E:                                    // 0x1E - End Personal KoTH Timer
        if ( player->KotHDeathCount > 0 )
        {
            player->KotHDeathCount--;
            player->KingCrownKills = 0;
            if ( player->KotHDeathCount )
            {
                buffer3[0] = 0x2B;                 // 0x2B - Set Personal KotH Timer
                *(unsigned int *)&buffer3[1]  = player->MyArena->ServersideArenaSettings.KingExpireTime;
                SendPlayerReliablePacket(player, buffer3, 5, 1);
            }
            else
            {
                buffer3[0] = 0x2C;                 // 0x2C - KotH Game Reset
                buffer3[1] = 0;
                *(unsigned int *)&buffer3[2] = 0;  // Timer Value
                *(unsigned short *)&buffer3[6] = player->PlayerId;                          // Player ID
                SendArenaPacket(player->MyArena, buffer3, 8, 1);
            }
        }
        return;
    case 0x05:                                     // 0x05 - Death message
        if ( !player->MyArena )
            return;
        UpdatePowerBallPositions(player);
        player->KingCrownKills = 0;
        v103 = *(unsigned short *)&packet[1];            // Killer's Player ID
        if ( v103 >= 0  && v103 <= 1024 && *(unsigned short *)&packet[3] <= 20000 ) // 20000 Bounty
        {
            a2 = 0;
            playera = ZonePlayerList[v103];
            if ( playera && playera->MyArena != player->MyArena )
                playera = 0;
            if ( !player->MyArena->ServersideArenaSettings.FlagFriendlyTransfer )
            {
                if ( !playera )
                    goto LABEL_226;
                if ( playera->Frequency == player->Frequency ) // Check for Team Kills?
                {
                    buffer6[0] = 0x16;           // 0x16 - Drop Flag
                    *(unsigned short *)&buffer6[1] = player->PlayerId;
                    SendArenaPacket(player->MyArena, buffer6, 3, 1);
                    if ( player->MyArena->ServersideArenaSettings.FlagMode )
                    {
                        if ( player->MyArena->ServersideArenaSettings.FlagMode == 1 )
                        {
                            CarryFlagsSomething(player->MyArena, player->PlayerId, 1);
                            FlagPositionUpdateSomething(player->MyArena, 0);
                        }
                    }
                    else
                    {
                        CarryFlagsSomething(player->MyArena, player->PlayerId, 0);
                    }
                }
            }
            if ( playera && playera->Ship == 8 )
            {
                buffer6[0] = 0x16;             // 0x16 - Drop Flag
                *(unsigned short *)&buffer6[1] = player->PlayerId;
                SendArenaPacket(player->MyArena, buffer6, 3, 1);
                if ( player->MyArena->ServersideArenaSettings.FlagMode )
                {
                    if ( player->MyArena->ServersideArenaSettings.FlagMode == 1 )
                    {
                        CarryFlagsSomething(player->MyArena, player->PlayerId, 1);
                        FlagPositionUpdateSomething(player->MyArena, 0);
                    }
                }
                else
                {
                    CarryFlagsSomething(player->MyArena, player->PlayerId, 0);
                }
            }
LABEL_226:
            if ( player->KotHDeathCount <= 0 )
            {
                if ( playera )
                {
                    if ( playera->KotHDeathCount > 0 )
                    {
                        if ( player->MyArena->ServersideArenaSettings.KingNonCrownAdjustTime > 0 )
                        {
                            if ( *(unsigned short *)&packet[3] >= player->MyArena->ServersideArenaSettings.KingNonCrownMinimumBounty
                                    && player->Frequency != playera->Frequency )
                            {
                                buffer3[0] = 0x2D;         // 0x2D - Add KotH time
                                *(unsigned int *)&buffer3[1] = player->MyArena->ServersideArenaSettings.KingNonCrownAdjustTime;
                                SendPlayerReliablePacket(playera, buffer3, 5, 1);
                                goto LABEL_243;
                            }
                        }
                    }
                }
            }
            else
            {
                player->KotHDeathCount--;
                if ( player->KotHDeathCount )
                {
                    buffer3[0] = 0x2B;               // 0x2B - Set Personal KotH Timer
                    *(unsigned int *)&buffer3[1] = player->MyArena->ServersideArenaSettings.KingExpireTime;
                    SendPlayerReliablePacket(player, buffer3, 5, 1);
                }
                else
                {
                    buffer3[0] = 0x2C;               // 0x2C - KotH Game Reset
                    buffer3[1] = 0;
                    *(unsigned int *)&buffer3[2] = 0;
                    *(unsigned short *)&buffer3[6] = player->PlayerId;
                    SendArenaPacket(player->MyArena, buffer3, 8, 1);
                }
                if ( playera )
                {
                    if ( playera->KotHDeathCount > 0 )
                    {
                        buffer3[0] = 0x2B;             // 0x2B - Set Personal KotH Timer
                        *(unsigned int *)&buffer3[1] = player->MyArena->ServersideArenaSettings.KingExpireTime;
                        SendPlayerReliablePacket(playera, buffer3, 5, 1);
                        goto LABEL_243;
                    }
                    playera->KingCrownKills++;
                    if ( player->MyArena->ServersideArenaSettings.KingCrownRecoverKills > 0
                            && playera->KingCrownKills >= player->MyArena->ServersideArenaSettings.KingCrownRecoverKills )
                    {
                        playera->KotHDeathCount = player->MyArena->ServersideArenaSettings.KingDeathCount;
                        buffer3[0] = 0x2C;            // 0x2C - KotH Game Reset
                        buffer3[1] = 1;
                        *(unsigned int *)&buffer3[2] = player->MyArena->ServersideArenaSettings.KingExpireTime;
                        *(unsigned short *)&buffer3[6] = playera->PlayerId;
                        SendArenaPacket(player->MyArena, buffer3, 8, 1);
                    }
                }
            }
LABEL_243:
            player->DebtKills = player->MyArena->ServersideArenaSettings.KillDebtKills;
            player->DeathsWithoutFiring++;
            if ( player->DeathsWithoutFiring > player->MyArena->ServersideArenaSettings.SecurityMaxDeathWithoutFiring && !player->IsModerator )
            {
                WriteSubGameLog("Played kicked off for too many deaths without firing: %s\n", player->PlayerName);
                player->DisconnectReason = 10;        // 0x0A - Server is Full
                player->AlreadySentReliablePacket = 1;
            }
            v128 = 0;
            v340 = 0;
            if ( player->MyArena->ArenaSettings.CarryFlags && player->MyArena->FlagCounter > 0 )
            {
                v127 = 0;
                do
                {
                    if ( player->MyArena->Flags[v127].CarrierPlayerId == player->PlayerId )
                        ++v128;
                    if ( player->MyArena->Flags[v127].CarrierPlayerId == *(unsigned short *)&packet[1] )
                        ++v340;
                    ++v127;
                }
                while ( v127 < player->MyArena->FlagCounter );
            }
            if ( player->MyArena->ArenaSettings.CarryFlags == 2 && v128 > 0 && v340 > 0 )
            {
                buffer6[0] = 0x16;	//0x16 - Drop Flag
                *(unsigned short *)&buffer6[1] = player->PlayerId;
                SendArenaPacket(player->MyArena, buffer6, 3, 1);
                if ( player->MyArena->ServersideArenaSettings.FlagMode )
                {
                    if ( player->MyArena->ServersideArenaSettings.FlagMode == 1 )
                    {
                        CarryFlagsSomething(player->MyArena, player->PlayerId, 1);
                        FlagPositionUpdateSomething(player->MyArena, 0);
                    }
                }
                else
                {
                    CarryFlagsSomething(player->MyArena, player->PlayerId, 0);
                }
                Password = 0;
            }
            if ( *(unsigned short *)&packet[1] == *(unsigned int *)&player->PlayerId ) // Killer's Player ID
            {
                v132 = -*(unsigned short *)&packet[3];
                printf("%s(%d) killed by self\n", player->PlayerDataBillerPacket.Name, v132);
                FormatMessageArena(player->MyArena, "%s(%d) killed by self\n", player->PlayerDataBillerPacket.Name, v132);
                player->CurrentSuicideCount++;
                if ( player->CurrentSuicideCount > player->MyArena->ServersideArenaSettings.SecuritySuicideLimit )
                {
                    WriteSubGameLog("Played kicked off for too many suicides: %s\n", player->PlayerName);
                    player->DisconnectReason = 0x13;   // 0x13 - Demo Versions not Allowed
                    player->AlreadySentReliablePacket = 1;
                }
                CarryFlagsSomething(player->MyArena, player->PlayerId, 0);
LABEL_304:
                v338 = -1;
                if ( playera )
                {
                    v155 = 0;
                    v156 = playera->FlagPoints;
                    v157 = playera->KillPoints;
                    v338 = playera->Frequency;
                    v158 = v157 + v156;
                    if ( v132 > 0 && v340 > 0 )
                        v155 = v132 * player->MyArena->ArenaSettings.FlaggerKillMultiplier;
                    AppendPointsLog(playera, v132, v155);
                    if ( playera->KillPoints < 0 )
                        playera->KillPoints = 0;
                    if ( v158 < AutoPermissionPoints )
                    {
                        if ( AutoPermissionPoints > 0 )
                        {
                            if (  playera->KillPoints + playera->FlagPoints >= AutoPermissionPoints )
                            {
                                if ( playera->MyArena)
                                {
                                    strcpy(v364, PermissionAutoPermissionMessage);
                                    a3[0] = 7;                            // 0x07 - Chat
                                    a3[1] = 0;
                                    a3[2] = 0;
                                    *(unsigned short *)&a3[3] = -1;
                                    v159 = strlen(PermissionAutoPermissionMessage);
                                    if ( GetBillingServerRelOut(playera->connection, 0) < 128 )
                                        SendPlayerReliablePacket(playera, a3, v159 + 6, 1);
                                }
                            }
                        }
                    }
                }
                ++player->CurrentDeaths;
                v163 = player->MyArena->ArenaJackpot;
                player->MyArena->ArenaJackpot = v163 + v132 * player->MyArena->ServersideArenaSettings.KillJackpotBountyPercent / 1000;
                if ( MiscJackpotBroadcastPoints > 0 )
                {
                    v340 = player->MyArena->ArenaJackpot / MiscJackpotBroadcastPoints;
                    if ( v163 / MiscJackpotBroadcastPoints < v340 )
                    {
                        a3[0] = 2;
                        a3[1] = 0;
                        sprintf(
                            &a3[2],
                            "Jackpot just passed %d points in %s",
                            MiscJackpotBroadcastPoints * player->MyArena->ArenaJackpot / MiscJackpotBroadcastPoints,
                            BillingServerName);
                        if ( BillingConnectionStructPointer )
                            SendBillerUserPrivateChatPacket(
                                BillingConnectionStructPointer,
                                -1,
                                BillingGroupId,
                                a3,
                                strlen(&a3[2]) + 3);
                    }
                }
                buffer4[0] = 0x06;                             // 0x06 - Player Death
                *(unsigned short *)&buffer4[2] = *(unsigned short *)&packet[1];
                *(unsigned short *)&buffer4[4] = player->PlayerId;
                *(unsigned short *)&buffer4[6] = v132;
                *(unsigned short *)&buffer4[8] = 0;
                v168 = 0;
                buffer4[1] = GetDeathPrizeGreenId(player->MyArena); //ID of green left by death
                if ( *(unsigned short *)&buffer4[8] || abs(*(signed short *)&buffer4[6]) > 160 )
                {
                    SendArenaPacket(player->MyArena, buffer4, 10, 1);
                }
                else
                {
                    if ( player->MyArena->ServersideArenaSettings.MiscTimedGame )
                    {
                        if ( player->MyArena->ArenaPlayerCount > 0 )
                        {
                            do
                            {
                                v174 = player->MyArena->ArenaPlayers[v168]->AttachedToPlayerId == player->PlayerId
                                       || (player->MyArena->ArenaPlayers[v168]->PlayerId == player->PlayerId)
                                       || (player->MyArena->ArenaPlayers[v168]->PlayerId == *(unsigned short *)&packet[1]);
                                SendPlayerReliablePacket(player->MyArena->ArenaPlayers[v168], buffer4, 10, v174);
                                ++v168;
                            }
                            while ( v168 < player->MyArena->ArenaPlayerCount );
                        }
                        goto LABEL_355;
                    }
                    v340 = 0;
                    if ( player->MyArena->ArenaPlayerCount > 0 )
                    {
                        do
                        {
                            v178 = player->MyArena->ArenaPlayers[v340];
                            if ( v178->ArenaPlayerIndex >= 0 )
                                v178 = ZonePlayerList[v178->ArenaPlayerIndex];
                            if ( !v178 ) {
                                ++v340;
                                continue;
                            }
                            if ( v178->Frequency != player->Frequency && v178->Frequency != v338 )
                            {
                                if ( !v178 ) {
                                    ++v340;
                                    continue;
                                }
                                v183 = v178->AttachedToPlayerId;
                                if ( v183 >= 0 )
                                    v178 = ZonePlayerList[v183];
                                if ( !v178
                                        || v178->YPixels - player->YPixels > player->MyArena->ServersideArenaSettings.RoutingDeathDistance
                                        || v178->XPixels - player->XPixels > player->MyArena->ServersideArenaSettings.RoutingDeathDistance ) {
                                    ++v340;
                                    continue;
                                }
                                v334 = 0;
                            }
                            else
                            {
                                v334 = v178->AttachedToPlayerId == player->PlayerId
                                       || (v178->PlayerId == player->PlayerId)
                                       || (v178->PlayerId == *(unsigned short *)&packet[1]);
                            }
                            SendPlayerReliablePacket(player->MyArena->ArenaPlayers[v340], buffer4, 0x0A, v334);
                            ++v340;
                        }
                        while ( v340 < player->MyArena->ArenaPlayerCount );
                    }
                }
LABEL_355:
                if ( player->MyArena->ServersideArenaSettings.MiscMaxLossesToPlay > 0 &&
                        player->CurrentDeaths >= player->MyArena->ServersideArenaSettings.MiscMaxLossesToPlay )
                    SetPlayerShip(player, 8);
                if ( AdvertiseSendMode == 3 || AdvertiseSendMode == 2 )
                    SendAdvertisement(player, false);
                if ( playera )
                    SendPlayerScoreUpdateAll(playera);
                SendPlayerScoreUpdateAll(player);
                return;
            }
            player->CurrentSuicideCount = 0;
            if ( !playera )
            {
                printf("%s killed by UNKNOWN\n", player->PlayerDataBillerPacket.Name);
                CarryFlagsSomething(player->MyArena, player->PlayerId, 0);
LABEL_303:
                dword_4D8B14 = *(unsigned int *)&player->PlayerId;
                goto LABEL_304;
            }
            if ( player->MyArena->ServersideArenaSettings.KillFixedKillReward < 0 )
            {
                v138 = player->MyArena->ArenaSettings.MaxBonus;
                if ( playera->Bounty >= 0 )
                {
                    v139 = *(unsigned short *)&packet[3] - playera->Bounty;
                    if ( v139 < v138 )
                        v138 = *(unsigned short *)&packet[3] - playera->Bounty;
                    v140 = -player->MyArena->ArenaSettings.MaxPenalty;
                    if ( v138 <= v140 || (v140 = player->MyArena->ArenaSettings.MaxBonus, v139 >= v140) )
                        v139 = v140;
                    v136 = v139 + *(unsigned short *)&packet[3] + player->MyArena->ArenaSettings.RewardBase;
                }
                else
                {
                    v136 = *(unsigned short *)&packet[3];
                }
            }
            else
            {
                v136 = player->MyArena->ServersideArenaSettings.KillFixedKillReward;
            }
            v141 = (signed int)playera->Bounty * player->MyArena->ServersideArenaSettings.KillBountyRewardPercent / 100
                   + v136;
            v338 = player->MyArena->ServersideArenaSettings.KillPointsPerFlag;
            a2 = v141;
            if ( v338
                    && player->MyArena->ArenaPlayerCount > player->MyArena->ServersideArenaSettings.PeriodicRewardMinimumPlayers
                    && *(unsigned short *)&packet[3] > player->MyArena->ServersideArenaSettings.KillPointsMinimumBounty )
            {
                v142 = 0;
                v143 = 0;
                if ( v142 > 0 )
                {
                    do
                    {
                        if ( player->MyArena->Flags[v142].OwnerFreq == playera->Frequency )
                            ++v143;
                        ++v142;
                    }
                    while ( v142 < player->MyArena->FlagCounter );
                }
                a2 = v338 * v143 + v141;
            }
            v145 = 0;
            v146 = &playera->someStringBuffer[4];
            do
            {
                if ( *(unsigned int *)v146 == player->PlayerDataBillerPacket.UserId )
                {
                    v147 = (GetTickCount() / 0xA - *(unsigned int *)&playera->someStringBuffer[8 * v145]);
                    goto LABEL_290;
                }
                ++v145;
                v146 += 8;
            }
            while ( v145 < 8 );
            v147 = 0xFFFFFFF;
LABEL_290:
            if ( v147 >= player->MyArena->ServersideArenaSettings.KillNoRewardKillDelay )
            {
                v148 = player->PlayerDataBillerPacket.UserId;
                *(unsigned int *)&playera->someStringBuffer[8 * playera->field_A8] = GetTickCount() / 0xA;
                *(unsigned int *)&playera->someStringBuffer[8 * playera->field_A8 + 4] = v148;
                playera->field_A8 = ((unsigned long)abs(*((unsigned char*)&(playera->field_A8)) + 1) & 7);
                if ( playera->Frequency != player->Frequency )
                {
                    v149 = playera->DebtKills;
                    if ( v149 <= 0 )
                    {
LABEL_295:
                        v150 = a2;
                        ++playera->CurrentWins;
                        printf("%s(%d) killed by %s\n", player->PlayerDataBillerPacket.Name, v150, playera->PlayerDataBillerPacket.Name);
                        FormatMessageArena(player->MyArena, "%s(%d) killed by %s\n", player->PlayerDataBillerPacket.Name, a2, playera->PlayerDataBillerPacket.Name);
                        if ( player->MyArena->ArenaSettings.CarryFlags )
                        {
                            v152 = 0;
                            if ( player->MyArena->FlagCounter > 0 )
                            {
                                do
                                {
                                    if ( player->MyArena->Flags[v152].CarrierPlayerId == player->PlayerId )
                                    {
                                        player->MyArena->Flags[v152].CarrierPlayerId = playera->PlayerId;
                                        player->MyArena->Flags[v152].OwnerFreq = playera->Frequency;
                                    }
                                    ++v152;
                                }
                                while ( v152 < player->MyArena->FlagCounter );
                            }
                        }
                        goto LABEL_303;
                    }
                    playera->DebtKills = v149 - 1;
                }
            }
            a2 = 0;
            goto LABEL_295;
        }
        if ( !player->IsSuperModerator )
        {
            sprintf(a1, "Packet tampering(%d)", PacketType);
            v332 = player;
            v328 = a1;
LABEL_366:
            SendBillerWarnings(v328, v332);
            if ( player->MyArena != 0 )
            {
                if ( player->MyArena->ServersideArenaSettings.dwordB4 != 0 ) {
                    player->DisconnectReason = 0x10;   // 0x10 - Restricted Zone, Compare against local Subspace.exe to determine if an Update is needed.
                    player->AlreadySentReliablePacket = 1;
                    return;
                }
            }
        }
        return;
    case 0x07:                                     // 0x07 - Take Green / Prize
        if ( player->MyArena && player->Ship != 8 )
        {
            if ( *(unsigned short *)&packet[9] >= 29
                    || *(unsigned short *)&packet[5] < 0
                    || *(unsigned short *)&packet[5] >= 1024
                    || *(unsigned short *)&packet[7] < 0
                    || *(unsigned short *)&packet[7] >= 1024 )
            {
                if ( !player->IsSuperModerator )
                {
                    sprintf(a1, "Packet tampering(%d)", PacketType);
                    SendBillerWarnings(a1, player);
                    if ( player->MyArena )
                    {
                        if ( player->MyArena->ServersideArenaSettings.dwordB4 ) {
                            player->DisconnectReason = 0x10;   // 0x10 - Restricted Zone, Compare against local Subspace.exe to determine if an Update is needed.
                            player->AlreadySentReliablePacket = 1;
                            return;
                        }
                    }
                }
            }
            else
            {
                v192 = ((player->connection->SyncResponseLocalTimeStamp + GetTickCount() / 0xA) & 0x7FFFFFFF) - *(unsigned int *)&packet[1];
                if ( (v192 & 0x80000000) != 0 || v192 > 30000 )
                    v192 = 0;
                if ( v192 <= player->MyArena->ServersideArenaSettings.LatencyMaxLatencyForPrizes )
                {
                    if ( player->PrizePacket.PrizeTimeStamp != *(unsigned int *)&packet[1] )
                    {
                        buffer4[0] = 0x08;                         // 0x08 - Player got a Prize
                        player->PrizePacket.PrizePacketId = PacketType;
                        player->PrizePacket.PrizeXTile = *(unsigned short *)&packet[5];
                        player->PrizePacket.PrizeYTile = *(unsigned short *)&packet[7];
                        player->PrizePacket.PrizeId = *(unsigned short *)&packet[9];

                        *(unsigned int *)&buffer4[1] = *(unsigned int *)&packet[1];
                        *(unsigned short*)&buffer4[5] = *(unsigned short *)&packet[5];
                        *(unsigned short*)&buffer4[7] = *(unsigned short *)&packet[7];
                        *(unsigned short*)&buffer4[9] = *(unsigned short *)&packet[9];
                        *(unsigned short*)&buffer4[11]= player->PlayerId;
                        if ( player->MyArena )
                        {
                            SendEverybodyButYourself(player, buffer4, 0x0D, player->MyArena->ServersideArenaSettings.PrizeS2CTakePrizeReliable);
                        }
                    }
                }
            }
        }
        return;
    case 0x13:                                    // 0x13 - Flag request
        if ( player->MyArena )
        {
            if ( player->Ship != 8 )
            {
                if ((GetTickCount() / 0xA - player->field_15B) >= player->MyArena->ServersideArenaSettings.LatencyNoFlagPenalty )
                {
                    v205 = *(unsigned short *)&packet[1];
                    if ( v205 >= 0 && v205 <= player->MyArena->FlagCounter )
                    {
                        if ( player->MyArena->ArenaSettings.CarryFlags != 2 )
                            goto LABEL_713;
                        v206 = 0;
                        v208 = 0;
                        if ( v206 > 0 )
                        {
                            do
                            {
                                if ( player->MyArena->Flags[v206].CarrierPlayerId == player->PlayerId )
                                    ++v208;
                                ++v206;
                            }
                            while ( v206 < player->MyArena->FlagCounter );
                        }
                        if ( v208 <= 0 )
                        {
LABEL_713:
                            if ( *(unsigned int *)&player->MyArena->Flags[v205].CarrierPlayerId == -1 )
                            {
                                buffer3[0] = 0x13;     // 0x13 - Flag Claim
                                *(unsigned short *)&buffer3[1] = *(unsigned short *)&packet[1];// Flag ID
                                *(unsigned short *)&buffer3[3] = player->PlayerId;// Player ID
                                SendArenaPacket(player->MyArena, buffer3, 5, 1);
                                player->MyArena->Flags[v205].OwnerFreq = player->Frequency;
                                if ( player->MyArena->ArenaSettings.CarryFlags )
                                    player->MyArena->Flags[v205].CarrierPlayerId = player->PlayerId;
                            }
                        }
                    }
                }
            }
        }
        return;
    case 0x0F:						// 0x0F - Frequency change
        if ( player->MyArena )
            PlayerChangeFrequency(player, *(unsigned short *)&packet[1]);
        return;
    case 0x18:                                    // 0x18 - Set ship type
        if ( !player->MyArena
                || (player->MyArena->ServersideArenaSettings.MiscMaxLossesToPlay > 0) && player->CurrentDeaths >= player->MyArena->ServersideArenaSettings.MiscMaxLossesToPlay
                || player->IsSpeced
                || packet[1] == player->Ship )
            return;
        v214 = packet[1];
        if ( v214 == 8 )
            goto LABEL_432;
        if ( !player->MyArena->ArenaLocked || player->IsSuperModerator )
        {
            if ( player->DemoPlayer && (v214 == 5 || v214 == 6 || v214 == 4 || v214 == 7) )
            {
                strcpy(&a3[5], "Demo version of SubSpace does not allow the use of that ship type.");
                a3[0] = 7;                            // 0x07 - Chat
                a3[1] = 0;
                a3[2] = 0;
                *(unsigned short *)&a3[3] = -1;
                v215 = strlen("Demo version of SubSpace does not allow the use of that ship type.");
                if ( GetBillingServerRelOut(player->connection, 0) < 128 )
                    SendPlayerReliablePacket(player, a3, v215 + 6, 1);
            }
            else
            {
                GetPingLOSSSomething(
                    player->connection,
                    &player->S2CPacketLossPercentage,
                    &player->C2SPacketLossPercentage);
                if ( player->S2CPacketLossPercentage >= player->MyArena->ServersideArenaSettings.PacketLossS2CKickOutPercent
                        && player->C2SPacketLossPercentage >= player->MyArena->ServersideArenaSettings.PacketLossC2SKickOutPercent
                        || player->IsSysop )
                {
LABEL_432:
                    player->DebtKills = player->MyArena->ServersideArenaSettings.KillDebtKills;
                    if ( v214 > 8 || v214 < 0 )
                    {
                        if ( !player->IsSuperModerator )
                        {
                            sprintf(a1, "Packet tampering(%d)", PacketType);
                            goto LABEL_606;
                        }
                    }
                    else
                    {
                        SetPlayerShip(player, v214);
                    }
                }
                else
                {
                    if ( player->MyArena )
                    {
                        a3[0] = 0x07;                        // 0x07 - Chat
                        a3[1] = 0;
                        a3[2] = 0;
                        *(unsigned short *)&a3[3] = -1;
                        strcpy(&a3[5], "Packet loss too high for you to enter the game.");
                        v216 = strlen("Packet loss too high for you to enter the game.");
                        if ( GetBillingServerRelOut(player->connection, 0) < 128 )
                            SendPlayerReliablePacket(player, a3, v216 + 6, 1);
                    }
                }
            }
        }
        return;
    case 0x14:                                    // 0x14 - Drop all attached pilots
        if ( player->MyArena )
        {
            buffer2[0] = 0x15;                     // 0x15 - Destroy Turret Link
            *(unsigned short *)&buffer2[1] = player->PlayerId;           // Turret Driver Player ID
            SendEverybodyButYourself(player, buffer2, 3, 1);
        }
        return;
    case 0x15:                                    // 0x15 - Drop flags
        if ( player->MyArena && player->MyArena->ArenaSettings.CarryFlags )
        {
            buffer2[0] = 0x16;                     //  0x16 - Drop Flag
            *(unsigned short *)&buffer2[1] = player->PlayerId;           // Carrier Player ID
            SendArenaPacket(player->MyArena, buffer2, 3, 1);
            if ( player->MyArena->ServersideArenaSettings.FlagMode )
            {
                if ( player->MyArena->ServersideArenaSettings.FlagMode == 1 )
                {
                    CarryFlagsSomething(player->MyArena, player->PlayerId, 1);
                    FlagPositionUpdateSomething(player->MyArena, 0);
                }
            }
            else
            {
                CarryFlagsSomething(player->MyArena, player->PlayerId, 0);
            }
        }
        return;
    case 0x08:                                     // 0x08 - Spectate request
        if ( player->MyArena )
        {
            v227 = *(unsigned short *)&packet[1]; //Spectated Player's Player ID
            if ( v227 == -1 || player->Ship == 8 )
            {
                if ( v227 > 1024 || v227 < -1 )
                {
                    if ( !player->IsSuperModerator )
                    {
                        sprintf(a1, "Packet tampering(%d)", PacketType);
                        SendBillerWarnings(a1, player);
                        if ( player->MyArena )
                        {
                            if ( player->MyArena->ServersideArenaSettings.dwordB4 ) {
                                player->DisconnectReason = 0x10;   // 0x10 - Restricted Zone, Compare against local Subspace.exe to determine if an Update is needed.
                                player->AlreadySentReliablePacket = 1;
                                return;
                            }
                        }
                    }
                }
                else
                {
                    v228 = player->ArenaPlayerIndex;
                    player->ArenaPlayerIndex = v227;
                    if ( v227 >= 0 )
                    {
                        v229 = ZonePlayerList[v227];
                        if ( v229 )
                        {
                            player->XPixels = v229->XPixels;
                            player->YPixels = v229->YPixels;
                            sub_40D870(player);
                        }
                    }
                    if ( player->IsSysop )
                    {
                        buffer2[0] = 0x1C;               // 0x1C - Put player in spectator mode / change extra info flag
                        if ( v228 >= 0 )
                        {
                            buffer2[1] = 0;                 // Player ID
                            if ( ZonePlayerList[v228] )
                                SendPlayerReliablePacket(ZonePlayerList[v228], buffer2, 2, 1);
                        }
                        if ( player->ArenaPlayerIndex >= 0 )
                        {
                            buffer2[1] = 1;                 // Player ID
                            if ( ZonePlayerList[player->ArenaPlayerIndex] )
                                SendPlayerReliablePacket(ZonePlayerList[player->ArenaPlayerIndex], buffer2, 2, 1);
                        }
                    }
                }
            }
            else
            {
                WriteSubGameLog("WARNING: Spectator request from non-spectator ship, ignoring\n");
            }
        }
        return;
    case 0x02:                                     // 0x02 - Leave arena
        if ( player->MyArena )
        {
            PlayerLeaveArena(player->MyArena, player);
            player->MyArena = 0;                    // Reset your arena pointer
        }
        printf("Player leaving game: %s\n", player->PlayerDataBillerPacket.Name);
        v236 = 0;
        do
        {
            if ( player->VoiceUploads[v236].VoiceMemoryPointer )
            {   //Free all Voice uploads.
                FreeMemory(player->VoiceUploads[v236].VoiceMemoryPointer);
                player->VoiceUploads[v236].VoiceMemoryPointer = 0;
            }
            ++v236;
        }
        while ( v236 < 4 );
        return;
    case 0x19:                                  // 0x19 - Set personal banner
        memcpy(player->PlayerDataBillerPacket.BannerData, &packet[1], sizeof(player->PlayerDataBillerPacket.BannerData));
        if ( BillingConnectionStructPointer )
            SendBillerUserBannerPacket(BillingConnectionStructPointer, player->BillerPlayerId, &packet[1]);
        buffer2[0] = 0x1E;                      // 0x1E - Personal Banner Changed
        buffer2[1] = 0;				// Boolean ?Unknown? (0x00)
        SendPlayerReliablePacket(player, buffer2, 2, 1);
        if ( player->MyArena
                && (player->FlagPoints + player->KillPoints >= player->MyArena->ServersideArenaSettings.MiscBannerPoints
                    || player->ForceWearBanner) )
        {
            buffer5[0] = 0x1F;                        // 0x1F - Player Banner Changed
            *(unsigned short *)&buffer5[1] = player->PlayerId;              // PlayerId
            memcpy(&buffer5[3], player->PlayerDataBillerPacket.BannerData, sizeof(player->PlayerDataBillerPacket.BannerData));// Banner Pixels
            SendArenaPacket(player->MyArena, buffer5, 99, 1);
        }
        return;
    case 0x0E:                                    // 0x0E - Voice Message
        v239 = packet[1];            // 0-3 Voice Slot Index
        v240 = *(unsigned short *)&packet[2];
        if ( v239 >= 4 || v239 < 0 || v240 > 1024 ) //PlayerId > 1024
        {
            if ( !player->IsSuperModerator )
            {
                sprintf(a1, "Packet tampering(%d)", PacketType);
                goto LABEL_606;
            }
        }
        else
        {
            if ( !player->VoiceUploads[v239].VoiceMemoryPointer )
            {
                player->VoiceUploads[v239].VoiceMemoryPointer = (char*)AllocateMemory(packetSize - 4);
                player->VoiceUploads[v239].VoiceSize = packetSize - 4;
                memcpy(
                    (unsigned char *)player->VoiceUploads[v239].VoiceMemoryPointer,
                    &packet[4],
                    packetSize - 4);
            }
            if ( v240 != -1 )
            {
                if ( v240 != -2 )
                {
                    if ( v240 >= 0 )
                    {
                        if ( ZonePlayerList[v240] )
                        {
                            if ( ZonePlayerList[v240]->connection->TotalHugeChunks == 0 )
                            {
                                v241 = player->VoiceUploads[v239].VoiceSize + 3;
                                v242 = AllocateMemory(player->VoiceUploads[v239].VoiceSize + 3);
                                v242[0] = 0x0C;	//0x0C - Player Voice
                                *(unsigned short *)&v242[1] = player->PlayerId;
                                memcpy(
                                    &v242[3],
                                    (unsigned char *)player->VoiceUploads[v239].VoiceMemoryPointer,
                                    player->VoiceUploads[v239].VoiceSize);
                                SendHugeChunkPacketAllocated(ZonePlayerList[v240]->connection, v242, v241, 1);
                                Wave += v241;
                            }
                        }
                    }
                }
            }
        }
        return;
    case 0x17:                                    // 0x17 - Registration Form Response
        if ( packetSize == 766 && BillingConnectionStructPointer )
            SendBillerUserDemographicsPacket(BillingConnectionStructPointer, player->BillerPlayerId, &packet[1]);
        return;
    case 0x06:                                     // 0x06 - Chat message
        if ( !player->IsSilenced  && player->MyArena )
        {
            ChatTargetPlayerId = *(unsigned short *)&packet[3];
            if ( ChatTargetPlayerId <= 1024 || ChatTargetPlayerId >= 0 )
            {
                if ( strlen(&packet[5]) > 250 )  //Max Chat text is 250 characters.
                {
                    if ( player->MyArena->ServersideArenaSettings.MessageBongAllowed || (v247 = player->IsModerator) != 0 )
                        v336 = packet[2];
                    else
                        v336 = 0;

                    ChatProcessor(player,
                                  packet[1],
                                  ChatTargetPlayerId,
                                  &packet[5], /* Chat Message */
                                  v336);
                }
            }
        } else {
	        if ( !player->IsSuperModerator )
	        {
	            sprintf(a1, "Packet tampering(%d)", PacketType);
	            SendBillerWarnings(a1, player);
	            if ( player->MyArena && player->MyArena->ServersideArenaSettings.dwordB4 ) {
	                player->DisconnectReason = 0x10;   // 0x10 - Restricted Zone, Compare against local Subspace.exe to determine if an Update is needed.
	                player->AlreadySentReliablePacket = 1;
	                return;
	            }
	        }
        }
        return;
    case 0x01:                                     // 0x01 - Arena login
        if ( player->PlayerDataBillerPacket.Name[0] )
        {
            if ( player->IsSuperModerator || GetProtocolVersion(player->connection) == 1 )
            {
                v249 = packet[1];  //Ship type
                if ( v249 > 8 || v249 < 0 )
                {
                    if ( !player->IsSuperModerator )
                    {
                        sprintf(a1, "Packet tampering(%d)", PacketType);
                        SendBillerWarnings(a1, player);
                        if ( player->MyArena )
                        {
                            if ( player->MyArena->ServersideArenaSettings.dwordB4 )
                            {
                                player->DisconnectReason = 0x10;// 0x10 - Restricted Zone - Compare against local Subspace.exe to determine if an Update is needed.
                                player->AlreadySentReliablePacket = 1;
                            }
                        }
                    }
                }
                else
                {
                    if ( player->MyArena )
                    {
                        PlayerLeaveArena(player->MyArena, player);
                        player->MyArena = 0;
                    }
                    player->ArenaPlayerIndex = -1;
                    player->Ship = v249;
                    player->AllowAudioByte1 = packet[2];
                    player->XResolution = *(unsigned short *)&packet[4];
                    player->YResolution = *(unsigned short *)&packet[6];
                    player->AllowAudioByte2 = packet[3];
                    if ( player->IsSpeced )
                        player->Ship = 8;
                    player->field_309 = 1;
                    *(unsigned short *)&buffer2[1] = player->PlayerId;// New PlayerId
                    buffer2[0] = 1;                     // 0x01 - PlayerID Change
                    SendPlayerReliablePacket(player, buffer2, 3, 1);
                    v251 = ArenaHandler(player, *(unsigned short *)&packet[8], &packet[10]);
                    player->MyArena = v251;
                    player->MyLastArena = v251;
                    PlayerEntering(v251, player);
                }
            }
            else
            {
                SendBillerWarnings("Incompatible network protocol attempting to enter game", player);
                player->AlreadySentReliablePacket = 1;
            }
        }
        return;
    case 0x16:                                    // 0x16 - File transfer
        v253 = player->field_58;
        if ( v253 < 0 )
        {
            v256 = player->field_60;
            if ( v256 < 0 )
            {
                CanUseFileTransferCommand = 0;
                if ( player->IsSysop )
                    CanUseFileTransferCommand = 1;
                if ( !stricmp(&packet[1], "moderate.txt") )
                    CanUseFileTransferCommand = 1;
                if ( !stricmp(&packet[1], "permit.txt") )
                    CanUseFileTransferCommand = 1;
                if ( !stricmp(&packet[1], player->MyArena->SetLevelMapFilename)
                        && player->PlayerDataBillerPacket.UserId == player->MyArena->ServersideArenaSettings.OwnerUserId )
                    CanUseFileTransferCommand = 1;
                if ( CanUseFileTransferCommand )
                {
                    if ( player->IsSysop || packetSize <= 524288 ) // 512 KB Max
                    {
                        v265 = fopen(&packet[1], "wb");
                        if ( v265 )
                        {
                            fwrite(&packet[17], packetSize - 17, 1, v265);
                            fclose(v265);
                        }
                        sprintf(a1, "File received: %s", &packet[1]);
                        if ( player->MyArena )
                        {
                            strcpy(&a3[5], a1); //File received text.
                            a3[0] = 0x07;	//0x07 - Chat packet
                            a3[1] = 0;
                            a3[2] = 0;
                            *(unsigned short *)&a3[3] = -1;
                            v267 = strlen(a1);
                            if ( GetBillingServerRelOut(player->connection, 0) < 128 )
                                SendPlayerReliablePacket(player, a3, v267 + 6, 1);
                        }
                        if ( !stricmp(&packet[1], player->MyArena->SetLevelMapFilename) )
                        {
                            if ( player->MyArena )
                            {
                                a3[0] = 7;		//0x07 - Chat packet
                                a3[1] = 0;
                                a3[2] = 0;
                                *(unsigned short *)&a3[3] = -1;
                                strcpy(&a3[5], "Arena is recycling so the change can take effect.");
                                v273 = strlen("Arena is recycling so the change can take effect.");
                                if ( GetBillingServerRelOut(player->connection, 0) < 128 )
                                    SendPlayerReliablePacket(player, a3, v273 + 6, 1);
                            }
                            player->MyArena->ArenaRecycling = 1;
                        }
                        if ( !stricmp(&packet[1], MiscDefaultLevelFile) )
                            RecycleServer = 1;
                    }
                    else
                    {
                        if ( player->MyArena )
                        {
                            strcpy(&a3[5], "File has arrived, but is too big (size limit of 512k)");
                            a3[0] = 7;                      // 0x07 - Chat
                            a3[1] = 0;
                            a3[2] = 0;
                            *(unsigned short *)&a3[3] = -1;
                            v264 = strlen("File has arrived, but is too big (size limit of 512k)");
                            if ( GetBillingServerRelOut(player->connection, 0) < 128 )
                                SendPlayerReliablePacket(player, a3, v264 + 6, 1);
                        }
                    }
                }
            }
            else
            {
                if ( ZonePlayerList[v256] && ZonePlayerList[v256]->PlayerDataBillerPacket.UserId == player->field_5C )
                {
                    sprintf(a1, "File arrived at server, forwarding to %s: %s", ZonePlayerList[v256]->PlayerDataBillerPacket.Name, &packet[1]);
                    if ( player->MyArena )
                    {
                        strcpy(&a3[5], a1);
                        a3[0] = 7;	                      // 0x07 - Chat
                        a3[1] = 0;
                        a3[2] = 0;
                        *(unsigned short *)&a3[3] = -1;
                        v258 = strlen(a1);
                        if ( GetBillingServerRelOut(player->connection, 0) < 128 )
                            SendPlayerReliablePacket(player, a3, v258 + 6, 1);
                    }
                    v259 = (char *)AllocateMemory(packetSize);
                    memcpy(&v259[17], &packet[17], packetSize - 17);
                    v259[0] = 0x10;	//0x10 - File Transfer
                    strcpy(&v259[1], &packet[1]);
                    SendHugeChunkPacketAllocated(ZonePlayerList[v256]->connection, v259, packetSize, 0);
                    player->field_60 = -1;
                    player->field_5C = -1;
                }
                else
                {
                    sprintf(a1, "File arrived at server, could not forward: %s", &packet[1]);
                    if ( player->MyArena )
                    {
                        strcpy(&a3[5], a1);
                        a3[0] = 7;
                        a3[1] = 0;
                        a3[2] = 0;
                        *(unsigned short *)&a3[3] = -1;
                        v261 = strlen(a1);
                        if ( GetBillingServerRelOut(player->connection, 0) < 128 )
                            SendPlayerReliablePacket(player, a3, v261 + 6, 1);
                    }
                    player->field_60 = -1;
                    player->field_5C = -1;
                }
            }
        }
        else
        {
            if ( ZonePlayerList[v253] && ZonePlayerList[v253]->IsSysop )
            {
                sprintf(a1, "File arrived, forwarding: %s", &packet[1]);
                if ( ZonePlayerList[v253]->MyArena )
                {
                    strcpy(&a3[5], a1);
                    a3[0] = 7;
                    a3[1] = 0;
                    a3[2] = 0;
                    *(unsigned short *)&a3[3] = -1;
                    v254 = strlen(a1);
                    if ( GetBillingServerRelOut(ZonePlayerList[v253]->connection, 0) < 128 )
                        SendPlayerReliablePacket(ZonePlayerList[v253], a3, v254 + 6, 1);
                }
                v255 = (char *)AllocateMemory(packetSize);
                memcpy(&v255[17], &packet[17], packetSize - 17);
                v255[0] = 0x10;	//0x10 - File Transfer
                strcpy(&v255[1], "pulled.dat");
                //v339 = v255 + 1; //trash code / lost bytes for try/catch
                SendHugeChunkPacketAllocated(ZonePlayerList[v253]->connection, v255, packetSize, 0);
            }
            player->field_58 = -1;
        }
        return;
    case 0x10:					// 0x10 - Attach request
        if ( !player->MyArena || player->Ship == 8 )
            return;
        v274 = *(unsigned short *)&packet[1];
        if ( v274 > 1024 || v274 < -1 )
        {
            if ( !player->IsSuperModerator )
            {
                sprintf(a1, "Packet tampering(%d)", PacketType);
LABEL_606:
                SendBillerWarnings(a1, player);
                if ( player->MyArena )
                {
                    if ( player->MyArena->ServersideArenaSettings.dwordB4 ) {
                        player->DisconnectReason = 0x10;   // 0x10 - Restricted Zone, Compare against local Subspace.exe to determine if an Update is needed.
                        player->AlreadySentReliablePacket = 1;
                        return;
                    }
                }
            }
        }
        else
        {
            player->AttachedToPlayerId = v274;
            if ( v274 >= 0 )
            {
                v275 = ZonePlayerList[v274];
                if ( v275 )
                {
                    if ( v275->Frequency != player->Frequency )
                    {
                        player->AttachedToPlayerId = -1;
                        return;
                    }
                    if ( v275->AttachedToPlayerId >= 0 )
                    {
                        player->AttachedToPlayerId = -1;
                        return;
                    }
                    player->XPixels = v275->XPixels;
                    player->YPixels = v275->YPixels;
                    sub_40D870(player);
                }
            }

            buffer2[0] = 0x0E;                    // 0x0E - Create Turret Link
            *(unsigned short *)&buffer2[1] = player->PlayerId;   // Turreter Requester Player ID
            *(unsigned short *)&buffer2[3] = player->AttachedToPlayerId;// Turreter Destination Player ID

            if ( v274 == player->AttachedToPlayerId )
            {
                if ( player->MyArena )
                    SendEverybodyButYourself(player, buffer2, 5, 1);
            }
            else
            {
                SendArenaPacket(player->MyArena, buffer2, 5, 1);
            }
        }
        return;
    case 0x09:                                     // 0x09 - Password packet
    case 0x23:                                  // 0x23 - Password packet
        player->DemoPlayer = 0;
        if ( !*(unsigned int *)&packet[77] ) // Mem Checksums [0x01BC] or [444]
            player->DemoPlayer = 1;
        //v285 = packet + 2;
        strcpy(player->TypedName, &packet[2]);
        Trim(player->TypedName);
        printf("Connection request from: %s\n", player->TypedName);
        v286 = 0;
        a2 = 0;
        v287 = strrchr(&packet[34], '*');// Does it Contains staff password after PW?
        if ( !v287 )
            goto LABEL_621;
        if ( !stricmp(v287 + 1, SysopPassword) ) {
            WriteSubGameLog("%s> SYSOP LOGGED IN\n", player->TypedName);
            v286 = 1;
            a2 = 1;
            player->IsSysop = 1;
            player->IsModerator = 1;
            player->IsSuperModerator = 1;
        }
        if ( !stricmp(v287 + 1, SuperModeratorPassword) ) {
            WriteSubGameLog("%s>  SUPER MODERATOR LOGGED IN\n", player->TypedName);
            v286 = 1;
            a2 = 1;
            player->IsModerator = 1;
            player->IsSuperModerator = 1;
        }
        if ( !stricmp(v287 + 1, ModeratorPassword) ) {
            WriteSubGameLog("%s>  MODERATOR LOGGED IN\n", player->TypedName);
            v286 = 1;
            a2 = 1;
            player->IsModerator = 1;
        }
        if ( !stricmp(v287 + 1, VIPPassword) ) {
            WriteSubGameLog("%s>  VIP LOGGED IN\n", player->TypedName);
            v286 = 1;
            a2 = 1;
        }
        *v287 = 0;
LABEL_621:
        if ( !player->DemoPlayer && BillingConnectionStructPointer && IsLineExistTextFile(ModeratePointer, player->TypedName) >= 0 )
        {
            v286 = 1;
            a2 = 1;
            player->IsModerator = 1;
        }
        player->PlayerDataBillerPacket.Name[0] = 0;
        strncpy(player->PlayerName, player->TypedName, 0x18);
        player->PlayerName[23] = 0;
        player->MachineId = *(unsigned int *)&packet[85];
        player->TimeZoneBias = *(unsigned short *)&packet[71];
        player->ConnectType = packet[70];
        if ( player->ConnectType == 1 )
            player->SlowModem = 1;
        if ( !PermissionAllowLowBandwidth && !v286 )
        {
            v344[0] = 0x0A;                         // 0x0A - Password response
            v344[1] = 8;                            // Byte [1] - 8 - Connection too slow.
            *(unsigned int *)&v344[2] = 134;              // Byte [2] - Server version 134 - SubSpace 1.34
            SendPlayerReliablePacket(player, v344, 0x24, 1);
            WriteSubGameLog("Played kicked off for having slow modem: %s\n", player->PlayerName);
            player->AlreadySentReliablePacket = 1;
            return;
        }
        *(unsigned int *)&player->SubspaceVersion = *(unsigned short *)&packet[75];
        player->SubspaceEXEChecksumIndex = 0;
        v289 = packet[0];
        if ( v289 >= 35 && v289 <= 44 )
            player->SubspaceEXEChecksumIndex = v289 - 35;
        if ( !Security[player->SubspaceEXEChecksumIndex].SubspaceEXEChecksum )
        {
            v344[0] = 0x0A;                         // 0x0A - Password Packet Response
            v344[1] = 5;                            // 0x05 - Permission Only Arena
            *(unsigned int *)&v344[2] = 134;              // Server Version 134 = SubSpace 1.34
            v344[19] = 0;                           // Registration Form Request (Boolean)
            SendPlayerReliablePacket(player, v344, 0x24, 1);
            player->KickOffDelayTimer = GetTickCount() / 0xA;
            return;
        }
        if ( IsOffensiveName(player->TypedName) && !player->IsModerator )
        {
            v344[0] = 0x0A;                         // 0x0A - Password Packet Response
            v344[1] = 0x0C;                         // 0x0C - Offensive Name
            *(unsigned int *)&v344[2] = 134;              // Server Version 134 = SubSpace 1.34
            v344[19] = 0;                           // Registration Form Request (Boolean)
            SendPlayerReliablePacket(player, v344, 0x24, 1);
            WriteSubGameLog("Played kicked off, obscene name: %s\n", player->TypedName);
            player->AlreadySentReliablePacket = 1;
            return;
        }
        if ( PermissionMode == 1 && !player->IsModerator && (player->DemoPlayer || IsLineExistTextFile(PermitPointer, player->TypedName) < 0) )
        {
            v344[0] = 0x0A;                         // 0x0A - Password Packet Response
            v344[1] = 5;                            // 0x05 - Permission Only Arena
            *(unsigned int *)&v344[2] = 134;              // Server Version 134 = SubSpace 1.34
            v344[19] = 0;                           // Registration Form Request (Boolean)
            SendPlayerReliablePacket(player, v344, 0x24, 1);
            player->KickOffDelayTimer = GetTickCount() / 0xA;
            return;
        }
        v290 = GetIPAddressString(player->IPAddressDWORD);
        if ( IsBannedIPAddress(player->SubspaceEXEChecksumIndex, v290) )
        {
            v344[0] = 0x0A;                         // 0x0A - Password Packet Response
            v344[1] = 4;                            // 0x04 - Locked Out of Zone
            *(unsigned int *)&v344[2] = 134;              // Server Version 134 = SubSpace 1.34
            v344[19] = 0;                           // Registration Form Request (Boolean)
            SendPlayerReliablePacket(player, v344, 0x24, 1);
            WriteSubGameLog("Played kicked off, IP block: %s\n", player->PlayerName);
            player->AlreadySentReliablePacket = 1;
            return;
        }
        sprintf(buffer, "%d", player->MachineId);
        if ( IsLineExistTextFile(IDBlockPointer, buffer) >= 0 )
        {
            v344[0] = 0x0A;                         // 0x0A - Password Packet Response
            v344[1] = 4;                            // 0x04 - Locked Out of Zone
            *(unsigned int *)&v344[2] = 134;              // Server Version 134 = SubSpace 1.34
            v344[19] = 0;                           // Registration Form Request (Boolean)
            SendPlayerReliablePacket(player, v344, 0x24, 1);
            WriteSubGameLog("Played kicked off, ID block: %s\n", player->PlayerName);
            player->AlreadySentReliablePacket = 1;
            return;
        }

        if ( MachineIdArrayCount > 0 ) {
            v291 = 0;
            while ( KickedUsers[v291].MachineId != player->MachineId || player->IsSysop )
            {
                ++v291;
                if ( v291 >= MachineIdArrayCount )
                    goto NO_BANNED_MACHINE_ID_FOUND;
            }
            v344[0] = 0x0A;                           // 0x0A - Password Packet Response
            v344[1] = 5;                              // 0x05 - Permission Only Arena
            *(unsigned int *)&v344[2] = 134;                // Server Version 134 = SubSpace 1.34
            v344[19] = 0;                             // Registration Form Request (Boolean)
            SendPlayerReliablePacket(player, v344, 0x24, 1);
            player->KickOffDelayTimer = GetTickCount() / 0xA;
        }
NO_BANNED_MACHINE_ID_FOUND:
        if ( !player->DemoPlayer )
            goto LABEL_668;
        TotalDemoPlayersCount = 0;
        if ( ZonePlayerCount > 0 )
        {
            v296 = 0;
            do
            {
                if ( ZonePlayers[v296]->DemoPlayer )
                    ++TotalDemoPlayersCount;
                ++v296;
            }
            while ( v296 < ZonePlayerCount );
        }
        if ( MiscMaxSharewarePlayer >= 0 && TotalDemoPlayersCount > MiscMaxSharewarePlayer )
        {
            v344[0] = 0x0A;					//0x0A - Password Packet Response
            v344[1] = (MiscMaxSharewarePlayer == 0) + 17;
            *(unsigned int *)&v344[2] = 134;              // Server Version 134 = SubSpace 1.34
            v344[19] = 0;
            SendPlayerReliablePacket(player, v344, 0x24, 1);
            WriteSubGameLog("Played kicked off, arena full to demo users: %s\n", player->PlayerName);
            player->AlreadySentReliablePacket = 1;
            return;
        }
        if ( player->DemoPlayer )
        {
            memset(&player->PlayerDataBillerPacket, 0, sizeof(struct PLAYER_DATA_BILLER_PACKET_STRUCT));         // TODO: Erases way past the Name LOL
            sprintf(player->PlayerDataBillerPacket.Name, "~Demo%d", player->PlayerId);
            strcpy(player->PlayerName, player->PlayerDataBillerPacket.Name);
            player->PlayerDataBillerPacket.UserId = -1;
            player->CurrentWins = 0;
            player->CurrentGoals = 0;
            player->KillPoints = 0;
            player->FlagPoints = 0;
        }
LABEL_668:
        if ( ZonePlayerCount > MiscMaxPlayers && !a2 )
        {
            v339 = 0;
            if ( MiscRegisterKickShareware )
            {
                if ( !player->DemoPlayer )
                {
                    v302 = 0;
                    if ( ZonePlayerCount > 0 )
                    {
                        while ( !ZonePlayers[v302]->DemoPlayer )
                        {
                            ++v302;
                            if ( v302 >= ZonePlayerCount )
                                goto LABEL_685;
                        }
                        v339 = 1;
                        if ( ZonePlayers[v302]->MyArena )
                        {
                            strcpy(&a3[5], "You have been kicked off to make space for a registered user.");
                            a3[0] = 7;			// 0x07 - Chat
                            a3[1] = 0;
                            a3[2] = 0;
                            *(unsigned short *)&a3[3] = -1;
                            v310 = strlen("You have been kicked off to make space for a registered user.");
                            if ( GetBillingServerRelOut(ZonePlayers[v302]->connection, 0) < 128 )
                                SendPlayerReliablePacket(ZonePlayers[v302], a3, v310 + 6, 1);
                        }
                        ZonePlayers[v302]->KickOffDelayTimer = GetTickCount() / 0xA;
                    }
                }
            }
LABEL_685:
            if ( !v339 )
            {
                v344[0] = 0x0A;
                v344[1] = 3;
                *(unsigned int *)&v344[2] = 134;
                v344[19] = 0;
                SendPlayerReliablePacket(player, v344, 0x24, 1);
                WriteSubGameLog("Played kicked off, arena full: %s\n", player->PlayerName);
                player->AlreadySentReliablePacket = 1;
                return;
            }
        }
        if ( BillingConnectionStructPointer )
        {
            if ( !a2 )
            {
                if ( GetBillingServerRelOut(EncryptionStruct, 0) > CommsMaxQueueToLogin )
                {
                    v344[0] = 0x0A;                     // 0x0A - Password Packet Response
                    v344[1] = 0x0E;                     // 0x0E - Server Busy, try Later
                    *(unsigned int *)&v344[2] = 134;          // Server Version 134 = SubSpace 1.34
                    v344[19] = 0;                       // Registration Form Request (Boolean)
                    SendPlayerReliablePacket(player, v344, 0x24, 1);
                    player->AlreadySentReliablePacket = 1;
                    return;
                }
            }
            if ( player->DemoPlayer && MiscDisableShareware )
                SendBillerUserLoginPacket(
                    BillingConnectionStructPointer,
                    "",
                    "",
                    player->IPAddressDWORD,
                    player->MachineId,
                    player->TimeZoneBias,
                    packet[1],
                    player->BillerPlayerId,
                    0,
                    player->IsSysop);
            else
                SendBillerUserLoginPacket(
                    BillingConnectionStructPointer,
                    &packet[2], /* Username */
                    &packet[34], /* Password */
                    player->IPAddressDWORD,
                    player->MachineId,
                    player->TimeZoneBias,
                    packet[1],
                    player->BillerPlayerId,
                    0,
                    player->IsSysop);
        }
        else
        {
            if ( IsLineExistTextFile(ReservedPointer, nameReturn) < 0 || a2 )
            {
                memset(&player->PlayerDataBillerPacket, 0, sizeof(struct PLAYER_DATA_BILLER_PACKET_STRUCT));       // TODO: Clears past the Name limit of 32 bytes.
                strcat(player->PlayerDataBillerPacket.Name, nameReturn);
                v344[0] = 0x0A;			// 0x0A - Password Packet Response
                v344[1] = 0x0D;			// 0x0D - No Active Biller
                *(unsigned int *)&v344[2] = 134;            // Server Version 134 = SubSpace 1.34
                player->CurrentWins = 0;
                player->CurrentGoals = 0;
                player->KillPoints = 0;
                player->FlagPoints = 0;
                *(unsigned int *)&v344[6] = 0;              // ? Unknown
                *(unsigned int *)&v344[14] = 0;             // ? Unknown
                v319 = 4 * (player->SubspaceEXEChecksumIndex + 16 * (63 * player->SubspaceEXEChecksumIndex));
                v344[18] = 0;                         // ? Unknown
                v344[19] = 0;                         // Registration Form Request (Boolean)
                v320 = *(int *)((char *)&Security[0].SubspaceEXEChecksum + v319);
                *(unsigned int *)&v344[20] = *(unsigned int *)&Security[0].ScrtyData[v319 + 4];
                *(unsigned int *)&v344[10] = v320;
                *(unsigned int *)&v344[24] = NewsTxtFileChecksum;
                if ( player->IsModerator )
                {
                    *(unsigned int *)&v344[10] = -1;          // Subspace.exe Checksum
                    *(unsigned int *)&v344[20] = -1;          // ? Unknown
                }
                SendPlayerReliablePacket(player, v344, 0x24, 1);
            }
            else
            {
                v344[0] = 0x0A;                       // 0x0A - Password Packet Response
                v344[1] = 12;                         // 12 - Offensive name.
                *(unsigned int *)&v344[2] = 134;            // Server Version 134 = SubSpace 1.34
                v344[19] = 0;
                SendPlayerReliablePacket(player, v344, 0x24, 1);
                player->KickOffDelayTimer = GetTickCount() / 0xA;
            }
        }
        return;
    default:
        if ( !player->IsSuperModerator )
        {
            sprintf(a1, "Packet tampering(%d)", PacketType);
            SendBillerWarnings(a1, player);
            if ( player->MyArena )
            {
                if ( player->MyArena->ServersideArenaSettings.dwordB4 )
                {
                    player->DisconnectReason = 0x10;   // 0x10 - Restricted Zone, Compare against local Subspace.exe to determine if an Update is needed.
                    player->AlreadySentReliablePacket = 1;
                }
            }
        }
        return;
    }
}
// 407730: using guessed type unsigned int __cdecl Trim(unsigned int);
// 41B960: using guessed type int __cdecl GetProtocolVersion(unsigned int);
// 41CA10: using guessed type int __cdecl sub_41CA10(unsigned int);
// 4314B0: using guessed type int AdvertiseSendMode;
// 432004: using guessed type int RecycleServer;
// 437CA0: using guessed type int CommsMaxQueueToLogin;
// 438138: using guessed type int MiscMaxSharewarePlayer;
// 4386D4: using guessed type int MachineIdArrayCount;
// 438B1C: using guessed type int PermissionMode;
// 438B74: using guessed type int MiscMaxPlayers;
// 4AC448: using guessed type struct KICK KickedUsers[1000];
// 4AF32C: using guessed type int AutoPermissionPoints;
// 4D5900: using guessed type int PermissionAllowLowBandwidth;
// 4D590C: using guessed type int MiscJackpotBroadcastPoints;
// 4D5910: using guessed type int MiscRegisterKickShareware;
// 4D5914: using guessed type int NewsTxtFileChecksum;
// 4D5918: using guessed type int MiscDisableShareware;
// 4D89C8: using guessed type int Wave;
// 4D8B14: using guessed type int dword_4D8B14;
// 408E80: using guessed type char var_65F[507];

//----- (0040CB80) --------------------------------------------------------
void __cdecl SecurityViolation(struct PLAYER *player, int a2)
{
    signed int v3; // edx@2
    char *securityResult; // eax@2
    struct ARENA *v5; // ecx@31
    int v6; // eax@31
    struct ARENA *v7; // eax@35
    char a1[256]; // [sp+8h] [bp-100h]@35

    if ( !player->IsSuperModerator )
    {
        v3 = 1;
        securityResult = "Unknown integrity violation";
        switch ( a2 )
        {
        case 28:
            securityResult = "Parameter mismatch detected";
            break;
        case 27:
            securityResult = "Data checksum mismatch detected";
            break;
        case 0:
            securityResult = "Normal integrity";
            break;
        case 1:
            securityResult = "Slow frame detected";
            break;
        case 2:
            securityResult = "Current energy higher than top energy";
            break;
        case 3:
            securityResult = "Top energy higher than max energy";
            break;
        case 4:
            securityResult = "Max energy without getting prizes";
            break;
        case 5:
            securityResult = "Recharge rate higher than max recharge rate";
            break;
        case 6:
            securityResult = "Max recharge rate without getting prizes";
            break;
        case 7:
            securityResult = "Too many burst used";
            break;
        case 8:
            securityResult = "Too many repel used";
            break;
        case 9:
            securityResult = "Too many decoy used";
            break;
        case 10:
            securityResult = "Too many thor used";
            break;
        case 11:
            securityResult = "Too many wall blocks used";
            break;
        case 12:
            securityResult = "Stealth on but never collected";
            break;
        case 13:
            securityResult = "Cloak on but never collected";
            break;
        case 14:
            securityResult = "XRadar on but never collected";
            break;
        case 15:
            securityResult = "AntiWarp on but never collected";
            break;
        case 16:
            securityResult = "Proximity bombs but never collected";
            break;
        case 17:
            securityResult = "Bouncing bullets but never collected";
            break;
        case 18:
            securityResult = "Max guns without getting prizes";
            break;
        case 19:
            securityResult = "Max bombs without getting prizes";
            break;
        case 20:
            securityResult = "Shields or Super on longer than possible";
            break;
        case 21:
            v3 = 0;
            securityResult = "Saved ship weapon limits too high (burst/repel/etc)";
            break;
        case 25:
            v3 = 0;
            securityResult = "Saved ship checksum mismatch";
            break;
        case 22:
            v3 = 0;
            securityResult = "Saved ship weapon level too high (guns/bombs)";
            break;
        case 23:
            v3 = 0;
            securityResult = "Login checksum mismatch (program exited)";
            break;
        case 26:
            securityResult = "Softice Debugger Running";
            break;
        case 24:
            player->CurrentSecurityPacketModifcationCount++;
            if ( player->CurrentSecurityPacketModifcationCount < player->MyArena->ServersideArenaSettings.SecurityPacketModificationMax )
                return;
            securityResult = "S2C position packet modified";
            break;
        default:
            break;
        }
        if ( !player->field_309 || !v3 )
        {
            sprintf(a1, "WARNING: %s", securityResult);
            SendBillerWarnings(a1, player);
            if ( player->MyArena )
            {
                if ( player->MyArena->ServersideArenaSettings.dwordB4 )
                {
                    player->DisconnectReason = 3;
                    player->AlreadySentReliablePacket = 1;
                }
            }
        }
    }
}

//----- (0040CDB0) --------------------------------------------------------
void __cdecl UpdatePowerBallPositions(struct PLAYER *player)
{
    //struct PLAYER *player; // esi@1
    struct ARENA *arena; // ecx@1
    int XPixels; // eax@2
    int powerBallId; // ebx@2
    int v5; // edi@3
    struct ARENA *v6; // ecx@9
    int v7; // [sp+8h] [bp-18h]@2
    int YPixels; // [sp+Ch] [bp-14h]@2
    char buf[16]; // [sp+10h] [bp-10h]@9

    if ( player->MyArena )
    {
        if ( player->MyArena->TotalSoccerBalls > 0 )
        {
            v5 = 0;
            while ( 1 )
            {
                if ( !player->MyArena->SoccerBalls[v5].StartTimeDelay && player->MyArena->SoccerBalls[v5].PlayerId == player->PlayerId )
                {
                    if ( player->XPixels <= 0 || player->YPixels <= 0 ) {
                        CreateSoccerBall(player->MyArena, powerBallId);
                    } else {
                        player->MyArena->SoccerBalls[v5].PowerBallId = powerBallId;
                        player->MyArena->SoccerBalls[v5].XPixels = player->XPixels;
                        player->MyArena->SoccerBalls[v5].YPixels = player->YPixels;
                        player->MyArena->SoccerBalls[v5].XVelocity = 0;
                        player->MyArena->SoccerBalls[v5].YVelocity = 0;
                        player->MyArena->SoccerBalls[v5].PlayerId = player->PlayerId;
                        player->MyArena->SoccerBalls[v5].StartTimeDelay = GetTickCount() / 0xA;
                        player->MyArena->SoccerBallTimers[powerBallId] = GetTickCount() / 0xA;

                        buf[0] = 0x2E; 	//0x2E - Power-Ball Position Update
                        buf[1] = *(unsigned char *)&v6->SoccerBalls[v5].PowerBallId;
                        *(unsigned short *)&buf[2] = *(unsigned short *)&player->MyArena->SoccerBalls[v5].XPixels;
                        *(unsigned short *)&buf[4] = *(unsigned short *)&player->MyArena->SoccerBalls[v5].YPixels;
                        *(unsigned short *)&buf[6] = *(unsigned short *)&player->MyArena->SoccerBalls[v5].XVelocity;
                        *(unsigned short *)&buf[8] = *(unsigned short *)&player->MyArena->SoccerBalls[v5].YVelocity;
                        *(unsigned short *)&buf[10] = *(unsigned short *)&player->MyArena->SoccerBalls[v5].PlayerId;
                        *(unsigned int *)&buf[12] = *(unsigned int *)&player->MyArena->SoccerBalls[v5].StartTimeDelay;
                        SendArenaPacket(v6, buf, 16, 0);
                    }
                }
                ++v5;
                if ( v5 >= player->MyArena->TotalSoccerBalls )
                    break;
            }
        }
    }
}

//----- (0040CF10) --------------------------------------------------------
bool __cdecl sub_40CF10(struct PLAYER *player)
{
    __int64 v4; // qax@6
    __int64 v5; // qax@9
    DWORD v6; // eax@15
    unsigned int v7; // kr08_4@16
    FILE *v8; // ebx@18
    unsigned int v9; // kr10_4@21
    bool v10; // sf@24
    unsigned char v11; // of@24
    int v12; // esi@27
    int v13; // edi@32
    signed int v14; // ecx@32
    bool v15; // zf@34
    unsigned int v16; // ecx@35
    char v17; // al@35
    const void *v18; // esi@35
    const void *v19; // ecx@35
    __int64 v20; // qax@37
    int v21; // edi@38
    signed int v22; // ecx@38
    unsigned int v23; // ecx@41
    char v24; // al@41
    const void *v25; // esi@41
    struct ARENA *v26; // esi@46
    unsigned int v27; // kr28_4@49
    char *v28; // ebx@52
    char *v29; // esi@52
    int v30; // edi@52
    struct ARENA *v31; // eax@54
    unsigned int v32; // kr30_4@60
    signed int v33; // eax@63
    int v34; // esi@65
    int v35; // eax@65
    int v36; // ecx@70
    int v37; // edi@72
    signed int v38; // edx@82
    int v39; // ST0C_4@82
    signed int v40; // edx@82
    struct ARENA *v41; // eax@82
    int v42; // esi@82
    signed int v43; // edx@87
    char *v44; // edi@87
    signed int v45; // ecx@87
    unsigned int v46; // ecx@90
    char v47; // al@90
    const void *v48; // esi@90
    unsigned int v49; // [sp-8h] [bp-524h]@35
    const char *v50; // [sp-8h] [bp-524h]@77
    int v51; // [sp-4h] [bp-520h]@35
    char *v52; // [sp-4h] [bp-520h]@77
    char v53; // [sp+13h] [bp-509h]@43
    int v54; // [sp+14h] [bp-508h]@19
    DWORD ExitCode; // [sp+18h] [bp-504h]@13
    char buf[512]; // [sp+1Ch] [bp-500h]@21
    char Dest[6]; // [sp+21Ch] [bp-300h]@15
    char Buf[512]; // [sp+31Ch] [bp-200h]@16

    if ( player->field_287 > 0 )
        HighestPlayerCountMaybeSomething = 1;
    if ( player->AlreadySentReliablePacket )
        return 1;
    if ( player->KickOffDelayTimer )
    {
        if ( (GetTickCount() / 0xA - player->KickOffDelayTimer) > 1000 )
        {
            printf("KickOffTime expired: %s\n", player->PlayerName);
            return 1;
        }
    }
    if ( !player->PlayerName[0] )
    {
        if ( (GetTickCount() / 0xA - player->NoPasswordPacketDelayTimer) > 300 )
        {
            printf("No password packet delay exceeded\n");
            player->DisconnectReason = 17;
            return 1;
        }
    }
    if ( !player->MyArena )
    {
        if ( abs(GetTickCount() / 0xA - player->connection->MenuKickOutDelayTimer) > MiscMenuKickOutDelay )
        {
            printf("Menu kickout delay exceeded: %s\n", player->PlayerName);
            player->DisconnectReason = 1;
            return 1;
        }
LABEL_78:
        if ( CheckState(player->connection) != 4 ) //4 = Disconnected
            return 0;
        printf("Connection status read as terminated: %s\n", player->PlayerName);
        player->DisconnectReason = 1;
        return 1;
    }
    if ( player->ProcessInformation
            && GetExitCodeProcess(player->ProcessInformation->hProcess, &ExitCode)
            && ExitCode != 259 )
    {
        TerminateProcess(player->ProcessInformation->hProcess, 0);
        CloseHandle(player->ProcessInformation->hProcess);
        v6 = ExitCode;
        player->ProcessInformation = 0;
        player->dword4 = 0;
        player->dword8 = 0;
        player->dwordC = 0;
        sprintf(Dest, "SPAWN TERMINATED: %d", v6);
        if ( player->MyArena )
        {
            strcpy(&Buf[5], Dest);
            Buf[0] = 7;                           // 0x07 - Chat
            Buf[1] = 0;
            Buf[2] = 0;
            *(unsigned short *)&Buf[3] = -1;
            v7 = strlen(Dest);
            if ( GetBillingServerRelOut(player->connection, 0) < 128 )
                SendPlayerReliablePacket(player, Buf, v7 + 6, 1);
        }
        v8 = fopen("spawn.log", "rt");
        if ( v8 )
        {
            v54 = 0;
            do
            {
                Buf[0] = 0;
                fgets(Buf, 256, v8);
                if ( player->MyArena )
                {
                    strcpy(&buf[5], Buf);
                    buf[0] = 7;                           // 0x07 - Chat
                    buf[1] = 0;
                    buf[2] = 0;
                    *(unsigned short *)&buf[3] = -1;
                    v9 = strlen(Buf);
                    if ( GetBillingServerRelOut(player->connection, 0) < 128 )
                        SendPlayerReliablePacket(player, buf, v9 + 6, 1);
                }
                if ( feof(v8) )
                    break;

                v54++;
            }
            while ( v54 < 40 );
            fclose(v8);
        }
    }
    v12 = abs(GetTickCount() / 0xA - player->connection->MenuKickOutDelayTimer);
    if ( v12 > player->MyArena->ServersideArenaSettings.LatencyNoFlagDelay )
        player->field_15B = GetTickCount() / 0xA;
    if ( v12 <= player->MyArena->ServersideArenaSettings.LatencyKickOutDelay
            || player->IsSysop && abs(GetTickCount() / 0xA - player->connection->MenuKickOutDelayTimer) <= 6000 )
    {
        if ( player->DemoPlayer )
        {
            if ((GetTickCount() / 0xA - player->NoPasswordPacketDelayTimer) > MiscMaxSharkwareTime )
            {
                WriteSubGameLog("Shareware Timer Expired: %s\n", player->PlayerName);

                strcpy(&buf[5], "DISCONNECTED: Your time for this session has expired. There is no time limit when you play the full version.");
                *(unsigned short *)&buf[3] = player->PlayerId;
                player->DisconnectReason = 22;
                buf[0] = 7;
                buf[1] = 0;
                buf[2] = 0;
                v51 = 0;
                v49 = strlen("DISCONNECTED: Your time for this session has expired. There is no time limit when you play the full version.")
                      + 6;
                v19 = buf;
                goto LABEL_91;
            }
        }
        if ( abs(GetTickCount() / 0xA - player->connection->KeepAliveDelayTimer) > MiscKeepAliveDelay )
        {
            v53 = 0x27;                              // 0x27 - Keep-Alive, Single byte packet
            SendPlayerReliablePacket(player, &v53, 1, 0);
        }
        if ( player->Ship != 8 )
        {
            if ( player->LatencyKickOutDelayTimer )
            {
                v26 = player->MyArena;
                if ( (GetTickCount() / 0xA - player->LatencyKickOutDelayTimer) > v26->ServersideArenaSettings.LatencyKickOutTime )
                {
                    if ( !player->IsSysop )
                    {
                        if ( v26 )
                        {
                            strcpy(&buf[5], "You have been put in spectator mode due to high latency (spike)");
                            buf[0] = 7;                       // 0x07 - Chat
                            buf[1] = 0;
                            buf[2] = 0;
                            *(unsigned short *)&buf[3] = -1;
                            v27 = strlen("You have been put in spectator mode due to high latency (spike)");
                            if ( GetBillingServerRelOut(player->connection, 0) < 128 )
                                SendPlayerReliablePacket(player, buf, v27 + 6, 1);
                        }
                        SetPlayerShip(player, 8);
                    }
                }
            }
        }
        v28 = (char *)&player->C2SPacketLossPercentage;
        v29 = (char *)&player->S2CPacketLossPercentage;
        GetPingLOSSSomething(
            player->connection,
            &player->S2CPacketLossPercentage,
            &player->C2SPacketLossPercentage);
        v30 = 0;
        if ( player->Ship == 8 )
            v30 = player->MyArena->ServersideArenaSettings.PacketLossSpectatorPercentAdjust;
        v31 = player->MyArena;
        if ( (*(unsigned int *)v29 < v31->ServersideArenaSettings.PacketLossS2CKickOutPercent - v30
                || *(unsigned int *)v28 < v31->ServersideArenaSettings.PacketLossC2SKickOutPercent - v30
                || *(unsigned int *)v28 > v31->ServersideArenaSettings.PacketLossC2SNegativeKickOutPercent + v30 + 1000)
                && !player->IsSysop )
        {
            if ( player->Ship == 8 )
            {
                WriteSubGameLog(
                    "Packet loss too high S2C:%d%%, C2S:%d%%, kicking out player: %s\n",
                    (1000 - *(unsigned int *)v29) / 10,
                    (1000 - *(unsigned int *)v28) / 10,
                    player->PlayerName);
                v42 = *(unsigned int *)v29;
                if ( v42 >= player->MyArena->ServersideArenaSettings.PacketLossS2CKickOutPercent - v30 )
                {
                    if ( *(unsigned int *)v28 <= player->MyArena->ServersideArenaSettings.PacketLossC2SNegativeKickOutPercent + v30 + 1000 )
                        player->DisconnectReason = 7;
                    else
                        player->DisconnectReason = 23;
                }
                else
                {
                    player->DisconnectReason = 6;
                }
                sprintf(
                    Dest,
                    "WARNING: Disconnected because of high packet loss (ServerToYou:%d%%, YouToServer:%d%%)",
                    (1000 - *(unsigned int *)v42) / 10,
                    (1000 - *(unsigned int *)v28) / 10);
                buf[0] = 7;                             // 0x07 - Chat
                buf[1] = 0;
                buf[2] = 0;
                *(unsigned short *)&buf[3] = player->PlayerId;
                strcpy(&buf[5], Dest);

                v51 = 0;
                v49 = strlen(Dest) + 6;
                v19 = buf;
                goto LABEL_91;
            }
            if ( v31 )
            {
                strcpy(&buf[5], "You have been put in spectator mode due to high packet loss");
                buf[0] = 7;                             // 0x07 - Chat
                buf[1] = 0;
                buf[2] = 0;
                *(unsigned short *)&buf[3] = -1;
                v32 = strlen("You have been put in spectator mode due to high packet loss");
                if ( GetBillingServerRelOut(player->connection, 0) < 128 )
                    SendPlayerReliablePacket(player, buf, v32 + 6, 1);
            }
            SetPlayerShip(player, 8);
        }
        v33 = *(unsigned int *)v28;
        if ( *(unsigned int *)v28 >= 1000 )
            v33 = 1000;
        v34 = player->S2CPacketLossPercentage;
        v35 = v33 - v34;
        player->field_153 = v35;
        if ( v34 > 900 || player->IsSysop || v35 < 0 )
            player->field_153 = 0;
        if ( v34 < 1000 )
        {
            v36 = player->SecurityWeaponCountTotal;
            if ( v36 > 400 )
            {
                if ( player->Ship != 8 )
                {
                    v37 = 1000 * player->SecurityWeaponCount / v36;
                    if ( v34 - v37 > 100 )
                    {
                        if ( v37 < player->MyArena->ServersideArenaSettings.SecurityS2CKickOutPercentWeapons && !player->IsSysop )
                        {
                            sprintf(
                                Dest,
                                "S2C weapon packet loss too high(S2CW=%d%%)(S2C=%d%%)",
                                (1000 - v37) / 10,
                                (1000 - v34) / 10,
                                player);
                            SendBillerWarnings(Dest, player);
                            player->DisconnectReason = 3;
                            return 1;
                        }
                    }
                }
            }
        }
        goto LABEL_78;
    }
    WriteSubGameLog("Kickout delay exceeded: %s\n", player->PlayerName);

    strcat(&buf[5], "WARNING: You have been disconnected because server has not been receiving data from you.");
    player->DisconnectReason = 9;
    *(unsigned short *)&buf[3] = player->PlayerId;
    buf[0] = 7;                                   // 0x07 - Chat
    buf[1] = 0;
    buf[2] = 0;
    v51 = 0;
    v49 = strlen("WARNING: You have been disconnected because server has not been receiving data from you.") + 6;
    v19 = buf;
LABEL_91:
    SendPlayerReliablePacket(player, v19, v49, v51);
    sub_41CB20(player->connection);
    return 1;
}
// 41B950: using guessed type int __cdecl CheckState(unsigned int);
// 4AF328: using guessed type int MiscKeepAliveDelay;
// 4D55D4: using guessed type int MiscMaxSharkwareTime;
// 4D55D8: using guessed type int MiscMenuKickOutDelay;
// 4D8AF8: using guessed type int HighestPlayerCountMaybeSomething;
// 40CF10: using guessed type char var_4FB[507];

//----- (0040D870) --------------------------------------------------------
void __cdecl sub_40D870(struct PLAYER *player)
{
    int v10; // edi@10
    int v11; // ebx@10

    player->LooksLikeX1BigOfSomething = player->XPixels - player->MyArena->CalculatedMapZoomFactor;
    if ( player->XPixels - player->MyArena->CalculatedMapZoomFactor < 0 )
        player->LooksLikeX1BigOfSomething = 0;
    if ( player->LooksLikeX1BigOfSomething > 2 * (8192 - player->MyArena->CalculatedMapZoomFactor) )
        player->LooksLikeX1BigOfSomething = 2 * (8192 - player->MyArena->CalculatedMapZoomFactor);

    player->LooksLikeYBigOfSomething = player->YPixels - player->MyArena->CalculatedMapZoomFactor;
    if ( player->YPixels - player->MyArena->CalculatedMapZoomFactor < 0 )
        player->LooksLikeYBigOfSomething = 0;
    if ( player->LooksLikeYBigOfSomething > 2 * (8192 - player->MyArena->CalculatedMapZoomFactor) )
        player->LooksLikeYBigOfSomething = 2 * (8192 - player->MyArena->CalculatedMapZoomFactor);

    player->LooksLikeXSmallOfSomething = player->LooksLikeX1BigOfSomething + 2 * player->MyArena->CalculatedMapZoomFactor;
    player->LooksLikeYSmallOfSomething = player->LooksLikeYBigOfSomething + 2 * player->MyArena->CalculatedMapZoomFactor;

    if ( player->MyArena )
    {
        v10 = (player->LooksLikeX1BigOfSomething + player->LooksLikeXSmallOfSomething) / 4096;
        v11 = (player->LooksLikeYSmallOfSomething + player->LooksLikeYBigOfSomething) / 4096;
        if ( v10 != player->field_50 || v11 != player->field_54 )
        {
            sub_404980(player->MyArena, player, player->field_50, player->field_54);
            player->field_50 = v10;
            player->field_54 = v11;
            AddPlayerToArenaSomething(player->MyArena, player, v10, v11);
        }
    }
}

//----- (0040D980) --------------------------------------------------------
void __cdecl PlayerChangeFrequency(struct PLAYER *player, signed int NewFrequency)
{
    struct ARENA *arena; // esi@1
    int v5; // ebx@2
    struct PLAYER **v6; // ecx@5
    int v7; // edx@5
    int v8; // eax@6
    int v9; // ecx@9
    signed int v10; // eax@9
    unsigned int v11; // kr04_4@14
    int v12; // ecx@17
    int v13; // edx@17
    struct PLAYER **v14; // eax@18
    int v15; // ecx@23
    __int16 v16; // ax@27
    struct ARENA *v17; // ecx@30
    __int16 v18; // dx@31
    char buf[6]; // [sp+10h] [bp-20Ch]@27
    char v20[3]; // [sp+18h] [bp-204h]@31
    char buffer[256]; // [sp+1Ch] [bp-200h]@4

    if ( NewFrequency >= player->MyArena->ArenaSettings.MaxFrequency )
        return;

    if ( player->MyArena->ServersideArenaSettings.TeamForceEvenTeams > 0 && !player->IsSuperModerator )
    {
        memset(buffer, 0, sizeof(buffer));
        if ( player->MyArena->ArenaPlayerCount > 0 )
        {
            v6 = (struct PLAYER **)player->MyArena->ArenaPlayers;
            v7 = player->MyArena->ArenaPlayerCount;
            do
            {
                v8 = (*v6)->Frequency;
                if ( v8 < 64 )
                    ++*(unsigned int *)&buffer[4 * v8];
                ++v6;
                --v7;
            }
            while ( v7 );
        }
        v9 = player->Frequency;
        v10 = player->MyArena->ServersideArenaSettings.TeamDesiredTeams;
        if ( v9 < v10
                && NewFrequency < v10
                && v10 < 64
                && *(unsigned int *)&buffer[4 * v9] + player->MyArena->ServersideArenaSettings.TeamForceEvenTeams - 1 <= *(unsigned int *)&buffer[4 * NewFrequency] )
        {
            if ( player->MyArena )
            {
                strcpy(&buffer[5], "Changing frequencies would make the teams too uneven.");
                buffer[0] = 7;                          // 0x07 - Chat
                buffer[1] = 0;
                buffer[2] = 0;
                *(unsigned short *)&buffer[3] = -1;
                v11 = strlen("Changing frequencies would make the teams too uneven.");
                if ( GetBillingServerRelOut(player->connection, 0) < 128 )
                    SendPlayerReliablePacket(player, buffer, v11 + 6, 1);
            }
            return;
        }
    }
    player->DebtKills = player->MyArena->ServersideArenaSettings.KillDebtKills;
    v12 = player->MyArena->ArenaPlayerCount;
    v13 = 0;
    if ( v12 > 0 )
    {
        v14 = (struct PLAYER **)player->MyArena->ArenaPlayers;
        do
        {
            if ( (*v14)->Frequency == NewFrequency )
                ++v13;
            ++v14;
            --v12;
        }
        while ( v12 );
    }
    v15 = player->MyArena->ArenaSettings.MaxPerTeam;
    if ( player->MyArena->ArenaSettings.MaxPerPrivateTeam > 0 )
        v15 = player->MyArena->ArenaSettings.MaxPerPrivateTeam;
    if ( v13 < v15 || player->IsSysop != 0 )
    {
        v16 = player->PlayerId;
        player->Frequency = NewFrequency;
        buf[0] = 0x0D;                              // 0x0D - Player Changed Frequency
        *(unsigned short *)&buf[1] = v16;                    // Player ID
        *(unsigned short *)&buf[3] = NewFrequency;         // Frequency
        buf[5] = -1;                                // Ship
        if ( player->MyArena->ServersideArenaSettings.MiscFrequencyShipTypes != 0 && player->Ship != 8 )
        {
            player->Ship = abs(NewFrequency) & 7;
            buf[5] = LOBYTE(player->Ship);          // Ship
        }
        SendArenaPacket(player->MyArena, buf, 6, 1);
        CarryFlagsSomething(player->MyArena, player->PlayerId, 0);
        UpdatePowerBallPositions(player);
        if ( player->MyArena->ServersideArenaSettings.MiscResetScoreOnFrequencyChange != 0 )
        {
            player->CurrentDeaths = 0;
            player->CurrentWins = 0;
            player->KillPoints = 0;
            player->FlagPoints = 0;
            player->CurrentGoals = 0;
            player->ScoreReset = 1;
            v20[0] = 0x1A;                           // 0x1A - Reset Score(s)
            *(unsigned short *)&v20[1] = player->PlayerId;
            if ( player->MyArena != 0 )
                SendArenaPacket(player->MyArena, v20, 3, 1);
        }
    }
}

//----- (0040DC00) --------------------------------------------------------
void __cdecl SetPlayerShip(struct PLAYER *player, signed int Ship)
{
    struct PLAYER *playerrr; // ebp@1
    __int16 v3; // ax@2
    signed int v4; // edi@2
    struct ARENA *v5; // ecx@2
    char v6; // al@4
    __int16 v7; // dx@4
    struct ARENA *v8; // ecx@5
    __int16 v9; // si@5
    struct ARENA *v10; // esi@9
    unsigned int v11; // kr04_4@11
    __int16 v12; // ax@13
    struct ARENA *v13; // ecx@19
    int v14; // esi@19
    char buffer2[6]; // [sp+10h] [bp-210h]@4
    char buffer1[5]; // [sp+18h] [bp-208h]@2
    char buf[512]; // [sp+20h] [bp-200h]@11

    if ( player->AttachedToPlayerId >= 0 )
    {
        buffer1[0] = 0x0E;                          // 0x0E - Create Turret Link
        *(unsigned short *)&buffer1[3] = -1;
        *(unsigned short *)&buffer1[1] = player->PlayerId;
        player->AttachedToPlayerId = -1;
        SendArenaPacket(player->MyArena, buffer1, 5, 1);
    }
    buffer2[0] = 0x1D;                           // 0x1D - Player Team and Ship Changed
    *(unsigned short *)&buffer2[2] = player->PlayerId;
    buffer2[1] = Ship;
    if ( Ship == 8 )                       // Spec Ship
    {
        *(unsigned short *)&buffer2[4] = player->MyArena->ServersideArenaSettings.TeamSpectatorFrequency;
LABEL_19:
        player->Ship = Ship;
        player->AttachedToPlayerId = -1;
        player->ArenaPlayerIndex = -1;
        player->Frequency = player->MyArena->ServersideArenaSettings.TeamSpectatorFrequency;
        SendArenaPacket(player->MyArena, buffer2, 6, 1);
        CarryFlagsSomething(player->MyArena, player->PlayerId, 0);
        UpdatePowerBallPositions(player);
        player->TotalShipChanges++;
        if ( player->TotalShipChanges > player->MyArena->ServersideArenaSettings.SecurityMaxShipTypeSwitchCount )
        {
            WriteSubGameLog("Played kicked off for too many ship type changes: %s\n", player->PlayerName);
            *(unsigned short *)&buf[3] = player->PlayerId;
            player->DisconnectReason = 15;
            player->AlreadySentReliablePacket = 1;
            strcpy(&buf[5], "WARNING: You have been disconnected for too many ship type changes.");
            buf[0] = 7;                               // 0x07 - Chat
            buf[1] = 0;
            buf[2] = 0;
            SendPlayerReliablePacket(
                player,
                buf,
                strlen("WARNING: You have been disconnected for too many ship type changes.") + 6,
                0);
            sub_41CB20(player->connection);
        }
        return;
    }
    if ( player->Ship != 8 )                    // Any Ship other then Spec
    {
        if ( player->MyArena->ServersideArenaSettings.MiscFrequencyShipTypes )
        {
            PlayerChangeFrequency(player, Ship);
            return;
        }
        v9 = player->Frequency;
        *(unsigned short *)&buffer2[4] = player->Frequency;
        goto LABEL_19;
    }
    if ( player->IsModerator
            || player->MyArena->ServersideArenaSettings.MiscMaxPlaying <= 0
            || (v10 = player->MyArena, GetTotalPlayingPlayers(player->MyArena) <= v10->ServersideArenaSettings.MiscMaxPlaying) )
    {
        v9 = GetNextFrequencyToJoin(player->MyArena);
        *(unsigned short *)&buffer2[4] = v9;
        if ( player->MyArena->ServersideArenaSettings.MiscFrequencyShipTypes )
        {
            v6 = abs(v9) & 7;
            buffer2[1] = v6;
        }
        else
        {
            v6 = buffer2[1];
        }
        goto LABEL_19;
    }
    if ( v10 )
    {
        *(unsigned short *)&buf[3] = -1;
        strcpy(&buf[5], "There are too many people playing the game right now, try again later.");
        buf[0] = 7;	// 0x07 - Chat
        buf[1] = 0;
        buf[2] = 0;
        v11 = strlen("There are too many people playing the game right now, try again later.");
        if ( GetBillingServerRelOut(player->connection, 0) < 128 )
            SendPlayerReliablePacket(player, buf, v11 + 6, 1);
    }
}

//----- (0040DEA0) --------------------------------------------------------
void __cdecl sub_40DEA0(struct PLAYER *player, const void *buf, unsigned int len, int a4)
{
    if ( !player->field_309 )
    {
        if ( player->MyArena )
        {
            if ( a4 == 21 && *((unsigned char *)buf + 19) & 0x1F )
            {
                ++player->SecurityWeaponCountyTotalNew;
                if ( player->S2CPacketLossPercentage < player->MyArena->ServersideArenaSettings.RoutingDoubleSendPercent )
                {
                    SendPlayerReliablePacket(player, buf, len, 0);
                    ++player->SecurityWeaponCountyTotalNew;
                    ++dword_4C8F38;
                    sub_41CB20(player->connection);
                }
            }
            SendPlayerReliablePacket(player, buf, len, 0);
        }
    }
}
// 4C8F38: using guessed type int dword_4C8F38;

//----- (0040DF30) --------------------------------------------------------
void __cdecl SendPlayerReliablePacket(struct PLAYER *player, const void *buf, unsigned int len, int IsReliableSend)
{
    struct ARENA *arena; // eax@3
    int v6; // eax@8

    if ( IsReliableSend
            || !player->field_309
            && ((arena = player->MyArena) == 0
                || player->connection->RatioBytesSent <= arena->ServersideArenaSettings.LatencyCutbackWatermark
                || *(unsigned char *)buf == 5) ) //0x05 - Large Position Packet (Weapons Packet)
    {
        if ( !SendReliablePacket(player->connection, (unsigned char *)buf, len, IsReliableSend) && IsReliableSend )
        {
            WriteSubGameLog(
                "Reliable packet lost(%d) to: %s (pending=%d current=%d diff=%d)\n",
                *(unsigned char *)buf,
                player->PlayerDataBillerPacket.Name,
                player->connection->ReliablePacketsPending,
                player->connection->ReliablePacketsCurrent,
                player->connection->ReliablePacketsCurrent - player->connection->ReliablePacketsPending);
            v6 = player->IsSysop;
            player->DisconnectReason = 8;
            player->AlreadySentReliablePacket = 1;
            if ( v6 )
                SaveLostReliablePackets(player->connection, "reliable.txt");
        }
        ++TotalSentForEachPacketType[*(unsigned char *)buf];          // All Packet Types Sent (I guess used for packet statistics)
        TotalSentSizeForEachPacketType[*(unsigned char *)buf] += len;     // All Packet Types Sizes Sent (I guess used for packet statistics)
    }
}

//----- (0040E000) --------------------------------------------------------
void __cdecl SendToSpectators(struct PLAYER *player, char *buf, int len, int a4, int a5, int a6)
{
    if ( !a5 || !player->AllowAudioByte2 )
    {
        if ( !a6 || player->Ship == 8 )
            SendPlayerReliablePacket(player, buf, len, a4);
    }
}

//----- (0040E040) --------------------------------------------------------
void __cdecl SendEverybodyButYourself(struct PLAYER *player, const void *buf, unsigned int len, int a4)
{
    int v6; // ebx@2
    signed int v7; // edi@3
    struct PLAYER *CheckPlayer; // eax@4

    if ( player->MyArena )
    {
        if ( player->MyArena->ArenaPlayerCount > 0 )
        {
            v6 = 0;
            do
            {
                CheckPlayer = player->MyArena->ArenaPlayers[v6];
                if ( CheckPlayer != player )
                {
                    if ( !CheckPlayer->AlreadySentReliablePacket )
                        SendPlayerReliablePacket(CheckPlayer, buf, len, a4);
                }
                ++v6;
            }
            while ( v6 < player->MyArena->ArenaPlayerCount );
        }
    }
}

//----- (0040E0A0) --------------------------------------------------------
void __cdecl SendPacketToMyFrequency(struct PLAYER *player, const void *buf, unsigned int len, int IsReliableSend)
{
    int v6; // ebx@2
    signed int v7; // edi@3
    struct PLAYER *CheckPlayer; // eax@4

    if ( player->MyArena )
    {
        v6 = 0;
        if ( player->MyArena->ArenaPlayerCount > 0 )
        {
            do
            {
                CheckPlayer = player->MyArena->ArenaPlayers[v6];
                if ( CheckPlayer != player )
                {
                    if ( CheckPlayer->Frequency == player->Frequency )
                        SendPlayerReliablePacket(CheckPlayer, buf, len, IsReliableSend);
                }
                ++v6;
            }
            while ( v6 < player->MyArena->ArenaPlayerCount );
        }
    }
}

//----- (0040E110) --------------------------------------------------------
void __cdecl SomethingWithAttachedPlayer(struct PLAYER *player, const void *buf, unsigned int len, int isMessageReliable, int a5, int a6)
{
    signed int v8; // ebp@3
    struct PLAYER *v9; // ecx@4
    struct PLAYER *v10; // esi@4
    int v11; // edx@5
    int v12; // edx@8
    signed int v13; // edi@12
    __int64 v14; // qax@12
    __int64 v15; // qax@13
    int v16; // [sp+0h] [bp-4h]@2

    if ( player->MyArena )
    {
        v16 = 0;
        if ( player->MyArena->ArenaPlayerCount > 0 )
        {
            do
            {
                v9 = player->MyArena->ArenaPlayers[v16];
                v10 = player->MyArena->ArenaPlayers[v16];
                if ( player->MyArena->ArenaPlayers[v16] != player )
                {
                    if ( player->MyArena->ArenaPlayers[v16]->ArenaPlayerIndex >= 0 )
                        v10 = ZonePlayerList[player->MyArena->ArenaPlayers[v16]->ArenaPlayerIndex];
                    if ( v10 )
                    {
                        if ( v10->AttachedToPlayerId >= 0 )
                            v10 = ZonePlayerList[v10->AttachedToPlayerId];
                        if ( v10 )
                        {
                            if ( player->MyArena->ArenaPlayers[v16]->IsSysop
                                    || ((v10->YPixels - player->YPixels) <= player->MyArena->ServersideArenaSettings.MessageDistance
                                        && (v10->XPixels - player->XPixels) <= player->MyArena->ServersideArenaSettings.MessageDistance))
                            {
                                if ( !a5 || !player->MyArena->ArenaPlayers[v16]->AllowAudioByte2 )
                                {
                                    if ( !a6 || player->MyArena->ArenaPlayers[v16]->Ship == 8 )
                                        SendPlayerReliablePacket(player->MyArena->ArenaPlayers[v16], buf, len, isMessageReliable);
                                }
                            }
                        }
                    }
                }
                ++v16;
            }
            while ( v16 < player->MyArena->ArenaPlayerCount );
        }
    }
}

//----- (0040E220) --------------------------------------------------------
void __cdecl sub_40E220(struct PLAYER *player, const void *buf, unsigned int len, int a4, int a5, int a6)
{
    int v8; // ebx@2
    signed int v9; // edi@3
    struct PLAYER *CheckPlayer; // ecx@4

    if ( player->MyArena )
    {
        v8 = 0;
        if ( player->MyArena->ArenaPlayerCount > 0 )
        {
            do
            {
                CheckPlayer = player->MyArena->ArenaPlayers[v8];
                if ( CheckPlayer != player
                        && CheckPlayer->Frequency == player->Frequency
                        && (!a5 || !CheckPlayer->AllowAudioByte2) )
                {
                    if ( !a6 || CheckPlayer->Ship == 8 )
                        SendPlayerReliablePacket(player->MyArena->ArenaPlayers[v8], buf, len, a4);
                }
                ++v8;
            }
            while ( v8 < player->MyArena->ArenaPlayerCount );
        }
    }
}

//----- (0040E2B0) --------------------------------------------------------
void __stdcall SomethingWithAudioByteAndShip8(int ArenaPlayerIndex, const void *buf, unsigned int len, int a4, int a5, int a6)
{
    struct PLAYER *v6; // ecx@1

    v6 = ZonePlayerList[ArenaPlayerIndex];
    if ( v6 && (!a5 || !v6->AllowAudioByte2) )
    {
        if ( !a6 || v6->Ship == 8 )
            SendPlayerReliablePacket(v6, buf, len, a4);
    }
}

//----- (0040E300) --------------------------------------------------------
void __cdecl sub_40E300(struct PLAYER *player, int a2, char *buf, int len, int a4, int a6, int a7)
{
    struct PLAYER *v7; // ebx@1
    struct ARENA *v8; // eax@2
    int v9; // edi@3
    signed int v10; // esi@4
    struct PLAYER *v11; // ecx@5

    if ( ZonePlayerList[a2] )
    {
        if ( ZonePlayerList[a2]->MyArena )
        {
            v9 = 0;
            if ( ZonePlayerList[a2]->MyArena->ArenaPlayerCount > 0 )
            {
                do
                {
                    if ( ZonePlayerList[a2]->MyArena->ArenaPlayers[v9] != player
                            && ZonePlayerList[a2]->MyArena->ArenaPlayers[v9]->Frequency == ZonePlayerList[a2]->Frequency
                            && (!a6 || !ZonePlayerList[a2]->MyArena->ArenaPlayers[v9]->AllowAudioByte2) )
                    {
                        if ( !a7 || ZonePlayerList[a2]->MyArena->ArenaPlayers[v9]->Ship == 8 )
                            SendPlayerReliablePacket(ZonePlayerList[a2]->MyArena->ArenaPlayers[v9], buf, len, a4);
                    }
                    ++v9;
                }
                while ( v9 < ZonePlayerList[a2]->MyArena->ArenaPlayerCount );
            }
        }
    }
}

//----- (0040E3A0) --------------------------------------------------------
void __cdecl SendArenaMessage(struct PLAYER *player, const char *a2, char SoundByte)
{
    unsigned int v4; // kr04_4@2
    char buf[512]; // [sp+10h] [bp-200h]@2

    if ( player->MyArena )
    {
        buf[2] = SoundByte;                         // Sound Byte
        strcpy(&buf[5], a2);                        // Chat Message
        buf[0] = 7;                                 // 0x07 - Chat
        buf[1] = 0;                                 // Chat Type - 0x00 - Message in green text [*arena, *zone, ...]
        *(unsigned short *)&buf[3] = -1;                     // Originator ID
        if ( GetBillingServerRelOut(player->connection, 0) < 128 )
            SendPlayerReliablePacket(player, buf, strlen(a2) + 6, 1);
    }
}

//----- (0040E440) --------------------------------------------------------
void __cdecl SendChannelMessage(struct PLAYER *player, const char *a2)
{
    char buf[512]; // [sp+4h] [bp-200h]@2

    if ( player->MyArena )
    {
        strcpy(&buf[5], a2);                        // Chat Message
        buf[0] = 7;                                 // 0x07 - Chat
        buf[1] = 9;                                 // Chat Type - 0x09 - Channel message
        buf[2] = 0;                                 // Sound Byte
        *(unsigned short *)&buf[3] = -1;                     // Originator ID
        SendPlayerReliablePacket(player, buf, strlen(a2) + 6, 1);
    }
}

//----- (0040E4C0) --------------------------------------------------------
void __cdecl SendArenaMessagePlayer(struct PLAYER *player, const char *a2, char SoundByte)
{
    char buf[512]; // [sp+10h] [bp-5h]@1

    buf[2] = SoundByte;                           // Sound Byte
    *(unsigned short *)&buf[3] =  player->PlayerId;                       // Originator ID
    strcpy(&buf[5], a2);                          // Chat Message
    buf[0] = 7;                                   // 0x07 - Chat
    buf[1] = 0;                                   // Chat Type - 0x00 - Message in green text [*arena, *zone, ...]
    SendPlayerReliablePacket(player, buf, strlen(a2) + 6, 0);
    sub_41CB20(player->connection);
}

//----- (0040E550) --------------------------------------------------------
void __cdecl GetServerFile(struct PLAYER *player, const char *filename)
{
    //struct PLAYER *player; // esi@1
    FILE *fileHandle; // eax@1
    FILE *v4; // edi@1
    int v5; // eax@2
    size_t v6; // ebp@2
    char *v7; // esi@2
    char buf[17]; // [sp+10h] [bp-14h]@3

    fileHandle = fopen(filename, "rb");
    if ( fileHandle )
    {
        v5 = _fileno(fileHandle);
        v6 = _filelength(v5);
        v7 = (char *)AllocateMemory(v6 + 17); //+17 is for packet header I believe.
        fread(v7 + 17, 1, v6, fileHandle);
        fclose(fileHandle);
        v7[0] = 0x10;  // 0x10 - File Transfer
        strncpy(&v7[1], filename, 0x10); //filename 16 bytes.
        v7 [16] = 0; //17th byte is null terminater.
        SendHugeChunkPacketAllocated(player->connection, v7, v6 + 17, 0);
    } else {
        //File isn't found on server or couldn't be opened for some reason.
        buf[0] = 0x10;                             // 0x10 - File Transfer
        strncpy(&buf[1], filename, 0x10u);
        buf[16] = 0;                                // Null terminater for File transfer filename. 16 bytes.
        SendPlayerReliablePacket(player, buf, 17u, 1);
    }
}
// 41F1B0: using guessed type unsigned int __cdecl _filelength(unsigned int);

//----- (0040E620) --------------------------------------------------------
struct ARENA *__cdecl ArenaHandler(struct PLAYER *player, int ArenaIndex, const char *ArenaName)
{
    int TotalMemoryUsage; // ebx@1
    int v5; // ecx@2
    struct ARENA *result; // eax@6
    const char *v7; // ebp@8
    struct ARENA **v8; // ebx@10
    struct ARENA *v9; // eax@11
    int v10; // edx@12
    int v11; // edi@13
    signed int v12; // esi@14
    int v13; // eax@22
    int v14; // esi@23
    struct ARENA **v15; // edx@23
    int v16; // edi@28
    signed int v17; // esi@29
    struct ARENA *v18; // eax@30
    int v19; // edi@37
    struct ARENA **v20; // esi@38
    struct ARENA *arena; // eax@51
    struct ARENA *v22; // eax@52
    signed int v23; // esi@54
    int i; // eax@54
    struct ARENA *v25; // edx@55
    struct ARENA **v26; // esi@63
    struct ARENA *v27; // eax@69
    int v28; // ecx@72
    int x; // [sp+24h] [bp+4h]@9

    TotalMemoryUsage = 0;
    if ( ArenaIndex < 0 )
    {
        //ArenaIndex = -1 has something to do with Squads Only Arena?
        if ( ArenaIndex == -1 && (v7 = player->PlayerDataBillerPacket.Squad, player->PlayerDataBillerPacket.Squad[0]) ) {
            if ( ArenaArrayLength > 0 )
            {
                x = 0;
                while ( 1 )
                {
                    if ( !Arenas[x]->ArenaName[0] )
                    {
                        if ( Arenas[x]->ArenaPlayerCount < ArenaMaxPlayers )
                        {
                            v11 = 0;
                            if ( Arenas[x]->ArenaPlayerCount > 0 )
                                break;
                        }
                    }
LABEL_18:
                    ++x;
                    if ( x >= ArenaArrayLength )
                        goto LABEL_54;
                }
                while ( stricmp(Arenas[x]->ArenaPlayers[v11]->PlayerDataBillerPacket.Squad, v7) )
                {
                    ++v11;
                    if ( v11 >= Arenas[x]->ArenaPlayerCount )
                    {
                        goto LABEL_18;
                    }
                }
                return Arenas[x];
            }
        } else if ( ArenaIndex == -2 ) {
            v13 = 0;

            if ( ArenaArrayLength > 0 )
            {
                while ( Arenas[v13] != player->MyLastArena )
                {
                    ++v13;
                    if ( v13 >= ArenaArrayLength )
                        break;
                }
            }

            v16 = 0;
            if ( ArenaArrayLength > 0 )
            {
                v17 = v13 + 1;
                do
                {
                    if ( !Arenas[v17 % ArenaArrayLength]->ArenaName[0] )
                    {
                        if ( player->IsModerator || Arenas[v17 % ArenaArrayLength]->ArenaPlayerCount < ArenaMaxPlayers )
                            return Arenas[v17 % ArenaArrayLength];
                    }
                    ++v16;
                    ++v17;
                }
                while ( v16 < ArenaArrayLength );
            }
        } else if ( ArenaIndex == -3 ) {
            v19 = 0;
            if ( ArenaArrayLength > 0 )
            {
                while ( 1 )
                {
                    TotalMemoryUsage += GetArenaMemoryTotal(Arenas[v19]);
                    if ( !stricmp(Arenas[v19]->ArenaName, ArenaName) )
                        break;
                    ++v19;
                    if ( v19 >= ArenaArrayLength )
                        goto LABEL_46;
                }
                if ( player->IsModerator )
                    return Arenas[v19];
                if ( Arenas[v19]->ArenaPlayerCount < ArenaMaxPlayers )
                    return Arenas[v19];
            }
LABEL_46:

            if ( v19 == ArenaArrayLength && (player->IsSuperModerator || ArenaArrayLength < MaxArenas && TotalMemoryUsage < MaxArenasMemory) )
            {
                arena = malloc (sizeof (struct ARENA));
                if ( arena )
                {
                    InitializeNewArena(arena, ArenaName);
                    Arenas[ArenaArrayLength] = arena;
                    return Arenas[ArenaArrayLength++];
                }
                Arenas[ArenaArrayLength] = 0;
                result = Arenas[ArenaArrayLength];
                ArenaArrayLength++;
                return result;
            }
        }
    } else {
        if ( ArenaIndex < ArenaArrayLength
                && (player->IsModerator || !Arenas[ArenaIndex]->ArenaName[0] && Arenas[ArenaIndex]->ArenaPlayerCount < ArenaMaxPlayers) )
            return Arenas[ArenaIndex];
    }
LABEL_54:
    v23 = -1;
    for ( i = 0; i < ArenaArrayLength; ++i )
    {
        v25 = Arenas[i];
        if ( !v25->ArenaName[0] && (v23 == -1 || v25->ArenaPlayerCount < Arenas[v23]->ArenaPlayerCount) )
            v23 = i;
    }
    if ( v23 == -1 || (result = Arenas[v23], result->ArenaPlayerCount >= ArenaMaxPlayers) )
    {
        arena = malloc (sizeof (struct ARENA));
        if ( arena )
        {
            InitializeNewArena(arena, "");
            Arenas[ArenaArrayLength++] = arena;
            return arena;
        }
        Arenas[ArenaArrayLength] = 0;
        return Arenas[ArenaArrayLength++];
    }
    if ( ArenaArrayLength > 0 )
    {
        v19 = 0;
        while ( Arenas[v19]->ArenaName[0] || Arenas[v19]->ArenaPlayerCount >= ArenaDesiredPlayers )
        {
            ++v19;
            if ( v19 >= ArenaArrayLength )
                return result;
        }
        result = Arenas[v19];
    }
    return result;
}
// 431FF4: using guessed type int ArenaArrayLength;
// 4380B0: using guessed type int ArenaMaxPlayers;
// 438B18: using guessed type int MaxArenasMemory;
// 4D5908: using guessed type int MaxArenas;
// 4D5928: using guessed type int ArenaDesiredPlayers;

//----- (0040E990) --------------------------------------------------------
void __cdecl SendWeaponPacket(struct PLAYER *player)
{
    //struct PLAYER *player; // ebx@1
    int v2; // eax@1
    short v3; // cx@2
    short v4; // dx@2
    struct CONNECTION *v5; // edi@2
    short v6; // ax@2
    //unsigned int v7; // eax@2
    int v8; // ebp@2
    int v9; // edi@2
    unsigned int v10; // edx@2
    struct CONNECTION *v11; // ebp@2
    unsigned int v12; // edx@2
    unsigned int v13; // edx@7
    short v14; // cx@11
    char v15; // al@11
    short v16; // ax@11
    char v17; // al@17
    char *v18; // ecx@17
    signed int v19; // edx@17
    struct ARENA *v20; // eax@20
    int v21; // ecx@22
    short v22; // dx@30
    short v23; // ax@30
    struct CONNECTION *v24; // edi@30
    short v25; // cx@30
    unsigned int v26; // eax@30
    int v27; // ebp@30
    int v28; // edi@30
    unsigned int v29; // edx@30
    struct CONNECTION *v30; // ebp@30
    unsigned int v31; // edx@30
    unsigned int v32; // edx@34
    char v33; // al@38
    char v34; // cl@38
    short v35; // ax@39
    short v36; // cx@39
    struct CONNECTION *v37; // edi@39
    short v38; // dx@39
    unsigned int v39; // eax@39
    int v40; // ebp@39
    int v41; // edi@39
    unsigned int v42; // edx@39
    struct CONNECTION *v43; // ebp@39
    unsigned int v44; // edx@39
    char v45; // al@43
    unsigned int v46; // edx@44
    short v47; // dx@48
    char v48; // al@48
    short v49; // cx@48
    short v50; // ax@48
    signed int v51; // edx@48
    short v52; // cx@48
    char v53; // al@48
    int *v54; // ecx@48
    unsigned int v55; // eax@52
    short v56; // dx@52
    int v57; // edx@54
    int v58; // edi@54
    short v59; // ax@55
    bool v60; // zf@68
    bool v61; // sf@68
    unsigned char v62; // of@68
    bool v63; // zf@72
    bool v64; // sf@72
    unsigned char v65; // of@72
    struct ARENA *v66; // eax@80
    signed int v67; // ebp@81
    struct PLAYER *v68; // esi@82
    int v69; // edx@83
    int v70; // ecx@85
    unsigned int v71; // edi@87
    struct ARENA *v72; // eax@93
    int v73; // esi@101
    int v74; // ecx@103
    int v75; // ebp@105
    signed int v76; // edx@107
    int v77; // eax@109
    int v78; // eax@109
    int v79; // eax@111
    int v80; // edi@113
    int v81; // eax@115
    int v82; // ecx@115
    int v83; // eax@116
    struct PLAYER *v84; // ebp@118
    int v85; // eax@121
    int v86; // eax@123
    struct PLAYER *v87; // ecx@123
    int v88; // eax@125
    long v89; // qax@127
    long v90; // qax@128
    unsigned int v91; // esi@129
    struct ARENA *v92; // eax@135
    int v93; // ecx@138
    int v94; // eax@151
    int v95; // esi@152
    int result; // eax@157
    unsigned int len; // [sp+10h] [bp-DCh]@30
    int v98; // [sp+14h] [bp-D8h]@54
    signed int v99; // [sp+14h] [bp-D8h]@116
    int v100; // [sp+18h] [bp-D4h]@54
    int v101; // [sp+18h] [bp-D4h]@109
    int v102; // [sp+1Ch] [bp-D0h]@80
    int v103; // [sp+1Ch] [bp-D0h]@105
    int v104; // [sp+20h] [bp-CCh]@54
    int v105; // [sp+20h] [bp-CCh]@109
    char buf[32]; // [sp+24h] [bp-C8h]@2
    int v121; // [sp+44h] [bp-A8h]@113
    int v122; // [sp+48h] [bp-A4h]@107
    int v123; // [sp+4Ch] [bp-A0h]@113
    int v124; // [sp+50h] [bp-9Ch]@117
    int v125; // [sp+54h] [bp-98h]@115
    int v126; // [sp+58h] [bp-94h]@109
    int v127; // [sp+5Ch] [bp-90h]@116
    int v128; // [sp+60h] [bp-8Ch]@109
    int v129; // [sp+64h] [bp-88h]@109
    int v130; // [sp+68h] [bp-84h]@109
    char v131[26]; // [sp+6Ch] [bp-80h]@30


    player->SendWeaponUpdatePacket = 0;
    if ( player->field_28B )
    {
        *(unsigned short *)&buf[4] = player->XPixels;                     // X Pixels (0-16384)
        *(unsigned short *)&buf[15] = player->YPixels;
        buf[1] = player->ShipDirection;							// Direction (0-360)
        buf[0] = 0x05;                                    						// 0x05 - Large Position Packet (Weapons Packet)
        *(unsigned short *)&buf[10] = player->XVelocity;                  // X Velocity
        *(unsigned short *)&buf[6] = player->YVelocity;                     // Y Velocity
        *(unsigned short *)&buf[2] = (player->connection->SyncResponseLocalTimeStamp + GetTickCount() / 0xA);
        v12 = ((player->connection->SyncResponseLocalTimeStamp + GetTickCount() / 0xA) & 0x7FFFFFFF) - player->PingTimestamp;
        if ( (v12 & 0x80000000) != 0 || v12 > 30000 )
            v12 = 0;
        if ( v12 <= 255 )
        {
            v13 = ((player->connection->SyncResponseLocalTimeStamp + GetTickCount() / 0xA) & 0x7FFFFFFF) - player->PingTimestamp;
            if ( (v13 & 0x80000000) != 0 || v13 > 30000 )
                *((unsigned char*)&(v13)) = 0;
            buf[14] = v13;                               // Ping
        }
        else
        {
            buf[14] = -1;                                // Ping
        }
        *(unsigned short *)&buf[8] = 1014;                                // Special PlayerId?
        v16 = player->WeaponsInfo & 0x1F;
        buf[13] = 0;
        *(unsigned short *)&buf[17] = 0;
        if ( v16 == 3 || v16 == 4 || v16 == 1 || v16 == 2 )
            *(unsigned short *)&buf[19] = player->WeaponsInfo ^ (player->WeaponsInfo ^ (unsigned char)(player->WeaponsInfo & 0x80) ^ (player->WeaponsInfo & 0x1F ^ *(unsigned short *)&buf[19] & 0xFF80) & 0xFC7F) & 0x3FF;
        else
            *(unsigned short *)&buf[19] = 0;
        v17 = 0;
        buf[12] = 0;                                   // Checksum
        v19 = 0;
        do
        {
            v17 ^= buf[v19++];
        }
        while ( v19 < 21 );
        buf[12] = v17;                                 // Computed Checksum
        if ( !player->field_309 )
        {
            if ( player->MyArena )
            {
                if ( buf[19] & 0x1F )
                {
                    v21 = player->S2CPacketLossPercentage;
                    ++player->SecurityWeaponCountyTotalNew;
                    if ( v21 < player->MyArena->ServersideArenaSettings.RoutingDoubleSendPercent )
                    {
                        SendPlayerReliablePacket(player, buf, 0x15, 0);
                        ++player->SecurityWeaponCountyTotalNew;
                        ++dword_4C8F38;
                        sub_41CB20(player->connection);
                    }
                }
                SendPlayerReliablePacket(player, buf, 0x15, 0);
            }
        }
    }
    if ( player->Ship < 8 && player->MyArena )
    {
        if ( player->PlayerId > 255 || player->Bounty > 255 || player->WeaponsInfo & 0x1F )
        {
            v37 = player->connection;
            *(unsigned short *)&v131[4] = player->XPixels;
            *(unsigned short *)&v131[15] = player->YPixels;
            len = 21;
            v131[0] = 5;                         // 0x05 - Large Position Packet (Weapons Packet)
            *(unsigned short *)&v131[10] = player->XVelocity;
            *(unsigned short *)&v131[6] = player->YVelocity;
            v131[1] = player->ShipDirection;
            *(unsigned short *)&v131[2] = v37->SyncResponseLocalTimeStamp + GetTickCount() / 0xA;
            v44 = ((player->connection->SyncResponseLocalTimeStamp + GetTickCount() / 0xA) & 0x7FFFFFFF) - player->PingTimestamp;
            if ( (v44 & 0x80000000) != 0 || v44 > 30000 )
                v44 = 0;
            if ( v44 <= 255 )
            {
                v45 = ((player->connection->SyncResponseLocalTimeStamp + GetTickCount() / 0xA) & 0x7FFFFFFF) - player->PingTimestamp;
                if ( (v45 & 0x80000000) != 0 || v45 > 30000 )
                    v45= 0;
            } else {
                v45 = -1;
            }
            v131[14] = v45;
            *(unsigned short *)&v131[8] = player->PlayerId;
            v131[13] = player->ShipTogglables;
            *(unsigned short *)&v131[17] = player->Bounty;
            *(unsigned short *)&v131[19] ^= ((unsigned char)player->WeaponsInfo ^ v131[19]) & 0x1F;// BitFlags
            *(unsigned short *)&v131[19] ^= ((unsigned char)player->WeaponsInfo ^ v131[19]) & 0x60;
            *(unsigned short *)&v131[19] ^= ((unsigned char)player->WeaponsInfo ^ v131[19]) & 0x80;
            *(unsigned short *)&v131[19] ^= (player->WeaponsInfo ^ *(unsigned short *)&v131[19]) & 0x300;
            *(unsigned short *)&v131[19] ^= (player->WeaponsInfo ^ *(unsigned short *)&v131[19]) & 0x7C00;
            *(unsigned short *)&v131[19]= player->WeaponsInfo ^ (player->WeaponsInfo ^ *(unsigned short *)&v131[19]) & 0x7FFF;
            v131[12] = 0;
            v51 = 0;
            v53 = 0;	// Checksum
            do
            {
                v53 ^= v131[v51++];
            }
            while ( v51 < 21 );
            v131[12] = v53; // Computed Checksum
        }
        else
        {
            *(unsigned short *)&v131[4] = player->XPixels;
            *(unsigned short *)&v131[12] = player->YPixels;
            len = 16;
            v131[0] = 0x28;                     // 0x28 - Small Position Packet
            *(unsigned short *)&v131[14] = player->XVelocity;
            *(unsigned short *)&v131[10] = player->YVelocity;
            v131[1]  = player->ShipDirection;
            *(unsigned short *)&v131[2] = player->connection->SyncResponseLocalTimeStamp + GetTickCount() / 0xA;
            v31 = ((player->connection->SyncResponseLocalTimeStamp + GetTickCount() / 0xA) & 0x7FFFFFFF) - player->PingTimestamp;
            if ( (v31 & 0x80000000) != 0 || v31 > 30000 )
                v31 = 0;
            if ( v31 <= 255 )
            {
                v32 = ((player->connection->SyncResponseLocalTimeStamp + GetTickCount() / 0xA) & 0x7FFFFFFF) - player->PingTimestamp;
                if ( (v32 & 0x80000000) != 0 || v32 > 30000 )
                    *((unsigned char*)&(v32)) = 0;
            }
            else
            {
                *((unsigned char*)&(v32)) = -1;
            }
            v131[6] = v32;
            v131[7] = *((unsigned char*)&(player->Bounty));
            v131[8] = *((unsigned char*)&(player->PlayerId));
            v131[9] = player->ShipTogglables;
        }
        if ( player->field_10B ) {
            v55 = len;
            *(unsigned int *)&v131[len] = player->EnergyOptional;
            *(unsigned int *)&v131[len + 4] = player->TimerOptional;
            *(unsigned short *)&v131[len + 8] =player->SharpnelMinesBombsBulletsMultifireInformationOptional;
            *(unsigned int *)&buf[24] = len + 10;
        } else {
            *(unsigned short *)&v131[len] = player->Energy;
            *(unsigned int *)&buf[24] = len + 2;
            v55 = len;
        }
        v57 = 0;
        v58 = 0;
        v104 = 0;
        v98 = 0;
        v100 = 0;
        if ( v55 != 21 )
            goto LABEL_79;
        v59 = v131[19] & 0x1F;
        if ( v59 == 6 || v59 == 3 && v131[20] & 0x80 || v59 == 4 && v131[20] & 0x80 || v59 == 5 || v59 == 8 )
        {
            player->field_10F = 1;
        }
        else
        {
            if ( v59 == 4 || v59 == 3 )
            {
                if ( v131[1] < 5 || v131[1] > 35 )
                    v98 = player->MyArena->ServersideArenaSettings.RoutingCloseEnoughBombAdjust;
                if ( v131[1] > 5 )
                {
                    v62 = __OFSUB__(v131[1], 15);
                    v60 = v131[1] == 15;
                    v61 = (char)(v131[1] - 15) < 0;
                    if ( v131[1] >= 15 )
                        goto LABEL_71;
                    v58 = player->MyArena->ServersideArenaSettings.RoutingCloseEnoughBombAdjust;
                }
                v62 = __OFSUB__(v131[1], 15);
                v60 = v131[1] == 15;
                v61 = (char)(v131[1] - 15) < 0;
LABEL_71:
                if ( !((unsigned char)(v61 ^ v62) | v60) )
                {
                    v65 = __OFSUB__(v131[1], 25);
                    v63 = v131[1] == 25;
                    v64 = (char)(v131[1] - 25) < 0;
                    if ( v131[1] >= 25 )
                    {
LABEL_75:
                        if ( !((unsigned char)(v64 ^ v65) | v63) && v131[1] < 35 )
                        {
                            v57 = player->MyArena->ServersideArenaSettings.RoutingCloseEnoughBombAdjust;
                            v104 = player->MyArena->ServersideArenaSettings.RoutingCloseEnoughBombAdjust;
                        }
                        goto LABEL_79;
                    }
                    v100 = player->MyArena->ServersideArenaSettings.RoutingCloseEnoughBombAdjust;
                }
                v65 = __OFSUB__(v131[1], 25);
                v63 = v131[1] == 25;
                v64 = (char)(v131[1] - 25) < 0;
                goto LABEL_75;
            }
        }
LABEL_79:
        if ( player->field_10F )
        {
            v102 = 0;
            if ( player->MyArena->ArenaPlayerCount > 0 )
            {
                do
                {
                    v68 = player->MyArena->ArenaPlayers[v102];
                    if ( v68 != player )
                    {
                        if ( v68->IsSysop || !player->field_3C || player->field_4C < 0 || player->field_4C == v68->PlayerId )
                        {
                            v71 = len;
                            if ( v68->IsEnergyShowing
                                    || v68->ArenaPlayerIndex == player->PlayerId
                                    && (player->MyArena->ArenaSettings.ExtraPositionData || v68->IsSysop) )
                                v71 = *(unsigned int *)&buf[24];
                            if ( !v68->field_309 )
                            {
                                if ( v68->MyArena )
                                {
                                    if ( len == 21 )              //  Large Position Packet (Weapons Packet) Without Optionals
                                    {
                                        if ( v131[19] & 0x1F )
                                        {
                                            ++v68->SecurityWeaponCountyTotalNew;
                                            if ( v68->S2CPacketLossPercentage < v68->MyArena->ServersideArenaSettings.RoutingDoubleSendPercent )
                                            {
                                                SendPlayerReliablePacket(v68, v131, v71, 0);
                                                ++v68->SecurityWeaponCountyTotalNew;
                                                ++dword_4C8F38;
                                                sub_41CB20(v68->connection);
                                            }
                                        }
                                    }
                                    SendPlayerReliablePacket(v68, v131, v71, 0);
                                }
                            }
                        }
                    }
                    ++v102;
                }
                while ( v102 < player->MyArena->ArenaPlayerCount );
            }
        }
        else
        {
            v73 = (player->LooksLikeX1BigOfSomething - v57) / 2048;
            if ( (player->LooksLikeX1BigOfSomething - v57) / 2048 < 0 )
                v73 = 0;
            v74 = (v58 + player->LooksLikeXSmallOfSomething) / 2048;
            if ( v74 >= 8 )
                v74 = 7;
            v75 = (player->LooksLikeYBigOfSomething - v98) / 2048;
            v103 = (player->LooksLikeYBigOfSomething - v98) / 2048;
            if ( (player->LooksLikeYBigOfSomething - v98) / 2048 < 0 )
            {
                v103 = 0;
                v75 = 0;
            }
            v122 = (v100 + player->LooksLikeYSmallOfSomething) / 2048;
            v76 = v122;
            if ( v122 >= 8 )
            {
                v76 = 7;
                v122 = 7;
            }
            v77 = player->XPixels;
            v129 = v77 + v58;
            v126 = v77 - v104;
            v78 = player->YPixels;
            v128 = v78 + v100;
            v130 = v78 - v98;
            v105 = 128;
            v101 = 128;
            if ( len == 21 && v131[19] & 0x1F )
            {
                v79 = player->MyArena->ServersideArenaSettings.RoutingCloseEnoughBulletAdjust;
                v105 = v79 + 128;
                v101 = v79 + 128;
            }
            if ( v73 <= v74 )
            {
                v80 = 1004 * (v75 + 8 * v73);
                v121 = 1004 * (v75 + 8 * v73);
                v123 = v74 - v73 + 1;
                do
                {
                    if ( v75 <= v76 )
                    {
                        v81 = v80;
                        v125 = v80;
                        v82 = v76 - v75 + 1;
                        *(unsigned int *)&buf[28] = v76 - v75 + 1;
                        do
                        {
                            v99 = 0;
                            v83 = (int)((char *)player->MyArena + v81);
                            v127 = v83;
                            if ( *(unsigned int *)(v83 + 1000) > 0 )
                            {
                                v124 = v83;
                                do
                                {
                                    v84 = *(struct PLAYER **)v83;
                                    if ( *(struct PLAYER **)v83 != player )
                                    {
                                        if ( v84->IsSysop
                                                || !player->field_3C
                                                || (v85 = player->field_4C, v85 < 0)
                                                || v85 == *(unsigned int *)&v84->PlayerId )
                                        {
                                            if ( v84->ArenaPlayerIndex < 0 || (v87 = ZonePlayerList[v84->ArenaPlayerIndex]) != 0 )
                                            {
                                                if ( v84->ArenaPlayerIndex < 0 || (v87 = ZonePlayerList[v84->ArenaPlayerIndex]) != 0 )
                                                {
                                                    if ( (signed int)(v87->YPixels - player->YPixels) > v101 + v84->YResolution / 2
                                                            || (signed int)(v87->XPixels - player->XPixels) > v105 + v84->XResolution / 2 )
                                                    {
                                                        if ( v129 >= v87->LooksLikeX1BigOfSomething
                                                                && v126 <= v87->LooksLikeXSmallOfSomething
                                                                && v128 >= v87->LooksLikeYBigOfSomething
                                                                && v130 <= v87->LooksLikeYSmallOfSomething
                                                                && (len == 21 && (v131[19] & 0x1F) > 2
                                                                    || v99 % player->MyArena->ServersideArenaSettings.RoutingRadarFavor == *(unsigned int *)&player->gap_11B[0]) )
                                                        {
                                                            if ( IncreasesRadarValueSomeHow >= 4000 )
                                                                IncreaseRadarValueShowHomeOverFourThousand();
                                                            v94 = 26 * IncreasesRadarValueSomeHow;
                                                            memcpy((char *)dword_4AF8FC + 26 * IncreasesRadarValueSomeHow, v131, len);
                                                            byte_4AF911[v94] = len;
                                                            *(int *)((char *)&dword_4AF8F8 + v94) = *(unsigned int *)&v84->PlayerId;
                                                            ++IncreasesRadarValueSomeHow;
                                                        }
                                                    }
                                                    else
                                                    {
                                                        v91 = len;
                                                        if ( v84->IsEnergyShowing
                                                                || v84->ArenaPlayerIndex == player->PlayerId
                                                                && (player->MyArena->ArenaSettings.ExtraPositionData || v84->IsSysop) )
                                                            v91 = *(unsigned int *)&buf[24];
                                                        if ( !v84->field_309 )
                                                        {
                                                            if ( v84->MyArena )
                                                            {
                                                                if ( len == 21 )
                                                                {
                                                                    if ( v131[19] & 0x1F )
                                                                    {
                                                                        ++v84->SecurityWeaponCountyTotalNew;
                                                                        if ( v84->S2CPacketLossPercentage < v84->MyArena->ServersideArenaSettings.RoutingDoubleSendPercent )
                                                                        {
                                                                            SendPlayerReliablePacket(v84, v131, v91, 0);
                                                                            ++v84->SecurityWeaponCountyTotalNew;
                                                                            ++dword_4C8F38;
                                                                            sub_41CB20(v84->connection);
                                                                        }
                                                                    }
                                                                }
                                                                SendPlayerReliablePacket(v84, v131, v91, 0);
                                                            }
                                                        }
                                                        ++dword_4D55D0;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    v83 = v124 + 4;
                                    v99++;
                                    v124 += 4;
                                }
                                while ( v99 < *(unsigned int *)(v127 + 1000) );
                                v75 = v103;
                                v76 = v122;
                                v80 = v121;
                                v82 = *(unsigned int *)&buf[28];
                            }
                            v81 = v125 + 1004;
                            --v82;
                            v125 += 1004;
                            *(unsigned int *)&buf[28] = v82;
                        }
                        while ( v82 );
                    }
                    v80 += 8032;
                    v60 = v123 == 1;
                    v121 = v80;
                    --v123;
                }
                while ( !v60 );
            }
            *(unsigned int *)&player->gap_11B[0] = (*(unsigned int *)&player->gap_11B[0] + 1)
                                                   % player->MyArena->ServersideArenaSettings.RoutingRadarFavor;
        }
    }
    result = 0;
    player->field_10F = 0;
    player->field_10B = 0;
}
// 4AF8F8: using guessed type int dword_4AF8F8;
// 4AF8FC: using guessed type int dword_4AF8FC[5];
// 4C8F38: using guessed type int dword_4C8F38;
// 4CA814: using guessed type int IncreasesRadarValueSomeHow;
// 4D55D0: using guessed type int dword_4D55D0;

//----- (0040F4A0) --------------------------------------------------------
void __cdecl SendResetScoresPacket(struct PLAYER *player)
{
    char buf[4]; // [sp+0h] [bp-4h]@1

    player->CurrentDeaths = 0;
    player->CurrentWins = 0;
    player->KillPoints = 0;
    player->FlagPoints = 0;
    player->CurrentGoals = 0;
    player->ScoreReset = 1;
    buf[0] = 0x1A;                               // 0x1A - Reset Score(s)
    *(unsigned short *)&buf[1] = player->PlayerId;
    if ( player->MyArena )
        SendArenaPacket(player->MyArena, buf, 3, 1);
}

//----- (0040F500) --------------------------------------------------------
void __cdecl SendPlayerScoreUpdate(struct PLAYER *player)
{
    //__int16 v1; // ax@1
    //__int16 v2; // dx@1
    //int v3; // eax@1
    char buf[16]; // [sp+0h] [bp-10h]@1

    buf[0] = 0x09;  // 0x09 - Player Score Update
    *(unsigned short *)&buf[1] = player->PlayerId;  // Player ID
    *(unsigned int *)&buf[3] = player->KillPoints;          // Kill Points
    *(unsigned short *)&buf[11] = player->CurrentWins;     // Wins
    *(unsigned int *)&buf[7] = player->FlagPoints;        // Flag Points
    *(unsigned short *)&buf[13] = player->CurrentDeaths;  // Losses
    SendPlayerReliablePacket(player, buf, 0x0F, 1);
}
//----- (0040F550) --------------------------------------------------------
bool __cdecl SendPlayerScoreUpdateAll(struct PLAYER *player)
{
    //PLAYER *player; // esi@1
    int v2; // edx@1
    int v3; // edi@1
    int v4; // ebp@1
    int v5; // ecx@1
    struct ARENA *v6; // eax@3
    __int16 v7; // dx@4
    int v8; // ebp@4
    __int16 v9; // cx@4
    int v10; // ebp@4
    int v11; // ebp@4
    int v12; // edi@4
    signed int v13; // ebx@5
    struct PLAYER *v14; // eax@6
    struct ARENA *v15; // eax@11
    bool result; // al@16
    char buf[16]; // [sp+10h] [bp-10h]@4

    v2 = player->KillPoints;
    v3 = player->KillPointsSomething;
    v4 = player->FlagPointsSomething;
    v5 = player->FlagPoints;
    if ( v5 + v2 - v3 - v4 > MiscPointUpdateDiff && dword_4C8F3C && (player->MyArena) != 0 )
    {
        buf[0] = 0x09;                                 // 0x09 - Player Score Update
        *(unsigned short *)&buf[1] = player->PlayerId;       // Player ID
        *(unsigned int *)&buf[3] = v2;                    // Kill Points
        *(unsigned int *)&buf[7] = v5;                    // Flag Points
        *(unsigned short *)&buf[11] = player->CurrentWins;                    // Wins
        *(unsigned short *)&buf[13] = player->CurrentDeaths;                    // Losses

        player->WinsSomething = player->CurrentWins;
        player->DeathsSomething = player->CurrentDeaths;
        player->GoalsSomething = player->CurrentGoals;
        player->FlagPointsSomething = player->FlagPoints;
        player->KillPointsSomething = player->KillPoints;

        SendEverybodyButYourself(player, buf, 0x0F, 0);
        SendPlayerReliablePacket(player, buf, 0x0F, 1);
        if ( BillingConnectionStructPointer )
        {
            if ( !player->MyArena->ServersideArenaSettings.MiscTimedGame )
            {
                if ( player->MyArena->RecordPointsToLog )
                {
                    if ( (MiscDisableSharewareScores || MiscDisableShareware)
                            && player->DemoPlayer )
                        return 1;
                    SendBillerUserScorePacket(BillingConnectionStructPointer, player->BillerPlayerId, &player->CurrentWins, 0x0E);
                }
            }
        }
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}
// 4C8F3C: using guessed type int dword_4C8F3C;
// 4CA60C: using guessed type int MiscPointUpdateDiff;
// 4D5918: using guessed type int MiscDisableShareware;
// 4D8AE0: using guessed type int MiscDisableSharewareScores;

//----- (0040F6B0) --------------------------------------------------------
void __cdecl SendAdvertisement(struct PLAYER *player, bool ForceAdvertisement)
{
    __int64 v3; // qax@2
    unsigned int v4; // kr00_4@3
    int v5; // eax@3
    int v6; // edx@6
    int v7; // edx@7
    int v8; // edx@15

    if ( ForceAdvertisement || (GetTickCount() / 0xA - player->LastAdvertisementTime) >= 3000)
    {
        player->LastAdvertisementTime = GetTickCount() / 0xA;
        if ( player->DemoPlayer )
        {
            if ( BothAdvertisementsFound > 0 || SharewareAdvertisementsFound > 0 )
            {
                v6 = rand() % (BothAdvertisementsFound + SharewareAdvertisementsFound);
                if ( v6 >= BothAdvertisementsFound )
                {
                    if ( ForceAdvertisement )
                        SendPlayerReliablePacket(player,  SharewareAd[v6].PacketBuffer, SharewareAd[v6].TotalPacketLength, 1);
                    else
                        SendHugeChunkPacketNotAllocated(player->connection, SharewareAd[v6].PacketBuffer, SharewareAd[v6].TotalPacketLength, 0);
                    return;
                }
                if ( ForceAdvertisement )
                {
                    SendPlayerReliablePacket(player, BothAd[v6].PacketBuffer, BothAd[v6].TotalPacketLength, 1);
                    return;
                }
                SendHugeChunkPacketNotAllocated(player->connection, BothAd[v6].PacketBuffer, BothAd[v6].TotalPacketLength, 0);
                return;
            }
        } else {
            if ( BothAdvertisementsFound > 0 || RegisteredAdvertisementsFound > 0 )
            {
                v6 = rand() % (BothAdvertisementsFound + RegisteredAdvertisementsFound);
                if ( v6 < BothAdvertisementsFound )
                {
                    if ( ForceAdvertisement ) {
                        SendPlayerReliablePacket(player, BothAd[v6].PacketBuffer, BothAd[v6].TotalPacketLength, 1);
                        return;
                    }
                    SendHugeChunkPacketNotAllocated(player->connection, BothAd[v6].PacketBuffer, BothAd[v6].TotalPacketLength, 0);
                    return;
                }
                if ( ForceAdvertisement )
                    SendPlayerReliablePacket(player, RegisteredAd[v6].PacketBuffer, RegisteredAd[v6].TotalPacketLength, 1);
                else
                    SendHugeChunkPacketNotAllocated(player->connection, RegisteredAd[v6].PacketBuffer, RegisteredAd[v6].TotalPacketLength, 0);
            }
        }
    }
}
// 4D8AFC: using guessed type int SharewareAdvertisementsFound;
// 4D8B00: using guessed type int RegisteredAdvertisementsFound;
// 4D8B04: using guessed type int BothAdvertisementsFound;

//----- (0040F840) --------------------------------------------------------
void __cdecl LoadZoneCFGSettings(struct ARENA_SETTINGS *arenaSettings, struct SERVERSIDE_ARENA_SETTINGS *serverArenaSettings, const char *a3)
{
    struct struc_2 *v3; // eax@1   TODO made void* so it compiles.
    struct struc_2 *v4; // ebp@2
    int v5; // eax@5
    int v6; // eax@7
    int v7; // eax@9
    int v8; // eax@11
    int v9; // eax@13
    int v10; // eax@15
    int v11; // eax@17
    int v12; // eax@19
    int v13; // eax@21
    int v14; // eax@23
    int v15; // eax@25
    int v16; // eax@27
    int v17; // eax@29
    int v18; // eax@31
    int v19; // eax@33
    int v20; // eax@35
    int v21; // eax@37
    int v22; // eax@39
    int v23; // eax@41
    int v24; // eax@43
    int v25; // eax@45
    int v26; // eax@47
    int v27; // eax@49
    int v28; // eax@51
    int v29; // eax@53
    int v30; // eax@55
    int v31; // eax@57
    int v32; // eax@59
    const char *v33; // edi@62
    int v34; // eax@62
    int v35; // ecx@62
    int v36; // eax@68
    int v37; // ecx@70
    int v38; // eax@72
    char v39; // al@74
    int v40; // edx@74
    char v41; // al@74
    int v42; // ecx@74
    char v43; // al@74
    int v44; // edx@74
    int v45; // eax@76
    char *v46; // esi@81
    signed int v47; // edi@81
    int v48; // [sp-4h] [bp-44h]@64
    //void *Str2[8]; // [sp+14h] [bp-2Ch]@61
    int v50; // [sp+3Ch] [bp-4h]@1
    signed int v51; // [sp+4Ch] [bp+Ch]@61

    v3 = malloc(sizeof(struct struc_2));
    v50 = 0; //Possible TRY/CATCH...
    if ( v3 )
        ReadCompleteSettings(v3, a3);

    v50 = -1; //Possible TRY/CATCH...
    if ( arenaSettings )
    {
        memset(arenaSettings, 0, 0x594);
        *((unsigned char*)&(arenaSettings->VersionAndManyBitFields)) = 15;
        arenaSettings->PrizeAddressAnchor = 0;

        arenaSettings->PrizeWeightQuickCharge = GetCFGSettingInteger(v3, "PrizeWeight", "QuickCharge", 80);
        if(arenaSettings->PrizeWeightQuickCharge > 255)
            arenaSettings->PrizeWeightQuickCharge = -1;

        arenaSettings->PrizeWeightEnergy = GetCFGSettingInteger(v3, "PrizeWeight", "Energy", 70);
        if ( arenaSettings->PrizeWeightEnergy > 255 )
            arenaSettings->PrizeWeightEnergy = -1;

        arenaSettings->PrizeWeightRotation = GetCFGSettingInteger(v3, "PrizeWeight", "Rotation", 60);
        if ( arenaSettings->PrizeWeightRotation > 255 )
            arenaSettings->PrizeWeightRotation = -1;

        arenaSettings->PrizeWeightStealth = GetCFGSettingInteger(v3, "PrizeWeight", "Stealth", 30);
        if ( arenaSettings->PrizeWeightStealth > 255 )
            arenaSettings->PrizeWeightStealth = -1;

        arenaSettings->PrizeWeightCloak = GetCFGSettingInteger(v3, "PrizeWeight", "Cloak", 20);
        if ( arenaSettings->PrizeWeightCloak > 255 )
            arenaSettings->PrizeWeightCloak = -1;

        arenaSettings->PrizeWeightAntiWarp = GetCFGSettingInteger(v3, "PrizeWeight", "AntiWarp", 20);
        if ( arenaSettings->PrizeWeightAntiWarp > 255 )
            arenaSettings->PrizeWeightAntiWarp = -1;

        arenaSettings->PrizeWeightXRadar = GetCFGSettingInteger(v3, "PrizeWeight", "XRadar", 20);
        if ( arenaSettings->PrizeWeightXRadar > 255 )
            arenaSettings->PrizeWeightXRadar = -1;

        arenaSettings->PrizeWeightWarp = GetCFGSettingInteger(v3, "PrizeWeight", "Warp", 40);
        if ( arenaSettings->PrizeWeightWarp > 255 )
            arenaSettings->PrizeWeightWarp = -1;

        arenaSettings->PrizeWeightGun = GetCFGSettingInteger(v3, "PrizeWeight", "Gun", 60);
        if ( arenaSettings->PrizeWeightGun > 255 )
            arenaSettings->PrizeWeightGun = -1;

        arenaSettings->PrizeWeightBomb = GetCFGSettingInteger(v3, "PrizeWeight", "Bomb", 50);
        if ( arenaSettings->PrizeWeightBomb > 255 )
            arenaSettings->PrizeWeightBomb = -1;

        arenaSettings->PrizeWeightBouncingBullets = GetCFGSettingInteger(v3, "PrizeWeight", "BouncingBullets", 30);
        if ( arenaSettings->PrizeWeightBouncingBullets > 255 )
            arenaSettings->PrizeWeightBouncingBullets = -1;

        arenaSettings->PrizeWeightThruster = GetCFGSettingInteger(v3, "PrizeWeight", "Thruster", 70);
        if ( arenaSettings->PrizeWeightThruster > 255 )
            arenaSettings->PrizeWeightThruster = -1;

        arenaSettings->PrizeWeightTopSpeed = GetCFGSettingInteger(v3, "PrizeWeight", "TopSpeed", 70);
        if ( arenaSettings->PrizeWeightTopSpeed > 255 )
            arenaSettings->PrizeWeightTopSpeed = -1;

        arenaSettings->PrizeWeightRecharge = GetCFGSettingInteger(v3, "PrizeWeight", "Recharge", 60);
        if ( arenaSettings->PrizeWeightRecharge > 255 )
            arenaSettings->PrizeWeightRecharge = -1;

        arenaSettings->PrizeWeightMultiFire = GetCFGSettingInteger(v3, "PrizeWeight", "MultiFire", 30);
        if ( arenaSettings->PrizeWeightMultiFire > 255 )
            arenaSettings->PrizeWeightMultiFire = -1;

        arenaSettings->PrizeWeightProximity = GetCFGSettingInteger(v3, "PrizeWeight", "Proximity", 30);
        if ( arenaSettings->PrizeWeightProximity > 255 )
            arenaSettings->PrizeWeightProximity = -1;

        arenaSettings->PrizeWeightGlue = GetCFGSettingInteger(v3, "PrizeWeight", "Glue", 20);
        if ( arenaSettings->PrizeWeightGlue > 255 )
            arenaSettings->PrizeWeightGlue = -1;

        arenaSettings->PrizeWeightAllWeapons = GetCFGSettingInteger(v3, "PrizeWeight", "AllWeapons", 10);
        if ( arenaSettings->PrizeWeightAllWeapons > 255 )
            arenaSettings->PrizeWeightAllWeapons = -1;

        arenaSettings->PrizeWeightShields = GetCFGSettingInteger(v3, "PrizeWeight", "Shields", 10);
        if ( arenaSettings->PrizeWeightShields > 255 )
            arenaSettings->PrizeWeightShields = -1;

        arenaSettings->PrizeWeightShrapnel = GetCFGSettingInteger(v3, "PrizeWeight", "Shrapnel", 40);
        if ( arenaSettings->PrizeWeightShrapnel > 255 )
            arenaSettings->PrizeWeightShrapnel = -1;

        arenaSettings->PrizeWeightRepel = GetCFGSettingInteger(v3, "PrizeWeight", "Repel", 40);
        if ( arenaSettings->PrizeWeightRepel > 255 )
            arenaSettings->PrizeWeightRepel = -1;

        arenaSettings->PrizeWeightBurst = GetCFGSettingInteger(v3, "PrizeWeight", "Burst", 30);
        if ( arenaSettings->PrizeWeightBurst > 255 )
            arenaSettings->PrizeWeightBurst = -1;

        arenaSettings->PrizeWeightDecoy = GetCFGSettingInteger(v3, "PrizeWeight", "Decoy", 20);
        if ( arenaSettings->PrizeWeightDecoy > 255 )
            arenaSettings->PrizeWeightDecoy = -1;

        arenaSettings->PrizeWeightThor = GetCFGSettingInteger(v3, "PrizeWeight", "Thor", 30);
        if ( arenaSettings->PrizeWeightThor > 255 )
            arenaSettings->PrizeWeightThor = -1;

        arenaSettings->PrizeWeightPortal = GetCFGSettingInteger(v3, "PrizeWeight", "Portal", 30);
        if ( arenaSettings->PrizeWeightPortal > 255 )
            arenaSettings->PrizeWeightPortal = -1;

        arenaSettings->PrizeWeightBrick = GetCFGSettingInteger(v3, "PrizeWeight", "Brick", 10);
        if ( arenaSettings->PrizeWeightBrick > 255 )
            arenaSettings->PrizeWeightBrick = -1;

        arenaSettings->PrizeWeightRocket = GetCFGSettingInteger(v3, "PrizeWeight", "Rocket", 10);
        if ( arenaSettings->PrizeWeightRocket > 255 )
            arenaSettings->PrizeWeightRocket = -1;

        arenaSettings->PrizeWeightMultiPrize = GetCFGSettingInteger(v3, "PrizeWeight", "MultiPrize", 20);
        if ( arenaSettings->PrizeWeightMultiPrize > 255 )
            arenaSettings->PrizeWeightMultiPrize = -1;

        const char *Str2[8] = {"Warbird", "Javelin", "Spider", "Leviathan", "Terrier", "Weasel", "Lancaster", "Shark" };

        v51 = 0;
        do
        {
            v33 = (const char *)Str2[v51];
            *(unsigned int *)&arenaSettings->ShipSettings[v51].SuperTime = GetCFGSettingInteger(v3, v33, "SuperTime", 6000);
            *(unsigned int *)&arenaSettings->ShipSettings[v51].ShieldsTime = GetCFGSettingInteger(v3, v33, "ShieldsTime", 4000);
            arenaSettings->ShipSettings[v51].Gravity = GetCFGSettingInteger(v3, v33, "Gravity", 1500);
            arenaSettings->ShipSettings[v51].GravityTopSpeed = GetCFGSettingInteger(v3, v33, "GravityTopSpeed", 100);
            arenaSettings->ShipSettings[v51].BulletFireEnergy = GetCFGSettingInteger(v3, v33, "BulletFireEnergy", 20);
            arenaSettings->ShipSettings[v51].MultiFireEnergy = GetCFGSettingInteger(v3, v33, "MultiFireEnergy", 30);
            arenaSettings->ShipSettings[v51].BombFireEnergy = GetCFGSettingInteger(v3, v33, "BombFireEnergy", 300);
            arenaSettings->ShipSettings[v51].BombFireEnergyUpgrade = GetCFGSettingInteger(v3, v33, "BombFireEnergyUpgrade", 50);
            arenaSettings->ShipSettings[v51].MineFireEnergy = GetCFGSettingInteger(v3, v33, "LandmineFireEnergy", 300);
            arenaSettings->ShipSettings[v51].MineFireEnergyUpgrade = GetCFGSettingInteger(v3, v33, "LandmineFireEnergyUpgrade", 150);
            arenaSettings->ShipSettings[v51].BulletSpeed = GetCFGSettingInteger(v3, v33, "BulletSpeed", 2000);
            arenaSettings->ShipSettings[v51].BombSpeed = GetCFGSettingInteger(v3, v33, "BombSpeed", 2000);
            v34 = -(v51 != 4) & 0xFB;
            arenaSettings->ShipSettings[v51].BulletFireDelay = GetCFGSettingInteger(v3, v33, "BulletFireDelay", v34 + 30);
            arenaSettings->ShipSettings[v51].MultiFireDelay = GetCFGSettingInteger(v3, v33, "MultiFireDelay", 50);
            arenaSettings->ShipSettings[v51].BombFireDelay = GetCFGSettingInteger(v3, v33, "BombFireDelay", 150);
            arenaSettings->ShipSettings[v51].LandmineFireDelay = GetCFGSettingInteger(v3, v33, "LandmineFireDelay", 125);
            arenaSettings->ShipSettings[v51].MultiFireAngleBits2 = GetCFGSettingInteger(v3, v33, "MultiFireAngle", 500);
            v35 = -(v51 != 7) & 0x38;
            arenaSettings->ShipSettings[v51].CloakEnergy = GetCFGSettingInteger(v3, v33, "CloakEnergy", v35 + 300);
            arenaSettings->ShipSettings[v51].StealthEnergy = GetCFGSettingInteger(v3, v33, "StealthEnergy", v51 != 7 ? 333 : 300);
            arenaSettings->ShipSettings[v51].AntiWarpEnergy = GetCFGSettingInteger(v3, v33, "AntiWarpEnergy", 100);
            arenaSettings->ShipSettings[v51].XRadarEnergy = GetCFGSettingInteger(v3, v33, "XRadarEnergy", 250);

            if ( v51 == 7 )
                v48 = 280;
            else if( v51 )
                v48 = 230;
            else
                v48 = 300;
            arenaSettings->ShipSettings[v51].MaximumRotation = GetCFGSettingInteger(v3, v33, "MaximumRotation", v48);
            if ( v51 == 7 )
                v36 = 19;
            else if( !v51 )
                v36 = 17;
            arenaSettings->ShipSettings[v51].MaximumThrust = GetCFGSettingInteger(v3, v33, "MaximumThrust", v36);
            arenaSettings->ShipSettings[v51].MaxmimumSpeed = GetCFGSettingInteger(v3, v33, "MaximumSpeed", v51 != 1 ? 3250 : 3750);
            arenaSettings->ShipSettings[v51].MaximumRecharge = GetCFGSettingInteger(v3, v33, "MaximumRecharge", 1150);
            arenaSettings->ShipSettings[v51].MaximumEnergy = GetCFGSettingInteger(v3, v33, "MaximumEnergy", v51 != 7 ? 1700 : 1750);
            arenaSettings->ShipSettings[v51].InitalRotation = GetCFGSettingInteger(v3, v33, "InitialRotation", v51 != 0 ? 200 : 210);
            arenaSettings->ShipSettings[v51].InitalThrust = GetCFGSettingInteger(v3, v33, "InitialThrust", 16 - (v51 != 0));
            v37 = -(v51 != 1) & 0x42;
            arenaSettings->ShipSettings[v51].InitalSpeed = GetCFGSettingInteger(v3, v33, "InitialSpeed", v37 + 2200);
            arenaSettings->ShipSettings[v51].InitialRecharge = GetCFGSettingInteger(v3, v33, "InitialRecharge", v51 != 2 ? 400 : 500);
            arenaSettings->ShipSettings[v51].InitialEnergy = GetCFGSettingInteger(v3, v33, "InitialEnergy", 1000);
            arenaSettings->ShipSettings[v51].UpgradeRotation = GetCFGSettingInteger(v3, v33, "UpgradeRotation", 40);
            arenaSettings->ShipSettings[v51].UpgradeThrust = GetCFGSettingInteger(v3, v33, "UpgradeThrust", 2);
            arenaSettings->ShipSettings[v51].UpgradeSpeed = GetCFGSettingInteger(v3, v33, "UpgradeSpeed", 250);
            arenaSettings->ShipSettings[v51].UpgradeRecharge = GetCFGSettingInteger(v3, v33, "UpgradeRecharge", 166);
            arenaSettings->ShipSettings[v51].UpgradeEnergy = GetCFGSettingInteger(v3, v33, "UpgradeEnergy", 100);
            arenaSettings->ShipSettings[v51].AfterburnerEnergy = GetCFGSettingInteger(v3, v33, "AfterburnerEnergy", 1200);
            arenaSettings->ShipSettings[v51].BombThrust = GetCFGSettingInteger(v3, v33, "BombThrust", 400);
            arenaSettings->ShipSettings[v51].BurstSpeed = GetCFGSettingInteger(v3, v33, "BurstSpeed", 3000);
            arenaSettings->ShipSettings[v51].BurstShrapnel = GetCFGSettingInteger(v3, v33, "BurstShrapnel", 24);
            arenaSettings->ShipSettings[v51].TurretThrustPenalty = GetCFGSettingInteger(v3, v33, "TurretThrustPenalty", 1);
            arenaSettings->ShipSettings[v51].TurretSpeedPenalty = GetCFGSettingInteger(v3, v33, "TurretSpeedPenalty", 125);
            arenaSettings->ShipSettings[v51].TurretLimit = GetCFGSettingInteger(v3, v33, "TurretLimit", 5);
            arenaSettings->ShipSettings[v51].RocketTime = GetCFGSettingInteger(v3, v33, "RocketTime", 1000);
            arenaSettings->ShipSettings[v51].InitialBounty = GetCFGSettingInteger(v3, v33, "InitialBounty", 0);
            arenaSettings->ShipSettings[v51].MaxMines = GetCFGSettingInteger(v3, v33, "MaxMines", 5);
            arenaSettings->ShipSettings[v51].RepelMax = GetCFGSettingInteger(v3, v33, "RepelMax", 3);
            arenaSettings->ShipSettings[v51].BurstMax = GetCFGSettingInteger(v3, v33, "BurstMax", 3);
            arenaSettings->ShipSettings[v51].DecoyMax = GetCFGSettingInteger(v3, v33, "DecoyMax", 3);
            arenaSettings->ShipSettings[v51].ThorMax = GetCFGSettingInteger(v3, v33, "ThorMax", 3);
            arenaSettings->ShipSettings[v51].BrickMax = GetCFGSettingInteger(v3, v33, "BrickMax", 3);
            arenaSettings->ShipSettings[v51].RocketMax = GetCFGSettingInteger(v3, v33, "RocketMax", 3);
            arenaSettings->ShipSettings[v51].PortalMax = GetCFGSettingInteger(v3, v33, "PortalMax", 3);
            arenaSettings->ShipSettings[v51].InitialRepel = GetCFGSettingInteger(v3, v33, "InitialRepel", 0);
            arenaSettings->ShipSettings[v51].InitialBurst = GetCFGSettingInteger(v3, v33, "InitialBurst", 0);
            arenaSettings->ShipSettings[v51].InitialBrick = GetCFGSettingInteger(v3, v33, "InitialBrick", 0);
            arenaSettings->ShipSettings[v51].InitialRocket = GetCFGSettingInteger(v3, v33, "InitialRocket", 0);
            arenaSettings->ShipSettings[v51].InitialThor = GetCFGSettingInteger(v3, v33, "InitialThor", 0);
            arenaSettings->ShipSettings[v51].InitialDecoy = GetCFGSettingInteger(v3, v33, "InitialDecoy", v51 == 2);
            arenaSettings->ShipSettings[v51].InitialPortal = GetCFGSettingInteger(v3, v33, "InitialPortal", 0);
            arenaSettings->ShipSettings[v51].BombBounceCount = GetCFGSettingInteger(v3, v33, "BombBounceCount", v51 == 6);
            //Lots of BitField stuff going on here.
            arenaSettings->ShipSettings[v51].LotsOfBitFields = ((GetCFGSettingInteger(v3, v33, "CloakStatus", (v51 == 2 || v51 == 7)) & 3) << 10) | arenaSettings->ShipSettings[v51].LotsOfBitFields & 0xF3;
            arenaSettings->ShipSettings[v51].LotsOfBitFields = ((GetCFGSettingInteger(v3, v33, "StealthStatus", (v51 == 2) + 1) & 3) << 12) | arenaSettings->ShipSettings[v51].LotsOfBitFields & 0xCF;
            arenaSettings->ShipSettings[v51].LotsOfBitFields = ((GetCFGSettingInteger(v3, v33, "XRadarStatus", 1) & 3) << 14) | arenaSettings->ShipSettings[v51].LotsOfBitFields & 0x3F;
            arenaSettings->ShipSettings[v51].LotsOfBitFields = ((GetCFGSettingInteger(v3, v33, "AntiWarpStatus", 1) & 3) << 16) | arenaSettings->ShipSettings[v51].LotsOfBitFields & 0xFFFCFFFF;
            arenaSettings->ShipSettings[v51].DamageFactor = GetCFGSettingInteger(v3, v33, "DamageFactor", 30);
            arenaSettings->ShipSettings[v51].PrizeShareLimit = GetCFGSettingInteger(v3, v33, "PrizeShareLimit", 100);
            arenaSettings->ShipSettings[v51].AttachBounty = GetCFGSettingInteger(v3, v33, "AttachBounty", 12);
            arenaSettings->ShipSettings[v51].LotsOfBitFields ^= ((unsigned char)GetCFGSettingInteger(v3, v33, "ShrapnelMax", v51 != 5 ? 8 : 0) ^ (unsigned char)arenaSettings->ShipSettings[v51].LotsOfBitFields) & 0x1F;
            arenaSettings->ShipSettings[v51].LotsOfBitFields = 32 * (GetCFGSettingInteger(v3, v33, "ShrapnelRate", 2) & 0x1F) | arenaSettings->ShipSettings[v51].LotsOfBitFields & 0xFFFFFC1F;
            arenaSettings->ShipSettings[v51].LotsOfBitFields = ((GetCFGSettingInteger(v3, v33, "MaxGuns", 3) & 3) << 20) | arenaSettings->ShipSettings[v51].LotsOfBitFields & 0xFFCFFFFF;
            arenaSettings->ShipSettings[v51].LotsOfBitFields = ((GetCFGSettingInteger(v3, v33, "MaxBombs", (v51 == 3) + 2) & 3) << 24) | arenaSettings->ShipSettings[v51].LotsOfBitFields & 0xFCFFFFFF;
            arenaSettings->ShipSettings[v51].LotsOfBitFields = ((GetCFGSettingInteger(v3, v33, "InitialGuns", (v51 == 4) + 1) & 3) << 18) | arenaSettings->ShipSettings[v51].LotsOfBitFields & 0xFFF3FFFF;
            arenaSettings->ShipSettings[v51].LotsOfBitFields = ((GetCFGSettingInteger(v3, v33, "InitialBombs", (v51 == 3 || v51 == 5)) & 3) << 22) | arenaSettings->ShipSettings[v51].LotsOfBitFields & 0xFF3FFFFF;
            arenaSettings->ShipSettings[v51].LotsOfBitFields = ((GetCFGSettingInteger(v3, v33, "EmpBomb", v51 == 5) & 1) << 27) | arenaSettings->ShipSettings[v51].LotsOfBitFields & 0xF7FFFFFF;
            arenaSettings->ShipSettings[v51].LotsOfBitFields = ((GetCFGSettingInteger(v3, v33, "SeeMines", v51 == 5) & 1) << 28) | arenaSettings->ShipSettings[v51].LotsOfBitFields & 0xEFFFFFFF;
            arenaSettings->ShipSettings[v51].LotsOfBitFields = ((GetCFGSettingInteger(v3, v33, "DoubleBarrel", v51 == 4) & 1) << 26) | arenaSettings->ShipSettings[v51].LotsOfBitFields & 0xFBFFFFFF;
            arenaSettings->ShipSettings[v51].SoccerBallFriction = GetCFGSettingInteger(v3, v33, "SoccerBallFriction", 12);
            arenaSettings->ShipSettings[v51].SoccerBallProximity = GetCFGSettingInteger(v3, v33, "SoccerBallProximity", 64);
            arenaSettings->ShipSettings[v51].SoccerThrowTime = GetCFGSettingInteger(v3, v33, "SoccerThrowTime", 1200);
            arenaSettings->ShipSettings[v51++].SoccerBallSpeed = GetCFGSettingInteger(v3, v33, "SoccerBallSpeed", 2500);
        }
        while ( v51 < 8 );

        arenaSettings->BulletDamageLevel = 1000 * GetCFGSettingInteger(v3, "Bullet", "BulletDamageLevel", 200);
        arenaSettings->BulletDamageUpgrade = 1000 * GetCFGSettingInteger(v3, "Bullet", "BulletDamageUpgrade", 100);
        arenaSettings->BulletAliveTime = GetCFGSettingInteger(v3, "Bullet", "BulletAliveTime", 550);
        arenaSettings->BombDamageLevel = 1000 * GetCFGSettingInteger(v3, "Bomb", "BombDamageLevel", 750);
        arenaSettings->BombAliveTime = GetCFGSettingInteger(v3, "Bomb", "BombAliveTime", 6000);
        arenaSettings->BombExplodeDelay = GetCFGSettingInteger(v3, "Bomb", "BombExplodeDelay", 150);
        arenaSettings->BombExplodePixels = GetCFGSettingInteger(v3, "Bomb", "BombExplodePixels", 80);
        arenaSettings->ProximityDistance = GetCFGSettingInteger(v3, "Bomb", "ProximityDistance", 3);
        arenaSettings->JitterTime = GetCFGSettingInteger(v3, "Bomb", "JitterTime", 72);
        arenaSettings->BombSafety = GetCFGSettingInteger(v3, "Bomb", "BombSafety", 1);
        arenaSettings->EBombShutdownTime = GetCFGSettingInteger(v3, "Bomb", "EBombShutdownTime", 400);
        arenaSettings->EBombDamagePercent = GetCFGSettingInteger(v3, "Bomb", "EBombDamagePercent", 1000);
        arenaSettings->BBombDamagePercent = GetCFGSettingInteger(v3, "Bomb", "BBombDamagePercent", 1000);
        arenaSettings->MineAliveTime = GetCFGSettingInteger(v3, "Mine", "MineAliveTime", 12000);
        arenaSettings->TeamMaxMines = GetCFGSettingInteger(v3, "Mine", "TeamMaxMines", 12);
        arenaSettings->ShrapnelSpeed = GetCFGSettingInteger(v3, "Shrapnel", "ShrapnelSpeed", 3000);
        arenaSettings->InactiveShrapnelDamage = 1000 * GetCFGSettingInteger(v3, "Shrapnel", "InactiveShrapDamage", 3);
        arenaSettings->ShrapnelDamagePercent = GetCFGSettingInteger(v3, "Shrapnel", "ShrapnelDamagePercent", 1000);
        arenaSettings->RandomShrapnel = GetCFGSettingInteger(v3, "Shrapnel", "Random", 1);
        arenaSettings->BurstDamageLevel = 1000 * GetCFGSettingInteger(v3, "Burst", "BurstDamageLevel", 515);
        arenaSettings->AntiwarpPixels = GetCFGSettingInteger(v3, "Toggle", "AntiWarpPixels", 1500);
        arenaSettings->MultiPrizeCount = GetCFGSettingInteger(v3, "Prize", "MultiPrizeCount", 10);
        arenaSettings->PrizeFactor = GetCFGSettingInteger(v3, "Prize", "PrizeFactor", 1000);
        arenaSettings->PrizeDelay = GetCFGSettingInteger(v3, "Prize", "PrizeDelay", 300);
        arenaSettings->PrizeHideCount = GetCFGSettingInteger(v3, "Prize", "PrizeHideCount", 30);
        arenaSettings->PrizeMinimumVirtual = GetCFGSettingInteger(v3, "Prize", "MinimumVirtual", 256);
        arenaSettings->PrizeUpgradeVirtual = GetCFGSettingInteger(v3, "Prize", "UpgradeVirtual", 6);
        arenaSettings->PrizeMaxExist = GetCFGSettingInteger(v3, "Prize", "PrizeMaxExist", 8000);
        arenaSettings->PrizeMinExist = GetCFGSettingInteger(v3, "Prize", "PrizeMinExist", 4000);
        arenaSettings->PrizeNegativeFactor = GetCFGSettingInteger(v3, "Prize", "PrizeNegativeFactor", 300);
        arenaSettings->DeathPrizeTime = GetCFGSettingInteger(v3, "Prize", "DeathPrizeTime", 800);
        arenaSettings->EngineShutdownTime = GetCFGSettingInteger(v3, "Prize", "EngineShutdownTime", 700);
        arenaSettings->TakePrizeReliable = GetCFGSettingInteger(v3, "Prize", "TakePrizeReliable", 0);
        arenaSettings->FlaggerOnRadar = GetCFGSettingInteger(v3, "Flag", "FlaggerOnRadar", 1);
        arenaSettings->FlaggerKillMultiplier = GetCFGSettingInteger(v3, "Flag", "FlaggerKillMultiplier", 2);
        arenaSettings->FlaggerGunUpgrade = GetCFGSettingInteger(v3, "Flag", "FlaggerGunUpgrade", 0);
        arenaSettings->FlaggerBombUpgrade = GetCFGSettingInteger(v3, "Flag", "FlaggerBombUpgrade", 0);
        arenaSettings->FlaggerFireCostPercent = GetCFGSettingInteger(v3, "Flag", "FlaggerFireCostPercent", 1000);
        arenaSettings->FlaggerDamagePercent = GetCFGSettingInteger(v3, "Flag", "FlaggerDamagePercent", 1000);
        arenaSettings->FlaggerBombFireDelay = GetCFGSettingInteger(v3, "Flag", "FlaggerBombFireDelay", 0);
        arenaSettings->FlaggerSpeedAdjustment = GetCFGSettingInteger(v3, "Flag", "FlaggerSpeedAdjustment", 0);
        arenaSettings->FlaggerThrustAdjustment = GetCFGSettingInteger(v3, "Flag", "FlaggerThrustAdjustment", 0);
        arenaSettings->CarryFlags = GetCFGSettingInteger(v3, "Flag", "CarryFlags", 1);
        arenaSettings->FlagDropDelay = GetCFGSettingInteger(v3, "Flag", "FlagDropDelay", 0);
        arenaSettings->FlagDropResetReward = GetCFGSettingInteger(v3, "Flag", "FlagDropResetReward", 0);
        arenaSettings->EnterGameFlaggingDelay = GetCFGSettingInteger(v3, "Flag", "EnterGameFlaggingDelay", 12000);
        arenaSettings->FlagBlankDelay = GetCFGSettingInteger(v3, "Flag", "FlagBlankDelay", 200);
        arenaSettings->NoDataFlagDropDelay = GetCFGSettingInteger(v3, "Flag", "NoDataFlagDropDelay", 500);
        arenaSettings->SoccerBallBounce = GetCFGSettingInteger(v3, "Soccer", "BallBounce", 1);
        arenaSettings->SoccerAllowBombs = GetCFGSettingInteger(v3, "Soccer", "AllowBombs", 1);
        arenaSettings->SoccerAllowGuns = GetCFGSettingInteger(v3, "Soccer", "AllowGuns", 1);
        arenaSettings->SoccerPassDelay = GetCFGSettingInteger(v3, "Soccer", "PassDelay", 20);
        arenaSettings->SoccerMode = GetCFGSettingInteger(v3, "Soccer", "Mode", 1);
        arenaSettings->SoccerBallBlankDelay = GetCFGSettingInteger(v3, "Soccer", "BallBlankDelay", 200);
        arenaSettings->SoccerUseFlagger = GetCFGSettingInteger(v3, "Soccer", "UseFlagger", 0);
        arenaSettings->SoccerBallLocation = GetCFGSettingInteger(v3, "Soccer", "BallLocation", 0);
        arenaSettings->RadarMode = GetCFGSettingInteger(v3, "Radar", "RadarMode", 0);
        arenaSettings->RadarNeutralSize = GetCFGSettingInteger(v3, "Radar", "RadarNeutralSize", 128);
        arenaSettings->MapZoomFactor = GetCFGSettingInteger(v3, "Radar", "MapZoomFactor", 10);
        arenaSettings->MaxFrequency = GetCFGSettingInteger(v3, "Team", "MaxFrequency", 9999);
        arenaSettings->MaxPerTeam = GetCFGSettingInteger(v3, "Team", "MaxPerTeam", 6);
        arenaSettings->MaxPerPrivateTeam = GetCFGSettingInteger(v3, "Team", "MaxPerPrivateTeam", 0);
        arenaSettings->MaxBonus = GetCFGSettingInteger(v3, "Kill", "MaxBonus", 0);
        arenaSettings->MaxPenalty = GetCFGSettingInteger(v3, "Kill", "MaxPenalty", 0);
        arenaSettings->RewardBase = GetCFGSettingInteger(v3, "Kill", "RewardBase", 0);
        arenaSettings->BountyIncreaseForKill = GetCFGSettingInteger(v3, "Kill", "BountyIncreaseForKill", 6);
        arenaSettings->EnterDelay = GetCFGSettingInteger(v3, "Kill", "EnterDelay", 200);
        arenaSettings->RepelSpeed = GetCFGSettingInteger(v3, "Repel", "RepelSpeed", 5000);
        arenaSettings->RepelTime = GetCFGSettingInteger(v3, "Repel", "RepelTime", 225);
        arenaSettings->RepelDistance = GetCFGSettingInteger(v3, "Repel", "RepelDistance", 512);
        arenaSettings->MessageReliable = GetCFGSettingInteger(v3, "Message", "MessageReliable", 0);
        arenaSettings->AllowAudioMessages = GetCFGSettingInteger(v3, "Message", "AllowAudioMessages", 1);
        arenaSettings->WormholeGravityBombs = GetCFGSettingInteger(v3, "Wormhole", "GravityBombs", 1);
        arenaSettings->WormholeSwitchTime = GetCFGSettingInteger(v3, "Wormhole", "SwitchTime", 0);
        arenaSettings->SendRoutePercent = GetCFGSettingInteger(v3, "Latency", "SendRoutePercent", 500);
        arenaSettings->ClientSlowPacketSampleSize = GetCFGSettingInteger(v3, "Latency", "ClientSlowPacketSampleSize", 100);
        arenaSettings->BrickTime = GetCFGSettingInteger(v3, "Brick", "BrickTime", 12000);
        arenaSettings->RocketThrust = GetCFGSettingInteger(v3, "Rocket", "RocketThrust", 25);
        arenaSettings->RocketSpeed = GetCFGSettingInteger(v3, "Rocket", "RocketSpeed", 5500);
        arenaSettings->DoorDelay = GetCFGSettingInteger(v3, "Door", "DoorDelay", 400);
        arenaSettings->DoorMode = GetCFGSettingInteger(v3, "Door", "DoorMode", -1);
        arenaSettings->WarpPointDelay = GetCFGSettingInteger(v3, "Misc", "WarpPointDelay", 6000);
        arenaSettings->DecoyAliveTime = GetCFGSettingInteger(v3, "Misc", "DecoyAliveTime", 3000);
        arenaSettings->BounceFactor = GetCFGSettingInteger(v3, "Misc", "BounceFactor", 22);
        arenaSettings->SendPositionDelay = GetCFGSettingInteger(v3, "Misc", "SendPositionDelay", 10);
        arenaSettings->SlowFrameCheck = GetCFGSettingInteger(v3, "Misc", "SlowFrameCheck", 0);
        arenaSettings->AllowSavedShip = GetCFGSettingInteger(v3, "Misc", "AllowSavedShips", 1);
        arenaSettings->SafetyLimit = GetCFGSettingInteger(v3, "Misc", "SafetyLimit", 90000);
        arenaSettings->FrequencyShift = GetCFGSettingInteger(v3, "Misc", "FrequencyShift", 900);
        arenaSettings->HelpTickerDelay = GetCFGSettingInteger(v3, "Misc", "TickerDelay", 1000);
        arenaSettings->ExtraPositionData = GetCFGSettingInteger(v3, "Misc", "ExtraPositionData", 0);
        arenaSettings->WarpRadiusLimit = GetCFGSettingInteger(v3, "Misc", "WarpRadiusLimit", 1024);
        arenaSettings->ActivateAppShutdownTime = GetCFGSettingInteger(v3, "Misc", "ActivateAppShutdownTime", 1500);
        arenaSettings->NearDeathLevel = GetCFGSettingInteger(v3, "Misc", "NearDeathLevel", 0);
        arenaSettings->VictoryMusic = GetCFGSettingInteger(v3, "Misc", "VictoryMusic", 1);
        arenaSettings->ClientSlowPacketTime = GetCFGSettingInteger(v3, "Latency", "ClientSlowPacketTime", 40);
        arenaSettings->S2CNoDataKickoutDelay = GetCFGSettingInteger(v3, "Latency", "S2CNoDataKickoutDelay", 500);
    }
    if ( serverArenaSettings )
    {
        serverArenaSettings->CustomSaveStatsTime = GetCFGSettingInteger(v3, "Custom", "SaveStatsTime", 720000);
        serverArenaSettings->TerritoryRewardDelay = GetCFGSettingInteger(v3, "Territory", "RewardDelay", 60000);
        serverArenaSettings->TerritoryRewardBaseFlags = GetCFGSettingInteger(v3, "Territory", "RewardBaseFlags", 8);
        serverArenaSettings->TerritoryRewardMinimumPlayers = GetCFGSettingInteger(v3, "Territory", "RewardMinimumPlayers", 5);
        serverArenaSettings->TerritoryRewardPoints = GetCFGSettingInteger(v3, "Territory", "RewardPoints", 30);
        serverArenaSettings->PeriodicRewardDelay = GetCFGSettingInteger(v3, "Periodic", "RewardDelay", 0);
        serverArenaSettings->PeriodicRewardMinimumPlayers = GetCFGSettingInteger(v3, "Periodic", "RewardMinimumPlayers", 16);
        serverArenaSettings->PeriodicRewardPoints = GetCFGSettingInteger(v3, "Periodic", "RewardPoints", 50);
        serverArenaSettings->FlagMode = GetCFGSettingInteger(v3, "Flag", "FlagMode", 0);
        serverArenaSettings->FlagResetDelay = GetCFGSettingInteger(v3, "Flag", "FlagResetDelay", 1440000);
        serverArenaSettings->MaxFlags = GetCFGSettingInteger(v3, "Flag", "MaxFlags", 16);
        serverArenaSettings->RandomFlags = GetCFGSettingInteger(v3, "Flag", "RandomFlags", 0);
        serverArenaSettings->FlagReward = GetCFGSettingInteger(v3, "Flag", "FlagReward", 1000);
        serverArenaSettings->FlagRewardMode = GetCFGSettingInteger(v3, "Flag", "FlagRewardMode", 0);
        serverArenaSettings->FlagTerritoryRadius = GetCFGSettingInteger(v3, "Flag", "FlagTerritoryRadius", 8);
        serverArenaSettings->FlagTerritoryRadiusCentroid = GetCFGSettingInteger(v3, "Flag", "FlagTerritoryRadiusCentroid", 0);
        serverArenaSettings->FlagFriendlyTransfer = GetCFGSettingInteger(v3, "Flag", "FriendlyTransfer", 1);
        serverArenaSettings->KillPointsPerFlag = GetCFGSettingInteger(v3, "Kill", "KillPointsPerFlag", 0);
        serverArenaSettings->KillPointsMinimumBounty = GetCFGSettingInteger(v3, "Kill", "KillPointsMinimumBounty", 50);
        serverArenaSettings->KillDebtKills = GetCFGSettingInteger(v3, "Kill", "DebtKills", 0);
        serverArenaSettings->KillNoRewardKillDelay = GetCFGSettingInteger(v3, "Kill", "NoRewardKillDelay", 0);
        serverArenaSettings->KillBountyRewardPercent = GetCFGSettingInteger(v3, "Kill", "BountyRewardPercent", 0);
        serverArenaSettings->KillFixedKillReward = GetCFGSettingInteger(v3, "Kill", "FixedKillReward", -1);
        serverArenaSettings->KillJackpotBountyPercent = GetCFGSettingInteger(v3, "Kill", "JackpotBountyPercent", 0);
        serverArenaSettings->TeamForceEvenTeams = GetCFGSettingInteger(v3, "Team", "ForceEvenTeams", 0);
        serverArenaSettings->TeamDesiredTeams = GetCFGSettingInteger(v3, "Team", "DesiredTeams", 2);
        serverArenaSettings->TeamSpectatorFrequency = GetCFGSettingInteger(v3, "Team", "SpectatorFrequency", 8025);
        serverArenaSettings->BrickSpan = GetCFGSettingInteger(v3, "Brick", "BrickSpan", 7);
        serverArenaSettings->MiscFrequencyShipTypes = GetCFGSettingInteger(v3, "Misc", "FrequencyShipTypes", 0);
        serverArenaSettings->MiscBannerPoints = GetCFGSettingInteger(v3, "Misc", "BannerPoints", 5000);
        serverArenaSettings->MiscMaxLossesToPlay = GetCFGSettingInteger(v3, "Misc", "MaxLossesToPlay", 0);
        serverArenaSettings->MiscSpectatorQuiet = GetCFGSettingInteger(v3, "Misc", "SpectatorQuiet", 0);
        serverArenaSettings->MiscTimedGame = GetCFGSettingInteger(v3, "Misc", "TimedGame", 0);
        GetCFGSettingString(v3, "Misc", "SheepMessage", "Sheep successfully cloned -- hello Dolly", serverArenaSettings->MiscSheepMessage, 0x100);
        serverArenaSettings->MiscResetScoreOnFrequencyChange = GetCFGSettingInteger(v3, "Misc", "ResetScoreOnFrequencyChange", 0);
        serverArenaSettings->MiscMaxPlaying = GetCFGSettingInteger(v3, "Misc", "MaxPlaying", 0);
        serverArenaSettings->MessageBongAllowed = GetCFGSettingInteger(v3, "Message", "BongAllowed", 0);
        serverArenaSettings->MessageQuickMessageLimit = GetCFGSettingInteger(v3, "Message", "QuickMessageLimit", 8);
        serverArenaSettings->MessageReliable = GetCFGSettingInteger(v3, "Message", "MessageReliable", 0);
        serverArenaSettings->MessageTeamReliable = GetCFGSettingInteger(v3, "Message", "MessageTeamReliable", 1);
        serverArenaSettings->MessageDistance = GetCFGSettingInteger(v3, "Message", "MessageDistance", 17000);
        serverArenaSettings->dwordB4 = 1;
        serverArenaSettings->SecurityS2CKickOutPercentWeapons = GetCFGSettingInteger(v3, "Security", "S2CKickOutPercentWeapons", 700);
        serverArenaSettings->SecuritySuicideLimit = GetCFGSettingInteger(v3, "Security", "SuicideLimit", 10);
        serverArenaSettings->SecurityMaxShipTypeSwitchCount = GetCFGSettingInteger(v3, "Security", "MaxShipTypeSwitchCount", 40);
        serverArenaSettings->SecurityPacketModificationMax = GetCFGSettingInteger(v3, "Security", "PacketModificationMax", 3);
        serverArenaSettings->SecurityMaxDeathWithoutFiring = GetCFGSettingInteger(v3, "Security", "MaxDeathWithoutFiring", 5);
        serverArenaSettings->PacketLossC2SKickOutPercent = GetCFGSettingInteger(v3, "PacketLoss", "C2SKickOutPercent", 800);
        serverArenaSettings->PacketLossC2SNegativeKickOutPercent = GetCFGSettingInteger(v3, "PacketLoss", "C2SNegativeKickOutPercent", 50);
        serverArenaSettings->PacketLossS2CKickOutPercent = GetCFGSettingInteger(v3, "PacketLoss", "S2CKickOutPercent", 800);
        serverArenaSettings->PacketLossSpectatorPercentAdjust = GetCFGSettingInteger(v3, "PacketLoss", "SpectatorPercentAdjust", 100);
        serverArenaSettings->PacketLossDisableWeapons = GetCFGSettingInteger(v3, "PacketLoss", "PacketLossDisableWeapons", 1);
        serverArenaSettings->LatencyKickOutDelay = GetCFGSettingInteger(v3, "Latency", "KickOutDelay", 1000);
        serverArenaSettings->LatencyNoFlagDelay = GetCFGSettingInteger(v3, "Latency", "NoFlagDelay", 300);
        serverArenaSettings->LatencyNoFlagPenalty = GetCFGSettingInteger(v3, "Latency", "NoFlagPenalty", 1000);
        serverArenaSettings->LatencySlowPacketKickoutPercent = GetCFGSettingInteger(v3, "Latency", "SlowPacketKickoutPercent", 200);
        serverArenaSettings->LatencyClientSlowPacketKickoutPercent = GetCFGSettingInteger(v3, "Latency", "ClientSlowPacketKickoutPercent", 200);
        serverArenaSettings->LatencySlowPacketTime = GetCFGSettingInteger(v3, "Latency", "SlowPacketTime", 50);
        serverArenaSettings->LatencySlowPacketSampleSize = GetCFGSettingInteger(v3, "Latency", "SlowPacketSampleSize", 300);
        serverArenaSettings->LatencyMaxLatencyForWeapons = GetCFGSettingInteger(v3, "Latency", "MaxLatencyForWeapons", 45);
        serverArenaSettings->LatencyMaxLatencyForPrizes = GetCFGSettingInteger(v3, "Latency", "MaxLatencyForPrizes", 80);
        serverArenaSettings->LatencyMaxLatencyForKickOut = GetCFGSettingInteger(v3, "Latency", "MaxLatencyForKickOut", 120);
        serverArenaSettings->LatencyKickOutTime = GetCFGSettingInteger(v3, "Latency", "LatencyKickOutTime", 2200);
        serverArenaSettings->LatencyCutbackWatermark = GetCFGSettingInteger(v3, "Latency", "CutbackWatermark", 2400);
        serverArenaSettings->PrizeS2CTakePrizeReliable = GetCFGSettingInteger(v3, "Prize", "S2CTakePrizeReliable", 0);
        serverArenaSettings->RoutingRadarFavor = GetCFGSettingInteger(v3, "Routing", "RadarFavor", 3);
        serverArenaSettings->RoutingCloseEnoughBulletAdjust = GetCFGSettingInteger(v3, "Routing", "CloseEnoughBulletAdjust", 512);
        serverArenaSettings->RoutingCloseEnoughBombAdjust = GetCFGSettingInteger(v3, "Routing", "CloseEnoughBombAdjust", 2048);
        serverArenaSettings->RoutingDeathDistance = GetCFGSettingInteger(v3, "Routing", "DeathDistance", 2800);
        serverArenaSettings->RoutingDoubleSendPercent = GetCFGSettingInteger(v3, "Routing", "DoubleSendPercent", 880);
        serverArenaSettings->RoutingWallResendCount = GetCFGSettingInteger(v3, "Routing", "WallResendCount", 2);
        serverArenaSettings->SoccerBallCount = GetCFGSettingInteger(v3, "Soccer", "BallCount", 0);
        serverArenaSettings->SoccerSendTime = GetCFGSettingInteger(v3, "Soccer", "SendTime", 200);
        serverArenaSettings->SoccerReward = GetCFGSettingInteger(v3, "Soccer", "Reward", 1000);
        serverArenaSettings->SoccerCapturePoints = GetCFGSettingInteger(v3, "Soccer", "CapturePoints", 0);
        serverArenaSettings->SoccerCatchMinimum = GetCFGSettingInteger(v3, "Soccer", "CatchMinimum", 12);
        serverArenaSettings->SoccerCatchPoints = GetCFGSettingInteger(v3, "Soccer", "CatchPoints", 0);
        serverArenaSettings->SoccerWinBy = GetCFGSettingInteger(v3, "Soccer", "WinBy", 0);
        serverArenaSettings->KingDeathCount = GetCFGSettingInteger(v3, "King", "DeathCount", 0);
        serverArenaSettings->KingExpireTime = GetCFGSettingInteger(v3, "King", "ExpireTime", 30000);
        serverArenaSettings->KingRewardFactor = GetCFGSettingInteger(v3, "King", "RewardFactor", 1000);
        serverArenaSettings->KingNonCrownAdjustTime = GetCFGSettingInteger(v3, "King", "NonCrownAdjustTime", 3000);
        serverArenaSettings->KingNonCrownMinimumBounty = GetCFGSettingInteger(v3, "King", "NonCrownMinimumBounty", 100);
        serverArenaSettings->KingCrownRecoverKills = GetCFGSettingInteger(v3, "King", "CrownRecoverKills", 3);

        memset(serverArenaSettings->BuySettings, 0, sizeof(serverArenaSettings->BuySettings));
        strcpy(serverArenaSettings->BuySettings[0].ItemName, "Recharge");
        serverArenaSettings->BuySettings[0].ItemId = 1;
        strcpy(serverArenaSettings->BuySettings[1].ItemName, "Energy");
        serverArenaSettings->BuySettings[1].ItemId = 2;
        strcpy(serverArenaSettings->BuySettings[2].ItemName, "Rotation");
        serverArenaSettings->BuySettings[2].ItemId = 3;
        strcpy(serverArenaSettings->BuySettings[3].ItemName, "Stealth");
        serverArenaSettings->BuySettings[3].ItemId = 4;
        strcpy(serverArenaSettings->BuySettings[4].ItemName, "Cloak");
        serverArenaSettings->BuySettings[4].ItemId = 5;
        strcpy(serverArenaSettings->BuySettings[5].ItemName, "XRadar");
        serverArenaSettings->BuySettings[5].ItemId = 6;
        strcpy(serverArenaSettings->BuySettings[6].ItemName, "Gun");
        serverArenaSettings->BuySettings[6].ItemId = 8;
        strcpy(serverArenaSettings->BuySettings[7].ItemName, "Bomb");
        serverArenaSettings->BuySettings[7].ItemId = 9;
        strcpy(serverArenaSettings->BuySettings[8].ItemName, "Bounce");
        serverArenaSettings->BuySettings[8].ItemId = 10;
        strcpy(serverArenaSettings->BuySettings[9].ItemName, "Thrust");
        serverArenaSettings->BuySettings[9].ItemId = 11;
        strcpy(serverArenaSettings->BuySettings[10].ItemName, "Speed");
        serverArenaSettings->BuySettings[10].ItemId = 12;
        strcpy(serverArenaSettings->BuySettings[11].ItemName, "MultiFire");
        serverArenaSettings->BuySettings[11].ItemId = 15;
        strcpy(serverArenaSettings->BuySettings[12].ItemName, "Prox");
        serverArenaSettings->BuySettings[12].ItemId = 16;
        strcpy(serverArenaSettings->BuySettings[13].ItemName, "Super");
        serverArenaSettings->BuySettings[13].ItemId = 17;
        strcpy(serverArenaSettings->BuySettings[14].ItemName, "Shield");
        serverArenaSettings->BuySettings[14].ItemId = 18;
        strcpy(serverArenaSettings->BuySettings[15].ItemName, "Shrap");
        serverArenaSettings->BuySettings[15].ItemId = 19;
        strcpy(serverArenaSettings->BuySettings[16].ItemName, "AntiWarp");
        serverArenaSettings->BuySettings[16].ItemId = 20;
        strcpy(serverArenaSettings->BuySettings[17].ItemName, "Repel");
        serverArenaSettings->BuySettings[17].ItemId = 21;
        strcpy(serverArenaSettings->BuySettings[18].ItemName, "Burst");
        serverArenaSettings->BuySettings[18].ItemId = 22;
        strcpy(serverArenaSettings->BuySettings[19].ItemName, "Decoy");
        serverArenaSettings->BuySettings[19].ItemId = 23;
        strcpy(serverArenaSettings->BuySettings[20].ItemName, "Thor");
        serverArenaSettings->BuySettings[20].ItemId = 24;
        strcpy(serverArenaSettings->BuySettings[21].ItemName, "Brick");
        serverArenaSettings->BuySettings[21].ItemId = 26;
        strcpy(serverArenaSettings->BuySettings[22].ItemName, "Rocket");
        serverArenaSettings->BuySettings[22].ItemId = 27;
        strcpy(serverArenaSettings->BuySettings[23].ItemName, "Portal");
        serverArenaSettings->BuySettings[23].ItemId = 28;

        v47 = 23;
        do
        {
            serverArenaSettings->BuySettings[v47].ItemPrice = GetCFGSettingInteger(v3, "Cost", serverArenaSettings->BuySettings[v47].ItemName, 0);
            --v47;
        }
        while ( v47 >= 0 );

        serverArenaSettings->CostPurchaseAnytime = GetCFGSettingInteger(v3, "Cost", "PurchaseAnytime", 0);
        serverArenaSettings->OwnerUserId = GetCFGSettingInteger(v3, "Owner", "UserId", -1);
        GetCFGSettingString(v3, "Owner", "Name", "None", serverArenaSettings->OwnerName, 0x20);
    }
    if ( v3 )
    {
        WriteCompleteSettings(v3);
        free(v3);
    }
}

//----- (00411D70) --------------------------------------------------------
char __cdecl SoccerRelatedMath(int SoccerMode, int a2, signed int a3)
{
    int v3; // eax@2

    switch ( SoccerMode )
    {
    case 1:
        return (a2 >= 512) ? 1 : 0;
        break;
    case 2:
        return (a3 >= 512) ? 1 : 0;
        break;
    case 3:
    case 4:
        if ( a2 >= 512 )
            return (a3 >= 512) ? 3 : 1;
        else
            return (a3 >= 512) ? 2 : 0;
        break;
    case 5:
    case 6:
        if ( a2 >= a3 )
            return (a2 >= 1024 - a3) ? 3 : 2;
        else
            return (a2 >= 1024 - a3) ? 1 : 0;
        break;
    default:
        return 0;
        break;
    }
}

// 408300: using guessed type int nullsub_1(void);
// 42C840: using guessed type int UseBillingServer;
// 437CA8: using guessed type int IsServerRunning;

//----- (00412060) --------------------------------------------------------
void __cdecl ServerInitialize()
{
    int v0; // eax@3
    int v1; // edi@3
    struct ARENA **v2; // esi@4
    int v3; // ebp@15
    struct SERVER_BIG_ARRAY *v4; // eax@15
    int v5; // edi@15
    signed int v6; // ecx@15
    bool v7; // zf@17
    signed int v8; // ecx@18
    const void *v9; // esi@18
    const char *v10; // edi@18
    unsigned int v11; // edx@18
    signed int v12; // ecx@18
    int v13; // edi@23
    signed int v14; // ecx@23
    signed int v15; // ecx@26
    const void *v16; // esi@26
    const char *v17; // edi@26
    unsigned int v18; // edx@26
    signed int v19; // ecx@26
    int v20; // edi@31
    signed int v21; // ecx@31
    signed int v22; // ecx@34
    const void *v23; // esi@34
    const char *v24; // edi@34
    unsigned int v25; // edx@34
    signed int v26; // ecx@34
    int v27; // edi@39
    signed int v28; // ecx@39
    signed int v29; // ecx@42
    const void *v30; // esi@42
    const char *v31; // edi@42
    unsigned int v32; // edx@42
    signed int v33; // ecx@42
    FILE *v34; // eax@46
    FILE *v35; // esi@46
    int v36; // eax@47
    int v37; // edi@51
    signed int v38; // ecx@51
    signed int v39; // ecx@54
    const void *v40; // esi@54
    const char *v41; // edi@54
    unsigned int v42; // edx@54
    signed int v43; // ecx@54
    struct TEXT_FILE_STRUCT *v44; // eax@57
    struct TEXT_FILE_STRUCT *v45; // eax@58
    int v46; // edi@60
    signed int v47; // ecx@60
    signed int v48; // ecx@63
    const void *v49; // esi@63
    const char *v50; // edi@63
    unsigned int v51; // edx@63
    signed int v52; // ecx@63
    struct TEXT_FILE_STRUCT *v53; // eax@66
    struct TEXT_FILE_STRUCT *v54; // eax@67
    bool v55; // sf@70
    unsigned char v56; // of@70
    unsigned int v57; // esi@72
    int LastBillingReconnectTime; // qax@72
    int LastBillingAttemptTime; // ebx@72
    struct PACKET_ATTACHMENT * v60; // eax@72
    void *v61; // eax@73
    int BillingServerEncryptionServerKey; // esi@77
    int v63; // eax@77
    void *v64; // ebx@80
    struct PACKET_ATTACHMENT *v65; // eax@82
    struct PACKET_ATTACHMENT *v66; // eax@83
    int v67; // eax@87
    struct BILLING_SERVER_STRUCT *billingStruct; // eax@95
    struct BILLING_SERVER_STRUCT *billingStructRet; // eax@96
    void *v70; // esi@98
    int v71; // eax@100
    void *v72; // eax@101
    signed int v73; // esi@105
    int v74; // eax@107
    void *v75; // eax@108
    struct TEXT_FILE_STRUCT *v76; // eax@111
    struct TEXT_FILE_STRUCT *v77; // eax@112
    struct TEXT_FILE_STRUCT *v78; // eax@114
    struct TEXT_FILE_STRUCT *v79; // eax@115
    struct TEXT_FILE_STRUCT *v80; // eax@117
    struct TEXT_FILE_STRUCT *v81; // eax@118
    struct TEXT_FILE_STRUCT *v82; // eax@120
    struct TEXT_FILE_STRUCT *v83; // eax@121
    struct TEXT_FILE_STRUCT *v84; // eax@123
    struct TEXT_FILE_STRUCT *v85; // eax@124
    int v86; // eax@126
    int v87; // eax@127
    struct PACKET_ATTACHMENT *v88; // eax@129
    struct PACKET_ATTACHMENT *v89; // eax@130
    int *v91; // [sp-Ch] [bp-448h]@11
    const char *v92; // [sp-8h] [bp-444h]@11
    int v93; // [sp-4h] [bp-440h]@11
    int SecurityArrayIndex; // [sp+14h] [bp-428h]@8
    int LocalPointer; // [sp+18h] [bp-424h]@22
    char Buffer[17]; // [sp+1Ch] [bp-420h]@8
    char cp[512]; // [sp+30h] [bp-40Ch]@15
    int Src[128]; // [sp+230h] [bp-20Ch]@11
    int WhichPartRan; // [sp+438h] [bp-4h]@57

    int directoryCounter = 0; //fix 1

    ShutdownArguments = 0;
    RecycleServer = 0;
    SubGameLogFileHandle = fopen("subgame.log", "wt");
    WriteSubGameLog("SubSpace Game Server f%d.%02d%c\n", 1, 34, 98);
    if ( SubGameLogFileHandle )
    {
        fclose(SubGameLogFileHandle);
        SubGameLogFileHandle = 0;
    }
    srand(clock()); //set random number generator seed.
    memset(LogArray, 0, sizeof(LogArray));
    memset(ZonePlayerList, 0, sizeof(ZonePlayerList));
    memset(ChatRelatedArray, 0, sizeof(ChatRelatedArray));
    MachineIdArrayCount = 0;
    CurrentLogLine = 0;
    ZonePlayerCount = 0;
    IncreasesRadarValueSomeHow = 0;
    dword_4D55D0 = 0;
    dword_4C8F38 = 0;
    PointsFileHandle = 0;
    SharewareAdvertisementsFound = 0;
    RegisteredAdvertisementsFound = 0;
    BothAdvertisementsFound = 0;
    ChatCounter64Max = 0;
    LoadWinsock();
    IsFileLastWrittenTime(ServerINIFilePath, &LastTimeServerINIWasEdited);
    ReadServerINI();
    IsFileLastWrittenTime(ServerCFGFilePath, &LastTimeMasterCFGWasEdited);
    LoadZoneCFGSettings(&ArenaSettings, &ServersideArenaSettings, ServerCFGFilePath);

    if ( ArenaArrayLength > 0 )
    {
        v1 = 0;
        do
        {
            if ( !stricmp(Arenas[v1]->SettingsFilename, ServerCFGFilePath) )
                Arenas[v1]->NeedSettingsUpdate = 1;
            ++v1;
        }
        while ( v1 < ArenaArrayLength );
    }
    LoadTemplateSSS();
    LoadDefaultServerMap();
    LoadAdvertisements();
    *(unsigned int *)Buffer = 0;
    Buffer[0] = 0x10;	//0x10 - File Transfer
    *(unsigned int *)&Buffer[4] = 0; //No FileName
    *(unsigned int *)&Buffer[8] = 0; //No FileName
    *(unsigned int *)&Buffer[12] = 0; //No FileName
    Buffer[16] = 0; //No FileName
    SecurityArrayIndex = 0;
    memset(Security, 0, sizeof(Security));
    do
    {
        if ( SecurityArrayIndex )
        {
            sprintf((char *)Src, "version%d\\", SecurityArrayIndex);
            goto LABEL_15;
        }
        if ( _access("version0", 0) != -1 )
        {
            sprintf((char *)Src, "version%d\\", 0);
            goto LABEL_15;
        }
        Src[0] = 0;
LABEL_15:
        Security[SecurityArrayIndex].Subspace131EXEBytes = 0;
        Security[SecurityArrayIndex].Subspace133EXEBytes = 0;
        Security[SecurityArrayIndex].Subspace132EXEBytes = 0;

        strcpy(cp, (const char *)Src);
        strcat(cp, "Update.exe");
        if ( _access(cp, 0) != -1 )
            Security[SecurityArrayIndex].Subspace131EXEBytes = CompressFile(cp, &Security[SecurityArrayIndex].Subspace131FileSize, &LocalPointer, Buffer, 0x11, 0);

        strcpy(cp, (const char *)Src);
        strcat(cp, "Update1.exe");
        if ( _access(cp, 0) != -1 )
            Security[SecurityArrayIndex].Subspace133EXEBytes = CompressFile(cp, &Security[SecurityArrayIndex].Subspace133FileSize, &LocalPointer, Buffer, 0x11, 0);

        strcpy(cp, (const char *)Src);
        strcat(cp, "Update2.exe");
        if ( _access(cp, 0) != -1 )
            Security[SecurityArrayIndex].Subspace132EXEBytes = CompressFile(cp, &Security[SecurityArrayIndex].Subspace132FileSize, &LocalPointer, Buffer, 0x11, 0);

        strcpy(cp, (const char *)Src);
        strcat(cp, "subspace.exe");
        if ( _access(cp, 0) != -1 )
        {
            Security[SecurityArrayIndex].SubspaceEXEChecksum = SubspaceEXEChecksum(cp);
            strcat(cp, " Z"); //subspace.exe Z or continuum.exe Z creates scrty file.
            system(cp); //creates and opens new process (starts subspace.exe Z, can't run this on linux anyways -_-.
            v34 = fopen("scrty", "rb");
            if ( v34 )
            {
                v36 = _fileno(v34);
                if ( _filelength(v36) != 4000 )
                {
                    printf("Security file invalid size\n");
                    exit(1);
                }
                fread(Security[SecurityArrayIndex].ScrtyData, 1, 4000, v34);
                fclose(v34);
            }
            strcpy(cp, (const char *)Src);
            strcat(cp, "ipblock.txt");
            Security[SecurityArrayIndex].IPBlockText = malloc (sizeof (struct TEXT_FILE_STRUCT));
            if ( Security[SecurityArrayIndex].IPBlockText )
                InitializeTextFile(Security[SecurityArrayIndex].IPBlockText, cp, 1);
            else
                Security[SecurityArrayIndex].IPBlockText = 0;

            strcpy(cp, (const char *)Src);
            strcat(cp, "ipallow.txt");
            Security[SecurityArrayIndex].IPAllowText = malloc (sizeof (struct TEXT_FILE_STRUCT));
            if ( Security[SecurityArrayIndex].IPAllowText )
                InitializeTextFile(Security[SecurityArrayIndex].IPAllowText, cp, 1);
            else
                Security[SecurityArrayIndex].IPAllowText = 0;
        }
        SecurityArrayIndex++;
    }
    while ( SecurityArrayIndex < 10 );
    CompressedNewsMemory = CompressFile("news.txt", &NewsTxtFileSize, &NewsTxtFileChecksum, Buffer, 0x11, 1);
    SetConsoleTitleA(BillingServerName);
    dword_4C8F3C = 1;
    memset(TotalSentForEachPacketType, 0, sizeof(TotalSentForEachPacketType));
    memset(TotalSentSizeForEachPacketType, 0, sizeof(TotalSentSizeForEachPacketType));
    memset(DirectoryConnectSockets, 0, sizeof(DirectoryConnectSockets));
    RadarValue = 0;
    ScreenValue = 0;
    ServerIterations = 0;
    DoubleValue = 0;
    Wave = 0;
    BillerSocket = 0;
    BillerPacketAttachment = 0;
    BillingConnectionStructPointer = 0;
    if ( UseBillingServer )
    {
        LastBillingReconnectTime = GetTickCount() / 0xA;
        LastBillingAttemptTime = GetTickCount() / 0xA;
        BillerPacketAttachment = malloc(sizeof (struct PACKET_ATTACHMENT));
        if ( BillerPacketAttachment )
            StartServerListener(BillerPacketAttachment, 0, 0, 16, 0, 8192, 8192, 1);
        EncryptionStruct = 0;
        while ( abs(GetTickCount() / 0xA - LastBillingAttemptTime) < BillingAttemptTime )
        {
            if ( !EncryptionStruct )
            {
                WriteSubGameLog("Attempting to establish link to billing server...\n");
                BillingServerEncryptionServerKey = -abs((GetTickCount() / 0xA) + rand());
                EncryptionStruct = ConnectToBiller(BillerPacketAttachment, BillingIP, BillingPort, BillingServerEncryptionServerKey, 0);
                LastBillingReconnectTime = GetTickCount() / 0xA;
            }
            ProcessPackets(BillerPacketAttachment);
            if ( CheckState(EncryptionStruct) == 2 ) //2 = Encryption is initialized
                break;
            if ( (GetTickCount() / 0xA - LastBillingReconnectTime) > 2000 ) // 20 seconds.
            {
                sub_41B7A0(EncryptionStruct);
                EncryptionStruct = 0;
                if ( BillerPacketAttachment )
                {
                    CleanUpPacketAttachment(BillerPacketAttachment);
                    free(BillerPacketAttachment);
                }
                BillerPacketAttachment = malloc(sizeof (struct PACKET_ATTACHMENT));
                if ( BillerPacketAttachment )
                    StartServerListener(BillerPacketAttachment, 0, 0, 16, 0, 8192, 8192, 1);
            }
            if ( _kbhit() )
            {
                v67 = _getch();
                if ( v67 == 0x00 || v67 == 0xE0 )  /* if extended key */
                {
                    if ( _getch() == 0x88 ) //Shift+F12
                    {
                        printf("Shutting down server...\n");
                        exit(1);
                    }
                }
            }
            Sleep(CPUSleepTime);
        }
        if ( CheckState(EncryptionStruct) == 2 ) //2 = Encryption is initialized
        {
            WriteSubGameLog("Billing server connected.\n");

            BillingConnectionStructPointer = malloc (sizeof (struct BILLING_SERVER_STRUCT));

            if ( BillingConnectionStructPointer )
            {
                SendBillerServerConnectPacket(
                    BillingConnectionStructPointer,
                    (int)HandleBillerPacket,
                    BillingServerName,
                    BillingServerId,
                    BillingGroupId,
                    BillingScoreId,
                    BillingPassword,
                    BillerPacketAttachment,
                    EncryptionStruct);
            } else {
                BillingConnectionStructPointer = 0;
            }
        }
        else
        {
            WriteSubGameLog("ERROR: Could not connect to billing server.\n");
            BillingConnectionStructPointer = 0;
            if ( BillerPacketAttachment )
            {
                CleanUpPacketAttachment(BillerPacketAttachment);
                free(BillerPacketAttachment);
            }
            BillerPacketAttachment = 0;
            WriteSubGameLog("Starting server in stand-alone mode.\n");
            ConnectSocket(&BillerSocket, BillingIP, BillingPort + 1, 0);
        }
    }
    if ( strlen(DirectoryIPAddresses) > 4 )
    {
        v73 = 0;
        do
        {
            if ( strlen(GetSplitNextDirectoryIP(cp, DirectoryIPAddresses)) == 0 )
                break;
            ConnectSocket(&DirectoryConnectSockets[v73], cp, DirectoryPort, 0);
            ++v73;
        }
        while ( v73 < sizeof(DirectoryConnectSockets) );
    }
    ObscenePointer = malloc (sizeof (struct TEXT_FILE_STRUCT));
    if ( ObscenePointer )
        InitializeTextFile(ObscenePointer, "obscene.txt", 1);
    else
        ObscenePointer = 0;
    IDBlockPointer = malloc (sizeof (struct TEXT_FILE_STRUCT));
    if ( IDBlockPointer )
        InitializeTextFile(IDBlockPointer, "idblock.txt", 0);
    else
        IDBlockPointer = 0;
    PermitPointer = malloc (sizeof (struct TEXT_FILE_STRUCT));
    if ( PermitPointer )
        InitializeTextFile(PermitPointer, "permit.txt", 0);
    else
        PermitPointer = 0;
    ModeratePointer = malloc (sizeof (struct TEXT_FILE_STRUCT));
    if ( v82 )
        InitializeTextFile(ModeratePointer, "moderate.txt", 0);
    else
        ModeratePointer = 0;
    ReservedPointer = malloc (sizeof (struct TEXT_FILE_STRUCT));
    if ( v84 )
        InitializeTextFile(ReservedPointer, "reserved.txt", 0);
    else
        ReservedPointer = 0;
    ServerListenPort = ReadIntegerINI("Misc", "Port", 382, ServerINIFilePath);
    ListenOnPort(&ZonePingSocket, ServerListenPort + 1);
    ArenaArrayLength = 0;
    ServerPacketAttachment = malloc(sizeof (struct PACKET_ATTACHMENT));
    if ( ServerPacketAttachment )
        StartServerListener(
            ServerPacketAttachment,
            (int)NewConnectionRequest,
            (int)PlayerHandleGamePacketWrapper,
            1024, /*Total number of connections*/
            ServerListenPort,
            CommsOutgoingBufferSize,
            CommsIncomingBufferSize,
            CommsPacketHistoryMax);
    SetPacketAttachmentEncryptMode(ServerPacketAttachment, CommsEncryptMode);
    sub_41B430(ServerPacketAttachment, CommsTransportBufferSize);
}
// 408300: using guessed type int nullsub_1(void);
// 41AC00: using guessed type int __cdecl ProcessPackets(unsigned int);
// 41B950: using guessed type int __cdecl CheckState(unsigned int);
// 41F1B0: using guessed type unsigned int __cdecl _filelength(unsigned int);
// 42C840: using guessed type int UseBillingServer;
// 431BB8: using guessed type int LastTimeServerINIWasEdited;
// 431BE0: using guessed type int MaxDirectoryConnections;
// 431BE8: using guessed type int RadarValue;
// 431FF4: using guessed type int ArenaArrayLength;
// 431FF8: using guessed type int ServerIterations;
// 432000: using guessed type int LastTimeMasterCFGWasEdited;
// 432004: using guessed type int RecycleServer;
// 437C18: using guessed type int DoubleValue;
// 437C1C: using guessed type int BillingAttemptTime;
// 437CA4: using guessed type int CurrentLogLine;
// 4386D4: using guessed type int MachineIdArrayCount;
// 438B10: using guessed type int ScreenValue;
// 438B20: using guessed type int CommsEncryptMode;
// 4C8F38: using guessed type int dword_4C8F38;
// 4C8F3C: using guessed type int dword_4C8F3C;
// 4CA814: using guessed type int IncreasesRadarValueSomeHow;
// 4D55D0: using guessed type int dword_4D55D0;
// 4D5914: using guessed type int NewsTxtFileChecksum;
// 4D89C8: using guessed type int Wave;
// 4D8AFC: using guessed type int SharewareAdvertisementsFound;
// 4D8B00: using guessed type int RegisteredAdvertisementsFound;
// 4D8B04: using guessed type int BothAdvertisementsFound;
// 4D8B18: using guessed type int ChatCounter64Max;

//----- (00412D50) --------------------------------------------------------
signed int __cdecl NewConnectionRequest(struct in_addr IPAddress, unsigned short Port, struct CONNECTION *connection)
{
    int v3; // ebp@1
    int v4; // edi@2
    struct PLAYER **v5; // esi@2
    const void *v6; // ebx@2
    struct PLAYER *v7; // eax@9
    struct PLAYER *v8; // eax@10
    int v9; // ecx@12
    void *Memory; // [sp+10h] [bp-10h]@5

    if ( ZonePlayerCount > 0 )
    {
        v3 = 0;
        do
        {
            if ( ZonePlayers[v3]->IPAddressDWORD.s_addr == IPAddress.s_addr && ZonePlayers[v3]->Port == Port )
            {
                printf("Connection broken because same ip/port requested another connection\n");
                OrderDisconnect(ZonePlayers[v3]->connection);
                if ( ZonePlayers[v3] )
                {
                    DisconnectUser(ZonePlayers[v3]);
                    free(ZonePlayers[v3]);
                }

                memcpy(
                    &ZonePlayers[v3],
                    &ZonePlayers[v3 + 1],
                    sizeof(&ZonePlayers) * (ZonePlayerCount - v3 - 1));
                ZonePlayerCount--;
                --v3;
            }
            ++v3;
        }
        while ( v3 < ZonePlayerCount );
    }

    v7 = malloc (sizeof (struct PLAYER)); //new Player struct pointer

    if ( v7 )
        v8 = CreateNewPlayer(v7, IPAddress, Port, connection);
    else
        v8 = 0;

    ZonePlayers[ZonePlayerCount] = v8;
    ZonePlayerCount++;
    return 1;
}

//----- (00412E80) --------------------------------------------------------
void __cdecl PlayerHandleGamePacketWrapper(unsigned char *packet, int packetSize, struct CONNECTION *a3)
{
    struct PLAYER *v3; // ecx@1

    v3 = ZonePlayerList[a3->PlayerId];
    if ( v3 )
        PlayerHandleGamePacket(v3, packet, packetSize);
}

//----- (00412EB0) --------------------------------------------------------
void __cdecl ServerMainLoop()
{
    //int (*GetTickCount)(void); // ebp@2
    int v1; // ebx@2
    signed int v2; // esi@2
    int v3; // eax@6
    int v4; // edi@12
    int v5; // edi@15
    struct PLAYER **v6; // esi@16
    unsigned int LastCPUProcessTime; // esi@21
    int v8; // edi@24
    struct PLAYER **v9; // esi@25
    int v10; // eax@29
    int v11; // edi@29
    unsigned int *v12; // esi@30
    struct PLAYER *v13; // ecx@31
    unsigned int v14; // eax@35
    int v15; // edi@36
    struct PLAYER **v16; // esi@36
    const void *v17; // ebp@36
    int v18; // edi@44
    struct ARENA **v19; // esi@44
    const void *v20; // ebp@44
    unsigned int (__stdcall *v21)(); // ebp@54
    int v22; // ebx@54
    int v23; // esi@55
    struct KICK *v24; // ebp@55
    struct KICK *v25; // edi@55
    long v26; // qax@56
    unsigned int v27; // eax@61
    void **v28; // esi@61
    int v29; // edi@73
    int v30; // esi@74
    const char **v31; // esi@78
    const char *v32; // ecx@79
    int v33; // edi@91
    int v34; // esi@92
    unsigned int v35; // eax@97
    unsigned int ElapsedCPUIterationTime; // esi@98
    struct PLAYER *player; // [sp+10h] [bp-1F4h]@38
    void *bufa; // [sp+10h] [bp-1F4h]@49
    unsigned int LastSettingsReReadTime; // [sp+10h] [bp-1F4h]@67
    unsigned int LastPlayerArenaCheckTime; // [sp+14h] [bp-1F0h]@1
    unsigned int LastDirectoryServerPingedTime; // [sp+18h] [bp-1ECh]@1
    unsigned int LastFilesReReadAndBillerConnectionCheckTime; // [sp+1Ch] [bp-1E8h]@1
    int LastCPUIterationTime; // [sp+20h] [bp-1E4h]@5
    char Buffer[17]; // [sp+24h] [bp-1E0h]@84
    int BillerServerLag; // [sp+2Ch] [bp-1D8h]@84
    int DirectoryServerLag; // [sp+30h] [bp-1D4h]@84
    char v48; // [sp+34h] [bp-1D0h]@84
    char v49; // [sp+38h] [bp-1CCh]@90
    char v50; // [sp+3Ch] [bp-1C8h]@63
    char DirectoryServerPacket[452]; // [sp+40h] [bp-1C4h]@61

    LastPlayerArenaCheckTime = GetTickCount() / 0xA;
    LastFilesReReadAndBillerConnectionCheckTime = GetTickCount() / 0xA;
    LastDirectoryServerPingedTime = 0;
    IsEditedServerINIorCFG = 0;
    if ( !IsServerRunning )
    {
        v1 = 0;
        v2 = 1;
        while ( 1 )
        {
            if ( RecycleServer != 0 )
                return;
            LastCPUIterationTime = GetTickCount() / 0xA;
            if ( _kbhit() )
            {
                v3 = _getch();
                if ( v3 == 0x00 || v3 == 0xE0 )  /* if extended key */
                {
                    if ( _getch() == 0x88 ) //Shift+F12
                    {
                        printf("Shutting down server...\n");
                        IsServerRunning = v2;
                        return;
                    }
                }
            }
            if ( BillingConnectionStructPointer != 0 )
            {
                if ( IsBillingServerDisconnected(BillingConnectionStructPointer) )
                {
                    WriteSubGameLog("Connection to billing server broken\n");
                    RecycleServer = v2;
                }
                v4 = GetBillerLastReconnectTime(BillingConnectionStructPointer);
                if ( (GetTickCount() / 0xA - v4) > BillingReconnectTime )
                {
                    WriteSubGameLog("Connection to billing server timed out\n");
                    RecycleServer = v2;
                }
                if ( RecycleServer != 0 )
                {
                    if ( ZonePlayerCount > 0 )
                    {
                        v5 = 0;
                        do
                        {
                            if ( ZonePlayers[v5]->MyArena != 0 )
                                SendArenaMessage(ZonePlayers[v5], "NOTICE: Server recycling, please log back in shortly.", 1);
                            ++v5;
                        }
                        while ( v5 < ZonePlayerCount );
                    }
                    SendPacketsToEverybody(ServerPacketAttachment);
                }
            }
            ProcessZonePingPlayerCount(ZonePingSocket, ZonePlayerCount);
            LastCPUProcessTime = GetTickCount() / 0xA;
            if ( ProcessPackets(ServerPacketAttachment) )
            {
                while ( (GetTickCount() / 0xA - LastCPUProcessTime) < CPUProcessMaxTime && ProcessPackets(ServerPacketAttachment) )
                    ;
            }
            if ( ZonePlayerCount > 0 )
            {
                v8 = 0;
                do
                {
                    if ( ZonePlayers[v8]->SendWeaponUpdatePacket != 0 )
                        SendWeaponPacket(ZonePlayers[v8]);
                    ++v8;
                }
                while ( v8 < ZonePlayerCount );
            }
            SendPacketsToEverybody(ServerPacketAttachment);
            v10 = IncreasesRadarValueSomeHow;
            ScreenValue += dword_4D55D0;
            v11 = 0;
            DoubleValue += dword_4C8F38;
            dword_4D55D0 = 0;
            dword_4C8F38 = 0;
            RadarValue += IncreasesRadarValueSomeHow;
            if ( IncreasesRadarValueSomeHow > 0 )
            {
                v12 = (unsigned int *)byte_4AF911;
                do
                {
                    v13 = ZonePlayerList[*(unsigned int *)((char *)v12 - 25)];
                    if ( v13 != 0 )
                    {
                        sub_40DEA0(v13, (char *)v12 - 21, *(unsigned char *)v12, *(unsigned char *)v12);
                        v10 = IncreasesRadarValueSomeHow;
                    }
                    ++v11;
                    v12 = (unsigned int *)((char *)v12 + 26);
                }
                while ( v11 < v10 );
            }
            IncreasesRadarValueSomeHow = 0;
            if ( (GetTickCount() / 0xA - LastPlayerArenaCheckTime) > 30 )
            {
                HighestPlayerCountMaybeSomething = 0;
                LastPlayerArenaCheckTime = GetTickCount() / 0xA;
                if ( ZonePlayerCount > 0 )
                {
                    v1 = 0;
                    do
                    {
                        if ( sub_40CF10(ZonePlayers[v1]) )
                        {
                            if ( ZonePlayers[v1] )
                            {
                                DisconnectUser(ZonePlayers[v1]);
                                free(ZonePlayers[v1]);
                            }

                            memcpy(
                                &ZonePlayers[v1],
                                &ZonePlayers[v1 + 1],
                                sizeof(ZonePlayers) * (ZonePlayerCount - v1 - 1));
                            --ZonePlayerCount;
                            --v1;
                        }
                        ++v1;
                    }
                    while ( v1 < ZonePlayerCount );
                }
                if ( ArenaArrayLength > 0 )
                {
                    v1 = 0;
                    do
                    {
                        if ( ProcessArena(Arenas[v1]) )
                        {
                            if ( Arenas[v1]->ArenaName[0] )
                                WriteSubGameLog("Private arena dropped: %s\n", Arenas[v1]->ArenaName);
                            else
                                WriteSubGameLog("Arena dropped\n");

                            if ( Arenas[v1] )
                            {
                                ShutdownArena(Arenas[v1]);
                                free(Arenas[v1]);
                            }

                            memcpy(
                                &Arenas[v1],
                                &Arenas[v1 + 1],
                                sizeof(Arenas) * (ArenaArrayLength - v1 - 1));
                            --ArenaArrayLength;
                            --v1;
                        }
                        ++v1;
                    }
                    while ( v1 < ArenaArrayLength );
                }
            }
            SendPacketsToEverybody(ServerPacketAttachment);
            ++ServerIterations;
            if ( (GetTickCount() / 0xA - LastServerStatsAndKickedPlayersTime) > 6000 ) //1 minute
            {
                memset(TotalSentForEachPacketType, 0, sizeof(TotalSentForEachPacketType));
                v22 = 0;
                memset(TotalSentSizeForEachPacketType, 0, sizeof(TotalSentSizeForEachPacketType));
                RadarValue = 0;
                ScreenValue = 0;
                ServerIterations = 0;
                DoubleValue = 0;
                Wave = 0;
                LastServerStatsAndKickedPlayersTime = GetTickCount() / 0xA;
                ResetPacketStatistics(ServerPacketAttachment);
                if ( MachineIdArrayCount <= 0 )
                    goto SKIP_KICKED_USERS;
                v23 = 0;
                v24 = KickedUsers;
                v25 = &KickedUsers[1];
                do
                {
                    if ( (GetTickCount() / 0xA - KickedUsers[v23].KickStartTime) > KickedUsers[v23].KickDelayMilliseconds )
                    {   //TODO: This is crazy removes a element from array which is also a structure itself, shifts all other kicks to front.
                        --MachineIdArrayCount;
                        memcpy(v24, v25, 12 * MachineIdArrayCount - v23 * 12);
                        --v22;
                        --v23;
                        --v25;
                        --v24;
                    }
                    ++v22;
                    ++v23;
                    ++v25;
                    ++v24;
                }
                while ( v22 < MachineIdArrayCount );
            }
SKIP_KICKED_USERS:
            //Sends Directory Server(s) the proper information of this zone.
            if ( abs(GetTickCount() / 0xA - LastDirectoryServerPingedTime) > 6000 )
            {
                memset(DirectoryServerPacket, 0, sizeof(DirectoryServerPacket));
                LastDirectoryServerPingedTime = GetTickCount() / 0xA;
                *(unsigned short *)&DirectoryServerPacket[0] = ServerListenPort;        // Sever Port, Directory Server
                *(unsigned short *)&DirectoryServerPacket[2] = ZonePlayerCount;     // Player Count Directory Server
                *(unsigned short *)&DirectoryServerPacket[4] = BillingConnectionStructPointer != 0;// Score Keeping Directory Server
                *(unsigned int *)&DirectoryServerPacket[6] = 134;                // Server Version, Directory Server
                strncpy(&DirectoryServerPacket[10], BillingServerName, 0x20);// Zone Name, Directory Server
                DirectoryServerPacket[41] = 0;
                strncpy(&DirectoryServerPacket[42], DirectoryNamePassword, 0x10);// Directory Password , Directory Server
                DirectoryServerPacket[57] = 0;
                strncpy(&DirectoryServerPacket[90], DirectoryDescription, 250);// Zone Description, Directory Server
                DirectoryServerPacket[339] = 0;
                *(unsigned short *)&DirectoryServerPacket[448] = 0;
                v29 = 0;
                do
                {
                    if ( DirectoryConnectSockets[v29] != 0 )
                    {
                        SendDirectoryServerZoneUpdatePacket(DirectoryConnectSockets[v29], DirectoryServerPacket, strlen(&DirectoryServerPacket[90]) + 91); //Variable - size packet
                        GetSocketRecvLag(DirectoryConnectSockets[v29], &DirectoryServerLag);
                    }
                    ++v29;
                }
                while ( v29 < sizeof(DirectoryConnectSockets) );
            }

            //Re-Read's alot of configuration and txt files if they changed with newer copy.
            if ( (GetTickCount() / 0xA - LastFilesReReadAndBillerConnectionCheckTime) > 18000 || IsEditedServerINIorCFG != 0 )
            {
                LastSettingsReReadTime = GetTickCount() / 0xA;
                if ( BillerSocket != 0 && BillingConnectionStructPointer == 0 )
                    SendDirectoryServerZoneUpdatePacket(BillerSocket, 0, 0);
                dword_4C8F3C = 1;
                IsEditedServerINIorCFG = 0;
                LastFilesReReadAndBillerConnectionCheckTime = GetTickCount() / 0xA;
                if ( IsFileLastWrittenTime(ServerINIFilePath, &LastTimeServerINIWasEdited) )
                {
                    printf("INI settings different, re-reading\n");
                    ReadServerINI();
                    SetPacketAttachmentEncryptMode(ServerPacketAttachment, CommsEncryptMode);
                    sub_41B430(ServerPacketAttachment, CommsTransportBufferSize);
                }
                if ( IsFileLastWrittenTime(ServerCFGFilePath, &LastTimeMasterCFGWasEdited) )
                {
                    printf("Master CFG settings different, re-reading\n");
                    LoadZoneCFGSettings(&ArenaSettings, &ServersideArenaSettings, ServerCFGFilePath);
                    if ( ArenaArrayLength > 0 )
                    {
                        v30 = 0;
                        do
                        {
                            if ( !stricmp((char *)Arenas[v30]->SettingsFilename, ServerCFGFilePath) )
                                Arenas[v30]->NeedSettingsUpdate = 1;
                            ++v30;
                        }
                        while ( v30 < ArenaArrayLength );
                    }
                }

                if ( Security[0].IPBlockText != 0 )
                    LoadTextFile(Security[0].IPBlockText, 0);
                if ( Security[0].IPAllowText != 0 )
                    LoadTextFile(Security[0].IPAllowText, 0);

                LoadTextFile(IDBlockPointer, 0);
                LoadTextFile(ObscenePointer, 0);
                LoadTextFile(PermitPointer, 0);
                LoadTextFile(ModeratePointer, 0);
                LoadTextFile(ReservedPointer, 0);

                //Updated news.txt file, loads newer version of news.txt
                if ( IsFileLastWrittenTime("news.txt", &LastTimeNewsTxtWasEdited) )
                {
                    if ( CompressedNewsMemory != 0 )
                        FreeMemory(CompressedNewsMemory);
                    //Setup new compressed packet of news.txt to send to anyone who needs it.
                    *(unsigned int *)Buffer = 0;
                    Buffer[0] = 0x10;	//0x10 - File Transfer
                    *(unsigned int *)&Buffer[4] = 0;
                    *(unsigned int *)&Buffer[8] = 0;
                    *(unsigned int *)&Buffer[12] = 0;
                    Buffer[16] = 0;
                    CompressedNewsMemory = CompressFile("news.txt", &NewsTxtFileSize, &NewsTxtFileChecksum, Buffer, 0x11, 1);
                }

                //Automatically recycles the server if the Billing server connection goes down.
                if ( BillerSocket != 0
                        && BillingConnectionStructPointer == 0
                        && GetSocketRecvLag(BillerSocket, &BillerServerLag) >= 0 )
                {
                    v34 = 0;
                    if ( ZonePlayerCount > 0 )
                    {
                        do
                        {
                            if ( ZonePlayers[v34]->MyArena != 0 )
                                SendArenaMessage(ZonePlayers[v34], "NOTICE: Server recycling in order to restore scores, please log back in.", 1);
                            ++v34;
                        }
                        while ( v34 < ZonePlayerCount );
                    }
                    SendPacketsToEverybody(ServerPacketAttachment);
                    RecycleServer = 1;
                }
                printf("Re-read Settings: %d ms\n", 10 * (GetTickCount() / 0xA - LastSettingsReReadTime));
                fflush(stdout); //probably not needed anymore this was for old compilers 1997 etc..
            }
            sub_41B570(100); //hmm lost code, maybe patched out, TOP SECRET function?
            ElapsedCPUIterationTime =  (GetTickCount() / 0xA) - LastCPUIterationTime;
            if ( ElapsedCPUIterationTime <= 2 || CPUSleepPerIteration != 0 )
                Sleep(CPUSleepTime);
            if ( ElapsedCPUIterationTime > CPUSlowIterationWarningLevel )
                WriteSubGameLog("Slow iteration warning: %d ms\n", 10 * ElapsedCPUIterationTime);
            if ( IsServerRunning != 0 )
                return;
            v2 = 1;
            v1 = 0;
        }
    }
}
// 406130: using guessed type int __cdecl GetBillerLastReconnectTime(unsigned int);
// 41AC00: using guessed type int __cdecl ProcessPackets(unsigned int);
// 41B3D0: using guessed type int __cdecl ResetPacketStatistics(unsigned int);
// 41B570: using guessed type unsigned int __stdcall sub_41B570(unsigned int);
// 431BB8: using guessed type int LastTimeServerINIWasEdited;
// 431BE8: using guessed type int RadarValue;
// 431FF4: using guessed type int ArenaArrayLength;
// 431FF8: using guessed type int ServerIterations;
// 432000: using guessed type int LastTimeMasterCFGWasEdited;
// 432004: using guessed type int RecycleServer;
// 437C18: using guessed type int DoubleValue;
// 437CA8: using guessed type int IsServerRunning;
// 4386D4: using guessed type int MachineIdArrayCount;
// 438B10: using guessed type int ScreenValue;
// 438B14: using guessed type int CPUSlowIterationWarningLevel;
// 438B20: using guessed type int CommsEncryptMode;
// 438B78: using guessed type int BillingReconnectTime;
// 4AC448: using guessed type struct KICK KickedUsers[1000];
// 4C8F38: using guessed type int dword_4C8F38;
// 4C8F3C: using guessed type int dword_4C8F3C;
// 4C9F44: using guessed type int CPUSleepPerIteration;
// 4CA814: using guessed type int IncreasesRadarValueSomeHow;
// 4D55D0: using guessed type int dword_4D55D0;
// 4D5904: using guessed type int CPUProcessMaxTime;
// 4D5914: using guessed type int NewsTxtFileChecksum;
// 4D5920: using guessed type int IsEditedServerINIorCFG;
// 4D5924: using guessed type int LastTimeNewsTxtWasEdited;
// 4D89C8: using guessed type int Wave;
// 4D8AF4: using guessed type int LastServerStatsAndKickedPlayersTime;
// 4D8AF8: using guessed type int HighestPlayerCountMaybeSomething;

//----- (004137F0) --------------------------------------------------------
int __cdecl IncreaseRadarValueShowHomeOverFourThousand()
{
    int result; // eax@1
    int v1; // edi@1
    unsigned int *v2; // esi@2
    struct PLAYER *v3; // ecx@3

    result = IncreasesRadarValueSomeHow;
    v1 = 0;
    RadarValue += IncreasesRadarValueSomeHow;
    if ( IncreasesRadarValueSomeHow > 0 )
    {
        v2 = (unsigned int *)byte_4AF911;
        do
        {
            v3 = ZonePlayerList[*(unsigned int *)((char *)v2 - 25)];
            if ( v3 )
            {
                sub_40DEA0(v3, (char *)v2 - 21, *(unsigned char *)v2, *(unsigned char *)v2);
                result = IncreasesRadarValueSomeHow;
            }
            ++v1;
            v2 = (unsigned int *)((char *)v2 + 26);
        }
        while ( v1 < result );
    }
    IncreasesRadarValueSomeHow = 0;
    return result;
}
// 431BE8: using guessed type int RadarValue;
// 4CA814: using guessed type int IncreasesRadarValueSomeHow;

//----- (00413850) --------------------------------------------------------
void __cdecl ServerUninitialize()
{
    int v0; // eax@1
    bool v1; // zf@1
    bool v2; // sf@1
    struct PLAYER **v3; // edi@2
    int v4; // ebx@2
    void *v5; // esi@3
    int v6; // ebx@6
    struct ARENA **v7; // edi@7
    void *v8; // esi@8
    void *v9; // esi@13
    void *v10; // esi@15
    void *v11; // esi@17
    void *v12; // esi@19
    void *v13; // esi@21
    int v14; // edi@23
    void *v15; // esi@24
    char * v16; // esi@27
    char * v17; // esi@29
    char * v18; // esi@31
    char * v19; // esi@33
    char * v20; // esi@35
    int v21; // ebx@39
    void *v22; // esi@40
    void *v23; // esi@42
    LPVOID *v24; // esi@44
    signed int v25; // edi@44
    void *v26; // esi@49

    v0 = ZonePlayerCount;
    ZonePlayerCount = 0;
    if ( !((v0 < 0) | (v0 == 0)) )
    {
        v3 = ZonePlayers;
        v4 = v0;
        do
        {
            if ( *v3 )
            {
                DisconnectUser(*v3);
                free(*v3);
            }
            ++v3;
            --v4;
        }
        while ( v4 );
    }
    v6 = 0;
    if ( ArenaArrayLength > 0 )
    {
        v7 = Arenas;
        do
        {
            if ( *v7 )
            {
                ShutdownArena(*v7);
                free(*v7);
            }
            ++v6;
            ++v7;
        }
        while ( v6 < ArenaArrayLength );
    }
    ArenaArrayLength = 0;
    if ( PointsFileHandle )
    {
        fclose(PointsFileHandle);
        PointsFileHandle = 0;
    }
    if ( ServerPacketAttachment )
    {
        CleanUpPacketAttachment(ServerPacketAttachment);
        free(ServerPacketAttachment);
    }
    if ( ZonePingSocket )
    {
        CloseSocketWrapper(ZonePingSocket);
        //free(ZonePingSocket);
    }
    if ( BillerSocket )
    {
        CloseSocketWrapper(BillerSocket);
    }
    if ( BillingConnectionStructPointer )
    {
        CleanUpBilling(BillingConnectionStructPointer);
        free(BillingConnectionStructPointer);
    }
    if ( BillerPacketAttachment )
    {
        CleanUpPacketAttachment(BillerPacketAttachment);
        free(BillerPacketAttachment);
    }
    v14 = 0; //Each Socket connection?
    do
    {
        if ( DirectoryConnectSockets[v14] )
        {
            CloseSocketWrapper(DirectoryConnectSockets[v14]);
        }
        ++v14;
    }
    while ( v14 < sizeof(DirectoryConnectSockets) );
    if ( ObscenePointer )
    {
        CleanTextFileMemory(ObscenePointer);
        free((void *)ObscenePointer);
    }
    if ( PermitPointer )
    {
        CleanTextFileMemory(PermitPointer);
        free((void *)PermitPointer);
    }
    if ( ModeratePointer )
    {
        CleanTextFileMemory(ModeratePointer);
        free((void *)ModeratePointer);
    }
    if ( ReservedPointer )
    {
        CleanTextFileMemory(ReservedPointer);
        free((void *)ReservedPointer);
    }
    if ( IDBlockPointer )
    {
        CleanTextFileMemory(IDBlockPointer);
        free((void *)IDBlockPointer);
    }
    if ( CompressedNewsMemory )
    {
        FreeMemory(CompressedNewsMemory);
        CompressedNewsMemory = 0;
    }

    if ( Security[0].IPBlockText )
    {
        CleanTextFileMemory(Security[0].IPBlockText);
        free(Security[0].IPBlockText);
    }

    if ( Security[0].IPAllowText )
    {
        CleanTextFileMemory(Security[0].IPAllowText);
        free(Security[0].IPAllowText);
    }

    v25 = 3;
    do
    {
        if ( Security[v25].IPAllowText )
        {
            FreeMemory(Security[v25].IPAllowText);
            Security[v25].IPAllowText = 0;
        }
        --v25;
    }
    while ( v25 );

    if ( BMPFilePointer )
    {
        sub_406B30(BMPFilePointer);
        free(BMPFilePointer);
    }
    FreeMemory(CompressedServerMap);
    FreeMemory(ServerMapData);
    CleanUpAdvertiseMemory();
    WSACleanup();
    if ( SubGameLogFileHandle )
        fclose(SubGameLogFileHandle);
    SubGameLogFileHandle = 0;
}
// 407060: using guessed type int __cdecl CleanTextFileMemory(unsigned int);
// 431FF4: using guessed type int ArenaArrayLength;

//----- (00413AE0) --------------------------------------------------------
void __cdecl HandleBillerPacket(char *packetBuffer, int packetSize)
{
    int v3; // eax@2
    struct PLAYER **v4; // esi@2
    int v5; // edx@7
    struct PLAYER **v6; // eax@8
    int v7; // ecx@14
    struct PLAYER **v8; // eax@15
    struct PLAYER *v9; // esi@16
    int v10; // eax@23
    int v11; // ecx@28
    struct PLAYER **v12; // eax@29
    struct PLAYER *v13; // ebp@30
    char v14; // al@33
    short v15; // ax@40
    int v16; // ebx@45
    int v17; // eax@46
    struct PLAYER **v18; // esi@57
    struct ARENA *v19; // eax@60
    int v20; // eax@62
    int v21; // ecx@63
    void *v22; // edi@64
    bool v23; // sf@67
    unsigned char v24; // of@67
    int v25; // ecx@72
    int v26; // eax@72
    int v27; // ecx@72
    int v28; // edx@72
    int v29; // eax@72
    unsigned char v30; // [sp+13h] [bp-835h]@33
    int v31; // [sp+14h] [bp-834h]@28
    int v32; // [sp+18h] [bp-830h]@28
    void *Src; // [sp+1Ch] [bp-82Ch]@57
    int v34; // [sp+20h] [bp-828h]@33
    char buf[36]; // [sp+24h] [bp-824h]@72
    char a2a[2048]; // [sp+48h] [bp-800h]@6

    switch ( packetBuffer[0] )
    {
    case 10:
        v3 = 0;
        if ( ZonePlayerCount > 0 )
        {
            while ( 1 )
            {
                if ( ZonePlayers[v3]->BillerPlayerId == *(unsigned int *)&packetBuffer[1] )
                    break;
                ++v3;
                if ( v3 >= ZonePlayerCount )
                    return;
            }
            sprintf(a2a, "%d:%s", packetBuffer[5], packetBuffer + 6);
            SendChannelMessage(ZonePlayers[v3], a2a);
        }
        break;
    case 9:
        v5 = 0;
        if ( ZonePlayerCount > 0 )
        {
            while ( 1 )
            {
                if ( ZonePlayers[v5]->BillerPlayerId == *(unsigned int *)&packetBuffer[1] )
                    break;
                ++v5;
                if ( v5 >= ZonePlayerCount )
                    return;
            }
            SendArenaMessage(ZonePlayers[v5], &packetBuffer[5], 0);
        }
        break;
    case 4:
        RecycleServer = 1;
        break;
    case 8:
        v7 = 0;
        if ( ZonePlayerCount > 0 )
        {
            while ( 1 )
            {
                if ( ZonePlayers[v7]->BillerPlayerId == *(unsigned int *)&packetBuffer[1] )
                    break;
                ++v7;
                if ( v7 >= ZonePlayerCount )
                    return;
            }
            WriteSubGameLog("Player kicked off by billing server, reason #%d\n", *(unsigned int *)&packetBuffer[5]);
            ZonePlayers[v7]->DisconnectReason = 21;
            ZonePlayers[v7]->AlreadySentReliablePacket = 1;
        }
        break;
    case 2:
        WriteSubGameLog("Shutdown packet received, shutting down server...\n");
        IsServerRunning = 1;
        break;
    case 3:
        if ( packetBuffer[5] == 1 )
        {
            if ( IsLineExistTextFile(PermitPointer, &packetBuffer[6]) < 0 )
            {
                AddLineTextFile(PermitPointer, &packetBuffer[6]);
                WriteTextFileToFile(PermitPointer);
            }
        }
        else
        {
            if ( *(unsigned char *)(packetBuffer + 5) == 2 )
            {
                if ( *(unsigned char *)(packetBuffer + 7) == ':' )
                    ChatProcessor(0, 7, 0, (char *)(packetBuffer + 7), *(unsigned char *)(packetBuffer + 6));
                else
                    ChatProcessor(0, 0, 0, (char *)(packetBuffer + 7), *(unsigned char *)(packetBuffer + 6));
            }
        }
        break;
    case 1:
        v11 = 0;
        v31 = packetSize - 178;
        //v32 = packetBuffer + 178;
        if ( ZonePlayerCount > 0 )
        {
            while ( 1 )
            {
                if ( ZonePlayers[v11]->BillerPlayerId == *(unsigned int *)(packetBuffer + 2) )
                    break;
                ++v11;
                if ( v11 >= ZonePlayerCount )
                    return;
            }
            v14 = *(unsigned char *)(packetBuffer + 1);
            v30 = 0x0A;                             // 0x0A - Server is Full
            v34 = 0;
            switch ( v14 )
            {
            case 7:
                v30 = 0x0E;                         // 0x0E - Server Busy, try Later
                break;
            case 5:
                v30 = 0x0B;                         // 0x0B - Invalid Name
                break;
            case 4:
                v30 = 0x0A;                         // 0x0A - Server is Full
                break;
            case 1:
                v30 = 1;                            // 0x01 - Unregistered Player
                break;
            case 2:
                v30 = 2;                            // 0x02 - Bad Password
                ZonePlayers[v11]->DisconnectReason = 18;
                ZonePlayers[v11]->KickOffDelayTimer = GetTickCount() / 0xA;
                break;
            case 3:
                v30 = 4;                            // 0x04 - Locked Out of Zone
                WriteSubGameLog("Player kicked off for IP block: %s\n", ZonePlayers[v11]->PlayerName);
                ZonePlayers[v11]->DisconnectReason = 11;
                ZonePlayers[v11]->AlreadySentReliablePacket = 1;
                break;
            case 8:
                v30 = 0x10;                        // 0x10 - Restricted Zone
                ZonePlayers[v11]->CurrentWins = 0;
                ZonePlayers[v11]->CurrentDeaths = 0;
                ZonePlayers[v11]->CurrentGoals = 0;
                ZonePlayers[v11]->KillPoints = 0;
                ZonePlayers[v11]->FlagPoints = 0;
                ZonePlayers[v11]->PersonalBestWins = ZonePlayers[v11]->CurrentWins;
                ZonePlayers[v11]->PersonalBestLosses = ZonePlayers[v11]->CurrentDeaths;
                ZonePlayers[v11]->PersonalBestGoalCount = ZonePlayers[v11]->CurrentGoals;
                ZonePlayers[v11]->PersonalBestKillPoints = ZonePlayers[v11]->KillPoints;
                ZonePlayers[v11]->PersonalBestFlagPoints = ZonePlayers[v11]->FlagPoints;

                memcpy(&ZonePlayers[v11]->PlayerDataBillerPacket, &packetBuffer[6], sizeof(struct PLAYER_DATA_BILLER_PACKET_STRUCT));
                strcpy(ZonePlayers[v11]->PlayerDataBillerPacket.Name, ZonePlayers[v11]->PlayerName);
                ZonePlayers[v11]->BillerPlayerId = -1;
                if ( PermissionMode == 2 && !ZonePlayers[v11]->IsModerator ) {
                    v30 = 6;                          // 0x06 - Permission to Spectate Only
                    ZonePlayers[v11]->IsSpeced = 1;
                }
                break;
            case 0:
            case 6:
                v30 = 0;                            // 0x00 - Login OK
                if ( v14 == 6 )
                    v34 = 1;
                memcpy(&ZonePlayers[v11]->PlayerDataBillerPacket, (const void *)(packetBuffer + 6), sizeof(struct PLAYER_DATA_BILLER_PACKET_STRUCT
                                                                                                          ));
                if ( v31 == 14 )
                {
                    ZonePlayers[v11]->CurrentWins = *(unsigned short *)(packetBuffer + 178);
                    ZonePlayers[v11]->CurrentDeaths = *(unsigned short *)(packetBuffer + 180);
                    ZonePlayers[v11]->CurrentGoals = *(unsigned short *)(packetBuffer + 182);
                    ZonePlayers[v11]->KillPoints = *(unsigned int *)(packetBuffer + 184);
                    ZonePlayers[v11]->FlagPoints =  *(unsigned int *)(packetBuffer + 188);
                }
                else
                {
                    ZonePlayers[v11]->CurrentWins = 0;
                    ZonePlayers[v11]->CurrentDeaths = 0;
                    ZonePlayers[v11]->CurrentGoals = 0;
                    ZonePlayers[v11]->KillPoints = 0;
                    ZonePlayers[v11]->FlagPoints = 0;
                }
                if ( ZonePlayers[v11]->DemoPlayer )
                {
                    ZonePlayers[v11]->CurrentWins = 0;
                    ZonePlayers[v11]->CurrentDeaths = 0;
                    ZonePlayers[v11]->CurrentGoals = 0;
                    ZonePlayers[v11]->KillPoints = 0;
                    ZonePlayers[v11]->FlagPoints = 0;
                }

                ZonePlayers[v11]->PersonalBestWins = ZonePlayers[v11]->CurrentWins;
                ZonePlayers[v11]->PersonalBestLosses = ZonePlayers[v11]->CurrentDeaths;
                ZonePlayers[v11]->PersonalBestGoalCount = ZonePlayers[v11]->CurrentGoals;
                ZonePlayers[v11]->PersonalBestKillPoints = ZonePlayers[v11]->KillPoints;
                ZonePlayers[v11]->PersonalBestFlagPoints = ZonePlayers[v11]->FlagPoints;

                if ( !ZonePlayers[v11]->IsModerator )
                {
                    if ( PermissionMaxPoints && ZonePlayers[v11]->FlagPoints + ZonePlayers[v11]->KillPoints > PermissionMaxPoints )
                        v30 = 7;                        // 0x07 - Too many points to Play here
                    if ( ZonePlayers[v11]->PlayerDataBillerPacket.UsageTotalSeconds < PermissionMinimumSecondsToLogin )
                        v30 = 0x0F;                     // 0x0F - Not enough usage to play here.
                }

                if ( ZonePlayerCount > 0 )
                {
                    v32 = 0;
                    do
                    {
                        if ( ZonePlayers[v32] != ZonePlayers[v11] && !stricmp(ZonePlayers[v32]->PlayerDataBillerPacket.Name, ZonePlayers[v11]->PlayerDataBillerPacket.Name) )
                        {
                            WriteSubGameLog("Player %s already on, kicking them off (lost connection probably)\n", ZonePlayers[v11]->PlayerDataBillerPacket.Name);

                            if ( ZonePlayers[v11]->MyArena )
                            {
                                if ( !ZonePlayers[v11]->MyArena->ServersideArenaSettings.MiscTimedGame )
                                {
                                    if ( ZonePlayers[v32]->CurrentWins + ZonePlayers[v32]->KillPoints + ZonePlayers[v32]->FlagPoints + ZonePlayers[v32]->CurrentDeaths > ZonePlayers[v11]->CurrentWins + ZonePlayers[v11]->FlagPoints + ZonePlayers[v11]->KillPoints + ZonePlayers[v11]->CurrentDeaths )
                                    {
                                        ZonePlayers[v11]->CurrentWins = ZonePlayers[v32]->CurrentWins;
                                        ZonePlayers[v11]->CurrentDeaths = ZonePlayers[v32]->CurrentDeaths;
                                        ZonePlayers[v11]->CurrentGoals = ZonePlayers[v32]->CurrentGoals;
                                        ZonePlayers[v11]->KillPoints = ZonePlayers[v32]->KillPoints;
                                        ZonePlayers[v11]->FlagPoints = ZonePlayers[v32]->FlagPoints;

                                        ZonePlayers[v11]->PersonalBestWins = ZonePlayers[v32]->PersonalBestWins;
                                        ZonePlayers[v11]->PersonalBestLosses = ZonePlayers[v32]->PersonalBestLosses;
                                        ZonePlayers[v11]->PersonalBestGoalCount =  ZonePlayers[v32]->PersonalBestGoalCount;
                                        ZonePlayers[v11]->PersonalBestKillPoints =  ZonePlayers[v32]->PersonalBestKillPoints;
                                        ZonePlayers[v11]->PersonalBestFlagPoints =  ZonePlayers[v32]->PersonalBestFlagPoints;
                                    }
                                }
                            }
                            if ( ZonePlayers[v32] )
                            {
                                DisconnectUser(ZonePlayers[v32]);
                                free(ZonePlayers[v32]);
                            }

                            memcpy(
                                &ZonePlayers[v32],
                                &ZonePlayers[v32 + 1],
                                sizeof(ZonePlayers) * (ZonePlayerCount - v32 - 1));
                            --ZonePlayerCount;
                        }
                        v32++;
                    }
                    while ( v32 < ZonePlayerCount );
                }
                if ( PermissionMode == 2
                        && !ZonePlayers[v11]->IsModerator
                        && IsLineExistTextFile(PermitPointer, ZonePlayers[v11]->PlayerName) < 0 )
                {
                    v30 = 6;                          // 0x06 - Permission to Spectate Only
                    ZonePlayers[v11]->IsSpeced = 1;
                }
                break;
            default:
                break;
            }
            buf[0] = 0x0A;                          // 0x0A - Password Packet Response
            buf[1] = v30;                           // Login Response
            *(unsigned int *)&buf[2] = 134;               // Server Version
            *(unsigned int *)&buf[6] = 0;                 // ? Unknown
            *(unsigned int *)&buf[14] = 0;                // ? Unknown
            buf[18] = 0;                            // ? Unknown
            buf[19] = v34;                          // Registration Form Request (Boolean)
            *(unsigned int *)&buf[24] = NewsTxtFileChecksum;// News.txt Checksum

            *(unsigned int *)&buf[10] = Security[ZonePlayers[v11]->SubspaceEXEChecksumIndex].SubspaceEXEChecksum;// Subspace.exe Checksum
            *(unsigned int *)&buf[20] = *(unsigned int *)&Security[ZonePlayers[v11]->SubspaceEXEChecksumIndex].ScrtyData[4];
            if ( ZonePlayers[v11]->IsModerator )
            {
                *(unsigned int *)&buf[10] = -1;
                *(unsigned int *)&buf[20] = -1;
            }
            SendPlayerReliablePacket(ZonePlayers[v11], buf, 0x24, 1);
            if ( !ZonePlayers[v11]->DemoPlayer )
            {
                v30 = 0x31;                          // 0x31 - Post Login Sequence
                SendPlayerReliablePacket(ZonePlayers[v11], &v30, 1, 1);
            }
        }
        break;
    default:
        return;
    }
}
// 432004: using guessed type int RecycleServer;
// 437CA8: using guessed type int IsServerRunning;
// 438B1C: using guessed type int PermissionMode;
// 438B7C: using guessed type int PermissionMinimumSecondsToLogin;
// 4AC438: using guessed type int PermissionMaxPoints;
// 4D5914: using guessed type int NewsTxtFileChecksum;

//----- (004141F0) --------------------------------------------------------
void FormatMessageArena(struct ARENA *arena, const char *Format, ...)
{
    struct tm *timeinfo; // eax@1
    char *v3; // eax@1
    int v4; // edi@4
    struct PLAYER *v5; // esi@5
    time_t rawtime; // [sp+Ch] [bp-484h]@1
    char CurrentTimeAndDate[128]; // [sp+10h] [bp-480h]@1
    char v9[512]; // [sp+90h] [bp-400h]@4
    char Dest[512]; // [sp+290h] [bp-200h]@4
    va_list va; // [sp+49Ch] [bp+Ch]@1

    va_start(va, Format);
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strcpy(CurrentTimeAndDate, asctime(timeinfo));
    v3 = strstr(CurrentTimeAndDate, " 199");      // 199x year?
    if ( v3 || (v3 = strstr(CurrentTimeAndDate, " 200")) != 0 ) // 200x year?
        *v3 = 0;                                    // Useless code I guess, maybe Y2K bug patch lol?
    vsprintf(v9, Format, va);
    sprintf(Dest, "%s:  %s", CurrentTimeAndDate, v9);
    if ( arena->ArenaPlayerCount > 0 )
    {
        v4 = 0;
        do
        {
            v5 = arena->ArenaPlayers[v4];
            if ( v5->pfile329 )
                fprintf(v5->pfile329, "%s", Dest);
            ++v4;
        }
        while ( v4 < arena->ArenaPlayerCount );
    }
}

//----- (00414310) --------------------------------------------------------
void WriteSubGameLog(const char *Format, ...)
{
    struct tm *timeinfo; // eax@7
    char *v3; // eax@7
    int v4; // edi@12
    signed int v5; // ecx@12
    void *v6; // edx@12
    bool v7; // zf@14
    unsigned int v8; // ecx@15
    char v9; // al@15
    const void *v10; // esi@15
    void *v11; // edi@15
    const void *v12; // esi@15
    void *v13; // eax@15
    char v14; // cl@16
    time_t rawtime; // [sp+8h] [bp-484h]@7
    char v16[128]; // [sp+Ch] [bp-480h]@7
    char Dest[512]; // [sp+8Ch] [bp-400h]@10
    char v18[512]; // [sp+28Ch] [bp-200h]@10
    va_list va; // [sp+494h] [bp+8h]@1

    va_start(va, Format);
    if ( SubGameLogFileHandle )
        goto LABEL_20;
    if ( MiscServerLog )
    {
        SubGameLogFileHandle = fopen("subgame.log", "at");
    }
    if ( SubGameLogFileHandle )
    {
LABEL_20:
        if ( !MiscServerLog )
        {
            fclose(SubGameLogFileHandle);
            SubGameLogFileHandle = 0;
        }
    }
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strcpy(v16, asctime(timeinfo));
    v3 = strstr(v16, " 199");                     // 199x year?
    if ( v3 || (v3 = strstr(v16, " 200")) != 0 )  // 200x year?
        *v3 = 0;                                    // Useless code I guess, maybe Y2K patch lol?
    vsprintf(v18, Format, va);
    sprintf(Dest, "%s:  %s", v16, v18);
    if ( SubGameLogFileHandle )
        fprintf(SubGameLogFileHandle, "%s", Dest);
    printf("%s", Dest);
    v6 = &LogArray[256 * CurrentLogLine];
    strcat(v6, Dest);
    v13 = v6;
    if ( *(unsigned char *)v6 >= 32 )
    {
        do
        {
            v14 = *((unsigned char *)v13 + 1);
            v13 = (char *)v13 + 1;
        }
        while ( v14 >= 32 );
    }
    *(unsigned char *)v13 = 0;
    CurrentLogLine = (CurrentLogLine + 1) % 48;
}
// 437CA4: using guessed type int CurrentLogLine;
// 4D55CC: using guessed type int MiscServerLog;

//----- (004144C0) --------------------------------------------------------
bool __cdecl IsOffensiveName(char *a1)
{
    int v1; // esi@1
    int v2; // edi@1
    char v3; // al@4
    struct TEXT_FILE_STRUCT *v4; // ecx@5
    int v5; // edi@5
    int v6; // esi@5
    char *v7; // eax@6
    char *v8; // eax@6
    char Str[400]; // [sp+8h] [bp-190h]@1
    bool Ret;

    if ( *a1 )
    {
        v2 = 0;
        do
        {
            if ( isalpha(a1[v2]) )
                Str[v2] = toupper(a1[v2]);
            else
                Str[v2] = a1[v2];
        }
        while ( a1[v2++] );
    }
    v5 = TextFileTotalLines(ObscenePointer);
    if ( v5 <= 0 )
    {
        Ret = false;
    } else {
        v6 = 0;
        while ( 1 )
        {
            v7 = TextFileByIndex(ObscenePointer, v6);
            v8 = strstr(Str, v7);
            if ( v8 ) {
                Ret = true; // found
                break;
            }
            ++v6;
            if ( v6 >= v5 ) { // checked all on list and not found
                Ret = false;
                break;
            }
        }
    }
    return Ret;
}

//----- (00414560) --------------------------------------------------------
signed int __cdecl IsBannedIPAddress(int a1, const char *a2)
{
    int CurrentLines; // ebp@1
    int v3; // ebx@1
    int v4; // edx@1
    unsigned int v5; // kr04_4@2
    int v6; // esi@2
    int TotalLines; // eax@4
    const char *v8; // edx@9
    unsigned int v9; // ecx@10
    const char *v10; // esi@12
    const char *v11; // edi@12
    bool v12; // zf@12
    signed int result; // eax@19
    int v14; // edx@20
    unsigned int v15; // kr1C_4@21
    int v16; // esi@21
    int CurrentLinesTwo; // ebp@22
    const char *v18; // edx@25
    unsigned int v19; // ecx@26
    const char *v20; // esi@28
    const char *v21; // edi@28
    bool v22; // zf@28
    int v23; // [sp+14h] [bp-4h]@4
    int TotalLinesTwo; // [sp+14h] [bp-4h]@22
    signed int IsBanned; // [sp+1Ch] [bp+4h]@2

    CurrentLines = 0;
    if ( !Security[a1].IPAllowText )
        goto LABEL_38;
    IsBanned = 1;
    v5 = strlen(a2);

    if ( v5 == 0 )
    {
        IsBanned = 0;
    }
    else
    {
        TotalLines = TextFileTotalLines(Security[a1].IPAllowText);

        if ( TotalLines > 0 )
        {
            while ( 1 )
            {
                v8 = TextFileByIndex(Security[a1].IPBlockText, CurrentLines);
                if ( v5 >= strlen(v8) )
                    v9 = strlen(v8);
                else
                    v9 = v5;

                if ( memicmp(v8, a2, v9) )
                    IsBanned = 0;
                ++CurrentLines;
                if ( CurrentLines >= TotalLines )
                    break;
            }
        }
        else
        {
            IsBanned = 0;
        }
    }

    if ( IsBanned )
    {
        result = 1;
    }
    else
    {
LABEL_38:
        if ( Security[a1].IPBlockText == 0
                || (v15 = strlen(a2) + 1, v16 = v15 - 1, v15 == 1)
                || (CurrentLinesTwo = 0, TotalLinesTwo = TextFileTotalLines(Security[a1].IPBlockText), TotalLinesTwo <= 0) )
        {
            result = 0;
        }
        else
        {
            while ( 1 )
            {
                v18 = TextFileByIndex(Security[a1].IPBlockText, CurrentLinesTwo);
                v19 = v16 >= strlen(v18) ? strlen(v18) : v16;

                if ( memicmp(v18, a2, v19) )
                    break;
                ++CurrentLinesTwo;
                if ( CurrentLinesTwo >= TotalLinesTwo )
                    return 0;
                v16 = v15 - 1;
            }
            result = 1;
        }
    }
    return result;
}

//----- (004146D0) --------------------------------------------------------
void __cdecl SendBillerWarnings(const char *a1, struct PLAYER *player)
{
    time_t v2; // ST14_8@2
    unsigned long  v3; // ST18_4@2
    char *v4; // eax@2
    signed int v5; // ecx@3
    int v6; // edi@3
    bool v7; // zf@5
    unsigned int v8; // ecx@6
    char v9; // al@6
    const void *v10; // esi@6
    void *v11; // edi@6
    const void *v12; // esi@6
    int v13; // eax@6
    int v14; // esi@6
    struct PLAYER **v15; // ebx@7
    struct PLAYER *v16; // edx@8
    time_t v17; // [sp+0h] [bp-410h]@0
    char stringBuffer[512]; // [sp+10h] [bp-400h]@1
    char buffer[512]; // [sp+210h] [bp-200h]@3

    strcpy(stringBuffer, a1);
    if ( player )
    {
        time(&v17);
        v3 = difftime(v17, player->UsageSessionSeconds);
        v4 = GetIPAddressString(player->IPAddressDWORD);
        sprintf(stringBuffer, "%s (%s)(%d)(%s)(sec=%d)", a1, player->PlayerName, player->MachineId, v4, v3);
    }
    WriteSubGameLog("%s\n", stringBuffer);
    buffer[0] = 7;                                // 0x07 - Chat
    buffer[1] = 8;                                // Chat Type - 0x08 - Red server errors, without a name tag (S2C only)
    buffer[2] = 0;                                // Sound Byte
    *(unsigned short *)&buffer[3] = -1;                    // Originator ID
    strcat(&buffer[5], stringBuffer);                  // Chat Message
    v14 = 0;
    if ( ZonePlayerCount > 0 )
    {
        v15 = ZonePlayers;
        do
        {
            v16 = *v15;
            if ( (*v15)->MyArena && v16->IsSysop )
                SendPlayerReliablePacket(v16, buffer, strlen(stringBuffer) + 6, 1);
            ++v14;
            ++v15;
        }
        while ( v14 < ZonePlayerCount );
    }
    if ( BillingConnectionStructPointer )
    {
        if ( player )
            SendBillerWarningPacket(BillingConnectionStructPointer, player->BillerPlayerId, stringBuffer);
        else
            SendBillerWarningPacket(BillingConnectionStructPointer, 0, stringBuffer);
    }
}
// 4146D0: using guessed type char var_1FB[507];

//----- (00414850) --------------------------------------------------------
void __cdecl ChatProcessor(struct PLAYER *player, int ChatType, int arenaPlayerIndex, char *ChatText, char ChatSoundType)
{
    void *v7; // esp@1
    const char *v8; // ebx@1
    struct PLAYER *v9; // ebp@1
    int v10; // edi@5
    struct PLAYER *v11; // edx@6
    int v12; // ecx@9
    int v13; // esi@17
    int v14; // eax@33
    //const char v15; // al@36
    const char *v16; // ebx@45
    struct PLAYER *v17; // eax@50
    int v18; // esi@51
    const char *v19; // ecx@54
    int v20; // edx@56
    unsigned int v21; // eax@61
    signed int v22; // ebx@61
    struct ARENA *v23; // eax@63
    int v24; // edx@63
    int v25; // ecx@63
    int v26; // esi@64
    signed int v27; // edi@65
    int v28; // eax@66
    int v29; // ecx@66
    int v30; // esi@69
    int v31; // edi@71
    int v32; // esi@71
    signed int v33; // ecx@74
    int v34; // eax@75
    const char *v35; // edi@78
    signed int v36; // ecx@78
    signed int v37; // ecx@81
    const void *v38; // esi@81
    const char *v39; // edi@81
    unsigned int v40; // edx@81
    signed int v41; // ecx@81
    char v42; // al@89
    char *v43; // ebx@89
    char v44; // al@90
    char v45; // al@96
    char *v46; // ebx@96
    char v47; // al@97
    char v48; // al@103
    char *v49; // ebx@103
    char v50; // al@104
    int v51; // ebx@107
    const char *v52; // edx@108
    unsigned int v53; // kr48_4@108
    unsigned int v54; // kr50_4@108
    const char *v55; // edi@108
    unsigned int v56; // kr58_4@110
    const char *v57; // esi@110
    const char *v58; // edi@110
    int v59; // ecx@110
    bool v60; // zf@110
    int v61; // edi@121
    int i; // esi@121
    const char *v63; // eax@122
    signed int v64; // esi@126
    char *v65; // ebx@134
    struct PLAYER *v66; // eax@140
    int v67; // edx@141
    int v68; // ecx@141
    struct PLAYER *v69; // eax@146
    int v70; // edx@147
    int v71; // ecx@147
    char v72; // cl@153
    int v73; // eax@153
    char *j; // edx@153
    char v75; // cl@156
    char v76; // cl@157
    int v77; // eax@157
    char *k; // edx@157
    char v79; // cl@160
    char v80; // cl@161
    int v81; // eax@161
    char *l; // edx@161
    char *v83; // eax@163
    char v84; // al@171
    int v85; // esi@171
    char *m; // ecx@171
    char v87; // al@174
    char v88; // al@175
    int v89; // esi@175
    char *n; // ecx@175
    char v91; // al@180
    int v92; // esi@180
    char *ii; // ecx@180
    char *v94; // ebx@189
    char v95; // al@200
    char *v96; // ebx@200
    char v97; // al@201
    struct ARENA *v98; // eax@204
    unsigned int v99; // kr68_4@208
    int v100; // edi@208
    struct PLAYER **v101; // ebx@209
    int v102; // ebx@215
    struct PLAYER *v103; // ecx@217
    long v104; // qax@218
    int v105; // ecx@218
    long v106; // qax@218
    int v107; // ST24_4@218
    long v108; // qax@218
    struct PLAYER *v109; // esi@223
    int v110; // ST24_4@224
    int v111; // ST1C_4@224
    int v112; // ST18_4@224
    char *v113; // eax@224
    struct ARENA *v114; // eax@226
    signed int v115; // ecx@228
    int v116; // eax@228
    struct CONNECTION *v117; // ecx@230
    int v118; // edi@230
    int v119; // edx@233
    int v120; // edi@233
    float v121; // st7@233
    unsigned int v122; // eax@235
    int v123; // ecx@235
    unsigned int v124; // eax@237
    float v125; // st7@237
    int v126; // ecx@237
    int v127; // edx@239
    unsigned int v128; // edi@239
    time_t v129; // ST20_8@242
    unsigned long v130; // qax@242
    signed int v131; // edi@242
    long v132; // qax@243
    long v133; // ST20_8@243
    signed int v134; // ecx@243
    long v135; // ST18_8@243
    int v136; // ecx@247
    struct PLAYER *v137; // eax@268
    int v138; // ecx@269
    char v139; // al@276
    char *v140; // edi@276
    char v141; // al@277
    char v142; // al@279
    short v143; // ax@284
    struct PLAYER *v144; // edi@289
    struct ARENA *v145; // eax@292
    int v146; // ecx@292
    signed int v147; // edx@293
    struct PLAYER *v148; // eax@294
    struct ARENA *v149; // eax@296
    int v150; // ecx@296
    signed int v151; // edx@297
    struct PLAYER *v152; // eax@298
    struct PLAYER *v153; // eax@308
    char *v154; // eax@309
    char v155; // al@312
    char *v156; // edi@312
    char v157; // al@313
    struct ARENA *v158; // eax@318
    unsigned int v159; // kr88_4@320
    char v160; // al@323
    char *v161; // edi@323
    char v162; // al@324
    char v163; // al@330
    char *v164; // edi@330
    char v165; // al@331
    int v166; // eax@336
    short v167; // ax@342
    struct PLAYER *v168; // esi@346
    int v169; // edx@350
    char v170; // al@384
    char *v171; // edi@384
    char v172; // al@385
    struct PLAYER *v173; // esi@392
    int v174; // edx@397
    struct PLAYER *v175; // esi@403
    int v176; // edi@408
    int v177; // eax@409
    int v178; // esi@410
    int v179; // eax@410
    struct ARENA *v180; // ecx@413
    int v181; // edi@415
    struct ARENA **v182; // esi@416
    struct PLAYER *v183; // ecx@423
    int v184; // edi@427
    struct PLAYER **v185; // esi@428
    struct PLAYER *v186; // ecx@437
    struct ARENA *v187; // ecx@443
    FILE *v188; // eax@449
    const char *v189; // edi@449
    int v190; // ebx@451
    int v191; // eax@451
    FILE *v192; // eax@454
    struct ARENA *v193; // eax@455
    int v194; // esi@456
    signed int v195; // edi@457
    struct PLAYER *v196; // eax@458
    const char *v197; // esi@461
    int v198; // eax@461
    signed int v199; // edi@463
    int v200; // edx@471
    time_t v201; // ST20_8@478
    unsigned long v202; // qax@478
    signed int v203; // esi@478
    signed int v204; // ecx@481
    int v205; // edi@481
    const char *v206; // esi@481
    bool v207; // zf@481
    const char *v208; // ebx@485
    signed int v209; // ebx@490
    char *v210; // eax@491
    int v211; // ecx@491
    int v212; // edi@494
    signed int v213; // ecx@496
    signed int v214; // ecx@499
    const void *v215; // esi@499
    const char *v216; // edi@499
    unsigned int v217; // edx@499
    signed int v218; // ecx@499
    const char *v219; // edi@502
    signed int v220; // ecx@502
    signed int v221; // ecx@505
    const void *v222; // esi@505
    const char *v223; // edi@505
    unsigned int v224; // edx@505
    signed int v225; // ecx@505
    int v226; // ebx@516
    signed int v227; // esi@516
    struct ARENA *v228; // edx@520
    int v229; // eax@520
    int v230; // esi@520
    int v231; // edi@520
    int v232; // edx@520
    int v233; // ecx@524
    struct ARENA *v234; // eax@527
    int v235; // edx@527
    int v236; // ecx@527
    short v237; // ax@527
    int v238; // eax@527
    int v239; // ecx@527
    int v240; // eax@527
    int v241; // eax@540
    struct ARENA *v242; // ecx@543
    char *v243; // eax@543
    char *v244; // edx@544
    char *v245; // ebx@546
    struct struc_2 *v246; // eax@546
    struct struc_2 *v247; // esi@547
    char *v248; // esi@550
    int v249; // ebp@554
    int v250; // eax@557
    int v251; // eax@562
    signed int v252; // ecx@570
    int v253; // edi@570
    const char *v254; // esi@570
    bool v255; // zf@570
    int v256; // eax@575
    const char *v257; // edx@578
    struct ARENA *v258; // ecx@585
    signed int v259; // ebx@586
    struct PLAYER *v260; // ecx@587
    signed int v261; // esi@587
    long v262; // qax@590
    long v263; // qax@591
    int v264; // edi@602
    signed int v265; // ecx@604
    signed int v266; // ecx@607
    const void *v267; // esi@607
    const char *v268; // edi@607
    unsigned int v269; // edx@607
    signed int v270; // ecx@607
    const char *v271; // edi@610
    signed int v272; // ecx@610
    signed int v273; // ecx@613
    const void *v274; // esi@613
    const char *v275; // edi@613
    unsigned int v276; // edx@613
    signed int v277; // ecx@613
    int v278; // edx@617
    int v279; // ecx@621
    int v280; // edx@638
    char *v281; // ebx@638
    unsigned int v282; // ebx@646
    struct PLAYER *v283; // eax@646
    signed int v284; // ecx@654
    signed int v285; // ecx@658
    signed int v286; // ecx@662
    signed int v287; // ecx@671
    int v288; // edi@671
    const char *v289; // esi@671
    bool v290; // zf@671
    signed int v291; // ecx@675
    int v292; // edi@675
    const char *v293; // esi@675
    bool v294; // zf@675
    signed int v295; // ecx@682
    int v296; // eax@683
    char v297; // al@688
    char *v298; // edi@688
    char *jj; // ecx@688
    char v300; // al@691
    char v301; // al@692
    int v302; // edi@692
    char *kk; // ecx@692
    char v304; // al@696
    int *v305; // edi@704
    int *v306; // esi@704
    int v307; // al@707 FIX
    int v308; // ecx@708
    int v309; // edi@708
    int v310; // esi@708
    const char *v311; // eax@709
    struct ARENA *v312; // edi@711
    struct ARENA *v313; // ecx@718
    int v314; // eax@718
    int v315; // eax@723
    long v316; // qax@727
    long v317; // qax@728
    long v318; // qax@729
    const char *v319; // ebx@730
    struct CHAT * v320; // edi@737
    int v322; // esi@737
    struct ARENA *v323; // eax@738
    struct ARENA *v324; // eax@743
    char *v325; // eax@748
    int v326; // edx@749
    struct PLAYER *v327; // esi@749
    bool v328; // sf@749
    struct ARENA **v329; // edi@750
    struct ARENA *v330; // eax@751
    int v331; // ebx@751
    signed int v332; // esi@752
    unsigned int v333; // krD8_4@774
    struct ARENA **v334; // esi@775
    int v335; // ebp@776
    signed int v336; // edi@777
    struct ARENA *v337; // edx@784
    int v338; // esi@785
    unsigned int v339; // ecx@785
    char *v340; // ecx@797
    char v341; // al@799
    char *ll; // edx@799
    char v343; // al@803
    char v344; // al@804
    const char *v345; // ecx@804
    int v346; // eax@819
    int v347; // eax@833
    unsigned int v348; // krE8_4@836
    int v349; // edi@836
    struct PLAYER **v350; // ebp@837
    char *v351; // [sp+4h] [bp-1608Ch]@668
    const char *v352; // [sp+8h] [bp-16088h]@668
    char *v353; // [sp+Ch] [bp-16084h]@52
    char *v354; // [sp+Ch] [bp-16084h]@351
    char *v355; // [sp+Ch] [bp-16084h]@598
    char *v356; // [sp+Ch] [bp-16084h]@644
    int v357; // [sp+Ch] [bp-16084h]@668
    const char *v358; // [sp+10h] [bp-16080h]@52
    const char *v359; // [sp+10h] [bp-16080h]@57
    const char *v360; // [sp+10h] [bp-16080h]@218
    const char *v361; // [sp+10h] [bp-16080h]@351
    int v362; // [sp+10h] [bp-16080h]@525
    const char *v363; // [sp+10h] [bp-16080h]@598
    const char *v364; // [sp+10h] [bp-16080h]@644
    int v365; // [sp+10h] [bp-16080h]@668
    int v366; // [sp+14h] [bp-1607Ch]@52
    char v367; // [sp+14h] [bp-1607Ch]@54
    char v368; // [sp+14h] [bp-1607Ch]@218
    int v369; // [sp+14h] [bp-1607Ch]@351
    int v370; // [sp+14h] [bp-1607Ch]@525
    int v371; // [sp+14h] [bp-1607Ch]@598
    char *v372; // [sp+14h] [bp-1607Ch]@644
    int v373; // [sp+14h] [bp-1607Ch]@668
    time_t v374; // [sp+18h] [bp-16078h]@1
    float a5; // [sp+28h] [bp-16068h]@63
    int a6; // [sp+2Ch] [bp-16064h]@69
    int v376; // [sp+30h] [bp-16060h]@69
    int v377; // [sp+34h] [bp-1605Ch]@61
    DWORD ExitCode; // [sp+38h] [bp-16058h]@233
    char v379; // [sp+3Fh] [bp-16051h]@420
    size_t Size; // [sp+40h] [bp-16050h]@69
    int v381; // [sp+44h] [bp-1604Ch]@233
    int v382; // [sp+48h] [bp-16048h]@69
    int v383; // [sp+4Ch] [bp-16044h]@69
    char v384[15]; // [sp+50h] [bp-16040h]@527
    int v390; // [sp+60h] [bp-16030h]@233
    char KeyName[256]; // [sp+64h] [bp-1602Ch]@157
    char Buffer[256]; // [sp+84h] [bp-1600Ch]@52
    char v393; // [sp+85h] [bp-1600Bh]@773
    short v395; // [sp+185h] [bp-15F0Bh]@342
    char v396; // [sp+187h] [bp-15F09h]@342
    char Str1[64]; // [sp+284h] [bp-15E0Ch]@153
    char AppName[64]; // [sp+2C4h] [bp-15DCCh]@76
    char buf[273]; // [sp+304h] [bp-15D8Ch]@45
    char v400; // [sp+309h] [bp-15D87h]@208
    char v401; // [sp+404h] [bp-15C8Ch]@255
    char v402; // [sp+405h] [bp-15C8Bh]@255
    char v403; // [sp+414h] [bp-15C7Ch]@255
    int v405; // [sp+510h] [bp-15B80h]@309
    char v415; // [sp+2815h] [bp-1387Bh]@546
    int v416; // [sp+16084h] [bp-Ch]@1
    //int (__cdecl *v417)(struct EHExceptionRecord *, struct EHRegistrationNode *, int, int); // [sp+16088h] [bp-8h]@1
    int v418; // [sp+1608Ch] [bp-4h]@1
    const char *Buf1b; // [sp+160A0h] [bp+10h]@485
    const char *Buf1a; // [sp+160A0h] [bp+10h]@489

    char CommandLine[256]; //fix1
    STARTUPINFO StartupInfo; //fix2
    char FileTransferBuffer[17]; //fix3  [sp+2804h] [bp-1388Ch]@543
    struct TEMPLATE_SSS * templatePtr; //fix4
    char buffer3[256]; //fix 5 [sp+504h] [bp-15B8Ch]@163
    char Dest[256]; //fix 6 [sp+184h] [bp-15F0Ch]@69
    char v406[6]; //fix 7 [sp+604h] [bp-15A8Ch]@741
    char v411[6]; //fix 8 [sp+804h] [bp-1588Ch]@638
    int a7; //fix 9


    v418 = -1;
    //v417 = sub_4288DE;
    //v7 = alloca(0x1605C); //char v7[0x1605C];
    if ( player && player->IsModerator && *ChatText == '8' || strlen(ChatText) > 250 ) //Chat max text 250 characters
        return;
    SomethingWithSendingChatTypes(player, ChatType, arenaPlayerIndex, ChatText, ChatSoundType);
    if ( player )
    {
        v11 = 0;
        if ( arenaPlayerIndex >= 0 && arenaPlayerIndex < 1024 )
            v11 = ZonePlayerList[arenaPlayerIndex];
        v12 = BillingLogMessages;
        if ( BillingLogMessages <= player->PlayerDataBillerPacket.Extra2 )
            v12 = player->PlayerDataBillerPacket.Extra2;
        if ( v11 && v11->PlayerDataBillerPacket.Extra2 )
        {
            if ( v12 )
            {
LABEL_17:
                v13 = -1;
                switch ( ChatType )
                {
                case 9: //0x09 - Channel message a [X;Whatever]
                    v13 = -4;
                    break;
                case 3: //0x03 - Team message [// or ']
                    v13 = -2;
                    break;
                case 5: //0x05 - Private message [/Whatever]
                    if ( v11 )
                        v13 = v11->PlayerDataBillerPacket.UserId;
                    break;
                case 4: //0x04 - Player to all members of another team ["Whatever]
                    v13 = -3;
                    break;
                default:
                    break;
                }
                if ( v12 == 3
                        || v12 == 2 && (ChatType == 3 || ChatType == 4 || ChatType == 5 || ChatType == 9 || *ChatText == '*')
                        || v12 == 1 && (ChatType == 5 || *ChatText == '*') ) //0x05 - Private message [/Whatever]
                {
                    v14 = player->PlayerDataBillerPacket.UserId;
                    if ( v14 >= 0 )
                    {
                        if ( BillingConnectionStructPointer )
                            SendBillerUnknownPacket(BillingConnectionStructPointer, v14, v13, ChatText);
                    }
                }
                goto LABEL_36;
            }
            if ( *ChatText != '*' )
                v12 = 1;
        }
        if ( !v12 )
            goto LABEL_36;
        goto LABEL_17;
    }
LABEL_36:
    if ( *ChatText == '*' && player ) //All staff commands go in this massive if statement
    {
        if( !stricmp(ChatText + 1, SysopPassword) )
        {
            WriteSubGameLog("%s> SYSOP LOGGED IN\n", player->PlayerDataBillerPacket.Name);
            player->IsSysop = 1;
            player->IsModerator = 1;
            player->IsSuperModerator = 1;
        }
        if ( !stricmp(ChatText + 1, SuperModeratorPassword) )
        {
            WriteSubGameLog("%s> SUPER MODERATOR LOGGED IN\n", player->PlayerDataBillerPacket.Name);
            player->IsModerator = 1;
            player->IsSuperModerator = 1;
        }
        if ( !stricmp(ChatText + 1, ModeratorPassword) )
        {
            WriteSubGameLog("%s> MODERATOR LOGGED IN\n", player->PlayerDataBillerPacket.Name);
            player->IsModerator = 1;
        }
        if ( !stricmp(ChatText + 1, EnergyPassword) )
        {
            WriteSubGameLog("%s> ENERGY VIEWING TURNED ON/OFF\n", player->PlayerDataBillerPacket.Name);
            if ( player->MyArena )
            {
                player->IsEnergyShowing = !player->IsEnergyShowing;
                if ( player->IsEnergyShowing )
                    SendArenaMessage(player, "Showing Energy OFF", 0);
                else
                    SendArenaMessage(player, "Showing Energy ON", 0);
            }
        }

        if( player->IsModerator ) {
            //Moderator Commands
            if ( memicmp(ChatText, "*arena", 6) )
            {
                v155 = ChatText[6];
                v156 = ChatText + 6;
                ChatText += 6;
                if ( v155 == ' ' )
                {
                    do
                        v157 = (v156++)[1];
                    while ( v157 == ' ' );
                    ChatText = v156;
                }
                if ( *v156 == '_' )
                    *v156 = ' ';
                if ( player )
                {
                    v158 = player->MyArena;
                    if ( v158 )
                        FormatMessageArena(v158, "%s\n", v156);
                }
                buf[2] = ChatSoundType;
                strcpy(&buf[5], ChatText);
                buf[0] = 7;
                buf[1] = 0;
                *(unsigned short *)&buf[3] = -1;
                v159 = strlen(ChatText) + 1;
                if ( player )
                {
                    SendArenaPacket(player->MyArena, buf, v159 + 5, 1);
                    return;
                }
                return;
            }
            else if ( !memicmp(ChatText, "*permit", 7) )
            {
                v160 = ChatText[7];
                v161 = ChatText + 7;
                ChatText += 7;
                if ( v160 == ' ' )
                {
                    do
                        v162 = (v161++)[1];
                    while ( v162 == ' ' );
                    ChatText = v161;
                }
                if ( *v161 )
                {
                    AddLineTextFile(PermitPointer, v161);
                    WriteTextFileToFile(PermitPointer);
                    if ( !player )
                        return;
                    sprintf(Buffer, "Permission Added: %s", v161);
                    SendArenaMessage(player, Buffer, 0);
                }
                return;
            }
            else if ( memicmp(ChatText, "*revoke", 7) )
            {
                v163 = ChatText[7];
                v164 = ChatText + 7;
                ChatText += 7;
                if ( v163 == ' ' )
                {
                    do
                        v165 = (v164++)[1];
                    while ( v165 == ' ' );
                    ChatText = v164;
                }
                if ( *v164 )
                {
                    if ( strcmp(v164, "*") )
                    {
                        v166 = IsLineExistTextFile(PermitPointer, v164);
                        if ( v166 >= 0 )
                            RemoveLineTextFile(PermitPointer, v166);
                    }
                    else
                    {
                        CleanTextFileMemory(PermitPointer);
                    }
                    WriteTextFileToFile(PermitPointer);
                    if ( !player )
                        return;
                    SendArenaMessage(player, "Permission revoked", 0);
                }
            }
            else if ( memicmp(ChatText, "*beginlog", 9) )
            {
                v188 = player->pfile329;
                v189 = ChatText + 9;
                ChatText += 9;
                if ( v188 )
                    fclose(v188);
                v190 = rand();
                v191 = rand();
                sprintf(&player->char32d, "SS%d.log", v191 + v190);
                player->pfile329 = fopen(&player->char32d, "wt");
                sprintf(Dest, "Logging session to: %s", &player->char32d);
                SendArenaMessage(player, Dest, 0);
                fprintf(player->pfile329, "LOG STARTED:%s\n", v189);
            }
            else if ( !memicmp(ChatText, "*endlog", 7u) )
            {
                if ( !player )
                    return;
                v192 = player->pfile329;
                if ( v192 )
                {
                    fprintf(v192, "Name               Win  Lose  Points\n");
                    fprintf(player->pfile329, "---------------- ----- ----- -------\n");
                    if ( player->MyArena )
                    {
                        v194 = 0;
                        if ( player->MyArena->ArenaPlayerCount > 0 )
                        {
                            do
                            {
                                v196 = player->MyArena->ArenaPlayers[v194];
                                fprintf(
                                    player->pfile329,
                                    "%-16.16s %5d %5d %7d\n",
                                    v196->PlayerDataBillerPacket.Name,
                                    v196->CurrentWins,
                                    v196->CurrentDeaths,
                                    v196->FlagPoints + v196->KillPoints);
                                ++v194;
                            }
                            while ( v194 < player->MyArena->ArenaPlayerCount );
                        }
                    }
                    fprintf(player->pfile329, "\nLOG FINISHED\n");
                    fclose(player->pfile329);
                    player->pfile329 = 0;
                    sprintf(
                        Dest,
                        "Logging session closed, sending file: %s",
                        &player->char32d);
                    SendArenaMessage(player,Dest, 0);
                    GetServerFile(player, &player->char32d);
                }
            }
            else if ( memicmp(ChatText, "*shipreset", 10) )
            {
                v379 = 27;
                if ( ChatType == 5 ) //0x05 - Private message [/Whatever]
                {
                    if ( player )
                        SendArenaMessage(player, "Player ship reset", 0);
                    v183 = ZonePlayerList[arenaPlayerIndex];
                    if ( v183 )
                        SendPlayerReliablePacket(v183, &v379, 1u, 1);
                }
                else
                {
                    if ( player )
                    {
                        SendArenaMessage(player, "All ships reset", 0);
                        SendArenaPacket(player->MyArena, &v379, 1, 1);
                    }
                    else
                    {
                        v184 = 0;
                        if ( ZonePlayerCount > 0 )
                        {
                            v185 = ZonePlayers;
                            do
                            {
                                if ( (*v185)->MyArena )
                                    SendPlayerReliablePacket(*v185, &v379, 1u, 1);
                                ++v184;
                                ++v185;
                            }
                            while ( v184 < ZonePlayerCount );
                        }
                    }
                }
            }
            else if ( memicmp(ChatText, "*scorereset", 11) )
            {
                if ( ChatType == 5 ) //0x05 - Private message [/Whatever]
                {
                    if ( player )
                        SendArenaMessage(player, "Player score reset", 0);
                    v186 = ZonePlayerList[arenaPlayerIndex];
                    if ( v186 )
                        SendResetScoresPacket(v186);
                }
                else
                {
                    if ( !player )
                        return;
                    ArenaScoreReset(player->MyArena, 1);
                }
            }
            else if ( memicmp(ChatText, "*flagreset", 10) )
            {
                if ( player )
                {
                    SendArenaMessage(player, "Flag game being reset", 0);
                    v180 = player->MyArena;
                    if ( v180 )
                        ResetJackpotFlags(v180);
                }
                else
                {
                    v181 = 0;
                    if ( ArenaArrayLength > 0 )
                    {
                        v182 = Arenas;
                        do
                        {
                            ResetJackpotFlags(*v182);
                            ++v181;
                            ++v182;
                        }
                        while ( v181 < ArenaArrayLength );
                    }
                }
            }
            else if ( memicmp(ChatText, "*timereset", 10) )
            {
                if ( !player )
                    return;
                v187 = player->MyArena;
                if ( v187 )
                {
                    if ( v187->ServersideArenaSettings.MiscTimedGame <= 0 )
                        SendArenaMessage(player, "Invalid command, this is not a timed game", 0);
                    else
                        sub_405360(v187, 1);
                }
            }
            else if ( memicmp(ChatText, "*banner", 7) )
            {
                player->ForceWearBanner = 1;
                Dest[0] = 0x1F;     //0x1F - Player Banner Changed
                *(unsigned short *)&Dest[1] = player->PlayerId;
                memcpy(&Dest[3], player->PlayerDataBillerPacket.BannerData, sizeof(player->PlayerDataBillerPacket.BannerData));
                SendArenaPacket(player->MyArena, Dest, 99, 1);
            }
            else if ( memicmp(ChatText, "*lock", 5) ) {
                if(player->MyArena) {
                    player->MyArena->ArenaLocked = !player->MyArena->ArenaLocked;
                    if ( player->MyArena->ArenaLocked )
                        SendArenaMessage(player, "Arena LOCKED", 0);
                    else
                        SendArenaMessage(player, "Arena UNLOCKED", 0);
                }
            }
            else if ( memicmp(ChatText, "*lockspec", 9) ) {
                if(player->MyArena) {
                    player->MyArena->SpecMessageLock = !player->MyArena->SpecMessageLock;
                    if ( player->MyArena->SpecMessageLock )
                        SendArenaMessage(player, "Message lock applies to spectators only.", 0);
                    else
                        SendArenaMessage(player, "Message lock applies to everybody.", 0);
                }
            }
            else if ( memicmp(ChatText, "*lockteam", 9) ) {
                if(player->MyArena) {
                    player->MyArena->AllMessagesLocked = !player->MyArena->AllMessagesLocked;
                    if ( player->MyArena->AllMessagesLocked )
                        SendArenaMessage(player, "Team Messages LOCKED", 0);
                    else
                        SendArenaMessage(player, "Team Messages UNLOCKED", 0);
                }
            }
            else if ( memicmp(ChatText, "*lockprivate", 12) ) {
                if(player->MyArena) {
                    player->MyArena->PrivateMessagesLocked = !player->MyArena->PrivateMessagesLocked;
                    if ( player->MyArena->PrivateMessagesLocked )
                        SendArenaMessage(player, "Private Messages LOCKED", 0);
                    else
                        SendArenaMessage(player, "Private Messages UNLOCKED", 0);
                }
            }
            else if ( memicmp(ChatText, "*lockpublic", 11) ) {
                if(player->MyArena) {
                    player->MyArena->AllMessagesLocked = !player->MyArena->AllMessagesLocked;
                    if ( player->MyArena->AllMessagesLocked )
                        SendArenaMessage(player, "Public Messages LOCKED", 0);
                    else
                        SendArenaMessage(player, "Public Messages UNLOCKED", 0);
                }
            }
            else if ( memicmp(ChatText, "*lockall", 8) ) {
                if(player->MyArena) {
                    player->MyArena->AllMessagesLocked = !player->MyArena->AllMessagesLocked;
                    player->MyArena->AllMessagesLockedAgainSomething = player->MyArena->AllMessagesLocked;
                    if ( player->MyArena->AllMessagesLocked )
                        SendArenaMessage(player, "All Messages LOCKED", 0);
                    else
                        SendArenaMessage(player, "All Messages UNLOCKED", 0);
                }
            }
            else if ( memicmp(ChatText, "*timer", 6) )
            {
                v170 = ChatText[6];
                v171 = ChatText + 6;
                ChatText += 6;
                if ( v170 == ' ' )
                {
                    do
                        v172 = (v171++)[1];
                    while ( v172 == ' ' );
                    ChatText = v171;
                }
                if ( *v171 )
                {
                    player->MyArena->GameTimeStart = 6000 * atoi(v171);
                    player->MyArena->GameTimePassed = GetTickCount() / 0xA;
                    player->MyArena->field_FF56 = 0;
                }
            }
            else if ( memicmp(ChatText, "*kill", 5) )
            {
                if ( ChatType == 5 ) //0x05 - Private message [/Whatever]
                {
                    v175 = ZonePlayerList[arenaPlayerIndex];
                    if ( v175 )
                    {
                        if ( player->IsSysop || !v175->IsSuperModerator )
                        {
                            v175->DisconnectReason = 4;
                            v175->AlreadySentReliablePacket = 1;
                            WriteSubGameLog("Player kicked off by moderator: %s\n", v175->PlayerDataBillerPacket.Name);
                            SendArenaMessage(player, "Player kicked off", 0);
                            if ( ChatText[5] == ' ' )
                            {
                                v176 = atoi(ChatText + 6);
                                if ( v176 > 0 )
                                {
                                    v177 = MachineIdArrayCount;
                                    if ( MachineIdArrayCount < 1000 )
                                    {
                                        KickedUsers[MachineIdArrayCount].MachineId = v175->MachineId;
                                        v178 = v177;
                                        KickedUsers[v177].KickStartTime = GetTickCount() / 0xA;
                                        v179 = MachineIdArrayCount + 1;
                                        KickedUsers[v178].KickDelayMilliseconds = 6000 * v176;
                                        MachineIdArrayCount = v179;
                                    }
                                }
                            }
                        } else {
                            SendArenaMessage(v175, "Moderator attempted to kick you off", 0);
                        }
                    }
                }
            }
            else if ( memicmp(ChatText, "*shutup", 7) ) {
                if ( ChatType == 5 )  //0x05 - Private message [/Whatever]
                {
                    if ( ZonePlayerList[arenaPlayerIndex] )
                    {
                        v168 = ZonePlayerList[arenaPlayerIndex];
                        if ( v168->IsSysop || v168->IsSuperModerator && !player->IsSysop )
                        {
                            sprintf(Dest, "%s tried to shut you up", player->PlayerDataBillerPacket.Name);
                            SendArenaMessage(v168, Dest, 0);
                        } else  {
                            v168->IsSilenced = !v168->IsSilenced;
                            if ( v169 ) {
                                v369 = (int)v168->PlayerDataBillerPacket.Name;
                                v361 = "%s can now speak";
                                v354 = Dest;
                            } else {
                                v369 = (int)v168->PlayerDataBillerPacket.Name;
                                v361 = "%s has been silenced";
                                v354 = Dest;
                            }
                            sprintf(v354, v361, v369);
                            SendArenaMessage(player, Dest, 0);
                        }
                    }
                }
            }
            else if ( memicmp(ChatText, "*spec", 5) )
            {
                if ( ChatType == 5 ) //0x05 - Private message [/Whatever]
                {
                    v173 = ZonePlayerList[arenaPlayerIndex];
                    if ( v173 )
                    {
                        if ( player->IsSysop || !v173->IsSuperModerator )
                        {
                            if ( v173->Ship != 8 )
                                SetPlayerShip(v173, 8);
                            v174 = v173->IsSpeced;
                            v173->IsSpeced = v174 == 0;
                            if ( v174 )
                                SendArenaMessage(player, "Player free to enter arena", 0);
                            else
                                SendArenaMessage(player, "Player locked in spectator mode", 0);
                        }
                    }
                }
            }
        } else if( player->IsSuperModerator  ) {
            //Super Moderator Commands

            if ( !memicmp(ChatText, "*szone", 6) )
            {
                v94 = ChatText + 6;
                if ( ChatText[6] == ' ' )
                    v94 = ChatText + 7;
                if ( *v94 == '_' )
                    *v94 = ' ';
                if ( player->IsSysop || *v94 != '*' || !memicmp(v94, "*permit", 7) || !memicmp(v94, "*revoke", 7) )
                {
                    strcpy(&buf[2], v94);
                    buf[1] = ChatSoundType;
                    buf[0] = 2;
                    if ( BillingConnectionStructPointer )
                        SendBillerZoneRevokePermitPacket(
                            BillingConnectionStructPointer,
                            player->BillerPlayerId,
                            BillingScoreId,
                            buf,
                            strlen(v94) + 3);
                }
                return;
            }
            else if ( !memicmp(ChatText, "*zone", 5) )
            {
                v95 = ChatText[5];
                v96 = ChatText + 5;
                ChatText += 5;
                if ( v95 == ' ' )
                {
                    do
                        v97 = (v96++)[1];
                    while ( v97 == ' ' );
                    ChatText = v96;
                }
                if ( player )
                {
                    if ( player->MyArena )
                        FormatMessageArena(player->MyArena, "%s\n", v96);
                }
                if ( *v96 == '_' )
                    *v96 = ' ';
                strcpy(&buf[5], v96);
                buf[2] = ChatSoundType;
                buf[0] = 7;
                buf[1] = 0;
                *(unsigned short *)&buf[3] = -1;
                v99 = strlen(v96) + 1;
                v100 = 0;
                if ( ZonePlayerCount > 0 )
                {
                    do
                    {
                        if ( ZonePlayers[v100]->MyArena )
                            SendPlayerReliablePacket(ZonePlayers[v100], buf, v99 - 1 + 6, 1);
                        ++v100;
                    }
                    while ( v100 < ZonePlayerCount );
                }
                return;
            }
            else if ( memicmp(ChatText, "*getlist", 8) || player == 0 )
            {
                SendArenaMessage(player, "File sent: permit.txt (please wait...)", 0);
                GetServerFile(player, "permit.txt");
                return;
            }
            else if ( memicmp(ChatText, "*putlist", 8) || player == 0 )
            {
                buf[0] = 25;
                strncpy(&buf[1], "permit.txt", 0x100);
                buf[256] = 0;
                strncpy(&buf[257], "permit.txt", 0x10);
                buf[272] = 0;
                SendPlayerReliablePacket(player, buf, 273, 1);
                return;
            }
            else if ( memicmp(ChatText, "*getmodlist", 11) || player == 0 )
            {
                SendArenaMessage(player, "File sent: moderate.txt (please wait...)", 0);
                GetServerFile(player, "moderate.txt");
                return;
            }
            else if ( memicmp(ChatText, "*putmodlist", 11) || player == 0 )
            {
                buf[0] = 25;
                strncpy(&buf[257], "moderate.txt", 0x10);
                buf[272] = 0;
                strncpy(&buf[1], "moderate.txt", 0x100);
                buf[256] = 0;
                SendPlayerReliablePacket(player, buf, 273, 1);
                return;
            }
            else if ( !memicmp(ChatText, "*recycle", 8) )
            {
                if ( player != 0 )
                    SendArenaMessage(player, "Recycling Server", 0);
                RecycleServer = 1;
                return;
            }
            else if ( !memicmp(ChatText, "*restart", 8) )
            {
                if ( player->ProcessInformation != 0
                        && GetExitCodeProcess(player->ProcessInformation->hProcess, &ExitCode) )
                {
                    if ( ExitCode == 259 )
                        TerminateProcess(player->ProcessInformation->hProcess, 0);
                    CloseHandle(player->ProcessInformation->hProcess);
                    player->ProcessInformation = 0;
                    player->dword4 = 0;
                    player->dword8 = 0;
                    player->dwordC = 0;
                }
                player->MyArena->LastTimedGameTime = 0; //TODO WHERE THIS BELONG?
                return;
            }
            else if ( !memicmp(ChatText, "*prize", 6) )
            {
                v139 = ChatText[6];
                v140 = ChatText + 6;
                ChatText += 6;
                if ( v139 == ' ' )
                {
                    do
                        v141 = (v140++)[1];
                    while ( v141 == ' ' );
                    ChatText = v140;
                }
                v142 = *v140;
                v60 = *v140 == '#';
                buf[0] = 0x20; //0x20 - Collect prize or get prized or buy item
                *(unsigned short *)&buf[3] = 0;
                *(unsigned short *)&buf[1] = 1;

                if ( v60 )
                {
                    *(unsigned short *)&buf[3] = atoi((const char *)(v140 + 1));
                }
                else
                {
                    if ( isdigit(v142) )
                        *(unsigned short *)&buf[1] = atoi((const char *)v140);
                }
                if ( player->IsSysop == 0 )
                {
                    v143 = *(unsigned short *)&buf[1];
                    *(unsigned short *)&buf[1] = 100;
                    if ( v143 <= 100 )
                        *(unsigned short *)&buf[1] = v143;
                }
                if ( player != 0 )
                    SendArenaMessage(player, "Granting prize(s)", 0);
                if ( ChatType == 5 ) //0x05 - Private message [/Whatever]
                {
                    v144 = ZonePlayerList[arenaPlayerIndex];
                    if ( v144 != 0 )
                    {
                        SendPlayerReliablePacket(v144, buf, 5, 1);
                        v144->field_305 = 1;
                    }
                }
                else
                {
                    if ( ChatType == 3 ) //0x03 - Team message [// or ']
                    {
                        SendPacketToMyFrequency(player, buf, 5, 1);
                        SendPlayerReliablePacket(player, buf, 5, 1);
                        if ( player->MyArena->ArenaPlayerCount > 0 )
                        {
                            v146 = 0;
                            do
                            {
                                v148 = player->MyArena->ArenaPlayers[v146];
                                ++v146;
                                v148->field_305 = 1;
                            }
                            while ( v146 < player->MyArena->ArenaPlayerCount );
                        }
                    }
                    else
                    {
                        SendArenaPacket(player->MyArena, buf, 5, 1);
                        v150 = 0;
                        if ( player->MyArena->ArenaPlayerCount > 0 )
                        {
                            do
                            {
                                v152 = player->MyArena->ArenaPlayers[v150];
                                ++v150;
                                v152->field_305 = 1;
                            }
                            while ( v150 < player->MyArena->ArenaPlayerCount );
                        }
                    }
                }
                return;
            }
            else if ( !memicmp(ChatText, "*info", 5) ) {
                if ( ChatType == 5 && ZonePlayerList[arenaPlayerIndex] ) { //0x05 - Private message [/Whatever]
                    v109 = ZonePlayerList[arenaPlayerIndex];
                    sprintf(
                        Buffer,
                        "IP:%s  TimeZoneBias:%d  Freq:%d  TypedName:%s  Demo:%d",
                        GetIPAddressString(v109->IPAddressDWORD),
                        v109->TimeZoneBias,
                        v109->Frequency,
                        v109->TypedName,
                        v109->DemoPlayer != 0);
                    if ( player->IsSysop )
                        sprintf(Buffer + strlen(Buffer), "  MachineId:%d", v109->MachineId);
                    SendArenaMessage(player, Buffer, 0);
                    if ( player->MyArena->ServersideArenaSettings.KingDeathCount > 0 )
                    {
                        sprintf(
                            Buffer,
                            "DeathsLeft:%d  KillsNeeded:%d",
                            v109->KotHDeathCount,
                            player->MyArena->ServersideArenaSettings.KingCrownRecoverKills - v109->KingCrownKills);
                        SendArenaMessage(player, Buffer, 0);
                    }
                    sprintf(
                        Buffer,
                        "Ping:%dms  LowPing:%dms  HighPing:%dms  AvePing:%dms",
                        10 * v109->SecurityPacketCache.CurrentPing,
                        10 * v109->SecurityPacketCache.LowPing,
                        10 * v109->SecurityPacketCache.HighPing,
                        10 * v109->SecurityPacketCache.AveragePing);
                    SendArenaMessage(player, Buffer, 0);
                    sprintf(
                        Buffer,
                        "S2CAveLatency:%dms  C2SAveLatency:%dms",
                        v109->SecurityPacketCache.S2CAverageLatency,
                        10 * v109->C2SAverageLatencyFirst / (v109->C2SAverageLatencySecond + 1));
                    v116 = 1000;
                    if ( v109->SecurityWeaponCountTotal > 200 )
                        v116 = 1000 * v109->SecurityWeaponCount / v109->SecurityWeaponCountTotal;
                    GetPingLOSSSomething(v109->connection, &a6, &v377);
                    v118 = GetBillingServerRelOut(v109->connection, &v383);
                    sprintf(
                        Buffer,
                        "LOSS: S2C:%.1f%%  C2S:%.1f%%",
                        (double)(1000 - a6) * 0.1, (double)(1000 - v377) * 0.1);
                    if ( player->IsSysop != 0 )
                        sprintf(
                            Buffer + strlen(Buffer),
                            "  S2CWeapons:%.1f%%  S2C_RelOut:%d(%d)",
                            (double)(1000 - v116) * 0.1,
                            v118,
                            v383);
                    SendArenaMessage(player, Buffer, 0);
                    if ( player->IsSuperModerator )
                    {
                        GetPacketCountInfoSomething(
                            v109->connection,
                            &v390,
                            &v376,
                            &Size,
                            &v382);
                        sprintf(Buffer, "S2C:%d-->%d  C2S:%d-->%d", v390, v382, Size, v376);
                        SendArenaMessage(player, Buffer, 0);

                        v121 = 0.0;
                        a5 = 0.0;

                        if ( (v109->C2SCurrentSlow + v109->C2SCurrentFast) > 0 )
                            a5 = (double)v109->C2SCurrentSlow * 100.0 / (double)(v109->C2SCurrentSlow + v109->C2SCurrentFast);

                        if ( (v109->C2SCurrentTotalFast + v109->C2SCurrentTotalSlow) > 0 )
                            v121 = (double)(signed int)v109->C2SCurrentTotalSlow * 100.0 / (double)(v109->C2SCurrentTotalFast + v109->C2SCurrentTotalSlow);

                        sprintf(
                            Buffer,
                            "C2S CURRENT: Slow:%d Fast:%d %.1f%%   TOTAL: Slow:%d Fast:%d %.1f%%",
                            v109->C2SCurrentSlow,
                            v109->C2SCurrentFast,
                            a5,
                            v109->C2SCurrentTotalSlow,
                            v109->C2SCurrentTotalFast,
                            v121);
                        SendArenaMessage(player, Buffer, 0);

                        v125 = 0.0;
                        a5 = 0.0;
                        v381 = v109->SecurityPacketCache.S2CCurrentFast + v109->SecurityPacketCache.S2CCurrentSlow;
                        if ( v381 > 0 )
                            a5 = (double)v109->SecurityPacketCache.S2CCurrentSlow * 100.0 / (double)v381;
                        v381 = v109->SecurityPacketCache.S2CCurrentTotalSlow + v109->SecurityPacketCache.S2CCurrentTotalFast;
                        if ( v381 > 0 )
                            v125 = (double)v109->SecurityPacketCache.S2CCurrentTotalSlow * 100.0 / (double)v381;
                        sprintf(
                            Buffer,
                            "S2C CURRENT: Slow:%d Fast:%d %.1f%%   TOTAL: Slow:%d Fast:%d %.1f%%",
                            v109->SecurityPacketCache.S2CCurrentSlow,
                            v109->SecurityPacketCache.S2CCurrentFast,
                            a5,
                            v109->SecurityPacketCache.S2CCurrentTotalSlow,
                            v109->SecurityPacketCache.S2CCurrentTotalFast,
                            v125);
                        SendArenaMessage(player, Buffer, 0);
                    }
                    time(&v129);
                    v130 = difftime(v129, v109->UsageSessionSeconds);
                    sprintf(
                        Dest,
                        "TIME: Session:%5d:%02d:00",
                        v130 / 3600,
                        v130 / 60 % 60);
                    if ( player->IsSysop ) { //TODO: Structure here of 6 DWORDS here.
                        sprintf(
                            &Dest[strlen(Dest)],
                            "  Total:%5d:%02d:00  Created: %d-%d-%d %02d:%02d:%02d",
                            v130 + v109->PlayerDataBillerPacket.UsageTotalSeconds / 3600,
                            v130 + v109->PlayerDataBillerPacket.UsageTotalSeconds / 60 % 60,
                            v109->PlayerDataBillerPacket.AccountCreationMonth,
                            v109->PlayerDataBillerPacket.AccountCreationDay,
                            v109->PlayerDataBillerPacket.AccountCreationYear,
                            v109->PlayerDataBillerPacket.AccountCreationHour,
                            v109->PlayerDataBillerPacket.AccountCreationMinute,
                            v109->PlayerDataBillerPacket.AccountCreationSecond);
                    }
                    SendArenaMessage(player, Dest, 0);
                    if ( player->IsSysop == 0 )
                        return;
                    if ( player->MyArena->ServersideArenaSettings.MiscTimedGame > 0 )
                    {
                        sprintf(
                            Buffer,
                            "BEST SCORE Points:%d  Win:%d  Lose:%d",
                            v109->PersonalBestFlagPoints + v109->PersonalBestKillPoints,
                            v109->PersonalBestWins,
                            v109->PersonalBestLosses);
                        SendArenaMessage(player, Buffer, 0);
                    }
                    a6 = 0;
                    v376 = 0;
                    v382 = 0;
                    Size = 0;
                    GetHugeChunkRecieveStats(v109->connection, &a6, &v376);
                    GetHugeChunkSendStats(v109->connection, &v382, &Size);
                    if ( a6 <= 0 && v382 <= 0 )
                        return;
                    sprintf(Buffer, "Async C2S:%d of %d  S2C:%d of %d", v376, a6, Size, v382);
                    SendArenaMessage(player, Buffer, 0);
                    return;
                }
            }
            else if ( !memicmp(ChatText, "*where", 6) )
            {
                if ( ChatType == 5 && ZonePlayerList[arenaPlayerIndex] ) { //0x05 - Private message [/Whatever]
                    v103 = ZonePlayerList[arenaPlayerIndex];
                    //Coordinate decoding code here, looks cool lol.
                    v106 = (((10 * v103->YPixels) / 16) / 512) + 1;
                    v107 = (((10 * v103->XPixels) / 16) / 512) + 'A';
                    sprintf(AppName, "%s: %c%d", v103->PlayerName, v107, v106);
                    SendArenaMessage(player, AppName, 0);
                    return;
                }
            }
            else if ( memicmp(ChatText, "*trace", 6) ) {
                if ( ChatType == 5 && ZonePlayerList[arenaPlayerIndex] ) { //0x05 - Private message [/Whatever]
                    v153 = ZonePlayerList[arenaPlayerIndex];
                    v154 = GetIPAddressString(v153->IPAddressDWORD);
                    sprintf(CommandLine, "SUBGAME /SPAWN tracert %s > spawn.log", v154);
                    memset(&StartupInfo, 0, sizeof(StartupInfo));
                    StartupInfo.cb = 68;
                    StartupInfo.lpTitle = "Spawned TRACERT";
                    CreateProcess(
                        NULL,
                        CommandLine,
                        NULL,
                        NULL,
                        FALSE,
                        0x20,
                        NULL,
                        NULL,
                        &StartupInfo,
                        player->ProcessInformation);
                    SendArenaMessage(player, "SPAWN STARTED", 0);
                    return;
                }
            }
            else if ( !memicmp(ChatText, "*moderator", 10) ) {
                if ( ChatType == 5 && ZonePlayerList[arenaPlayerIndex] ) { //0x05 - Private message [/Whatever]
                    v137 = ZonePlayerList[arenaPlayerIndex];
                    v137->IsModerator = !v137->IsModerator;
                    if ( v137->IsModerator )
                        v360 = "Player Moderator Mode OFF";
                    else
                        v360 = "Player Moderator Mode ON";
                    SendArenaMessage(player, v360, 0);
                    return;
                }
            }
        }  else if( player->IsSysop  ) {
            //Sysop Commands
            if ( !memicmp(ChatText, "*stat", 5)  )
            {
                v22 = GetTickCount() / 0xA - LastServerStatsAndKickedPlayersTime;
                if ( v22 <= 0 )
                {
                    v22 = 1;
                }
                v24 = 0;
                a5 = 0;
                if ( player->MyArena->ArenaPlayerCount > 0 )
                {
                    v26 = 0;
                    if ( player->MyArena->ArenaPlayerCount > 0 )
                    {
                        do
                        {
                            v28 = GetBillingServerRelOut(player->MyArena->ArenaPlayers[v26]->connection, 0);
                            v29 = (a5 + v28);
                            a5 = v29;
                            ++v26;
                        }
                        while ( v26 < player->MyArena->ArenaPlayerCount );
                        v24 = a5;
                    }
                    a5 = (10 * v24 / player->MyArena->ArenaPlayerCount);
                }
                GetPacketStatistics(ServerPacketAttachment, &v383, &v24, &v382, &Size, &v376);
                sprintf(
                    Dest,
                    "Send:%d(%d)  Recv:%d(%d)  RelOut:%.1f  Multi:%.1f\n",
                    100 * v383 / v22,
                    (signed int)(100 * (unsigned int)v24) / v22,
                    100 * v382 / v22,
                    (signed int)(100 * Size) / v22,
                    (double)a5 * 0.1,
                    (double)v376 * 100.0 / (double)v22);
                SendArenaMessage(player, Dest, 0);
                v30 = 0;
                if ( EncryptionStruct )
                    v30 = GetBillingServerRelOut(EncryptionStruct, 0);
                sprintf(
                    Dest,
                    "Iterations:%d  Players:%d  BillingRelOut:%d  Wave:%d\n",
                    100 * ServerIterations / v22,
                    ZonePlayerCount,
                    v30,
                    100 * Wave / v22);
                SendArenaMessage(player, Dest, 0);
                sprintf(
                    Dest,
                    "Screen:%d  Radar:%d  Double:%d  Timer:%d\n",
                    100 * ScreenValue / v22,
                    100 * RadarValue / v22,
                    100 * DoubleValue / v22,
                    v22 / 100);
                SendArenaMessage(player, Dest, 0);
                v31 = 0;
                v32 = 0;
                if ( ArenaArrayLength > 0 )
                {
                    do
                    {
                        v31 += GetArenaMemoryTotal(Arenas[v32]);
                        ++v32;
                    }
                    while ( v32 < ArenaArrayLength );
                }
                sprintf(Dest, "MemoryUsage:%dk\n", v31);
                SendArenaMessage(player, Dest, 0);
                v33 = 0;
                Dest[0] = 0;
                v377 = 0;
                do
                {
                    v34 = TotalSentForEachPacketType[v33];
                    if ( v34 )
                    {
                        sprintf(AppName, "%d:%d(%d)  ", v33, 100 * TotalSentSizeForEachPacketType[v33] / v22, 100 * v34 / v22);
                        if ( strlen(AppName) + strlen(Dest) > 0x4B )
                        {
                            SendArenaMessage(player, Dest, 0);
                            Dest[0] = 0;
                        }

                        strcat(Dest, AppName);
                        v33 = v377;
                    }
                    ++v33;
                    v377 = v33;
                }
                while ( v33 < 256 );
                if ( !Dest )
                    return;
                SendArenaMessage(player, Dest, 0);
            }
            else if ( !memicmp(ChatText, "*addword", 8) )
            {
                v42 = ChatText[8];
                v43 = (char *)(ChatText + 8);
                ChatText = v43;
                if ( v42 == ' ' )
                {
                    do
                        v44 = (v43++)[1];
                    while ( v44 == ' ' );
                    ChatText = v43;
                }
                if ( !*v43 || (AddLineTextFile(ObscenePointer, v43), WriteTextFileToFile(ObscenePointer), !player) )
                    return;
                sprintf(Buffer, "Obscene Word Added: %s", v43);
                SendArenaMessage(player, Buffer, 0);
            }
            else if ( !memicmp(ChatText, "*shutdown", 9) )
            {
                if ( player )
                    SendArenaMessage(player, "Shutting down server...", 0);
                printf("Shutting down server...\n");
                v65 = ChatText + 9;
                RecycleServer = 1;
                IsServerRunning = 1;
                ShutdownArguments = 0;
                ChatText = v65;
                if ( *v65 == ' ' )
                {
                    ++v65;
                    ChatText = v65;
                }
                if ( *v65 )
                    strcpy(&ShutdownArguments, v65);
                return;
            }
            else if ( !memicmp(ChatText, "*s*", 3) || !memicmp(ChatText, "*g*", 3) ) {
                v84 = ChatText[3];
                v85 = (int)(ChatText + 3);
                for ( m = Str1; v84; ++v85 )
                {
                    if ( v84 == ':' )
                        break;
                    *m = v84;
                    v84 = *(unsigned char *)(v85 + 1);
                    ++m;
                }
                v87 = *(unsigned char *)v85;
                *m = 0;
                if ( !v87 )
                    return;
                v88 = *(unsigned char *)(v85 + 1);
                v89 = v85 + 1;
                for ( n = KeyName; v88; ++v89 )
                {
                    if ( v88 == ':' )
                        break;
                    *n = v88;
                    v88 = *(unsigned char *)(v89 + 1);
                    ++n;
                }
                *n = 0;
                if ( !memicmp(ChatText, "*s*", 3) ) //Lets you set Server.ini variable.
                {
                    if ( !*(unsigned char *)v89 )
                        return;
                    v91 = *(unsigned char *)(v89 + 1);
                    v92 = v89 + 1;
                    for ( ii = AppName; v91; ++v92 )
                    {
                        *ii = v91;
                        v91 = *(unsigned char *)(v92 + 1);
                        ++ii;
                    }
                    *ii = 0;
                    WritePrivateProfileStringA(Str1, KeyName, AppName, ServerINIFilePath);
                    IsEditedServerINIorCFG = 1;
                }
                if ( !player )
                    return;
                //This is probably the *g* command to get Server.ini variable.
                GetPrivateProfileStringA(Str1, KeyName, "InvalidTag", buffer3, 0x40u, ServerINIFilePath);
                sprintf(Dest, "%s:%s:%s", Str1, KeyName, buffer3);
                SendArenaMessage(player, Dest, 0);
            }
            else if ( !memicmp(ChatText, "*set ", 5) ) {
                v72 = ChatText[5];
                v73 = (int)(ChatText + 5);
                for ( j = Str1; v72; ++v73 )
                {
                    if ( v72 == ':' )
                        break;
                    *j = v72;
                    v72 = *(unsigned char *)(v73 + 1);
                    ++j;
                }
                v75 = *(unsigned char *)v73;
                *j = 0;
                if ( !v75 )
                    return;
                v76 = *(unsigned char *)(v73 + 1);
                v77 = v73 + 1;
                for ( k = KeyName; v76; ++v77 )
                {
                    if ( v76 == ':' )
                        break;
                    *k = v76;
                    v76 = *(unsigned char *)(v77 + 1);
                    ++k;
                }
                v79 = *(unsigned char *)v77;
                *k = 0;
                if ( !v79 )
                    return;
                v80 = *(unsigned char *)(v77 + 1);
                v81 = v77 + 1;
                for ( l = Dest; v80; ++v81 )
                {
                    *l = v80;
                    v80 = *(unsigned char *)(v81 + 1);
                    ++l;
                }
                *l = 0;
                GetModuleFileNameA(0, buffer3, 0x100u);
                v83 = strrchr(buffer3, '\\');
                if ( v83 )
                    *v83 = 0;
                else
                    buffer3[0] = 0;
                sprintf(Buffer, "%s\\server.cfg", buffer3);
                if ( stricmp(Str1, "All") )
                {
                    WritePrivateProfileStringA(Str1, KeyName, Dest, Buffer);
                }
                else
                {
                    WritePrivateProfileStringA("Warbird", KeyName, Dest, Buffer);
                    WritePrivateProfileStringA("Javelin", KeyName, Dest, Buffer);
                    WritePrivateProfileStringA("Spider", KeyName, Dest, Buffer);
                    WritePrivateProfileStringA("Leviathan", KeyName, Dest, Buffer);
                    WritePrivateProfileStringA("Weasel", KeyName, Dest, Buffer);
                    WritePrivateProfileStringA("Terrier", KeyName, Dest, Buffer);
                    WritePrivateProfileStringA("Lancaster", KeyName, Dest, Buffer);
                    WritePrivateProfileStringA("Shark", KeyName, Dest, Buffer);
                }
                if ( !player )
                    return;
                SendArenaMessage(player,  "Change complete", 0);
            }
            else if ( !memicmp(ChatText, "*log", 4) )
            {
                v64 = 0;
                do
                {
                    if ( LogArray[256 * (v64 + CurrentLogLine) % 48] )
                        SendArenaMessage(player, &LogArray[256 * (v64 + CurrentLogLine) % 48], 0);
                    ++v64;
                }
                while ( v64 < 48 );
                return;
            }
            else if ( !memicmp(ChatText, "*energy", 7) )
            {
                if ( ChatType != 5 )	//0x05 - Private message [/Whatever]
                {
                    if ( !player->MyArena )
                        return;
                    player->IsEnergyShowing = !player->IsEnergyShowing;
                    if ( player->IsEnergyShowing )
                        v359 = "Showing Energy OFF";
                    else
                        v359 = "Showing Energy ON";
                    SendArenaMessage(player, v359, 0);
                }
                if ( !ZonePlayerList[arenaPlayerIndex] )
                    return;
                player->IsEnergyShowing = !player->IsEnergyShowing;
                if ( player->IsEnergyShowing )
                    v358 = "Showing Energy OFF for %s";
                else
                    v358 = "Showing Energy ON for %s";
                sprintf(Buffer, v358, ZonePlayerList[arenaPlayerIndex]->PlayerDataBillerPacket.Name);
                SendArenaMessage(player, Buffer, 0);
            }
            else if ( memicmp(ChatText, "*addmachine", 11) )
            {
                v45 = ChatText[11];
                v46 = (char *)(ChatText + 11);
                ChatText = v46;
                if ( v45 == ' ' )
                {
                    do
                        v47 = *(unsigned char *)(v46++ + 1);
                    while ( v47 == ' ' );
                    ChatText = v46;
                }
                if ( !*(unsigned char *)v46 || (AddLineTextFile(IDBlockPointer, v46), WriteTextFileToFile(IDBlockPointer), !player) )
                    return;
                sprintf(Buffer, "MachineId Block Added: %s", v46);
                SendArenaMessage(player, Buffer, 0);
            }
            else if ( !memicmp(ChatText, "*removemachine", 14) )
            {
                v48 = ChatText[14];
                v49 = ChatText + 14;
                ChatText = v49;
                if ( v48 == ' ' )
                {
                    do
                        v50 = (v49++)[1];
                    while ( v50 == ' ' );
                    ChatText = v49;
                }
                if ( !*v49 )
                    return;
                v51 = 0;
                v377 = TextFileTotalLines(IDBlockPointer);
                if ( v377 > 0 )
                {
                    do
                    {
                        v52 = TextFileByIndex(IDBlockPointer, v51);
                        v53 = strlen(v52) + 1;
                        v54 = strlen(ChatText) + 1;
                        v55 = ChatText;
                        if ( v54 - 1 >= v53 - 1 )
                            v55 = v52;

                        if ( memicmp(v52, ChatText, strlen(v55) + 1) )
                        {
                            RemoveLineTextFile(IDBlockPointer, v51);
                            --v377;
                        }
                        else
                        {
                            ++v51;
                        }
                    }
                    while ( v51 < v377 );
                }
                WriteTextFileToFile(IDBlockPointer);
                if ( !player )
                    return;
                SendArenaMessage(player, "MachineId Block Removed", 0);
            }
            else if ( !memicmp(ChatText, "*listmachine", 12) )
            {
                v61 = TextFileTotalLines(IDBlockPointer);
                for ( i = 0; i < v61; ++i )
                {
                    v63 = TextFileByIndex(IDBlockPointer, i);
                    SendArenaMessage(player, v63, 0);
                }
                return;
            }
            else if ( !memicmp(ChatText, "*sysop", 6) )
            {
                if ( ChatType == 5 && ZonePlayerList[arenaPlayerIndex] ) { 	// 0x05 - Private message [/Whatever]
                    v66 = ZonePlayerList[arenaPlayerIndex];
                    v66->IsSysop = !v66->IsSysop;
                    v66->IsSuperModerator = v66->IsSysop;
                    v66->IsModerator = v66->IsSysop;
                    if ( v66->IsSysop )
                        v359 = "Player Sysop Mode OFF";
                    else
                        v359 = "Player Sysop Mode ON";
                    SendArenaMessage(player, v359, 0);
                }
            }
            else if ( !memicmp(ChatText, "*smoderator", 0x0B) )
            {
                if ( ChatType == 5 && ZonePlayerList[arenaPlayerIndex] ) {	// 0x05 - Private message [/Whatever]
                    v69 = ZonePlayerList[arenaPlayerIndex];
                    v69->IsSuperModerator = !v69->IsSuperModerator;
                    v69->IsModerator = v69->IsSuperModerator;
                    if ( v69->IsSuperModerator )
                        v359 = "Player Super Moderator Mode OFF";
                    else
                        v359 = "Player Super Moderator Mode ON";
                    SendArenaMessage(player, v359, 0);
                }
            }
            else if ( !memicmp(ChatText, "**", 2) )
            {
                //**(message) = Sends a green message to all zones. Do not space after the *
                v16 = ChatText + 2;
                buf[1] = ChatSoundType;
                strcpy(&buf[2], v16);
                buf[0] = 2;
                if ( BillingConnectionStructPointer )
                    SendBillerUserPrivateChatPacket(
                        BillingConnectionStructPointer,
                        player->BillerPlayerId,
                        BillingGroupId,
                        buf,
                        strlen(v16) + 3);
                return;
            }
        }
    } //this is all the * (star) commands

    //This is where ?something (question mark) commands start up
    if ( *ChatText == '?' && player && player->MyArena )
    {
        if ( !strcmp(ChatText, "?usage") )
        {
            time(&v201);
            v202 = difftime(v201, player->UsageSessionSeconds);
            sprintf(
                Buffer,
                "Session Usage: %5d hours %d minutes",
                v202 / 3600,
                v202 / 60 % 60);
            SendArenaMessage(player, Buffer, 0);
            sprintf(
                Buffer,
                "  Total Usage: %5d hours %d minutes",
                (player->PlayerDataBillerPacket.UsageTotalSeconds + v202) / 3600,
                (player->PlayerDataBillerPacket.UsageTotalSeconds + v202) / 60 % 60);
            SendArenaMessage(player, Buffer, 0);
            sprintf(
                Buffer,
                " First played: %d-%d-%d %d:%d:%d",
                player->PlayerDataBillerPacket.AccountCreationMonth,
                player->PlayerDataBillerPacket.AccountCreationDay,
                player->PlayerDataBillerPacket.AccountCreationYear,
                player->PlayerDataBillerPacket.AccountCreationHour,
                player->PlayerDataBillerPacket.AccountCreationMinute,
                player->PlayerDataBillerPacket.AccountCreationSecond);
            SendArenaMessage(player, Buffer, 0);
            return;
        }
        else if ( !strcmp(ChatText, "?sheep") )
        {
            SendArenaMessage(player, player->MyArena->ServersideArenaSettings.MiscSheepMessage, 24);
            return;
        }
        else if ( !memicmp(ChatText, "?buy", 4) )
        {
            v208 = ChatText + 4;
            Buf1b = ChatText + 4;
            while ( *v208 == ' ' || *v208 == '=' ) //could be ?buy=Item or ?buy Item interesting.
                ++v208;
            Buf1a = v208;
            if ( *v208 )
            {
                if ( player->Ship == 8 )
                {
                    SendArenaMessage(player, "Spectators cannot purchase items.", 0);
                }
                else
                {
                    if ( player->MyArena->ServersideArenaSettings.CostPurchaseAnytime || player->ShipTogglables & 0x20 )
                    {
                        v226 = 0;
                        v227 = 0;
                        while ( stricmp(player->MyArena->ServersideArenaSettings.BuySettings[v227].ItemName, Buf1a) )
                        {
                            ++v227;
                            ++v226;
                            if ( v227 >= 24 )
                                goto LABEL_529;
                        }
                        v232 = (int)&player->MyArena->ServersideArenaSettings.BuySettings[v226].ItemPrice;
                        if ( player->MyArena->ServersideArenaSettings.BuySettings[v226].ItemPrice )
                        {
                            if ( player->MyArena->ServersideArenaSettings.BuySettings[v226].ItemPrice <= player->FlagPoints + player->KillPoints )
                            {
                                v233 = *(unsigned int *)v232;
                                if ( *(unsigned int *)v232 <= player->FlagPoints )
                                {
                                    v370 = -v233;
                                    v362 = 0;
                                }
                                else
                                {
                                    v370 = -player->FlagPoints;
                                    v362 = player->FlagPoints - v233;
                                }
                                AppendPointsLog(player, v362, v370);
                                Buffer[0] = 0x20;	//0x20 - Collected Prize, special header 5 bytes only.
                                *(unsigned short *)&Buffer[3] = *(unsigned short *)&player->MyArena->ServersideArenaSettings.BuySettings[v226].ItemId;
                                *(unsigned short *)&Buffer[1] = 1;
                                SendPlayerReliablePacket(player, Buffer, 5, 1);
                                v384[0] = 0x09;  //0x09 - Player Score Update
                                *(unsigned short *)&v384[1] = player->PlayerId;
                                *(unsigned int *)&v384[3] = player->KillPoints;
                                *(unsigned int *)&v384[7] = player->FlagPoints;
                                *(unsigned short *)&v384[11] = player->CurrentWins;
                                *(unsigned short *)&v384[13] = player->CurrentDeaths;
                                player->WinsSomething = player->CurrentWins;
                                player->DeathsSomething = player->CurrentDeaths;
                                player->GoalsSomething = player->CurrentGoals;
                                player->KillPointsSomething = player->KillPoints;
                                player->FlagPointsSomething = player->FlagPoints;
                                SendPlayerReliablePacket(player, v384, 0x0F, 1);
                                if ( player->MyArena->ServersideArenaSettings.BuySettings[v226].ItemPrice > 500 )
                                    SendEverybodyButYourself(player, v384, 0x0F, 0);
                            }
                            else
                            {
                                SendArenaMessage(player, "You do not have enough points to purchase that item.", 0);
                            }
                        }
                        else
                        {
                            SendArenaMessage(player, "That item is not available for purchase.", 0);
                        }
LABEL_529:
                        if ( v226 == 24 )
                            SendArenaMessage(player, "Invalid item specified for purchase.", 0);
                    }
                    else
                    {
                        SendArenaMessage(player, "You must be in safe zone to purchase items.", 0);
                    }
                }
            }
            else
            {
                Buffer[0] = 0;
                v209 = 0;
                do
                {
                    if ( player->MyArena->ServersideArenaSettings.BuySettings[v209].ItemPrice > 0 )
                    {
                        sprintf(Dest, "%s=%d",
                                player->MyArena->ServersideArenaSettings.BuySettings[v209].ItemName,
                                player->MyArena->ServersideArenaSettings.BuySettings[v209].ItemPrice);
                        if ( strlen(Dest) + strlen(Buffer) > 0x4B )
                        {
                            SendArenaMessage(player, Buffer, 0);
                            Buffer[0] = 0;
                        }

                        if ( !Buffer[0] )
                            strcpy(Buffer, "PRICE: ");
                        else
                            strcat(Buffer, " ");
                        strcat(Buffer, Dest);
                    }
                    v209 ++;
                }
                while ( v209 < 24 );
                if ( Buffer[0] )
                    SendArenaMessage(player, Buffer, 0);
            }
            return;
        }
        else if ( !strcmp(ChatText, "?zone") )
        {
            SendArenaMessage(player, BillingServerName, 0);
            return;
        }
        else if ( !strcmp(ChatText, "?userid") )
        {
            sprintf(Dest, "UserId:%d", player->PlayerDataBillerPacket.UserId);
            SendArenaMessage(player, Dest, 0);
            return;
        }
        else if ( !strcmp(ChatText, "?owner") )
        {
            sprintf(Dest, "Arena Owner:%s", player->MyArena->ServersideArenaSettings.OwnerName);
            SendArenaMessage(player, Dest, 0);
            return;
        }
        else if ( !strcmp(ChatText, "?getsettings") )
        {
            if ( player->IsSysop
                    || (v241 = player->MyArena->ServersideArenaSettings.OwnerUserId, player->PlayerDataBillerPacket.UserId == v241) && v241 >= 0 )
            {
                SendArenaMessage(player, "File being sent, please wait.", 0);
                v242 = player->MyArena;
                FileTransferBuffer[0] = 0x10;  // 0x10 - File Transfer
                v243 = strrchr(v242->SettingsFilename, '\\'); //Get Arena file path for settings.
                if ( v243 )
                {
                    strcpy(&FileTransferBuffer[1], v243 + 1);
                    v244 = strrchr(&FileTransferBuffer[1], '.');
                    if ( v244 )
                        strcpy(v244, ".set");
                    v245 = &v415;
                    v246 = malloc(sizeof(struct struc_2)); //very big data [177KB] pointer!
                    //ExitCode = v246;
                    v418 = 0;
                    if ( v246 )
                        ReadCompleteSettings(v246, player->MyArena->SettingsFilename);
                    v418 = -1;
                    v376 = 0;
                    if ( TotalTemplateSSSEntries > 0 )
                    {
                        do
                        {
                            if ( !TotalTemplateSSSList[v376].SomeString256[256] || player->IsSysop )
                            {
                                if ( stricmp(TotalTemplateSSSList[v376].SomeString32, "All") )
                                {
                                    sub_4066B0(
                                        v246,
                                        TotalTemplateSSSList[v376].SomeString32,
                                        TotalTemplateSSSList[v376].KeyName,
                                        "",
                                        Dest,
                                        0x100);
                                    v251 = TotalTemplateSSSList[v376].someInteger;
                                    if ( v251 == -999 )
                                        sprintf(v245,
                                                "%s:%s:%s:::%s\r\n",
                                                TotalTemplateSSSList[v376].SomeString32,
                                                TotalTemplateSSSList[v376].KeyName,
                                                Dest,
                                                TotalTemplateSSSList[v376].SomeString256);
                                    else
                                        sprintf(
                                            v245,
                                            "%s:%s:%s:%d:%d:%s\r\n",
                                            TotalTemplateSSSList[v376].SomeString32,
                                            TotalTemplateSSSList[v376].KeyName,
                                            Dest,
                                            v251,
                                            TotalTemplateSSSList[v376].someInteger2,
                                            TotalTemplateSSSList[v376].SomeString256);
                                    v245 += strlen(v245);
                                }
                                else
                                {
                                    do
                                    {
                                        sub_4066B0(
                                            v246,
                                            ShipNames[v249],
                                            TotalTemplateSSSList[v376].KeyName,
                                            "",
                                            Buffer,
                                            0x100);
                                        if ( v249 <= 8 ) { //It's a Ship setting.
                                            if ( TotalTemplateSSSList[v376].someInteger == -999 ) {
                                                sprintf(v245,
                                                        "%s:%s:%s:::%s\r\n",
                                                        ShipNames[v249],
                                                        TotalTemplateSSSList[v376].KeyName,
                                                        Buffer,
                                                        TotalTemplateSSSList[v376].SomeString256);
                                            } else {
                                                sprintf(v245,
                                                        "%s:%s:%s:%d:%d:%s\r\n",
                                                        ShipNames[v249],
                                                        TotalTemplateSSSList[v376].KeyName,
                                                        Buffer,
                                                        TotalTemplateSSSList[v376].someInteger,
                                                        TotalTemplateSSSList[v376].someInteger2,
                                                        TotalTemplateSSSList[v376].SomeString256);
                                            }
                                        } else { //It's not a Ship setting, is this even possible?
                                            sprintf(v245,
                                                    "%s:%s:%s:*\r\n",
                                                    ShipNames[v249],
                                                    TotalTemplateSSSList[v376].KeyName,
                                                    Buffer);
                                        }
                                        ++v249;
                                        v245 += strlen(v245);
                                    }
                                    while ( v249 < 9 );
                                }
                            }
                            ++v376;
                        }
                        while ( v376 < TotalTemplateSSSEntries );
                    }
                    SendPlayerReliablePacket(player, FileTransferBuffer, v245 - FileTransferBuffer, 1);
                    if ( v246 )
                    {
                        WriteCompleteSettings(v246);
                        free(v246); //very big data [277KB] pointer deleted right after packet sent.
                    }
                }
            }
            else
            {
                SendArenaMessage(player, "Only the owner of this arena can view the settings.", 0);
            }
            return;
        }
        else if ( !memicmp(ChatText, "?setlevel ", 10) )
        {
            if ( player->IsSysop
                    || player->PlayerDataBillerPacket.UserId == player->MyArena->ServersideArenaSettings.OwnerUserId
                    && player->PlayerDataBillerPacket.UserId >= 0 )
            {
                buf[0] = 0x19;	//0x19 - Request File
                strncpy(&buf[1], ChatText + 10, 0x100);
                buf[256] = 0;
                strncpy(&buf[257], player->MyArena->SetLevelMapFilename, 0x10);
                buf[272] = 0;
                SendPlayerReliablePacket(player, buf, 0x111, 1);
            }
            else
            {
                SendArenaMessage(player, "Only the owner of this arena can change the level.", 0);
            }
            return;
        }
        else  if ( !strcmp(ChatText, "?recycle") )
        {
            if ( player->IsSysop || player->PlayerDataBillerPacket.UserId == player->MyArena->ServersideArenaSettings.OwnerUserId )
                player->MyArena->ArenaRecycling = 1;
            else
                SendArenaMessage(player, "Only the owner of this arena can recycle it.", 0);
            return;
        }
        else if ( !strcmp(ChatText, "?spec") )
        {
            Buffer[0] = 0;
            v376 = 0;
            if ( player->MyArena->ArenaPlayerCount > 0 )
            {
                do
                {
                    v261 = 0;
                    if ( player->IsSuperModerator
                            && player->MyArena->ArenaPlayers[v376]->Ship == 8
                            && player->MyArena->ArenaPlayers[v376]->ArenaPlayerIndex < 0
                            && player->MyArena->ArenaPlayers[v376]->XPixels - player->XPixels < 1280
                            && player->MyArena->ArenaPlayers[v376]->YPixels - player->YPixels < 1024 )
                    {
                        v261 = 1;
                    }
                    if ( (player->MyArena->ArenaPlayers[v376]->ArenaPlayerIndex == player->PlayerId || v261)
                            && (player->IsSysop || !player->MyArena->ArenaPlayers[v376]->IsModerator) )
                    {
                        if ( v261 )
                            v363 = "*%s";
                        else
                            v363 = "%s";
                        sprintf(Dest, v363,
                                player->MyArena->ArenaPlayers[v376]->PlayerDataBillerPacket.Name);
                        if ( strlen(Dest) + strlen(Buffer) > 0x4B )
                        {
                            SendArenaMessage(player, Buffer, 0);
                            Buffer[0] = 0;
                        }
                        if ( !Buffer )
                            strcpy(Buffer, "SPEC: ");
                        else
                            strcat(Buffer, ",");
                        strcat(Buffer, Dest);
                    }
                    ++v376;
                }
                while ( v376 < player->MyArena->ArenaPlayerCount );
            }
            if ( Buffer[0] )
                SendArenaMessage(player, Buffer, 0);
            return;
        }
        else if ( !strcmp(ChatText, "?packetloss") )
        {
            GetPingLOSSSomething(player->connection, &a6, &v377);
            v279 = 1000 - v377;
            v60 = 1000 == a6;
            a6 = (1000 - a6);
            v377 = 1000 - v377;
            if ( !v60 || v279 )
                sprintf(
                    Buffer,
                    "PACKET LOSS ServerToYou:%.1f%%  YouToServer:%.1f%%",
                    (double)a6 * 0.1,
                    (double)v377 * 0.1);
            else
                sprintf(Buffer, "PACKET LOSS Unknown, check again in a few minutes.");
            SendArenaMessage(player, Buffer, 0);
            return;
        }
        else if ( !strcmp(ChatText, "?jackpot") )
        {
            sprintf(Dest, "Current Jackpot: %d", player->MyArena->ArenaJackpot);
            SendArenaMessage(player, Dest, 0);
            return;
        }
        else if ( !strcmp(ChatText, "?crown") )
        {
            if ( player->MyArena->ServersideArenaSettings.KingDeathCount <= 0
                    || player->MyArena->ServersideArenaSettings.KingCrownRecoverKills <= 0 )
            {
                SendArenaMessage(player, "This is not a king of the hill style game or crowns cannot be recovered.", 0);
            }
            else
            {
                if ( player->KotHDeathCount <= 0 )
                {
                    sprintf(
                        Dest,
                        "Kills needed for crown: %d",
                        player->MyArena->ServersideArenaSettings.KingCrownRecoverKills - player->KingCrownKills);
                    SendArenaMessage(player, Dest, 0);
                }
                else
                {
                    SendArenaMessage(player, "You already have a crown.", 0);
                }
            }
            return;
        }
        else if ( !strcmp(ChatText, "?score") )
        {
            GetScore(player->MyArena, player);
            return;
        }
        else if ( !strcmp(ChatText, "?arena") )
        {
            v280 = 0;
            v411[0] = 0x2F;                      // 0x2F - Arena Directory Listing
            v281 = &v411[1];
            v376 = 0;
            if ( ArenaArrayLength > 0 )
            {
                do
                {
                    if ( Arenas[v280]->ArenaName[0] != '#' || player->IsModerator || player->MyArena == Arenas[v280] )
                    {
                        if ( Arenas[v280]->ArenaName[0] )
                        {
                            v372 = Arenas[v280]->ArenaName;
                            v364 = "%s";
                            v356 = Buffer;
                        }
                        else
                        {
                            v372 = (char *)v280;
                            v364 = "%d";
                            v356 = Buffer;
                        }
                        sprintf(v356, v364, v372);
                        strcpy(v281, Buffer);
                        v282 = (unsigned int)&v281[strlen(Buffer) + 1];
                        if ( Arenas[v280] == player->MyArena )
                            *(unsigned short *)v282 = -Arenas[v280]->ArenaPlayerCount;
                        else
                            *(unsigned short *)v282 = Arenas[v280]->ArenaPlayerCount;
                        v280 = v376;
                        v281 = (char *)(v282 + 2);
                    }
                    ++v280;
                    v376 = v280;
                }
                while ( v280 < ArenaArrayLength );
            }
            SendPlayerReliablePacket(player, v411, v281 - v411, 1);
            return;
        }
        else if ( !strcmp(ChatText, "?time") )
        {
            if ( player->MyArena->ServersideArenaSettings.MiscTimedGame <= 0 )
            {
                if ( player->MyArena->GameTimeStart )
                {
                    v285 = player->MyArena->GameTimeStart - abs(GetTickCount() / 0xA - player->MyArena->GameTimePassed);
                    if ( v285 < 0 )
                        v285 = 0;
                    sprintf(Buffer, "Time left: %d minutes %d seconds", v285 / 6000, v285 % 6000 / 100);
                    SendArenaMessage(player, Buffer, 0);
                }
                else
                {
                    if ( player->IsModerator )
                    {
                        v286 = player->MyArena->ServersideArenaSettings.TerritoryRewardDelay
                               - abs(GetTickCount() / 0xA - player->MyArena->LastTerritoryRewardTime);
                        if ( v286 < 0 )
                            v286 = 0;
                        sprintf(
                            Buffer,
                            "Time left to reward: %d minutes %d seconds",
                            v286 / 6000,
                            v286 % 6000 / 100);
                        SendArenaMessage(player, Buffer, 0);
                    }
                    else
                    {
                        SendArenaMessage(player, "This zone does not have a game time limit", 0);
                    }
                }
            }
            else
            {
                v284 = player->MyArena->ServersideArenaSettings.MiscTimedGame
                       - abs(GetTickCount() / 0xA - player->MyArena->LastTimedGameTime);
                if ( v284 < 0 )
                    v284 = 0;
                sprintf(Buffer, "Time left: %d minutes %d seconds", v284 / 6000, v284 % 6000 / 100);
                SendArenaMessage(player, Buffer, 0);
            }
            return;
        }
        else if ( !strcmp(ChatText, "?best") )
        {
            if ( player->MyArena->ServersideArenaSettings.MiscTimedGame <= 0 )
            {
                v373 = player->CurrentDeaths;
                v365 = player->CurrentWins;
                v357 = player->KillPoints + player->FlagPoints;
                v352 = "CURRENT SCORE  Points:%d  Win:%d  Lose:%d";
            }
            else
            {
                v373 = player->PersonalBestLosses;
                v365 = player->PersonalBestWins;
                v357 = player->PersonalBestFlagPoints + player->PersonalBestKillPoints;
                v352 = "PERSONAL BEST  Points:%d  Win:%d  Lose:%d";
            }
            sprintf(Dest, v352, v357, v365, v373);
            SendArenaMessage(player, Dest, 0);
            return;
        }
        else if ( !memicmp(ChatText, "?get ", 5) || !memicmp(ChatText, "?set ", 5))
        {
            v295 = 0;
            if ( player->IsSysop
                    || player->PlayerDataBillerPacket.UserId >= 0
                    && player->MyArena->HasScoreFile
                    && player->MyArena->ServersideArenaSettings.OwnerUserId == player->PlayerDataBillerPacket.UserId )
                v295 = 1;
            if ( v295 )
            {
                v297 = ChatText[5];
                v298 = ChatText + 5;
                for ( jj = AppName; v297; ++v298 )
                {
                    if ( v297 == ':' )
                        break;
                    *jj = v297;
                    v297 = v298[1];
                    ++jj;
                }
                v300 = *v298;
                *jj = 0;
                if ( v300 )
                {
                    v301 = v298[1];
                    v302 = (int)(v298 + 1);
                    for ( kk = Str1; v301; ++v302 )
                    {
                        if ( v301 == '=' )
                            break;
                        if ( v301 == ':' )
                            break;
                        *kk = v301;
                        v301 = *(unsigned char *)(v302 + 1);
                        ++kk;
                    }
                    v304 = *(unsigned char *)v302;
                    *kk = 0;
                    if ( v304 )
                        ++v302;
                    strcpy(Dest, (const char *)v302);
                    if ( !memicmp(ChatText, "?set ", 5) )
                    {
                        sprintf(Buffer, "%s:%s:%s", AppName, Str1, Dest);
                        ChangeSettings(player->MyArena, player, Buffer);
                        if ( !stricmp(AppName, "All") )
                            strcpy(AppName, "Warbird");
                        GetPrivateProfileStringA(AppName, Str1, "InvalidTag", Buffer, 0x80, player->MyArena->SettingsFilename);
                        sprintf(buf, "%s:%s=%s", AppName, Str1, Buffer);
                        SendArenaMessage(player, buf, 0);
                    }
                }
            }
            else
            {
                SendArenaMessage(player, "You do not have permission to set parameters in this arena.", 0);
            }
            return;
        }
        //All Commands that are not numbers are sent to Billing Server as well
        if ( isalpha(ChatText[1]) )
        {
            if ( BillingConnectionStructPointer )
                SendBillerUserCommandPacket(BillingConnectionStructPointer, player->BillerPlayerId, ChatText);
            return;
        }
    }

    v307 = 0;
    if ( *ChatText )
    {
        //Creates all UPPERCASE characters from chat message for checking with text files.
        do
        {
            if ( isalpha(ChatText[v307]) )
                buf[v307] = toupper(ChatText[v307]);
            ++v307;
        }
        while ( buf[v307] );
    }
    buf[v307] = 0; //null terminate

    v309 = TextFileTotalLines(ObscenePointer);
    v310 = 0;
    if ( v309 <= 0 ) {
        a5 = 0; //Obscene word not found
    } else {
        a5 = 1; //Obscene word found
        while ( 1 )
        {
            v311 = TextFileByIndex(ObscenePointer, v310);
            if ( strstr(buf, v311) )
                break;
            ++v310;
            if ( v310 >= v309 ) {
                a5 = 0; //Obscene word not found
                break;
            }
        }
    }
    a7 = 0;
    if ( player )
    {
        if ( player->Ship == 8 && player->MyArena->ServersideArenaSettings.MiscSpectatorQuiet && !player->IsModerator )
            a7 = 1;
        if ( (GetTickCount() / 0xA - player->LastMessageSpamResetCheckTime) >= 100 ) {
            player->MessageSpamTotal = 0;
        } else {
            player->MessageSpamTotal++;
            if ( player->MessageSpamTotal > player->MyArena->ServersideArenaSettings.MessageQuickMessageLimit && !player->IsSysop )
            {
                WriteSubGameLog("Played kicked off for message flooding: %s\n", player->PlayerName);
                player->DisconnectReason = 12;
                player->AlreadySentReliablePacket = 1;
                SendArenaMessagePlayer(player, "WARNING: You have been disconnected for message flooding.", 0);
                return;
            }
        }
        player->LastMessageSpamResetCheckTime = GetTickCount() / 0xA;
    }
    if ( ChatType == 1 || ChatType == 2 )	//0x01 - Public macro, 0x02 - Public message
    {
        if ( player )
        {
            if ( player->MyArena )
            {
                if ( (GetTickCount() / 0xA - player->MyArena->LastTimedGameTime) < 600
                        ||(GetTickCount() / 0xA - player->MyArena->LastFlagResetTime) < 500
                        || (GetTickCount() / 0xA - player->MyArena->LastTerritoryRewardTime) < 500 )
                    return;
            }
        }

        if ( player )
            v319 = player->PlayerDataBillerPacket.Name;
        else
            v319 = "";
        
        if ( *v319 && ChatCounter64Max > 0 )
        {
            if ( !strcmp(ChatRelatedArray[ChatCounter64Max].PlayerName, v319)
                    && !strcmp(ChatRelatedArray[ChatCounter64Max].ChatMessage, ChatText) )
                return;
        }
        ChatCounter64Max = ((ChatCounter64Max + 1) % 64);
        strncpy(ChatRelatedArray[ChatCounter64Max].ChatMessage, ChatText, 300);
        ChatRelatedArray[ChatCounter64Max].ChatMessage[299] = 0;
        strncpy(ChatRelatedArray[ChatCounter64Max].PlayerName, v319, 32);
        ChatRelatedArray[ChatCounter64Max].PlayerName[31] = 0;
        strncpy(ChatRelatedArray[ChatCounter64Max].field_14C, "(Everyone)", 0x20);
        ChatRelatedArray[ChatCounter64Max].field_14C[31] = 0;
        if ( player && player->MyArena )
                FormatMessageArena(player->MyArena, "%16.16s>%s\n", v319, ChatText);
    }
    v406[0] = 7;
    v406[1] = ChatType;
    v406[2] = ChatSoundType;
    if ( ChatType == 7 )	//0x07 - Remote private message a [(Whoever)> Whatever]
    {
        if ( !player
                || (v324 = player->MyArena) == 0
                || player->IsModerator
                || v324->SpecMessageLock && player->Ship != 8
                || !v324->PrivateMessagesLocked )
        {
            *(unsigned short *)&v406[3] = 0;
            v325 = strchr(ChatText + 1, ':');
            if ( v325 )
            {
                v326 = v325 - ChatText - 1;
                memcpy(Buffer, ChatText + 1, v326);
                v327 = 0;
                Buffer[v326] = 0;
                v377 = 0;
                v376 = 0;
                if ( ArenaArrayLength > 0 )
                {
                    do
                    {
                        v331 = 0;
                        if ( Arenas[v376]->ArenaPlayerCount > 0 )
                        {
                            while ( stricmp(Buffer, Arenas[v376]->ArenaPlayers[v331]->PlayerDataBillerPacket.Name) )
                            {
                                if ( !v327 && player && !memicmp(Buffer, Arenas[v376]->ArenaPlayers[v331]->PlayerDataBillerPacket.Name, v326) )
                                    v327 = Arenas[v376]->ArenaPlayers[v331];
                                ++v331;
                                if ( v331 >= Arenas[v376]->ArenaPlayerCount ) {
                                    ++v376;
                                    continue;
                                }
                            }
                            v327 = Arenas[v376]->ArenaPlayers[v331];
                        }
                        ++v376;
                    }
                    while ( v376 < ArenaArrayLength );
                }
                if ( v327 )
                {
                    if ( player )
                        sprintf(&v406[5], "(%s)>%s", player->PlayerDataBillerPacket.Name, v325 + 1);
                    else
                        sprintf(&v406[5], "%s", v325 + 1);
                    SendToSpectators(v327, v406, strlen(&v406[5]) + 6, 1, a5, a7);
                }
                else
                {
                    if ( player )
                    {
                        buf[0] = 2;
                        buf[1] = ChatSoundType;
                        sprintf(&buf[2], ":%s:(%s)>%s", Buffer, player->PlayerDataBillerPacket.Name, v325 + 1);
                        if ( BillingConnectionStructPointer )
                            SendBillerUserPrivateChatPacket(
                                BillingConnectionStructPointer,
                                -1,
                                BillingGroupId,
                                buf,
                                strlen(&buf[2]) + 3);
                    }
                    else
                    {
                        if ( Buffer[0] == '#' )
                        {
                            if ( v326 > 2 )
                            {
                                if ( Buffer[1] != ' ' )
                                {
                                    sprintf(&v406[5], "%s", v325 + 1);
                                    v333 = strlen(&v406[5]) + 1;
                                    v376 = 0;
                                    if ( ArenaArrayLength > 0 )
                                    {
                                        do
                                        {
                                            v335 = 0;
                                            if ( Arenas[v376]->ArenaPlayerCount > 0 )
                                            {
                                                do
                                                {
                                                    if ( !stricmp(&Buffer[1], Arenas[v376]->ArenaPlayers[v335]->PlayerDataBillerPacket.Squad) )
                                                        SendToSpectators(Arenas[v376]->ArenaPlayers[v335], v406, v333 - 1 + 6, 1, a5, a7);
                                                    ++v335;
                                                }
                                                while ( v335 < Arenas[v376]->ArenaPlayerCount );
                                            }
                                            ++v376;
                                        }
                                        while ( v376 < ArenaArrayLength );
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else
    {
        if ( player && player->MyArena )
        {
            *(unsigned short *)&v406[3] = player->PlayerId;
            strcpy(&v406[5], ChatText);
            v338 = player->MyArena->ServersideArenaSettings.MessageReliable;
            v339 = strlen(ChatText) + 6;
            if ( player->MyArena->ArenaPlayerCount < 20 )
                v338 = 1;
            switch ( ChatType )
            {
            case 9:	//0x09 - Channel message a [X;Whatever]
                if ( player->IsModerator
                        || player->MyArena->SpecMessageLock
                        && player->Ship != 8
                        || !player->MyArena->PrivateMessagesLocked )
                {
                    if ( BillingConnectionStructPointer )
                    {
                        if ( *ChatText == ';' || isdigit(*ChatText) && ChatText[1] == ';' )
                        {
                            v340 = ChatText;
                            if ( *ChatText == ';' )
                                v340 = ChatText + 1;
                            v341 = *v340;
                            for ( ll = Str1; v341; ++v340 )
                            {
                                if ( v341 == ';' )
                                    break;
                                if ( v341 == ':' )
                                    break;
                                *ll = v341;
                                v341 = v340[1];
                                ++ll;
                            }
                            v343 = *v340;
                            *ll = 0;
                            if ( v343 )
                            {
                                v344 = v340[1];
                                v345 = v340 + 1;
                                if ( v344 )
                                {
                                    if ( Str1[0] )
                                        SendBillerUserChannelChatPacket(
                                            BillingConnectionStructPointer,
                                            player->BillerPlayerId,
                                            Str1,
                                            v345);
                                }
                            }
                        }
                        else
                        {
                            SendBillerUserChannelChatPacket(
                                BillingConnectionStructPointer,
                                player->BillerPlayerId,
                                "",
                                ChatText);
                        }
                    }
                    else
                    {
                        SendArenaMessage(player, "Chat channels not available at this time.", 0);
                    }
                }
                break;
            case 1:	//0x01 - Public macro
            case 2:	//0x02 - Public message
                if ( player->IsModerator
                        || player->MyArena->SpecMessageLock
                        && player->Ship != 8
                        || !player->MyArena->AllMessagesLocked )
                    SomethingWithAttachedPlayer(player, v406, v339, v338, a5, a7);
                break;
            case 3:	//0x03 - Team message [// or ']
                if ( player->IsModerator
                        || player->MyArena->SpecMessageLock && player->Ship != 8
                        || !player->MyArena->AllMessagesLockedAgainSomething )
                {
                    v346 = player->MyArena->ServersideArenaSettings.MessageTeamReliable || v338;
                    sub_40E220(player, v406, v339, v346, a5, a7);
                }
                break;
            case 5:	//0x05 - Private message [/Whatever]
                if ( player->IsModerator
                        || player->MyArena->SpecMessageLock
                        && player->Ship != 8
                        || !player->MyArena->PrivateMessagesLocked )
                    SomethingWithAudioByteAndShip8(arenaPlayerIndex, v406, v339, 1, a5, a7);
                break;
            case 4:	//0x04 - Player to all members of another team ["Whatever]
                if ( player->IsModerator
                        || player->MyArena->SpecMessageLock && player->Ship != 8
                        || !player->MyArena->AllMessagesLockedAgainSomething )
                {
                    v347 = player->MyArena->ServersideArenaSettings.MessageTeamReliable || v338;
                    sub_40E300(player, arenaPlayerIndex, v406, v339, v347, a5, a7);
                }
                break;
            default:
                return;
            }
        }
        else
        {
            buf[2] = ChatSoundType;
            strcpy(&buf[5], ChatText);
            buf[0] = 7;	//0x07 - Chat
            buf[1] = 0;	//Green message / *arena / *zone message
            *(unsigned short *)&buf[3] = 0;
            v348 = strlen(ChatText) + 1;
            v349 = 0;
            if ( ZonePlayerCount > 0 )
            {
                do
                {
                    if ( ZonePlayers[v349]->MyArena )
                        SendPlayerReliablePacket(ZonePlayers[v349], buf, v348 - 1 + 6, 1);
                    ++v349;
                }
                while ( v349 < ZonePlayerCount );
            }
        }
    }
}
// 414850: could not find valid save-restore pair for edi
// 414850: could not find valid save-restore pair for esi
// 4043C0: using guessed type int __cdecl ResetJackpotFlags(unsigned int);
// 407060: using guessed type int __cdecl CleanTextFileMemory(unsigned int);
// 42C848: using guessed type char *off_42C848[8];
// 431BE8: using guessed type int RadarValue;
// 431E9C: using guessed type int dword_431E9C[75];
// 431FC8: using guessed type int dword_431FC8[10];
// 431FF4: using guessed type int ArenaArrayLength;
// 431FF8: using guessed type int ServerIterations;
// 432004: using guessed type int RecycleServer;
// 437C18: using guessed type int DoubleValue;
// 437CA4: using guessed type int CurrentLogLine;
// 437CA8: using guessed type int IsServerRunning;
// 4386D4: using guessed type int MachineIdArrayCount;
// 438B10: using guessed type int ScreenValue;
// 4AC448: using guessed type struct KICK KickedUsers[1000];
// 4CA810: using guessed type int BillingLogMessages;
// 4D5920: using guessed type int IsEditedServerINIorCFG;
// 4D89C8: using guessed type int Wave;
// 4D8AE4: using guessed type int TotalTemplateSSSEntries;
// 4D8AF4: using guessed type int LastServerStatsAndKickedPlayersTime;
// 4D8B18: using guessed type int ChatCounter64Max;

//----- (00418F20) --------------------------------------------------------
void __cdecl SomethingWithSendingChatTypes(struct PLAYER *player, char ChatType, signed int TargetPlayerId, char *ChatText, char SoundByte)
{
    signed int v6; // edx@2
    struct PLAYER *v7; // ecx@6
    struct PLAYER *v8; // esi@7
    struct PLAYER **v9; // ebp@13
    struct PLAYER *v10; // eax@15
    char *v11; // edx@24
    int v12; // edi@24
    signed int v13; // ecx@30
    bool v14; // zf@32
    signed int v15; // ecx@33
    const void *v16; // esi@33
    char *v17; // edi@33
    unsigned int v18; // edx@33
    signed int v19; // ecx@33
    struct PLAYER *v20; // ecx@37
    int v21; // edi@47
    signed int v22; // ecx@47
    signed int v23; // ecx@50
    const void *v24; // esi@50
    char *v25; // edi@50
    unsigned int v26; // edx@50
    signed int v27; // ecx@50
    const char *v28; // [sp-8h] [bp-424h]@23
    int v29; // [sp-4h] [bp-420h]@23
    struct PLAYER *v30; // [sp+10h] [bp-40Ch]@2
    int v31; // [sp+14h] [bp-408h]@2
    int v32; // [sp+18h] [bp-404h]@12
    char Dest[512]; // [sp+1Ch] [bp-400h]@17
    char buf; // [sp+21Ch] [bp-200h]@57
    char v35; // [sp+21Dh] [bp-1FFh]@57
    char v36; // [sp+21Eh] [bp-1FEh]@57
    short v37; // [sp+21Fh] [bp-1FDh]@57
    char v38; // [sp+221h] [bp-1FBh]@57

    if ( HighestPlayerCountMaybeSomething )
    {
        v31 = -1;
        v30 = 0;
        if ( TargetPlayerId >= 0 && TargetPlayerId < 1024 )
            v30 = ZonePlayerList[TargetPlayerId];

        if ( ChatType == 3 && player != 0 ) //0x03 - Team message [// or ']
            v31 = player->Frequency;
        else if ( ChatType == 4 && v30 ) //0x04 - Player to all members of another team ["Whatever]
            v31 = v30->Frequency;

        v32 = 0;
        if ( ZonePlayerCount > 0 )
        {
            while ( 1 )
            {
                if ( ZonePlayers[v32]->MyArena )
                {
                    if ( ZonePlayers[v32]->field_287 > 0 )
                    {
                        Dest[0] = 0;
                        if ( ChatType != 5 || ZonePlayers[v32]->PlayerId != TargetPlayerId ) //0x05 - Private message [/Whatever]
                        {
                            if ( player != ZonePlayers[v32] )
                            {
                                if ( !player )
                                {
                                    if ( ZonePlayers[v32]->field_287 < 4 ) {
                                        ++v32;
                                        if ( v32 >= ZonePlayerCount )
                                            return;
                                    }
                                    sprintf(Dest, "*> %s ", ChatText);
                                    if ( Dest[0] )
                                    {
                                        strcpy(&v38, Dest);
                                        buf = 7;
                                        v35 = 6;
                                        v36 = SoundByte;
                                        v37 = -1;
                                        SendPlayerReliablePacket(ZonePlayers[v32], &buf, strlen(Dest) + 6, 1);
                                    }
                                    ++v32;
                                    if ( v32 >= ZonePlayerCount )
                                        return;
                                }
                                sprintf(Dest, "%s> %s ", player->PlayerDataBillerPacket.Name, ChatText);
                                switch ( ChatType )
                                {
                                case 5: //0x05 - Private message [/Whatever]
                                    if ( v30 )
                                    {
                                        sprintf(&Dest[strlen(Dest)], "(TO:%s)", v30->PlayerDataBillerPacket.Name);
                                        break;
                                    }
                                    strcat(Dest, "(TO:----)");
                                case 3: //0x03 - Team message [// or ']
                                    sprintf(&Dest[strlen(Dest)], "(TEAM:%d)", v31);
                                    break;
                                case 4: //0x04 - Player to all members of another team ["Whatever]
                                    sprintf(&Dest[strlen(Dest)], "(ENEMYTEAM:%d)", v31);
                                    break;
                                case 9: //0x09 - Channel message a [X;Whatever]
                                    strcat(Dest, "(CHAT)");
                                    break;
                                case 7: //0x07 - Remote private message a [(Whoever)> Whatever]
                                    strcat(Dest, "(FIND)");
                                    break;
                                default:
                                    break;
                                }
                                if ( player->MyArena != ZonePlayers[v32]->MyArena )
                                {
                                    if ( ZonePlayers[v32]->field_287 < 3 ) {
                                        ++v32;
                                        if ( v32 >= ZonePlayerCount )
                                            return;
                                    }

                                    strcat(Dest, "(SPAWN)");
                                    if ( Dest[0] )
                                    {
                                        strcpy(&v38, Dest);
                                        v36 = SoundByte;
                                        buf = 7;
                                        v35 = 6;
                                        v37 = -1;
                                        SendPlayerReliablePacket(ZonePlayers[v32], &buf, strlen(Dest) + 6, 1);
                                    }
                                    ++v32;
                                    if ( v32 >= ZonePlayerCount )
                                        return;
                                }
                                //0x01 - Public macro, 0x02 - Public message, 0x05 - Private message [/Whatever]
                                if ( ZonePlayers[v32]->Frequency != v31
                                        && (ChatType != 1 && ChatType != 2 || *ChatText == '*' || *ChatText == '?')
                                        && (ChatType == 5 || ZonePlayers[v32]->field_287 >= 2) )
                                    if ( Dest[0] )
                                    {
                                        strcpy(&v38, Dest);
                                        v36 = SoundByte;
                                        buf = 7;
                                        v35 = 6;
                                        v37 = -1;
                                        SendPlayerReliablePacket(ZonePlayers[v32], &buf, strlen(Dest) + 6, 1);
                                    }
                                ++v32;
                                if ( v32 >= ZonePlayerCount )
                                    return;
                            }
                        }
                    }
                }
                ++v32;
                if ( v32 >= ZonePlayerCount )
                    return;
            }
        }
    }
}
// 4D8AF8: using guessed type int HighestPlayerCountMaybeSomething;
// 418F20: using guessed type char Dest[512];

//----- (00419270) --------------------------------------------------------
void __cdecl AppendPointsLog(struct PLAYER *player, int a2, int a3)
{
    char buffer[16]; // [sp+Ch] [bp-10h]@8

    player->KillPoints += a2;
    player->FlagPoints = a3 + player->FlagPoints;
    if ( MiscLogPoints && BillingConnectionStructPointer )
    {
        if ( !PointsFileHandle )
            PointsFileHandle = fopen("points.log", "ab");

        if ( player->MyArena && player->MyArena->RecordPointsToLog )
        {
            if ( PointsFileHandle )
            {
                *(unsigned int *)buffer = player->PlayerDataBillerPacket.UserId;
                *(unsigned int *)&buffer[4] = a2;
                *(unsigned int *)&buffer[8] = a3;
                *(unsigned int *)&buffer[12] = time(0);
                fwrite(buffer, 16, 1, PointsFileHandle);
            }
        }
    } else {
        if ( PointsFileHandle )
        {
            fclose(PointsFileHandle);
            PointsFileHandle = 0;
        }
    }
}
// 438B08: using guessed type int MiscLogPoints;

//----- (00419350) --------------------------------------------------------
void __cdecl ReadServerINI()
{
    unsigned int v0; // edi@1
    int v1; // eax@1
    unsigned int v2; // edi@1
    int v3; // eax@1
    unsigned int v4; // edi@1
    int v5; // eax@1
    unsigned int v6; // edi@1
    int v7; // eax@1
    unsigned int v8; // esi@1
    int v9; // eax@1
    int v10; // eax@1
    char Dest[16]; // [sp+Ch] [bp-10h]@1

    CustomArenaMode = ReadIntegerINI("Custom", "ArenaMode", 0, ServerINIFilePath);
    ArenaMaxPlayers = ReadIntegerINI("Arena", "ArenaMaxPlayers", 60, ServerINIFilePath);
    ArenaDesiredPlayers = ReadIntegerINI("Arena", "ArenaDesiredPlayers", 40, ServerINIFilePath);
    ArenaMinimumPlayers = ReadIntegerINI("Arena", "ArenaMinimumPlayers", 15, ServerINIFilePath);
    ArenaSpawnKeepScores = ReadIntegerINI("Arena", "SpawnKeepScores", 0, ServerINIFilePath);
    MaxArenas = ReadIntegerINI("Arena", "MaxArenas", 100, ServerINIFilePath);
    MaxArenasMemory = ReadIntegerINI("Arena", "MaxArenasMemory", 64000, ServerINIFilePath);
    CommsMaxQueueToLogin = ReadIntegerINI("Comms", "MaxQueueToLogin", 16, ServerINIFilePath);
    CommsPacketHistoryMax = ReadIntegerINI("Comms", "PacketHistoryMax", 2000, ServerINIFilePath);
    CommsIncomingBufferSize = ReadIntegerINI("Comms", "IncomingBufferSize", 0x20000, ServerINIFilePath);
    CommsOutgoingBufferSize = ReadIntegerINI("Comms", "OutgoingBufferSize", 0x20000, ServerINIFilePath);
    CommsTransportBufferSize = ReadIntegerINI("Comms", "TransportBufferSize", 160, ServerINIFilePath);
    MiscDisableShareware = 1;
    MiscDisableSharewareScores = 1;
    CommsEncryptMode = 1;
    dword_437B14 = 1;
    BillingLogMessages = 0;
    MiscRegisterKickShareware = 1;
    MiscMaxSharewarePlayer = ReadIntegerINI("Misc", "MaxSharewarePlayers", 0xFFFFFFFF, ServerINIFilePath);
    MiscMaxSharkwareTime = ReadIntegerINI("Misc", "MaxSharewareTime", 90000, ServerINIFilePath);
    MiscMaxPlayers = ReadIntegerINI("Misc", "MaxPlayers", 120, ServerINIFilePath);
    MiscMenuKickOutDelay = ReadIntegerINI("Misc", "MenuKickOutDelay", 12000, ServerINIFilePath);
    MiscLogPoints = ReadIntegerINI("Misc", "LogPoints", 0, ServerINIFilePath);
    MiscPointUpdateDiff = ReadIntegerINI("Misc", "PointUpdateDiff", 500, ServerINIFilePath);
    MiscJackpotBroadcastPoints = ReadIntegerINI("Misc", "JackpotBroadcastPoints", 0, ServerINIFilePath);
    MiscServerLog = ReadIntegerINI("Misc", "ServerLog", 0, ServerINIFilePath);
    MiscKeepAliveDelay = ReadIntegerINI("Misc", "KeepAliveDelay", 400, ServerINIFilePath);
    ReadStringINI("Misc", "DefaultLevelFile", "changeme.lvl", MiscDefaultLevelFile, 0x100, ServerINIFilePath);
    CPUProcessMaxTime = ReadIntegerINI("CPU", "ProcessMaxTime", 4, ServerINIFilePath);
    CPUSleepPerIteration = ReadIntegerINI("CPU", "SleepPerIteration", 0, ServerINIFilePath);
    CPUSleepTime = ReadIntegerINI("CPU", "SleepTime", 0, ServerINIFilePath);
    CPUSlowIterationWarningLevel = ReadIntegerINI("CPU", "SlowIterationWarningLevel", 100, ServerINIFilePath);
    PermissionAllowLowBandwidth = ReadIntegerINI("Permission", "AllowLowBandwidth", 1, ServerINIFilePath);
    PermissionMinimumSecondsToLogin = ReadIntegerINI("Permission", "MinimumSecondsToLogin", 0, ServerINIFilePath);
    PermissionMaxPoints = ReadIntegerINI("Permission", "PermissionMaxPoints", 0, ServerINIFilePath);
    PermissionMode = ReadIntegerINI("Permission", "PermissionMode", 0, ServerINIFilePath);
    AutoPermissionPoints = ReadIntegerINI("Permission", "AutoPermissionPoints", 0, ServerINIFilePath);
    ReadStringINI("Permission", "AutoPermissionIDList", "0", PermissionAutoPermissionIDList, 0x200, ServerINIFilePath);
    ReadStringINI("Permission", "AutoPermissionMessage", "Congratulations", PermissionAutoPermissionMessage, 0x100, ServerINIFilePath);
    sprintf(Dest, "%d", abs(GetTickCount() / 0xA + rand())); //This how they picked the default staff passwords lol
    ReadStringINI("Password", "SysopPassword", Dest, SysopPassword, 0x40, ServerINIFilePath);
    sprintf(Dest, "%d", abs(GetTickCount() / 0xA + rand())); //This how they picked the default staff passwords lol
    ReadStringINI("Password", "EnergyPassword", Dest, EnergyPassword, 0x40, ServerINIFilePath);
    sprintf(Dest, "%d", abs(GetTickCount() / 0xA + rand())); //This how they picked the default staff passwords lol
    ReadStringINI("Password", "ModeratorPassword", Dest, ModeratorPassword, 0x40, ServerINIFilePath);
    sprintf(Dest, "%d", abs(GetTickCount() / 0xA + rand())); //This how they picked the default staff passwords lol
    ReadStringINI("Password", "SuperModeratorPassword", Dest, SuperModeratorPassword, 0x40, ServerINIFilePath);
    sprintf(Dest, "%d", abs(GetTickCount() / 0xA + rand())); //This how they picked the default staff passwords lol
    ReadStringINI("Password", "VIPPassword", Dest, VIPPassword, 0x40, ServerINIFilePath);
    ReadStringINI("Billing", "IP", "127.0.0.1", BillingIP, 0x80, ServerINIFilePath);
    ReadStringINI("Billing", "Password", "money", BillingPassword, 0x20, ServerINIFilePath);
    ReadStringINI("Billing", "ServerName", "Unknown", BillingServerName, 0x80, ServerINIFilePath);
    BillingPort = ReadIntegerINI("Billing", "Port", 900, ServerINIFilePath);
    BillingServerId = ReadIntegerINI("Billing", "ServerId", rand(), ServerINIFilePath);
    BillingGroupId = ReadIntegerINI("Billing", "GroupId", 1, ServerINIFilePath);
    BillingScoreId = ReadIntegerINI("Billing", "ScoreId", 0, ServerINIFilePath);
    BillingReconnectTime = ReadIntegerINI("Billing", "ReconnectTime", 12000, ServerINIFilePath);
    BillingAttemptTime = ReadIntegerINI("Billing", "AttemptTime", 10000, ServerINIFilePath);
    AdvertiseSendMode = ReadIntegerINI("Advertise", "SendMode", 0, ServerINIFilePath);
    AdvertiseDisplayMode = ReadIntegerINI("Advertise", "DisplayMode", 2, ServerINIFilePath);
    AdvertiseDuration = ReadIntegerINI("Advertise", "Duration", 12000, ServerINIFilePath);
    ReadStringINI("Directory", "IP", "sscentral.vie.com", DirectoryIPAddresses, 0x200, ServerINIFilePath);
    ReadStringINI("Directory", "Description", "None", DirectoryDescription, 0x100, ServerINIFilePath);
    ReadStringINI("Directory", "NamePassword", "", DirectoryNamePassword, 0x80, ServerINIFilePath);
    DirectoryPort = ReadIntegerINI("Directory", "Port", 4991, ServerINIFilePath);
}
// 4314B0: using guessed type int AdvertiseSendMode;
// 431FFC: using guessed type int ArenaMinimumPlayers;
// 437B10: using guessed type int ArenaSpawnKeepScores;
// 437B14: using guessed type int dword_437B14;
// 437C1C: using guessed type int BillingAttemptTime;
// 437CA0: using guessed type int CommsMaxQueueToLogin;
// 4380B0: using guessed type int ArenaMaxPlayers;
// 438138: using guessed type int MiscMaxSharewarePlayer;
// 438B08: using guessed type int MiscLogPoints;
// 438B14: using guessed type int CPUSlowIterationWarningLevel;
// 438B18: using guessed type int MaxArenasMemory;
// 438B1C: using guessed type int PermissionMode;
// 438B20: using guessed type int CommsEncryptMode;
// 438B74: using guessed type int MiscMaxPlayers;
// 438B78: using guessed type int BillingReconnectTime;
// 438B7C: using guessed type int PermissionMinimumSecondsToLogin;
// 4AC438: using guessed type int PermissionMaxPoints;
// 4AF328: using guessed type int MiscKeepAliveDelay;
// 4AF32C: using guessed type int AutoPermissionPoints;
// 4C9F44: using guessed type int CPUSleepPerIteration;
// 4CA60C: using guessed type int MiscPointUpdateDiff;
// 4CA810: using guessed type int BillingLogMessages;
// 4D45C0: using guessed type int CustomArenaMode;
// 4D55CC: using guessed type int MiscServerLog;
// 4D55D4: using guessed type int MiscMaxSharkwareTime;
// 4D55D8: using guessed type int MiscMenuKickOutDelay;
// 4D5900: using guessed type int PermissionAllowLowBandwidth;
// 4D5904: using guessed type int CPUProcessMaxTime;
// 4D5908: using guessed type int MaxArenas;
// 4D590C: using guessed type int MiscJackpotBroadcastPoints;
// 4D5910: using guessed type int MiscRegisterKickShareware;
// 4D5918: using guessed type int MiscDisableShareware;
// 4D5928: using guessed type int ArenaDesiredPlayers;
// 4D8930: using guessed type int AdvertiseDuration;
// 4D8AD8: using guessed type int AdvertiseDisplayMode;
// 4D8AE0: using guessed type int MiscDisableSharewareScores;

//----- (00419B60) --------------------------------------------------------
void __cdecl LoadTemplateSSS()
{
    FILE *fileHandle; // eax@1
    char *v2; // eax@7
    char v3; // cl@11
    char *i; // edx@11
    char v5; // cl@16
    char *j; // edx@16
    char v7; // cl@21
    char *k; // edx@21
    char v9; // cl@26
    char *l; // edx@26
    char v11; // dl@31
    char *m; // ecx@31
    int v13; // eax@33
    struct TEMPLATE_SSS *v14; // esi@33
    int v15; // esi@33
    int v16; // esi@33
    int v17; // ecx@33
    int v18; // esi@34
    int v19; // eax@34
    int v20; // eax@37
    char boolean1; // [sp+8h] [bp-888h]@7
    char boolean2; // [sp+Ch] [bp-884h]@9
    char v23[40]; // [sp+10h] [bp-880h]@7
    char Source[32]; // [sp+50h] [bp-840h]@7
    char v25[256]; // [sp+90h] [bp-800h]@7
    char Str[256]; // [sp+190h] [bp-700h]@7
    char v27[256]; // [sp+290h] [bp-600h]@7
    char Buf[1024]; // [sp+490h] [bp-400h]@3

    TotalTemplateSSSEntries = 0;
    fileHandle = fopen("template.sss", "rt");

    if ( fileHandle )
    {
        if ( !feof(fileHandle) )
        {
            do
            {
                if ( fgets(Buf, 1024, fileHandle) && (isalpha(Buf[0]) || Buf[0] == '*' || Buf[0] == '+') )
                {
                    Source[0] = 0;
                    v23[0] = 0;
                    Str[0] = 0;
                    v25[0] = 0;
                    v27[0] = 0;
                    v2 = Buf;
                    boolean1 = 0;
                    if ( Buf[0] == '*' )
                    {
                        boolean1 = 1;
                        v2 = &Buf[1];
                    }
                    boolean2 = 1;
                    if ( *v2 == '+' )
                    {
                        boolean2 = 0;
                        ++v2;
                    }
                    v3 = *v2;
                    for ( i = Source; v3 != ':'; ++v2 )
                    {
                        if ( !v3 )
                            break;
                        *i = v3;
                        v3 = v2[1];
                        ++i;
                    }
                    *i = 0;
                    if ( v2 )
                        ++v2;
                    v5 = *v2;
                    for ( j = v23; v5 != ':'; ++v2 )
                    {
                        if ( !v5 )
                            break;
                        *(unsigned char *)j = v5;
                        v5 = v2[1];
                        ++j;
                    }
                    *(unsigned char *)j = 0;
                    if ( v2 )
                        ++v2;
                    v7 = *v2;
                    for ( k = Str; v7 != ':'; ++v2 )
                    {
                        if ( !v7 )
                            break;
                        *(unsigned char *)k = v7;
                        v7 = v2[1];
                        ++k;
                    }
                    *(unsigned char *)k = 0;
                    if ( v2 )
                        ++v2;
                    v9 = *v2;
                    for ( l = v25; v9 != ':'; ++v2 )
                    {
                        if ( !v9 )
                            break;
                        *(unsigned char *)l = v9;
                        v9 = v2[1];
                        ++l;
                    }
                    *(unsigned char *)l = 0;
                    if ( v2 )
                        ++v2;
                    v11 = *v2;
                    for ( m = v27; v11 >= ' '; ++v2 )
                    {
                        *(unsigned char *)m = v11;
                        v11 = v2[1];
                        ++m;
                    }
                    *(unsigned char *)m = 0;
                    TotalTemplateSSSList[TotalTemplateSSSEntries].SomeChar1a = boolean1;
                    TotalTemplateSSSList[TotalTemplateSSSEntries].SomeChar1b = boolean2;
                    v14 = &TotalTemplateSSSList[TotalTemplateSSSEntries];
                    strncpy(TotalTemplateSSSList[TotalTemplateSSSEntries].SomeString32, Source, 0x20u);
                    v14->SomeString32[31] = 0;
                    strncpy(TotalTemplateSSSList[TotalTemplateSSSEntries].KeyName, v23, 0x28u);
                    v14->KeyName[39] = 0;
                    strncpy(TotalTemplateSSSList[TotalTemplateSSSEntries].SomeString256, v27, 0x100u);
                    v14->SomeString256[255] = 0;

                    if (  Str[0] )
                    {
                        v19 = atoi(Str);
                        TotalTemplateSSSList[TotalTemplateSSSEntries].someInteger = v19;
                    }
                    else
                    {
                        TotalTemplateSSSList[TotalTemplateSSSEntries].someInteger = -999;
                    }
                    if ( v25[0] )
                    {
                        v20 = atoi(v25);
                        TotalTemplateSSSList[TotalTemplateSSSEntries].someInteger2 = v20;
                    }
                    else
                    {
                        TotalTemplateSSSList[TotalTemplateSSSEntries].someInteger2 = -999;
                    }
                    TotalTemplateSSSEntries++;
                }
            }
            while ( !feof(fileHandle) );
        }
        fclose(fileHandle);
    }
    printf("Template.sss read, %d entries found\n", TotalTemplateSSSEntries);
}
// 4D8AE4: using guessed type int TotalTemplateSSSEntries;

//----- (00419E50) --------------------------------------------------------
void __cdecl LoadDefaultServerMap()
{
    int tileCounter; // ebx@1
    struct BMP_FILE_STRUCT *v1; // eax@4
    struct BMP_FILE_STRUCT *v2; // eax@5
    int BMPFileSizeTotal; // ebp@7
    unsigned int TileValuee; // edx@9
    signed int XRadiusCounter; // edi@10
    signed int YRadiusCounter; // esi@11
    int XCoordinate; // ecx@12
    int YCoordinate; // eax@12
    unsigned char CheckTileValue; // eax@14
    int TileValue; // [sp+10h] [bp-24h]@4
    char Buffer[17]; // [sp+14h] [bp-20h]@4
    int v12; // [sp+30h] [bp-4h]@4
    unsigned char TileId; //fix 1
    unsigned short TileX; //fix 2
    unsigned short TileY; //fix 3

    tileCounter = 0;
    if ( _access(MiscDefaultLevelFile, 0) )
    {
        printf(
            "Could not find specified level file (%s), make sure a level file with this name is in the server directory.",
            MiscDefaultLevelFile);
        exit(1);
    }
    *(unsigned int *)Buffer = 0;
    *(unsigned int *)&Buffer[4] = 0;
    *(unsigned int *)&Buffer[8] = 0;
    Buffer[0] = 0x2A;                            // 0x2A - Compressed Map File
    *(unsigned int *)&Buffer[12] = 0;
    strcpy(&Buffer[1], MiscDefaultLevelFile);
    Buffer[16] = 0;
    CompressedServerMap = CompressFile(MiscDefaultLevelFile, &MapFileSize, &MapChecksum, Buffer, 0x11, 1);
    BMPFilePointer = malloc (sizeof (struct BMP_FILE_STRUCT));

    TileValue = 0;
    v12 = 0;
    if ( BMPFilePointer )
        LoadBMPHeader(BMPFilePointer, MiscDefaultLevelFile);
    v12 = -1;
    ServerMapData = (char *)AllocateMemory(0x100000);
    memset(ServerMapData, 0, 0x100000);

    if ( BMPFilePointer->TotalMapTiles > 0 )
    {
        do
        {
            GetTileValue(BMPFilePointer, tileCounter, &TileValue);
            TileId = (TileValue >> 24) & 0xFF;
            TileX = (TileValue >> 12) & 0xFFF;
            TileY = (TileValue & 0xFFF);
            if ( TileId != 0xAA ) // Anything other then 0xAA - Turf Flag Tile
            {
                ServerMapData[(1024 * TileX) + TileY] = TileId;

                if ( TileId >= 0xD8 ) // >= 0xD8 Big Tiles like Asteroids/Space Station/Wormhole and Secret Tiles
                {
                    XRadiusCounter = 0;
                    do
                    {
                        YRadiusCounter = 0;
                        do
                        {
                            XCoordinate = XRadiusCounter + TileX;
                            YCoordinate = YRadiusCounter + TileY;
                            if ( XCoordinate < 1024 )
                            {
                                if ( YCoordinate < 1024 )
                                {
                                    //  1024x1024 memory required
                                    if ( !ServerMapData[(1024 * YCoordinate) + XCoordinate] )
                                    {
                                        ServerMapData[(1024 * YCoordinate) + XCoordinate] = 0xF0;    // Set's the tile to default value of 0xF0 -  Invisible on screen, visible on radar, solid block (like any other tile).
                                    }
                                }
                            }
                            ++YRadiusCounter;
                        }
                        while ( YRadiusCounter < 7 );
                        ++XRadiusCounter;
                    }
                    while ( XRadiusCounter < 7 );
                }
            }
            ++tileCounter;
        }
        while ( tileCounter < BMPFilePointer->TotalMapTiles );
    }
}
// 406BE0: using guessed type int __cdecl sub_406BE0(unsigned int);
// 4386F8: using guessed type int MapChecksum;
// 4D8AF0: using guessed type int MapFileSize;

//----- (0041A040) --------------------------------------------------------
void __cdecl LoadAdvertisements()
{
    signed int v0; // esi@1
    HANDLE v1; // ebx@3
    LONG v2; // esi@3
    size_t v3; // edi@3
    int BothTotalPacketSize; // ebp@3
    char *BothAdPacketBuffer; // eax@3
    char *v6; // ebx@3
    FILE *v7; // eax@3
    int v8; // esi@4
    bool v9; // zf@7
    int v10; // eax@9
    int v11; // eax@9
    signed int v12; // esi@12
    HANDLE v13; // ebx@14
    LONG v14; // esi@14
    size_t v15; // edi@14
    int SharewareAdTotalPacketSize; // ebp@14
    int v17; // eax@14
    char *SharewareAdPacketBuffer; // ebx@14
    FILE *v19; // eax@14
    int v20; // esi@15
    int v21; // eax@20
    int v22; // eax@20
    signed int v23; // esi@23
    HANDLE v24; // ebx@25
    LONG v25; // esi@25
    size_t v26; // edi@25
    int RegisteredAdTotalPacketSize; // ebp@25
    int v28; // eax@25
    char *RegisteredAdPacketBuffer; // ebx@25
    FILE *v30; // eax@25
    int v31; // esi@26
    int v32; // eax@31
    int v33; // eax@31
    unsigned int v34; // [sp+10h] [bp-8C0h]@3
    unsigned int v35; // [sp+10h] [bp-8C0h]@14
    unsigned int v36; // [sp+10h] [bp-8C0h]@25
    FILE *File; // [sp+14h] [bp-8BCh]@3
    void *Filea; // [sp+14h] [bp-8BCh]@16
    void *Fileb; // [sp+14h] [bp-8BCh]@27
    void *v40; // [sp+18h] [bp-8B8h]@5
    FILE *v41; // [sp+18h] [bp-8B8h]@14
    FILE *v42; // [sp+18h] [bp-8B8h]@25
    int v43; // [sp+1Ch] [bp-8B4h]@5
    int v44; // [sp+1Ch] [bp-8B4h]@16
    int v45; // [sp+1Ch] [bp-8B4h]@27
    signed int v46; // [sp+20h] [bp-8B0h]@1
    signed int v47; // [sp+20h] [bp-8B0h]@12
    signed int v48; // [sp+20h] [bp-8B0h]@23
    unsigned int v49; // [sp+24h] [bp-8ACh]@3
    unsigned int v50; // [sp+24h] [bp-8ACh]@14
    unsigned int v51; // [sp+24h] [bp-8ACh]@25
    char DstBuf[14]; // [sp+28h] [bp-8A8h]@4
    BITMAP bm; // [sp+38h] [bp-898h]@3
    char Dest[128]; // [sp+50h] [bp-880h]@2
    char v56[2048]; // [sp+D0h] [bp-800h]@7

    v0 = 0;
    SharewareAdvertisementsFound = 0;
    RegisteredAdvertisementsFound = 0;
    BothAdvertisementsFound = 0;
    v46 = 0;
    do
    {
        sprintf(Dest, "b_ad%d.bmp", v0);
        if ( _access(Dest, 0) != -1 ) //Existence only
        {
            v1 = LoadImageA(0, Dest, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION|LR_LOADFROMFILE);
            GetObjectA(v1, sizeof(bm), &bm);
            v3 = 4 * (bm.bmWidth + 3) / 4;
            v49 = 4 * (bm.bmWidth + 3) / 4;
            DeleteObject(v1);
            BothTotalPacketSize = bm.bmWidth * bm.bmHeight + 10;
            BothAdPacketBuffer = (char *)AllocateMemory(BothTotalPacketSize);
            BothAdPacketBuffer[0] = 0x30;	//0x30 - Zone Banner Advertisements
            BothAdPacketBuffer[1] = AdvertiseDisplayMode;
            *(unsigned short *)(&BothAdPacketBuffer[2]) = bm.bmWidth;
            *(unsigned short *)(&BothAdPacketBuffer[4]) = bm.bmHeight;
            *(unsigned int *)(&BothAdPacketBuffer[6]) = AdvertiseDuration;
            File = fopen(Dest, "rb");
            if ( File )
            {
                fread(DstBuf, 1, 0x0E, File);
                fseek(File, *(unsigned int *)&DstBuf[10], 0); //Goes to offset where Pixels are found.
                v8 = bm.bmHeight - 1;
                if ( v8 >= 0 )
                {
                    v40 = &BothAdPacketBuffer[bm.bmWidth * v8 + 10];
                    v43 = v8 + 1;
                    while ( 1 )
                    {
                        fread(v56, 1, v3, File);
                        memcpy(v40, v56, bm.bmWidth);
                        v9 = v43 == 1;
                        v40 = (char *)v40 - bm.bmWidth;
                        --v43;
                        if ( v9 )
                            break;
                        v3 = v49;
                    }
                }
                fclose(File);
            }
            v0 = v46;
            BothAd[BothAdvertisementsFound].TotalPacketLength = BothTotalPacketSize;
            BothAd[BothAdvertisementsFound].PacketBuffer = BothAdPacketBuffer;
            BothAdvertisementsFound += 1;
        }
        ++v0;
        v46 = v0;
    }
    while ( v0 < 128 );
    printf("%d both advertisements found\n", BothAdvertisementsFound);
    v12 = 0;
    v47 = 0;
    do
    {
        sprintf(Dest, "s_ad%d.bmp", v12);
        if ( _access(Dest, 0) != -1 )  //Existence only
        {
            v13 = LoadImageA(0, Dest, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION|LR_LOADFROMFILE);
            GetObjectA(v13, sizeof(bm), &bm);
            v15 = 4 * (bm.bmWidth + 3) / 4;
            DeleteObject(v13);
            SharewareAdTotalPacketSize = bm.bmWidth * bm.bmHeight + 10;
            SharewareAdPacketBuffer =(char *)AllocateMemory(SharewareAdTotalPacketSize);
            SharewareAdPacketBuffer[0] = 0x30;	//0x30 - Zone Banner Advertisements
            SharewareAdPacketBuffer[1] = AdvertiseDisplayMode;
            *(unsigned short *)(&SharewareAdPacketBuffer[2]) = bm.bmWidth;
            *(unsigned short *)(&SharewareAdPacketBuffer[4]) = bm.bmHeight;
            *(unsigned int *)(&SharewareAdPacketBuffer[6]) = AdvertiseDuration;
            v41 = fopen(Dest, "rb");
            if ( v41 )
            {
                fread(DstBuf, 1, 0x0E, v41);
                fseek(v41, *(unsigned int *)&DstBuf[10], 0);
                v20 = bm.bmHeight - 1;
                if ( v20 >= 0 )
                {
                    Filea = &SharewareAdPacketBuffer[bm.bmWidth * v20 + 10];
                    v44 = v20 + 1;
                    while ( 1 )
                    {
                        fread(v56, 1, v15, v41);
                        memcpy(Filea, v56, bm.bmWidth);
                        v9 = v44 == 1;
                        Filea = (char *)Filea - bm.bmWidth;
                        --v44;
                        if ( v9 )
                            break;
                    }
                }
                fclose(v41);
            }
            v12 = v47;
            SharewareAd[SharewareAdvertisementsFound].TotalPacketLength = SharewareAdTotalPacketSize;
            SharewareAd[SharewareAdvertisementsFound].PacketBuffer = SharewareAdPacketBuffer;
            SharewareAdvertisementsFound += 1;
        }
        ++v12;
        v47 = v12;
    }
    while ( v12 < 128 );
    printf("%d shareware advertisements found\n", SharewareAdvertisementsFound);
    v23 = 0;
    v48 = 0;
    do
    {
        sprintf(Dest, "r_ad%d.bmp", v23);
        if ( _access(Dest, 0) != -1 )  //Existence only
        {
            v24 = LoadImageA(0, Dest, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION|LR_LOADFROMFILE);
            GetObjectA(v24, sizeof(bm), &bm);
            v26 = 4 * (bm.bmWidth + 3) / 4;
            DeleteObject(v24);
            RegisteredAdTotalPacketSize = bm.bmWidth * bm.bmHeight + 10;
            RegisteredAdPacketBuffer = (char *)AllocateMemory(RegisteredAdTotalPacketSize);
            RegisteredAdPacketBuffer[0] = 0x30;	//0x30 - Zone Banner Advertisements
            RegisteredAdPacketBuffer[1] = AdvertiseDisplayMode;
            *(unsigned short *)(&RegisteredAdPacketBuffer[2]) = bm.bmWidth;
            *(unsigned short *)(&RegisteredAdPacketBuffer[4]) = bm.bmHeight;
            *(unsigned int *)(&RegisteredAdPacketBuffer[6]) = AdvertiseDuration;
            v42 = fopen(Dest, "rb");
            if ( v42 )
            {
                fread(DstBuf, 1, 0x0E, v42);
                fseek(v42, *(unsigned int *)&DstBuf[10], 0);
                v31 = bm.bmHeight - 1;
                if ( v31 >= 0 )
                {
                    Fileb = &RegisteredAdPacketBuffer[bm.bmWidth * v31 + 10];
                    v45 = v31 + 1;
                    while ( 1 )
                    {
                        fread(v56, 1, v26, v42);
                        memcpy(Fileb, v56, bm.bmWidth);
                        v9 = v45 == 1;
                        Fileb = (char *)Fileb - bm.bmWidth;
                        --v45;
                        if ( v9 )
                            break;
                    }
                }
                fclose(v42);
            }
            v23 = v48;
            RegisteredAd[RegisteredAdvertisementsFound].TotalPacketLength = RegisteredAdTotalPacketSize;
            RegisteredAd[RegisteredAdvertisementsFound].PacketBuffer = RegisteredAdPacketBuffer;
            RegisteredAdvertisementsFound += 1;
        }
        ++v23;
        v48 = v23;
    }
    while ( v23 < 128 );
    printf("%d registered advertisements found\n", RegisteredAdvertisementsFound);
}
// 4D8930: using guessed type int AdvertiseDuration;
// 4D8AD8: using guessed type int AdvertiseDisplayMode;
// 4D8AFC: using guessed type int SharewareAdvertisementsFound;
// 4D8B00: using guessed type int RegisteredAdvertisementsFound;
// 4D8B04: using guessed type int BothAdvertisementsFound;

//----- (0041A580) --------------------------------------------------------
void __cdecl CleanUpAdvertiseMemory()
{
    int v0; // esi@1
    struct PACKET_ADVERTISEMENT *v1; // edi@2
    int v2; // edi@6
    struct PACKET_ADVERTISEMENT *v3; // esi@7
    int v4; // edi@11
    struct PACKET_ADVERTISEMENT *v6; // esi@12

    v0 = 0;
    if ( RegisteredAdvertisementsFound > 0 )
    {
        do
        {
            if ( RegisteredAd[v0].PacketBuffer )
                FreeMemory(RegisteredAd[v0].PacketBuffer);
            ++v0;
        }
        while ( v0 < RegisteredAdvertisementsFound );
    }
    v2 = 0;
    RegisteredAdvertisementsFound = 0;
    if ( SharewareAdvertisementsFound > 0 )
    {
        do
        {
            if ( SharewareAd[v2].PacketBuffer )
                FreeMemory(SharewareAd[v2].PacketBuffer);
            ++v2;
        }
        while ( v2 < SharewareAdvertisementsFound );
    }
    v4 = 0;
    SharewareAdvertisementsFound = 0;
    if ( BothAdvertisementsFound > 0 )
    {
        do
        {
            if ( BothAd[v4].PacketBuffer )
                FreeMemory(BothAd[v4].PacketBuffer);
            ++v4;
        }
        while ( v4 < BothAdvertisementsFound );
    }
    BothAdvertisementsFound = 0;
}
// 4D8AFC: using guessed type int SharewareAdvertisementsFound;
// 4D8B00: using guessed type int RegisteredAdvertisementsFound;
// 4D8B04: using guessed type int BothAdvertisementsFound;

//----- (0041A630) --------------------------------------------------------
int __cdecl LoadWinsock()
{
    struct WSAData WSAData; // [sp+0h] [bp-190h]@1

    return WSAStartup(0x101u, &WSAData);
}

//----- (0041A660) --------------------------------------------------------
void __cdecl StartServerListener(struct PACKET_ATTACHMENT *packetAttachment, int NewConnectionRequestAddress, int PlayerHandleGamePacketWrapperAddress, int MaxConnections, int ServerListenPort, int OutgoingBufferSize, int IncomingBufferSize, int PacketHistoryMax)
{
    signed int v8; // eax@1
    int v9; // esi@1
    int v10; // edi@3
    int v11; // eax@3
    unsigned int v12; // ecx@3
    int v13; // edi@3
    int i; // ecx@3
    int v15; // edi@6
    struct CONNECTION *v16; // eax@6
    int v17; // ecx@8
    int v18; // edx@8
    void *v19; // edi@10
    unsigned int v20; // ecx@12
    char v21; // dl@12
    int v22; // edi@12
    int j; // ecx@12
    int v24; // eax@15
    //int v25; // eax@15
    //int v26; // ST00_4@15
    //int v27; // ST00_4@15
    //int v28; // ST00_4@15
    unsigned short v29; // cx@15
    unsigned long ioctl_nonblocking; // [sp+Ch] [bp-14h]@15
    struct sockaddr_in name; // [sp+10h] [bp-10h]@15

    int optval; //fix 1

    if ( PacketHistoryMax < 1 )
        PacketHistoryMax = 1;
    packetAttachment->PacketHistoryMax = PacketHistoryMax;
    packetAttachment->PacketCurrentHistory = 0;
    packetAttachment->recievePacketBuffer = (struct PACKET_ATTACHMENT_HISTORY *)AllocateMemory(sizeof(struct PACKET_ATTACHMENT_HISTORY) * packetAttachment->PacketHistoryMax);

    memset(packetAttachment->recievePacketBuffer, 0, (sizeof(struct PACKET_ATTACHMENT_HISTORY) * packetAttachment->PacketHistoryMax));

    packetAttachment->NewConnectionRequestAddress = NewConnectionRequestAddress;
    packetAttachment->PlayerHandleGamePacketWrapperAddress = PlayerHandleGamePacketWrapperAddress;
    packetAttachment->EncryptMode = 0;
    packetAttachment->CommsTransportBufferSizeLimited = 0;
    packetAttachment->MaxConnections = MaxConnections;
    packetAttachment->Port = ServerListenPort;
    packetAttachment->TickCountDividedBy10 = GetTickCount() / 0xA;
    packetAttachment->dword24 = 500;
    packetAttachment->TotalPacketSendLength = 0;
    packetAttachment->TotalPacketSendCalls = 0;
    packetAttachment->TotalPacketRecvLength = 0;
    packetAttachment->TotalPacketRecvCalls = 0;
    packetAttachment->TotalPacketClustersCalls = 0;
    memset(packetAttachment->field_34, 0, sizeof(packetAttachment->field_34));
    packetAttachment->SomeCounter = 0;
    packetAttachment->dword8C34 = 0;
    packetAttachment->FreshConnections = malloc(sizeof(struct CONNECTION) * packetAttachment->MaxConnections);
    if ( packetAttachment->FreshConnections )
    {
        if ( packetAttachment->MaxConnections - 1 >= 0 )
        {
            v18 = 0;
            do
            {
                packetAttachment->FreshConnections[v18].state = 0; //0 = no state
                ++v18;
            }
            while ( v18 < packetAttachment->MaxConnections );
        }
    }
    //TODO: Why even do the loop above if below memset will set everything to zero anyways?
    memset(packetAttachment->FreshConnections, 0, sizeof(struct CONNECTION) * packetAttachment->MaxConnections);

    packetAttachment->TotalConnections = 0;
    packetAttachment->Connections = AllocateMemory(sizeof(struct CONNECTION *) *  packetAttachment->MaxConnections);

    packetAttachment->Socket = socket(AF_INET, SOCK_DGRAM, 0);
    ioctl_nonblocking = 1;
    ioctlsocket(packetAttachment->Socket, FIONBIO, &ioctl_nonblocking);
    optval = -1;
    setsockopt(packetAttachment->Socket, IPPROTO_TCP, TCP_NODELAY, (char *)&optval, sizeof(optval));
    optval = OutgoingBufferSize;
    setsockopt(packetAttachment->Socket, SOL_SOCKET, SO_SNDBUF, (char *)&optval, sizeof(optval));
    optval = IncomingBufferSize;
    setsockopt(packetAttachment->Socket, SOL_SOCKET, SO_RCVBUF, (char *)&optval, sizeof(optval));

    name.sin_family = AF_INET;
    name.sin_port = htons(packetAttachment->Port);
    name.sin_addr.s_addr = htonl(INADDR_ANY);
    bind(packetAttachment->Socket, (struct sockaddr *)&name, sizeof(name)); //Binds on IP 0.0.0.0 : packetAttachment->Port
}

//----- (0041A870) --------------------------------------------------------
void __cdecl CleanUpPacketAttachment(struct PACKET_ATTACHMENT *packetAttachment)
{
    struct PACKET_ATTACHMENT *packetAttachmentt; // edi@1
    int v2; // ebx@1
    struct CONNECTION *connection; // esi@1
    int v4; // ebx@5
    LPVOID *v5; // esi@6

    v2 = 0;
    for ( connection = packetAttachment->FreshConnections; v2 < packetAttachment->MaxConnections; ++connection )
    {
        if ( connection->state )
            sub_41B7A0(connection);
        ++v2;
    }
    closesocket(packetAttachment->Socket);
    free(packetAttachment->FreshConnections);
    v4 = 0;
    if ( packetAttachment->SomeCounter > 0 )
    {
        do
        {
            if ( packetAttachment->field_34[v4].LargePacketBuffer )
            {
                FreeMemory(packetAttachment->field_34[v4].LargePacketBuffer);
                packetAttachment->field_34[v4].LargePacketBuffer= 0;
            }
            ++v4;
        }
        while ( v4 < packetAttachment->SomeCounter );
    }
    FreeMemory(packetAttachment->Connections);
    FreeMemory(packetAttachment->recievePacketBuffer);
}

//----- (0041A910) --------------------------------------------------------
void __cdecl SetPacketAttachmentEncryptMode(struct PACKET_ATTACHMENT *packetAttachment, int CommsEncryptMode)
{
    packetAttachment->EncryptMode = CommsEncryptMode;
}

//----- (0041A920) --------------------------------------------------------
struct CONNECTION *__cdecl ConnectToBiller(struct PACKET_ATTACHMENT *packetAttachment, const char *BillingIP, unsigned short hostshort, int EncryptionServerKey, int a5)
{
    const char *v5; // edi@1
    struct PACKET_ATTACHMENT *v6; // esi@1
    struct in_addr v7; // ebp@1
    struct hostent *host; // eax@2
    int v9; // ecx@4
    int v10; // edi@4
    int v11; // eax@5
    int v12; // ST1C_4@10
    struct CONNECTION *v13; // ebx@10
    int v14; // ST14_4@10
    unsigned short BillingPort; // ax@10
    int v16; // eax@10
    int v17; // edi@10
    int v18; // ecx@11
    int v19; // ST10_4@11
    int v20; // eax@11
    int v21; // eax@11
    int v22; // ecx@11
    int ElementToFind; // [sp+10h] [bp-Ch]@11
    __int16 v25; // [sp+14h] [bp-8h]@11
    int v26; // [sp+16h] [bp-6h]@11
    bool found; // fix 1

    v7.s_addr = inet_addr(BillingIP);
    if ( v7.s_addr == -1 )
    {
        host = gethostbyname(BillingIP);
        if ( !host )
            return 0;
        v7.s_addr = ((struct in_addr *)host->h_addr_list[0])->s_addr;
    }
    v10 = 0;
    if ( packetAttachment->MaxConnections <= 0 ) { //16
        v10 = -1;
    } else {
        while ( packetAttachment->FreshConnections[v10].state )
        {
            ++v10;
            if ( v10 >= packetAttachment->MaxConnections ) {
                v10 = -1;
                break;
            }
        }
    }
    if ( v10 == -1 )
        return 0;

    BillingPort = htons(hostshort);
    InitializeEncryption(&packetAttachment->FreshConnections[v10],
                         packetAttachment,
                         1,
                         v10,
                         v7,
                         BillingPort,
                         EncryptionServerKey,
                         1,
                         a5);
    v17 = 0;

    if ( packetAttachment->TotalConnections )
    {
        v21 = BinarySearch(
                  (int)&packetAttachment->FreshConnections[v10],
                  (int)packetAttachment->Connections,
                  packetAttachment->TotalConnections,
                  sizeof(struct CONNECTION *),
                  (int (__cdecl *)(int, int))SomeOtherCompare(
                      packetAttachment->FreshConnections[v10].RemotePort,
                      packetAttachment->FreshConnections[v10].PlayerId),
                  &found);
        v22 = (int)packetAttachment->Connections;
        v17 = (v21 - v22) / sizeof(struct CONNECTION *); //>> 2 same as divide by 4. (powers of 2)

        memcpy(&packetAttachment->Connections[v17 + 1],
               &packetAttachment->Connections[v17],
               sizeof(struct CONNECTION *) * (packetAttachment->TotalConnections + -v17)); //any number multipled by 0x3FFFFFFF gives the negative of that number
    }
    packetAttachment->Connections[v17] = &packetAttachment->FreshConnections[v10];
    ++packetAttachment->TotalConnections;
    return &packetAttachment->FreshConnections[v10];
}

//----- (0041AA50) --------------------------------------------------------
void __cdecl DumpPacketHistory(struct PACKET_ATTACHMENT *packetAttachment, const char *Filename)
{
    struct PACKET_ATTACHMENT *v2; // ebx@1
    FILE *v3; // eax@1
    signed int v4; // ecx@2
    signed int v5; // ebp@2
    int v6; // edx@3
    int v7; // ecx@3
    int v8; // esi@3
    int v9; // edi@3
    char *v10; // ebp@4
    char *v11; // eax@4
    FILE *File; // [sp+0h] [bp-4h]@1
    signed int tempCount; // [sp+8h] [bp+4h]@2

    File = fopen(Filename, "wt");
    if ( File )
    {
        v5 = 0;
        if ( packetAttachment->PacketHistoryMax > 0 )
        {
            do
            {
                v6 = (packetAttachment->PacketCurrentHistory + v5) % packetAttachment->PacketHistoryMax;
                v9 = packetAttachment->recievePacketBuffer[v6].PacketLength;
                if ( v9 > 0 )
                {
                    v10 = packetAttachment->recievePacketBuffer[v6].PacketBuffer;
                    v11 = inet_ntoa(*(struct in_addr *)&packetAttachment->recievePacketBuffer[v6].RemoteIP); //ip 2 string
                    fprintf(File, "%16s,%5d %3d: ", v11, packetAttachment->recievePacketBuffer[v6].RemotePort, v9);
                    do
                    {
                        fprintf(File, "%02x ", (unsigned char)*v10++);
                        --v9;
                    }
                    while ( v9 );
                    fprintf(File, "\n");
                }
                ++v5;
            }
            while ( v5 < packetAttachment->PacketHistoryMax );
        }
        fclose(File);
    }
}

//----- (0041AB30) --------------------------------------------------------
char * __cdecl PlayerReadPackets(struct PACKET_ATTACHMENT *packetAttachment, int *RecvLength, struct in_addr *RemoteIP, int *RemotePort)
{
    struct PACKET_ATTACHMENT *v4; // esi@1
    int v5; // eax@1
    int v6; // edx@1
    int v7; // edi@1
    int RecvLenn; // eax@1
    int RecvLen; // ecx@1
    int v10; // eax@2
    int v11; // edx@2
    char *result; // eax@2
    int fromlen; // [sp+8h] [bp-14h]@1
    struct sockaddr_in from; // [sp+Ch] [bp-10h]@1

    fromlen = sizeof(from);
    RecvLen = recvfrom(packetAttachment->Socket, packetAttachment->recievePacketBuffer[packetAttachment->PacketCurrentHistory].PacketBuffer, 512, 0, (struct sockaddr *)&from, &fromlen);
    if ( RecvLen == -1 ) {
        result = 0;
    } else {
        packetAttachment->recievePacketBuffer[packetAttachment->PacketCurrentHistory].PacketLength = RecvLen;
        packetAttachment->recievePacketBuffer[packetAttachment->PacketCurrentHistory].RemoteIP.s_addr = *(unsigned int *)&from.sin_addr.s_addr;
        packetAttachment->recievePacketBuffer[packetAttachment->PacketCurrentHistory].RemotePort = *(unsigned short *)&from.sin_port;
        RemoteIP->s_addr = from.sin_addr.s_addr; //IP
        *RemotePort = *(unsigned short *)&from.sin_port; //PORT
        *RecvLength = RecvLen;
        packetAttachment->TotalPacketRecvLength += RecvLen;
        result = packetAttachment->recievePacketBuffer[packetAttachment->PacketCurrentHistory].PacketBuffer;
        packetAttachment->PacketCurrentHistory = (packetAttachment->PacketCurrentHistory + 1) % packetAttachment->PacketHistoryMax;
        packetAttachment->TotalPacketRecvCalls++;
    }
    return result;
}

//----- (0041AC00) --------------------------------------------------------
bool __cdecl ProcessPackets(struct PACKET_ATTACHMENT *packetAttachment)
{
    struct PACKET_ATTACHMENT *packetAttachmentt; // edi@1
    __int64 v2; // qax@1
    unsigned int v3; // kr00_4@2
    int v4; // eax@2
    int v5; // esi@2
    __int64 v6; // qax@5
    unsigned int v7; // kr04_4@6
    int v8; // eax@6
    int v9; // ebx@6
    struct CONNECTION *v10; // esi@7
    int v11; // eax@7
    char *v12; // eax@13
    bool result; // al@14
    char *v14; // [sp-8h] [bp-20h]@9
    unsigned int v15; // [sp-4h] [bp-1Ch]@9
    int RemotePort; // [sp+Ch] [bp-Ch]@13
    struct in_addr RemoteIP; // [sp+10h] [bp-8h]@13
    int RecvLength; // [sp+14h] [bp-4h]@13

    if ( (GetTickCount() / 0xA - packetAttachment->TickCountDividedBy10Two) > 10 )
    {
        packetAttachment->TickCountDividedBy10Two = GetTickCount() / 0xA;
        if ( packetAttachment->TotalConnections > 0 )
        {
            v5 = 0;
            do
                SendBiDirectionalCorePackets(packetAttachment->Connections[v5++]);
            while ( v5 < packetAttachment->TotalConnections );
        }
    }
    if ( packetAttachment->CommsTransportBufferSizeLimited > 0 )
    {
        if ( (GetTickCount() / 0xA - packetAttachment->TickCountDividedBy10) >= 100 )
        {
            v9 = 0;
            packetAttachment->TickCountDividedBy10 = GetTickCount() / 0xA;
            if ( packetAttachment->TotalConnections > 0 )
            {
                do
                {
                    v10 = packetAttachment->Connections[v9];
                    v11 = v10->ClusterPacketLength - v10->ClusterPacket[0];
                    if ( v11 > 2 )
                    {
                        if ( v10->ClusterPacket[2] + 3 == v11 ) {
                            v15 = v10->ClusterPacketLength - v10->ClusterPacket[3];
                            v14 = &v10->ClusterPacket[3];
                        } else {
                            v15 = v10->ClusterPacketLength - v10->ClusterPacket[0];
                            v14 = &v10->ClusterPacket[0];
                        }
                        SendPacket(v10, v14, v15);
                        v10->ClusterPacketLength = v10->ClusterPacket[0];
                    }
                    ++v9;
                }
                while ( v9 < packetAttachment->TotalConnections );
            }
        }
    }
    v12 = PlayerReadPackets(packetAttachment, &RecvLength, &RemoteIP, &RemotePort);
    if ( v12 )
    {
        printf("packet sizes found %d\n", RecvLength);
        PlayerHandlePacket(packetAttachment, v12, RecvLength, RemoteIP, RemotePort);
        return true;
    } else {
        return false;
    }
}
// 41AC00: using guessed type int __cdecl ProcessPackets(unsigned int);

//----- (0041AD60) --------------------------------------------------------
void __cdecl PlayerHandlePacket(struct PACKET_ATTACHMENT *packetAttachment, unsigned char *buffer, signed int RecvLength, struct in_addr RemoteIP, unsigned short RemotePort)
{
    struct PACKET_ATTACHMENT *packetAttachmentt; // esi@1
    int v6; // eax@1
    int v7; // ST0C_4@1
    struct CONNECTION **v8; // eax@1
    struct CONNECTION *connectionn; // ebp@2
    int v10; // ebx@4
    int v11; // eax@9
    int v12; // eax@10
    int v13; // eax@11
    int v14; // eax@17
    int v15; // edx@19
    int v16; // ecx@19
    int v17; // eax@20
    struct CONNECTION *connection; // edi@26
    int v19; // eax@26
    int v20; // ebp@26
    int v21; // ecx@27
    int v22; // ST10_4@27
    int v23; // eax@27
    int v24; // eax@27
    int v25; // ecx@27
    int v26; // eax@28
    int v27; // ecx@28
    int v28; // edx@29
    unsigned int v29; // kr00_4@32
    int v30; // eax@32
    int v31; // ecx@32
    int v32; // ecx@32
    int v33; // eax@36
    unsigned int v34; // esi@36
    signed int v35; // edx@36
    int v36; // edi@37
    unsigned int v37; // ecx@38
    unsigned int v38; // ebx@38
    int *v39; // eax@40
    int *v40; // esi@40
    signed int v41; // edx@40
    //char *SSEncryptionTablee; // edi@41
    int v43; // ecx@42
    int v44; // ebx@42
    unsigned char buf[6]; // [sp+10h] [bp-14h]@1
    int ElementToFind; // [sp+18h] [bp-Ch]@1
    __int16 v47; // [sp+1Ch] [bp-8h]@1
    int v48; // [sp+1Eh] [bp-6h]@1
    int ProtocolVersion; // [sp+28h] [bp+4h]@6
    bool found; //fix 1

    struct CONNECTION search;
    search.RemoteIP.s_addr = RemoteIP.s_addr;
    search.RemotePort = RemotePort;
    search.PlayerId = -1;
    search.dword6 = 0; //must be 0 I think.

    v8 = (struct CONNECTION **)BinarySearch(
             (int)&search,
             (int)packetAttachment->Connections,
             packetAttachment->TotalConnections,
             sizeof(struct CONNECTION *),
             (int (__cdecl *)(int, int))SomeOtherCompare, //every player has a unique RemotePort I believe this is why it's used.
             &found);
    if ( found )
        connection = *v8;
    else
        connection = 0;

    if ( buffer[0] || buffer[1] != 1 )
    {
        if ( !connection )
            return;

        connection->MenuKickOutDelayTimer = GetTickCount() / 0xA;
        connection->TotalPacketsRecieved++;

        if ( connection->ServerKey <= 0 ) {
            ProcessCorePackets(connection, buffer, RecvLength, 0);
            return;
        }
        if ( buffer[0] ) {
            //Packet doesn't have 0 in first byte, then it's encrypted for sure.
            v41 = connection->ServerKey;

            for(unsigned short Counter = 0; Counter < RecvLength; Counter += 4) {
                v43 = *(unsigned int *)&buffer[Counter+1];
                v44 = v41 ^ *(unsigned int *)&connection->SSEncryptionTable[Counter];
                *(unsigned int *)&buffer[Counter+1] = v43 ^ v44;
                v41 = v43;
            }

            ProcessCorePackets(connection, buffer, RecvLength, 0);
            return;
        } else {
            //Packet has 0 in first byte, if second byte is 2 then its decrypted.
            //Otherwise it's encrypted.
            if ( buffer[1] == 2 ) {
                ProcessCorePackets(connection, buffer, RecvLength, 0);
                return;
            }
            if ( RecvLength < 2 )
                return;

            v35 = connection->ServerKey;
            
            printf("RECV Packet before\n");
            int k = 0;
            for(k = 0; k < RecvLength; k++) {
                printf("%X ", buffer[k]);
            }
            printf("\n");

            for(unsigned short Counter = 0; Counter < RecvLength; Counter += 4) {
                v37 = *(unsigned int *)&buffer[Counter+2];
                v38 = v35 ^ *(unsigned int *)&connection->SSEncryptionTable[Counter];
                *(unsigned int *)&buffer[Counter+2] = v37 ^ v38;
                v35 = v37;
            }

            printf("RECV Packet after\n");
            int j = 0;
            for(j = 0; j < RecvLength; j++) {
                printf("%X ", buffer[j]);
            }
            printf("\n");

            ProcessCorePackets(connection, buffer, RecvLength, 0);
            return;
        }
        ProcessCorePackets(connection, buffer, RecvLength, 0);
        return;
    }
    ProtocolVersion = 0;
    if ( RecvLength >= 8 )
        ProtocolVersion = *(unsigned short *)(&buffer[6]);
    if ( ProtocolVersion != 1 ) {
        v11 = -abs(*(unsigned int *)(&buffer[2]));
        *(signed int *)(&buffer[2]) = v11;
    } else if ( packetAttachment->EncryptMode ) {
        v13 = packetAttachment->EncryptMode - 1;
        if ( !v13 )
        {
            v11 = abs(*(unsigned int *)(&buffer[2]));
            *(unsigned int *)(&buffer[2]) = v11;
        }
        if ( v13 == 1 )
        {
            v11 = -abs(*(unsigned int *)(&buffer[2]));
            *(unsigned int *)(&buffer[2]) = v11;
        }
    }

    if ( connection && (connection->ServerKey == *(unsigned int *)(&buffer[2])) )
    {
        buf[0] = 0;
        buf[1] = 0x02;	//0x02 - Encryption Response
        *(signed int *)&buf[2] = *(unsigned int *)(&buffer[2]);
        SendPacket(connection, buf, 6);
    } else {
        v16 = 0;
        if ( packetAttachment->MaxConnections <= 0 )
        {
            v16 = -1;
        } else {
            while ( packetAttachment->FreshConnections[v16].state )
            {
                ++v16;
                if ( v16 >= packetAttachment->MaxConnections ) {
                    v16 = -1;
                    break;
                }
            }
        }
        if ( v16 != -1 && packetAttachment->NewConnectionRequestAddress )
        {
            InitializeEncryption(
                &packetAttachment->FreshConnections[v16],
                packetAttachment,
                3, /* state 3 = normal mode? because state 4 = disconnection */
                v16,
                RemoteIP,
                RemotePort,
                *(unsigned int *)&buffer[2],
                ProtocolVersion, /* 0x0001 - SubSpace and 0x0010 - Continuum */
                0);
            packetAttachment->FreshConnections[v16].TotalPacketsRecieved = 1;
            v20 = 0;
            if ( packetAttachment->TotalConnections )
            {
                v24 = BinarySearch(
                          (int)&packetAttachment->FreshConnections[v16],
                          (int)packetAttachment->Connections,
                          packetAttachment->TotalConnections,
                          sizeof(struct CONNECTION *),
                          (int (__cdecl *)(int, int))SomeOtherCompare(
                              packetAttachment->FreshConnections[v16].RemotePort,
                              packetAttachment->FreshConnections[v16].PlayerId),
                          &found);

                v20 = (v24 - (int)packetAttachment->Connections) / sizeof(struct CONNECTION *);
                memcpy(&packetAttachment->Connections[v20 + 1],
                       &packetAttachment->Connections[v20],
                       sizeof(struct CONNECTION *) * (packetAttachment->TotalConnections + -v20));
            }
            packetAttachment->Connections[v20] = &packetAttachment->FreshConnections[v16];
            ++packetAttachment->TotalConnections;
            //NewConnectionRequest(struct in_addr *IPAddress, short Port, struct CONNECTION *connection);
            if ( ((int (__cdecl *)(struct in_addr, unsigned short, struct CONNECTION *))packetAttachment->NewConnectionRequestAddress)(RemoteIP, RemotePort, &packetAttachment->FreshConnections[v16]) )
            {
                packetAttachment->FreshConnections[v16].state = 2; //2 = Encryption is initialized
                buf[0] = 0;
                buf[1] = 2;
                *(unsigned int *)&buf[2] = *(unsigned int *)&buffer[2];
                SendPacket(&packetAttachment->FreshConnections[v16], buf, 6);
            } else {
                sub_41B7A0(&packetAttachment->FreshConnections[v16]);
            }
        }
    }
}

//----- (0041B070) --------------------------------------------------------
void __cdecl ProcessRegularPackets(struct PACKET_ATTACHMENT *packetAttachment, char *buffer, int packetLength, struct CONNECTION *connection, int a5)
{
    struct PACKET_ATTACHMENT *v5; // ebx@1
    void (__cdecl *v6)(unsigned char *, int, struct CONNECTION *); // eax@1
    void *v7; // ebp@2
    int v8; // ecx@6
    char *v9; // esi@6
    char *v10; // edi@6

    v6 = (void (__cdecl *)(unsigned char *, int, struct CONNECTION *))packetAttachment->PlayerHandleGamePacketWrapperAddress;
    if ( v6 )
    {
        v6(buffer, packetLength, connection);
    }
    else
    {
        packetAttachment->field_34[packetAttachment->SomeCounter].PacketLength = packetLength;
        packetAttachment->field_34[packetAttachment->SomeCounter].connection = connection;
        if ( a5 )
        {
            a5 = 0;
            packetAttachment->field_34[packetAttachment->SomeCounter].LargePacketBuffer = buffer;
        }
        else
        {
            if ( packetLength >= 128 )
            {
                packetAttachment->field_34[packetAttachment->SomeCounter].LargePacketBuffer = (char *)AllocateMemory(packetLength);
                v10 = packetAttachment->field_34[packetAttachment->SomeCounter].LargePacketBuffer;
            }
            else
            {
                packetAttachment->field_34[packetAttachment->SomeCounter].LargePacketBuffer = 0;
                v10 = packetAttachment->field_34[packetAttachment->SomeCounter].SmallPacketBuffer;
            }
            memcpy(v10, buffer, packetLength);
        }
        ++packetAttachment->SomeCounter;
    }
    if ( a5 )
        FreeMemory(buffer);
}

//----- (0041B1B0) --------------------------------------------------------
char * __cdecl sub_41B1B0(struct PACKET_ATTACHMENT *packetAttachment, int *PacketLength, struct CONNECTION *connection)
{
    struct PACKET_ATTACHMENT *v3; // esi@1
    int v4; // ecx@1
    __int64 v5; // qax@5
    unsigned int v6; // kr00_4@6
    int v7; // eax@6
    int v8; // edi@6
    __int64 v9; // qax@9
    unsigned int v10; // kr04_4@10
    int v11; // eax@10
    int v12; // ebx@10
    struct CONNECTION *v13; // edi@11
    int v14; // eax@11
    char *v15; // eax@17
    int v16; // ecx@19
    char *PacketBuffer; // eax@20
    int v18; // eax@21
    int v19; // ecx@21
    char *v20; // [sp-8h] [bp-20h]@13
    unsigned int v21; // [sp-4h] [bp-1Ch]@13
    int a6; // [sp+Ch] [bp-Ch]@17
    struct in_addr a5; // [sp+10h] [bp-8h]@17
    int Size; // [sp+14h] [bp-4h]@17

    if ( packetAttachment->dword8C34 > 0 && *(&packetAttachment->recievePacketBuffer + 35 * packetAttachment->dword8C34) )
    {
        FreeMemory(*((LPVOID *)&packetAttachment->recievePacketBuffer + 35 * packetAttachment->dword8C34));
        *(&packetAttachment->recievePacketBuffer + 35 * packetAttachment->dword8C34) = 0;
    }
    if ( packetAttachment->SomeCounter == packetAttachment->dword8C34 )
    {
        packetAttachment->dword8C34 = 0;
        packetAttachment->SomeCounter = 0;

        if ( (GetTickCount() / 0xA - packetAttachment->TickCountDividedBy10Two) > 10 )
        {
            v8 = 0;
            packetAttachment->TickCountDividedBy10Two = GetTickCount() / 0xA;
            if ( packetAttachment->TotalConnections > 0 )
            {
                do
                    SendBiDirectionalCorePackets(packetAttachment->Connections[v8++]);
                while ( v8 < packetAttachment->TotalConnections );
            }
        }
        if ( packetAttachment->CommsTransportBufferSizeLimited > 0 )
        {
            if ( (GetTickCount() / 0xA - packetAttachment->TickCountDividedBy10) >= 100 )
            {
                v12 = 0;
                packetAttachment->TickCountDividedBy10 = GetTickCount() / 0xA;
                if ( packetAttachment->TotalConnections > 0 )
                {
                    do
                    {
                        v13 = packetAttachment->Connections[v12];
                        v14 = v13->ClusterPacketLength - v13->ClusterPacket[0];
                        if ( v14 > 2 )
                        {
                            if ( v13->ClusterPacket[2] + 3 == v14 )
                            {
                                v21 = v13->ClusterPacketLength - v13->ClusterPacket[3];
                                v20 =  &v13->ClusterPacket[3];
                            }
                            else
                            {
                                v21 = v13->ClusterPacketLength - v13->ClusterPacket[0];
                                v20 = &v13->ClusterPacket[0];
                            }
                            SendPacket(v13, v20, v21);
                            v13->ClusterPacketLength = v13->ClusterPacket[0];
                        }
                        ++v12;
                    }
                    while ( v12 < packetAttachment->TotalConnections );
                }
            }
        }
        v15 = PlayerReadPackets(packetAttachment, &Size, &a5, &a6);
        if ( v15 )
            PlayerHandlePacket(packetAttachment, v15, Size, a5, a6);
    }

    if ( packetAttachment->SomeCounter == packetAttachment->dword8C34 )
    {
        PacketBuffer = 0;
    } else {
        PacketBuffer = packetAttachment->field_34[packetAttachment->dword8C34].LargePacketBuffer;
        if ( !PacketBuffer )
            PacketBuffer = packetAttachment->field_34[packetAttachment->dword8C34].SmallPacketBuffer;
        *PacketLength = packetAttachment->field_34[packetAttachment->dword8C34].PacketLength;
        connection = packetAttachment->field_34[packetAttachment->dword8C34++].connection;
    }
    return PacketBuffer;
}

//----- (0041B3D0) --------------------------------------------------------
void __cdecl ResetPacketStatistics(struct PACKET_ATTACHMENT *packetAttachment)
{
    packetAttachment->TotalPacketSendLength = 0;
    packetAttachment->TotalPacketSendCalls = 0;
    packetAttachment->TotalPacketRecvLength = 0;
    packetAttachment->TotalPacketRecvCalls = 0;
    packetAttachment->TotalPacketClustersCalls = 0;
}
// 41B3D0: using guessed type int __cdecl ResetPacketStatistics(unsigned int);

//----- (0041B3F0) --------------------------------------------------------
void __cdecl GetPacketStatistics(struct PACKET_ATTACHMENT *packetAttachment, int *TotalPacketSendLength, int *TotalPacketSendCalls, int *TotalPacketRecvLength, int *TotalPacketRecvCalls, int *TotalPacketClustersCalls)
{
    *TotalPacketSendLength = packetAttachment->TotalPacketSendLength;
    *TotalPacketRecvLength = packetAttachment->TotalPacketRecvLength;
    *TotalPacketSendCalls = packetAttachment->TotalPacketSendCalls;
    *TotalPacketRecvCalls = packetAttachment->TotalPacketRecvCalls;
    *TotalPacketClustersCalls = packetAttachment->TotalPacketClustersCalls;
}

//----- (0041B430) --------------------------------------------------------
void __cdecl sub_41B430(struct PACKET_ATTACHMENT *packetAttachment, signed int CommsTransportBufferSize)
{
    struct PACKET_ATTACHMENT *packetAttachmentt; // ebx@1
    unsigned int v3; // kr00_4@1
    int v4; // eax@1
    int v5; // edi@1
    struct CONNECTION *v6; // esi@2
    int v7; // eax@2
    signed int v8; // eax@8
    char *v9; // [sp-8h] [bp-14h]@4
    unsigned int v10; // [sp-4h] [bp-10h]@4

    v5 = 0;
    packetAttachment->TickCountDividedBy10 = GetTickCount() / 0xA;
    if ( packetAttachment->TotalConnections > 0 )
    {
        do
        {
            v6 = packetAttachment->Connections[v5];
            v7 = v6->ClusterPacketLength - v6->ClusterPacket[0];
            if ( v7 > 2 )
            {
                if ( v6->ClusterPacket[2] + 3 == v7 ) //Is Cluster packet
                {   //Is Cluster Packet ?
                    v10 = v6->ClusterPacketLength - v6->ClusterPacket[3];
                    v9 = &v6->ClusterPacket[3];
                } else { //Is Regular Packet?
                    v10 = v6->ClusterPacketLength - v6->ClusterPacket[0];
                    v9 = &v6->ClusterPacket[0];
                }
                SendPacket(v6, v9, v10);
                v6->ClusterPacketLength = v6->ClusterPacket[0];
            }
            ++v5;
        }
        while ( v5 < packetAttachment->TotalConnections );
    }

    if ( CommsTransportBufferSize >= 384 )
        packetAttachment->CommsTransportBufferSizeLimited = 384;
    else
        packetAttachment->CommsTransportBufferSizeLimited = CommsTransportBufferSize;
}

//----- (0041B4E0) --------------------------------------------------------
void __cdecl SendPacketsToEverybody(struct PACKET_ATTACHMENT *packetAttachment)
{
    struct PACKET_ATTACHMENT *packetAttachmentt; // ebx@1
    unsigned int v2; // kr00_4@1
    int v3; // eax@1
    int v4; // edi@1
    struct CONNECTION *v5; // esi@2
    int v6; // eax@2
    char *v7; // [sp-Ch] [bp-14h]@4
    unsigned int v8; // [sp-8h] [bp-10h]@4

    v4 = 0;
    packetAttachment->TickCountDividedBy10 = GetTickCount() / 0xA;
    if ( packetAttachment->TotalConnections > 0 )
    {
        do
        {
            v5 = packetAttachment->Connections[v4];
            v6 = v5->ClusterPacketLength - (unsigned int)v5->ClusterPacket[0];
            if ( v6 > 2 )
            {
                if ( v5->ClusterPacket[2] + 3 == v6 ) // Is Cluster Packet?
                {
                    //Cluster Packet?
                    v8 = v5->ClusterPacketLength - (unsigned int)v5->ClusterPacket[3];
                    v7 = &v5->ClusterPacket[3];
                } else {
                    //Regular Packet?
                    v8 = v5->ClusterPacketLength - (unsigned int)v5->ClusterPacket[0];
                    v7 = &v5->ClusterPacket[0];
                }
                SendPacket(v5, v7, v8);
                v5->ClusterPacketLength = (int)v5->ClusterPacket[0];
            }
            ++v4;
        }
        while ( v4 < packetAttachment->TotalConnections );
    }
}

//----- (0041B570) --------------------------------------------------------
int __stdcall sub_41B570(int a1)
{
    return 1;
}
// 41B570: using guessed type unsigned int __stdcall sub_41B570(unsigned int);

//----- (0041B5D0) --------------------------------------------------------
void __cdecl InitializeEncryption(struct CONNECTION *connection, struct PACKET_ATTACHMENT *packetAttachment, int state, int PlayerId, struct in_addr RemoteIP, unsigned short RemotePort, signed int ServerKey, int ProtocolVersion, int alwaysZero)
{
    signed int v10; // edi@1
    int v11; // ebp@1
    int result; // eax@5
    signed int v13; // [sp+24h] [bp+14h]@1

    v10 = ServerKey;
    connection->ProtocolVersion = ProtocolVersion;
    connection->MyPacketAttachment = packetAttachment;
    connection->state = state;
    connection->PlayerId = PlayerId;
    connection->RemoteIP.s_addr = RemoteIP.s_addr;
    connection->RemotePort = RemotePort;
    connection->dword6 = alwaysZero;
    connection->dwordA = 9999999;
    connection->SyncResponseLocalTimeStamp = 0;
    connection->dword12 = 0;
    connection->dword16 = 0;
    connection->TotalSyncResponses = 0;
    connection->dword1E = 0;
    connection->LowestSyncResponseDelay = 0;
    connection->HighestSyncResponseDelay = 0;
    connection->ServerKey = ServerKey;

    v11 = 0;
    do
    {
        v10 = 16807 * (v10 % 127773) - 2836 * (v10 / 127773) + 123;
        if ( v10 <= 0 )
            v10 += 2147483647;
        connection->SSEncryptionTable[v11] = (v10 & 0xFF);
        connection->SSEncryptionTable[v11+1] = (v10 >> 8) & 0xFF;
        //*(unsigned short *)connection->SSEncryptionTable[v11] = (unsigned short)v10;
        v11 += 2;
    }
    while ( v11 < 520 );
    connection->KeepAliveDelayTimer = 0;
    connection->MenuKickOutDelayTimer = GetTickCount() / 0xA;
    connection->KeepAliveDelayTimer = GetTickCount() / 0xA;
    connection->SmallChunkPacketSize = 0;
    connection->SmallChunkPacketBuffer = 0;
    connection->RatioBytesSent = 0;
    connection->TotalBytesSent = 0;
    connection->LastTotalBytesSent = 0;
    connection->LastRatioSendTime = GetTickCount() / 0xA;
    connection->CurrentReliableMessageACKID = 0;
    connection->HighestRecievedReliableMessageACKID = 0;
    connection->MaxOutPacketSizeQueue = 0;
    connection->ReliablePacketsCurrent = 0;
    connection->ReliablePacketsPending = 0;
    memset(connection->ReliableInPackets, 0, sizeof(connection->ReliableInPackets));
    memset(connection->ReliableOutPackets, 0, sizeof(connection->ReliableOutPackets));
    connection->ServerToYou = 1000;
    connection->YouToServer = 1000;
    connection->TotalPacketsSent = 0;
    connection->TotalPacketsRecieved = 0;
    connection->TotalPacketsClientRecieved = 0;
    connection->TotalPacketsClientSent = 0;
    connection->ClusterPacketLength = connection->ClusterPacket[0]; //A92 = beginning of cluster packet so this means 0?
    memset(connection->HugeChunk, 0, sizeof(connection->HugeChunk)); //4 huge chunks total
    connection->TotalHugeChunks = 0;
    connection->HugeChunkRecievePacket = 0;
    connection->HugeChunkRecieveTotalSize = 0;
    connection->HugeChunkRecievedSize = 0;
}

//----- (0041B7A0) --------------------------------------------------------
void __cdecl sub_41B7A0(struct CONNECTION *connection)
{
    int v2; // eax@1
    int v3; // ebp@8
    struct HUGE_CHUNK_STRUCT *v4; // esi@9
    void *v5; // eax@13
    char *v6; // esi@15
    signed int v7; // ebp@15
    int v8; // esi@23
    __int16 v9; // dx@23
    int v10; // eax@23
    int v11; // edx@23
    struct CONNECTION **connectionResult; // eax@23
    int v13; // ecx@24
    int v14; // esi@24
    char *PacketBuffer; // [sp-8h] [bp-28h]@3
    unsigned int PacketSize; // [sp-4h] [bp-24h]@3
    char buf[4]; // [sp+10h] [bp-10h]@7
    int v18; // [sp+14h] [bp-Ch]@23
    __int16 v19; // [sp+18h] [bp-8h]@23
    int v20; // [sp+1Ah] [bp-6h]@23
    bool found; //fix 1

    v2 = connection->ClusterPacketLength - connection->ClusterPacket[0];
    if ( v2 > 2 )
    {
        if ( connection->ClusterPacket[2] + 3 == v2 ) //Is Cluster Packet?
        {
            PacketSize = connection->ClusterPacketLength - connection->ClusterPacket[3];
            PacketBuffer = &connection->ClusterPacket[3];
        } else {
            PacketSize = connection->ClusterPacketLength - connection->ClusterPacket[0];
            PacketBuffer = &connection->ClusterPacket[0];
        }
        SendPacket(connection, PacketBuffer, PacketSize);
        connection->ClusterPacketLength = connection->ClusterPacket[0];
    }
    if ( connection->state == 2 ) //2 = Encryption is initialized
    {
        buf[0] = 0;
        buf[1] = 0x07;	//0x07 - Order to Disconnect
        SendPacket(connection, buf, 2);
    }
    v3 = 0;
    if ( connection->TotalHugeChunks > 0 )
    {
        do
        {
            if ( connection->HugeChunk[v3].IsMemoryAllocated )
                FreeMemory(connection->HugeChunk[v3].PacketBuffer);
            ++v3;
        }
        while ( v3 < connection->TotalHugeChunks );
    }
    connection->TotalHugeChunks = 0;
    if ( connection->HugeChunkRecievePacket )
        FreeMemory(connection->HugeChunkRecievePacket);
    connection->HugeChunkRecievePacket = 0;
    connection->HugeChunkRecieveTotalSize = 0;
    connection->HugeChunkRecievedSize = 0;
    v7 = 0;
    do
    {
        if ( connection->ReliableInPackets[v7] )
        {
            FreeMemory(connection->ReliableInPackets[v7]);
            connection->ReliableInPackets[v7] = 0;
        }
        ++v7;
    }
    while ( v7 < 256 );

    if ( connection->SmallChunkPacketBuffer )
    {
        FreeMemory(connection->SmallChunkPacketBuffer);
        connection->SmallChunkPacketBuffer = 0;
    }

    connectionResult = (struct CONNECTION **)BinarySearch(
                           (int)connection,
                           (int)connection->MyPacketAttachment->Connections,
                           connection->MyPacketAttachment->TotalConnections,
                           sizeof(struct CONNECTION *),
                           (int (__cdecl *)(int, int))SomeOtherCompare,
                           &found);
    if ( found )
    {
        connection->MyPacketAttachment->TotalConnections--;
        v13 = (connectionResult - connection->MyPacketAttachment->Connections) / sizeof(struct CONNECTION *);

        memcpy(
            &connection->MyPacketAttachment->Connections[v13],
            &connection->MyPacketAttachment->Connections[v13 + 1],
            sizeof(struct CONNECTION *) * (connection->MyPacketAttachment->TotalConnections + -v13));
    }
    connection->state = 0; //no state
}

//----- (0041B950) --------------------------------------------------------
int __cdecl CheckState(struct CONNECTION *connection)
{
    return connection->state; //anything over 0 is connected.
}
// 41B950: using guessed type int __cdecl CheckState(unsigned int);

//----- (0041B960) --------------------------------------------------------
int __cdecl GetProtocolVersion(struct CONNECTION *connection)
{
    return connection->ProtocolVersion;
}
// 41B960: using guessed type int __cdecl GetProtocolVersion(unsigned int);

//----- (0041B970) --------------------------------------------------------
int __cdecl GetBillingServerRelOut(struct CONNECTION *connection, int *MaxOutPacketSizeQueue)
{
    if ( MaxOutPacketSizeQueue )
        *MaxOutPacketSizeQueue = connection->MaxOutPacketSizeQueue;
    return connection->ReliablePacketsCurrent - connection->ReliablePacketsPending;
}

//----- (0041B9A0) --------------------------------------------------------
void __cdecl SendPacket(struct CONNECTION *connection, unsigned char *buf, unsigned int len)
{
    unsigned int StartServerKey; // edx@2
    const char *SendBuffer; // ebp@2
    char v6; // al@4
    char *v7; // ecx@7
    char *v8; // esi@7
    int v9; // eax@8
    int v10; // eax@8
    char *v11; // ecx@10
    char *v12; // esi@10
    int v13; // eax@11
    int v14; // eax@11
    unsigned int v15; // kr00_4@13
    int v16; // ecx@13
    int v17; // eax@13
    __int64 v18; // qax@13
    signed int v19; // ecx@13
    int v20; // edi@14
    int v21; // edx@14
    int v22; // edi@15
    __int16 v23; // cx@15
    int v24; // ST00_4@15
    int v25; // eax@15
    char v26; // [sp+7h] [bp-411h]@3
    struct sockaddr_in to; // [sp+8h] [bp-410h]@15
    unsigned char buffer[1024]; // [sp+18h] [bp-400h]@6

    if ( connection->state != 4 ) //4 = Disconnected
    {
        StartServerKey = connection->ServerKey;
        SendBuffer = buf;
        if ( (signed int) StartServerKey > 0 )
        {
            if ( buf[0] || buf[1] != 1 && buf[1] != 2 ) //0x01 - Encryption Request && 0x02 - Encryption Response
            {
                memcpy(buffer, buf, len);
                if ( buf[0] ) //First Byte of packet isn't a 0
                {

                    printf("SEND Packet 1\n");
                    int l = 0;
                    for(l = 0; l < len; l++) {
                        printf("%X ", buffer[l]);
                    }
                    printf("\n");

                    //TODO: Counter shouldn't really exceed 520 or it will crash.
                    for(unsigned short Counter = 0; Counter < len; Counter += 4) {
                        StartServerKey ^= *(unsigned int *)&buffer[Counter+1] ^ *(unsigned int *)&(connection->SSEncryptionTable[Counter]);
                        *(unsigned int *)&buffer[Counter+1] = StartServerKey;
                    }                    
                } else { //First byte of packet is a zero.

                    printf("SEND Packet 2\n");
                    int b = 0;
                    for(b = 0; b < len; b++) {
                        printf("%X ", buffer[b]);
                    }
                    printf("\n");
                    
                    //TODO: Counter shouldn't really exceed 520 or it will crash.
                    for(unsigned short Counter = 0; Counter < len; Counter += 4) {
                        StartServerKey ^= *(unsigned int *)&buffer[Counter+2] ^ *(unsigned int *)&(connection->SSEncryptionTable[Counter]);
                        *(unsigned int *)&buffer[Counter+2] = StartServerKey;
                    }
                }
                SendBuffer = buffer;
            }
        }
        connection->KeepAliveDelayTimer = GetTickCount() / 0xA;
        connection->TotalPacketsSent++;
        connection->TotalBytesSent += len; //packetSize goes up to this value.
        int timePassed = (connection->LastRatioSendTime - GetTickCount() / 0xA);
        if ( timePassed >= 100 )
        {
            connection->RatioBytesSent = 100 * (connection->TotalBytesSent - connection->LastTotalBytesSent) / timePassed;
            connection->LastRatioSendTime = GetTickCount() / 0xA;
            connection->LastTotalBytesSent = connection->TotalBytesSent;
        }
        //This sends the packet to a player or billing server
        to.sin_family = AF_INET;
        to.sin_addr.s_addr = connection->RemoteIP.s_addr;
        to.sin_port = connection->RemotePort;
        printf("Send Lengths = %d\n", len);
        sendto(connection->MyPacketAttachment->Socket, SendBuffer, len, 0, (struct sockaddr *)&to, sizeof(to));
        connection->MyPacketAttachment->TotalPacketSendLength += len;
        connection->MyPacketAttachment->TotalPacketSendCalls += 1;
    }
}
// 41B9A0: using guessed type char var_3FE[1022];

//----- (0041BB70) --------------------------------------------------------
void __cdecl ProcessCorePackets(struct CONNECTION *connection, unsigned char *buffer, int PacketLength, int a4)
{
    int v5; // ecx@1
    void *v6; // esi@2
    signed int v7; // edi@3
    signed int v8; // esi@6
    int v9; // edi@7
    int v10; // ebx@7
    int ReliablePacketIndex; // eax@17
    int v12; // esi@19
    unsigned char *PacketBuffer; // eax@19
    int v14; // esi@20
    int v15; // ecx@21
    int v16; // eax@25
    unsigned int RecievedACK_Id; // eax@25
    int v18; // eax@27
    int v19; // ecx@27
    int v20; // edx@29
    __int64 v21; // qax@29
    int i; // esi@29
    int v23; // edx@30
    __int64 v24; // qax@30
    int v25; // ebx@32
    __int16 PacketSize; // di@33
    int v27; // eax@33
    unsigned int v28; // eax@34
    unsigned int v29; // edi@34
    int v30; // edx@34
    int v31; // esi@34
    int v32; // eax@34
    __int64 v33; // qax@40
    __int64 v34; // qax@42
    int v35; // eax@44
    signed int v36; // ecx@45
    signed int v37; // ecx@48
    int v38; // edi@51
    struct HUGE_CHUNK_STRUCT *v39; // esi@52
    void *v40; // eax@57
    int v41; // edi@60
    struct HUGE_CHUNK_STRUCT *v42; // esi@61
    void *v43; // eax@66
    int v44; // ebx@69
    signed int v45; // eax@69
    int v46; // ST04_4@69
    int v47; // eax@69
    int v48; // eax@72
    int v49; // ecx@74
    int v50; // esi@76
    int v51; // eax@76
    int v52; // esi@79
    char *v53; // ebx@79
    int v54; // edx@80
    char *v55; // esi@80
    int v56; // edi@80
    char OutBuffer[10]; // [sp+10h] [bp-Ch]@25

    if ( connection->state == 4 ) //4 = Disconnected
    {
        goto RETURN_FREE_MEMORY;
    }
    if ( buffer[0] == 0 ) //Core Packets
    {
        if ( PacketLength <= 1 )
            goto RETURN_FREE_MEMORY;
        switch ( buffer[1] )
        {
        case 2:	//0x02 - Encryption Response
            if ( connection->state != 1 )
                goto RETURN_FREE_MEMORY;
            v8 = *(unsigned int *)&buffer[2];	//Client Encryption Key
            if ( abs(connection->ServerKey) == abs(v8) )
            {
                connection->ServerKey = v8;
                v10 = 0;
                do
                {
                    v8 = 16807 * (v8 % 127773) - 2836 * (v8 / 127773) + 123;
                    if ( v8 <= 0 )
                        v8 += 0x7FFFFFFF;
                    connection->SSEncryptionTable[v10] = (v8 & 0xFF);
                    connection->SSEncryptionTable[v10+1] = (v8 >> 8) & 0xFF;
                    //*(unsigned short *)connection->SSEncryptionTable[v10] = (unsigned short)v8;
                    v10 += 2;
                }
                while ( v10 < 520 );
                connection->state = 2; //2 = Encryption is initialized
            }
            goto RETURN_FREE_MEMORY;
        default:
            goto RETURN_FREE_MEMORY;
        case 4:	//0x04 - Reliable ACK
            if ( PacketLength < 6
                    || (connection->ReliablePacketsPending > *(unsigned int *)&buffer[2])
                    || *(unsigned int *)&buffer[2] >= connection->ReliablePacketsCurrent )
                goto RETURN_FREE_MEMORY;
            ReliablePacketIndex = (*(unsigned int *)&buffer[2]) % 256;	//ACK ID, 0 - 255 only allowed
            PacketBuffer = connection->ReliableOutPackets[ReliablePacketIndex];
            if ( PacketBuffer )
            {
                //Clear previous reliable packet on this index.
                connection->MaxOutPacketSizeQueue -= *(unsigned short *)&PacketBuffer[4];
                FreeMemory(connection->ReliableOutPackets[ReliablePacketIndex]);
                connection->ReliableOutPackets[ReliablePacketIndex] = 0;
                if ( connection->ReliablePacketsPending < connection->ReliablePacketsCurrent )
                {
                    do
                    {
                        if ( connection->ReliableOutPackets[connection->ReliablePacketsPending % 256] )
                            break;
                        connection->ReliablePacketsPending++;
                    }
                    while ( connection->ReliablePacketsPending + 1 < connection->ReliablePacketsCurrent );
                }
            }
            goto RETURN_FREE_MEMORY;
        case 3:	//0x03 - Reliable Message
            if ( PacketLength < 6 )
                goto RETURN_FREE_MEMORY;
            //You tell the client which ACK packet you already recieved so it won't send it anymore.
            OutBuffer[0] = 0;
            OutBuffer[1] = 4;                          // 0x04 - Reliable ACK
            *(unsigned int *)&OutBuffer[2] = *(unsigned int *)&buffer[2]; //ACK ID
            SendPacketCluster(connection, OutBuffer, 6);
            RecievedACK_Id = *(unsigned int *)&buffer[2];	//ACK ID
            if ( RecievedACK_Id > connection->HighestRecievedReliableMessageACKID )
                connection->HighestRecievedReliableMessageACKID = RecievedACK_Id;
            if ( connection->CurrentReliableMessageACKID > RecievedACK_Id )
                goto RETURN_FREE_MEMORY;
            //Currently this packet's turn to get processed
            if ( connection->CurrentReliableMessageACKID == RecievedACK_Id )
            {
                ProcessCorePackets(connection, &buffer[6], PacketLength - 6, 0);
                connection->CurrentReliableMessageACKID++;
                //TODO: Cleaned obfuscation.
                //AFAIK this works like this..
                //if a pattern of ACK's gets created like 2,3,4,5 ACK's all filled in and Current ACK is 2
                //Then all 2,3,4,5 get processed right away, if only 2,4,5 is filled in and current is 2 then only 2 gets processed.
                //If above Current ACK is 3 with pattern 2,3,4,5 then 3,4,5 get processed, and 2 gets glitched up (shouldn't happen?).
                //ACK's keep getting resent if any of them are missing in random order.
                for ( i = connection->CurrentReliableMessageACKID; connection->ReliableInPackets[i]; i++)
                {
                    ProcessCorePackets(
                        connection,
                        connection->ReliableInPackets[i % 256] + 2,
                        *(unsigned short *)connection->ReliableInPackets[i % 256],
                        0);
                    FreeMemory(connection->ReliableInPackets[i % 256]);
                    connection->ReliableInPackets[i % 256] = 0;
                    connection->CurrentReliableMessageACKID = i + 1;
                }
            }
            else
            {
                if ( !connection->ReliableInPackets[RecievedACK_Id % 256] )
                {
                    PacketSize = PacketLength - 6;
                    connection->ReliableInPackets[RecievedACK_Id % 256] = AllocateMemory(PacketSize + 2);
                    //first 2 bytes for this pointer is size.
                    *(unsigned short *)connection->ReliableInPackets[RecievedACK_Id % 256] = PacketSize;
                    memcpy(connection->ReliableInPackets[RecievedACK_Id % 256] + 2, &buffer[6], PacketSize);
                }
            }
            goto RETURN_FREE_MEMORY;
        case 6:	//0x06 - Sync Response
            v31 = GetTickCount() / 0xA - *(unsigned int *)&buffer[2];	//Received Timestamp
            ++connection->TotalSyncResponses;
            connection->dword1E = v31 + connection->dword1E;
            if ( connection->LowestSyncResponseDelay > 0 || v31 < connection->LowestSyncResponseDelay )
                connection->LowestSyncResponseDelay = v31;
            if ( v31 > connection->HighestSyncResponseDelay )
                connection->HighestSyncResponseDelay = v31;
            if ( v31 <= (connection->dwordA + 1)
                    || (GetTickCount() / 0xA - connection->dword16) > 12000 )
            {
                if ( v31 < (connection->dwordA * 2)
                        || (GetTickCount() / 0xA - connection->dword16) > 60000 )
                {
                    connection->SyncResponseLocalTimeStamp = *(unsigned int *)&buffer[6]	//Local Timestamp
                            + v31 * (1000 - connection->MyPacketAttachment->dword24) / 1000
                            - (GetTickCount() / 0xA);
                    connection->dword16 = GetTickCount() / 0xA;
                    connection->dwordA = v31;
                }
            }
            goto RETURN_FREE_MEMORY;
        case 5:	//0x05 - Sync Request To Sync Time
            OutBuffer[0] = 0;
            OutBuffer[1] = 6;                          // 0x06 - Sync Response
            *(unsigned int *)&OutBuffer[2] = *(unsigned int *)&buffer[2];            // Received Timestamp
            *(unsigned int *)&OutBuffer[6] = GetTickCount() / 0xA;            // Local Timestamp
            SendPacket(connection, OutBuffer, 10);
            connection->TotalPacketsClientRecieved = *(unsigned int *)&buffer[6]; //most likely means TotalPacketsRecieved something.
            connection->TotalPacketsClientSent = *(unsigned int *)&buffer[10]; //most likely means TotalPacketsSent something.
            if ( PacketLength > 6 )
            {
                if ( connection->TotalPacketsSent <= 300 )
                    connection->ServerToYou = 1000;
                else
                    connection->ServerToYou = 1000 * connection->TotalPacketsSent / connection->TotalPacketsClientSent;

                if ( connection->TotalPacketsClientRecieved <= 300 )
                    connection->YouToServer = 1000;
                else
                    connection->YouToServer = 1000 * connection->TotalPacketsRecieved / connection->TotalPacketsClientRecieved;
            }
            goto RETURN_FREE_MEMORY;
        case 11:	//0x0B - Cancel Huge Chunk
            v38 = 0;
            if ( connection->TotalHugeChunks > 0 )
            {
                do
                {
                    if ( connection->HugeChunk[v38].IsMemoryAllocated )
                        FreeMemory(connection->HugeChunk[v38].PacketBuffer);
                    ++v38;
                }
                while ( v38 < connection->TotalHugeChunks );
            }
            connection->TotalHugeChunks = 0;
            if ( connection->HugeChunkRecievePacket )
                FreeMemory(connection->HugeChunkRecievePacket);
            connection->HugeChunkRecievePacket = 0;
            connection->HugeChunkRecieveTotalSize = 0;
            connection->HugeChunkRecievedSize = 0;

            OutBuffer[0] = 0;
            OutBuffer[1] = 0x0C;	//0x0C - Cancel Huge Chunk ACK
            SendReliablePacket(connection, OutBuffer, 2, 1);
            goto RETURN_FREE_MEMORY;
        case 12:	//0x0C - Cancel Huge Chunk ACK
            v41 = 0;
            if ( connection->TotalHugeChunks > 0 )
            {
                do
                {
                    if ( connection->HugeChunk[v41].IsMemoryAllocated )
                        FreeMemory(connection->HugeChunk[v41].PacketBuffer);
                    ++v41;
                }
                while ( v41 < connection->TotalHugeChunks );
            }
            connection->TotalHugeChunks = 0;
            if ( connection->HugeChunkRecievePacket )
                FreeMemory(v43);
            connection->HugeChunkRecievePacket = 0;
            connection->HugeChunkRecieveTotalSize = 0;
            connection->HugeChunkRecievedSize = 0;
            goto RETURN_FREE_MEMORY;
        case 8:	//0x08 - Small Chunk Body
        case 9:	//0x09 - Small Chunk Tail
            connection->SmallChunkPacketSize = PacketLength + connection->SmallChunkPacketSize - 2;
            connection->SmallChunkPacketBuffer = (char *)ExpandMemory(connection->SmallChunkPacketBuffer, connection->SmallChunkPacketSize, 1);
            memcpy(&connection->SmallChunkPacketBuffer[connection->SmallChunkPacketSize], buffer + 2, PacketLength - 2);
            if ( buffer[1] == 9 ) //if tail detected only!
            {
                ProcessCorePackets(connection, connection->SmallChunkPacketBuffer, connection->SmallChunkPacketSize, 1);
                connection->SmallChunkPacketBuffer = 0;
                connection->SmallChunkPacketSize = 0;
            }
            goto RETURN_FREE_MEMORY;
        case 10:	//0x0A - HUGE Chunk
            if ( PacketLength < 6 )
                goto RETURN_FREE_MEMORY;
            v48 = *(unsigned int *)&buffer[2];
            if ( v48 < 0 || v48 >= 20971520 )       // 20 Megabytes (if it's in bytes)
                goto LABEL_78;
            connection->HugeChunkRecieveTotalSize = v48;
            if ( !connection->HugeChunkRecievePacket ) //Start a fresh HUGE Chunk transfer
            {
                connection->HugeChunkRecievePacket = AllocateMemory(v48);
                connection->HugeChunkRecievedSize = 0;
            }
            memcpy(&connection->HugeChunkRecievePacket[connection->HugeChunkRecievedSize], &buffer[6], PacketLength - 6);
            connection->HugeChunkRecievedSize = (PacketLength - 6 + connection->HugeChunkRecievedSize);
            if ( connection->HugeChunkRecievedSize == connection->HugeChunkRecieveTotalSize )
            {
                ProcessCorePackets(connection, connection->HugeChunkRecievePacket, connection->HugeChunkRecieveTotalSize, 1);
                connection->HugeChunkRecievedSize = 0;
                connection->HugeChunkRecieveTotalSize = 0;
                connection->HugeChunkRecievePacket = 0;
            }
            goto RETURN_FREE_MEMORY;
        case 7:	//0x07 - Order to Disconnect
LABEL_78:
            connection->state = 4; //4 = Disconnected
            goto RETURN_FREE_MEMORY;
        case 14:	//0x0E - Packet Cluster
            v52 = 0; //counter.
            if ( buffer[2] < PacketLength )
            {
                do
                {
                    //buffer[2+X] = packet size
                    //buffer[3+X] = packet data
                    ProcessCorePackets(connection, &buffer[3+v52], buffer[2+v52], 0);
                    v52 += buffer[2+v52];
                }
                while ( (3+v52) < PacketLength );
            }
            break;
        }
        goto RETURN_FREE_MEMORY;
    }
    ProcessRegularPackets(connection->MyPacketAttachment, buffer, PacketLength, connection, a4);
    a4 = 0;
RETURN_FREE_MEMORY:
    if ( a4 )
        FreeMemory(buffer);
}

//----- (0041C2B0) --------------------------------------------------------
void __cdecl SendBiDirectionalCorePackets(struct CONNECTION *connection)
{
    int v2; // eax@1
    __int64 v3; // qax@2
    int v4; // edx@3
    __int64 v5; // qax@6
    signed int v6; // eax@6
    unsigned int v7; // kr00_4@11
    int v8; // eax@11
    signed int v9; // eax@13
    int HugeChunkTotal; // eax@17
    int HugeChunkSent; // edx@17
    int HugeChunkRemaining; // eax@17
    unsigned int HugeChunkPacketSize; // ebx@17
    int v14; // ecx@19
    int v15; // eax@19
    int v16; // eax@22
    signed int v17; // ebx@25
    DWORD v18; // esi@25
    unsigned char *PacketBuffer; // ecx@25
    unsigned int PacketSize; // edi@25
    signed int v21; // ebx@28
    int i; // edi@30
    unsigned char *PacketBuffer2; // ecx@32
    char buffer1[14]; // [sp+10h] [bp-210h]@3
    unsigned char buffer2[492]; // [sp+20h] [bp-200h]@17

    if ( connection->state == 1 ) //1 = Encryption Request
    {
        if ( (GetTickCount() / 0xA - connection->KeepAliveDelayTimer) > 100 ) //1 second delay
        {
            buffer1[0] = 0;                               // BI : Bi-directional Core Packets
            buffer1[1] = 0x01;                               // 0x01 - Encryption Request
            *(unsigned int *)&buffer1[2] = connection->ServerKey;                  // Client Encryption Key
            *(unsigned short *)&buffer1[6] = 1;                    // Client Version/Type      0x0001 - Subspace
            SendPacket(connection, buffer1, 8);
        }
    }
    else if ( connection->state == 2 ) //2 = Encryption is initialized
    {
        if ( connection->dword6 )
        {
            if ( (v6 = (GetTickCount() / 0xA - connection->dword12),
                    v6 > 2000) //20 second delay
                    || v6 > 500 && connection->dwordA > 300 //5 second delay
                    || v6 > 50 && connection->dwordA > 1000 ) //500 millisecond delay
            {
                connection->dword12 = GetTickCount() / 0xA;
                buffer1[0] = 0;                           // BI : Bi-directional Core Packets
                buffer1[1] = 0x05;                           // 0x05 - Sync Request To Sync Time
                *(unsigned int *)&buffer1[2] = GetTickCount() / 0xA;        // Timestamp
                *(unsigned int *)&buffer1[6] = connection->TotalPacketsSent + 1; // Total Packets Sent
                *(unsigned int *)&buffer1[10] = connection->TotalPacketsRecieved;             // Total Packets Received
                SendPacket(connection, buffer1, 14);
            }
        }
        while ( connection->TotalHugeChunks > 0 )
        {
            //If packet is over 2 KB in size or there is over 128 reliable packets pending to be sent
            //Then don't send HUGE Chunk packet just yet.
            if ( connection->MaxOutPacketSizeQueue >= 2048
                    || (connection->ReliablePacketsCurrent - connection->ReliablePacketsPending) >= 128
                    || connection->HugeChunk[0].field_10
                    && connection->MaxOutPacketSizeQueue > 256 )
                break;
            HugeChunkTotal = connection->HugeChunk[0].TotalLength;
            HugeChunkSent = connection->HugeChunk[0].SentLength;
            HugeChunkRemaining = connection->HugeChunk[0].TotalLength - connection->HugeChunk[0].SentLength;
            buffer2[0] = 0;             // BI : Bi-directional Core Packets (guess, since it's biller packet)
            buffer2[1] = 0x0A;      // 0x0A - HUGE Chunk (guess, since it's biller packet)
            *(unsigned int *)&buffer2[2] = connection->HugeChunk[0].TotalLength; // Total Length
            PacketSize = 480;
            if ( HugeChunkRemaining <= 480 )
                PacketSize = HugeChunkRemaining;
            memcpy(
                &buffer2[6],
                &connection->HugeChunk[0].PacketBuffer[HugeChunkSent],
                PacketSize);
            SendReliablePacket(connection, buffer2, PacketSize + 6, 1);

            connection->HugeChunk[0].SentLength += PacketSize;
            HugeChunkSent = connection->HugeChunk[0].SentLength;

            if ( HugeChunkSent == HugeChunkTotal )
            {
                //Finished sending HUGE CHUNK
                //Free Memory and remove HUGE CHUNK from the Queue.
                if ( connection->HugeChunk[0].IsMemoryAllocated )
                    FreeMemory(connection->HugeChunk[0].PacketBuffer);
                connection->TotalHugeChunks--;
                memcpy(connection->HugeChunk, &connection->HugeChunk[1], sizeof(struct HUGE_CHUNK_STRUCT) * connection->TotalHugeChunks);
            }
        }
        if ( connection->ReliablePacketsPending < connection->ReliablePacketsCurrent )
        {
            v17 = 90; //0.9 seconds.
            PacketBuffer = connection->ReliableOutPackets[connection->ReliablePacketsPending % 256];
            PacketSize = *(unsigned short *)&PacketBuffer[4]; //2 bytes after first 4 bytes is size.
            if ( PacketSize > 256 )
                v17 = 170; //1.7 seconds.
            if ( (GetTickCount() / 0xA - *(unsigned int *)&PacketBuffer[0]) <= v17 )
            {
                //Packet is too early to be sent, by timer standards?
                v21 = 0;
            } else {
                //Send the packet
                *(unsigned int *)&PacketBuffer[0] = GetTickCount() / 0xA; //first 4 bytes are a timer.
                SendPacketCluster(connection, &PacketBuffer[6], PacketSize);
                v21 = 1;
            }
            //Loop through all pending reliable packets to be sent and send them all if time has came.
            for ( i = connection->ReliablePacketsPending + 1; i < connection->ReliablePacketsCurrent; ++i )
            {
                if ( v21 >= 3 ) //limit of only 2 packets to send.
                    break;
                PacketBuffer = connection->ReliableOutPackets[i % 256];
                if ( PacketBuffer )
                {
                    if ( (GetTickCount() / 0xA - *(unsigned int *)&PacketBuffer[0]) > 200 ) //2 second delay
                    {
                        *(unsigned int *)&PacketBuffer[0] = GetTickCount() / 0xA;
                        SendPacketCluster(connection, &PacketBuffer[6], *(unsigned short *)&PacketBuffer[4]);
                    }
                    ++v21;
                }
            }
        }
    }
}

//----- (0041C5E0) --------------------------------------------------------
bool __cdecl SendReliablePacket(struct CONNECTION *connection, unsigned char *buffer, unsigned int len, int IsSendReliable)
{
    unsigned int v4; // edi@1
    //struct CONNECTION *connection; // ebx@1
    signed int TotalProcessed; // esi@2
    unsigned int AmountLeft; // ebp@5
    int v9; // esi@13
    unsigned char *PacketBuffer; // eax@13
    int v11; // ebp@13
    DWORD PacketDelayTime; // edx@14
    int v13; // ebp@16
    int v14; // ebp@16
    int v15; // edx@16
    const void *v16; // [sp-8h] [bp-214h]@17
    unsigned int v17; // [sp-4h] [bp-210h]@17
    signed int v18; // [sp+10h] [bp-1FCh]@2
    unsigned int v19; // [sp+10h] [bp-1FCh]@13
    int v20; // [sp+14h] [bp-1F8h]@13
    char v21[500]; // [sp+18h] [bp-1F4h]@7

    if ( len > 496 )
    {
        TotalProcessed = 0;

        if ( len > 0 )
        {
            while ( 1 )
            {
                AmountLeft = len - TotalProcessed;
                if ( (len - TotalProcessed) >= 480 )
                    AmountLeft = 480;
                v21[0] = 0;
                v21[1] = (AmountLeft == len - TotalProcessed) + 8;
                memcpy(&v21[2], &buffer[TotalProcessed], AmountLeft);
                if ( !SendReliablePacket(connection, v21, AmountLeft + 2, 1) )
                    break;
                TotalProcessed += AmountLeft;
                if ( TotalProcessed >= len )
                    return 1;
            }
            return 0;
        }
        return 1;
    }
    if ( !IsSendReliable )
    {
        SendPacketCluster(connection, buffer, len);
        return 1; //sent successfully
    }
    if ( connection->ReliablePacketsCurrent - connection->ReliablePacketsPending >= 255 )
        return 0; //failed to send

    PacketBuffer = AllocateMemory(len + 12);
    connection->ReliableOutPackets[connection->ReliablePacketsCurrent % 256] = PacketBuffer;

    if ( connection->MaxOutPacketSizeQueue < 4096 )
        PacketDelayTime = GetTickCount() / 0xA;
    else
        PacketDelayTime = 0;
    *(unsigned int *)&PacketBuffer[0] = PacketDelayTime; //Delay header of packet array
    *(unsigned short *)&PacketBuffer[4] = (len + 6); //Packet size of packet array

    PacketBuffer[6]= 0;
    PacketBuffer[7] = 0x03;  //0x03 - Reliable Message
    *(unsigned int *)&PacketBuffer[8] = connection->ReliablePacketsCurrent;  //ACK ID
    memcpy(&PacketBuffer[12], buffer, len);

    if ( connection->MaxOutPacketSizeQueue < 4096 )
        SendPacketCluster(connection, &PacketBuffer[6], len + 6);

    connection->MaxOutPacketSizeQueue += (len + 6);
    connection->ReliablePacketsCurrent += 1;

    return 1; //sent successfully
}

//----- (0041C7C0) --------------------------------------------------------
void __cdecl SaveLostReliablePackets(struct CONNECTION *connection, const char *Filename)
{
    FILE *result; // eax@1
    FILE *v3; // ebx@1
    int i; // ebp@2
    unsigned char *PacketBuffer; // esi@3
    int PacketSize; // edi@4
    unsigned char *Packet; // esi@4

    v3 = fopen(Filename, "wt");
    if ( v3 )
    {
        for ( i = connection->ReliablePacketsPending; i < connection->ReliablePacketsCurrent; ++i )
        {
            PacketBuffer = connection->ReliableOutPackets[i % 256];
            if ( PacketBuffer )
            {
                PacketSize = *(unsigned short *)(PacketBuffer + 4);
                fprintf(v3, "%10d %4d: ", *(unsigned int *)&PacketBuffer[0], PacketSize);
                Packet = &PacketBuffer[6];
                if ( PacketSize > 0 )
                {
                    do
                    {
                        fprintf(v3, "%02x ", *(unsigned char *)Packet++);
                        --PacketSize;
                    }
                    while ( PacketSize );
                }
                fprintf(v3, "\n");
            }
            else
            {
                fprintf(v3, "Acknowledged\n");
            }
        }
        fclose(v3);
    }
}

//----- (0041C890) --------------------------------------------------------
void __cdecl SendHugeChunkPacketAllocated(struct CONNECTION *connection, unsigned char *MemoryPointer, int TotalLength, int a4)
{
    if ( connection->TotalHugeChunks < 4 )
    {
        connection->HugeChunk[connection->TotalHugeChunks].PacketBuffer = MemoryPointer;
        connection->HugeChunk[connection->TotalHugeChunks].TotalLength = TotalLength;
        connection->HugeChunk[connection->TotalHugeChunks].SentLength = 0;
        connection->HugeChunk[connection->TotalHugeChunks].IsMemoryAllocated = 1; //compressed?
        connection->HugeChunk[connection->TotalHugeChunks++].field_10 = a4;
        SendBiDirectionalCorePackets(connection);
    }
}

//----- (0041C920) --------------------------------------------------------
void __cdecl SendHugeChunkPacketNotAllocated(struct CONNECTION *connection, unsigned char *MemoryPointer, int TotalLength, int a4)
{
    if ( connection->TotalHugeChunks < 4 )
    {
        connection->HugeChunk[connection->TotalHugeChunks].PacketBuffer = MemoryPointer;
        connection->HugeChunk[connection->TotalHugeChunks].TotalLength = TotalLength;
        connection->HugeChunk[connection->TotalHugeChunks].SentLength = 0;
        connection->HugeChunk[connection->TotalHugeChunks].IsMemoryAllocated = 0;
        connection->HugeChunk[connection->TotalHugeChunks++].field_10 = a4;
        SendBiDirectionalCorePackets(connection);
    }
}

//----- (0041C9B0) --------------------------------------------------------
void __cdecl GetHugeChunkRecieveStats(struct CONNECTION *connection, int *HugeChunkRecieveTotalSize, int *HugeChunkRecievedSize)
{
    *HugeChunkRecieveTotalSize = connection->HugeChunkRecieveTotalSize;
    *HugeChunkRecievedSize = connection->HugeChunkRecievedSize;
}
//----- (0041C9D0) --------------------------------------------------------
void __cdecl GetHugeChunkSendStats(struct CONNECTION *connection, int *HugeChunkSendTotalSize, int *HugeChunkSendSize)
{
    if ( connection->TotalHugeChunks <= 0 )
    {
        *HugeChunkSendTotalSize = 0;
        *HugeChunkSendSize = 0;
    }
    else
    {
        *HugeChunkSendTotalSize = connection->HugeChunk[0].TotalLength;
        *HugeChunkSendSize = connection->HugeChunk[0].SentLength;
    }
}

//----- (0041CA20) --------------------------------------------------------
void __cdecl SendPacketCluster(struct CONNECTION *connection, unsigned char *buf, unsigned int len)
{
    struct CONNECTION *connectionn; // ebp@1
    signed int v4; // ecx@2
    int v5; // eax@3
    int v6; // ecx@10
    void *v7; // ecx@12
    char *PacketBuffer; // [sp-8h] [bp-18h]@6
    unsigned int PacketLength; // [sp-4h] [bp-14h]@6

    if ( len > 255
            || (len + 3) > connection->MyPacketAttachment->CommsTransportBufferSizeLimited )
    {
        SendPacket(connection, buf, len);
    } else {
        if ( connection->ClusterPacketLength == 0
                || connection->ClusterPacket[2] + 3 != connection->ClusterPacketLength )
        {
            //Creates a new Packet Cluster header
            connection->ClusterPacket[0] = 0;
            connection->ClusterPacket[1] = 0x0E; //0x0E - Packet Cluster
            connection->ClusterPacket[2] = len;
            memcpy(&connection->ClusterPacket[3], buf, len);
            connection->ClusterPacketLength = len + 3;
        }
        SendPacket(connection, connection->ClusterPacket, connection->ClusterPacketLength);
        connection->ClusterPacketLength = 0;
    }
    ++connection->MyPacketAttachment->TotalPacketClustersCalls;
}

//----- (0041CB20) --------------------------------------------------------
void __cdecl sub_41CB20(struct CONNECTION *connection)
{
    struct CONNECTION *v1; // esi@1
    int v2; // eax@1
    unsigned char *PacketBuffer; // [sp-8h] [bp-Ch]@3
    unsigned int PacketLength; // [sp-4h] [bp-8h]@3

    v2 = connection->ClusterPacketLength - connection->ClusterPacket[0];
    if ( v2 > 2 )
    {
        if ( connection->ClusterPacket[2] + 3 == v2 ) //Is Cluster Packet?
        {   //Is Cluster Packet?
            PacketLength = connection->ClusterPacketLength - connection->ClusterPacket[3];
            PacketBuffer = &connection->ClusterPacket[3];
        } else { //Is Regular Packet?
            PacketLength = connection->ClusterPacketLength - connection->ClusterPacket[0];
            PacketBuffer = &connection->ClusterPacket[0];
        }
        SendPacket(connection, PacketBuffer, PacketLength);
        connection->ClusterPacketLength = connection->ClusterPacket[0];
    }
}

//----- (0041CB70) --------------------------------------------------------
void __cdecl GetPingLOSSSomething(struct CONNECTION *connection, int *ServerToYou, int *YouToServer)
{
    *ServerToYou = connection->ServerToYou;
    *YouToServer = connection->YouToServer;
}

//----- (0041CB90) --------------------------------------------------------
void __cdecl GetPacketCountInfoSomething(struct CONNECTION *connection, int *a2, int *a3, int *a4, int *a5)
{
    *a2 = connection->TotalPacketsSent;
    *a3 = connection->TotalPacketsRecieved;
    *a4 = connection->TotalPacketsClientRecieved;
    *a5 = connection->TotalPacketsClientSent;
}

//----- (0041CBD0) --------------------------------------------------------
void __cdecl OrderDisconnect(struct CONNECTION *connection)
{
    connection->state = 4; //Forces a disconnect state
}

//----- (0041CBE0) --------------------------------------------------------
char *__cdecl GetIPAddressString(struct in_addr in)
{
    return inet_ntoa(in);
}

//----- (0041CBF0) --------------------------------------------------------
int __cdecl SubspaceEXEChecksum(char *Filename)
{
    char *FileBytes; // eax@1
    unsigned long OutSize; // [sp+0h] [bp-4h]@1
    int CRC_32;

    FileBytes = CompressFile(Filename, &OutSize, &CRC_32, 0, 0, 0);
    if ( FileBytes )
        FreeMemory((LPVOID)FileBytes);
    return CRC_32;
}

//----- (0041CC30) --------------------------------------------------------
char * __cdecl CompressFile(const char *Filename, unsigned long *FileSize, int *CRC_32, const void *Buffer, unsigned int OffsetBytes, int DoFileCompression)
{
    FILE *FileHandle; // eax@1
    FILE *v8; // edi@1
    char *result; // eax@6
    int v10; // eax@8
    unsigned int OriginalFileSize; // ebx@8
    char *OriginalFileBytes; // esi@8
    char *CompressedBytes; // edi@13
    char *v14; // eax@15
    char *ReturnBytes; // ebp@16
    char *ptra; // [sp+18h] [bp+Ch]@14

    FileHandle = fopen(Filename, "rb");
    if ( FileHandle )
    {
        v10 = _fileno(FileHandle);
        OriginalFileSize = _filelength(v10);
        OriginalFileBytes = AllocateMemory(OriginalFileSize);
        fread(OriginalFileBytes, OriginalFileSize, 1, FileHandle);
        fclose(FileHandle);
        if ( FileSize )
            *FileSize = OriginalFileSize;
        if ( CRC_32 )
            *CRC_32 = CRC32(OriginalFileBytes, OriginalFileSize);
        if ( DoFileCompression )
        {
            *FileSize = (4 * OriginalFileSize) / 3 + 12;
            CompressedBytes = ExpandMemory(0, *FileSize, 1);
            if ( compress(CompressedBytes, FileSize, OriginalFileBytes, OriginalFileSize) )
            {
                FreeMemory(CompressedBytes);
            } else {
                CompressedBytes = ExpandMemory(CompressedBytes, *FileSize, 1);
            }
            ReturnBytes = AllocateMemory(*FileSize + OffsetBytes);
            if ( Buffer )
                memcpy(ReturnBytes, Buffer, OffsetBytes);
            memcpy(&ReturnBytes[OffsetBytes], CompressedBytes, *FileSize);
            FreeMemory(CompressedBytes);
        } else {
            *FileSize = OriginalFileSize + OffsetBytes;
            ReturnBytes = AllocateMemory(*FileSize);
            if ( Buffer )
                memcpy(ReturnBytes, Buffer, OffsetBytes);
            memcpy(&ReturnBytes[OffsetBytes], OriginalFileBytes, OriginalFileSize);
        }
        FreeMemory(OriginalFileBytes);
        result = ReturnBytes;
    }
    else
    {
        if ( CRC_32 )
            *CRC_32 = 0;
        if ( FileSize )
            *FileSize = 0;
        *FileSize = OffsetBytes;
        result = AllocateMemory(*FileSize);
        if ( Buffer )
            memcpy(result, Buffer, OffsetBytes);
    }
    return result;
}
// 41CE30: using guessed type int __stdcall compress(unsigned int, unsigned int, unsigned int, unsigned int);
// 41F1B0: using guessed type unsigned int __cdecl _filelength(unsigned int);

//----- (0041CEA0) --------------------------------------------------------
/*void __cdecl setRNGSeed(int SeedRNG)
{ //un-used this is srand(), look below..
  RNGSeed = SeedRNG;
}*/
// 42E458: using guessed type int RNGSeed;

/*
int __cdecl rand()
{ //see it's this is what rand() is.
  RNGSeed = 0x343FD * RNGSeed + 0x269EC3;
  return (RNGSeed >> 16) & 0x7FFF;
}
*/

//----- (0041E940) --------------------------------------------------------
/*int __cdecl system(char *argumentsPointer)
{
  int result; // eax@1
  char *v2; // eax@8
  int arguments[4]; // [sp+0h] [bp-10h]@1

  result = (int)getenv("COMSPEC");
  arguments[0] = result;
  if ( argumentsPointer )
  {
    arguments[1] = (int)"/c";
    arguments[2] = (int)argumentsPointer;
    arguments[3] = 0;
    if ( !result
      || (result = _spawnve(0, (char *)result, (int)arguments, 0), result == -1)
      && (dword_4D8B38 == 2 || dword_4D8B38 == 13) )// _P_WAIT
    {
      v2 = "command.com";
      if ( !(BYTE1(dword_4D8B44) & 0x80) )      // Byte 2
        v2 = "cmd.exe";
      arguments[0] = (int)v2;
      result = _spawnvpe(0, v2, (int)arguments, 0);// _P_WAIT
    }
  }
  else
  {
    if ( result )
      result = _access((LPCSTR)result, 0) == 0;
  }
  return result;
}*/

// 4D8B38: using guessed type int dword_4D8B38;
// 4D8B44: using guessed type int dword_4D8B44;

//----- (004210C9) --------------------------------------------------------
/*int __cdecl sub_4210C9(int a1)
{
  return ExFilterRethrow(*(struct _EXCEPTION_POINTERS **)(a1 - 20));
}*/

//----- (004210D6) --------------------------------------------------------
//#error "4210FB: positive sp value has been found (funcsize=11)"

//----- (00421101) --------------------------------------------------------
/*void __cdecl sub_421101()
{
  JUMPOUT(sub_42110A);
}*/

//----- (004214B0) --------------------------------------------------------
/*void __cdecl sub_4214B0(int a1, int a2, int a3, int a4)
{
  int v4; // [sp-Ch] [bp-24h]@1
  int v5; // [sp-8h] [bp-20h]@1
  int v6; // [sp-4h] [bp-1Ch]@1
  int *v7; // [sp+0h] [bp-18h]@1
  int v8; // [sp+8h] [bp-10h]@1
  int (__cdecl *v9)(int, PVOID, int); // [sp+Ch] [bp-Ch]@1
  int v10; // [sp+10h] [bp-8h]@1
  int v11; // [sp+14h] [bp-4h]@1

  v10 = (int)dword_429128;
  v9 = unknown_libname_6;
  v8 = a1;
  v6 = a2;
  v5 = a4;
  v4 = a3;
  v7 = &v4;
  v11 = 0;
  if ( dword_4D8BDC )
  {
    v11 = 1;
    dword_4D8BDC(v4, v5, v6, v7);
    v11 = 0;
  }
  v11 = -1;
  j__abort();
}*/
// 429128: using guessed type int dword_429128[2];
// 4D8BDC: using guessed type int (__cdecl *dword_4D8BDC)(unsigned int, unsigned int, unsigned int, unsigned int);

//----- (00421540) --------------------------------------------------------
/*void __cdecl sub_421540(int a1, int a2, int a3, int a4)
{
  int v4; // [sp-Ch] [bp-24h]@1
  int v5; // [sp-8h] [bp-20h]@1
  int v6; // [sp-4h] [bp-1Ch]@1
  int v7; // [sp+0h] [bp-18h]@1
  int v8; // [sp+8h] [bp-10h]@1
  int (__cdecl *v9)(int, PVOID, int); // [sp+Ch] [bp-Ch]@1
  int v10; // [sp+10h] [bp-8h]@1
  int v11; // [sp+14h] [bp-4h]@1

  v10 = (int)dword_429140;
  v9 = unknown_libname_6;
  v8 = a1;
  v6 = a2;
  v5 = a4;
  v4 = a3;
  v7 = (int)&v4;
  v11 = 0;
  if ( off_42E734 )
  {
    v11 = 1;
    off_42E734(v4, v5, v6, v7);
    JUMPOUT(*(int *)loc_42157F);
  }
  v11 = -1;
  sub_4215AE(v4, v5, v6, v7);
}*/
// 42157F: using guessed type int();
// 4215AE: using guessed type int __cdecl sub_4215AE(unsigned int, unsigned int, unsigned int, unsigned int);
// 429140: using guessed type int[2];
// 42E734: using guessed type int (__cdecl *off_42E734)(unsigned int, unsigned int, unsigned int, unsigned int);

//----- (00423390) --------------------------------------------------------
/*signed int __cdecl DateFunction(int a1)
{
  signed int result; // eax@2
  int v2; // eax@3
  int v3; // ecx@15
  int v4; // eax@26
  signed int v5; // [sp-28h] [bp-30h]@7
  signed int v6; // [sp-28h] [bp-30h]@11
  int v7; // [sp-24h] [bp-2Ch]@7
  int v8; // [sp-24h] [bp-2Ch]@10
  int v9; // [sp-20h] [bp-28h]@7
  signed int v10; // [sp-20h] [bp-28h]@10
  int v11; // [sp-1Ch] [bp-24h]@7
  signed int v12; // [sp-1Ch] [bp-24h]@10
  int v13; // [sp-18h] [bp-20h]@7
  int v14; // [sp-18h] [bp-20h]@10
  int v15; // [sp-14h] [bp-1Ch]@7
  int v16; // [sp-14h] [bp-1Ch]@10
  int v17; // [sp-10h] [bp-18h]@7
  signed int v18; // [sp-10h] [bp-18h]@10
  int v19; // [sp-Ch] [bp-14h]@7
  int v20; // [sp-Ch] [bp-14h]@10
  int v21; // [sp-8h] [bp-10h]@7
  int v22; // [sp-8h] [bp-10h]@10
  int v23; // [sp-4h] [bp-Ch]@7
  int v24; // [sp-4h] [bp-Ch]@10

  if ( !dword_43099C )
    return 0;
  v2 = *(unsigned int *)(a1 + 20);
  if ( v2 != dword_430A30 || v2 != dword_430A40 )
  {
    if ( dword_4D8C18 )
    {
      if ( TimeZoneInformation.DaylightDate.wYear )
      {
        v23 = TimeZoneInformation.DaylightDate.wMilliseconds;
        v21 = TimeZoneInformation.DaylightDate.wSecond;
        v19 = TimeZoneInformation.DaylightDate.wMinute;
        v17 = TimeZoneInformation.DaylightDate.wHour;
        v15 = TimeZoneInformation.DaylightDate.wDay;
        v13 = 0;
        v11 = 0;
        v9 = TimeZoneInformation.DaylightDate.wMonth;
        v7 = *(unsigned int *)(a1 + 20);
        v5 = 0;
      }
      else
      {
        v23 = TimeZoneInformation.DaylightDate.wMilliseconds;
        v21 = TimeZoneInformation.DaylightDate.wSecond;
        v19 = TimeZoneInformation.DaylightDate.wMinute;
        v17 = TimeZoneInformation.DaylightDate.wHour;
        v15 = 0;
        v13 = TimeZoneInformation.DaylightDate.wDayOfWeek;
        v11 = TimeZoneInformation.DaylightDate.wDay;
        v9 = TimeZoneInformation.DaylightDate.wMonth;
        v7 = *(unsigned int *)(a1 + 20);
        v5 = 1;
      }
      cvtdate(1, v5, v7, v9, v11, v13, v15, v17, v19, v21, v23);
      if ( TimeZoneInformation.StandardDate.wYear )
      {
        v24 = TimeZoneInformation.StandardDate.wMilliseconds;
        v22 = TimeZoneInformation.StandardDate.wSecond;
        v20 = TimeZoneInformation.StandardDate.wMinute;
        v18 = TimeZoneInformation.StandardDate.wHour;
        v16 = TimeZoneInformation.StandardDate.wDay;
        v14 = 0;
        v12 = 0;
        v10 = TimeZoneInformation.StandardDate.wMonth;
        v8 = *(unsigned int *)(a1 + 20);
        v6 = 0;
LABEL_14:
        cvtdate(0, v6, v8, v10, v12, v14, v16, v18, v20, v22, v24);
        goto LABEL_15;
      }
      v24 = TimeZoneInformation.StandardDate.wMilliseconds;
      v22 = TimeZoneInformation.StandardDate.wSecond;
      v20 = TimeZoneInformation.StandardDate.wMinute;
      v18 = TimeZoneInformation.StandardDate.wHour;
      v16 = 0;
      v14 = TimeZoneInformation.StandardDate.wDayOfWeek;
      v12 = TimeZoneInformation.StandardDate.wDay;
      v10 = TimeZoneInformation.StandardDate.wMonth;
      v8 = *(unsigned int *)(a1 + 20);
    }
    else
    {
      cvtdate(1, 1, v2, 4, 1, 0, 0, 2, 0, 0, 0);
      v24 = 0;
      v22 = 0;
      v20 = 0;
      v18 = 2;
      v16 = 0;
      v14 = 0;
      v12 = 5;
      v10 = 10;
      v8 = *(unsigned int *)(a1 + 20);
    }
    v6 = 1;
    goto LABEL_14;
  }
LABEL_15:
  v3 = *(unsigned int *)(a1 + 28);
  if ( dword_430A34 < dword_430A44 )
  {
    if ( v3 >= dword_430A34 && v3 <= dword_430A44 )
    {
      if ( v3 > dword_430A34 && v3 < dword_430A44 )
        return 1;
      goto LABEL_26;
    }
    return 0;
  }
  if ( v3 < dword_430A44 || v3 > dword_430A34 )
    return 1;
  if ( v3 > dword_430A44 && v3 < dword_430A34 )
    return 0;
LABEL_26:
  v4 = 1000 * (*(unsigned int *)a1 + 60 * (*(unsigned int *)(a1 + 4) + 60 * *(unsigned int *)(a1 + 8)));
  if ( v3 == dword_430A34 )
    result = v4 >= dword_430A38;
  else
    result = v4 < dword_430A48;
  return result;
}*/
// 423600: using guessed type unsigned int __cdecl cvtdate(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
// 43099C: using guessed type int dword_43099C;
// 430A30: using guessed type int dword_430A30;
// 430A34: using guessed type int dword_430A34;
// 430A38: using guessed type int dword_430A38;
// 430A40: using guessed type int dword_430A40;
// 430A44: using guessed type int dword_430A44;
// 430A48: using guessed type int dword_430A48;
// 4D8C18: using guessed type int dword_4D8C18;

//----- (00426670) --------------------------------------------------------
/*int __cdecl sub_426670(int a1, int a2)
{
  return _ld12cvt(a1, a2, dword_430E60);
}*/
// 4264A0: using guessed type unsigned int __cdecl _ld12cvt(unsigned int, unsigned int, unsigned int);
// 430E60: using guessed type int dword_430E60[6];

//----- (00426690) --------------------------------------------------------
/*int __cdecl sub_426690(int a1, int a2)
{
  return _ld12cvt(a1, a2, dword_430E78);
}*/
// 4264A0: using guessed type unsigned int __cdecl _ld12cvt(unsigned int, unsigned int, unsigned int);
// 430E78: using guessed type int dword_430E78[6];

//----- (004266B0) --------------------------------------------------------
/*int __cdecl sub_4266B0(int a1, int a2)
{
  char v3; // [sp+0h] [bp-Ch]@1

  __strgtold12(&v3, &a2, a2, 0, 0, 0, 0);
  return sub_426670((int)&v3, a1);
}*/
// 427370: using guessed type unsigned int __cdecl __strgtold12(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);

//----- (004266F0) --------------------------------------------------------
/*int __cdecl sub_4266F0(int a1, int a2)
{
  char v3; // [sp+0h] [bp-Ch]@1

  __strgtold12(&v3, &a2, a2, 0, 0, 0, 0);
  return sub_426690((int)&v3, a1);
}*/
// 427370: using guessed type unsigned int __cdecl __strgtold12(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);

//----- (004283A0) --------------------------------------------------------
/*HANDLE __cdecl getch()
{
  HANDLE result; // eax@2
  signed int v1; // esi@10
  int v2; // eax@11
  unsigned int NumberOfEventsRead; // [sp+10h] [bp-1Ch]@6
  unsigned int dwMode; // [sp+14h] [bp-18h]@6
  struct _INPUT_RECORD Buffer; // [sp+18h] [bp-14h]@6

  if ( dword_431490 == -1 )
  {
    result = hConsoleHandle;
    if ( hConsoleHandle != (HANDLE)-1 )
    {
      if ( hConsoleHandle == (HANDLE)-2 )
      {
        __initconin();
        result = hConsoleHandle;
      }
      GetConsoleMode(result, &dwMode);
      SetConsoleMode(hConsoleHandle, 0);
      if ( ReadConsoleInputA(hConsoleHandle, &Buffer, 1u, &NumberOfEventsRead) )
      {
        while ( NumberOfEventsRead )
        {
          if ( Buffer.EventType == 1 && Buffer.Event.KeyEvent.bKeyDown )
          {
            v1 = *((unsigned char*)&(Buffer.Event.KeyEvent.uChar.UnicodeChar));
            if ( *((unsigned char*)&(Buffer.Event.KeyEvent.uChar.UnicodeChar)) )
              goto LABEL_14;
            v2 = _getextendedkeycode(&Buffer.Event);
            if ( v2 )
            {
              v1 = *(unsigned char *)v2;
              dword_431490 = *(unsigned char *)(v2 + 1);
              goto LABEL_14;
            }
          }
          if ( !ReadConsoleInputA(hConsoleHandle, &Buffer, 1u, &NumberOfEventsRead) )
            break;
        }
      }
      v1 = -1;
LABEL_14:
      SetConsoleMode(hConsoleHandle, dwMode);
      result = (HANDLE)v1;
    }
  }
  else
  {
    result = (HANDLE)(unsigned char)dword_431490;
    dword_431490 = -1;
  }
  return result;
}*/
// 4285A0: using guessed type unsigned int __cdecl _getextendedkeycode(unsigned int);
// 428720: using guessed type int __initconin(void);
// 431490: using guessed type int dword_431490;

//----- (004284B0) --------------------------------------------------------
/*signed int __cdecl _kbhit()
{
  HANDLE v1; // eax@3
  int v2; // eax@8
  void *v3; // esp@8
  int *v4; // edi@8
  unsigned int v5; // eax@10
  int *v6; // esi@13
  int v7; // [sp+0h] [bp-10h]@8
  int v8; // [sp+4h] [bp-Ch]@13
  unsigned int nLength; // [sp+8h] [bp-8h]@6
  unsigned int NumberOfEventsRead; // [sp+Ch] [bp-4h]@9

  if ( dword_431490 != -1 )
    return 1;
  v1 = hConsoleHandle;
  if ( hConsoleHandle == (HANDLE)-2 )
  {
    __initconin();
    v1 = hConsoleHandle;
  }
  if ( v1 != (HANDLE)-1 )
  {
    if ( GetNumberOfConsoleInputEvents(v1, &nLength) )
    {
      if ( nLength )
      {
        v2 = 20 * nLength + 3;
        *((unsigned char*)&(v2)) = v2 & 0xFC;
        v3 = alloca(v2); //char v7[v2];
        v4 = &v7;
        if ( &v7 )
        {
          if ( PeekConsoleInputA(hConsoleHandle, (PINPUT_RECORD)&v7, nLength, &NumberOfEventsRead) )
          {
            v5 = NumberOfEventsRead;
            if ( NumberOfEventsRead )
            {
              if ( NumberOfEventsRead <= nLength && NumberOfEventsRead )
              {
                v6 = &v8;
                while ( 1 )
                {
                  if ( *(unsigned short *)v4 == 1 && *v6 )
                  {
                    if ( *((unsigned char *)v6 + 10) || _getextendedkeycode(v6) )
                      return 1;
                    v5 = NumberOfEventsRead;
                  }
                  --v5;
                  v4 += 5;
                  v6 += 5;
                  NumberOfEventsRead = v5;
                  if ( !v5 )
                    return 0;
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}*/
// 4285A0: using guessed type unsigned int __cdecl _getextendedkeycode(unsigned int);
// 428720: using guessed type int __initconin(void);
// 431490: using guessed type int dword_431490;

//----- (00428770) --------------------------------------------------------
/*int __cdecl sub_428770(int a1)
{
  return free(*(void **)(a1 - 36));
}*/

//----- (0042877B) --------------------------------------------------------
/*int __cdecl SEH_404B10(struct EHExceptionRecord *a1, struct EHRegistrationNode *a2, int a3, int a4)
{
  return __CxxFrameHandler(a1, a2, a3, a4);
}*/

//----- (00428790) --------------------------------------------------------
/*int __cdecl sub_428790(int a1)
{
  return free(*(void **)(a1 + 4));
}*/

//----- (0042879B) --------------------------------------------------------
/*int __cdecl sub_42879B(int a1)
{
  return free(*(void **)(a1 + 4));
}*/

//----- (004287A6) --------------------------------------------------------
/*int __cdecl SEH_40E620(struct EHExceptionRecord *a1, struct EHRegistrationNode *a2, int a3, int a4)
{
  return __CxxFrameHandler(a1, a2, a3, a4);
}*/

//----- (004287B0) --------------------------------------------------------
/*int __cdecl sub_4287B0(int a1)
{
  return free(*(void **)(a1 - 48));
}*/

//----- (004287E0) --------------------------------------------------------
/*int __cdecl sub_4287E0(int a1)
{
  return free(*(void **)(a1 - 1068));
}*/

//----- (004287EE) --------------------------------------------------------
/*int __cdecl sub_4287EE(int a1)
{
  return free(*(void **)(a1 - 1068));
}*/

//----- (004287FC) --------------------------------------------------------
/*int __cdecl sub_4287FC(int a1)
{
  return free(*(void **)(a1 - 1068));
}*/

//----- (0042880A) --------------------------------------------------------
/*int __cdecl sub_42880A(int a1)
{
  return free(*(void **)(a1 - 1068));
}*/

//----- (00428818) --------------------------------------------------------
/*int __cdecl sub_428818(int a1)
{
  return free(*(void **)(a1 - 1068));
}*/

//----- (00428826) --------------------------------------------------------
/*int __cdecl sub_428826(int a1)
{
  return free(*(void **)(a1 - 1068));
}*/

//----- (00428834) --------------------------------------------------------
/*int __cdecl sub_428834(int a1)
{
  return free(*(void **)(a1 - 1068));
}*/

//----- (00428842) --------------------------------------------------------
/*int __cdecl sub_428842(int a1)
{
  return free(*(void **)(a1 - 1068));
}*/

//----- (00428850) --------------------------------------------------------
/*int __cdecl sub_428850(int a1)
{
  return free(*(void **)(a1 - 1068));
}*/

//----- (0042885E) --------------------------------------------------------
/*int __cdecl sub_42885E(int a1)
{
  return free(*(void **)(a1 - 1068));
}*/

//----- (0042886C) --------------------------------------------------------
/*int __cdecl sub_42886C(int a1)
{
  return free(*(void **)(a1 - 1068));
}*/

//----- (0042887A) --------------------------------------------------------
/*int __cdecl sub_42887A(int a1)
{
  return free(*(void **)(a1 - 1068));
}*/

//----- (00428888) --------------------------------------------------------
/*int __cdecl sub_428888(int a1)
{
  return free(*(void **)(a1 - 1068));
}*/

//----- (00428896) --------------------------------------------------------
/*int __cdecl sub_428896(int a1)
{
  return free(*(void **)(a1 - 1068));
}*/

//----- (004288BB) --------------------------------------------------------
/*int __cdecl SEH_412D50(struct EHExceptionRecord *a1, struct EHRegistrationNode *a2, int a3, int a4)
{
  return __CxxFrameHandler(a1, a2, a3, a4);
}*/

//----- (004288D0) --------------------------------------------------------
/*int __cdecl sub_4288D0(int a1)
{
  return free(*(void **)(a1 - 90200));
}*/

//----- (004288DE) --------------------------------------------------------
/*int __cdecl sub_4288DE(struct EHExceptionRecord *a1, struct EHRegistrationNode *a2, int a3, int a4)
{
  return __CxxFrameHandler(a1, a2, a3, a4);
}*/

//----- (004288F0) --------------------------------------------------------
/*int __cdecl sub_4288F0(int a1)
{
  return free(*(void **)(a1 - 36));
}*/

// overflow flag of subtraction (x-y)
char __OFSUB__(int x, int y)
{
    int y2 = y;
    unsigned char sx = __SETS__(x);
    return (sx ^ __SETS__(y2)) & (sx ^ __SETS__(x-y2));
}

// sign flag
char __SETS__(int x)
{
    if ( sizeof(int) == 1 )
        return x < 0;
    if ( sizeof(int) == 2 )
        return x < 0;
    if ( sizeof(int) == 4 )
        return x < 0;
    return x < 0;
}

