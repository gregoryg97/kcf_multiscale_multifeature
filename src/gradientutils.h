//
// Created by Gregory Graham on 17/5/20.
//

#ifndef KCF_MULTISCALE_MULTIFEATURE_GRADIENTUTILS_H
#define KCF_MULTISCALE_MULTIFEATURE_GRADIENTUTILS_H

#include <stdlib.h>

namespace utils {
    namespace memory {
        void* alMalloc(size_t size, int alignment) {
            const size_t pSize = sizeof(void*), a = alignment - 1;

            void *raw = malloc(size + a + pSize);
            void *aligned = (void*) (((size_t) raw + pSize + a) & ~a);

            *(void**) ((size_t) aligned - pSize) = raw;

            return aligned;
        }

        void alFree(void* aligned) {
            void *raw = *(void**)((char*)aligned-sizeof(void*));
            free(raw);
        }
    }
}
#endif //KCF_MULTISCALE_MULTIFEATURE_GRADIENTUTILS_H
