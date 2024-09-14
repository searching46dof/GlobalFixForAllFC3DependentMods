// GlobalFixForAllFC3DependentMods.cpp : Defines the entry point for the console application.
//
// Build with Visual Studio 2022 Community Edition as a C/C++ console application
// Requires preprocessor define _CRT_SECURE_NO_WARNINGS for wcstombs 
// 

// Change History
// ============================================================================
// cj43g3r				2024-09-01	Initial version
//									compatibile with DCS DCS 2.9.7.59074
// ============================================================================

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <string.h>
#include <string>
#include <vector>

/******************************************************************************/

static const char *GPL3license =
"\r\n"
"                    GNU GENERAL PUBLIC LICENSE\r\n"
"Version 3, 29 June 2007\r\n"
"\r\n"
"Copyright(C) 2007 Free Software Foundation, Inc. < https://fsf.org/>\r\n"
"Everyone is permitted to copy and distribute verbatim copies\r\n"
"of this license document, but changing it is not allowed.\r\n"
"\r\n"
"Preamble\r\n"
"\r\n"
"The GNU General Public License is a free, copyleft license for\r\n"
"software and other kinds of works.\r\n"
"\r\n"
"The licenses for most software and other practical works are designed\r\n"
"to take away your freedom to share and change the works.By contrast, \r\n"
"the GNU General Public License is intended to guarantee your freedom to\r\n"
"share and change all versions of a program--to make sure it remains free\r\n"
"software for all its users.We, the Free Software Foundation, use the\r\n"
"GNU General Public License for most of our software; it applies also to\r\n"
"any other work released this way by its authors.You can apply it to\r\n"
"your programs, too.\r\n"
"\r\n"
"When we speak of free software, we are referring to freedom, not\r\n"
"price.Our General Public Licenses are designed to make sure that you\r\n"
"have the freedom to distribute copies of free software(and charge for\r\n"
"them if you wish), that you receive source code or can get it if you\r\n"
"want it, that you can change the software or use pieces of it in new\r\n"
"free programs, and that you know you can do these things.\r\n"
"\r\n"
"To protect your rights, we need to prevent others from denying you\r\n"
"these rights or asking you to surrender the rights.Therefore, you have\r\n"
"certain responsibilities if you distribute copies of the software, or if\r\n"
"you modify it : responsibilities to respect the freedom of others.\r\n"
"\r\n"
"For example, if you distribute copies of such a program, whether\r\n"
"gratis or for a fee, you must pass on to the recipients the same\r\n"
"freedoms that you received.You must make sure that they, too, receive\r\n"
"or can get the source code.And you must show them these terms so they\r\n"
"know their rights.\r\n"
"\r\n"
"Developers that use the GNU GPL protect your rights with two steps : \r\n"
"(1) assert copyright on the software, and (2) offer you this License\r\n"
"giving you legal permission to copy, distribute and /or modify it.\r\n"
"\r\n"
"For the developers' and authors' protection, the GPL clearly explains\r\n"
"that there is no warranty for this free software.For both users' and\r\n"
"authors' sake, the GPL requires that modified versions be marked as\r\n"
"changed, so that their problems will not be attributed erroneously to\r\n"
"authors of previous versions.\r\n"
"\r\n"
"Some devices are designed to deny users access to install or run\r\n"
"modified versions of the software inside them, although the manufacturer\r\n"
"can do so.This is fundamentally incompatible with the aim of\r\n"
"protecting users' freedom to change the software.  The systematic\r\n"
"pattern of such abuse occurs in the area of products for individuals to\r\n"
"use, which is precisely where it is most unacceptable.Therefore, we\r\n"
"have designed this version of the GPL to prohibit the practice for those\r\n"
"products.If such problems arise substantially in other domains, we\r\n"
"stand ready to extend this provision to those domains in future versions\r\n"
"of the GPL, as needed to protect the freedom of users.\r\n"
"\r\n"
"Finally, every program is threatened constantly by software patents.\r\n"
"States should not allow patents to restrict development and use of\r\n"
"software on general - purpose computers, but in those that do, we wish to\r\n"
"avoid the special danger that patents applied to a free program could\r\n"
"make it effectively proprietary.To prevent this, the GPL assures that\r\n"
"patents cannot be used to render the program non - free.\r\n"
"\r\n"
"The precise terms and conditions for copying, distribution and \r\n"
"modification follow.\r\n"
"\r\n"
"TERMS AND CONDITIONS\r\n"
"\r\n"
"0. Definitions.\r\n"
"\r\n"
"\"This License\" refers to version 3 of the GNU General Public License.\r\n"
"\r\n"
"\"Copyright\" also means copyright - like laws that apply to other kinds of\r\n"
"works, such as semiconductor masks.\r\n"
"\r\n"
"\"The Program\" refers to any copyrightable work licensed under this\r\n"
"License.Each licensee is addressed as \"you\".  \"Licensees\" and \r\n"
"\"recipients\" may be individuals or organizations.\r\n"
"\r\n"
"To \"modify\" a work means to copy from or adapt all or part of the work\r\n"
"in a fashion requiring copyright permission, other than the making of an\r\n"
"exact copy.The resulting work is called a \"modified version\" of the\r\n"
"earlier work or a work \"based on\" the earlier work.\r\n"
"\r\n"
"A \"covered work\" means either the unmodified Program or a work based\r\n"
"on the Program.\r\n"
"\r\n"
"To \"propagate\" a work means to do anything with it that, without\r\n"
"permission, would make you directly or secondarily liable for\r\n"
"infringement under applicable copyright law, except executing it on a\r\n"
"computer or modifying a private copy.Propagation includes copying, \r\n"
"distribution(with or without modification), making available to the\r\n"
"public, and in some countries other activities as well.\r\n"
"\r\n"
"To \"convey\" a work means any kind of propagation that enables other\r\n"
"parties to make or receive copies.Mere interaction with a user through\r\n"
"a computer network, with no transfer of a copy, is not conveying.\r\n"
"\r\n"
"An interactive user interface displays \"Appropriate Legal Notices\"\r\n"
"to the extent that it includes a convenient and prominently visible\r\n"
"feature that(1) displays an appropriate copyright notice, and (2)\r\n"
"tells the user that there is no warranty for the work(except to the\r\n"
"extent that warranties are provided), that licensees may convey \r\n"
"work under this License, and how to view a copy of this License.If\r\n"
"the interface presents a list of user commands or options, such as a\r\n"
"menu, a prominent item in the list meets this criterion.\r\n"
"\r\n"
"1. Source Code.\r\n"
"\r\n"
"The \"source code\" for a work means the preferred form of the work\r\n"
"for making modifications to it.  \"Object code\" means any non - source\r\n"
"form of a work.\r\n"
"\r\n"
"A \"Standard Interface\" means an interface that either is an official\r\n"
"standard defined by a recognized standards body, or , in the case of\r\n"
"interfaces specified for a particular programming language, one that\r\n"
"is widely used among developers working in that language.\r\n"
"\r\n"
"The \"System Libraries\" of an executable work include anything, other\r\n"
"than the work as a whole, that(a) is included in the normal form of\r\n"
"packaging a Major Component, but which is not part of that Major\r\n"
"Component, and (b)serves only to enable use of the work with that\r\n"
"Major Component, or to implement a Standard Interface for which an\r\n"
"implementation is available to the public in source code form.A\r\n"
"\"Major Component\", in this context, means a major essential component\r\n"
"(kernel, window system, and so on) of the specific operating system\r\n"
"(if any) on which the executable work runs, or a compiler used to\r\n"
"produce the work, or an object code interpreter used to run it.\r\n"
"\r\n"
"The \"Corresponding Source\" for a work in object code form means all\r\n"
"the source code needed to generate, install, and (for an executable\r\n"
"work) run the object code and to modify the work, including scripts to\r\n"
"control those activities.However, it does not include the work's\r\n"
"System Libraries, or general - purpose tools or generally available free\r\n"
"programs which are used unmodified in performing those activities but\r\n"
"which are not part of the work.For example, Corresponding Source\r\n"
"includes interface definition files associated with source files for\r\n"
"the work, and the source code for shared libraries and dynamically\r\n"
"linked subprograms that the work is specifically designed to require, \r\n"
"such as by intimate data communication or control flow between those\r\n"
"subprograms and other parts of the work.\r\n"
"\r\n"
"The Corresponding Source need not include anything that users\r\n"
"can regenerate automatically from other parts of the Corresponding\r\n"
"Source.\r\n"
"\r\n"
"The Corresponding Source for a work in source code form is that\r\n"
"same work.\r\n"
"\r\n"
"2. Basic Permissions.\r\n"
"\r\n"
"All rights granted under this License are granted for the term of\r\n"
"copyright on the Program, and are irrevocable provided the stated\r\n"
"conditions are met.This License explicitly affirms your unlimited\r\n"
"permission to run the unmodified Program.The output from running a\r\n"
"covered work is covered by this License only if the output, given its\r\n"
"content, constitutes a covered work.This License acknowledges your\r\n"
"rights of fair use or other equivalent, as provided by copyright law.\r\n"
"\r\n"
"You may make, run and propagate covered works that you do not\r\n"
"convey, without conditions so long as your license otherwise remains\r\n"
"in force.You may convey covered works to others for the sole purpose\r\n"
"of having them make modifications exclusively for you, or provide you\r\n"
"with facilities for running those works, provided that you comply with\r\n"
"the terms of this License in conveying all material for which you do\r\n"
"not control copyright.Those thus making or running the covered works\r\n"
"for you must do so exclusively on your behalf, under your direction\r\n"
"and control, on terms that prohibit them from making any copies of\r\n"
"your copyrighted material outside their relationship with you.\r\n"
"\r\n"
"Conveying under any other circumstances is permitted solely under\r\n"
"the conditions stated below.Sublicensing is not allowed; section 10\r\n"
"makes it unnecessary.\r\n"
"\r\n"
"3. Protecting Users' Legal Rights From Anti-Circumvention Law.\r\n"
"\r\n"
"No covered work shall be deemed part of an effective technological\r\n"
"measure under any applicable law fulfilling obligations under article\r\n"
"11 of the WIPO copyright treaty adopted on 20 December 1996, or \r\n"
"similar laws prohibiting or restricting circumvention of such\r\n"
"measures.\r\n"
"\r\n"
"When you convey a covered work, you waive any legal power to forbid\r\n"
"circumvention of technological measures to the extent such circumvention\r\n"
"is effected by exercising rights under this License with respect to\r\n"
"the covered work, and you disclaim any intention to limit operation or \r\n"
"modification of the work as a means of enforcing, against the work's\r\n"
"users, your or third parties' legal rights to forbid circumvention of\r\n"
"technological measures.\r\n"
"\r\n"
"4. Conveying Verbatim Copies.\r\n"
"\r\n"
"You may convey verbatim copies of the Program's source code as you\r\n"
"receive it, in any medium, provided that you conspicuously and \r\n"
"appropriately publish on each copy an appropriate copyright notice; \r\n"
"keep intact all notices stating that this License and any\r\n"
"non - permissive terms added in accord with section 7 apply to the code; \r\n"
"keep intact all notices of the absence of any warranty; and give all\r\n"
"recipients a copy of this License along with the Program.\r\n"
"\r\n"
"You may charge any price or no price for each copy that you convey, \r\n"
"and you may offer support or warranty protection for a fee.\r\n"
"\r\n"
"5. Conveying Modified Source Versions.\r\n"
"\r\n"
"You may convey a work based on the Program, or the modifications to\r\n"
"produce it from the Program, in the form of source code under the\r\n"
"terms of section 4, provided that you also meet all of these conditions : \r\n"
"\r\n"
"a) The work must carry prominent notices stating that you modified\r\n"
"it, and giving a relevant date.\r\n"
"\r\n"
"b) The work must carry prominent notices stating that it is\r\n"
"released under this License and any conditions added under section\r\n"
"7.  This requirement modifies the requirement in section 4 to\r\n"
"\"keep intact all notices\".\r\n"
"\r\n"
"c) You must license the entire work, as a whole, under this\r\n"
"License to anyone who comes into possession of a copy.This\r\n"
"License will therefore apply, along with any applicable section 7\r\n"
"additional terms, to the whole of the work, and all its parts, \r\n"
"regardless of how they are packaged.This License gives no\r\n"
"permission to license the work in any other way, but it does not\r\n"
"invalidate such permission if you have separately received it.\r\n"
"\r\n"
"d) If the work has interactive user interfaces, each must display\r\n"
"Appropriate Legal Notices; however, if the Program has interactive\r\n"
"interfaces that do not display Appropriate Legal Notices, your\r\n"
"work need not make them do so.\r\n"
"\r\n"
"A compilation of a covered work with other separate and independent\r\n"
"works, which are not by their nature extensions of the covered work, \r\n"
"and which are not combined with it such as to form a larger program, \r\n"
"in or on a volume of a storage or distribution medium, is called an\r\n"
"\"aggregate\" if the compilation and its resulting copyright are not\r\n"
"used to limit the access or legal rights of the compilation's users\r\n"
"beyond what the individual works permit.Inclusion of a covered work\r\n"
"in an aggregate does not cause this License to apply to the other\r\n"
"parts of the aggregate.\r\n"
"\r\n"
"6. Conveying Non - Source Forms.\r\n"
"\r\n"
"You may convey a covered work in object code form under the terms\r\n"
"of sections 4 and 5, provided that you also convey the\r\n"
"machine - readable Corresponding Source under the terms of this License, \r\n"
"in one of these ways : \r\n"
"\r\n"
"a) Convey the object code in, or embodied in, a physical product\r\n"
"(including a physical distribution medium), accompanied by the\r\n"
"Corresponding Source fixed on a durable physical medium\r\n"
"customarily used for software interchange.\r\n"
"\r\n"
"b) Convey the object code in, or embodied in, a physical product\r\n"
"(including a physical distribution medium), accompanied by a\r\n"
"written offer, valid for at least three years and valid for as\r\n"
"long as you offer spare parts or customer support for that product\r\n"
"model, to give anyone who possesses the object code either(1) a\r\n"
"copy of the Corresponding Source for all the software in the\r\n"
"product that is covered by this License, on a durable physical\r\n"
"medium customarily used for software interchange, for a price no\r\n"
"more than your reasonable cost of physically performing this\r\n"
"conveying of source, or (2) access to copy the\r\n"
"Corresponding Source from a network server at no charge.\r\n"
"\r\n"
"c) Convey individual copies of the object code with a copy of the\r\n"
"written offer to provide the Corresponding Source.This\r\n"
"alternative is allowed only occasionally and noncommercially, and \r\n"
"only if you received the object code with such an offer, in accord\r\n"
"with subsection 6b.\r\n"
"\r\n"
"d) Convey the object code by offering access from a designated\r\n"
"place(gratis or for a charge), and offer equivalent access to the\r\n"
"Corresponding Source in the same way through the same place at no\r\n"
"further charge.You need not require recipients to copy the\r\n"
"Corresponding Source along with the object code.If the place to\r\n"
"copy the object code is a network server, the Corresponding Source\r\n"
"may be on a different server(operated by you or a third party)\r\n"
"that supports equivalent copying facilities, provided you maintain\r\n"
"clear directions next to the object code saying where to find the\r\n"
"Corresponding Source.Regardless of what server hosts the\r\n"
"Corresponding Source, you remain obligated to ensure that it is\r\n"
"available for as long as needed to satisfy these requirements.\r\n"
"\r\n"
"e) Convey the object code using peer - to - peer transmission, provided\r\n"
"you inform other peers where the object code and Corresponding\r\n"
"Source of the work are being offered to the general public at no\r\n"
"charge under subsection 6d.\r\n"
"\r\n"
"A separable portion of the object code, whose source code is excluded\r\n"
"from the Corresponding Source as a System Library, need not be\r\n"
"included in conveying the object code work.\r\n"
"\r\n"
"A \"User Product\" is either(1) a \"consumer product\", which means any\r\n"
"tangible personal property which is normally used for personal, family, \r\n"
"or household purposes, or (2) anything designed or sold for incorporation\r\n"
"into a dwelling.In determining whether a product is a consumer product, \r\n"
"doubtful cases shall be resolved in favor of coverage.For a particular\r\n"
"product received by a particular user, \"normally used\" refers to a\r\n"
"typical or common use of that class of product, regardless of the status\r\n"
"of the particular user or of the way in which the particular user\r\n"
"actually uses, or expects or is expected to use, the product.A product\r\n"
"is a consumer product regardless of whether the product has substantial\r\n"
"commercial, industrial or non - consumer uses, unless such uses represent\r\n"
"the only significant mode of use of the product.\r\n"
"\r\n"
"\"Installation Information\" for a User Product means any methods,\r\n"
"procedures, authorization keys, or other information required to install\r\n"
"and execute modified versions of a covered work in that User Product from\r\n"
"a modified version of its Corresponding Source.The information must\r\n"
"suffice to ensure that the continued functioning of the modified object\r\n"
"code is in no case prevented or interfered with solely because\r\n"
"modification has been made.\r\n"
"\r\n"
"If you convey an object code work under this section in, or with, or \r\n"
"specifically for use in, a User Product, and the conveying occurs as\r\n"
"part of a transaction in which the right of possession and use of the\r\n"
"User Product is transferred to the recipient in perpetuity or for a\r\n"
"fixed term(regardless of how the transaction is characterized), the\r\n"
"Corresponding Source conveyed under this section must be accompanied\r\n"
"by the Installation Information.But this requirement does not apply\r\n"
"if neither you nor any third party retains the ability to install\r\n"
"modified object code on the User Product(for example, the work has\r\n"
"been installed in ROM).\r\n"
"\r\n"
"The requirement to provide Installation Information does not include a\r\n"
"requirement to continue to provide support service, warranty, or updates\r\n"
"for a work that has been modified or installed by the recipient, or for\r\n"
"the User Product in which it has been modified or installed.Access to a\r\n"
"network may be denied when the modification itself materially and \r\n"
"adversely affects the operation of the network or violates the rules and \r\n"
"protocols for communication across the network.\r\n"
"\r\n"
"Corresponding Source conveyed, and Installation Information provided, \r\n"
"in accord with this section must be in a format that is publicly\r\n"
"documented(and with an implementation available to the public in\r\n"
"source code form), and must require no special password or key for\r\n"
"unpacking, reading or copying.\r\n"
"\r\n"
"7. Additional Terms.\r\n"
"\r\n"
"\"Additional permissions\" are terms that supplement the terms of this\r\n"
"License by making exceptions from one or more of its conditions.\r\n"
"Additional permissions that are applicable to the entire Program shall\r\n"
"be treated as though they were included in this License, to the extent\r\n"
"that they are valid under applicable law.If additional permissions\r\n"
"apply only to part of the Program, that part may be used separately\r\n"
"under those permissions, but the entire Program remains governed by\r\n"
"this License without regard to the additional permissions.\r\n"
"\r\n"
"When you convey a copy of a covered work, you may at your option\r\n"
"remove any additional permissions from that copy, or from any part of\r\n"
"it.  (Additional permissions may be written to require their own\r\n"
"removal in certain cases when you modify the work.)  You may place\r\n"
"additional permissions on material, added by you to a covered work, \r\n"
"for which you have or can give appropriate copyright permission.\r\n"
"\r\n"
"Notwithstanding any other provision of this License, for material you\r\n"
"add to a covered work, you may(if authorized by the copyright holders of\r\n"
"that material) supplement the terms of this License with terms : \r\n"
"\r\n"
"a) Disclaiming warranty or limiting liability differently from the\r\n"
"terms of sections 15 and 16 of this License; or \r\n"
"\r\n"
"b) Requiring preservation of specified reasonable legal notices or \r\n"
"author attributions in that material or in the Appropriate Legal\r\n"
"Notices displayed by works containing it; or \r\n"
"\r\n"
"c) Prohibiting misrepresentation of the origin of that material, or \r\n"
"requiring that modified versions of such material be marked in\r\n"
"reasonable ways as different from the original version; or \r\n"
"\r\n"
"d) Limiting the use for publicity purposes of names of licensors or \r\n"
"authors of the material; or \r\n"
"\r\n"
"e) Declining to grant rights under trademark law for use of some\r\n"
"trade names, trademarks, or service marks; or \r\n"
"\r\n"
"f) Requiring indemnification of licensors and authors of that\r\n"
"material by anyone who conveys the material(or modified versions of\r\n"
"it) with contractual assumptions of liability to the recipient, for\r\n"
"any liability that these contractual assumptions directly impose on\r\n"
"those licensors and authors.\r\n"
"\r\n"
"All other non - permissive additional terms are considered \"further\r\n"
"restrictions\" within the meaning of section 10.  If the Program as you\r\n"
"received it, or any part of it, contains a notice stating that it is\r\n"
"governed by this License along with a term that is a further\r\n"
"restriction, you may remove that term.If a license document contains\r\n"
"a further restriction but permits relicensing or conveying under this\r\n"
"License, you may add to a covered work material governed by the terms\r\n"
"of that license document, provided that the further restriction does\r\n"
"not survive such relicensing or conveying.\r\n"
"\r\n"
"If you add terms to a covered work in accord with this section, you\r\n"
"must place, in the relevant source files, a statement of the\r\n"
"additional terms that apply to those files, or a notice indicating\r\n"
"where to find the applicable terms.\r\n"
"\r\n"
"Additional terms, permissive or non - permissive, may be stated in the\r\n"
"form of a separately written license, or stated as exceptions; \r\n"
"the above requirements apply either way.\r\n"
"\r\n"
"8. Termination.\r\n"
"\r\n"
"You may not propagate or modify a covered work except as expressly\r\n"
"provided under this License.Any attempt otherwise to propagate or \r\n"
"modify it is void, and will automatically terminate your rights under\r\n"
"this License(including any patent licenses granted under the third\r\n"
"paragraph of section 11).\r\n"
"\r\n"
"However, if you cease all violation of this License, then your\r\n"
"license from a particular copyright holder is reinstated(a)\r\n"
"provisionally, unless and until the copyright holder explicitly and \r\n"
"finally terminates your license, and (b)permanently, if the copyright\r\n"
"holder fails to notify you of the violation by some reasonable means\r\n"
"prior to 60 days after the cessation.\r\n"
"\r\n"
"Moreover, your license from a particular copyright holder is\r\n"
"reinstated permanently if the copyright holder notifies you of the\r\n"
"violation by some reasonable means, this is the first time you have\r\n"
"received notice of violation of this License(for any work) from that\r\n"
"copyright holder, and you cure the violation prior to 30 days after\r\n"
"your receipt of the notice.\r\n"
"\r\n"
"Termination of your rights under this section does not terminate the\r\n"
"licenses of parties who have received copies or rights from you under\r\n"
"this License.If your rights have been terminated and not permanently\r\n"
"reinstated, you do not qualify to receive new licenses for the same\r\n"
"material under section 10.\r\n"
"\r\n"
"9. Acceptance Not Required for Having Copies.\r\n"
"\r\n"
"You are not required to accept this License in order to receive or \r\n"
"run a copy of the Program.Ancillary propagation of a covered work\r\n"
"occurring solely as a consequence of using peer - to - peer transmission\r\n"
"to receive a copy likewise does not require acceptance.However, \r\n"
"nothing other than this License grants you permission to propagate or \r\n"
"modify any covered work.These actions infringe copyright if you do\r\n"
"not accept this License.Therefore, by modifying or propagating a\r\n"
"covered work, you indicate your acceptance of this License to do so.\r\n"
"\r\n"
"10. Automatic Licensing of Downstream Recipients.\r\n"
"\r\n"
"Each time you convey a covered work, the recipient automatically\r\n"
"receives a license from the original licensors, to run, modify and \r\n"
"propagate that work, subject to this License.You are not responsible\r\n"
"for enforcing compliance by third parties with this License.\r\n"
"\r\n"
"An \"entity transaction\" is a transaction transferring control of an\r\n"
"organization, or substantially all assets of one, or subdividing an\r\n"
"organization, or merging organizations.If propagation of a covered\r\n"
"work results from an entity transaction, each party to that\r\n"
"transaction who receives a copy of the work also receives whatever\r\n"
"licenses to the work the party's predecessor in interest had or could\r\n"
"give under the previous paragraph, plus a right to possession of the\r\n"
"Corresponding Source of the work from the predecessor in interest, if\r\n"
"the predecessor has it or can get it with reasonable efforts.\r\n"
"\r\n"
"You may not impose any further restrictions on the exercise of the\r\n"
"rights granted or affirmed under this License.For example, you may\r\n"
"not impose a license fee, royalty, or other charge for exercise of\r\n"
"rights granted under this License, and you may not initiate litigation\r\n"
"(including a cross - claim or counterclaim in a lawsuit) alleging that\r\n"
"any patent claim is infringed by making, using, selling, offering for\r\n"
"sale, or importing the Program or any portion of it.\r\n"
"\r\n"
"11. Patents.\r\n"
"\r\n"
"A \"contributor\" is a copyright holder who authorizes use under this\r\n"
"License of the Program or a work on which the Program is based.The\r\n"
"work t\r\n"
"A contributor's \"essential patent claims\" are all patent claims\r\n"
"owned or controlled by the contributor, whether already acquired or \r\n"
"hereafter acquired, that would be infringed by some manner, permitted\r\n"
"by this License, of making, using, or selling its contributor version, \r\n"
"but do not include claims that would be infringed only as a\r\n"
"consequence of further modification of the contributor version.For\r\n"
"purposes of this definition, \"control\" includes the right to grant\r\n"
"patent sublicenses in a manner consistent with the requirements of\r\n"
"this License.\r\n"
"\r\n"
"Each contributor grants you a non - exclusive, worldwide, royalty - free\r\n"
"patent license under the contributor's essential patent claims, to\r\n"
"make, use, sell, offer for sale, import and otherwise run, modify and \r\n"
"propagate the contents of its contributor version.\r\n"
"\r\n"
"In the following three paragraphs, a \"patent license\" is any express\r\n"
"agreement or commitment, however denominated, not to enforce a patent\r\n"
"(such as an express permission to practice a patent or covenant not to\r\n"
"sue for patent infringement).To \"grant\" such a patent license to a\r\n"
"party means to make such an agreement or commitment not to enforce a\r\n"
"patent against the party.\r\n"
"\r\n"
"If you convey a covered work, knowingly relying on a patent license, \r\n"
"and the Corresponding Source of the work is not available for anyone\r\n"
"to copy, free of charge and under the terms of this License, through a\r\n"
"publicly available network server or other readily accessible means, \r\n"
"then you must either(1) cause the Corresponding Source to be so\r\n"
"available, or (2) arrange to deprive yourself of the benefit of the\r\n"
"patent license for this particular work, or (3) arrange, in a manner\r\n"
"consistent with the requirements of this License, to extend the patent\r\n"
"license to downstream recipients.  \"Knowingly relying\" means you have\r\n"
"actual knowledge that, but for the patent license, your conveying the\r\n"
"covered work in a country, or your recipient's use of the covered work\r\n"
"in a country, would infringe one or more identifiable patents in that\r\n"
"country that you have reason to believe are valid.\r\n"
"\r\n"
"If, pursuant to or in connection with a single transaction or \r\n"
"arrangement, you convey, or propagate by procuring conveyance of, a\r\n"
"covered work, and grant a patent license to some of the parties\r\n"
"receiving the covered work authorizing them to use, propagate, modify\r\n"
"or convey a specific copy of the covered work, then the patent license\r\n"
"you grant is automatically extended to all recipients of the covered\r\n"
"work and works based on it.\r\n"
"\r\n"
"A patent license is \"discriminatory\" if it does not include within\r\n"
"the scope of its coverage, prohibits the exercise of, or is\r\n"
"conditioned on the non - exercise of one or more of the rights that are\r\n"
"specifically granted under this License.You may not convey a covered\r\n"
"work if you are a party to an arrangement with a third party that is\r\n"
"in the business of distributing software, under which you make payment\r\n"
"to the third party based on the extent of your activity of conveying\r\n"
"the work, and under which the third party grants, to any of the\r\n"
"parties who would receive the covered work from you, a discriminatory\r\n"
"patent license(a) in connection with copies of the covered work\r\n"
"conveyed by you(or copies made from those copies), or (b)primarily\r\n"
"for and in connection with specific products or compilations that\r\n"
"contain the covered work, unless you entered into that arrangement, \r\n"
"or that patent license was granted, prior to 28 March 2007.\r\n"
"\r\n"
"Nothing in this License shall be construed as excluding or limiting\r\n"
"any implied license or other defenses to infringement that may\r\n"
"otherwise be available to you under applicable patent law.\r\n"
"\r\n"
"12. No Surrender of Others' Freedom.\r\n"
"\r\n"
"If conditions are imposed on you(whether by court order, agreement or \r\n"
"otherwise) that contradict the conditions of this License, they do not\r\n"
"excuse you from the conditions of this License.If you cannot convey a\r\n"
"covered work so as to satisfy simultaneously your obligations under this\r\n"
"License and any other pertinent obligations, then as a consequence you may\r\n"
"not convey it at all.For example, if you agree to terms that obligate you\r\n"
"to collect a royalty for further conveying from those to whom you convey\r\n"
"the Program, the only way you could satisfy both those terms and this\r\n"
"License would be to refrain entirely from conveying the Program.\r\n"
"\r\n"
"13. Use with the GNU Affero General Public License.\r\n"
"\r\n"
"Notwithstanding any other provision of this License, you have\r\n"
"permission to link or combine any covered work with a work licensed\r\n"
"under version 3 of the GNU Affero General Public License into a single\r\n"
"combined work, and to convey the resulting work.The terms of this\r\n"
"License will continue to apply to the part which is the covered work, \r\n"
"but the special requirements of the GNU Affero General Public License, \r\n"
"section 13, concerning interaction through a network will apply to the\r\n"
"combination as such.\r\n"
"\r\n"
"14. Revised Versions of this License.\r\n"
"\r\n"
"The Free Software Foundation may publish revised and /or new versions of\r\n"
"the GNU General Public License from time to time.Such new versions will\r\n"
"be similar in spirit to the present version, but may differ in detail to\r\n"
"address new problems or concerns.\r\n"
"\r\n"
"Each version is given a distinguishing version number.If the\r\n"
"Program specifies that a certain numbered version of the GNU General\r\n"
"Public License \"or any later version\" applies to it, you have the\r\n"
"option of following the terms and conditions either of that numbered\r\n"
"version or of any later version published by the Free Software\r\n"
"Foundation.If the Program does not specify a version number of the\r\n"
"GNU General Public License, you may choose any version ever published\r\n"
"by the Free Software Foundation.\r\n"
"\r\n"
"If the Program specifies that a proxy can decide which future\r\n"
"versions of the GNU General Public License can be used, that proxy's\r\n"
"public statement of acceptance of a version permanently authorizes you\r\n"
"to choose that version for the Program.\r\n"
"\r\n"
"Later license versions may give you additional or different\r\n"
"permissions.However, no additional obligations are imposed on any\r\n"
"author or copyright holder as a result of your choosing to follow a\r\n"
"later version.\r\n"
"\r\n"
"15. Disclaimer of Warranty.\r\n"
"\r\n"
"THERE IS NO WARRANTY FOR THE PROGRAM, TO THE EXTENT PERMITTED BY\r\n"
"APPLICABLE LAW.EXCEPT WHEN OTHERWISE STATED IN WRITING THE COPYRIGHT\r\n"
"HOLDERS AND / OR OTHER PARTIES PROVIDE THE PROGRAM \"AS IS\" WITHOUT WARRANTY\r\n"
"OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, \r\n"
"THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR\r\n"
"PURPOSE.THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF THE PROGRAM\r\n"
"IS WITH YOU.SHOULD THE PROGRAM PROVE DEFECTIVE, YOU ASSUME THE COST OF\r\n"
"ALL NECESSARY SERVICING, REPAIR OR CORRECTION.\r\n"
"\r\n"
"16. Limitation of Liability.\r\n"
"\r\n"
"IN NO EVENT UNLESS REQUIRED BY APPLICABLE LAW OR AGREED TO IN WRITING\r\n"
"WILL ANY COPYRIGHT HOLDER, OR ANY OTHER PARTY WHO MODIFIES AND / OR CONVEYS\r\n"
"THE PROGRAM AS PERMITTED ABOVE, BE LIABLE TO YOU FOR DAMAGES, INCLUDING ANY\r\n"
"GENERAL, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THE\r\n"
"USE OR INABILITY TO USE THE PROGRAM(INCLUDING BUT NOT LIMITED TO LOSS OF\r\n"
"DATA OR DATA BEING RENDERED INACCURATE OR LOSSES SUSTAINED BY YOU OR THIRD\r\n"
"PARTIES OR A FAILURE OF THE PROGRAM TO OPERATE WITH ANY OTHER PROGRAMS), \r\n"
"EVEN IF SUCH HOLDER OR OTHER PARTY HAS BEEN ADVISED OF THE POSSIBILITY OF\r\n"
"SUCH DAMAGES.\r\n"
"\r\n"
"17. Interpretation of Sections 15 and 16.\r\n"
"\r\n"
"If the disclaimer of warranty and limitation of liability provided\r\n"
"above cannot be given local legal effect according to their terms, \r\n"
"reviewing courts shall apply local law that most closely approximates\r\n"
"an absolute waiver of all civil liability in connection with the\r\n"
"Program, unless a warranty or assumption of liability accompanies a\r\n"
"copy of the Program in return for a fee.\r\n"
"\r\n"
"END OF TERMS AND CONDITIONS\r\n"
"\r\n"
"How to Apply These Terms to Your New Programs\r\n"
"\r\n"
"If you develop a new program, and you want it to be of the greatest\r\n"
"possible use to the public, the best way to achieve this is to make it\r\n"
"free software which everyone can redistribute and change under these terms.\r\n"
"\r\n"
"To do so, attach the following notices to the program.It is safest\r\n"
"to attach them to the start of each source file to most effectively\r\n"
"state the exclusion of warranty; and each file should have at least\r\n"
"the \"copyright\" line and a pointer to where the full notice is found.\r\n"
"\r\n"
"< one line to give the program's name and a brief idea of what it does.>\r\n"
"Copyright(C) < year > <name of author>\r\n"
"\r\n"
"This program is free software : you can redistribute it and /or modify\r\n"
"it under the terms of the GNU General Public License as published by\r\n"
"the Free Software Foundation, either version 3 of the License, or \r\n"
"(at your option) any later version.\r\n"
"\r\n"
"This program is distributed in the hope that it will be useful, \r\n"
"but WITHOUT ANY WARRANTY; without even the implied warranty of\r\n"
"MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the\r\n"
"GNU General Public License for more details.\r\n"
"\r\n"
"You should have received a copy of the GNU General Public License\r\n"
"along with this program.If not, see < https://www.gnu.org/licenses/>.\r\n"
"\r\n"
"Also add information on how to contact you by electronic and paper mail.\r\n"
"\r\n"
"If the program does terminal interaction, make it output a short\r\n"
"notice like this when it starts in an interactive mode : \r\n"
"\r\n"
"<program>  Copyright(C) < year > <name of author>\r\n"
"This program comes with ABSOLUTELY NO WARRANTY; for details type `show w'.\r\n"
"This is free software, and you are welcome to redistribute it\r\n"
"under certain conditions; type `show c' for details.\r\n"
"\r\n"
"The hypothetical commands `show w' and `show c' should show the appropriate\r\n"
"parts of the General Public License.Of course, your program's commands\r\n"
"might be different; for a GUI interface, you would use an \"about box\".\r\n"
"\r\n"
"You should also get your employer(if you work as a programmer) or school, \r\n"
"if any, to sign a \"copyright disclaimer\" for the program, if necessary.\r\n"
"For more information on this, and how to apply and follow the GNU GPL, see\r\n"
"< https ://www.gnu.org/licenses/>.\r\n"
"\r\n"
"The GNU General Public License does not permit incorporating your program\r\n"
"into proprietary programs.If your program is a subroutine library, you\r\n"
"may consider it more useful to permit linking proprietary applications with\r\n"
"the library.If this is what you want to do, use the GNU Lesser General\r\n"
"Public License instead of this License.But first, please read\r\n"
"< https://www.gnu.org/licenses/why-not-lgpl.html>.\r\n\r\n";
			
/******************************************************************************/

#define MAX_KEY_LENGTH 255
#define MAX_VALUE_NAME 1024

#define VERBOSE_NONE         0
#define VERBOSE_CRITICAL     1
#define VERBOSE_ERROR        2
#define VERBOSE_WARNING      3
#define VERBOSE_INFO         4
#define VERBOSE_DEBUG_LOW    5
#define VERBOSE_DEBUG_MEDIUM 6
#define VERBOSE_DEBUG_HIGH   7
int verbose = VERBOSE_INFO;

int backupLua = 1;

#define SET_LOADIMMEDIATELY_TRUE   1
#define SET_LOADIMMEDIATELY_FALSE  0
#define SET_LOADIMMEDIATELY_UNSET -1

size_t binaries_buffer_size = 2048;

std::wstring              szIniFile;
std::vector<std::wstring> DCSpaths;

#define SIZEOFARRAY(nameOfArray) (sizeof(nameOfArray)/sizeof(nameOfArray[0]))

/*****************************************************************************/

const TCHAR* FC_LIST__FC3 = _T("FC3");
const TCHAR* fc3_modules[7] =
{
	_T("A-10A"),
	_T("F-15C"),
	_T("MiG-29"),
	_T("Su-25A"),
	_T("Su-25T"),
	_T("Su-27"),
	_T("Su-33")
};

const TCHAR* FC_LIST__FC2024 = _T("FC2024");
const TCHAR* fc2024_modules[10] =
{
	_T("A-10A"),
	_T("F-15C"),
	_T("F-5E_FC"),
	_T("F-86_FC"),
	_T("MiG-15bis_FC"),
	_T("MiG-29"),
	_T("Su-25A"),
	_T("Su-25T"),
	_T("Su-27"),
	_T("Su-33")
};

typedef struct _LISTOF_FC_MODULES
{
	std::wstring              fc_name;
	std::vector<std::wstring> fc_modules;
} LISTOF_FC_MODULES;
typedef std::vector<LISTOF_FC_MODULES> VECTOROF_LISTOF_FC_MODULES;
VECTOROF_LISTOF_FC_MODULES    vectorof_listof_fc_modules;

/*****************************************************************************/

static void initialize(void)
{
	// initialize debug section values
	{
		LPCTSTR lpSectionName_DEBUG = _T("DEBUG");

		// VERBOSE=[0-7]
		LPCTSTR lpKeyName_VERBOSE = _T("VERBOSE");
		verbose = GetPrivateProfileIntW(lpSectionName_DEBUG, lpKeyName_VERBOSE, VERBOSE_INFO, &szIniFile[0]);

		LPCTSTR lpKeyName_BAK = _T("BAK");
		backupLua = GetPrivateProfileIntW(lpSectionName_DEBUG, lpKeyName_BAK, 1, &szIniFile[0]);

		// DCSPATH=C:\Program Files (x86)\DCSWorld
		// DCSPATH=C:\Program Files (x86)\Steam\steamapps\common\DCSWorld
		std::wstring DCSpath;
		DCSpath.resize(2048);
		LPCTSTR lpKeyName_DCSPATH = _T("DCSPATH");
		DWORD numCharsRead = GetPrivateProfileStringW(lpSectionName_DEBUG, lpKeyName_DCSPATH, (LPCTSTR)NULL,
			&DCSpath[0], (DWORD)DCSpath.size(), &szIniFile[0]);
		DCSpath.resize(numCharsRead);
		if (DCSpath.size() && !isspace(DCSpath[0]))
		{
			DCSpaths.push_back(DCSpath);
			if (DCSpaths.size())
				_tprintf(_T("IniFile DCSPATH=%s\n"), DCSpaths[DCSpaths.size() - 1].c_str());
		}
	}

	// initialize lists of flaming cliff modules

	std::wstring fc_list;
	fc_list.resize(2048);
	LPCTSTR lpSectionName_FC_LIST = _T("FC_LIST");
	DWORD numCharsRead = GetPrivateProfileStringW(lpSectionName_FC_LIST, NULL, (LPCTSTR)NULL, &fc_list[0], (DWORD)fc_list.size(), &szIniFile[0]);
	fc_list.resize(numCharsRead);

	TCHAR* fc_list_ptr = &fc_list[0];
	while (*fc_list_ptr)
	{
		size_t vector_size = vectorof_listof_fc_modules.size();
		vectorof_listof_fc_modules.resize(vector_size + 1);
		vectorof_listof_fc_modules[vector_size].fc_name = std::wstring(fc_list_ptr);

		std::wstring fc_modules;
		fc_modules.resize(2048);
		LPCTSTR lpSectionName_FC_LIST = _T("FC_LIST");
		numCharsRead = GetPrivateProfileStringW(lpSectionName_FC_LIST, fc_list_ptr, (LPCTSTR)NULL, &fc_modules[0], (DWORD)fc_modules.size(), &szIniFile[0]);
		fc_modules.resize(numCharsRead);


		const TCHAR* pSeparator = _T(",");
		TCHAR* context = NULL;
		TCHAR* fc_modules_ptr = _tcstok_s(&fc_modules[0], pSeparator, &context);
		while (fc_modules_ptr)
		{
			vectorof_listof_fc_modules[vector_size].fc_modules.push_back(std::wstring(fc_modules_ptr));
			fc_modules_ptr = _tcstok_s(NULL, pSeparator, &context);
		}

		fc_list_ptr = fc_list_ptr + _tcslen(fc_list_ptr) + 1;
	}

	if (vectorof_listof_fc_modules.size() == 0)
	{
		vectorof_listof_fc_modules.resize(2);
		vectorof_listof_fc_modules[0].fc_name = _T("FC3");
		for (size_t i = 0; i < SIZEOFARRAY(fc3_modules); i++)
			vectorof_listof_fc_modules[0].fc_modules.push_back(std::wstring(fc3_modules[i]));
		vectorof_listof_fc_modules[1].fc_name = _T("FC2024");
		for (size_t i = 0; i < SIZEOFARRAY(fc2024_modules); i++)
			vectorof_listof_fc_modules[0].fc_modules.push_back(std::wstring(fc2024_modules[i]));
	}
}

/*****************************************************************************/

static bool is_FCname(const TCHAR* cmdLineParameter, int* vectorIndex)
{
	*vectorIndex = -1;
	for (size_t i = 0; i < vectorof_listof_fc_modules.size(); i++)
	{
		if (!_tcsncmp(cmdLineParameter, &vectorof_listof_fc_modules[i].fc_name[0], vectorof_listof_fc_modules[i].fc_name.size()))
		{
			*vectorIndex = (int)i;
			return true;
		}
	}
	return false;
}

/*****************************************************************************/

static bool is_FCmodule(const TCHAR* cmdLineParameter, int* vectorIndex, int* moduleIndex)
{
	*vectorIndex = -1;
	*moduleIndex = -1;
	for (size_t i = 0; i < vectorof_listof_fc_modules.size(); i++)
	{
		for (size_t j = 0; j < vectorof_listof_fc_modules[i].fc_modules.size(); j++)
		{
			if (!_tcsncmp(cmdLineParameter, vectorof_listof_fc_modules[i].fc_modules[j].c_str(), vectorof_listof_fc_modules[i].fc_modules[j].size()))
			{
				return true;
			}
		}
	}
	return false;
}

/*****************************************************************************/

static size_t unescapeTString(TCHAR* destBuffer, size_t destBufferSize, const TCHAR* srcBuffer)
{
	TCHAR* destPtr = destBuffer;
	const TCHAR* srcPtr = srcBuffer;
	size_t length = 0;

	while ((length < destBufferSize) && (*srcPtr != '\0'))
	{
		if (*srcPtr == (TCHAR)'\\')
		{
			srcPtr++;
			if (*srcPtr == (TCHAR)'x')
			{
				srcPtr++;

				if (_istxdigit(srcPtr[0]) && _istxdigit(srcPtr[1]))
				{
					// \xHH
					unsigned short value = 0;
					for (int i = 0; i < 2; i++)
					{
						value = value << 4;
						if (_istdigit(*srcPtr))
						{
							value += (*srcPtr - (TCHAR)'0');
							srcPtr++;
						}
						else if (_istxdigit(*srcPtr))
						{
							value += (_totlower(*srcPtr) - (TCHAR)'a' + 10);
							srcPtr++;
						}
					}

					*destPtr = (char)value;
					destPtr++;
					length++;
				}
				else if (*srcPtr == (TCHAR)'[')
				{
					srcPtr++;

					// \x[HH<...>]
					while (_istxdigit(srcPtr[0]) && _istxdigit(srcPtr[1]))
					{
						unsigned short value = 0;
						for (int i = 0; i < 2; i++)
						{
							value = value << 4;
							if (_istdigit(*srcPtr))
							{
								value += (*srcPtr - (TCHAR)'0');
								srcPtr++;
							}
							else if (_istxdigit(*srcPtr))
							{
								value += (_totlower(*srcPtr) - (TCHAR)'a' + 10);
								srcPtr++;
							}
						}
						if ((*srcPtr == ',') || (*srcPtr == ' '))
							srcPtr++;
						*destPtr = (char)value;
						destPtr++;
						length++;
					}
					if (*srcPtr == (TCHAR)']')
						srcPtr++;
				}
			}
			else
			{
				switch (*srcPtr)
				{
				case 'a': *destPtr = (TCHAR)'\a'; break;
				case 'b': *destPtr = (TCHAR)'\b'; break;
				case 'e': *destPtr = (TCHAR)0x1B; break;
				case 'f': *destPtr = (TCHAR)'\f'; break;
				case 'n': *destPtr = (TCHAR)'\n'; break;
				case 'r': *destPtr = (TCHAR)'\r'; break;
				case 't': *destPtr = (TCHAR)'\t'; break;
				case 'v': *destPtr = (TCHAR)'\v'; break;
				case '\\': *destPtr = (TCHAR)'\\'; break;
				case '\'': *destPtr = (TCHAR)'\''; break;
				case '\"': *destPtr = (TCHAR)'\"'; break;
				case '?': *destPtr = (TCHAR)'?'; break;
				default:  *destPtr = *srcPtr;  break;
				}
				srcPtr++;
				destPtr++;
				length++;
			}
		}
		else
		{
			*destPtr = *srcPtr;
			srcPtr++;
			destPtr++;
			length++;
		}
	}
	*destPtr = '\0';
	return length;
}

/*****************************************************************************/

static LSTATUS RegOpenKeyExWRecursive(
	HKEY    hKey,
	LPCWSTR lpSubKey,
	DWORD   ulOptions,
	REGSAM  samDesired,
	PHKEY   phkResult
)
{
	if (verbose >= VERBOSE_DEBUG_HIGH)
		_tprintf(_T("RegOpenKeyExWRecursive: RegOpenKeyExWRecursive(\"%s\")\n"), lpSubKey);

	*phkResult = 0;
	if (hKey == NULL)
	{
		if (verbose >= VERBOSE_DEBUG_LOW)
			return ERROR_INVALID_PARAMETER;
		_tprintf(_T("RegOpenKeyExWRecursive: RegOpenKeyEx(\"%s\")  (hKey==NULL) ERROR_INVALID_PARAMETER\n"), lpSubKey);
		return ERROR_INVALID_PARAMETER;
	}
	const TCHAR* pDelimiter = _tcschr(lpSubKey, (wchar_t)'\\');
	if (!pDelimiter)
	{
		LSTATUS retCode = ::RegOpenKeyExW(hKey, lpSubKey, ulOptions, samDesired, phkResult);
		if (retCode != ERROR_SUCCESS)
		{
			if (verbose >= VERBOSE_DEBUG_LOW)
				_tprintf(_T("RegOpenKeyExWRecursive: RegOpenKeyEx(\"%s\") failure 0x%x, lastError=%d\n"), lpSubKey, retCode, GetLastError());
			return -retCode;
		}
		if (verbose >= VERBOSE_DEBUG_MEDIUM)
			_tprintf(_T("RegOpenKeyExWRecursive: RegOpenKeyEx(\"%s\") ERROR_SUCCESS\n"), lpSubKey);
		return ERROR_SUCCESS;
	}

	std::wstring strSubKey(lpSubKey);
	int delimiterIndex = (int)(pDelimiter - lpSubKey);
	strSubKey[delimiterIndex] = '\0';
	if (hKey == HKEY_LOCAL_MACHINE)
	{
		if (!_tcscmp(&strSubKey[0], _T("SOFTWARE")) ||
			!_tcscmp(&strSubKey[0], _T("SYSTEM")))
		{
			strSubKey[delimiterIndex] = '\\';
			pDelimiter = _tcschr(&lpSubKey[delimiterIndex + 1], (wchar_t)'\\');
			if (pDelimiter)
			{
				delimiterIndex = (int)(pDelimiter - lpSubKey);
				strSubKey[delimiterIndex] = '\0';
			}
		}
	}

	HKEY hSubKey = NULL;
	LSTATUS retCode = ::RegOpenKeyExW(hKey, &strSubKey[0], ulOptions, samDesired, &hSubKey);
	if (retCode != ERROR_SUCCESS)
	{
		if (verbose >= VERBOSE_DEBUG_LOW)
			_tprintf(_T("RegOpenKeyExWRecursive: RegOpenKeyEx(\"%s\") failure 0x%x, lastError=%d\n"), &strSubKey[0], retCode, GetLastError());
		return -retCode;
	}
	if (verbose >= VERBOSE_DEBUG_MEDIUM)
		_tprintf(_T("RegOpenKeyExWRecursive: RegOpenKeyEx(\"%s\") success\n"), &strSubKey[0]);

	retCode = RegOpenKeyExWRecursive(hSubKey, &strSubKey[delimiterIndex + 1], ulOptions, samDesired, phkResult);
	::RegCloseKey(hSubKey);
	return retCode;
}

/*****************************************************************************/

static LSTATUS QueryKeyForDCSWorld(size_t index, TCHAR* lpSubKey, std::vector<std::wstring>& DCSpaths, HKEY* phUninstallKey, HKEY* phEnumKey)
{
	LSTATUS retCode = 0;
	DWORD   dwLastError = 0;
	union
	{
		BYTE  szDisplayName[MAX_VALUE_NAME * 2];
		TCHAR wszDisplayName[MAX_VALUE_NAME];
	};
	DWORD cbDisplayName = sizeof(szDisplayName);
	union
	{
		BYTE  szInstallLocation[MAX_VALUE_NAME * 2];
		TCHAR wszInstallLocation[MAX_VALUE_NAME];
	};
	DWORD cbInstallLocation = sizeof(szInstallLocation);

	if (verbose >= VERBOSE_DEBUG_HIGH)
		_tprintf(_T("QueryKeyForDCSWorld: %u) %s:\n"), (unsigned)(index + 1), lpSubKey);

	retCode = ::RegOpenKeyExW(*phUninstallKey,
		lpSubKey,
		0,
		KEY_READ,
		phEnumKey);
	if (retCode != ERROR_SUCCESS)
	{
		if (verbose >= VERBOSE_DEBUG_HIGH)
			_tprintf(_T("QueryKeyForDCSWorld: %u) RegOpenKeyEx(\"<Uninstall>\\%s\") failure 0x%x, lastError=%d\n"), (unsigned)(index + 1), lpSubKey, retCode, GetLastError());
		return -retCode;
	}

	szDisplayName[0] = '\0';
	retCode = ::RegQueryValueExW(*phEnumKey,
		_T("DisplayName"),
		NULL,
		NULL,
		szDisplayName,
		&cbDisplayName);
	if (retCode != ERROR_SUCCESS)
	{
		dwLastError = GetLastError();
		::RegCloseKey(*phEnumKey);
		*phEnumKey = 0;

		if (verbose >= VERBOSE_DEBUG_HIGH)
			_tprintf(_T("QueryKeyForDCSWorld: %u) RegQueryValueExW(\"DisplayName\") failure 0x%x, lastError=%d\n"), (unsigned)(index + 1), retCode, dwLastError);
		return -retCode;
	}

	szInstallLocation[0] = '\0';
	retCode = RegQueryValueExW(*phEnumKey,
		_T("InstallLocation"),
		NULL,
		NULL,
		szInstallLocation,
		&cbInstallLocation);
	if (retCode != ERROR_SUCCESS)
	{
		dwLastError = GetLastError();
		::RegCloseKey(*phEnumKey);
		*phEnumKey = 0;

		if (verbose >= VERBOSE_DEBUG_HIGH)
			_tprintf(_T("QueryKeyForDCSWorld: %u) RegQueryValueExW(\"InstallLocation\") failure 0x%x, lastError=%d\n"), (unsigned)(index + 1), retCode, dwLastError);
		return -retCode;
	}

	::RegCloseKey(*phEnumKey);
	*phEnumKey = 0;

	static const TCHAR* DCS_World = _T("DCS World");
	if (!_tcsstr(wszDisplayName, DCS_World) || (wszInstallLocation[0] == (TCHAR)'\0'))
	{
		if (verbose >= VERBOSE_DEBUG_LOW)
			_tprintf(_T("QueryKeyForDCSWorld: %u) DisplayName=\"%s\"\n"), (unsigned)(index + 1), wszDisplayName);
		return -ERROR_INVALID_DATA;
	}

	if (verbose >= VERBOSE_DEBUG_LOW)
		_tprintf(_T("QueryKeyForDCSWorld: %u) DisplayName=\"%s\", adding InstallLocation=\"%s\"\n"), (unsigned)(index + 1), wszDisplayName, wszInstallLocation);

	DCSpaths.push_back(std::wstring(wszInstallLocation));
	return ERROR_SUCCESS;
}

/*****************************************************************************/

HKEY hUninstallKey = 0;
HKEY hEnumKey = 0;
static LSTATUS QueryWindowsUninstallForDCSWorld(std::vector<std::wstring>& DCSpaths, HKEY* phUninstallKey, HKEY* phEnumKey)
{
	TCHAR    achKey[MAX_KEY_LENGTH];   // buffer for subkey name
	DWORD    cbName = 0;                   // size of name string 
	TCHAR    achClass[MAX_PATH] = TEXT("");  // buffer for class name 
	DWORD    cchClassName = MAX_PATH;  // size of class string 
	DWORD    cSubKeys = 0;               // number of subkeys 
	DWORD    cbMaxSubKey = 0;              // longest subkey size 
	DWORD    cchMaxClass = 0;              // longest class string 
	DWORD    cValues = 0;              // number of values for key 
	DWORD    cchMaxValue = 0;          // longest value name 
	DWORD    cbMaxValueData = 0;       // longest value data 
	DWORD    cbSecurityDescriptor = 0; // size of security descriptor 
	FILETIME ftLastWriteTime;      // last write time 

	DWORD i = 0;
	LSTATUS retCode = 0;
	DWORD dwLastError = 0;

	_tprintf(_T("[Searching registry Uninstall for DCS World]\n"));

	if ((retCode = ::RegOpenKeyExWRecursive(HKEY_LOCAL_MACHINE,
		TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall"),
		0,
		KEY_READ,
		phUninstallKey)) != ERROR_SUCCESS)
	{
		dwLastError = GetLastError();
		if (verbose >= VERBOSE_ERROR)
			printf("QueryWindowsUninstallForDCSWorld: RegOpenKeyEx(\"HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\") failure, lastError=%d\n", dwLastError);
		return -retCode;
	}

	// Get the class name and the value count. 
	retCode = ::RegQueryInfoKeyW(
		*phUninstallKey,         // key handle 
		achClass,                // buffer for class name 
		&cchClassName,           // size of class string 
		NULL,                    // reserved 
		&cSubKeys,               // number of subkeys 
		&cbMaxSubKey,            // longest subkey size 
		&cchMaxClass,            // longest class string 
		&cValues,                // number of values for this key 
		&cchMaxValue,            // longest value name 
		&cbMaxValueData,         // longest value data 
		&cbSecurityDescriptor,   // security descriptor 
		&ftLastWriteTime);       // last write time 

	// Enumerate the subkeys, until RegEnumKeyEx fails.
	if (verbose >= VERBOSE_DEBUG_LOW)
		_tprintf(_T("QueryWindowsUninstallForDCSWorld: Number of subkeys: %d\n"), cSubKeys);
	if (cSubKeys)
	{
		for (i = 0; i < cSubKeys; i++)
		{
			cbName = MAX_KEY_LENGTH;
			retCode = ::RegEnumKeyExW(*phUninstallKey, i,
				achKey,
				&cbName,
				NULL,
				NULL,
				NULL,
				&ftLastWriteTime);

			if (retCode == ERROR_SUCCESS)
			{
				QueryKeyForDCSWorld(i, achKey, DCSpaths, phUninstallKey, phEnumKey);
			}
		}
		for (i = 0; i < DCSpaths.size(); i++)
		{
			if (verbose >= VERBOSE_INFO)
				_tprintf(_T("Found: %d) \"%s\"\n"), (unsigned)(i + 1), DCSpaths[i].c_str());
		}
	}


	::RegCloseKey(*phUninstallKey);
	*phUninstallKey = 0;

	return ERROR_SUCCESS;
}

/*****************************************************************************/

static LSTATUS set_entry_lua__load_immediately(const std::wstring& entry_lua_filename, const std::wstring& module, int true_or_false_or_delete)
{
	DWORD dwLastError = 0;

	// memory map the entry.lua

	HANDLE hEntryLua = CreateFileW(&entry_lua_filename[0], GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hEntryLua == INVALID_HANDLE_VALUE)
	{
		dwLastError = GetLastError();
		if (verbose >= VERBOSE_ERROR)
			_tprintf(_T("CreateFileW(\"%s\")=%p, lastError=%d\n"), &entry_lua_filename[0], hEntryLua, dwLastError);
		return -(LSTATUS)dwLastError;
	}

	DWORD dwFileSizeHigh = 0;
	DWORD dwFileSizeLow = GetFileSize(hEntryLua, &dwFileSizeHigh);

	HANDLE hEntryLuaMapping = CreateFileMappingA(hEntryLua, NULL, PAGE_READONLY, dwFileSizeHigh, dwFileSizeLow, NULL);
	if (hEntryLuaMapping == INVALID_HANDLE_VALUE)
	{
		dwLastError = GetLastError();
		if (verbose >= VERBOSE_ERROR)
			_tprintf(_T("CreateFileMappingA(\"%s\")=%p, lastError=%d\n"), &entry_lua_filename[0], hEntryLuaMapping, dwLastError);
		CloseHandle(hEntryLua);
		return -(LSTATUS)dwLastError;
	}

	LPVOID pEntryLuaView = MapViewOfFile(hEntryLuaMapping, FILE_MAP_READ, 0, 0, dwFileSizeLow);
	if (!pEntryLuaView)
	{
		dwLastError = GetLastError();
		if (verbose >= VERBOSE_ERROR)
			_tprintf(_T("MapViewOfFile(\"%s\")=%p, lastError=%d\n"), &entry_lua_filename[0], pEntryLuaView, dwLastError);
		CloseHandle(hEntryLuaMapping);
		CloseHandle(hEntryLua);
		return -(LSTATUS)dwLastError;
	}

	_tprintf(_T("Opened file \"%s\"\n"), &entry_lua_filename[0]);

	// store contents of entry.lua in std::string

	std::string strEntryLua;
	strEntryLua.resize(dwFileSizeLow);
	size_t blockSize = 4096;
	for (size_t i = 0; i < dwFileSizeLow; i += blockSize)
	{
		size_t bytesToCopy = blockSize;
		if ((i + bytesToCopy) > dwFileSizeLow)
			bytesToCopy = dwFileSizeLow - i;
		memcpy(&strEntryLua[i], ((char*)pEntryLuaView) + i, bytesToCopy);
	}

	UnmapViewOfFile(pEntryLuaView);
	CloseHandle(hEntryLuaMapping);
	// CloseHandle(hEntryLua); don't close file to keep the file locked

	// get search patterns from ini file

	std::wstring raw_pattern_binaries;
	std::wstring raw_pattern_loadImmediately_equals_false;
	std::wstring raw_pattern_loadImmediately_equals_true;
	std::wstring pattern_binaries;
	std::wstring pattern_loadImmediately_equals_false;
	std::wstring pattern_loadImmediately_equals_true;
	DWORD numCharsRead;

	LPCTSTR lpSectionName_DEBUG = _T("DEBUG");
	LPCTSTR lpKeyName_binaries_buffer_size = _T("BINARIES_BUFFER_SIZE");
	binaries_buffer_size = GetPrivateProfileInt(lpSectionName_DEBUG, lpKeyName_binaries_buffer_size, 2048, &szIniFile[0]);
	if (binaries_buffer_size == 0)
		binaries_buffer_size = 2048;

	raw_pattern_binaries.resize(binaries_buffer_size);
	LPCTSTR lpKeyName_binaries = _T("BINARIES");
	numCharsRead = GetPrivateProfileString(&module[0], lpKeyName_binaries, (LPCTSTR)NULL,
		&raw_pattern_binaries[0], (DWORD)raw_pattern_binaries.size(), &szIniFile[0]);
	raw_pattern_binaries.resize(numCharsRead);

	pattern_binaries.resize(binaries_buffer_size);
	pattern_binaries.resize(unescapeTString(&pattern_binaries[0], pattern_binaries.size(), &raw_pattern_binaries[0]));
	if (verbose >= VERBOSE_DEBUG_HIGH)
		_tprintf(_T("%s=%s\n"), lpKeyName_binaries, &raw_pattern_binaries[0]);

	raw_pattern_loadImmediately_equals_false.resize(128);
	LPCTSTR lpKeyName_loadImmediately_equals_false = _T("LOADIMMEDIATELY_EQUALS_FALSE");
	numCharsRead = GetPrivateProfileString(&module[0], lpKeyName_loadImmediately_equals_false, (LPCTSTR)NULL,
		&raw_pattern_loadImmediately_equals_false[0], (DWORD)raw_pattern_loadImmediately_equals_false.size(), &szIniFile[0]);
	raw_pattern_loadImmediately_equals_false.resize(numCharsRead);

	pattern_loadImmediately_equals_false.resize(128);
	pattern_loadImmediately_equals_false.resize(unescapeTString(&pattern_loadImmediately_equals_false[0], pattern_loadImmediately_equals_false.size(), &raw_pattern_loadImmediately_equals_false[0]));
	if (verbose >= VERBOSE_DEBUG_HIGH)
		_tprintf(_T("%s=%s\n"), lpKeyName_loadImmediately_equals_false, &raw_pattern_loadImmediately_equals_false[0]);

	raw_pattern_loadImmediately_equals_true.resize(128);
	LPCTSTR lpKeyName_loadImmediately_equals_true = _T("LOADIMMEDIATELY_EQUALS_TRUE");
	numCharsRead = GetPrivateProfileString(&module[0], lpKeyName_loadImmediately_equals_true, (LPCTSTR)NULL,
		&raw_pattern_loadImmediately_equals_true[0], (DWORD)raw_pattern_loadImmediately_equals_true.size(), &szIniFile[0]);
	raw_pattern_loadImmediately_equals_true.resize(numCharsRead);

	pattern_loadImmediately_equals_true.resize(128);
	pattern_loadImmediately_equals_true.resize(unescapeTString(&pattern_loadImmediately_equals_true[0], pattern_loadImmediately_equals_true.size(), &raw_pattern_loadImmediately_equals_true[0]));
	if (verbose >= VERBOSE_DEBUG_HIGH)
		_tprintf(_T("%s=%s\n"), lpKeyName_loadImmediately_equals_true, &raw_pattern_loadImmediately_equals_true[0]);

	if (!pattern_binaries.size() || !pattern_binaries[0] ||
		!raw_pattern_binaries.size() || !raw_pattern_binaries[0])
	{
		if (verbose >= VERBOSE_DEBUG_LOW)
			_tprintf(_T("ERROR_NOT_SUPPORTED, IniFile missing %s=\n"), lpKeyName_binaries);
		CloseHandle(hEntryLua);
		return -ERROR_NOT_SUPPORTED;
	}
	if (!pattern_loadImmediately_equals_false.size() || !pattern_loadImmediately_equals_false[0] ||
		!raw_pattern_loadImmediately_equals_false.size() || !raw_pattern_loadImmediately_equals_false[0])
	{
		if (verbose >= VERBOSE_DEBUG_LOW)
			_tprintf(_T("ERROR_NOT_SUPPORTED, IniFile missing %s=\n"), lpKeyName_loadImmediately_equals_false);
		CloseHandle(hEntryLua);
		return -ERROR_NOT_SUPPORTED;
	}
	if (!pattern_loadImmediately_equals_true.size() || !pattern_loadImmediately_equals_true[0] ||
		!raw_pattern_loadImmediately_equals_true.size() || !raw_pattern_loadImmediately_equals_true[0])
	{
		if (verbose >= VERBOSE_DEBUG_LOW)
			_tprintf(_T("ERROR_NOT_SUPPORTED, IniFile missing %s=\n"), lpKeyName_loadImmediately_equals_false);
		CloseHandle(hEntryLua);
		return -ERROR_NOT_SUPPORTED;
	}

	// search for BINARIES string

	std::string mbs_pattern_binaries;
	mbs_pattern_binaries.resize(binaries_buffer_size * 2);
	mbs_pattern_binaries.resize(wcstombs(&mbs_pattern_binaries[0], &pattern_binaries[0], binaries_buffer_size * 2));

	size_t find_mbs_pattern_binaries_pos = strEntryLua.find(mbs_pattern_binaries);
	if (find_mbs_pattern_binaries_pos == std::string::npos)
	{
		if (verbose >= VERBOSE_DEBUG_LOW)
			_tprintf(_T("entry.lua missing BINARIES: %s\n"), &raw_pattern_binaries[0]);
		CloseHandle(hEntryLua);
		return ERROR_SUCCESS;
	}

	_tprintf(_T("%s(%u):{%s}\n"), &entry_lua_filename[0], (unsigned)find_mbs_pattern_binaries_pos, _T("BINARIES"));

	// search for LOAD_IMMEDIATELY_EQUALS_FALSE pattern and LOAD_IMMEDIATELY_EQUALS_FALSE pattern, and add to vector

	std::string mbs_pattern_loadImmediately_equals_false;
	mbs_pattern_loadImmediately_equals_false.resize(binaries_buffer_size * 2);
	mbs_pattern_loadImmediately_equals_false.resize(wcstombs(&mbs_pattern_loadImmediately_equals_false[0], &pattern_loadImmediately_equals_false[0], binaries_buffer_size * 2));

	std::string mbs_pattern_loadImmediately_equals_true;
	mbs_pattern_loadImmediately_equals_true.resize(binaries_buffer_size * 2);
	mbs_pattern_loadImmediately_equals_true.resize(wcstombs(&mbs_pattern_loadImmediately_equals_true[0], &pattern_loadImmediately_equals_true[0], binaries_buffer_size * 2));

	int    compare_mbs_pattern_loadImmediately_equals_false = 0;
	int    compare_mbs_pattern_loadImmediately_equals_true = 0;
	size_t start_search_pos = find_mbs_pattern_binaries_pos + mbs_pattern_binaries.size();

	typedef struct load_immediately_struct
	{
		size_t pos;
		size_t length;
	} LOAD_IMMEDIATELY;
	std::vector<LOAD_IMMEDIATELY> load_immediately_vector;

	do
	{
		compare_mbs_pattern_loadImmediately_equals_false = strEntryLua.compare(start_search_pos, mbs_pattern_loadImmediately_equals_false.size(), mbs_pattern_loadImmediately_equals_false);
		if (compare_mbs_pattern_loadImmediately_equals_false == 0)
		{
			_tprintf(_T("%s(%u):<->{%s}\n"), &entry_lua_filename[0], (unsigned)start_search_pos, _T("LOADIMMEDIATELY_EQUALS_FALSE"));
			LOAD_IMMEDIATELY load_immediately =
			{
				start_search_pos, mbs_pattern_loadImmediately_equals_false.size()
			};
			load_immediately_vector.push_back(load_immediately);
			start_search_pos += mbs_pattern_loadImmediately_equals_false.size();
		}

		compare_mbs_pattern_loadImmediately_equals_true = strEntryLua.compare(start_search_pos, mbs_pattern_loadImmediately_equals_true.size(), mbs_pattern_loadImmediately_equals_true);
		if (compare_mbs_pattern_loadImmediately_equals_true == 0)
		{
			_tprintf(_T("%s(%u):<->{%s}\n"), &entry_lua_filename[0], (unsigned)start_search_pos, _T("LOADIMMEDIATELY_EQUALS_TRUE"));
			LOAD_IMMEDIATELY load_immediately =
			{
				start_search_pos, mbs_pattern_loadImmediately_equals_true.size()
			};
			load_immediately_vector.push_back(load_immediately);
			start_search_pos += mbs_pattern_loadImmediately_equals_true.size();
		}

	} while ((compare_mbs_pattern_loadImmediately_equals_false == 0) ||
		(compare_mbs_pattern_loadImmediately_equals_true == 0));

	if ((true_or_false_or_delete < 0) && (load_immediately_vector.size() == 0))
	{
		// delete LOAD_IMMEDIATELY_EQUALS_FALSE pattern and LOAD_IMMEDIATELY_EQUALS_TRUE patterh, nothing to do
		CloseHandle(hEntryLua);
		if (verbose >= VERBOSE_DEBUG_HIGH)
			_tprintf(_T("LOAD_IMMEDIATELY_EQUALS_FALSE and LOAD_IMMEDIATELY_EQUALS_TRUE not found\n"));
		return ERROR_SUCCESS;
	}

	// remove matching LOAD_IMMEDIATELY_EQUALS_FALSE pattern and LOAD_IMMEDIATELY_EQUALS_FALSE pattern in reverse order

	if (verbose >= VERBOSE_DEBUG_HIGH)
		_tprintf(_T("removing LOAD_IMMEDIATELY_EQUALS_FALSE and LOAD_IMMEDIATELY_EQUALS_TRUE\n"));
	for (int i = (int)load_immediately_vector.size() - 1; i >= 0; i--)
	{
		strEntryLua = strEntryLua.erase(load_immediately_vector[i].pos, load_immediately_vector[i].length);
	}

	// insert new LOAD_IMMEDIATELY_EQUALS_FALSE pattern or LOAD_IMMEDIATELY_EQUALS_TRUE patterh

	size_t end_mbs_pattern_binaries_pos = find_mbs_pattern_binaries_pos + mbs_pattern_binaries.size();
	if (true_or_false_or_delete > 0)
	{
		// insert "load_immediately = true,\r\n" immediately after binaries block
		strEntryLua = strEntryLua.insert(end_mbs_pattern_binaries_pos, mbs_pattern_loadImmediately_equals_true);
		_tprintf(_T("%s(%u):<+>{%s}\n"), &entry_lua_filename[0], (unsigned)end_mbs_pattern_binaries_pos, _T("LOADIMMEDIATELY_EQUALS_TRUE"));
	}
	else if (true_or_false_or_delete == 0)
	{
		// insert "load_immediately = false,\r\n" immediately after binaries block
		strEntryLua = strEntryLua.insert(end_mbs_pattern_binaries_pos, mbs_pattern_loadImmediately_equals_false);
		_tprintf(_T("%s(%u):<+>{%s}\n"), &entry_lua_filename[0], (unsigned)end_mbs_pattern_binaries_pos, _T("LOADIMMEDIATELY_EQUALS_FALSE"));
	}

	// create tmp file to save changes

	std::wstring entry_lua_filename_tmp;
	entry_lua_filename_tmp += entry_lua_filename;
	entry_lua_filename_tmp += _T(".load_immediately.tmp");

	HANDLE hEntryLuaTmp = CreateFileW(&entry_lua_filename_tmp[0], GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hEntryLuaTmp == INVALID_HANDLE_VALUE)
	{
		dwLastError = GetLastError();
		if (verbose >= VERBOSE_ERROR)
			_tprintf(_T("CreateFileW(\"%s\")=%p, lastError=%d\n"), &entry_lua_filename_tmp[0], hEntryLuaTmp, dwLastError);
		CloseHandle(hEntryLua);
		return -(LSTATUS)dwLastError;
	}

	DWORD dwNumberOfBytesWritten = 0;
	if (!WriteFile(hEntryLuaTmp, &strEntryLua[0], (DWORD)strEntryLua.size(), &dwNumberOfBytesWritten, NULL))
	{
		dwLastError = GetLastError();
		if (verbose >= VERBOSE_ERROR)
			_tprintf(_T("WriteFile(\"%s\")=false, lastError=%d\n"), &entry_lua_filename_tmp[0], dwLastError);
		CloseHandle(hEntryLuaTmp);
		CloseHandle(hEntryLua);
		return -(LSTATUS)dwLastError;
	}

	std::wstring entry_lua_filename_bak;
	entry_lua_filename_bak += entry_lua_filename;
	entry_lua_filename_bak += std::wstring(_T(".load_immediately.bak"));

	// preserve file attributes

	FILE_BASIC_INFO fileBasicInfo_entry_lua;
	FILE_BASIC_INFO fileBasicInfo_entry_lua_tmp;
	if (!GetFileInformationByHandleEx(hEntryLua, FileBasicInfo, &fileBasicInfo_entry_lua, sizeof(fileBasicInfo_entry_lua)))
	{
		dwLastError = GetLastError();
		if (verbose >= VERBOSE_DEBUG_LOW)
			_tprintf(_T("GetFileInformationByHandleEx(\"%s\")=false, lastError=%d\n"), &entry_lua_filename[0], dwLastError);
	}
	else if (!GetFileInformationByHandleEx(hEntryLuaTmp, FileBasicInfo, &fileBasicInfo_entry_lua_tmp, sizeof(fileBasicInfo_entry_lua_tmp)))
	{
		dwLastError = GetLastError();
		if (verbose >= VERBOSE_DEBUG_LOW)
			_tprintf(_T("GetFileInformationByHandleEx(\"%s\")=false, lastError=%d\n"), &entry_lua_filename_tmp[0], dwLastError);
	}
	else
	{
		fileBasicInfo_entry_lua_tmp.CreationTime = fileBasicInfo_entry_lua.CreationTime;
		fileBasicInfo_entry_lua_tmp.LastWriteTime = fileBasicInfo_entry_lua.LastWriteTime;
		if (!SetFileInformationByHandle(hEntryLuaTmp, FileBasicInfo, &fileBasicInfo_entry_lua_tmp, sizeof(fileBasicInfo_entry_lua_tmp)))
		{
			dwLastError = GetLastError();
			if (verbose >= VERBOSE_DEBUG_LOW)
				_tprintf(_T("SetFileInformationByHandle(\"%s\")=false, lastError=%d\n"), &entry_lua_filename_tmp[0], dwLastError);
		}
	}

	// transactional update

	DeleteFile(&entry_lua_filename_bak[0]); // delete existing entry.lua backup before MoveFile
	CloseHandle(hEntryLuaTmp);
	CloseHandle(hEntryLua);
	if (!MoveFile(&entry_lua_filename[0], &entry_lua_filename_bak[0]))
	{
		dwLastError = GetLastError();
		if (verbose >= VERBOSE_ERROR)
			_tprintf(_T("MoveFile(\"%s\", \"%s\")=false, lastError=%d\n"), &entry_lua_filename[0], &entry_lua_filename_bak[0], dwLastError);
		return -(LSTATUS)dwLastError;
	}
	if (!MoveFile(&entry_lua_filename_tmp[0], &entry_lua_filename[0]))
	{
		dwLastError = GetLastError();
		if (verbose >= VERBOSE_ERROR)
			_tprintf(_T("MoveFile(\"%s\", \"%s\")=false, lastError=%d\n"), &entry_lua_filename_tmp[0], &entry_lua_filename[0], dwLastError);
		return -(LSTATUS)dwLastError;
	}
	if (backupLua == 0)
	{
		// don't keep entry.lua backup
		DeleteFile(&entry_lua_filename_bak[0]);
	}
	return 1;
}

/*****************************************************************************/

static LSTATUS set_modules_entry_lua__load_immediately(std::vector<std::wstring>& DCSpaths, const std::vector<std::wstring>& modules, int true_or_false_or_delete)
{
	if (true_or_false_or_delete > 0)
		_tprintf(_T("Set \"load_immediately = true\"\n"));
	else if (true_or_false_or_delete == 0)
		_tprintf(_T("Set \"load_immediately = false\"\n"));
	else
		_tprintf(_T("Delete \"load_immediately = <true|false>\"\n"));

	LSTATUS savedLastStatus = ERROR_SUCCESS;
	for (size_t i = 0; i < DCSpaths.size(); i++)
	{
		// remove trailing backslash
		size_t length = DCSpaths[i].size();
		if (length > 0)
		{
			if (DCSpaths[i][length - 1] == '\\')
				DCSpaths[i].resize(length - 1);

		}
		for (size_t j = 0; j < modules.size(); j++)
		{
			std::wstring entry_lua_filename;
			try
			{
				entry_lua_filename += DCSpaths[i];
				entry_lua_filename += std::wstring(_T("\\Mods\\Aircraft\\"));
				entry_lua_filename += modules[j];
				entry_lua_filename += std::wstring(_T("\\entry.lua"));

				_tprintf(_T("%u) Configuring %s"), (unsigned)(j + 1), modules[j].c_str());

				LSTATUS retCode = set_entry_lua__load_immediately(entry_lua_filename, modules[j], true_or_false_or_delete);
				if (retCode < ERROR_SUCCESS)
				{
					savedLastStatus = retCode;
				}
			}
			catch (...)
			{
			}
		}
	}
	_tprintf(_T("\n"));
	return savedLastStatus;
}

/*****************************************************************************/

static LSTATUS print_entry_lua__load_immediately(const std::wstring& entry_lua_filename, const std::wstring& module)
{
	DWORD dwLastError = 0;

	// memory map the entry.lua

	HANDLE hEntryLua = CreateFileW(&entry_lua_filename[0], GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hEntryLua == INVALID_HANDLE_VALUE)
	{
		dwLastError = GetLastError();
		if (verbose >= VERBOSE_ERROR)
			_tprintf(_T("CreateFileW(\"%s\")=%p, lastError=%d\n"), &entry_lua_filename[0], hEntryLua, dwLastError);
		return -(LSTATUS)dwLastError;
	}

	DWORD dwFileSizeHigh = 0;
	DWORD dwFileSizeLow = GetFileSize(hEntryLua, &dwFileSizeHigh);

	HANDLE hEntryLuaMapping = CreateFileMappingA(hEntryLua, NULL, PAGE_READONLY, dwFileSizeHigh, dwFileSizeLow, NULL);
	if (hEntryLuaMapping == INVALID_HANDLE_VALUE)
	{
		dwLastError = GetLastError();
		if (verbose >= VERBOSE_ERROR)
			_tprintf(_T("CreateFileMappingA(\"%s\")=%pd, lastError=%d\n"), &entry_lua_filename[0], hEntryLuaMapping, dwLastError);
		CloseHandle(hEntryLua);
		return -(LSTATUS)dwLastError;
	}

	LPVOID pEntryLuaView = MapViewOfFile(hEntryLuaMapping, FILE_MAP_READ, 0, 0, dwFileSizeLow);
	if (!pEntryLuaView)
	{
		dwLastError = GetLastError();
		if (verbose >= VERBOSE_ERROR)
			_tprintf(_T("MapViewOfFile(\"%s\")=%p, lastError=%d\n"), &entry_lua_filename[0], pEntryLuaView, dwLastError);
		CloseHandle(hEntryLuaMapping);
		CloseHandle(hEntryLua);
		return -(LSTATUS)dwLastError;
	}

	_tprintf(_T("Opened file \"%s\"\n"), &entry_lua_filename[0]);

	// store contents of entry.lua in std::string

	std::string strEntryLua;
	strEntryLua.resize(dwFileSizeLow);
	size_t blockSize = 4096;
	for (size_t i = 0; i < dwFileSizeLow; i += blockSize)
	{
		size_t bytesToCopy = blockSize;
		if ((i + bytesToCopy) > dwFileSizeLow)
			bytesToCopy = dwFileSizeLow - i;
		memcpy(&strEntryLua[i], ((char*)pEntryLuaView) + i, bytesToCopy);
	}

	UnmapViewOfFile(pEntryLuaView);
	CloseHandle(hEntryLuaMapping);
	CloseHandle(hEntryLua);

	// get search patterns from ini file

	std::wstring raw_pattern_binaries;
	std::wstring raw_pattern_loadImmediately_equals_false;
	std::wstring raw_pattern_loadImmediately_equals_true;
	std::wstring pattern_binaries;
	std::wstring pattern_loadImmediately_equals_false;
	std::wstring pattern_loadImmediately_equals_true;
	DWORD numCharsRead;

	LPCTSTR lpSectionName_DEBUG = _T("DEBUG");
	LPCTSTR lpKeyName_binaries_buffer_size = _T("BINARIES_BUFFER_SIZE");
	binaries_buffer_size = GetPrivateProfileInt(lpSectionName_DEBUG, lpKeyName_binaries_buffer_size, 2048, &szIniFile[0]);
	if (binaries_buffer_size == 0)
		binaries_buffer_size = 2048;

	raw_pattern_binaries.resize(binaries_buffer_size);
	LPCTSTR lpKeyName_binaries = _T("BINARIES");
	numCharsRead = GetPrivateProfileString(&module[0], lpKeyName_binaries, (LPCTSTR)NULL,
		&raw_pattern_binaries[0], (DWORD)raw_pattern_binaries.size(), &szIniFile[0]);
	raw_pattern_binaries.resize(numCharsRead);

	pattern_binaries.resize(binaries_buffer_size);
	pattern_binaries.resize(unescapeTString(&pattern_binaries[0], pattern_binaries.size(), &raw_pattern_binaries[0]));
	if (verbose >= VERBOSE_DEBUG_HIGH)
		_tprintf(_T("%s=%s\n"), lpKeyName_binaries, &raw_pattern_binaries[0]);

	raw_pattern_loadImmediately_equals_false.resize(128);
	LPCTSTR lpKeyName_loadImmediately_equals_false = _T("LOADIMMEDIATELY_EQUALS_FALSE");
	numCharsRead = GetPrivateProfileString(&module[0], lpKeyName_loadImmediately_equals_false, (LPCTSTR)NULL,
		&raw_pattern_loadImmediately_equals_false[0], (DWORD)raw_pattern_loadImmediately_equals_false.size(), &szIniFile[0]);
	raw_pattern_loadImmediately_equals_false.resize(numCharsRead);

	pattern_loadImmediately_equals_false.resize(128);
	pattern_loadImmediately_equals_false.resize(unescapeTString(&pattern_loadImmediately_equals_false[0], pattern_loadImmediately_equals_false.size(), &raw_pattern_loadImmediately_equals_false[0]));
	if (verbose >= VERBOSE_DEBUG_HIGH)
		_tprintf(_T("%s=%s\n"), lpKeyName_loadImmediately_equals_false, &raw_pattern_loadImmediately_equals_false[0]);

	raw_pattern_loadImmediately_equals_true.resize(128);
	LPCTSTR lpKeyName_loadImmediately_equals_true = _T("LOADIMMEDIATELY_EQUALS_TRUE");
	numCharsRead = GetPrivateProfileString(&module[0], lpKeyName_loadImmediately_equals_true, (LPCTSTR)NULL,
		&raw_pattern_loadImmediately_equals_true[0], (DWORD)raw_pattern_loadImmediately_equals_true.size(), &szIniFile[0]);
	raw_pattern_loadImmediately_equals_true.resize(numCharsRead);

	pattern_loadImmediately_equals_true.resize(128);
	pattern_loadImmediately_equals_true.resize(unescapeTString(&pattern_loadImmediately_equals_true[0], pattern_loadImmediately_equals_true.size(), &raw_pattern_loadImmediately_equals_true[0]));
	if (verbose >= VERBOSE_DEBUG_HIGH)
		_tprintf(_T("%s=%s\n"), lpKeyName_loadImmediately_equals_true, &raw_pattern_loadImmediately_equals_true[0]);

	if (!pattern_binaries.size() || !pattern_binaries[0] ||
		!raw_pattern_binaries.size() || !raw_pattern_binaries[0])
	{
		if (verbose >= VERBOSE_DEBUG_LOW)
			_tprintf(_T("ERROR_NOT_SUPPORTED, IniFile missing %s=\n"), lpKeyName_binaries);
		return -ERROR_NOT_SUPPORTED;
	}
	if (!pattern_loadImmediately_equals_false.size() || !pattern_loadImmediately_equals_false[0] ||
		!raw_pattern_loadImmediately_equals_false.size() || !raw_pattern_loadImmediately_equals_false[0])
	{
		if (verbose >= VERBOSE_DEBUG_LOW)
			_tprintf(_T("ERROR_NOT_SUPPORTED, IniFile missing %s=\n"), lpKeyName_loadImmediately_equals_false);
		return -ERROR_NOT_SUPPORTED;
	}
	if (!pattern_loadImmediately_equals_true.size() || !pattern_loadImmediately_equals_true[0] ||
		!raw_pattern_loadImmediately_equals_true.size() || !raw_pattern_loadImmediately_equals_true[0])
	{
		if (verbose >= VERBOSE_DEBUG_LOW)
			_tprintf(_T("ERROR_NOT_SUPPORTED, IniFile missing %s=\n"), lpKeyName_loadImmediately_equals_false);
		return -ERROR_NOT_SUPPORTED;
	}

	// search for BINARIES pattern

	std::string mbs_pattern_binaries;
	mbs_pattern_binaries.resize(binaries_buffer_size * 2);
	mbs_pattern_binaries.resize(wcstombs(&mbs_pattern_binaries[0], &pattern_binaries[0], binaries_buffer_size * 2));

	size_t find_mbs_pattern_binaries_pos = strEntryLua.find(mbs_pattern_binaries);
	if (find_mbs_pattern_binaries_pos == std::string::npos)
	{
		if (verbose >= VERBOSE_DEBUG_LOW)
			_tprintf(_T("entry.lua missing BINARIES: %s\n"), &raw_pattern_binaries[0]);
		return ERROR_SUCCESS;
	}

	_tprintf(_T("%s(%u):{%s}\n"), &entry_lua_filename[0], (unsigned)find_mbs_pattern_binaries_pos, _T("BINARIES"));

	// search for LOAD_IMMEDIATELY_EQUALS_FALSE pattern and LOAD_IMMEDIATELY_EQUALS_FALSE pattern

	std::string mbs_pattern_loadImmediately_equals_false;
	mbs_pattern_loadImmediately_equals_false.resize(binaries_buffer_size * 2);
	mbs_pattern_loadImmediately_equals_false.resize(wcstombs(&mbs_pattern_loadImmediately_equals_false[0], &pattern_loadImmediately_equals_false[0], binaries_buffer_size * 2));

	std::string mbs_pattern_loadImmediately_equals_true;
	mbs_pattern_loadImmediately_equals_true.resize(binaries_buffer_size * 2);
	mbs_pattern_loadImmediately_equals_true.resize(wcstombs(&mbs_pattern_loadImmediately_equals_true[0], &pattern_loadImmediately_equals_true[0], binaries_buffer_size * 2));

	int    compare_mbs_pattern_loadImmediately_equals_false = 0;
	int    compare_mbs_pattern_loadImmediately_equals_true = 0;
	size_t start_search_pos = find_mbs_pattern_binaries_pos + mbs_pattern_binaries.size();

	do
	{
		compare_mbs_pattern_loadImmediately_equals_false = strEntryLua.compare(start_search_pos, mbs_pattern_loadImmediately_equals_false.size(), mbs_pattern_loadImmediately_equals_false);
		if (compare_mbs_pattern_loadImmediately_equals_false == 0)
		{
			_tprintf(_T("%s(%u):{%s}\n"), &entry_lua_filename[0], (unsigned)start_search_pos, _T("LOADIMMEDIATELY_EQUALS_FALSE"));

			start_search_pos += mbs_pattern_loadImmediately_equals_false.size();
		}

		compare_mbs_pattern_loadImmediately_equals_true = strEntryLua.compare(start_search_pos, mbs_pattern_loadImmediately_equals_true.size(), mbs_pattern_loadImmediately_equals_true);
		if (compare_mbs_pattern_loadImmediately_equals_true == 0)
		{
			_tprintf(_T("%s(%u):{%s}\n"), &entry_lua_filename[0], (unsigned)start_search_pos, _T("LOADIMMEDIATELY_EQUALS_TRUE"));

			start_search_pos += mbs_pattern_loadImmediately_equals_true.size();
		}

	} while ((compare_mbs_pattern_loadImmediately_equals_false == 0) ||
		(compare_mbs_pattern_loadImmediately_equals_true == 0));

	return 1;
}

/*****************************************************************************/

static LSTATUS print_modules_entry_lua__load_immediately(std::vector<std::wstring>& DCSpaths, const std::vector<std::wstring>& modules)
{
	_tprintf(_T("Searching for \"load_immediately = <true|false>\"\n"));

	LSTATUS savedLastError = ERROR_SUCCESS;
	for (size_t i = 0; i < DCSpaths.size(); i++)
	{
		// remove trailing backslash
		size_t length = DCSpaths[i].size();
		if (length > 0)
		{
			if (DCSpaths[i][length - 1] == '\\')
				DCSpaths[i].resize(length - 1);

		}
		for (size_t j = 0; j < modules.size(); j++)
		{
			std::wstring entry_lua_filename;
			try
			{
				entry_lua_filename += DCSpaths[i];
				entry_lua_filename += std::wstring(_T("\\Mods\\Aircraft\\"));
				entry_lua_filename += modules[j];
				entry_lua_filename += std::wstring(_T("\\entry.lua"));

				_tprintf(_T("%u) Searching %s:\n"), (unsigned)(j + 1), modules[j].c_str());

				int retCode = print_entry_lua__load_immediately(entry_lua_filename, modules[j]);
				if (retCode < ERROR_SUCCESS)
				{
					savedLastError = retCode;
				}
			}
			catch (...)
			{
			}
		}
	}
	_tprintf(_T("\n"));
	return savedLastError;
}

/*****************************************************************************/

const char szDefaultIniFile[] =
";---------------------------------------\r\n"
"; Compatibile with DCS 2.9.7.59074      \r\n"
";---------------------------------------\r\n"
"[DEBUG]\r\n"
"\r\n"
";VERBOSE=[0-7]\r\n"
"VERBOSE=4\r\n"
"\r\n"
";DCSPATH=C:\\Program Files (x86)\\DCSWorld\r\n"
";DCSPATH=C:\\Program Files (x86)\\Steam\\steamapps\\common\\DCSWorld\r\n"
"\r\n"
";#######################################\r\n"
"[FC_LIST]\r\n"
"FC3=A-10A,F-15C,MiG-29,Su-25A,Su-25T,Su-27,Su-33\r\n"
"FC2024=A-10A,F-15C,F-5E_FC,F-86_FC,MiG-15bis_FC,MiG-29,Su-25A,Su-25T,Su-27,Su-33\r\n"
";#######################################\r\n"
"[A-10A]\r\n"
";---------------------------------------\r\n"
";binaries 	 =\r\n"
";{\r\n"
";'A10ACWS',\r\n"
";'A10A',\r\n"
";},\r\n"
";---------------------------------------\r\n"
"BINARIES=\\r\\nbinaries 	 =\\r\\n{\\r\\n'A10ACWS',\\r\\n'A10A',\\r\\n},\\r\\n\r\n"
"LOADIMMEDIATELY_EQUALS_FALSE=load_immediately = false,\\r\\n\r\n"
"LOADIMMEDIATELY_EQUALS_TRUE=load_immediately = true,\\r\\n\r\n"
"\r\n"
";#######################################\r\n"
"[A-10C]\r\n"
";---------------------------------------\r\n"
";binaries 	 =\r\n"
";{\r\n"
";'A10',\r\n"
";\"Cockpit_A10Common\",\r\n"
";\"Cockpit_A10C\",\r\n"
";},\r\n"
";---------------------------------------\r\n"
"BINARIES=\\r\\nbinaries 	 =\\r\\n{\\r\\n'A10',\\r\\n\"Cockpit_A10Common\",\\r\\n\"Cockpit_A10C\",\\r\\n},\\r\\n\r\n"
"LOADIMMEDIATELY_EQUALS_FALSE=load_immediately = false,\\r\\n\r\n"
"LOADIMMEDIATELY_EQUALS_TRUE=load_immediately = true,\\r\\n\r\n"
"\r\n"
";#######################################\r\n"
"[F-5E_FC]\r\n"
";---------------------------------------\r\n"
";binaries =\r\n"
";{\r\n"
";	'F5E_FC',\r\n"
";},\r\n"
";---------------------------------------\r\n"
"BINARIES=\\r\\nbinaries =\\r\\n{\\r\\n	'F5E_FC',\\r\\n},\\r\\n\r\n"
"LOADIMMEDIATELY_EQUALS_FALSE=load_immediately = false,\\r\\n\r\n"
"LOADIMMEDIATELY_EQUALS_TRUE=load_immediately = true,\\r\\n\r\n"
"\r\n"
";#######################################\r\n"
"[F-15C]\r\n"
";---------------------------------------\r\n"
";binaries =\r\n"
";{\r\n"
";'F15CCWS',\r\n"
";'F15'\r\n"
";},\r\n"
";---------------------------------------\r\n"
"BINARIES=\\r\\nbinaries =\\r\\n{\\r\\n'F15CCWS',\\r\\n'F15'\\r\\n},\\r\\n\r\n"
"LOADIMMEDIATELY_EQUALS_FALSE=load_immediately = false,\\r\\n\r\n"
"LOADIMMEDIATELY_EQUALS_TRUE=load_immediately = true,\\r\\n\r\n"
"\r\n"
";#######################################\r\n"
"[F-86_FC]\r\n"
";---------------------------------------\r\n"
";binaries =\r\n"
";{\r\n"
";	'F86_FC',\r\n"
";},\r\n"
";---------------------------------------\r\n"
"BINARIES=\\r\\nbinaries =\\r\\n{\\r\\n	'F86_FC',\\r\\n},\\r\\n\r\n"
"LOADIMMEDIATELY_EQUALS_FALSE=load_immediately = false,\\r\\n\r\n"
"LOADIMMEDIATELY_EQUALS_TRUE=load_immediately = true,\\r\\n\r\n"
"\r\n"
";#######################################\r\n"
"[MiG-15bis_FC]\r\n"
";---------------------------------------\r\n"
";binaries =\r\n"
";{\r\n"
";	'Mig15_FC',\r\n"
";},\r\n"
";---------------------------------------\r\n"
"BINARIES=\\r\\nbinaries =\\r\\n{\\r\\n	'Mig15_FC',\\r\\n},\\r\\n\r\n"
"LOADIMMEDIATELY_EQUALS_FALSE=load_immediately = false,\\r\\n\r\n"
"LOADIMMEDIATELY_EQUALS_TRUE=load_immediately = true,\\r\\n\r\n"
"\r\n"
";#######################################\r\n"
"[MiG-29]\r\n"
";---------------------------------------\r\n"
";binaries 	 =\r\n"
";{\r\n"
";'MiG29',\r\n"
";'MIG29CWS'\r\n"
";},\r\n"
";---------------------------------------\r\n"
"BINARIES=\\r\\nbinaries 	 =\\r\\n{\\r\\n'MiG29',\\r\\n'MIG29CWS'\\r\\n},\\r\\n\r\n"
"LOADIMMEDIATELY_EQUALS_FALSE=load_immediately = false,\\r\\n\r\n"
"LOADIMMEDIATELY_EQUALS_TRUE=load_immediately = true,\\r\\n\r\n"
"\r\n"
";#######################################\r\n"
"[P-51D]\r\n"
";---------------------------------------\r\n"
";binaries 	 =\r\n"
";{\r\n"
";'P51B',\r\n"
";'Cockpit_P51D'\r\n"
";},\r\n"
";---------------------------------------\r\n"
"BINARIES=\\r\\nbinaries 	 =\\r\\n{\\r\\n'P51B',\\r\\n'Cockpit_P51D'\\r\\n},\\r\\n\r\n"
"LOADIMMEDIATELY_EQUALS_FALSE=load_immediately = false,\\r\\n\r\n"
"LOADIMMEDIATELY_EQUALS_TRUE=load_immediately = true,\\r\\n\r\n"
"\r\n"
";#######################################\r\n"
"[Su-25A]\r\n"
";---------------------------------------\r\n"
";binaries 	 =\r\n"
";{\r\n"
";'SU25ACWS',\r\n"
";},\r\n"
";---------------------------------------\r\n"
"BINARIES=\\r\\nbinaries 	 =\\r\\n{\\r\\n'SU25ACWS',\\r\\n},\\r\\n\r\n"
"LOADIMMEDIATELY_EQUALS_FALSE=load_immediately = false,\\r\\n\r\n"
"LOADIMMEDIATELY_EQUALS_TRUE=load_immediately = true,\\r\\n\r\n"
"\r\n"
";#######################################\r\n"
"[Su-25T]\r\n"
";---------------------------------------\r\n"
";Options =\\r\\n\r\n"
";    {\\r\\n\r\n"
";        {\\r\\n\r\n"
";            name\\t\\t= _(\"Su-25T\"),\\r\\n\r\n"
";            nameId\\t\\t= \"Su-25T\",\\r\\n\r\n"
";            dir\\t\\t\\t= \"Options\",\\r\\n\r\n"
";            CLSID\\t\\t= \"{Su-25T options}\"\r\n"
";        },\r\n"
";    }, \\t\\r\\n\r\n"
";---------------------------------------\r\n"
"BINARIES=\\r\\nOptions =\\r\\n    {\\r\\n        {\\r\\n            name\\t\\t= _(\\\"Su-25T\\\"),\\r\\n            nameId\\t\\t= \\\"Su-25T\\\",\\r\\n            dir\\t\\t\\t= \\\"Options\\\",\\r\\n            CLSID\\t\\t= \\\"{Su-25T options}\\\"\\r\\n        },\\r\\n    }, \\t\\r\\n\r\n"
"LOADIMMEDIATELY_EQUALS_FALSE=load_immediately = false,\\r\\n\r\n"
"LOADIMMEDIATELY_EQUALS_TRUE=load_immediately = true,\\r\\n\r\n"
"\r\n"
";#######################################\r\n"
"[Su-27]\r\n"
";---------------------------------------\r\n"
";binaries 	 =\r\n"
";{\r\n"
";'Su27',\r\n"
";'SU27CWS'\r\n"
";},\r\n"
";---------------------------------------\r\n"
"BINARIES=\\r\\nbinaries 	 =\\r\\n{\\r\\n'Su27',\\r\\n'SU27CWS'\\r\\n},\\r\\n\r\n"
"LOADIMMEDIATELY_EQUALS_FALSE=load_immediately = false,\\r\\n\r\n"
"LOADIMMEDIATELY_EQUALS_TRUE=load_immediately = true,\\r\\n\r\n"
"\r\n"
";#######################################\r\n"
"[Su-33]\r\n"
";---------------------------------------\r\n"
";binaries 	 =\r\n"
";{\r\n"
";'Su33',\r\n"
";'SU33CWS'\r\n"
";},\r\n"
";---------------------------------------\r\n"
"BINARIES=\\r\\nbinaries 	 =\\r\\n{\\r\\n'Su33',\\r\\n'SU33CWS'\\r\\n},\\r\\n\r\n"
"LOADIMMEDIATELY_EQUALS_FALSE=load_immediately = false,\\r\\n\r\n"
"LOADIMMEDIATELY_EQUALS_TRUE=load_immediately = true,\\r\\n\r\n"
"\r\n"
";#######################################\r\n"
"[TF-51D]\r\n"
";---------------------------------------\r\n"
";---------------------------------------\r\n"
"\r\n";

#define F_OK 0
static LSTATUS createInifileWithDefaults(const std::wstring& szIniFile)
{
	DWORD dwLastError = 0;

	std::wstring szIniFileBak = szIniFile;
	szIniFileBak += _T(".bak");
	if (_taccess(&szIniFile[0], F_OK) == 0)
	{
		DeleteFile(&szIniFileBak[0]);
		if (!MoveFile(&szIniFile[0], &szIniFileBak[0]))
		{
			dwLastError = GetLastError();
			if (verbose >= VERBOSE_ERROR)
				_tprintf(_T("MoveFile(\"%s\", \"%s\")=false, lastError=%d\n"), &szIniFile[0], &szIniFileBak[0], dwLastError);
		}
	}

	HANDLE hIniFile = CreateFileW(&szIniFile[0], GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hIniFile == INVALID_HANDLE_VALUE)
	{
		dwLastError = GetLastError();
		if (verbose >= VERBOSE_ERROR)
			_tprintf(_T("CreateFileW(\"%s\")=%p, lastError=%d\n"), &szIniFile[0], hIniFile, dwLastError);
		return -(LSTATUS)dwLastError;
	}

	DWORD dwNumberOfBytesWritten = 0;
	// Write excluding terminaating NUL character
	if (!WriteFile(hIniFile, szDefaultIniFile, sizeof(szDefaultIniFile) - 1, &dwNumberOfBytesWritten, NULL))
	{
		dwLastError = GetLastError();
		if (verbose >= VERBOSE_ERROR)
			_tprintf(_T("WriteFile(\"%s\")=false, lastError=%d\n"), &szIniFile[0], dwLastError);
		CloseHandle(hIniFile);
		return -(LSTATUS)dwLastError;
	}
	CloseHandle(hIniFile);
	return ERROR_SUCCESS;
}

/*****************************************************************************/

static void print_help(int argc, const TCHAR* argv[])
{
	argc;
	const TCHAR* pCmd = _tcsrchr(argv[0], L'\\');
	if (!pCmd)
		pCmd = argv[0];

	printf("\n");
	printf("GlobalFixForAllFC3DependentMods version 2.9.7.59074  Copyright(C) 2024 steam:cj43g3r aka searching46dof@github.com\n");
	printf("For details see https://forum.dcs.world/topic/355315-global-fix-for-all-fc3-dependent-mods/\n");
	printf("and https://forum.dcs.world/topic/252855-f-22a-raptor-mod-enhancement-mod/page/54/#comment-5495698\n");
	printf("  Special thanks to SkateZilla and everyone involved in debugging/testing the issue\n");
	printf("Usage: %s <options>\n", "GlobalFixForAllFC3DependentMods.exe");
	printf("where <options>:\n");
	printf(" /help or /?                display help screen\n");
	printf(" /LICENSE                   display GPL3 license\n");
	printf(" /VERBOSE=<verbosity>       set verbosity level 0-7, default=4\n");
	printf(" /DEFAULTS                  creates inifile with defaults in current directory\n");
	printf(" /DCSPATH=<DCShomePath>     override autodetected DCS home path\n");
	printf("   e.g. /DCSPATH=\"C:\\Program Files (x86)\\DCSWorld\"\n");
	printf("   e.g. /DCSPATH=\"C:\\Program Files (x86)\\Steam\\steamapps\\common\\DCSWorld\"\n");
	printf(" /BAK=[1|0]                 1=true(default) or 0=false, persistent entry.lua.load_immediately.bak backup file after update\n");
	printf(" /MOD:<MOD>                 search/print load_immediately values via search for BINARIES string\n");
	printf("                            immediately followed by LOADIMMEDIATELY_EQUALS_* string\n");
	printf(" /MOD:<MOD>=[1|true]        set LOADIMMEDIATELY_EQUALS_TRUE string via search for BINARIES string\n");
	printf("                            and removes following LOADIMMEDIATELY_EQUALS_* strings\n");
	printf("                            then inserts LOADIMMEDIATELY_EQUALS_TRUE string\n");
	printf(" /MOD:<MOD>=[0|false]       set LOADIMMEDIATELY_EQUALS_FALSE string via search for BINARIES string\n");
	printf("                            and removes following LOADIMMEDIATELY_EQUALS_* strings\n");
	printf("                            then inserts LOADIMMEDIATELY_EQUALS_FALSE string\n");
	printf(" /MOD:<MOD>=[<space>|unset] unset LOADIMMEDIATELY_EQUALS_* string via search for BINARIES string\n");
	printf("                            and removes following LOADIMMEDIATELY_EQUALS_* strings\n");
	printf("where <MOD> is either FC3, FC2024, or a specific FC3/FC2024 module:\n");
	printf("\t");
	for (size_t i = 0; i < SIZEOFARRAY(fc2024_modules); i++)
	{
		_tprintf(_T("%s%s"), fc2024_modules[i], (i < SIZEOFARRAY(fc2024_modules) - 1 ? _T(", ") : _T("\n")));
	}
	printf("or:\n");
	printf("\t%s\n", "P-51D");
	printf("Notes:\r\n");
	printf("GlobalFixForAllFC3DependentMods.ini under each <MOD> contains exact search strings for BINARIES, LOADIMMEDIATELY_EQUALS_FALSE and LOADIMMEDIATELY_EQUALS_TRUE.\n");
	printf("Creates a backup copy of entry.lua as entry.lua.load_immediately.bak in same directory by default\n");
	printf("Prereqisites:\n");
	printf("Visual C++ Redistributables version 14.40.33810.0 https://learn.microsoft.com/en-us/cpp/windows/latest-supported-vc-redist?view=msvc-170\n");
	printf("   x86 https://aka.ms/vs/17/release/vc_redist.x86.exe\n");
	printf("   x64 https://aka.ms/vs/17/release/vc_redist.x64.exe\n");
}

/*****************************************************************************/

static void __cdecl atexitFunc(void)
{
	if (hEnumKey)
		::RegCloseKey(hEnumKey);
	hEnumKey = 0;

	if (hUninstallKey)
		::RegCloseKey(hUninstallKey);
	hUninstallKey = 0;
}

/*****************************************************************************/

int _tmain(int argc, const TCHAR* argv[])
{
	if (argc < 1)
		return -ERROR_BAD_COMMAND;

	int retCode = atexit(atexitFunc);

	// set ini configuration file
	szIniFile = argv[0];
	if (!szIniFile.compare((szIniFile.size() - 4), 4, _T(".exe")))
	{
		szIniFile.replace((szIniFile.size() - 4), 4, _T(".ini"));
	}

	initialize();

	bool bPrintHelp = true;
	int fcVectorIndex = 0;

	for (int i = 1; i < argc; i++)
	{
		const _TCHAR* ptr = argv[i];
		if ((*ptr == *_T("-")) || (*ptr == *_T("/")))
		{
			ptr++;
			if (!_tcsicmp(ptr, _T("help")) || !_tcscmp(ptr, _T("?")))
			{
				print_help(argc, argv);
				return ERROR_SUCCESS;
			}
			else if (!_tcsicmp(ptr, _T("license")))
			{
				printf("%s", GPL3license);
				return ERROR_SUCCESS;
			}
			else if (!_tcsnicmp(ptr, _T("verbose"), 7))
			{
				ptr += 7;
				if (*ptr == (TCHAR)'=')
				{
					verbose = _wtoi(ptr);
				}
				else
					verbose = 1;
			}
			else if (!_tcsicmp(ptr, _T("DEFAULTS")))
			{
				bPrintHelp = false;
				return createInifileWithDefaults(szIniFile);
			}
			else if (!_tcsnicmp(ptr, _T("DCSPATH="), 8))
			{
				ptr += 8;
				DCSpaths.clear();
				DCSpaths.push_back(std::wstring(ptr));
				if (DCSpaths.size())
					_tprintf(_T("CmdLine /DCSPATH=%s\n"), DCSpaths[DCSpaths.size() - 1].c_str());
			}
			else if (!_tcsnicmp(ptr, _T("BAK="), 4))
			{
				ptr += 4;
				if (!_tcscmp(ptr, _T("1")) || !_tcsicmp(ptr, _T("true")))
				   backupLua = 1;
				else if (!_tcscmp(ptr, _T("0")) || !_tcsicmp(ptr, _T("false")))
				   backupLua = 0;
			}
			else if (!_tcsnicmp(ptr, _T("MOD:"), 4))
			{
				ptr += 4;

				bPrintHelp = false;
				if (is_FCname(ptr, &fcVectorIndex))
				{
					ptr += vectorof_listof_fc_modules[fcVectorIndex].fc_name.size();

					if (DCSpaths.size() == 0)
						retCode = QueryWindowsUninstallForDCSWorld(DCSpaths, &hUninstallKey, &hEnumKey);

					if (DCSpaths.size() <= 0)
					{
						_tprintf(_T("DCS installations not detected, please override with /DCSPATH=...\n"));
						return -ERROR_BAD_ENVIRONMENT;
					}

					if (!_tcscmp(ptr, _T("=1")) || !_tcsicmp(ptr, _T("=true")))
					{
						set_modules_entry_lua__load_immediately(DCSpaths, vectorof_listof_fc_modules[fcVectorIndex].fc_modules, SET_LOADIMMEDIATELY_TRUE);
					}
					else if (!_tcscmp(ptr, _T("=0")) || !_tcsicmp(ptr, _T("=false")))
					{
						set_modules_entry_lua__load_immediately(DCSpaths, vectorof_listof_fc_modules[fcVectorIndex].fc_modules, SET_LOADIMMEDIATELY_FALSE);
					}
					else if (!_tcscmp(ptr, _T("=")) || !_tcsicmp(ptr, _T("=unset")))
					{
						set_modules_entry_lua__load_immediately(DCSpaths, vectorof_listof_fc_modules[fcVectorIndex].fc_modules, SET_LOADIMMEDIATELY_UNSET);
					}
					else
					{
						print_modules_entry_lua__load_immediately(DCSpaths, vectorof_listof_fc_modules[fcVectorIndex].fc_modules);
					}
				}
				else
				{
					if (DCSpaths.size() == 0)
						retCode = QueryWindowsUninstallForDCSWorld(DCSpaths, &hUninstallKey, &hEnumKey);

					if (DCSpaths.size() <= 0)
					{
						_tprintf(_T("DCS installations not detected, please override with /DCSPATH=...\n"));
						return -ERROR_BAD_ENVIRONMENT;
					}

					std::vector<std::wstring> otherModuleList;
					std::wstring otherModule(ptr);
					const TCHAR* pEqual = _tcschr(ptr, (TCHAR)'=');
					if (pEqual)
						otherModule.resize(pEqual - ptr);
					else
						pEqual = _T("");
					otherModuleList.push_back(otherModule);

					if (!_tcscmp(pEqual, _T("=1")) || !_tcsicmp(pEqual, _T("=true")))
					{
						set_modules_entry_lua__load_immediately(DCSpaths, otherModuleList, SET_LOADIMMEDIATELY_TRUE);
					}
					else if (!_tcscmp(pEqual, _T("=0")) || !_tcsicmp(pEqual, _T("=false")))
					{
						set_modules_entry_lua__load_immediately(DCSpaths, otherModuleList, SET_LOADIMMEDIATELY_FALSE);
					}
					else if (!_tcscmp(pEqual, _T("=")) || !_tcsicmp(pEqual, _T("=unset")))
					{
						set_modules_entry_lua__load_immediately(DCSpaths, otherModuleList, SET_LOADIMMEDIATELY_UNSET);
					}
					else
					{
						print_modules_entry_lua__load_immediately(DCSpaths, otherModuleList);
					}
				}
			}
		}
	}

	if (bPrintHelp)
		print_help(argc, argv);
	return ERROR_SUCCESS;
}


