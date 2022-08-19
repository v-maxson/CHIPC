#include "../instruction_functions.h"

CHIPC_InstructionFunction CHIPC_FetchInstruction(CHIPC_Instruction ins) {
    switch (ins.op) {
        case 0x0:
            return CHIPC_Op0;
        case 0x1:
            return CHIPC_Op1;
//        case 0x2:
//            return CHIPC_Op2;
//        case 0x3:
//            return CHIPC_Op3;
//        case 0x4:
//            return CHIPC_Op4;
//        case 0x5:
//            return CHIPC_Op5;
        case 0x6:
            return CHIPC_Op6;
        case 0x7:
            return CHIPC_Op7;
//        case 0x8:
//            return CHIPC_Op8;
//        case 0x9:
//            return CHIPC_Op9;
        case 0xA:
            return CHIPC_OpA;
//        case 0xB:
//            return CHIPC_OpB;
//        case 0xC:
//            return CHIPC_OpC;
        case 0xD:
            return CHIPC_OpD;
//        case 0xE:
//            return CHIPC_OpE;
//        case 0xF:
//            return CHIPC_OpF;

        default:
            return NULL;
    }
}