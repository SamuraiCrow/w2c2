#ifndef W2C2_INSTRUCTION_H
#define W2C2_INSTRUCTION_H

#include "w2c2_base.h"
#include "buffer.h"
#include "opcode.h"

/* WasmLocalInstruction */

typedef struct WasmLocalInstruction {
    U32 localIndex;
} WasmLocalInstruction;

bool
WARN_UNUSED_RESULT
wasmLocalInstructionRead(
    Buffer* buffer,
    WasmLocalInstruction* result
);

/* WasmGlobalInstruction */

typedef struct WasmGlobalInstruction {
    U32 globalIndex;
} WasmGlobalInstruction;

bool
WARN_UNUSED_RESULT
wasmGlobalInstructionRead(
    Buffer* buffer,
    WasmGlobalInstruction* result
);

/* WasmConstInstruction */

typedef union WasmValue {
    I32 i32;
    I64 i64;
    F32 f32;
    F64 f64;
} WasmValue;

typedef struct WasmConstInstruction {
    WasmValue value;
} WasmConstInstruction;

bool
WARN_UNUSED_RESULT
wasmConstInstructionRead(
    Buffer* buffer,
    WasmOpcode opcode,
    WasmConstInstruction* result
);

/* WasmLoadStoreInstruction */

typedef struct WasmLoadStoreInstruction {
    U32 align;
    U32 offset;
} WasmLoadStoreInstruction;

bool
WARN_UNUSED_RESULT
wasmLoadStoreInstructionRead(
    Buffer* buffer,
    WasmLoadStoreInstruction* result
);

/* WasmCallInstruction */

typedef struct WasmCallInstruction {
    U32 funcIndex;
} WasmCallInstruction;

bool
WARN_UNUSED_RESULT
wasmCallInstructionRead(
    Buffer* buffer,
    WasmCallInstruction* result
);

/* WasmCallIndirectInstruction */

typedef struct WasmCallIndirectInstruction {
    U32 functionTypeIndex;
    U32 tableIndex;
} WasmCallIndirectInstruction;

bool
WARN_UNUSED_RESULT
wasmCallIndirectInstructionRead(
    Buffer* buffer,
    WasmCallIndirectInstruction* result
);

/* WasmBranchInstruction */

typedef struct WasmBranchInstruction {
    U32 labelIndex;
} WasmBranchInstruction;

bool
WARN_UNUSED_RESULT
wasmBranchInstructionRead(
    Buffer* buffer,
    WasmBranchInstruction* result
);

/* WasmBranchTableInstruction */

typedef struct WasmBranchTableInstruction {
    U32* labelIndices;
    U32 labelIndexCount;
    U32 defaultLabelIndex;
} WasmBranchTableInstruction;

void
wasmBranchTableInstructionFree(
    WasmBranchTableInstruction instruction
);

bool
WARN_UNUSED_RESULT
wasmBranchTableInstructionRead(
    Buffer* buffer,
    WasmBranchTableInstruction* result
);

/* WasmMemoryInstruction */

typedef struct WasmMemoryInstruction {
    U32 memoryIndex;
} WasmMemoryInstruction;

bool
WARN_UNUSED_RESULT
wasmMemoryInstructionRead(
    Buffer* buffer,
    WasmMemoryInstruction* result
);

/* WasmMemoryCopyInstruction */

typedef struct WasmMemoryCopyInstruction {
    U32 memoryIndex1;
    U32 memoryIndex2;
} WasmMemoryCopyInstruction;

bool
WARN_UNUSED_RESULT
wasmMemoryCopyInstructionRead(
    Buffer* buffer,
    WasmMemoryCopyInstruction* result
);

#endif /* W2C2_INSTRUCTION_H */
