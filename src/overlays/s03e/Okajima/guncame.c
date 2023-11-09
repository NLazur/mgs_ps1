#include "common.h"
#include "libgv/libgv.h"
#include "Bullet/blast.h"
#include "Game/control.h"
#include "Game/game.h"
#include "Game/linkvarbuf.h"
#include "Game/object.h"

// We came, we saw, GunCamE
typedef struct GunCamEWork
{
    GV_ACT   actor;
    CONTROL  control;
    OBJECT   field_9C;
    MATRIX   field_180[2];
    MATRIX   world;
    TARGET  *target;
    int      field_1E4;
    int      field_1E8;
    int      field_1EC;
    int      field_1F0;
    OBJECT   field_1F4;
    MATRIX   field_2D8[2];
    SVECTOR  field_318;
    int      field_320;
    int      field_324;
    DG_PRIM *field_328;
    DG_TEX  *field_32C;
    SVECTOR  field_330;
    SVECTOR  field_338;
    int      field_340;
    int      field_344;
    int      field_348;
    int      field_34C;
    int      field_350;
    int      field_354;
    int      field_358;
    int      field_35C;
    int      field_360;
    int      field_364;
    int      field_368;
    int      field_36C;
    int      field_370;
    int      field_374;
    int      map;
    SVECTOR  field_37C[2];
    SVECTOR  field_38C[2];
    int      field_39C;
    int      field_3A0;
    int      field_3A4;
    int      field_3A8;
    SVECTOR  field_3AC;
    SVECTOR  field_3B4;
    int      field_3BC;
    int      field_3C0;
    int      field_3C4;
    int      field_3C8;
    int      field_3CC;
    int      field_3D0;
    int      proc;
    int      field_3D8;
    int      name;
    int      field_3E0;
    int      field_3E4;
    int      field_3E8;
    int      field_3EC;
    int      field_3F0;
    SVECTOR  field_3F4;
    SVECTOR  field_3FC;
    int      field_404;
    int      field_408;
    int      field_40C;
    int      field_410;
    int      field_414;
    int      field_418;
} GunCamEWork;

extern int     dword_8009F480;
extern int     s03e_dword_800C32B8;
extern SVECTOR DG_ZeroVector_800AB39C;
extern char    s03e_aGcaarm_800CC110[];
extern char    s03e_aGcagun_800CC108[];
extern int     s03e_dword_800C32B4;
extern SVECTOR guncame_svec;
extern int     s03e_dword_800CC6BC;
extern int     s03e_dword_800C32B4;
extern char    s03e_dword_800CC118[];
extern char    s03e_aCameral_800CC0FC[];
extern RECT    guncame_rect;
extern SVECTOR GM_PlayerPosition_800ABA10;
extern int     dword_8009F46C[];
extern int     dword_8009F480;
extern SVECTOR svector_8009F478;
extern SVECTOR s03e_svec_800CC0F4;
extern int     GV_Time_800AB330;
extern int     GM_GameStatus_800AB3CC;
extern int     GM_CurrentMap_800AB9B0;
extern int     GM_PlayerMap_800ABA0C;
extern int     GM_PadVibration_800ABA3C;
extern int     GM_PadVibration2_800ABA54;
extern int     s03e_dword_800C32BC;
extern SVECTOR s03e_svec_800CC084;

extern const char s03e_aKill_800CC08C[]; // = "kill";
extern const char s03e_dword_800CC094[]; // = "\xb2\xbb\xc6\xfe\xa4\xec\xa4\xeb"         // 音入れる
extern const char s03e_dword_800CC0A0[]; // = "\xb2\xbb\xc0\xda\xa4\xeb"                 // 音切る
extern const char s03e_dword_800CC0A8[]; // = "\xbb\xeb\xce\xcf\xcc\xe1\xa4\xb9"         // 視力戻す
extern const char s03e_dword_800CC0B4[]; // = "\xbb\xeb\xce\xcf\xcc\xb5\xa4\xaf\xa4\xb9" // 視力無くす
extern const char s03e_dword_800CC0C0[]; // = "\xbd\xe8\xcd\xfd\xba\xc6\xb3\xab";        // 処理再開
extern const char s03e_dword_800CC0CC[]; // = "\xbd\xe8\xcd\xfd\xc4\xe4\xbb\xdf"         // 処理停止

void AN_Unknown_800C9CBC(MATRIX *world, int index);
void AN_Unknown_800D6EB0(SVECTOR *pos);

GV_ACT * NewSpark2_800CA714(MATRIX *world);

// Identical to d03a_red_alrt_800C437C
int s03e_guncame_800C6F60(unsigned short name, int nhashes, unsigned short *hashes)
{
    GV_MSG *msg;
    int     nmsgs;
    int     found;
    int     hash;
    int     i;

    nmsgs = GV_ReceiveMessage_80016620(name, &msg);
    found = -1;

    for (; nmsgs > 0; nmsgs--, msg++)
    {
        hash = msg->message[0];

        for (i = 0; i < nhashes; i++)
        {
            if (hash == hashes[i])
            {
                found = i;
            }
        }
    }

    return found;
}

void s03e_guncame_800C6FF8(GunCamEWork *work)
{
    SVECTOR svec;

    svec.vx = 0;
    svec.vy = 200;
    svec.vz = 900;

    DG_SetPos2_8001BC8C(&work->control.field_0_mov, &work->control.field_8_rot);
    DG_PutVector_8001BE48(&svec, &svec, 1);
    work->field_338 = svec;
}

void s03e_guncame_800C7068(GunCamEWork *work)
{
    work->field_3A0 = 1;
    work->field_3AC = GM_PlayerPosition_800ABA10;
    if (dword_8009F46C[0] == 1)
    {
        work->field_3A4 = dword_8009F46C[0];
        work->field_3B4 = svector_8009F478;
    }
    else
    {
        work->field_3B4 = GM_PlayerPosition_800ABA10;
        work->field_3A4 = 0;
        dword_8009F480 = 0;
        work->field_3C4 = 0;
    }
}

void s03e_guncame_800C7118(DG_PRIM *prim, DG_TEX *tex, int r, int g, int b)
{
    POLY_FT4 *poly;

    poly = &prim->field_40_pBuffers[0]->poly_ft4;
    setRGB0(poly, r, g, b);

    poly = &prim->field_40_pBuffers[1]->poly_ft4;
    setRGB0(poly, r, g, b);
}

void s03e_guncame_800C7144(GunCamEWork *work, int r, int g, int b)
{
    work->field_3F4.vx = r;
    work->field_3F4.vy = g;
    work->field_3F4.vz = b;
}

int s03e_guncame_800C7154(int opt, SVECTOR *svec)
{
    int   count;
    char *result;

    count = 0;

    while ((result = GCL_Get_Param_Result_80020AA4()) != NULL)
    {
        GCL_StrToSV_80020A14(result, svec);

        svec++;
        count++;
    }

    return count;
}

void s03e_guncame_800C71A8(SVECTOR* arg0, SVECTOR* arg1, SVECTOR* arg2) {

    SVECTOR sp10;
    int temp_s0;

    GV_SubVec3_80016D40(arg1, arg0, &sp10);

    arg2->vy = (ratan2(sp10.vx, (int) sp10.vz) & 0xFFF);

    temp_s0 = sp10.vy;
    sp10.vy = 0;

    arg2->vx = (short int) ((ratan2(GV_VecLen3_80016D80(&sp10), (int) temp_s0) & 0xFFF) - 0x400);
}

#pragma INCLUDE_ASM("asm/overlays/s03e/s03e_guncame_800C7224.s")
int s03e_guncame_800C7224(GunCamEWork *work);

#pragma INCLUDE_ASM("asm/overlays/s03e/s03e_guncame_800C73D0.s")
void s03e_guncame_800C73D0(GunCamEWork *work);

void s03e_guncame_800C75FC(SVECTOR *svec1, SVECTOR *svec2, GunCamEWork *work)
{
    int dir;

    dir = GV_DiffDirS_8001704C(svec1->vy, svec2->vy);
    if (work->field_36C < dir)
    {
        svec2->vy = (svec1->vy + work->field_36C) & 0xFFF;
    }
    else if (dir < -work->field_36C)
    {
        svec2->vy = (svec1->vy - work->field_36C) & 0xFFF;
    }

    dir = GV_DiffDirS_8001704C(svec1->vx, svec2->vx);
    if (work->field_36C < dir)
    {
        svec2->vx = (svec1->vx + work->field_36C) & 0xFFF;
    }
    else if (dir < -work->field_36C)
    {
        svec2->vx = (svec1->vx - work->field_36C) & 0xFFF;
    }
}

void s03e_guncame_800C76E8(GunCamEWork* work) {

    SVECTOR* temp_s1;
    temp_s1 = &work->control.field_4C_turn;

    s03e_guncame_800C71A8(&work->control.field_0_mov, &work->field_3AC + (work->field_39C), temp_s1);
    s03e_guncame_800C75FC(&work->field_330, temp_s1, work);
}

int s03e_guncame_800C7740(GunCamEWork *work)
{
    SVECTOR *vec;

    if (work->field_34C > 60)
    {
        if (work->field_404 != 0)
        {
            GM_SeSet_80032858(&work->control.field_0_mov, 94);
        }

        vec = &work->control.field_4C_turn;
        vec->vy = (vec->vy + 8) & 0xFFF;

        if (work->field_36C < GV_DiffDirAbs_8001706C(work->field_330.vy, vec->vy))
        {
            return 1;
        }
    }
    work->field_34C++;
    return 0;
}

int s03e_guncame_800C77D4(GunCamEWork *work)
{
    SVECTOR *vec;

    if (work->field_34C > 60)
    {
        if (work->field_404 != 0)
        {
            GM_SeSet_80032858(&work->control.field_0_mov, 94);
        }

        vec = &work->control.field_4C_turn;
        vec->vy = (vec->vy - 8) & 0xFFF;

        if (work->field_36C < GV_DiffDirAbs_8001706C(work->field_330.vy, vec->vy))
        {
            return 1;
        }
    }
    work->field_34C++;
    return 0;
}

int s03e_guncame_800C7868(GunCamEWork *work)
{
    SVECTOR *svec1, *svec2;
    int      dir;

    svec1 = &work->field_330;
    svec2 = &work->control.field_4C_turn;

    dir = GV_DiffDirS_8001704C(svec1->vy, svec2->vy);
    if (dir < -0xA)
    {
        svec2->vy += 8;
    }
    else if (dir < 0xA)
    {
        svec2->vy = svec1->vy;
    }
    else
    {
        svec2->vy -= 8;
    }

    dir = GV_DiffDirS_8001704C(svec1->vx, svec2->vx);
    if (dir < -0xA)
    {
        svec2->vx += 8;
    }
    else if (dir < 0xA)
    {
        svec2->vx = svec1->vx;
    }
    else
    {
        svec2->vx -= 8;
    }

    if (svec2->vx != svec1->vx || svec2->vy != svec1->vy || work->field_34C < 0x91)
    {
        work->field_34C++;
        return 0;
    }

    return 1;
}

void s03e_guncame_800C7994(GunCamEWork *work)
{
    switch (work->field_344)
    {
    case 2:
        if (s03e_guncame_800C7740(work))
        {
            work->field_344 = 3;
            work->field_34C = GV_RandU_80017090(32);
            work->control.field_4C_turn.vy = work->field_330.vy + work->field_36C;
        }
        break;

    case 3:
        if (s03e_guncame_800C77D4(work))
        {
            work->field_344 = 2;
            work->field_34C = GV_RandU_80017090(32);
            work->control.field_4C_turn.vy = work->field_330.vy - work->field_36C;
        }
        break;

    case 4:
    case 5:
        break;
    }

    if ((((GV_Time_800AB330 + work->field_414) & 3) == 0) && s03e_guncame_800C7224(work))
    {
        AN_Unknown_800C9CBC(&work->field_9C.objs->objs[0].world, 0);

        if (s03e_dword_800CC6BC <= 0)
        {
            s03e_dword_800CC6BC = 90;

            if (work->field_404 != 0)
            {
                GM_SeSet2_80032968(0, 63, 83);
            }
        }

        work->field_340 = 1;
        work->field_344 = 5;
        work->field_34C = 0;

        s03e_guncame_800C7144(work, 0xFF, 0, 0);

        work->field_3EC = 10;
    }
}

void s03e_guncame_800C7AD8(GunCamEWork *work)
{
    switch (work->field_344)
    {
    case 5:
        s03e_guncame_800C76E8(work);
        work->field_348++;
        if (!(work->field_348 & 3))
        {
            if (work->field_354 < work->field_370)
            {
                work->field_354++;
                s03e_guncame_800C73D0(work);
                if (work->field_404 != 0)
                {
                    GM_Sound_800329C4(&work->control.field_0_mov, 0x2E, 1);
                }
                work->field_350 = 1;
            }
            else
            {
                work->field_358++;
                if (work->field_358 >= work->field_374)
                {
                    work->field_354 = 0;
                    work->field_358 = 0;
                }
            }
        }
        else
        {
            work->field_350 = 0;
        }
        if (s03e_guncame_800C7224(work) == 0)
        {
            work->field_344 = 1;
            work->field_34C = 0;
            break;
        }
        break;
    case 1:
        work->field_350 = 0;
        work->field_34C++;
        if (work->field_34C >= 0x5B)
        {
            work->field_340 = 2;
            work->field_344 = 6;
            work->field_34C = 0;
            break;
        }
        if (s03e_guncame_800C7224(work) != 0)
        {
            work->field_344 = 5;
        }
        break;
    }
}

void s03e_guncame_800C7C0C(GunCamEWork *work)
{
    switch (work->field_344)
    {
    case 6:
        work->field_344 = 7;
        break;
    case 7:
        if (s03e_guncame_800C7868(work) != 0)
        {
            work->field_340 = 0;
            if (work->field_360 == 1)
            {
                if (GV_RandU_80017090(2U) == 0)
                {
                    work->field_344 = 3;
                }
                else
                {
                    work->field_344 = 2;
                }
            }
            else
            {
                work->field_344 = 4;
            }
            work->field_34C = 0;
            s03e_guncame_800C7144(work, 0, 0xFF, 0);
        }
        break;
    }

    if (s03e_guncame_800C7224(work) != 0)
    {
        work->field_340 = 1;
        work->field_344 = 5;
        work->field_34C = 0;
        s03e_guncame_800C7144(work, 0xFF, 0, 0);
    }
}

void s03e_guncame_800C7CE0(GunCamEWork *work)
{
    int time;
    int tx, ty;

    switch (work->field_344)
    {
    case 0:
        work->field_344 = 7;
        /* fallthrough */

    case 7:
        time = work->field_3D0 + GV_Time_800AB330;

        if ((GV_RandU_80017090(16) == 0) && (work->field_404 != 0))
        {
            GM_SeSet_80032858(&work->control.field_0_mov, 109);
        }

        if (GM_GameStatus_800AB3CC & GAME_FLAG_BIT_01) // chaff active
        {
            ty = rsin(time * 64) - rsin(time * 31) / 2 - rsin(time * 231) / 2;
            work->control.field_4C_turn.vy += ty / 16;

            tx = rsin(time * 23) - rsin(time * 45) / 2 - rsin(time * 245) / 2;
            work->control.field_4C_turn.vx += tx / 16;

            work->control.field_4C_turn.vx &= 0xFFF;
            work->control.field_4C_turn.vy &= 0xFFF;

            s03e_guncame_800C75FC(&work->field_330, &work->control.field_4C_turn, work);

            // Each macro expansion calls rsin three times
            work->field_3FC.vx = ABS(rsin(time * 95) / 16);
            work->field_3FC.vy = ABS(rsin(time * 154) / 16);
            work->field_3FC.vz = ABS(rsin(time * 43) / 16);

            s03e_guncame_800C7144(work, work->field_3FC.vx, work->field_3FC.vy, work->field_3FC.vz);
        }
        else
        {
            s03e_guncame_800C7144(work, 0, 255, 0);

            work->field_3D0 = -1;
            work->field_340 = 2;
            work->field_344 = 6;
            work->field_34C = 0;
        }
        break;
    }
}

void s03e_guncame_800C8024(GunCamEWork *work)
{
    work->control.field_3C.vx = work->control.field_8_rot.vy;
}

void s03e_guncame_800C8030(GunCamEWork *work)
{
    switch (work->field_340)
    {
    case 0:
        GM_ConfigControlInterp_80026244(&work->control, 4);
        s03e_guncame_800C7994(work);
        break;
    case 1:
        GM_ConfigControlInterp_80026244(&work->control, 0);
        s03e_guncame_800C7AD8(work);
        break;
    case 2:
        GM_ConfigControlInterp_80026244(&work->control, 4);
        s03e_guncame_800C7C0C(work);
        break;
    case 3:
        GM_ConfigControlInterp_80026244(&work->control, 4);
        s03e_guncame_800C7CE0(work);
        break;
    }
}

void s03e_guncame_800C80F4(GunCamEWork *work)
{
    MATRIX         world;
    SVECTOR        rot;
    SVECTOR        disp_world;
    SVECTOR        mov;
    SVECTOR        disp_local;
    unsigned short hashes[7];
    int            found;
    CONTROL       *control;
    int            flags;
    TARGET        *target;
    int            i;

    disp_local = s03e_svec_800CC084;

    if (s03e_dword_800CC6BC > 0)
    {
        s03e_dword_800CC6BC--;
    }

    hashes[0] = GV_StrCode_80016CCC(s03e_aKill_800CC08C);
    hashes[1] = GV_StrCode_80016CCC(s03e_dword_800CC094);
    hashes[2] = GV_StrCode_80016CCC(s03e_dword_800CC0A0);
    hashes[3] = GV_StrCode_80016CCC(s03e_dword_800CC0A8);
    hashes[4] = GV_StrCode_80016CCC(s03e_dword_800CC0B4);
    hashes[5] = GV_StrCode_80016CCC(s03e_dword_800CC0C0);
    hashes[6] = GV_StrCode_80016CCC(s03e_dword_800CC0CC);

    found = s03e_guncame_800C6F60(work->name, 7, hashes);
    switch(found)
    {
    case 0:
        GV_DestroyActor_800151C8(&work->actor);
        break;

    case 1:
        work->field_404 = 1;
        break;

    case 2:
        work->field_404 = 0;
        break;

    case 3:
        work->field_408 = 1;
        break;

    case 4:
        work->field_408 = 0;
        break;

    case 5:
        work->field_410 = 0;
        break;

    case 6:
        work->field_410 = 1;
        break;
    }

    control = &work->control;

    if (((work->map & GM_PlayerMap_800ABA0C) == 0) || (work->field_410 != 0))
    {
        DG_InvisibleObjs(work->field_9C.objs);
        DG_InvisibleObjs(work->field_1F4.objs);
        DG_InvisiblePrim(work->field_328);

        if (work->field_40C == 1)
        {
            return;
        }

        work->field_40C = 1;
    }
    else
    {
        work->field_40C = 0;

        DG_VisibleObjs(work->field_9C.objs);
        DG_VisibleObjs(work->field_1F4.objs);
        DG_VisiblePrim(work->field_328);
    }

    GM_CurrentMap_800AB9B0 = work->map;

    work->field_3FC.vx = (work->field_3FC.vx * 15 + work->field_3F4.vx) / 16;
    work->field_3FC.vy = (work->field_3FC.vy * 15 + work->field_3F4.vy) / 16;
    work->field_3FC.vz = (work->field_3FC.vz * 15 + work->field_3F4.vz) / 16;

    s03e_guncame_800C7118(work->field_328, work->field_32C, work->field_3FC.vx, work->field_3FC.vy, work->field_3FC.vz);
    s03e_guncame_800C7068(work);

    if (work->field_3EC > 0)
    {
        GM_PadVibration_800ABA3C = 1;
        GM_PadVibration2_800ABA54 = 255;
        work->field_3EC--;
    }
    else
    {
        work->field_3EC = 0;
    }

    if ((work->field_3A4 == 1) || (work->field_3A8 == 1))
    {
        work->field_3CC = 60;
    }

    if (work->field_3CC >= 1)
    {
        work->field_3CC--;

        if (work->field_3E8 != 0)
        {
            flags = work->target->class & ~(TARGET_SEEK | TARGET_POWER | TARGET_AVAIL);
            work->target->class = flags | TARGET_AVAIL;
        }
    }
    else
    {
        work->target->class |= TARGET_SEEK | TARGET_POWER | TARGET_AVAIL;
    }

    if (work->field_40C == 0)
    {
        if (((GM_GameStatus_800AB3CC & GAME_FLAG_BIT_01) != 0) && (work->field_3D0 == -1))
        {
            work->field_3D0 = GV_RandU_80017090(4096);
            work->field_340 = 3;
            work->field_344 = 0;
            work->field_34C = 0;
        }
    }
    else
    {
        s03e_guncame_800C7144(work, 0, 255, 0);

        work->field_3D0 = -1;
        work->field_340 = 2;
        work->field_344 = 6;
        work->field_34C = 0;
    }

    if (work->field_35C == 0)
    {
        if (work->field_350 == 1)
        {
            rot = control->field_8_rot;
            rot.vx -= 1024;

            RotMatrixYXZ_gte(&rot, &world);
            ApplyMatrixSV(&world, &disp_local, &disp_world);

            mov = control->field_0_mov;

            control->field_0_mov.vx -= disp_world.vx;
            control->field_0_mov.vy -= disp_world.vy;
            control->field_0_mov.vz -= disp_world.vz;

            GM_ActControl_80025A7C(control);

            control->field_0_mov = mov;
        }
        else
        {
            GM_ActControl_80025A7C(control);
        }

        if (GM_CurrentItemId == ITEM_THERM_G)
        {
            work->field_3D8 = 1;

            DG_AmbientObjs(work->field_9C.objs);
            DG_AmbientObjs(work->field_1F4.objs);

            DG_GetLightMatrix2_8001A5D8(&control->field_0_mov, work->field_180);
            DG_GetLightMatrix2_8001A5D8(&control->field_0_mov, work->field_2D8);
        }
        else if (work->field_3D8 == 1)
        {
            work->field_3D8 = 0;

            DG_UnAmbientObjs(work->field_9C.objs);
            DG_UnAmbientObjs(work->field_1F4.objs);

            DG_GetLightMatrix_8001A3C4(&control->field_0_mov, work->field_180);
            DG_GetLightMatrix_8001A3C4(&control->field_0_mov, work->field_2D8);
        }

        GM_ActObject2_80034B88(&work->field_9C);

        DG_PutPrim_8001BE00(&work->field_328->world);
        DG_SetPos_8001BC44(&work->world);

        GM_ActObject2_80034B88(&work->field_1F4);

        target = work->target;

        GM_Target_SetVector_8002D500(target, &control->field_0_mov);

        if (target->field_6_flags & TARGET_POWER)
        {
            if (target->field_3E != 2)
            {
                target->field_28 = 0;
                target->field_6_flags = 0;
            }
            else if (s03e_dword_800C32B8 == 0)
            {
                s03e_dword_800C32B8 = 1;
                s03e_dword_800C32BC++;

                if (work->field_404 != 0)
                {
                    GM_SeSet_80032858(&control->field_0_mov, 59);
                }

                work->field_35C = 1;

                AN_Blast_Minimini_8006E32C(&control->field_0_mov);

                for (i = 0; i < 2; i++)
                {
                    rot.vz = 0;

                    disp_world.vx = GV_RandS_800170BC(128);
                    disp_world.vy = GV_RandU_80017090(256) + 32;
                    disp_world.vz = 0;

                    rot.vx = GV_RandU_80017090(256) + 64;
                    rot.vy = control->field_8_rot.vy + GV_RandS_800170BC(512);

                    RotMatrixYXZ_gte(&rot, &world);
                    ApplyMatrixSV(&world, &disp_world, &work->field_37C[i]);

                    work->field_38C[i] = control->field_0_mov;
                }
            }
        }
    }
    else
    {
        if (++work->field_35C == 19)
        {
            rot.vx = GV_RandU_80017090(1024);
            rot.vy = GV_RandU_80017090(2048);
            rot.vz = 0;

            DG_SetPos2_8001BC8C(&control->field_0_mov, &rot);
            ReadRotMatrix(&world);

            NewSpark2_800CA714(&world);
        }

        DG_InvisibleObjs(work->field_9C.objs);
        DG_InvisibleObjs(work->field_1F4.objs);

        s03e_guncame_800C7144(work, 0, 0, 0);

        if ((work->field_35C >= 20) || ((s03e_dword_800C32BC & 0x1) == 0))
        {
            if (work->proc != -1)
            {
                GCL_ExecProc_8001FF2C(work->proc, 0);
            }

            GV_DestroyActor_800151C8(&work->actor);
        }
        else
        {
            for (i = 0; i < 2; i++)
            {
                work->field_37C[i].vy -= 15;

                work->field_38C[i].vx += work->field_37C[i].vx;
                work->field_38C[i].vy += work->field_37C[i].vy;
                work->field_38C[i].vz += work->field_37C[i].vz;

                AN_Unknown_800D6EB0(&work->field_38C[i]);
            }
        }
    }

    s03e_guncame_800C8024(work);
    s03e_guncame_800C8030(work);
}

void s03e_guncame_800C8940(GunCamEWork *work)
{
    CONTROL *control;
    SVECTOR *vec;

    control = &work->control;
    control->field_3A_radar_atr |= 0x2000;

    vec = &work->control.field_3C;
    vec->vx = 0;
    vec->vy = work->field_364;
    vec->vz = work->field_368 * 2;
    vec->pad = 0;
}

int s03e_guncame_800C8978(GunCamEWork *work, int name, int map)
{
    SVECTOR disp_local;
    SVECTOR pos;
    SVECTOR dir;
    SVECTOR disp_world;
    MATRIX  rot;
    int     opt;
    char   *param;

    disp_world = s03e_svec_800CC0F4;

    opt = GCL_GetOption_80020968('m');
    if (opt != NULL)
    {
        work->field_360 = GCL_StrToInt_800209E8((char *)opt);
        if (work->field_360 != 1)
        {
            work->field_360 = 0;
        }
    }
    else
    {
        work->field_360 = 0;
    }

    opt = GCL_GetOption_80020968('l');
    if (opt != NULL)
    {
        work->field_364 = GCL_StrToInt_800209E8((char *)opt);
    }
    else
    {
        work->field_364 = 0xFFFF;
    }

    opt = GCL_GetOption_80020968('w');
    if (opt != NULL)
    {
        work->field_368 = GCL_StrToInt_800209E8((char *)opt);
    }
    else
    {
        work->field_368 = 512;
    }

    opt = GCL_GetOption_80020968('p');
    if (opt != NULL)
    {
        s03e_guncame_800C7154(opt, &pos);
    }
    else
    {
        pos = DG_ZeroVector_800AB39C;
    }

    opt = GCL_GetOption_80020968('d');
    if (opt != NULL)
    {
        s03e_guncame_800C7154(opt, &dir);
    }
    else
    {
        dir = DG_ZeroVector_800AB39C;
    }

    work->control.field_0_mov = pos;
    work->control.field_4C_turn = dir;

    RotMatrixYXZ_gte(&dir, &rot);
    ApplyMatrixSV(&rot, &disp_world, &disp_local);

    work->control.field_0_mov.vx -= disp_local.vx;
    work->control.field_0_mov.vy -= disp_local.vy;
    work->control.field_0_mov.vz -= disp_local.vz;

    DG_SetPos2_8001BC8C(&pos, &dir);
    ReadRotMatrix(&work->world);

    opt = GCL_GetOption_80020968('r');
    if (opt != NULL)
    {
        s03e_guncame_800C7154(opt, &pos);
        work->control.field_4C_turn.vx += pos.vx;
        work->control.field_4C_turn.vy += pos.vy;
    }

    work->control.field_8_rot = work->control.field_4C_turn;
    work->field_330 = work->control.field_4C_turn;

    opt = GCL_GetOption_80020968('x');
    if (opt != NULL)
    {
        work->field_36C = GCL_StrToInt_800209E8((char *)opt);
    }
    else
    {
        work->field_36C = 512;
    }

    opt = GCL_GetOption_80020968('g');
    if (opt != NULL)
    {
        param = GCL_Get_Param_Result_80020AA4();
        if (param != NULL)
        {
            work->field_370 = GCL_StrToInt_800209E8(param);
        }

        param = GCL_Get_Param_Result_80020AA4();
        if (param != NULL)
        {
            work->field_374 = GCL_StrToInt_800209E8(param);
        }
    }
    else
    {
        work->field_370 = 1;
        work->field_374 = 30;
    }

    opt = GCL_GetOption_80020968('v');
    if (opt != NULL)
    {
        work->field_418 = 1;
    }
    else
    {
        work->field_418 = 0;
    }

    work->field_340 = 0;

    if (work->field_360 == 1)
    {
        if ((work->field_418 == 0) && (GV_RandU_80017090(2) == 0))
        {
            work->field_344 = 3;
        }
        else
        {
            work->field_344 = 2;
        }
    }
    else
    {
        work->field_344 = 4;
    }

    work->field_3F4.vx = 0;
    work->field_3F4.vy = 255;
    work->field_3F4.vz = 0;

    opt = GCL_GetOption_80020968('n');
    if (opt != NULL)
    {
        work->field_3F0 = 0;
        GM_ConfigControlAttribute_8002623C(&work->control, 0x3);
    }
    else
    {
        work->field_3F0 = 1;
        GM_ConfigControlAttribute_8002623C(&work->control, 0x47);
        s03e_guncame_800C8940(work);
    }

    opt = GCL_GetOption_80020968('o');
    if (opt != NULL)
    {
        work->field_3E8 = 1;
    }
    else
    {
        work->field_3E8 = 0;
    }

    work->field_348 = 0;
    work->field_34C = 0;
    work->field_354 = 0;
    work->field_358 = 0;
    work->field_35C = 0;
    work->field_3C4 = 0;
    work->field_3C8 = 0;
    work->field_3CC = 0;
    work->field_3D0 = -1;
    work->field_3D8 = 0;
    work->field_3EC = 0;

    opt = GCL_GetOption_80020968('e');
    if (opt != NULL)
    {
        work->proc = GCL_StrToInt_800209E8((char *)opt);
    }
    else
    {
        work->proc = -1;
    }

    opt = GCL_GetOption_80020968('a');
    if (opt != NULL)
    {
        work->field_3E0 = GCL_StrToInt_800209E8((char *)opt);
        if (work->field_3E0 < 2)
        {
            work->field_3E0 = 2;
        }
    }
    else
    {
        work->field_3E0 = 2;
    }

    opt = GCL_GetOption_80020968('b');
    if (opt != NULL)
    {
        work->field_3E4 = GCL_StrToInt_800209E8((char *)opt);
        if (work->field_3E4 < 2)
        {
            work->field_3E4 = 2;
        }
    }
    else
    {
        work->field_3E4 = 2;
    }

    return 0;
}

void s03e_guncame_800C8E04(POLY_FT4* poly, DG_TEX* tex, int col) {

    signed char height;
    signed char width;
    unsigned char x_offset;
    unsigned char y_offset;

    setPolyFT4(poly);
    setRGB0(poly, col, col, col);
    poly->code = (poly->code | 0x02);

    x_offset = tex->field_8_offx;
    width = x_offset + tex->field_A_width;

    y_offset = tex->field_9_offy;
    height = y_offset + tex->field_B_height;

    poly->u0 = x_offset;
    poly->v0 = y_offset;
    poly->u1 = width;
    poly->v1 = y_offset;
    poly->u2 = x_offset;
    poly->v2 = height;
    poly->u3 = width;
    poly->v3 = height;

    poly->tpage = tex->field_4_tPage;
    poly->clut = (unsigned short) tex->field_6_clut;
}

int s03e_guncame_800C8E7C(GunCamEWork *work)
{
    DG_PRIM *prim;
    DG_TEX  *tex;

    work->field_318.vx = -90;
    work->field_318.vy = 300;
    work->field_318.vz = 350;
    prim = DG_GetPrim(0x412, 1, 0, &work->field_318, &guncame_rect);
    work->field_328 = prim;
    if (prim != NULL)
    {
        prim->field_2E_k500 = 500;
        tex = DG_GetTexture_8001D830(GV_StrCode_80016CCC(s03e_aCameral_800CC0FC));
        work->field_32C = tex;
        if (tex != 0)
        {
            s03e_guncame_800C8E04(&prim->field_40_pBuffers[0]->poly_ft4, tex, 128);
            s03e_guncame_800C8E04(&prim->field_40_pBuffers[1]->poly_ft4, tex, 100);
            return 0;
        }
    }
    return -1;
}

int s03e_guncame_800C8F64(GunCamEWork *work, int name, int where)
{
    CONTROL *control;
    OBJECT  *obj1, *obj2;

    control = &work->control;
    work->field_404 = 1;
    work->field_408 = 1;
    work->name = name;

    if (GM_InitLoader_8002599C(control, name, where) < 0)
    {
        return -1;
    }

    GM_ConfigControlAttribute_8002623C(control, 7);
    GM_ConfigControlHazard_8002622C(control, -1, -2, -1);
    GM_ConfigControlInterp_80026244(control, 4);
    work->control.field_44_step = DG_ZeroVector_800AB39C;

    obj1 = &work->field_9C;
    do {} while (0);
    GM_InitObject_80034A18(obj1, GV_StrCode_80016CCC(s03e_aGcagun_800CC108), 0x26D, 0);
    GM_ConfigObjectLight_80034C44(obj1, work->field_180);

    obj2 = &work->field_1F4;
    do {} while (0);
    GM_InitObject_80034A18(obj2, GV_StrCode_80016CCC(s03e_aGcaarm_800CC110), 0x26D, 0);
    GM_ConfigObjectLight_80034C44(obj2, work->field_2D8);

    if (s03e_guncame_800C8E7C(work) == -1)
    {
        return -1;
    }

    work->target = GM_AllocTarget_8002D400();
    if (work->target)
    {
        GM_SetTarget_8002DC74(work->target, 0x15, 2, &guncame_svec);
        s03e_guncame_800C8978(work, name, where);
        DG_GetLightMatrix_8001A3C4(&control->field_0_mov, work->field_180);
        DG_GetLightMatrix_8001A3C4(&control->field_0_mov, work->field_2D8);
        s03e_dword_800CC6BC = 0;
        work->field_40C = 0;
        work->field_410 = 0;
        work->field_414 = s03e_dword_800C32B4;
        return 0;
    }

    return -1;
}

void s03e_guncame_800C911C(GunCamEWork *work)
{
    DG_PRIM *prim;

    s03e_dword_800C32B8 = 0;
    dword_8009F480 = 0;
    GM_FreeObject_80034BF8(&work->field_9C);
    GM_FreeObject_80034BF8(&work->field_1F4);
    GM_FreeTarget_8002D4B0(work->target);
    GM_FreeControl_800260CC(&work->control);
    prim = work->field_328;
    if (prim)
    {
        DG_DequeuePrim_800182E0(prim);
        DG_FreePrim_8001BC04(prim);
    }
}

GV_ACT *s03e_guncame_800C9190(int name, int where, int argc, char **argv)
{
    GunCamEWork *work;

    work = (GunCamEWork *)GV_NewActor_800150E4(4, sizeof(GunCamEWork));
    if (work != NULL)
    {
        GV_SetNamedActor_8001514C(&work->actor, (TActorFunction)s03e_guncame_800C80F4,
                                  (TActorFunction)s03e_guncame_800C911C, s03e_dword_800CC118);
        if (s03e_guncame_800C8F64(work, name, where) < 0)
        {
            GV_DestroyActor_800151C8(&work->actor);
            return NULL;
        }
        work->map = where;
        s03e_dword_800C32B4++;
    }
    return &work->actor;
}
