@echo off
echo ================================================
echo  INSTALLATION DE GNU MAKE
echo ================================================
echo.
echo Ce script va installer Make via Chocolatey.
echo Une elevation de privileges est necessaire.
echo.
pause

powershell -Command "Start-Process powershell -Verb RunAs -ArgumentList '-NoProfile -ExecutionPolicy Bypass -Command ""choco install make -y""'"

echo.
echo ================================================
echo  Installation lancee en mode administrateur
echo ================================================
echo.
echo Attendez que l'installation se termine dans
echo la fenetre administrateur qui s'est ouverte.
echo.
echo Ensuite, FERMEZ ET ROUVREZ ce terminal,
echo puis utilisez: make run
echo.
pause
