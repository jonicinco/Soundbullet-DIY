# 🔧 Proyecto: Soundbullet‑DIY  
Herramienta de diagnóstico y testeo portátil de audio profesional

Versión DIY del dispositivo **Sound Bullet** de Sonnect, con mejoras como pantalla OLED, encoder rotativo, expansión microSD, LEDs de estado y alimentación por batería recargable.  
Pensado para técnicos de sonido que necesitan una herramienta compacta para comprobar líneas, cables, etapas, mesas y sistemas de PA.

---

## 🎯 Objetivos del dispositivo

- Generador de señal (ruido rosa/blanco, tonos fijos, clips de audio desde microSD).
- Comprobación rápida de líneas balanceadas y cables XLR.
- Medición básica de nivel en entrada XLR.
- Comprobación de phantom power.
- Monitorización por auriculares y/o altavoz interno.
- Interfaz clara mediante OLED + encoder + LEDs.

---

## 🧩 Componentes principales

### Microcontrolador y lógica

- Placa **ESP32** (ESP32‑WROOM / ESP32‑S3, por definir en la versión final).
- Regulador de tensión lineal o conmutado a **3,3 V** (ej. AMS1117‑3.3 o alternativa de baja caída/ruido).
- Botón de RESET y, opcionalmente, botón de BOOT.

### Pantalla e interfaz de usuario

- **Pantalla OLED 0,96"** (controlador SSD1306 u otro compatible, interfaz I²C).
- **Encoder rotativo con pulsador** para:
  - Navegación por menús.
  - Ajuste de nivel y selección de funciones.
- 1–2 **botones extras** (ej. BACK / FUNCTION).
- LED(s) de estado:
  - 1× LED RGB direccionable (ej. WS2812B mini).
  - 1–2× LEDs monocromo (power, phantom, clip, etc.).

### Audio

- **DAC externo** de audio, por ejemplo:
  - PCM5102 (I²S, salida estéreo analógica).
- **Amplificador I²S de potencia** para altavoz interno:
  - MAX98357A (modo mono).
- **Salida de auriculares**:
  - Conector **jack 3,5 mm TRS desenroscable** (parte metálica desmontable para transporte).
- Posible **altavoz interno** pequeño (sólo para chequeo rápido / pitidos).

### Conectividad y almacenamiento

- **Módulo microSD** (SPI) para reproducir archivos de prueba:
  - Soporte previsto para WAV (y en el futuro, MP3 si se usa librería correspondiente).
- Pines de expansión (cabecera de 6–8 pines) para:
  - Programación / depuración.
  - Posibles ampliaciones futuras.

### Conectores XLR

- **XLR macho de chasis sobresaliente**, con borde plano alineado con el cuerpo del conector de los cables:
  - Pensado para conectarse directamente a un patch/rack.
- **XLR hembra de chasis sobresaliente**, también con borde plano:
  - Para recibir señales desde mangueras, cajas de escenario, etc.
- Los dos conectores se situarán en extremos opuestos de la caja, imitando la lógica del Sound Bullet original.

### Alimentación

- **Batería Li‑Po 3,7 V** (ej. 602030 ≈ 300–400 mAh, a concretar según espacio).
- Módulo de carga **TP4056** (o similar) con:
  - Conector **USB‑C** o **Micro‑USB**.
  - LEDs de carga / batería llena.
- Interruptor general de encendido/apagado.
- Posible protección adicional:
  - Fusible / PTC.
  - Protección contra inversión de batería.

---

## 📐 Arquitectura de la PCB y distribución física

### Dimensiones orientativas

- **PCB**:  
  - Largo: **90–100 mm**  
  - Ancho: **40–50 mm**
- **Caja**:  
  - Algo más grande que la PCB para:
    - Dejar borde de fijación a tornillos.
    - Alojamiento de paredes y refuerzos.
    - Espacio para la batería y la electrónica en “capas”.

### Colocación general de bloques en la PCB

- Zona **central/superior**:
  - Módulo ESP32.
  - Líneas de I²S hacia DAC y amplificador.
- Zona **frontal** (alineada con la pared donde se ve el usuario):
  - Pantalla OLED centrada.
  - Encoders y botones justo debajo o al lado de la pantalla.
  - LEDs de estado cerca de la pantalla.
- Zona **laterales** (alineadas con los cantos cortos de la caja):
  - XLR macho en un extremo.
  - XLR hembra en el extremo opuesto.
- Zona **lateral larga**:
  - Jack 3,5 mm desenroscable (en un canto).
  - Conector USB‑C / Micro‑USB de carga.
  - A ser posible, ranura de microSD en el canto inferior o trasero para no interferir con el uso normal.
- Zona **inferior o “segunda altura”**:
  - Batería Li‑Po pegada al fondo de la caja.
  - PCB encima, con separadores de plástico/metal.
  - Si hace falta, una pequeña PCB “hija” para separar la parte analógica (audio) de la digital (ESP32).

---

## 🔁 Flujo de señal (bloques funcionales)

1. **Generación digital** en ESP32:
   - Generador de ruido / tonos por software.
   - Reproducción de archivos desde microSD.

2. **Salidas de audio**:
   - I²S → DAC PCM5102 → etapa de salida balanceada/XLR y salida jack.
   - I²S → MAX98357A → altavoz interno.

3. **Entradas de audio**:
   - Entrada XLR hembra → etapa de adaptación / atenuación → ADC del ESP32 (para medición de nivel, presencia de señal).
   - Posible medición dedicada de phantom (a través de red de resistencias y protección).

4. **Control y UI**:
   - Encoder y botones → GPIO del ESP32.
   - OLED → bus I²C.
   - LEDs (RGB + mono) → GPIO / bus serie de los Neopixel.

5. **Alimentación**:
   - Batería → protección → regulador(es) 3,3 V.
   - USB‑C/Micro‑USB → TP4056 → batería.
   - Detección de estado de carga / batería baja mediante entrada ADC.

---

## 🧱 Arquitectura externa de la caja

> Nota: la caja se plantea tipo “barra” alargada, pensada para llevar en el cinturón o en una funda.

### Vista frontal

Elementos centrados y orientados al usuario:

- Pantalla OLED 0,96" centrada o ligeramente desplazada hacia un lado.
- Encoder rotativo con pulsador junto a la pantalla.
- 1–2 botones adicionales alineados.
- 1 LED RGB (ej. debajo de la pantalla) para indicar:
  - Modo activo.
  - Estado (OK / error / clip).
- 1 LED monocromo para indicar power / carga / phantom.

**Posible distribución:**

- Fila superior: OLED.
- Fila inferior: [Botón 1] [Encoder] [Botón 2] + LED(s) a los lados.

### Vistas laterales cortas

- **Lateral A**:
  - XLR macho de chasis sobresaliente con borde plano.
- **Lateral B**:
  - XLR hembra de chasis sobresaliente con borde plano.

Ambos diseñados para que el “barril” del XLR salga lo suficiente como para conectarse cómodamente a:
- Parches de escenario.
- Cajas directas.
- Racks de estudio.

### Vista lateral larga

- Jack 3,5 mm TRS desenroscable (con tuerca exterior).
- Conector USB‑C o Micro‑USB.
- Opcionalmente, ranura accesible de microSD.
- Pequeña leyenda serigrafiada indicando cada conector.

### Vista inferior / trasera

- Zona para etiqueta con:
  - Nombre del proyecto.
  - Versión del hardware.
  - Posibles advertencias (tensión, phantom, etc.).
- Orificios para tornillos de cierre de la carcasa.
- Posible ventana o tapa para acceso directo a la batería o a la SD (a definir).

---

## 🧾 Estructura del repositorio

```text
Soundbullet-DIY/
├── README.md              # Este archivo
├── hardware/
│   ├── esquematico.pdf    # Esquema eléctrico general
│   ├── pcb-top.png        # Render de la PCB vista superior
│   ├── pcb-bottom.png     # Render de la PCB vista inferior
│   └── bom.xlsx           # Lista de materiales (BOM)
├── firmware/
│   ├── src/
│   │   ├── main.cpp       # Lógica principal (ESP32)
│   │   ├── audio.cpp      # Manejo de DAC, I²S, generadores
│   │   ├── ui.cpp         # Menús, encoder, OLED
│   │   └── config.h       # Pines, constantes y opciones
│   └── platformio.ini     # (si se usa PlatformIO)
├── enclosure/
│   ├── soundbullet-case-v1.stl   # Caja 3D versión 1
│   └── belt-holster-v1.stl       # Funda para cinturón (opcional)
└── docs/
    ├── arquitectura.md    # Explicación más detallada de bloques
    ├── modos-de-uso.md    # Ejemplos de uso en directo
    └── img/
        ├── prototipo-frontal.png
        ├── prototipo-lateral.png
        └── prototipo-interno.png

---

## ✅ Mejoras previstas frente al Sound Bullet original

- Pantalla OLED para:
  - Ver niveles.
  - Navegar menús.
  - Seleccionar tipo de señal de prueba.
- Encoder rotativo multipropósito (en lugar de simples pulsadores).
- Jack 3,5 mm desenroscable para minimizar daños en el transporte.
- Reproducción de archivos de prueba desde microSD (no sólo ruido/tono generados).
- Iluminación RGB como feedback de estado.
- Mayor modularidad interna (fácil reparación y modding).
- Posible ampliación futura vía firmware (nuevos modos, nuevos generadores, etc.).

---
