# bakefile�̓����
$bakefileUrl = "https://github.com/vslavik/bakefile/releases/download/v1.2.5.1/bakefile-1.2.5.1_beta-win.zip"
# wxWidgets�̓����
$wxUrl       = "https://github.com/wxWidgets/wxWidgets/archive/WX_3_0_2.zip"

# �J�����g�f�B���N�g���Ȃ�
$parentPath  = (Split-Path $script:myInvocation.MyCommand.path -parent)
$jcBklPath   = "$parentPath\janeclone.bkl"
$bklZipPath  = "$parentPath\bakefile.zip"
$bklExePath  = "$parentPath\bakefile-1.2.5.1_beta-win\bkl.exe"
$wxZipPath   = "$parentPath\WX_3_0_2.zip"
$wxDirPath   = "$parentPath\wxWidgets-WX_3_0_2"

# proxy���g���ꍇ�ɐݒ肷��
$proxyAddr   = ""
$proxyId     = ""
$proxyPass   = ""

# zip�t�@�C���W�J
function Expand-ZIPFile($file, $destination)
{
	$shell = new-object -com shell.application
	$zip = $shell.NameSpace($file)
	foreach($item in $zip.items())
	{
		$shell.Namespace($destination).copyhere($item)
	}
} 

# WebClient�̎擾
function Get-ProxyWebClient {
	$webclient = New-Object System.Net.WebClient

	If ([String]::IsNullOrEmpty($proxyAddr)) {
		return $webclient
	}
	$proxy = New-Object System.Net.WebProxy($proxyAddr)
	$proxy.Credentials = New-Object System.Net.NetworkCredential($proxyId, $proxyPass);
	$webclient.Proxy = $proxy
	return $webclient
}

# ------------------------------------------------------------------------------------------------------------ #
#  �o�b�`�����̊J�n                                                                                            #
# ------------------------------------------------------------------------------------------------------------ #

# HTTP�N���C�A���g�����
Write-Host "Start batch job..."
$iex = (Get-ProxyWebClient);

# �Â��v���W�F�N�g�t�@�C���͍폜����
Write-Host "Delete old project files..."
Remove-Item "$parentPath\*.vcxproj"
Remove-Item "$parentPath\*.filters"
Remove-Item "$parentPath\*.sln"

#
# bakefile�̓���
#
If (Test-Path $bklExePath) {
	Write-Host "--> bkl.exe is exist, Skip download"
} Else {
	If (Test-Path $bklZipPath) {
		Write-Host "--> Extract bkl zip file..."
		Expand-ZIPFile -File $bklZipPath -Destination $parentPath
	} Else {
		Write-Host "--> Downloading bkl zip file..."
		$iex.DownloadFile($bakefileUrl, $bklZipPath)
		Write-Host "--> Extract bkl zip file..."
		Expand-ZIPFile -File $bklZipPath -Destination $parentPath
	}
}

#
# wxWidgets�̓���
#
If (Test-Path $wxDirPath) {
	Write-Host "--> wxWidgets is exist, Skip download"
} Else {
	If (Test-Path $wxZipPath) {
		Write-Host "--> Extract wxWidgets zip file..."
		Expand-ZIPFile -File "$wxZipPath" -Destination "$parentPath"
	} Else {
		Write-Host "--> Downloading wxWidgets zip file..."
		$iex.DownloadFile($wxUrl, $wxZipPath)
		Write-Host "--> Extract wxWidgets zip file..."
		Expand-ZIPFile -File "$wxZipPath" -Destination "$parentPath"
	}
}

# build wxWidgets
Write-Host "Waiting..."
[Console]::ReadKey() | Out-Null

#
# bakefile���N��������
#
#Start-Process -FilePath $bklExePath -ArgumentList $jcBklPath -Wait