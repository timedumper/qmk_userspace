#include "utils.h"

unsigned int num_active_layers(layer_state_t state) {
    return
#if defined(LAYER_STATE_8BIT)
        bitpop(state);
#elif defined(LAYER_STATE_16BIT)
        bitpop16(state);
#else
        bitpop32(state);
#endif
    ;
}
