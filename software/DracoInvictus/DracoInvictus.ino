/**
 * This example turns the ESP32 into a Bluetooth LE keyboard that writes the words, presses Enter, presses a media key and then Ctrl+Alt+Delete
 */
#include "BleKeyboard.h"

BleKeyboard bleKeyboard("DracoInvictusKB");

#include "PS2KeyAdvanced.h"

#define DATAPIN 19
#define IRQPIN 18

uint16_t c;

PS2KeyAdvanced keyboard;


void setup() {
  Serial.begin(115200);

  keyboard.begin(DATAPIN, IRQPIN);
  Serial.println("PS2 Advanced Key Simple Test:");


  Serial.println("Starting BLE work!");
  bleKeyboard.begin();
}

void loop() {
  //  Serial.println ("Still alive");

  if (keyboard.available()) {
    // read the next key
    c = keyboard.read();
    if (c > 0) {
      Serial.print("Value ");
      Serial.print(c, HEX);
      Serial.print(" - Status Bits ");
      Serial.print(c >> 8, HEX);
      Serial.print("  Code ");
      Serial.println(c & 0xFF, HEX);


      if (bleKeyboard.isConnected()) {
        Serial.println("Sending");
        uint16_t key = c & 0xFF;

        switch (key) {
          case PS2_KEY_SPACE: key = ' '; break;
          case PS2_KEY_UP_ARROW: key = KEY_UP_ARROW; break;
          case PS2_KEY_DN_ARROW: key = KEY_DOWN_ARROW; break;
          case PS2_KEY_L_ARROW: key = KEY_LEFT_ARROW; break;
          case PS2_KEY_R_ARROW: key = KEY_RIGHT_ARROW; break;
          case PS2_KEY_BS: key = KEY_BACKSPACE; break;
          case PS2_KEY_TAB: key = KEY_TAB; break;
          case PS2_KEY_ENTER: key = KEY_RETURN; break;
          case PS2_KEY_ESC: key = KEY_ESC; break;
          case PS2_KEY_INSERT: key = KEY_INSERT; break;
          case PS2_KEY_PRTSCR: key = KEY_PRTSC; break;
          case PS2_KEY_DELETE: key = KEY_DELETE; break;
          case PS2_KEY_PGUP: key = KEY_PAGE_UP; break;
          case PS2_KEY_PGDN: key = KEY_PAGE_DOWN; break;
          case PS2_KEY_HOME: key = KEY_HOME; break;
          case PS2_KEY_END: key = KEY_END; break;

          case PS2_KEY_KP0: key = KEY_NUM_0; break;
          case PS2_KEY_KP1: key = KEY_NUM_1; break;
          case PS2_KEY_KP2: key = KEY_NUM_2; break;
          case PS2_KEY_KP3: key = KEY_NUM_3; break;
          case PS2_KEY_KP4: key = KEY_NUM_4; break;
          case PS2_KEY_KP5: key = KEY_NUM_5; break;
          case PS2_KEY_KP6: key = KEY_NUM_6; break;
          case PS2_KEY_KP7: key = KEY_NUM_7; break;
          case PS2_KEY_KP8: key = KEY_NUM_8; break;
          case PS2_KEY_KP9: key = KEY_NUM_9; break;
          case PS2_KEY_KP_DOT: key = KEY_NUM_PERIOD; break;
          case PS2_KEY_KP_ENTER: key = KEY_NUM_ENTER; break;
          case PS2_KEY_KP_PLUS: key = KEY_NUM_PLUS; break;
          case PS2_KEY_KP_MINUS: key = KEY_NUM_MINUS; break;
          case PS2_KEY_KP_TIMES: key = KEY_NUM_ASTERISK; break;
          case PS2_KEY_KP_DIV: key = KEY_NUM_SLASH; break;
          case PS2_KEY_KP_EQUAL: key = '='; break;
          case PS2_KEY_KP_COMMA: key = ','; break;

          case PS2_KEY_APOS: key = '\''; break;
          case PS2_KEY_COMMA: key = ','; break;
          case PS2_KEY_MINUS: key = '-'; break;
          case PS2_KEY_DOT: key = '.'; break;
          case PS2_KEY_DIV: key = '/'; break;
          case PS2_KEY_SINGLE: key = '`'; break;
          case PS2_KEY_SEMI: key = ';'; break;
          case PS2_KEY_BACK: key = '\\'; break;
          case PS2_KEY_OPEN_SQ: key = '['; break;
          case PS2_KEY_CLOSE_SQ: key = ']'; break;
          case PS2_KEY_EQUAL: key = '='; break;

          case PS2_KEY_F1: key = KEY_F1; break;
          case PS2_KEY_F2: key = KEY_F2; break;
          case PS2_KEY_F3: key = KEY_F3; break;
          case PS2_KEY_F4: key = KEY_F4; break;
          case PS2_KEY_F5: key = KEY_F5; break;
          case PS2_KEY_F6: key = KEY_F6; break;
          case PS2_KEY_F7: key = KEY_F7; break;
          case PS2_KEY_F8: key = KEY_F8; break;
          case PS2_KEY_F9: key = KEY_F9; break;
          case PS2_KEY_F10: key = KEY_F10; break;
          case PS2_KEY_F11: key = KEY_F11; break;
          case PS2_KEY_F12: key = KEY_F12; break;
          case PS2_KEY_F13: key = KEY_F13; break;
          case PS2_KEY_F14: key = KEY_F14; break;
          case PS2_KEY_F15: key = KEY_F15; break;
          case PS2_KEY_F16: key = KEY_F16; break;
          case PS2_KEY_F17: key = KEY_F17; break;
          case PS2_KEY_F18: key = KEY_F18; break;
          case PS2_KEY_F19: key = KEY_F19; break;
          case PS2_KEY_F20: key = KEY_F20; break;
          case PS2_KEY_F21: key = KEY_F21; break;
          case PS2_KEY_F22: key = KEY_F22; break;
          case PS2_KEY_F23: key = KEY_F23; break;
          case PS2_KEY_F24:
            key = KEY_F24;
            break;

          case PS2_KEY_NUM: key = KEY_NUM_LOCK; break;
          case PS2_KEY_SCROLL: key = KEY_SCROLL_LOCK; break;
          case PS2_KEY_CAPS:
            key = KEY_CAPS_LOCK;
            break;
            //          case PS2_KEY_PAUSE : key = KEY_; break;
          case PS2_KEY_L_SHIFT: key = KEY_LEFT_SHIFT; break;
          case PS2_KEY_R_SHIFT: key = KEY_RIGHT_SHIFT; break;
          case PS2_KEY_L_CTRL: key = KEY_LEFT_CTRL; break;
          case PS2_KEY_R_CTRL: key = KEY_RIGHT_CTRL; break;
          case PS2_KEY_L_ALT: key = KEY_LEFT_ALT; break;
          case PS2_KEY_R_ALT: key = KEY_RIGHT_ALT; break;
          case PS2_KEY_L_GUI: key = KEY_LEFT_GUI; break;
          case PS2_KEY_R_GUI:
            key = KEY_RIGHT_GUI;
            break;
            //          case PS2_KEY_MENU : key = KEY_; break;
            //          case PS2_KEY_BREAK : key = KEY_; break;
        }
        if ((key >= 'A') && (key <= 'Z')) {
          key = key - 'A' + 'a';
        }
        if (key != 0xFA) {
          if ((key == KEY_CAPS_LOCK) || (key == KEY_NUM_LOCK) || (key == KEY_SCROLL_LOCK))  // toggle, so double press/release rather than press or release.
          {
            bleKeyboard.press(key);
            bleKeyboard.release(key);
          } else {
            if (c & PS2_BREAK)  // release
            {
              bleKeyboard.release(key);
            } else {
              bleKeyboard.press(key);
            }
          }
        }
      }
    }
  }


  //  if (bleKeyboard.isConnected()) {
  //    Serial.println("Sending 'Hello world'...");
  //  bleKeyboard.print("Hello world");

  //   delay(1000);

  // Serial.println("Sending Enter key...");
  //   bleKeyboard.write(KEY_RETURN);

  //   delay(1000);

  //   Serial.println("Sending Play/Pause media key...");
  //   bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);

  //   delay(1000);

  //  Serial.println("Sending Ctrl+Alt+Delete...");
  //  bleKeyboard.press(KEY_LEFT_CTRL);
  //  bleKeyboard.press(KEY_LEFT_ALT);
  //  bleKeyboard.press(KEY_DELETE);
  //  delay(100);
  //  bleKeyboard.releaseAll();
  //  }

  //  Serial.println("Waiting 5 seconds...");
  // delay(5000);
}
