GlobalFixForAllFC3DependentMods is free software provided as-is under GPL3
copyleft license. You can freely make changes to the sources and binaries and
redistribute them provided the changes are indicated.

GlobalFixForAllFC3DependentMods is provided as a solution to the issue mentioned at:
https://forum.dcs.world/topic/355315-global-fix-for-all-fc3-dependent-mods/
https://forum.dcs.world/topic/252855-f-22a-raptor-mod-enhancement-mod/page/54/#comment-5495698

===============================================================================

Getting Started Guide
=====================
GlobalFixForAllFC3DependentMods was built with Visual Studio 2022 Community
Edition as a C/C++ console application.
Prereqisites:
Visual C++ Redistributables version 14.40.33810.0
https://learn.microsoft.com/en-us/cpp/windows/latest-supported-vc-redist?view=msvc-170
	https://aka.ms/vs/17/release/vc_redist.x86.exe
	https://aka.ms/vs/17/release/vc_redist.x64.exe
If you run GlobalFixForAllFC3DependentMods.exe with no output, install the
Visual C++ Redistributables

From a terminal in the program's directory verify GlobalFixForAllFC3DependentMods
is working correctly:
   .\GlobalFixForAllFC3DependentMods.exe /MOD:FC3
and then set "load_immediately = true" via:
   .\GlobalFixForAllFC3DependentMods.exe /MOD:FC3=1

To restore the entry.lua's for integrity check:
   .\GlobalFixForAllFC3DependentMods.exe /BAK=0 /MOD:FC3= 


===============================================================================

The first command verifies GlobalFixForAllFC3DependentMods by finding matches
for the module's {BINARIES} variable string fome the iniFile. it displays the
path for each FC3 entry.lua with the file position of the {BINARIES} string.
If an entry.lua is missing a {BINARIES} then the module entry.lua has changed
and the iniFile will require an update. 

e.g. from a clean DCS insall
.\GlobalFixForAllFC3DependentMods.exe /MOD:FC3
Searching for "load_immediately = <true|false>"
1) Searching A-10A:
Opened file "C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\A-10A\entry.lua"
C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\A-10A\entry.lua(1581):{BINARIES}
2) Searching F-15C:
Opened file "C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\F-15C\entry.lua"
C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\F-15C\entry.lua(1412):{BINARIES}
3) Searching MiG-29:
Opened file "C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\MiG-29\entry.lua"
C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\MiG-29\entry.lua(607):{BINARIES}
4) Searching Su-25A:
Opened file "C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\Su-25A\entry.lua"
C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\Su-25A\entry.lua(1424):{BINARIES}
5) Searching Su-25T:
Opened file "C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\Su-25T\entry.lua"
C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\Su-25T\entry.lua(1145):{BINARIES}
6) Searching Su-27:
Opened file "C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\Su-27\entry.lua"
C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\Su-27\entry.lua(656):{BINARIES}
7) Searching Su-33:
Opened file "C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\Su-33\entry.lua"
C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\Su-33\entry.lua(821):{BINARIES}

===============================================================================

The second command sets "load_immediately = true," by adding the
{LOADIMMEDIATELY_EQUALS_TRUE} variable string immediately after a match for the
{BINARIES} variable string. The <+> indicates the string has been added. By
default, it renames the entry.lua as backup entry.lua.load_immediately.bak as a
saftey measure.

e.g.
.\GlobalFixForAllFC3DependentMods.exe /MOD:FC3=1
Set "load_immediately = true"
1) Configuring A-10AOpened file "C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\A-10A\entry.lua"
C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\A-10A\entry.lua(1581):{BINARIES}
C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\A-10A\entry.lua(1625):<+>{LOADIMMEDIATELY_EQUALS_TRUE}
2) Configuring F-15COpened file "C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\F-15C\entry.lua"
C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\F-15C\entry.lua(1412):{BINARIES}
C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\F-15C\entry.lua(1452):<+>{LOADIMMEDIATELY_EQUALS_TRUE}
3) Configuring MiG-29Opened file "C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\MiG-29\entry.lua"
C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\MiG-29\entry.lua(607):{BINARIES}
C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\MiG-29\entry.lua(652):<+>{LOADIMMEDIATELY_EQUALS_TRUE}
4) Configuring Su-25AOpened file "C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\Su-25A\entry.lua"
C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\Su-25A\entry.lua(1424):{BINARIES}
C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\Su-25A\entry.lua(1460):<+>{LOADIMMEDIATELY_EQUALS_TRUE}
5) Configuring Su-25TOpened file "C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\Su-25T\entry.lua"
C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\Su-25T\entry.lua(1145):{BINARIES}
C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\Su-25T\entry.lua(1338):<+>{LOADIMMEDIATELY_EQUALS_TRUE}
6) Configuring Su-27Opened file "C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\Su-27\entry.lua"
C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\Su-27\entry.lua(656):{BINARIES}
C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\Su-27\entry.lua(699):<+>{LOADIMMEDIATELY_EQUALS_TRUE}
7) Configuring Su-33Opened file "C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\Su-33\entry.lua"
C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\Su-33\entry.lua(821):{BINARIES}
C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\Su-33\entry.lua(864):<+>{LOADIMMEDIATELY_EQUALS_TRUE}

===============================================================================

The third command removes the {LOADIMMEDIATELY_EQUALS_TRUE} and
{LOADIMMEDIATELY_EQUALS_TRUE} variable strings immediately following a match
for the {BINARIES} variable string. The <-> indicates the string has been removed.
By default, it renames the entry.lua as backup entry.lua.load_immediately.bak.
The /BAK=0 configures deletion of the automatic backup after the modification
to remove the extra file. This should restore it to pass integrity check. 

e.g.
.\GlobalFixForAllFC3DependentMods.exe /BAK=0 /MOD:FC3=
Delete "load_immediately = <true|false>"
1) Configuring A-10AOpened file "C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\A-10A\entry.lua"
C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\A-10A\entry.lua(1581):{BINARIES}
C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\A-10A\entry.lua(1625):<->{LOADIMMEDIATELY_EQUALS_TRUE}
2) Configuring F-15COpened file "C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\F-15C\entry.lua"
C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\F-15C\entry.lua(1412):{BINARIES}
C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\F-15C\entry.lua(1452):<->{LOADIMMEDIATELY_EQUALS_TRUE}
3) Configuring MiG-29Opened file "C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\MiG-29\entry.lua"
C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\MiG-29\entry.lua(607):{BINARIES}
C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\MiG-29\entry.lua(652):<->{LOADIMMEDIATELY_EQUALS_TRUE}
4) Configuring Su-25AOpened file "C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\Su-25A\entry.lua"
C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\Su-25A\entry.lua(1424):{BINARIES}
C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\Su-25A\entry.lua(1460):<->{LOADIMMEDIATELY_EQUALS_TRUE}
5) Configuring Su-25TOpened file "C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\Su-25T\entry.lua"
C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\Su-25T\entry.lua(1145):{BINARIES}
C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\Su-25T\entry.lua(1338):<->{LOADIMMEDIATELY_EQUALS_TRUE}
6) Configuring Su-27Opened file "C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\Su-27\entry.lua"
C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\Su-27\entry.lua(656):{BINARIES}
C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\Su-27\entry.lua(699):<->{LOADIMMEDIATELY_EQUALS_TRUE}
7) Configuring Su-33Opened file "C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\Su-33\entry.lua"
C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\Su-33\entry.lua(821):{BINARIES}
C:\GlobalFixForAllFC3DependentMods\Mods\Aircraft\Su-33\entry.lua(864):<->{LOADIMMEDIATELY_EQUALS_TRUE}

===============================================================================

For additional command line options, see the help screen.

e.g.
.\GlobalFixForAllFC3DependentMods.exe /HELP

GlobalFixForAllFC3DependentMods version 2.9.7.59074  Copyright(C) 2024 steam:cj43g3r aka searching46dof@github.com
For details see https://forum.dcs.world/topic/355315-global-fix-for-all-fc3-dependent-mods/
and https://forum.dcs.world/topic/252855-f-22a-raptor-mod-enhancement-mod/page/54/#comment-5495698
  Special thanks to SkateZilla and everyone involved in debugging/testing the issue
Usage: GlobalFixForAllFC3DependentMods.exe <options>
where <options>:
 /help or /?                display help screen
 /LICENSE                   display GPL3 license
 /VERBOSE=<verbosity>       set verbosity level 0-7, default=4
 /DEFAULTS                  creates inifile with defaults in current directory
 /DCSPATH=<DCShomePath>     override autodetected DCS home path
   e.g. /DCSPATH="C:\Program Files (x86)\DCSWorld"
   e.g. /DCSPATH="C:\Program Files (x86)\Steam\steamapps\common\DCSWorld"
 /BAK=[1|0]                 1=true(default) or 0=false, persistent entry.lua.load_immediately.bak backup file after update
 /MOD:<MOD>                 search/print load_immediately values via search for BINARIES string
                            immediately followed by LOADIMMEDIATELY_EQUALS_* string
 /MOD:<MOD>=[1|true]        set LOADIMMEDIATELY_EQUALS_TRUE string via search for BINARIES string
                            and removes following LOADIMMEDIATELY_EQUALS_* strings
                            then inserts LOADIMMEDIATELY_EQUALS_TRUE string
 /MOD:<MOD>=[0|false]       set LOADIMMEDIATELY_EQUALS_FALSE string via search for BINARIES string
                            and removes following LOADIMMEDIATELY_EQUALS_* strings
                            then inserts LOADIMMEDIATELY_EQUALS_FALSE string
 /MOD:<MOD>=[<space>|unset] unset LOADIMMEDIATELY_EQUALS_* string via search for BINARIES string
                            and removes following LOADIMMEDIATELY_EQUALS_* strings
where <MOD> is either FC3, FC2024, or a specific FC3/FC2024 module:
        A-10A, F-15C, F-5E_FC, F-86_FC, MiG-15bis_FC, MiG-29, Su-25A, Su-25T, Su-27, Su-33
or:
        P-51D
Notes:
GlobalFixForAllFC3DependentMods.ini under each <MOD> contains exact search strings for BINARIES, LOADIMMEDIATELY_EQUALS_FALSE and LOADIMMEDIATELY_EQUALS_TRUE.
Creates a backup copy of entry.lua as entry.lua.load_immediately.bak in same directory by default
Prereqisites:
Visual C++ Redistributables version 14.40.33810.0 https://learn.microsoft.com/en-us/cpp/windows/latest-supported-vc-redist?view=msvc-170
   x86 https://aka.ms/vs/17/release/vc_redist.x86.exe
   x64 https://aka.ms/vs/17/release/vc_redist.x64.exe


===============================================================================

FAQ
====================

You can set/unset a single FC3 module's entry.lua:

e.g.
.\GlobalFixForAllFC3DependentMods.exe /MOD:F-15C=1
.\GlobalFixForAllFC3DependentMods.exe /MOD:F-15C=

--------------------

You can set/unset the P-51D module's entry.lua for mods dependent on it:

e.g.
.\GlobalFixForAllFC3DependentMods.exe /MOD:P-51D=1
.\GlobalFixForAllFC3DependentMods.exe /MOD:P-51D=

--------------------

Support for multiple DCS installations, e.g. standalone vs steam ?

It automatically detects all DCS installations via windows uninstall registry
and will set all of them.

You can use the option /DCSPATH=... on the commandline to point to a
single installation.

You can use multiple copies of GlobalFixForAllFC3DependentMods in separate
directories, each iniFile configured with a different DCSPATH=... 

--------------------

Why a C/C++ console application?

Built-in windows scripting technology didn't provide the required functionality.
It reduces the dependencies to just the Visual C++ Redistributables which are
likely to already be installed. A console application doesn't require any GUI
changes to be extensible via its iniFile configuration.

--------------------

Support for MS Unicode, locales?

GlobalFixForAllFC3DependentMods is written with MS Unicode support but hasn't
been tested with other locales since the current FC3 modules entry.lua's appear
to be in EN-US locale.

--------------------

Support for future mods based on current FC2024 modules?

You can use the commandline options /MOD:FC2024=1 and /MOD:FC2024=

--------------------

Support for mods dependent on other modules?

You can edit the iniFile to provide additional support. Create a section with
the module's directory name.

e.g.
########################################
[F-15C]
;---------------------------------------
;binaries =
;{
;'F15CCWS',
;'F15'
;},
;---------------------------------------
BINARIES=\r\nbinaries =\r\n{\r\n'F15CCWS',\r\n'F15'\r\n},\r\n
LOADIMMEDIATELY_EQUALS_FALSE=load_immediately = false,\r\n
LOADIMMEDIATELY_EQUALS_TRUE=load_immediately = true,\r\n

########################################

In the above, the binaries section was copied from the F-15C's entry.lua and
preceded by a comment symbol, the semicolon ';'. The BINARIES variable contains
the same string represented as an escaped sequence string.
The LOADIMMEDIATELY_EQUALS_FALSE and LOADIMMEDIATELY_EQUALS_TRUE variables
contains escaped strings for setting load_immediately to true and false.

--------------------

Note the Su-25T doesn't have a binaries section so the Options section was the
last equivalent section was the options section of it's entry.lua.
It also has contains tabs. Its comments section shows the escape sequences to
make them more apparent.

e.g.
########################################
[Su-25T]
;---------------------------------------
;Options =
;    {\r\n
;        {\r\n
;            name\t\t= _("Su-25T"),\r\n
;            nameId\t\t= "Su-25T",\r\n
;            dir\t\t\t= "Options",\r\n
;            CLSID\t\t= "{Su-25T options}"
;        },
;    }, \t\r\n
;---------------------------------------
BINARIES=\r\nOptions =\r\n    {\r\n        {\r\n            name\t\t= _(\"Su-25T\"),\r\n            nameId\t\t= \"Su-25T\",\r\n            dir\t\t\t= \"Options\",\r\n            CLSID\t\t= \"{Su-25T options}\"\r\n        },\r\n    }, \t\r\n
LOADIMMEDIATELY_EQUALS_FALSE=load_immediately = false,\r\n
LOADIMMEDIATELY_EQUALS_TRUE=load_immediately = true,\r\n

########################################

--------------------

The variables BINARIES, LOADIMMEDIATELY_EQUALS_FALSE and
LOADIMMEDIATELY_EQUALS_TRUE are exact match strings. They are not regular
expressions making it easier to update the iniFile if any of the entry.lua's
change. Copy the binaries section of an entry.lua into a hex editor and use
the ascii values to help create an escaped string.
https://learn.microsoft.com/en-us/cpp/c-language/escape-sequences?view=msvc-170

There is additional support for multiple contiguous escape sequences in the
following format:
e.g.
\0x[01,02,03,04,05,06,07,08,09,0A,0B,0C,0D,0E,0F,10]

--------------------

There is a FC_LIST section containing a comma separated lists of FC3 and FC2024
modules.
You can add a module's directory name (e.g. under <Mods>\Aircraft )
to one of these lists for additional future planes.
You can create additional lists for future FlamingCliffs DLC. 

e.g.
;#######################################
[FC_LIST]
FC3=A-10A,F-15C,MiG-29,Su-25A,Su-25T,Su-27,Su-33
FC2024=A-10A,F-15C,F-5E_FC,F-86_FC,MiG-15bis_FC,MiG-29,Su-25A,Su-25T,Su-27,Su-33
;#######################################
