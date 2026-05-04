param(
    [ValidateSet('install-a','install-b','remove','status')]
    [string]$Action = 'status',
    [string]$DriverDir = 'C:\temp\tacx'
)

$ErrorActionPreference = 'Stop'

$InfA = Join-Path $DriverDir 'tacx_winusb_arm64.inf'
$InfB = Join-Path $DriverDir 'tacx_winusb_arm64_compat.inf'
$TargetPattern = 'VID_0FCF&PID_1008'

function Run-PnPUtil {
    param([string[]]$Args)
    Write-Host "> pnputil $($Args -join ' ')" -ForegroundColor Cyan
    pnputil @Args
}

function Assert-File([string]$Path) {
    if (-not (Test-Path $Path)) {
        throw "Bestand niet gevonden: $Path"
    }
}

function Get-TacxOemInfs {
    $drivers = pnputil /enum-drivers | Out-String
    $blocks = $drivers -split "\r?\n\r?\n"
    $matches = @()
    foreach ($b in $blocks) {
        if ($b -match 'Published Name\s*:\s*(oem\d+\.inf)' -and $b -match '(?i)Tacx ANT\+ USB Dongle') {
            $matches += $Matches[1]
        }
    }
    return $matches
}

function Show-Status {
    Run-PnPUtil -Args @('/enum-devices','/connected')
    Run-PnPUtil -Args @('/enum-drivers')
}

switch ($Action) {
    'install-a' {
        Assert-File $InfA
        Run-PnPUtil -Args @('/add-driver', $InfA, '/install')
        Show-Status
    }
    'install-b' {
        Assert-File $InfB
        Run-PnPUtil -Args @('/add-driver', $InfB, '/install')
        Show-Status
    }
    'remove' {
        $oems = Get-TacxOemInfs
        if (-not $oems -or $oems.Count -eq 0) {
            Write-Host 'Geen Tacx prototype oem*.inf entries gevonden.' -ForegroundColor Yellow
        } else {
            foreach ($oem in $oems) {
                Run-PnPUtil -Args @('/delete-driver', $oem, '/uninstall', '/force')
            }
        }
        Show-Status
    }
    'status' {
        Show-Status
    }
}
