/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _QWERTY_ALT,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  SEND_YES,
  SEND_NO,
  VIM_CNF,
  CUST_BSPC,
};

#define EMDASH 0x2014
#define GBP 0x00A3

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define QWALT MO(_QWERTY_ALT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   Q  |   W  |   E  |      |      |      |      |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |Qwalt |      |      |Qwalt |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |      |      |      |      |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  OS  |Lower | Ctrl |Space |Raise | Alt  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_GRV,  KC_Q,    KC_W,    KC_E,          _______, _______,       _______, _______, KC_I,          KC_O,    KC_P,    CUST_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,          QWALT,   _______,       _______, QWALT,   KC_K,          KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,          _______, _______,       _______, _______, KC_COMM,       KC_DOT,  KC_SLSH, KC_RSFT,
    _______, _______, _______, OSM(MOD_LGUI), LOWER,   OSM(MOD_LCTL), KC_SPC,  RAISE,   OSM(MOD_LALT), _______, _______, _______
),

/* Qwerty (Alternate)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |   R  |   T  |      |      |      |      |   Y  |   U  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  —   |   F  |   G  |      |      |      |      |   H  |   J  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |   V  |   B  |      |      |      |      |   N  |   M  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY_ALT] = LAYOUT_planck_grid(
    _______, _______,    KC_R,    KC_T,    _______, _______, _______, _______, KC_Y,    KC_U,    _______, _______,
    _______, UC(EMDASH), KC_F,    KC_G,    _______, _______, _______, _______, KC_H,    KC_J,    _______, _______,
    _______, _______,    KC_V,    KC_B,    _______, _______, _______, _______, KC_N,    KC_M,    _______, _______,
    _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |   !  |   @  |   #  |      |      |      |      |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Caps |   _  |   +  |   -  |S-Tab |      |      |Enter |Ctrl-L|   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   ^  |   $  |   =  |      |      |      |      |      |   [  |   ]  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    _______, KC_EXLM, KC_AT,     KC_HASH,  _______,      _______, _______, _______, KC_ASTR,    KC_LPRN, KC_RPRN, LCTL(KC_BSPC),
    KC_CAPS, KC_UNDS, KC_PLUS,   KC_MINS,  LSFT(KC_TAB), _______, _______, KC_ENT,  LCTL(KC_L), KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_CIRC, KC_DOLLAR, KC_EQUAL, _______,      _______, _______, _______, _______,    KC_LBRC, KC_RBRC, _______,
    _______, _______, _______,   _______,  _______,      _______, _______, _______, _______,    _______, _______, _______
),


/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   0  |   1  |   2  |   3  |      |      |      |      |  Up  |   %  |  &   | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   4  |   5  |   6  | Tab  |      |      | Left | Down |Right | End  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   7  |   8  |   9  |      |      |      |      |C-A-L |C-A-R |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_0,    KC_1,    KC_2,    KC_3,    _______, _______, _______, _______, KC_UP,        KC_PERC,       KC_AMPR, CUST_BSPC,
    _______, KC_4,    KC_5,    KC_6,    KC_TAB,  _______, _______, KC_LEFT, KC_DOWN,      KC_RIGHT,      KC_END,  KC_BSLS,
    _______, KC_7,    KC_8,    KC_9,    _______, _______, _______, _______, LCA(KC_LEFT), LCA(KC_RIGHT), _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,      _______,       _______, _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | ULnx | UOSX |      | Yes  |      |      |      |      | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |C-S-L |C-S-D |C-S-U |C-S-R |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  | No   |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   UNICODE_MODE_LNX, UNICODE_MODE_OSX, _______, SEND_YES,            _______,             _______,           _______,              _______, KC_DEL,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,            KC_F5,            KC_F6,   LCTL(LGUI(KC_LEFT)), LCTL(LGUI(KC_DOWN)), LCTL(LGUI(KC_UP)), LCTL(LGUI(KC_RIGHT)), _______, _______,
    /* _______, AU_ON,   AU_OFF,  _______,          VIM_CNF,          ______, SEND_NO,  _______, _______, _______, _______, _______, */
    KC_F7,   KC_F8,   KC_F9,   KC_F10,           KC_F11,           KC_F12,  SEND_NO,             _______,             _______,           _______,              _______, _______,
    _______, _______, _______, _______,          _______,          _______, _______,             _______,             _______,           _______,              _______, _______
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case UNICODE_MODE_LNX:
      if (record->event.pressed){
        SEND_STRING("L");
      }
      // Continue to process the key as normal
      return true;
      break;
    case UNICODE_MODE_OSX:
      if (record->event.pressed){
        SEND_STRING("M");
      }
      // Continue to process the key as normal
      return true;
      break;
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case SEND_YES:
      if (record->event.pressed) {
        SEND_STRING("y\n");
      }
      return false;
      break;
    case SEND_NO:
      if (record->event.pressed) {
        SEND_STRING("n\n");
      }
      return false;
      break;
    case VIM_CNF:
      if (record->event.pressed) {
        SEND_STRING(":set nocompatible\n");
        SEND_STRING(":filetype plugin indent on\n");
        SEND_STRING(":let mapleader= \"\\\\\"\n");
        SEND_STRING(":set backspace=indent,eol,start\n");
        SEND_STRING(":set tabstop=2\n");
        SEND_STRING(":set shiftwidth=2\n");
        SEND_STRING(":set softtabstop=2\n");
        SEND_STRING(":set shiftround\n");
        SEND_STRING(":set autoindent\n");
        SEND_STRING(":set smartindent\n");
        SEND_STRING(":set expandtab\n");
        SEND_STRING(":set nowrap\n");
        SEND_STRING(":set nostartofline\n");
        SEND_STRING(":set modeline\n");
        SEND_STRING(":set number\n");
        SEND_STRING(":set relativenumber\n");
        SEND_STRING(":set incsearch\n");
        SEND_STRING(":set nowrapscan\n");
        SEND_STRING(":autocmd BufNewFile,BufRead * exec \"setlocal colorcolumn=\".(&ma ? \"81\" : \"0\")\n");
        SEND_STRING(":syntax enable\n");

        SEND_STRING(":function! InsertModeChanged(mode)\n");
        SEND_STRING("   if a:mode == 'i'\n");
        SEND_STRING("        highlight LineNr ctermfg=45\n");
        SEND_STRING("        highlight CursorLineNr ctermfg=33\n");
        SEND_STRING("    elseif a:mode == 'r'\n");
        SEND_STRING("        highlight LineNr ctermfg=202\n");
        SEND_STRING("        highlight CursorLineNr ctermfg=196\n");
        SEND_STRING("    else\n");
        SEND_STRING("        highlight LineNr ctermfg=244\n");
        SEND_STRING("        highlight CursorLineNr ctermfg=238\n");
        SEND_STRING("    endif\n");
        SEND_STRING("endfunction\n");
        SEND_STRING(":autocmd InsertEnter * call InsertModeChanged(v:insertmode)\n");
        SEND_STRING(":autocmd InsertLeave * call InsertModeChanged('')\n");
        SEND_STRING(":call InsertModeChanged('')\n");

        SEND_STRING(":nnoremap <expr> ` printf('`\%czz', getchar())\n");
        SEND_STRING(":noremap <leader>i `iO\n");

        SEND_STRING(":set hidden\n");
        SEND_STRING(":nmap <silent> <leader>Tn <Esc>:tabnew<CR>\n");
        SEND_STRING(":nmap <silent> <leader>bb <Esc>:b#<CR>zz\n");
        SEND_STRING(":nmap <silent> <leader>bq <Esc>:call CloseBuffer()<CR>\n");
        SEND_STRING(":nmap <silent> <leader>bw <Esc>:w<CR>:call CloseBuffer()<CR>\n");
        SEND_STRING(":nmap <silent> \\| <Esc>:b#<CR>zz\n");

        SEND_STRING(":inoremap <C-s> <Esc>:wa<CR>\n");
        SEND_STRING(":nnoremap <C-s> <Esc>:wa<CR>\n");
        SEND_STRING(":command! Q wqa\n");

        SEND_STRING(":setlocal completeopt=longest,menuone\n");
        SEND_STRING(":fun! ShouldAutocomplete()\n");
        SEND_STRING("    return pumvisible() || !(strpart(getline('.'), 0, col('.') - 1) =~ '^\\s*$')\n");
        SEND_STRING("endfun\n");
        SEND_STRING(":imap <expr> <Tab> ShouldAutocomplete() ? '<C-p>' : '<Tab>'\n");
        SEND_STRING(":imap <expr> <Up> pumvisible() ? '<C-p>' : '<Up>'\n");
        SEND_STRING(":imap <expr> <Down> pumvisible() ? '<C-n>' : '<Down>'\n");
      }
      return false;
      break;

    case CUST_BSPC: {
      uint8_t temp_mods = get_mods();

      del_mods(MOD_MASK_SHIFT);

      if (record->event.pressed) {
        register_code(KC_BSPC);
      } else {
        unregister_code(KC_BSPC);
      }

      set_mods(temp_mods);

      return false;
      break;
    }

  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
    return true;
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
