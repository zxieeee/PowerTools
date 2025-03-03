[Setup]
AppName=gtk_multimedia_organiser
AppVersion=0.1
DefaultDirName={pf}\gtk_multimedia_organiser
DefaultGroupName=gtk_multimedia_organiser
OutputDir=.
OutputBaseFilename=gtk_multimedia_organiser_Installer_ALPHA_0.1
Compression=lzma
SolidCompression=yes

[Files]
Source: "build\gtk_multimedia_organiser.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "include\config.conf"; DestDir: "{userappdata}\gtk_multimedia_organiser"; Flags: onlyifdoesntexist

[Icons]
Name: "{group}\gtk_multimedia_organiser"; Filename: "{app}\gtk_multimedia_organiser.exe"

[Run]
Filename: "{app}\gtk_multimedia_organiser.exe"; Description: "Launch gtk_multimedia_organiser"; Flags: nowait postinstall
