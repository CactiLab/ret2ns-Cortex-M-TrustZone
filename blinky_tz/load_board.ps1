$sourcePathS = "C:\Users\andy2\Documents\GitHub\code-CortexM-ret2user\blinky_tz\Boards\ARM\V2M-MPS2\IOTKit_CM33\IOTKit_CM33_S_NS\IOTKit_CM33_s\Objects\IOTKit_CM33_s.axf"
$destinationPathS = "E:\SOFTWARE\s.axf"
$sourcePathNS = "C:\Users\andy2\Documents\GitHub\code-CortexM-ret2user\blinky_tz\Boards\ARM\V2M-MPS2\IOTKit_CM33\IOTKit_CM33_S_NS\IOTKit_CM33_ns\Objects\IOTKit_CM33_ns.axf"
$destinationPathNS = "E:\SOFTWARE\ns.axf"

Write-Host "Removing old files..." -NoNewline
if (Test-Path $sourcePathS)
{
    Remove-Item -Path $sourcePathS
}
else
{
    Write-Output "File does not exist: IOTKit_CM33_s.axf"
}

if (Test-Path $sourcePathNS)
{
    Remove-Item -Path $sourcePathNS
}
else
{
    Write-Output "File does not exist: IOTKit_CM33_ns.axf"
}
Write-Host "Done"

& C:/Keil_v5/UV4/UV4.exe -j4 -b .\Boards\ARM\V2M-MPS2\IOTKit_CM33\IOTKit_CM33_S_NS\IOTKit_CM33_s\IOTKit_CM33_s.uvprojx -o s_build.log
& C:/Keil_v5/UV4/UV4.exe -j4 -b .\Boards\ARM\V2M-MPS2\IOTKit_CM33\IOTKit_CM33_S_NS\IOTKit_CM33_ns\IOTKit_CM33_ns.uvprojx -o ns_build.log

if (Test-Path $destinationPathS)
{
    Remove-Item -Path $destinationPathS
}
else
{
    Write-Output "File does not exist: s.axf"
}

if (Test-Path $destinationPathNS)
{
    Remove-Item -Path $destinationPathNS
}
else
{
    Write-Output "File does not exist: ns.axf"
}

Write-Host "Building" -NoNewline
while (-not (Test-Path $sourcePathS) -or -not (Test-Path $sourcePathNS)) {
    Start-Sleep -Seconds 0.5
    Write-Host "." -NoNewline
}
Write-Output "Done"

Write-Host "Loading to board..." -NoNewline

Copy-Item $sourcePathS $destinationPathS
Copy-Item $sourcePathNS $destinationPathNS

Write-Host "Done" -NoNewline