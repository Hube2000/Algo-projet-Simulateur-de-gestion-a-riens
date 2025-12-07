@echo off
echo ================================================
echo  LANCEMENT DU SYSTEME MULTI-TERMINAL
echo ================================================
echo.

cd /d "%~dp0"

REM Compilation des terminaux
echo [1/4] Compilation du terminal visuel...
gcc -std=c11 terminal_visuel.c -o terminal_visuel.exe
if %errorlevel% neq 0 (
    echo ERREUR lors de la compilation de terminal_visuel.c
    pause
    exit /b 1
)

echo [2/4] Compilation du terminal info...
gcc -std=c11 terminal_info.c -o terminal_info.exe
if %errorlevel% neq 0 (
    echo ERREUR lors de la compilation de terminal_info.c
    pause
    exit /b 1
)

echo [3/4] Compilation du terminal events...
gcc -std=c11 terminal_events.c -o terminal_events.exe
if %errorlevel% neq 0 (
    echo ERREUR lors de la compilation de terminal_events.c
    pause
    exit /b 1
)

echo [4/4] Compilation du programme principal...
cd ..\Terminal
gcc -std=c11 test.c ../fonctionnement/*.c ../controllers/*.c ../verifications/*.c -I../headers -o test.exe
if %errorlevel% neq 0 (
    echo ERREUR lors de la compilation de test.c
    pause
    exit /b 1
)

echo.
echo ================================================
echo  COMPILATION REUSSIE!
echo ================================================
echo.
echo Lancement des terminaux dans 2 secondes...
timeout /t 2 /nobreak >nul

REM Lancer le terminal visuel (cycles)
start "Terminal Visuel - Cycles" cmd /k "cd /d %~dp0 && terminal_visuel.exe"

REM Attendre un peu avant de lancer le suivant
timeout /t 1 /nobreak >nul

REM Lancer le terminal d'informations
start "Terminal Info - Informations Generales" cmd /k "cd /d %~dp0 && terminal_info.exe"

REM Attendre un peu avant de lancer le suivant
timeout /t 1 /nobreak >nul

REM Lancer le terminal des événements UI
start "Terminal Events - Evenements Visuels" cmd /k "cd /d %~dp0 && terminal_events.exe"

REM Attendre un peu avant de lancer le programme principal
timeout /t 1 /nobreak >nul

REM Lancer le programme principal
cd ..\Terminal
start "Programme Principal - Simulation" cmd /k "test.exe"

echo.
echo ================================================
echo  TOUS LES TERMINAUX SONT LANCES!
echo ================================================
echo.
echo Vous pouvez fermer cette fenetre.
echo Pour arreter la simulation, fermez les fenetres
echo ou utilisez Ctrl+C dans le terminal principal.
echo.
pause
