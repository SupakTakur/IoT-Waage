# IoT-Waage -- Projektdokumentation

## Inhaltsverzeichnis

1.  [Einleitung](#1-einleitung)
    -   [Projektauftrag](#11-projektauftrag)
    -   [Zielsetzung](#12-zielsetzung)
    -   [Rahmenbedingungen](#13-rahmenbedingungen)

2.  [Grundlagen & Theorie](#2-grundlagen--theorie)
    - [Wägezellen & HX711](#21-wägezellen--hx711)
    - [ESP32 Grundlagen](#22-esp32-grundlagen)
    - [DS18B20 Grundlagen](#23-ds18b20-grundlagen)
    - [OLED und I²C](#24-oled-und-i²c)
    - [IoT-Architektur (InfluxDB & Grafana)](#25-iot-architektur-influxdb--grafana)

3.  [Anforderungen](#3-anforderungen)
    - [Funktionale Anforderungen](#31-funktionale-anforderungen)
    - [Nicht-funktionale Anforderungen](#32-nicht-funktionale-anforderungen)
    - [Abnahmekriterien](#33-abnahmekriterien)
    - [Risiken & Herausforderungen](#34-risiken--herausforderungen)

4.  [Projektplanung](#4-projektplanung)
    - [Projektstruktur](#41-projektstruktur)
    - [Zeitplan](#42-zeitplan)
    - [Meilensteine](#43-meilensteine)
    - [Aufwandsschätzung](#44-aufwandsschätzung)
    - [Arbeitsmethode](#45-arbeitsmethode)

5.  [Mechanischer Aufbau](#5-mechanischer-aufbau)
    - [Komponenten & Materialien](#51-komponenten--materialien)
    - [Mechanisches Konzept](#52-mechanisches-konzept)
    - [CAD-Modelle](#53-cad-modelle)
    - [Belastungstests](#54-belastungstests)

6.  [Elektronischer Aufbau](#6-elektronischer-aufbau)
    - [Schaltplan](#61-schaltplan)
    - [Pinbelegung](#62-pinbelegung)
    - [Verkabelung](#63-verkabelung)
    - [Stromversorgung](#64-stromversorgung)

7.  [Softwareentwicklung](#7-softwareentwicklung)
    - [Softwarearchitektur](#71-softwarearchitektur)
    - [Kalibrierung](#72-kalibrierung)
    - [Temperaturmessung](#73-temperaturmessung)
    - [OLED-Ausgabe](#74-oled-ausgabe)
    - [WLAN & InfluxDB](#75-wlan--influxdb)
    - [Fehlerhandling](#76-fehlerhandling)

8.  [Inbetriebnahme & Tests](#8-inbetriebnahme--tests)
    - [Einzelkomponententests](#81-einzelkomponententests)
    - [Integrationstests](#82-integrationstests)
    - [Belastungstest](#83-belastungstest)
    - [Genauigkeitsanalyse](#84-genauigkeitsanalyse)

9.  [Ergebnisse & Visualisierung](#9-ergebnisse--visualisierung)
    - [Beispielmessungen](#91-beispielmessungen)
    - [Grafana Screenshots](#92-grafana-screenshots)
    - [Bewertung](#93-bewertung)

10. [Fazit](#10-fazit)
    - [Reflexion](#101-reflexion)
    - [Verbesserungsansätze](#102-verbesserungsansätze)
    - [Ausblick](#103-ausblick)

11. [Anhang](#11-anhang)
    - [Schaltpläne](#111-schaltpläne)
    - [CAD-Zeichnungen](#112-cad-zeichnungen)
    - [Stückliste](#113-stückliste)
    - [Quellcode](#114-quellcode)
    - [Datenblätter](#115-datenblätter)
    - [GitHub-Link](#116-github-link)

------------------------------------------------------------------------

# 1. Einleitung

## 1.1 Projektauftrag

Es soll eine elektronische IoT-Waage gebaut werden, welche periodisch
(alle 60 Sekunden) das Gewicht der Last in kg misst. Zusätzlich soll die
Temperatur der Last gemessen werden. Diese Messwerte sollen auf einem
OLED-Display dargestellt und gleichzeitig via WLAN in eine
InfluxDB-Datenbank gespeichert werden. Die Werte können via GrafanaDB
visualisiert werden. Alles wird auf GitHub veröffentlicht.

## 1.2 Zielsetzung

-   Zuverlässige Gewichtsmessung
-   Temperaturmessung
-   Senden der Daten an InfluxDB
-   Darstellung auf OLED

## 1.3 Rahmenbedingungen

-   Zeitraum: 120h
-   Arbeitsumgebung: Labor
-   Software: Arduino IDE
-   Komponenten: ESP32, HX711, DS18B20
-   Keine Tara-Funktion
-   Interner Gebrauch

------------------------------------------------------------------------

# 2. Grundlagen & Theorie

## 2.1 Wägezellen & HX711

Wägezellen basieren meist auf Dehnungsmessstreifen (DMS), die in einer Wheatstone-Brücke verschaltet sind. Wird die Zelle belastet, verändert sich der elektrische Widerstand der DMS minimal, wodurch eine sehr kleine Spannungsänderung entsteht. Diese Differenzspannung liegt typischerweise im Millivolt-Bereich und muss verstärkt und digitalisiert werden.

Der HX711 ist ein speziell für Wägezellen entwickelter 24-Bit-Analog-Digital-Wandler mit integriertem Verstärker. Er verstärkt die geringe Brückenspannung und wandelt sie in digitale Messwerte um, die seriell über zwei Pins (DOUT und SCK) ausgelesen werden können. Er ermöglicht eine hohe Messauflösung und eignet sich dadurch gut für Präzisionswaagen.

## 2.2 ESP32 Grundlagen

Der ESP32 ist ein Mikrocontroller mit integrierter WLAN- und Bluetooth-Funktionalität und eignet sich daher besonders für IoT-Anwendungen. Er verfügt über eine Vielzahl von GPIOs, unterstützt mehrere Kommunikationsprotokolle wie I²C, SPI, UART und OneWire und bietet ausreichend Rechenleistung für Sensorverarbeitung, Datenübertragung und interne Logik.

Für dieses Projekt übernimmt der ESP32 die Messwerterfassung, die Datenverarbeitung und die Kommunikation mit der Datenbank. Zudem steuert er Peripheriegeräte wie das OLED-Display und den Temperatursensor.

## 2.3 DS18B20 Grundlagen

Der DS18B20 ist ein digitaler Temperatursensor, der über das OneWire-Protokoll kommuniziert. Dieses benötigt nur eine einzige Datenleitung, über die sowohl die Kommunikation als auch die Identifikation erfolgt. Jede DS18B20-Einheit besitzt eine weltweit eindeutige 64-Bit-ID, wodurch mehrere Sensoren auf derselben Leitung betrieben werden können.

Der Sensor liefert Temperaturwerte zwischen −55 °C und +125 °C mit einer typischen Genauigkeit von ±0.5 °C im Bereich um 25 °C. Er kann normal mit drei Leitungen betrieben oder über „Parasite Power“ mit nur zwei Leitungen versorgt werden.

## 2.4 OLED und I²C

OLED-Displays bestehen aus selbstleuchtenden Pixeln und benötigen daher keine Hintergrundbeleuchtung. Typische Module im Embedded-Bereich, wie 128×64-Pixel-Displays, verwenden den I²C-Bus zur Kommunikation. I²C arbeitet mit zwei Leitungen (SDA und SCL) und ermöglicht das parallele Betreiben mehrerer Geräte am selben Bus, die jeweils über eine eindeutige Adresse angesprochen werden.

Im Projekt dient das OLED-Display zur visuellen Ausgabe der Gewichtswerte und Statusinformationen. Durch die geringe Leistungsaufnahme und die einfache Ansteuerung eignet es sich gut für kompakte IoT-Systeme.

## 2.5 IoT-Architektur (InfluxDB & Grafana)

Für die Speicherung und Visualisierung der Messdaten wird eine IoT-Architektur verwendet, die auf einer Zeitreihendatenbank basiert. Der ESP32 übermittelt die erfassten Werte über WLAN an eine InfluxDB-Instanz. InfluxDB ist optimiert für zeitbasierte Daten und erlaubt effizientes Speichern, Abfragen und Verarbeiten von Messreihen.

Zur Darstellung der Daten wird Grafana eingesetzt. Grafana ermöglicht das Erstellen interaktiver Dashboards, in denen Gewichtswerte, Temperaturverläufe und weitere Parameter übersichtlich visualisiert werden können. Die Kombination aus InfluxDB und Grafana bildet damit eine robuste Grundlage für die Analyse und Überwachung des Systems.

------------------------------------------------------------------------

# 3. Anforderungen

## 3.1 Funktionale Anforderungen

## 3.2 Nicht-funktionale Anforderungen

## 3.3 Abnahmekriterien

## 3.4 Risiken & Herausforderungen

------------------------------------------------------------------------

# 4. Projektplanung

## 4.1 Projektstruktur

## 4.2 Zeitplan

## 4.3 Meilensteine

## 4.4 Aufwandsschätzung

## 4.5 Arbeitsmethode

------------------------------------------------------------------------

# 5. Mechanischer Aufbau

## 5.1 Komponenten & Materialien

## 5.2 Mechanisches Konzept

## 5.3 CAD-Modelle

## 5.4 Belastungstests

------------------------------------------------------------------------

# 6. Elektronischer Aufbau

## 6.1 Schaltplan

## 6.2 Pinbelegung

## 6.3 Verkabelung

## 6.4 Stromversorgung

------------------------------------------------------------------------

# 7. Softwareentwicklung

## 7.1 Softwarearchitektur

## 7.2 Kalibrierung

## 7.3 Temperaturmessung

## 7.4 OLED-Ausgabe

## 7.5 WLAN & InfluxDB

## 7.6 Fehlerhandling

------------------------------------------------------------------------

# 8. Inbetriebnahme & Tests

## 8.1 Einzelkomponententests

## 8.2 Integrationstests

## 8.3 Belastungstest

## 8.4 Genauigkeitsanalyse

------------------------------------------------------------------------

# 9. Ergebnisse & Visualisierung

## 9.1 Beispielmessungen

## 9.2 Grafana Screenshots

## 9.3 Bewertung

------------------------------------------------------------------------

# 10. Fazit

## 10.1 Reflexion

## 10.2 Verbesserungsansätze

## 10.3 Ausblick

------------------------------------------------------------------------

# 11. Anhang

## 11.1 Schaltpläne

## 11.2 CAD-Zeichnungen

## 11.3 Stückliste

## 11.4 Quellcode

## 11.5 Datenblätter

## 11.6 GitHub-Link
