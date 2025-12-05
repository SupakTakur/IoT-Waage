# IoT-Waage -- Projektdokumentation

## Inhaltsverzeichnis

1.  [Einleitung](#1-einleitung)
    -   [Projektauftrag](#11-projektauftrag)
    -   [Zielsetzung](#12-zielsetzung)
    -   [Rahmenbedingungen](#13-rahmenbedingungen)
2.  [Grundlagen & Theorie](#2-grundlagen--theorie)
3.  [Anforderungen](#3-anforderungen)
4.  [Projektplanung](#4-projektplanung)
5.  [Mechanischer Aufbau](#5-mechanischer-aufbau)
6.  [Elektronischer Aufbau](#6-elektronischer-aufbau)
7.  [Softwareentwicklung](#7-softwareentwicklung)
8.  [Inbetriebnahme & Tests](#8-inbetriebnahme--tests)
9.  [Ergebnisse & Visualisierung](#9-ergebnisse--visualisierung)
10. [Fazit](#10-fazit)
11. [Anhang](#11-anhang)

------------------------------------------------------------------------

# 1. Einleitung

## 1.1 Projektauftrag

Es soll eine elektronische IoT-Waage gebaut werden, welche periodisch
(alle 60 Sekunden) das Gewicht der Last in kg misst. Zusätzlich soll die
Temperatur der Last gemessen werden. Diese Messwerte sollen auf einem
OLED-Display dargestellt und gleichzeitig via WLAN in eine
InfluxDB-Datenbank gespeichert werden. Die Werte können via Grafana
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

## 2.2 ESP32 Grundlagen

## 2.3 DS18B20 Grundlagen

## 2.4 OLED und I²C

## 2.5 IoT-Architektur (InfluxDB & Grafana)

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
