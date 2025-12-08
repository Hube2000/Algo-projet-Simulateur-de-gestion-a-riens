@echo off
REM Script de lancement appelé par le Makefile
cd /d "%~dp0MultiTerminal"
start "Terminal Visuel" cmd /k terminal_visuel.exe
timeout /t 1 /nobreak >nul
start "Terminal Info" cmd /k terminal_info.exe
timeout /t 1 /nobreak >nul
start "Terminal Events" cmd /k terminal_events.exe
timeout /t 1 /nobreak >nul
start "Programme Principal" cmd /k test.exe
echo Tous les terminaux sont lances!
