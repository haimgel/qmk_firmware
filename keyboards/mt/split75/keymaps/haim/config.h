
#pragma once

// Do not do effects by default
#undef RGBLIGHT_DEFAULT_MODE

// This prevents hangups when M1/M2 MacBook is reconnected. This disables the USB suspend feature
// altogether, though... Nothing else appears to work.
#define NO_USB_STARTUP_CHECK
