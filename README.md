BookManager
Opis projektu:
BookManager to aplikacja konsolowa napisana w C++, która umożliwia zarządzanie kolekcją książek. Pozwala na dodawanie, usuwanie, przeglądanie oraz sortowanie książek, a także zapisywanie i wczytywanie danych z plików CSV.

Wymagania:
- Microsoft Visual Studio 2019 lub 2022 z komponentem „Desktop development with C++”
- System Windows 10/11

Struktura projektu:

bookmanager/
├── main.cpp
├── include/
│   ├── Book.h
│   ├── BookManager.h
│   └── utils.h
├── src/
│   ├── Book.cpp
│   ├── BookManager.cpp
│   └── utils.cpp
│   └── books.csv
├── data/
└── README.md

Jak skompilować:
Używając Microsoft Visual Studio
1. Otwórz plik BookManager.sln w Visual Studio
2. Wybierz konfigurację „Debug” lub „Release”
3. Naciśnij Ctrl + Shift + B, aby zbudować projekt
4. Uruchom program za pomocą Ctrl + F5 (bez debugowania) lub F5 (z debugowaniem)

Jak uruchomić:
Po skompilowaniu, program uruchomi się w trybie interaktywnym, gdzie możesz wybrać opcje z menu.

Argumenty wiersza poleceń
Program obsługuje również argumenty wiersza poleceń:
--import [plik] – importuje dane z podanego pliku CSV
--sort [pole] – wczytuje dane z pliku data/books.csv i sortuje według podanego pola (title / author / year / pages)

Przykład:
BookManager.exe --sort title

Format pliku CSV:
Program używa plików CSV o następującym formacie:

Tytuł,Autor,Rok,Strony
Wiedźmin,Andrzej Sapkowski,1994,320
Gambit królowej,Walter Tevis,1983,264

Funkcjonalności:
- Dodawanie nowych książek
- Usuwanie książek według tytułu
- Wyświetlanie wszystkich książek
- Sortowanie książek według tytułu, autora, roku lub liczby stron
- Filtrowanie po autorze
- Wczytywanie danych z plików CSV
- Zapisywanie danych do plików CSV

