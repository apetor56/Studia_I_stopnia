# Projekt strony dynamicznej
## Autor: Łukasz Tenerowicz
<br>

## Zawartość:
Projekt jest rozwinięciem pierwszej strony statycznej, gdzie zaprojektowane są poniższe strony:
- `Introduction` (index.html, strona startowa),
- Z zakładki `Basics`:
  - `First triange`,
  - `Textures`,
- Z zakładki `Lighting`:
  - `Colors`.

Z elementów dynamicznych przygotowałem możliwość zalogowania/rejestracji użytkownika oraz dodawania komentarzy pod konkretnymi sekcjami. Dane o użytkownikach i ich komentarzach przechowywane są w bazie NoSQL MongoDB.

Wykorzystane moduły:
- `dotenv`
- `ejs`
- `express`
- `express-session`
- `mongoose`
- `passport`
- `passport-local`
- `passport-local-mongoose`

## Instalacja i uruchomienie
W terminalu należy przejść do folderu `strona-statyczna` (lub do któregoś z jego podfolderów) i wprowadzić następujące komendy: 

1. `npm install`
2. `npm start`

Następnie w dowolnej przeglądarce należy przejść na adres
`localhost:3000` lub wpisać w terminalu (windows): `start http://localhost:3000/`.