# 💾 Firmware – Soundbullet-DIY

Esta carpeta contiene todo el software necesario para programar el ESP32 usado en el Soundbullet-DIY.

El firmware está organizado para **PlatformIO**, pero también puede adaptarse a Arduino IDE.

## 📄 Estructura prevista

```
firmware/
├── platformio.ini         # Configuración del proyecto en PlatformIO
├── README.md              # Este archivo
└── src/
    ├── main.cpp           # Lógica principal
    ├── audio.cpp          # Generación de señal, DAC, I2S
    ├── ui.cpp             # Interfaz: OLED, encoder, menús
    └── config.h           # Pines, constantes, typedefs
```

## 🧠 Objetivos del firmware

- Generar ruido rosa / blanco.
- Generar tono de 1 kHz y otros tonos seleccionables.
- Reproducir archivos WAV desde microSD.
- Mostrar menús e información en la pantalla OLED.
- Medir señal de entrada por XLR hembra.
- Detectar presencia de phantom.
- Control mediante encoder rotativo y botones.

## ✔️ Dependencias sugeridas

- **ESP32 Arduino Core**
- **Adafruit SSD1306** (OLED)
- **ESP32 I2S driver**
- **SD / SDFat**
- **Adafruit Neopixel**

## 📝 Notas

Cualquier nuevo archivo .cpp o .h debe explicarse brevemente aquí.
