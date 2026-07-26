## O projekcie

Projekt polega na wygenerowaniu, wyczyszczeniu oraz analizie syntetycznej bazy danych pomiarowych.

Składa się z dwóch części:
* **C++**: Skrypt (`main.cpp`) generujący 100 000 losowych pomiarów IoT do pliku `.csv`.
* **Python**: Notatnik Jupyter służący do czyszczenia anomalii oraz statystycznej wizualizacji danych.

## Jak uruchomić projekt?

**1. Generowanie danych (C++)**
Skompiluj kod, a następnie uruchom program, aby wygenerować bazę danych:
g++ -o generator main.cpp
.\generator.exe

**2. Analiza danych (Python)**
Zainstaluj pakiety z pliku requirements i uruchom środowisko analityczne:
pip install -r requirements.txt
jupyter notebook
