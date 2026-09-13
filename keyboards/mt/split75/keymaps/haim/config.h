
#pragma once

// Do not do effects by default
#undef RGBLIGHT_DEFAULT_MODE

// This prevents hangups when M1/M2 MacBook is reconnected. This disables the USB suspend feature
// altogether, though... Nothing else appears to work.
#define NO_USB_STARTUP_CHECK

// QMK limits System Control to 0x81-0x8F by default; the DND key sends 0x9B (System Do Not Disturb).
#define SYSTEM_CONTROL_USAGE_MAXIMUM 0x009B
