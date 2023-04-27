#include "../portultra/multilibultra.hpp"
#include "recomp.h"

extern "C" void osViSetYScale_recomp(uint8_t* rdram, recomp_context * ctx) {
    osViSetYScale(ctx->f12.fl);
}

extern "C" void osViSetXScale_recomp(uint8_t* rdram, recomp_context * ctx) {
    osViSetXScale(ctx->f12.fl);
}

extern "C" void osCreateViManager_recomp(uint8_t* rdram, recomp_context* ctx) {
    ;
}

extern "C" void osViBlack_recomp(uint8_t* rdram, recomp_context* ctx) {
    osViBlack((uint32_t)ctx->r4);
}

extern "C" void osViSetSpecialFeatures_recomp(uint8_t* rdram, recomp_context* ctx) {
    osViSetSpecialFeatures((uint32_t)ctx->r4);
}

extern "C" void osViGetCurrentFramebuffer_recomp(uint8_t* rdram, recomp_context* ctx) {
    ctx->r2 = (gpr)(int32_t)osViGetCurrentFramebuffer();
}

extern "C" void osViGetNextFramebuffer_recomp(uint8_t* rdram, recomp_context* ctx) {
    ctx->r2 = (gpr)(int32_t)osViGetNextFramebuffer();
}

extern "C" void osViSwapBuffer_recomp(uint8_t* rdram, recomp_context* ctx) {
    osViSwapBuffer(rdram, (int32_t)ctx->r4);
}

extern "C" void osViSetMode_recomp(uint8_t* rdram, recomp_context* ctx) {
    osViSetMode(rdram, (int32_t)ctx->r4);
}