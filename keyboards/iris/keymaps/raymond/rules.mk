# features I don't use
RGBLIGHT_ENABLE = no
BACKLIGHT_ENABLE = no
BOOTMAGIC_ENABLE = no
MOUSEKEY_ENABLE = no
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
MIDI_ENABLE = no
BLUETOOTH_ENABLE = no
API_SYSEX_ENABLE = no
SLEEP_LED_ENABLE = no
AUDIO_ENABLE = no

# features I do use
# EXTRAKEY_ENABLE is needed for audio control keys
EXTRAKEY_ENABLE = yes
NKRO_ENABLE = yes
UNICODE_ENABLE = no
UNICODEMAP_ENABLE = yes

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif
