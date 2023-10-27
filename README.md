

# Fastbootwizard

## Beschreibung

Komandozeilentool um lästige Arbeiten mit Fastboot automatisch durchzuführen.

***→  siehe Funktionen***

### Nutzungshinweise:

- ! ! ! Dies ist ein reines Linux-Tool ! ! ! 

- ! ! ! Benutzung auf eigene Gefahr ! ! ! 

- ! ! ! Es kann zu Schäden an den Gerät kommen ! ! ! 

- ! ! ! Das Programm wird zur Installation von ADB und Fastboot Root-Rechte (sudo) verwenden. ! ! ! 

### Funktionen:
- Boot Recovery
- Boot Fastboot (+ fastboot help, alle Bootloader Variablen)
- öffnen/schließen Bootloader
- Löschen von Systemteilen ohne erneuten Flash
- Flashen von Systembestandteilen (auch für only-a-devices und a/b-devices)
- umbenennen von Dateien

---
## Lizenz

**GNU GENERAL PUBLIC LICENSE (GPLv3)**

---
## Installation

Es werden für die Ausführung des Programms folgende Tools benötigt. 

*Android Debug Bridge (adb)*, *Fastboot*

Normaler Weise prüft das Programm ob diese Tools schon verfügbar sind und sollte sie installieren (Nur für Ubuntu/Debian, Fedora, Arch, OpenSUSE → andere folgen später)

Falls das nicht geht prüfen sie auf welchem Betriebssystem ihr Betriebssystem basiert, dann installieren sie die benötigten Tools mit folgenden Befehlen:
```sh
# Debian / Ubuntu:
sudo apt update
sudo apt install android-tools-adb android-tools-fastboot
```
```sh
# Fedora: 
sudo dnf install android-tools
```
```sh
# Arch:
sudo pacman -S android-tools
```
```sh
# openSUSE:
sudo zypper install android-tools
```
 
Um diese Tool auszuführen führen sie im Terminal folgendes aus:
```sh
./v_0_3_3-Weintraube
```
Dann folgen sie den Anweisungen des Programms.

---
## Versionen

- v.0.3.3.- Weintraube → ***aktuelle Version***
- v.0.2. - Kirschreiher (Beta)
- v.0.1. - Kirsche (Alpha)

---
## Build

1. Laden sie den Quellcode herunter 
2. bearbeiten sie diesen nach ihren Vorstellungen
3. installieren sie GCC:

```sh
# Debian / Ubuntu:
sudo apt update
sudo apt install build-essential
```
```sh
# Fedora:
sudo dnf install gcc
```
```sh
# Arch:
sudo pacman -Syu
sudo pacman -S gcc
```
```sh
# Open SUSE:
sudo zypper install gcc
```

4. Kompilieren sie den Code:
```sh
gcc dateiname.c -o dateiname
```

---
## Ersteller

***Elias Mörz***

---
## Fehler
Fehlermeldungen / Fehlfunktionen melden an:
Kirschblute.in.c@gmail.com

Ich versuche mich so schnell wie möglich zu kümmern.