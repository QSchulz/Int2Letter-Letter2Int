#Conversion of letters in integer and integer in letters (french numbers)

The aim is to convert a number up to size of integer type (circa 2 billions) to its translation in French and vice-versa.<br>
For non-French speakers, see: http://www.youtube.com/watch?v=WM1FFhaWj9w<br>
However this is a simpler conversion, since we do not care about dashes and plurals (there is some particular cases for hundreads, thousands and millions in French).<br>

####Author:
Quentin SCHULZ (quentin.schulz@utbm.fr)

####Usage:

**Needed file**

* *fichier_1* which is the source file (it can be both numbers in its integer form or in its French form and both can be mixed in the same file).

Download all files (except PDF files if you do not need them) and run the make file with: make.<br>
You can run your program with: /path/to/project/main fichier_1 fichier_2<br>
or with: make launch<br>
*fichier_2* is the file where the result will be put.<br>

#####Changelog

**v0.1 - 2014-02-23**
Initial release.<br>
