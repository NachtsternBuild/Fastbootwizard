

# Fastbootwizard

## Beschreibung

Komandozeilentool um lästige Arbeiten mit Fastboot automatisch durchzuführen.

***→  siehe Funktionen***

### Nutzungshinweise:

- ! ! ! Dies ist ein reines Linux-Tool ! ! ! 

- ! ! ! Benutzung auf eigene Gefahr ! ! ! 

- ! ! ! Es kann zu Schäden an den Gerät kommen ! ! ! 

- Dies ist ein vorkompiliertes Tool

### Funktionen: → siehe Liste "Buchstabenverteilung der Funktionen/Variablen"
- Boot Recovery
- Boot Bootloader (+ fastboot help, alle Bootloader Variablen)
- öffnen/schließen Bootloader
- Löschen von Systemteilen ohne erneuten Flash
- Flashen von Systembestandteilen

→ siehe Buchstabenverteilung um genaue Übersicht über die Funktionen zu bekommen 

---
## Lizenz

**GNU GENERAL PUBLIC LICENSE (GPLv3)**

## Ersteller
***Elias Mörz***

---
## Installation

Es werden für die Ausführung des Programms folgende Tools benötigt:

*Android Debug Bridge (adb)*, *Fastboot*

Wenn sie das diese Tools noch nicht installiert haben, dann geben sie folgenden Befehle in das Terminal:
```sh
# Debian / Ubuntu
sudo apt update
sudo apt install android-tools-adb android-tools-fastboot
```
```sh
# Fedora 
sudo dnf install android-tools
```
```sh
# Arch
sudo pacman -S android-tools
```
```sh
# openSUSE
sudo zypper install android-tools
```
 
Um diese Tool auszuführen führen sie im Terminal folgendes aus:
```sh
./v_0_2-Kirschreiher
```
Dann folgen sie den Anweisungen des Programms.

---
## Versionen

- *v.0.3.-1 - Weintraube (Deutsch) → kommendes Release*
- *v.0.3.-2 - Weintraube (Englisch) → kommendes Release*  
- v.0.2. - Kirschreiher (Beta) → ***Aktuelle Version***
- v.0.1. - Kirsche (Alpha) → siehe **Archived**

### Buchstabenverteilung der Funktionen/Variablen:

---

- a = Alle Funktionen von der ADB ausführen (Hauptfunktion Cherry) (Unterfunktionen: 2. 'Erdbeere/strawberry')
- b = Bootloader öffnen oder schließen (Unterfunktionen: 4. 'Papaya' (ADB); 10. 'Kakadupflaume' (Fastboot))
- c =
- d =
- e = Löschen von Systemteilen ohne neuen Flash (Unterfunktionen: 6. 'Durian' (ADB); 10. 'Kaki' (Fastboot))
- f = Alle Funktionen direkt von Fastboot ausführen (Hauptfunktion Cherry) (Unterfunktionen: 7. 'Mango')
- g =
- h = Boot in Fastboot-Modus + fastboot help und alle Fastboot Variablen (Unterfunktionen: 3. 'Litschi/lychee' (ADB); 9. 'Fingerlimette' (Fastboot))
- i = Flashen von Image-Dateien. Update via Zip-Datei (Unterfunktionen: 7. 'Baumtomate' (ADB); 12. 'Guave' (Fastboot))
- j = 
- k =
- l =
- m =
- n =
- o =
- p =
- q =
- r = Boot ins Recovery OS ('Erdberre/strawberry' (ADB); 'Mango' (Fastboot))
- s =
- t =
- u = umbenennen von Dateien (Hauptfunktion: 'Cherry') (Unterfunktion: 'Zitrone')*noch in Arbeit*
- v =
- w =
- x =
- y =
- z =

---

#### Variablen für Unterfunktionen:

---

1. : ***cherry*** (Übergeornet: 2.; 7.)

2. : strawberry (Übergeordnet: 3.; 4.; 5.; 6.) 

3. : lychee: 

		h = fastboot help;
 
 		g = alle Fastboot Variablen
           
4. : papaya: 

		u = Bootloader öffnen (5. Drachenauge (ADB))

		l = Bootloader schließen
            
5. : drachenauge: 

		o = Bootloader öffnen bei älteren Geräten

        n = Bootloader öffnen bei neueren Geräten
           
6. : durian: 

		r = Recovery-Partition löschen

         b = Boot-Partition löschen

         v = Vendor-Partition löschen

         s = System-Partition löschen

         w = Löschen dere Nutzerdaten und des Caches

         a = Löschen Nutzerdaten + Cache, Recovery-, Boot-, Vendor-, System-Partition
           
7. : baumtomate: 

			u = Update einer Zip-Datei
            
			r = Flashen des Recovery-Images
                
			b = Flashen des Boot-Images
                
			v = Flashen des Vendor-Images
                
			s = Flashen des System-Images
                
			a = Flashen des Recovery-, Boot-, Vendor-, System-Images
8. : ***mango*** (Übergeordnet: 8.; 9.; 10.; 11.) 

9. : fingerlimette: 

			h = fastboot help
             
			g = alle Fastboot Variablen

10. : kakadupflaume: 

			u = Bootloader öffnen (11. Zwergbanane (Fastboot))
                   
			l =  Bootloader schließen

11. : zwergbanane: 

				o = Bootloader öffnen bei älteren Geräten
                 n = Bootloader öffnen bei neueren Geräten

12. : kaki: 
			
			r = Recovery-Partition löschen
           	
			b = Boot-Partition löschen
           	
			v = Vendor-Partition löschen
           
			s = System-Partition löschen
           
			w = Löschen dere Nutzerdaten und des Caches
           
			a = Löschen Nutzerdaten + Cache, Recovery-, Boot-, Vendor-, System-Partition

13. : guave: 

			u = Update einer Zip-Datei
            
			r = Flashen des Recovery-Images
            
			b = Flashen des Boot-Images
            
			v = Flashen des Vendor-Images
            
			s = Flashen des System-Images
            
			a = Flashen des Recovery-, Boot-, Vendor-, System-Images
14. : ***zitrone*** (Übergeordnet: 15.; 16.)
15. : preiselbeere: 

		i = beliebigen Datei einen beliebigen Namen zu geben (Mit Dateiendung)

		w = Recovery-, Boot-, Vendor-, System-Image umbenennen 

16. : mandel:

		r = Recovery-Image in recovery.img umbenennen 

		b = Boot-Image in boot.img umbenennen

		v = Vendor-Image in vendor.img umbenennen

		s = System-Image in system.img umbenennen
		
		u = als Update-Zip gedachte Datei in update.zip umbenennen		

16. : tomate: 

---
***Variablen für das umbennen von Dateien***
            
1. : specht: umbennen in update.zip (ADB)

2. : star: umbennen in recovery.img (ADB)

3. : hornvogel: umbennen in boot.img (ADB)

4. : kondor: umbennen in vendor.img (ADB)

5. : flamingo: umbennen in system.img (ADB)

6. : pfau: umbennen in recovery.img (multi) (ADB)

7. : kolibri: umbennen in boot.img (multi) (ADB)

8. : eule: umbennen in vendor.img (multi) (ADB)

9. : tukan: umbennen in system.img (multi) (ADB)

10. : kiwi: umbennen in update.zip (Fastboot)

11. : blauerAra: umbennen in recovery.img (Fastboot)

12. : baldEagle: umbennen in boot.img (Fastboot)

13. : spatz: umbennen in vendor.img (Fastboot)

14. : fasan: umbennen in system.img (Fastboot)

15. : meise: umbennen in recovery.img (multi) (Fastboot)

29. : amsel: umbennen in boot.img (multi) (Fastboot)

30. : waldlaeufer: umbennen in vendor.img (multi) (Fastboot)

31. : fregattvogel: umbennen in system.img (multi) (Fastboot)

32. : walnuss: Alte Datei
33. : haselnuss: in den neuen Name umbennant
34. : cashewnuss: umbennen der Originaldatei in recovery.img
35. : erdnuss: umbennen der Originaldatei in boot.img
36. : macadamianuss: umbennen der Originaldatei in vendor.img
37. : pistazie: umbennen der Originaldatei in system.img
38. : kokosnuss: umbennen der Originaldatei in update.zip


---
---
## Build



## To-Do:
---
---
- auto umbennen von Dateien (eigene Unterfunktion)
- extrahieren von system Bestandteilen
- weitere ADB-Funktionen

## Fehler
Fehlermeldungen / Fehlfunktionen melden an:
Kirschblute.in.c@gmail.com

Ich versuche mich so schnell wie möglich zu kümmern.