// -------------------------------------------------------------
// main.cpp – Lógica principal del proyecto Soundbullet-DIY
// -------------------------------------------------------------
// NOTA: Este archivo es un esqueleto básico para comenzar a
// construir el firmware. No implementa funcionalidad real,
// pero establece la estructura general del programa.
// -------------------------------------------------------------

#include <Arduino.h>
#include "config.h"
#include "audio.h"
#include "ui.h"

void setup() {
    Serial.begin(115200);
    
    ui_init();
    audio_init();

    ui_showSplash();
}

void loop() {
    // Leer encoder y botones
    ui_update();

    // Ejecutar modo o herramienta activa
    audio_update();

    delay(5); // Evita saturar la CPU
}
