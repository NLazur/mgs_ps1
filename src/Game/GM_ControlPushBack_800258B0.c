#include "linker.h"
#include <sys/types.h>
#include <libgte.h>

int SECTION(".sbss") dword_800AB9B0;
int SECTION(".sbss") gControlCount_800AB9B4;

typedef struct Res_Control_unknown
{
    short field_0_scriptData_orHashedName;
    short field_2_name_hash;
    short field_4_trigger_Hash_Name_or_camera_w;
    short field_6_count;
    int field_8_wordPtr;
    int field_C;
    int field_10;
    SVECTOR field_14_vec;
} Res_Control_unknown;

struct map_record;

typedef struct Res_Control
{
    SVECTOR field_0_vec;
    SVECTOR field_8_vec;
    Res_Control_unknown field_10_pStruct_hzd_unknown;
    struct map_record *field_2C_map;
    unsigned short field_30_scriptData;
    short field_32_height;
    short field_34;
    short field_36;
    short field_38;
    short field_3A;
    short field_3C;
    short field_3E;
    short field_40;
    short field_42;
    SVECTOR field_44_vec;
    SVECTOR field_4C_turn_vec;
    char field_54;
    char field_55_flags;
    char field_56;
    char field_57;
    char field_58;
    char field_59;
    short field_5A;
    int field_5C_mesg;
    SVECTOR field_60_vecs_ary[2];
    int field_70;
    int field_74;
    short field_78;
    short field_7A;
} Res_Control;

#define MAX_CONTROLS 96
Res_Control *SECTION(".gControlArray_800B56D0") gControlArray_800B56D0[96];
Res_Control SECTION(".gDefaultControl_800B5650") gDefaultControl_800B5650;

int GM_ControlPushBack_800258B0(Res_Control *pControlToAdd)
{
    // sna_init must always be the first item
    if (pControlToAdd->field_30_scriptData == 0x21CA)
    {
        gControlArray_800B56D0[0] = pControlToAdd;
    }
    else
    {
        if (gControlCount_800AB9B4 > MAX_CONTROLS - 1)
        {
            return -1;
        }
        gControlArray_800B56D0[gControlCount_800AB9B4] = pControlToAdd;
        gControlCount_800AB9B4++;
    }

    return 0;
}

void GM_ControlRemove_80025904(Res_Control *pControl)
{
    int i = gControlCount_800AB9B4;
    int totalCount = gControlCount_800AB9B4;

    Res_Control **pControlIter = gControlArray_800B56D0;

    while (i > 0)
    {
        i--;

        if (*pControlIter == pControl)
        {
            goto found;
        }
        pControlIter++;
    }

    return;

found:

    if (pControlIter != gControlArray_800B56D0)
    {
        *pControlIter = gControlArray_800B56D0[--totalCount];
        gControlCount_800AB9B4 = totalCount;
    }
    else
    {
        gControlArray_800B56D0[0] = &gDefaultControl_800B5650;
    }
}

void GM_ControlSetDefault_8002597C(void)
{
    gControlArray_800B56D0[0] = &gDefaultControl_800B5650;
    gControlCount_800AB9B4 = 1;
}

extern const char aInitcontrolNoM[];

void GM_control_loader_helper_80029AB4(void *param_1, int param_2);
void GV_ZeroMemory_8001619c(void *, int);
extern void mg_printf_8008BBA0(const char *, ...);
struct map_record *Map_FromId_800314C0(int);

int Res_Control_init_loader_44EB9E(Res_Control *pControl, int scriptData, int scriptBinds)
{
    struct map_record *pMapRec;
    const int mapId = scriptBinds ? scriptBinds : dword_800AB9B0;
    dword_800AB9B0 = mapId;

    GV_ZeroMemory_8001619c(pControl, sizeof(Res_Control));

    pMapRec = Map_FromId_800314C0(mapId);
    pControl->field_2C_map = pMapRec;
    if (!pMapRec)
    {
        mg_printf_8008BBA0(aInitcontrolNoM, mapId);
        return -1;
    }

    pControl->field_30_scriptData = scriptData;
    if (scriptData)
    {
        GM_control_loader_helper_80029AB4(&pControl->field_10_pStruct_hzd_unknown, scriptData);
        if (GM_ControlPushBack_800258B0(pControl) < 0)
        {
            return -1;
        }
    }

    pControl->field_32_height = 850;
    pControl->field_34 = -32767;
    pControl->field_38 = 450;
    pControl->field_36 = 450;
    pControl->field_59 = 2;
    pControl->field_55_flags = 2;
    pControl->field_78 = -32000;
    pControl->field_7A = 32000;

    return 0;
}
