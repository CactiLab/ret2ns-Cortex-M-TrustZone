$sourcePathS = "C:\Users\andy2\Documents\GitHub\code-CortexM-ret2user\blinky_tz\Boards\ARM\V2M-MPS2\IOTKit_CM33\IOTKit_CM33_S_NS\IOTKit_CM33_s\Objects\IOTKit_CM33_s.axf"
$destinationPathS = "E:\SOFTWARE\s.axf"
$sourcePathNS = "C:\Users\andy2\Documents\GitHub\code-CortexM-ret2user\blinky_tz\Boards\ARM\V2M-MPS2\IOTKit_CM33\IOTKit_CM33_S_NS\IOTKit_CM33_ns\Objects\IOTKit_CM33_ns.axf"
$destinationPathNS = "E:\SOFTWARE\ns.axf"

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

Copy-Item $sourcePathS $destinationPathS
Copy-Item $sourcePathNS $destinationPathNS

Write-Output "Done!"