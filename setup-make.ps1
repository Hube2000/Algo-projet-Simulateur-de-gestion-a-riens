# ================================================================
# Script d'installation de Make pour Windows
# ================================================================
# Ce script installe automatiquement GNU Make via Chocolatey
# ou propose des alternatives si Chocolatey n'est pas disponible

param(
    [switch]$Force
)

Write-Host "================================================================" -ForegroundColor Cyan
Write-Host " INSTALLATION DE GNU MAKE POUR WINDOWS" -ForegroundColor Cyan
Write-Host "================================================================" -ForegroundColor Cyan
Write-Host ""

# Vérifier si Make est déjà installé
$makeInstalled = Get-Command make -ErrorAction SilentlyContinue

if ($makeInstalled -and -not $Force) {
    Write-Host "Make est deja installe!" -ForegroundColor Green
    Write-Host "Version:" (make --version | Select-Object -First 1)
    Write-Host ""
    Write-Host "Vous pouvez maintenant utiliser:" -ForegroundColor Yellow
    Write-Host "  make          - Compiler le projet"
    Write-Host "  make run      - Lancer la simulation"
    Write-Host "  make clean    - Nettoyer"
    Write-Host "  make help     - Aide"
    exit 0
}

Write-Host "Make n'est pas detecte. Installation en cours..." -ForegroundColor Yellow
Write-Host ""

# Vérifier si Chocolatey est installé
$chocoInstalled = Get-Command choco -ErrorAction SilentlyContinue

if ($chocoInstalled) {
    Write-Host "Chocolatey detecte. Installation de Make..." -ForegroundColor Green
    
    try {
        # Installer Make via Chocolatey
        choco install make -y
        
        Write-Host ""
        Write-Host "================================================================" -ForegroundColor Green
        Write-Host " INSTALLATION REUSSIE!" -ForegroundColor Green
        Write-Host "================================================================" -ForegroundColor Green
        Write-Host ""
        Write-Host "IMPORTANT: Fermez et rouvrez votre terminal PowerShell" -ForegroundColor Yellow
        Write-Host "pour que les changements prennent effet." -ForegroundColor Yellow
        Write-Host ""
        Write-Host "Ensuite, vous pourrez utiliser:" -ForegroundColor Cyan
        Write-Host "  make          - Compiler le projet"
        Write-Host "  make run      - Lancer la simulation"
        Write-Host "  make clean    - Nettoyer"
        Write-Host "  make help     - Aide"
        
    } catch {
        Write-Host "ERREUR lors de l'installation via Chocolatey" -ForegroundColor Red
        Write-Host $_.Exception.Message -ForegroundColor Red
    }
    
} else {
    Write-Host "Chocolatey n'est pas installe." -ForegroundColor Yellow
    Write-Host ""
    Write-Host "OPTIONS D'INSTALLATION:" -ForegroundColor Cyan
    Write-Host ""
    Write-Host "1. Installer Chocolatey puis Make (RECOMMANDE)" -ForegroundColor Green
    Write-Host "   Executez dans PowerShell (Admin):" -ForegroundColor Gray
    Write-Host '   Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString("https://community.chocolatey.org/install.ps1"))' -ForegroundColor DarkGray
    Write-Host "   Puis:" -ForegroundColor Gray
    Write-Host "   choco install make -y" -ForegroundColor DarkGray
    Write-Host ""
    Write-Host "2. Installer MinGW-w64 (inclut Make)" -ForegroundColor Green
    Write-Host "   Telechargez depuis: https://www.mingw-w64.org/" -ForegroundColor Gray
    Write-Host "   Ou utilisez MSYS2: https://www.msys2.org/" -ForegroundColor Gray
    Write-Host ""
    Write-Host "3. Utiliser les scripts alternatifs (SANS MAKE)" -ForegroundColor Yellow
    Write-Host "   - build.ps1 (PowerShell)" -ForegroundColor Gray
    Write-Host "   - build.bat (Batch)" -ForegroundColor Gray
    Write-Host ""
    Write-Host "UTILISATION DES SCRIPTS ALTERNATIFS:" -ForegroundColor Cyan
    Write-Host "  .\build.ps1          - Compiler"
    Write-Host "  .\build.ps1 -Run     - Compiler et lancer"
    Write-Host "  .\build.ps1 -Clean   - Nettoyer"
    Write-Host ""
    Write-Host "  OU" -ForegroundColor Yellow
    Write-Host ""
    Write-Host "  build.bat            - Compiler"
    Write-Host "  build.bat run        - Compiler et lancer"
    Write-Host "  build.bat clean      - Nettoyer"
}

Write-Host ""
Write-Host "================================================================" -ForegroundColor Cyan
