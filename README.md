[README.md](https://github.com/user-attachments/files/23617730/README.md)
# 🔧 Proyecto: Soundbullet-DIY  
🎛️ Herramienta de diagnóstico y testeo portátil de audio profesional

Versión DIY del conocido dispositivo "Sound Bullet" de Sonnect, con mejoras modulares como pantalla OLED, encoder, expansión microSD, LEDs y alimentación por batería recargable. Ideal para técnicos de sonido que desean construir su propio equipo compacto de pruebas.

---

## 🧩 Componentes utilizados

### 🔹 Microcontroladores y placas base
- ESP32-S3 o ESP32-WROOM
- Regulador de voltaje AMS1117 3.3V

![Componentes MCU](https://images.openai.com/generated/775aced5-b94b-425d-b956-69cba419671a.png)

---

### 🔹 Pantalla
- OLED 0.96" I2C o SPI (SSD1306 u otro compatible)

![Pantalla OLED](https://images.openai.com/generated/c1015200-d723-4a2c-b8b3-d6d040444bf7.png)

---

### 🔹 Interfaz de usuario
- Encoder rotativo con pulsador
- Botones adicionales (navegación, selección)

![Encoder + controles](https://images.openai.com/generated/c1015200-d723-4a2c-b8b3-d6d040444bf7.png)

---

### 🔹 Audio
- DAC PCM5102 (Adafruit / SparkFun)
- Amplificador I2S MAX98357A
- Salida de auriculares 3.5mm (jack desmontable)
- Piezo opcional para señales acústicas internas

![Módulos de audio](https://images.openai.com/generated/c1015200-d723-4a2c-b8b3-d6d040444bf7.png)

---

### 🔹 Conectividad y almacenamiento
- Módulo microSD con level shifter integrado
- Soporte para archivos MP3 o WAV desde SD

![MicroSD + módulos I/O](https://images.openai.com/generated/c1015200-d723-4a2c-b8b3-d6d040444bf7.png)

---

### 🔹 Conectores XLR
- XLR macho y hembra de **chasis empotrable con borde plano**, ideales para conexión directa a patches o racks
- Salida desmontable jack TRS (para evitar roturas al transportar)

![Conectores XLR](https://images.openai.com/generated/c1015200-d723-4a2c-b8b3-d6d040444bf7.png)

---

### 🔹 Iluminación y señalización
- LEDs RGB direccionables (Neopixel, WS2812)
- LEDs blancos para nivel/estado

---

### 🔋 Alimentación
- Batería LiPo 3.7V 300mAh (modelo 602030)
- Módulo TP4056 para carga por MicroUSB o USB-C

---

## 📐 Distribución física de la caja

**Dimensiones estimadas:**
- PCB: 100 mm (largo) × 50 mm (ancho)
- Caja: ligeramente mayor para cubrir los bordes y permitir montaje estructurado

---

### 🧱 Arquitectura externa

**FRENTE:**
- Pantalla OLED
- Encoder con pulsador
- Botones adicionales (2)

**LATERALES:**
- XLR macho en un extremo
- XLR hembra en el opuesto
- Jack 3.5mm con sistema desenroscable

**PARTE INFERIOR:**
- Puerto de carga (MicroUSB o USB-C)
- LED de carga y estado

---

### 🖼️ Imagen del prototipo (referencial)

> Render de ejemplo: carcasa impresa en 3D, con display, encoder, microSD, batería y XLRs visibles.

![Prototipo Soundbullet-DIY](https://images.openai.com/generated/c1015200-d723-4a2c-b8b3-d6d040444bf7.png)

---

## 🗂️ Organización del repositorio

