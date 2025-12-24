# Christmas Audio Synthesizer

![Language](https://img.shields.io/badge/language-C-00599C?style=for-the-badge&logo=c&logoColor=white)
![License](https://img.shields.io/badge/license-MIT-green?style=for-the-badge)
![Platform](https://img.shields.io/badge/platform-Windows%20%7C%20Linux%20%7C%20macOS-lightgrey?style=for-the-badge)

A high-performance, pure C audio synthesis engine designed to generate musical melodies using mathematical wave functions. This project demonstrates low-level audio programming, WAV file manipulation, and digital signal processing (DSP) concepts without relying on external audio libraries.

## 📋 Features

- **Pure C Implementation**: Built using standard C libraries (`stdio.h`, `stdlib.h`, `math.h`).
- **Custom Synthesis Engine**: Implements additive synthesis to simulate instrument timbres (e.g., Sleigh Bells).
- **WAV File Generation**: Writes raw PCM data with a compliant WAV header (16-bit, 44.1kHz, Mono).
- **Cross-Platform**: Compiles and runs on any system with a C compiler (GCC, Clang, MSVC).
- **Optimized Performance**: Efficient memory management and mathematical calculations.

## 🚀 Getting Started

### Prerequisites

You need a C compiler installed on your system.
- **Windows**: MinGW or Visual Studio.
- **Linux/macOS**: GCC or Clang.

### Installation & Compilation

1.  **Clone the repository** (or download the source code).
2.  **Compile the program** using the following command:

    ```bash
    gcc main.c -o program -lm -O3
    ```

    *Note: The `-lm` flag is required for linking the math library on Linux/macOS.*

### Usage

Run the compiled executable to generate the audio file:

```bash
./program
```

Upon successful execution, the program will generate a file named `output.wav` in the current directory. You can play this file with any standard media player (VLC, Windows Media Player, etc.).

## 🛠️ Technical Details

### Project Structure

- `christmas_songs.c`: Main entry point. Orchestrates the melody sequencing and file I/O.
- `audio_generator.h`: Core synthesis logic. Contains the `AudioBuffer` structure and wave generation functions (`generate_sine_wave`, `generate_bell_note`).
- `music_notes.h`: Defines musical note frequencies (Hz) and timing logic.
- `wav_writer.h`: Handles the creation of the WAV file header according to the RIFF specification.

### How It Works

1.  **Initialization**: The program allocates a memory buffer for the audio data.
2.  **Synthesis**:
    -   **Sine Wave**: Generates fundamental frequencies using `sin(2 * PI * freq * t)`.
    -   **Bell Instrument**: Uses additive synthesis, combining a fundamental frequency with higher harmonics and an exponential decay envelope to simulate the metallic sound of a bell.
3.  **Encoding**: The floating-point audio samples are quantized to 16-bit signed integers (PCM).
4.  **Export**: A valid WAV header is written to the file, followed by the raw audio data.

## Author

**Jorgebyte**

[![GitHub](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/Jorgebyte)
[![Discord](https://img.shields.io/badge/Discord-5865F2?style=for-the-badge&logo=discord&logoColor=white)](https://discord.com/users/1165097093480853634)
[![TikTok](https://img.shields.io/badge/TikTok-000000?style=for-the-badge&logo=tiktok&logoColor=white)](https://www.tiktok.com/@jorgebyte_)
[![Instagram](https://img.shields.io/badge/Instagram-E4405F?style=for-the-badge&logo=instagram&logoColor=white)](https://www.instagram.com/jorgebyte_/)

---
*Generated with ❤️ by Jorgebyte*
