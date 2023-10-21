/*
 *-------------------------------------------*
 *          Fastbootwizard                   *
 *-------------------------------------------*
 *  GNU GENERAL PUBLIC LICENSE (GPLv3)       *
 *-------------------------------------------*
 *                                           *
 *  Komandozeilentool um lästige Arbeiten    *
 * mit Fastboot automatisch durchzuführen.   *
 *                                           *
 *-------------------------------------------*
 *      (C) Copyright 2023 Elias Mörz   
 *
 */

/*
 *--------------*
 * TO-DO:       *
 *--------------*
 *
 * - Überprüfen umbenennen von Dateien
 * - flashen Boot/Vendor-Image zusätzlich für a/b-partitionierte Geräte
 * - Englische version erstellen
 * - Windows-Version erstellen
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/utsname.h>

// Funktion zur Installation von adb und fastboot auf Ubuntu/Debian
void installAdbAndFastbootDebian() 
{
    system("sudo apt-get update");
    system("sudo apt-get install android-tools-adb android-tools-fastboot");
}

// Funktion zur Installation von adb und fastboot auf Fedora
void installAdbAndFastbootFedora() 
{
    system("sudo dnf install android-tools");
}

// Funktion zur Installation von adb und fastboot auf Arch Linux
void installAdbAndFastbootArch() 
{
    system("sudo pacman -S android-tools");
}

// Funktion zur Installation von adb und fastboot auf openSUSE
void installAdbAndFastbootOpenSUSE() 
{
    system("sudo zypper install android-tools");
}

// Funktion zur Erkennung der Linux-Distribution
const char* getLinuxDistribution() 
{
    FILE *fp;
    char buffer[128];
    
    // Überprüfen, ob es sich um Ubuntu/Debian handelt
    if ((fp = popen("lsb_release -is", "r")) != NULL) 
    {
        if (fgets(buffer, sizeof(buffer), fp) != NULL) 
        {
            if (strstr(buffer, "Ubuntu") || strstr(buffer, "Debian")) 
            {
                pclose(fp);
                return "Ubuntu/Debian";
            }
        }
        pclose(fp);
    }

    // Überprüfen, ob es sich um Fedora handelt
    if ((fp = popen("cat /etc/redhat-release", "r")) != NULL) 
    {
        if (fgets(buffer, sizeof(buffer), fp) != NULL) 
        {
            if (strstr(buffer, "Fedora")) 
            {
                pclose(fp);
                return "Fedora";
            }
        }
        pclose(fp);
    }

    // Überprüfen, ob es sich um Arch Linux handelt
    if ((fp = popen("cat /etc/os-release | grep -i 'arch linux'", "r")) != NULL) 
    {
        if (fgets(buffer, sizeof(buffer), fp) != NULL) 
        {
            if (strstr(buffer, "Arch Linux")) 
            {
                pclose(fp);
                return "Arch Linux";
            }
        }
        pclose(fp);
    }

    // Überprüfen, ob es sich um openSUSE handelt
    if ((fp = popen("cat /etc/os-release | grep -i 'opensuse'", "r")) != NULL) 
    {
        if (fgets(buffer, sizeof(buffer), fp) != NULL) 
        {
            if (strstr(buffer, "openSUSE")) 
            {
                pclose(fp);
                return "openSUSE";
            }
        }
        pclose(fp);
    }
    
    // Standard: Andere Distribution
    return "Andere Linux-Distribution";
}

int main() 
{
    struct utsname sysinfo;
    
    if (uname(&sysinfo) == -1) 
    {
        perror("uname");
        return 1;
    }

    printf("Betriebssystem: %s\n", sysinfo.sysname);
    printf("Kernel-Version: %s\n", sysinfo.release);

    #ifdef __linux__
        const char *linuxDistribution = getLinuxDistribution();
        printf("Dieses Programm wird auf einem %s-basierten System ausgeführt.\n", linuxDistribution);

        // Installation von adb und fastboot
        if (strcmp(linuxDistribution, "Ubuntu/Debian") == 0) 
        {
            installAdbAndFastbootDebian();
        }
        
        else if (strcmp(linuxDistribution, "Fedora") == 0) 
        {
            installAdbAndFastbootFedora();
        }
        
        else if (strcmp(linuxDistribution, "Arch Linux") == 0) 
        {
            installAdbAndFastbootArch();
        }
        
        else if (strcmp(linuxDistribution, "openSUSE") == 0) 
        {
            installAdbAndFastbootOpenSUSE();
        }
       
    #else
        printf("Das Betriebssystem konnte nicht erkannt werden oder ist nicht unterstützt.\n");
    #endif
    
    char cherry; //Beginn für mögliche Wiederholung (Hauptfunktion Cherry)
    do 
    {
        printf("!!!Achtung!!!:\n Dieses Programm ist nur für Linux getestet!\n !!!Achtung!!!:\n Lesen sie vor dem Start die Readme!\n !!!Achtung!!!:\n Benutzung auf eigene Gefahr!\n Alle Funktionen gehen davon aus, dass sich ihr Gerät im Fastboot-Modus befindet.\n Ausnahme:\n Das umbenennen von Dateien, Boot in Recovery und Fastboot.\n Wenn sie das alles beachtet haben, dann:\n ***Drücken sie 'u' um Dateien umzubenennen ohne andere Aktionen auszuführen.***\n ***Drücken sie 'f' um fortzufahren.***\n"); 
     
        scanf(" %c", &cherry);
     
        if (cherry == 'u' || cherry == 'U') //siehe Liste Buchstaben 'u', 'f'
        {
            char preiselbeere;
            do
            {
                printf("!!!Dies ist Unterfunktion 'Zitrone'!\n Hier werden nur die Dateien umbenannt!\n Drücken sie 'i' um einer beliebigen Datei einen beliebigen Namen zu geben.\n Drücken sie 'w' um .img Dateien in für das Programm ausführbare Dateien umzubennen.\n");
            
                scanf(" %c", &preiselbeere);
            
                if (preiselbeere == 'i' || preiselbeere == 'I') // beliebigen Datei einen beliebigen Namen zu geben
                {
                    printf("Hier können sie beliebigen Datei einen beliebigen Namen zu geben (Mit Dateiendung).\n");
                    
                    char walnuss[100];
                    char haselnuss[100];

                    printf("Geben Sie den Namen der Eingabedatei ein:\n");
                    scanf("%s", walnuss);

                    printf("Geben Sie den neuen Namen für die Datei ein:\n");
                    scanf("%s", haselnuss);

                    if (rename(walnuss, haselnuss) == 0) 
                    {
                        printf("Datei erfolgreich umbenannt.\n");
                    }
        
                    else 
                    {
                        perror("Der Programmierer kann's nicht!\n");
                    }
                }
            
                else if (preiselbeere == 'w' || preiselbeere == 'W')
                {
                    printf("Um das Recovery-Image umzubenennen in recovery.img drücken sie 'r'.\n Um das Boot-Image umzubenennen in boot.img drücken sie 'b'.\n Um das Vendor-Image umzubenennen in vendor.img drücken sie 'v'.\n Um das System-Image umzubenennen in system.img drücken sie 's'.\n");
                
                    char mandel;
                    scanf(" %c", &mandel);
                
                    if (mandel == 'r' || mandel == 'R')
                    {
                        printf("Geben sie den Namen des künftigen Recovery-Images ein (Dateiname.img):\n");
                
                        char cashewnuss[255]; //umbennen der Originaldatei in recovery.img
                        scanf(" %s", cashewnuss);
    
                        if(rename(cashewnuss, "recovery.img") == -1)
                        {
                            printf("Wieder was falsch! Hier muss der Programmierer ran!\n");
                        }
                        
                        else
                        {
                            printf("Datei umbenannt!\n");
                        }
                    }
                
                    else if (mandel == 'b' || mandel == 'B')
                    {
                        printf("Geben sie den Namen des künftigen Boot-Images ein (Dateiname.img):\n");
                
                        char erdnuss[255]; //umbennen der Originaldatei in boot.img
                        scanf(" %s", erdnuss);
    
                        if(rename(erdnuss, "boot.img") == -1)
                        {
                            printf("Wieder was falsch! Hier muss der Programmierer ran!\n");
                        }
                        else
                        {
                            printf("Datei umbenannt!\n");
                        }
                    }
                
                    else if (mandel == 'v' || mandel == 'V')
                    {
                        printf("Geben sie den Namen des künftigen Vendor-Images ein (Dateiname.img):\n");
                
                        char macadamianuss[255]; //umbennen der Originaldatei in vendor.img
                        scanf(" %s", macadamianuss);
    
                        if(rename(macadamianuss, "vendor.img") == -1)
                        {
                            printf("Wieder was falsch! Hier muss der Programmierer ran!\n");
                        }
                    
                        else
                        {
                            printf("Datei umbenannt!\n");
                        }
                    }
                
                    else if (mandel == 's' || mandel == 'S')
                    {
                        printf("Geben sie den Namen des künftigen System-Images ein (Dateiname.img):\n");
                
                        char pistazie[255]; //umbennen der Originaldatei in system.img
                        scanf(" %s", pistazie);
    
                        if(rename(pistazie, "system.img") == -1)
                        {
                            printf("Wieder was falsch! Hier muss der Programmierer ran!\n");
                        }
                    
                        else
                        {
                            printf("Datei umbenannt!\n");
                        }
                    }
                
                    if (mandel == 'u' || mandel == 'U')
                    {
                        printf("Geben sie den Namen des künftigen Update.zips ein (Dateiname.zip):\n");
                
                        char kokosnuss[255]; //umbennen der Originaldatei in update.zip
                        scanf(" %s", kokosnuss);
    
                        if(rename(kokosnuss, "update.zip") == -1)
                        {
                            printf("Wieder was falsch! Hier muss der Programmierer ran!\n");
                        }
                    
                        else
                        {
                            printf("Datei umbenannt!\n");
                        }
                    }
                
                    else 
                    {
                        printf("Verdammt! Es ist die Schuld des Programmierers!\n");
                    }
                }
            
                printf("Möchten sie das Programm erneut ausführen? (y/n): ");
                scanf(" %c", &preiselbeere);
            
            } while (preiselbeere == 'y' || preiselbeere == 'Y');          
        }
     
        else if (cherry == 'f' || cherry == 'F') //siehe Liste Buchstaben 'u', 'a' und 'f'
        {
            char strawberry;
            do
            {
                printf("!Dies ist Unterfunktion 'Erdbeere (strawberry)'!\n !!!Achtung!!!:\n Lesen sie vor dem Start die Readme!\n !!!Achtung!!!:\n Benutzung auf eigene Gefahr!\n !!!Achtung!!!:\n Jede Funktionen starten mit der ADB.\n Wenn alles beachtet wurde, dann:\n Drücken sie 'r' wenn sie in das Recovery OS booten wollen.\n Drücken sie 'f' um in den Fastboot-Modus zu booten oder die Fastboothilfe auf zu listen (Litschi/Lychee).\n Drücken sie 'h' um vom Bootloader (Fastboot) in den Recovery zu booten.\n Drücken sie 'b' um den Bootloader zu öffnen oder schließen (Papaya).\n Drücken sie 'e' um Systemteile zu löschen (Durian).\n Drücken sie 'i' um Image-dateien zu flashen oder eine Zip-datei als Update zu installieren (Baumtomate).\n");
        
                scanf(" %c", &strawberry); 
        
                if (strawberry == 'r' || strawberry == 'R')//boot to recovery
                {
                    printf("Neustart in das Recovery OS...\n");
                    printf("Verbinden mit der ADB...\n");
                    system("adb devices");
                    system("adb devices");
        
                    printf("Booten des Gerätes in das Recovery OS...");
                    system("adb reboot recovery");
                }
        
                else if (strawberry == 'f' || strawberry == 'F') //boot to fastboot
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
                    scanf(" %c", &lychee); //fastboot help aufrufen oder alle Bootloader-Variablen 
        
                    if (lychee == 'h' || lychee == 'H') //fastboot help 
                    {
                        printf("Hier ist die Liste aller Fastboot-Befehle:\n");
                        system("fastboot help");
                    }
                    
                    else if (lychee == 'g' || lychee == 'G') //alle Fastboot Variablen 
                    {
                        printf("Befehl wird ausgeführt...");
                        system("fastboot getvar all");
                    }
                    
                    else
                    {
                        printf("Viel Spaß mit Fastboot:)");
                    }
                }
                
                else if (strawberry == 'h' || strawberry == 'H')
                {
                    printf("Neustart in das Recovery OS...\n");
                    system("fastboot reboot recovery");
                }
                
            
                else if (strawberry == 'b' || strawberry == 'B') //Bootloader öffnen oder schließen
                {
                    printf("!Dies ist Unterfunktion 'Papaya'!\n !!!Achtung!!! Benutzung auf eigene Gefahr!\n !!!Achtung!!!:\n Manche Chipsätze unterstützen diesen Vorgang nicht in dieser Weise.\n Drücken sie 'u' um den Bootloader zu öffnen oder 'l' um den Bootloader zu schließen.\n");
            
                    char papaya;
                    scanf(" %c", &papaya);
            
                    if (papaya == 'u' || papaya == 'U') //Bootloader öffnen
                    {
                        printf("!!!Achtung!!! Benutzung auf eigene Gefahr!\n !!!Achtung!!!:\n Manche Chipsätze unterstützen diesen Vorgang nicht in dieser Weise.\n Es gibt zwei verschiedene Methoden um den Bootloader zu öffnen. Für alte Geräte drücken sie 'o'.\n Für neuere Geräte drücken sie 'n'.\n");
                
                        char drachenauge;
                        scanf(" %c", &drachenauge); // Bootloader öffnen alt/neu
                        
                        if (drachenauge == 'o' || drachenauge == 'O') // Bootloader öffnen alt
                        {
                            printf("Starte Vorgang um den Bootloader zu öffnen...\n");
                            printf("Gerät im Fastboot verfügbar:\n");
                            system("fastboot devices");
                            system("fastboot devices");
            
                            printf("Bootloader wird geöffnet...\n");
                            system("fastboot flashing unlock");
                        }
                  
                        if (drachenauge == 'n' || drachenauge == 'N') // Bootloader öffnen neu 
                        { 
                            printf("Starte Vorgang um den Bootloader zu öffnen...\n");
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
              
                      else if (papaya == 'l' || papaya == 'L') //Bootloader schließen 
                      {
                          printf("!!!Achtung!!! Benutzung auf eigene Gefahr!\n !!!Achtung!!!:\n Manche Chipsätze unterstützen diesen Vorgang nicht in dieser Weise.\n Starte Vorgang um den Bootloader zu schließen...\n");
        
                          printf("Vorgang zum schließen des Bootloaders wird gestartet...\n");
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
        
                else if (strawberry == 'e' || strawberry == 'E') //Löschen von Systemteilen ohne neuen flash 
                {
                    printf("!Dies ist Unterfunktion 'Durian'!\n !!!Achtung!!! Benutzung auf eigene Gefahr!\n Achten sie darauf das nur bestimmte Partitionen gelöscht werden!\n Es werden keine neuen Image-Dateien geflasht!\n Um die Rcovery-Partition zu löschen drücken sie 'r'.\n Um die Boot-Partition zu löschen drücken sie 'b'.\n Um die Vendor-Partition zu löschen drücken sie 'v'.\n Um die System-Partition zu löschen drücken sie 's'.\n Um die Recovery-, Boot-, Vendor-, System-Partition zu löschen drücken sie 'a'.\n");
                    
                    char durian;
                    scanf(" %c", &durian);
            
                    if (durian == 'r' || durian == 'R') //Recovery-Partition löschen
                    {
                        printf("Recovery-Partition wird gelöscht...\n");
                        printf("Gerät im Fastboot verfügbar:\n");
                        system("fastboot devices");
                        system("fastboot devices");
                
                        printf("Löschen der Recovery-Partition...\n");
                        system("fastboot erase recovery");
                        printf("Recovery-Partition gelöscht!\n");
                    } 
            
                    else if (durian == 'b' || durian == 'B') //Boot-Partition löschen
                    {
                        printf("Boot-Partition wird gelöscht...\n");
                        printf("Gerät im Fastboot verfügbar:\n");
                        system("fastboot devices");
                        system("fastboot devices");
                  
                        printf("Löschen der Boot-Partition...\n");
                        system("fastboot erase boot");
                        printf("Boot-Partition gelöscht!\n");
                    }
            
                    else if (durian == 'v' || durian == 'V') //Vendor-Partition löschen 
                    {
                        printf("Vendor-Partition wird gelöscht...\n");
                        printf("Gerät im Fastboot verfügbar:\n");
                        system("fastboot devices");
                        system("fastboot devices");
                  
                        printf("Löschen der Vendor-Partition...\n");
                        system("fastboot erase Vendor");
                        printf("Vendor-Partition gelöscht!\n");
                    } 
            
                    else if (durian == 's' || durian == 'S') //System-Partiton löschen
                    { 
                        printf("System-Partition wird gelöscht...\n");
                        printf("Gerät im Fastboot verfügbar:\n");
                        system("fastboot devices");
                        system("fastboot devices");
                  
                        printf("Löschen der System-Partition...\n");
                        system("fastboot erase system");
                        printf("System-Partition gelöscht!\n");
                    }
                    
                     else if (durian == 'w' || durian == 'W') //Löschen der Nutzerdaten und des Caches
                    {
                        printf("!!!Achtung!!!:\n Manche Chipsätze unterstützen diesen Vorgang nicht in dieser Weise.\n Lösche alle Nutzerdaten und den Cache...\n");
          
                        printf("Gerät im Fastboot verfügbar:\n");
                        system("fastboot devices");
                        system("fastboot devices");
              
                        printf("Löschen der Nutzerdaten und des Cachs...");
                        system("fastboot erase -w");
                    }
        
            
                    else if (durian == 'a' || durian == 'A') //Löschen Nutzerdaten + Cache, Recovery-, Boot-, Vendor-, System-Prtition 
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
                
                else if (strawberry == 'i' || strawberry == 'I')
                {
                    printf("!Dies ist Unterfunktion 'Baumtomate'!\n !!!Achtung!!! Benutzung auf eigene Gefahr!\n !!!Achtung!!!:\n Es werden vorher die Partitionen überschrieben!\n Achten sie darauf das sich alle benötigten Dateien im selben Verzeichnis wie dieses Programm befinden.\n ***Um ein Update als Zip-Datei durchzuführen drücken sie 'u'.***\n Sie haben die Wahl welches Image sie flashen wollen:\n Drücken sie 'r' um das Recovery-Image zu flashen.\n Drücken sie 'b' um das Boot-Image zu flashen.\n Drücken sie 'v' um das Vendor-Image zu flashen.\n Drücken sie 's' um das System-Image zu flashen.\n"); //Flashen von Image-Dateien. Update via Zip-Datei 
            
                    char baumtomate;
                    scanf(" %c", &baumtomate);
            
                    if (baumtomate == 'u' || baumtomate == 'U') //Update einer Zip-Datei
                    {
                        printf("Achten sie darauf, dass das ihre zip-Datei im selben Verzeic\n Geben sie bitte den Namen der Datei ein die als Update dienen soll:\n");
                
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
                
                        printf("Gerät im Fastboot verfügbar:\n");
                        system("fastboot devices");
                        system("fastboot devices");
            
                        printf("Flashen der zip-Datei...");
                        system("fastboot update update.zip");
                        printf("Update durchgeführt.");
                    }
        
                    else if (baumtomate == 'f' || baumtomate == 'F') //Flashen eines Images
                    {
                        printf("Achten sie vor dem Flash darauf:\n Für a/b-Geräte wird beim flash für beide Partitionen ein und dasselbe Image verwendet!\n Welches Image wollen sie Flashen:\n ***(r) Recovery-Image***\n ***(b) Boot-Image***\n ***(v) Vendor-Image***\n ***(s) System-Image***\n oder Recovery-, Boot-, Vendor-, System-Image (a)\n");
                        
                        char mango;
                        scanf(" %c", &mango);
                        
                        if (mango == 'r' || mango == 'R') //Flashen des Recovery-Images
                        {
                            printf("Geben sie den Namen des künftigen Recovery-Images ein (Dateiname.img):\n");
                
                            char star[255]; //umbennen der Originaldatei in recovery.img 
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
        
                            printf("Gerät im Fastboot verfügbar:\n");
                            system("fastboot devices");
                            system("fastboot devices");
        
                            printf("Flashen des neuen Recovery-Images...\n");
                            system("fastboot flash recovery recovery.img");
                            printf("Recovery-Image wurde geflasht!\n");    
                        }
    
                        else if (mango == 'b' || mango == 'B') //Flashen des Boot-Images
                        {
                            printf("Geben sie den Namen des künftigen Boot-Images ein (Dateiname.img):\n");
                
                            char hornvogel[255]; //umbennen der Originaldatei in boot.img
                            scanf(" %s", hornvogel);
    
                            if(rename(hornvogel, "boot.img") == -1)
                            {
                                printf("Wieder was falsch! Hier muss der Programmierer ran!\n");
                            }
                    
                            else
                            {
                                printf("Datei umbenannt!\n");
                            }
                            
                            printf("Hat ihr Gerät eine a/b-Partitionierung oder nur a-Partition?\n ***(e) only-a***\n ***(z) a/b-Partitionierung***\n");
                            char kaki;
                            scanf(" %c", &kaki);
                            
                            if(kaki == 'e' || kaki == 'E') // flash boot.img only-a-devices
                            {
                                printf("Lehnen sie sich zurück:\n Vorgang zum Flashen des Boot-Images wird gestartet...\n");
        
                                printf("Gerät im Fastboot verfügbar:\n");
                                system("fastboot devices");
                                system("fastboot devices");
        
                                printf("Flashen des neuen Boot-Images...\n");
                                system("fastboot flash boot boot.img");
                                printf("Boot-Image wurde geflasht!\n");
                            }
                            
                            else if(kaki == 'z' || kaki == 'Z') //flash boot.img a/b devices
                            {
                                printf("Lehnen sie sich zurück:\n Vorgang zum Flashen des Boot-Images wird gestartet...\n");
                                printf("Gerät im Fastboot verfügbar:\n");
                                system("fastboot devices");
                                system("fastboot devices");
        
                                printf("Flashen des neuen Boot-Images...\n");
                                system("fastboot flash boot_a boot.img");
                                system("fastboot flash boot_b boot.img");
                                printf("Boot-Image wurde geflasht!\n");
                            }
                            
                            else
                            {
                                printf("Sie wissen wohl nicht was für Partitionen ihr Gerät hat?\n");
                            }
                                
                        }
                        
                        else if (mango == 'v' || mango == 'V') //Flashen des Vendor-Images
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
                            
                            printf("Hat ihr Gerät eine a/b-Partitionierung oder nur a-Partition?\n ***(e) only-a***\n ***(z) a/b-Partitionierung***\n");
                            char guave;
                            scanf(" %c", &guave);
                            
                            if(guave == 'e' || guave == 'E') // flash vendor.img only-a-devices
                            {
                
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
                            
                            else if(guave == 'z' || guave == 'Z') // flash vendor.img a/b-devices
                            {
                                printf("Lehnen sie sich zurück:\n Vorgang zum Flashen des Vendor-Images wird gestartet...\n");
        
                                printf("Gerät im Fastboot verfügbar:\n");
                                system("fastboot devices");
                                system("fastboot devices");
        
                                printf("Löschen des alten Vendor-Images...\n");
                                system("fastboot erase vendor_a");
                                system("fastboot erase vendor_b");
        
                                printf("Flashen des neuen Vendor-Images...\n");
                                system("fastboot flash vendor_a vendor.img");
                                system("fastboot flash vendor_b vendor.img");
                                printf("Vendor-Image wurde geflasht!\n"); 
                            }
                            
                            else
                            {
                                printf("Sie wissen wohl nicht was für Partitionen ihr Gerät hat?\n");
                            }
                        }
    
                        else if (mango == 's' || mango == 'S') //Flashen des System-Images
                        {  
                            printf("Geben sie den Namen des künftigen System-Images ein (Dateiname.img):\n");
                
                            char flamingo[255]; //umbennen der Originaldatei in system.img
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
                
                            printf("Gerät im Fastboot verfügbar:\n");
                            system("fastboot devices");
                            system("fastboot devices");
          
                            printf("Löschen der alten System-Partition...\n");
                            system("fastboot erase system");
                            printf("Flashen des neuen System-Images\n");
                            system("fastboot flash system system.img");
                            printf("System-Image wurde geflasht!\n");
        		
        	
                        }
        	
                        else if (mango == 'a' || mango == 'A') //Flashen des Recovery-, Boot-, Vendor-, System-Images 
                        {
                            printf("Geben sie den Namen des künftigen Recovery-Images ein (Dateiname.img):\n");
                    
                            char pfau[255]; //umbennen der Originaldatei in recovery.img
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
                
                            char kolibri[255]; //umbennen der Originaldatei in boot.img
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
                
                            char eule[255]; //umbennen der Originaldatei in vendor.img
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
                
                            char tukan[255]; //umbennen der Originaldatei in system.img
                            scanf(" %s", tukan);
    
                            if(rename(tukan, "system.img") == -1)
                            {
                                printf("Wieder was falsch! Hier muss der Programmierer ran!\n");
                            }
                    
                            else
                            {
                                printf("Datei umbenannt!\n");
                            }
                            
                            printf("Hat ihr Gerät eine a/b-Partitionierung oder nur a-Partition?\n ***(e) only-a***\n ***(z) a/b-Partitionierung***\n");
                            char zitrone;
                            scanf(" %c", &zitrone);
                            
                            if(zitrone == 'e' || zitrone == 'E') // flash recovery-, boot-,vendor-, system.img only-a-devices
                            {
                                printf("Lehnen sie sich zurück:\n Vorgang zum Flashen des Recovery-, Boot-, Vendor-, System-Images wird gestartet...\n");
        
                                printf("Geräte in Fastboot verfügbar:\n");
                                system("fastboot devices");
                                system("fastboot devices");
                        
                                system("fastboot flash recovery recovery.img");
                                system("fastboot reboot bootloader");
                                system("fastboot devices");
                                system("fastboot devices");
                                system("fastboot flash boot boot.img");
                                system("fastboot erase vendor");
                                system("fastboot flash vendor vendor.img");
                                system("fastboot erase system");
                                system("fastboot flash system system.img");
                                printf("Flash des Recovery-, Boot-, Vendor-, System-Images durchgeführt!\n");
                            }
                            
                            else if(zitrone == 'z' || zitrone == 'Z') // flash recovery-, boot-,vendor-, system.img a/b-devices
                            {
                                printf("Lehnen sie sich zurück:\n Vorgang zum Flashen des Recovery-, Boot-, Vendor-, System-Images wird gestartet...\n");
        
                                printf("Geräte in Fastboot verfügbar:\n");
                                system("fastboot devices");
                                system("fastboot devices");
                        
                                system("fastboot flash recovery recovery.img");
                                system("fastboot reboot bootloader");
                                system("fastboot devices");
                                system("fastboot devices");
                                
                                system("fastboot flash boot_a boot.img");
                                system("fastboot flash boot_b boot.img");
                                system("fastboot erase vendor_a");
                                system("fastboot erase vendor_b");
                                system("fastboot flash vendor_a vendor.img");
                                system("fastboot flash vendor_b vendor.img");
                                
                                system("fastboot erase system");
                                system("fastboot flash system system.img");
                                printf("Flash des Recovery-, Boot-, Vendor-, System-Images durchgeführt!\n");
                            }
                            
                            
                            else
                            {
                                printf("Sie wissen wohl nicht was für Partitionen ihr Gerät hat?\n");
                            }
                        }
            
                        else
                        {
                            printf("Wie jetzt weiter?\n");
                        }
                    }
                }
        
                else 
                {
                    printf("Entweder sie haben etwas nicht beachtet oder irgendetwas läuft schief. Auf jedenfall: der Programmierer ist Schuld:)\n");
                }
            
            printf("Möchten sie das Programm erneut ausführen? (y/n): ");
            scanf(" %c", &strawberry);
            
      } while (strawberry == 'y' || strawberry == 'Y');  // Erdbeer Schleife  
    }

    /* letzter Teil */
    
    printf("Möchten sie das Programm erneut ausführen? (y/n): "); // letzter Teil do-while-Schleife
    scanf(" %c", &cherry);
    
    return 0;
    } while (cherry == 'y' || cherry == 'Y');
        
}
    
