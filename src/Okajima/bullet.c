#include "linker.h"
#include "bullet.h"
#include "Game/linkvarbuf.h"

extern const char   aBulletC[];

extern SVECTOR svec_8009F6AC[4];

//------------------------------------------------------------------------------

void bullet_80075314(SVECTOR *pVec, short amount)
{
    svec_8009F6AC[0].vx = amount;
    svec_8009F6AC[1].vx = -amount;
    svec_8009F6AC[2].vz = amount;
    svec_8009F6AC[3].vz = -amount;
    DG_PutVector_8001BE48(svec_8009F6AC, pVec, 4);
}

#pragma INCLUDE_ASM("asm/Okajima/bullet_loader2_helper_80075358.s") // 188 bytes
#pragma INCLUDE_ASM("asm/Okajima/bullet_act_helper_80075414.s")     // 208 bytes
#pragma INCLUDE_ASM("asm/Okajima/bullet_act_helper_800754E4.s")     // 300 bytes
#pragma INCLUDE_ASM("asm/Okajima/bullet_loader2_helper_80075610.s") // 332 bytes
#pragma INCLUDE_ASM("asm/Okajima/bullet_loader3_8007575C.s")        // 1656 bytes
#pragma INCLUDE_ASM("asm/Okajima/bullet_act_80075DD4.s")            // 912 bytes
void bullet_act_80075DD4(Actor_Bullet *actor);

void bullet_kill_80076164(int param_1)
{
    DG_PRIM *prim;

    prim = *(DG_PRIM **)(param_1 + 0x8c);
    if (prim)
    {
        DG_DequeuePrim_800182E0(prim);
        DG_FreePrim_8001BC04(prim);
    }
    return;
}

extern int SECTION(".data") aDdd_8009F6EC[]; // TODO: define as SVECTOR*

int bullet_SetTarget_800761A0( Actor_Bullet *actor, int target_flags )
{
    SVECTOR pos;

    GM_SetTarget_8002DC74( &actor->field_44_target, 4, target_flags, (SVECTOR *)aDdd_8009F6EC );

    pos.vx = actor->field_120.vx >> 3; // divide 8 won't match
    pos.vy = actor->field_120.vy >> 3;
    pos.vz = actor->field_120.vz >> 3;

    if ( actor->field_14C & 0x800 )
    {
        GM_Target_8002DCCC( &actor->field_44_target, 0, 2, actor->field_154_hp, 0, &pos );
    }
    else
    {
        GM_Target_8002DCCC( &actor->field_44_target, 0, 1, actor->field_154_hp, 0, &pos );
    }

    return 0;
}

#pragma INCLUDE_ASM("asm/Okajima/bullet_loader2_80076274.s") // 428 bytes
int                              bullet_loader2_80076274(Actor_Bullet *actor, MATRIX *param_2, int param_3, int param_4, int param_5);
//#pragma INCLUDE_ASM("asm/Okajima/NewBulletEnemy_80076420.s") // 356 bytes

Actor_Bullet *NewBulletEnemy_80076420(MATRIX *arg0, int arg1, int arg2, int arg3, int arg4)
{
	Actor_Bullet  *actor;
	SVECTOR       vec;

	actor = (Actor_Bullet *)GV_NewActor_800150E4( 5, sizeof(Actor_Bullet) );
	if ( actor != NULL )
	{
		GV_SetNamedActor_8001514C( (GV_ACT *)actor,
								   (TActorFunction)&bullet_act_80075DD4,
								   (TActorFunction)&bullet_kill_80076164,
								   (char *)aBulletC );
		vec.vx = arg0->m[0][0];
		vec.vy = arg0->m[1][0];
		vec.vz = arg0->m[2][0];
		actor->field_160 = GV_VecLen3_80016D80( &vec );
		actor->field_150 = 10;
		actor->field_154_hp = 64;

		if ( arg3 == 2 )
		{
			actor->field_158 = 100000;
			actor->field_15C = 5000;
		}
		else if ( arg3 == 1 )
		{
			actor->field_158 = 10000;
			actor->field_15C = 5000;
		}
		else
		{
			actor->field_158 = 10000;
			actor->field_15C = 750;
		}

		actor->field_168 = arg4;

		if ( bullet_loader2_80076274( actor, arg0, arg2, arg3, arg1 ) < 0 )
		{
			GV_DestroyActor_800151C8( (GV_ACT *)actor );
			return NULL;
		}

		if ( bullet_SetTarget_800761A0( actor, arg1 ) < 0 )
		{
			GV_DestroyActor_800151C8( (GV_ACT *)actor );
		}

		actor->field_14C = 0x100;
		actor->field_144_noise_len = arg3;
		actor->field_134 = arg2;
		actor->field_148 = arg1;
	}
	return actor;
}

Actor_Bullet * bullet_init_80076584(MATRIX *pMtx, int whichSide, int a3, int noiseLen)
{
    SVECTOR vec;
    Actor_Bullet *pActor;

    pActor = (Actor_Bullet *)GV_NewActor_800150E4(5, sizeof(Actor_Bullet));
    if ( pActor )
    {
        GV_SetNamedActor_8001514C(&pActor->field_0_actor,
								  (TActorFunction)&bullet_act_80075DD4,
								  (TActorFunction)&bullet_kill_80076164,
								  aBulletC);
        vec.vx = pMtx->m[0][0];
        vec.vy = pMtx->m[1][0];
        vec.vz = pMtx->m[2][0];
        pActor->field_160 = GV_VecLen3_80016D80(&vec);
        pActor->field_150 = 10;

        if ( whichSide == 1 )
        {

            if ( GM_CurrentWeaponId == WEAPON_PSG1 )
            {
                pActor->field_154_hp = 256;
            }
            else
            {
                pActor->field_154_hp = 64;
            }
        }
        else
        {
            pActor->field_154_hp = 64;
        }

        if ( noiseLen == 2 )
        {
            pActor->field_158 = 100000;
            pActor->field_15C = 5000;
        }
        else if ( noiseLen == 1 )
        {
            pActor->field_158 = 10000;
            pActor->field_15C = 5000;
        }
        else
        {
            pActor->field_158 = 10000;
            pActor->field_15C = 750;
        }

        pActor->field_168 = 1;

        if ( bullet_loader2_80076274(pActor, pMtx, a3, noiseLen, whichSide) < 0 )
        {
            GV_DestroyActor_800151C8(&pActor->field_0_actor);
            return 0;
        }

        if ( bullet_SetTarget_800761A0(pActor, whichSide) < 0 )
        {
            GV_DestroyActor_800151C8(&pActor->field_0_actor);
        }

        pActor->field_14C = 256;
        pActor->field_144_noise_len = noiseLen;
        pActor->field_134 = a3;
        pActor->field_148 = whichSide;
    }

    return pActor;
}

#pragma INCLUDE_ASM("asm/Okajima/NewBulletEx_80076708.s")    // 548 bytes
#pragma INCLUDE_ASM("asm/Okajima/sub_8007692C.s")            // 192 bytes
