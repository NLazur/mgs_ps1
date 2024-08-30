#ifndef _BAKUDAN_H_
#define _BAKUDAN_H_

#include <sys/types.h>
#include <libgte.h>
#include <libgpu.h>
#include "Game/game.h"
#include "libgv/libgv.h"
#include "Game/target.h"
#include "Game/control.h"

// c4 (armed)

typedef struct BakudanWork
{
    GV_ACT         actor;
    CONTROL        control;
    OBJECT_NO_ROTS field_9C_kmd;
    MATRIX         field_C0_light_mtx[2];
    MATRIX        *field_100_pMtx;         // (assigned if the c4 is placed on a moving target)
    SVECTOR       *rotation;               // rotation vector (assigned if the c4 is placed on a moving target)
    int            detonator_btn_pressed;  // 1 if the detonator button is pressed, 0 otherwise
    int            detonator_frames_count; // number of actor actions to wait before detonate
    GV_PAD        *active_pad;             // pointer to the currently active gamepad
    int            c4_index;               // the index in the c4_actors array
    int            map_index;              // the current map where the c4 is placed
} BakudanWork;

GV_ACT *NewBakudan_8006A6CC(MATRIX *pMtx, SVECTOR *pVec, int a3, int not_used, void *data);

#endif // _BAKUDAN_H_
