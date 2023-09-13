/*
 * Kirschreiherflash
 *
 * (C) Copyright 2023 Elias Mörz
 *
 * GNU GENERAL PUBLIC LICENSE (GPLv3)
 *
 * Komandozeilentool um lästige Arbeiten mit Fastboot automatisch durchzuführen.
 *
 */

#include <stdio.h>
#include <stdlib.h>


/*
To do:

-auto umbennen von Dateien (eigene Unterfunktion)
-extrahieren von system Bestandteilen
-weitere ADB-Funktionen

*/

int main() 
{
  char cherry; //Beginn für mögliche Wiederholung (Hauptfunktion Cherry)
  do 
  {
     printf("!!!Achtung!!!:\n Lesen sie vor dem Start die Readme!\n !!!Achtung!!!:\n Benutzung auf eigene Gefahr!\n !!!Achtung!!!:\n Benennen sie das Image, dass:\n als Recovery-Image gedacht ist: recovery.img\n als Boot-Image gedacht ist: boot.img\n als Vendor-Image gedacht ist: vendor.img\n als System-Image gedacht ist: system.img\n als ein Update gedacht Zip als: update.zip\n Sonst funktioniert dieses Programm nicht.\n Wenn sie das alles beachtet haben, dann:\n Drücken sie 'a' um alle Funktionen starten von der ADB.\n Drücken sie 'f' um alle Funktionen vom Bootloader (Fastboot) zu starten.\n"); 
     scanf(" %c", &cherry); //printf überarbeiten
     
     if (cherry == 'a' || cherry == 'A') //siehe Liste Buchstaben 'a' und 'f'
     {
        printf("!!!Dies ist Unterfunktion 'Erdbeere (strawberry)' !!!\n !!!Achtung!!!:\n Lesen sie vor dem Start die Readme!\n !!!Achtung!!!:\n Benutzung auf eigene Gefahr!\n !!!Achtung!!!:\n Jede Funktionen starten mit der ADB.\n Wenn alles beachtet wurde, dann:\n Drücken sie 'r' wenn sie in das Recovery OS booten wollen.\n Drücken sie 'h' um in den Fastboot-Modus zu booten oder die Fastboothilfe auf zu listen (Litschi/Lychee).\n Drücken sie 'b' um den Bootloader zu öffnen oder schließen (Papaya).\n Drücken sie 'e' um Systemteile zu löschen (Durian).\n Drücken sie 'i' um Image-dateien zu flashen oder eine Zip-datei als Update zu installieren (Baumtomate).\n");
        
        char strawberry;
        scanf(" %c", &strawberry); //boot to recovery (ADB)
        
        if (strawberry == 'r' || strawberry == 'R')
        {
          printf("Neustart in das Recovery OS...\n");
          printf("Verbinden mit der ADB...\n");
          system("adb devices");
          system("adb devices");
        
          printf("Booten des Gerätes in das Recovery OS...");
          system("adb reboot recovery");
        }
        
        else if (strawberry == 'h' || strawberry == 'H') //boot to fastboot (ADB)
        {
            printf("!!!Dies ist Unterfunktion 'Litsch (Lychee)' !!!\n Neustart in den Fastboot-Modus...\n");
        
            printf("Verbinden mit der ADB...\n");
            system("adb devices");
            system("adb devices");
        
            printf("Booten des Gerätes in den Bootloader...\n");
            system("adb reboot bootloader");
        
            printf("Gerät im Fastboot verfügbar:\n");
            system("fastboot devices");
            system("fastboot devices");
        
            printf("Um die Liste aller Fastboot-Befehle zu öffnen 'h' drücken.\n Um die alle Bootloader-Variablen aufzulisten 'g' drücken.\n");
            
            char lychee;
            scanf(" %c", &lychee); //fastboot help aufrufen oder alle Bootloader-Variablen (ADB)
        
            if (lychee == 'h' || lychee == 'H') //fastboot help (ADB)
            {
                printf("Hier ist die Liste aller Fastboot-Befehle:\n");
                system("fastboot help");
            }
            else if (lychee == 'g' || lychee == 'G') //alle Fastboot Variablen (ADB)
            {
                printf("Befehl wird ausgeführt...");
                system("fastboot getvar all");
            }
            else
            {
                printf("Viel Spaß mit Fastboot:)");
            }
        }
            
        else if (strawberry == 'b' || strawberry == 'B') //Bootloader öffnen oder schließen (ADB)
        {
            printf("!!!Dies ist Unterfunktion 'Papaya'!!!\n !!!Achtung!!! Benutzung auf eigene Gefahr!\n !!!Achtung!!!:\n Manche Chipsätze unterstützen diesen Vorgang nicht in dieser Weise.\n Drücken sie 'u' um den Bootloader zu öffnen oder 'l' um den Bootloader zu schließen.\n");
            
            char papaya;
            scanf(" %c", &papaya);
            
            if (papaya == 'u' || papaya == 'U') //Bootloader öffnen (ADB)
            {
                printf("!!!Achtung!!! Benutzung auf eigene Gefahr!\n !!!Achtung!!!:\n Manche Chipsätze unterstützen diesen Vorgang nicht in dieser Weise.\n Es gibt zwei verschiedene Methoden um den Bootloader zu öffnen. Für alte Geräte drücken sie 'o'.\n Für neuere Geräte drücken sie 'n'.\n");
                
                char drachenauge;
                scanf(" %c", &drachenauge); // Bootloader öffnen alt/neu (ADB)
                
                if (drachenauge == 'o' || drachenauge == 'O') // Bootloader öffnen alt (ADB)
                {
                    printf("Starte Vorgang um den Bootloader zu öffnen...\n");
                    printf("Verbinden mit der ADB...\n");
                    system("adb devices");
                    system("adb devices");
        
                    printf("Booten des Gerätes in den Bootloader...\n");
                    system("adb reboot bootloader");
        
                    printf("Gerät im Fastboot verfügbar:\n");
                    system("fastboot devices");
                    system("fastboot devices");
            
                    printf("Bootloader wird geöffnet...\n");
                    system("fastboot flashing unlock");
                  }
                  
                  if (drachenauge == 'n' || drachenauge == 'N') // Bootloader öffnen neu (ADB)
                {
                    printf("Starte Vorgang um den Bootloader zu öffnen...\n");
                    printf("Verbinden mit der ADB...\n");
                    system("adb devices");
                    system("adb devices");
        
                    printf("Booten des Gerätes in den Bootloader...\n");
                    system("adb reboot bootloader");
        
                    printf("Gerät im Fastboot verfügbar:\n");
                    system("fastboot devices");
                    system("fastboot devices");
            
                    printf("Bootloader wird geöffnet...\n");
                    system("fastboot oem unlock");
                  }
                  
                  else 
                  {
                      printf("Das hier hat keine Funktion!!!\n");
                  }
              }
              
              else if (papaya == 'l' || papaya == 'L') //Bootloader schließen (ADB)
              {
                  printf("!!!Achtung!!! Benutzung auf eigene Gefahr!\n !!!Achtung!!!:\n Manche Chipsätze unterstützen diesen Vorgang nicht in dieser Weise.\n Starte Vorgang um den Bootloader zu schließen...\n");
        
                  printf("Verbinden mit der ADB...\n");
                  system("adb devices");
                  system("adb devices");
        
                  printf("Booten des Gerätes in den Bootloader...\n");
                  system("adb reboot bootloader");
        
                  printf("Gerät im Fastboot verfügbar:\n");
                  system("fastboot devices");
                  system("fastboot devices");
            
                  printf("Bootloader wird geschlossen...\n");
                  system("fastboot flashing lock");
                }
                
                else
                {
                    printf("Und was jetzt?\n");
                }
        }
        
        else if (strawberry == 'e' || strawberry == 'E') //Löschen von Systemteilen ohne neuen flash (ADB)
        {
            printf("!!!Dies ist Unterfunktion 'Durian'!!!\n !!!Achtung!!! Benutzung auf eigene Gefahr!\n Achten sie darauf das nur bestimmte Partitionen gelöscht werden!\n Es werden keine neuen Image-Dateien geflasht!\n Um die Rcovery-Partition zu löschen drücken sie 'r'.\n Um die Boot-Partition zu löschen drücken sie 'b'.\n Um die Vendor-Partition zu löschen drücken sie 'v'.\n Um die System-Partition zu löschen drücken sie 's'.\n Um die Recovery-, Boot-, Vendor-, System-Partition zu löschen drücken sie 'a'.\n");
            char durian;
            scanf(" %c", &durian);
            
            if (durian == 'r' || durian == 'R') //Recovery-Partition löschen (ADB)
            {
                printf("Recovery-Partition wird gelöscht...\n");
                printf("Verbinden mit der ADB...\n");
                system("adb devices");
                system("adb devices");
                
                printf("Booten des Gerätes in den Bootloader...\n");
                system("adb reboot bootloader");
                
                printf("Gerät im Fastboot verfügbar:\n");
                system("fastboot devices");
                system("fastboot devices");
                
                printf("Löschen der Recovery-Partition...\n");
                system("fastboot erase recovery");
                printf("Recovery-Partition gelöscht!\n");
            }
            
            else if (durian == 'b' || durian == 'B') //Boot-Partition löschen (ADB)
            {
                printf("Boot-Partition wird gelöscht...\n");
                printf("Verbinden mit der ADB...\n");
                system("adb devices");
                system("adb devices");
                
                printf("Booten des Gerätes in den Bootloader...\n");
                system("adb reboot bootloader");
                
                printf("Gerät im Fastboot verfügbar:\n");
                system("fastboot devices");
                system("fastboot devices");
                
                printf("Löschen der Boot-Partition...\n");
                system("fastboot erase boot");
                printf("Boot-Partition gelöscht!\n");
            }
            
            else if (durian == 'v' || durian == 'V') //Vendor-Partition löschen (ADB)
            {
                printf("Vendor-Partition wird gelöscht...\n");
                printf("Verbinden mit der ADB...\n");
                system("adb devices");
                system("adb devices");
                
                printf("Booten des Gerätes in den Bootloader...\n");
                system("adb reboot bootloader");
                
                printf("Gerät im Fastboot verfügbar:\n");
                system("fastboot devices");
                system("fastboot devices");
                
                printf("Löschen der Vendor-Partition...\n");
                system("fastboot erase Vendor");
                printf("Vendor-Partition gelöscht!\n");
            }
            
            else if (durian == 's' || durian == 'S') //System-Partiton löschen (ADB)
            {
                printf("System-Partition wird gelöscht...\n");
                printf("Verbinden mit der ADB...\n");
                system("adb devices");
                system("adb devices");
                
                printf("Booten des Gerätes in den Bootloader...\n");
                system("adb reboot bootloader");
                
                printf("Gerät im Fastboot verfügbar:\n");
                system("fastboot devices");
                system("fastboot devices");
                
                printf("Löschen der System-Partition...\n");
                system("fastboot erase system");
                printf("System-Partition gelöscht!\n");
            }
            
            else if (durian == 'w' || durian == 'W') //Löschen der Nutzerdaten und des Caches (ADB)
            {
                printf("!!!Achtung!!!:\n Manche Chipsätze unterstützen diesen Vorgang nicht in dieser Weise.\n Lösche alle Nutzerdaten und den Cache...\n");
        
                printf("Verbinden mit der ADB...\n");
                system("adb devices");
                system("adb devices");
        
                printf("Booten des Gerätes in den Bootloader...\n");
                system("adb reboot bootloader");
        
                printf("Gerät im Fastboot verfügbar:\n");
                system("fastboot devices");
                system("fastboot devices");
            
                printf("Löschen der Nutzerdaten und des Cachs...");
                system("fastboot erase -w");
            }
        
            
            else if (durian == 'a' || durian == 'A') //Löschen Nutzerdaten + Cache, Recovery-, Boot-, Vendor-, System-Prtition (ADB)
            {
                printf("!!!Achtung!!!:\n Manche Chipsätze unterstützen diesen Vorgang nicht in dieser Weise.\n Nutzerdaten, Cache, Recovery-, Boot-, Vendor-, System-Partition werden gelöscht...\n");
                printf("Verbinden mit der ADB...\n");
                system("adb devices");
                system("adb devices");
                
                printf("Booten des Gerätes in den Bootloader...\n");
                system("adb reboot bootloader");
                
                printf("Gerät im Fastboot verfügbar:\n");
                system("fastboot devices");
                system("fastboot devices");
                
                printf("Löschen der Nutzerdaten, Cache, Recovery-, Boot-, Vendor-, System-Partition...\n");
                system("fastboot erase -w");
                system("fastboot erase recovery");
                system("fastboot erase boot");
                system("fastboot erase vendor");
                system("fastboot erase system");
                printf("Nutzerdaten, Cache, Recovery-, Boot-, Vendor-, System-Partition gelöscht!\n");
            
            }
            
            else 
            {
                printf("Ich weiß nicht was du willst!\n");
            }
        }   
        else if (strawberry == 'i' || strawberry == 'I')
        {
            printf("!!!Dies ist Unterfunktion 'Baumtomate'!!!\n !!!Achtung!!! Benutzung auf eigene Gefahr!\n !!!Achtung!!!:\n Es werden vorher die Partitionen überschrieben!\n Um ein Update als Zip-Datei durchzuführen drücken sie 'u'\n Sie haben die Wahl welches Image sie flashen wollen:\n Drücken sie 'r' um das Recovery-Image zu flashen.\n Drücken sie 'b' um das Boot-Image zu flashen.\n Drücken sie 'v' um das Vendor-Image zu flashen.\n Drücken sie 's' um das System-Image zu flashen.\n"); //Flashen von Image-Dateien. Update via Zip-Datei (ADB)
            
            char baumtomate;
            scanf(" %c", &baumtomate);
            
            if (baumtomate == 'u' || baumtomate == 'U') //Update einer Zip-Datei (ADB)
            {
                printf("Achten sie darauf, dass das ihre zip-Datei im selben Verzeichnis wie dieser Quellcode und der Bash-Skript!\n Geben sie bitte den Namen der Datei ein die als Update dienen soll:\n");
                
                char specht[255];
                scanf(" %s", specht);
    
                if(rename(specht, "update.zip") == -1)
                {
                    printf("Wieder was falsch! Hier muss der Programmierer ran!\n");
                }
                else
                {
                    printf("Datei umbenannt!\n");
                }
                
                printf("Lehnen sie sich zurück:\n Update wird durchgeführt...\n"); 
                
        
                printf("Verbinden mit der ADB...\n");
                system("adb devices");
                system("adb devices");
        
                printf("Booten des Gerätes in den Bootloader...\n");
                system("adb reboot bootloader");
        
                printf("Gerät im Fastboot verfügbar:\n");
                system("fastboot devices");
                system("fastboot devices");
            
                printf("Flashen der zip-Datei...");
                system("fastboot update update.zip");
                printf("Update durchgeführt.");
            }
        
            
            else if (baumtomate == 'r' || baumtomate == 'R') //Flashen des Recovery-Images (ADB)
            {
                printf("Geben sie den Namen des künftigen Recovery-Images ein (Dateiname.img):\n");
                
                char star[255]; //umbennen der Originaldatei in recovery.img (ADB)
                scanf(" %s", star);
    
                if(rename(star, "recovery.img") == -1)
                {
                    printf("Wieder was falsch! Hier muss der Programmierer ran!\n");
                }
                else
                {
                    printf("Datei umbenannt!\n");
                }
                
                printf("Lehnen sie sich zurück:\n Vorgang zum Flashen des Recovery-Images wird gestartet...\n");
        
                printf("Verbinden mit der ADB...\n");
                system("adb devices");
                system("adb devices");
        
                printf("Booten des Gerätes in den Bootloader...\n");
                system("adb reboot bootloader");
        
                printf("Gerät im Fastboot verfügbar:\n");
                system("fastboot devices");
                system("fastboot devices");
        
                printf("Löschen des alten Recovery-Images...\n");
                system("fastboot erase recovery");
        
                printf("Flashen des neuen Recovery-Images...\n");
                system("fastboot flash recovery recovery.img");
                printf("Recovery-Image wurde geflasht!\n");    
            }
    
            else if (baumtomate == 'b' || baumtomate == 'B') //Flashen des Boot-Images (ADB)
            {
                printf("Geben sie den Namen des künftigen Boot-Images ein (Dateiname.img):\n");
                
                char hornvogel[255]; //umbennen der Originaldatei in boot.img (ADB)
                scanf(" %s", hornvogel);
    
                if(rename(hornvogel, "boot.img") == -1)
                {
                    printf("Wieder was falsch! Hier muss der Programmierer ran!\n");
                }
                else
                {
                    printf("Datei umbenannt!\n");
                }
                
                printf("Lehnen sie sich zurück:\n Vorgang zum Flashen des Boot-Images wird gestartet...\n");
        
                printf("Verbinden mit der ADB...\n");
                system("adb devices");
                system("adb devices");
        
                printf("Booten des Gerätes in den Bootloader...\n");
                system("adb reboot bootloader");
        
                printf("Gerät im Fastboot verfügbar:\n");
                system("fastboot devices");
                system("fastboot devices");
                
                printf("Löschen des alten Boot-Images...\n");
                system("fastboot erase boot");
        
                printf("Flashen des neuen Boot-Images...\n");
                system("fastboot flash boot boot.img");
                printf("Boot-Image wurde geflasht!\n"); 
            }
    
            else if (baumtomate == 'v' || baumtomate == 'V') //Flashen des Vendor-Images (ADB)
            {        
                printf("Geben sie den Namen des künftigen Vendor-Images ein (Dateiname.img):\n");
                
                char kondor[255]; // umbennen der Originaaldatei in vendor.img
                scanf(" %s", kondor);
    
                if(rename(kondor, "vendor.img") == -1)
                {
                    printf("Wieder was falsch! Hier muss der Programmierer ran!\n");
                }
                else
                {
                    printf("Datei umbenannt!\n");
                }
                
                printf("Lehnen sie sich zurück:\n Vorgang zum Flashen des Vendor-Images wird gestartet...\n");
        
                printf("Verbinden mit der ADB...\n");
                system("adb devices");
                system("adb devices");
        
                printf("Booten des Gerätes in den Bootloader...\n");
                system("adb reboot bootloader");
        
                printf("Gerät im Fastboot verfügbar:\n");
                system("fastboot devices");
                system("fastboot devices");
        
                printf("Löschen des alten Vendor-Images...\n");
                system("fastboot erase vendor");
        
                printf("Flashen des neuen Vendor-Images...\n");
                system("fastboot flash vendor vendor.img");
                printf("Vendor-Image wurde geflasht!\n");    
            }
    
            else if (baumtomate == 's' || baumtomate == 'S') //Flashen des System-Images (ADB)
            {  
                printf("Geben sie den Namen des künftigen System-Images ein (Dateiname.img):\n");
                
                char flamingo[255]; //umbennen der Originaldatei in system.img (ADB)
                scanf(" %s", flamingo);
    
                if(rename(flamingo, "system.img") == -1)
                {
                    printf("Wieder was falsch! Hier muss der Programmierer ran!\n");
                }
                else
                {
                    printf("Datei umbenannt!\n");
                }
        
                printf("Lehnen sie sich zurück:\n Vorgang zum Flashen des System-Images wird gestartet...\n");
                
                printf("Verbinden mit der ADB...\n");
                system("adb devices");
                system("adb devices");
          
                printf("Booten des Gerätes in den Bootloader...\n");
                system("adb reboot bootloader");
        
                printf("Gerät im Fastboot verfügbar:\n");
                system("fastboot devices");
                system("fastboot devices");
          
                printf("Löschen der alten System-Partition...\n");
                system("fastboot erase system");
        
                printf("Flashen des neuen System-Images\n");
                system("fastboot flash system system.img");
                printf("System-Image wurde geflasht!\n");  
            }
        
            else if (baumtomate == 'a' || baumtomate == 'A') //Flashen des Recovery-, Boot-, Vendor-, System-Images (ADB)
            {
                printf("Geben sie den Namen des künftigen Recovery-Images ein (Dateiname.img):\n");
                
                char pfau[255]; //umbennen der Originaldatei in recovery.img (ADB)
                scanf(" %s", pfau);
    
                if(rename(pfau, "recovery.img") == -1)
                {
                    printf("Wieder was falsch! Hier muss der Programmierer ran!\n");
                }
                else
                {
                    printf("Datei umbenannt!\n");
                }
                
                printf("Geben sie den Namen des künftigen Boot-Images ein (Dateiname.img):\n");
                
                char kolibri[255]; //umbennen der Originaldatei in boot.img (ADB)
                scanf(" %s", kolibri);
    
                if(rename(kolibri, "boot.img") == -1)
                {
                    printf("Wieder was falsch! Hier muss der Programmierer ran!\n");
                }
                else
                {
                    printf("Datei umbenannt!\n");
                }
                
                printf("Geben sie den Namen des künftigen Vendor-Images ein (Dateiname.img):\n");
                
                char eule[255]; //umbennen der Originaldatei in vendor.img (ADB)
                scanf(" %s", eule);
    
                if(rename(eule, "vendor.img") == -1)
                {
                    printf("Wieder was falsch! Hier muss der Programmierer ran!\n");
                }
                else
                {
                    printf("Datei umbenannt!\n");
                }
                
                printf("Geben sie den Namen des künftigen System-Images ein (Dateiname.img):\n");
                
                char tukan[255]; //umbennen der Originaldatei in system.img (ADB)
                scanf(" %s", tukan);
    
                if(rename(tukan, "system.img") == -1)
                {
                    printf("Wieder was falsch! Hier muss der Programmierer ran!\n");
                }
                else
                {
                    printf("Datei umbenannt!\n");
                }
                
                printf("Lehnen sie sich zurück:\n Vorgang zum Flashen des Recovery-, Boot-, Vendor-, System-Images wird gestartet...\n");
        
                printf("Verbinden mit der ADB...\n");
                system("adb devices");
                system("adb devices");
        
                printf("Booten des Gerätes in den Bootloader...\n");
                system("adb reboot bootloader");
        
                printf("Gerät im Fastboot verfügbar:\n");
                system("fastboot devices");
                system("fastboot devices");
      
                system("fastboot erase vendor");
                system("fastboot erase system");
        
                printf("Flashen der neuen Recovery-, Boot-, Vendor-, System-Images...\n");
                system("fastboot erase recovery");
                system("fastboot flash recovery recovery.img");
                system("fastboot reboot bootloader");
                system("fastboot devices");
                system("fastboot erase boot");
                system("fastboot flash boot boot.img");
                system("fastboot erase vendor");
                system("fastboot flash vendor vendor.img");
                system("fastboot erase system");
                system("fastboot flash system system.img");
                printf("Flash des Recovery-, Boot-, Vendor-, System-Images durchgeführt!\n");
            }
            
            else
            {
                printf("Wie jetzt weiter?\n");
            }
        }
        
        else 
        {
            printf("Entweder sie haben etwas nicht beachtet oder irgendetwas läuft schief. Auf jedenfall: der Programmierer ist Schuld:)\n");
        }
    }
    
    else if (cherry == 'f' || cherry == 'F')
    {
        
        printf("!!!Dies ist Unterfunktion 'Mango' !!!\n !!!Achtung!!!:\n Lesen sie vor dem Start die Readme!\n !!!Achtung!!!:\n Benutzung auf eigene Gefahr!\n !!!Achtung!!!:\n Jede Funktionen starten mit der ADB.\n Wenn alles beachtet wurde, dann:\n Drücken sie 'r' wenn sie in das Recovery OS booten wollen.\n Drücken sie 'h' um in den Fastboot-Modus zu booten oder die Fastboothilfe auf zu listen (Fingerlimette).\n Drücken sie 'b' um den Bootloader zu öffnen oder schließen (Kakaduplaume).\n Drücken sie 'e' um Systemteile zu löschen (Kaki).\n Drücken sie 'i' um Image-dateien zu flashen oder eine Zip-datei als Update zu installieren (Guave).\n");
        
        char mango;
        scanf(" %c", &mango); //boot to recovery (Fastboot)
        
        if (mango == 'r' || mango == 'R')
        {
          printf("Neustart in das Recovery OS...\n");
          system("fastboot reboot recovery");
        }
        
        else if (mango == 'h' || mango == 'H') //fastboot Modus (Fastboot)
        {
            printf("!!!Dies ist Unterfunktion 'Fingerlimette' !!!\n");
            
            printf("Gerät im Fastboot-Modus verfügbar:");
            system("fastboot devices");
            system("fastboot devices");
        
            printf("Um die Liste aller Fastboot-Befehle zu öffnen 'h' drücken.\n Um die alle Bootloader-Variablen aufzulisten 'g' drücken.\n");
            
            char fingerlimette;
            scanf(" %c", &fingerlimette); //fastboot help aufrufen oder alle Bootloader-Variablen (Fastboot)
        
            if (fingerlimette == 'h' || fingerlimette == 'H') //fastboot help (Fastboot)
            {
                printf("Hier ist die Liste aller Fastboot-Befehle:\n");
                system("fastboot help");
            }
            
             else if (fingerlimette == 'g' || fingerlimette == 'G') //alle Fastboot Variablen (Fastboot)
            {
                printf("Befehl wird ausgeführt...");
                system("fastboot getvar all");
            }
            else
            {
                printf("Viel Spaß mit Fastboot:)");
            }
        }
            
        else if (mango == 'b' || mango == 'B') //Bootloader öffnen oder schließen (Fastboot)
        {
            printf("!!!Dies ist Unterfunktion 'Kakaduplaume'!!!\n !!!Achtung!!! Benutzung auf eigene Gefahr!\n !!!Achtung!!!:\n Manche Chipsätze unterstützen diesen Vorgang nicht in dieser Weise.\n Drücken sie 'u' um den Bootloader zu öffnen oder 'l' um den Bootloader zu schließen.\n");
            
            char kakadupflaume;
            scanf(" %c", &kakadupflaume);
            
            if (kakadupflaume == 'u' || kakadupflaume == 'U') //Bootloader öffnen (Fastboot)
            {
                printf("!!!Achtung!!! Benutzung auf eigene Gefahr!\n !!!Achtung!!!:\n Manche Chipsätze unterstützen diesen Vorgang nicht in dieser Weise.\n Es gibt zwei verschiedene Methoden um den Bootloader zu öffnen. Für alte Geräte drücken sie 'o'.\n Für neuere Geräte drücken sie 'n'.\n");
                
                char zwergbanane;
                scanf(" %c", &zwergbanane); // Bootloader öffnen alt/neu (Fastboot)
                
                
                if (zwergbanane == 'o' || zwergbanane == 'O') // Bootloader öffnen alt (Fastboot)
                {
                    printf("Starte Vorgang um den Bootloader zu öffnen...\n");
                    printf("Gerät im Fastboot verfügbar:\n");
                    system("fastboot devices");
                    system("fastboot devices");
            
                    printf("Bootloader wird geöffnet...\n");
                    system("fastboot flashing unlock");
                  }
                  
                  if (zwergbanane == 'n' || zwergbanane == 'N') // Bootloader öffnen neu (Fastboot)
                {
                    printf("Starte Vorgang um den Bootloader zu öffnen...\n");
                    printf("Gerät im Fastboot verfügbar:\n");
                    system("fastboot devices");
                    system("fastboot devices");
            
                    printf("Bootloader wird geöffnet...\n");
                    system("fastboot oem unlock");
                  }
              }
              else if (kakadupflaume == 'l' || kakadupflaume == 'L') //Bootloader schließen (Fastboot)
              {
                  printf("!!!Achtung!!! Benutzung auf eigene Gefahr!\n !!!Achtung!!!:\n Manche Chipsätze unterstützen diesen Vorgang nicht in dieser Weise.\n Starte Vorgang um den Bootloader zu schließen...\n");
        
                  printf("Gerät im Fastboot verfügbar:\n");
                  system("fastboot devices");
                  system("fastboot devices");
            
                  printf("Bootloader wird geschlossen...\n");
                  system("fastboot flashing lock");
                }
                
                else
                {
                    printf("Und was jetzt?\n");
                }
        }
        
        else if (mango == 'e' || mango == 'E') //Löschen von Systemteilen ohne neuen Flash (Fastboot)
        {
            printf("!!!Dies ist Unterfunktion 'Kaki'!!!\n !!!Achtung!!! Benutzung auf eigene Gefahr!\n Achten sie darauf das nur bestimmte Partitionen gelöscht werden!\n Es werden keine neuen Image-Dateien geflasht!\n Um die Rcovery-Partition zu löschen drücken sie 'r'.\n Um die Boot-Partition zu löschen drücken sie 'b'.\n Um die Vendor-Partition zu löschen drücken sie 'v'.\n Um die System-Partition zu löschen drücken sie 's'.\n Um die Recovery-, Boot-, Vendor-, System-Partition zu löschen drücken sie 'a'.\n");
            
            char kaki;
            scanf(" %c", &kaki);
            
            if (kaki == 'r' || kaki == 'R') //Recovery-Partition löschen (Fastboot)
            {
                printf("Recovery-Partition wird gelöscht...\n");
                printf("Gerät im Fastboot verfügbar:\n");
                system("fastboot devices");
                system("fastboot devices");
                
                printf("Löschen der Recovery-Partition...\n");
                system("fastboot erase recovery");
                printf("Recovery-Partition gelöscht!\n");
            }
            else if (kaki == 'b' || kaki == 'B') //Boot-Partition löschen (Fastboot)
            {
                printf("Boot-Partition wird gelöscht...\n");
                printf("Gerät im Fastboot verfügbar:\n");
                system("fastboot devices");
                system("fastboot devices");
                
                printf("Löschen der Boot-Partition...\n");
                system("fastboot erase boot");
                printf("Boot-Partition gelöscht!\n");
            }
            
            else if (kaki == 'v' || kaki == 'V') //Vendor-Partition löschen (Fastboot)
            {
                printf("Vendor-Partition wird gelöscht...\n");
                printf("Gerät im Fastboot verfügbar:\n");
                system("fastboot devices");
                system("fastboot devices");
                
                printf("Löschen der Vendor-Partition...\n");
                system("fastboot erase Vendor");
                printf("Vendor-Partition gelöscht!\n");
            }
            
            else if (kaki == 's' || kaki == 'S') //System-Partiton löschen (Fastboot)
            {
                printf("System-Partition wird gelöscht...\n");
                printf("Gerät im Fastboot verfügbar:\n");
                system("fastboot devices");
                system("fastboot devices");
                
                printf("Löschen der System-Partition...\n");
                system("fastboot erase system");
                printf("System-Partition gelöscht!\n");
            }
            
            else if (kaki == 'w' || kaki == 'W') //Löschen der Nutzerdaten und des Caches (Fastboot)
            {
                printf("!!!Achtung!!!:\n Manche Chipsätze unterstützen diesen Vorgang nicht in dieser Weise.\n Lösche alle Nutzerdaten und den Cache...\n");
        
                printf("Gerät im Fastboot verfügbar:\n");
                system("fastboot devices");
                system("fastboot devices");
            
                printf("Löschen der Nutzerdaten und des Cachs...");
                system("fastboot erase -w");
            }
            
            else if (kaki == 'a' || kaki == 'A') //Löschen Nutzerdaten + Cache, Recovery-, Boot-, Vendor-, System-Prtition (Fastboot)
            {
                printf("!!!Achtung!!!:\n Manche Chipsätze unterstützen diesen Vorgang nicht in dieser Weise.\n Nutzerdaten, Cache, Recovery-, Boot-, Vendor-, System-Partition werden gelöscht...\n");
                printf("Gerät im Fastboot verfügbar:\n");
                system("fastboot devices");
                system("fastboot devices");
                
                printf("Löschen der Nutzerdaten, Cache, Recovery-, Boot-, Vendor-, System-Partition...\n");
                system("fastboot erase -w");
                system("fastboot erase recovery");
                system("fastboot erase boot");
                system("fastboot erase vendor");
                system("fastboot erase system");
                printf("Nutzerdaten, Cache, Recovery-, Boot-, Vendor-, System-Partition gelöscht!\n");
            
            }
            
            else 
            {
                printf("Ich weiß nicht was du willst!\n");
            }
        }   
        else if (mango == 'i' || mango == 'I')
        {
            printf("!!!Dies ist Unterfunktion 'Guave'!!!\n !!!Achtung!!! Benutzung auf eigene Gefahr!\n !!!Achtung!!!:\n Es werden vorher die Partitionen überschrieben!\n Um ein Update als Zip-Datei durchzuführen drücken sie 'u'\n Sie haben die Wahl welches Image sie flashen wollen:\n Drücken sie 'r' um das Recovery-Image zu flashen.\n Drücken sie 'b' um das Boot-Image zu flashen.\n Drücken sie 'v' um das Vendor-Image zu flashen.\n Drücken sie 's' um das System-Image zu flashen.\n"); //Flashen von Image-Dateien. Update via Zip-Datei (Fastboot)
            
            char guave;
            scanf(" %c", &guave);
            
            if (guave == 'u' || guave == 'U') //Update einer Zip-Datei (Fastboot)
            {
                printf("Achten sie darauf, dass das ihre zip-Datei im selben Verzeichnis wie dieser Quellcode und der Bash-Skript!\n Geben sie bitte den Namen der Datei ein die als Update dienen soll:\n");
                
                char kiwi[255]; //umbennen der Originaldatei in update.zip (Fastboot)
                scanf(" %s", kiwi);
    
                if(rename(kiwi, "update.zip") == -1)
                {
                    printf("Wieder was falsch! Hier muss der Programmierer ran!\n");
                }
                else
                {
                    printf("Datei umbenannt!\n");
                }
        
        
                printf("Gerät im Fastboot verfügbar:\n");
                system("fastboot devices");
                system("fastboot devices");
            
                printf("Flashen der zip-Datei...");
                system("fastboot update update.zip");
                printf("Update durchgeführt.");
            }
        
            
            else if (guave == 'r' || guave == 'R') //Flashen des Recovery-Images (Fastboot)
            {
                printf("Geben sie den Namen des künftigen Recovery-Images ein (Dateiname.img):\n");
                
                char blauerAra[255]; //umbennen der Originaldatei in recovery.img (Fastboot)
                scanf(" %s", blauerAra);
    
                if(rename(blauerAra, "recovery.img") == -1)
                {
                    printf("Wieder was falsch! Hier muss der Programmierer ran!\n");
                }
                else
                {
                    printf("Datei umbenannt!\n");
                }
                
                printf("Lehnen sie sich zurück:\n Vorgang zum Flashen des Recovery-Images wird gestartet...\n");
                
                printf("Gerät im Fastboot verfügbar:\n");
                system("fastboot devices");
                system("fastboot devices");
        
                printf("Löschen des alten Recovery-Images...\n");
                system("fastboot erase recovery");
        
                printf("Flashen des neuen Recovery-Images...\n");
                system("fastboot flash recovery recovery.img");
                printf("Recovery-Image wurde geflasht!\n");    
            }
            
            else if (guave == 'b' || guave == 'B') //Flashen des Boot-Images (Fastboot)
            {
                printf("Geben sie den Namen des künftigen Boot-Images ein (Dateiname.img):\n");
                
                char baldEagle[255]; //umbennen der Originaldatei in boot.img (Fastboot)
                scanf(" %s", baldEagle);
    
                if(rename(baldEagle, "boot.img") == -1)
                {
                    printf("Wieder was falsch! Hier muss der Programmierer ran!\n");
                }
                else
                {
                    printf("Datei umbenannt!\n");
                }
                
                printf("Lehnen sie sich zurück:\n Vorgang zum Flashen des Boot-Images wird gestartet...\n");
        
                printf("Gerät im Fastboot verfügbar:\n");
                system("fastboot devices");
                system("fastboot devices");
                
                printf("Löschen des alten Boot-Images...\n");
                system("fastboot erase boot");
        
                printf("Flashen des neuen Boot-Images...\n");
                system("fastboot flash boot boot.img");
                printf("Boot-Image wurde geflasht!\n"); 
            }
    
            else if (guave == 'v' || guave == 'V') //Flashen des Vendor-Images (Fastboot)
            {        
                printf("Geben sie den Namen des künftigen Vendor-Images ein (Dateiname.img):\n");
                
                char spatz[255]; //umbennen der Originaldatei in vendor.img (Fastboot)
                scanf(" %s", spatz);
    
                if(rename(spatz, "vendor.img") == -1)
                {
                    printf("Wieder was falsch! Hier muss der Programmierer ran!\n");
                }
                else
                {
                    printf("Datei umbenannt!\n");
                }
                
                printf("Lehnen sie sich zurück:\n Vorgang zum Flashen des Vendor-Images wird gestartet...\n");
        
                printf("Gerät im Fastboot verfügbar:\n");
                system("fastboot devices");
                system("fastboot devices");
        
                printf("Löschen des alten Vendor-Images...\n");
                system("fastboot erase vendor");
        
                printf("Flashen des neuen Vendor-Images...\n");
                system("fastboot flash vendor vendor.img");
                printf("Vendor-Image wurde geflasht!\n");    
            }
            
             else if (guave == 's' || guave == 'S') //Flashen des System-Images (Fastboot)
            {  
                printf("Geben sie den Namen des künftigen Recovery-Images ein (Dateiname.img):\n");
                
                char fasan[255]; //umbennen der Originaldatei in system.img (Fastboot)
                scanf(" %s", fasan);
    
                if(rename(fasan, "system.img") == -1)
                {
                    printf("Wieder was falsch! Hier muss der Programmierer ran!\n");
                }
                else
                {
                    printf("Datei umbenannt!\n");
                }
                
                printf("Lehnen sie sich zurück:\n Vorgang zum Flashen des Recovery-Images wird gestartet...\n");
        
                printf("Gerät im Fastboot verfügbar:\n");
                system("fastboot devices");
                system("fastboot devices");
          
                printf("Löschen der alten System-Partition...\n");
                system("fastboot erase system");
        
                printf("Flashen des neuen System-Images\n");
                system("fastboot flash system system.img");
                printf("System-Image wurde geflasht!\n");  
            }
        
            else if (guave == 'a' || guave == 'A') //Flashen des Recovery-, Boot-, Vendor-, System-Images (Fastboot)
            {
                printf("Geben sie den Namen des künftigen Boot-Images ein (Dateiname.img):\n");
                
                char meise[255];//umbennen der Originaldatei in recovery.img (Fastboot)
                scanf(" %s", meise);
    
                if(rename(meise, "recovery.img") == -1)
                {
                    printf("Wieder was falsch! Hier muss der Programmierer ran!\n");
                }
                else
                {
                    printf("Datei umbenannt!\n");
                }
                
                char amsel[255]; //umbennen der Originaldatei in boot.img (Fastboot)
                scanf(" %s", amsel);
    
                if(rename(amsel, "boot.img") == -1)
                {
                    printf("Wieder was falsch! Hier muss der Programmierer ran!\n");
                }
                else
                {
                    printf("Datei umbenannt!\n");
                }
                
                printf("Geben sie den Namen des künftigen Vendor-Images ein (Dateiname.img):\n");
                
                char waldlaeufer[255]; //umbennen der Originaldatei in vendor.img (Fastboot)
                scanf(" %s", waldlaeufer);
    
                if(rename(waldlaeufer, "vendor.img") == -1)
                {
                    printf("Wieder was falsch! Hier muss der Programmierer ran!\n");
                }
                else
                {
                    printf("Datei umbenannt!\n");
                }
                
                printf("Geben sie den Namen des künftigen System-Images ein (Dateiname.img):\n");
                
                char fregattvogel[255]; //umbenne der Originaldatei in system.img (Fastboot)
                scanf(" %s", fregattvogel);
    
                if(rename(fregattvogel, "system.img") == -1)
                {
                    printf("Wieder was falsch! Hier muss der Programmierer ran!\n");
                }
                else
                {
                    printf("Datei umbenannt!\n");
                }
                
                printf("Lehnen sie sich zurück:\n Vorgang zum Flashen des Recovery-, Boot-, Vendor-, System-Images wird gestartet...\n");
        
                printf("Gerät im Fastboot verfügbar:\n");
                system("fastboot devices");
                system("fastboot devices");
      
                system("fastboot erase vendor");
                system("fastboot erase system");
        
                printf("Flashen der neuen Recovery-, Boot-, Vendor-, System-Images...\n");
                system("fastboot erase recovery");
                system("fastboot flash recovery recovery.img");
                system("fastboot reboot bootloader");
                system("fastboot devices");
                system("fastboot erase boot");
                system("fastboot flash boot boot.img");
                system("fastboot erase vendor");
                system("fastboot flash vendor vendor.img");
                system("fastboot erase system");
                system("fastboot flash system system.img");
                printf("Flash des Recovery-, Boot-, Vendor-, System-Images durchgeführt!\n");
            }
            
            else
            {
                printf("Wie jetzt weiter?\n");
            }
        }
        
        else 
        {
            printf("Entweder sie haben etwas nicht beachtet oder irgendetwas läuft schief. Auf jedenfall: der Programmierer ist Schuld:)\n");
        }
        
        printf("Möchten sie das Programm erneut ausführen? (j/n): ");
        scanf(" %c", &cherry);
  } 

    return 0;
    
} while (cherry == 'j' || cherry == 'J');

}
